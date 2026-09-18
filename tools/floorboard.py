#!/usr/bin/env python3
"""Score every guarded first-party floor in parallel and rank them.

Triage across the whole tree: a floor under twenty differing words is two or
three edits from a MATCH and outranks any cold window, but with two hundred
floors banked there is no other way to find out which ones those are.  Each
floor is recompiled from its guarded body, so this measures what is banked
rather than the `#else INCLUDE_ASM` arm.

Writes the ranked list to /var/tmp/floorboard.txt as `words name owner`.

`--audit` additionally reports every floor whose note never states the score
the floor actually measures.  A note that claims 16 differing words on a body
that measures 295 does not merely mislead the next reader, it sends them after
a residual that does not exist; fifty-nine floors were in that state when the
check was first written.

Usage:
  python3 -E -s tools/floorboard.py
  python3 -E -s tools/floorboard.py --audit
"""
import concurrent.futures as cf
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import verify  # noqa: E402

# Marker and `#ifdef` are usually separated by the measured note.
GUARD = re.compile(
    r"// FUN_([0-9A-Fa-f]{8}) NONMATCHING[^\n]*\n"
    r"(?:[ \t]*(?://[^\n]*|/\*(?:[^*]|\*(?!/))*\*/)?[ \t]*\n)*"
    r"[ \t]*#\s*ifdef\s+(?:NON_MATCHING|SKIP_ASM)")
SCORE = re.compile(r"GUARDED_SCORE \S+: (\d+)")
COUNTS = re.compile(r"retail (\d+) instrs  object (\d+) instrs")


def collect():
    out = []
    for path in sorted((REPO / "src").rglob("*.c")):
        if "generated" in path.parts or path.name.startswith("."):
            continue
        text = path.read_text(errors="replace")
        for m in GUARD.finditer(text):
            addr = int(m.group(1), 16)
            if verify.code_origin(path, addr) == "main":
                out.append((path.relative_to(REPO), "func_%08x" % addr))
    return out


def score(item):
    path, name = item
    r = subprocess.run(
        [sys.executable, "-E", "-s", "tools/measure_guarded.py", str(path), name],
        cwd=REPO, capture_output=True, text=True)
    m = SCORE.search(r.stdout)
    if not m:
        return (path, name, None, None, None,
                (r.stderr or r.stdout).strip().splitlines()[-1:] or ["?"])
    return (path, name, int(m.group(1)), None, None, None)


NUMBER = re.compile(r"(\d+)\s+differing words|\bnd\s*(\d+)|GUARDED_SCORE[^:]*:\s*(\d+)")


def note_above(path: Path, name: str) -> str:
    """The comment block immediately above a floor's marker."""
    addr = name[5:].upper()
    text = path.read_text(errors="replace")
    lines = text.split("\n")
    for i, line in enumerate(lines):
        if ("// FUN_" + addr) in line and "NONMATCHING" in line:
            return "\n".join(lines[max(0, i - 60):i])
    return ""


def audit(rows):
    stale = []
    for path, name, words, _a, _b, _c in rows:
        if words is None:
            continue
        note = note_above(REPO / path, name)
        claims = {int(g) for m in NUMBER.finditer(note) for g in m.groups() if g}
        if claims and words not in claims:
            stale.append((words, name, path, sorted(claims)[-5:]))
    print("\nfloors whose note never states the measured score: %d" % len(stale))
    for words, name, path, claims in sorted(stale, reverse=True,
                                            key=lambda r: max(r[3]) - r[0]):
        print("  %-15s %-44s measures %5d, note claims %s"
              % (name, path, words, claims))


def main():
    items = collect()
    print("scoring %d guarded first-party floors" % len(items), flush=True)
    rows = []
    with cf.ThreadPoolExecutor(max_workers=8) as pool:
        for r in pool.map(score, items):
            rows.append(r)
            if r[2] is None:
                print("  FAILED %s %s :: %s" % (r[0], r[1], r[5]), flush=True)
    ok = [r for r in rows if r[2] is not None]
    ok.sort(key=lambda r: r[2])
    print("\nrank  words  function        owner")
    for i, (path, name, words, _a, _b, _c) in enumerate(ok, 1):
        print("%4d  %5d  %-15s %s" % (i, words, name, path))
    Path("/var/tmp/floorboard.txt").write_text(
        "\n".join("%d %s %s" % (w, n, p) for p, n, w, _a, _b, _c in ok))
    if "--audit" in sys.argv:
        audit(rows)
    print("\nunder 20 words: %d   under 50: %d   total: %d"
          % (sum(1 for r in ok if r[2] < 20),
             sum(1 for r in ok if r[2] < 50), len(ok)))


if __name__ == "__main__":
    main()
