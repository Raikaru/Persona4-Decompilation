import importlib.util
import os
import unittest

_SPEC = importlib.util.spec_from_file_location(
    'nd_audit', os.path.join(os.path.dirname(__file__), '..', 'tools', 'nd_audit.py'))
nd = importlib.util.module_from_spec(_SPEC)
try:
    _SPEC.loader.exec_module(nd)
    _LOADED = True
except BaseException:
    _LOADED = False


def claim(note_text, marker='// FUN_00100000'):
    lines = note_text.split('\n') + [marker]
    return nd.claimed_nd(lines, len(lines) - 1)


@unittest.skipUnless(_LOADED, 'nd_audit did not import')
class ClaimExtraction(unittest.TestCase):
    """Only the note's closing statement is the claim.

    Reading the last integer anywhere in the prose flagged 49 of 19 bodies as
    stale on the first run - notes routinely quote alternatives and before/after
    pairs, and every one of those looked like a drifted number.
    """

    def test_reads_a_trailing_claim(self):
        self.assertEqual(claim('/* measured: something. nd 22. */'), 22)

    def test_reads_the_as_committed_form(self):
        self.assertEqual(claim('/* measured: something.\n   nd 20 as committed. */'), 20)

    def test_ignores_numbers_quoted_mid_prose(self):
        self.assertIsNone(
            claim('/* measured: nd 46 with a while loop, nd 26 with break,\n'
                  '   and the shape below is exact. */'))

    def test_a_trailing_alternative_is_not_the_claim(self):
        # This is the shape that caused the false positives: the last sentence
        # quotes what a REJECTED spelling costs.
        self.assertIsNone(
            claim('/* measured: the goto graph is exact.\n'
                  '   The plain if form costs nd 31 here. */'))

    def test_no_note_at_all(self):
        self.assertIsNone(claim('s32 other_function(void);'))

    def test_a_note_without_any_number(self):
        self.assertIsNone(claim('/* measured: schedule on is load-bearing. */'))

    def test_stops_at_the_start_of_the_block(self):
        # A number in an EARLIER, unrelated comment must not be picked up.
        self.assertIsNone(claim('/* an older note mentioning nd 99 */\n'
                                '\n'
                                '/* measured: no number here. */'))

    def test_blank_lines_between_note_and_marker_are_skipped(self):
        self.assertEqual(claim('/* measured: fine. nd 7. */\n\n'), 7)


@unittest.skipUnless(_LOADED, 'nd_audit did not import')
class BlockDetection(unittest.TestCase):
    def test_finds_a_preserved_body(self):
        lines = ['// FUN_00100000', '#ifdef NON_MATCHING', 'void f(void) {}',
                 '#else', 'INCLUDE_ASM("asm", f);', '#endif']
        self.assertEqual(list(nd.preserved_blocks(lines)), [(0, 1, 3, 5)])

    def test_skips_pragmas_and_notes_between_marker_and_ifdef(self):
        lines = ['// FUN_00100000', '/* measured: x. */', '#pragma schedule on',
                 '#ifdef NON_MATCHING', 'void f(void) {}', '#else',
                 'INCLUDE_ASM("asm", f);', '#endif']
        self.assertEqual(list(nd.preserved_blocks(lines)), [(0, 3, 5, 7)])

    def test_a_plain_include_asm_is_not_a_preserved_body(self):
        lines = ['// FUN_00100000', 'INCLUDE_ASM("asm", f);']
        self.assertEqual(list(nd.preserved_blocks(lines)), [])

    def test_a_matched_body_is_not_a_preserved_body(self):
        lines = ['// FUN_00100000', 'void f(void) {}']
        self.assertEqual(list(nd.preserved_blocks(lines)), [])


if __name__ == '__main__':
    unittest.main()
