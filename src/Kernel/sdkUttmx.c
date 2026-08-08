/* Original translation unit sdkUttmx.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u8 *func_003e2f60(s32 mode, s32 arg1, u8 *name);
extern s32 func_003e2910(u8 *fh, void *dst, s32 size);
extern void func_003e2e40(u8 *fh, s32 arg1);
extern void func_0044ea90(u8 *file, s32 line);
extern void func_0043f810(u8 *dst, void *src, s32 size);
extern s32 func_00463930(u8 *arg0);
extern u8 *(*jtbl_008873E8[])(s32 size, s32 align);
extern void (*jtbl_008873EC[])(u8 *ptr);
extern u8 D_00712688[];
extern void func_003ec2a0(s32 arg0);
extern void func_003ec2e0(s32 arg0);
extern u32 func_003ec3d0(s32 arg0, s32 arg1);
extern s32 func_003ec590(u16 arg0, u16 arg1, s32 arg2, s32 arg3);
extern u32 func_003ec6a0(s32 arg0, s32 arg1, s32 arg2);
extern void func_0046d730(u8 *file, s32 line);
extern void func_00463ea0(u32 arg0, u32 arg1, u32 arg2);

// FUN_00463D60
s32 func_00463d60(u8 *name)
{
    u8 hdr[0x40];
    u8 *fh;
    s32 ret;
    u8 *buf;

    ret = 0;
    fh = func_003e2f60(2, 1, name);
    if (fh != NULL) {
        func_003e2910(fh, hdr, 0x40);
        func_0044ea90(D_00712688, 0x3BE);
        buf = jtbl_008873E8[0](*(s32 *)(hdr + 4), 0x40000);
        func_003e2910(fh, buf + 0x40, *(s32 *)(hdr + 4) - 0x40);
        func_0043f810(buf, hdr, 0x40);
        ret = func_00463930(buf);
        jtbl_008873EC[0](buf);
        func_003e2e40(fh, 0);
    }
    return ret;
}
// FUN_00463EA0
INCLUDE_ASM("asm/nonmatchings/sdkUttmx", func_00463ea0);

/* measured: plain-C reconstruction is 1240B against the 1248B retail window at
   verify normalized_diff 10. The header checks, format switch, allocation and
   upload/copy paths match; only the func_003ec590 argument setup differs:
   fndiff 0x218/0x21C/0x220 (candidate ori,lhu,lhu; retail lhu,lhu,ori).
   Tried direct flag expression, named flag temporary, dimension temporaries,
   separate pointer-pinned dimensions, comma sequencing, and both switch-case
   declaration orders; all either retained these rows or worsened coloring.
   Committed at nd 10. */
