from __future__ import annotations

import importlib.util
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("p4_pragma_audit",
                                              REPO / "tools" / "pragma_audit.py")
assert SPEC is not None and SPEC.loader is not None
audit = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(audit)


def mwcc_path() -> str | None:
    """Must never raise: this is evaluated at import time by @skipUnless.

    `load_config` calls `sys.exit` when the toolchain is not configured, which is
    a BaseException and slips straight past `except Exception` - that is exactly
    how this module broke CI, where no compiler exists.
    """
    try:
        import sys
        sys.path.insert(0, str(REPO / "tools"))
        from verify import load_config
        path = load_config().get("mwcc")
        return path if path and Path(path).is_file() else None
    except BaseException:
        return None


MWCC = mwcc_path()


class CollectTests(unittest.TestCase):
    def test_collects_pragmas_from_the_tree(self) -> None:
        seen = audit.collect()
        self.assertGreater(sum(seen.values()), 0)
        # every key is the text AFTER `#pragma`, with no directive prefix left on
        for spelling in seen:
            self.assertFalse(spelling.startswith("#"))
            self.assertEqual(spelling, spelling.strip())


    def test_comments_do_not_leak_into_the_scan(self) -> None:
        """Floor notes in this tree quote pragmas at the start of a line inside
        a block comment; reading those as directives makes the audit cry wolf."""
        text = ("/* the note said\n"
                "#pragma opt_loop_invariants on holds this together\n"
                "*/\n"
                "#pragma schedule off\n"
                "// #pragma line_comment_pragma on\n")
        stripped = audit.strip_comments(text)
        found = [m.group(1) for m in
                 (audit.PRAGMA_RE.match(l) for l in stripped.splitlines()) if m]
        self.assertEqual(found, ["schedule off"])
        # line structure is preserved so line numbers stay meaningful
        self.assertEqual(len(stripped.splitlines()), len(text.splitlines()))

    def test_a_pragma_inside_a_string_is_not_a_directive(self) -> None:
        stripped = audit.strip_comments('const char *s = "/* not a comment */";\n')
        self.assertIn("/* not a comment */", stripped)


@unittest.skipUnless(MWCC, "MWCCPS2 not available")
class CompilerTests(unittest.TestCase):
    """b210 ignores an unknown #pragma silently, so a typo does nothing while the
    lint still demands a justification for it and floor notes still credit it."""

    def test_a_bogus_spelling_is_reported(self) -> None:
        bad = audit.illegal({"bogus_pragma_xyz off": 1}, MWCC)
        self.assertEqual(bad, ["bogus_pragma_xyz off"])

    def test_a_real_spelling_is_not_reported(self) -> None:
        self.assertEqual(audit.illegal({"schedule off": 1}, MWCC), [])

    def test_it_separates_real_from_bogus_in_one_unit(self) -> None:
        spellings = {"schedule off": 1, "bogus_pragma_xyz off": 1,
                     "opt_common_subs off": 1, "another_fake_pragma on": 1}
        self.assertEqual(audit.illegal(spellings, MWCC),
                         ["another_fake_pragma on", "bogus_pragma_xyz off"])

    def test_every_pragma_in_the_tree_is_recognized(self) -> None:
        """The point of the tool: no spelling in src/ or include/ is inert."""
        seen = audit.collect()
        self.assertEqual(audit.illegal(seen, MWCC), [])

    def test_alias_stays_rejected(self) -> None:
        """`#pragma alias` was used 109 times in this tree and does nothing.

        b210 rejects it in every spelling, including the `extern code X_abs[];`
        form the tree paired it with, so aliasing has to come from the symbol
        registration in config/symbols_recovered.txt instead. Pinned here so the
        directive cannot quietly return.
        """
        self.assertEqual(audit.illegal({"alias DAT_x_abs DAT_x": 1}, MWCC),
                         ["alias DAT_x_abs DAT_x"])


if __name__ == "__main__":
    unittest.main()
