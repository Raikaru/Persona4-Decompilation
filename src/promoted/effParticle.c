/* Consolidated Persona 4 source units. */
/* Original translation unit effParticle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "btl_shuffle_draw_internal.h"

typedef unsigned int ParticleSnapshot __attribute__((mode(TI)));

void func_004833f0(s32 arg0);
s32 func_004830f0(s32 arg0, s32 arg1);

void func_00481ee0(s32 arg0);
s32 func_00481d80(s32 *arg0);
extern s32 func_00481e30(s32 arg0);

void func_004829c0(s32 arg0);
s32 func_00482800(s32 *arg0);
extern s32 func_00482a70(s32 arg0);

extern void func_00492d00(int param_1);
extern void func_00492cd0(u8 *arg0);
extern u8 *func_00492b20(u16 arg0, u32 arg1, void *arg2);
extern s32 func_00481300(s32 arg0);
typedef struct RpMaterial RpMaterial;
typedef struct RwTexture RwTexture;

extern RpMaterial *func_003c42b0(RpMaterial *material, RwTexture *texture);
extern void *func_00481390(void *arg0);
extern void func_003ef3a0(void *arg0);
extern void func_0044ea90(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0046d730(void *file, s32 line);
extern u8 D_00713CC0[];
extern u8 D_00713CD0[];
extern void (*jtbl_008873EC[])(void *);
extern u8 *func_00484570(u8 *arg0);
extern void func_004846d0(u8 *arg0);
extern u8 *func_00484830(u8 *arg0);
extern u8 *func_00484bb0(u8 *arg0);
extern void func_00485b20(void *arg0);
extern void *func_00485c80(void *arg0);
extern u8 *func_00483270(void *arg0);
extern s32 func_00484490(s32 arg0);
extern s32 func_004844d0(s32 arg0);
void func_004875d0(u8 *arg0, s32 arg1, void *arg2);
void func_00487160(u8 *arg0, u8 *arg1);
void func_00487650(u8 *arg0, s32 arg1, s32 arg2);
void func_004877b0(u8 *arg0, s32 arg1);
void func_00487860(u8 *arg0, s32 *arg1);
void func_00487710(u8 *arg0, s32 arg1);
void func_004878c0(u8 *arg0, void *arg1);
void func_00487a30(u8 *arg0, void *arg1);
void func_00487ba0(u8 *arg0, s32 *arg1);
extern void func_00484970(s32 arg0);
extern void func_00484a90(u8 *arg0, f32 arg1);
extern void func_00484a40(s32 arg0, void *arg1);
extern void func_004849c0(s32 arg0);
extern void func_00485fe0(s32 arg0);
extern void func_00486400(s32 arg0, f32 arg1);
extern void func_004861f0(s32 arg0, void *arg1);
extern void func_00485630(s32 arg0);
extern ParticleSnapshot func_00492df0(s32 arg0, u32 *arg1);
extern ParticleSnapshot func_00492db0(s32 arg0, u32 *arg1);
extern void func_004bceb0(void);

// FUN_00486A50
void *func_00486a50(s32 arg0)
{
    u8 *p;

    func_0044ea90(D_00713CC0, 0x171);
    p = (u8 *)(*jtbl_008873E8)(0x60, 0x40000);
    func_0043f9c8(p, 0, 0x60);
    if (p == NULL) {
        func_0046d730(D_00713CD0, 0x1F);
    }
    *(s32 *)(p + 0) = arg0;
    *(s32 *)(p + 4) = -1;
    *(s32 *)(p + 8) = 0x3F800000;
    return p;
}
// FUN_00486B00
s32 func_00486b00(u8 *source)
{
    u8 *settings;
    u32 allocatorAddress;
    u32 count;
    u32 emitCount;
    u8 *link;
    s32 *resource;

    settings = (u8 *)func_00484490((s32)source);
    if (settings == NULL) {
        func_0046d730(D_00713CD0, 0x55);
    }
    emitCount = *(u32 *)(settings + 0x20);
    if (emitCount == 0) {
        count = *(u32 *)(settings + 0xB8) * *(u32 *)(settings + 0x24);
    } else {
        count = emitCount * *(u32 *)(settings + 0x24);
    }
    if (count > 300) {
        count = 300;
    }
    func_0044ea90(D_00713CC0, 0x171);
    allocatorAddress = (u32)jtbl_008873E8;
    {
        u8 *const particle = (*(void *(**)(u32, u32))allocatorAddress)(0x60, 0x40000);
        func_0043f9c8(particle, 0, 0x60);
        if (particle == NULL) {
            func_0046d730(D_00713CD0, 0x1F);
        }
        *(u32 *)(particle + 0) = count;
        *(s32 *)(particle + 4) = -1;
        *(f32 *)(particle + 8) = 1.0f;
        if (particle == NULL) {
            func_0046d730(D_00713CD0, 0x57);
        }
        func_004875d0(particle, *(u16 *)(source + 0xC), settings);
        if (*(u32 *)particle == 0) {
            return (s32)particle;
        }
        resource = (s32 *)func_004844d0((s32)source);
        if (resource != NULL) {
            switch (*(u16 *)(source + 0x1C)) {
            case 1:
                func_00487650(particle, *(s32 *)(*(u8 **)(particle + 0x4C) + 8), 1);
                func_004877b0(particle, (s32)resource);
                break;
            case 2:
                func_00487650(particle, *(s32 *)(*(u8 **)(particle + 0x4C) + 8), 2);
                func_00487860(particle, resource);
                break;
            case 4:
                func_00487650(particle, *(s32 *)(*(u8 **)(particle + 0x4C) + 8), 4);
                func_00487710(particle, *resource);
                break;
            case 5:
                func_004878c0(particle, resource);
                break;
            case 6:
                func_00487a30(particle, resource);
                break;
            case 7:
                func_00487650(particle, *(s32 *)(*(u8 **)(particle + 0x4C) + 8), 7);
                func_00487ba0(particle, resource);
                func_0044ea90(D_00713CC0, 0x171);
                link = (*(void *(**)(u32, u32))allocatorAddress)(0x30, 0x40000);
                func_0043f9c8(link, 0, 0x30);
                *(u8 **)(particle + 0x5C) = link;
                *(u16 *)(link + 0x18) = 0x19;
                *(u8 **)(*(u8 **)(particle + 0x5C) + 0x1C) = particle;
                break;
            default:
                func_0046d730(D_00713CD0, 0x7E);
                break;
            }
            *(u16 *)(particle + 0xC) = *(u16 *)(source + 0x1C);
        }
        return (s32)particle;
    }
}

// FUN_00486E10
void func_00486e10(u8 *arg0)
{
    u32 count;
    u32 i;

    if (*(s32 *)(arg0 + 0x38) != 0) {
        if (*(s32 *)(arg0 + 0x4C) != 0) {
            count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
        } else {
            count = *(s32 *)(arg0 + 0);
        }
        for (i = 0; i < count; i++) {
            func_004846d0(*(u8 **)(*(u8 **)(arg0 + 0x34) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    }
    if (*(s32 *)(arg0 + 0x40) != 0) {
        if (*(s32 *)(arg0 + 0x4C) != 0) {
            count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
        } else {
            count = *(s32 *)(arg0 + 0);
        }
        for (i = 0; i < count; i++) {
            func_00485b20(*(u8 **)(*(u8 **)(arg0 + 0x3C) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x40));
    }
    if (*(s32 *)(arg0 + 0x44) != 0) {
        func_00481ee0(*(s32 *)(arg0 + 0x44));
    }
    if (*(s32 *)(arg0 + 0x48) != 0) {
        func_004829c0(*(s32 *)(arg0 + 0x48));
    }
    if (*(u8 *)(arg0 + 0xE) & 1) {
        func_00492cd0((u8 *)*(s32 *)(arg0 + 0x4C));
    }
    if (*(s32 *)(arg0 + 0x50) != 0) {
        func_004833f0(*(s32 *)(arg0 + 0x50));
    }
    if (*(s32 *)(arg0 + 0x5C) != 0) {
        jtbl_008873EC[0](*(void **)(arg0 + 0x5C));
    }
    jtbl_008873EC[0](arg0);
}
// FUN_00486FB0
void *func_00486fb0(u8 *arg0)
{
    u32 s19;
    u8 *s17;
    u8 *p;
    u32 v;

    if (*(s32 *)(arg0 + 0x4C) == 0) {
        func_0046d730(D_00713CD0, 0xE0);
    }
    s17 = *(u8 **)(*(u8 **)(arg0 + 0x4C) + 0x24);
    if (s17 == NULL) {
        func_0046d730(D_00713CD0, 0xE2);
    }
    v = *(u32 *)(s17 + 0x20);
    if (v == 0) {
        s19 = *(u32 *)(s17 + 0xB8) * *(u32 *)(s17 + 0x24);
    } else {
        s19 = v * *(u32 *)(s17 + 0x24);
    }
    if (s19 > 0x12C) {
        s19 = 0x12C;
    }
    func_0044ea90(D_00713CC0, 0x171);
    p = (u8 *)(*jtbl_008873E8)(0x60, 0x40000);
    func_0043f9c8(p, 0, 0x60);
    if (p == NULL) {
        func_0046d730(D_00713CD0, 0x1F);
    }
    *(u32 *)(p + 0) = s19;
    *(s32 *)(p + 4) = -1;
    *(s32 *)(p + 8) = 0x3F800000;
    if (p == NULL) {
        func_0046d730(D_00713CD0, 0xE4);
    }
    func_004875d0(p, *(u16 *)(*(u8 **)(arg0 + 0x4C)), (void *)s17);
    if (*(s32 *)(p + 0) == 0) {
        return p;
    }
    if (*(s32 *)(arg0 + 0x50) != 0) {
        *(s32 *)(p + 0x50) = (s32)func_00483270((void *)*(s32 *)(arg0 + 0x50));
    }
    func_00487160(p, arg0);
    return p;
}
/* measured: case-local count/index pairs make b210 color the loop locals
   $s2/$s3 and the parameters $s1/$s0, matching retail. The named case-7
   allocation result remains in $s2 through memset before being stored at
   arg0+0x5C. Shared function-scope counters rotate all four saved registers.
   Object/window 1136B, normalized_diff 0. */
