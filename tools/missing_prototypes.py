#!/usr/bin/env python3
"""Find guarded bodies that call a function with no visible prototype.

An `sd` surplus in `tools/opclass.py` often is not a wide local at all: a
callee with no declaration in scope takes the default promotion, so every
stack argument is stored 64 bits wide.  On `func_00263cb0` that was `sd +42`
and a single missing `extern` line; declaring it took the floor 915 -> 908
and the census 62 -> 38 (handoff 7x).

This finds the same defect everywhere without compiling anything.  For each
guarded body it lists the functions the body calls, subtracts the ones
declared inside the body and the ones declared at file scope, and reports
what is left along with the real signature if the tree defines it.

    python3 -E -s tools/missing_prototypes.py            # every floor
    python3 -E -s tools/missing_prototypes.py src/foo.c  # one file
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))

from measure_guarded import extract_guarded_body  # noqa: E402
import probe_variants as probe  # noqa: E402

GUARD = re.compile(r"// FUN_([0-9A-Fa-f]{8}) NONMATCHING")
CALL = re.compile(r"\b(func_[0-9a-f]{6,8})\s*\(")
# A declaration is anything that names the symbol followed by `(` and is not
# itself a call: `extern s32 func_x(...)`, `void func_x(...);`, or a
# definition.  Keeping this loose is deliberate - a false "declared" only
# costs a missed report, while a false "missing" wastes a worker's time.
DECL = re.compile(r"(?:extern\s+)?[A-Za-z_][\w \t*]*\b(func_[0-9a-f]{6,8})\s*\([^;{]*\)\s*[;{]")
DEFINITION = re.compile(
    r"^(?!extern)([A-Za-z_][\w \t*]*?)\b(func_[0-9a-f]{6,8})\s*\(([^;{]*)\)\s*\{", re.M)


def definitions() -> dict[str, str]:
    """Every first-party definition in the tree, as a printable signature."""
    found: dict[str, str] = {}
    for path in sorted((REPO / "src").rglob("*.c")):
        if path.parent.name == "generated" or path.name.startswith("."):
            continue
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        for match in DEFINITION.finditer(text):
            returns, name, parameters = (match.group(1).strip(), match.group(2),
                                         " ".join(match.group(3).split()))
            if returns.endswith(("if", "else", "return", "while", "for", "switch")):
                continue
            found.setdefault(name, f"{returns} {name}({parameters})")
    return found


def main() -> None:
    only = {Path(a).resolve() for a in sys.argv[1:]}
    known = definitions()
    rows: list[tuple[int, str, str, list[str]]] = []

    for path in sorted((REPO / "src").rglob("*.c")):
        if path.parent.name == "generated" or path.name.startswith("."):
            continue
        if only and path.resolve() not in only:
            continue
        text = path.read_text(errors="replace")
        # Declarations outside any guarded body are visible to every body in
        # the file; block-scope ones are not, which is exactly the trap.
        # Included headers count as file scope too - missing them reported
        # four false positives in y_fclShopDraw.c, whose eleven-argument
        # callee is declared in include/fr_font_internal.h.
        file_scope = {match.group(1) for match in DECL.finditer(text)
                      if not _inside_function(text, match.start())}
        file_scope |= _header_declarations(text)
        for marker in GUARD.finditer(text):
            name = "func_%s" % marker.group(1).lower()
            try:
                body = extract_guarded_body(text, "FUN_" + marker.group(1).upper(), name)
            except BaseException:
                continue
            declared = {m.group(1) for m in DECL.finditer(body)} | file_scope | {name}
            missing = sorted({m.group(1) for m in CALL.finditer(body)} - declared)
            if missing:
                rows.append((len(missing), name, str(path.relative_to(REPO)), missing))

    # A missing prototype only costs instructions when the call has stack
    # arguments: with four or fewer they travel in registers and the default
    # promotion is invisible.  `func_0025f430` takes fourteen and was worth
    # seven words; `func_0010fbd0` takes one and measured a dead tie.  Rank
    # by the widest callee so the expensive ones come first.
    def arity(symbol: str) -> int:
        signature = known.get(symbol)
        if not signature:
            return 0
        inner = signature[signature.index("(") + 1:-1].strip()
        return 0 if inner in ("", "void") else inner.count(",") + 1

    ranked = []
    for _count, name, source, missing in rows:
        widest = max((arity(symbol) for symbol in missing), default=0)
        ranked.append((widest, name, source, missing))

    worth_it = [row for row in ranked if row[0] > 4]
    for widest, name, source, missing in sorted(worth_it, reverse=True):
        print(f"{widest:3d} args  {name}  {source}")
        for symbol in sorted(missing, key=arity, reverse=True):
            signature = known.get(symbol)
            print(f"       {symbol}"
                  + (f"   -> {signature}" if signature else "   (no definition in tree)"))
    print(f"\n{len(worth_it)} bodies call an undeclared function with stack arguments "
          f"(more than four); {len(rows) - len(worth_it)} more call only "
          "narrow ones, where the missing declaration is usually free")


def _header_declarations(text: str) -> set[str]:
    """Symbols declared by the headers this translation unit includes."""
    found: set[str] = set()
    for name in re.findall(r'#\s*include\s+"([^"]+)"', text):
        header = REPO / "include" / name
        if not header.is_file():
            continue
        try:
            body = header.read_text(errors="replace")
        except OSError:
            continue
        found |= {match.group(1) for match in DECL.finditer(body)}
    return found


def _inside_function(text: str, position: int) -> bool:
    """True when POSITION sits inside a brace block, i.e. at block scope."""
    return text.count("{", 0, position) > text.count("}", 0, position)


if __name__ == "__main__":
    main()
