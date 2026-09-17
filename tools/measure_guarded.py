#!/usr/bin/env python3
"""Measure the guarded NON_MATCHING body of one function via an isolated probe.

Usage: measure_guarded.py <source> <func> [--save-candidate PATH] [--objdump PATH]

Extracts the #ifdef-guarded C body (unwrapping ifdef/#else/INCLUDE/#endif,
keeping inner pragmas), splices it into a scratch TU copy, and runs fndiff.
Prints the differing-word score plus dsll/dsra pair counts for obj vs retail.
"""
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import probe_variants as probe

def extract_guarded_body(text, address, function):
    start, end = probe.region_for(text, address, function)
    region = text[start:end]
    lines = region.splitlines(keepends=True)
    # Drop guard lines: #if..., #else, #endif; drop INCLUDE_ASM fallback row.
    out = []
    for line in lines:
        s = line.strip()
        if re.match(r"#\s*(ifdef|ifndef|if|else|elif|endif)\b", s):
            continue
        if re.match(r"INCLUDE_ASM\s*\(", s):
            continue
        out.append(line)
    return "".join(out)

def count_pairs(disasm_text):
    """Count dsll32/dsra32-family extension instructions and adjacent pairs."""
    insns = []
    for line in disasm_text.splitlines():
        m = re.match(r"\s*(\d+)\s+(!?)\s*(\S+)\s+(\S+)", line)
        # fndiff rows: off, object word, object disasm, retail...
        # Fall back: count mnemonic occurrences in obj/retail columns separately.
        pass
    return None

def main():
    src = Path(sys.argv[1])
    func = sys.argv[2]
    save = None
    if "--save" in sys.argv:
        idx = sys.argv.index("--save")
        save = Path(sys.argv[idx + 1])
    m = re.search(r"([0-9a-fA-F]{8})", func)
    address = "FUN_" + m.group(1).upper()
    text = probe._read_text(src)
    body = extract_guarded_body(text, address, func)
    if save:
        save.write_text(body)
        print(f"saved candidate to {save} ({len(body)} bytes)")
    start, end = probe.region_for(text, address, func)
    newline = probe._newline_for(src.read_bytes())
    body_n = probe._normalise_candidate(body, newline)
    patched = probe.splice_region(text, start, end, body_n, newline)
    with probe.scratch_source(src.resolve()) as scratch:
        scratch.write_bytes(patched.encode("utf-8", errors="surrogateescape"))
        score, diagnostics = probe.run_fndiff(scratch, func, src.resolve())
        print(diagnostics.rstrip())
        if score is None:
            print(f"probe failed for {func}")
            return 1
        print(f"GUARDED_SCORE {func}: {score}")
        return 0

if __name__ == "__main__":
    raise SystemExit(main())
