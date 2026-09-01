/* archive: candidate object 824 bytes; retail window 1056 bytes; normalized_diff 575; first differing offsets 0x04, 0x11, 0x16, 0x24-0x2C, 0x30-0x34, 0x38-0x3C, 0x40, 0x48-0x4C, 0x54-0x58; conversion casts: `var_f0 = (f32)(u32)temp_2` (int->float) and `var_3 = (u32)(var_f0 * var_f2)` (float->unsigned); ruled out: corrected four-argument callee declaration, plain-C branch reconstruction, declaration/lifetime variants, and permitted COP2 packet skeleton; residual remains a large packet/control-flow mismatch.
s32 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 spC;
    s32 sp8;
    s32 sp4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f2;
    s32 temp_2;
    s32 var_3;
    s32 var_4;
    s32 var_9;
    u8 temp_3;
    f32 inv;

    if (arg3 == 0) {
        return ((u64)((s64)*(s32 *)(arg0 + 4) << 40) >> 40) |
               (*(s32 *)(arg1 + 0) << 24);
    }
    temp_f0 = (f32)arg3;
    temp_3 = *(u8 *)(arg0 + 0);
    switch (temp_3) {
    case 0:
        var_9 = *(s32 *)(arg0 + 4);
        var_4 = *(s32 *)(arg0 + 8);
        break;
    case 1:
        if (arg2 < (s32)(*(f32 *)(arg0 + 0x10) * temp_f0)) {
            var_9 = *(s32 *)(arg0 + 4);
            var_4 = *(s32 *)(arg0 + 0xC);
        } else {
            var_9 = *(s32 *)(arg0 + 0xC);
            var_4 = *(s32 *)(arg0 + 8);
        }
        break;
    case 2:
        if (arg2 < (s32)(*(f32 *)(arg0 + 0x10) * temp_f0)) {
            var_9 = *(s32 *)(arg0 + 4);
            var_4 = *(s32 *)(arg0 + 0xC);
        } else if (arg2 < (s32)(*(f32 *)(arg0 + 0x18) * temp_f0)) {
            var_9 = *(s32 *)(arg0 + 0xC);
            var_4 = *(s32 *)(arg0 + 0x14);
        } else {
            var_9 = *(s32 *)(arg0 + 0x14);
            var_4 = *(s32 *)(arg0 + 8);
        }
        break;
    default:
        var_9 = *(s32 *)(arg0 + 4);
        var_4 = *(s32 *)(arg0 + 8);
        break;
    }
    spC = var_4;
    sp8 = var_9;
    temp_f1 = *(f32 *)(arg1 + 8) * temp_f0;
    temp_f0_2 = *(f32 *)(arg1 + 0xC) * temp_f0;
    if (arg2 < (s32)temp_f1) {
        var_f2 = (f32)arg2 / (f32)temp_f1;
    } else if ((s32)temp_f0_2 < arg2) {
        var_f2 = (f32)(arg3 - arg2) / (f32)(arg3 - (s32)temp_f0_2);
    }
    inv = 1.0f - var_f2;
    __asm__ volatile(
        ".set noreorder\n"
        "sw %0, 12($sp)\n"
        "addiu $2, $sp, 12\n"
        "lw $2, 0($2)\n"
        "pextlb $2, $0, $2\n"
        "pextlh $2, $0, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vmove.xyzw $vf11, $vf10\n"
        "sw %1, 8($sp)\n"
        "addiu $2, $sp, 8\n"
        "lw $2, 0($2)\n"
        "pextlb $2, $0, $2\n"
        "pextlh $2, $0, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "mfc1 $2, %3\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "mfc1 $2, %4\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf11, $vf11, $vf2x\n"
        "vadd.xyzw $vf10, $vf10, $vf11\n"
        "lui $2, 0x437f\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vftoi0.xyzw $vf10, $vf10\n"
        "qmfc2.ni $2, $vf10\n"
        "ppach $2, $0, $2\n"
        "ppacb $2, $0, $2\n"
        "sw $2, 4($sp)\n"
        ".set reorder\n"
        :
        : "r"(spC), "r"(sp8), "f"(fGpffff8044), "f"(inv), "f"(var_f2)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    sp4 = *(s32 *)(void *)((u8 *)&sp4);
    temp_2 = *(s32 *)(arg1 + 0);
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = (f32)(u32)temp_2;
    }
    temp_f1_2 = var_f0 * var_f2;
    var_3 = (s32)(u32)temp_f1_2;
    return ((u64)((s64)sp4 << 40) >> 40) | (var_3 << 24);
}
