#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit calendar.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "shd_misc_internal.h"
extern s32 func_00452380();
extern u8 D_005E4FE8[];
extern u8 D_005E4FD8[];

extern s32 D_007242B4;
extern s32 D_007242B0;
extern s32 D_007242B8;
extern u8 D_005E4FF8[];
extern u8 D_005E5038[];
extern u8 D_005E5050[];
extern void (*jtbl_008873EC[])(void *);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void func_0044ea90(u8 *file, s32 line);
extern s32 func_00451de0(const void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern s32 func_00451fc0(s32 a, const void *b, s32 c, s32 d, s32 e, void *init, void *close, void *buf);
extern void func_00120f70();
extern void func_00121170();
extern void func_001211a0();
extern s32 func_00121690(void);
extern s32 func_001104a0(s32 arg0);
extern void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2);
extern u8 func_001060c0(void);
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern void func_00122520(s32 a, s32 b);
extern void func_00106100(s32 a);
extern void func_001029a0(s32 a, void *b, s32 c, s32 d);
extern void func_00123850(void);
extern s32 func_00144af0(s32 a);
extern s32 func_004522d0(s32 a);
extern void func_001062f0(s32 a);
extern s32 func_00110580(s32 arg0);
extern s32 func_001105b0(s32 arg0);
extern s32 func_00110600(s32 arg0, s32 arg1);
extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 farg0);
extern s32 iGpffff9c54;
extern const char *D_005E5010[];
extern u8 D_005E5028[];



// FUN_001211B0
void func_001211b0(void)
{
    u8 *work;
    s32 handle;

    D_007242B8 = 0;
    func_0044ea90(D_005E4FD8, 0x79);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work != NULL) {
        handle = func_00451de0(D_005E4FE8, 0x100, 0, 0, func_00120f70, func_00121170, work);
        D_007242B0 = (s32)work;
        func_00451fc0(handle, D_005E4FF8, 0x101, 0, 0, func_001211a0, NULL, NULL);
    }
}

// FUN_00121280
s32 func_00121280(void)
{
    return (s32)(func_00452380(D_005E4FE8) != 0);
}

// FUN_001212B0
void func_001212b0(void)
{
    s32 handle = func_00452380(D_005E4FE8);

    if (handle == 0) {
        func_0046d730(D_005E4FD8, 0xA8);
    }
    func_00452080(handle);
}

