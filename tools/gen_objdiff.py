#!/usr/bin/env python3
"""Generate an objdiff project configuration (objdiff.json) for Persona 4 USA.

objdiff (https://github.com/encounter/objdiff) compares relocatable ELF
objects - functions AND data - which tools/verify.py cannot (it never
compares function-owned .rodata jump tables).  This generator turns a
``tools/verify.py --json`` report into one objdiff unit per tracked function:

  * functions inside a P4_UNIT guard compile as their own translation unit
    (``-DP4_UNIT_<ADDR>``), so they get one unit named after the guard, e.g.
    ``Battle/btlTarget:001EC630`` with base object
    ``build/objdiff/base/Battle/btlTarget_unit_001ec630.o`` (the whole unit
    object IS the function);
  * functions in unguarded files are one unit each, named after the function,
    e.g. ``Battle/btlUnit:00195850`` with base object
    ``build/objdiff/base/Battle/btlUnit/00195850.o`` (a per-function slice of
    the compiled translation unit).

``metadata.complete`` is true exactly when verify.py reports that function
MATCH.  Match state comes solely from the report, and sources are read only
to classify each function as guard-unit or plain-file (mirroring
tools/verify.py's P4_UNIT guard parsing).

With ``--emit-objects`` the generator also produces the objects the config
names, reusing tools/verify.py's compile path:

  * the base object (build/objdiff/base/...) is our compiled code: for guard
    units the P4_UNIT compile itself, for plain-file units a minimal .o
    sliced down to the one function (its .text bytes, its .rel.text entries
    with offsets adjusted, and the referenced symbols as undefined globals);
  * the target object (build/objdiff/target/...) is synthesised from the
    retail ELF: a minimal ELF32 little-endian MIPS ET_REL object whose .text
    holds the function's retail window bytes under a single global symbol
    named after the C function, with e_flags mirrored from the base object so
    objdiff decodes both sides with the same ISA/ABI.  When the verifier
    reports the unit MATCH and the window bytes past our compiled function's
    length are all zero (verify.py's padding criterion), the target .text is
    cut to the function's length so objdiff does not count padding
    instructions; otherwise the full window is emitted unchanged.

Emission is incremental: a unit is skipped when both objects exist, are
non-empty, and are at least as fresh as the source file, the report, the
retail ELF, and the compiler configuration.  ``--only SUBSTRING`` restricts
emission to units whose name or path contains SUBSTRING, and ``--force``
rebuilds regardless.  Files are written atomically, so a partial or
interrupted run leaves valid objects behind.

The generated config sets ``options.functionRelocDiffs: "none"``: retail
bytes are linked, so the target object carries no relocations, and objdiff
only treats a base relocation against a target constant as equal in that
relaxed mode (see objdiff-core's diff/display, ``FunctionRelocDiffs``).

The generator never invokes objdiff itself.
"""
from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
import tempfile
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"

# Mirrors tools/verify.py's guard parsing (UNIT_GUARD_RE / #endif scan).
UNIT_GUARD_RE = re.compile(r"^\s*#if\s+defined\(P4_UNIT_([0-9a-fA-F]{8})\)\s*$")
ENDIF_RE = re.compile(r"^\s*#endif\b")

SCHEMA_URL = "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json"
MIN_VERSION = "2.0.0"
BASE_DIR = "build/objdiff/base"
TARGET_DIR = "build/objdiff/target"
WATCH_PATTERNS = [
    "*.c", "*.cc", "*.cp", "*.cpp", "*.cxx", "*.c++",
    "*.h", "*.hh", "*.hp", "*.hpp", "*.hxx", "*.h++",
    "*.pch", "*.pch++", "*.inc", "*.s", "*.S", "*.asm",
    "*.py", "*.yml", "*.txt", "*.json",
]
IGNORE_PATTERNS = ["build/**/*"]
CONFIG_UNIT_KEYS = ("name", "target_path", "base_path", "metadata")


def _align(value: int, alignment: int) -> int:
    return (value + alignment - 1) & ~(alignment - 1)


def unit_guards(cpath: Path) -> list[dict]:
    """Return P4_UNIT guard ranges as [{start, end, addr}] with 1-based lines
    (start = guard line, end = one past the matching #endif line)."""
    lines = cpath.read_text(errors="replace").splitlines()
    guards: list[dict] = []
    for index, line in enumerate(lines):
        guard = UNIT_GUARD_RE.match(line)
        if not guard:
            continue
        end = next(
            (cursor for cursor in range(index + 1, len(lines))
             if ENDIF_RE.match(lines[cursor])),
            None,
        )
        if end is None:
            raise ValueError(f"unterminated P4_UNIT guard in {cpath}")
        guards.append(dict(start=index + 1, end=end + 1, addr=int(guard.group(1), 16)))
    return guards


