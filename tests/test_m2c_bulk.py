from __future__ import annotations

import importlib.util
import json
import sys
import tempfile
import struct
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "m2c_bulk.py"
SPEC = importlib.util.spec_from_file_location("p4_m2c_bulk_tests", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
bulk = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = bulk
SPEC.loader.exec_module(bulk)


class M2cBulkTests(unittest.TestCase):
    def test_parses_valid_syntax_function_blocks(self) -> None:
        output = """Warning: missing jr
M2C_UNK func_00400020(); /* extern */

void func_00100000(void) {
    func_00400020();
}

s32 func_00100010(s32 arg0) {
    return arg0 + 1;
}
"""
        parsed = bulk.parse_m2c_output(output)
        self.assertEqual(sorted(parsed), [0x00100000, 0x00100010])
        self.assertIn("func_00400020", parsed[0x00100000].body)
        self.assertEqual(parsed[0x00100010].declarations, ("M2C_UNK func_00400020(); /* extern */",))
    def test_ignores_calls_that_look_like_function_definitions(self) -> None:
        output = """if (func_00100010()) {
    return 1;
}

s32 func_00100010(void) {
    return 2;
}
"""
        parsed = bulk.parse_m2c_output(output)
        self.assertEqual(sorted(parsed), [0x00100010])
        self.assertTrue(parsed[0x00100010].body.startswith("s32 func_00100010"))
    def test_excludes_candidate_own_prototype(self) -> None:
        candidate = bulk.M2cCandidate(
            "void func_00100000(void) {\n    return func_00400020();\n}",
            (
                "void func_00100000(s32 arg0, s32);",
                "M2C_UNK func_00400020(s32, void *);",
            ),
        )
        self.assertEqual(
            bulk.declaration_subset(candidate, set()),
            ("M2C_UNK func_00400020();",),
        )
    def test_declares_fallback_and_direct_data_calls(self) -> None:
        candidate = bulk.M2cCandidate(
            "void func_00100000(void) {\n"
            "    func_00100010();\n"
            "    D_00001000();\n"
            "    jtbl_00001000();\n"
            "}",
            (
                "extern M2C_UNK D_00001000;",
                "extern M2C_UNK jtbl_00001000[];",
            ),
        )
        self.assertEqual(
            bulk.declaration_subset(candidate, {0x00100010}),
            (
                "extern M2C_UNK D_00001000();",
                "extern M2C_UNK jtbl_00001000();",
                "extern M2C_UNK func_00100010();",
            ),
        )
        self.assertEqual(
            bulk.normalize_external_declaration(
                "extern void *func_00100020(s32);",
                set(),
            ),
            "extern u8 *func_00100020();",
        )
        self.assertEqual(
            bulk.normalize_external_declaration(
                "extern M2C_UNK D_008873F4;",
                {"D_008873F4"},
            ),
            "extern u8 *D_008873F4();",
        )
        self.assertEqual(
            bulk.normalize_external_declaration(
                "extern M2C_UNK func_003df8c0();",
                set(),
                {"func_003df8c0"},
            ),
            "extern void func_003df8c0();",
        )
        self.assertEqual(
            bulk.normalize_external_declaration(
                "M2C_UNK (**func_00510e40();",
                {"func_00510e40"},
            ),
            "extern M2C_UNK func_00510e40();",
        )
        self.assertEqual(
            bulk.function_return_hints(
                "void func_00100070(void) {\n"
                "    M2C_FIELD(arg0, s32 (**)(s32), 0x48) = func_003a2290;\n"
                "}"
            ),
            {"func_003a2290": "s32"},
        )
        bitwise = bulk.normalize_candidate_body(
            "u8 *func_00100080(f32 value) {\n"
            "    return M2C_BITWISE(u8 *, value);\n"
            "}"
        )
        self.assertIn("return ((u8 *)(s32)(value));", bitwise)

    def test_normalizes_opaque_pointers_and_missing_placeholders(self) -> None:
        body = (
            "void func_00100000(void *arg0) {\n"
            "    s32 value;\n"
            "\n"
            "    value = sp0;\n"
            "    arg0 += 4;\n"
            "}"
        )
        normalized = bulk.normalize_candidate_body(body)
        self.assertIn("void func_00100000(u8 *arg0)", normalized)
        self.assertIn("    M2C_UNK sp0;", normalized)
        self.assertIn("    arg0 += 4;", normalized)
        existing = bulk.normalize_candidate_body(
            "void func_00100010(void) {\n"
            "    s64 sp90; /* compiler-managed */\n"
            "\n"
            "    return sp90;\n"
            "}"
        )
        self.assertNotIn("M2C_UNK sp90;", existing)
        pointer_cast = bulk.normalize_candidate_body(
            "void func_00100020(void) {\n"
            "    s32 *temp_6;\n"
            "    u8 *temp_7;\n"
            "\n"
            "    temp_7 = temp_6 - 1;\n"
            "}"
        )
        self.assertIn("temp_7 = (u8 *)(temp_6 - 1);", pointer_cast)
        scalar_cast = bulk.normalize_candidate_body(
            "s32 func_00100025(u8 *arg0) {\n"
            "    s32 value;\n"
            "    value = arg0 + 4;\n"
            "    return arg0;\n"
            "}"
        )
        self.assertIn("value = (s32)(arg0 + 4);", scalar_cast)
        self.assertIn("return (s32)(arg0);", scalar_cast)
        compound_scalar_cast = bulk.normalize_candidate_body(
            "void func_00100026(s32 *arg0, s32 *arg1) {\n"
            "    s32 *var_4;\n"
            "    var_4 = arg0;\n"
            "    *var_4 += arg1;\n"
            "}"
        )
        self.assertIn("*var_4 += (s32)(arg1);", compound_scalar_cast)
        global_scalar_cast = bulk.normalize_candidate_body(
            "void func_00100027(void) {\n"
            "    D_00100000 = &D_00100000;\n"
            "}"
        )
        self.assertIn("D_00100000 = (s32)(&D_00100000);", global_scalar_cast)
        function_pointer_cast = bulk.normalize_candidate_body(
            "void func_00100028(void) {\n"
            "    M2C_UNK (**temp_2)();\n"
            "    temp_2 = func_00100029();\n"
            "}"
        )
        self.assertIn(
            "temp_2 = (M2C_UNK (**)())(func_00100029());",
            function_pointer_cast,
        )
        pointer_lvalue_cast = bulk.normalize_candidate_body(
            "void func_0010002A(s32 **arg0, u8 **arg1) {\n"
            "    *arg0 = arg1;\n"
            "    M2C_FIELD(arg1, u8 **, 0) = sp0;\n"
            "}",
        )
        self.assertIn("*arg0 = (s32 *)(arg1);", pointer_lvalue_cast)
        self.assertIn(
            "M2C_FIELD(arg1, u8 **, 0) = (u8 *)(sp0);",
            pointer_lvalue_cast,
        )
        global_pointer_cast = bulk.normalize_candidate_body(
            "void func_0010002B(void) {\n"
            "    D_00100000 = &D_00100004;\n"
            "}",
            (
                "extern u8 *D_00100000;",
                "extern M2C_UNK D_00100004;",
            ),
        )
        self.assertIn(
            "D_00100000 = (u8 *)(&D_00100004);",
            global_pointer_cast,
        )
        comparison_cast = bulk.normalize_candidate_body(
            "void func_0010002C(s32 arg0, u8 *ptr) {\n"
            "    if (arg0 == ptr) {\n"
            "    }\n"
            "    if (ptr != 0) {\n"
            "    }\n"
            "    if (M2C_FIELD(arg0, s32 *, 0) == ptr) {\n"
            "    }\n"
            "    if (func_0010002D() == NULL) {\n"
            "    }\n"
            "}",
        )
        self.assertIn("if ((u8 *)(arg0) == ptr)", comparison_cast)
        self.assertIn("if (ptr != (u8 *)(0))", comparison_cast)
        self.assertIn(
            "if ((u8 *)(M2C_FIELD(arg0, s32 *, 0)) == ptr)",
            comparison_cast,
        )
        self.assertIn(
            "if ((u8 *)(func_0010002D()) == NULL)",
            comparison_cast,
        )
        indirect = bulk.normalize_candidate_body(
            "void func_00100030(s32 arg0) {\n"
            "    *(&D_005DCC68 + (arg0 * 4))(arg0);\n"
            "}"
        )
        self.assertIn(
            "((M2C_UNK (*)())((u8 *)&D_005DCC68 + (arg0 * 4)))(arg0);",
            indirect,
        )
        labels = bulk.normalize_candidate_body(
            "void func_00100040(void) {\n"
            "    if (1) {\n"
            "    } else {\n"
            "    default:\n"
            "    }\n"
            "}"
        )
        self.assertNotIn("default:", labels)
        dereference = bulk.normalize_candidate_body(
            "s32 func_00100050(s32 arg0) {\n"
            "    s32 value;\n"
            "\n"
            "    value = *(arg0 + 4);\n"
            "    return value;\n"
            "}"
        )
        self.assertIn("value = *((u8 *)(arg0 + 4));", dereference)
        explicit_vector = bulk.normalize_candidate_body(
            "void func_00100085(void) {\n"
            "    *((s128 *)0x10007010) = 0;\n"
            "}"
        )
        self.assertIn("*((s128 *)0x10007010) = 0;", explicit_vector)
        multiplication = bulk.normalize_candidate_body(
            "f32 func_00100055(f32 value) {\n"
            "    f32 result;\n"
            "    result = 2.0f * (value + 1.0f);\n"
            "    return result;\n"
            "}"
        )
        self.assertIn("result = 2.0f * (value + 1.0f);", multiplication)
        indexing = bulk.normalize_candidate_body(
            "void func_00100060(void) {\n"
            "    s32 spEC;\n"
            "    s32 index;\n"
            "    index = 0;\n"
            "    (&spEC[0])[index] = 1;\n"
            "}"
        )
        self.assertIn("((u8 *)&spEC)[index] = 1;", indexing)
        arithmetic = bulk.normalize_candidate_body(
            "u8 *func_00100070(void) {\n"
            "    return (u8 *)((-0x2000 - &D_00100000) + &D_00100004);\n"
            "}"
        )
        self.assertIn("(s32)&D_00100000", arithmetic)
        self.assertIn("(s32)&D_00100004", arithmetic)
        address_of_cast = bulk.normalize_candidate_body(
            "void func_00100071(void) {\n"
            "    if (&(u8 *)(spE0) == NULL) {\n"
            "    }\n"
            "}"
        )
        self.assertNotIn("&(u8 *)(spE0)", address_of_cast)
        malformed_declaration = bulk.normalize_candidate_body(
            "void func_00100072(void) {\n"
            "    M2C_UNK (*func_00100073(); /* extern */\n"
            "}"
        )
        self.assertIn("extern M2C_UNK func_00100073();", malformed_declaration)
        function_field = bulk.normalize_candidate_body(
            "void func_00100074(void) {\n"
            "    M2C_FIELD(sp, void (**)(u8 *), 8) = func_00100075;\n"
            "}"
        )
        self.assertIn(
            "M2C_FIELD(sp, void (**)(u8 *), 8) = "
            "(void (*)(u8 *))((void (**)(u8 *))(func_00100075));",
            function_field,
        )
        bare_function = bulk.normalize_candidate_body(
            "void func_00100076(void) {\n"
            "    f32 value;\n"
            "    value = nanf;\n"
            "}"
        )
        self.assertIn("value = nanf();", bare_function)
    def test_promotes_only_verifier_proven_matches(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            source = directory / "code1_0010.c"
            source.write_text(
                "// FUN_00100000 NONMATCHING\n"
                "// FUN_00100010 NONMATCHING\n",
                encoding="utf-8",
            )
            report = directory / "report.json"
            report.write_text(
                json.dumps(
                    {
                        "results": [
                            {
                                "file": "src\\generated\\code1_0010.c",
                                "addr": "00100000",
                                "status": "STALE_NONMATCHING",
                                "normalized_diff": 0,
                            },
                            {
                                "file": "src\\generated\\code1_0010.c",
                                "addr": "00100010",
                                "status": "NONMATCHING",
                                "normalized_diff": 4,
                            },
                        ]
                    }
                ),
                encoding="utf-8",
            )
            promoted, verified = bulk.promote_verified_matches(
                directory, report, {0x00100000, 0x00100010}
            )
            self.assertEqual((promoted, verified), (1, 1))
            self.assertEqual(
                source.read_text(encoding="utf-8"),
                "// FUN_00100000\n// FUN_00100010 NONMATCHING\n",
            )

    def test_loads_code2_alabel_boundaries(self) -> None:
        blocks = bulk.load_assembly_blocks()
        self.assertIn(0x0070C850, blocks)
        self.assertIn(0x0070CF00, blocks)
        self.assertIn("glabel func_0070cf00", blocks[0x0070CF00])


    def test_loads_jump_table_words_from_image(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            symbols = directory / "undefined_syms.txt"
            symbols.write_text(
                "jtbl_00001000 = 0x1000;\n"
                "jtbl_00001008 = 0x1008;\n",
                encoding="utf-8",
            )
            image = bytearray(0x1010)
            struct.pack_into("<II", image, 0x1000, 0x00100020, 0)
            image_path = directory / "image.bin"
            image_path.write_bytes(image)
            loaded_symbols = bulk.load_jump_table_symbols(symbols)
            tables = bulk.load_jump_tables(image_path, loaded_symbols, image_vram=0)
            self.assertEqual(loaded_symbols["jtbl_00001000"], 0x1000)
            self.assertEqual(tables["jtbl_00001000"].words, (0x00100020,))

    def test_prepares_indirect_jump_table_targets(self) -> None:
        block = """glabel func_00100000
    /* 000000 00100000 3C040070 */  lui        $4, 0x70
    /* 000004 00100004 24840000 */  addiu      $4, $4, %lo(jtbl_00700000)
    /* 000008 00100008 00821021 */  addu       $2, $4, $2
    /* 00000C 0010000C 00400008 */  jr         $2
    /* 000010 00100010 00000000 */   nop
    """
        table = bulk.JumpTable("jtbl_00700000", 0x00700000, (0x00100010,))
        prepared, error = bulk.prepare_assembly_block(block, {table.name: table})
        self.assertIsNone(error)
        self.assertIn(".L00100010:", prepared.text)
        self.assertEqual(prepared.tables, ((table.name, (0x00100010,)),))
    def test_specializes_ambiguous_jump_table_setup(self) -> None:
        blocks = bulk.load_assembly_blocks()
        tables = bulk.load_jump_tables()
        contextual = bulk.prepare_control_flow_context(blocks[0x003CC720], blocks)
        prepared, error = bulk.prepare_assembly_block(contextual, tables)
        self.assertIsNone(error)
        self.assertEqual(
            [name for name, _ in prepared.tables],
            [
                "jtbl_00752E30",
                "jtbl_00752E00",
                "jtbl_00752DE0",
                "jtbl_00752DB0",
            ],
        )

    def test_recovers_split_branch_context_and_delay_slot(self) -> None:
        first = """glabel func_00100000
    /* 000000 00100000 0C000000 */  b          func_00100010
    /* 000004 00100004 00000000 */   nop
endlabel func_00100000
"""
        second = """glabel func_00100010
    /* 000010 00100010 0800E003 */  jr         $31
endlabel func_00100010
"""
        prepared = bulk.prepare_control_flow_context(
            first, {0x00100000: first, 0x00100010: second}
        )
        self.assertIn(".L00100010:", prepared)
        self.assertIn("jr         $31", prepared)
        self.assertIn("    nop", prepared)

    def test_renders_multiple_units_in_one_c_file(self) -> None:
        fallbacks = {
            0x00100000: bulk.Fallback(0x00100000, 16, "build/function_sources/code1_0010.c"),
            0x00100010: bulk.Fallback(0x00100010, 16, "build/function_sources/code1_0010.c"),
        }
        generated = {
            0x00100000: bulk.M2cCandidate(
                "s32 func_00100000(void) {\n    return func_00400020();\n}",
                ("M2C_UNK func_00400020();",),
            )
        }
        with tempfile.TemporaryDirectory() as temporary:
            output = Path(temporary)
            files = bulk.render_candidates(
                output,
                fallbacks,
                generated,
                {0x00100010: "test fallback"},
                {0x00100010: "// FUN_00100010 RETAIL_ASM\nasm void func_00100010(void) {}"},
            )
            self.assertEqual([path.name for path in files], ["code1_0010.c"])
            text = files[0].read_text(encoding="utf-8")
            self.assertIn("P4_UNIT_00100000", text)
            self.assertIn("P4_UNIT_00100010", text)
            self.assertIn("M2C_CANDIDATE", text)
            self.assertIn("EXACT_RETAIL_FALLBACK", text)
            self.assertIn("M2C_UNK func_00400020();", text)
            source_output = output / "source"
            source_files = bulk.render_candidates(
                source_output,
                fallbacks,
                generated,
                {0x00100010: "test fallback"},
                {0x00100010: "// FUN_00100010 RETAIL_ASM\nasm void func_00100010(void) {}"},
                source_mode=True,
            )
            source_text = source_files[0].read_text(encoding="utf-8")
            self.assertIn('#include "include/type.h"', source_text)
            self.assertIn("// FUN_00100000 NONMATCHING", source_text)
            self.assertIn("// FUN_00100010 NONMATCHING", source_text)

    def test_moves_verified_units_into_unguarded_groups(self) -> None:
        source_text = """#include "include/type.h"

/* Grouped m2c candidates; not authoritative matching-C sources. */
#if defined(P4_UNIT_00100000)
// FUN_00100000 NONMATCHING
void func_00100000(void) {
    return;
}
#endif /* P4_UNIT_00100000 */

#if defined(P4_UNIT_00100010)
// FUN_00100010 NONMATCHING
void func_00100010(void) {
    return;
}
#endif /* P4_UNIT_00100010 */
"""
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "source"
            generated = source / "src" / "generated"
            generated.mkdir(parents=True)
            source_path = generated / "code1_0010.c"
            source_path.write_text(source_text, encoding="utf-8")
            initial_report = root / "initial.json"
            initial_report.write_text(
                json.dumps(
                    {
                        "results": [
                            {
                                "file": "src/generated/code1_0010.c",
                                "addr": "00100000",
                                "status": "MATCH",
                                "normalized_diff": 0,
                            }
                        ]
                    }
                ),
                encoding="utf-8",
            )
            grouped = source / "src" / "generated" / "matched"
            files, units = bulk.render_verified_groups(
                generated, grouped, initial_report
            )
            self.assertEqual((files, units), (1, 1))
            grouped_text = (grouped / "code1_0010.c").read_text(encoding="utf-8")
            self.assertNotIn("#if defined(P4_UNIT_", grouped_text)
            self.assertIn("// FUN_00100000 NONMATCHING", grouped_text)

            grouped_report = root / "grouped.json"
            grouped_report.write_text(
                json.dumps(
                    {
                        "results": [
                            {
                                "file": "src/generated/matched/code1_0010.c",
                                "addr": "00100000",
                                "status": "MATCH",
                                "normalized_diff": 0,
                            }
                        ]
                    }
                ),
                encoding="utf-8",
            )
            applied_files, applied_units = bulk.apply_verified_groups(
                generated, grouped, grouped_report
            )
            self.assertEqual((applied_files, applied_units), (1, 1))
            remaining = source_path.read_text(encoding="utf-8")
            self.assertNotIn("P4_UNIT_00100000", remaining)
            self.assertIn("P4_UNIT_00100010", remaining)

    def test_rewrites_retail_words_for_mwcc_inline_asm(self) -> None:
        body = (
            "// FUN_00100010 RETAIL_ASM\n"
            "asm void func_00100010(void) {\n"
            "    .word 0x0300023C  /* 00100010 */\n"
            "}"
        )
        converted = bulk.prepare_retail_asm_candidate(body)
        self.assertIn(".word 0x3C020003  /* 00100010 */", converted)

if __name__ == "__main__":
    unittest.main()
