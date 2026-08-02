#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effGeometry.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern s32 func_00481460();
extern void func_00460ac0();
extern s32 func_00481390();
extern void func_003c42b0();
extern void func_003ef3a0();
extern void func_003a2760();
extern void func_003c02e0();
extern void func_003e9390();
extern void func_003c4220();
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_0048a150();
extern void func_003e0a90(void *arg0, f32 *arg1, s32 arg2);
extern void func_003e0c90(void *arg0, void *arg1, s32 arg2);
extern void func_003e05f0(void *arg0, void *arg1, void *arg2);
extern void func_003a2950();
extern void func_0046d730();
extern u8 D_00713448[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern s32 func_003e9320();
extern s32 func_003c00e0();
extern s32 func_003c4140();
extern void *func_003c2630(s32 arg0, s32 arg1, u32 arg2);
extern void func_003c1b90();
extern void func_003c0210();
extern void func_003c2a80();
extern void func_0043f9c8();
extern void func_0044ea90();
extern f32 fGpffff8078;
extern s32 iGpffffb610;
extern s32 func_003a2340();
extern u8 D_00713460[];
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_003c2150();
extern void func_003c2290();
extern void func_003c22f0();

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

void func_00483700(RwMatrix *arg0, RwV3d *arg1, void *arg2, f32 fparg0);
void func_003e9cb0(void *frame, void *matrix, u32 flags);

void func_00483810(RwMatrix *arg0, RwV3d *arg1, void *arg2, RwV3d *arg3);



// FUN_00482C40
u8 *func_00482c40(s32 arg0, s32 arg1, s32 arg2) {
    struct F4 { f32 x, y, z, w; } vec;
    void *p;
    void *obj;
    s32 t22;
    s32 t16;
    s32 t23;

    func_0044ea90(D_00713448, 0x1B);
    p = jtbl_008873E8[0](0x48, 0x40000);
    t22 = func_003e9320();
    t16 = func_003c00e0();
    t23 = func_003c4140();
    obj = func_003c2630(arg0, arg1, arg2);
    func_003c1b90(t16, t22);
    vec.x = 0.0f;
    vec.y = 0.0f;
    vec.z = 0.0f;
    vec.w = fGpffff8078;
    {
        u8 *q = *(u8 **)((u8 *)obj + 0x5C);
        *(struct F4 *)(q + 4) = vec;
    }
    func_003c0210(t16, obj, 0);
    func_003c2a80(obj);
    *(s16 *)((u8 *)p + 0) = 5;
    *(s32 *)((u8 *)p + 4) = arg2;
    *(s16 *)((u8 *)p + 8) = (s16)arg0;
    *(s16 *)((u8 *)p + 0xA) = (s16)arg1;
    *(s32 *)((u8 *)p + 0xC) = t22;
    *(s32 *)((u8 *)p + 0x10) = t16;
    *(s32 *)((u8 *)p + 0x14) = t23;
    func_0043f9c8((u8 *)p + 0x18, 0, 0x30);
    *(s16 *)((u8 *)p + 0x30) = 0x15;
    *(void **)((u8 *)p + 0x34) = p;
    return p;
}

// FUN_00482DC0
INCLUDE_ASM("asm/nonmatchings/effGeometry", func_00482dc0);

// FUN_00482F70
INCLUDE_ASM("asm/nonmatchings/effGeometry", func_00482f70);

// FUN_004830F0
u8 *func_004830f0(u16 arg0, s32 arg1) {
    u8 *p;
    s32 t;

    func_0044ea90(D_00713448, 0xA6);
    p = jtbl_008873E8[0](0x48, 0x40000);
    *(s16 *)(p + 0) = 3;
    *(s32 *)(p + 4) = arg1;
    *(s16 *)(p + 8) = 0;
    *(u16 *)(p + 0xA) = arg0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x10) = func_003a2340(arg0 & 0xFFFF, arg1, 2);
    t = func_003e9320();
    *(s32 *)(p + 0xC) = t;
    func_003c1b90(*(s32 **)(p + 0x10), t);
    *(s32 *)(*(u8 **)(*(u8 **)(p + 0x10) + iGpffffb610) + 0xB4) = 1;
    if (arg1 & 0x80000) {
        func_0043f810(*(u8 **)(*(u8 **)(p + 0x10) + iGpffffb610) + 0xE0, D_00713460, 0x10);
        *(s32 *)(*(u8 **)(*(u8 **)(p + 0x10) + iGpffffb610) + 0x40) |= 0x80000;
    }
    *(s32 *)(*(u8 **)(*(u8 **)(p + 0x10) + iGpffffb610) + 0x40) |= 0x800000;
    *(s32 *)(*(u8 **)(*(u8 **)(p + 0x10) + iGpffffb610) + 4) = 0;
    func_0043f9c8(p + 0x18, 0, 0x30);
    *(s16 *)(p + 0x30) = 0x15;
    *(u8 **)(p + 0x34) = p;
    return p;
}

// FUN_00483270
INCLUDE_ASM("asm/nonmatchings/effGeometry", func_00483270);

// FUN_004833F0
void func_004833f0(void *arg0) {
    s32 p = *(s32 *)((u8 *)arg0 + 0x10);
    if (p != 0) {
        if (*(u16 *)arg0 & 2) {
            func_003a2760(p);
        } else {
            func_003c02e0(p);
        }
    }
    p = *(s32 *)((u8 *)arg0 + 0xC);
    if (p != 0) {
        func_003e9390(p);
    }
    p = *(s32 *)((u8 *)arg0 + 0x14);
    if (p != 0) {
        func_003c4220(p);
    }
    jtbl_008873EC[0](arg0);
}

