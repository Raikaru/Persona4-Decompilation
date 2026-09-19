#!/usr/bin/env python3
"""Check every banked floor against the 3% instruction-count gate.

A guarded body is only worth banking when its object is within 3% of retail's
instruction count.  Outside that band the body is missing or inventing work,
and - the part that keeps biting - **its differing-word score stops meaning
anything**, because `measure_guarded` diffs over a fixed window and a short
body scores well by sliding out of alignment with the code it lacks.

`func_0035fd60` was banked at 1522 words with its object 86 instructions
short (-4.8%).  Replacing it with a body at +0.7% raised the word score to
1689 and nearly halved the alignment edits, 849 -> 478.  The 1522 was never a
floor; it was a measurement artefact (handoff 7y).

This finds every floor in that state, so a bad baseline cannot quietly
survive as the thing a later pass tries to beat.

    python3 -E -s tools/gate_audit.py            # every floor
    python3 -E -s tools/gate_audit.py src/foo.c  # one file
"""

from __future__ import annotations

import re
import sys
import tempfile
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "mwccgap"))

import fnalign  # noqa: E402
import verify  # noqa: E402
from measure_guarded import extract_guarded_body  # noqa: E402

GUARD = re.compile(r"// FUN_([0-9A-Fa-f]{8}) NONMATCHING")
TOLERANCE = 0.03


def boundaries(windows: dict) -> list[int]:
    out = {int(k, 16) for k in windows["windows"]}
    out.update(int(k, 16) + v for k, v in windows["windows"].items() if v)
    for path in (REPO / "src").rglob("*.c"):
        try:
            out.update(m["addr"] for m in verify.scan_markers(path))
        except OSError:
            continue
    return sorted(out)


STAMP = re.compile(r"^/\* gate: [^*]*\*/\n", re.M)


def stamp_for(got: int, want: int, drift: float) -> str:
    return (f"/* gate: object {got} against retail {want}, {drift:+.1%} - OUTSIDE\n"
            f"   the +-3% band.  Any differing-word score in this note was measured\n"
            f"   against a body of the wrong length and is not comparable to one\n"
            f"   measured inside the gate (handoff 7y).  Fix the count first. */\n")


def annotate(path: Path, marker: str, text: str, note: str) -> str:
    """Insert or replace the machine-written gate stamp above MARKER."""
    at = text.index(marker)
    head = text.rfind("\n", 0, at)
    existing = STAMP.search(text, max(0, head - 400), at + 1)
    if existing and existing.end() >= head:
        return text[:existing.start()] + note + text[existing.end():]
    return text[:at] + note + text[at:]


def main() -> None:
    annotating = "--annotate" in sys.argv
    only = {Path(a).resolve() for a in sys.argv[1:] if not a.startswith("-")}
    cfg = verify.load_config()
    windows = fnalign._read_json(fnalign.FUNCTION_WINDOWS)
    elf = fnalign.RetailElf(cfg["retail_elf"], fnalign._read_json(fnalign.TARGET),
                            windows["sha1"])
    bounds = boundaries(windows)

    composition = "--composition" in sys.argv
    inside, outside, unmeasured, split = 0, [], 0, []
    with tempfile.TemporaryDirectory() as scratch:
        for path in sorted((REPO / "src").rglob("*.c")):
            if path.parent.name == "generated" or path.name.startswith("."):
                continue
            # Third-party code is out of scope: the floors under src/middleware
            # and friends are ee-gcc output that b210 provably cannot reproduce,
            # so their drift is evidence of authorship, not of a defect.
            rel = path.relative_to(REPO / "src").as_posix()
            if rel.startswith(verify.THIRD_PARTY_PREFIXES):
                continue
            if only and path.resolve() not in only:
                continue
            text = path.read_text(errors="replace")
            for marker in GUARD.finditer(text):
                name = "func_%s" % marker.group(1).lower()
                marker_text = marker.group(1).upper()
                address = int(marker.group(1), 16)
                candidate = Path(scratch) / f"{name}.c"
                try:
                    candidate.write_text(extract_guarded_body(
                        text, "FUN_" + marker.group(1).upper(), name))
                    body, _relocations = fnalign._object_for(path, name, candidate, cfg)
                    retail = elf.bytes_at(address, fnalign.window_for(address, bounds))
                except BaseException:
                    unmeasured += 1
                    continue
                # Trim retail's zero alignment tail the way fnalign does, so
                # the comparison is instructions against instructions.
                while (len(retail) >= 4 and not any(retail[-4:])
                       and len(retail) > len(body)):
                    retail = retail[:-4]
                want, got = len(retail) // 4, len(body) // 4
                if not want:
                    unmeasured += 1
                    continue
                drift = (got - want) / want
                # 3% of a six-instruction function is a fifth of an
                # instruction, so a percentage alone condemns every tiny
                # body.  Allow two instructions of slack before the
                # percentage applies; that is the smallest difference a
                # prologue or a delay slot can make.
                if abs(got - want) <= max(2, round(TOLERANCE * want)):
                    inside += 1
                    if composition:
                        # A count inside the band proves nothing on its own:
                        # a pure `delete` run and a pure `insert` run can
                        # cancel (handoff 7aa).  Only pure runs count - a
                        # `replace` is a diverged region, not missing code.
                        script, _edits, _reloc = fnalign.align(
                            fnalign.decode(retail, address),
                            fnalign.decode(body, 0), set())
                        hole = max((i2 - i1 for t, i1, i2, _j1, _j2 in script
                                    if t == "delete"), default=0)
                        lump = max((j2 - j1 for t, _i1, _i2, j1, j2 in script
                                    if t == "insert"), default=0)
                        if hole >= 25 and lump >= 25:
                            split.append((min(hole, lump), hole, lump, got,
                                          want, name,
                                          str(path.relative_to(REPO))))
                else:
                    outside.append((abs(drift), drift, got, want, name,
                                    str(path.relative_to(REPO))))
                    if annotating:
                        marker = f"// FUN_{marker_text} NONMATCHING"
                        text = annotate(path, marker, text,
                                        stamp_for(got, want, drift))
                        path.write_text(text)

    for _key, drift, got, want, name, source in sorted(outside, reverse=True):
        print(f"{drift:+7.1%}  object {got:5d}  retail {want:5d}  {name}  {source}")
    for _key, hole, lump, got, want, name, source in sorted(split, reverse=True):
        print(f"  hole {hole:4d}  lump {lump:4d}  object {got:5d}  retail {want:5d}"
              f"  {name}  {source}")
    if split:
        print(f"\n{len(split)} floors are inside the gate but hide a pure hole "
              "against a pure lump (handoff 7aa)")
    print(f"\n{inside} floors inside the 3% gate, {len(outside)} outside"
          + (f", {unmeasured} could not be measured" if unmeasured else ""))
    if outside:
        print("\nA floor outside the gate has no comparable word score (handoff 7y):"
              "\nfix the count before trusting any number measured against it.")


if __name__ == "__main__":
    main()
