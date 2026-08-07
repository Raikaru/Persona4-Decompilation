"""Score candidate bodies for a function whose marker is already parked.

`tools/try_bare.py` only handles a bare `INCLUDE_ASM` line.  Once a function
carries a `// FUN_XXXXXXXX NONMATCHING` marker with an `#ifdef NON_MATCHING`
guard, the guarded arm is not what compiles, so a candidate has to replace the
WHOLE block -- marker through `#endif` -- to be measured at all.

usage:
    python tools/try_parked.py <file> <func> <cands.json> [--apply LABEL]

`<cands.json>` maps a label to a whole function definition (pragmas included if
the body needs them).  The file is always restored unless `--apply` names a
label, in which case that body is left in place, still guarded, with the marker
and the surrounding note untouched.  Line endings are preserved.

A body that reaches nd 0 is a MATCH: drop the ` NONMATCHING` suffix from the
marker and the guard by hand, then re-run `tools/verify.py` -- the verifier
reports `STALE_NONMATCHING` until you do.
"""

import json
import pathlib
import subprocess
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import park_probe  # noqa: E402  (same directory, shares the block parser)


def measure(path, func, tag):
    out = pathlib.Path("build/_tryparked_%s.json" % tag)
    if out.exists():
        out.unlink()
    subprocess.run(
        [sys.executable, "tools/verify.py", "--json", str(out), str(path)],
        capture_output=True,
    )
    if not out.exists():
        return None, "NO_REPORT"
    data = json.load(open(out))
    for r in data["results"]:
        if r["name"] == func:
            return r.get("normalized_diff"), r["status"]
    return None, "GONE"


def main(argv):
    path, func, cands = argv[0], argv[1], argv[2]
    apply_label = argv[argv.index("--apply") + 1] if "--apply" in argv else None

    p = pathlib.Path(path)
    orig = p.read_bytes()
    crlf = b"\r\n" in orig
    lines = orig.decode("utf-8", "surrogateescape").replace("\r\n", "\n").split("\n")

    block = [b for b in park_probe.blocks(lines) if b[4] == func]
    if not block:
        sys.exit("%s: no guarded body for %s (use try_bare.py for a bare marker)" % (path, func))
    marker_i, _, _, block_end, _ = block[0]

    def write(new_lines):
        out = "\n".join(new_lines)
        p.write_bytes(
            (out.replace("\n", "\r\n") if crlf else out).encode("utf-8", "surrogateescape")
        )

    bodies = json.load(open(cands))
    best = (10**6, None)
    try:
        for label, body in bodies.items():
            # Measure UNGUARDED: inside `#ifdef NON_MATCHING` the INCLUDE_ASM arm
            # is what compiles, so the verifier would report ASM at nd 0 for any
            # body at all -- a convincing false MATCH.
            write(lines[: marker_i + 1] + body.split("\n") + lines[block_end + 1 :])
            nd, status = measure(p, func, "%s_%s" % (func, label))
            score = 10**6 if nd is None else nd
            print(
                "  %-22s %-18s nd=%s%s"
                % (label, status, nd, "   <== MATCH" if score == 0 else "")
            )
            if score < best[0]:
                best = (score, label)
    finally:
        if apply_label is not None:
            body = bodies[apply_label]
            guarded = (
                ["#ifdef NON_MATCHING"]
                + body.split("\n")
                + ["#else", lines[block_end - 1], "#endif"]
            )
            write(lines[: marker_i + 1] + guarded + lines[block_end + 1 :])
            print("applied %s" % apply_label)
        else:
            write(lines)
    print("best: %s (nd %s)" % (best[1], best[0]))


if __name__ == "__main__":
    main(sys.argv[1:])
