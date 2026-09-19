#!/usr/bin/env python3
"""Solve the signedness of a body's narrow memory reads against retail.

`tools/opclass.py` reports `lb` against `lbu` and `lh` against `lhu` as exact
paired deltas.  That makes signedness a finite discrete choice with a cheap,
sign-sensitive objective: flip one field's spelling, recompile, and read
whether the pair collapsed.  The differing-word score is a worse objective -
noisier, and it moves for unrelated reasons.

Three things keep this honest and cheap:

* **Most sites need no compiler.**  Where retail's own load opcode is visible
  at an offset that appears exactly once, the answer is read straight out of
  the disassembly and asserted.  Only genuinely ambiguous fields - an offset
  retail loads both ways, or one the candidate spells at several widths - go
  to compile-in-the-loop.
* **Coordinate descent, not 2^n.**  Flipping one field only changes that
  field's load sites, so a greedy pass is linear in fields.
* **Every accepted flip is gated on the instruction count.**  This is
  mechanically close to the banned "search spellings until a number improves";
  the difference is that each candidate here is a semantically meaningful type
  claim checked by a paired opcode delta.  Section 7u is the guard: a flip
  that improves the score while moving the count is rejected, because that is
  how a body inflates or deflates its way to a good-looking number.

A tie - both spellings producing identical bytes - is information, not
failure.  The signedness is unobservable at that site, so it is reported as
free and left at the project's convention rather than letting the search
thrash.

    python3 -E -s tools/solve_signedness.py src/foo.c func_00123456
    python3 -E -s tools/solve_signedness.py src/foo.c func_00123456 --apply
    python3 -E -s tools/solve_signedness.py src/foo.c func_00123456 --json facts.json

`--json` writes the accepted claims in the shape `tools/romwright_feedback.py`
pushes, so a solved field becomes an asserted fact for every later
reconstruction instead of being re-solved by hand.
"""

from __future__ import annotations

import argparse
import collections
import io
import json
import re
import sys
import tempfile
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "mwccgap"))

import fnalign  # noqa: E402
import verify  # noqa: E402
from measure_guarded import extract_guarded_body  # noqa: E402

NARROW = {"lb": ("s8", 1), "lbu": ("u8", 1), "lh": ("s16", 2), "lhu": ("u16", 2)}
SIGNED_OF = {"u8": "s8", "s8": "u8", "u16": "s16", "s16": "u16"}
# `*(u8 *)(base + 0x1C)` and `*(s16 *)(base + 4)`; the base may be any
# expression without parentheses, which covers every form in the tree.
CAST = re.compile(r"\*\(\s*(u8|s8|u16|s16)\s*\*\s*\)\s*\(")
TRAILING_OFFSET = re.compile(r"\+\s*(0x[0-9a-fA-F]+|\d+)\s*$")
# The other narrow-read spelling in this tree is a subscript on a typed
# array, `extern s8 D_0063EF40[];` then `D_0063EF40[i]`.  The element type of
# the declaration decides `lb` against `lbu`, so the declaration is the site.
ARRAY = re.compile(r"\bextern\s+(u8|s8|u16|s16)\s+(\w+)\s*\[\s*\]")
# A third spelling: cast-then-subscript, `((s16 *)hdr)[2]`.  The signedness
# lives in the cast, and every subscript through that cast shares it.
CAST_INDEX = re.compile(
    r"\(\(\s*(u8|s8|u16|s16)\s*\*\s*\)\s*([A-Za-z_]\w*)\s*\)\s*\[")
# And a fourth: a narrow pointer or array local, whose declaration decides
# every subscript and dereference of it.  The bracket group repeats to cover
# multi-dimensional arrays (`u8 colors[9][4]` in func_00112830); a single
# trailing `?` misses the second dimension and drops the site entirely.
LOCAL = re.compile(r"^\s*(u8|s8|u16|s16)\s+\*?\s*(\w+)\s*(?:\[[^\]]*\])*\s*;",
                   re.M)
LOAD = re.compile(r"^(lb|lbu|lh|lhu)\s+\$\w+,\s*(?:(-?0x[0-9a-fA-F]+|-?\d+))?\(")


def census(instructions: list[str]) -> collections.Counter:
    counts = collections.Counter()
    for text in instructions:
        head = text.split()[0] if text else ""
        if head in NARROW:
            counts[head] += 1
    return counts


def offsets_by_opcode(instructions: list[str]) -> dict[int, set[str]]:
    """Which narrow load opcodes touch each immediate offset."""
    seen: dict[int, set[str]] = {}
    for text in instructions:
        match = LOAD.match(text)
        if not match:
            continue
        opcode, immediate = match.group(1), match.group(2)
        offset = int(immediate, 0) if immediate else 0
        seen.setdefault(offset, set()).add(opcode)
    return seen


