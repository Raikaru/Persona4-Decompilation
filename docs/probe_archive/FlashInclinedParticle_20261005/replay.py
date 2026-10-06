#!/usr/bin/env python3
"""Reproduce complete Flash owner code/reference proofs in private build scratch."""
from collections import Counter, defaultdict
from pathlib import Path
import argparse
import hashlib
import json
import struct
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[3]
ARCHIVE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / "tools"))
import verify as V
import probe_variants as P
import build as B
from measure_guarded import extract_guarded_body

def forced_addresses(label, markers):
    return {m["addr"] for m in markers if m.get("asm")} if label.endswith("guarded") else set()

def digest(data):
    return hashlib.sha256(data).hexdigest()


def signed16(word):
    return (word & 0x7fff) - (word & 0x8000)


def relocate(code, relocations, addresses, gp):
    output = bytearray(code)
    pending = defaultdict(list)
    records = []
    for reloc in relocations:
        offset, kind, name = reloc['offset'], reloc['r_type'], reloc.get('symbol') or ''
        address = V.resolve_symbol(name, gp, addresses)
        assert address is not None, ('Unresolved reference', reloc)
        assert 0 <= offset <= len(code) - 4 and offset % 4 == 0
        word, = struct.unpack_from('<I', code, offset)
        row = dict(offset=offset, kind=V.R_MIPS_NAMES.get(kind, str(kind)), symbol=name,
                   symbol_address=f'{address:08x}')
        records.append(row)
        if kind == 4:
            destination = address + ((word & 0x3ffffff) << 2)
            assert destination % 4 == 0
            value = (word & 0xfc000000) | ((destination >> 2) & 0x3ffffff)
            row['destination'] = f'{destination:08x}'
        elif kind == 5:
            pending[name].append((offset, word, row))
            continue
        elif kind == 6:
            highs = pending.pop(name, [])
            row['paired_high_offsets'] = [offset for offset, _, _ in highs]
            for hi_offset, hi_word, hi_row in highs:
                destination = address + ((hi_word & 0xffff) << 16) + signed16(word)
                struct.pack_into('<I', output, hi_offset,
                                 (hi_word & 0xffff0000) | (((destination + 0x8000) >> 16) & 0xffff))
                hi_row['paired_low_offset'] = offset
                hi_row['destination'] = f'{destination & 0xffffffff:08x}'
            value = (word & 0xffff0000) | ((address + signed16(word)) & 0xffff)
        elif kind in (7, 8):
            destination = address + signed16(word)
            displacement = destination - gp
            assert -0x8000 <= displacement < 0x8000, 'GP displacement outside range'
            value = (word & 0xffff0000) | (displacement & 0xffff)
            row['destination'] = f'{destination:08x}'
        elif kind == 2:
            value = (word + address) & 0xffffffff
            row['destination'] = f'{value:08x}'
        else:
            raise AssertionError(('Unsupported relocation', reloc))
        struct.pack_into('<I', output, offset, value)
    assert not any(pending.values()), 'Unpaired HI16 relocation'
    return bytes(output), records


def inspect(label, directory, markers, windows, retail, addresses, gp):
    obj = V.ObjectFile(directory / label / 'owner.o')
    allocated_data = [s for s in obj.sections if s['flags'] & 2 and not s['flags'] & 4 and s['size']]
    assert not allocated_data, 'This owner now has allocated data; re-audit its placement'
    forced = forced_addresses(label, markers)
    rows, functions, covered = [], {}, defaultdict(set)
    symbols = dict(addresses)
    symbols.update({m['name']: m['addr'] for m in markers})
    for marker in markers:
        name, address = marker['name'], marker['addr']
        code, relocs = obj.function(name)
        resolved, references = relocate(code, relocs, symbols, gp)
        window = windows['windows'][f'{address:08x}']
        target = retail.bytes_at(address, window)
        differences = [offset for offset in range(0, max(len(resolved), window), 4)
                       if not (offset >= len(resolved) and not any(target[offset:offset + 4]))
                       and resolved[offset:offset + 4] != target[offset:offset + 4]]
        exact = not differences and len(resolved) <= window
        kind = 'ASM' if marker.get('asm') and address not in forced else 'C'
        for reference in references:
            offset = reference['offset']
            reference['same_relocated_instruction'] = resolved[offset:offset + 4] == target[offset:offset + 4]
        rows.append(dict(address=f'{address:08x}', name=name, source_kind=kind,
                         status=('ASM' if kind == 'ASM' else 'MATCH') if exact else 'NONMATCHING',
                         bytes=len(code), window=window, exact=exact,
                         zero_suffix=window-len(code) if len(code) <= window and not any(target[len(code):]) else None,
                         code_sha256=digest(code), resolved_sha256=digest(resolved),
                         relocation_count=len(relocs), references=references,
                         differing_words=len(differences), differing_offsets=differences))
        functions[name] = (code, relocs, resolved)
        symbol = next(s for s in obj.symbols if s['name'] == name and s['size'] and s['shndx'] != 0)
        interval = set(range(symbol['value'], symbol['value'] + symbol['size']))
        assert not covered[symbol['shndx']].intersection(interval), 'Overlapping function symbols'
        covered[symbol['shndx']].update(interval)
    executable = []
    for section in obj.sections:
        if not section['flags'] & 2 or not section['size']:
            continue
        assert section['flags'] & 4
        raw = obj.data[section['offset']:section['offset'] + section['size']]
        unused = set(range(section['size'])) - covered[section['idx']]
        assert not any(raw[i] for i in unused), 'Unaccounted executable bytes'
        for offset, _, _ in B.section_relocs(obj, section['idx']):
            assert set(range(offset, offset + 4)) <= covered[section['idx']]
        executable.append(dict(name=section['name'], index=section['idx'], size=section['size'],
                               covered_bytes=len(covered[section['idx']]), zero_alignment_bytes=len(unused)))
    report = dict(object_sha256=digest(obj.data), functions=rows,
                  status_counts=dict(Counter(r['status'] for r in rows)),
                  code_relocation_count=sum(r['relocation_count'] for r in rows),
                  allocated_data=[], data_relocation_count=0, executable_sections=executable)
    print(label, report['status_counts'], 'code references', report['code_relocation_count'], flush=True)
    return report, functions