// FUN_00487160
void func_00487160(u8 *arg0, u8 *arg1)
{
    switch (*(u16 *)(arg1 + 0xC)) {
    case 1:
    case 4:
        *(f32 *)(arg0 + 0x54) = *(f32 *)(arg1 + 0x54);
        *(f32 *)(arg0 + 0x58) = *(f32 *)(arg1 + 0x58);
        break;
    case 2:
        if (*(s32 *)(arg1 + 0x44) == 0) {
            func_0046d730(D_00713CD0, 0x10D);
        }
        if (*(s32 *)(arg1 + 0x4C) == 0) {
            func_0046d730(D_00713CD0, 0x10E);
        }
        if (*(s32 *)(arg0 + 0x44) != 0) {
            func_00481ee0(*(s32 *)(arg0 + 0x44));
        }
        *(s32 *)(arg0 + 0x44) = func_00481e30(*(s32 *)(arg1 + 0x44));
        break;
    case 5: {
        u32 count5;
        u32 i5;

        count5 = *(u32 *)(*(u8 **)(arg1 + 0x4C) + 8);
        if (count5 == 0) {
            return;
        }
        if (*(s32 *)(arg1 + 0x38) == 0) {
            func_0046d730(D_00713CD0, 0x119);
        }
        if (*(s32 *)(arg1 + 0x4C) == 0) {
            func_0046d730(D_00713CD0, 0x11A);
        }
        if (*(s32 *)(arg0 + 0x38) != 0) {
            for (i5 = 0; i5 < count5; i5++) {
                func_004846d0(*(u8 **)(*(u8 **)(arg0 + 0x34) + i5 * 4));
            }
            jtbl_008873EC[0](*(void **)(arg0 + 0x38));
            *(u8 **)(arg0 + 0x34) = NULL;
            *(u8 **)(arg0 + 0x38) = NULL;
        }
        if (count5 * 4 == 0) {
            return;
        }
        func_0044ea90(D_00713CD0, 0x12C);
        *(u8 **)(arg0 + 0x38) = (u8 *)(*jtbl_008873E8)(count5 * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x38) == NULL) {
            func_0046d730(D_00713CD0, 0x12D);
        }
        *(u8 **)(arg0 + 0x34) = *(u8 **)(arg0 + 0x38);
        for (i5 = 0; i5 < count5; i5++) {
            *(u8 **)(*(u8 **)(arg0 + 0x34) + i5 * 4) =
                func_00484830(*(u8 **)(*(u8 **)(arg1 + 0x34)));
        }
        break;
    }
    case 6: {
        u32 count6;
        u32 i6;

        count6 = *(u32 *)(*(u8 **)(arg1 + 0x4C) + 8);
        if (count6 == 0) {
            return;
        }
        if (*(s32 *)(arg1 + 0x40) == 0) {
            func_0046d730(D_00713CD0, 0x139);
        }
        if (*(s32 *)(arg1 + 0x4C) == 0) {
            func_0046d730(D_00713CD0, 0x13A);
        }
        if (*(s32 *)(arg0 + 0x40) != 0) {
            for (i6 = 0; i6 < count6; i6++) {
                func_00485b20(*(u8 **)(*(u8 **)(arg0 + 0x3C) + i6 * 4));
            }
            jtbl_008873EC[0](*(void **)(arg0 + 0x40));
            *(u8 **)(arg0 + 0x3C) = NULL;
            *(u8 **)(arg0 + 0x40) = NULL;
        }
        if (count6 * 4 == 0) {
            return;
        }
        func_0044ea90(D_00713CD0, 0x14C);
        *(u8 **)(arg0 + 0x40) = (u8 *)(*jtbl_008873E8)(count6 * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x40) == NULL) {
            func_0046d730(D_00713CD0, 0x14D);
        }
        *(u8 **)(arg0 + 0x3C) = *(u8 **)(arg0 + 0x40);
        for (i6 = 0; i6 < count6; i6++) {
            *(u8 **)(*(u8 **)(arg0 + 0x3C) + i6 * 4) =
                func_00485c80(*(u8 **)(*(u8 **)(arg1 + 0x3C)));
        }
        break;
    }
    case 7: {
        u8 *p;

        if (*(s32 *)(arg1 + 0x48) == 0) {
            func_0046d730(D_00713CD0, 0x156);
        }
        if (*(s32 *)(arg0 + 0x48) != 0) {
            func_004829c0(*(s32 *)(arg0 + 0x48));
        }
        *(s32 *)(arg0 + 0x48) = func_00482a70(*(s32 *)(arg1 + 0x48));
        if (*(s32 *)(arg0 + 0x5C) != 0) {
            func_0046d730(D_00713CD0, 0x15F);
        }
        func_0044ea90(D_00713CC0, 0x171);
        p = (u8 *)(*jtbl_008873E8)(0x30, 0x40000);
        func_0043f9c8(p, 0, 0x30);
        *(u8 **)(arg0 + 0x5C) = p;
        *(u16 *)(p + 0x18) = 0x19;
        *(u8 **)(*(u8 **)(arg0 + 0x5C) + 0x1C) = arg0;
        break;
    }
    default:
        func_0046d730(D_00713CD0, 0x16A);
        break;
    }
    *(u16 *)(arg0 + 0xC) = *(u16 *)(arg1 + 0xC);
}

// FUN_004875D0
void func_004875d0(u8 *arg0, s32 arg1, void *arg2)
{
    if (*(u32 *)(arg0 + 0x4C) != 0) {
        func_00492cd0((u8 *)*(u32 *)(arg0 + 0x4C));
    }
    *(u32 *)(arg0 + 0x4C) = (u32)func_00492b20(arg1 & 0xFFFF, *(u32 *)(arg0 + 0), arg2);
    *(u8 *)(arg0 + 0xE) |= 1;
}




// FUN_00487650
void func_00487650(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x50);

    if (temp_4 != 0) {
        func_004833f0(temp_4);
    }
    switch (arg2) {
    case 1:
    case 4:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x20080027);
        return;
    case 2:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x200000A7);
        /* fallthrough */
    case 7:
        return;
    }
}

// FUN_00487710
void func_00487710(u8 *arg0, s32 arg1)
{
    void *temp_2 = (void *)func_00481300(arg1 & 0xFFFF);
    u8 *temp_2_2 = *(u8 **)temp_2;
    f32 f_10 = (f32)*(s32 *)(temp_2_2 + 0x10);
    f32 f_0c = (f32)*(s32 *)(temp_2_2 + 0xC);

    *(f32 *)(arg0 + 0x54) = f_0c / 2.0f / 16.0f;
    *(f32 *)(arg0 + 0x58) = f_10 / 2.0f / 16.0f;
    func_003c42b0((RpMaterial *)*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x50) + 0x10) + 0x18) + 0x20)), (RwTexture *)temp_2);
}
// FUN_004877B0
void func_004877b0(u8 *arg0, s32 arg1)
{
    void *temp_2 = func_00481390((void *)arg1);
    u8 *temp_2_2 = *(u8 **)temp_2;
    f32 f_10 = (f32)*(s32 *)(temp_2_2 + 0x10);
    f32 f_0c = (f32)*(s32 *)(temp_2_2 + 0xC);

    *(f32 *)(arg0 + 0x54) = f_0c / 2.0f / 16.0f;
    *(f32 *)(arg0 + 0x58) = f_10 / 2.0f / 16.0f;
    func_003c42b0((RpMaterial *)*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x50) + 0x10) + 0x18) + 0x20)), (RwTexture *)temp_2);
    func_003ef3a0(temp_2);
}




// FUN_00487860
void func_00487860(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x44);

    if (temp_4 != 0) {
        func_00481ee0(temp_4);
    }
    *(s32 *)(arg0 + 0x44) = func_00481d80(arg1);
}

