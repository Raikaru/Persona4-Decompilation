import importlib.util
import os
import tempfile
import unittest
from pathlib import Path

_SPEC = importlib.util.spec_from_file_location(
    'pragma_scope_audit', os.path.join(os.path.dirname(__file__), '..', 'tools',
                                       'pragma_scope_audit.py'))
psa = importlib.util.module_from_spec(_SPEC)
try:
    _SPEC.loader.exec_module(psa)
    _LOADED = True
except BaseException:
    _LOADED = False


def scopes(text):
    with tempfile.TemporaryDirectory() as d:
        p = Path(d) / 'unit.c'
        p.write_text(text, encoding='utf-8')
        src = psa.lint.Source(p, p.read_bytes())
        return psa.scopes_for(src)


@unittest.skipUnless(_LOADED, 'pragma_scope_audit did not import')
class ScopeTracking(unittest.TestCase):
    def test_a_function_outside_any_pragma_is_clean(self):
        got = scopes('// FUN_00100000\nvoid func_00100000(void) {}\n')
        self.assertEqual(got['00100000'][1], {})

    def test_an_open_scope_reaches_the_next_function(self):
        # This is the whole point: the pragma was opened for the first function
        # and the second one inherits it.
        got = scopes('#pragma optimization_level 3\n'
                     '// FUN_00100000\n'
                     'void func_00100000(void) {}\n'
                     '// FUN_00100010\n'
                     'void func_00100010(void) {}\n')
        self.assertEqual(got['00100010'][1], {'optimization_level': '3'})

    def test_closing_the_scope_stops_it(self):
        got = scopes('#pragma optimization_level 3\n'
                     '// FUN_00100000\n'
                     'void func_00100000(void) {}\n'
                     '#pragma optimization_level 2\n'
                     '// FUN_00100010\n'
                     'void func_00100010(void) {}\n')
        self.assertEqual(got['00100010'][1], {})

    def test_markers_are_found_despite_being_comments(self):
        # decomp_lint.Source.code strips comments, so reading markers from it
        # finds nothing and reports a clean tree - the wrong answer.
        got = scopes('// FUN_00100000\nvoid func_00100000(void) {}\n')
        self.assertIn('00100000', got)

    def test_a_pragma_quoted_in_a_comment_is_not_a_directive(self):
        got = scopes('/* measured: removing\n'
                     '#pragma schedule on\n'
                     '   costs 4 words. */\n'
                     '// FUN_00100000\n'
                     'void func_00100000(void) {}\n')
        self.assertEqual(got['00100000'][1], {})

    def test_several_knobs_accumulate(self):
        got = scopes('#pragma schedule on\n'
                     '#pragma no_branch_likely on\n'
                     '// FUN_00100000\n'
                     'void func_00100000(void) {}\n')
        self.assertEqual(got['00100000'][1],
                         {'schedule': 'on', 'no_branch_likely': 'on'})

    def test_untracked_pragmas_are_ignored(self):
        got = scopes('#pragma push\n'
                     '#pragma warn_illpragma on\n'
                     '// FUN_00100000\n'
                     'void func_00100000(void) {}\n')
        self.assertEqual(got['00100000'][1], {})

    def test_reported_line_is_the_marker_line(self):
        got = scopes('#pragma schedule on\n'
                     '// FUN_00100000\n'
                     'void func_00100000(void) {}\n')
        self.assertEqual(got['00100000'][0], 2)

    def test_defaults_cover_the_knobs_lint_bans(self):
        for knob in ('optimization_level', 'schedule', 'opt_common_subs',
                     'opt_loop_invariants'):
            self.assertIn(knob, psa.DEFAULTS)


if __name__ == '__main__':
    unittest.main()
