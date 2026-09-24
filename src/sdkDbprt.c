/* Consolidated Persona 4 source units. */
/* Original translation unit sdkDbprt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
#include "sdk_dbprt.h"

#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)

typedef struct HDbText3D HDbText3D;
struct HDbText3D
{
    HDbText3D* next; // 0x00
};
typedef struct { u8 b0, b1, b2, b3; } RGBA8;

static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];
/* b210 emits these private small-data objects in reverse declaration order.
 * This sequence places the queue, camera, image and raster at retail's four
 * consecutive words 0x00764ACC through 0x00764AD8. */
static s32 *iGpffffb9e8;    /* gp -0x4618 (0x00764AD8), font raster */
static u8 *iGpffffb9e4;     /* gp -0x461C (0x00764AD4), loaded image */
static void *iGpffffb9e0;   /* gp -0x4620 (0x00764AD0), camera */
static HDbText3D* iGpffffb9dc; /* gp -0x4624 (0x00764ACC), queued text */

extern void* memset(void* destination, s32 value, size_t count);
/* rwGlobals.memFuncs.RwFree slot: indirect call through data. */
extern void (*RwFree_abs[])(void* memory);

/* Absolute debug-assert strings and file resources (0x007105xx region). */
extern char D_00710500[];
extern char D_00710510[];
extern char D_00710530[];
/* Absolute 12x12 font grid (zero-filled .bss). */
extern char D_008BF720[];

/* library / file helpers */
extern void func_00440b68(const char *fmt, ...);
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_00456150(void *handle);
extern void func_00454bd0(u8 *ptr);
extern u8 *func_003eaf60(u8 *arg0);
extern s32 *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003ec180(u8 *arg0, s32 *arg1);
extern s32 func_003ea370(s32 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);


/* text3d helpers */
extern void func_0044ec50(s32 arg0);
extern void func_0044ea90(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void func_00446ed8(void *buf, const void *fmt, void *va);
extern char iGpffffac30;
extern char iGpffffac38[6]; /* gp -0x53C8: "%s %d" */

typedef char *va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)


// FUN_0044F570
void func_0044f570(s32 arg0) {
    u8 *h1;
    u8 *h2;
    s32 *raster;

    func_00440b68(iGpffffac38, D_00710500, 0x4F);
    h1 = func_00454a60((u8 *)D_00710510, 0);
    func_00456150(h1);
    func_00440b68(iGpffffac38, D_00710500, 0x52);
    h2 = func_00454a60((u8 *)D_00710530, 0);
    func_00456150(h2);
    func_00454bd0(h2);
    iGpffffb9e4 = func_003eaf60((u8 *)D_00710510);
    iGpffffb9e0 = (void *)arg0;
    func_00454bd0(h1);
    raster = func_003ec590(*(s32 *)(iGpffffb9e4 + 4), *(s32 *)(iGpffffb9e4 + 8), 4, 0x4504);
    iGpffffb9e8 = raster;
    func_003ec180((u8 *)raster, (s32 *)iGpffffb9e4);
    func_003ea370((s32 *)iGpffffb9e4);
    iGpffffb9e4 = NULL;
    func_0043f9c8(D_008BF720, 0x20, 0x848);
    iGpffffb9dc = NULL;
}

// FUN_0044F6B0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));

    curr = iGpffffb9dc;
    iGpffffb9dc = NULL;
    while (1)
    {
        if (curr == NULL)
        {
            break;
        }

        next = curr->next;
        RwFree_abs[0](curr);
        curr = next;
    }
}
/* Native b210 O2: 876/880 bytes, 17 resolved relocations and four zero
 * alignment bytes. The near-depth field belongs to the complete device
 * record; keeping that ownership reproduces the vertex-loop preheader.
 * See docs/probe_archive/Debug_grid_0044f720_20260924.md. */
#pragma push
#pragma opt_loop_invariants on
/* The glyph atlas has sixteen columns. Keep this conversion signed so
 * its remainder operation also describes negative input values. */
static inline s32 debugGlyphColumn(s32 value)
{
    return value % 16;
}

