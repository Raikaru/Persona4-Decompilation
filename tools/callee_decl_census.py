#!/usr/bin/env python3
"""Rank still-open functions by how many of their callees are mis-declared.

Four of the six closures in the 12d8fc07 wave came from a DECLARATION rather
than from the function's own body: a callee's extern declared its parameters at
the wrong width or signedness, and the caller therefore emitted the wrong mask,
sign-extend or argument materialisation order.

An earlier campaign-wide declaration sweep closed nothing, because it compared
every declaration against every definition and most of those disagreements are
harmless old-style C. This is the narrow version that actually predicts a fix:

  * only callees whose DEFINITION is a verified MATCH -- a matched definition is
    ground truth, so a caller that disagrees with it is objectively wrong;
  * only callers that are still on INCLUDE_ASM -- the ones with something to win;
  * only real signature disagreements, ignoring parameter names, `extern`, and
    pure spelling differences.

Output ranks open functions by mis-declared callee count, which is the order to
spend lanes in.

    python tools/callee_decl_census.py [--report build/verify_wave.json] [--top 40]
"""
import argparse
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402

# A definition is a signature followed by a brace; a declaration ends in `;`.
DEFN = re.compile(
    r"^[A-Za-z_][\w \*]*?\b(func_[0-9a-f]{8})\s*\(([^;{]*)\)\s*\{", re.M)
DECL = re.compile(
    r"^\s*(?:extern\s+)?[A-Za-z_][\w \*]*?\b(func_[0-9a-f]{8})\s*\(([^;{]*)\)\s*;", re.M)
CALL = re.compile(r"\b(func_[0-9a-f]{8})\s*\(")


def params(text: str) -> str:
    """A parameter list normalised for comparison: types only, no names."""
    text = re.sub(r"\s+", " ", text).strip()
    if text in ("", "void"):
        return "void"
    out = []
    for part in text.split(","):
        part = part.strip()
        # Drop the parameter NAME when a type precedes it. A lone token is a
        # type (old-style or a typedef), so it is kept whole.
        tokens = part.replace("*", " * ").split()
        if len(tokens) > 1 and re.fullmatch(r"[A-Za-z_]\w*", tokens[-1]):
            tokens = tokens[:-1]
        out.append(" ".join(tokens))
    return ", ".join(out)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", default="build/verify_wave.json")
    ap.add_argument("--top", type=int, default=40)
    args = ap.parse_args()

    rows = json.load(open(REPO / args.report))["results"]
    status = {r["name"]: r for r in rows}
    matched = {r["name"] for r in rows if r["status"] == "MATCH"}
    open_fp = {r["name"]: r["file"].replace("\\", "/") for r in rows
               if r["status"] == "ASM"
               and not V.is_third_party(r["file"])
               and not V.is_vendor_address(r.get("addr"))}

    # Ground truth: the parameter list of every MATCHED definition.
    truth: dict[str, str] = {}
    bodies: dict[Path, str] = {}
    for src in sorted((REPO / "src").rglob("*.c")):
        if V.is_generated(src):
            continue
        try:
            text = src.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        bodies[src] = text
        for name, plist in DEFN.findall(text):
            if name in matched:
                truth[name] = params(plist)

    # Per file, the declarations in force and the calls each open function makes.
    bad_by_open: dict[str, list[tuple[str, str, str]]] = defaultdict(list)
    for src, text in bodies.items():
        decls = {n: params(p) for n, p in DECL.findall(text)}
        wrong = {n: d for n, d in decls.items()
                 if n in truth and d != truth[n]}
        if not wrong:
            continue
        # Attribute each wrong declaration to the open functions that call it.
        # The body must be bounded by BRACE MATCHING, not by a fixed slice: a
        # 20 KB window spills into neighbouring functions and credits their
        # calls to this one, which inflated one target's count from 6 to 15.
        for name, plist in DEFN.findall(text):
            if name not in open_fp:
                continue
            start = text.index("{", text.index(plist, text.index(name)))
            depth, end = 0, start
            for i in range(start, len(text)):
                if text[i] == "{":
                    depth += 1
                elif text[i] == "}":
                    depth -= 1
                    if depth == 0:
                        end = i
                        break
            for callee in set(CALL.findall(text[start:end])):
                if callee in wrong:
                    bad_by_open[name].append(
                        (callee, wrong[callee], truth[callee]))
        # Functions still on INCLUDE_ASM have no body here, so also report the
        # file-level count -- those declarations are wrong for whoever adopts it.
        for name in open_fp:
            if open_fp[name] == src.relative_to(REPO).as_posix() and name not in bad_by_open:
                bad_by_open.setdefault(name, [])

    ranked = sorted(((len(v), k, v) for k, v in bad_by_open.items() if v),
                    reverse=True)
    print("matched definitions used as ground truth: %d" % len(truth))
    print("open first-party functions calling a mis-declared callee: %d"
          % len(ranked))
    for count, name, items in ranked[:args.top]:
        r = status[name]
        print("\n%-18s %-44s window=%s  (%d mis-declared callee(s))"
              % (name, open_fp[name], r.get("window"), count))
        for callee, declared, real in items[:6]:
            print("    %-18s declared (%s)" % (callee, declared))
            print("    %-18s defined  (%s)" % ("", real))
    return 0


if __name__ == "__main__":
    sys.exit(main())
