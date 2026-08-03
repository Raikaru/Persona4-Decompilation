/* Consolidated Persona 4 source units. */
/* Original translation unit sdkDbprt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)

typedef struct HDbText3D HDbText3D;
struct HDbText3D
{
    HDbText3D* next; // 0x00
};
typedef struct { u8 b0, b1, b2, b3; } RGBA8;

static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];
static HDbText3D* sText3DList;

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

static void *sFontWork;   /* gp -0x4620 (0x00764AD0) */
static u8 *sFontFile;     /* gp -0x461C (0x00764AD4) */
static s32 *sRaster;      /* gp -0x4618 (0x00764AD8) */

/* text3d helpers */
extern void func_0044ec50(s32 arg0);
extern void func_0044ea90(const void *file, s32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void func_00446ed8(void *buf, const void *fmt, void *va);

typedef char *va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)


// FUN_0044F570
void func_0044f570(s32 arg0) {
    u8 *h1;
    u8 *h2;
    s32 *raster;

    func_00440b68("%s %d", D_00710500, 0x4F);
    h1 = func_00454a60((u8 *)D_00710510, 0);
    func_00456150(h1);
    func_00440b68("%s %d", D_00710500, 0x52);
    h2 = func_00454a60((u8 *)D_00710530, 0);
    func_00456150(h2);
    func_00454bd0(h2);
    sFontFile = func_003eaf60((u8 *)D_00710510);
    sFontWork = (void *)arg0;
    func_00454bd0(h1);
    raster = func_003ec590(*(s32 *)(sFontFile + 4), *(s32 *)(sFontFile + 8), 4, 0x4504);
    sRaster = raster;
    func_003ec180((u8 *)raster, (s32 *)sFontFile);
    func_003ea370((s32 *)sFontFile);
    sFontFile = NULL;
    func_0043f9c8(D_008BF720, 0x20, 0x848);
    sText3DList = NULL;
}

// FUN_0044F6B0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));

    curr = sText3DList;
    sText3DList = NULL;
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
/* measured: retail keeps the D_00887300 render-vtable base in $s1 and the
   D_008BF720 grid row base (grid + var_18*0x35) hoisted in $s0 across the
   glyph loop, and loads sFontWork into caller-saved $a0 (reloaded at the
   func_003e8110 tail); mwcc b210 with the u32-cast base hoist lands the base
   in $s0, keeps sFontWork in saved $s3 across the body, and re-orders the
   glyph quad/UV position arithmetic (the 12x12 cell corners and 0.0625/0.046875
   UV block) differently from retail. Frame (0x190) and the D_00887300 calls
   match; nf-diff 175. */
// FUN_0044F720
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_0044f720);

/* measured: retail iterates the sText3DList nodes and renders each glyph into
   the 4x0x40 quad buffer (sp+0x40) with the byte-color conversion (lbu + bltz
   guard, then cvt.w.s or srl/or + doubling) and the same 12x12-cell / 0.0625
   UV block as func_0044f720; mwcc b210 reorders the color-conversion branches
   and glyph arithmetic across the two scale paths (f21 vs var_f20). nf-diff 342. */
// FUN_0044FA90
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_0044fa90);

/* measured: retail renders the formatted string into the 12x12 grid with the
   grid-index (D_008BF720 + var_17*0x35 + var_18) built base-into-$v1 AFTER the
   multiplier and the sp60[var_19] byte read as a 2-step `addiu $v1,$v1,0x60` +
   `lb`; mwcc b210 emits the D_008BF720 base FIRST (lui/addiu before the mult)
   and folds the 0x60 into the load offset, and places the loop condition check
   at the top instead of retail's bottom. Register allocation (var_18->$s2,
   var_17->$s1, var_19->$s3, saved_x->$s0) matched via declaration order
   `var_19, var_18, var_17, saved_x`; the rest is the load-scheduling floor.
   nf-diff 42. */
// FUN_00450050
INCLUDE_ASM("asm/nonmatchings/sdkDbprt", func_00450050);

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
        var_4 = sText3DList;
        if (var_4 == NULL) {
            sText3DList = (HDbText3D *)temp_2;
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
        var_4 = sText3DList;
        if (var_4 == NULL) {
            sText3DList = (HDbText3D *)temp_2;
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