// FUN_004878C0
void func_004878c0(u8 *arg0, void *arg1)
{
    u32 count;
    u32 i;

    if (*(s32 *)(arg0 + 0x4C) != 0) {
        count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
    } else {
        count = *(s32 *)(arg0 + 0);
    }
    if (*(s32 *)(arg0 + 0x38) != 0) {
        for (i = 0; i < count; i++) {
            func_004846d0(*(u8 **)(*(u8 **)(arg0 + 0x34) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x38));
        *(u8 **)(arg0 + 0x34) = NULL;
        *(u8 **)(arg0 + 0x38) = NULL;
    }
    if (count * 4 != 0) {
        func_0044ea90(D_00713CD0, 0x21C);
        *(u8 **)(arg0 + 0x38) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x38) == NULL) {
            func_0046d730(D_00713CD0, 0x21D);
        }
        *(u8 **)(arg0 + 0x34) = *(u8 **)(arg0 + 0x38);
        *(u8 **)(*(u8 **)(arg0 + 0x34)) = func_00484570((u8 *)arg1);
        for (i = 1; i < count; i++) {
            *(u8 **)(*(u8 **)(arg0 + 0x34) + i * 4) = func_00484830(*(u8 **)(*(u8 **)(arg0 + 0x34)));
        }
    }
}
// FUN_00487A30
void func_00487a30(u8 *arg0, void *arg1)
{
    u32 count;
    u32 i;

    if (*(s32 *)(arg0 + 0x4C) != 0) {
        count = *(s32 *)(*(s32 *)(arg0 + 0x4C) + 8);
    } else {
        count = *(s32 *)(arg0 + 0);
    }
    if (*(s32 *)(arg0 + 0x40) != 0) {
        for (i = 0; i < count; i++) {
            func_00485b20(*(u8 **)(*(u8 **)(arg0 + 0x3C) + i * 4));
        }
        jtbl_008873EC[0](*(void **)(arg0 + 0x40));
        *(u8 **)(arg0 + 0x3C) = NULL;
        *(u8 **)(arg0 + 0x40) = NULL;
    }
    if (count * 4 != 0) {
        func_0044ea90(D_00713CD0, 0x24F);
        *(u8 **)(arg0 + 0x40) = (u8 *)(*jtbl_008873E8)(count * 4, 0x40000);
        if (*(u8 **)(arg0 + 0x40) == NULL) {
            func_0046d730(D_00713CD0, 0x250);
        }
        *(u8 **)(arg0 + 0x3C) = *(u8 **)(arg0 + 0x40);
        *(u8 **)(*(u8 **)(arg0 + 0x3C)) = func_00484bb0((u8 *)arg1);
        for (i = 1; i < count; i++) {
            *(u8 **)(*(u8 **)(arg0 + 0x3C) + i * 4) = func_00485c80(*(u8 **)(*(u8 **)(arg0 + 0x3C)));
        }
    }
}




// FUN_00487BA0
void func_00487ba0(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x48);

    if (temp_4 != 0) {
        func_004829c0(temp_4);
    }
    *(s32 *)(arg0 + 0x48) = func_00482800(arg1);
}



// FUN_00487C00
void func_00487c00(int param_1)
{
  if (*(int *)(param_1 + 0x4c) != 0) {
    func_00492d00(*(int *)(param_1 + 0x4c));
  }
  return;
}

/* measured: reconstructed full switch/VU0 particle path; retail and candidate differ only by temp_17/var_16 saved-register assignment (retail $s1/$s0, candidate $s0/$s1), nd 27, object 892B/window 896B. Tried saved-local declaration permutations, case-local splits, register qualifiers, pointer/count types, expression shapes, and O1; no improvement. Parked near-match. */
// Archived C body: build/WBHygiene_func_00487c30_archive.txt; no current park body remains.
/* measured: 27 differing words, 223/223 instrs, fnalign 49ed, obj892B/window896B; loopinv 27wd/49ed tie, schedule 194 (764B), commons 27 tie, prop 27 tie; decl-swap var_16-front 64ed (worse); temp_17/var_16 $s0/$s1 vs retail $s1/$s0 rotation stands from earliest hunk (retail[18] lw $s0 vs object $s1); no lb/lbu so s8 N/A; no sunk address chain so double-def N/A; VU0 lqc2/sqc2 split blocks reproduce. Banked near-match. */
/* pair sweep 2026-09-17: `python3 -E -s tools/pragma_sweep.py src/promoted/effParticle.c func_00487c30 --pairs` banked 27; best ties 27 (all 8 singles except schedule/peephole plus 13 pairs among them); all 28 pairs neutral or worse (peephole 175-191, schedule 190-194). Singles loopinv/commons/prop already tie per above; pairs confirm $s0/$s1 rotation floor. fnalign retail/object 223/223 per assignment. Floor stands; production stays ASM. */
/* 2026-09-18 lead pass; section 7m exchanged-register-pair class, floor
   confirmed at 27 words.  223/223 instructions and every differing word is
   an instruction naming `var_16` or `temp_17`: retail puts the pointer
   loaded from `0x18(temp_18)` in $s0 and the count from `8(temp_18)` in
   $s1, this body has them the other way round.  The load order already
   matches retail, so it is the allocation and not the sequence.
   Declaration order does not reach it: moving `temp_17` above `var_19` ties
   at 27, while swapping `var_16` with `temp_18` costs 27 -> 42 and moving
   `var_16` after `var_19` costs the same.  One more member of the class
   documented in handoff 7m; stop here. */
