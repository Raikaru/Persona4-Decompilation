#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit mc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern u8 *func_00452560(void);
extern void func_00454bd0(u8 *ptr);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern void func_0045d6e0(void *, void *, f32, s32);
extern void func_0025f230(u32 param_1);
extern void func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, s32, s32);
extern void func_002a6650(void *, void *);
extern void func_002a6680(s32);
extern void func_002aa2b0(void *arg0);
extern void func_0044ea90(const void *file, u32 line);
extern void func_0046d730(const void *file, u32 line);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4,
                        s32 (*arg5)(s32), s32 (*arg6)(s32), u8 *arg7);
extern void func_003f6440(s32, s32);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_0025ef20(const void *);
extern s32 func_0025f110(s32);
extern s32 func_004553c0(s32);
extern s32 func_00454a60(const char *path, s32 flags);
extern void func_00440b68(const void *, const void *, u32);
extern char D_0063EB20[];
extern char D_0063ED38[];
extern char D_00763900;
extern void func_00149680(s32);
extern s32 func_002a4570(void *);
extern s32 func_002a4d10(s32);
extern s32 func_002a5630(s32);
extern void func_002a5f00(s32);
extern void func_00453670(void *, s32, s32, s32, s32);
extern void func_004538e0(void *, s32, s32, s32, s32);
extern void func_00453ff0(void *, s32);
extern void func_004537e0(void *, s32);
extern s32 func_00453960(void *);
extern void func_00453760(void *, s32);
extern s32 func_00453dc0(void *);
extern s32 func_00453d70(void *);
extern void func_0045af60(s32, s32, s32, s32);
extern void *memset(void *dst, s32 value, u32 size);
extern char D_00796370[];
extern void (*D_008873EC[])(void *);
extern u8 *(*D_008873F4[])(s32, s32, s32);
typedef int (*RwRenderStateSetFunc)(s32, s32);
extern f32 D_00763910;
extern s32 D_00764634;
extern s32 D_00764638;
extern char D_007638F8;
extern char D_00763918;
typedef struct { u64 lo, hi; } Qword;
extern Qword D_0063ED70;
typedef struct { s32 a, b, c, d; } Quad4;
extern RwRenderStateSetFunc D_00887300[4];

// FUN_002A2E50
INCLUDE_ASM("asm/nonmatchings/mc", func_002a2e50);

// FUN_002A3070
INCLUDE_ASM("asm/nonmatchings/mc", func_002a3070);

// FUN_002A32C0
INCLUDE_ASM("asm/nonmatchings/mc", func_002a32c0);

// FUN_002A34E0
INCLUDE_ASM("asm/nonmatchings/mc", func_002a34e0);

// FUN_002A3D80
INCLUDE_ASM("asm/nonmatchings/mc", func_002a3d80);

// FUN_002A4390
s32 func_002a4390(s32 arg0) {
    typedef struct {
        u8 pad[4];
        u32 flags; /* 0x04 */
        u8 pad2[0x3A4];
        s32 f3AC; /* 0x3AC */
        s32 f3B0; /* 0x3B0 */
        u8 pad3[4];
        s32 f3B8; /* 0x3B8 */
    } McWork;
    u8 buf[0x30];
    McWork *w = (McWork *)arg0;
    s32 v;

    func_00453670(buf, 0x10, 0x10, w->f3AC, w->f3B0);
    func_004538e0(buf, 0x4000, 0x1000, 0, 0);
    func_00453ff0(buf, 0);
    func_004537e0(buf, 0);
    v = func_00453960(buf);
    switch (v) {
    case 1:
    case 3:
        w->flags |= 0x2000;
        w->f3B8 = 0xA;
        func_0045af60(0, 0, 0, 0);
        break;
    case 2:
    case 4:
        w->flags |= 0x1000;
        w->f3B8 = 0xA;
        func_0045af60(0, 0, 0, 0);
        break;
    default:
        func_00453760(buf, 0);
        break;
    }
    w->f3AC = func_00453dc0(buf);
    w->f3B0 = func_00453d70(buf);
    if (w->f3AC == 0) {
        w->flags &= ~0x4000;
    } else {
        w->flags |= 0x4000;
    }
    if (w->f3AC == 0xF) {
        w->flags &= ~0x8000;
    } else {
        w->flags |= 0x8000;
    }
    w->flags |= 0x80000;
    return 0;
}

// FUN_002A4570
INCLUDE_ASM("asm/nonmatchings/mc", func_002a4570);

// FUN_002A4B10
s32 func_002a4b10(s32 arg0) {
    u8 *w = func_00452560();

    switch (*(s16 *)(w + 0)) {
    case 0:
        *(s16 *)(w + 0) = 3;
        /* fallthrough */
    case 3:
        *(s16 *)(w + 0) = 4;
        *(u32 *)(w + 0x398) = func_0025ef20(D_0063EB20);
        func_00440b68(&D_00763900, &D_007638F8, 0x47E);
        *(u32 *)(w + 0x3A4) = func_00454a60(D_0063ED38, 1);
        *(u32 *)(w + 0x568) = 0;
        *(u32 *)(w + 4) |= 0x400;
        /* fallthrough */
    case 4:
        if (func_0025f110(*(u32 *)(w + 0x398)) == 0) {
            break;
        }
        if (func_004553c0(*(u32 *)(w + 0x3A4)) == 0) {
            break;
        }
        *(s16 *)(w + 0) = 5;
        *(u32 *)(w + 4) |= 1;
        break;
    case 5:
        if (*(u32 *)(w + 4) & 0x400) {
            break;
        }
        func_00149680(1);
        *(s16 *)(w + 0) = 6;
        /* fallthrough */
    case 6:
        if (func_002a4570(w) == 0) {
            break;
        }
        func_00149680(0);
        *(s16 *)(w + 0) = 7;
        break;
    case 7:
        if (*(u32 *)(w + 4) & 0x40000) {
            break;
        }
        *(s16 *)(w + 0) = 8;
        /* fallthrough */
    case 8:
        return -1;
    }
    func_002a6680(arg0);
    return 0;
}

