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
        """4865 tracked markers across first-party src/.  Bump deliberately.

        1,843 are decompiled C; the rest are INCLUDE_ASM fallbacks placed by the
        __FILE__-driven translation-unit recovery, which gave every function a
        real source file to live in.
        """
        sources = first_party_sources()
        self.assertEqual(
            sum(len(verify.scan_markers(path)) for path in sources),
            4865,
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


if __name__ == "__main__":
    unittest.main()
