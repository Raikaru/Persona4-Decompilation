"""Exercise the guarded selection highlight using its actual C body and 32-bit ABI.

The fixture covers the selection renderer, first-free dispatch, live counter
reload and the resource-ready gate in phases 4/5. Other message states are
outside this fixture; unexpected calls fail rather than silently succeeding.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from measure_guarded import extract_guarded_body

OWNER = ROOT / "src/promoted/itfMsgProcedure_Window.c"
FIXTURE = ROOT / "tests/message_window_selection_fixture.c.in"
FUNCTION = "func_0027f6f0"


def fixture_source(mutation=None):
    source = OWNER.read_text(encoding="utf-8")
    body = extract_guarded_body(source, "FUN_0027F6F0", FUNCTION)
    prefix = source[:source.index("// FUN_0027CAE0")]
    # The freestanding fixture already provides the actual memory operation.
    # Its libc-compatible declaration is not part of the function under test.
    prefix = prefix.replace("extern s32 memset(void *a0, s32 a1, s32 a2);", "")
    prefix += "s32 func_0027f560(u8*);\nvoid func_0027f630(u8*);\n"
    prefix += "void func_0027d660(s32,s32,s32,s32,f32,void*);\n"
    resource_start = source.index("static inline s32 msgWinSelectionResource(void)")
    resource_end = source.index("\n}\n", resource_start) + 3
    resource_helper = source[resource_start:resource_end]
    if mutation is not None:
        before, after = mutation
        if body.count(before) + resource_helper.count(before) != 1:
            raise AssertionError("Negative control no longer identifies exactly one expression")
        body = body.replace(before, after)
        resource_helper = resource_helper.replace(before, after)
    functions = {
        match.group(2): match.group(0).strip().removeprefix("extern ").removesuffix(";")
        for match in re.finditer(
            r"^(?:extern )?([A-Za-z0-9_ *]+)\b(func_[0-9a-f]+|sinf|cosf)\(([^;{}]*)\);",
            prefix, re.M)
    }
    functions["func_00451fc0"] = (
        "void *func_00451fc0(void *parent, const void *name, s32 priority, s32 delay, "
        "s32 freeDelay, SdkTaskUpdate update, SdkTaskDestroy destroy, u8 *work)"
    )
    for match in re.finditer(
            r"^    extern ([A-Za-z0-9_ *]+)\b(func_[0-9a-f]+)\(([^;{}]*)\);", body, re.M):
        functions[match.group(2)] = match.group(0).strip().removeprefix("extern ").removesuffix(";")
    referenced = set(re.findall(r"\b(func_[0-9a-f]+|sinf|cosf)\b", body + resource_helper))
    mocked = {"func_00278110", "func_0027bec0", "func_0045da40", "func_00277070", "func_00279010", "sinf", "func_0025ecd0", "func_00452380", "func_00451fc0", FUNCTION}
    stubs = "\n".join(
        signature + ' { native32_failure(__LINE__, 0, "unexpected ' + name + '"); }'
        for name, signature in functions.items() if name in referenced and name not in mocked
    )
    definitions = []
    for line in (prefix + "\n" + body[:body.index("    PrimitiveRectangleColor color;")]).splitlines():
        match = re.match(r"\s*extern ([A-Za-z_][A-Za-z0-9_ *]+) (D_[A-Z0-9]+|iGp[a-z0-9]+)(\[[0-9]*\])?;", line)
        if match and match.group(1).strip() not in ("PrimitiveRectangleColor", "PrimitiveRectangleWords"):
            suffix = "[16]" if match.group(3) == "[]" else match.group(3) or ""
            if match.group(2) != "D_00796490":
                definitions.append(match.group(1) + " " + match.group(2) + suffix + ";")
    helper_start = source.index("static inline MsgProcWindowEntry *msgWinFindFreeEntry(void)")
    helper_end = source.index("\n}\n", helper_start) + 3
    helper = source[helper_start:helper_end]
    return (RUNTIME_C + prefix + "\n" + helper + "\n" + resource_helper + "\n" + body + "\n" + "\n".join(sorted(set(definitions)))
            + "\n" + stubs + "\n" + FIXTURE.read_text() + ENTRY_C)


class MessageWindowSelectionSourceTests(unittest.TestCase):
    def test_shared_packet_contract_and_complete_objects(self):
        text = fixture_source()
        self.assertIn("PrimitiveRectangleWords selection;", text)
        self.assertIn("selection.signedWords.word[1] = j >> 3;", text)
        self.assertIn("rectangle = selection;", text)
        self.assertIn("selectionColor.transport = iGpffffa784.transport;", text)
        self.assertIn('#include "primitive_rectangle_packet.h"', text)


class MessageWindowSelectionRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def run_fixture(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix="p4_message_selection_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(fixture_source(mutation), encoding="utf-8")
            for level in ("-O0", "-O2"):
                executable = self.runtime.compile(source, directory / ("fixture" + level), level, (ROOT / "include",))
                result = self.runtime.run(executable)
                if mutation is None:
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, "message-window contracts: 224 scenarios passed\n")
                else:
                    self.assertNotEqual(result.returncode, 0, "Negative control was not rejected")

    def test_complete_color_and_rectangle_snapshots(self):
        self.run_fixture()

    def test_stale_completion_counter_is_rejected(self):
        self.run_fixture(("if (D_00882024[0] >= 0x14)", "if (0)"))

    def test_pending_resource_is_not_used(self):
        self.run_fixture(("if (work->state >= 2)", "if (work->state >= 1)"))

    def test_second_task_search_is_preserved(self):
        self.run_fixture(("else if (func_00452380((s8 *)&D_00723868) == 0)", "else if (1)"))

    def test_task_creation_priority_is_preserved(self):
        self.run_fixture(("NULL, &D_00723868, 15, 0, 0", "NULL, &D_00723868, 14, 0, 0"))

    def test_wrong_color_is_rejected(self):
        self.run_fixture(("backgroundColor.transport = iGpffffa780.transport;", "backgroundColor.transport = iGpffffa784.transport;"))

    def test_wrong_rectangle_word_is_rejected(self):
        self.run_fixture(("selection.signedWords.word[1] = j >> 3;", "selection.signedWords.word[3] = j >> 3;"))

    def test_unmodified_template_is_rejected(self):
        self.run_fixture(("rectangle = selection;", "rectangle = D_0063C140;"))

    def test_truncated_rectangle_is_rejected(self):
        self.run_fixture(("selection.signedWords.word[0] = 0x38;", "selection.signedWords.word[0] = 0x38; selection.signedWords.word[2] = 0;"))


if __name__ == "__main__":
    unittest.main()
