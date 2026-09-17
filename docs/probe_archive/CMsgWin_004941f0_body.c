/* func_004941f0 DRAFT 263w/203ed 253/291 13% short cseoff words-best. See code1_0049.c draft note; production plain. */
/* measured: probing opt_common_subs off for color reloads. */
#pragma opt_common_subs off
void func_004941f0(u8 *arg0, u8 *arg1)
{
    extern void func_003c2290(void *arg0, s32 arg1);
    extern void func_003c22f0(void *arg0);
    extern void func_0043f810(void *dst, const void *src, u32 size);
    extern f32 fGpffff8044;
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    u8 *work;
    u8 *dst;
    u8 *dstBase;
    s16 count2;
    s16 wdiv;
    u32 n;
    f32 step;
    f32 t;
    u32 i;
    u32 j;
    s32 stride;
    u8 *model;
    u8 *work2;
    u8 *dst2;
    u8 *dst2Base;
    u8 *model2;
    s32 spEC;
    s32 spE8;
    s32 spE4;
    s32 spE0;
    u_long128 spC0;
    u_long128 spA0;
    u_long128 spB0;
    u_long128 sp90;
    f32 scale;

    work = *(u8 **)(arg0 + 0x10);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 8);
    count2 = *(s16 *)(work + 0x48);
    wdiv = *(s16 *)(work + 8);
    n = (u32)(u16)wdiv / 3;
    dst = *(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x30);
    dstBase = dst;
    step = 1.0f / (f32)n;
    t = 0.0f;
    scale = fGpffff8044;
    spEC = *(s32 *)(arg1 + 0);
    __asm__ volatile(
        "lw $2, 0(%0)          \n"
        "pextlb $2, $0, $2     \n"
        "pextlh $2, $0, $2     \n"
        "qmtc2.ni $2, $vf10    \n"
        "vitof0.xyzw $vf10, $vf10 \n"
        "mfc1 $2, %2           \n"
        "nop                   \n"
        "qmtc2.ni $2, $vf2     \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "sqc2 $vf10, 0(%1)     \n"
        :
        : "r"(&spEC), "r"(&spC0), "f"(scale)
        : "$2", "$vf2", "$vf10", "memory");
    spE8 = *(s32 *)(arg1 + 4);
    __asm__ volatile(
        "lw $2, 0(%0)          \n"
        "pextlb $2, $0, $2     \n"
        "pextlh $2, $0, $2     \n"
        "qmtc2.ni $2, $vf10    \n"
        "vitof0.xyzw $vf10, $vf10 \n"
        "mfc1 $2, %2           \n"
        "nop                   \n"
        "qmtc2.ni $2, $vf2     \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "sqc2 $vf10, 0(%1)     \n"
        :
        : "r"(&spE8), "r"(&spA0), "f"(scale)
        : "$2", "$vf2", "$vf10", "memory");
    spE4 = *(s32 *)(arg1 + 8);
    __asm__ volatile(
        "lw $2, 0(%0)          \n"
        "pextlb $2, $0, $2     \n"
        "pextlh $2, $0, $2     \n"
        "qmtc2.ni $2, $vf10    \n"
        "vitof0.xyzw $vf10, $vf10 \n"
        "mfc1 $2, %2           \n"
        "nop                   \n"
        "qmtc2.ni $2, $vf2     \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "sqc2 $vf10, 0(%1)     \n"
        :
        : "r"(&spE4), "r"(&spB0), "f"(scale)
        : "$2", "$vf2", "$vf10", "memory");
    spE0 = *(s32 *)(arg1 + 12);
    __asm__ volatile(
        "lw $2, 0(%0)          \n"
        "pextlb $2, $0, $2     \n"
        "pextlh $2, $0, $2     \n"
        "qmtc2.ni $2, $vf10    \n"
        "vitof0.xyzw $vf10, $vf10 \n"
        "mfc1 $2, %2           \n"
        "nop                   \n"
        "qmtc2.ni $2, $vf2     \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "sqc2 $vf10, 0(%1)     \n"
        :
        : "r"(&spE0), "r"(&sp90), "f"(scale)
        : "$2", "$vf2", "$vf10", "memory");
    i = 0;
    if (n != 0) {
        goto loop_check;
loop_body:
        dst[4] = arg1[0];
        dst[5] = arg1[1];
        dst[6] = arg1[2];
        dst[7] = arg1[3];
        dst[0] = arg1[4];
        dst[1] = arg1[5];
        dst[2] = arg1[6];
        dst[3] = arg1[7];
        dst[8] = dst[0];
        dst[9] = dst[1];
        dst[10] = dst[2];
        dst[11] = dst[3];
        t += step;
        dst += 12;
        i += 1;
loop_check:
        if (i < n) {
            goto loop_body;
        }
    }
    j = 1;
    stride = (s32)wdiv * 4;
    goto rep_check;
rep_body:
    func_0043f810(dst, dstBase, stride);
    dst += stride;
    j += 1;
rep_check:
    if (j < (u32)count2) {
        goto rep_body;
    }
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if ((*(u16 *)work & 4) != 0) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    work2 = *(u8 **)(arg0 + 0x14);
    func_003c2290(*(u8 **)(*(u8 **)(work2 + 0x10) + 0x18), 8);
    dst2 = *(u8 **)(*(u8 **)(*(u8 **)(work2 + 0x10) + 0x18) + 0x30);
    dst2Base = dst2;
    *(s32 *)(dst2 + 0) = *(s32 *)(arg1 + 0);
    *(s32 *)(dst2 + 4) = *(s32 *)(arg1 + 4);
    dst2[8] = dst2[4];
    dst2[9] = dst2[5];
    dst2[10] = dst2[6];
    dst2[11] = dst2[7];
    dst2[12] = dst2[4];
    dst2[13] = dst2[5];
    dst2[14] = dst2[6];
    dst2[15] = dst2[7];
    dst2[16] = dst2[4];
    dst2[17] = dst2[5];
    dst2[18] = dst2[6];
    dst2[19] = dst2[7];
    dst2[20] = dst2[4];
    dst2[21] = dst2[5];
    dst2[22] = dst2[6];
    dst2[23] = dst2[7];
    dst2[24] = dst2[4];
    dst2[25] = dst2[5];
    dst2[26] = dst2[6];
    dst2[27] = dst2[7];
    dst2[28] = dst2[4];
    dst2[29] = dst2[5];
    dst2[30] = dst2[6];
    dst2[31] = dst2[7];
    {
        u8 *cur = dst2 + 0x20;
        u32 k = 1;
        goto rep2_check;
rep2_body:
        func_0043f810(cur, dst2Base, 0x20);
        cur += 0x20;
        k += 1;
rep2_check:
        if (k < (u32)count2) {
            goto rep2_body;
        }
        model2 = *(u8 **)(*(u8 **)(work2 + 0x10) + 0x18);
        func_003c22f0(model2);
        if ((*(u16 *)work2 & 4) != 0) {
            *(u16 *)(model2 + 0xC) = *(u16 *)(model2 + 0xC) | 1;
        }
    }
}

/* measured: closes opt_common_subs. */
#pragma opt_common_subs on
