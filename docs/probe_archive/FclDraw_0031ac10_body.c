/* func_0031ac10 draft (2026-09-25): fnalign 240 edits, 1450 vs 1448 instructions,
   frame 0x280 and every stack slot at its retail offset (probe_variants reports 1132
   reloc-masked words only because of the 2-instruction shift). The previous guarded
   body no longer compiled against the (u8 *, FclVec2, s8, s8, s32, u16, s16, s8, s8, u8)
   contract.

   Levers used (same family as FclDraw_0031e5b0_body.c):
     - struct-return func_002b2970 nested in every consuming call; the 2970 and 2a60
       results are then compiler temporaries in retail's appearance order (colours from
       0x27C down, points from 0x248 down);
     - local s16 func_002b6c30 extern; colours stored by FclByte4 assignment;
     - local func_002b6a70 extern with an s16 last parameter, passing `arg6 + 3`
       (with `(s16)(arg6 + 3)` against the s32 file prototype the frame grows 0x10);
     - `row12` is a named s16 (retail homes it at sp+0xE0 for the ba080/ba970 pair);
     - func_002ba080 local extern (u8 *, s16, s16, FclVec2, FclDrawColor, s32, s32, s32,
       f32, s32) read off the retail call.

   Residual, all float/saved-register colouring:
     - retail keeps iGpffff8504 in $f21 (loaded in both arms of block 0, reused by every
       later func_002b6af0) and 2.0f in $f20; b210 reloads the gp global each time, so y
       lands in $f21 instead of $f22 and 286.0f + x in $f22 instead of $f23 (and no
       $f24 save);
     - b210 CSEs (s16)arg6 into $s5 across blocks; retail renormalises at each use;
     - arg4 is homed (sw 0xFC) instead of living in $s7, a knock-on of the extra $s5. */