// FUN_0044F720
void func_0044f720(void)
{
    extern u32 func_003e8120(u32 camera);
    extern u32 func_003e8110(u32 camera);
    extern void func_0044fa90(void);
    extern void func_00450630(void);
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 (*D_00887304[])(s32 state, void *value);
    extern s32 (*D_00887310[])(s32, void *, s32);
    typedef struct DebugRenderDevice {
        f32 gamma;
        s32 (*system)(s32, void *, void *, s32);
        f32 nearDepth;
        f32 farDepth;
        s32 (*setState)(s32, void *);
        s32 (*getState)(s32, void *);
        /* The eight remaining immediate-mode callbacks occupy address words. */
        u32 renderCallbackAddresses[8];
    } DebugRenderDevice;
    extern DebugRenderDevice D_008872F0;
    f32 textureCoordinates[8];
    typedef struct DebugGlyphVertex {
        f32 position[3];
        f32 cameraZ;
        f32 texcoord[2];
        f32 reciprocal;
        f32 pad1;
        f32 color[4];
        f32 normal[3];
        f32 pad2;
    } DebugGlyphVertex;
    DebugGlyphVertex vertices[4];
    s32 savedFog;
    f32 reciprocalDepth;
    f32 topY;
    f32 bottomY;
    s32 column;
    s32 row;
    struct { s32 (*setState)(s32, void *); } *renderer;
    u8 *characters;

    reciprocalDepth = 1.0f / *(f32 *)((u8 *)iGpffffb9e0 + 0x80);
    if (func_003e8120((u32)iGpffffb9e0) != 0) {
        D_00887304[0](14, &savedFog);
        renderer = (void *)D_00887300;
        renderer->setState(14, (void *)0);
        renderer->setState(6, (void *)1);
        renderer->setState(7, (void *)2);
        renderer->setState(8, (void *)1);
        renderer->setState(9, (void *)1);
        renderer->setState(12, (void *)1);
        renderer->setState(1, iGpffffb9e8);
        {
            s32 vertexIndex;
            vertexIndex = 0;
            for (; vertexIndex < 4; vertexIndex++) {
                DebugGlyphVertex *vertex = &vertices[vertexIndex];
                vertex->reciprocal = reciprocalDepth;
                vertex->color[0] = 255.0f;
                vertex->color[1] = 255.0f;
                vertex->color[2] = 255.0f;
                vertex->color[3] = 255.0f;
                vertex->position[2] = D_008872F0.nearDepth;
            }
        }
        row = 0;
        while (row < 0x28) {
            column = 0;
            characters = (u8 *)sGrid[row];
            topY = 12.0f * (f32)row;
            bottomY = 11.0f + topY;
            for (; column < 0x35; column++) {
                u8 character;
                character = *(u8 *)((u8 *)characters + column);
                if (character != 0x20) {
                    u8 glyphIndex;
                    f32 leftX;
                    f32 rightX;
                    s32 tileColumn;
                    f32 leftU;
                    f32 topV;
                    s32 vertexIndex;
                    glyphIndex = character - 0x20;
                    if ((s32)glyphIndex >= 0x80) {
                        glyphIndex = glyphIndex - 0x20;
                    }
                    leftX = 12.0f * (f32)column;
                    vertices[0].position[0] = leftX;
                    vertices[0].position[1] = topY;
                    rightX = 11.0f + leftX;
                    vertices[1].position[0] = rightX;
                    vertices[1].position[1] = topY;
                    vertices[2].position[0] = leftX;
                    vertices[2].position[1] = bottomY;
                    vertices[3].position[0] = rightX;
                    vertices[3].position[1] = bottomY;
                    tileColumn = debugGlyphColumn((s32)glyphIndex);
                    leftU = 0.0625f * (f32)tileColumn;
                    textureCoordinates[0] = leftU;
                    topV = 0.0625f * (f32)(s32)((u32)glyphIndex >> 4);
                    textureCoordinates[1] = topV;
                    textureCoordinates[2] = 0.046875f + leftU;
                    textureCoordinates[3] = topV;
                    textureCoordinates[4] = leftU;
                    textureCoordinates[5] = 0.046875f + topV;
                    textureCoordinates[6] = 0.046875f + leftU;
                    textureCoordinates[7] = 0.046875f + topV;
                    vertexIndex = 0;
                    while (vertexIndex < 4) {
                        DebugGlyphVertex *vertex;
                        f32 *texcoord;
                        texcoord = &textureCoordinates[vertexIndex * 2];
                        vertex = &vertices[vertexIndex];
                        vertex->texcoord[0] = texcoord[0];
                        vertex->texcoord[1] = texcoord[1];
                        vertexIndex += 1;
                    }
                    D_00887310[0](4, vertices, 4);
                }
            }
            row++;
        }
        func_0044fa90();
        func_00450630();
        renderer->setState(14, (void *)savedFog);
        func_003e8110((u32)iGpffffb9e0);
    }
}
#pragma pop

