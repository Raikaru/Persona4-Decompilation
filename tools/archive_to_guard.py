#!/usr/bin/env python3
"""Reinstall archived near-miss bodies as `#ifdef NON_MATCHING` guarded blocks.

Waves archive their best candidate body to `docs/probe_archive/<LANE>_<addr>_body.c` and then
revert the source to bare `INCLUDE_ASM`. That is right for the tree -- an unproven
body must not ship -- but it hides the body from `tools/permute_sweep.py`, which
discovers its targets by scanning for `#ifdef NON_MATCHING`. The permuter needs a
starting body: from bare `INCLUDE_ASM` there is nothing to mutate.

This bridges the two. For every archive it finds the owning source file by marker
address, checks the function is currently bare `INCLUDE_ASM`, and rewrites it as

    // FUN_XXXXXXXX NONMATCHING
    #ifdef NON_MATCHING
    <archived body>
    #else
    INCLUDE_ASM("asm/nonmatchings/<unit>", func_xxxxxxxx);
    #endif

which is inert for the build (NON_MATCHING is never defined) and visible to the
sweep. When several archives target one address the largest is used, on the
assumption that the most developed body is the best permuter seed.

    python tools/archive_to_guard.py --list
    python tools/archive_to_guard.py --apply [--exclude src/a.c,src/b.c]
"""
import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify as V

REPO = Path(__file__).resolve().parent.parent
ADDR = re.compile(r"([0-9a-fA-F]{8})")
MEASURED = re.compile(r"^\s*/\*.*\*/\s*$")
MARKER_LINE = re.compile(r"^\s*//\s*FUN_[0-9A-Fa-f]{8}")
BANNED_PRAGMA = re.compile(
    r"^\s*#pragma\s+(optimization_level\s+[013]\b|schedule\s+off\b"
    r"|opt_common_subs\s+off\b|opt_loop_invariants\b)")


def archives() -> dict[str, Path]:
    """Best archive per address: the largest body wins."""
    by_addr: dict[str, list[Path]] = defaultdict(list)
    for path in sorted((REPO / "docs" / "probe_archive").glob("*_body.c")):
        match = ADDR.search(path.name)
        if match:
            by_addr[match.group(1).lower()].append(path)
    return {a: max(v, key=lambda p: p.stat().st_size) for a, v in by_addr.items()}


UNIT_BLOCK = re.compile(r"^#if defined\(P4_UNIT_([0-9A-Fa-f]{8})\)", re.M)
# m2c artefacts that mean the candidate is semantically WRONG, not merely
# untyped: `M2C_ERROR` is m2c's own "I could not translate this instruction"
# marker (it expands to 0), and `saved_reg_*` are pseudo-globals it invents
# when it cannot attribute a callee-saved register. Neither can match retail,
# so seeding them only burns permuter budget.
UNPORTABLE = ("M2C_ERROR", "saved_reg_", "M2C_TRAP_IF", "M2C_BREAK")

# The remaining artefacts -- M2C_UNK, M2C_FIELD, M2C_BITWISE and friends -- are
# merely UNTYPED, and tools/vendor/m2c/m2c_macros.h defines every one of them
# in 58 lines. The promoted units do not include that header, which is the sole
# reason 122 of 131 otherwise-clean candidates failed to compile. The prelude
# is inlined into each seed rather than included once per file because the
# sweep activates exactly one guarded block at a time: a file-scope prelude
# under its own guard would stay inactive and the body would not compile.
M2C_PRELUDE = """typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define CLZ(x) (0)"""

