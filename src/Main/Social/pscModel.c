/* Consolidated Persona 4 source units. */
/* Original translation unit pscModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern f32 D_00761480;
extern f32 D_00761484;

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} PscVec;

typedef struct
{
    /* 0x00 */ PscVec dir;
    /* 0x0C */ u8 c[4];
    /* 0x10 */ PscVec unused;
    /* 0x1C */ f32 f1c;
    /* 0x20 */ f32 f20;
} PscLight;

extern void* func_00457120(void);
extern void func_0046d730(u8 *file, s32 line);
extern u8 D_0064E480[];
extern u16 D_00884690[];
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);

// FUN_003694D0
INCLUDE_ASM("asm/nonmatchings/pscModel", func_003694d0);




// FUN_0036A6B0
void func_0036a6b0(s32 unused, const f32* source, f32 scale, void* viewport)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;
    f32* out = viewport;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    out[0] = panelScale * (camera[0] * (1.0f + (-source[0] / (f32)(size[0] >> 1))));
    out[1] = panelScale * (camera[1] * (1.0f + (-source[1] / (f32)(size[1] >> 1))));
    out[2] = panelScale;
}



// FUN_0036A790
f32 func_0036a790(const f32* value, f32 scale)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    return (6.0f * value[11] * (f32)(size[0] >> 1)) / (panelScale * camera[0]);
}

// FUN_0036A820
void func_0036a820(u8 *arg0, s16 arg1)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        func_0046d730(D_0064E480, 0x524);
    }
    *(u16 *)(arg0 + 0x174) = arg1;
}

// FUN_0036A880
void func_0036a880(u8 *arg0, s32 arg1, s32 arg2)
{
    if (*(s32 *)(arg0 + 4) != 1) {
        func_0046d730(D_0064E480, 0x52F);
    }
    *(s32 *)(arg0 + 0x170) = arg1;
    *(s32 *)(arg0 + 0x174) = arg2;
}
// FUN_0036A900
void func_0036a900(PscLight *dst)
{
    PscVec v0;
    PscVec v1;
    PscVec v2;
    PscVec v3;

    v0.x = 3.0f;
    v0.y = D_00761480;
    v0.z = 0.0f;
    dst[0].dir = v0;
    v1.x = 3.0f;
    v1.y = D_00761484;
    v1.z = 0.0f;
    dst[1].dir = v1;
    v2.x = -3.0f;
    v2.y = D_00761484;
    v2.z = 0.0f;
    dst[2].dir = v2;
    v3.x = -3.0f;
    v3.y = D_00761480;
    v3.z = 0.0f;
    dst[3].dir = v3;
    dst[0].c[0] = 255;
    dst[0].c[1] = 255;
    dst[0].c[2] = 255;
    dst[0].c[3] = 255;
    dst[1].c[0] = 255;
    dst[1].c[1] = 255;
    dst[1].c[2] = 255;
    dst[1].c[3] = 255;
    dst[2].c[0] = 255;
    dst[2].c[1] = 255;
    dst[2].c[2] = 255;
    dst[2].c[3] = 255;
    dst[3].c[0] = 255;
    dst[3].c[1] = 255;
    dst[3].c[2] = 255;
    dst[3].c[3] = 255;
    dst[0].f1c = 0.9921875f;
    dst[1].f1c = 0.9921875f;
    dst[2].f1c = 0.0f;
    dst[3].f1c = 0.0f;
    dst[0].f20 = 0.0f;
    dst[1].f20 = 0.64453125f;
    dst[2].f20 = 0.64453125f;
    dst[3].f20 = 0.0f;
}
// FUN_0036AA20
void func_0036aa20(void)
{
    u16 *p;
    s32 v;
    s32 t1, t2;
    s32 col;
    s32 row;
    s32 parity;
    s32 i;

    v = 0;
    p = D_00884690;
    for (row = 0; row < 8; row++) {
        col = 0;
        parity = ~row & 1;
        for (; col < 6; col++) {
            if (parity != 0) {
                p[0] = v;
                t1 = v + 1;
                p[1] = t1;
                t2 = v + 8;
                p[2] = t2;
                p[3] = t1;
                p[4] = v + 9;
                p[5] = t2;
                p += 6;
                v = t1;
            } else {
                p[0] = v;
                t2 = v + 8;
                p[1] = t2;
                p[2] = v + 7;
                p[3] = v;
                v = v + 1;
                p[4] = v;
                p[5] = t2;
                p += 6;
            }
        }
        if (parity != 0) {
            p[0] = v;
            p[1] = v + 1;
            p[2] = v + 8;
            p += 3;
            v = v + 2;
        } else {
            p[0] = v;
            p[1] = v + 8;
            p[2] = v + 7;
            p += 3;
            v = v + 1;
        }
    }
    for (i = 0; i < 0x138; i++) {
        if (D_00884690[i] >= 0x44) {
            func_0046d730(D_0064E480, 0x5C8);
        }
    }
    if ((p - D_00884690) != 0x138) {
        func_0046d730(D_0064E480, 0x5CA);
    }
}