def guard_for_line(guards: list[dict], line: int) -> dict | None:
    """Return the guard whose body contains the given 1-based source line."""
    for guard in guards:
        if guard["start"] <= line < guard["end"]:
            return guard
    return None


def build_units(results: list[dict]) -> list[dict]:
    """Derive one objdiff unit dict per report entry.

    Each unit carries the four config keys plus emission metadata
    (``file``, ``addr``, ``symbol``, ``unit``, ``window``).
    """
    by_file: dict[str, list[dict]] = {}
    for entry in results:
        by_file.setdefault(Path(entry["file"]).as_posix(), []).append(entry)

    units: list[dict] = []
    for file_rel in sorted(by_file):
        cpath = REPO / file_rel
        if not cpath.is_file():
            sys.exit(f"gen_objdiff: report file not found: {file_rel}")
        guards = unit_guards(cpath)
        stem = file_rel
        if stem.startswith("src/"):
            stem = stem[len("src/"):]
        if stem.endswith(".c"):
            stem = stem[:-2]
        for entry in sorted(by_file[file_rel], key=lambda e: e["line"]):
            guard = guard_for_line(guards, entry["line"]) if guards else None
            if guards and guard is None:
                sys.exit(f"gen_objdiff: {file_rel}: function at line {entry['line']} "
                         f"is not inside a P4_UNIT guard (stale report?)")
            address = int(entry["addr"], 16) if re.fullmatch(r"[0-9a-fA-F]{8}", entry["addr"]) else None
            if address is None:
                sys.exit(f"gen_objdiff: {file_rel}: bad function address {entry['addr']!r}")
            if guard is not None:
                name = f"{stem}:{guard['addr']:08X}"
                suffix = f"_unit_{guard['addr']:08x}"
                object_rel = f"{stem}{suffix}.o"
            else:
                name = f"{stem}:{address:08X}"
                object_rel = f"{stem}/{address:08x}.o"
            units.append(dict(
                name=name,
                target_path=f"{TARGET_DIR}/{object_rel}",
                base_path=f"{BASE_DIR}/{object_rel}",
                metadata={"complete": entry["status"] == "MATCH"},
                file=file_rel,
                addr=address,
                symbol=entry.get("name"),
                unit=guard["addr"] if guard is not None else None,
                window=entry.get("window"),
            ))

    units.sort(key=lambda unit: unit["name"])
    return units


def _verify():
    """Import tools/verify.py lazily so config generation never needs it."""
    sys.path.insert(0, str(TOOLS))
    import verify  # noqa: PLC0415  (intentional lazy import)
    return verify


def _elf_flags(data: bytes) -> int:
    """e_flags from an ELF32 header (offset 36), or 0 for non-ELF input."""
    return struct.unpack_from("<I", data, 36)[0] if len(data) >= 40 else 0