// FUN_00483490
void func_00483490(u8 *arg0, s32 arg1) {
    s32 h = func_00481460(arg1);

    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    func_00460ac0(h, arg0 + 0x18);
}

// FUN_004834E0
void func_004834e0(u8 *arg0, s32 arg1) {
    if (*(u16 *)arg0 & 2) {
        switch (arg1 & 0xFFFF) {
        case 0:
            func_003a2950(*(s32 **)(arg0 + 0x10), 2, 0x717FB);
            func_003a2950(*(s32 **)(arg0 + 0x10), 1, 0x44);
            break;
        case 1:
            func_003a2950(*(s32 **)(arg0 + 0x10), 2, 0x71801);
            func_003a2950(*(s32 **)(arg0 + 0x10), 1, 0x44);
            break;
        case 2:
            func_003a2950(*(s32 **)(arg0 + 0x10), 2, 0x71801);
            func_003a2950(*(s32 **)(arg0 + 0x10), 1, 0x48);
            break;
        case 3:
        case 4:
            func_003a2950(*(s32 **)(arg0 + 0x10), 2, 0x71801);
            func_003a2950(*(s32 **)(arg0 + 0x10), 1, 0x42);
            break;
        case 5:
        case 6:
            func_003a2950(*(s32 **)(arg0 + 0x10), 2, 0x71801);
            func_003a2950(*(s32 **)(arg0 + 0x10), 1, 6);
            break;
        default:
            func_0046d730(D_00713448, 0x14C);
            break;
        }
    }
}

// FUN_00483660
void func_00483660(u8 *arg0)
{
    RwMatrix matrix;
    void func_00483700();

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_004836B0
void func_004836b0(u8 *arg0)
{
    RwMatrix matrix;
    void func_00483810();

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}



// FUN_00483700
void func_00483700(RwMatrix *arg0, RwV3d *arg1, void *arg2, f32 fparg0) {
    f32 v[3];

    if (arg2 != 0) {
        func_0048a150(arg0, arg2);
    } else {
        arg0->at.z = 1.0f;
        arg0->up.y = 1.0f;
        arg0->right.x = 1.0f;
        arg0->up.x = 0.0f;
        arg0->right.z = 0.0f;
        arg0->right.y = 0.0f;
        arg0->at.y = 0.0f;
        arg0->at.x = 0.0f;
        arg0->up.z = 0.0f;
        arg0->pos.z = 0.0f;
        arg0->pos.y = 0.0f;
        arg0->pos.x = 0.0f;
        arg0->flags |= 0x20003;
    }
    if (fparg0 != 1.0f) {
        v[2] = fparg0;
        v[1] = fparg0;
        v[0] = fparg0;
        func_003e0a90(arg0, v, 2);
    }
    if (arg1 != 0) {
        v[0] = arg1->x;
        v[1] = arg1->y;
        v[2] = arg1->z;
        func_003e0c90(arg0, v, 2);
    }
}

// FUN_00483810
void func_00483810(RwMatrix *arg0, RwV3d *arg1, void *arg2, RwV3d *arg3) {
    RwMatrix out;
    RwMatrix m;
    f32 v[3];

    if (arg3 != 0) {
        v[0] = arg3->x;
        v[1] = arg3->y;
        v[2] = arg3->z;
        func_003e0a90(&m, v, 0);
    } else {
        m.at.z = 1.0f;
        m.up.y = 1.0f;
        m.right.x = 1.0f;
        m.up.x = 0.0f;
        m.right.z = 0.0f;
        m.right.y = 0.0f;
        m.at.y = 0.0f;
        m.at.x = 0.0f;
        m.up.z = 0.0f;
        m.pos.z = 0.0f;
        m.pos.y = 0.0f;
        m.pos.x = 0.0f;
        m.flags |= 0x20003;
    }
    if (arg2 != 0) {
        func_0048a150(&out, arg2);
        func_003e05f0(arg0, &m, &out);
    } else {
        s32 *sp = (s32 *)&m;
        s32 *dp;
        s32 n;
        n = 8;
        dp = (s32 *)arg0;
        do {
            s32 a = sp[0];
            s32 b = sp[1];
            sp += 2;
            n -= 1;
            dp[0] = a;
            dp[1] = b;
            dp += 2;
        } while (n > 0);
    }
    if (arg1 != 0) {
        v[0] = arg1->x;
        v[1] = arg1->y;
        v[2] = arg1->z;
        func_003e0c90(arg0, v, 2);
    }
}

// FUN_00483970
void func_00483970(u8 *arg0, u8 *arg1) {
    s32 ret = func_00481390(arg1);

    func_003c42b0(*(s32 **)(arg0 + 0x14), ret);
    func_003ef3a0(ret);
}

// FUN_004839D0
void func_004839d0(int param_1, u32 *param_2)
{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)**(int **)(param_1 + 0x14);
  param_2[2] = (u32)piVar1;

  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    *param_2 = *(u32 *)(iVar2 + 0xc);
    param_2[1] = *(u32 *)(iVar2 + 0x10);
  }

  return;
}

// FUN_00483A00
INCLUDE_ASM("asm/nonmatchings/effGeometry", func_00483a00);

// FUN_00483C40
INCLUDE_ASM("asm/nonmatchings/effGeometry", func_00483c40);

// FUN_00483E10
INCLUDE_ASM("asm/nonmatchings/effGeometry", func_00483e10);
