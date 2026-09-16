#!/usr/bin/env python3
"""Search the mechanical part of a candidate's shape: declaration order and pragmas.

Two source properties move MWCC output without changing a line of logic:

* the order of the local declarations, which decides which variable gets which
  callee-saved or temporary register, and
* a scoped optimisation pragma, which decides whether a fold, a hoist or a
  dead store survives.

Both are pure search, and searching them by hand is slow: `verify`/`fndiff`
reload the retail ELF and rescan every marker under `src/` for each candidate,
about nine seconds. This tool loads that state once and splices candidates
in-process, which costs about a sixth of a second each, so a few hundred
orders take a minute instead of most of an hour.

    python tools/probe_search.py src/foo.c func_00123456 --candidate body.c
    python tools/probe_search.py src/foo.c func_00123456 --candidate body.c \
        --declarations 400 --pragmas --out /tmp/best.c

The candidate is never installed and the tracked source is never written. The
exit status is 0 if the best candidate matched, otherwise 1.
"""
from __future__ import annotations

import argparse
import itertools
import random
import re
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import fnalign  # noqa: E402
import probe_variants as probe  # noqa: E402
import verify  # noqa: E402


DECLARATION_RE = re.compile(
    r"^[ \t]+(?:const\s+|static\s+|volatile\s+)*"
    r"[A-Za-z_][\w]*(?:\s*\*+\s*|\s+)\**[A-Za-z_]\w*(?:\[[^\]]*\])?\s*;\s*$"
)
# Pragmas whose effect on b210 output is documented in the matching handoff.
PRAGMAS = (
    "opt_propagation off",
    "opt_dead_assignments off",
    "opt_common_subs off",
    "opt_loop_invariants on",
    "opt_lifetimes off",
    "opt_strength_reduction off",
    "optimize_for_size off",
    "opt_unroll_loops off",
)


