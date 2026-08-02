"""A function defined by spliced assembly must not be reported undefined.

`INCLUDE_ASM` splices retail assembly into the object, so the function IS
defined there. When the same unit's C also references it by name -- storing a
callback into a dispatch table -- mwcc additionally emits an undefined entry for
the `extern`. Both entries reach the symbol table under one name, and the link
eligibility check reads that table to decide whether the whole translation unit
can be placed. Reading the wrong entry drops the object silently: the build
still reproduces both retail hashes, so nothing fails, only the C-linked count
quietly falls.

That is exactly what happened: eight units lost their link at once (144 objects
where 151 had linked before) because each had gained a C function that took the
address of an `INCLUDE_ASM` sibling.
"""

import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import build  # noqa: E402


def sym(name, shndx):
    return {"name": name, "shndx": shndx}


class MergeSymbolSectionsTests(unittest.TestCase):
    def test_definition_wins_when_it_comes_first(self) -> None:
        sections = build.merge_symbol_sections(
            [sym("func_001015c0", 8), sym("func_001015c0", 0)]
        )
        self.assertEqual(sections["func_001015c0"], 8)

    def test_definition_wins_when_it_comes_last(self) -> None:
        """Order must not decide it -- the emitter is free to choose either."""
        sections = build.merge_symbol_sections(
            [sym("func_001015c0", 0), sym("func_001015c0", 8)]
        )
        self.assertEqual(sections["func_001015c0"], 8)

    def test_genuinely_undefined_symbol_stays_undefined(self) -> None:
        """The relaxation must not invent definitions.

        A symbol this unit only imports has no defined entry anywhere, and the
        eligibility check still has to reject it unless the linker can resolve
        it from elsewhere.
        """
        sections = build.merge_symbol_sections(
            [sym("func_0046d730", 0), sym("func_0046d730", 0)]
        )
        self.assertEqual(sections["func_0046d730"], 0)

    def test_distinct_names_are_independent(self) -> None:
        sections = build.merge_symbol_sections(
            [sym("defined", 3), sym("imported", 0), sym("also_defined", 5)]
        )
        self.assertEqual(
            sections, {"defined": 3, "imported": 0, "also_defined": 5}
        )

    def test_missing_shndx_is_treated_as_undefined(self) -> None:
        sections = build.merge_symbol_sections([{"name": "func_x"}])
        self.assertEqual(sections["func_x"], 0)

    def test_empty_symbol_table(self) -> None:
        self.assertEqual(build.merge_symbol_sections([]), {})


if __name__ == "__main__":
    unittest.main()