// FUN_0031AC10
void func_0031ac10(u8 *arg0, FclVec2 arg1, s8 arg2, s8 arg3, s32 arg4, u16 arg5, s16 arg6, s8 arg7, s8 arg8, u8 arg9) {
    extern FclVec2 func_002b2970(f32, f32);
    extern void func_002b6a70(s16, u8, u8, s32, s32, s16);
    extern void func_002b6c30(s16, FclVec2, f32, s32);
    extern void func_002ba080(u8 *, s16, s16, FclVec2, FclDrawColor, s32, s32, s32, f32, s32);
    extern void func_002ba970(u8 *, s16, FclDrawColor);
    s16 row12;
    u8 *t;
    u8 *h;
    f32 y;
    s32 t16;
    s8 v3;
    s8 v30;
    s16 id;

    t = *(u8 **)(arg0 + 0x38);
    v3 = 1;
    t16 = arg3;
    y = arg1.y + (f32)(t16 * 23);
    if (arg8 == 1) {
        v3 = *(s8 *)(func_002e4870(0) + arg2 * 12 + t16 + 0x14);
    }
    if (*(s8 *)(t + 0x128) != t16 && *(s8 *)(t + 0x129) != t16 && (v30 = v3) > 0) {
        if (v30 != 2) {
            id = (s16)(t16 + 0x270);
            func_002b7750(id, 0x193);
            func_002b6c30(id, func_002b2970(arg1.x, y), 191.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x193);
            if (arg7 == 1) {
                func_002b6a70(id, *(u8 *)(func_002b6150(id) + 0x6E), 0, 0, 0, arg6 + 3);
                func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(arg1.x, y), func_002b2970(arg1.x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg6);
            } else {
                *(FclByte4 *)(func_002b6150(id) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                func_002b6a70(id, 0, arg9, 0, 0, arg6);
                func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(arg1.x, y + func_0046b2f0(h) / 2.0f), func_002b2970(arg1.x, y), 0, 3, arg6);
            }
            func_0046d280(h);
            id = (s16)(t16 + 0x27D);
            func_002b7750(id, 0x19B);
            func_002b6c30(id, func_002b2970(286.0f + arg1.x, y), 192.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x19B);
            if (arg7 == 1) {
                func_002b6a70(id, *(u8 *)(func_002b6150(id) + 0x6E), 0, 0, 0, arg6 + 3);
                func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(286.0f + arg1.x, y), func_002b2970(286.0f + arg1.x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg6);
            } else {
                *(FclByte4 *)(func_002b6150(id) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                func_002b6a70(id, 0, arg9, 0, 0, arg6);
                func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(286.0f + arg1.x, y + func_0046b2f0(h) / 2.0f), func_002b2970(286.0f + arg1.x, y), 0, 3, arg6);
            }
            func_0046d280(h);
            id = (s16)(t16 + 0x28B);
            func_002b6c30(id, func_002b2970(arg1.x, y), 163.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x188);
            if (arg7 == 1) {
                func_002b6a70(id, 0xFF, 0, 0, 0, arg6 + 3);
                func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(arg1.x, y), func_002b2970(arg1.x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg6);
            } else {
                *(FclByte4 *)(func_002b6150(id) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                func_002b6a70(id, 0, 0xFF, 0, 0, arg6);
                func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(arg1.x, y + func_0046b2f0(h) / 2.0f), func_002b2970(arg1.x, y), 0, 3, arg6);
            }
            func_0046d280(h);
            id = (s16)(t16 + 0x297);
            func_002b6c30(id, func_002b2970(36.0f + arg1.x, y), 163.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x18C);
            if (arg7 == 1) {
                func_002b6a70(id, 0xFF, 0, 0, 0, arg6 + 3);
                func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(36.0f + arg1.x, y), func_002b2970(36.0f + arg1.x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg6);
            } else {
                *(FclByte4 *)(func_002b6150(id) + 0x85) = func_002b2a60(0x49, 0x72, 0xFF, 0xFF);
                func_002b6a70(id, 0, 0xFF, 0, 0, arg6);
                func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(36.0f + arg1.x, y + func_0046b2f0(h) / 2.0f), func_002b2970(36.0f + arg1.x, y), 0, 3, arg6);
            }
            func_0046d280(h);
        }
        id = (s16)(t16 + 0x2A3);
        h = func_0046d200(func_00331560(), (u16)((func_00109280((u16)arg4) & 0xFF) + 0x1B));
        if (arg7 == 1) {
            func_002b6a70(id, 0xFF, 0, 0, 0, arg6 + 3);
            func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
            func_002b69f0(id, func_002b2970(8.0f + arg1.x, 2.0f + y), func_002b2970(8.0f + arg1.x, 2.0f + y + func_0046b2f0(h) / 2.0f), 0, 3, arg6);
        } else {
            func_002b6c30(id, func_002b2970(8.0f + arg1.x, 2.0f + y), 46.0f, 0x59);
            *(s16 *)(func_002b6150(id) + 4) = (func_00109280((u16)arg4) & 0xFF) + 0x1B;
            *(FclByte4 *)(func_002b6150(id) + 0x85) = func_002b2a60(0, 0, 0x66, 0xFF);
            func_002b6a70(id, 0, 0xFF, 0, 0, arg6);
            func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
            func_002b69f0(id, func_002b2970(8.0f + arg1.x, 2.0f + y + func_0046b2f0(h) / 2.0f), func_002b2970(8.0f + arg1.x, 2.0f + y), 0, 3, arg6);
        }
        func_0046d280(h);
        y = 2.0f + y;
        row12 = (s8)(t16 + 0xC);
        func_002ba080(*(u8 **)(t + 0x2BC), row12, (s16)arg5, func_002b2970(arg1.x - 16.0f, y),
                      func_002b2a60(0xCC, 0xFF, 0xFF, 0x80), 3, arg6, 0x59, 46.0f, arg7);
        if (v30 == 2) {
            id = (s16)(t16 + 0x270);
            func_002b7750(id, 0x193);
            func_002b6c30(id, func_002b2970(arg1.x, y), 191.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x193);
            if (arg7 == 1) {
                func_002b6a70(id, *(u8 *)(func_002b6150(id) + 0x6E), 0, 0, 0, arg6 + 3);
                func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(arg1.x, y), func_002b2970(arg1.x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg6);
            } else {
                *(FclByte4 *)(func_002b6150(id) + 0x85) = func_002b2a60(0, 0, 0x99, 0xFF);
                func_002b6a70(id, 0, 0, 0, 0, arg6);
                func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b69f0(id, func_002b2970(arg1.x, y + func_0046b2f0(h) / 2.0f), func_002b2970(arg1.x, y), 0, 3, arg6);
            }
            func_0046d280(h);
            id = (s16)(t16 + 0x27D);
            func_002b7750(id, 0x19B);
            func_002b6c30(id, func_002b2970((f32)0x11D + arg1.x, y), 192.0f, 0x57);
            h = func_0046d200(func_00331560(), 0x19B);
            if (arg7 == 1) {
                func_002b6a70(id, *(u8 *)(func_002b6150(id) + 0x6E), 0, 0, 0, arg6 + 3);
                func_002b6af0(id, 1.0f, 1.0f, 1.0f, iGpffff8504, 0, 3, arg6);
                func_002b69f0(id, func_002b2970((f32)0x11D + arg1.x, y), func_002b2970((f32)0x11D + arg1.x, y + func_0046b2f0(h) / 2.0f), 0, 3, arg6);
            } else {
                *(FclByte4 *)(func_002b6150(id) + 0x85) = func_002b2a60(0, 0, 0x99, 0xFF);
                func_002b6a70(id, 0, 0, 0, 0, arg6);
                func_002b6af0(id, 1.0f, 1.0f, iGpffff8504, 1.0f, 0, 3, arg6);
                func_002b69f0(id, func_002b2970((f32)0x11D + arg1.x, y + func_0046b2f0(h) / 2.0f), func_002b2970((f32)0x11D + arg1.x, y), 0, 3, arg6);
            }
            func_0046d280(h);
            func_002b7750(0xCF, 0xCF);
            func_002b77d0(0xCF, func_002b2970(arg1.x - 10.0f, y - 12.0f), 0xCF, func_002b2a60(0xFF, 0xFF, 0xFF, 0x80), 193.0f, 0x56, arg7, 3, 3, arg6, func_00331560());
            func_002b7750(0xD2, 0xD2);
            func_002b77d0(0xD2, func_002b2970(282.0f + arg1.x, y - 12.0f), 0xD2, func_002b2a60(0xFF, 0xFF, 0xFF, 0x80), 193.0f, 0x56, arg7, 3, 3, arg6, func_00331560());
            if (arg7 == 0) {
                *(FclVec2 *)(t + 0x298) = func_002b2970(arg1.x - 60.0f, y - 8.0f);
                func_002b6c30(0x1C7, func_002b2970(arg1.x - 60.0f, y - 8.0f), 190.0f, 0x58);
                *(u8 *)(func_002b6150(0x1C7) + 0x6E) = 0;
                *(s8 *)(t + 0x294) = 0;
                func_002b68d0(0x1C7, 2, 1);
                *(u8 *)(func_002b6150(0x1C7) + 0x73) = 1;
                func_002b7750(0x2E8, 0x1C7);
                func_002b6c30(0x2E8, func_002b2970(arg1.x - 60.0f, y - 8.0f), 190.0f, 0x58);
                *(u8 *)(func_002b6150(0x2E8) + 0x6E) = 0;
                *(s8 *)(t + 0x295) = 0;
                func_002b68d0(0x2E8, 2, 1);
                *(u8 *)(func_002b6150(0x2E8) + 0x73) = 1;
                *(FclByte4 *)(func_002b6150((s16)(t16 + 0x2A3)) + 0x85) = func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF);
                func_002ba970(*(u8 **)(t + 0x2BC), row12, func_002b2a60(0xFF, 0xCC, 0xFA, 0xFF));
                return;
            }
            func_002b68d0(0x1C7, 0, 1);
            func_002b68d0(0x2E8, 0, 1);
        }
    } else {
        func_002b68d0((s16)(t16 + 0x270), 0, 1);
        func_002b68d0((s16)(t16 + 0x27D), 0, 1);
        func_002b68d0((s16)(t16 + 0x28B), 0, 1);
        func_002b68d0((s16)(t16 + 0x297), 0, 1);
        func_002b68d0((s16)(t16 + 0x2A3), 0, 1);
    }
}
