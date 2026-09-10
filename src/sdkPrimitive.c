/* Consolidated Persona 4 source units. */
/* Original translation unit sdkPrimitive.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

typedef struct { u8 c[4]; } PrimByte4;
typedef struct { f32 v[4]; } PrimFloat4;
typedef struct { f32 v[2]; } PrimFloat2;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0[12];
    f32 inv;
    u8 pad1[4];
    f32 color[4];
    u8 pad2[16];
} PrimVertex;
extern void func_0044ea90(void *msg, s32 id);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s64 iGpffffabe8;
extern u8 *func_00460990(void);
extern void func_00460ac0(void *param, void *work);
extern void func_0045d890(void);
extern void func_0045d370(void *out, void *a1, void *a2, f32 f0, s32 a3, s32 a4, f32 f1, f32 f2, f32 f3);
extern void func_0045dd30(PrimVertex *out, const PrimByte4 *colors, const PrimFloat2 *positions,
                          f32 depth, u32 count, s32 offsetX, s32 offsetY,
                          f32 rotation, f32 scaleX, f32 scaleY);
extern void func_003f6440(s32 param, s32 value);
extern void (*D_00887300[])();
extern void (*D_00887304[])();
extern void (*D_00887310[])(s32 primType, void *verts, s32 numVerts);
extern struct {
    s32 state;
    s32 val;
} D_00712490[6];
extern u8 D_007124C0[];
extern u8 *func_00457120(void);
extern f32 func_0044b7b0(f32 x);
extern f32 func_0044b610(f32 x);
extern f32 D_008872F8[];
extern f32 iGpffff81d0;


// FUN_0045DA40
void func_0045da40(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 fparg0) {
    PrimFloat4 pos;
    struct {
        PrimByte4 col;
        PrimFloat4 pos;
        f32 scale;
        s32 tag;
    } packet;
    u8 *temp_2;
    u8 *temp_2_2;

    pos = *(PrimFloat4 *)arg1;
    packet.col = *(PrimByte4 *)arg0;
    packet.pos = pos;
    packet.scale = fparg0;
    packet.tag = arg2;
    func_0044ea90(D_007124C0, 0x101);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x1C, 0x40000);
    func_0043f810(temp_2, &packet, 0x1C);
    temp_2_2 = (u8 *)(func_00460990());
    *(void **)(temp_2_2 + 8) = (void *)func_0045d890;
    *(u8 **)(temp_2_2 + 0x10) = temp_2;
    func_00460ac0((void *)arg3, temp_2_2);
}


// FUN_0045DB40
void func_0045db40(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, f32 fparg3) {
    struct { s32 saved[6]; u8 pad1[8]; f32 out; u8 pad2[0xFC]; PrimFloat4 pos; } work;
    u32 i;
    u32 j;
    s32 *p;
    work.pos = *(PrimFloat4 *)arg1;
    if (arg2 != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)((u8 *)work.saved + i * 4));
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    func_0045d370(&work.out, arg0, &work.pos, fparg0, arg3, arg4, fparg1, fparg2, fparg3);
    D_00887310[0](4, &work.out, 4);
    if (arg2 != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], work.saved[j]);
        }
    }
}


/* Measured: 664/672 bytes, six resolved relocations and eight zero alignment bytes.
 * Keep both coordinate subtractions before the in-place scale multiplications;
 * the base position and unsigned color channels retain their actual layouts. */
// FUN_0045DD30
void func_0045dd30(PrimVertex *out, const PrimByte4 *colors, const PrimFloat2 *positions,
                  f32 depth, u32 count, s32 offsetX, s32 offsetY,
                  f32 rotation, f32 scaleX, f32 scaleY) {
    PrimFloat2 base;
    const PrimFloat2 *position;
    PrimVertex *vertex;
    const u8 *color;
    f32 inv;
    f32 angle;
    f32 sine;
    f32 cosine;
    f32 centerX;
    f32 centerY;
    f32 x;
    f32 y;
    f32 negSine;
    u32 i;

    inv = 1.0f / *(f32 *)(func_00457120() + 0x80);
    depth = D_008872F8[0] - depth;
    angle = iGpffff81d0 * rotation;
    sine = func_0044b7b0(angle);
    cosine = func_0044b610(angle);
    base = *positions;
    i = 0;
    centerX = base.v[0] + (f32)offsetX;
    centerY = base.v[1] + (f32)offsetY;
    negSine = -sine;
    while (i < count) {
        position = &positions[i];
        x = position->v[0] - centerX;
        y = position->v[1] - centerY;
        x *= scaleX;
        y *= scaleY;
        vertex = &out[i];
        vertex->x = centerX + (x * cosine + y * sine);
        vertex->y = centerY + (x * negSine + y * cosine);
        vertex->z = depth;
        color = colors[i].c;
        vertex->color[0] = (f32)(u32)color[0];
        vertex->color[1] = (f32)(u32)color[1];
        vertex->color[2] = (f32)(u32)color[2];
        vertex->color[3] = (f32)(u32)color[3];
        vertex->inv = inv;
        i++;
    }
}


// FUN_0045DFD0

