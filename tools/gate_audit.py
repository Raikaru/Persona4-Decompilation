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


def reason_for(exc: BaseException) -> str:
    """Say WHY a floor could not be measured, in a few words.

    A bare count of unmeasurable floors is useless: it reads like a tolerable
    rounding error rather than the "this body has not compiled for weeks"
    that it usually is.  The common causes are worth distinguishing - a body
    that does not compile is a defect to repair, while a bare marker over an
    INCLUDE_ASM row is simply not a floor yet.
    """
    text = " ".join(str(exc).split())
    if "Error compiling" in text or "command failed" in text:
        return "guarded body does not compile"
    if "could not find a definition" in text:
        return "no body or INCLUDE_ASM row found"
    if "symbol not present in object" in text:
        return "no guarded body: marker sits directly on INCLUDE_ASM"
    return (type(exc).__name__ + ": " + text[:60]) if text else type(exc).__name__


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
    inside, outside, unmeasured, split, cancelled = 0, [], [], [], []
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
                except BaseException as exc:
                    unmeasured.append((name, str(path.relative_to(REPO)),
                                       reason_for(exc)))
                    continue
                # Trim retail's zero alignment tail the way fnalign does, so
                # the comparison is instructions against instructions.
                while (len(retail) >= 4 and not any(retail[-4:])
                       and len(retail) > len(body)):
                    retail = retail[:-4]
                want, got = len(retail) // 4, len(body) // 4
                if not want:
                    unmeasured.append((name, str(path.relative_to(REPO)),
                                       "retail window is empty"))
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
                        # `delete` runs and `insert` runs cancel (handoff
                        # 7aa).  Only pure runs count - a `replace` is a
                        # diverged region, not missing code.
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
                        # An EXACT count hides cancellation best of all,
                        # because it reads as finished.  func_001265a0 sat at
                        # 4404 against 4404 while calling `__fixsfdi` where
                        # retail has cvt.w.s/mfc1/nop/dsll32/dsra32 - one
                        # instruction short there, one long somewhere else.
                        # No run threshold catches that; the totals do.
                        missing = sum(i2 - i1 for t, i1, i2, _j1, _j2 in script
                                      if t == "delete")
                        extra = sum(j2 - j1 for t, _i1, _i2, j1, j2 in script
                                    if t == "insert")
                        if got == want and missing and extra:
                            cancelled.append((missing + extra, missing, extra,
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
    for _key, missing, extra, want, name, source in sorted(cancelled, reverse=True):
        print(f"  CANCELLED  missing {missing:4d}  extra {extra:4d}  of {want:5d}"
              f"  {name}  {source}")
    if cancelled:
        print(f"\n{len(cancelled)} floors match retail's count EXACTLY while still"
              "\nmissing instructions and emitting others - two errors cancelling."
              "\nAn exact count reads as finished, so these hide better than any"
              "\nfloor outside the band.  func_001265a0 was 4404 against 4404 while"
              "\ncalling __fixsfdi where retail has cvt.w.s/mfc1/nop/dsll32/dsra32.")
    # A marker sitting straight on an INCLUDE_ASM row has no body to measure.
    # That is an honest "not started", not a defect, and lumping the two
    # together is what let a body that had stopped compiling hide among them.
    bodyless = [u for u in unmeasured if u[2].startswith("no guarded body")]
    broken = [u for u in unmeasured if not u[2].startswith("no guarded body")]
    for name, source, why in sorted(broken):
        print(f"  BROKEN  {name}  {source}  ({why})")
    print(f"\n{inside} floors inside the 3% gate, {len(outside)} outside"
          + (f", {len(broken)} broken" if broken else "")
          + (f", {len(bodyless)} markers with no body" if bodyless else ""))
    if outside:
        print("\nA floor outside the gate has no comparable word score (handoff 7y):"
              "\nfix the count before trusting any number measured against it.")
    if broken:
        print("\nA BROKEN floor is INVISIBLE, which is worse than a bad one: no score,"
              "\nno gate, no evidence it still compiles.  A guarded body is never built"
              "\nby tools/build.py, so a prototype added elsewhere in the file can break"
              "\nit and nothing will say so - func_0023e6f0 sat broken this way until a"
              "\ntree-wide audit named it.  Repair it or delete it; do not ignore it.")


if __name__ == "__main__":
    main()
