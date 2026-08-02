/* Consolidated Persona 4 source units. */
/* Original translation unit effPolygonThunder.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

/* FUN_004833F0 is a texture release helper shared by the eff* units. */
extern void func_004833f0(void *arg0);
extern u32 func_004bd050(u32 arg0);
extern f32 func_004bd0b0(u32 arg0);
extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const char *file, s32 line);
extern u8 *func_00484490(u8 *obj);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *);
extern char D_00713E50[];
extern u32 D_00713E70[];
extern u32 D_00713E74[];
extern u32 D_00713E84[];
u8 *func_004988c0(u16 arg0, u8 *arg1);


// FUN_00495160
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00495160);
// FUN_00495620
void func_00495620(u8 *arg0)
{
    u8 *obj;
    u8 **p;
    u32 count;
    u32 i;

    obj = *(u8 **)(arg0 + 0x30);
    p = *(u8 ***)obj;
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        func_004833f0(*p);
        i++;
        p += 4;
    }
    jtbl_008873EC[0](obj);
}


// FUN_004956B0
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_004956b0);


// FUN_00495F80
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00495f80);


// FUN_004961F0
void func_004961f0(u8 *arg0)
{
    u8 *obj0;
    u8 *obj1;
    u32 *p;
    s32 count;
    f32 a;
    f32 v;
    u32 i;

    obj0 = *(u8 **)(arg0 + 0x30);
    obj1 = *(u8 **)(arg0 + 0x34);
    p = *(u32 **)obj0;
    count = *(s32 *)(obj1 + 0x34);
    a = *(f32 *)(obj1 + 0x90);
    v = *(f32 *)(obj1 + 0x8C) * (a * func_004bd0b0(0) + (1.0f - a));
    if (count > 0)
    {
        f32 b = *(f32 *)(obj1 + 0x98);
        f32 w = *(f32 *)(obj1 + 0x94) * (b * func_004bd0b0(0) + (1.0f - b));
        *(f32 *)(obj0 + 4) = v;
        *(f32 *)(obj0 + 8) = (w - v) / (f32)count;
    }
    else
    {
        *(f32 *)(obj0 + 4) = v;
        *(f32 *)(obj0 + 8) = 0.0f;
    }
    count = *(s32 *)(obj1 + 0x38);
    i = 0;
    while (i < (u32)count)
    {
        p[5] = -1 - (func_004bd050(0) & 7);
        i++;
        p += 0xC;
    }
}


// FUN_00496340
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00496340);


// FUN_00496810
void func_00496810(u8 *arg0)
{
    u8 *obj;
    u8 **p;
    u32 count;
    u32 i;

    obj = *(u8 **)(arg0 + 0x30);
    p = *(u8 ***)obj;
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        func_004833f0(*p);
        i++;
        p += 0xC;
    }
    jtbl_008873EC[0](*(void **)(obj + 0xC));
}


// FUN_004968A0
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_004968a0);


// FUN_00497460
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00497460);


// FUN_004976D0
void func_004976d0(u8 *arg0)
{
    u32 *p;
    u32 count;
    u32 i;

    p = **(u32 ***)(arg0 + 0x30);
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        p[1] = -1 - (func_004bd050(0) & 3);
        i++;
        p += 3;
    }
}


// FUN_00497750
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00497750);


// FUN_00497C50
void func_00497c50(u8 *arg0)
{
    u8 *obj;
    u8 **p;
    u32 count;
    u32 i;

    obj = *(u8 **)(arg0 + 0x30);
    p = *(u8 ***)obj;
    count = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    i = 0;
    while (i < count)
    {
        func_004833f0(*p);
        i++;
        p += 3;
    }
    jtbl_008873EC[0](obj);
}


// FUN_00497CE0
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00497ce0);


// FUN_00498650
INCLUDE_ASM("asm/nonmatchings/effPolygonThunder", func_00498650);


// FUN_004988C0
u8 *func_004988c0(u16 arg0, u8 *arg1)
{
    u8 *p;
    s32 size;
    u32 idx;

    if (arg0 >= 5)
    {
        func_0046d730(D_00713E50, 0x6A1);
    }
    idx = arg0;
    size = D_00713E84[idx * 6];
    func_0044ea90(D_00713E50, 0x6A5);
    p = (u8 *)(*jtbl_008873E8)(size + 0x40, 0x40000);
    if (p == NULL)
    {
        func_0046d730(D_00713E50, 0x6A6);
    }
    *(u32 *)(p + 0x34) = (u32)(p + 0x40);
    *(u32 *)(p + 0x28) = 0;
    *(u32 *)(p + 0x2C) = idx;
    *(u32 *)(p + 0x24) = -1;
    *(u32 *)(p + 0x20) = 0x3F800000;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(p) : "memory");
    __asm__ volatile("sqc2 vf0, 0x10(%0)" : : "r"(p) : "memory");
    func_0043f810(*(void **)(p + 0x34), arg1, size);
    *(u32 *)(p + 0x30) = ((u32 (*)(u8 *))D_00713E74[arg0 * 6])(arg1);
    ((void (*)(u8 *))D_00713E70[arg0 * 6])(p);
    return p;
}


// FUN_00498A30
u8 *func_00498a30(u8 *arg0)
{
    u8 *tex;

    tex = func_00484490(arg0);
    if (tex == NULL)
    {
        func_0046d730(D_00713E50, 0x6C9);
    }
    tex = func_004988c0(*(u16 *)(arg0 + 0xC), tex);
    if (tex == NULL)
    {
        func_0046d730(D_00713E50, 0x6CB);
    }
    return tex;
}