def mismatch(object_counts: collections.Counter,
             retail_counts: collections.Counter) -> int:
    return sum(abs(object_counts[op] - retail_counts[op]) for op in NARROW)


class Solver:
    def __init__(self, source: Path, function: str) -> None:
        self.source = source.resolve()
        self.function = function
        address = re.search(r"([0-9a-fA-F]{8})", function)
        if address is None:
            raise SystemExit(f"cannot read an address out of {function!r}")
        self.address = int(address.group(1), 16)
        self.marker = "FUN_" + address.group(1).upper()
        self.cfg = verify.load_config()
        windows = fnalign._read_json(fnalign.FUNCTION_WINDOWS)
        self.elf = fnalign.RetailElf(self.cfg["retail_elf"],
                                     fnalign._read_json(fnalign.TARGET),
                                     windows["sha1"])
        self.bounds = self._bounds(windows)
        self.scratch = Path(tempfile.mkdtemp(prefix="signedness_"))
        self.body = extract_guarded_body(self.source.read_text(errors="replace"),
                                         self.marker, function)

    def _bounds(self, windows: dict) -> list[int]:
        out = {int(k, 16) for k in windows["windows"]}
        out.update(int(k, 16) + v for k, v in windows["windows"].items() if v)
        for path in (REPO / "src").rglob("*.c"):
            try:
                out.update(m["addr"] for m in verify.scan_markers(path))
            except OSError:
                continue
        return sorted(out)

    def compile(self, body: str) -> tuple[list[str], bytes]:
        candidate = self.scratch / f"{self.function}.c"
        candidate.write_text(body)
        # A rejected trial is expected to fail to compile, and mwcc is loud
        # about it; the caller turns the exception into a recorded reject, so
        # the diagnostics would only bury the report.
        noise = io.StringIO()
        with redirect_stdout(noise), redirect_stderr(noise):
            obj, _relocations = fnalign._object_for(self.source, self.function,
                                                    candidate, self.cfg)
        return fnalign.decode(obj, 0), obj

    def retail(self) -> list[str]:
        window = fnalign.window_for(self.address, self.bounds)
        return fnalign.decode(self.elf.bytes_at(self.address, window), self.address)


def groups(body: str) -> dict[tuple[str, int], list[tuple[int, str]]]:
    """Source sites keyed by (base expression, offset).

    Two spellings qualify: a cast-and-offset dereference, whose offset lets
    retail answer directly; and a typed array declaration, whose element type
    decides every subscript on it at once.  Array declarations get offset -1,
    which no real offset uses, so they sort first and are never confused with
    a site retail can name.
    """
    found: dict[tuple[str, int], list[tuple[int, str]]] = {}
    for match in CAST.finditer(body):
        # The base is frequently itself parenthesised - `*(u8 *)(p +
        # (u32)f() + col + 0x59)` - so walk to the matching close paren
        # rather than trying to express nesting in the pattern.
        depth, index = 1, match.end()
        while index < len(body) and depth:
            depth += (body[index] == "(") - (body[index] == ")")
            index += 1
        inner = body[match.end():index - 1]
        tail = TRAILING_OFFSET.search(inner)
        if not tail:
            continue
        key = (inner[:tail.start()].strip(), int(tail.group(1), 0))
        found.setdefault(key, []).append((match.start(1), match.group(1)))
    for match in ARRAY.finditer(body):
        spelling, name = match.group(1), match.group(2)
        found.setdefault((name + "[]", -1), []).append((match.start(1), spelling))
    for match in CAST_INDEX.finditer(body):
        spelling, name = match.group(1), match.group(2)
        found.setdefault((f"(({spelling} *){name})[]", -1), []).append(
            (match.start(1), spelling))
    for match in LOCAL.finditer(body):
        spelling, name = match.group(1), match.group(2)
        found.setdefault((name + " (local)", -1), []).append(
            (match.start(1), spelling))
    return found