class Evaluator:
    """Scores candidate bodies for one function without rebuilding the world."""

    def __init__(self, source: Path, function: str) -> None:
        self.source, self.function = source.resolve(), function
        self.cfg = verify.load_config()
        target = verify._read_json(verify.TARGET)
        windows = verify._read_json(verify.FUNCTION_WINDOWS)
        if windows.get("program") != "SLUS_217.82" or windows.get("sha1") != target["elf"]["sha1"]:
            verify._die("slus21782_functions.json does not describe the configured target")
        retail = verify.RetailElf(self.cfg["retail_elf"], target, windows["sha1"])
        self.marker = probe.address_of(function)
        self.address = int(self.marker[4:], 16)
        boundaries = {int(item, 16) for item in windows["windows"]}
        boundaries.update(int(item, 16) + size
                          for item, size in windows["windows"].items() if size)
        for path in (verify.REPO / "src").rglob("*.c"):
            try:
                boundaries.update(marker["addr"] for marker in verify.scan_markers(path))
            except OSError:
                continue
        window = verify.window_for(self.address, sorted(boundaries))
        if window is None or window > 0x10000:
            verify._die(f"no plausible function window at {self.address:#010x}")
        self.retail_bytes = retail.bytes_at(self.address, window)
        trimmed = self.retail_bytes
        while len(trimmed) >= 4 and not any(trimmed[-4:]):
            trimmed = trimmed[:-4]
        self.retail_text = fnalign.decode(trimmed, self.address)
        self.text = probe._read_text(self.source)
        self.newline = probe._newline_for(self.source.read_bytes())
        self.start, self.end = probe.region_for(self.text, self.marker, function)
        self._tmp = tempfile.TemporaryDirectory(prefix="p4search_")
        self._obj = Path(self._tmp.name) / "out.o"

    def score(self, body: str) -> tuple[int | None, int | None]:
        """(differing words, edit instructions); (None, None) if it did not compile."""
        patched = probe.splice_region(
            self.text, self.start, self.end,
            probe._normalise_candidate(body, self.newline), self.newline)
        with probe.scratch_source(self.source) as scratch:
            scratch.write_text(patched)
            compiled, _ = probe._compile_in_context(scratch, self.source, self.cfg, self._obj)
            if not compiled:
                return None, None
            try:
                emitted, relocations = verify.ObjectFile(self._obj).function(self.function)
            except KeyError:
                return None, None
        mask = verify.mask_bytes(max(len(emitted), len(self.retail_bytes)), relocations)
        words = 0
        for offset in range(0, max(len(emitted), len(self.retail_bytes)), 4):
            mine, theirs = emitted[offset:offset + 4], self.retail_bytes[offset:offset + 4]
            if offset >= len(emitted) and not any(theirs):
                continue
            if any((mine[i] if i < len(mine) else None) != (theirs[i] if i < len(theirs) else None)
                   for i in range(4) if offset + i < len(mask) and not mask[offset + i]):
                words += 1
        _, edits, _ = fnalign.align(
            self.retail_text, fnalign.decode(emitted, 0),
            {relocation["offset"] // 4 for relocation in relocations})
        return words, edits


def declaration_block(body: str) -> tuple[list[str], int, int]:
    """The longest run of permutable local declarations in the function body.

    A body often opens with a local struct or typedef and with block-scope
    callee prototypes. Neither is register-allocated, and reordering a
    declaration past a type it uses would not compile, so both are skipped and
    the run of plain one-line declarations after them is returned.
    """
    lines = body.split("\n")
    opening = next((index for index, line in enumerate(lines)
                    if line.rstrip().endswith("{")), None)
    if opening is None:
        return [], 0, 0
    best: tuple[int, int] = (0, 0)
    index, depth = opening + 1, 0
    run_start: int | None = None
    while index < len(lines):
        line = lines[index]
        stripped = line.strip()
        depth += line.count("{") - line.count("}")
        if depth > 0 or (run_start is None and not stripped):
            run_start = None
            index += 1
            continue
        if DECLARATION_RE.match(line) and "(" not in line:
            if run_start is None:
                run_start = index
            if index + 1 - run_start > best[1] - best[0]:
                best = (run_start, index + 1)
        elif stripped and not stripped.startswith(("/*", "*", "//")):
            if run_start is not None and not stripped.startswith(("extern ", "typedef ", "struct ", "union ")):
                break
            run_start = None
        index += 1
    return lines[best[0]:best[1]], best[0], best[1]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("file")
    parser.add_argument("function")
    parser.add_argument("--candidate", required=True, help="body to search around")
    parser.add_argument("--declarations", type=int, default=0,
                        help="try this many declaration orders (0 = skip)")
    parser.add_argument("--pragmas", action="store_true",
                        help="try each documented pragma on the best body")
    parser.add_argument("--seed", type=int, default=0)
    parser.add_argument("--out", help="write the best body here")
    args = parser.parse_args()

    source, candidate = Path(args.file), Path(args.candidate)
    if not source.is_file():
        verify._die(f"source file does not exist: {args.file}")
    if not candidate.is_file():
        verify._die(f"candidate file does not exist: {args.candidate}")

    evaluator = Evaluator(source, args.function)
    body = candidate.read_text()
    best_body, best = body, evaluator.score(body)
    if best[0] is None:
        verify._die("the candidate itself does not compile")
    print(f"start {best[0]} words, {best[1]} edit instructions")

    if args.declarations:
        declarations, start, end = declaration_block(best_body)
        if len(declarations) < 2:
            print("no declaration block to permute")
        else:
            lines = best_body.split("\n")
            random.seed(args.seed)
            seen: set[tuple[int, ...]] = set()
            orders = [tuple(range(len(declarations)))]
            if len(declarations) <= 6:
                orders += list(itertools.permutations(range(len(declarations))))
            while len(orders) < args.declarations:
                order = list(range(len(declarations)))
                random.shuffle(order)
                orders.append(tuple(order))
            for order in orders[:args.declarations]:
                if order in seen:
                    continue
                seen.add(order)
                trial = "\n".join(lines[:start] + [declarations[i] for i in order] + lines[end:])
                score = evaluator.score(trial)
                if score[0] is not None and score < best:
                    best, best_body = score, trial
                    print(f"  declarations -> {best[0]} words, {best[1]} edits")
                    if best[0] == 0:
                        break
            print(f"searched {len(seen)} declaration orders")

    if args.pragmas and best[0]:
        # Every pragma is measured against the same body: wrapping the running
        # best instead stacks them, and each later trial then reports the
        # earlier winner's score.
        unwrapped = best_body
        for pragma in PRAGMAS:
            trial = f"#pragma push\n#pragma {pragma}\n{unwrapped.rstrip()}\n#pragma pop\n"
            score = evaluator.score(trial)
            if score[0] is None:
                continue
            print(f"  {pragma:<28} {score[0]} words, {score[1]} edits")
            if score < best:
                best, best_body = score, trial

    print(f"best {best[0]} words, {best[1]} edit instructions")
    if args.out:
        Path(args.out).write_text(best_body)
        print(f"wrote {args.out}")
    return 0 if best[0] == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
