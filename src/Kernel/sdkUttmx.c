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

// FUN_00464100
INCLUDE_ASM("asm/nonmatchings/sdkUttmx", func_00464100);