def build_elf_object(text: bytes, relocations: list[dict], symbol_name: str,
                     e_flags: int) -> bytes:
    """Build a minimal ELF32 little-endian MIPS ET_REL object.

    Sections: .text (SHF_ALLOC|SHF_EXECINSTR), .rel.text, .symtab, .strtab,
    .shstrtab.  ``relocations`` are verify.py-style dicts (``offset``,
    ``r_type``, ``symbol``); referenced symbols are emitted as undefined
    globals so the object stays self-contained.  ``symbol_name`` becomes a
    global function symbol spanning the whole .text section.
    """
    symbol_name = symbol_name or ""
    ref_names: list[str] = []
    ref_index: dict[str, int] = {}
    for relocation in relocations:
        symbol = relocation.get("symbol") or ""
        if symbol and symbol != symbol_name and symbol not in ref_index:
            ref_index[symbol] = len(ref_names) + 2
            ref_names.append(symbol)

    # String tables.
    strtab = b"\0"
    name_offsets = [0]
    for name in (symbol_name, *ref_names):
        name_offsets.append(len(strtab))
        strtab += name.encode("utf-8") + b"\0"
    shstrtab = b"\0.text\0.rel.text\0.symtab\0.strtab\0.shstrtab\0"

    # Symbol table: null, the function, then undefined referenced symbols.
    symbols = bytearray()
    symbols += struct.pack("<IIIBBH", 0, 0, 0, 0, 0, 0)
    symbols += struct.pack("<IIIBBH", name_offsets[1], 0, len(text), 0x12, 0, 1)
    for index, name in enumerate(ref_names):
        symbols += struct.pack("<IIIBBH", name_offsets[index + 2], 0, 0, 0x10, 0, 0)

    relocs = bytearray()
    for relocation in relocations:
        symbol = relocation.get("symbol") or ""
        symbol_index = 1 if symbol == symbol_name else ref_index.get(symbol, 0)
        relocs += struct.pack(
            "<II", int(relocation["offset"]), (symbol_index << 8) | int(relocation["r_type"]))

    text_offset = _align(52, 16)
    rel_offset = _align(text_offset + len(text), 4)
    sym_offset = _align(rel_offset + len(relocs), 4)
    str_offset = _align(sym_offset + len(symbols), 4)
    shstr_offset = str_offset + len(strtab)
    sh_offset = _align(shstr_offset + len(shstrtab), 4)

    header = struct.pack(
        "<16sHHIIIIIHHHHHH",
        b"\x7fELF\x01\x01\x01" + b"\0" * 9,
        1,            # ET_REL
        8,            # EM_MIPS
        1,            # EV_CURRENT
        0,            # e_entry
        0,            # e_phoff
        sh_offset,    # e_shoff
        e_flags,
        52,           # e_ehsize
        0,            # e_phentsize
        0,            # e_phnum
        40,           # e_shentsize
        6,            # e_shnum
        5,            # e_shstrndx
    )

    def sh(name_off, stype, flags, offset, size, link, info, align, entsize):
        return struct.pack("<IIIIIIIIII", name_off, stype, flags, 0, offset,
                           size, link, info, align, entsize)

    section_headers = b"".join([
        sh(0, 0, 0, 0, 0, 0, 0, 0, 0),
        sh(1, 1, 6, text_offset, len(text), 0, 0, 16, 0),
        sh(7, 9, 0, rel_offset, len(relocs), 3, 1, 4, 8),
        sh(17, 2, 0, sym_offset, len(symbols), 4, 1, 4, 16),
        sh(25, 3, 0, str_offset, len(strtab), 0, 0, 1, 0),
        sh(33, 3, 0, shstr_offset, len(shstrtab), 0, 0, 1, 0),
    ])

    blob = bytearray(header)
    blob.extend(b"\0" * (text_offset - len(blob)))
    blob.extend(text)
    blob.extend(b"\0" * (rel_offset - len(blob)))
    blob.extend(relocs)
    blob.extend(b"\0" * (sym_offset - len(blob)))
    blob.extend(symbols)
    blob.extend(b"\0" * (str_offset - len(blob)))
    blob.extend(strtab)
    blob.extend(b"\0" * (shstr_offset - len(blob)))
    blob.extend(shstrtab)
    blob.extend(b"\0" * (sh_offset - len(blob)))
    blob.extend(section_headers)
    return bytes(blob)


def slice_function_object(obj, name: str) -> bytes:
    """Rebuild a minimal .o containing just ``name`` from a compiled TU object."""
    body, relocations = obj.function(name)
    return build_elf_object(body, relocations, name, _elf_flags(obj.data))


def trim_window_padding(retail_bytes: bytes, body_len: int, complete: bool) -> bytes:
    """Return the window bytes a target object should carry.

    verify.py grants MATCH only when the window bytes past our function's
    length are all zero (``tail = target[len(body):]``; ``not any(tail)`` in
    verify_file), so those trailing zero bytes are padding, not function
    content.  When the unit is complete (verifier MATCH) and every byte past
    ``body_len`` in the window is zero, the function's true extent is
    ``body_len``: emit exactly that much so objdiff does not count padding
    instructions against the diff.  Every other case keeps the full window -
    a non-zero tail is real content (owned data or an unmarked sibling
    function), and a unit the verifier does not report MATCH keeps current
    behaviour so genuine differences stay visible.  The justification for
    trimming is never the bytes being zero (a MIPS ``nop`` is 0x00000000):
    it is that our object ends here and the remainder of the window is zero.
    """
    if complete and 0 < body_len < len(retail_bytes) and not any(retail_bytes[body_len:]):
        return retail_bytes[:body_len]
    return retail_bytes


def _current(path: Path, dep_mtime: float) -> bool:
    """True when ``path`` exists, is non-empty, and is at least as new as deps."""
    path = Path(path)
    try:
        st = path.stat()
    except OSError:
        return False
    return st.st_size > 0 and st.st_mtime >= dep_mtime


