#!/usr/bin/env python3
"""Teach romwright what this project has already proven.

6359 first-party functions are byte-exact, so their C signatures and names are
not guesses -- they reproduce retail's bytes. A decompiler that does not know
them re-derives each one badly: it emits `FUN_00107ac0` instead of
`func_00107ac0`, guesses the argument count from register liveness (measured
here at 73% against the matched set), and prints
"Supplied declaration required" for callees it cannot type at all.

Feeding the proven set back fixes all three at once, and it compounds: every
function matched from here on makes the next reconstruction's context better.

    python tools/romwright_feedback.py            # push names and prototypes
    python tools/romwright_feedback.py --dry-run  # show what would be pushed

Only functions whose body is live and unguarded are pushed. A guarded
NON_MATCHING body is a draft, its signature is a hypothesis, and asserting a
hypothesis into the analysis database would launder a guess into a fact.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
PROGRAM = "p4usa"
DEFAULT_PROJECT = REPO / "build" / "romwright"

DEFINITION = re.compile(
    r"^(?!\s)([A-Za-z_][\w \*]*?)\s+(func_[0-9a-f]{8})\s*\(([^;{]*)\)\s*\{", re.M)
GUARDED = re.compile(r"^// FUN_([0-9A-F]{8}) NONMATCHING", re.M)


# The analyser parses supplied signatures against the decompiler's own core
# type table (`coretypes.xml`), not against C. Multi-word spellings like
# `unsigned long long` are a syntax error there; the names it knows are
# `byte`, `sbyte`, `ushort`, `uint`, `ulonglong` and so on. Every type has to
# map exactly -- a prototype that parses but means something else is worse
# than none, so anything unmapped is skipped rather than approximated.
BASE_TYPES = {
    "u8": "byte", "s8": "sbyte", "u16": "ushort", "s16": "short",
    "u32": "uint", "s32": "int", "u64": "ulonglong", "s64": "longlong",
    "f32": "float", "f64": "double", "void": "void", "char": "char",
    "int": "int", "unsigned": "uint", "float": "float", "double": "double",
    "short": "short", "long": "long", "bool": "bool",
}


def _base_c(declaration: str) -> str | None:
    """Rewrite one declaration in base C, or None if a type does not map."""
    text = declaration.strip()
    if not text or text in ("void", "..."):
        return text or None
    stars = text.count("*")
    words = [word for word in re.split(r"[\s\*]+", text) if word]
    qualifiers = [word for word in words if word in ("const", "volatile", "struct", "unsigned", "signed")]
    core = [word for word in words if word not in ("const", "volatile", "struct")]
    if not core:
        return None
    # A parameter may carry a name; the type is everything before it.
    if len(core) > 1 and core[-1] not in BASE_TYPES:
        core = core[:-1]
    if len(core) != 1:
        return None
    mapped = BASE_TYPES.get(core[0])
    if mapped is None:
        # A pointer to an unknown project struct is still honestly a pointer.
        return ("void " + "*" * stars).strip() if stars else None
    const = "const " if "const" in qualifiers else ""
    return (const + mapped + " " + "*" * stars).strip()


def _signature(returns: str, name: str, parameters: str) -> str | None:
    mapped_return = _base_c(returns)
    if mapped_return is None:
        return None
    if parameters.strip() in ("", "void"):
        return f"{mapped_return} {name}(void)"
    mapped = []
    for parameter in parameters.split(","):
        piece = _base_c(parameter)
        if piece is None:
            return None
        mapped.append(piece)
    return f"{mapped_return} {name}({', '.join(mapped)})"


def proven() -> list[dict]:
    """Every first-party function whose body is live, with its real signature."""
    rows: dict[str, dict] = {}
    for path in sorted((REPO / "src").rglob("*.c")):
        # `probe_variants.py` writes `.<unit>.probe_XXXX.c` beside the source
        # and deletes it again, so a scan that races one sees a file that no
        # longer exists by the time it is read.
        if path.parent.name == "generated" or path.name.startswith("."):
            continue
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        drafts = {match.group(1).lower() for match in GUARDED.finditer(text)}
        for match in DEFINITION.finditer(text):
            returns, name, parameters = (match.group(1).strip(), match.group(2),
                                         match.group(3).strip())
            address = name[5:]
            if address in drafts or returns.endswith(("if", "else", "return", "while")):
                continue
            if returns.startswith("asm "):
                continue
            signature = _signature(returns, name, parameters)
            rows[address] = {"function": address, "signature": signature,
                             "return_type": _base_c(returns), "name": name}
    return sorted(rows.values(), key=lambda row: row["function"])


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--project", default=str(DEFAULT_PROJECT))
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    sys.path.insert(0, str(TOOLS))
    from romwright_decompile import _cli  # noqa: PLC0415 - shares the binary lookup

    rows = proven()
    typed = [row for row in rows if row["signature"]]
    print(f"{len(rows)} matched first-party functions with a live body; "
          f"{len(typed)} have a signature that maps to base C")
    if args.dry_run:
        for row in typed[:5]:
            print(f"  {row['function']}  {row['signature']}")
        unmapped = [row["name"] for row in rows if not row["signature"]]
        print(f"  ... {len(unmapped)} skipped, e.g. {', '.join(unmapped[:4])}")
        return

    cli, project = _cli(), str(Path(args.project))
    with tempfile.TemporaryDirectory() as scratch:
        protos = Path(scratch) / "prototypes.json"
        names = Path(scratch) / "names.json"
        protos.write_text(json.dumps(
            [{"function": row["function"], "signature": row["signature"],
              "return_type": row["return_type"]} for row in typed]))
        names.write_text(json.dumps(
            [{"function": row["function"], "name": row["name"]} for row in rows]))
        for command in (
            [cli, "assert-names", PROGRAM, str(names), "--project", project],
            [cli, "assert-prototypes", PROGRAM, str(protos), "--source", "p4-matched",
             "--project", project],
        ):
            completed = subprocess.run(command, text=True, capture_output=True)
            sys.stdout.write(completed.stdout)
            if completed.returncode != 0:
                sys.stderr.write(completed.stderr)
                sys.exit(completed.returncode)


if __name__ == "__main__":
    main()
