"""Prepare the guarded trail proposal without modifying the source checkout."""
from pathlib import Path
import re
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants as P


def sdk_contracts(source):
    replacements = {
        "extern void func_00410420(s32 arg0, s32 arg1, void *arg2, s32 arg3);":
            "struct RxObjSpace3DVertex;\nextern void *func_00410420(struct RxObjSpace3DVertex *vertices, u32 count, BtlShuffleMatrix *matrix, u32 flags);",
        "extern void func_004106a0(s32 arg0);":
            "extern s32 func_004106a0(BtlShufflePrimitive primitive);",
        "extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);":
            "typedef enum RpSkyRenderState {\n"
            "    rpSKYRENDERSTATENARENDERSTATE = 0,\n"
            "    rpSKYRENDERSTATEDITHER,\n"
            "    rpSKYRENDERSTATEALPHA_1,\n"
            "    rpSKYRENDERSTATEATEST_1,\n"
            "    rpSKYRENDERSTATEFARFOGPLANE,\n"
            "    rpSKYRENDERSTATEMAXMIPLEVELS,\n"
            "    rpSKYRENDERSTATEFORCEENUMSIZEINT = 0x7fffffff\n"
            "} RpSkyRenderState;\n"
            "extern s32 RpSkyRenderStateSet(RpSkyRenderState state, void *value);",
        "extern void *func_003e9700(s32 arg0);":
            "struct RwFrame;\nextern BtlShuffleMatrix *func_003e9700(struct RwFrame *frame);",
    }
    for old, new in replacements.items():
        if source.count(old) != 1:
            raise ValueError("Expected one current declaration: " + old)
        source = source.replace(old, new)
    source = re.sub(r"RpSkyRenderStateSet\((\d+), (0x[0-9A-Fa-f]+)\)", r"RpSkyRenderStateSet(\1, (void *)\2)", source)
    for name in ("first", "second", "backVertices", "frontVertices"):
        source = source.replace("func_00410420((s32)" + name + ",", "func_00410420((struct RxObjSpace3DVertex *)" + name + ",")
        source = source.replace("func_00410420(" + name + ",", "func_00410420((struct RxObjSpace3DVertex *)" + name + ",")
    source = re.sub(r"(func_00410420\([^\n;]+, 4), m, 3\)", r"\1, (BtlShuffleMatrix *)m, 3)", source)
    source = source.replace("func_003e9700(*(s32 *)((u8 *)func_00457120() + 4))", "func_003e9700(*(struct RwFrame **)((u8 *)func_00457120() + 4))")
    source = source.replace("func_003e9700(camera)", "func_003e9700((struct RwFrame *)camera)")
    return source


def proposal(owner):
    original = P._read_text(owner)
    newline = P._newline_for(owner.read_bytes())
    start, end = P.region_for(original, "FUN_003768E0", "func_003768e0")
    body = (HERE / "body.c").read_text(encoding="utf-8")
    guarded = "#ifdef NON_MATCHING\n" + body + '\n#else\nINCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003768e0);\n#endif\n'
    source = P.splice_region(original, start, end, P._normalise_candidate(guarded, newline), newline)
    source = sdk_contracts(source)
    # Replace stale measurements about the replaced guard, preserving the
    # preceding matched sampler and the following matched display routine.
    start = source.index("/* measured 003768e0: archived")
    end = source.index("// FUN_003768E0 NONMATCHING", start)
    note = ("/* Guarded trail recovery: native 4176/4176 bytes and frame 0xF50;\n"
            " * 511 fully resolved differing words. Uses 21 samples, two 42-vertex\n"
            " * strips, native alpha conversions and finite 4/4/2 render passes.\n"
            " * Matrix flags are explicitly initialized; retail's SDK identity\n"
            " * macro reads an unwritten flag word. ASM remains the production\n"
            " * implementation. See docs/probe_archive/Shuffle_trail_003768e0_20261006. */\n")
    if newline != "\n":
        note = note.replace("\n", newline)
    return source[:start] + note + source[end:]