def replace_body(source, body, guarded):
    if guarded:
        body = '#ifdef NON_MATCHING\n' + body.rstrip() + '\n#else\nINCLUDE_ASM("asm/nonmatchings/effPolygonFlash", func_004a0c00);\n#endif\n'
    a, b = P.region_for(source, "FUN_004A0C00", "func_004a0c00")
    return P.splice_region(source, a, b, P._normalise_candidate(body, "\n"), "\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--reuse-dir", type=Path)
    args = parser.parse_args()
    saved = json.loads((ARCHIVE / "receipt.json").read_text())
    owner = ROOT / saved["owner"]
    original = owner.read_bytes()
    assert digest(original) == saved["source_sha256"], "Owner changed; re-audit the recovery"
    after = P._read_text(owner)
    before = replace_body(after, P._read_text(ARCHIVE / "before_body.c"), True)
    assert digest(before.encode()) == saved["before_sha256"]
    body = extract_guarded_body(before, "FUN_004A0C00", "func_004a0c00")
    profiles = {"before-default": before, "after-default": after,
                "before-guarded": replace_body(before, body, False),
                "after-guarded": "#define NON_MATCHING 1\n" + after}
    cfg = V.load_config()
    assert digest(Path(V.unit_compiler(owner, cfg)).read_bytes()) == saved["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == saved["flags"]
    for name, expected in saved["dependencies"].items():
        assert digest((ROOT / name).read_bytes()) == expected, name
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), windows["sha1"])
    directory = args.reuse_dir or Path(tempfile.mkdtemp(prefix="flash-inclined-", dir=ROOT / "build"))
    reports, functions = {}, {}
    markers = V.scan_markers(owner)
    gp, addresses = V.symbol_addresses()
    addresses.update(B.load_symbol_addr_map())
    for label, source in profiles.items():
        entry = directory / label
        if args.reuse_dir:
            assert P._read_text(entry / "owner.c") == source
            compiled = P._read_text(entry / "compiled_owner.c")
            expected = saved["profile_objects"][label]
            assert digest(compiled.encode()) == expected["compiled_source_sha256"]
            assert digest((entry / "owner.o").read_bytes()) == expected["object_sha256"]
            bridge = saved["comment_equivalence"]
            assert compiled == source or compiled.replace(bridge["old_comment"], bridge["new_comment"]) == source
        else:
            entry.mkdir(exist_ok=False)
            (entry / "owner.c").write_bytes(source.encode())
            if label == "after-default":
                rows = V.verify_file(owner, cfg, retail, sorted(int(a, 16) for a in windows["windows"]), entry)
                assert dict(Counter(row["status"] for row in rows)) == {"MATCH": 48, "ASM": 1}
                opath, = entry.glob("*.o")
                opath.rename(entry / "owner.o")
            else:
                ok, log = P._compile_in_context(entry / "owner.c", owner, cfg, entry / "owner.o")
                (entry / "compile.log").write_text(log)
                assert ok, log
        reports[label], functions[label] = inspect(label, directory, markers, windows, retail, addresses, gp)
        reports[label]["source_sha256"] = digest(source.encode())
        reports[label]["compilation"] = "authenticated completed object" if args.reuse_dir else "fresh complete owner"
    assert functions["before-default"] == functions["after-default"]
    assert functions["before-guarded"] == functions["after-guarded"]
    for name in functions["after-default"]:
        if name != "func_004a0c00":
            assert functions["after-default"][name] == functions["after-guarded"][name]
    target = next(r for r in reports["after-guarded"]["functions"] if r["address"] == "004a0c00")
    assert target["bytes"] == 2204 and target["zero_suffix"] == 4 and target["differing_words"] == 16
    assert all(r["same_relocated_instruction"] for r in target["references"])
    assert owner.read_bytes() == original
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps({"source_sha256": digest(original), "new_C_matches": 0,
                                      "profiles": reports, "all_49_guarded_functions_preserved": True,
                                      "48_C_siblings_preserved": True}, indent=2) + "\n")
    print("PASS: 49 owner functions, complete references, preserved siblings, sixteen-word residual")

if __name__ == "__main__":
    main()