/* Floor (measured 2026-09-17, source-repo only): probe_variants s_best 314 words / 132 edits / 366 vs 367 BEST faithful (bare 353/464, levers unfaithful despite words wins), fnalign 367/366/132 (+5), emitted 1464B/window 1472B (99.5%). Four-pragma sweep: bare wins (loop +1w/-6ed noted, cse/sched catastrophic, nobl neutral). Eight-singles re-sweep 2026-09-17: dead/prop/strength/unroll neutral at 314, loop-inv 315, sched 337, peephole 341, cse 377. Object-longer blocks are float spills (9x swc1 f3-f7); residual is coloring/scheduling/orientation + daddu. Re-derived sibling v8 floor; production stays ASM. Banked as guarded floor. */
/* measured 0044fa90 (owner, 2026-09-20): fnalign **132 -> 101 edits**, count 366 -> 364
   against retail 367 (-0.8%, inside).  Its three 11-14 instruction runs are all CROSS -
   the deficit is 1 - so nothing was written; both fixes are desync repairs.
   (a) Retail HOISTS the global `D_008872F8[0] - node->unk110` out of the j-loop: at
       retail[106] it loads `lwc1 $f1, 0x72f8($v0)` before the `b` into the loop, while
       the object reloaded it every iteration.  Hoisting it into a local is worth 2.
   (b) The object computed a second address for the uv array each iteration -
       `sll $v0, $a2, 3; addu $v0, $v0, $sp; addiu $a0, $v0, 0x140` - because the body
       kept a `uvp = &uv[j * 2]` pointer.  Indexing `uv[j * 2]` directly at the two uses
       drops that address computation and is worth the other 29.
   Note (a) and (b) point in OPPOSITE directions on the same loop: hoist the float the
   body reloaded, un-hoist the pointer the body cached.  Doing the same to the `quad`
   pointer as well is much worse - 190 edits and the object grows to 370 - so the third
   pointer stays.  Hoisting is a per-variable measurement, never a policy. */
// FUN_0044FA90 NONMATCHING
#ifdef NON_MATCHING
/* Target: func_0044fa90 -- source-repo faithful floor (banked, production stays ASM).
 * Owner: src/sdkDbprt.c (source/Persona4-Decompilation, CRLF; candidates LF, probe normalises).
 * Retail: 0x0044FA90, window 1472B (0x5C0), 368 words / 367 instrs after padding strip.
 * Measured (source): probe_variants 314 words (reloc-masked), fnalign 132 edits (+5 reloc-only), obj 366 vs retail 367 (1464B/1472B).
 * Shape: uv[8] then quads[64] (reverse-alloc bases sp+0x140/sp+0x40), mixed scale forms (field outer / byte inner, 0x160 frame), split x0 (mul+add), byte text, dead low-nibble branch kept, unsigned colors, (s32) high, (s32)v>=0x80.
 * No owner edits; no pragma (bare wins words+edits jointly). See report.md for full sweep.
 */