def generated_bodies() -> dict[str, tuple[str, str]]:
    """m2c candidate bodies from `src/generated/`, keyed by address.

    These are the counterpart to the archives: nobody has hand-ground them, so
    they are the population the permuter has any chance against. Candidates
    carrying an artefact from UNPORTABLE are skipped as semantically wrong;
    the rest get M2C_PRELUDE prepended so their remaining macros resolve.

    Candidate blocks carry their own `// FUN_` marker and `INCLUDE_ASM`
    fallback, exactly like the archives, so they go through the same stripping:
    splicing one verbatim produces a DUPLICATE marker, which `decomp_lint`
    reports as M001 and the gate's marker audit rejects.
    """
    out: dict[str, tuple[str, str]] = {}
    for path in sorted((REPO / "src" / "generated").rglob("*.c")):
        parts = UNIT_BLOCK.split(path.read_text(errors="replace"))
        for i in range(1, len(parts), 2):
            addr, body = parts[i].lower(), parts[i + 1].split("#endif")[0]
            if any(bad in body for bad in UNPORTABLE):
                continue
            lines = [l for l in body.splitlines()
                     if not l.lstrip().startswith("/* Candidate status:")
                     and not MARKER_LINE.match(l)
                     and not l.startswith("INCLUDE_ASM(")
                     and not l.lstrip().startswith("#pragma")
                     and l.strip() not in ("#ifdef NON_MATCHING", "#else")]
            note = ("/* measured: unmodified m2c candidate from src/generated,"
                    " installed as a permuter seed; not a verified body. */")
            body = "\n".join(lines).strip("\n")
            if "M2C_" in body:
                # The prelude must go in the NOTE, i.e. above the `// FUN_`
                # marker, not at the head of the body.  permute.scan_markers
                # associates a marker with the function on the line after it;
                # a body that starts with typedefs leaves the marker nameless,
                # and every permuter run on that seed dies with
                # "no // FUN_ marker for func_xxxxxxxx".  Measured: 447
                # first-party generated seeds were unusable for this reason.
                # The prelude is pure text substitution, so hoisting it cannot
                # change a byte of the object.
                note = note + "\n" + M2C_PRELUDE
            out[addr] = (note, body)
    return out


def body_text(path: Path) -> tuple[str, str]:
    """The archive's measurement note and its function body, separated.

    Archives are lane output, not clean fragments. Three things are dropped
    from the body:

    * the leading `/* measured: ... */` note, which describes the archive
      rather than the code -- it is returned separately, because it has to be
      re-emitted ABOVE the marker (see below);
    * an embedded `// FUN_XXXXXXXX` marker or `INCLUDE_ASM` fallback -- 27
      archives carry one, and splicing it duplicates a marker, which the gate's
      marker audit rejects and which makes verify.py score one function twice;
    * every `#pragma`. A lane's pragma bracket is only balanced in the file it
      was cut from, so re-splicing it silently re-pairs with the neighbouring
      function's bracket. A seed does not need them: the permuter re-derives
      the pragma state it wants.

    The note must be re-emitted above the marker because `decomp_lint`'s H003
    waiver is FUNCTION-scoped -- it looks six lines above the nearest enclosing
    `// FUN_` marker. Inserting a new marker makes it the nearest enclosing one
    for every banned pragma below it, orphaning justifications that were valid
    before. On this tree that alone turned a clean baseline into seven errors.
    """
    lines = path.read_text(errors="replace").splitlines()
    note, start, depth = [], 0, 0
    for i, line in enumerate(lines):
        stripped = line.strip()
        if depth == 0 and stripped.startswith("/*"):
            depth = 0 if stripped.endswith("*/") and len(stripped) > 3 else 1
            note.append(stripped)
            continue
        if depth:
            note.append(stripped)
            if stripped.endswith("*/"):
                depth = 0
            continue
        if stripped:
            start = i
            break
    kept = [l for l in lines[start:]
            if not MARKER_LINE.match(l) and not l.startswith("INCLUDE_ASM(")
            and not l.lstrip().startswith("#pragma")
            and l.strip() not in ("#ifdef NON_MATCHING", "#else", "#endif")]
    # A measurement note that mentions a pointer type ("parameter u8*/u32* forms")
    # carries a literal `*/` in its prose, which CLOSES the comment early and
    # makes the whole translation unit fail to parse. Measured: 56 archives in
    # code1_003c alone were unmeasurable for this reason, and lanes that pasted
    # such a note reported it as a mysterious unit-wide COMPILE_ERROR. Only the
    # final terminator may be a real one.
    text = "\n".join(note)
    if text.endswith("*/"):
        text = text[:-2].replace("*/", "* /") + "*/"
    else:
        text = text.replace("*/", "* /")
    return text, "\n".join(kept).strip("\n")


def sources() -> dict[Path, list[str]]:
    """Every buildable source file's lines, read once.

    Two exclusions. Lanes running concurrently create and delete temporary
    files inside src/, so a file that existed when the glob ran can be gone by
    the time it is read; those are never real targets. And `src/generated/`
    holds ~12,000 raw m2c CANDIDATE units that are not part of the build --
    they sort before `src/promoted/`, so a marker lookup that does not exclude
    them resolves to a file the compiler never sees.
    """
    out: dict[Path, list[str]] = {}
    for src in sorted((REPO / "src").rglob("*.c")):
        if src.name.startswith("tmp") or V.is_generated(src):
            continue
        try:
            out[src] = src.read_text(encoding="utf-8", errors="replace").splitlines()
        except OSError:
            continue
    return out


