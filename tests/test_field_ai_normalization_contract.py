"""Exercise the 25 real guarded normalization call fragments with 32-bit pointers.

The recording provider checks object/alias boundaries and supplies distinct XYZ
outputs plus fractional floating returns. It is deliberately NOT retail execution
or a numerical PS2 normalization emulator. SDK declarations constrain the
boundary; retail evidence and full-owner token equivalence live in the archive.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / "tools"), str(ROOT / "tests")]
from measure_guarded import extract_guarded_body
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

OWNER = ROOT / "src/Kosaka/Field/k_fldAI.c"
PROTOTYPE = "extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);"
# Three consecutive old scalar names, in x/y/z order, for each real object.
SCALARS = {
    "state11Delta": ("200", "1fc", "1f8"),
    "state11Right": ("1f0", "1ec", "1e8"),
    "state11Forward": ("1e0", "1dc", "1d8"),
    "state10Delta": ("1c0", "1bc", "1b8"),
    "state10Right": ("1b0", "1ac", "1a8"),
    "state10Forward": ("1a0", "19c", "198"),
    "state9Direction": ("180", "17c", "178"),
    "state9Delta": ("170", "16c", "168"),
    "state9Right": ("160", "15c", "158"),
    "state9Forward": ("150", "14c", "148"),
    "state8Delta": ("120", "11c", "118"),
    "state8Right": ("110", "10c", "108"),
    "state8Forward": ("100", "fc", "f8"),
    "state7Delta": ("e0", "dc", "d8"),
    "state7Right": ("d0", "cc", "c8"),
    "state7Forward": ("c0", "bc", "b8"),
    "state6Direction": ("a0", "9c", "98"),
    "state6Delta": ("90", "8c", "88"),
    "state2Delta": ("50", "4c", "48"),
    "state2Right": ("40", "3c", "38"),
    "state2Forward": ("30", "2c", "28"),
}
# Object names are frozen in lexical call order; repeated delta buffers are
# intentionally reused by later distance checks in the same state.
CALL_OBJECTS = (
    "state2Forward", "state2Right", "state2Delta", "state6Direction", "state6Delta",
    "state7Forward", "state7Right", "state7Delta", "state7Delta", "state8Delta",
    "state8Forward", "state8Right", "state8Delta", "state8Delta", "state9Forward",
    "state9Right", "state9Direction", "state9Delta", "state10Forward", "state10Right",
    "state10Delta", "state11Forward", "state11Right", "state11Delta", "state11Delta",
)

RETURN_SITES = {2: "temp_v10", 4: "temp_v8", 7: "temp_v10", 8: "temp_v8",
                9: "temp_v10", 12: "temp_v10", 13: "temp_v8", 17: "temp_v10",
                20: "temp_v10", 24: "temp_v8"}


def body():
    return extract_guarded_body(OWNER.read_text(), "FUN_0017F490", "func_0017f490")


def source_contract(source):
    assert source.count(PROTOTYPE) == 1, "canonical complete-vector floating prototype"
    assert "FUN_003e40b0" not in source, "no stale integer-return name"
    assert len(re.findall(r"\bRwV3dNormalize\(", source)) == 26
    calls = re.findall(r"(?m)^\s*(?:(temp_v(?:8|10)) = )?RwV3dNormalize\(&(state\w+),&(state\w+)\);", source)
    assert len(calls) == 25 and sum(bool(c[0]) for c in calls) == 10
    assert tuple(c[1] for c in calls) == CALL_OBJECTS, "normalization call order"
    assert {i: c[0] for i, c in enumerate(calls) if c[0]} == RETURN_SITES, "floating-return consumers"
    assert all(c[1] == c[2] for c in calls), "every call is in-place"
    for name, offsets in SCALARS.items():
        assert source.count("FldAIVec3 " + name + ";") == 1, name
        for offset in offsets:
            assert not re.search(r"\bfStack_" + offset + r"\b", source), "no orphaned scalar vector component"


def declarations(source, names):
    out = []
    for name in names:
        found = re.search(r"(?m)^  (?:FldAIVec3|float|int)\s*\*?\s*" + re.escape(name) + r";", source)
        assert found, name
        out.append(found[0].strip())
    return "\n".join(out)


# Independent source-storage oracle kinds, in actual lexical call order.
KINDS = (0, 1, 2, 3, 4, 0, 1, 3, 5, 3, 0, 1, 6, 5, 0, 1, 7, 8, 0, 1, 2, 0, 1, 3, 5)
ANCHORS = {
    "fStack_60": "x", "fStack_58": "z", "fStack_b0": "x", "fStack_ac": "y", "fStack_a8": "z",
    "fStack_f0": "x", "fStack_ec": "y", "fStack_e8": "z", "fStack_130": "x", "fStack_12c": "y", "fStack_128": "z",
    "fStack_140": "x", "fStack_13c": "y", "fStack_138": "z", "fStack_190": "x", "fStack_18c": "y", "fStack_188": "z",
    "fStack_1d0": "x", "fStack_1c8": "z", "fStack_210": "x", "fStack_20c": "y", "fStack_208": "z",
}


def parts():
    source = body()
    source_contract(source)
    full = OWNER.read_text()
    alias = re.search(r"(?m)^typedef RwV3d FldAIVec3;", full)[0]
    prototype = re.search(r"(?m)^extern f32 RwV3dNormalize\(RwV3d \*out, const RwV3d \*in\);", source)[0]
    lines = source.splitlines()
    wrappers = []
    for pos, line in enumerate(lines):
        call = re.fullmatch(r"\s*(?:(temp_v(?:8|10)) = )?RwV3dNormalize\(&(state\w+),&(state\w+)\);", line)
        if not call:
            continue
        returned, name, other = call.groups()
        assert name == other
        constructions = []
        for component in "xyz":
            candidates = [s.strip() for s in lines[:pos] if re.match(r"\s*" + name + r"\." + component + r" = ", s)]
            assert candidates, name
            constructions.append(candidates[-1])
        snippet = "\n".join(constructions + [line.strip()])
        scalar_names = sorted(set(re.findall(r"\bfStack_[0-9a-f]+\b", snippet)))
        state_names = sorted(set(re.findall(r"\bstate\w+\b", snippet)))
        deps = [n for n in state_names if n != name]
        wrapper = ["static void call_%d(void) {" % len(wrappers),
                   "    struct { u32 before[4]; " + declarations(source, [name]) + " u32 after[4]; } storage;",
                   declarations(source, scalar_names + deps + ["temp_v0", "piVar1", "pfVar8", "temp_v8", "temp_v10", "temp_v11"]),
                   "    temp_v0 = (int)matrix; piVar1 = (int *)work; pfVar8 = matrix;",
                   "    temp_v8 = anchor.y; temp_v10 = anchor.z; temp_v11 = coefficient;",
                   "    memset(&storage, 0xA5, sizeof(storage));",
                   "    CHECK(sizeof(storage." + name + ") == 12);",
                   "#define " + name + " storage." + name]
        wrapper += [n + " = anchor." + ANCHORS[n] + ";" for n in scalar_names]
        wrapper += [n + " = " + ("side" if n.endswith("Right") else "direction") + ";" for n in deps]
        wrapper += ["    expected_input = input_for_kind(%d);" % KINDS[len(wrappers)],
                    "    expected_pointer = &" + name + ";", snippet,
                    "    CHECK(provider_calls == 1);",
                    "    CHECK(" + name + ".x == output.x && " + name + ".y == output.y && " + name + ".z == output.z);"]
        if returned:
            wrapper += ["    CHECK(" + returned + " == length_return);"]
        wrapper += ["    for (u32 i = 0; i < 4; ++i) CHECK(storage.before[i] == 0xA5A5A5A5U && storage.after[i] == 0xA5A5A5A5U);",
                    "#undef " + name, "}"]
        wrappers.append("\n".join(wrapper))
    assert len(wrappers) == 25
    readers = []
    for state in (2, 7, 8, 9, 10, 11):
        delta, forward, right = ("state%d%s" % (state, suffix) for suffix in ("Delta", "Forward", "Right"))
        assignment = next(s.strip() for s in lines if re.match(r"\s*temp_v\d+ = .*" + delta + r"\.z \* " + forward, s))
        result = assignment.split(" = ")[0]
        expr = re.search(r"if \((" + delta + r"\.z \* " + right + r"\.z .*?) < 0\.0f\)", source)[1]
        readers += ["static void readback_%d(void) {" % state, declarations(source, [delta, forward, right, result]),
                    delta + " = output; " + forward + " = direction; " + right + " = side;",
                    assignment, "CHECK(" + result + " == " + ("1.0f - " if "1.0f -" in assignment else "") + "dot(output, direction));",
                    "CHECK((" + expr + " < 0.0f) == (dot(output, side) < 0.0f));", "}"]
    for state in (6, 9):
        name = "state%dDirection" % state
        assignments = [s.strip() for s in lines if re.match(r"\s*" + name + r"\.[xyz] = " + name + r"\.[xyz] \* 200\.0f", s)]
        assert len(assignments) == 3
        readers += ["static void direction_%d(void) {" % state, declarations(source, [name]),
                    declarations(source, ["piVar1"]), "piVar1 = (int *)work;", name + " = output;", *assignments]
        for c, index in zip("xyz", (20, 21, 22)):
            readers += ["CHECK(" + name + "." + c + " == output." + c + " * 200.0f" + (" + work[%d]" % index if state == 9 else "") + ");"]
        readers += ["}"]
    return {"ALIAS": alias, "PROTOTYPE": prototype, "CALLERS": "\n".join(wrappers), "READERS": "\n".join(readers)}


def fixture(mutation=None):
    values = parts()
    text = Path(__file__).with_name("field_ai_normalization_fixture.c.in").read_text()
    for key, value in values.items():
        text = text.replace("@" + key + "@", value)
    changes = {
        "integer_return_cast": ("= RwV3dNormalize(", "= (int)RwV3dNormalize("),
        "wrong_input_component": ("state2Forward.z = *(float *)(temp_v0 + 0x28);", "state2Forward.z = *(float *)(temp_v0 + 0x24);"),
        "wrong_delta_origin": ("state7Delta.z = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a4);", "state7Delta.z = *(float *)(temp_v0 + 0x38) - *(float *)(piVar1[3] + 0x1a0);"),
        "lost_output_z": ("out->z = output.z;", "out->z = output.y;"),
        "swapped_input_xy": ("state2Forward.x = *(float *)(temp_v0 + 0x20);\nstate2Forward.y = *(float *)(temp_v0 + 0x24);", "state2Forward.x = *(float *)(temp_v0 + 0x24);\nstate2Forward.y = *(float *)(temp_v0 + 0x20);"),
        "wrong_output_alias": ("RwV3dNormalize(&state2Forward,&state2Forward);", "RwV3dNormalize(&expected_input,&state2Forward);"),
        "broken_alias": ("RwV3dNormalize(&state2Forward,&state2Forward);", "RwV3dNormalize(&state2Forward,&expected_input);"),
        "shifted_pointer_cast": ("RwV3dNormalize(&state2Forward,&state2Forward);", "RwV3dNormalize((RwV3d *)&state2Forward.y,(RwV3d *)&state2Forward.y);"),
        "wrong_dot_component": ("state2Delta.z * state2Forward.z", "state2Delta.x * state2Forward.z"),
        "undersized_object": ("FldAIVec3 state2Forward;", "struct { f32 x; } state2Forward;"),
        "wrong_return_prototype": (PROTOTYPE, "extern int RwV3dNormalize(RwV3d *out, const RwV3d *in);"),
        "component_pointer": ("RwV3dNormalize(&state2Forward,&state2Forward);", "RwV3dNormalize(&state2Forward.x,&state2Forward.x);"),
    }
    if mutation:
        before, after = changes[mutation]
        assert before in text
        text = text.replace(before, after, 1 if mutation != "integer_return_cast" else -1)
        if mutation == "undersized_object":
            # The size assertion fires before the call: never execute an
            # intentional out-of-bounds write for a mutation-control result.
            start = text.index("static void call_0")
            end = text.index("static void call_1", start)
            part = text[start:end].replace("&state2Forward", "(RwV3d *)&state2Forward")
            part = part.replace("state2Forward.y", "state2Forward.x").replace("state2Forward.z", "state2Forward.x")
            text = text[:start] + part + text[end:]
    assert not re.search(r"@[A-Z_]+@", text)
    return RUNTIME_C + text + ENTRY_C


class FieldAINormalizationSource(unittest.TestCase):
    def test_normalization_family_shape_and_order(self):
        source_contract(body())

    def test_real_sdk_boundary_declaration(self):
        header = (ROOT / "include/rw/plcore/bavector.h").read_text()
        self.assertRegex(header, r"extern RwReal RwV3dNormalize\(RwV3d \* out, const RwV3d \* in\);")
    def test_source_guard_rejects_shape_order_and_cast_mutations(self):
        source = body()
        for old, new in (("&state2Forward,&state2Forward", "&state2Right,&state2Right"),
                         ("temp_v10 = RwV3dNormalize", "temp_v10 = (int)RwV3dNormalize"),
                         ("&state2Forward,&state2Forward", "(RwV3d *)&state2Forward.x,(RwV3d *)&state2Forward.x"),
                         ("extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);", "extern f32 RwV3dNormalize();"),
                         ("FldAIVec3 state2Forward;", "float state2Forward;")):
            with self.subTest(mutation=new):
                self.assertIn(old, source)
                with self.assertRaises(AssertionError):
                    source_contract(source.replace(old, new, 1))


class FieldAINormalizationNative(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, optimization, mutation=None):
        with tempfile.TemporaryDirectory(prefix="p4_field_ai_normalize_") as temporary:
            path = Path(temporary)
            source = path / "fixture.c"
            source.write_text(fixture(mutation))
            binary = self.runtime.compile(source, path / "fixture", optimization, (ROOT / "include",))
            return self.runtime.run(binary)

    def test_all_real_call_constructions_returns_and_readbacks(self):
        for opt in ("-O0", "-O2"):
            with self.subTest(optimization=opt):
                result = self.execute(opt)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "field_ai_normalize_calls=102400 readback_groups=32768\n")
                print(opt, result.stdout.strip())

    def test_runtime_mutation_controls(self):
        for opt in ("-O0", "-O2"):
            for mutation in ("integer_return_cast", "wrong_input_component", "wrong_delta_origin", "lost_output_z", "swapped_input_xy", "wrong_output_alias", "broken_alias", "shifted_pointer_cast", "wrong_dot_component", "undersized_object"):
                with self.subTest(optimization=opt, mutation=mutation):
                    result = self.execute(opt, mutation)
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("scenario", result.stdout)
                    print(opt, mutation, "rejected:", result.stdout.strip())

    def test_strict_compiler_rejects_wrong_boundary_types(self):
        for opt in ("-O0", "-O2"):
            for mutation in ("wrong_return_prototype", "component_pointer"):
                with self.subTest(optimization=opt, mutation=mutation):
                    with self.assertRaisesRegex(RuntimeError, "Native32 compilation failed"):
                        self.execute(opt, mutation)
                    print(opt, mutation, "rejected by strict compiler")


if __name__ == "__main__":
    unittest.main()
