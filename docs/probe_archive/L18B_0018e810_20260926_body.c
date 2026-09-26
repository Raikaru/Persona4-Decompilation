/* func_0018e810 (code1_0018.c) 2026-09-26 round 3: 25 fnalign edits
   (+20 reloc-only) at 452/452 instructions, 104 positional words. Round 2
   had 35 edits. To reproduce, install beside func_0018f950, whose
   PadStatus and PanelColor types (the X suffixes here) must then move
   above this function. The unit also needs func_00450340's format
   parameter typed as a pointer: `const char *arg1` in src/sdkDbprt.c,
   with `(void *)arg1` becoming `arg1` (that function stays MATCH) and the
   matching file-scope declaration in code1_0018.c. Without it the call
   evaluates `(s32)"%d"` first and scores about three edits worse.
   Levers over round 2:
   - pad reads as PadStatus members, which reproduces retail's reload
     after the cursor stores;
   - the draw position, cell colour and "%d" are a static
     {300.0f, 32.0f}, a static colour copied to a local before each
     func_0014def0 call (definition parameter order), and a literal;
   - cell addresses as `(u8 *)((y << 8) + (u32)func_00155280()) + x * 0x10
     + 0x54`. The integer add keeps retail's row-first `addu`, and the
     pointer add keeps the cell offset second;
   - `(off = x * 0x10)` inside the 0x58 read keeps the 0x58/0x59
     displacements folded.
   Residual (two coupled items): retail computes `y << 8` first in the
   y-loop preamble (b210 appends it after ty and panels), and it copies
   x * 16 into $s7 for the 0x58/0x59 reads where b210 copies y << 8.
   These made it worse:
   - a named `row` local, anywhere (95-414);
   - ty and panels inlined (49-64);
   - an all-integer address (the second addu flips);
   - a FieldMap[24][16] struct view (38 edits, base-first);
   - off in block scope, off at the top of the body, or no off (inert
     or worse). */
typedef struct {
    u8 unk00[0xC];
    u16 level;
    u16 trigger;
    u8 unk10[2];
    u16 repeat;
    u8 unk14[0x36];
} PadStatusX;
typedef struct {
    u8 r, g, b, a;
} PanelColorX;
typedef struct {
    f32 x, y;
} DbTextPosX;
s32 func_0018e810(u8 *arg0)
{
    extern PadStatusX D_008C0240[2];
    static DbTextPosX text_pos = {300.0f, 32.0f};
    static PanelColorX cell_color = {0xFF, 0x00, 0x00, 0x80};
    extern s32 iGpffffb240;
    extern s32 func_00470e20(s32 handle);
    extern void func_001582f0(s32 mode, s32 value, s32 arg2);
    PanelColorX color;
    u8 *state;
    s32 v0;
    s32 index;

    state = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)state) {
    case 0:
        *(s32 *)(state + 0x1B438) = func_00470250(arg0, 0x100, 0x40);
        func_00470810(*(s32 *)(state + 0x1B438), D_005F5730, 4);
        func_00470430(*(s32 *)(state + 0x1B438), 0x14);
        func_004703c0(*(s32 *)(state + 0x1B438), 4);
        func_004703d0(*(s32 *)(state + 0x1B438), 1);
        *(u8 **)(state + 0x1B434) = D_007E3720;
        *(s32 *)state += 1;
        break;
    case 1:
        if (D_008C0240[0].trigger & 0x40) {
            switch (func_00470e20(*(s32 *)(state + 0x1B438))) {
            case 0:
                *((u8 *)func_00155280() + 0x4A) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 9);
                *(s32 *)(state + 4) = 2;
                v0 = *func_00470bd0(*(s32 *)(state + 0x1B438), 0);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(s32 *)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 1:
                *((u8 *)func_00155280() + 0x4A) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 9);
                *(s32 *)(state + 4) = 0;
                v0 = *func_00470bd0(*(s32 *)(state + 0x1B438), 1);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(s32 *)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 2:
                *((u8 *)func_00155280() + 0x4A) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *((u8 *)(*func_00470bd0(*(s32 *)(state + 0x1B438), 3) * 0x10) +
                      (u32)*(u8 **)(state + 0x1B434) + 9);
                *(s32 *)(state + 4) = 1;
                v0 = *func_00470bd0(*(s32 *)(state + 0x1B438), 2);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(s32 *)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            }
        }
        break;
    case 2:
        *(s32 *)state += 1;
        break;
    case 3:
        *(s32 *)state += 1;
        break;
    case 4:
        if (D_008C0240[0].trigger & 0x8000) {
            *(s32 *)(state + 0x1B430) -= 1;
        } else if (D_008C0240[0].trigger & 0x2000) {
            *(s32 *)(state + 0x1B430) += 1;
        }
        if (*(s32 *)(state + 0x1B430) < 0) {
            *(s32 *)(state + 0x1B430) = 3;
        }
        if (*(s32 *)(state + 0x1B430) > 3) {
            *(s32 *)(state + 0x1B430) = 0;
        }
        if (D_008C0240[0].trigger & 0x40) {
            func_001582f0(*(s32 *)(state + 4), 0, 0);
        }
        func_00450340(*(s64 *)&text_pos, "%d", iGpffffb240);
        {
            s32 y;
            s32 x;
            s32 ty;
            u8 *panels;
            s32 colofs;
            s32 type;
            s32 off;
            f32 fx;
            f32 fy;

            for (y = 0; y < 0x18; y++) {
                for (x = 0, ty = y * 0x12, panels = state + y * 0x1200; x < 0x10; x++) {
                    if (*((u8 *)((y << 8) + (u32)func_00155280()) + x * 0x10 + 0x54) != 0 &&
                        (*((u8 *)((y << 8) + (u32)func_00155280()) + x * 0x10 + 0x55) & 0xF) == 1) {
                        type = *((u8 *)((y << 8) + (u32)func_00155280()) + (off = x * 0x10) + 0x58);
                        fx = (f32)(x * 0x12);
                        fy = (f32)ty;
                        func_0017d1f0(D_007966D0, panels + x * 0x120 + 0x10, type, 0,
                                      fx, fy, 0.0f,
                                      *((u8 *)((y << 8) + (u32)func_00155280()) + off + 0x59));
                    }
                    if (*((u8 *)((y << 8) + (u32)func_00155280()) + x * 0x10 + 0x54) == 2) {
                        color = cell_color;
                        func_0014def0(D_007966D0, panels + x * 0x120 + 0x10,
                                      (f32)(x * 0x12), (f32)ty, 0.0f, 18.0f, 18.0f,
                                      (u8 *)&color, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
                    }
                }
            }
        }
        if (D_008C0240[0].trigger & 0x20) {
            *(s32 *)state = 0;
        }
        break;
    }
    return 0;
}
