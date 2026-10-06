"""Resolve movie owner references from independent sibling anchors.

Nonexact target code and its switch table are reported honestly. No instruction
or emitted object is changed; relocated copies exist only for comparison.
"""
from collections import defaultdict
from pathlib import Path
import ast
import hashlib
import json
import struct
import sys

from movie_context import ROOT, OUT, OWNER, NAME, WINDOWS, RETAIL, V, sha
sys.path.insert(0, str(ROOT / "tools"))
import build as B

GP, ADDRESSES = V.symbol_addresses()
ADDRESSES.update(B.load_symbol_addr_map())
assert GP is not None
support = ROOT / "docs/probe_archive/BtlEpl_vector_blend_worker25_20261005/native.py"
parsed = ast.parse(support.read_text())
definitions = [node for node in parsed.body if isinstance(node, ast.FunctionDef)
               and node.name in {"signed16", "section_relocations", "relocate"}]
assert len(definitions) == 3
# Reuse precisely the already audited relocation implementations, with no
# import-time Battle owner initialization and no changes to their algorithms.
exec(compile(ast.Module(body=definitions, type_ignores=[]), str(support), "exec"), globals())


def inspect(directory, target_table=False):
    directory = Path(directory)
    obj = V.ObjectFile(directory / "owner.o")
    available = {s["name"] for s in obj.symbols if s["info"] & 15 == 2 and s["size"]}
    markers = [m for m in V.scan_markers(OWNER) if m["name"] in available]
    anchors = []
    for marker in markers:
        if marker["name"] == NAME:
            continue
        code, refs = obj.function(marker["name"])
        window = WINDOWS["windows"][f'{marker["addr"]:08x}']
        native = RETAIL.bytes_at(marker["addr"], window)
        differences, _ = V.compare(code, refs, native)
        if not differences and len(code) <= window and not any(native[len(code):]):
            anchors.append(marker)
    bases = B.recover_section_bases(obj, anchors, RETAIL, GP)
    pointer_bases = B.recover_pointer_data_bases(obj, anchors, RETAIL, GP)
    if pointer_bases is not None:
        bases.update(pointer_bases)
    groups = defaultdict(list)
    for section in obj.sections:
        if section["flags"] & 2 and not section["flags"] & 4 and section["size"]:
            groups[section["name"]].append(section)
    layouts = {}
    for name, sections in groups.items():
        layout = B.recover_concatenated_layout(sections, bases)
        if layout is None:
            continue
        base, offsets, total = layout
        layouts[name] = (base, offsets, total)
        for section, offset in zip(sections, offsets):
            assert bases.get(section["idx"], base + offset) == base + offset
            bases[section["idx"]] = base + offset
    table_contract = None
    if target_table:
        from native_table_contract import recover
        extra_bases, table_contract = recover(obj, section_relocations)
        for index, base in extra_bases.items():
            assert bases.get(index, base) == base
            bases[index] = base
    mapping = dict(ADDRESSES)
    mapping.update({m["name"]: m["addr"] for m in markers})
    for symbol in obj.symbols:
        if symbol["name"] and symbol["shndx"] in bases:
            mapping[symbol["name"]] = bases[symbol["shndx"]] + symbol["value"]
    functions = []
    for marker in markers:
        code, refs = obj.function(marker["name"])
        resolved, errors = relocate(code, refs, mapping, bases)
        window = WINDOWS["windows"][f'{marker["addr"]:08x}']
        native = RETAIL.bytes_at(marker["addr"], window)
        diff = [i for i in range(max(len(resolved), window))
                if ((resolved[i] if i < len(resolved) else 0) != (native[i] if i < window else 0))]
        tail_zero = len(resolved) <= window and not any(native[len(resolved):])
        functions.append(dict(name=marker["name"], size=len(code), window=window,
                              differing_words=len({i // 4 for i in diff}),
                              differing_bytes=len(diff), errors=errors,
                              exact=not diff and not errors and tail_zero,
                              zero_suffix=window-len(code) if tail_zero else None,
                              relocations=len(refs), resolved_sha256=sha(resolved)))
        if marker["name"] == NAME and not errors:
            (directory / "resolved-target.bin").write_bytes(resolved)
    data = []
    for section in obj.sections:
        if not section["flags"] & 2 or section["flags"] & 4 or not section["size"]:
            continue
        refs = section_relocations(obj, section["idx"])
        raw = obj.data[section["offset"]:section["offset"]+section["size"]]
        payload, errors = (bytes(section["size"]), []) if section["type"] == 8 else relocate(raw, refs, mapping, bases)
        address = bases.get(section["idx"])
        native = RETAIL.bytes_at(address, len(payload)) if address is not None else None
        data.append(dict(index=section["idx"], name=section["name"], size=section["size"],
                         address=f'{address:08x}' if address is not None else None,
                         exact=native is not None and payload == native and not errors,
                         errors=errors, relocations=len(refs), payload_sha256=sha(payload)))
    report = dict(logical_owner=str(OWNER.relative_to(ROOT)),
                  source_sha256=sha((directory / "owner.c").read_bytes()), object_sha256=sha(obj.data),
                  relocation_support_sha256=sha(support.read_bytes()),
                  independent_anchor_functions=len(anchors), section_bases=bases,
                  functions=functions, data_sections=data, target_table_contract=table_contract,
                  complete_exact=all(r["exact"] for r in functions+data))
    proof_name = "resolved-contract-proof.json" if target_table else "resolved-proof.json"
    (directory / proof_name).write_text(json.dumps(report, indent=2) + "\n")
    target = next(row for row in functions if row["name"] == NAME)
    print(directory.name, "TARGET", json.dumps(target), flush=True)
    print("SIBLINGS", len(functions)-1, "nonexact", [r["name"] for r in functions if r["name"] != NAME and not r["exact"]],
          "DATA", len(data), "nonexact", [{k:r[k] for k in ("index", "name", "size", "address", "errors")} for r in data if not r["exact"]], flush=True)
    return report


if __name__ == "__main__":
    contract = "--target-table" in sys.argv
    for label in (arg for arg in sys.argv[1:] if arg != "--target-table"):
        assert "/" not in label and "\\" not in label
        inspect(OUT / "candidates" / label, target_table=contract)