// FUN_00487C30 NONMATCHING
#ifdef NON_MATCHING
void func_00487c30(u8 *arg0, f32 arg1)
{
    u8 spC0[16];
    u8 spB0[16];
    u8 spA0[16];
    u8 sp60[0x40];
    s32 *var_19;
    s32 temp_17;
    s32 var_18;
    u16 temp_5;
    u8 *temp_18;
    u8 *var_16;

    temp_18 = *(u8 **)(arg0 + 0x4C);
    temp_5 = *(u16 *)(arg0 + 0xC);
    switch (temp_5) {
    case 5:
        var_16 = *(u8 **)(temp_18 + 0x18);
        var_19 = *(s32 **)(arg0 + 0x34);
        temp_17 = *(s32 *)(temp_18 + 8);
        if ((*(u32 *)(temp_18 + 0xC) & 1) == 0) {
            var_18 = 0;
            while (var_18 < temp_17) {
                if (*(s32 *)(var_16 + 0x10) == 0) {
                    func_00484970(*var_19);
                }
                if (*(s32 *)(var_16 + 0x10) >= 0) {
                    func_00484a90((u8 *)*var_19,
                                  *(f32 *)(var_16 + 0x18) * arg1);
                    func_00484a40(*var_19, var_16);
                    func_004849c0(*var_19);
                }
                var_18++;
                var_16 += 0x20;
                var_19++;
            }
            return;
        }
        func_00492df0((s32)temp_18, (u32 *)spA0);
        func_00492db0((s32)temp_18, (u32 *)spB0);
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf10, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spA0)
            : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf31, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spB0)
            : "$vf31", "memory");
        __asm__ volatile(
            ".set noreorder       \n"
            "sqc2 $vf28, 0(%0)    \n"
            "sqc2 $vf29, 16(%0)   \n"
            "sqc2 $vf30, 32(%0)   \n"
            "sqc2 $vf31, 48(%0)   \n"
            ".set reorder         \n"
            :
            : "r"(sp60)
            : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
        var_18 = 0;
        while (var_18 < temp_17) {
            if (*(s32 *)(var_16 + 0x10) >= 0) {
                __asm__ volatile(
                    ".set noreorder                  \n"
                    "lqc2 $vf28, 0(%0)                \n"
                    "lqc2 $vf29, 16(%0)               \n"
                    "lqc2 $vf30, 32(%0)               \n"
                    "lqc2 $vf31, 48(%0)               \n"
                    "lqc2 $vf10, 0(%1)                \n"
                    "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                    "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                    "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                    "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                    ".set reorder                    \n"
                    :
                    : "r"(sp60), "r"(var_16)
                    : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10",
                      "ACC", "memory");
                __asm__ volatile(
                    ".set noreorder       \n"
                    "sqc2 $vf10, 0(%0)    \n"
                    ".set reorder         \n"
                    :
                    : "r"(spC0)
                    : "$vf10", "memory");
                func_00484a90((u8 *)*var_19,
                              *(f32 *)(var_16 + 0x18) * arg1);
                func_00484a40(*var_19, spC0);
                func_004849c0(*var_19);
            }
            var_18++;
            var_16 += 0x20;
            var_19++;
        }
        return;
    case 6:
        var_16 = *(u8 **)(temp_18 + 0x18);
        var_19 = *(s32 **)(arg0 + 0x3C);
        temp_17 = *(s32 *)(temp_18 + 8);
        if ((*(u32 *)(temp_18 + 0xC) & 1) == 0) {
            var_18 = 0;
            while (var_18 < temp_17) {
                if (*(s32 *)(var_16 + 0x10) == 0) {
                    func_00485fe0(*var_19);
                }
                if (*(s32 *)(var_16 + 0x10) >= 0) {
                    func_00486400(*var_19,
                                  *(f32 *)(var_16 + 0x18) * arg1);
                    func_004861f0(*var_19, var_16);
                    func_00485630(*var_19);
                }
                var_18++;
                var_16 += 0x20;
                var_19++;
            }
            return;
        }
        func_00492df0((s32)temp_18, (u32 *)spA0);
        func_00492db0((s32)temp_18, (u32 *)spB0);
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf10, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spA0)
            : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile(
            ".set noreorder       \n"
            "lqc2 $vf31, 0(%0)    \n"
            ".set reorder         \n"
            :
            : "r"(spB0)
            : "$vf31", "memory");
        __asm__ volatile(
            ".set noreorder       \n"
            "sqc2 $vf28, 0(%0)    \n"
            "sqc2 $vf29, 16(%0)   \n"
            "sqc2 $vf30, 32(%0)   \n"
            "sqc2 $vf31, 48(%0)   \n"
            ".set reorder         \n"
            :
            : "r"(sp60)
            : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
        var_18 = 0;
        while (var_18 < temp_17) {
            if (*(s32 *)(var_16 + 0x10) == 0) {
                func_00485fe0(*var_19);
            }
            if (*(s32 *)(var_16 + 0x10) >= 0) {
                __asm__ volatile(
                    ".set noreorder                  \n"
                    "lqc2 $vf28, 0(%0)                \n"
                    "lqc2 $vf29, 16(%0)               \n"
                    "lqc2 $vf30, 32(%0)               \n"
                    "lqc2 $vf31, 48(%0)               \n"
                    "lqc2 $vf10, 0(%1)                \n"
                    "vmulax.xyzw $ACC, $vf28, $vf10x \n"
                    "vmadday.xyzw $ACC, $vf29, $vf10y \n"
                    "vmaddaz.xyzw $ACC, $vf30, $vf10z \n"
                    "vmaddw.xyzw $vf10, $vf31, $vf0w \n"
                    ".set reorder                    \n"
                    :
                    : "r"(sp60), "r"(var_16)
                    : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10",
                      "ACC", "memory");
                __asm__ volatile(
                    ".set noreorder       \n"
                    "sqc2 $vf10, 0(%0)    \n"
                    ".set reorder         \n"
                    :
                    : "r"(spC0)
                    : "$vf10", "memory");
                func_00486400(*var_19,
                              *(f32 *)(var_16 + 0x18) * arg1);
                func_004861f0(*var_19, spC0);
                func_00485630(*var_19);
            }
            var_18++;
            var_16 += 0x20;
            var_19++;
        }
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/effParticle", func_00487c30);
#endif
typedef struct RpAtomic RpAtomic;
typedef enum RpPTankLockFlags
{
    rpPTANKLOCKWRITE = ((s32)0x40000000),
    rpPTANKLOCKREAD = ((s32)0x80000000)
} RpPTankLockFlags;
typedef struct RpPTankLockStruct
{
    u8* data;
    s32 stride;
} RpPTankLockStruct;

typedef struct ParticleRenderColorBytes
{
    u8 red, green, blue, alpha;
} ParticleRenderColorBytes;
typedef union ParticleRenderColor
{
    u32 word;
    ParticleRenderColorBytes bytes;
} ParticleRenderColor;
typedef char ParticleRenderColorSize[(sizeof(ParticleRenderColor) == 4) ? 1 : -1];

typedef struct ParticleAnimationOutput
{
    f32 x, y, width, height;
    f32 angle;
    void* texture;
    f32 u0, v0, u1, v1;
    u16 type;
    u16 unknown2A;
    u32 color;
    f32 textureWidth, textureHeight;
} ParticleAnimationOutput;
typedef char ParticleAnimationOutputSize[(sizeof(ParticleAnimationOutput) == 56) ? 1 : -1];

/* VU0 boundary: VF10 contains the normalized animated particle color.
 * Packing produces the real four-byte scalar consumed by the color stream. */
static inline u32 particlePackAnimatedColor(void)
{
    u32 result;
    u32 work;
    work = 0x437F0000U;
    __asm__ volatile("qmtc2.ni %0, $vf2\n"
                     "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                     "vftoi0.xyzw $vf10, $vf10\n"
                     "qmfc2.ni %0, $vf10\n"
                     "ppach %0, $0, %0\n"
                     "ppacb %0, $0, %0\n"
                     "sw %0, result\n"
                     : "+r"(work), "=m"(result)
                     :
                     : "$vf2", "$vf10", "memory");
    return result;
}

/* The transformed pass keeps the color-byte scale in an FPR. */
static inline u32 particlePackAnimatedColorTransformed(f32 scale)
{
    u32 result;
    u32 work;
    __asm__ volatile("mfc1 %0, %2\n"
                     "nop\n"
                     "qmtc2.ni %0, $vf2\n"
                     "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                     "vftoi0.xyzw $vf10, $vf10\n"
                     "qmfc2.ni %0, $vf10\n"
                     "ppach %0, $0, %0\n"
                     "ppacb %0, $0, %0\n"
                     "sw %0, result\n"
                     : "=&r"(work), "=m"(result)
                     : "f"(scale)
                     : "$vf2", "$vf10", "memory");
    return result;
}

/* measured: native b210 -O2 emits3516 exact bytes and four alignment bytes.
 * Native lock records, color results, and phase-local matrix/angle/count
 * lifetimes preserve the full renderer and its eight-entry switch table.
 * Evidence: build/finish-first-party-20260922/particle-next-02/. */

// FUN_00487FB0
void func_00487fb0(u8* particle, f32 scale)
{
    extern s32 func_003a5180(RpAtomic * atomic);
    extern s32 func_003a2770(RpAtomic * atomic, RpPTankLockStruct * lock, u32 dataFlags, RpPTankLockFlags access);
    extern s32 func_003a2920(s32 a);
    extern void func_00482730(int a, u32 b);
    extern void func_00482700(int a, float* b);
    extern s32 func_00482790(u8 * *a, u32 b);
    extern void func_004834e0(u8 * a, s32 b);
    extern void func_00483490(u8 * a, s32 b);
    extern void func_00484ae0(u8 * a, s32 b);
    extern void func_00484a00(u8 * a);
    extern void func_004865c0(u8 * a, s32 b);
    extern void func_00485870(s32 a);
    extern s32 func_00481460(u16 a);
    extern void func_00460ac0(u8 * list, u8 * node);
    extern f32 fGpffff8044;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff80a0;
    extern f32 fGpffff80a4;
    extern f32 fGpffff80a8;
    extern f32 fGpffff80ac;
    extern f32 fGpffff80b0;
    extern f32 fGpffff80b4;
    extern f32 fGpffff80b8;
    extern s32 iGpffffb610;
    extern u8 D_00713CD0[];
    ParticleRenderColor materialColor;
    u8 transformedPoint[16] __attribute__((aligned(16)));
    u8 translationSnapshot[16] __attribute__((aligned(16)));
    u8 rotationSnapshot[16] __attribute__((aligned(16)));
    u8 transformStorage[64] __attribute__((aligned(16)));
    f32 parentColor[4] __attribute__((aligned(16)));
    ParticleAnimationOutput animation;
    RpPTankLockStruct rotationLock;
    RpPTankLockStruct positionLock;
    RpPTankLockStruct sizeLock;
    RpPTankLockStruct colorLock;
    RpPTankLockStruct uvLock;
    u8* emitterOrObjects;
    u8* record;
    u8* atomicAddress;
    u8* settings;
    u8* animationSettings;
    s32 particleCount;
    s32 activeCount;
    f32 colorScale;
    f32 scaleX;
    f32 scaleY;
    s32 plainIndex;
    s32 transformedIndex;
    s32 animatedIndex;
    s32 animatedTransformedIndex;
    s32 effectIndex;
    s32 modelIndex;
    emitterOrObjects = *(u8**)(particle + 0x4C);
    {
        s32 inputColor = *(s32*)(particle + 4);
        const s32* word = &inputColor;
        colorScale = fGpffff8044;
        __asm__ volatile("lw $2, 0(%0)\n"
                         "pextlb $2, $0, $2\n"
                         "pextlh $2, $0, $2\n"
                         "qmtc2.ni $2, $vf10\n"
                         "vitof0.xyzw $vf10, $vf10\n"
                         "mfc1 $3, %1\n"
                         "nop\n"
                         "qmtc2.ni $3, $vf2\n"
                         "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                         :
                         : "r"(word), "f"(colorScale), "m"(inputColor)
                         : "$2", "$3", "$vf2", "$vf10", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%1)\n" : "=m"(parentColor) : "r"(parentColor) : "memory");
    }
    particleCount = *(s32*)(emitterOrObjects + 8);
    if (particleCount == 0)
    {
        goto particle_render_done;
    }
    if (*(s32*)(emitterOrObjects + 0x10) == 0)
    {
        goto particle_render_done;
    }
    record = *(u8**)(emitterOrObjects + 0x18);
    switch (*(u16*)(particle + 0xC))
    {
    case 1:
    case 4:
    {
        f32 upperAngle;
        f32 angleStep;
        f32 lowerAngle;
        activeCount = 0;
        scaleX = *(f32*)(particle + 0x54) * scale;
        scaleY = *(f32*)(particle + 0x58) * scale;
        atomicAddress = *(u8**)(*(u8**)(particle + 0x50) + 0x10);
        settings = *(u8**)(emitterOrObjects + 0x20);
        func_003a5180((RpAtomic*)atomicAddress);
        func_003a2770((RpAtomic*)atomicAddress, &positionLock, 1, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &colorLock, 2, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &sizeLock, 4, 0x40000000);
        func_003a2770((RpAtomic*)atomicAddress, &rotationLock, 0x20, 0x40000000);
        if ((*(u32*)(emitterOrObjects + 0xC) & 1) == 0)
        {
            plainIndex = 0;
            angleStep = fGpffff8080;
            upperAngle = fGpffff8084;
            lowerAngle = fGpffff80a0;
            while (plainIndex < particleCount)
            {
                if (*(s32*)(record + 0x10) >= 0)
                {
                    *(f32*)(positionLock.data + 0) = *(f32*)(record + 0);
                    *(f32*)(positionLock.data + 4) = *(f32*)(record + 4);
                    *(f32*)(positionLock.data + 8) = *(f32*)(record + 8);
                    positionLock.data += positionLock.stride;
                    *(s32*)colorLock.data = *(s32*)(record + 0x14);
                    colorLock.data += colorLock.stride;
                    {
                        f32 f = *(f32*)(record + 0x1C);
                        if (!(f <= upperAngle))
                        {
                            while (!(f <= upperAngle))
                            {
                                f -= angleStep;
                            }
                        }
                        else if (f < lowerAngle)
                        {
                            while (f < lowerAngle)
                            {
                                f += angleStep;
                            }
                        }
                        *(f32*)(record + 0x1C) = f;
                        *(f32*)rotationLock.data = f;
                        rotationLock.data += rotationLock.stride;
                    }
                    {
                        f32 s = *(f32*)(record + 0x18);
                        *(f32*)(sizeLock.data + 0) = scaleX * s;
                        *(f32*)(sizeLock.data + 4) = scaleY * s;
                        sizeLock.data += sizeLock.stride;
                    }
                    activeCount++;
                }
                plainIndex++;
                record += 0x20;
            }
        }
        else
        {
            f32(*transformMatrix)[4];
            f32* transformedPosition;
            func_00492df0((s32)emitterOrObjects, (u32*)rotationSnapshot);
            func_00492db0((s32)emitterOrObjects, (u32*)translationSnapshot);
            __asm__ volatile("lqc2 $vf10, 0(%0)\n"
                             :
                             : "r"(rotationSnapshot), "m"(rotationSnapshot)
                             : "$vf10", "memory");
            func_004bceb0();
            __asm__ volatile("lqc2 $vf31, 0(%0)\n"
                             :
                             : "r"(translationSnapshot), "m"(translationSnapshot)
                             : "$vf31", "memory");
            transformMatrix = (f32(*)[4])transformStorage;
            __asm__ volatile("sqc2 $vf28, 0(%1)\n"
                             "sqc2 $vf29, 16(%1)\n"
                             "sqc2 $vf30, 32(%1)\n"
                             "sqc2 $vf31, 48(%1)\n"
                             : "=m"(transformStorage)
                             : "r"(transformMatrix)
                             : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
            transformedIndex = 0;
            upperAngle = fGpffff8084;
            angleStep = fGpffff80a4;
            lowerAngle = fGpffff80a8;
            transformedPosition = (f32*)transformedPoint;
            while (transformedIndex < particleCount)
            {
                if (*(s32*)(record + 0x10) >= 0)
                {
                    __asm__ volatile("lqc2 $vf28, 0(%0)\n"
                                     "lqc2 $vf29, 16(%0)\n"
                                     "lqc2 $vf30, 32(%0)\n"
                                     "lqc2 $vf31, 48(%0)\n"
                                     "lqc2 $vf10, 0(%1)\n"
                                     "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                     "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                     "vmaddaz.xyzw $ACC, $vf30, $vf10z\n"
                                     "vmaddw.xyzw $vf10, $vf31, $vf0w\n"
                                     :
                                     : "r"(transformMatrix), "r"(record)
                                     : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                    __asm__ volatile("sqc2 $vf10, 0(%1)\n"
                                     : "=m"(transformedPoint)
                                     : "r"(transformedPosition)
                                     : "$vf10", "memory");
                    *(f32*)(positionLock.data + 0) = *(f32*)(transformedPoint + 0);
                    *(f32*)(positionLock.data + 4) = *(f32*)(transformedPoint + 4);
                    *(f32*)(positionLock.data + 8) = *(f32*)(transformedPoint + 8);
                    positionLock.data += positionLock.stride;
                    *(s32*)colorLock.data = *(s32*)(record + 0x14);
                    colorLock.data += colorLock.stride;
                    {
                        f32 f = *(f32*)(record + 0x1C);
                        if (!(f <= upperAngle))
                        {
                            while (!(f <= upperAngle))
                            {
                                f -= angleStep;
                            }
                        }
                        else if (f < lowerAngle)
                        {
                            while (f < lowerAngle)
                            {
                                f += angleStep;
                            }
                        }
                        *(f32*)(record + 0x1C) = f;
                        *(f32*)rotationLock.data = f;
                        rotationLock.data += rotationLock.stride;
                    }
                    {
                        f32 s = *(f32*)(record + 0x18);
                        *(f32*)(sizeLock.data + 0) = scaleX * s;
                        *(f32*)(sizeLock.data + 4) = scaleY * s;
                        sizeLock.data += sizeLock.stride;
                    }
                    activeCount++;
                }
                transformedIndex++;
                record += 0x20;
            }
        }
        func_003a2920((s32)atomicAddress);
        if (activeCount != 0)
        {
            u8* material;
            materialColor.word = *(u32*)(particle + 4);
            material = **(u8***)(*(u8**)(atomicAddress + 0x18) + 0x20);
            *(ParticleRenderColorBytes*)(material + 4) = materialColor.bytes;
            {
                *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 0x40) |= 0x800000;
                *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 4) = activeCount;
            }
            func_004834e0(*(u8**)(particle + 0x50), *(u16*)(settings + 0x54));
            func_00483490(*(u8**)(particle + 0x50), *(u16*)(settings + 0x54));
        }
        break;
    }
    case 2:
    {
        u8* animationResource = *(u8**)(particle + 0x44);
        if (animationResource == 0)
        {
            func_0046d730(D_00713CD0, 0x380);
        }
        /* Count only active particles in either animation path. This
         * initialized lifetime begins after the resource diagnostic and
         * ends after the active-count guard and PTank count store. */
        {
            s32 animatedActiveCount = 0;
            atomicAddress = *(u8**)(*(u8**)(particle + 0x50) + 0x10);
            animationSettings = *(u8**)(emitterOrObjects + 0x20);
            func_003a5180((RpAtomic*)atomicAddress);
            func_003a2770((RpAtomic*)atomicAddress, &positionLock, 1, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &colorLock, 2, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &sizeLock, 4, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &rotationLock, 0x20, 0x40000000);
            func_003a2770((RpAtomic*)atomicAddress, &uvLock, 0x80, 0x40000000);
            {
                s32 t = func_00482790((u8**)animationResource, 0);
                func_003c42b0(**(RpMaterial***)(*(u8**)(atomicAddress + 0x18) + 0x20), (RwTexture*)t);
            }
            if ((*(u32*)(emitterOrObjects + 0xC) & 1) == 0)
            {
                animatedIndex = 0;
                while (animatedIndex < particleCount)
                {
                    if (*(s32*)(record + 0x10) >= 0)
                    {
                        func_00482730((int)animationResource, *(u32*)(record + 0x10));
                        func_00482700((int)animationResource, (float*)&animation);
                        *(f32*)(uvLock.data + 0) = animation.u0;
                        *(f32*)(uvLock.data + 4) = animation.v0;
                        *(f32*)(uvLock.data + 8) = animation.u1;
                        *(f32*)(uvLock.data + 12) = animation.v1;
                        uvLock.data += uvLock.stride;
                        *(f32*)(positionLock.data + 0) = *(f32*)(record + 0);
                        *(f32*)(positionLock.data + 4) = *(f32*)(record + 4);
                        *(f32*)(positionLock.data + 8) = *(f32*)(record + 8);
                        positionLock.data += positionLock.stride;
                        {
                            u32 particleColor = *(u32*)(record + 0x14);
                            u32 animationColor;
                            f32 colorScale = fGpffff8044;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf11\n"
                                             "vitof0.xyzw $vf11, $vf11\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                                             :
                                             : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                             : "$2", "$vf2", "$vf11", "memory");
                            animationColor = animation.color;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf10\n"
                                             "vitof0.xyzw $vf10, $vf10\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                             :
                                             : "r"(&animationColor), "f"(colorScale), "m"(animationColor)
                                             : "$2", "$vf2", "$vf10", "memory");
                            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10", "$vf11", "memory");
                            *(s32*)colorLock.data = (s32)particlePackAnimatedColor();
                            colorLock.data += colorLock.stride;
                        }
                        {
                            f32 f = *(f32*)(record + 0x1C) + animation.angle;
                            f32 upperAngle = fGpffff8084;
                            if (!(f <= upperAngle))
                            {
                                f32 angleStep = fGpffff80ac;
                                while (!(f <= upperAngle))
                                {
                                    f -= angleStep;
                                }
                            }
                            else
                            {
                                f32 lowerAngle = fGpffff80b0;
                                if (f < lowerAngle)
                                {
                                    f32 angleStep = fGpffff80b4;
                                    while (f < lowerAngle)
                                    {
                                        f += angleStep;
                                    }
                                }
                            }
                            *(f32*)rotationLock.data = f;
                            rotationLock.data += rotationLock.stride;
                        }
                        {
                            f32 s = *(f32*)(record + 0x18) * scale;
                            *(f32*)(sizeLock.data + 0) = animation.width * s;
                            *(f32*)(sizeLock.data + 4) = animation.height * s;
                            sizeLock.data += sizeLock.stride;
                        }
                        animatedActiveCount++;
                    }
                    animatedIndex++;
                    record += 0x20;
                }
            }
            else
            {
                f32 colorByteScale;
                f32 upperAngle;
                f32 angleStep;
                f32 lowerAngle;
                func_00492df0((s32)emitterOrObjects, (u32*)rotationSnapshot);
                func_00492db0((s32)emitterOrObjects, (u32*)translationSnapshot);
                __asm__ volatile("lqc2 $vf10, 0(%0)\n"
                                 :
                                 : "r"(rotationSnapshot), "m"(rotationSnapshot)
                                 : "$vf10", "memory");
                func_004bceb0();
                __asm__ volatile("lqc2 $vf31, 0(%0)\n"
                                 :
                                 : "r"(translationSnapshot), "m"(translationSnapshot)
                                 : "$vf31", "memory");
                __asm__ volatile("sqc2 $vf28, 0(%1)\n"
                                 "sqc2 $vf29, 16(%1)\n"
                                 "sqc2 $vf30, 32(%1)\n"
                                 "sqc2 $vf31, 48(%1)\n"
                                 : "=m"(transformStorage)
                                 : "r"(transformStorage)
                                 : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
                animatedTransformedIndex = 0;
                colorByteScale = 255.0f;
                upperAngle = fGpffff8084;
                angleStep = fGpffff80b4;
                lowerAngle = fGpffff80b8;
                while (animatedTransformedIndex < particleCount)
                {
                    if (*(s32*)(record + 0x10) >= 0)
                    {
                        func_00482730((int)animationResource, *(u32*)(record + 0x10));
                        func_00482700((int)animationResource, (float*)&animation);
                        __asm__ volatile("lqc2 $vf28, 0(%0)\n"
                                         "lqc2 $vf29, 16(%0)\n"
                                         "lqc2 $vf30, 32(%0)\n"
                                         "lqc2 $vf31, 48(%0)\n"
                                         "lqc2 $vf10, 0(%1)\n"
                                         "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                                         "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                                         "vmaddaz.xyzw $ACC, $vf30, $vf10z\n"
                                         "vmaddw.xyzw $vf10, $vf31, $vf0w\n"
                                         :
                                         : "r"(transformStorage), "r"(record)
                                         : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                        __asm__ volatile("sqc2 $vf10, 0(%1)\n"
                                         : "=m"(transformedPoint)
                                         : "r"(transformedPoint)
                                         : "$vf10", "memory");
                        *(f32*)(uvLock.data + 0) = animation.u0;
                        *(f32*)(uvLock.data + 4) = animation.v0;
                        *(f32*)(uvLock.data + 8) = animation.u1;
                        *(f32*)(uvLock.data + 12) = animation.v1;
                        uvLock.data += uvLock.stride;
                        *(f32*)(positionLock.data + 0) = *(f32*)(transformedPoint + 0);
                        *(f32*)(positionLock.data + 4) = *(f32*)(transformedPoint + 4);
                        *(f32*)(positionLock.data + 8) = *(f32*)(transformedPoint + 8);
                        positionLock.data += positionLock.stride;
                        {
                            u32 particleColor = *(u32*)(record + 0x14);
                            u32 animationColor;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf11\n"
                                             "vitof0.xyzw $vf11, $vf11\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                                             :
                                             : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                             : "$2", "$vf2", "$vf11", "memory");
                            animationColor = animation.color;
                            __asm__ volatile("lw $2, 0(%0)\n"
                                             "pextlb $2, $0, $2\n"
                                             "pextlh $2, $0, $2\n"
                                             "qmtc2.ni $2, $vf10\n"
                                             "vitof0.xyzw $vf10, $vf10\n"
                                             "mfc1 $2, %1\n"
                                             "nop\n"
                                             "qmtc2.ni $2, $vf2\n"
                                             "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                             :
                                             : "r"(&animationColor), "f"(colorScale), "m"(animationColor)
                                             : "$2", "$vf2", "$vf10", "memory");
                            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11\n" : : : "$vf10", "$vf11", "memory");
                            *(s32*)colorLock.data = (s32)particlePackAnimatedColorTransformed(colorByteScale);
                            colorLock.data += colorLock.stride;
                        }
                        {
                            f32 f = *(f32*)(record + 0x1C) + animation.angle;
                            if (!(f <= upperAngle))
                            {
                                while (!(f <= upperAngle))
                                {
                                    f -= angleStep;
                                }
                            }
                            else if (f < lowerAngle)
                            {
                                while (f < lowerAngle)
                                {
                                    f += angleStep;
                                }
                            }
                            *(f32*)rotationLock.data = f;
                            rotationLock.data += rotationLock.stride;
                        }
                        {
                            f32 s = *(f32*)(record + 0x18) * scale;
                            *(f32*)(sizeLock.data + 0) = animation.width * s;
                            *(f32*)(sizeLock.data + 4) = animation.height * s;
                            sizeLock.data += sizeLock.stride;
                        }
                        animatedActiveCount++;
                    }
                    animatedTransformedIndex++;
                    record += 0x20;
                }
            }
            func_003a2920((s32)atomicAddress);
            if (animatedActiveCount != 0)
            {
                u8* material;
                materialColor.word = *(u32*)(particle + 4);
                material = **(u8***)(*(u8**)(atomicAddress + 0x18) + 0x20);
                *(ParticleRenderColorBytes*)(material + 4) = materialColor.bytes;
                {
                    *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 0x40) |= 0x800000;
                    *(s32*)(*(u8**)(atomicAddress + iGpffffb610) + 4) = animatedActiveCount;
                }
                func_004834e0(*(u8**)(particle + 0x50), *(u16*)(animationSettings + 0x54));
                func_00483490(*(u8**)(particle + 0x50), *(u16*)(animationSettings + 0x54));
            }
        }
    }
    break;
    case 5:
    {
        emitterOrObjects = *(u8**)(particle + 0x34);
        if (emitterOrObjects == 0)
        {
            func_0046d730(D_00713CD0, 0x3F3);
        }
        effectIndex = 0;
        while (effectIndex < particleCount)
        {
            if (*(s32*)(record + 0x10) >= 0)
            {
                u32 particleColor = *(u32*)(record + 0x14);
                u32 packedColor;
                u32 colorWord;
                __asm__ volatile("lw $2, 0(%0)\n"
                                 "pextlb $2, $0, $2\n"
                                 "pextlh $2, $0, $2\n"
                                 "qmtc2.ni $2, $vf10\n"
                                 "vitof0.xyzw $vf10, $vf10\n"
                                 "mfc1 $2, %1\n"
                                 "nop\n"
                                 "qmtc2.ni $2, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 :
                                 : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                 : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile("lqc2 $vf11, 0(%0)\n"
                                 "vmul.xyzw $vf10, $vf10, $vf11\n"
                                 :
                                 : "r"(parentColor), "m"(parentColor)
                                 : "$vf10", "$vf11", "memory");
                colorWord = 0x437F0000U;
                __asm__ volatile("qmtc2.ni %0, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 "vftoi0.xyzw $vf10, $vf10\n"
                                 "qmfc2.ni %0, $vf10\n"
                                 "ppach %0, $0, %0\n"
                                 "ppacb %0, $0, %0\n"
                                 "sw %0, packedColor\n"
                                 : "+r"(colorWord), "=m"(packedColor)
                                 :
                                 : "$vf2", "$vf10", "memory");
                func_00484ae0((u8*)*(s32*)emitterOrObjects, packedColor);
                func_00484a00((u8*)*(s32*)emitterOrObjects);
            }
            effectIndex++;
            record += 0x20;
            emitterOrObjects += sizeof(s32);
        }
    }
    break;
    case 6:
    {
        emitterOrObjects = *(u8**)(particle + 0x3C);
        if (emitterOrObjects == 0)
        {
            func_0046d730(D_00713CD0, 0x406);
        }
        modelIndex = 0;
        while (modelIndex < particleCount)
        {
            if (*(s32*)(record + 0x10) >= 0)
            {
                u32 particleColor = *(u32*)(record + 0x14);
                u32 packedColor;
                u32 colorWord;
                __asm__ volatile("lw $2, 0(%0)\n"
                                 "pextlb $2, $0, $2\n"
                                 "pextlh $2, $0, $2\n"
                                 "qmtc2.ni $2, $vf10\n"
                                 "vitof0.xyzw $vf10, $vf10\n"
                                 "mfc1 $2, %1\n"
                                 "nop\n"
                                 "qmtc2.ni $2, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 :
                                 : "r"(&particleColor), "f"(colorScale), "m"(particleColor)
                                 : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile("lqc2 $vf11, 0(%0)\n"
                                 "vmul.xyzw $vf10, $vf10, $vf11\n"
                                 :
                                 : "r"(parentColor), "m"(parentColor)
                                 : "$vf10", "$vf11", "memory");
                colorWord = 0x437F0000U;
                __asm__ volatile("qmtc2.ni %0, $vf2\n"
                                 "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                                 "vftoi0.xyzw $vf10, $vf10\n"
                                 "qmfc2.ni %0, $vf10\n"
                                 "ppach %0, $0, %0\n"
                                 "ppacb %0, $0, %0\n"
                                 "sw %0, packedColor\n"
                                 : "+r"(colorWord), "=m"(packedColor)
                                 :
                                 : "$vf2", "$vf10", "memory");
                func_004865c0((u8*)*(s32*)emitterOrObjects, packedColor);
                func_00485870(*(s32*)emitterOrObjects);
            }
            modelIndex++;
            record += 0x20;
            emitterOrObjects += sizeof(s32);
        }
    }
    break;
    case 7:
    {
        u8* t = *(u8**)(emitterOrObjects + 0x20);
        *(s32*)(*(u8**)(particle + 0x5C) + 0) = 0;
        *(s32*)(*(u8**)(particle + 0x5C) + 4) = 0;
        {
            u8* pb = (u8*)func_00481460(*(u16*)(t + 0x54));
            func_00460ac0(pb, *(u8**)(particle + 0x5C));
        }
    }
    break;
    default:
        func_0046d730(D_00713CD0, 0x41D);
        break;
    }
particle_render_done:
    return;
}
typedef struct ParticleProjectedColorBytes {
    u8 red, green, blue, alpha;
} ParticleProjectedColorBytes;
typedef union ParticleProjectedColor {
    u32 word;
    ParticleProjectedColorBytes bytes;
} ParticleProjectedColor;
typedef char ParticleProjectedColorSize[(sizeof(ParticleProjectedColor) == 4) ? 1 : -1];

/* Shared first-party views of the native vector and immediate vertex ABI. */
typedef BtlShuffleVec3 ParticleProjectedVec3;
typedef BtlShuffleSkyVertex ParticleProjectedVertex;
typedef struct TLP TLP;
typedef struct TlpSel {
    f32 a, b, w, h;
    void *tex;
} TlpSel;
typedef char ParticleProjectedVec3Size[(sizeof(ParticleProjectedVec3) == 12) ? 1 : -1];
typedef char ParticleProjectedVertexSize[(sizeof(ParticleProjectedVertex) == 64) ? 1 : -1];
typedef char ParticleProjectedSelectionSize[(sizeof(TlpSel) == 20) ? 1 : -1];

static inline u32 particleProjectedFrameIndex(const u8 *record)
{
    return *(const u32 *)(record + 0x10);
}

/* measured: b210 -O2, full unmasked 4236/4240-byte proof and four zero tail bytes.
 * Native vertex/selection fields and VU outputs preserve the retail memory order.
 * The transformed path reads its unsigned frame index through the accessor before
 * loading the texture resource; both the reload and argument order are significant.
 * Receipt: build/first-party-continue-live/particle/resume-20260922-closure/. */
// FUN_00488D70
void func_00488d70(u8 *arg0)
{
    extern s32 func_00457120(void);
    extern void func_004bceb0(void);
    extern void func_00482ad0(TLP *a, u32 b, TlpSel *c);
    extern BtlShuffleRenderStateSet D_00887300[];
    extern BtlShuffleRenderPrimitive D_00887310[];
    extern f32 func_0044b610(f32);
    extern f32 func_0044b7b0(f32);
    extern ParticleProjectedVec3 *func_003e42a0(ParticleProjectedVec3 *a, const ParticleProjectedVec3 *b, const BtlShuffleMatrix *c);
    extern void func_0046d730(void *a, s32 b);
    extern f32 fGpffff81f4;
    extern f32 D_008872F8[];
    extern f32 D_008872FC[];
    extern u8 D_00713CD0[];
    extern u8 D_00713D10[];
    typedef unsigned int u_long128 __attribute__((mode(TI)));
    ParticleProjectedVec3 tmpPos;
    ParticleProjectedVec3 tmpOut;
    f32 parent[4] __attribute__((aligned(16)));
    ParticleProjectedVertex qb[4];
    u32 snapB[4] __attribute__((aligned(16)));
    u32 snapA[4] __attribute__((aligned(16)));
    u8 base[64] __attribute__((aligned(16)));
    TlpSel outA0;
    u8 *temp_19;
    u8 *var_18;
    s32 temp_16;
    s32 i;
    f32 bufferFar;
    f32 bufferNear;
    f32 cameraNear;
    f32 cameraFar;
    ParticleProjectedColor packed;
    s32 w;
    s32 cw2;
    s32 cw3;
    u32 pk;
    u32 pk2;
    f32 colorScale;
    {
        w = *(s32 *)(arg0 + 4);
        __asm__ volatile(
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 $2, %1\n"
            "nop\n"
            "qmtc2.ni $2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            : : "r"(&w), "f"(colorScale = fGpffff81f4), "m"(w)
            : "$2", "$vf2", "$vf10", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%1)\n"
            : "=m"(parent) : "r"(parent) : "memory");
    }
    temp_19 = *(u8 **)(arg0 + 0x4C);
    var_18 = *(u8 **)(temp_19 + 0x18);
    bufferNear = D_008872FC[0];
    bufferFar = D_008872F8[0];
    cameraFar = *(f32 *)((u8 *)(u32)func_00457120() + 0x84);
    cameraNear = *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    temp_16 = *(s32 *)(temp_19 + 8);
    switch (*(u16 *)(arg0 + 0xC)) {
    case 7:
    if ((*(s32 *)(temp_19 + 0xC) & 1) == 0) {
        f32 reciprocalDepth;
        f32 projectedDepth;
        f32 planeSpan;
        i = 0;
        planeSpan = cameraNear - cameraFar;
        bufferFar = bufferFar - bufferNear;
        while (i < temp_16) {
            if (*(s32 *)(var_18 + 0x10) >= 0) {
                u32 work;
                cw2 = *(s32 *)(var_18 + 0x14);
                __asm__ volatile(
                    "lw $2, 0(%0)\n"
                    "pextlb $2, $0, $2\n"
                    "pextlh $2, $0, $2\n"
                    "qmtc2.ni $2, $vf10\n"
                    "vitof0.xyzw $vf10, $vf10\n"
                    "mfc1 $2, %1\n"
                    "nop\n"
                    "qmtc2.ni $2, $vf2\n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                    : : "r"(&cw2), "f"(colorScale), "m"(cw2)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)\n"
                    "vmul.xyzw $vf10, $vf10, $vf11\n"
                    : : "r"(parent), "m"(parent)
                    : "$vf10", "$vf11", "memory");
                work = 0x437F0000U;
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2\n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                    "vftoi0.xyzw $vf10, $vf10\n"
                    "qmfc2.ni %0, $vf10\n"
                    "ppach %0, $0, %0\n"
                    "ppacb %0, $0, %0\n"
                    "sw %0, pk\n"
                    : "+r"(work), "=m"(pk)
                    :
                    : "$vf2", "$vf10", "memory");
                packed.word = pk;
                if (packed.bytes.alpha != 0) {
                    f32 f29;
                    f32 f28;
                    func_00482ad0(*(TLP **)(arg0 + 0x48), (u32)*(s32 *)(var_18 + 0x10), &outA0);
                    D_00887300[0](rwRENDERSTATETEXTURERASTER, *(void **)outA0.tex);
                    f29 = *(f32 *)(var_18 + 0x18) * ((outA0.w / 32.0f) * outA0.a);
                    f28 = *(f32 *)(var_18 + 0x18) * ((outA0.h / 32.0f) * outA0.b);
                    qb[0].u.els.color.r = (f32)(u32)packed.bytes.red;
                    qb[0].u.els.color.g = (f32)(u32)packed.bytes.green;
                    qb[0].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    qb[0].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    qb[1].u.els.color.r = (f32)(u32)packed.bytes.red;
                    qb[1].u.els.color.g = (f32)(u32)packed.bytes.green;
                    qb[1].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    qb[1].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    qb[2].u.els.color.r = (f32)(u32)packed.bytes.red;
                    qb[2].u.els.color.g = (f32)(u32)packed.bytes.green;
                    qb[2].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    qb[2].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    qb[3].u.els.color.r = (f32)(u32)packed.bytes.red;
                    qb[3].u.els.color.g = (f32)(u32)packed.bytes.green;
                    qb[3].u.els.color.b = (f32)(u32)packed.bytes.blue;
                    qb[3].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                    tmpPos.x = *(f32 *)(var_18 + 0);
                    tmpPos.y = *(f32 *)(var_18 + 4);
                    tmpPos.z = *(f32 *)(var_18 + 8);
                    func_003e42a0(&tmpOut, &tmpPos, (const BtlShuffleMatrix *)((u8 *)(u32)func_00457120() + 0x20));
                    {
                        f32 ry = tmpOut.y / tmpOut.z;
                        f32 rx = tmpOut.x / tmpOut.z;
                        s32 bad;
                        if (rx < -2.0f || !(rx <= 2.0f) || ry < -2.0f || !(ry <= 2.0f)) {
                            bad = 1;
                        } else {
                            bad = 0;
                        }
                        if (bad == 0) {
                            f32 a0;
                            f32 a1;
                            f32 b0;
                            f32 b1;
                            projectedDepth = (cameraNear / tmpOut.z) * ((tmpOut.z - cameraFar) * (bufferFar / planeSpan)) + (bufferNear + 0.0f);
                            if (projectedDepth < 0.0f) {
                                projectedDepth = 0.0f;
                            }
                            reciprocalDepth = 1.0f / projectedDepth;
                            a0 = func_0044b610(*(f32 *)(var_18 + 0x1C));
                            a1 = func_0044b7b0(*(f32 *)(var_18 + 0x1C));
                            b0 = f29 * a0;
                            b1 = f28 * a0;
                            f29 = f29 * a1;
                            f28 = f28 * a1;
                            qb[0].u.els.u = 0.0f; qb[0].u.els.v = 0.0f;
                            qb[1].u.els.u = 1.0f; qb[1].u.els.v = 0.0f;
                            qb[2].u.els.u = 0.0f; qb[2].u.els.v = 1.0f;
                            qb[3].u.els.u = 1.0f; qb[3].u.els.v = 1.0f;
                            {
                                qb[0].u.els.scrVertex.x = 640.0f * ((tmpOut.x + (-b0 + f28)) / tmpOut.z);
                                qb[0].u.els.scrVertex.y = 448.0f * ((tmpOut.y - (-f29 - b1)) / tmpOut.z);
                                qb[0].u.els.scrVertex.z = projectedDepth;
                                qb[0].u.els.recipZ = reciprocalDepth;
                                qb[1].u.els.scrVertex.x = 640.0f * ((tmpOut.x + (b0 + f28)) / tmpOut.z);
                                qb[1].u.els.scrVertex.y = 448.0f * ((tmpOut.y - (f29 - b1)) / tmpOut.z);
                                qb[1].u.els.scrVertex.z = projectedDepth;
                                qb[1].u.els.recipZ = reciprocalDepth;
                                qb[2].u.els.scrVertex.x = 640.0f * ((tmpOut.x + (-b0 - f28)) / tmpOut.z);
                                qb[2].u.els.scrVertex.y = 448.0f * ((tmpOut.y - (-f29 + b1)) / tmpOut.z);
                                qb[2].u.els.scrVertex.z = projectedDepth;
                                qb[2].u.els.recipZ = reciprocalDepth;
                                qb[3].u.els.scrVertex.x = 640.0f * ((tmpOut.x + (b0 - f28)) / tmpOut.z);
                                qb[3].u.els.scrVertex.y = 448.0f * ((tmpOut.y - (f29 + b1)) / tmpOut.z);
                                qb[3].u.els.scrVertex.z = projectedDepth;
                                qb[3].u.els.recipZ = reciprocalDepth;
                            }
                            D_00887310[0](rwPRIMTYPETRISTRIP, qb, 4);
                        }
                    }
                }
            }
            i++;
            var_18 += 0x20;
        }
    } else {
        f32 full;
        f32 scale32;
        f32 neg2;
        f32 pos2;
        f32 zero;
        f32 one;
        f32 s640;
        f32 s448;
        func_00492df0((s32)temp_19, snapA);
        func_00492db0((s32)temp_19, snapB);
        __asm__ volatile("lqc2 $vf10, 0(%0)\n" : : "r"(snapA) : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile("lqc2 $vf31, 0(%0)\n" : : "r"(snapB) : "$vf31", "memory");
        __asm__ volatile("sqc2 $vf28, 0(%0)\nsqc2 $vf29, 16(%0)\nsqc2 $vf30, 32(%0)\nsqc2 $vf31, 48(%0)\n" : : "r"(base) : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
        i = 0;
        full = 255.0f;
        scale32 = 32.0f;
        neg2 = -2.0f;
        pos2 = 2.0f;
        zero = 0.0f;
        one = 1.0f;
        s640 = 640.0f;
        s448 = 448.0f;
        while (i < temp_16) {
            if (*(s32 *)(var_18 + 0x10) >= 0) {
                __asm__ volatile("lqc2 $vf28, 0(%0)\nlqc2 $vf29, 16(%0)\nlqc2 $vf30, 32(%0)\nlqc2 $vf31, 48(%0)\nlqc2 $vf10, 0(%1)\nvmulax.xyzw $ACC, $vf28, $vf10x\nvmadday.xyzw $ACC, $vf29, $vf10y\nvmaddaz.xyzw $ACC, $vf30, $vf10z\nvmaddw.xyzw $vf10, $vf31, $vf0w\n" : : "r"(base), "r"(var_18) : "$vf28", "$vf29", "$vf30", "$vf31", "$vf10", "ACC", "memory");
                __asm__ volatile("sqc2 $vf10, 0(%1)\n" : "=m"(*(ParticleSnapshot *)D_00713D10) : "r"(D_00713D10) : "$vf10", "memory");
                tmpPos.x = *(f32 *)(D_00713D10 + 0);
                tmpPos.y = *(f32 *)(D_00713D10 + 4);
                tmpPos.z = *(f32 *)(D_00713D10 + 8);
                {
                    u32 work;
                    cw3 = *(s32 *)(var_18 + 0x14);
                    __asm__ volatile(
                        "lw $2, 0(%0)\n"
                        "pextlb $2, $0, $2\n"
                        "pextlh $2, $0, $2\n"
                        "qmtc2.ni $2, $vf10\n"
                        "vitof0.xyzw $vf10, $vf10\n"
                        "mfc1 $2, %1\n"
                        "nop\n"
                        "qmtc2.ni $2, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        : : "r"(&cw3), "f"(colorScale), "m"(cw3)
                        : "$2", "$vf2", "$vf10", "memory");
                    __asm__ volatile(
                        "lqc2 $vf11, 0(%0)\n"
                        "vmul.xyzw $vf10, $vf10, $vf11\n"
                        : : "r"(parent), "m"(parent)
                        : "$vf10", "$vf11", "memory");
                    __asm__ volatile(
                        "mfc1 %0, %2\n"
                        "nop\n"
                        "qmtc2.ni %0, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "vftoi0.xyzw $vf10, $vf10\n"
                        "qmfc2.ni %0, $vf10\n"
                        "ppach %0, $0, %0\n"
                        "ppacb %0, $0, %0\n"
                        "sw %0, pk2\n"
                        : "=&r"(work), "=m"(pk2)
                        : "f"(full)
                        : "$vf2", "$vf10", "memory");
                    packed.word = pk2;
                    if (packed.bytes.alpha != 0) {
                        f32 g0;
                        f32 g1;
                        u32 frameIndex;

                        frameIndex = particleProjectedFrameIndex(var_18);
                        func_00482ad0(*(TLP **)(arg0 + 0x48), frameIndex, &outA0);
                        D_00887300[0](rwRENDERSTATETEXTURERASTER, *(void **)outA0.tex);
                        {
                            f32 particleScale = *(f32 *)(var_18 + 0x18);
                            f32 dimension = outA0.w / scale32;
                            dimension = dimension * outA0.a;
                            g0 = particleScale * dimension;
                            dimension = outA0.h / scale32;
                            dimension = dimension * outA0.b;
                            g1 = particleScale * dimension;
                        }
                        qb[0].u.els.color.r = (f32)(u32)packed.bytes.red;
                        qb[0].u.els.color.g = (f32)(u32)packed.bytes.green;
                        qb[0].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        qb[0].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        qb[1].u.els.color.r = (f32)(u32)packed.bytes.red;
                        qb[1].u.els.color.g = (f32)(u32)packed.bytes.green;
                        qb[1].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        qb[1].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        qb[2].u.els.color.r = (f32)(u32)packed.bytes.red;
                        qb[2].u.els.color.g = (f32)(u32)packed.bytes.green;
                        qb[2].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        qb[2].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        qb[3].u.els.color.r = (f32)(u32)packed.bytes.red;
                        qb[3].u.els.color.g = (f32)(u32)packed.bytes.green;
                        qb[3].u.els.color.b = (f32)(u32)packed.bytes.blue;
                        qb[3].u.els.color.a = (f32)(u32)packed.bytes.alpha;
                        func_003e42a0(&tmpOut, &tmpPos, (const BtlShuffleMatrix *)((u8 *)(u32)func_00457120() + 0x20));
                        {
                            f32 ry2 = tmpOut.y / tmpOut.z;
                            f32 rx2 = tmpOut.x / tmpOut.z;
                            s32 bad2;
                            if (rx2 < neg2 || !(rx2 <= pos2) || ry2 < neg2 || !(ry2 <= pos2)) {
                                bad2 = 1;
                            } else {
                                bad2 = 0;
                            }
                            if (bad2 == 0) {
                                f32 f10;
                                f32 inv2;
                                f32 e0;
                                f32 e1;
                                f32 f0b;
                                f32 f1b;
                                f10 = (cameraNear / tmpOut.z) * ((tmpOut.z - cameraFar) * ((bufferFar - bufferNear) / (cameraNear - cameraFar))) + (bufferNear + 0.0f);
                                if (f10 < zero) {
                                    f10 = zero;
                                }
                                inv2 = one / f10;
                                e0 = func_0044b610(*(f32 *)(var_18 + 0x1C));
                                e1 = func_0044b7b0(*(f32 *)(var_18 + 0x1C));
                                f0b = g0 * e0;
                                f1b = g1 * e0;
                                g0 = g0 * e1;
                                g1 = g1 * e1;
                                qb[0].u.els.u = zero; qb[0].u.els.v = zero;
                                qb[1].u.els.u = one; qb[1].u.els.v = zero;
                                qb[2].u.els.u = zero; qb[2].u.els.v = one;
                                qb[3].u.els.u = one; qb[3].u.els.v = one;
                                {
                                    qb[0].u.els.scrVertex.x = s640 * ((tmpOut.x + (-f0b + g1)) / tmpOut.z);
                                    qb[0].u.els.scrVertex.y = s448 * ((tmpOut.y - (-g0 - f1b)) / tmpOut.z);
                                    qb[0].u.els.scrVertex.z = f10;
                                    qb[0].u.els.recipZ = inv2;
                                    qb[1].u.els.scrVertex.x = s640 * ((tmpOut.x + (f0b + g1)) / tmpOut.z);
                                    qb[1].u.els.scrVertex.y = s448 * ((tmpOut.y - (g0 - f1b)) / tmpOut.z);
                                    qb[1].u.els.scrVertex.z = f10;
                                    qb[1].u.els.recipZ = inv2;
                                    qb[2].u.els.scrVertex.x = s640 * ((tmpOut.x + (-f0b - g1)) / tmpOut.z);
                                    qb[2].u.els.scrVertex.y = s448 * ((tmpOut.y - (-g0 + f1b)) / tmpOut.z);
                                    qb[2].u.els.scrVertex.z = f10;
                                    qb[2].u.els.recipZ = inv2;
                                    qb[3].u.els.scrVertex.x = s640 * ((tmpOut.x + (f0b - g1)) / tmpOut.z);
                                    qb[3].u.els.scrVertex.y = s448 * ((tmpOut.y - (g0 + f1b)) / tmpOut.z);
                                    qb[3].u.els.scrVertex.z = f10;
                                    qb[3].u.els.recipZ = inv2;
                                }
                                D_00887310[0](rwPRIMTYPETRISTRIP, qb, 4);
                            }
                        }
                    }
                }
            }
            i++;
            var_18 += 0x20;
        }
    }
    break;
    default:
        func_0046d730(D_00713CD0, 0x4F3);
        break;
    }
    D_00887300[0](rwRENDERSTATETEXTURERASTER, 0);
}
