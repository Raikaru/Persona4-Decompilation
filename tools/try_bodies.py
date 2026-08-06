"""Splice candidate bodies for one function into a source file and score each.

Usage:
    python tools/try_bodies.py <file.c> <func_name> <variants.json>

`variants.json` is a JSON object mapping a short label to the replacement text
for the function's whole definition (marker line excluded).  The current
definition is located by its `// FUN_XXXXXXXX` marker: everything from the line
after the marker (plus any `#pragma` lines that immediately follow it) through
the closing brace, or through the `INCLUDE_ASM(...)` line, is replaced.

Each variant is compiled with a scoped `tools/verify.py` run and reported with
its status / normalized_diff / object size.  The file is always restored.
"""
import json
import pathlib
import re
import subprocess
import sys

MARK = re.compile(r"^\s*//\s*FUN_([0-9A-Fa-f]{8})\b")


def locate(lines, addr):
    for i, line in enumerate(lines):
        m = MARK.match(line)
        if m and m.group(1).lower() == addr:
            break
    else:
        raise SystemExit(f"no marker for {addr}")
    start = i + 1
    j = start
    if "INCLUDE_ASM" in lines[j]:
        return start, j + 1
    depth = 0
    seen = False
    while j < len(lines):
        if "INCLUDE_ASM" in lines[j] and not seen:
            return start, j + 1
        depth += lines[j].count("{") - lines[j].count("}")
        if lines[j].count("{"):
            seen = True
        if seen and depth == 0:
            return start, j + 1
        j += 1
    raise SystemExit(f"unterminated body for {addr}")


def main():
    cfile, func, spec = sys.argv[1], sys.argv[2], sys.argv[3]
    addr = func.split("_")[-1].lower()
    variants = json.loads(pathlib.Path(spec).read_text(encoding="utf-8"))
    path = pathlib.Path(cfile)
    original = path.read_text(encoding="utf-8", errors="surrogateescape")
    nl = "\r\n" if original.count("\r\n") >= max(1, original.count("\n") // 2) else "\n"
    lines = original.replace("\r\n", "\n").split("\n")
    start, end = locate(lines, addr)
    print(f"replacing lines {start + 1}..{end} of {cfile}")
    results = []
    try:
        for label, body in variants.items():
            new = lines[:start] + body.split("\n") + lines[end:]
            path.write_text(nl.join(new), encoding="utf-8", errors="surrogateescape")
            subprocess.run(
                [sys.executable, "tools/verify.py", "--json", "build/try_bodies.json", cfile],
                capture_output=True, stdin=subprocess.DEVNULL,
            )
            try:
                report = json.loads(pathlib.Path("build/try_bodies.json").read_text())
            except Exception:
                print(f"  {label:24} VERIFY_FAILED")
                continue
            rows = [r for r in report["results"] if r["name"] == func]
            collateral = [r["name"] for r in report["results"]
                          if r["status"] in ("MISMATCH", "COMPILE_ERROR") and r["name"] != func]
            if not rows:
                print(f"  {label:24} NO_ROW  collateral={len(collateral)}")
                continue
            row = rows[0]
            score = (-1 if row["status"] == "MATCH"
                     else row.get("normalized_diff") if row["status"] == "MISMATCH"
                     else 10 ** 6)
            results.append((score, label))
            flag = "  <== MATCH" if row["status"] == "MATCH" and not collateral else ""
            print(f"  {label:24} {row['status']:14} nd={row.get('normalized_diff')} "
                  f"obj={row.get('object_size')}/{row.get('window')} coll={len(collateral)}{flag}")
    finally:
        path.write_text(original, encoding="utf-8", errors="surrogateescape")
    if results:
        results.sort()
        print(f"\nbest: {results[0][1]} (nd {results[0][0]})")


if __name__ == "__main__":
    main()