// FUN_002A4CB0
void func_002a4cb0(void) {
    u8 *work = func_00452560();
    s32 p = *(s32 *)(work + 0x3A4);
    if (p != 0) {
        func_00454bd0((u8 *)p);
        *(s32 *)(work + 0x3A4) = 0;
    }
    func_0025f230(*(u32 *)(work + 0x398));
    func_002aa2b0(work);
}

// FUN_002A4D10
INCLUDE_ASM("asm/nonmatchings/mc", func_002a4d10);

// FUN_002A4F20
INCLUDE_ASM("asm/nonmatchings/mc", func_002a4f20);

// FUN_002A5630
INCLUDE_ASM("asm/nonmatchings/mc", func_002a5630);

// FUN_002A5F00
INCLUDE_ASM("asm/nonmatchings/mc", func_002a5f00);

// FUN_002A6510
s32 func_002a6510(s32 arg0) {
    u8 *work = func_00452560();
    s32 flags = *(u32 *)(work + 4);

    if (!(flags & 1)) {
        return 0;
    }
    if (flags & 0x400) {
        if (func_002a4d10(arg0) != 0) {
            *(u32 *)(work + 4) &= ~0x400;
            *(u32 *)(work + 4) |= 0x20000;
        }
        return 0;
    }
    if (flags & 0x20000) {
        if (func_002a4f20(arg0) != 0) {
            *(u32 *)(work + 4) &= ~0x20000;
        }
        return 0;
    }
    if (flags & 0x40000) {
        if (func_002a5630(arg0) != 0) {
            *(u32 *)(work + 4) &= ~0x40000;
        }
        return 0;
    }
    func_002a5f00(arg0);
    return 0;
}

// FUN_002A6680
void func_002a6680(s32 arg0) {
    u8 *work = func_00460990();
    *(void **)(work + 8) = func_002a6650;
    *(void **)(work + 0x10) = (void *)arg0;
    func_00460ac0(&D_00796370, work);
}

// FUN_002A66D0
INCLUDE_ASM("asm/nonmatchings/mc", func_002a66d0);

// FUN_002A6960
INCLUDE_ASM("asm/nonmatchings/mc", func_002a6960);

// FUN_002A6AF0
s32 func_002a6af0(u8 *arg0) {
    s32 idx = *(s32 *)(arg0 + 0x3AC) * 4;
    return *(s32 *)(idx + (s32)arg0 + 0x14);
}

// FUN_002A6B10
void func_002a6b10(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    typedef union { f32 f; u8 b[4]; } U4;
    U4 u;
    Qword q;
    U4 *pu = &u;

    pu->f = D_00763910;
    pu->b[3] = (u8)arg2;
    q = D_0063ED70;
    if (arg2 != 0) {
        func_0045d6e0(pu, &q, 0.0f, 1);
    }
}

// FUN_002A6B60
INCLUDE_ASM("asm/nonmatchings/mc", func_002a6b60);

// FUN_002A6C30
INCLUDE_ASM("asm/nonmatchings/mc", func_002a6c30);

// FUN_002A6E30
INCLUDE_ASM("asm/nonmatchings/mc", func_002a6e30);

// FUN_002A7330
s32 func_002a7330(u8 *arg0) {
    s32 i = 0;
    while (i < 0x14) {
        if (!(*(u32 *)arg0 & 1)) {
            func_0043f9c8(arg0, 0, 0x14);
            *(u32 *)arg0 |= 1;
            return (s32)arg0;
        }
        arg0 += 0x14;
        i++;
    }
    return 0;
}

// FUN_002A73C0
INCLUDE_ASM("asm/nonmatchings/mc", func_002a73c0);

// FUN_002A7710
INCLUDE_ASM("asm/nonmatchings/mc", func_002a7710);

// FUN_002A7920
INCLUDE_ASM("asm/nonmatchings/mc", func_002a7920);

// FUN_002A9100
INCLUDE_ASM("asm/nonmatchings/mc", func_002a9100);

// FUN_002A95C0
INCLUDE_ASM("asm/nonmatchings/mc", func_002a95c0);

// FUN_002A9F50
INCLUDE_ASM("asm/nonmatchings/mc", func_002a9f50);

// FUN_002AA2B0
void func_002aa2b0(void *arg0) {
    typedef struct { u8 pad[0x3A4]; s32 handle; } Work;
    Work *work = arg0;
    if (work->handle != 0) {
        func_00454bd0((u8 *)work->handle);
        work->handle = 0;
    }
    D_008873EC[0](work);
}
// FUN_002AA300
void func_002aa300(s32 arg0, s32 arg1) {
    u8 *work;

    D_00764634 = 0;
    func_0044ea90(&D_007638F8, 0x8FF);
    work = D_008873F4[0](1, 0x56C, 0x40000);
    if (work == NULL) {
        func_0046d730(&D_007638F8, 0xE8);
    }
    *(s32 *)(work + 0x3AC) = D_00764638;
    *(s32 *)(work + 0x3B4) = D_00764638 << 16;
    *(u16 *)(work + 0) = 0;
    *(u16 *)(work + 2) = 0;
    if (arg1 == 1) {
        *(u32 *)(work + 4) |= 2;
    }
    func_00451fc0((u8 *)arg0, &D_00763918, 0xF, 0, 0, (s32 (*)(s32))func_002a4b10,
                 (s32 (*)(s32))func_002a4cb0, work);
}