void func_0045dfd0(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4) {
    s32 saved[6];
    s32 *p;
    PrimVertex *out;
    PrimVertex *vertex;
    u8 *color;
    u8 *position;
    f32 z;
    f32 inv;
    u32 i;
    u32 j;
    u32 k;

    if (arg4 != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)((u8 *)saved + i * 4));
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    func_0044ea90(D_007124C0, 0x2DA);
    out = (PrimVertex *)D_008873F4[0](1, arg2 << 6, 0x40000);
    inv = 1.0f / *(f32 *)(func_00457120() + 0x80);
    z = D_008872F8[0] - fparg0;
    for (k = 0; k < (u32)arg2; k++) {
        position = arg1 + k * 8;
        vertex = &out[k];
        vertex->x = *(f32 *)position;
        vertex->y = *(f32 *)(position + 4);
        vertex->z = z;
        color = arg0 + k * 4;
        vertex->color[0] = (f32)(u32)color[0];
        vertex->color[1] = (f32)(u32)color[1];
        vertex->color[2] = (f32)(u32)color[2];
        vertex->color[3] = (f32)(u32)color[3];
        vertex->inv = inv;
    }
    D_00887310[0](arg3, out, arg2);
    if (arg4 != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], saved[j]);
        }
    }
    jtbl_008873EC[0](out);
}


typedef struct {
    u8 *colors;
    void *positions;
    f32 scale;
    u32 count;
    s32 enabled;
    s8 alpha;
    u8 pad[3];
    s32 primType;
} PrimBatch;

// FUN_0045E310
void func_0045e310(void *unused, PrimBatch *work) {
    s32 saved[6];
    s32 *p;
    PrimVertex *out;
    PrimFloat2 *positions;
    u8 *colors;
    f32 z;
    f32 inv;
    f32 scale;
    u32 i;
    u32 count;
    s32 enabled;
    u32 j;
    u32 k;
    u32 table_addr;
    void (**release)(void *);

    positions = (PrimFloat2 *)work->positions;
    colors = work->colors;
    scale = work->scale;
    enabled = work->enabled;
    count = work->count;
    if (enabled != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)((u8 *)saved + i * 4));
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    func_0044ea90(D_007124C0, 0x30D);
    out = (PrimVertex *)jtbl_008873E8[0](count << 6, 0x40000);
    inv = 1.0f / *(f32 *)(func_00457120() + 0x80);
    z = D_008872F8[0] - scale;
    for (k = 0; k < count; k++) {
        PrimFloat2 *pos = &positions[k];
        PrimVertex *vertex = &out[k];
        u8 *color;

        vertex->x = pos->v[0];
        vertex->y = pos->v[1];
        vertex->z = z;
        color = colors + k * 4;
        vertex->color[0] = (f32)(u32)color[0];
        vertex->color[1] = (f32)(u32)color[1];
        vertex->color[2] = (f32)(u32)color[2];
        vertex->color[3] = (f32)(u32)color[3];
        vertex->inv = inv;
    }
    if (work->alpha == 1) {
        iGpffffabe8 |= 0x80;
    }
    D_00887310[0](work->primType, out, count);
    if (work->alpha == 1) {
        iGpffffabe8 &= ~0x80;
    }
    if (enabled != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], saved[j]);
        }
    }
    table_addr = (u32)jtbl_008873EC;
    release = (void (**)(void *))table_addr;
    release[0](out);
    release[0](work);
}


// FUN_0045E6A0
void func_0045e6a0(s32 arg0, s32 arg1, f32 fparg0, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 fparg1, f32 fparg2, f32 fparg3) {
    s32 saved[6];
    s32 *p;
    s32 *out;
    u32 i;
    u32 j;
    if (arg4 != 0) {
        for (i = 0; i < 6; i++) {
            p = (s32 *)&D_00712490[i];
            D_00887304[0](p[0], (void *)((u8 *)saved + i * 4));
            D_00887300[0](p[0], p[1]);
        }
        D_00887300[0](1, 0);
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x717FB);
    }
    func_0044ea90(D_007124C0, 0x355);
    out = (s32 *)jtbl_008873E8[0](arg2 << 6, 0x40000);
    func_0045dd30((PrimVertex *)out, (const PrimByte4 *)arg0, (const PrimFloat2 *)arg1,
                  fparg0, arg2, arg5, arg6, fparg1, fparg2, fparg3);
    D_00887310[0](arg3, out, arg2);
    if (arg4 != 0) {
        for (j = 0; j < 6; j++) {
            p = (s32 *)&D_00712490[j];
            D_00887300[0](p[0], saved[j]);
        }
    }
    jtbl_008873EC[0](out);
}


/* Refreshed probe: Lng_0045e8e0_body.c uses the real iGpffff81d0 conversion,
   caches it across both trigonometric calls and keeps center X as s32.
   Ordinary C reproduces both product-seeded mula/madd/add chains; the old
   blanket accumulator-floor claim was false. The current 560B/576B candidate
   has 100 fully relocated differing words, plus a missing 4B executable nop
   and 12B alignment. Register allocation and scheduling remain unresolved;
   this does not improve the historical nd88 score. Retail stays in ASM. */
// FUN_0045E8E0
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045e8e0);


/* MnB_0045eb20_body.c has the same recovered product-seeded rotation chains
   and the post-loop alpha byte store. Its 568B/576B candidate has 102 fully
   relocated differing words, a missing 4B executable nop and 4B alignment.
   Both probes resolve all 14 relocations and preserve all five owner C
   functions; neither is an instruction match or a proven FPU limitation. */
// FUN_0045EB20
INCLUDE_ASM("asm/nonmatchings/sdkPrimitive", func_0045eb20);
