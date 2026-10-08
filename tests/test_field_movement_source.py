"""Lexical boundaries for bounded Field witnesses, without a C preprocessor."""
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from field_movement_source import movement_definition


class FieldMovementSourceTests(unittest.TestCase):
    def test_comments_literals_nested_blocks_and_directives(self):
        body = r'''s32 func_00174e10(u8 *arg0)
{
    /* } #else { */
    const char *text = "} \\\" {";
    char brace = '}'; // }
    if (arg0) { while (*arg0) { ++arg0; } }
    return 1;
}'''
        for prefix, suffix in (
            ('#define UNUSED } {\n#pragma push\n// FUN_00174E10\n', '\n#pragma pop\n'),
            ('// FUN_00174E10 NONMATCHING\n#ifdef NON_MATCHING\n',
             '\n#else\nINCLUDE_ASM("owner", func_00174e10);\n#endif\n'),
        ):
            source = prefix + body + suffix + '\nvoid sibling(void) { int x = 123; }\n'
            self.assertEqual(movement_definition(source), body)
            self.assertEqual(movement_definition(source.replace('\n', '\r\n')),
                             body.replace('\n', '\r\n'))

    def test_definition_spelling_in_comment_or_string_is_not_a_definition(self):
        body = 's32 func_00174e10(u8 *arg0) { return 1; }'
        source = '// ' + body + '\nchar *s = "' + body + '";\n' + body
        self.assertEqual(movement_definition(source), body)

    def test_missing_duplicate_and_unterminated_definitions_rejected(self):
        body = 's32 func_00174e10(u8 *arg0) { return 1; }'
        for source in ('// ' + body, body + '\n' + body, body[:-1]):
            with self.subTest(source=source), self.assertRaises(ValueError):
                movement_definition(source)

    def test_line_splices_fail_closed_before_comment_or_directive_parsing(self):
        body = 's32 func_00174e10(u8 *arg0) { return 1; }'
        for source in ('// hidden ' + '\\' + '\n' + body,
                       body.replace('return 1;', '#\\\nif FLAG\nreturn 1;\n#endif\n'),
                       '#define UNUSED } ' + '\\' + '\n{\n' + body):
            with self.subTest(source=source), self.assertRaisesRegex(ValueError, 'preprocessing'):
                movement_definition(source)

    def test_alternative_c_punctuators_fail_closed(self):
        body = 's32 func_00174e10(u8 *arg0) { return 1; }'
        for source in ('// hidden ??/\n' + body,
                       body.replace('return 1;', '%:if FLAG\nreturn 1;\n%:endif\n'),
                       body.replace('{', '<%').replace('}', '%>')):
            with self.subTest(source=source), self.assertRaisesRegex(ValueError, 'preprocessing'):
                movement_definition(source)

    def test_inner_conditionals_fail_closed(self):
        for directive in ('#if ENABLED', '#ifdef ENABLED', '#ifndef ENABLED',
                          '#define c148 ignored', '#undef c148', '#pragma unused(arg0)'):
            source = ('s32 func_00174e10(u8 *arg0) {\n' + directive +
                      '\n{ return 1; }\n#else\nreturn 0;\n#endif\n}')
            with self.subTest(directive=directive), self.assertRaisesRegex(ValueError, 'preprocessing'):
                movement_definition(source)


if __name__ == '__main__':
    unittest.main()
