from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_probe_search",
                                              REPO / "tools" / "probe_search.py")
assert SPEC is not None and SPEC.loader is not None
search = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(search)


class DeclarationBlockTests(unittest.TestCase):
    def test_returns_the_leading_declarations_only(self) -> None:
        body = ("s32 f(u8 *p)\n"
                "{\n"
                "    s32 count;\n"
                "    u8 *scan;\n"
                "\n"
                "    count = 0;\n"
                "    u8 *late;\n"
                "}\n")
        declarations, start, end = search.declaration_block(body)
        self.assertEqual([d.strip() for d in declarations], ["s32 count;", "u8 *scan;"])
        self.assertEqual(body.split("\n")[start:end], declarations)

    def test_a_local_prototype_ends_the_block(self) -> None:
        """Permuting a declaration past a prototype it uses would not compile, and
        prototypes are not register-allocated anyway."""
        body = ("void f(void)\n"
                "{\n"
                "    extern s32 helper(u8 *p);\n"
                "    s32 count;\n"
                "}\n")
        declarations, _, _ = search.declaration_block(body)
        self.assertEqual(declarations, [])

    def test_arrays_and_qualifiers_are_declarations(self) -> None:
        body = ("void f(void)\n"
                "{\n"
                "    u16 buf[8];\n"
                "    const u8 *name;\n"
                "    volatile s32 flag;\n"
                "    buf[0] = 0;\n"
                "}\n")
        declarations, _, _ = search.declaration_block(body)
        self.assertEqual([d.strip() for d in declarations],
                         ["u16 buf[8];", "const u8 *name;", "volatile s32 flag;"])

    def test_a_body_without_declarations_yields_nothing(self) -> None:
        body = "void f(void)\n{\n    g();\n}\n"
        self.assertEqual(search.declaration_block(body)[0], [])


if __name__ == "__main__":
    unittest.main()
