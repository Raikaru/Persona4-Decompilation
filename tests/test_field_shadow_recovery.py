"""Exercise the recovered shadow construction and projection paths.

The unchanged production function runs with real 32-bit pointers at O0 and O2.
The constructor fixture checks allocation, geometry, state and queued callback
contracts. Deterministic trigonometric samples isolate the geometry and angle
sequence from the platform's sine/cosine implementation. Native MWCC proofs and
the complete retail link separately validate the PlayStation 2 instruction ABI.
Projection runs the actual atomic callback and checks the world, collision and
renderer boundaries, including allocation failures and render-state restoration.
"""
from __future__ import annotations

import math
from pathlib import Path
import re
import struct
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q  # noqa: E402
import verify as V  # noqa: E402

OWNER = ROOT / "src/promoted/code1_0017.c"
CALLBACKS = ROOT / "src/Kosaka/k_spipe.c"


def _definition(owner: Path, name: str) -> str:
    markers = [row for row in V.scan_markers(owner) if row["name"] == name]
    if len(markers) != 1 or markers[0].get("asm"):
        raise AssertionError(f"The fixture requires one recovered C definition: {owner}: {name}")
    return Q.function_bodies(owner)[name][1]


def _one_declaration(text: str, pattern: str) -> str:
    matches = list(re.finditer(pattern, text, re.S))
    if len(matches) != 1:
        raise AssertionError(f"Expected one production type declaration: {pattern}")
    return matches[0].group()


def _constructor_math() -> str:
    # fGpffff82bc at retail address 0x007613ac; the exact binary32 value is
    # 0.19634954631328583. Every accumulated angle is rounded like the C loop.
    step = struct.unpack("<f", struct.pack("<I", 0x3E490FDB))[0]

    def binary32(value: float) -> float:
        return struct.unpack("<f", struct.pack("<f", value))[0]

    angles = []
    angle = 0.0
    for _ in range(32):
        angles.append(angle)
        angle = binary32(angle + step)
    angles.append(0.0)
    output = f"f32 fGpffff82bc = {step.hex()}f;\n"
    samples = {"angles": angles, "sines": [binary32(math.sin(x)) for x in angles],
               "cosines": [binary32(math.cos(x)) for x in angles]}
    for name, values in samples.items():
        output += f"static const f32 fixture_{name}[33] = {{" + ",".join(
            value.hex() + "f" for value in values) + "};\n"
    return output


def shadow_construct_fixture(owner: Path | None = None, mutation: str | None = None) -> str:
    owner = owner or OWNER
    text = owner.read_text(encoding="utf-8")
    body = _definition(owner, "func_0017acc0")
    if mutation == "lost-bounds-center":
        before = "                *(RwV3d *)(ctx + 0x2C) = bounds.center;\n"
        after = ""
    elif mutation == "extra-atomic-indirection":
        before = "                *(u8 **)(*(u8 **)(ctx + 0x50) + 4) = func_003c00e0();"
        after = "                **(u8 ***)(*(u8 **)(ctx + 0x50) + 4) = func_003c00e0();"
    elif mutation is not None:
        raise ValueError(f"Unknown negative control: {mutation}")
    if mutation is not None:
        if body.count(before) != 1:
            raise AssertionError(f"Negative control no longer targets one operation: {mutation}")
        body = body.replace(before, after, 1)

    types = "\n".join(_one_declaration(text, pattern) for pattern in (
        r"typedef struct\s*\{\s*u8 red;.*?\} FieldColor_0017;",
        r"typedef struct RwV3d \{[^}]+\} RwV3d;",
        r"typedef struct FldShadowBoundsAccum \{[^}]+\} FldShadowBoundsAccum;",
        r"typedef struct RwSphere \{[^}]+\} RwSphere;",
    )) + "\nstruct RpTriangle;\nstruct RpMorphTarget;\n"
    getters = ROOT / "src/mdlManager_grouped.c"
    replacements = {
        "@@CONSTRUCT_TYPES@@": types,
        "@@MATH_DATA@@": _constructor_math(),
        "@@BOUNDS_CALLBACK@@": _definition(CALLBACKS, "func_00179130"),
        "@@MODEL_GETTERS@@": "\n".join(_definition(getters, name) for name in ("mdlGetMatrix", "mdlGetClump")),
        "@@MODEL_FLAG@@": _definition(ROOT / "src/Graphics/Model/mdlManager.c", "func_0047a810"),
        "@@CONSTRUCT_BODY@@": body,
    }
    result = Path(__file__).with_name("shadow_construct_fixture.c.in").read_text(encoding="utf-8")
    for token, value in replacements.items():
        if result.count(token) != 1:
            raise AssertionError(f"Fixture requires one substitution: {token}")
        result = result.replace(token, value)
    if "@@" in result:
        raise AssertionError("Unexpanded fixture token")
    return RUNTIME_C + result + ENTRY_C


def shadow_projection_fixture(owner: Path | None = None) -> str:
    owner = owner or OWNER
    replacements = {
        "@@TARGET@@": _definition(owner, "func_00179fc0"),
        "@@ATOMIC_CALLBACK@@": _definition(CALLBACKS, "func_00179f70"),
    }
    result = Path(__file__).with_name("shadow_project_fixture.c.in").read_text(encoding="utf-8")
    for token, value in replacements.items():
        if result.count(token) != 1:
            raise AssertionError(f"Fixture requires one substitution: {token}")
        result = result.replace(token, value)
    if "@@" in result:
        raise AssertionError("Unexpanded projection fixture token")
    return RUNTIME_C + result + ENTRY_C


class FieldShadowRecoveryTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def test_construction_state_geometry_and_callbacks(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_shadow_construct_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(shadow_construct_fixture(), encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(source, directory / ("fixture" + level),
                                                      level, (ROOT / "include",))
                    result = self.runtime.run(executable)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, "6912 shadow construction cases passed\n")
                    print(level, result.stdout.strip())

    def test_construction_fixture_rejects_lost_center_and_wrong_indirection(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_shadow_negative_") as temporary:
            directory = Path(temporary)
            for mutation in ("lost-bounds-center", "extra-atomic-indirection"):
                with self.subTest(mutation=mutation):
                    source = directory / (mutation + ".c")
                    source.write_text(shadow_construct_fixture(mutation=mutation), encoding="utf-8")
                    executable = self.runtime.compile(source, directory / mutation, "-O2", (ROOT / "include",))
                    result = self.runtime.run(executable)
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("scenario", result.stdout)

    def test_projection_world_atomic_draw_and_allocation_paths(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_shadow_projection_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(shadow_projection_fixture(), encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(source, directory / ("projection" + level),
                                                      level, (ROOT / "include",))
                    result = self.runtime.run(executable)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, "shadow_projection_cases=4 checks=187\n")
                    print(level, result.stdout.strip())


if __name__ == "__main__":
    unittest.main()