// FUN_00464100 NONMATCHING
#ifdef NON_MATCHING
s32 func_00464100(u8 *arg0, s32 arg1)
{
    u8 *temp_22;
    s32 temp_23;
    u32 temp_2_2;
    s32 var_18;
    s32 var_17;
    s32 var_16;
    u32 temp_2_3;
    u8 temp_3;
    u8 temp_3_2;
    u8 temp_4;
    u16 width;
    u16 height;

    var_18 = 0;
    var_17 = 0;
    if (arg0 == NULL) {
        func_0046d730(D_00712688, 0x453);
    }
    if (*(u8 *)(arg0 + 0) != 2) {
        func_0046d730(D_00712688, 0x457);
    }
    if (*(u8 *)(arg0 + 1) != 0) {
        func_0046d730(D_00712688, 0x458);
    }
    if ((*(u8 *)(arg0 + 8) != 0x54 ||
         *(u8 *)(arg0 + 9) != 0x4D ||
         *(u8 *)(arg0 + 0xA) != 0x58) &&
        *(u8 *)(arg0 + 0xB) != 0x30) {
        func_0046d730(D_00712688, 0x459);
    }
    temp_3 = *(u8 *)(arg0 + 0x16);
    switch (temp_3) {
    case 0:
        var_16 = 0x20;
        break;
    case 1:
        var_16 = 0x18;
        break;
    case 10:
    case 2:
        var_16 = 0x10;
        break;
    case 27:
    case 19:
        var_16 = 8;
        var_17 = 0x2000;
        break;
    case 36:
    case 44:
    case 20:
        var_16 = 4;
        var_17 = 0x4000;
        break;
    default:
        var_16 = 0;
        break;
    }
    temp_4 = *(u8 *)(arg0 + 0x10);
    if (temp_4 != 0) {
        temp_3_2 = *(u8 *)(arg0 + 0x11);
        switch (temp_3_2) {
        case 0:
            var_18 = 0x20;
            break;
        case 2:
        case 10:
            var_18 = 0x10;
            break;
        default:
            var_18 = 0;
            break;
        }
    }
    temp_22 = arg0 + 0x40;
    temp_23 = 1 << var_16;
    var_18 = (s32)(temp_22 + ((var_18 * (temp_4 * temp_23)) >> 3));
    width = *(u16 *)(arg0 + 0x12);
    height = *(u16 *)(arg0 + 0x14);
    temp_2_3 = var_17 | 0x504;
    var_17 = func_003ec590(width, height, var_16, temp_2_3);
    if (var_17 == 0) {
        func_0046d730(D_00712688, 0x48D);
    }
    temp_2_2 = func_003ec6a0(var_17, 0, 1);
    if (temp_2_2 == 0) {
        func_0046d730(D_00712688, 0x48F);
    }
    switch (var_16) {
    case 32:
    case 24:
        if (arg1 != 0) {
            func_00463ea0(temp_2_2, (u32)var_18,
                          *(u16 *)(arg0 + 0x12) * *(u16 *)(arg0 + 0x14) * 4);
        } else {
            func_0043f810((u8 *)temp_2_2, (void *)var_18,
                          *(u16 *)(arg0 + 0x12) * *(u16 *)(arg0 + 0x14) * 4);
        }
        break;
    case 16:
        if (arg1 != 0) {
            func_00463ea0(temp_2_2, (u32)var_18,
                          *(u16 *)(arg0 + 0x12) * *(u16 *)(arg0 + 0x14) * 2);
        } else {
            func_0043f810((u8 *)temp_2_2, (void *)var_18,
                          *(u16 *)(arg0 + 0x12) * *(u16 *)(arg0 + 0x14) * 2);
        }
        break;
    case 8:
        if (arg1 != 0) {
            func_00463ea0(temp_2_2, (u32)var_18,
                          *(u16 *)(arg0 + 0x12) * *(u16 *)(arg0 + 0x14));
        } else {
            func_0043f810((u8 *)temp_2_2, (void *)var_18,
                          *(u16 *)(arg0 + 0x12) * *(u16 *)(arg0 + 0x14));
        }
        break;
    case 4:
        if (arg1 != 0) {
            func_00463ea0(temp_2_2, (u32)var_18,
                          (*(u16 *)(arg0 + 0x12) >> 1) * *(u16 *)(arg0 + 0x14));
        } else {
            func_0043f810((u8 *)temp_2_2, (void *)var_18,
                          (*(u16 *)(arg0 + 0x12) >> 1) * *(u16 *)(arg0 + 0x14));
        }
        break;
    }
    func_003ec2a0(var_17);
    if (*(u8 *)(arg0 + 0x10) != 0) {
        temp_2_3 = func_003ec3d0(var_17, 1);
        if (temp_2_3 == 0) {
            func_0046d730(D_00712688, 0x4C2);
        }
        if (arg1 != 0) {
            func_00463ea0(temp_2_3, (u32)temp_22, temp_23 * 4);
        } else {
            func_0043f810((u8 *)temp_2_3, temp_22, temp_23 * 4);
        }
        func_003ec2e0(var_17);
    }
    return var_17;
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkUttmx", func_00464100);
#endif

