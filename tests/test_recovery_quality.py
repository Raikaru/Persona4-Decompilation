"""The recovery score must not flatter decompiler output.

A byte-identical function can still be unreadable: an address for a name, raw
field offsets, `M2C_FIELD`, `temp_3`/`uVar1` locals. Reporting only MATCH hides
that, so `tools/recovery_quality.py` scores matched functions on NAMED, TYPED and
DOCUMENTED independently of matching. These tests pin the classification, because
a scorer that is generous by accident is worse than no scorer at all: it would
report the tree as recovered while it still reads like m2c output.
"""

import json
import re
import sys
import textwrap
import urllib.parse
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import gen_objdiff  # noqa: E402
import progress  # noqa: E402
import recovery_quality as rq  # noqa: E402


def score(body, name="func_00123456", before=()):
    return rq.score(name, list(before), textwrap.dedent(body).strip())


class NamedTests(unittest.TestCase):
    def test_address_placeholder_is_not_named(self) -> None:
        self.assertFalse(score("void func_00123456(void) { return; }")["named"])

    def test_uppercase_placeholder_is_not_named(self) -> None:
        self.assertFalse(
            score("void FUN_00123456(void) { return; }", name="FUN_00123456")["named"]
        )

    def test_recovered_name_is_named(self) -> None:
        self.assertTrue(
            score("void Scr_JumpToProcedure(void) { return; }",
                  name="Scr_JumpToProcedure")["named"]
        )

    def test_name_merely_containing_hex_is_still_named(self) -> None:
        """`crc32_00` is a real name, not a `func_<address>` placeholder."""
        self.assertTrue(score("void crc32_00(void) { return; }", name="crc32_00")["named"])


class TypedTests(unittest.TestCase):
    def test_cast_and_offset_read_is_not_typed(self) -> None:
        body = """
        s32 f(u8 *p) {
            return *(s32 *)(p + 0x18);
        }
        """
        self.assertFalse(score(body)["typed"])

    def test_cast_and_offset_write_is_not_typed(self) -> None:
        body = """
        void f(u8 *p, s32 v) {
            *(s32 *)(p + 0x18) = v;
        }
        """
        self.assertFalse(score(body)["typed"])

    def test_m2c_macro_is_not_typed(self) -> None:
        body = """
        s32 f(u8 *p) {
            return M2C_FIELD(p, s32 *, 0x18);
        }
        """
        self.assertFalse(score(body)["typed"])

    def test_named_field_access_is_typed(self) -> None:
        body = """
        s32 ScrStackDepth(ScrData *scr) {
            return scr->stackDepth;
        }
        """
        self.assertTrue(score(body, name="ScrStackDepth")["typed"])

    def test_raw_offset_inside_a_comment_does_not_disqualify(self) -> None:
        """Comments are stripped before scoring, so documentation is free."""
        body = """
        s32 ScrStackDepth(ScrData *scr) {
            /* retail reads *(s32 *)(scr + 0x18) here */
            return scr->stackDepth;
        }
        """
        self.assertTrue(score(body, name="ScrStackDepth")["typed"])


class ResidueTests(unittest.TestCase):
    def test_m2c_temp_names_are_residue(self) -> None:
        flags = score("s32 f(void) { s32 temp_3 = 1; return temp_3; }")
        self.assertTrue(flags["residue"])
        self.assertFalse(flags["typed"])

    def test_ghidra_names_are_residue(self) -> None:
        for local in ("uVar1", "iVar1", "bVar1", "param_1", "spA0"):
            with self.subTest(local=local):
                body = "s32 f(void) { s32 %s = 1; return %s; }" % (local, local)
                self.assertTrue(score(body)["residue"], local)

    def test_ordinary_names_are_not_residue(self) -> None:
        body = "s32 f(void) { s32 depth = 1; return depth; }"
        self.assertFalse(score(body)["residue"])

    def test_a_name_merely_containing_var_is_not_residue(self) -> None:
        """`variance` and `sprite` must not be mistaken for `var_1`/`spNN`."""
        body = "s32 f(void) { s32 variance = 1; s32 sprite = 2; return variance + sprite; }"
        self.assertFalse(score(body)["residue"])


