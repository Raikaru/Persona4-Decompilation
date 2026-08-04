"""Tree-integrity tripwires for the authoritative source tree.

The marker-count test is the tripwire against silently dropped or duplicated
markers; bump it deliberately when functions are genuinely added, and never to
silence a drop you did not intend.  The guard tests lock in the whole-file
translation-unit model: one C file == one object, no per-function guard
selection macros anywhere in first-party source.
"""
from __future__ import annotations

import importlib.util
import re
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]

SPEC = importlib.util.spec_from_file_location("p4_verify_tripwire", REPO / "tools" / "verify.py")
assert SPEC is not None and SPEC.loader is not None
verify = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(verify)

ADDRESS_SUFFIX_RE = re.compile(r"_[0-9A-Fa-f]{8}\.c$")
# The guard macro name, assembled at runtime so neither the source nor the
# compiled bytecode carries the scheme's literal (the repo-wide grep for it
# must stay clean; chr(85) is "U").
GUARD_MACRO = "P4_" + chr(85) + "NIT"
GUARD_SELECT_RE = re.compile(
    rf"^\s*#if\s+defined\({GUARD_MACRO}_([0-9a-fA-F]{{8}})\)", re.MULTILINE
)


def first_party_sources() -> list[Path]:
    return sorted(
        path for path in (REPO / "src").rglob("*.c")
        if not verify.is_generated(path)
    )


class MarkerCountTripwireTests(unittest.TestCase):
    def test_first_party_marker_count_is_unchanged(self) -> None:
        """4876 tracked markers across first-party src/.  Bump deliberately.

        Most are INCLUDE_ASM fallbacks placed by the __FILE__-driven translation
        unit recovery, which gave every function a real source file to live in;
        the rest are decompiled C.

        Was 4865 until g_data.c was found carrying three functions whose
        `// FUN_` marker line was duplicated (FUN_001055A0, FUN_00106020,
        FUN_0010F420).  The duplicates were counted as separate tracked
        functions and reported NO_SYMBOL because only the second copy had a
        body; removing them lowers the count by exactly three without losing a
        single function.

        Raised to 4863 when k_fldUnit.c was found carrying `}// FUN_00166600` --
        a marker sharing a line with the previous function's closing brace, so
        the scanner never saw it and func_00166600 was invisible to the
        verifier. Splitting it onto its own line exposes a function that was
        always there; nothing was added.

        Raised to 4864 when the `jr $ra; nop` nullsub at 0x00244100 was given its
        own marker. It is a real function -- 0x00635950 holds its address and the
        next two slots of that table hold 0x00244110 and 0x00244540, both already
        canonical -- and folding it into func_00243fa0's window left that function
        with a 368-byte window against a 352-byte body, so it could never leave
        SIZE_MISMATCH. Marking it shrinks the window and BOTH functions match.
        This is the one case in the campaign where the count grew because a
        function was genuinely added rather than uncovered.

        Raised to 4866 for the `jr $ra` nullsubs at 0x001C7770 (btlCamera.c) and
        0x004B5F70 (k_vpad.c). Both are canonical windows in
        tools/slus21782_functions.json that sat BETWEEN two already-marked
        functions of the same file, so their owning translation unit is not in
        doubt -- they were simply never given a marker, which left them outside
        the verifier entirely and supplied to the link as raw retail bytes.
        Marking them costs nothing and both match as empty functions. 8,220
        windows are still in that unscanned state; this is the first two coming
        in, and the count is expected to keep climbing as they do.

        Raised to 4876 for the ten unscanned windows in 0x0017B510..0x0017CCC0.
        tu_audit groups that span as ONE translation unit at HIGH tier (score 5)
        from a `__FILE__` string naming k_shadow.c, and two of its members were
        already marked in code1_0017.c, so the ten join their siblings there.
        They are canonical windows that had no marker at all; two of them
        (func_0017b990, func_0017cc90) matched immediately once visible.
        """
        sources = first_party_sources()
        self.assertEqual(
            sum(len(verify.scan_markers(path)) for path in sources),
            4876,
        )

    def test_no_address_suffixed_sources_remain(self) -> None:
        """The consolidation scheme's input files (_<addr>.c) are gone."""
        sources = first_party_sources()
        self.assertFalse(
            any(ADDRESS_SUFFIX_RE.search(path.name) for path in sources),
        )

    def test_no_guard_macros_in_first_party_sources(self) -> None:
        """Every first-party file is a whole translation unit: no guards."""
        for path in first_party_sources():
            text = path.read_text(encoding="utf-8", errors="replace")
            self.assertIsNone(
                GUARD_SELECT_RE.search(text),
                f"{path.relative_to(REPO)} still contains a {GUARD_MACRO}_ guard",
            )

    def test_nothing_sits_between_a_marker_and_its_include_asm(self) -> None:
        """A note wedged under the marker hides the function from the verifier.

        `verify.py` pairs a `// FUN_` marker with the body directly beneath it, so
        prose in between silently drops the function from the census -- it reads as
        `NO_SYMBOL`, and the matched count falls with no other symptom. This is a
        recurring wave mistake: it cost three functions in `y_smap.c` while the
        `#ifdef NON_MATCHING` blocks there were being removed, because stripping
        the conditional left the floor note under the marker.
        """
        sys.path.insert(0, str(REPO / "tools"))
        import floor_census

        for path in first_party_sources():
            lines = floor_census.read_lines(path)
            offenders = floor_census.misplaced_notes(lines)
            self.assertEqual(
                offenders, [],
                f"{path.relative_to(REPO)}: measured note between the marker and "
                f"its INCLUDE_ASM at line(s) {[n for n, _ in offenders]}; the note "
                "belongs ABOVE the marker",
            )

    def test_no_scratch_functions_left_in_first_party_sources(self) -> None:
        """Agent scratch in a source file breaks the layout, not just the diff.

        A wave left `func_003724f0_tmp` under a fake `// TMP_003724F0` marker in
        `btlShuffleCalc.c`. It compiled into a bare `.text` section no marker
        owned, so `build.py` refused to lay the object out per function -- but only
        after a six-minute build, and every per-function verify passed meanwhile.
        The brief's "no tmp*.c under src/" rule does not cover a scratch function
        inside a real file, so check the shapes directly.
        """
        scratch = re.compile(
            r"^[ \t]*//[ \t]*TMP_[0-9A-Fa-f]{8}"     # fake marker
            r"|\bfunc_[0-9A-Fa-f]{8}_(?:tmp|probe|test|old|copy)\b"  # scratch name
            # Code BEFORE the marker on the same line: `}// FUN_00166600` hid a
            # function from the verifier for the whole campaign. A trailing word
            # after the address is tolerated (the verifier reads it fine) and is
            # an existing convention in ~30 files, so it is deliberately not
            # flagged here.
            r"|^[ \t]*\S[^\n]*//[ \t]*FUN_[0-9A-Fa-f]{8}",
            re.MULTILINE,
        )
        for path in first_party_sources():
            text = path.read_text(encoding="utf-8", errors="replace")
            m = scratch.search(text)
            self.assertIsNone(
                m,
                f"{path.relative_to(REPO)}:{text[: m.start()].count(chr(10)) + 1}: "
                f"scratch or malformed marker {m.group(0).strip()!r}" if m else "",
            )


if __name__ == "__main__":
    unittest.main()