def _install_bytes(data: bytes, path: Path) -> None:
    """Write ``data`` to ``path`` atomically (temp file + os.replace)."""
    path.parent.mkdir(parents=True, exist_ok=True)
    descriptor, temporary = tempfile.mkstemp(dir=str(path.parent), prefix=".objdiff-", suffix=".tmp")
    try:
        with os.fdopen(descriptor, "wb") as handle:
            handle.write(data)
        os.replace(temporary, path)
    except BaseException:
        try:
            os.unlink(temporary)
        except OSError:
            pass
        raise


def select_units(units: list[dict], needle: str) -> list[dict]:
    """Subset of units whose name, base path, or target path contains ``needle``."""
    return [unit for unit in units
            if needle in unit["name"] or needle in unit["target_path"] or needle in unit["base_path"]]


def emit_objects(units: list[dict], args: argparse.Namespace) -> int:
    """Write base and target objects for every unit; returns failure count."""
    verify = _verify()
    started = time.monotonic()
    cfg = verify.load_config()
    target = verify._read_json(verify.TARGET)
    windows = verify._read_json(verify.FUNCTION_WINDOWS)
    if windows.get("program") != "SLUS_217.82" or windows.get("sha1") != target["elf"]["sha1"]:
        verify._die("slus21782_functions.json does not describe the configured P4 USA target")
    retail = verify.RetailElf(cfg["retail_elf"], target, windows["sha1"])
    retail_mtime = Path(cfg["retail_elf"]).stat().st_mtime
    windows_mtime = verify.FUNCTION_WINDOWS.stat().st_mtime
    report_mtime = Path(args.report).stat().st_mtime

    # Fresh function boundaries, mirroring tools/verify.py main().
    boundaries = {int(address, 16) for address in windows["windows"]}
    boundaries.update(int(address, 16) + size
                      for address, size in windows["windows"].items() if size)
    for path in (REPO / "src").rglob("*.c"):
        if verify.is_generated(path):
            continue
        boundaries.update(marker["addr"] for marker in verify.scan_markers(path))
    bounds = sorted(boundaries)

    if args.only:
        units = select_units(units, args.only)
        if not units:
            sys.exit(f"gen_objdiff: --only {args.only!r} matched no units")

    # Dependency timestamps shared by every base object.
    shared = [TOOLS / "verify_config.json", TOOLS / "verify_config.local.json",
              TOOLS / "verify.py", TOOLS / "mwccgap" / "mwccgap.py",
              REPO / "asm" / "macro.inc"]
    base_dep = max((path.stat().st_mtime for path in shared if path.is_file()), default=0)
    include_dir = REPO / "include"
    if include_dir.is_dir():
        base_dep = max(base_dep, max(
            (path.stat().st_mtime for path in include_dir.rglob("*") if path.is_file()),
            default=0))

    emitted = skipped = failed = 0
    by_file: dict[str, list[dict]] = {}
    for unit in units:
        by_file.setdefault(unit["file"], []).append(unit)

    with tempfile.TemporaryDirectory(prefix="p4objdiff_") as directory:
        scratch = Path(directory)
        for file_rel, file_units in by_file.items():
            cpath = REPO / file_rel
            cpath_mtime = cpath.stat().st_mtime
            unit_base_dep = max(base_dep, cpath_mtime, report_mtime)
            unit_target_dep = max(cpath_mtime, report_mtime, retail_mtime, windows_mtime)

            plain = [unit for unit in file_units if unit["unit"] is None]
            tu_obj = None
            tu_log = ""
            if plain and (args.force or any(not _current(unit["base_path"], unit_base_dep)
                                            for unit in plain)):
                compiled, tu_log = verify._compile(cpath, cfg, scratch / "tu.o", None)
                if compiled:
                    tu_obj = verify.ObjectFile(scratch / "tu.o")

            for unit in file_units:
                try:
                    base_needed = args.force or not _current(unit["base_path"], unit_base_dep)
                    target_needed = args.force or not _current(unit["target_path"], unit_target_dep)
                    if not base_needed and not target_needed:
                        skipped += 1
                        continue
                    base_bytes: bytes | None = None
                    if base_needed:
                        if unit["unit"] is not None:
                            compiled, log = verify._compile(cpath, cfg, scratch / "unit.o",
                                                            unit["unit"])
                            if not compiled:
                                raise RuntimeError(f"compile failed: {log.strip()[:300]}")
                            base_bytes = (scratch / "unit.o").read_bytes()
                        else:
                            if tu_obj is None:
                                raise RuntimeError(
                                    f"translation unit failed to compile: {tu_log.strip()[:200]}")
                            if not unit["symbol"]:
                                raise RuntimeError("report entry has no function symbol")
                            base_bytes = slice_function_object(tu_obj, unit["symbol"])
                        _install_bytes(base_bytes, Path(unit["base_path"]))
                        emitted += 1
                    if target_needed:
                        window = unit["window"] or verify.window_for(unit["addr"], bounds)
                        if window is None or window > 0x10000:
                            skipped += 1
                            print(f"  SKIP target {unit['target_path']}: "
                                  f"no retail window at {unit['addr']:#010x}")
                            continue
                        retail_bytes = retail.bytes_at(unit["addr"], window)
                        source = base_bytes if base_bytes is not None else Path(unit["base_path"]).read_bytes()
                        symbol = unit["symbol"] or f"func_{unit['addr']:08x}"
                        if unit["metadata"]["complete"] and unit["symbol"]:
                            # Mirror verify.py's function body extent so the
                            # target ends exactly where our compiled function
                            # ends; its zero tail is padding, not content.
                            try:
                                base_object = scratch / "base.o"
                                base_object.write_bytes(source)
                                body, _ = verify.ObjectFile(base_object).function(unit["symbol"])
                                retail_bytes = trim_window_padding(retail_bytes, len(body), True)
                            except (KeyError, ValueError, OSError) as error:
                                print(f"  WARN {unit['name']}: cannot size base function for "
                                      f"window trim ({error}); keeping full window")
                        target_bytes = build_elf_object(
                            retail_bytes, [], symbol,
                            _elf_flags(source))
                        _install_bytes(target_bytes, Path(unit["target_path"]))
                        emitted += 1
                except Exception as error:
                    failed += 1
                    print(f"  FAIL {unit['name']}: {error}")

    elapsed = time.monotonic() - started
    print(f"objdiff objects: emitted {emitted}, up to date {skipped}, failed {failed} "
          f"({elapsed:.1f}s)")
    return failed


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--report", required=True, metavar="PATH",
                        help="tools/verify.py --json report to derive state from")
    parser.add_argument("--output", default="objdiff.json", metavar="PATH",
                        help="output path (default: objdiff.json)")
    parser.add_argument("--emit-objects", action="store_true",
                        help="also write the base and target object files each unit names")
    parser.add_argument("--only", metavar="SUBSTRING",
                        help="with --emit-objects, only emit units whose name or path "
                             "contains SUBSTRING")
    parser.add_argument("--force", action="store_true",
                        help="with --emit-objects, rebuild even when outputs are up to date")
    args = parser.parse_args()

    report_path = Path(args.report)
    try:
        report = json.loads(report_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        sys.exit(f"gen_objdiff: cannot read report {report_path}: {error}")
    results = report.get("results") if isinstance(report, dict) else None
    if not isinstance(results, list):
        sys.exit("gen_objdiff: report must be a verify.py JSON object with a 'results' list")

    for entry in results:
        if not isinstance(entry, dict) or not (
            isinstance(entry.get("file"), str)
            and isinstance(entry.get("addr"), str)
            and isinstance(entry.get("line"), int)
            and isinstance(entry.get("status"), str)
        ):
            sys.exit(f"gen_objdiff: malformed report entry: {entry!r}")

    units = build_units(results)
    config = {
        "$schema": SCHEMA_URL,
        "min_version": MIN_VERSION,
        "custom_make": "make",
        "custom_args": [],
        "build_target": False,
        "build_base": True,
        # Retail bytes are linked, so target objects carry no relocations;
        # objdiff only treats a base relocation against a target constant as
        # equal in this relaxed mode.
        "options": {"functionRelocDiffs": "none"},
        "watch_patterns": WATCH_PATTERNS,
        "ignore_patterns": IGNORE_PATTERNS,
        "units": [{key: unit[key] for key in CONFIG_UNIT_KEYS} for unit in units],
    }
    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(config, indent=2, ensure_ascii=False) + "\n",
                      encoding="utf-8")
    complete = sum(1 for unit in units if unit["metadata"]["complete"])
    print(f"objdiff units: {len(units)} (complete: {complete}), wrote {output}")

    if args.emit_objects:
        failed = emit_objects(units, args)
        if failed:
            sys.exit(f"gen_objdiff: {failed} unit(s) failed to emit")


if __name__ == "__main__":
    main()
