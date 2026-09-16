// func_00263730 (0x00263730-0x00263cb0, 1408B) — guarded floor @~289fndiff/1372B (36B under; frame/saves agree).
// Wins: negated c.le.s/bc1t conv idiom exact; sd-zero stack-arg shape; lbu alpha; chained 110c50(s7v,..)
// threading (m2c wrong); full-word fontWord (m2c (s16) wrong); x94 shift-chain; all 19 calls; GPREL relocs.
// Walls: full s-map rotation (args s3-s7 vs s1-s5; s7v spills; decl-order/t22-inline/ptr-type/merge all
// inert — global-coloring wall); dead lq+mult x2 (kept-dead-mult family; voided-product summon DSEd);
// stack-slot layout; OR-dest; GPREL-vs-ABSOLUTE phantoms.
// Unattempted before (no prior note). Production stays ASM.
void func_00263730(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 *arg5, f32 fparg0)
{
    typedef signed __int128 s128;
    s128 spC0;
    u8 sp110;
    u8 sp100;
    s32 spF0;
    s32 spE0;
    s32 spD0;
    s32 sp12C;
    s32 i;
    s32 t22;
    s32 s7v;
    s32 v22;
    s32 s8v;
    f32 f1;
    s32 cv;

    sp12C = arg4;
    spC0 = arg2 & 0xFF;
    for (i = 0; i < 8; i++) {
        t22 = arg3 - 1 + i;
        if (t22 < 0) {
            continue;
        }
        if (sp12C != 0) {
            s7v = func_00110c50(t22, arg3) & 0xFFFF;
            if (s7v != (func_00110c50(t22, arg3 + 1) & 0xFFFF)) {
                f1 = (f32)func_0043c6a0(arg0) / 94.0f;
                f1 = 255.0f - f1;
                if (!(2147483648.0f <= f1)) {
                    cv = (s32)f1 & 0xFF;
                } else {
                    cv = ((s32)(f1 - 2147483648.0f)) | 0x80000000;
                    cv &= 0xFF;
                }
                sp110 = cv & 0xFF;
                s8v = arg0 + i * 0x5E;
                v22 = s8v + 15;
                func_00262de0(v22, arg1 + 245, fparg0, sp110, s7v, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)((u8 *)arg5 + 4), 0);
                spF0 = *(s32 *)((u8 *)arg5 + 4);
                func_00261560(s8v, arg1 + 295, fparg0, sp110, func_00110c50(s7v, arg3) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, spF0, 0);
                f1 = (f32)func_0043c6a0(arg0) / 94.0f;
                if (!(2147483648.0f <= f1)) {
                    cv = (s32)f1 & 0xFF;
                } else {
                    cv = ((s32)(f1 - 2147483648.0f)) | 0x80000000;
                    cv &= 0xFF;
                }
                sp100 = cv & 0xFF;
                func_00262de0(v22, arg1 + 245, fparg0, sp100, s7v, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)((u8 *)arg5 + 4), 0);
                spE0 = *(s32 *)((u8 *)arg5 + 4);
                func_00261560(s8v, arg1 + 295, fparg0, sp100, func_00110c50(s7v, arg3 + 1) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, spE0, 0);
            }
        } else {
            t22 = arg3 - 1 + i;
            s7v = arg3 - 1 + i;
            s8v = arg0 + i * 0x5E;
            v22 = s8v + 15;
            func_00262de0(v22, arg1 + 245, fparg0, arg2, s7v, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)((u8 *)arg5 + 4), 0);
            spD0 = *(s32 *)((u8 *)arg5 + 4);
            func_00261560(s8v, arg1 + 295, fparg0, arg2, func_00110c50(s7v, arg3) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, spD0, 0);
        }
        if (i == 1) {
            t22 = arg3 - 1 + i;
            s7v = arg3 - 1 + i;
            s8v = arg0 + i * 0x5E;
            v22 = s8v + 15;
            func_00262de0(v22, arg1 + 245, fparg0, arg2, s7v, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)((u8 *)arg5 + 4), 0);
            v22 = *(s32 *)((u8 *)arg5 + 4);
            func_00261560(s8v, arg1 + 295, fparg0, arg2, func_00110c50(s7v, arg3) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, v22, 0);
        } else if (i == 2) {
            t22 = arg3 - 1 + i;
            s7v = arg3 - 1 + i;
            s8v = arg0 + i * 0x5E;
            v22 = s8v + 15;
            func_00262de0(v22, arg1 + 245, fparg0, arg2, s7v, 1, 1.0f, 1.0f, 0xB2, 0x5E, *(s32 *)((u8 *)arg5 + 4), 0);
            v22 = *(s32 *)((u8 *)arg5 + 4);
            func_00261560(s8v, arg1 + 295, fparg0, arg2, func_00110c50(s7v, arg3) & 0xFFFF, 1, 1.0f, 1.0f, 0xB2, 0x5E, v22, 0);
        }
    }
}