// FUN_00121310
s32 func_00121310(void *arg0)
{
    s32 sp3C;
    s32 sp38;
    u8 *work;
    s32 state;
    s32 v;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    state = *(s32 *)work;
    switch (state) {
    case 0:
        *(s32 *)(work + 8) = 0;
        *(s32 *)(work + 4) = 1;
        *(s32 *)(work + 0) = 1;
        break;
    case 1:
        if (D_008C0276[0] & 0x40) {
            func_00122520(1, 1);
            func_00106100((s16)*(s32 *)(work + 8));
            func_001029a0(0x1A, NULL, 0, 0);
            return -1;
        }
        if (D_008C0276[0] & 0x800) {
            func_00106100((s16)*(s32 *)(work + 8));
            func_00123850();
            *(s32 *)(work + 0xC) = func_00144af0((s32)arg0);
            *(s32 *)(work + 0) = 4;
        } else if (D_008C027A[0] & 0x1000) {
            v = *(s32 *)(work + 8);
            if (v < 7) {
                *(s32 *)(work + 8) = 0;
            } else {
                *(s32 *)(work + 8) = v - 7;
            }
        } else if (D_008C027A[0] & 0x4000) {
            v = *(s32 *)(work + 8);
            if (v > 0x165) {
                *(s32 *)(work + 8) = 0x16C;
            } else {
                *(s32 *)(work + 8) = v + 7;
            }
        } else if (D_008C027A[0] & 0x8000) {
            v = *(s32 *)(work + 8);
            if (v != 0) {
                *(s32 *)(work + 8) = v - 1;
            }
        } else if (D_008C027A[0] & 0x2000) {
            v = *(s32 *)(work + 8);
            if (v != 0x16C) {
                *(s32 *)(work + 8) = v + 1;
            }
        } else if (D_008C027A[0] & 0x4) {
            if ((func_001060c0() & 0xFF) == 0) {
                func_001062f0(5);
            } else {
                func_001062f0(((func_001060c0() & 0xFF) - 1) & 0xFF);
            }
        } else if (D_008C027A[0] & 0x8) {
            if ((func_001060c0() & 0xFF) == 5) {
                func_001062f0(0);
            } else {
                func_001062f0(((func_001060c0() & 0xFF) + 1) & 0xFF);
            }
        } else if (D_008C027A[0] & 0x1) {
            func_001104d0(*(s32 *)(work + 8), &sp3C, &sp38);
            if (sp3C != 4) {
                *(s32 *)(work + 8) = *(s32 *)(work + 8) - (func_001104a0(sp3C) - 1);
            }
        } else if (D_008C027A[0] & 0x2) {
            func_001104d0(*(s32 *)(work + 8), &sp3C, &sp38);
            if (sp3C != 3) {
                *(s32 *)(work + 8) = *(s32 *)(work + 8) + func_001104a0(sp3C);
            }
        }
        break;
    case 4:
        if (func_004522d0(*(s32 *)(work + 0xC)) == 3) {
            *(s32 *)(work + 0) = 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00121660
void func_00121660(void *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B4 = 0;
    jtbl_008873EC[0](p);
}

/* Measured: 688 bytes and 17 resolved relocations. Packed positions retain
 * both coordinate components; the formatter consumes a genuine vararg list.
 * Keep the loop bound live and reuse the selected row offset across queries. */
// FUN_00121690
s32 func_00121690(void)
{
    s32 month, day;
    u8 color[4];
    PackedVec2f pos;
    s32 dim[4];
    s32 current, index;
    s32 offset;
    s32 weekday;
    u8 *work;

    work = (u8 *)D_007242B4;
    if (work == NULL) return 0;
    if (*(s32 *)(work + 4) == 0) return 0;
    color[0] = 0x40; color[1] = 0x40; color[2] = 0x40; color[3] = 0xff;
    dim[0] = 100; dim[1] = 100; dim[2] = 250; dim[3] = 100;
    func_0045d6e0(color, dim, 1, 0.0f);
    func_001104d0(*(s32 *)(work + 8), &month, &day);
    weekday = func_00110580(func_00110600(month, 1));
    current = func_00110580(*(s32 *)(work + 8));
    if (current >= weekday) offset = 0; else offset = 12;
    offset = offset + (func_001105b0(*(s32 *)(work + 8)) - 1) * 12;
    color[0] = 0x40; color[1] = 0x80; color[2] = 0x80; color[3] = 0xff;
    dim[0] = current * 36 + 100; dim[1] = offset + 124; dim[2] = 36; dim[3] = 12;
    func_0045d6e0(color, dim, 1, 0.0f);
    pos.xy.x = 100.0f; pos.xy.y = 100.0f;
    func_00450dd0(pos, 0.0f, D_005E5028, month, D_005E5010[func_001060c0()]);
    pos.xy.x = 0.0f + 100.0f + 36.0f * (f32)weekday;
    pos.xy.y = 124.0f;
    index = 0;
    while (index < func_001104a0(month)) {
        func_00450dd0(pos, 0.0f, &iGpffff9c54, index + 1);
        weekday++;
        if (weekday > 6) {
            weekday = 0;
            pos.xy.x -= 252.0f; pos.xy.y += 12.0f;
        }
        pos.xy.x += 36.0f;
        index++;
    }
    return 0;
}

// FUN_00121940
s32 func_00121940(void)
{
    s32 handle;
    u8 *work;

    func_0044ea90(D_005E4FD8, 0x164);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work == NULL) {
        return 0;
    }
    handle = func_00451de0(D_005E5038, 0x100, 0, 0, func_00121310, func_00121660, work);
    D_007242B4 = (s32)work;
    func_00451fc0(handle, D_005E5050, 0x101, 0, 0, func_00121690, NULL, NULL);
    return handle;
}

// FUN_00121A20
void func_00121a20(void)
{
    u8 *work;
    s32 handle;

    D_007242B8 = 1;
    func_0044ea90(D_005E4FD8, 0x79);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work != NULL) {
        handle = func_00451de0(D_005E4FE8, 0x100, 0, 0, func_00120f70, func_00121170, work);
        D_007242B0 = (s32)work;
        func_00451fc0(handle, D_005E4FF8, 0x101, 0, 0, func_001211a0, NULL, NULL);
    }
}