class DocumentedTests(unittest.TestCase):
    def test_trivial_body_needs_no_prose(self) -> None:
        body = """
        s32 ScrStackDepth(ScrData *scr) {
            return scr->stackDepth;
        }
        """
        self.assertTrue(score(body, name="ScrStackDepth")["documented"])

    def test_nontrivial_body_without_prose_is_undocumented(self) -> None:
        body = """
        s32 f(ScrData *scr) {
            s32 a = scr->stackDepth;
            s32 b = scr->pc;
            s32 c = a + b;
            if (c > 4) {
                c = 4;
            }
            return c;
        }
        """
        self.assertFalse(score(body)["documented"])

    def test_prose_above_the_marker_counts(self) -> None:
        body = """
        s32 f(ScrData *scr) {
            s32 a = scr->stackDepth;
            s32 b = scr->pc;
            s32 c = a + b;
            if (c > 4) {
                c = 4;
            }
            return c;
        }
        """
        before = ["/* Clamp the combined stack depth to the four hardware slots. */"]
        self.assertTrue(score(body, before=before)["documented"])

    def test_the_marker_line_is_not_prose(self) -> None:
        body = """
        s32 f(ScrData *scr) {
            s32 a = scr->stackDepth;
            s32 b = scr->pc;
            s32 c = a + b;
            if (c > 4) {
                c = 4;
            }
            return c;
        }
        """
        self.assertFalse(score(body, before=["// FUN_00123456"])["documented"])


class StatusTableTests(unittest.TestCase):
    """The README table drifted to 1,314 matches when the truth was 3,419."""

    METRICS = {
        "total": 13084,
        "hashes": {"retail_sha1": "aa", "image_sha1": "bb"},
        "matching": {"count": 3419, "percent": 26.131},
        "linked": {"count": 977, "percent": 7.467,
                   "asm_fallbacks_in_linked_objects": 814},
        "coverage": {"scanned": 4864, "scanned_percent": 37.174,
                     "unscanned": 8220, "unscanned_percent": 62.826},
    }
    RECOVERY = {
        "matched_first_party": 2801, "named": 155, "typed": 1163,
        "documented": 1651, "decompiler_residue": 600,
        "named_percent": 5.534, "typed_percent": 41.521,
        "documented_percent": 58.943, "residue_percent": 21.421,
    }

    def test_table_reports_the_metrics_it_was_given(self) -> None:
        body = progress.render_status(self.METRICS, self.RECOVERY)
        for expected in ("13,084", "3,419", "977", "814", "2,801", "155", "1,163"):
            self.assertIn(expected, body)
        # the table must not hide how much is still handed to the link as retail
        # bytes: measuring against the scanned subset alone reads as near-done
        self.assertIn("8,220", body)
        self.assertIn("62.826", body)

    def test_table_separates_matching_from_recovery(self) -> None:
        body = progress.render_status(self.METRICS, self.RECOVERY)
        self.assertIn("not recovered", body)
        self.assertIn("recovery_quality.py", body)
        self.assertIn("NAMED", body)
        self.assertIn("TYPED", body)

    def test_recovery_rows_are_optional(self) -> None:
        body = progress.render_status(self.METRICS, None)
        self.assertIn("3,419", body)
        self.assertNotIn("NAMED", body)

    def test_update_readme_replaces_only_the_marked_block(self) -> None:
        import tempfile

        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "README.md"
            path.write_text(
                "# Title\n\nkeep me above\n"
                f"{progress.STATUS_BEGIN}\nstale garbage\n{progress.STATUS_END}\n"
                "keep me below\n",
                encoding="utf-8",
            )
            progress.update_readme(path, "fresh table\n")
            text = path.read_text(encoding="utf-8")
            self.assertIn("keep me above", text)
            self.assertIn("keep me below", text)
            self.assertIn("fresh table", text)
            self.assertNotIn("stale garbage", text)

    def test_missing_markers_is_an_error_not_a_silent_skip(self) -> None:
        import tempfile

        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "README.md"
            path.write_text("# Title\n\nno markers here\n", encoding="utf-8")
            with self.assertRaises(progress.ProgressError):
                progress.update_readme(path, "fresh table\n")


class CommittedReadmeTests(unittest.TestCase):
    def test_readme_status_block_is_generated_not_handwritten(self) -> None:
        text = (REPO / "README.md").read_text(encoding="utf-8")
        self.assertIn(progress.STATUS_BEGIN, text)
        self.assertIn(progress.STATUS_END, text)

    def test_readme_agrees_with_the_committed_metrics(self) -> None:
        """Catches the drift that let the README claim 1,314 for months."""
        metrics = json.loads(
            (REPO / "progress" / "metrics.json").read_text(encoding="utf-8")
        )
        text = (REPO / "README.md").read_text(encoding="utf-8")
        block = text.split(progress.STATUS_BEGIN, 1)[1].split(progress.STATUS_END, 1)[0]
        self.assertIn(f"{metrics['matching']['count']:,}", block)
        self.assertIn(f"{metrics['linked']['count']:,}", block)
        self.assertIn(f"{metrics['total']:,}", block)


