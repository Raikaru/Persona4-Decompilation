"""Re-probe every parked `#ifdef NON_MATCHING` body against a fixed set of pragmas.

Parked bodies accumulate over a campaign, and a lever discovered later never gets
applied to the ones parked before it.  This walks the guarded bodies in one file,
compiles each one with each pragma wrapper in turn, and reports any that beat the
body's current measured nd.

usage:
    python tools/park_probe.py <file> [<file> ...]
    python tools/park_probe.py <file> --only func_00247770
    python tools/park_probe.py <file> --apply func_00247770=cse_off

The file is always restored unless `--apply` names a function and a wrapper.  The
wrappers carry `measured` comments documenting their optimization settings;
these explain H003 advisories but never waive assembly integrity checks.
"""

import argparse
import json
import pathlib
import re
import subprocess
import sys

MARKER_RE = re.compile(r"^\s*//\s*FUN_([0-9A-Fa-f]{8})\s+NONMATCHING\s*$")

WRAPPERS = {
    # The body exactly as committed, so a note can record what it really measures.
    "plain": ("", ""),
    # Document both the changed setting and its restoration for scope review.
    "cse_off": (
        "/* measured: retail re-issues a value b210 would hoist into a saved\n"
        "   register; disabling common-subexpression sharing restores that. */\n"
        "#pragma opt_common_subs off\n",
        "\n/* measured: closes the scope above at the file's -O2 baseline. */\n"
        "#pragma opt_common_subs on",
    ),
    "loopinv": (
        "/* measured: retail materialises a loop-invariant value in the preheader\n"
        "   where plain -O2 rematerialises it in the body. */\n"
        "#pragma opt_loop_invariants on\n",
        "\n/* measured: closes the scope above at the file's -O2 baseline. */\n"
        "#pragma opt_loop_invariants off",
    ),
    "cse_off_loopinv": (
        "/* measured: retail both hoists a loop invariant and re-issues a masked\n"
        "   value that b210 would share; both pragmas are needed together. */\n"
        "#pragma opt_common_subs off\n#pragma opt_loop_invariants on\n",
        "\n/* measured: closes both scopes above at the file's -O2 baseline. */\n"
        "#pragma opt_loop_invariants off\n"
        "/* measured: closes both scopes above at the file's -O2 baseline. */\n"
        "#pragma opt_common_subs on",
    ),
    "sched": (
        "/* measured: retail fills delay slots this function leaves empty at -O2. */\n"
        "#pragma schedule on\n",
        "\n/* measured: closes the scope above at the file's -O2 baseline. */\n"
        "#pragma schedule off",
    ),
    "sched_off": (
        "/* measured: retail interleaves a stack-address materialisation with the\n"
        "   surrounding stores; b210's scheduler sinks it to just before the call. */\n"
        "#pragma schedule off\n",
        "\n/* measured: closes the scope above at the file's -O2 baseline. */\n"
        "#pragma schedule on",
    ),
    "nobl": (
        "/* measured: b210 emits a branch-likely where retail uses a plain branch. */\n"
        "#pragma no_branch_likely on\n",
        "\n/* measured: closes the scope above at the file's -O2 baseline. */\n"
        "#pragma no_branch_likely off",
    ),
    "sched_cse_off": (
        "/* measured: retail both fills delay slots this function leaves empty and\n"
        "   re-issues a value b210 would share; both pragmas are needed. */\n"
        "#pragma schedule on\n#pragma opt_common_subs off\n",
        "\n/* measured: closes both scopes above at the file's -O2 baseline. */\n"
        "#pragma opt_common_subs on\n"
        "/* measured: closes both scopes above at the file's -O2 baseline. */\n"
        "#pragma schedule off",
    ),
    "sched_loopinv": (
        "/* measured: retail fills delay slots and hoists a loop invariant into the\n"
        "   preheader; both pragmas are needed together. */\n"
        "#pragma schedule on\n#pragma opt_loop_invariants on\n",
        "\n/* measured: closes both scopes above at the file's -O2 baseline. */\n"
        "#pragma opt_loop_invariants off\n"
        "/* measured: closes both scopes above at the file's -O2 baseline. */\n"
        "#pragma schedule off",
    ),
    # -O1 does far less coalescing and redundant-operation elimination than -O2,
    # so it is the lever for a body whose object is a few words SHORT because
    # b210 folded something retail kept separate (a missing andi, a missing move,
    # two live values collapsed into one register). Measured on func_00108950:
    # nd 162 at -O2, nd 17 at -O1; and it turned func_0024a710 byte-exact.
    "o1": (
        "/* measured: -O2 coalesces two values retail keeps in separate registers\n"
        "   and folds a mask retail re-issues; level 1 does neither. */\n"
        "#pragma optimization_level 1\n",
        "\n/* measured: closes the level 1 scope above at the file's -O2 baseline. */\n"
        "#pragma optimization_level 2",
    ),
    "o3": (
        "/* measured: this body needs -O3; at -O2 b210 declines an optimisation\n"
        "   retail performed. */\n"
        "#pragma optimization_level 3\n",
        "\n/* measured: closes the level 3 scope above at the file's -O2 baseline. */\n"
        "#pragma optimization_level 2",
    ),
    "o1_sched": (
        "/* measured: level 1 keeps the values retail keeps separate, and retail\n"
        "   also fills delay slots this body leaves empty; both are needed. */\n"
        "#pragma optimization_level 1\n#pragma schedule on\n",
        "\n#pragma schedule off\n"
        "/* measured: closes the level 1 scope above at the file's -O2 baseline. */\n"
        "#pragma optimization_level 2",
    ),
    "o1_nobl": (
        "/* measured: level 1 keeps the values retail keeps separate, and b210\n"
        "   emits a branch-likely where retail uses a plain branch. */\n"
        "#pragma optimization_level 1\n#pragma no_branch_likely on\n",
        "\n#pragma no_branch_likely off\n"
        "/* measured: closes the level 1 scope above at the file's -O2 baseline. */\n"
        "#pragma optimization_level 2",
    ),
}


