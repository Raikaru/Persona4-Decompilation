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
static HDbText3D* iGpffffb9dc; /* gp -0x4624 (0x00764ACC) */

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

static void *iGpffffb9e0;   /* gp -0x4620 (0x00764AD0) */
static u8 *iGpffffb9e4;     /* gp -0x461C (0x00764AD4) */
static s32 *iGpffffb9e8;      /* gp -0x4618 (0x00764AD8) */

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
/* Floor (measured 2026-09-17, source-repo only): quad-base hoist (qf/qi locals over quads[i*16]) 163 -> 124 words, fnalign 218/218/74; the +10-instr over-emission is gone (was 230 obj vs 220 retail: the four qi stores each recomputed (i*16+k)*4, the sll+5/addu+4/addiu+3 opclass surplus). Singles sweep on the 163 body: opt_unroll_loops off, opt_strength_reduction off, opt_dead_assignments off all neutral (genuinely inert, verified byte-identical objects; b210 ignores them here), peephole off 166, cse 192, sched 196, prop 211, loop-inv 219. Re-sweep on the 124 body: same three neutral, cse 173, loop-inv 171, peephole 140, sched 198, prop 199. Tried: f878/white const hoists (125, white rematerialises per-iter), block-scoped row/col counters (neutral at 124). Prior: w2 163 best (w1 202, w3 s64 230, loop 219, sched 196, prop 211). Frame MATCH, vtBase hoist restores 7+1 jalr, dead low branch kept. Banked as guarded floor; production stays ASM. */
/* measured 0044f720 (owner, 2026-09-19): fnalign **74 -> 72 edits**, count
   218 -> 216 against retail 218, by turning one constant-bound `for` loop into
   the `do { } while` retail emits.  A `for (i = <const>; i < <const>; i++)` compiles
   with a guard before the first iteration; retail has none, because the loop provably
   runs at least once and the original source said so.
   This is the same lever as the `loop_N:` goto sweep but reaches ordinary `for` loops,
   which that sweep could not see.  Across the 40 floors with the most constant-bound
   loops, 21 improved and 19 had no loop that helped - and only ONE loop per function
   was ever the right one, so each loop is measured separately rather than converting
   them all. */
// FUN_0044F720 NONMATCHING
#ifdef NON_MATCHING
void func_0044f720(void)
{
    extern s32 func_003e8120(s32 arg0);
    extern void func_003e8110(s32 arg0);
    extern void func_0044fa90(void);
    extern void func_00450630(void);
    extern void (*D_00887300[])(u32, u32);
    extern void (*D_00887304[])(s32, s32 *);
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern f32 D_008872F8[];
    f32 uv[8];
    f32 quads[64];
    s32 save;
    f32 inv;
    f32 rowY;
    f32 rowY1;
    s32 row;
    s32 col;
    u32 vtBase;
    u8 *gridRow;

    inv = 1.0f / *(f32 *)((u8 *)iGpffffb9e0 + 0x80);
    if (func_003e8120((s32)iGpffffb9e0) != 0) {
        D_00887304[0](14, &save);
        vtBase = (u32)D_00887300;
        ((void (*)(u32, u32))*(u32 *)vtBase)(14, 0);
        ((void (*)(u32, u32))*(u32 *)vtBase)(6, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(7, 2);
        ((void (*)(u32, u32))*(u32 *)vtBase)(8, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(9, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(12, 1);
        ((void (*)(u32, u32))*(u32 *)vtBase)(1, (u32)iGpffffb9e8);
        {
            s32 i;
            for (i = 0; i < 4; i++) {
                f32 *qf = &quads[i * 16];
                s32 *qi = (s32 *)qf;
                qf[6] = inv;
                qi[8] = 0x437F0000;
                qi[9] = 0x437F0000;
                qi[10] = 0x437F0000;
                qi[11] = 0x437F0000;
                qf[2] = D_008872F8[0];
            }
        }
        row = 0;
        do {
            gridRow = (u8 *)((u32)D_008BF720 + (u32)(row * 0x35));
            rowY = 12.0f * (f32)row;
            rowY1 = 11.0f + rowY;
            for (col = 0; col < 0x35; col++) {
                u8 ch;
                ch = *(u8 *)((u8 *)gridRow + col);
                if (ch != 0x20) {
                    u32 v;
                    f32 x0;
                    f32 x1;
                    s32 low;
                    s32 tmp;
                    f32 u0;
                    f32 vv0;
                    s32 k;
                    v = (ch - 0x20) & 0xFF;
                    if ((s32)v >= 0x80) {
                        v = (v - 0x20) & 0xFF;
                    }
                    x0 = 12.0f * (f32)col;
                    x1 = 11.0f + x0;
                    quads[0] = x0;
                    quads[1] = rowY;
                    quads[16] = x1;
                    quads[17] = rowY;
                    quads[32] = x0;
                    quads[33] = rowY1;
                    quads[48] = x1;
                    quads[49] = rowY1;
                    low = (s32)((v & 0xFF) & 0xF);
                    tmp = (s32)(v & 0xFF);
                    if (tmp < 0 && low != 0) {
                        low -= 0x10;
                    }
                    u0 = 0.0625f * (f32)low;
                    vv0 = 0.0625f * (f32)(s32)((v & 0xFF) >> 4);
                    uv[0] = u0;
                    uv[1] = vv0;
                    uv[2] = 0.046875f + u0;
                    uv[3] = vv0;
                    uv[4] = u0;
                    uv[5] = 0.046875f + vv0;
                    uv[6] = 0.046875f + u0;
                    uv[7] = 0.046875f + vv0;
                    k = 0;
                    while (k < 4) {
                        f32 *quad;
                        f32 *uvp;
                        quad = &quads[k * 16];
                        uvp = &uv[k * 2];
                        quad[4] = uvp[0];
                        quad[5] = uvp[1];
                        k += 1;
                    }
                    D_00887310[0](4, quads, 4);
                }
            }
            row++;
        } while (row < 0x28);
        func_0044fa90();
        func_00450630();
        ((void (*)(u32, u32))*(u32 *)vtBase)(14, save);
        func_003e8110((s32)iGpffffb9e0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_0044f720);
#endif

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
