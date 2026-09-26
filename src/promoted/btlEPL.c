#include "btl_motion_internal.h"
#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlEPL.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

extern void func_004abd60(s32 arg0);
extern void (*jtbl_008873EC[])(void *);

extern void func_0044ea90(u8 *file, s32 line);
extern s32 func_004abc50(s32 arg0, s32 arg1);
extern s32 func_004abd80(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00625230[];

static u8 *D_0072449C;

extern void func_00194ff0(void *arg0, void *arg1, void *arg2, void *arg3);
extern void btlUnitSetPos(void *arg0, void *arg1);
extern void btlUnitSetRot(void *arg0, void *arg1);
extern void func_0048a150(void *arg0, void *arg1);
extern void func_0047a1c0(void *arg0, void *arg1, s32 arg2);
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern RwMatrix *func_0047a180(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void func_0047a0e0(void *arg0, s32 arg1, f32 arg2);
extern void func_00478e70(void *arg0);
extern s32 func_0047a510(void *arg0, s32 arg1, void *arg2);
extern void RwMatrixScale(void *arg0, f32 *arg1, s32 arg2);
extern void RwMatrixMultiply(void *arg0, void *arg1, void *arg2);
extern void RtQuatConvertFromMatrix(void *arg0, void *arg1);
extern void func_001ec350(void *arg0, void *arg1);
extern u32 func_0047a7c0(u32 arg0);
extern u32 effMiscRand(s32 arg0);
extern void func_0019d990(void *arg0, s32 arg1);
extern void func_00199890(void *arg0, s32 arg1);
extern void func_0019d7a0(void *arg0, s32 arg1);
extern s32 func_00243d80(s32 arg0);
extern s32 datCalcIsDead(u32 arg0, u32 arg1);
extern s32 func_0047a6d0(void *arg0, s32 arg1, void *arg2);
extern u8 *func_001b7020(void);
extern u8 *func_001b7030(void);
extern u8 *func_001b7040(void);
extern u8 *func_001b7050(void);
extern void func_001496c0(void *arg0);
extern u8 *func_00149ca0(void);
extern u8 *func_00149ce0(void);
extern f32 D_0076129C;
extern f32 D_00922CA0[];
extern s32 D_00922CC0[];
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct
{
    f32 v[4];
} V4;

typedef struct BtlEplEplWork
{
    s32 target;   // 0x00
    s16 pattern;  // 0x04
} BtlEplEplWork; // 0x08

typedef struct BtlEplColor
{
    u8 r; // 0x00
    u8 g; // 0x01
    u8 b; // 0x02
    u8 a; // 0x03
} BtlEplColor; // 0x04

typedef union BtlEplRgba
{
    u32 rgba;
    BtlEplColor c;
} BtlEplRgba; // 0x04

extern BtlEplColor D_007641F8;
extern BtlEplColor D_00764C54;

typedef struct BtlEplFadeParam
{
    u32 total;        // 0x00
    u16 fadeIn;       // 0x04
    u16 fadeOut;      // 0x06
    BtlEplRgba color; // 0x08
} BtlEplFadeParam;

static inline void btlEplRgbaToV4(V4 *out, const BtlEplColor *rgba)
{
    out->v[0] = (1.0f / 255.0f) * (f32)(u32)rgba->r;
    out->v[1] = (1.0f / 255.0f) * (f32)(u32)rgba->g;
    out->v[2] = (1.0f / 255.0f) * (f32)(u32)rgba->b;
    out->v[3] = (1.0f / 255.0f) * (f32)(u32)rgba->a;
}





/* measured: opt_loop_invariants on keeps the table base and the constant 1 hoisted above the
   scan loop as retail; the mode-1 blocks are `var = 1; if (slot == arg0) { t = var; } else
   { var = 0; t = var; } return (s8)t;` - the copy at the join keeps the then-branch as
   retail's `b join` trampoline (the plain if/else folds to xor/sltiu under rebuildconditionals,
   which must stay off for these two blocks). */
// FUN_001FC300
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
static s64 func_001fc300(u8 *arg0, u8 *arg1)
{
    extern s32 D_00881440_abs[];
    u8 *table;
    s32 temp_8;
    s32 var_10;
    s32 one;
    s64 var_2;
    s64 t;
    s64 var_2_2;
    u32 temp_6;
    u8 temp_3;
    u8 temp_3_2;

    if (*(u8 *)(arg1 + 3) != 0) {
        return 1;
    }
    var_10 = 0;
    table = (u8 *)D_00881440_abs;
    one = 1;
    goto loop_test;
loop_body:
    temp_8 = *(s32 *)(table + ((u16)var_10 * 4) + 8);
    if (temp_8 != 0) {
        if ((*(u8 *)(arg1 + 2) & (one << temp_6)) &&
            ((u8 *)temp_8 == arg0)) {
            return 1;
        }
        var_10 = (var_10 + 1) & 0xFFFF;
        goto loop_test;
    }
    goto block_9;
loop_test:
    temp_6 = var_10 & 0xFFFF;
    if (temp_6 < 3U) {
        goto loop_body;
    }
block_9:
    if ((D_00881440_abs[0] != 0) &&
        (*(u8 *)(arg0 + 0xA2) ==
         *(u8 *)(D_00881440_abs[0] + 0xA2))) {
        temp_3 = *(u8 *)(arg1 + 0);
        switch (temp_3) {
        case 0:
            return 0;
        case 1:
            var_2_2 = 1;
            if (D_00881440_abs[0] == (s32)arg0) {
                t = var_2_2;
            } else {
                var_2_2 = 0;
                t = var_2_2;
            }
            return (s64)(t << 0x38) >> 0x38;
        case 2:
            return 1;
        }
    }
    if ((D_00881440_abs[1] != 0) &&
        (*(u8 *)(arg0 + 0xA2) ==
         *(u8 *)(D_00881440_abs[1] + 0xA2))) {
        temp_3_2 = *(u8 *)(arg1 + 1);
        switch (temp_3_2) {
        case 0:
            return 0;
        case 1:
            var_2 = 1;
            if (D_00881440_abs[1] == (s32)arg0) {
                t = var_2;
            } else {
                var_2 = 0;
                t = var_2;
            }
            return (s64)(t << 0x38) >> 0x38;
        case 2:
            return 1;
        }
    }
    return 0;
}
/* measured: restore rebuildconditionals after func_001fc300. */
#pragma opt_rebuildconditionals on
/* measured: restore the unit default after func_001fc300. */
#pragma opt_loop_invariants off
// FUN_001FC4A0
s32 *func_001fc4a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *result;

    func_0044ea90(D_00625230, 0xB1);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        *result = func_004abc50(arg2, arg3);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_001FC550
s32 *func_001fc550(u8 *arg0) {
    s32 *field;
    s32 *result;
    s32 value;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0xB1);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    value = *field;
    if (value != 0) {
        *result = func_004abd80(value);
    } else {
        *result = 0;
    }
    return result;
}
// FUN_001FC5E0
void func_001fc5e0(s32 *arg0) {
    if (*arg0 != 0) {
        func_004abd60(*arg0);
    }
    jtbl_008873EC[0](arg0);
}



typedef struct BtlEplUnitParam
{
    u8 select[4];          // 0x00, read by func_001fc300
    u8 pad04[8];           // 0x04
    BtlEplFadeParam fade;  // 0x0C
    f32 rotate;            // 0x18
    f32 scale;             // 0x1C
} BtlEplUnitParam;

typedef struct BtlEplV3
{
    f32 x;
    f32 y;
    f32 z;
} BtlEplV3;

typedef struct BtlEplUnit
{
    u8 pad00[0x38];
    BtlEplColor startRgba;   // 0x38
    BtlEplColor rgba;        // 0x3C
    u8 pad40[0x14];
    BtlEplV3 pos;            // 0x54
    V4 startColor;           // 0x60
    V4 color;                // 0x70
    u8 pad80[0x18];
    u32 flags;               // 0x98
    u8 pad9C[0x9D0];
    struct BtlEplUnit *next; // 0xA6C
} BtlEplUnit;

/* measured: opt_dead_assignments off keeps the four colour conversions ahead of
   the blend products (217 words without it); opt_loop_invariants on hoists the
   mode byte and 1 - scale above the unit loop in retail order. */
// FUN_001FC630
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void func_001fc630(u8 *arg0)
{
    u32 count;
    BtlEplUnitParam *param;
    u8 **model;
    u32 total;
    u8 mode;
    f32 scale;
    s32 hasPos;
    u32 i;
    BtlEplUnit *node;
    BtlEplRgba rgba;
    BtlEplV3 pos;
    f32 vec[3];
    u8 matrix[0x40];

    model = *(u8 ***)(arg0 + 0x30);
    param = *(BtlEplUnitParam **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    total = param->fade.total;
    if (total < count && total != 0) {
        return;
    }
    mode = 0;
    if (total != 0) {
        if (count <= param->fade.fadeIn) {
            if (param->fade.fadeIn > 0) {
                scale = (f32)count / (f32)param->fade.fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fade.fadeOut) {
            if (param->fade.fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fade.fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    hasPos = 0;
    if (*model != NULL) {
        func_0048a150(matrix, arg0 + 0x10);
        func_0047a1c0(*model, matrix, 0);
        vec[0] = vec[1] = vec[2] = *(f32 *)(arg0 + 0x20) * param->scale;
        mdlScale(*model, vec, 2);
        vec[0] = ((f32 *)arg0)[0];
        vec[1] = ((f32 *)arg0)[1];
        vec[2] = ((f32 *)arg0)[2];
        func_0047a180((RwMatrix *)*model, (const RwV3d *)vec, 2);
        func_0047a0e0(*model, 0, param->rotate);
        func_00478e70(*model);
        if (func_0047a6d0(*model, 0, &pos) != 0) {
            hasPos = 1;
        }
    }
    {

        for (i = 0; i < 4; i++) {
            for (node = *(BtlEplUnit **)(D_0072449C + i * 8 + 0x178); node != NULL; node = node->next) {
                if (func_001fc300((u8 *)node, param->select) == 0) {
                    continue;
                }
                switch (mode) {
                case 0:
                    if (count == 0) {
                        rgba.rgba = param->fade.color.rgba;
                        btlEplRgbaToV4(&node->color, &rgba.c);
                    }
                    break;
                case 1:
                    if (count == 0) {
                        node->startColor = node->color;
                    }
                    rgba.rgba = param->fade.color.rgba;
                    {
                        V4 color;
                        f32 a0, a1, a2, a3;
                        f32 b0, b1, b2, b3;

                        btlEplRgbaToV4(&color, &rgba.c);
                        a0 = node->startColor.v[0] * (1.0f - scale);
                        a1 = node->startColor.v[1] * (1.0f - scale);
                        a2 = node->startColor.v[2] * (1.0f - scale);
                        a3 = node->startColor.v[3] * (1.0f - scale);
                        b0 = color.v[0] * scale;
                        b1 = color.v[1] * scale;
                        b2 = color.v[2] * scale;
                        b3 = color.v[3];
                        node->color.v[0] = a0 + b0;
                        node->color.v[1] = a1 + b1;
                        node->color.v[2] = a2 + b2;
                        node->color.v[3] = a3 + b3 * scale;
                    }
                    break;
                case 2:
                    if (count == total - param->fade.fadeOut) {
                        node->startColor = node->color;
                    }
                    {
                        V4 color;
                        f32 a0, a1, a2, a3;
                        f32 b0, b1, b2, b3;

                        btlEplRgbaToV4(&color, &D_00764C54);
                        a0 = color.v[0] * (1.0f - scale);
                        a1 = color.v[1] * (1.0f - scale);
                        a2 = color.v[2] * (1.0f - scale);
                        a3 = color.v[3] * (1.0f - scale);
                        b0 = node->startColor.v[0] * scale;
                        b1 = node->startColor.v[1] * scale;
                        b2 = node->startColor.v[2] * scale;
                        b3 = node->startColor.v[3];
                        node->color.v[0] = a0 + b0;
                        node->color.v[1] = a1 + b1;
                        node->color.v[2] = a2 + b2;
                        node->color.v[3] = a3 + b3 * scale;
                    }
                    break;
                }
                if (hasPos) {
                    node->pos = pos;
                } else {
                    node->pos.x = ((f32 *)arg0)[0];
                    node->pos.y = ((f32 *)arg0)[1];
                    node->pos.z = ((f32 *)arg0)[2];
                }
            }
        }
    }
}
#pragma opt_dead_assignments on
#pragma opt_loop_invariants off

// FUN_001FCE30
void func_001fce30(void) {
    func_0044ea90(D_00625230, 0x1D3);
    (*jtbl_008873E8)(0x20, 0x40000);
}

// FUN_001FCE80
void func_001fce80(void *arg0) {
    jtbl_008873EC[0](arg0);
}

typedef struct BtlEplFade2Param
{
    u32 total;          // 0x00
    u16 fadeIn;         // 0x04
    u16 fadeOut;        // 0x06
    BtlEplRgba color[2]; // 0x08
} BtlEplFade2Param;

/* measured: opt_dead_assignments off keeps the colour conversions where the
   source puts them (first pair converted up front, second pair converted and
   scaled per component); 189 words without it. */
// FUN_001FCEB0
#pragma opt_dead_assignments off
void func_001fceb0(u8 *arg0)
{
    u32 count;
    BtlEplFade2Param *param;
    V4 *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *dst;
    V4 *src;
    BtlEplRgba rgba;

    target = *(V4 **)(arg0 + 0x30);
    param = *(BtlEplFade2Param **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    dst = (V4 *)func_001b7030();
    src = (V4 *)func_001b7040();
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    switch (mode) {
    case 0:
        if (count != 0) {
            return;
        }
        rgba.rgba = param->color[0].rgba;
        btlEplRgbaToV4(&dst[0], &rgba.c);
        rgba.rgba = param->color[1].rgba;
        btlEplRgbaToV4(&dst[1], &rgba.c);
        break;
    case 1:
        if (count == 0) {
            target[0] = dst[0];
            target[1] = dst[1];
        }
        {
            V4 color;
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            rgba.rgba = param->color[0].rgba;
            btlEplRgbaToV4(&color, &rgba.c);
            inv = 1.0f - scale;
            a0 = target[0].v[0] * inv;
            a1 = target[0].v[1] * inv;
            a2 = target[0].v[2] * inv;
            a3 = target[0].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            dst[0].v[0] = a0 + b0;
            dst[0].v[1] = a1 + b1;
            dst[0].v[2] = a2 + b2;
            dst[0].v[3] = a3 + b3 * scale;

            rgba.rgba = param->color[1].rgba;
            a0 = target[1].v[0] * inv;
            a1 = target[1].v[1] * inv;
            a2 = target[1].v[2] * inv;
            a3 = target[1].v[3] * inv;
            b0 = (1.0f / 255.0f) * (f32)(u32)rgba.c.r * scale;
            b1 = (1.0f / 255.0f) * (f32)(u32)rgba.c.g * scale;
            b2 = (1.0f / 255.0f) * (f32)(u32)rgba.c.b * scale;
            b3 = (1.0f / 255.0f) * (f32)(u32)rgba.c.a * scale;
            a0 += b0;
            dst[1].v[0] = a0;
            a1 += b1;
            dst[1].v[1] = a1;
            a2 += b2;
            dst[1].v[2] = a2;
            a3 += b3;
            dst[1].v[3] = a3;
        }
        break;
    case 2:
        if (count == total - param->fadeOut) {
            target[0] = dst[0];
            target[1] = dst[1];
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            inv = 1.0f - scale;
            a0 = src[0].v[0] * inv;
            a1 = src[0].v[1] * inv;
            a2 = src[0].v[2] * inv;
            a3 = src[0].v[3] * inv;
            b0 = target[0].v[0] * scale;
            b1 = target[0].v[1] * scale;
            b2 = target[0].v[2] * scale;
            b3 = target[0].v[3];
            dst[0].v[0] = a0 + b0;
            dst[0].v[1] = a1 + b1;
            dst[0].v[2] = a2 + b2;
            dst[0].v[3] = a3 + b3 * scale;
            a0 = src[1].v[0] * inv;
            a1 = src[1].v[1] * inv;
            a2 = src[1].v[2] * inv;
            a3 = src[1].v[3] * inv;
            b0 = target[1].v[0] * scale;
            b1 = target[1].v[1] * scale;
            b2 = target[1].v[2] * scale;
            b3 = target[1].v[3];
            dst[1].v[0] = a0 + b0;
            dst[1].v[1] = a1 + b1;
            dst[1].v[2] = a2 + b2;
            dst[1].v[3] = a3 + b3 * scale;
        }
        break;
    }
}
#pragma opt_dead_assignments on
// FUN_001FD780
void func_001fd780(void)
{
}

typedef struct BtlEplUnitRgbaParam
{
    BtlEplFadeParam fade; // 0x00
    u8 select[4];         // 0x0C, read by func_001fc300
} BtlEplUnitRgbaParam;

/* measured: fresh rewrite on the btlEPL family shape, 96 words (obj 2172B, window 2176B);
   residual is FP colouring only (retail inv = 1 - scale in $f2, here $f4). See
   docs/probe_archive/BtlEpl_001fd790_20260926_body.c for what was tried. */
// FUN_001FD790 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void func_001fd790(u8 *arg0)
{
    u32 count;
    BtlEplUnitRgbaParam *param;
    u32 total;
    u8 mode;
    f32 scale;
    u32 i;
    BtlEplUnit *node;
    BtlEplRgba rgba;

    param = *(BtlEplUnitRgbaParam **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    total = param->fade.total;
    if (total < count && total != 0) {
        return;
    }
    mode = 0;
    if (total != 0) {
        if (count <= param->fade.fadeIn) {
            if (param->fade.fadeIn > 0) {
                scale = (f32)count / (f32)param->fade.fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fade.fadeOut) {
            if (param->fade.fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fade.fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        f32 inv = 1.0f - scale;

        for (node = *(BtlEplUnit **)(D_0072449C + i * 8 + 0x178); node != NULL; node = node->next) {
            if (func_001fc300((u8 *)node, param->select) == 0) {
                continue;
            }
            node->flags |= 4;
            switch (mode) {
            case 0:
                if (count == 0) {
                    rgba.rgba = param->fade.color.rgba;
                    node->rgba = rgba.c;
                }
                break;
            case 1:
                if (count == 0) {
                    node->startRgba = node->rgba;
                }
                rgba.rgba = param->fade.color.rgba;
                {
                    V4 color;
                    V4 start;
                    f32 a0, a1, a2, a3;
                    f32 b0, b1, b2, b3;

                    btlEplRgbaToV4(&color, &rgba.c);
                    btlEplRgbaToV4(&start, &node->startRgba);
                    a0 = start.v[0] * inv;
                    a1 = start.v[1] * inv;
                    a2 = start.v[2] * inv;
                    a3 = start.v[3] * inv;
                    b0 = color.v[0] * scale;
                    b1 = color.v[1] * scale;
                    b2 = color.v[2] * scale;
                    b3 = color.v[3];
                    color.v[0] = a0 + b0;
                    color.v[1] = a1 + b1;
                    color.v[2] = a2 + b2;
                    color.v[3] = a3 + b3 * scale;
                    node->rgba.r = (s32)(0.5f + 255.0f * color.v[0]);
                    node->rgba.g = (s32)(0.5f + 255.0f * color.v[1]);
                    node->rgba.b = (s32)(0.5f + 255.0f * color.v[2]);
                    node->rgba.a = (s32)(0.5f + 255.0f * color.v[3]);
                }
                break;
            case 2:
                if (count == total - param->fade.fadeOut) {
                    node->startRgba = node->rgba;
                }
                {
                    V4 color;
                    V4 start;
                    f32 a0, a1, a2, a3;
                    f32 b0, b1, b2, b3;

                    btlEplRgbaToV4(&color, &D_007641F8);
                    btlEplRgbaToV4(&start, &node->startRgba);
                    a0 = color.v[0] * inv;
                    a1 = color.v[1] * inv;
                    a2 = color.v[2] * inv;
                    a3 = color.v[3] * inv;
                    b0 = start.v[0] * scale;
                    b1 = start.v[1] * scale;
                    b2 = start.v[2] * scale;
                    b3 = start.v[3];
                    color.v[0] = a0 + b0;
                    color.v[1] = a1 + b1;
                    color.v[2] = a2 + b2;
                    color.v[3] = a3 + b3 * scale;
                    node->rgba.r = (s32)(0.5f + 255.0f * color.v[0]);
                    node->rgba.g = (s32)(0.5f + 255.0f * color.v[1]);
                    node->rgba.b = (s32)(0.5f + 255.0f * color.v[2]);
                    node->rgba.a = (s32)(0.5f + 255.0f * color.v[3]);
                }
                break;
            }
        }
    }
}
#pragma opt_dead_assignments on
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/btlEPL", func_001fd790);
#endif

// FUN_001FE010
void func_001fe010(void) {
    func_0044ea90(D_00625230, 0x2DF);
    (*jtbl_008873E8)(0x20, 0x40000);
}

// FUN_001FE060
void func_001fe060(void *arg0) {
    jtbl_008873EC[0](arg0);
}

/* measured: opt_dead_assignments off keeps the second pair's blend unfused
   like the first (138 words without it). */
// FUN_001FE090
#pragma opt_dead_assignments off
void func_001fe090(u8 *arg0)
{
    u32 count;
    BtlEplFade2Param *param;
    V4 *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *mul;
    V4 color;
    BtlEplRgba rgba;

    target = *(V4 **)(arg0 + 0x30);
    param = *(BtlEplFade2Param **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    mul = (V4 *)func_001b7020();
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    switch (mode) {
    case 0:
        if (count != 0) {
            return;
        }
        rgba.rgba = param->color[0].rgba;
        btlEplRgbaToV4(&color, &rgba.c);
        color.v[0] = color.v[0] * mul[0].v[0];
        color.v[1] = color.v[1] * mul[0].v[1];
        color.v[2] = color.v[2] * mul[0].v[2];
        color.v[3] = color.v[3] * mul[0].v[3];
        *(V4 *)func_00149ca0() = color;
        rgba.rgba = param->color[1].rgba;
        btlEplRgbaToV4(&color, &rgba.c);
        color.v[0] = color.v[0] * mul[1].v[0];
        color.v[1] = color.v[1] * mul[1].v[1];
        color.v[2] = color.v[2] * mul[1].v[2];
        color.v[3] = color.v[3] * mul[1].v[3];
        *(V4 *)func_00149ce0() = color;
        break;
    case 1:
        if (count == 0) {
            target[0] = *(V4 *)func_00149ca0();
            target[1] = *(V4 *)func_00149ce0();
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            rgba.rgba = param->color[0].rgba;
            btlEplRgbaToV4(&color, &rgba.c);
            color.v[0] = color.v[0] * mul[0].v[0];
            color.v[1] = color.v[1] * mul[0].v[1];
            color.v[2] = color.v[2] * mul[0].v[2];
            color.v[3] = color.v[3] * mul[0].v[3];
            inv = 1.0f - scale;
            a0 = target[0].v[0] * inv;
            a1 = target[0].v[1] * inv;
            a2 = target[0].v[2] * inv;
            a3 = target[0].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)func_00149ca0() = color;

            rgba.rgba = param->color[1].rgba;
            btlEplRgbaToV4(&color, &rgba.c);
            color.v[0] = color.v[0] * mul[1].v[0];
            color.v[1] = color.v[1] * mul[1].v[1];
            color.v[2] = color.v[2] * mul[1].v[2];
            color.v[3] = color.v[3] * mul[1].v[3];
            a0 = target[1].v[0] * inv;
            a1 = target[1].v[1] * inv;
            a2 = target[1].v[2] * inv;
            a3 = target[1].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)func_00149ce0() = color;
        }
        break;
    case 2:
        if (count == total - param->fadeOut) {
            target[0] = *(V4 *)func_00149ca0();
            target[1] = *(V4 *)func_00149ce0();
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            inv = 1.0f - scale;
            a0 = mul[0].v[0] * inv;
            a1 = mul[0].v[1] * inv;
            a2 = mul[0].v[2] * inv;
            a3 = mul[0].v[3] * inv;
            b0 = target[0].v[0] * scale;
            b1 = target[0].v[1] * scale;
            b2 = target[0].v[2] * scale;
            b3 = target[0].v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)func_00149ca0() = color;
            a0 = mul[1].v[0] * inv;
            a1 = mul[1].v[1] * inv;
            a2 = mul[1].v[2] * inv;
            a3 = mul[1].v[3] * inv;
            b0 = target[1].v[0] * scale;
            b1 = target[1].v[1] * scale;
            b2 = target[1].v[2] * scale;
            b3 = target[1].v[3];
            color.v[0] = a0 + b0;
            color.v[1] = a1 + b1;
            color.v[2] = a2 + b2;
            color.v[3] = a3 + b3 * scale;
            *(V4 *)func_00149ce0() = color;
        }
        break;
    }
}
#pragma opt_dead_assignments on
// FUN_001FEB80
void func_001feb80(void) {
    func_0044ea90(D_00625230, 0x389);
    (*jtbl_008873E8)(0x10, 0x40000);
}

// FUN_001FEBD0
void func_001febd0(void *arg0) {
    jtbl_008873EC[0](arg0);
}

// FUN_001FEC00
/* The blend keeps the third colour term unscaled until the final add, as in
   func_001b7e70 (btlMain.c); retail fuses only that last component. */
void func_001fec00(u8 *arg0)
{
    u32 count;
    BtlEplFadeParam *param;
    V4 *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *heap;
    V4 color;
    V4 blend;
    BtlEplRgba rgba;
    f32 inv;
    f32 a0;
    f32 a1;
    f32 a2;
    f32 b0;
    f32 b1;
    f32 b2;

    target = *(V4 **)(arg0 + 0x30);
    param = *(BtlEplFadeParam **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    heap = (V4 *)func_001b7050();
    switch (mode) {
    case 0:
        if (count != 0) {
            return;
        }
        rgba.rgba = param->color.rgba;
        btlEplRgbaToV4(&color, &rgba.c);
        color.v[3] = 1.0f;
        *heap = color;
        func_001496c0(&color);
        break;
    case 1:
        if (count == 0) {
            *target = *heap;
        }
        rgba.rgba = param->color.rgba;
        btlEplRgbaToV4(&color, &rgba.c);
        inv = 1.0f - scale;
        a0 = target->v[0] * inv;
        a1 = target->v[1] * inv;
        a2 = target->v[2] * inv;
        b0 = color.v[0] * scale;
        b1 = color.v[1] * scale;
        b2 = color.v[2];
        blend.v[0] = a0 + b0;
        blend.v[1] = a1 + b1;
        blend.v[2] = a2 + b2 * scale;
        blend.v[3] = 1.0f;
        *heap = blend;
        func_001496c0(&blend);
        break;
    case 2:
        if (count == total - param->fadeOut) {
            *target = *heap;
        }
        btlEplRgbaToV4(&color, &D_007641F8);
        inv = 1.0f - scale;
        a0 = color.v[0] * inv;
        a1 = color.v[1] * inv;
        a2 = color.v[2] * inv;
        b0 = target->v[0] * scale;
        b1 = target->v[1] * scale;
        b2 = target->v[2];
        blend.v[0] = a0 + b0;
        blend.v[1] = a1 + b1;
        blend.v[2] = a2 + b2 * scale;
        blend.v[3] = 1.0f;
        *heap = blend;
        func_001496c0(&blend);
        break;
    }
}
// FUN_001FF300
s32 *func_001ff300(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *result;

    func_0044ea90(D_00625230, 0x429);
    result = (s32 *)(*jtbl_008873E8)(0x24, 0x40000);
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        *result = func_004abc50(arg2, arg3);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_001FF3B0
s32 *func_001ff3b0(u8 *arg0) {
    s32 *field;
    s32 *result;
    s32 value;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0x429);
    result = (s32 *)(*jtbl_008873E8)(0x24, 0x40000);
    value = *field;
    if (value != 0) {
        *result = func_004abd80(value);
    } else {
        *result = 0;
    }
    return result;
}
// FUN_001FF440
void func_001ff440(s32 *arg0) {
    if (*arg0 != 0) {
        func_004abd60(*arg0);
    }
    jtbl_008873EC[0](arg0);
}

typedef struct BtlEplMatrix
{
    BtlEplV3 right; // 0x00
    u32 flags;      // 0x0C
    BtlEplV3 up;    // 0x10
    u32 pad1;       // 0x1C
    BtlEplV3 at;    // 0x20
    u32 pad2;       // 0x2C
    BtlEplV3 pos;   // 0x30
    u32 pad3;       // 0x3C
} BtlEplMatrix;

typedef struct BtlEplLightParam
{
    u32 total;           // 0x00
    u16 fadeIn;          // 0x04
    u16 fadeOut;         // 0x06
    BtlEplRgba color[2]; // 0x08
    f32 rotate;          // 0x10
    f32 scale;           // 0x14
} BtlEplLightParam;

typedef struct BtlEplLightTarget
{
    u8 *model;    // 0x00
    V4 start[2];  // 0x04
} BtlEplLightTarget;

extern BtlEplMatrix D_00922C60;

/* measured: opt_dead_assignments off keeps the colour conversions where the
   source puts them, as in func_001fceb0. */
// FUN_001FF490
#pragma opt_dead_assignments off
void func_001ff490(u8 *arg0)
{
    u32 count;
    BtlEplLightParam *param;
    BtlEplLightTarget *target;
    u32 total;
    u8 mode;
    f32 scale;
    V4 *src;
    s32 hasMatrix;
    BtlEplRgba rgba;
    f32 vec[3];
    BtlEplMatrix matrix;

    target = *(BtlEplLightTarget **)(arg0 + 0x30);
    param = *(BtlEplLightParam **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    total = param->total;
    if (total < count && total != 0) {
        return;
    }
    src = (V4 *)func_001b7020();
    mode = 0;
    if (total != 0) {
        if (count <= param->fadeIn) {
            if (param->fadeIn > 0) {
                scale = (f32)count / (f32)param->fadeIn;
            } else {
                scale = 1.0f;
            }
            mode = 1;
        } else if (count >= total - param->fadeOut) {
            if (param->fadeOut > 0) {
                scale = (f32)(total - count) / (f32)param->fadeOut;
            } else {
                scale = 0.0f;
            }
            mode = 2;
        }
    }
    hasMatrix = 0;
    if (target->model != NULL) {
        func_0048a150(&matrix, arg0 + 0x10);
        func_0047a1c0(target->model, &matrix, 0);
        vec[0] = vec[1] = vec[2] = *(f32 *)(arg0 + 0x20) * param->scale;
        mdlScale(target->model, vec, 2);
        vec[0] = ((f32 *)arg0)[0];
        vec[1] = ((f32 *)arg0)[1];
        vec[2] = ((f32 *)arg0)[2];
        func_0047a180((RwMatrix *)target->model, (const RwV3d *)vec, 2);
        func_0047a0e0(target->model, 0, param->rotate);
        func_00478e70(target->model);
        if (func_0047a510(target->model, 0, &matrix) != 0) {
            hasMatrix = 1;
        }
    }
    switch (mode) {
    case 0:
        if (count != 0) {
            break;
        }
        rgba.rgba = param->color[0].rgba;
        btlEplRgbaToV4((V4 *)&D_00922CA0[0], &rgba.c);
        rgba.rgba = param->color[1].rgba;
        btlEplRgbaToV4((V4 *)&D_00922CA0[4], &rgba.c);
        D_00922CC0[0] = 1;
        break;
    case 1:
        if (count == 0) {
            target->start[0] = *(V4 *)&D_00922CA0[0];
            target->start[1] = *(V4 *)&D_00922CA0[4];
        }
        {
            V4 color;
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            rgba.rgba = param->color[0].rgba;
            btlEplRgbaToV4(&color, &rgba.c);
            inv = 1.0f - scale;
            a0 = target->start[0].v[0] * inv;
            a1 = target->start[0].v[1] * inv;
            a2 = target->start[0].v[2] * inv;
            a3 = target->start[0].v[3] * inv;
            b0 = color.v[0] * scale;
            b1 = color.v[1] * scale;
            b2 = color.v[2] * scale;
            b3 = color.v[3];
            D_00922CA0[0] = a0 + b0;
            D_00922CA0[1] = a1 + b1;
            D_00922CA0[2] = a2 + b2;
            D_00922CA0[3] = a3 + b3 * scale;

            rgba.rgba = param->color[1].rgba;
            a0 = target->start[1].v[0] * inv;
            a1 = target->start[1].v[1] * inv;
            a2 = target->start[1].v[2] * inv;
            a3 = target->start[1].v[3] * inv;
            b0 = (1.0f / 255.0f) * (f32)(u32)rgba.c.r * scale;
            b1 = (1.0f / 255.0f) * (f32)(u32)rgba.c.g * scale;
            b2 = (1.0f / 255.0f) * (f32)(u32)rgba.c.b * scale;
            b3 = (1.0f / 255.0f) * (f32)(u32)rgba.c.a * scale;
            a0 += b0;
            D_00922CA0[4] = a0;
            a1 += b1;
            D_00922CA0[5] = a1;
            a2 += b2;
            D_00922CA0[6] = a2;
            a3 += b3;
            D_00922CA0[7] = a3;
        }
        D_00922CC0[0] = 1;
        break;
    case 2:
        if (count == total - param->fadeOut) {
            target->start[0] = *(V4 *)&D_00922CA0[0];
            target->start[1] = *(V4 *)&D_00922CA0[4];
        }
        {
            f32 inv;
            f32 a0, a1, a2, a3;
            f32 b0, b1, b2, b3;

            inv = 1.0f - scale;
            a0 = src[0].v[0] * inv;
            a1 = src[0].v[1] * inv;
            a2 = src[0].v[2] * inv;
            a3 = src[0].v[3] * inv;
            b0 = target->start[0].v[0] * scale;
            b1 = target->start[0].v[1] * scale;
            b2 = target->start[0].v[2] * scale;
            b3 = target->start[0].v[3];
            D_00922CA0[0] = a0 + b0;
            D_00922CA0[1] = a1 + b1;
            D_00922CA0[2] = a2 + b2;
            D_00922CA0[3] = a3 + b3 * scale;
            a0 = src[1].v[0] * inv;
            a1 = src[1].v[1] * inv;
            a2 = src[1].v[2] * inv;
            a3 = src[1].v[3] * inv;
            b0 = target->start[1].v[0] * scale;
            b1 = target->start[1].v[1] * scale;
            b2 = target->start[1].v[2] * scale;
            b3 = target->start[1].v[3];
            D_00922CA0[4] = a0 + b0;
            D_00922CA0[5] = a1 + b1;
            D_00922CA0[6] = a2 + b2;
            D_00922CA0[7] = a3 + b3 * scale;
        }
        D_00922CC0[0] = 1;
        break;
    }
    if (hasMatrix) {
        D_00922C60 = matrix;
    }
}
#pragma opt_dead_assignments on
// FUN_001FFF40
void func_001fff40(u8 *arg0) {
    s32 count;
    u8 *param;
    u8 *node;
    u32 i;
    s32 value;

    param = *(u8 **)(arg0 + 0x38);
    count = *(s32 *)(arg0 + 0x28);
    for (i = 0; i < 4; i++) {
        node = *(u8 **)(D_0072449C + i * 8 + 0x178);
        while (node != NULL) {
            if ((func_001fc300(node, param) != 0) &&
                ((value = *(s32 *)(node + 0xA64), value == 0) ||
                 (func_00243d80(value) != 0) ||
                 (datCalcIsDead(*(s32 *)(node + 0xA64), 0) == 0))) {
                *(u16 *)(node + 0x9D8) |= 8;
                if (count == 0) {
                    if (*(u8 *)(param + 0xE) == 0) {
                        func_0019d990(node, 4);
                    }
                    value = *(s16 *)(param + 4);
                    func_00198920(node, (s16)value, *(u16 *)(param + 0xC),
                                  *(f32 *)(param + 8), *(u16 *)(param + 6));
                    value = *(s32 *)(param + 0x10);
                    if (value != 0) {
                        func_00199890(node, (s16)value);
                    }
                    func_0019d7a0(node, 4);
                }
            }
            node = *(u8 **)(node + 0xA6C);
        }
    }
}
// FUN_00200090
s32 *func_00200090(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *result;

    func_0044ea90(D_00625230, 0x54D);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    *result = 0;
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        *result = func_004abc50(arg2, arg3);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_00200150
s32 *func_00200150(u8 *arg0) {
    s32 *field;
    s32 *result;
    s32 value;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0x54D);
    result = (s32 *)(*jtbl_008873E8)(4, 0x40000);
    *result = 0;
    value = *field;
    if (value != 0) {
        *result = func_004abd80(value);
    } else {
        *result = 0;
    }
    return result;
}

// FUN_002001E0
void func_002001e0(s32 *arg0) {
    if (*arg0 != 0) {
        func_004abd60(*arg0);
    }
    jtbl_008873EC[0](arg0);
}

// FUN_00200230
void func_00200230(u8 *arg0) {
    f32 sp130[4];
    u8 sp120[0x10];
    u8 sp110[0x10];
    u8 spE0[0x30];
    u8 spA0[0x40];
    u8 sp60[0x40];
    u8 sp50[0x10];
    f32 scale;
    f32 inv;
    u32 count;
    u32 i;
    u8 *target;
    u8 *param;
    u8 *node;

    target = *(u8 **)(arg0 + 0x30);
    param = *(u8 **)(arg0 + 0x38);
    count = *(u32 *)(arg0 + 0x28);
    if ((*(u32 *)(param + 4) >= count) || (*(u32 *)(param + 4) == 0)) {
        if ((count == *(u32 *)(param + 4)) && (*(s32 *)(param + 0x10) != 0)) {
            for (i = 0; i < 2; i++) {
                node = *(u8 **)(D_0072449C + i * 8 + 0x178);
                while (node != NULL) {
                    if ((*(s32 *)(node + 0xA64) != 0) && (func_001fc300(node, param) != 0) &&
                        (datCalcIsDead(*(s32 *)(node + 0xA64), 0) == 0)) {
                        func_00194ff0(node, sp120, sp50, NULL);
                        btlUnitSetPos(node, sp120);
                        btlUnitSetRot(node, sp50);
                        func_00198dd0(node, 0);
                        func_00198920(node, *(s16 *)(node + 0x9EC), 0, *(f32 *)(node + 0x9F0),
                                      (u16)*(s8 *)(node + 0x9F4));
                    }
                    node = *(u8 **)(node + 0xA6C);
                }
            }
            return;
        }
        if (*(u8 **)target != NULL) {
            func_0048a150(spE0, arg0 + 0x10);
            func_0047a1c0(*(u8 **)target, spE0, 0);
            scale = *(f32 *)(arg0 + 0x20) * *(f32 *)(param + 0xC);
            sp130[2] = scale;
            sp130[1] = scale;
            sp130[0] = scale;
            mdlScale(*(u8 **)target, sp130, 2);
            sp130[0] = *(f32 *)(arg0 + 0);
            sp130[1] = *(f32 *)(arg0 + 4);
            sp130[2] = *(f32 *)(arg0 + 8);
            func_0047a180((RwMatrix *)*(u8 **)target, (const RwV3d *)sp130, 2);
            func_0047a0e0(*(u8 **)target, 0, *(f32 *)(param + 8));
            func_00478e70(*(u8 **)target);
            if (func_0047a510(*(u8 **)target, 0, spE0) != 0) {
                for (i = 0; i < 4; i++) {
                    node = *(u8 **)(D_0072449C + i * 8 + 0x178);
                    while (node != NULL) {
                        if ((func_001fc300(node, param) != 0) &&
                            (*(s32 *)(node + 0xA64) == 0 ||
                             datCalcIsDead(*(s32 *)(node + 0xA64), 0) == 0)) {
                            btlUnitSetPos(node, sp110);
                            inv = 1.0f / scale;
                            sp130[2] = inv;
                            sp130[1] = inv;
                            sp130[0] = inv;
                            RwMatrixScale(spA0, sp130, 0);
                            RwMatrixMultiply(sp60, spE0, spA0);
                            RtQuatConvertFromMatrix(sp50, sp60);
                            func_001ec350(sp50, sp50);
                            btlUnitSetRot(node, sp50);
                        }
                        node = *(u8 **)(node + 0xA6C);
                    }
                }
            }
        }
    }
}

// FUN_00200550
s32 *func_00200550(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BtlEplEplWork *result;
    s32 value;
    u32 rnd;

    func_0044ea90(D_00625230, 0x60D);
    result = (BtlEplEplWork *)(*jtbl_008873E8)(8, 0x40000);
    result->target = 0;
    result->pattern = 0;
    if ((arg2 != 0) && ((arg1 & 0xFFFF) == 3)) {
        value = func_004abc50(arg2, arg3);
        result->target = value;
        rnd = func_0047a7c0(value);
        if ((rnd >> 1) != 0) {
            result->pattern = (s16)((effMiscRand(0) % (rnd / 2)) * 2);
        }
    } else {
        result->target = 0;
    }
    return (s32 *)result;
}

// FUN_00200650
s32 *func_00200650(u8 *arg0) {
    s32 *field;
    BtlEplEplWork *result;
    s32 value;
    u32 rnd;

    field = *(s32 **)(arg0 + 0x30);
    func_0044ea90(D_00625230, 0x60D);
    result = (BtlEplEplWork *)(*jtbl_008873E8)(8, 0x40000);
    result->target = 0;
    result->pattern = 0;
    value = *field;
    if (value != 0) {
        value = func_004abd80(value);
        result->target = value;
        rnd = func_0047a7c0(value);
        if ((rnd >> 1) != 0) {
            result->pattern = (s16)((effMiscRand(0) % (rnd / 2)) * 2);
        }
    } else {
        result->target = 0;
    }
    return (s32 *)result;
}