def locate(addr: str, cache: dict[Path, list[str]]) -> tuple[Path, int, str] | None:
    """The file, marker line index and INCLUDE_ASM line for a bare function."""
    name = "func_" + addr
    marker = "// FUN_" + addr.upper()
    for src, lines in cache.items():
        for i, line in enumerate(lines):
            if line.strip().rstrip(" NONMATCHING").strip() != marker:
                continue
            # Only bare INCLUDE_ASM is convertible: a live body is already better
            # than any archive, and a guarded one is already a sweep target.
            for j in range(i + 1, min(len(lines), i + 3)):
                if lines[j].startswith("INCLUDE_ASM(") and name in lines[j]:
                    return src, i, lines[j]
                if lines[j].strip() and not lines[j].startswith("/*"):
                    break
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--exclude", default="", help="comma-separated files to skip")
    ap.add_argument("--source", choices=("archives", "generated"),
                    default="archives",
                    help="archives = hand-ground lane output; generated = "
                         "untouched m2c candidates, which the permuter cracks "
                         "far more often")
    ap.add_argument("--max-lines", type=int, default=0,
                    help="skip bodies longer than this (0 = no limit)")
    args = ap.parse_args()

    skip = {s.strip() for s in args.exclude.split(",") if s.strip()}
    found, edits = [], defaultdict(list)
    cache = sources()

    if args.source == "generated":
        pool = generated_bodies()
    else:
        pool = {a: body_text(p) for a, p in archives().items()}

    for addr, (note, body) in pool.items():
        if args.max_lines and len(body.splitlines()) > args.max_lines:
            continue
        hit = locate(addr, cache)
        if hit is None:
            continue
        src, marker_line, include = hit
        rel = src.relative_to(REPO).as_posix()
        if rel in skip:
            continue
        found.append((rel, addr, "%d lines" % len(body.splitlines())))
        edits[src].append((marker_line, include, (note, body)))

    for rel, addr, name in sorted(found):
        print("%-44s func_%s  <- %s" % (rel, addr, name))
    print("%d archived body/bodies installable across %d file(s)"
          % (len(found), len(edits)))

    if not args.apply:
        return 0

    for src, items in edits.items():
        raw = src.read_bytes()
        lines = raw.decode("utf-8", errors="replace").splitlines()
        # Descending so earlier line numbers stay valid as we splice.
        for marker_line, include, (note, body) in sorted(items, reverse=True):
            end = next(i for i in range(marker_line + 1, len(lines))
                       if lines[i] == include)
            marker = lines[marker_line].rstrip()
            if not marker.endswith("NONMATCHING"):
                marker += " NONMATCHING"
            # The note goes ABOVE the marker: that is where decomp_lint's
            # function-scoped waiver looks, and it keeps every banned pragma
            # below this point justified as it was before the splice.
            block = note.splitlines() if note else [
                "/* measured: archived permuter seed; see the docs/probe_archive/ archive"
                " header for its object/window/normalized_diff. */"]
            block.append(marker)
            # The body is spliced line by line, never as one embedded string:
            # a multi-line element would keep LF inside a CRLF file.
            block += ["#ifdef NON_MATCHING", *body.splitlines(),
                      "#else", include, "#endif"]
            lines[marker_line:end + 1] = block
        # Path.write_text would translate "\n" to CRLF on Windows, and forcing
        # "\n" would flip the files that are committed CRLF. Either way every
        # line of the file changes. Rejoin with the newline the file already
        # uses and write bytes, so untouched lines stay byte-identical.
        eol = "\r\n" if b"\r\n" in raw else "\n"
        # Preserve whether the file ended with a newline. src/promoted/code1_0042.c
        # is committed WITHOUT one, so appending unconditionally rewrote its last
        # line every run and the declaration-environment check read that as a lost
        # declaration -- it blocked the wave gate four waves in a row.
        tail = eol if raw.endswith(eol.encode()) else ""
        src.write_bytes((eol.join(lines) + tail).encode("utf-8"))
        print("installed %d body/bodies in %s"
              % (len(items), src.relative_to(REPO).as_posix()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