void func_0044fa90(void) {
    extern void (*D_00887300[])(u32, u32);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern f32 D_008872F8[];
    extern f32 func_00450490(f32);
    typedef struct Ext Ext;
    struct Ext { HDbText3D *next; f32 x; f32 y; f32 scale; u8 text[256]; f32 unk110; u8 col[4]; };
    HDbText3D *node;
    s32 idx;
    f32 invW;
    f32 scaled;
    f32 uv[8];
    f32 quads[64];
    f32 depth;
    invW = 1.0f / *(f32 *)((u8 *)iGpffffb9e0 + 0x80);
    node = iGpffffb9dc;
    D_00887300[0](1, (u32)iGpffffb9e8);
    while (node != NULL) {
        if (((Ext *)node)->scale != 0.0f) {
            scaled = func_00450490(((Ext *)node)->scale);
        }
        idx = 0;
        while (idx < 0x100) {
            u8 ch;
            ch = *(u8 *)((u8 *)node + 0x10 + idx);
            if (ch == 0) {
                break;
            }
            if (ch != 0x20) {
                if (*(f32 *)((u8 *)node + 0xC) == 0.0f) {
                    u32 v;
                    f32 x0;
                    f32 y0;
                    f32 x1;
                    f32 y1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 j;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)idx;
                    x0 += ((Ext *)node)->x;
                    y0 = ((Ext *)node)->y;
                    x1 = 11.0f + x0;
                    y1 = 11.0f + y0;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    quads[0] = x0;
                    quads[1] = y0;
                    quads[16] = x1;
                    quads[17] = y0;
                    quads[32] = x0;
                    quads[33] = y1;
                    quads[48] = x1;
                    quads[49] = y1;
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    depth = D_008872F8[0] - ((Ext *)node)->unk110;
                    j = 0;
                    while (j < 4) {
                        f32 *quad;
                        quad = &quads[j * 16];
                        quad[2] = depth;
                        quad[8] = (f32)(u32)((Ext *)node)->col[0];
                        quad[9] = (f32)(u32)((Ext *)node)->col[1];
                        quad[10] = (f32)(u32)((Ext *)node)->col[2];
                        quad[11] = (f32)(u32)((Ext *)node)->col[3];
                        quad[6] = invW;
                        quad[4] = uv[j * 2];
                        quad[5] = uv[j * 2 + 1];
                        j += 1;
                    }
                    D_00887310[0](4, quads, 4);
                } else {
                    u32 v;
                    f32 x0;
                    f32 y0;
                    f32 x1;
                    f32 y1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 j;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)idx;
                    x0 += ((Ext *)node)->x;
                    y0 = ((Ext *)node)->y;
                    x1 = 11.0f + x0;
                    y1 = 11.0f + y0;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    quads[0] = x0;
                    quads[1] = y0;
                    quads[16] = x1;
                    quads[17] = y0;
                    quads[32] = x0;
                    quads[33] = y1;
                    quads[48] = x1;
                    quads[49] = y1;
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    j = 0;
                    while (j < 4) {
                        f32 *quad;
                        quad = &quads[j * 16];
                        quad[2] = scaled;
                        quad[8] = (f32)(u32)((Ext *)node)->col[0];
                        quad[9] = (f32)(u32)((Ext *)node)->col[1];
                        quad[10] = (f32)(u32)((Ext *)node)->col[2];
                        quad[11] = (f32)(u32)((Ext *)node)->col[3];
                        quad[6] = invW;
                        quad[4] = uv[j * 2];
                        quad[5] = uv[j * 2 + 1];
                        j += 1;
                    }
                    D_00887310[0](4, quads, 4);
                }
            }
            idx += 1;
        }
        node = node->next;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_0044fa90);
#endif

/* measured: declaration order maps temp_16/var_17/var_18/var_19 to retail
   $s0/$s1/$s2/$s3; integer-domain grid indexing and the stack-base expression
   reproduce the retail post-multiply address order. Object 416B/window 416B,
   exact MATCH. */
/* measured: the residual at offsets 0xF4/0xF8 was an address-materialisation
   order/width choice. Converting the pointer through a named s32 local emits
   retail's addu $v1,$s3,$sp; addiu $v1,$v1,0x60 pair before lb $a1,0($v1). */