def rewrite(body: str, sites: list[tuple[int, str]],
            target: str | None = None) -> str:
    """Rewrite each site to TARGET, or to the opposite signedness if None."""
    out = body
    for position, spelling in sorted(sites, reverse=True):
        want = target or SIGNED_OF[spelling]
        out = out[:position] + want + out[position + len(spelling):]
    return out


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("source")
    parser.add_argument("function")
    parser.add_argument("--apply", action="store_true",
                        help="write the accepted flips back into the owner file")
    parser.add_argument("--json", metavar="PATH",
                        help="write accepted claims for tools/romwright_feedback.py")
    args = parser.parse_args()

    solver = Solver(Path(args.source), args.function)
    retail_text = solver.retail()
    retail_counts, retail_offsets = census(retail_text), offsets_by_opcode(retail_text)
    base_text, _base_obj = solver.compile(solver.body)
    base_counts = census(base_text)
    base_length = len(base_text)
    start = mismatch(base_counts, retail_counts)

    print(f"{solver.function}: retail "
          + ", ".join(f"{op} {retail_counts[op]}" for op in NARROW))
    print(f"{' ' * len(solver.function)}  object "
          + ", ".join(f"{op} {base_counts[op]}" for op in NARROW)
          + f"   mismatch {start}")
    if not start:
        print("\nnothing to solve: every narrow load already agrees with retail")
        return

    candidates = groups(solver.body)
    if not candidates:
        print("\nno `*(u8 *)(base + off)` style accesses found; "
              "this body spells its narrow reads some other way")
        return

    body, counts, current = solver.body, base_counts, start
    asserted: list[dict] = []
    free: list[str] = []
    rejected: list[str] = []
    # `solver.compile` writes into a scratch copy of the owning TU, so a
    # failed trial leaves the tree untouched; only `--apply` writes back.

    for (base, offset), sites in sorted(candidates.items(), key=lambda kv: kv[0][1]):
        if not current:
            break
        spellings = {spelling for _, spelling in sites}
        spelling = sites[0][1]
        width = 1 if spelling.endswith("8") else 2
        # Phase 1: retail names the answer outright when this offset is loaded
        # exactly one way and that way disagrees with the source.
        observed = set() if offset < 0 else retail_offsets.get(offset, set())
        direct = {op for op in observed if NARROW[op][1] == width}
        wanted = {NARROW[op][0] for op in direct}
        target: str | None = None
        if len(wanted) == 1 and (spelling not in wanted or len(spellings) > 1):
            # Also covers a group the source spells inconsistently: retail
            # reads this offset one way, so every site should agree with it.
            target = sorted(wanted)[0]
            reason = f"retail loads +{offset:#x} only as {sorted(direct)[0]}"
            if all(sp == target for sp in spellings):
                continue
        elif len(wanted) == 1:
            continue                      # already agrees; nothing to do
        else:
            reason = "ambiguous at the site; decided by recompiling"

        trial = rewrite(body, sites, target)
        try:
            text, _obj = solver.compile(trial)
        except BaseException:
            # A flip that does not compile is still information: the type is
            # load-bearing somewhere else, usually a pointer passed to a
            # callee or compared against a differently-signed pointer.  Say
            # so rather than dying, and leave the site alone.
            rejected.append(f"{base}: flipping to "
                            f"{target or SIGNED_OF[sites[0][1]]} does not compile; "
                            "the type is constrained by a use elsewhere")
            continue
        trial_counts = census(text)
        trial_mismatch = mismatch(trial_counts, retail_counts)
        shown = target or SIGNED_OF[spelling]
        label = (f"{base} {spelling} -> {shown}" if offset < 0 else
                 f"{base} + {offset:#x} {'/'.join(sorted(spellings))} -> {shown}")

        if len(text) != base_length:
            rejected.append(f"{label}: instruction count moved "
                            f"{base_length} -> {len(text)} (section 7u)")
            continue
        if text == base_text:
            free.append(f"{label}: identical bytes, signedness unobservable here")
            continue
        if trial_mismatch < current:
            body, counts, current = trial, trial_counts, trial_mismatch
            asserted.append({"function": f"{solver.address:08x}", "offset": offset,
                             "width": width, "type": shown,
                             "reason": reason})
            print(f"  accept  {label}   mismatch -> {trial_mismatch}")
        else:
            rejected.append(f"{label}: mismatch {current} -> {trial_mismatch}")

    print(f"\nmismatch {start} -> {current} over {len(candidates)} candidate fields")
    for row in free:
        print(f"  free    {row}")
    for row in rejected:
        print(f"  reject  {row}")

    if args.json:
        Path(args.json).write_text(json.dumps(asserted, indent=2))
        print(f"\nwrote {len(asserted)} claims to {args.json}")
    if args.apply and body != solver.body:
        text = solver.source.read_text(errors="replace")
        solver.source.write_text(text.replace(solver.body, body, 1))
        print(f"\napplied {len(asserted)} flips to {args.source}")
    elif args.apply:
        print("\nnothing to apply")


if __name__ == "__main__":
    main()