class ReadmeBadgeTests(unittest.TestCase):
    """The decomp.dev badges fail silently when their query string is wrong.

    Every failure mode here still returns HTTP 200, so nothing but a test
    catches them: dropping `mode=shield` serves the 4.6 MB unit treemap in place
    of a badge, and a `category` decomp.dev does not know reports the whole
    project under a first-party label.
    """

    SLUG = "Raikaru/Persona4-Decompilation"
    # Verified live against decomp.dev's shield endpoint. `code` and
    # `complete_code` are the conventional short names other projects use --
    # Gauntlet: Dark Legacy labels `measure=code` "Code" and
    # `measure=complete_code` "Linked Code" -- and both resolve for this project.
    MEASURES = {
        "code",
        "complete_code",
        "matched_code",
        "matched_code_percent",
        "matched_data_percent",
        "matched_functions",
        "matched_functions_percent",
        "fuzzy_match_percent",
        "complete_code_percent",
        "complete_units",
    }
    # Only `fuzzy_match_percent` gives partial credit now. tools/gen_decomp_report.py
    # computes the report itself and defines `matched_*` as strictly byte-exact and
    # `complete_*` as shipped-in-the-linked-image, so the matched family is no
    # longer fuzzy-weighted the way objdiff-cli's derived report made it.
    FUZZY = {"fuzzy_match_percent"}

    @classmethod
    def setUpClass(cls) -> None:
        cls.text = (REPO / "README.md").read_text(encoding="utf-8")
        cls.urls = re.findall(r"https://decomp\.dev/[^\s)\"]+\.svg\?[^\s)\"]+", cls.text)

    def query(self, url):
        return urllib.parse.parse_qs(urllib.parse.urlsplit(url).query)

    def test_readme_has_decomp_dev_badges(self) -> None:
        self.assertTrue(self.urls, "README lost its decomp.dev badges")

    def test_every_badge_requests_shield_mode(self) -> None:
        """Without mode=shield the same URL returns a multi-megabyte treemap."""
        for url in self.urls:
            self.assertEqual(self.query(url).get("mode"), ["shield"], url)

    def test_every_category_is_one_we_actually_emit(self) -> None:
        ids = {c["id"] for c in gen_objdiff.PROGRESS_CATEGORIES}
        for url in self.urls:
            for category in self.query(url).get("category", []):
                self.assertIn(category, ids, url)

    def test_first_party_badge_uses_the_first_party_category(self) -> None:
        """A first-party label over the default category would read 27%, not 72%."""
        labelled = [u for u in self.urls if "first-party" in u]
        self.assertEqual(len(labelled), 1)
        self.assertEqual(self.query(labelled[0]).get("category"), ["main"])

    def test_every_measure_is_supported(self) -> None:
        for url in self.urls:
            for measure in self.query(url).get("measure", []):
                self.assertIn(measure, self.MEASURES, url)

    def test_fuzzy_measures_are_labelled_fuzzy(self) -> None:
        """A fuzzy measure may be published, but never under a label that reads
        as byte-identical.

        decomp.dev's `matched_*` and `fuzzy_match_percent` measures credit near
        misses, while this project's headline claim is byte-exactness, so the two
        must never be confusable. Forbidding fuzzy measures outright also hid
        genuinely useful information -- how close the unfinished 24% actually is
        -- so the rule is now that the label has to say so. `fuzzy match` is
        fine; `code` or `functions` over a fuzzy measure is not.
        """
        for url in self.urls:
            measures = self.query(url).get("measure", [])
            if not any(measure in self.FUZZY for measure in measures):
                continue
            label = " ".join(self.query(url).get("label", [])).lower()
            self.assertIn("fuzzy", label, url)

    def test_all_badges_point_at_one_slug_matching_the_pages_badge(self) -> None:
        for url in self.urls:
            self.assertIn(f"decomp.dev/{self.SLUG}.svg", url)
        owner, repo = self.SLUG.split("/")
        self.assertIn(f"{owner}.github.io/{repo}/progress/", self.text)

    def test_badges_link_to_the_project_page(self) -> None:
        """A bare image is a dead end; peers link the badge to the report."""
        for url in self.urls:
            self.assertIn(f"]({url})](https://decomp.dev/{self.SLUG})", self.text)


if __name__ == "__main__":
    unittest.main()