// FUN_00450050
void func_00450050(s64 arg0, const char* arg1, ...) {
    va_list args;
    s8 sp60[0x100];
    f32 arg0hi;
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 temp_16;
    s8 temp_5;
    s32 read_int;
    u8 *read;

    arg0hi = *(f32 *)((u8 *)&arg0 + 4);
    va_start(args, arg1);
    func_00446ed8(sp60, arg1, args);
    var_18 = (s32)(*(f32 *)&arg0);
    var_17 = (s32)arg0hi;
    var_19 = 0;
    temp_16 = var_18;
    while (var_19 < 0x100) {
        if ((*(f32 *)&arg0 < 53.0f) && (arg0hi < 40.0f) && (var_18 < 0x35) && (var_17 < 0x28)) {
            read_int = (s32)((u8 *)sp60 + var_19);
            read = (u8 *)read_int;
            temp_5 = *(s8 *)read;
            if (temp_5 != 0) {
                if (temp_5 == 0xA) {
                    var_18 = temp_16;
                    var_17 += 1;
                } else {
                    if ((var_17 == 0x27) && (var_18 >= 0x35)) {
                        func_00440b68((char *)&iGpffffac30 + 0x10, temp_5);
                    } else {
                        *(u8 *)((u32)D_008BF720 + (u32)(var_17 * 0x35) + (u32)var_18) = temp_5;
                    }
                    var_18 += 1;
                }
                var_19 += 1;
                continue;
            }
        }
        break;
    }
}

// FUN_004501F0
void func_004501f0(s64 arg0, s32 arg1, s32 arg2, ...) {
    va_list args;
    u8 *temp_2;
    HDbText3D *var_4;
    HDbText3D *temp_3;
    f32 arg0hi;

    arg0hi = *(f32 *)((u8 *)&arg0 + 4);
    func_0044ec50(1);
    func_0044ea90(D_00710500, 0x1EA);
    temp_2 = D_008873F4[0](1, 0x118, 0x40000);
    if (temp_2 != NULL) {
        func_0044ec50(0);
        va_start(args, arg2);
        func_00446ed8(temp_2 + 0x10, (void *)arg2, args);
        *(f32 *)(temp_2 + 4) = *(f32 *)&arg0;
        *(f32 *)(temp_2 + 8) = arg0hi;
        *(s32 *)(temp_2 + 0xC) = 0;
        *(RGBA8 *)(temp_2 + 0x114) = *(RGBA8 *)((u8 *)&arg1 + 0);
        *(s32 *)(temp_2 + 0x110) = 0;
        var_4 = iGpffffb9dc;
        if (var_4 == NULL) {
            iGpffffb9dc = (HDbText3D *)temp_2;
            return;
        }
        do {
            temp_3 = var_4->next;
            if (temp_3 == NULL) {
                var_4->next = (HDbText3D *)temp_2;
                break;
            }
            var_4 = temp_3;
        } while (1);
    }
}

// FUN_00450340
void func_00450340(s64 arg0, s32 arg1, ...) {
    va_list args;
    u8 *temp_2;
    HDbText3D *var_4;
    HDbText3D *temp_3;
    f32 arg0hi;

    arg0hi = *(f32 *)((u8 *)&arg0 + 4);
    func_0044ec50(1);
    func_0044ea90(D_00710500, 0x20A);
    temp_2 = D_008873F4[0](1, 0x118, 0x40000);
    if (temp_2 != NULL) {
        func_0044ec50(0);
        va_start(args, arg1);
        func_00446ed8(temp_2 + 0x10, (void *)arg1, args);
        *(f32 *)(temp_2 + 4) = *(f32 *)&arg0;
        *(f32 *)(temp_2 + 8) = arg0hi;
        *(s32 *)(temp_2 + 0xC) = 0;
        *(s32 *)(temp_2 + 0x110) = 0;
        *(u8 *)(temp_2 + 0x117) = 0xFF;
        *(u8 *)(temp_2 + 0x116) = 0xFF;
        *(u8 *)(temp_2 + 0x115) = 0xFF;
        *(u8 *)(temp_2 + 0x114) = 0xFF;
        var_4 = iGpffffb9dc;
        if (var_4 == NULL) {
            iGpffffb9dc = (HDbText3D *)temp_2;
            return;
        }
        do {
            temp_3 = var_4->next;
            if (temp_3 == NULL) {
                var_4->next = (HDbText3D *)temp_2;
                break;
            }
            var_4 = temp_3;
        } while (1);
    }
}
