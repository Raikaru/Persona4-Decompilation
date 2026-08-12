#!/usr/bin/env python3
"""Find callee declarations that disagree with the callee's real definition.

Five functions across three waves were closed purely by correcting a callee's
parameter list at the call site - the residual looked like register allocation
and was actually the compiler being told the wrong argument classes. That is a
mechanical defect, so find it mechanically rather than one function at a time.

For every function DEFINED as C somewhere in src/, this compares the definition's
parameter list against every `extern` declaration of the same name elsewhere, and
reports the disagreements. An old-style `()` declaration is called out separately:
it tells the compiler nothing at all, so every call through it materialises
arguments by default rules.

    python tools/decl_disagreements.py [--calls-only]

`--calls-only` restricts output to declarations in files that actually call the
function, which is where a wrong declaration can change emitted code.
"""
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

def rtype(text: str) -> str:
    """Normalise a return type: `extern`, storage class and spacing removed."""
    text = re.sub(r"\b(extern|static|inline)\b", " ", text)
    text = re.sub(r"\s*\*\s*", " *", text)
    return " ".join(text.split()) or "int"

# A definition is a signature followed by a brace; a declaration ends in `;`.
# Both capture the return type, because it drives return-register handling and
# sign extension just as parameter types drive argument setup - a lane found a
# callee declared `s32` whose definition returns `s64`, and that one word was
# the whole residual.
DEFN = re.compile(
    r"^([A-Za-z_][\w \t\*]*?)\b(func_[0-9a-fA-F]{8})\s*\(([^;{]*?)\)\s*\{",
    re.M | re.S)
DECL = re.compile(
    r"^\s*(?:extern\s+)?(?!return\b|goto\b|case\b|else\b)"
    r"([A-Za-z_][\w \t\*]*?)\b(func_[0-9a-fA-F]{8})\s*\(([^;{]*?)\)\s*;",
    re.M | re.S)


def params(text: str) -> str:
    """Normalise a parameter list for comparison."""
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S).strip()
    if text in ("", "void"):
        return "void" if text == "void" else ""
    out = []
    for part in text.split(","):
        part = " ".join(part.strip().split())
        # Drop the parameter NAME only when a type precedes it; a lone token
        # like `s32` is the type itself, and eating it invents a disagreement.
        tokens = part.replace("*", " * ").split()
        if len(tokens) > 1 and re.fullmatch(r"[a-z_]\w*", tokens[-1]) \
                and tokens[-1] not in ("void", "char", "short", "int", "long",
                                       "float", "double", "unsigned", "signed"):
            tokens = tokens[:-1]
        part = " ".join(tokens).replace(" *", "*").replace("*", " *")
        out.append(" ".join(part.split()))
    return ", ".join(out)


def main() -> int:
    calls_only = "--calls-only" in sys.argv
    sources = [p for p in (REPO / "src").rglob("*.c") if "generated" not in p.parts]
    text = {p: p.read_text(errors="replace") for p in sources}

    defined: dict[str, tuple[str, str, Path]] = {}
    for path, body in text.items():
        for ret, name, args in DEFN.findall(body):
            defined.setdefault(name, (rtype(ret), params(args), path))

    findings = defaultdict(list)
    for path, body in text.items():
        for ret, name, args in DECL.findall(body):
            if name not in defined:
                continue
            rtruth, ptruth, home = defined[name]
            if home == path:
                continue
            rseen, pseen = rtype(ret), params(args)
            if rseen == rtruth and pseen == ptruth:
                continue
            if calls_only and not re.search(r"\b%s\s*\(" % name, body):
                continue
            if pseen == "":
                kind = "EMPTY"
            elif rseen != rtruth and pseen == ptruth:
                kind = "RETURN"
            else:
                kind = "DIFFERS"
            findings[path].append((kind, name, "%s (%s)" % (rseen, pseen),
                                   "%s (%s)" % (rtruth, ptruth), home.name))

    counts = Counter(f[0] for v in findings.values() for f in v)
    print("functions defined as C: %d" % len(defined))
    print("declarations disagreeing with their definition: "
          "%d empty, %d return-type only, %d differing"
          % (counts["EMPTY"], counts["RETURN"], counts["DIFFERS"]))
    for path in sorted(findings, key=lambda p: -len(findings[p])):
        rel = path.relative_to(REPO).as_posix()
        print("\n%s  (%d)" % (rel, len(findings[path])))
        for kind, name, seen, truth, home in sorted(findings[path])[:14]:
            print("   %-8s %s" % (kind, name))
            print("        declared %s" % seen)
            print("        defined  %s   in %s" % (truth, home))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
