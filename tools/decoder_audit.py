#!/usr/bin/env python3
"""Check fnalign's instruction decoder against the tree's own disassembly.

Three decoder defects surfaced in one session, each found by hand after it
had already corrupted measurements:

  * `lq`/`sq` decoded to `"??"`, and every `"??"` compares equal to every
    other, so prologue register saves were invisible to the aligner;
  * `lqc2`/`sqc2` decoded to Octeon `bbit0`/`bbit1` with the displacement
    rendered as a pc-relative BRANCH TARGET, so two byte-identical VU loads
    at different addresses compared UNEQUAL and every one counted as an
    edit.

Finding those one at a time, by noticing an odd mnemonic in a diff, is not a
method.  The authoritative answer was in the repository the whole time:
`asm/nonmatchings/**/*.s` carries 11k functions of correctly disassembled
retail code, each line giving both the instruction word and its mnemonic:

    /* EE610 001EE610 20FBBD27 */  addiu      $29, $29, -0x4E0

So decode every one of those words with the decoder under test and compare
mnemonics.  A disagreement is a decoder defect, an assembler alias, or a
listing quirk - all three are worth knowing, and none of them should be
discovered by accident in a floor's alignment.

This does NOT check operands.  The listing spells registers numerically
(`$29`) where capstone uses names (`$sp`), and immediates differ in radix
and sign convention, so operand text is not comparable without a normaliser
that would itself need testing.  Mnemonics are where the three real defects
lived, and they are directly comparable.

Usage:  python3 -E -s tools/decoder_audit.py [--quiet] [path ...]
"""
from __future__ import annotations

import re
import sys
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import fnalign

ROW = re.compile(r"^\s*/\*\s*\S+\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s*\*/\s+(\S+)")

# The listing writes what the assembler accepts; capstone writes what the
# hardware does.  These pairs are the same instruction under two spellings
# and are not defects.
ALIASES = {
    ("nop", "sll"), ("move", "daddu"), ("move", "addu"), ("move", "or"),
    ("b", "beq"), ("beqz", "beq"), ("bnez", "bne"), ("negu", "subu"),
    ("not", "nor"), ("li", "addiu"), ("li", "ori"), ("la", "addiu"),
    ("bal", "bgezal"), ("beqzl", "beql"), ("bnezl", "bnel"),
    # The listing names the ordered compares without the `o`; same encoding.
    ("c.le.s", "c.ole.s"), ("c.lt.s", "c.olt.s"),
    ("c.le.d", "c.ole.d"), ("c.lt.d", "c.olt.d"),
    # `sync.p` and `qmtc2.ni` are the EE's pipeline-qualified spellings of
    # instructions capstone names plainly.  Same word, same behaviour here.
    ("sync.p", "sync"), ("sync.l", "sync"),
    ("qmtc2.ni", "dmtc2"), ("qmfc2.ni", "dmfc2"),
    ("qmtc2.i", "dmtc2"), ("qmfc2.i", "dmfc2"),
    # The listing prints a bare `c1` where capstone names the COP1 op; the
    # word at 0x0016C090 is 0x46000084, fmt=S function 0x04, which is `sqrt.s`.
    ("c1", "sqrt.s"), ("c1", "abs.s"), ("c1", "rsqrt.s"),
}

# Where the LISTING gives up and writes a bare `.word`, the decoder knowing
# what it is is not a defect - it is the listing being conservative about
# what the project's assembler will accept.
LISTING_GAVE_UP = ".word"


def mnemonic_of(text: str) -> str:
    return text.split()[0] if text.split() else ""


def audit(paths: list[Path], quiet: bool) -> int:
    disagreements: Counter[tuple[str, str]] = Counter()
    undecoded: Counter[str] = Counter()
    example: dict[tuple[str, str], str] = {}
    words = 0
    for path in paths:
        for line in path.read_text(errors="replace").splitlines():
            match = ROW.match(line)
            if match is None:
                continue
            address, word, listed = match.groups()
            words += 1
            got = mnemonic_of(fnalign.disassemble(bytes.fromhex(word), int(address, 16)))
            listed = listed.lower()
            if got == listed:
                continue
            if (listed, got) in ALIASES or (got, listed) in ALIASES:
                continue
            if listed == LISTING_GAVE_UP:
                continue
            key = (listed, got or "??")
            if got.startswith(LISTING_GAVE_UP):
                undecoded[listed] += 1
                continue
            disagreements[key] += 1
            example.setdefault(key, f"{path.name} {address} {word}")

    for (listed, got), count in disagreements.most_common():
        print(f"{count:7d}  listing says {listed:<12} decoder says {got:<12} "
              f"e.g. {example[(listed, got)]}")
    for listed, count in undecoded.most_common(12):
        print(f"{count:7d}  undecoded, kept distinct as a raw word: {listed}")
    if not quiet:
        print(f"\n{words} instructions checked against the tree's own listings."
              f"\n{sum(disagreements.values())} WRONG in {len(disagreements)} forms"
              f" - these name one instruction as another and are defects."
              f"\n{sum(undecoded.values())} undecoded in {len(undecoded)} forms"
              f" - MMI, VU macro-mode and the EE three-operand `mult`."
              f"\nUndecoded is safe but coarse: each keeps its own raw word, so two"
              f"\ndifferent instructions no longer compare equal, which is the whole"
              f"\npoint.  Naming them properly would let the aligner see two uses of"
              f"\nthe same op with different registers as a near-match rather than a"
              f"\nreplace, which is a refinement, not a correctness fix.")
        if disagreements:
            print("\nA disagreement is a decoder defect, an assembler alias, or a"
                  "\nlisting quirk.  The first kind corrupts every measurement that"
                  "\ntouches the instruction: `lqc2` read as Octeon `bbit0` made"
                  "\nbyte-identical VU loads compare unequal, and `sq` read as `??`"
                  "\nmade every register save compare equal to every other.")
    return 1 if disagreements else 0


def main() -> int:
    quiet = "--quiet" in sys.argv
    given = [Path(a) for a in sys.argv[1:] if not a.startswith("-")]
    paths = given or sorted((REPO / "asm" / "nonmatchings").rglob("*.s"))
    return audit(paths, quiet)


if __name__ == "__main__":
    sys.exit(main())