def blocks(lines):
    """Yield (marker_index, body_start, body_end, block_end, func_name).

    body_start is the first line after `#ifdef NON_MATCHING`, body_end is the
    index of the `#else`, and block_end is the index of the closing `#endif`.
    Scoring a parked body means REPLACING the whole guarded block with the body
    alone: while the `#else INCLUDE_ASM` arm is present it is what compiles, and
    the verifier reports the function as ASM rather than measuring anything.
    """
    for i, line in enumerate(lines):
        m = MARKER_RE.match(line)
        if not m:
            continue
        j = i + 1
        while j < len(lines) and lines[j].strip().startswith("#pragma"):
            j += 1
        if j >= len(lines) or lines[j].strip() != "#ifdef NON_MATCHING":
            continue
        k = j + 1
        depth = 0
        while k < len(lines):
            s = lines[k].strip()
            if s == "#else" and depth == 0:
                break
            if s.startswith("#if"):
                depth += 1
            elif s == "#endif" and depth:
                depth -= 1
            k += 1
        if k >= len(lines):
            continue
        e = k
        while e < len(lines) and lines[e].strip() != "#endif":
            e += 1
        if e >= len(lines):
            continue
        yield i, j + 1, k, e, "func_%s" % m.group(1).lower()


def noted_nd(lines, marker_idx):
    for j in range(max(0, marker_idx - 24), marker_idx):
        m = re.search(r"Committed at nd (\d+)", lines[j])
        if m:
            return int(m.group(1))
    return None


def measure(path, func, tag):
    # A unique report per probe: reusing one path silently re-reads the previous
    # probe's numbers whenever verify.py fails to write, which reported a MATCH
    # that was really nd 24.
    out = pathlib.Path("build/_parkprobe_%s.json" % tag)
    if out.exists():
        out.unlink()
    subprocess.run(
        [sys.executable, "tools/verify.py", "--json", str(out), str(path)],
        capture_output=True,
    )
    if not out.exists():
        return 10**6
    try:
        data = json.load(open(out))
    except Exception:
        return 10**6
    for r in data["results"]:
        if r["name"] == func:
            if r["status"] == "MATCH":
                return -1
            # A body spliced in under a `NONMATCHING`-suffixed marker keeps that
            # status even though it is what compiled, so trust the diff instead.
            nd = r.get("normalized_diff")
            return 10**6 if nd is None else nd
    return 10**6


def run(path, only, apply_spec):
    p = pathlib.Path(path)
    orig = p.read_bytes()
    crlf = b"\r\n" in orig
    text = orig.decode("utf-8", "surrogateescape").replace("\r\n", "\n")
    lines = text.split("\n")

    def write(new_lines):
        out = "\n".join(new_lines)
        p.write_bytes(
            (out.replace("\n", "\r\n") if crlf else out).encode("utf-8", "surrogateescape")
        )

    found = list(blocks(lines))
    if only:
        found = [b for b in found if b[4] == only]
    if not found:
        print("%s: no guarded bodies%s" % (path, " for " + only if only else ""))
        return

    try:
        for marker_i, start, end, block_end, func in found:
            base = noted_nd(lines, marker_i)
            body = lines[start:end]
            # A body that already carries its own pragma bracket is left alone;
            # wrapping it again would nest brackets the lint cannot balance.
            if any(l.strip().startswith("#pragma") for l in body):
                continue
            results = {}
            for label, (pre, post) in WRAPPERS.items():
                spliced = (pre + "\n".join(body) + post).split("\n")
                new = lines[: marker_i + 1] + spliced + lines[block_end + 1 :]
                write(new)
                results[label] = measure(p, func, "%s_%s" % (func, label))
            write(lines)
            best = min(results, key=lambda k: results[k])
            got = results[best]
            flag = ""
            if got == -1:
                flag = "   <== MATCH"
            elif base is not None and got < base:
                flag = "   <== BETTER"
            print(
                "%-24s %-16s noted %-6s best %-16s %s%s"
                % (
                    pathlib.Path(path).name,
                    func,
                    base if base is not None else "-",
                    "%s=%s" % (best, "MATCH" if got == -1 else got),
                    {k: ("MATCH" if v == -1 else v) for k, v in results.items()},
                    flag,
                )
            )
    finally:
        if apply_spec:
            fname, label = apply_spec.split("=")
            for marker_i, start, end, block_end, func in blocks(lines):
                if func != fname:
                    continue
                pre, post = WRAPPERS[label]
                body = lines[start:end]
                # Re-wrap the guard. Scoring replaces the whole block with the
                # bare body so the body is what compiles, but KEEPING it that way
                # would leave a non-retail object linked into the image. The
                # pragmas travel INSIDE the `#ifdef NON_MATCHING` arm so they are
                # dead in the normal build and cannot leak into a neighbour.
                kept = (
                    [lines[marker_i]]
                    + lines[marker_i + 1 : start - 1]
                    + ["#ifdef NON_MATCHING"]
                    + (pre + "\n".join(body) + post).split("\n")
                    + lines[end : block_end + 1]
                )
                write(lines[:marker_i] + kept + lines[block_end + 1 :])
                print("applied %s to %s" % (label, fname))
                break
        else:
            write(lines)


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("files", nargs="+")
    ap.add_argument("--only")
    ap.add_argument("--apply")
    a = ap.parse_args(argv)
    for f in a.files:
        run(f, a.only, a.apply)


if __name__ == "__main__":
    main(sys.argv[1:])
