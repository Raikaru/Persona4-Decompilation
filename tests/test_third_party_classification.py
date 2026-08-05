from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import verify  # noqa: E402

MIDDLEWARE = REPO / "src" / "middleware" / "gcc_ee_grouped.c"


class PrefixTests(unittest.TestCase):
    def test_middleware_is_third_party(self) -> None:
        self.assertTrue(verify.is_third_party("src/middleware/gcc_ee_grouped.c"))
        self.assertTrue(verify.is_third_party("middleware/gcc_ee_grouped.c"))

    def test_windows_separators_are_handled(self) -> None:
        self.assertTrue(verify.is_third_party("src\\middleware\\gcc_ee_grouped.c"))

    def test_the_existing_prefixes_still_classify(self) -> None:
        for rel in ("src/cri/cri_adx.c", "src/sce/rofs_if.c", "src/rw/rwcore_grouped.c",
                    "src/crt0.c", "src/libc_core.c"):
            self.assertTrue(verify.is_third_party(rel), rel)

    def test_game_code_is_not_third_party(self) -> None:
        """The prefix must not accidentally swallow real game files."""
        for rel in ("src/g_data/g_data.c", "src/Battle/btlShuffleDraw.c",
                    "src/promoted/code1_0044.c", "src/middlewareish.c"):
            self.assertFalse(verify.is_third_party(rel), rel)


@unittest.skipUnless(MIDDLEWARE.is_file(), "middleware unit not present")
class MiddlewareUnitTests(unittest.TestCase):
    """The unit only holds functions with a signature b210 cannot emit.

    Reclassifying is a claim about authorship, so the file has to keep carrying its
    evidence and must never become a dumping ground for merely-hard functions.
    """

    def setUp(self) -> None:
        self.text = MIDDLEWARE.read_text(errors="replace")

    def test_every_entry_is_include_asm(self) -> None:
        markers = self.text.count("// FUN_")
        self.assertEqual(markers, self.text.count("INCLUDE_ASM"))
        self.assertGreater(markers, 0)

    def test_any_preserved_body_stays_behind_include_asm(self) -> None:
        """Some entries kept a reverse-engineered body, and that is deliberate.

        The bodies cannot match under MWCCPS2 - that is precisely why these functions
        were reclassified - but they document the semantics and would be the starting
        point if ee-gcc is ever added to the build. What must NOT happen is a body
        being compiled in place of the retail bytes, so every one stays inside
        `#ifdef NON_MATCHING` with `INCLUDE_ASM` on the `#else` arm.
        """
        self.assertEqual(self.text.count("#ifdef NON_MATCHING"),
                         self.text.count("#else"))
        for chunk in self.text.split("#ifdef NON_MATCHING")[1:]:
            head = chunk.split("#endif")[0]
            self.assertIn("#else", head)
            self.assertIn("INCLUDE_ASM", head.split("#else", 1)[1])

    def test_the_evidence_is_recorded(self) -> None:
        for needle in ("ee-gcc", "lui rX", "framed tail jump", "permute_ast",
                       "flanked by genuine third-party"):
            self.assertIn(needle, self.text, needle)

    def test_preprocessor_blocks_are_balanced(self) -> None:
        self.assertEqual(self.text.count("#ifdef"), self.text.count("#endif"))


if __name__ == "__main__":
    unittest.main()
