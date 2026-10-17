#include "model_motion_internal.h"
typedef signed __int128 s128;
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern f32 fGpffff9cA0;
extern f32 fGpffff9cA4;
extern s128 D_005E5740;
extern s128 D_005E5750;
struct RwMatrixTag;
extern s32 func_00366c70(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb, s32 alpha, s32 mode, s16 centerX, s16 centerY, struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2]);
extern f32 fGpffff84a4;
extern u8 iGpffffb1d8;
extern u8 iGpffffb1d4;
extern u8 iGpffffb1d0;
extern f32 sinf();
extern void PrimDrawFlatRectangle(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void PrimDrawPoints(void *arg0, void *arg1, f32 fparg0, s32 arg2,
                          s32 arg3, s32 arg4);
extern f32 fGpffff8478;
extern f32 cosf(f32 fparg0);
extern s32 mdlCopyIndexedMatrix(void *arg0, s32 arg1, void *arg2);
extern void mdlApplyModelMatrix(void *arg0, void *arg1, s32 arg2);
extern void func_002ab550(void *arg0, void *arg1);
extern void mdlAdvanceModelFromFlags(void *arg0);
static inline s32 code1_0012_stride(s32 index, s32 base)
{
    return index + base;
}
static inline s32 code1_0012_stride_loop(s32 base, s32 index)
{
    return base + index;
}

extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);

extern void cldDayChangeStartTask();
extern s32 D_00796670[];
extern u8 D_005E50D0[];
extern u8 D_005E5870[];
extern u8 *resourceFindByName(char *filename);
extern void calendarSetMode(s32 arg0);

extern void cldTimeChangeCreate();

extern s32 iGpffffb1e0;
extern s32 iGpffffb1e8;
extern s32 iGpffffb1cc;
extern s32 iGpffff9c58;
extern void fclBankTableReset(void);

extern s32 func_00121af0(u8 *task);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(char *name, u8 *task);
extern void fadeUpdateCallback(void *arg0, u8 *arg1);
extern void calendarDrawBackdrop(void *unusedNode, void *work);
extern char D_00796340[];
extern char D_00795F50[];
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s32 calGetDayTableValue(s16 arg0, s16 arg1);
extern s32 FldStepIndex(void);
extern s32 evtHasTaskHandle(void);
extern s32 iGpffffb1c8;
extern s32 datGetPendingDateIndex(void);
extern s32 datGetPendingTimeSlot(void);
extern s32 datGetPendingFlag(void);
extern void datSetPendingDateIndex();
extern void datSetPendingTimeSlot();
extern void datSetPendingFlag();
extern s32 calHasDayEntry();
extern void func_00260450(void);
extern s16 clndGetPeriod(void);
extern s16 clndGetDaysSinceApr5(void);
extern void calendarSyncFromDate(void);
extern s32 func_00268990(s32 arg0);
extern void fclBankTableInit(void);
extern void poolFree(s32 arg0);
extern void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern void sdkListStateConfigure(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void sdkListStateSetSecondaryMasks(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 sdkListStateHandleInput(void *arg0);
extern s32 sdkListStateGetCursor(void *arg0);
extern u16 D_008C024E[];
extern void sprintf(void *arg0, const char *arg1, ...);
extern s32 H_Cdvd_LookupRequest(void *arg0, s32 *arg1);
extern void *mdlCreateModelObjectFromMemory(u32 arg0, u16 arg1, void *arg2, u32 arg3, u32 arg4);
extern s32 mdlPrepareModel(void *arg0);
extern u8 D_005E5560[];
extern u8 D_005E5570[];
extern void datCarryOverPersistentState(void);
extern s32 shdWindowTaskCreate(u8 *arg0, s32 arg1, s32 arg2);
extern void shdWindowMarkDone(s32 arg0);
extern s32 shdWindowQueryState(s32 arg0);
extern s32 mcIconTaskCreate(u8 *arg0, s32 arg1);
extern s32 mcIconTaskPoll(void);
extern s32 titleSlotSetMode(u8 *arg0, s32 arg1);
extern void sdkSpriteFreeNode(void *node);
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5, f32 z, s32 arg6);
extern s32 nLineIsIdle(void);

typedef struct {
    u8 pad0[0x18];
    s32 field_18;
} B810Obj;

extern s32 kwlnTaskIsLinked();
extern void *kwlnTaskGetWork();
extern void kwlnTaskDestroyWithHierarchy();

typedef struct {
    u8 pad0[4];
    s32 field_4;
} C1A0Obj;
typedef struct {
    f32 x;
    f32 y;
} SVec2_0012;

extern void func_003ef3a0(void *arg0);
extern void radarAnimateValue(u8 *arg0, s32 arg1, s32 arg2);
extern void datCommunityEntryStep(u8 *arg0);
extern s32 chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005E57B8[];
extern u8 D_005E57D0[];
extern s32 titleSoundStartStep(u8 *arg0);
extern void radarDrawPanel(u8 *arg0);
extern void radarStepSlotAnimB(u8 *arg0);
extern void radarStepPairAnim(u8 *arg0);
extern s32 calendarStateTask(u8 *task);
/* Calendar state block at iGpffffb1dc: header fields, five 0x30-byte records from 0x20, owner pointer at 0x110. */
typedef struct CalendarRecord {
    f32 field_00;
    f32 field_04;
    f32 field_08;
    f32 field_0C;
    f32 field_10;
    f32 field_14;
    s8 field_18;
    s8 field_19;
    u8 field_1A;
    u8 pad_1B[0xD];
    s32 field_28;
    s32 field_2C;
} CalendarRecord;

typedef struct CalendarState {
    s32 state; /* 0 init, 1 load, 2 done */
    s16 daysSinceApr5;
    s16 period;
    s16 field_08;
    s16 field_0A;
    s32 field_0C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    CalendarRecord records[5];
    s32 field_110;
} CalendarState;

extern u8 *iGpffffb1dc;
extern s32 clndPromptUpdate(u8 *arg0);
extern u8 D_005E5170[];
extern u8 D_005E5180[];
extern u8 D_005E5190[];
extern u8 D_005E51A0[];
extern u8 D_005E51B0[];
extern void clndPromptDestroy(u8 *arg0);
extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern void kAssertFail(const void *file, s32 line);
extern u8 D_005E5548[];
extern s32 datItemCount(s16 id);
extern u8 D_005E76C8[];
extern u8 D_005E5720[];
extern s32 func_0012aa70(u8 *arg0);
extern void titleLoaderTeardown(u8 *task);
extern void sdkSpritePackDestroy(s32 arg0);
extern void H_Cdvd_Destroy(s32 arg0);
extern void sdkSndStopChannel(s32 arg0);
extern void mdlDestroyModelObject(s32 arg0);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s16 datBuildPartyIdList(void *arg0);
extern u8 *sdkSpriteNewNode(u32 sprites, u32 index);
extern u8 D_005E5F40[];
extern u8 D_005E7670[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern s32 datGetFlag(s32 arg0);
extern u8 D_005E5810[];
extern s32 D_005E5B60[];
extern u8 D_005E5BB8[];
extern u8 D_005E76C8[];
extern void titleCollectFlaggedIds(u8 *arg0);
extern s32 titleSetMenuLayout(u8 *arg0, u32 arg1);
typedef struct {
    u8 b[4];
} PanelRgba;

void drawNumberSprites(Vec2f position, f32 depth, PanelRgba color, u32 number, s32 sprites);

typedef struct {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    u8 pad10[0xC];
    u8 c1c;
    u8 c1d;
    u8 c1e;
    u8 c1f;
} Frame00121DE0;
/* measured: closes the opt_propagation bracket for fadeUpdateCallback. */
#pragma opt_propagation on

/* measured: closes the optimization_level bracket at the file's -O2 baseline (nd 0). */
#pragma optimization_level 2

extern void *RwMatrixRotate(void *m, void *src, f32 angle, s32 mode);
extern void *func_003e4320(void *dst, void *src, void *m);
extern void *RwMatrixScale(void *m, void *v, s32 mode);
extern void *RwMatrixTranslate(void *m, void *v, s32 mode);
extern u8 D_005E55B0[];
extern u8 D_005E55B8[];
extern u8 D_005E55C0[];
extern u8 D_005E55C8[];
extern u8 D_005E55D0[];
extern u8 D_005E55D8[];

typedef struct {
    u8 q[8];
    f32 f;
} Code1GlobalPair12;

#pragma opt_propagation on
/* Floor: 844 differing words (was 900), 967 of 964 instrs (+3, +0.3% well inside 3% band, 26 slack to 993 edge; was 993/+29 edge), 932 fnalign edits (was 1077). Surplus was 6 extra clamped float->u8 (cvt.w.s/mfc1 +12, c.ole/sub/bc1t +6, lui +6) from double-converting white via f intermediates + a2; fix is u32 r/g/b for retail's unsigned bltz/srl doubling, a0 as (s32)(f32)*(s32 *) for lwc1/cvt.s.w/cvt.w.s/mfc1, and 5 of 6 f intermediates folded to direct sums (first f0 double retained to center count). Cheap causes ruled out: all literals f-suffixed, 13 jals both with no __ soft-float relocs, no 2.0f in body (mul.s 3/3). Gate 8 inside 0 outside. Body also at docs/probe_archive/Lane0012_00124f70_body.c; production stays ASM. */
/* measured 2026-09-18: reconstructed from bare marker (retail 0x00124F70, 3856B window, 964 instrs). v1c baseline 921 (Ghidra-direct, [6] frame exact at 0x360; [8] gave 0x370 at 922). v2 908 (-13: D_5530/40 array not scalar + 002aaf20 640/448 not 512/480,512/1216). v3 904 (-4: flag beqz polarity + col order + buffers address-ascending). v4 903 (-1: buffers descending, first-declared highest per micro stacktest2). v5 900 (-3: explicit p5234/5230/524C/5248/5244/5240/523C/5238 locals, first two spill to 0xA0/0xB0). Free pragmas tie/worse: loopinv 922 (+1), nounroll 921 tie, sched 921 tie, propoff 943 (+22), commonsubs 940 (+19). 7o eight skipped: body already in 7o form (bare decls + statement assigns, no Type name = ...; initialisers). Full proof in archive. */
/* Title palettes contain six complete four-byte RGBA values. Native value
 * assignment through the byte-storage view preserves the copied object.
 * Measured: 3852/3856 bytes, with one zero alignment word. */

typedef union { f32 value; u8 bytes[4]; } TitleDrawColor;
typedef char TitleDrawColorSizeCheck[sizeof(TitleDrawColor) == 4 ? 1 : -1];
static inline u8 *titleCopyValue(u8 *destination, const u8 *source)
{
    *(TitleDrawColor *)destination = *(const TitleDrawColor *)source;
    return destination;
}

static inline void titleRectangle(u8 *color, f32 x, f32 y, f32 depth, f32 width, f32 height, s32 flags, void *parent)
{
    extern void func_002aaf20(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *parent);
    func_002aaf20(x, y, depth, color, width, height, flags, parent);
}
static inline f32 titleBlend(f32 delta, f32 blend, f32 value)
{
    return value + delta * blend;
}

static inline u8 titlePaletteChannel(u32 value, u32 target, f32 blend)
{
    return (u8)titleBlend((f32)(target - value), blend, (f32)value);
}

typedef struct { u32 words[6]; } TitlePalette;
typedef char TitlePaletteSizeCheck[sizeof(TitlePalette) == 24 ? 1 : -1];
static inline void titlePaletteCopy(TitlePalette *destination, const TitlePalette *source)
{
    const s32 *src = (const s32 *)source->words;
    s32 *dst = (s32 *)destination->words;
    s32 count = 3;
    do {
        s32 first = src[0];
        s32 second = src[1];
        src += 2;
        count--;
        dst[0] = first;
        dst[1] = second;
        dst += 2;
    } while (count > 0);
}

static inline u32 titleCopySelect(u8 *destination, const u8 *source, s32 byteOffset)
{
    *(TitlePalette *)destination = *(const TitlePalette *)source;
    return *(u32 *)(destination + byteOffset);
}

#pragma push
#pragma always_inline on
#pragma pop
extern s32 shdSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 * arg4, s32 arg5);
extern void titleSkyApplyBasePreset(void);
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern s32 D_005E55E0[];
extern s8 D_005E5610[];
extern void (*D_00887300[])(s32 arg0, s32 arg1);

extern s32 shdSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5);
extern s32 shdSpriteDrawNowEx(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5,
                         s16 arg6, s16 arg7, f32 farg3, f32 farg5, f32 farg4);

extern void titleSkyApplyBasePreset(void);
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
typedef struct { u8 c0, c1, c2, c3; } __attribute__((aligned(4))) TitleColor;
typedef struct { s128 bits; } TitleRect;
extern TitleRect D_005E5590;
extern TitleRect D_005E55A0;

static inline void titleRing(f32 x, f32 y, s32 color, f32 scale, f32 angle, u8 *texture)
{
    f32 size = 64.0f * scale;

    shdSpriteDrawNowEx(x - size, y - size, 0.0f, color, 0x80, 0x1000F, 0, texture, 0, (s16)size, (s16)size, angle,
                  scale, scale);
}

/* 1288/1296 bytes (two words of padding); relocations: D_005E5590,
   D_005E55A0, this function's literal pool at gp-0x7DD0..-0x7D64, and the
   called functions.  The eight rings share one inline shape: size is
   64 * scale, the position is the centre minus size, and b210 folds each
   product and difference into the pool (radius, x, y, scale per ring) while
   still converting the radius at run time.  The screen colour and the two
   rectangles are copied into scratch locals declared ahead of their
   sources, which is what fixes retail's frame slots (0x7C/0x60 above
   0x78/0x74/0x70 and 0x50/0x40). */
/* The caller passes 0.0f in $f12-$f14 ahead of the colour and task
   (retail titleDrawTaskView); the three floats are unused here. */
/* measured: archived build/func_001265a0_floor_v1.c (1791L m2c) + jtbl-bound fix cases 10-15 to tail per ELF jtbl_00746730 dump at file-off 0x6467B0 (16 entries 0:26660,1-2:26664,3:26688,4-5:2679C,6-7:29778,8-9:2A024,10-15:2A948 tail; sltiu 0xa->0x10 exact). Installed fnalign retail 4404/object 4404 (exact, 0.0%, 80 edits +124 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_0012.c func_001265a0`; probe 3842 words via measure_guarded. Candidate-method fnalign (--candidate floor) reports retail 4400/object 3779 (-14.1%, 6325 edits) due to scratch-vs-real TU compilation difference (header/guard placement), not body quality; installed is exact. Call census: all 202 retail jals +14 jalr have counterparts (30x0045d6e0,22x0025f3f0,17x0044b7b0,14x003f6440/002aaf20/002aaac0,11x0048a000/00489f80,etc.). Loops: 40 retail backward branches (30x6-instr zeroing +8x8-instr bgtz copy +3 large 414/240/240 at 0x126D9C/0x12742C/0x129B0C) all present as draft loop_93/loop_128/loop_351 + 4-word do-whiles. Frame -0x6C0 exact, sltiu 0x10 exact. Residual 80 edits are lui symbol materialization (0x5e vs 0) + MMI lq/add_a.w vs plain + VU0 adda/madd + scheduling, no missing regions by address (no deletes in installed alignment). */
/* gate: func_001265a0 is INSIDE the +-3% band at 4404 against retail 4404 (+0.0%, band
   4272-4536), deficit 0, via --candidate measurement 2026-09-20.  Filled the 46-run
   (0x12A794-0x12A84C) that deficit_scan named ABSENT: the empty-if at 0x12A7F4 is the
   same defect as its 0x12A794 neighbour - retail's 0.25f normalization
   ((f32)(0x20<<16)+0.25f*(f32)((0x20-0x24)<<16)-(f32)0x28), (s32) compare, recomputed $3
   ((f32)$2+$f1), and 32.0f*((f32)$3/65535.0f)+327.0f madd for the first 0x10006
   shdSpriteDrawNow call, which m2c had left as an empty if plus blend/0.0f args.  The 46
   dissolves into small register-color replaces; deficit_scan now reports only CROSS runs
   (2350 at 0x127930, 142 at 0x129E18, 48 at 0x12A6F8) with mtc1 +207/lui +108/sb +40.
   Prior stamp described 4348/4400 -1.2% deficit 52 (15 color channels + quantized factor;
   159-run and 104-run dissolved; 2350/142/46 phantoms + sb+40/lwc1+37/empty-if gaps) and
   3779/-14.1% floor, kept for history.  Candidate fnalign is 6509 edits +15 reloc-only,
   probe 3903 words (base 3899); installed TU stays 74 MATCH/8 ASM with func_0012d630
   untouched.  The old 4404/4404 +0.0% 80-edit number came from running `fnalign.py
   <file> <func>` with NO --candidate on this guarded floor, which compiles the
   INCLUDE_ASM fallback and therefore aligns retail against itself; fnalign now refuses
   that invocation outright and tests/test_fnalign.py pins it. */
/* fix 2026-09-20: old 4404/4404 was two errors cancelling, not evidence the body was right. */
/* Historical count-only experiments used the wrong alpha-scratch value for
 * temp_10. Retail 0x1291FC keeps 137.0f * scale in f2 while f0 converts alpha;
 * 0x129268 then converts f2 and narrows its signed integer to 16 bits. The
 * guarded source now preserves that independent value flow, not just width.
 * The adjacent scale uses separate mul.s/add.s rounding. Other upstream
 * ACC placeholders remain outside this bounded sprite-alpha repair. */
/* measured 2026-09-29: canonical TitleRect payload reads compile the guarded
 * body to 17072/17616 bytes, nd 3941. Earlier scores above are historical;
 * this body remains assembly-backed.
   2026-10-08: opt_lifetimes on lowers fnalign from 3558 to 3424 edits. */
/* 2026-10-09: 3424 -> 3340 edits: m2c's expanded float-to-unsigned conversions are plain (u32) casts. Open, found by comparing the retail lui constants: the m2c body drops several sinf results and leaves `temp_f20 * temp_f21 +/- temp_f7 * temp_f8` placeholders where retail has adda/madd chains with constants such as 200 - 700 * (1 - (1 + sin) / 2) (0x00126C48). */
static inline u8 *titleOffsetPtr_001265a0(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}

/* Matching notes for the title-screen draw:
 * - Rectangle and background-colour constants go through TitleRect /
 *   TitleDrawColor locals (retail stores each constant, then copies it);
 *   D_005E538C/D_005E53B4 are absolute arrays (lui/lw %lo).
 * - Task fields are TitleTaskView members so b210 does not hoist the
 *   address arithmetic; each (8,1)/(6,1) call pair uses an integer-cast
 *   fnTable so the table address stays in $s1.
 * - Palette glows follow titleDrawScene (titleCopySelect,
 *   titlePaletteChannel); alpha bytes convert float -> u8 inside the calls.
 * - Commutative FP orders come from reusing multi-definition floats
 *   (lerpT, temp_f2, temp_f13_28); 1 - t is a separate step.
 * - Range tests use retail's `> N - 1` / `> N` forms.
 * - The record-delta counter reuses temp_2 (dead there), so its live range is
 *   numbered after the hoisted 0xFFFFFF constant: retail's $s1/$s2.
 * - Record pointers 2-5 go through titleOffsetPtr_001265a0 (offset-first addu).
 */
#pragma push
#pragma opt_lifetimes on
typedef struct { u8 bytes[0x28]; } TitleRecordBlock;
static inline f32 *titleCopyRect(u8 *destination, const u8 *source)
{
    *(TitleRect *)destination = *(const TitleRect *)source;
    return (f32 *)destination;
}

typedef struct {
    u32 f00;
    u32 state;
    s32 f08;
    s32 timer;
    s32 f10;
    u8 pad0[0xc];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 pad1[0xc];
    u8 *sprites;
    u8 pad2[0x4];
    u8 *model0;
    u8 pad3[0x3c];
    u32 f84;
    s32 f88;
} TitleTaskView;
#include "btl_shuffle_draw_internal.h"
#define M2C_GUARD
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
void func_00124bb0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, u32 arg1, u32 arg2, f32 fparg6, s32 arg3, u32 *arg4);

void titleBuildPointRows(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 *arg1);

void titleDrawScene(s32 titleIndex, s32 brightness, s32 unusedArgument, s32 drawMode, u8 *sceneContext);

void titleDrawShadeBars(f32 x, f32 y, f32 depth, s32 arg0, u8 *arg1);

/* The draw queue supplies node+0x1C, then the task stored at node+0x10.
 * Only the task reaches the word-returning work accessor; the first payload
 * is a real, unused callback input. See Title_entry_contract_001265a0_20261003. */
// Kept in bucket: diff 395 when moved; cause not diagnosed (uses static inline titleCopyRect and titleCopySelect).
// FUN_001265A0
void titleDrawTaskView(void *unusedDrawData, void *task) {
    f32 temp_f21;
    u32 *temp_20;
    TitleTaskView *taskView;
    extern u8 D_005E5234[];
    extern u8 D_005E5238[];
    typedef union TitleRectangleWords { s128 bits; s32 words[4]; } TitleRectangleWords;
    extern s32 shdSpriteDrawNow(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern void titleSkyApplyBasePreset(void);
    extern void func_002ab380(f32 x, f32 y, f32 z, s32 color, s32 alpha, s32 mode, void *texture, s32 kind, void *extra);
    extern void func_002abb30(f32 x, f32 y, f32 z, s32 color, s32 alpha, f32 scale, s32 mode, u8 *object, void *extra);
    extern s32 RpSkyRenderStateSet();
    extern s32 RpSkyGetDisplayBufferRaster(void);
    extern s32 func_0043c6a0(s32);
    extern f32 sinf(f32);
    extern u32 kwlnTaskGetWork(void *task);
    extern s32 H_Cdvd_LookupRequest();
    extern s32 func_0045ad50();
    extern void func_0045c870(u8 *colors, s32 enabled);
    extern void PrimDrawFlatRectangle(u8 *color, f32 *rectangle, f32 depth, s32 saveState);
    extern s32 kAssertFail();
    extern s32 mdlPrepareModel();
    extern void mdlAdvanceModelFromFlags(u8 *);
    extern void mdlSetLayerWeight(u8 *model, s32 layer, f32 speed);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern u8 D_005E5230[];
    extern u8 D_005E523C[];
    extern u8 D_005E5240[];
    extern u8 D_005E5248[];
    extern u8 D_005E5254[];
    extern s32 D_005E5370[];
    extern s32 D_005E538C[];
    extern s32 D_005E5398[];
    extern s32 D_005E53C0[];
    extern f32 D_005E5374[];
    extern f32 D_005E5378[];
    extern f32 D_005E537C[];
    extern f32 D_005E5380[];
    extern f32 D_005E5384[];
    extern f32 D_005E5388[];
    extern f32 D_005E539C[];
    extern f32 D_005E53A0[];
    extern f32 D_005E53A4[];
    extern f32 D_005E53A8[];
    extern f32 D_005E53AC[];
    extern f32 D_005E53B0[];
    extern f32 D_005E53C4[];
    extern f32 D_005E53C8[];
    extern f32 D_005E53CC[];
    extern f32 D_005E53D0[];
    extern f32 D_005E53D4[];
    extern f32 D_005E53D8[];
    extern s32 D_005E53B4[];
    extern TitlePalette D_005E5530;
    extern u8 D_005E5548[];
    extern BtlShuffleVec3 D_005E5628;
    extern BtlShuffleVec3 D_005E5638;
    extern s128 D_005E5650;
    extern s128 D_005E5660;
    extern s128 D_005E5670;
    extern s128 D_005E5680;
    extern s128 D_005E5690;
    extern s128 D_005E56A0;
    extern u32 D_005E56B0[8];
    extern u8 D_005E56D0[];
    extern void (*D_00887300[])(s32, s32);
    extern f32 fGpffff9c70;
    extern f32 fGpffff9c74;
    extern f32 fGpffff9c78;
    extern f32 fGpffff9c7c;
    extern f32 fGpffff9c80;
    extern f32 fGpffff9c84;
    extern f32 fGpffff9c88;
    extern f32 fGpffff9c8c;
    extern f32 fGpffff82a0;
    extern f32 fGpffff822c;
    extern f32 fGpffff8228;
    extern f32 fGpffff8170;
    extern f32 fGpffff8110;
    extern f32 fGpffff80bc;
    extern f32 fGpffff81e0;
    extern f32 iGpffff81dc;
    extern f32 fGpffff8094;
    s32 var_19;

    TitleDrawColor sp6BC;
    s32 sp6B8;
    TitleDrawColor sp6B4;
    TitleDrawColor sp6B0;
    TitleDrawColor sp6AC;
    TitleDrawColor sp6A8;
    TitleDrawColor sp6A4;
    TitleDrawColor sp6A0;
    TitleDrawColor sp69C;
    TitleDrawColor sp698;
    TitleDrawColor sp694;
    TitleDrawColor sp690;
    TitleDrawColor sp68C;
    TitleDrawColor layerColor;
    TitleDrawColor layerColorSource;
    TitleDrawColor firstOverlayColor;
    TitleDrawColor firstOverlaySource;
    TitleDrawColor sp678;
    TitleDrawColor sp674;
    TitleDrawColor sp670;
    TitleDrawColor sp66C;
    TitleDrawColor sp668;
    TitleDrawColor sp664;
    TitleDrawColor sp660;
    TitleDrawColor sp65C;
    TitleDrawColor sp658;
    TitleDrawColor sp654;
    TitleDrawColor sp650;
    TitleDrawColor sp64C;
    TitleDrawColor sp648;
    TitleDrawColor sp644;
    TitleDrawColor sp640;
    TitleDrawColor sp63C;
    TitleDrawColor sp638;
    TitleDrawColor sp634;
    TitleDrawColor sp630;
    TitleDrawColor sp62C;
    TitleDrawColor sp628;
    TitleDrawColor sp624;
    TitleDrawColor sp620;
    TitleDrawColor sp61C;
    TitleDrawColor sp618;
    TitleDrawColor sp614;
    TitleDrawColor sp610;
    TitleDrawColor sp60C;
    TitleDrawColor sp608;
    TitleDrawColor sp604;
    TitleDrawColor sp600;
    TitleDrawColor sp5FC;
    TitleDrawColor sp5F8;
    TitleDrawColor sp5F4;
    TitleDrawColor sp5F0;
    TitleDrawColor sp5EC;
    TitleDrawColor sp5E8;
    TitleDrawColor sp5E4;
    TitleDrawColor sp5E0;
    TitleDrawColor sp5DC;
    TitleDrawColor sp5D8;
    TitleDrawColor sp5D4;
    BtlShuffleVec3 titleYawAxis;
    BtlShuffleVec3 titlePitchAxis;
    BtlShuffleVec3 titleTranslation;
    s128 sp590;
    BtlShuffleMatrix titleMatrix __attribute__((aligned(16)));
    union { u32 words[8]; f32 pairs[4][2]; } fadeUv;
    u32 *fadeUvSource;
    u32 *fadeUvDestination;
    s32 fadeAlpha;
    TitleRectangleWords sp520;
    TitleRectangleWords sp510;
    TitleRect sp500;
    TitleRect sp4F0;
    TitleRect sp4E0;
    TitleRect sp4D0;
    s128 sp4C0;
    TitleRect sp4B0;
    TitleRect sp4A0;
    s128 sp490;
    TitleRect sp480;
    TitleRect sp470;
    TitlePalette firstHighlight;
    TitlePalette firstBase;
    TitlePalette thirdHighlight;
    TitlePalette thirdBase;
    TitlePalette fourthHighlight;
    TitlePalette fourthBase;
    s128 sp3A0;
    TitleRect sp390;
    TitleRect sp380;
    s128 sp370;
    TitleRect sp360;
    TitleRect sp350;
    s128 sp340;
    TitleRect sp330;
    TitleRect sp320;
    s128 sp310;
    TitleRect sp300;
    TitleRect sp2F0;
    s128 sp2E0;
    TitleRect sp2D0;
    TitleRect sp2C0;
    s128 sp2B0;
    TitleRect sp2A0;
    TitleRect sp290;
    s128 sp280;
    TitleRect sp270;
    TitleRect sp260;
    s128 sp250;
    TitleRect sp240;
    TitleRect sp230;
    s128 sp220;
    TitleRect sp210;
    TitleRect sp200;
    s128 sp1F0;
    TitleRect sp1E0;
    TitleRect sp1D0;
    TitlePalette secondHighlight;
    TitlePalette secondBase;
    TitlePalette fifthHighlight;
    TitlePalette fifthBase;
    TitlePalette firstPalette;
    TitlePalette secondPalette;
    TitlePalette thirdPalette;
    TitlePalette fourthPalette;
    TitlePalette fifthPalette;
    u8 *var_3_10;
    u8 *var_3_12;
    u8 *var_3_14;
    u8 *var_3_16;
    u8 *var_3_18;
    u8 *var_3_20;
    u8 *var_3_22;
    u8 *var_3_24;
    u8 *var_3_27;
    u8 *overlayClearByte;
    u8 *var_3_31;
    u8 *var_3_33;
    u8 *var_3_4;
    u8 *var_3_5;
    f32 lerpT;
    void (**fnTable)(s32, s32);
    s32 paletteOffset;
    u32 packedColor;
    u32 packedBaseColor;
    u32 red;
    u32 green;
    u32 blue;
    f32 fadeT;
    f32 temp_f0_11;
    f32 temp_f0_5;
    f32 temp_f0_7;
    f32 temp_f0_9;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f16_3;
    f32 temp_q1;
    f32 temp_f1_28;
    f32 temp_f13_28;
    f32 temp_f1_11;
    f32 temp_f1_17;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f21_2;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    u8 *layerClearByte;
    u8 *var_3_11;
    u8 *var_3_13;
    u8 *var_3_15;
    u8 *var_3_17;
    u8 *var_3_19;
    u8 *var_3_21;
    u8 *var_3_23;
    u8 *var_3_25;
    u8 *var_3_28;
    u8 *var_3_32;
    u8 *var_3_3;
    s32 temp_16;
    s32 temp_17;
    s32 temp_2_19;
    s32 temp_2_24;
    s32 temp_2_26;
    u32 temp_2_27;
    s32 temp_2_2;
    s32 temp_3_19;
    s32 temp_3_20;
    s32 temp_3_21;
    u32 temp_3_22;
    s32 temp_3_23;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_5;
    s32 temp_f0_10;
    s32 temp_28;
    s32 temp_i28;
    s32 var_16;
    s32 temp_2;
    s32 var_17_2;
    s32 layerClearCount;
    s32 var_2_10;
    s32 var_2_11;
    s32 var_2_12;
    s32 var_2_13;
    s32 var_2_14;
    s32 var_2_15;
    s32 var_2_16;
    s32 var_2_17;
    s32 var_2_18;
    s32 var_2_19;
    s32 var_2_20;
    s32 var_2_21;
    s32 var_2_22;
    s32 var_2_23;
    s32 var_2_24;
    s32 var_2_25;
    s32 var_2_26;
    s32 var_2_27;
    s32 var_2_28;
    s32 var_2_29;
    s32 overlayClearCount;
    s32 var_2_30;
    s32 var_2_31;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_2_6;
    s32 var_2_7;
    s32 var_2_8;
    s32 var_2_9;
    s32 var_3_30;
    s32 var_4_17;
    s32 var_4_18;
    s32 temp_10;
    s32 temp_10_2;
    u32 var_3_26;
    u32 var_3_29;
    u32 *temp_2_11;
    u32 *temp_2_12;
    u32 *temp_2_23;
    u32 *temp_2_25;
    u32 *temp_2_3;
    u32 *temp_2_4;
    u32 temp_17_2;
    u32 temp_3;
    u8 *temp_21;
    u8 *temp_7;
    u8 *temp_7_2;
    u8 *temp_7_5;
    u8 *var_16_2;
    u8 *var_4;
    u8 *var_4_16;
    u8 *var_4_2;
    u8 *var_4_7;
    u8 *var_4_8;
    u8 *var_4_9;

    temp_20 = (u32 *)kwlnTaskGetWork(task);
    taskView = (TitleTaskView *)temp_20;
    titleYawAxis = D_005E5628;
    titlePitchAxis = D_005E5638;
    sp6B8 = 0;
    sp6B4.value = fGpffff9c70;
    sp6BC = sp6B4;
    func_0045c870((u8 *)&sp6BC, 1);
    temp_3 = (u32)(taskView->state);
    switch (temp_3) {
    case 0:
        taskView->f88 = 0;
        /* fallthrough */
    case 1:
    case 2:
        sp6B0.value = fGpffff9c74;
        sp6BC = sp6B0;
        func_0045c870((u8 *)&sp6BC, 1);
        break;
    case 3:
        sp6AC.value = fGpffff9c78;
        sp6BC = sp6AC;
        func_0045c870((u8 *)&sp6BC, 1);
        temp_2 = (s32)(taskView->f88 + 1);
        taskView->f88 = temp_2;
        if (temp_2 >= 0x14) {
            taskView->f88 = 0x14;
        }
        temp_f20 = (f32) taskView->f88 / 20.0f;
        sp6A8.value = fGpffff9c7c;
        sp6BC = sp6A8;
        sp520.bits = D_005E5650;
        lerpT = 1.0f - temp_f20;
        temp_f20 = 42.0f * lerpT;
        sp520.words[1] = (s32)-temp_f20;
        PrimDrawFlatRectangle((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp520), 0.0f, 1);
        sp510.bits = D_005E5660;
        sp510.words[1] = (s32)(406.0f + temp_f20);
        PrimDrawFlatRectangle((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp510), 0.0f, 1);
        break;
    case 4:
    case 5:
        temp_16 = (s32)(taskView->timer + 1);
        taskView->timer = temp_16;
        if (temp_16 > 0x19) {
            if (temp_16 < 0x74) {
                shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0x4C, 0, 0, taskView->sprites, 0);
            } else if (temp_16 < 0xA1) {
                temp_f20_2 = sinf((1.5707964f * (f32) (temp_16 - 0x73)) / 45.0f);
                shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, (u8)(255.0f * (fGpffff822c + fGpffff8228 * (1.0f - temp_f20_2))), 0, 0, taskView->sprites, 0);
            } else {
                shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0x2D, 0, 0, taskView->sprites, 0);
            }
            /* Retail colors at sp+0x684 and sp+0x688 are distinct four-byte objects. */
            layerClearByte = layerColorSource.bytes;
            layerClearCount = 4;
            if (layerClearByte != NULL) {
                do {
                    *layerClearByte = 0;
                    layerClearByte += 1;
                    layerClearCount -= 1;
                } while (layerClearCount != 0);
            }
            layerColorSource.bytes[3] = 0xFF;
            titleCopyValue((u8 *)&layerColor, (const u8 *)&layerColorSource);
            {
                /* Retail passes depth in f12 and saveState in a2 at both calls. */
                extern void PrimDrawFlatRectangle(u8 *color, f32 *rectangle, f32 depth, s32 saveState);
                sp4B0 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&layerColor, titleCopyRect((u8 *)&sp4C0, (const u8 *)&sp4B0), 0.0f, 1);
                sp4A0 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&layerColor, titleCopyRect((u8 *)&sp4C0, (const u8 *)&sp4A0), 0.0f, 1);
            }
            titleDrawShadeBars(0.0f, 0.0f, 0.0f, 0xFF, (u8 *)temp_20);
            if (temp_16 >= 0xCD) {
                /* Retail sp+0x67C is cleared bytewise before its independent value copy. */
                overlayClearByte = firstOverlaySource.bytes;
                overlayClearCount = 4;
                if (overlayClearByte != NULL) {
                    do {
                        *overlayClearByte = 0;
                        overlayClearByte += 1;
                        overlayClearCount -= 1;
                    } while (overlayClearCount != 0);
                }
                titleCopyValue((u8 *)&firstOverlayColor, (const u8 *)&firstOverlaySource);
                titleRectangle((u8 *)&firstOverlayColor, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                D_00887300[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_3 = sp624.bytes;
                var_2_3 = 4;
                if ((u8 *)(var_3_3) != NULL) {
                    do {
                        *var_3_3 = 0;
                        var_3_3 += 1;
                        var_2_3 -= 1;
                    } while (var_2_3 != 0);
                }
                sp624.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp628, (const u8 *)&sp624);
                sp480 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp628, titleCopyRect((u8 *)&sp490, (const u8 *)&sp480), 0.0f, 0);
                sp470 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp628, titleCopyRect((u8 *)&sp490, (const u8 *)&sp470), 0.0f, 0);
                mdlEffectEmitTagPair();
                temp_2_2 = (s32)(taskView->f10 + 1);
                taskView->f10 = temp_2_2;
                if (temp_2_2 >= 0x168) {
                    taskView->f10 = 0;
                }
                titleBuildPointRows(200.0f - 700.0f * (1.0f - (1.0f + sinf((((iGpffff81dc + ((fGpffff81e0 * (f32) taskView->f10) / 360.0f)))))) / 2.0f), 0.0f, 10.0f, 0xB2, (u8 *)temp_20);
            }
            if (temp_16 > 0x3d) {
                if (temp_16 < 0x11A) {
                    var_3_4 = sp6A4.bytes;
                    var_2_4 = 4;
                    if (var_3_4 != NULL) {
                        do {
                            *var_3_4 = 0;
                            var_3_4 += 1;
                            var_2_4 -= 1;
                        } while (var_2_4 != 0);
                    }
                    titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp6A4);
                    titleRectangle((u8 *)&sp6BC, 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x12, NULL);
                    sinf(((((1.5707964f * (f32) (temp_16 - 0x3D)) / 80.0f))));
                    for (var_19 = 1; (s32)var_19 < 8; var_19++) {
                        if ((u32) var_19 >= 0x13U) {
                            kAssertFail(D_005E5548, 0xD1);
                        }
                        temp_21 = (u8 *)&((TitleRecordBlock *)D_005E5230)[(s32)var_19];
                        temp_2 = (s32)((s32)(u32)(temp_16 - 0x3D) - M2C_FIELD(temp_21, s32 *, 0x20));
                        if (temp_2 > 0) {
                            var_2_5 = temp_2 - 0x32;
                            if (var_2_5 < 0) {
                                var_2_5 = 0;
                            } else if (var_2_5 > 0x1E) {
                                var_2_5 = 0x1E;
                            }
                            temp_f20_3 = sinf(((((1.5707964f * (f32) var_2_5) / 30.0f))));
                            if (temp_2 >= 0x32) {
                                temp_2 = 0x32;
                            }
                            temp_f21 = sinf(((((1.5707964f * (f32) temp_2) / 50.0f))));
                            if (temp_2 == 1) {
                                temp_3_2 = (s32)(M2C_FIELD(temp_21, s32 *, 0));
                                if (temp_3_2 >= 0xF) {
                                    var_4 = NULL;
                                } else {
                                    temp_2_3 = (u32 *)(&temp_20[temp_3_2]);
                                    if (mdlPrepareModel(M2C_FIELD(temp_2_3, u8 **, 0x44)) != 0) {
                                        var_4 = (u8 *)(M2C_FIELD(temp_2_3, u8 **, 0x44));
                                    } else {
                                        var_4 = NULL;
                                    }
                                }
                                if (var_4 != NULL) {
                                    mdlDispatchAnimIfPresent(var_4, 0, 1, 0, 1);
                                }
                            } else if (temp_2 == 0x1E) {
                                temp_3_3 = (s32)(M2C_FIELD(temp_21, s32 *, 0));
                                if (temp_3_3 >= 0xF) {
                                    var_4_2 = NULL;
                                } else {
                                    temp_2_4 = (u32 *)(&temp_20[temp_3_3]);
                                    if (mdlPrepareModel(M2C_FIELD(temp_2_4, u8 **, 0x44)) != 0) {
                                        var_4_2 = (u8 *)(M2C_FIELD(temp_2_4, u8 **, 0x44));
                                    } else {
                                        var_4_2 = NULL;
                                    }
                                }
                                if (var_4_2 != NULL) {
                                    mdlDispatchAnimIfPresent(var_4_2, 0, 0, 0x1E, 1);
                                }
                            }
                            if (temp_f21 < 1.0f) {
                                titleDrawScene(var_19, (s32)(255.0f * temp_f21), 0, 1, (u8 *)temp_20);
                            } else {
                                var_3_5 = sp6A0.bytes;
                                var_2_6 = 4;
                                if (var_3_5 != NULL) {
                                    do {
                                        *var_3_5 = 0;
                                        var_3_5 += 1;
                                        var_2_6 -= 1;
                                    } while (var_2_6 != 0);
                                }
                                titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp6A0);
                                titleRectangle((u8 *)&sp6BC, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                                /* Six packed colors form one snapshot and two independent copies.
                                 * Model calls use the same-owner typed definition; special ACC
                                 * producers remain supplied/unproven expressions. */
                                firstPalette = D_005E5530;
                                titlePaletteCopy(&firstHighlight, &firstPalette);
                                temp_7 = (u8 *)&((TitleRecordBlock *)D_005E5230)[var_19];
                                paletteOffset = *(s32 *)(temp_7 + 0x1C) * 4;
                                packedColor = *(u32 *)((u8 *)firstHighlight.words + paletteOffset);
                                temp_q1 = (f32)(s32)(255.0f * temp_f20_3) / 255.0f;
                                packedBaseColor = titleCopySelect((u8 *)&firstBase, (const u8 *)&firstPalette, paletteOffset);
                                green = (packedColor >> 0x10) & 0xFF;
                                red = (packedColor >> 0x18) & 0xFF;
                                blue = (packedColor >> 8) & 0xFF;
                                {
                                    s32 a0 = (s32)((f32) M2C_FIELD(temp_7, s32 *, 0));
                                    u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                                    u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, temp_q1) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, temp_q1) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, temp_q1) << 8) | 0xFF;
                                    func_00124bb0(a0, M2C_FIELD(temp_7, f32 *, 4), 0.0f, M2C_FIELD(temp_7, f32 *, 8), M2C_FIELD(temp_7, f32 *, 0xC), M2C_FIELD(temp_7, f32 *, 0x10), M2C_FIELD(temp_7, f32 *, 0x14), a1, a2, M2C_FIELD(temp_7, f32 *, 0x18), 0x42, temp_20);
                                }
                            }
                        }
                    }
                } else {
                    for (var_17_2 = 1; var_17_2 < 8; var_17_2++) {
                        secondPalette = D_005E5530;
                        titlePaletteCopy(&secondHighlight, &secondPalette);
                        temp_7_2 = D_005E5230 + var_17_2 * 0x28;
                        paletteOffset = *(s32 *)(temp_7_2 + 0x1C) * 4;
                        packedColor = *(u32 *)((u8 *)secondHighlight.words + paletteOffset);
                        packedBaseColor = titleCopySelect((u8 *)&secondBase, (const u8 *)&secondPalette, paletteOffset);
                        green = (packedColor >> 0x10) & 0xFF;
                        red = (packedColor >> 0x18) & 0xFF;
                        blue = (packedColor >> 8) & 0xFF;
                        {
                            s32 a0 = (s32)((f32) M2C_FIELD(temp_7_2, s32 *, 0));
                            u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                            u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
                            func_00124bb0(a0, M2C_FIELD(temp_7_2, f32 *, 4), 0.0f, M2C_FIELD(temp_7_2, f32 *, 8), M2C_FIELD(temp_7_2, f32 *, 0xC), M2C_FIELD(temp_7_2, f32 *, 0x10), M2C_FIELD(temp_7_2, f32 *, 0x14), a1, a2, M2C_FIELD(temp_7_2, f32 *, 0x18), 0x42, temp_20);
                        }
                    }
                }
            }
            if (temp_16 > 0x81) {
                if (temp_16 < 0xBE) {
                    temp_17 = temp_16 - 0x81;
                    lerpT = sinf(((((1.5707964f * (f32) temp_17) / 60.0f))));
                    if (temp_17 == 1) {
                        if (*(s32 *)D_005E5230 >= 0xF) {
                            var_4_7 = NULL;
                        } else {
                            temp_2_11 = (u32 *)titleOffsetPtr_001265a0((*(s32 *)D_005E5230) * 4, (u8 *)temp_20);
                            if (mdlPrepareModel(M2C_FIELD(temp_2_11, u8 **, 0x44)) != 0) {
                                var_4_7 = (u8 *)(M2C_FIELD(temp_2_11, u8 **, 0x44));
                            } else {
                                var_4_7 = NULL;
                            }
                        }
                        if (var_4_7 != NULL) {
                            mdlDispatchAnimIfPresent(var_4_7, 0, 2, 0, 1);
                        }
                        if (mdlPrepareModel(taskView->model0) != 0) {
                            var_4_8 = (u8 *)(taskView->model0);
                        } else {
                            var_4_8 = NULL;
                        }
                        mdlSetLayerWeight(var_4_8, 0, fGpffff8110);
                    } else if (temp_17 == 0x3A) {
                        if (*(s32 *)D_005E5230 >= 0xF) {
                            var_4_9 = NULL;
                        } else {
                            temp_2_12 = (u32 *)titleOffsetPtr_001265a0((*(s32 *)D_005E5230) * 4, (u8 *)temp_20);
                            if (mdlPrepareModel(M2C_FIELD(temp_2_12, u8 **, 0x44)) != 0) {
                                var_4_9 = (u8 *)(M2C_FIELD(temp_2_12, u8 **, 0x44));
                            } else {
                                var_4_9 = NULL;
                            }
                        }
                        if (var_4_9 != NULL) {
                            mdlDispatchAnimIfPresent(var_4_9, 0, 0, 0xF, 1);
                        }
                    }
                    thirdPalette = D_005E5530;
                    titlePaletteCopy(&thirdHighlight, &thirdPalette);
                    paletteOffset = D_005E538C[0] * 4;
                    packedColor = *(u32 *)((u8 *)thirdHighlight.words + paletteOffset);
                    packedBaseColor = titleCopySelect((u8 *)&thirdBase, (const u8 *)&thirdPalette, paletteOffset);
                    {
                        s32 a0 = (s32)((f32) D_005E5370[0]);
                        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                        func_00124bb0(a0, (0.0f + D_005E5374[0] + lerpT * (D_005E539C[0] - D_005E5374[0])), 0.0f, (0.0f + D_005E5378[0] + lerpT * (D_005E53A0[0] - D_005E5378[0])), (0.0f + D_005E537C[0] + lerpT * (D_005E53A4[0] - D_005E537C[0])), (0.0f + D_005E5380[0] + lerpT * (D_005E53A8[0] - D_005E5380[0])), (0.0f + D_005E5384[0] + lerpT * (D_005E53AC[0] - D_005E5384[0])), a1, ((u32)titlePaletteChannel((packedColor >> 0x18) & 0xFF, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel((packedColor >> 0x10) & 0xFF, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel((packedColor >> 8) & 0xFF, 0xFF, 1.0f) << 8) | 0xFF, (0.0f + D_005E5388[0] + lerpT * (D_005E53B0[0] - D_005E5388[0])), 0x40, temp_20);
                    }
                } else if (temp_16 < 0xD2) {
                    lerpT = sinf(((((1.5707964f * (f32) (temp_16 - 0xBD)) / 20.0f))));
                    fourthPalette = D_005E5530;
                    titlePaletteCopy(&fourthHighlight, &fourthPalette);
                    paletteOffset = D_005E53B4[0] * 4;
                    packedColor = *(u32 *)((u8 *)fourthHighlight.words + paletteOffset);
                    packedBaseColor = titleCopySelect((u8 *)&fourthBase, (const u8 *)&fourthPalette, paletteOffset);
                    {
                        s32 a0 = (s32)((f32) D_005E5398[0]);
                        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                        func_00124bb0(a0, (0.0f + D_005E539C[0] + lerpT * (D_005E53C4[0] - D_005E539C[0])), 0.0f, (0.0f + D_005E53A0[0] + lerpT * (D_005E53C8[0] - D_005E53A0[0])), (0.0f + D_005E53A4[0] + lerpT * (D_005E53CC[0] - D_005E53A4[0])), (0.0f + D_005E53A8[0] + lerpT * (D_005E53D0[0] - D_005E53A8[0])), (0.0f + D_005E53AC[0] + lerpT * (D_005E53D4[0] - D_005E53AC[0])), a1, ((u32)titlePaletteChannel((packedColor >> 0x18) & 0xFF, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel((packedColor >> 0x10) & 0xFF, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel((packedColor >> 8) & 0xFF, 0xFF, 1.0f) << 8) | 0xFF, (0.0f + D_005E53B0[0] + lerpT * (D_005E53D8[0] - D_005E53B0[0])), 0x40, temp_20);
                    }
                } else {
                    titleDrawScene(0xA, 0xFF, 0xFF, 0x40, (u8 *)temp_20);
                }
            }
            if (temp_16 < 0x74) {
                temp_f20_4 = sinf(((((1.5707964f * (f32) (temp_16 - 0x19)) / 90.0f))));
                var_3_10 = sp674.bytes;
                var_2_7 = 4;
                if (var_3_10 != NULL) {
                    do {
                        *var_3_10 = 0;
                        var_3_10 += 1;
                        var_2_7 -= 1;
                    } while (var_2_7 != 0);
                }
                titleCopyValue((u8 *)&sp678, (const u8 *)&sp674);
                titleRectangle((u8 *)&sp678, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                fnTable = (void (**)(s32, s32))(u32)D_00887300;
                fnTable[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_11 = sp61C.bytes;
                var_2_8 = 4;
                if ((u8 *)(var_3_11) != NULL) {
                    do {
                        *var_3_11 = 0;
                        var_3_11 += 1;
                        var_2_8 -= 1;
                    } while (var_2_8 != 0);
                }
                sp61C.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp620, (const u8 *)&sp61C);
                sp390 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp620, titleCopyRect((u8 *)&sp3A0, (const u8 *)&sp390), 0.0f, 0);
                sp380 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp620, titleCopyRect((u8 *)&sp3A0, (const u8 *)&sp380), 0.0f, 0);
                mdlEffectEmitTagPair();
                titleSkyApplyBasePreset();
                fnTable[0](6, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                shdSpriteDrawNow(-1.0f, -1.0f, 10.0f, 0xFFFFFFU, (u8)(255.0f * (1.0f - temp_f20_4)), 0, 0, taskView->sprites, 0);
            }
            if (temp_16 == 0x55) {
                func_0045ad50(2, H_Cdvd_LookupRequest(&D_005E56D0, &sp6B8), sp6B8);
            }
            if (temp_16 > 0x5a) {
                if (temp_16 < 0x65) {
temp_f2 = sinf(((((1.5707964f * (f32) (temp_16 - 0x5A)) / 10.0f))));
    /* ACC seed */;
                    temp_f14 = 0.0f;
                    shdSpriteDrawNowEx(159.0f + 36.0f * temp_f2, 87.0f + -15.0f * temp_f2, temp_f14, 0xFFFFFFU, (u8)(255.0f * temp_f2), 0x10001, 0, taskView->sprites, 1, 0, 0, temp_f14, 1.0f, 1.0f);
                } else {
                    shdSpriteDrawNow(195.0f, 72.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10001, 0, taskView->sprites, 1);
                }
            }
            if ((temp_16 > 0xbb) && (temp_16 < 0xDF)) {
                temp_f2_2 = 1.5707964f;
                shdSpriteDrawNow(195.0f, 72.0f, 0.0f, 0xFFFFFFU, (u8)(255.0f * sinf((((temp_f2_2 + ((temp_f2_2 * (f32) (temp_16 - 0xBB)) / 35.0f)))))), 0x10009, 0, taskView->sprites, 1);
            }
            if (temp_16 < 0x74) {
                var_3_12 = sp66C.bytes;
                var_2_9 = 4;
                if (var_3_12 != NULL) {
                    do {
                        *var_3_12 = 0;
                        var_3_12 += 1;
                        var_2_9 -= 1;
                    } while (var_2_9 != 0);
                }
                titleCopyValue((u8 *)&sp670, (const u8 *)&sp66C);
                titleRectangle((u8 *)&sp670, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                D_00887300[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_13 = sp614.bytes;
                var_2_10 = 4;
                if ((u8 *)(var_3_13) != NULL) {
                    do {
                        *var_3_13 = 0;
                        var_3_13 += 1;
                        var_2_10 -= 1;
                    } while (var_2_10 != 0);
                }
                sp614.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp618, (const u8 *)&sp614);
                sp360 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp618, titleCopyRect((u8 *)&sp370, (const u8 *)&sp360), 0.0f, 0);
                sp350 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp618, titleCopyRect((u8 *)&sp370, (const u8 *)&sp350), 0.0f, 0);
                mdlEffectEmitTagPair();
                shdSpriteDrawNow(268.0f, (f32) 0x169, 10.0f, 0xFFFFFFU, 0xFF, 0x10002, 0, taskView->sprites, 1);
            } else {
                shdSpriteDrawNow(268.0f, (f32) 0x169, 0.0f, 0xFFFFFFU, 0xFF, 0x10002, 0, taskView->sprites, 1);
            }
            if (temp_16 < 0x56) {
                var_3_14 = sp664.bytes;
                var_2_11 = 4;
                if (var_3_14 != NULL) {
                    do {
                        *var_3_14 = 0;
                        var_3_14 += 1;
                        var_2_11 -= 1;
                    } while (var_2_11 != 0);
                }
                titleCopyValue((u8 *)&sp668, (const u8 *)&sp664);
                titleRectangle((u8 *)&sp668, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                fnTable = (void (**)(s32, s32))(u32)D_00887300;
                fnTable[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_15 = sp60C.bytes;
                var_2_12 = 4;
                if ((u8 *)(var_3_15) != NULL) {
                    do {
                        *var_3_15 = 0;
                        var_3_15 += 1;
                        var_2_12 -= 1;
                    } while (var_2_12 != 0);
                }
                sp60C.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp610, (const u8 *)&sp60C);
                sp330 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp610, titleCopyRect((u8 *)&sp340, (const u8 *)&sp330), 0.0f, 0);
                sp320 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp610, titleCopyRect((u8 *)&sp340, (const u8 *)&sp320), 0.0f, 0);
                mdlEffectEmitTagPair();
                titleSkyApplyBasePreset();
                fnTable[0](6, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                shdSpriteDrawNow(268.0f, (f32) 0x169, 10.0f, 0xFFFFFFU, 0xFF, 0x1000A, 0, taskView->sprites, 0);
            } else if (temp_16 < 0x92) {
                var_3_16 = sp65C.bytes;
                var_2_13 = 4;
                if (var_3_16 != NULL) {
                    do {
                        *var_3_16 = 0;
                        var_3_16 += 1;
                        var_2_13 -= 1;
                    } while (var_2_13 != 0);
                }
                titleCopyValue((u8 *)&sp660, (const u8 *)&sp65C);
                titleRectangle((u8 *)&sp660, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                fnTable = (void (**)(s32, s32))(u32)D_00887300;
                fnTable[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_17 = sp604.bytes;
                var_2_14 = 4;
                if ((u8 *)(var_3_17) != NULL) {
                    do {
                        *var_3_17 = 0;
                        var_3_17 += 1;
                        var_2_14 -= 1;
                    } while (var_2_14 != 0);
                }
                sp604.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp608, (const u8 *)&sp604);
                sp300 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp608, titleCopyRect((u8 *)&sp310, (const u8 *)&sp300), 0.0f, 0);
                sp2F0 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp608, titleCopyRect((u8 *)&sp310, (const u8 *)&sp2F0), 0.0f, 0);
                mdlEffectEmitTagPair();
                temp_f22 = sinf(((((1.5707964f * (f32) (temp_16 - 0x55)) / 60.0f))));
                titleSkyApplyBasePreset();
                fnTable[0](6, 1);
                RpSkyRenderStateSet(3, (void *)0x50003);
                RpSkyRenderStateSet(2, 0x48);
                shdSpriteDrawNow(268.0f, (f32) 0x169, 10.0f, 0xFFFFFFU, (u8)(255.0f * (1.0f - temp_f22)), 0x1000A, 0, taskView->sprites, 0);
            }
            if (temp_16 < 0x56) {
                var_3_18 = sp654.bytes;
                var_2_15 = 4;
                if (var_3_18 != NULL) {
                    do {
                        *var_3_18 = 0;
                        var_3_18 += 1;
                        var_2_15 -= 1;
                    } while (var_2_15 != 0);
                }
                titleCopyValue((u8 *)&sp658, (const u8 *)&sp654);
                titleRectangle((u8 *)&sp658, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                D_00887300[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_19 = sp5FC.bytes;
                var_2_16 = 4;
                if ((u8 *)(var_3_19) != NULL) {
                    do {
                        *var_3_19 = 0;
                        var_3_19 += 1;
                        var_2_16 -= 1;
                    } while (var_2_16 != 0);
                }
                sp5FC.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp600, (const u8 *)&sp5FC);
                sp2D0 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp600, titleCopyRect((u8 *)&sp2E0, (const u8 *)&sp2D0), 0.0f, 0);
                sp2C0 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp600, titleCopyRect((u8 *)&sp2E0, (const u8 *)&sp2C0), 0.0f, 0);
                mdlEffectEmitTagPair();
                titleBuildPointRows(200.0f, 0.0f, 10.0f, 0xFF, (u8 *)temp_20);
            } else if (temp_16 < 0xCE) {
                var_3_20 = sp64C.bytes;
                var_2_17 = 4;
                if (var_3_20 != NULL) {
                    do {
                        *var_3_20 = 0;
                        var_3_20 += 1;
                        var_2_17 -= 1;
                    } while (var_2_17 != 0);
                }
                titleCopyValue((u8 *)&sp650, (const u8 *)&sp64C);
                titleRectangle((u8 *)&sp650, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                D_00887300[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_21 = sp5F4.bytes;
                var_2_18 = 4;
                if ((u8 *)(var_3_21) != NULL) {
                    do {
                        *var_3_21 = 0;
                        var_3_21 += 1;
                        var_2_18 -= 1;
                    } while (var_2_18 != 0);
                }
                sp5F4.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp5F8, (const u8 *)&sp5F4);
                sp2A0 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp5F8, titleCopyRect((u8 *)&sp2B0, (const u8 *)&sp2A0), 0.0f, 0);
                sp290 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp5F8, titleCopyRect((u8 *)&sp2B0, (const u8 *)&sp290), 0.0f, 0);
                mdlEffectEmitTagPair();
                titleBuildPointRows(200.0f - 700.0f * sinf(((((1.5707964f * (f32) (temp_16 - 0x55)) / 120.0f)))), 0.0f, 10.0f, 0xFF, (u8 *)temp_20);
            }
            if (temp_16 < 0xE2) {
                var_3_22 = sp644.bytes;
                var_2_19 = 4;
                if (var_3_22 != NULL) {
                    do {
                        *var_3_22 = 0;
                        var_3_22 += 1;
                        var_2_19 -= 1;
                    } while (var_2_19 != 0);
                }
                titleCopyValue((u8 *)&sp648, (const u8 *)&sp644);
                titleRectangle((u8 *)&sp648, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
                titleSkyApplyBasePreset();
                D_00887300[0](8, 1);
                mdlEffectEmitMaskedTagPair();
                var_3_23 = sp5EC.bytes;
                var_2_20 = 4;
                if ((u8 *)(var_3_23) != NULL) {
                    do {
                        *var_3_23 = 0;
                        var_3_23 += 1;
                        var_2_20 -= 1;
                    } while (var_2_20 != 0);
                }
                sp5EC.bytes[3] = 0xFF;
                titleCopyValue((u8 *)&sp5F0, (const u8 *)&sp5EC);
                sp270 = D_005E5590;
                PrimDrawFlatRectangle((u8 *)&sp5F0, titleCopyRect((u8 *)&sp280, (const u8 *)&sp270), 0.0f, 0);
                sp260 = D_005E55A0;
                PrimDrawFlatRectangle((u8 *)&sp5F0, titleCopyRect((u8 *)&sp280, (const u8 *)&sp260), 0.0f, 0);
                mdlEffectEmitTagPair();
                temp_f20_5 = sinf((1.5707964f * (f32) temp_16) / 225.0f);
                if (temp_16 > 0x87) {
                    var_2_21 = temp_16 - 0x87;
                } else {
                    var_2_21 = 0;
                }
                temp_f21_2 = sinf((1.5707964f * (f32) var_2_21) / 90.0f);
                /* Keep the first return across the second call; round multiply and add separately. */
                temp_f2 = 1.5f * temp_f20_5;
                temp_f16 = fGpffff8170 + temp_f2;
                {
                    f32 size = 137.0f * temp_f16;

                    temp_f2 = 1.0f - temp_f21_2;
                    temp_f21_2 = 255.0f * temp_f2;
                    shdSpriteDrawNowEx(-3.0f, -76.0f, 10.0f, 0xFFFFFFU, (u8)temp_f21_2, 0x1000E, 0, taskView->sprites, 1, (s16)size, (s16)size, -82.0f + 160.0f * temp_f20_5, temp_f16, temp_f16);
                }
    /* ACC seed */;
                temp_f16_2 = 1.3f;
                shdSpriteDrawNowEx(-9.0f, 33.0f, 10.0f, 0xFFFFFFU, (u8)temp_f21_2, 0x1000E, 0, taskView->sprites, 1, 0x6B, 0xE6, -51.0f + 60.0f * temp_f20_5, temp_f16_2, temp_f16_2);
            }
        }
        if (temp_16 < 0x19) {
            var_3_24 = sp63C.bytes;
            var_2_22 = 4;
            if (var_3_24 != NULL) {
                do {
                    *var_3_24 = 0;
                    var_3_24 += 1;
                    var_2_22 -= 1;
                } while (var_2_22 != 0);
            }
            titleCopyValue((u8 *)&sp640, (const u8 *)&sp63C);
            titleRectangle((u8 *)&sp640, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
            titleSkyApplyBasePreset();
            D_00887300[0](8, 1);
            mdlEffectEmitMaskedTagPair();
            var_3_25 = sp5E4.bytes;
            var_2_23 = 4;
            if ((u8 *)(var_3_25) != NULL) {
                do {
                    *var_3_25 = 0;
                    var_3_25 += 1;
                    var_2_23 -= 1;
                } while (var_2_23 != 0);
            }
            sp5E4.bytes[3] = 0xFF;
            titleCopyValue((u8 *)&sp5E8, (const u8 *)&sp5E4);
            sp240 = D_005E5590;
            PrimDrawFlatRectangle((u8 *)&sp5E8, titleCopyRect((u8 *)&sp250, (const u8 *)&sp240), 0.0f, 0);
            sp230 = D_005E55A0;
            PrimDrawFlatRectangle((u8 *)&sp5E8, titleCopyRect((u8 *)&sp250, (const u8 *)&sp230), 0.0f, 0);
            mdlEffectEmitTagPair();
            sp69C.value = fGpffff9c80;
            temp_f1_11 = 255.0f;
            var_3_26 = (u8)temp_f1_11;
            sp69C.bytes[3] = (u8)var_3_26;
            titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp69C);
            sp500 = *(TitleRect *)&D_005E5670;
            PrimDrawFlatRectangle((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp500), 10.0f, 1);
        } else if (temp_16 < 0x56) {
            var_3_27 = sp634.bytes;
            var_2_24 = 4;
            if (var_3_27 != NULL) {
                do {
                    *var_3_27 = 0;
                    var_3_27 += 1;
                    var_2_24 -= 1;
                } while (var_2_24 != 0);
            }
            titleCopyValue((u8 *)&sp638, (const u8 *)&sp634);
            titleRectangle((u8 *)&sp638, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
            titleSkyApplyBasePreset();
            D_00887300[0](8, 1);
            mdlEffectEmitMaskedTagPair();
            var_3_28 = sp5DC.bytes;
            var_2_25 = 4;
            if ((u8 *)(var_3_28) != NULL) {
                do {
                    *var_3_28 = 0;
                    var_3_28 += 1;
                    var_2_25 -= 1;
                } while (var_2_25 != 0);
            }
            sp5DC.bytes[3] = 0xFF;
            titleCopyValue((u8 *)&sp5E0, (const u8 *)&sp5DC);
            sp210 = D_005E5590;
            PrimDrawFlatRectangle((u8 *)&sp5E0, titleCopyRect((u8 *)&sp220, (const u8 *)&sp210), 0.0f, 0);
            sp200 = D_005E55A0;
            PrimDrawFlatRectangle((u8 *)&sp5E0, titleCopyRect((u8 *)&sp220, (const u8 *)&sp200), 0.0f, 0);
            mdlEffectEmitTagPair();
            temp_f2_3 = 1.5707964f;
            temp_f0_5 = sinf((((temp_f2_3 + ((temp_f2_3 * (f32) (temp_16 - 0x19)) / 60.0f)))));
            sp698.value = fGpffff9c84;
            temp_f1_11 = 255.0f * temp_f0_5;
            var_3_29 = (u8)temp_f1_11;
            sp698.bytes[3] = (u8)var_3_29;
            titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp698);
            sp4F0 = *(TitleRect *)&D_005E5680;
            PrimDrawFlatRectangle((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp4F0), 10.0f, 1);
        }
        break;
    case 6:
    case 7:
        var_3_30 = (s32)(taskView->timer + 1);
        taskView->timer = var_3_30;
        if (var_3_30 >= 0x14) {
            var_3_30 = 0x14;
        }
        fadeT = (f32) var_3_30 / 20.0f;
        shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0xFF, 0, 0, taskView->sprites, 1);
        RpSkyRenderStateSet(3, (void *)0x50003);
        RpSkyRenderStateSet(2, 0x48);
        shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, 0xFFFFFFU, 0x2D, 0, 0, taskView->sprites, 0);
        sp694.value = fGpffff9c88;
        sp6BC = sp694;
        sp4E0 = *(TitleRect *)&D_005E5690;
        PrimDrawFlatRectangle((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp4E0), 0.0f, 1);
        sp4D0 = *(TitleRect *)&D_005E56A0;
        PrimDrawFlatRectangle((u8 *)&sp6BC, titleCopyRect((u8 *)&sp590, (const u8 *)&sp4D0), 0.0f, 1);
        titleDrawShadeBars(0.0f, 0.0f, 0.0f, 0xFF, (u8 *)temp_20);
        var_3_31 = sp62C.bytes;
        var_2_26 = 4;
        if (var_3_31 != NULL) {
            do {
                *var_3_31 = 0;
                var_3_31 += 1;
                var_2_26 -= 1;
            } while (var_2_26 != 0);
        }
        titleCopyValue((u8 *)&sp630, (const u8 *)&sp62C);
        titleRectangle((u8 *)&sp630, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
        titleSkyApplyBasePreset();
        D_00887300[0](8, 1);
        mdlEffectEmitMaskedTagPair();
        var_3_32 = sp5D4.bytes;
        var_2_27 = 4;
        if ((u8 *)(var_3_32) != NULL) {
            do {
                *var_3_32 = 0;
                var_3_32 += 1;
                var_2_27 -= 1;
            } while (var_2_27 != 0);
        }
        sp5D4.bytes[3] = 0xFF;
        titleCopyValue((u8 *)&sp5D8, (const u8 *)&sp5D4);
        sp1E0 = D_005E5590;
        PrimDrawFlatRectangle((u8 *)&sp5D8, titleCopyRect((u8 *)&sp1F0, (const u8 *)&sp1E0), 0.0f, 0);
        sp1D0 = D_005E55A0;
        PrimDrawFlatRectangle((u8 *)&sp5D8, titleCopyRect((u8 *)&sp1F0, (const u8 *)&sp1D0), 0.0f, 0);
        mdlEffectEmitTagPair();
        temp_2_19 = (s32)(taskView->f10 + 1);
        taskView->f10 = temp_2_19;
        if (temp_2_19 >= 0x168) {
            taskView->f10 = 0;
        }
        titleBuildPointRows(200.0f - 700.0f * (1.0f - (1.0f + sinf((((iGpffff81dc + ((fGpffff81e0 * (f32) taskView->f10) / 360.0f)))))) / 2.0f), 0.0f, 10.0f, 0x99, (u8 *)temp_20);
        var_3_33 = sp690.bytes;
        var_2_28 = 4;
        if (var_3_33 != NULL) {
            do {
                *var_3_33 = 0;
                var_3_33 += 1;
                var_2_28 -= 1;
            } while (var_2_28 != 0);
        }
        titleCopyValue((u8 *)&sp6BC, (const u8 *)&sp690);
        titleRectangle((u8 *)&sp6BC, 0.0f, 0.0f, (f32) 0xFFFF, 640.0f, 448.0f, 0x12, NULL);
        for (var_16 = 1; var_16 < 8; var_16++) {
            fifthPalette = D_005E5530;
            titlePaletteCopy(&fifthHighlight, &fifthPalette);
            temp_7_5 = D_005E5230 + var_16 * 0x28;
            paletteOffset = *(s32 *)(temp_7_5 + 0x1C) * 4;
            packedColor = *(u32 *)((u8 *)fifthHighlight.words + paletteOffset);
            packedBaseColor = titleCopySelect((u8 *)&fifthBase, (const u8 *)&fifthPalette, paletteOffset);
            green = (packedColor >> 0x10) & 0xFF;
            red = (packedColor >> 0x18) & 0xFF;
            blue = (packedColor >> 8) & 0xFF;
            {
                s32 a0 = (s32)((f32) M2C_FIELD(temp_7_5, s32 *, 0));
                u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
                u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
                func_00124bb0(a0, M2C_FIELD(temp_7_5, f32 *, 4), 0.0f, M2C_FIELD(temp_7_5, f32 *, 8), M2C_FIELD(temp_7_5, f32 *, 0xC), M2C_FIELD(temp_7_5, f32 *, 0x10), M2C_FIELD(temp_7_5, f32 *, 0x14), a1, a2, M2C_FIELD(temp_7_5, f32 *, 0x18), 0x42, temp_20);
            }
        }
        titleDrawScene(0xA, 0xFF, 0xFF, 0x40, (u8 *)temp_20);
        shdSpriteDrawNow(195.0f, 72.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10001, 0, taskView->sprites, 1);
        shdSpriteDrawNowEx(204.0f, (f32) 0x143, 0.0f, 0xFFFFFFU, (u8)(255.0f * fadeT), 0x10007, 0, taskView->sprites, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        shdSpriteDrawNow(268.0f, (f32) 0x169, 0.0f, 0xFFFFFFU, 0xFF, 0x10002, 0, taskView->sprites, 1);
        break;
    case 8:
    case 9:
        if (taskView->timer == 0) {
            temp_f0_7 = (f32)*(s32 *)(D_005E5230 + taskView->f84 * 0x28);
            if (M2C_BITWISE(s32, temp_f0_7) >= 0xF) {
                var_4_16 = NULL;
            } else {
                temp_2_23 = (u32 *)titleOffsetPtr_001265a0((M2C_BITWISE(s32, temp_f0_7)) * 4, (u8 *)temp_20);
                if (mdlPrepareModel(M2C_FIELD(temp_2_23, u8 **, 0x44)) != 0) {
                    var_4_16 = (u8 *)(M2C_FIELD(temp_2_23, u8 **, 0x44));
                } else {
                    var_4_16 = NULL;
                }
            }
            if (var_4_16 != NULL) {
                mdlDispatchAnimIfPresent(var_4_16, 0, 2, 0, 1);
            }
        }
        temp_2_24 = (s32)(taskView->timer);
        if (temp_2_24 < 0x258) {
            taskView->timer = (s32) (temp_2_24 + 1);
        }
        sp68C.value = fGpffff9c8c;
        sp6BC = sp68C;
        func_0045c870((u8 *)&sp6BC, 1);
        temp_f0_9 = (f32)*(s32 *)(D_005E5230 + taskView->f84 * 0x28);
        if (M2C_BITWISE(s32, temp_f0_9) >= 0xF) {
            var_16_2 = NULL;
        } else {
            temp_2_25 = (u32 *)titleOffsetPtr_001265a0((M2C_BITWISE(s32, temp_f0_9)) * 4, (u8 *)temp_20);
            if (mdlPrepareModel(M2C_FIELD(temp_2_25, u8 **, 0x44)) != 0) {
                var_16_2 = (u8 *)(M2C_FIELD(temp_2_25, u8 **, 0x44));
            } else {
                var_16_2 = NULL;
            }
        }
        if (var_16_2 != NULL) {
            f32 titleY;
            f32 temp_f24;
            f32 temp_f23;
            f32 temp_f21_3;
            f32 titleX;

            temp_3_19 = (s32)(taskView->f84 * 0x28);
            titleX = *(f32 *)(D_005E5234 + temp_3_19);
            titleY = *(f32 *)(D_005E5238 + temp_3_19);
            temp_f24 = *(f32 *)(D_005E523C + temp_3_19);
            temp_f23 = *(f32 *)(D_005E5240 + temp_3_19);
            temp_f21_3 = *(f32 *)(D_005E5248 + temp_3_19);
            temp_2_26 = (s32)(M2C_FIELD(var_16_2, s32 *, 0xD8) & ~8);
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_2_26;
            temp_3_20 = temp_2_26 | 0x10;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_3_20;
            temp_3_21 = temp_3_20 | 0x100000;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = temp_3_21;
            M2C_FIELD(var_16_2, s32 *, 0xD8) = (s32) (temp_3_21 | 0x40000);
            temp_17_2 = (u32)(taskView->f84);
            if (temp_17_2 >= 0x13U) {
                kAssertFail(D_005E5548, 0xEB);
            }
            mdlSetLayerWeight(var_16_2, 0, *(f32 *)(D_005E5254 + temp_17_2 * 0x28));
            /* Replace writes the matrix fields and flags before concatenation.
             * Provider padding remains unspecified; do not synthesize values. */
            RwMatrixRotate(&titleMatrix, &titleYawAxis, temp_f23, 0);
            RwMatrixRotate(&titleMatrix, &titlePitchAxis, temp_f24, 2);
            titleTranslation.x = 0.0f;
            titleTranslation.y = -90.0f;
            titleTranslation.z = 0.0f;
            RwMatrixTranslate(&titleMatrix, &titleTranslation, 1);
            mdlApplyModelMatrix(var_16_2, &titleMatrix, 0);
            var_2_29 = (s32)(taskView->timer - 5);
            if (var_2_29 > 0) {
                if (var_2_29 > 5) {
                    var_2_29 = 5;
                }
                {
                    f32 t = 1.0f - sinf(1.5707964f * (f32)var_2_29 / 5.0f);

                    titleX = titleX + 200.0f * t;
                    titleY = titleY + 250.0f * t;
                }
                func_002abb30(titleX + 49.0f * temp_f21_3, titleY - 33.0f * temp_f21_3, 100.0f, 0xFFFF81, 0xFF, temp_f21_3, 1, var_16_2, 0);
                func_002abb30(titleX + 24.0f * temp_f21_3, titleY - 12.0f * temp_f21_3, 100.0f, 0xFFFFFF, 0xFF, temp_f21_3, 1, var_16_2, 0);
                func_002abb30(titleX + 9.0f * temp_f21_3, titleY - 5.0f * temp_f21_3, 100.0f, 0xFFC705, 0xFF, temp_f21_3, 1, var_16_2, 0);
                func_002abb30(titleX, titleY, 100.0f, 0xFFF000, 0xFF, temp_f21_3, 1, var_16_2, 0);
                mdlAdvanceModelFromFlags(var_16_2);
                func_002ab380(-1.0f, -1.0f, 1.0f, 0xFFFFFF, 0xFF, 0, taskView->sprites, 9, 0);
            }
        }
        var_2_30 = (s32)(taskView->timer);
        if (var_2_30 > 5) {
            var_2_30 = 5;
        }
        fadeT = (f32) var_2_30 / 5.0f;
        shdSpriteDrawNow(195.0f, 72.0f, 0.0f, 0xFFFFFFU, (u8)(255.0f * (1.0f - fadeT)), 0x10001, 0, taskView->sprites, 1);
        var_2_31 = (s32)(taskView->timer - 2);
        if (var_2_31 > 0) {
            if (var_2_31 > 2) {
                var_2_31 = 5;
            }
            temp_f1_17 = (f32) var_2_31 / 5.0f;
            temp_f14_2 = 0.0f;
            temp_f16_3 = 0.87f;
            shdSpriteDrawNowEx(52.0f + 246.0f * (1.0f - temp_f1_17), 81.0f, temp_f14_2, 0xFFFFFFU, (u8)(255.0f * temp_f1_17), 0x10001, 0, taskView->sprites, 1, 0, 0, temp_f14_2, temp_f16_3, temp_f16_3);
        }
        if (taskView->f28 != (taskView->f20 << 0x10)) {
    /* ACC seed */;
            temp_10_2 = (taskView->f20 << 0x10) - taskView->f28;
            temp_f0_10 = (f32)(s32)temp_10_2 + 0.5f * (f32)((taskView->f20 - taskView->f24) << 0x10);
            temp_10_2 = (s32)temp_f0_10;
            if (func_0043c6a0(temp_10_2) < 0xB) {
                taskView->f28 = (s32) (taskView->f20 << 0x10);
                taskView->f08 = (s32) ~(taskView->f08 ^ -5);
            } else {
                temp_f2 = 0.5f;
                taskView->f28 = (s32) (taskView->f28 + (s32)((f32)(s32)temp_10_2 * temp_f2));
            }
        }
        temp_5 = (s32)(taskView->f24);
        temp_4 = (s32)(taskView->f20);
        temp_i28 = (temp_4 - temp_5) << 0x10;
        temp_f13_28 = 0.25f;
        temp_f13_28 *= (f32)temp_i28;
        temp_f1_28 = (f32)(temp_4 << 0x10) + temp_f13_28;
        temp_28 = (s32)taskView->f28;
        temp_f0_11 = temp_f1_28 - (f32)temp_28;
        temp_i28 = (s32)temp_f0_11;
        if (((temp_5 < temp_4) && (temp_i28 < 0)) || ((temp_4 < temp_5) && (temp_i28 > 0))) {
            temp_28 = (s32)((f32)temp_i28 + temp_f1_28);
        }
        temp_f13_28 = 32.0f * ((f32)temp_28 / 65535.0f) + 327.0f;
        shdSpriteDrawNow((f32) 0x18B, temp_f13_28, 0.0f, 0xFFFFFFU, 0xFF, 0x10006, 0, taskView->sprites, 1);
        shdSpriteDrawNow(414.0f, 330.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10003, 0, taskView->sprites, 1);
        shdSpriteDrawNow(444.0f, 362.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10004, 0, taskView->sprites, 1);
        shdSpriteDrawNow((f32) 0x193, 394.0f, 0.0f, 0xFFFFFFU, 0xFF, 0x10005, 0, taskView->sprites, 1);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
    /* The update callback seeds this countdown with 10 or 13 frames. */
    if (taskView->f2C > 0) {
        /* Four UV pairs, copied as their original words before the texture lookup. */
        fadeUvSource = D_005E56B0;
        fadeUvDestination = fadeUv.words;
        var_4_17 = 4;
        do {
            temp_3_22 = fadeUvSource[0];
            temp_2_27 = fadeUvSource[1];
            fadeUvSource += 2;
            var_4_17 -= 1;
            fadeUvDestination[0] = temp_3_22;
            fadeUvDestination[1] = temp_2_27;
            fadeUvDestination += 2;
        } while (var_4_17 > 0);
        var_4_18 = 0xD;
        if (taskView->f00 == 0x10) {
            var_4_18 = 0xA;
        }
        temp_3_23 = (s32)(taskView->f2C - 1);
        taskView->f2C = temp_3_23;
        fadeAlpha = (s32)((f32)(temp_3_23 * 0xFF) / (f32)var_4_18);
        func_00366c70(0, 0, 0.0f, 0x280, 0x1C0, 0xFFFFFF, fadeAlpha,
                      1, 0, 0, NULL, RpSkyGetDisplayBufferRaster(), fadeUv.pairs);
    }
}
#pragma pop
typedef struct Code12FrameVector { f32 x, y, z; } Code12FrameVector;
typedef struct Code12FrameMatrix {
    Code12FrameVector right; u32 flags;
    Code12FrameVector up; u32 pad1;
    Code12FrameVector at; u32 pad2;
    Code12FrameVector pos; u32 pad3;
} Code12FrameMatrix;
typedef union Code12FrameQuaternion {
    s128 packed;
    f32 value[4];
} Code12FrameQuaternion;
typedef union Code12FrameVectorTransfer {
    struct { s64 xy; f32 z; } words;
    f32 value[3];
    Code12FrameVector vector;
} Code12FrameVectorTransfer;

#pragma push
#pragma opt_propagation off
static inline void code12QuaternionMatrix(Code12FrameMatrix *matrix, const Code12FrameQuaternion *rotation)
{
    f32 x, y, z, w;
    f32 xx, yy, zz, yz, zx, xy, wx, wy, wz;
    f32 squaredYZ;
    x = rotation->value[0];
    y = rotation->value[1];
    z = rotation->value[2];
    w = rotation->value[3];
    xx = x * x;
    yy = y * y;
    zz = z * z;
    yz = y * z;
    zx = z * x;
    xy = x * y;
    wx = w * x;
    wy = w * y;
    wz = w * z;
    squaredYZ = yy + zz;
    matrix->right.x = 1.0f - 2.0f * squaredYZ;
    matrix->right.y = 2.0f * (xy + wz);
    matrix->right.z = 2.0f * (zx - wy);
    matrix->up.x = 2.0f * (xy - wz);
    matrix->up.y = 1.0f - 2.0f * (xx + zz);
    matrix->up.z = 2.0f * (yz + wx);
    matrix->at.x = 2.0f * (zx + wy);
    matrix->at.y = 2.0f * (yz - wx);
    matrix->at.z = 1.0f - 2.0f * (xx + yy);
    matrix->pos.x = 0.0f;
    matrix->pos.y = 0.0f;
    matrix->pos.z = 0.0f;
    matrix->flags = 3;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 fadeStatus(void);

s32 taskLoadSlotModels(u8 *arg0);

s32 titleMusicStreamStep(u8 *arg0);

/* Native b210 O2: 3056/3056 bytes, 105 resolved relocations and the
 * complete 17-entry switch table at 0x00746770. Complete vector and
 * matrix objects retain the original stack transfers; reset-phase
 * models and the queued draw task have separate value lifetimes.
 * See docs/probe_archive/Menu_callback_0012aa70_20260923.md. */
// Kept in bucket: diff 1978 when moved; cause not diagnosed (uses static inline code12QuaternionMatrix).
// FUN_0012AA70
s32 func_0012aa70(u8 *task)
{
    extern s128 D_005E56F0;
    extern const Code12FrameVectorTransfer D_005E5700[1];
    extern u8 D_005E5220[];
    extern u8 D_005E5230[];
    extern u8 D_005E5710[];
    extern u8 D_005E5548[];
    extern char D_00795E60[];
    extern f32 fGpffff813c;
    extern s32 func_00440b68(const char *, ...);
    extern u8 *H_Cdvd_AcquireDirectory(u8 *task, s32 arg1);
    extern s32 H_Cdvd_IsFileLoaded(void *task);
    extern u8 *sdkSpritePackCreate(u8 *task);
    extern s32 shdSpriteEnsureLoaded(u8 *task);
    extern s32 taskLoadSlotModels(u8 *task);
    extern s32 titleMusicStreamStep(u8 *task);
    extern s32 func_00124350(u8 *unusedWork);
    extern s32 calReadDayFlagMask(void);
    extern void calWriteDayFlagMask(s32 task);
    extern s32 calCaptureDayFlagMask(void);
    extern void datInitDefaultGameState(void);
    extern void func_00122520(s32 task, s32 arg1);
    extern void func_00122640(s32 task, s32 arg1);
    extern s32 fadeStatus(void);
    extern s32 cmpConfigCreate(void *task, s32 arg1);
    extern s32 cmpConfigIsStepDone(u8 *task);
    extern s32 cmpConfigIsFlagsSynced(u8 *task);
    extern u8 *kwlnGetCamera(void);
    extern void K_View_SetFov(void *task, f32 arg1);
    extern u8 *func_003e8180(u8 *camera, f32 nearClip);
    extern u8 *func_003e81c0(u8 *camera, f32 farClip);
    extern u8 *func_003e9cb0(u8 *frame, const void *matrix, s32 combine);
    extern u8 *func_003e9c10(u8 *frame, const f32 *translation, s32 combine);
    extern u8 hsndQueueSound(s16 id, s16 unused);
    extern void sdkSndFadeOutChannelFrames(s16 task, s32 arg1, s32 arg2);

    extern void mdlSetLayerWeight(u8 *model, s32 layer, f32 speed);
    /* The persistent copy destination is a complete 0x5D0-byte buffer. */
    extern struct MenuSavedState { u8 bytes[0x5D0]; } iGpffff9c90 __attribute__((section(".sdata")));
    extern void titleDrawTaskView(void *unusedDrawData, void *task);

    Code12FrameVectorTransfer translation;
    Code12FrameVectorTransfer initialTranslation;
    Code12FrameMatrix matrix;
    Code12FrameQuaternion rotation;
    Code12FrameQuaternion initialRotation;
    u8 *work;
    s32 state;
    s32 result;
    s32 updateIndex;
    s32 modelIndex;
    u32 pressed;
    u8 *activeModel;
    u8 *animation;

    work = (u8 *)kwlnTaskGetWork(task);
    initialRotation.packed = D_005E56F0;
    rotation = initialRotation;
    initialTranslation.vector = D_005E5700[0].vector;
    translation.vector = initialTranslation.vector;
    *(s32 *)(work + 4) = *(s32 *)work;
    state = *(s32 *)work;
    switch (state) {
    case 0:
        *(s32 *)work = 1;
        func_00122640(1, 1);
    case 1:
        *(s32 *)work = 2;
        func_00440b68((const char *)&iGpffff9c90, D_005E5548, 0x5D0);
        *(u8 **)(work + 0x38) = H_Cdvd_AcquireDirectory(D_005E5710, 1);
    case 2:
        if (H_Cdvd_IsFileLoaded(*(u8 **)(work + 0x38)) != 0) {
            *(s32 *)work = 3;
            *(u8 **)(work + 0x3C) = sdkSpritePackCreate(D_005E5220);
        }
        break;
    case 3:
        if ((shdSpriteEnsureLoaded(*(u8 **)(work + 0x3C)) != 0) && (taskLoadSlotModels(work) != 0)) {
            *(s32 *)work = 4;
            hsndQueueSound(0x13, 0x1E);
        }
        break;
    case 4:
        code12QuaternionMatrix(&matrix, &rotation);
        func_003e9cb0(*(u8 **)(kwlnGetCamera() + 4), &matrix, 0);
        func_003e9c10(*(u8 **)(kwlnGetCamera() + 4), translation.value, 2);
        K_View_SetFov(kwlnGetCamera(), 50.0f);
        func_003e81c0(kwlnGetCamera(), 25600.0f);
        func_003e8180(kwlnGetCamera(), 10.0f);
        *(s32 *)work = 5;
        *(s32 *)(work + 0x14) = 0;
        *(s32 *)(work + 0xC) = 0;
        *(s32 *)(work + 0x10) = 0;
    case 5:
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
        if ((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x40) || (D_008C024E[0] & 4) || (D_008C024E[0] & 1) || (D_008C024E[0] & 8) || (D_008C024E[0] & 2) || (D_008C024E[0] & 0x800) || (D_008C024E[0] & 0x100)) {
            sdkSndStartStream(0, 0, 0, 1);
            pressed = D_008C024E[0];
        } else {
            pressed = 0;
        }
        if ((pressed != 0) || (*(s32 *)(work + 0x14) >= 0xEC)) {
            *(s32 *)(work + 8) = *(s32 *)(work + 8) & ~2;
            if (*(s32 *)(work + 0x14) < 0xEC) {
                *(s32 *)(work + 8) = *(s32 *)(work + 8) | 2;
                *(s32 *)(work + 0x2C) = 0xA;
            }
            *(s32 *)work = 6;
        }
        break;
    case 6:
        sdkSndFadeOutChannelFrames(2, 0, 0x1E);
        *(s32 *)work = 7;
        *(s32 *)(work + 0x14) = 0;
        *(s32 *)(work + 0xC) = 0;
        code12QuaternionMatrix(&matrix, &rotation);
        func_003e9cb0(*(u8 **)(kwlnGetCamera() + 4), &matrix, 0);
        func_003e9c10(*(u8 **)(kwlnGetCamera() + 4), translation.value, 2);
        K_View_SetFov(kwlnGetCamera(), 50.0f);
        func_003e81c0(kwlnGetCamera(), 25600.0f);
        func_003e8180(kwlnGetCamera(), 10.0f);
        if (mdlPrepareModel(*(u8 **)(work + 0x44)) != 0) {
            activeModel = *(u8 **)(work + 0x44);
        } else {
            activeModel = 0;
        }
        mdlSetLayerWeight(activeModel, 0, fGpffff813c);
        updateIndex = 1;
        while (updateIndex < 8) {
            animation = D_005E5230 + updateIndex * 0x28;
            modelIndex = (s32)(f32)*(s32 *)animation;
            if (modelIndex >= 0xF) {
                activeModel = 0;
            } else {
                result = mdlPrepareModel(*(u8 **)(work + modelIndex * 4 + 0x44));
                if (result != 0) {
                    activeModel = *(u8 **)(work + modelIndex * 4 + 0x44);
                } else {
                    activeModel = 0;
                }
            }
            if (activeModel != 0) {
                if ((u32)updateIndex >= 0x13) {
                    kAssertFail(D_005E5548, 0xEB);
                }
                mdlSetLayerWeight(activeModel, 0, *(f32 *)(animation + 0x24));
            }
            updateIndex++;
        }
        if ((*(s32 *)(work + 8) & 2) != 0) {
            u8 *resetModel;
            s32 resetIndex;
            u8 *resetRow;
            modelIndex = *(s32 *)D_005E5230;
            if (modelIndex >= 0xF) {
                resetModel = 0;
            } else {
                result = mdlPrepareModel(*(u8 **)((u8 *)(modelIndex * 4) + (u32)work + 0x44));
                if (result != 0) {
                    resetModel = *(u8 **)((u8 *)(modelIndex * 4) + (u32)work + 0x44);
                } else {
                    resetModel = 0;
                }
            }
            if (resetModel != 0) {
                mdlDispatchAnimIfPresent(resetModel, 0, 0, 0, 1);
            }
            resetIndex = 1;
            while (resetIndex < 8) {
                resetRow = D_005E5230 + resetIndex * 0x28;
                modelIndex = *(s32 *)resetRow;
                if (modelIndex >= 0xF) {
                    resetModel = 0;
                } else {
                    result = mdlPrepareModel(*(u8 **)(work + modelIndex * 4 + 0x44));
                    if (result != 0) {
                        resetModel = *(u8 **)(work + modelIndex * 4 + 0x44);
                    } else {
                        resetModel = 0;
                    }
                }
                if (resetModel != 0) {
                    mdlDispatchAnimIfPresent(resetModel, 0, 0, 0, 1);
                }
                resetIndex++;
            }
        }
        *(s32 *)(work + 8) = *(s32 *)(work + 8) | 2;
    case 7:
        result = *(s32 *)(work + 0x14) + 1;
        *(s32 *)(work + 0x14) = result;
        if (result >= 0x1C2) {
            *(s32 *)work = 0x10;
            *(s32 *)(work + 0x1C) = 1;
            *(s32 *)(work + 0x2C) = 0xA;
            func_00122520(1, 0xA);
        } else {
            if ((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x80) || (D_008C024E[0] & 0x40) || (D_008C024E[0] & 4) || (D_008C024E[0] & 1) || (D_008C024E[0] & 8) || (D_008C024E[0] & 2) || (D_008C024E[0] & 0x800) || (D_008C024E[0] & 0x100)) {
                sdkSndStartStream(0, 0, 0, 1);
                pressed = D_008C024E[0];
            } else {
                pressed = 0;
            }
            if (pressed != 0) {
                *(s32 *)work = 8;
            }
        }
        break;
    case 8:
        iGpffffb1e8 = iGpffffb1e8 + 1;
        *(s32 *)work = 9;
        *(s32 *)(work + 0x14) = 0;
        *(s32 *)(work + 0xC) = 0;
        *(s32 *)(work + 0x84) = func_00124350(work);
        matrix.right.x = matrix.up.y = matrix.at.z = 1.0f;
        matrix.up.z = matrix.at.x = matrix.at.y = matrix.right.y = matrix.right.z = matrix.up.x = 0.0f;
        matrix.pos.x = matrix.pos.y = matrix.pos.z = 0.0f;
        /* Preserve the original identity macro's read/OR of flags. This
         * branch does not initialize the pre-existing flag word. */
        matrix.flags |= 0x20003;
        func_003e9cb0(*(u8 **)(kwlnGetCamera() + 4), &matrix, 0);
        K_View_SetFov(kwlnGetCamera(), 70.0f);
        *(s32 *)(work + 0x28) = 0;
        *(s32 *)(work + 0x24) = 0;
        *(s32 *)(work + 0x20) = 0;
    case 9:
        *(s32 *)(work + 0x14) = *(s32 *)(work + 0x14) + 1;
        if ((D_008C024E[0] & 0x20) || (*(s32 *)(work + 0x14) >= 0x1C2)) {
            *(s32 *)(work + 0x2C) = 0xD;
            *(s32 *)work = 6;
        } else {
            result = titleMusicStreamStep(work);
            switch (result) {
            case 0:
                *(s32 *)(work + 0x14) = 0;
                break;
            case 1:
                *(s32 *)work = 0xA;
                break;
            case 2:
                *(s32 *)work = 0xC;
                sdkSndFadeOutChannelFrames(2, 0, 0);
                break;
            case 3:
                *(s32 *)work = 0xE;
                break;
            }
        }
        break;
    case 10:
        *(s32 *)(work + 0x8C) = calReadDayFlagMask();
        datInitDefaultGameState();
        *(s32 *)work = 0xB;
        *(s32 *)(work + 0x34) = mcIconTaskCreate(task, 0);
    case 11:
        result = mcIconTaskPoll();
        switch (result) {
        case 1:
            func_00122520(1, 0xA);
            *(s32 *)(work + 0x1C) = 3;
            *(s32 *)work = 0x10;
            break;
        case 2:
            *(s32 *)work = 8;
            calWriteDayFlagMask(*(s32 *)(work + 0x8C));
            break;
        }
        break;
    case 12:
        *(s32 *)work = 0xD;
        func_00122520(1, 0xA);
    case 13:
        if (fadeStatus() != 0) {
            *(s32 *)(work + 0x1C) = 2;
            *(s32 *)work = 0x10;
        }
        break;
    case 14:
        *(s32 *)work = 0xF;
        *(s32 *)(work + 0x34) = cmpConfigCreate(task, 1);
    case 15:
        if (cmpConfigIsStepDone(*(u8 **)(work + 0x34)) != 0) {
            if (cmpConfigIsFlagsSynced(*(u8 **)(work + 0x34)) != 0) {
                calCaptureDayFlagMask();
            }
            kwlnTaskDestroyWithHierarchy(*(u8 **)(work + 0x34));
            *(s32 *)(work + 0x34) = 0;
            *(s32 *)work = 8;
        }
        break;
    case 16:
        if ((fadeStatus() != 0) && (*(s32 *)(work + 0x2C) == 0)) {
            *(s32 *)(work + 0x18) = *(s32 *)(work + 0x1C);
        }
        break;
    }
    {
        u8 *drawTask = PrimAllocQueueNode();
        *(void (**)(void *, void *))(drawTask + 8) = titleDrawTaskView;
        *(u8 **)(drawTask + 0x10) = task;
        PrimAppendNode(D_00795E60, drawTask);
    }
    return 0;
}

#pragma pop

// Kept in bucket: diff 72 when moved; cause not diagnosed.
// FUN_0012B9A0
void func_0012b9a0(s32 unused, s32 arg1)
{
    typedef struct {
        s128 sp50;
        s128 sp60;
        s128 sp70;
        u8 gap[4];
        f32 sp84;
        f32 sp88;
        f32 sp8C;
    } B9Stack;
    B9Stack stack;
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_17;
    s32 temp_17_2;
    s32 var_2;
    s32 var_2_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_2;
    s32 temp_3;
    f32 *sp8c_ptr;
    s32 *sp70_ptr;

    temp_2 = (u8 *)kwlnTaskGetWork(arg1);
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 4:
    case 5:
    case 6:
        temp_f0 = fGpffff9cA0;
        stack.sp88 = temp_f0;
        sp8c_ptr = &stack.sp8C;
        stack.sp8C = temp_f0;
        stack.sp60 = D_005E5740;
        sp70_ptr = (s32 *)&stack.sp70;
        stack.sp70 = D_005E5740;
        PrimDrawFlatRectangle(sp8c_ptr, sp70_ptr, 0.0f, 1);
        temp_17 = *(s32 *)(temp_2 + 0x10);
        temp_16 = (u8 *)kwlnTaskGetWork(temp_17);
        if (kwlnTaskIsLinked(temp_17) == 0) {
            var_2 = 0;
        } else if (*(s32 *)(temp_16 + 0) == 3) {
            var_2 = *(s32 *)(*(u8 **)(temp_16 + 8));
        } else {
            var_2 = 0;
        }
        func_00366c70(0x77, 0xAA, 0.0f, 0x200, 0x80, 0xFFFFFF, 0xFF, 1, 0, 0, 0, var_2, 0);
        return;
    case 7:
    case 8:
    case 9:
        temp_f0_2 = fGpffff9cA4;
        stack.sp84 = temp_f0_2;
        sp8c_ptr = &stack.sp8C;
        stack.sp8C = temp_f0_2;
        stack.sp50 = D_005E5750;
        sp70_ptr = (s32 *)&stack.sp70;
        stack.sp70 = D_005E5750;
        PrimDrawFlatRectangle(sp8c_ptr, sp70_ptr, 0.0f, 1);
        temp_17_2 = *(s32 *)(temp_2 + 0x14);
        temp_16_2 = (u8 *)kwlnTaskGetWork(temp_17_2);
        if (kwlnTaskIsLinked(temp_17_2) == 0) {
            var_2_2 = 0;
        } else if (*(s32 *)(temp_16_2 + 0) == 3) {
            var_2_2 = *(s32 *)(*(u8 **)(temp_16_2 + 8));
        } else {
            var_2_2 = 0;
        }
        func_00366c70(0, 0, 0.0f, 0x400, 0x200, 0xFFFFFF, 0xFF, 1, 0, 0, 0, var_2_2, 0);
        /* fall through */
    default:
        return;
    }
}

#pragma push
/* measured: opt_loop_invariants on hoists the loop constants into the
   retail preheader and opt_propagation off keeps the pre-call indexed
   destination address materialised; 92 differing words -> 0 (532/544). */
#pragma opt_loop_invariants on
#pragma opt_propagation off
// Kept in bucket: diff 207 when moved; cause not diagnosed.
// FUN_0012D410
void titleSlotTableInit(u8 *arg0)
{
    u32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    s32 var_18_2;
    s32 var_18;
    s32 var_17;
    s32 var_2;
    s32 var_5;
    s32 temp_5;
    s32 temp_6;
    s32 *temp_4;

    *(s16 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x18) = -1;
    var_5 = 0;
    temp_5 = 0x42700000;
    temp_6 = 0x1000;
    while (var_5 < 0xB) {
        *(s32 *)(arg0 + (var_5 * 0x30) + 0xA4) = temp_5;
        *(s32 *)(arg0 + (var_5 * 0x30) + 0xA8) = 0;
        *(s16 *)(arg0 + (var_5 * 0x30) + 0xBA) = temp_6;
        *(s8 *)(arg0 + (var_5 * 0x30) + 0xAE) = 0;
        var_5++;
    }
    temp_2_2 = (u32)resourceFindByName((char *)D_005E5810);
    if (temp_2_2 == 0) {
        kAssertFail(D_005E5BB8, 0xC1);
    }
    temp_2_3 = (s32)resourceFindByName((char *)D_005E57F0);
    *(s32 *)(arg0 + 0x90) = temp_2_3;
    if (temp_2_3 == 0) {
        kAssertFail(D_005E5BB8, 0xC3);
    }
    var_18 = 0;
    while (var_18 < 0x15) {
        temp_3 = var_18 * 4;
        temp_4 = (s32 *)(arg0 + temp_3 + 0x3C);
        temp_2_4 = (s32)sdkSpriteNewNode(temp_2_2,
                                 *(u32 *)((u8 *)D_005E5B60 + temp_3));
        *temp_4 = temp_2_4;
        if (temp_2_4 == 0) {
            kAssertFail(D_005E5BB8, 0xC9);
        }
        var_18++;
    }
    var_17 = 0;
    var_18_2 = 0;
    while (var_17 < 7) {
        switch (var_17) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
            var_2 = 1;
            break;
        case 5:
            if (datGetFlag(0x1F) != 0) {
                var_2 = 0;
            } else {
                var_2 = 1;
            }
            break;
        default:
            kAssertFail(D_005E5BB8, 0xA7);
            var_2 = 0;
            break;
        }
        if (var_2 != 0) {
            *(s32 *)(arg0 + (var_18_2 * 4) + 0x1C) = var_17;
            var_18_2++;
        }
        var_17++;
    }
    *(s32 *)(arg0 + 0x38) = var_18_2;
    titleSlotSetMode(arg0, 0);
}
#pragma opt_propagation on
#pragma opt_loop_invariants off
#pragma pop
/* The menu owns eleven complete tween records and three seven-sprite banks.
 * measured: native b210 -O2 emits 1348 exact bytes plus 12 zero alignment bytes.
 * Scoped propagation preserves the selected sprite/opacity snapshots and the
 * two metadata color loads before their zero-depth argument transfers.
 * See docs/probe_archive/Camp_renderer_0012d630_complete_20260922.md. */
typedef struct {
    Vec2f startPosition;
    Vec2f endPosition;
    Vec2f position;
    u8 startAlpha;
    u8 endAlpha;
    u8 alpha;
    u8 pad1B;
    u16 startScaleX;
    u16 endScaleX;
    u16 scaleX;
    u16 startScaleY;
    u16 endScaleY;
    u16 scaleY;
    s32 startFrame;
    s32 endFrame;
} CampMenuTween;
typedef struct {
    s32 field00;
    Vec2f position;
    s16 frame;
    s16 field0E;
    s32 selection;
    s32 previousSelection;
    s32 state;
    s32 visibleOptions[7];
    s32 optionCount;
    u8 *sprites[3][7];
    s32 informationResource;
    CampMenuTween tweens[11];
} CampMenuWork;
typedef char CampMenuTweenSize[(sizeof(CampMenuTween) == 0x30) ? 1 : -1];
typedef char CampMenuWorkSize[(sizeof(CampMenuWork) == 0x2A4) ? 1 : -1];

#pragma push
#pragma opt_propagation off
// Kept in bucket: diff 43 when moved; cause not diagnosed.
// FUN_0012D630
s32 func_0012d630(u8 *menu)
{
    extern s32 func_0012e1d0(u8 *arg0);
    extern void sdkRenderStateSetDefault(void);
    extern void sdkSpriteDrawSized(u8 *arg0, f32 farg0, f32 farg1, f32 farg2,
                              u8 arg1, u8 arg2, u8 arg3, u8 arg4, u16 arg5,
                              u16 arg6, s16 arg7, f32 farg3, s16 arg_sp0);
    extern void sdkSpriteDrawFooter(Vec2f pos, f32 z, u8 arg1, s32 arg2, s32 arg3);
    Vec2f pos;
    Vec2f pos2;
    u8 *bytes;
    s32 finished;
    s32 tweenIndex;
    s32 visibleCount;
    s32 selection;
    s32 row;
    f32 x;
    f32 y;
    f32 labelY;
    u8 numberColor;
    u8 informationColor;

    bytes = menu;
    finished = 1;
    switch (*(s32 *)(bytes + 0x18)) {
    case 0:
        if (func_0012e1d0(bytes) != 0) {
            titleSlotSetMode(bytes, 1);
            break;
        }
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            radarAnimateValue(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 0);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    case 1:
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            radarAnimateValue(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 0);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    case 2:
        if (func_0012e1d0(bytes) != 0) {
            titleSlotSetMode(bytes, 1);
            break;
        }
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            radarAnimateValue(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 2);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    case 3:
        if (*(s16 *)(bytes + 0xC) < 100) {
            *(s16 *)(bytes + 0xC) = *(s16 *)(bytes + 0xC) + 1;
        }
        for (tweenIndex = 0; tweenIndex < 0xB; tweenIndex++) {
            u8 *rowBytes = bytes + tweenIndex * 0x30;
            radarAnimateValue(rowBytes + 0x94, *(s16 *)(bytes + 0xC), 0);
            if (*(u8 *)(rowBytes + 0xAE) != 0) {
                finished = 0;
            }
        }
        break;
    }
    sdkRenderStateSetDefault();
    selection = *(s32 *)(bytes + 0x10);
    visibleCount = *(s32 *)(bytes + 0x38);
    for (row = 0; row < visibleCount; row++) {
        u8 *rowBytes = bytes + row * 0x30;
        s32 option;
        u8 *sprite;
        u8 alpha;

        x = *(f32 *)(bytes + 4) + 173.0f + *(f32 *)(rowBytes + 0xA4);
        pos.x = x;
        y = *(f32 *)(bytes + 8) + 52.0f + *(f32 *)(rowBytes + 0xA8) + (f32)(row * 0x16);
        pos.y = y;
        alpha = *(u8 *)(rowBytes + 0xAE);
        option = *(s32 *)(bytes + row * 4 + 0x1C);
        if (row == selection) {
            pos.x += 2.0f;
            pos.y += 11.0f;
            sprite = *(u8 **)(bytes + option * 4 + 0x58);
        } else {
            pos.x += 1.0f;
            if (selection < row) {
                pos.y += 45.0f;
            }
            sprite = *(u8 **)(bytes + option * 4 + 0x3C);
        }
        sdkSpriteDrawSized(sprite, pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF,
                      alpha, 0x1000, *(u16 *)(rowBytes + 0xBA), 0,
                      0.0f, 0);
    }
    pos.x = *(f32 *)(bytes + 4) + 173.0f + *(f32 *)(bytes + 0x1F4) + 3.0f;
    pos.y = *(f32 *)(bytes + 8) + 52.0f + *(f32 *)(bytes + 0x1F8) + 311.0f;
    {
        CampMenuWork *work = (CampMenuWork *)bytes;
        u32 tweenOffset = (u32)row * sizeof(CampMenuTween);
        CampMenuTween *tween = (CampMenuTween *)(tweenOffset + (u32)bytes + 0x94);
        u8 selectedAlpha = tween->alpha;
        s32 selectedOption = work->visibleOptions[work->selection];
        u8 *selectedSprite = work->sprites[2][selectedOption];
        sdkSpriteDrawSized(selectedSprite, pos.x, pos.y, 0.0f,
                      0xFF, 0xFF, 0xFF, selectedAlpha, 0x1000,
                      tween->scaleY, 0, 0.0f, 0);
    }
    pos.x = *(f32 *)(bytes + 0x224) + 18.0f;
    labelY = (f32)0x17D;
    labelY += *(f32 *)(bytes + 0x228);
    pos.y = labelY;
    numberColor = *(u8 *)(bytes + 0x22E);
    shdDrawNumberText(pos, 0.0f, numberColor, -1);
    pos2.x = *(f32 *)(bytes + 0x254) + 640.0f;
    pos2.y = *(f32 *)(bytes + 0x258) + 400.0f;
    informationColor = *(u8 *)(bytes + 0x25E);
    sdkSpriteDrawFooter(pos2, 0.0f, informationColor, 0, *(s32 *)(bytes + 0x90));
    return finished;
}

#pragma pop
/* measured: opt_loop_invariants on is load-bearing for 0012DC00 -- without it
   the object grows to 676 bytes against the 672-byte window at nd 243. */
#pragma opt_loop_invariants on
/* measured: closes the opt_loop_invariants bracket opened above func_0012dc00. */
#pragma opt_loop_invariants off
extern u8 D_005E58C0[];
extern u8 D_005E59A0[];
extern u8 D_005E5A80[];
extern void titleLayoutSlots(u8 *arg0);

#pragma push
/* measured: opt_loop_invariants on is load-bearing: removing it yields MISMATCH nd 383 (obj 684B/window 688B); on yields MATCH nd 0 (obj 680B/window 688B) by hoisting the case-zero constants. */
#pragma opt_loop_invariants on
/* measured: closes the opt_loop_invariants bracket for titleSlotSetMode. */
#pragma opt_loop_invariants off
#pragma pop
/* measured: opt_loop_invariants on hoists the conversion constants into the loop preheader. */
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
#pragma opt_rebuildconditionals on
/* measured: closes the opt_loop_invariants bracket for func_0012e2f0. */
#pragma opt_loop_invariants off
/* measured: opt_propagation off probe for temp16 width in func_0012e7c0 */
#pragma opt_propagation off
/* measured: opt_propagation on closes the temp16 width probe */
#pragma opt_propagation on
/* measured: propagation and constant extraction off preserve cached
 * opacity values and the independent animation-row evaluations. */
#pragma push
#pragma opt_propagation off
#pragma opt_pulloutconstants off
/* The label renderer reads these fields at offsets 0x00..0x18. */
typedef struct {
    s16 itemId;
    s16 quantity;
    s16 field04; /* Not read by these label modes. */
    s16 comparisonItem;
    s32 priceMode;
    s32 drawName;
    s32 drawStats;
    s16 iconFlags;
    s16 palette;
    s16 layout;
} CampLabelEntry;

/* Grid state shared with the countdown and cell-weight providers. */
typedef struct {
    s16 palette;
    s16 countdown;
    s32 column;
    s32 row;
    s32 columns;
    s32 rows;
} CampGridCell;

/* Draw the animated item list, selection, scrollbar, and background grid.
 * Native b210 -O2: 5148 executable bytes and four zero alignment bytes.
 * Preserve the independent position/opacity views across renderer calls. */
// Kept in bucket: diff 1481 when moved; cause not diagnosed.
// FUN_0012E9D0
void radarDrawPanel(u8 *state)
{
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2f position, s32 alpha, s32 mode, f32 depth);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern f32 cmpGridCellFade(u8 *cell, f32 horizontal, f32 vertical, f32 gain);
    extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth, u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
        u16 scaleY, s16 mode, f32 angle, s16 flags);
    extern void radarDrawSpritePair(u8 *state, s64 position, s32 color);
    extern void datEntryReset(u8 *entry);
    extern void datEntryDrawRow(Vec2f position, f32 depth, u8 alpha, u8 *entry);
    extern void radarDrawEntryRow(u8 *state, s32 index);
    extern u32 datEntryGetFlags(s16 item);
    extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 font, s32 mode, const char *text, s32 flags,
        s32 unused);
    extern void radarDrawEntryCard(u8 *state, PackedVec2f position, s32 alpha, s16 *entry);
    extern void sdkSpriteDrawFooter(Vec2f position, f32 depth, u8 alpha, s32 value, s32 mode);
    extern u8 D_005E76B0[];
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E4[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2F4[];
    extern u8 *iGpffff9cc8;
    PackedVec2f position;
    f32 opacityScale;
    f32 originX;
    f32 originY;
    f32 value;
    f32 scaledAlpha;
    s32 alphaByte;
    s32 dotIndex;
    void *dotSprite;
    s32 cellIndex;
    s32 labelIndex;
    u8 cachedAlpha;
    u8 *palette;
    s32 rowIndex;
    s32 selectedItem;
    u8 *row;
    CampGridCell *cell;
    f32 drawX;
    f32 rowY;
    f32 cellY;
    f32 cellWeight;
    CampLabelEntry label;
    CampLabelEntry detailLabel;
    typedef struct { u8 bytes[4]; } CampColorBytes;
    union { CampColorBytes channels; s32 word; } color;
    s32 itemIndex;
    s16 itemId;
    s16 quantity;
    u32 itemFlags;
    u8 *theme;
    s32 scrollRange;
    s32 scrollPosition;
    u8 fontAlpha;
    u8 *textRow;
    s32 textIndex;
    u8 *panelSprite;
    s16 selection;
    sdkRenderStateSetDefault();
    originX = *(f32 *)(state + 4);
    originY = *(f32 *)(state + 8);
    value = (f32)*(u8 *)(state + 0);
    opacityScale = value / 255.0f;
    if (*(s32 *)(state + 0x10) != 0) {
        position.xy.x = originX;
        position.xy.y = originY;
        scaledAlpha = 255.0f * opacityScale;
        alphaByte = (u8)scaledAlpha;
        nLineDrawSet(position.xy, alphaByte & 0xFF, *(s32 *)(state + 0x10), 0.0f);
    }
    selectedItem = *(s16 *)(state + 0x24) + *(s16 *)(state + 0x22);
    if ((*(s32 *)(state + 0x14) & 0x200) != 0) {
        dotSprite = *(void **)(state + 0x1B50);
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        dotIndex = 0;
        scaledAlpha = 190.0f * opacityScale;
        alphaByte = (u8)scaledAlpha;
        cachedAlpha = alphaByte;
        for (; dotIndex < 0xC; dotIndex++) {
            row = state + dotIndex * 0x30;
            position.xy.x = 363.0f + (originX + *(f32 *)(row + 0x1888));
            position.xy.y = 8.0f + (originY + *(f32 *)(row + 0x188C));
            sdkSpriteDrawAt(dotSprite, position.xy.x, position.xy.y, 0, 0xFF, 0x64, cachedAlpha);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        position.xy.x = 363.0f + (originX + *(f32 *)(state + 0x17F8));
        position.xy.y = 8.0f + (originY + *(f32 *)(state + 0x17FC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x1802) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        cachedAlpha = alphaByte;
        cellIndex = 0;
        rowY = position.xy.y;
        for (; cellIndex < 0x54; cellIndex++) {
            row = state + cellIndex * 0x14;
            cell = (CampGridCell *)(row + 0xC48);
            if (cell->palette >= 0) {
                drawX = position.xy.x + (f32)(*(s32 *)(row + 0xC4C) * 44);
                cellY = rowY + (f32)(*(s32 *)(row + 0xC50) * 37);

                /* Literal weights retain the compiler-owned small-data constants. */
                cellWeight = cmpGridCellFade((u8 *)cell, 0.3f, 0.3f, 0.6f);
                palette = D_005E76B0 + cell->palette * 4;
                color.channels = *(CampColorBytes *)palette;
                scaledAlpha = (f32)cachedAlpha * cellWeight;
                sdkSpriteDrawAt(dotSprite, drawX, cellY, color.channels.bytes[0], color.channels.bytes[1],
                    color.channels.bytes[2], (u8)scaledAlpha);
            }
        }
    }
    if ((*(s32 *)(state + 0x14) & 1) != 0) {
        position.xy.x = 152.0f + (originX + *(f32 *)(state + 0x12E8));
        position.xy.y = 370.0f + (originY + *(f32 *)(state + 0x12EC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x12F2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        sdkSpriteDrawAt(*(void **)(state + 0x1BDC), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alphaByte);
    }
    if ((*(s32 *)(state + 0x14) & 0x40) != 0) {
        position.xy.x = 16.0f + (originX + *(f32 *)(state + 0x1798));
        position.xy.y = 405.0f + (originY + *(f32 *)(state + 0x179C));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x17A2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        sdkSpriteDrawAt(*(void **)(state + 0x1B88), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alphaByte);
    }
    if ((*(s32 *)(state + 0x14) & 0x80) != 0) {
        position.xy.x = 62.0f + (originX + *(f32 *)(state + 0x17C8));
        position.xy.y = 405.0f + (originY + *(f32 *)(state + 0x17CC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x17D2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        sdkSpriteDrawAt(*(void **)(state + 0x1B8C), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, alphaByte);
    }
    if ((*(s32 *)(state + 0x14) & 8) != 0) {
        u8 headingAlpha;
        position.xy.x = 271.0f + (originX + *(f32 *)(state + 0x1468));
        position.xy.y = 21.0f + (originY + *(f32 *)(state + 0x146C));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x1472) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        headingAlpha = alphaByte;

        theme = D_0064B2F4;
        color.channels.bytes[0] = theme[0];
        color.channels.bytes[1] = theme[1];
        color.channels.bytes[2] = theme[2];
        color.channels.bytes[3] = headingAlpha;
        radarDrawSpritePair(state, position.packed, color.word);
        datEntryReset((u8 *)&label);
        label.itemId = ((s16 *)(state + 0x3E))[selectedItem * 2];
        label.quantity = ((s16 *)(state + 0x40))[selectedItem * 2];
        label.priceMode = -1;
        label.drawName = 1;
        label.drawStats = 0;
        label.layout = 4;
        label.iconFlags = 1;
        label.palette = 4;
        position.xy.x = position.xy.x + 1.0f;

        datEntryDrawRow(position.xy, 0.0f, headingAlpha, (u8 *)&label);
    }
    if ((*(s32 *)(state + 0x14) & 4) != 0) {
        for (labelIndex = 0; labelIndex < *(s16 *)(state + 0x3C); labelIndex++) {
            radarDrawEntryRow(state, labelIndex);
        }
    }
    if ((*(s32 *)(state + 0x14) & 0x400) != 0) {
        value = *(f32 *)(state + 0x1AF8) + (originX + *(f32 *)(state + 0x15B8));
        rowY = *(f32 *)(state + 0x1AFC) + (originY + *(f32 *)(state + 0x15BC));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x15C2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        cachedAlpha = alphaByte;
        drawX = 573.0f + value;
        position.xy.x = drawX;
        position.xy.y = 32.0f + rowY;
        sdkSpriteDrawAt(*(void **)(state + 0x1B44), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, cachedAlpha);
        position.xy.x = drawX;
        position.xy.y = 197.0f + rowY;
        sdkSpriteDrawAt(*(void **)(state + 0x1B48), position.xy.x, position.xy.y, 0xFF, 0xFF, 0xFF, cachedAlpha);
        position.xy.x = drawX;
        position.xy.y = 35.0f + rowY;
        scrollRange = (s32)*(s16 *)(state + 0xC3E) - 6;
        if (scrollRange > 0) {
            scrollPosition = (s32)*(s16 *)(state + 0x24) * 134;
            position.xy.y += (f32)(scrollPosition / scrollRange);
        }
        theme = D_0064B2E8;
        sdkSpriteDrawAt(*(void **)(state + 0x1B4C), position.xy.x, position.xy.y, theme[0], theme[1], theme[2],
            cachedAlpha);
    }
    if ((*(s32 *)(state + 0x14) & 2) != 0) {
        if (*(s16 *)(state + 0xC3E) == 0) {
            position.xy.x = 280.0f + (originX + *(f32 *)(state + 0x1318));
            position.xy.y = 20.0f + (originY + *(f32 *)(state + 0x131C));
            fontAlpha = *(u8 *)(state + 0x1322);
            frFontExDrawText(position.xy.x, position.xy.y, 0.0f, (fontAlpha | ~0xFF), 6, 1, (const char *)iGpffff9cc8,
                0, 0);
        } else {
            if (*(u8 *)(state + 0x1AD2) > 0) {
                position.xy.x = originX + *(f32 *)(state + 0x1AC8);
                position.xy.y = originY + *(f32 *)(state + 0x1ACC);
                theme = D_0064B2E4;
                panelSprite = *(u8 **)(state + 0x1B18);
                sdkSpriteDrawSized(panelSprite, position.xy.x, position.xy.y, 0.0f, theme[0], theme[1], theme[2],
                    *(u8 *)(state + 0x1AD2), 0x1000, 0x1000, 0, 0.0f, 0);
            }
            for (rowIndex = 0; rowIndex < 6; rowIndex++) {
                u8 iconAlpha;
                u8 *iconSprite;
                itemIndex = rowIndex + *(s16 *)(state + 0x24);
                if (itemIndex < *(s16 *)(state + 0xC3E)) {
                    row = state + itemIndex * 4;
                    itemId = *(s16 *)(row + 0x3E);
                    quantity = *(s16 *)(row + 0x40);
                    itemFlags = datEntryGetFlags(itemId);
                    selection = *(s16 *)(state + 0x22);
                    if (rowIndex == selection) {
                        theme = D_0064B2E8;
                        palette = D_0064B2EC;
                        if ((*(s32 *)(state + 0x14) & 0x100) != 0) {
                            continue;
                        }
                        position.xy.x = 223.0f + (originX + *(f32 *)(state + 0x1318));
                        position.xy.y = 21.0f + (*(f32 *)(state + 0x131C) + (originY + 34.0f * (f32)selection));
                        color.channels.bytes[0] = theme[0];
                        color.channels.bytes[1] = theme[1];
                        color.channels.bytes[2] = theme[2];
                        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x1322) * opacityScale;
                        alphaByte = (u8)scaledAlpha;
                        color.channels.bytes[3] = (u8)(alphaByte & 0xFF);

                        radarDrawSpritePair(state, position.packed, color.word);
                    } else {
                        theme = D_0064B2E4;
                        palette = D_0064B2E0;
                        row = state + rowIndex * 0x30;
                        position.xy.x = 221.0f + (originX + *(f32 *)(row + 0x1498));
                        position.xy.y = (21.0f + (originY + *(f32 *)(row + 0x149C))) + 34.0f * (f32)rowIndex;
                        scaledAlpha = (f32)(u32)*(u8 *)(row + 0x14A2) * opacityScale;
                        alphaByte = (u8)scaledAlpha;
                        panelSprite = *(u8 **)(state + 0x1B18);
                        sdkSpriteDrawSized(panelSprite, position.xy.x, position.xy.y, 0.0f, theme[0], theme[1], theme[2],
                            alphaByte, 0x1000, *(u16 *)(row + 0x14AE), 0, 0.0f, 0);
                    }
                    row = state + rowIndex * 0x30;
                    position.xy.x = 224.0f + (originX + *(f32 *)(row + 0x1498));
                    rowY = 34.0f * (f32)rowIndex;
                    position.xy.y = rowY + (23.0f + (originY + *(f32 *)(row + 0x149C)));
                    scaledAlpha = (f32)(u32)*(u8 *)(row + 0x14A2) * opacityScale;
                    iconAlpha = (u8)scaledAlpha;
                    if ((itemFlags & 0x10000) != 0) {
                        iconSprite = *(u8 **)(state + 0x1B9C);
                    } else if ((itemFlags & 0x20000) != 0) {
                        iconSprite = *(u8 **)(state + 0x1BA0);
                    } else {
                        iconSprite = *(u8 **)(state + 0x1B98);
                    }
                    /* Text geometry uses a separate row evaluation; the icon row
                     * remains live for the opacity read after label initialization. */
                    textIndex = rowIndex;
                    textRow = state + textIndex * 0x30;
                    sdkSpriteDrawSized(iconSprite, position.xy.x, position.xy.y, 0.0f, palette[0], palette[1],
                        palette[2], iconAlpha, 0x1000, *(u16 *)(textRow + 0x14AE), 0, 0.0f, 0);
                    position.xy.x = 266.0f + (originX + *(f32 *)(textRow + 0x1348));
                    position.xy.y = 21.0f + (*(f32 *)(textRow + 0x134C) + (originY + rowY));

                    datEntryReset((u8 *)&label);
                    label.itemId = itemId;
                    label.quantity = quantity;
                    label.priceMode = -1;
                    label.drawName = 1;
                    label.drawStats = 0;
                    label.layout = 4;
                    if (rowIndex == *(s16 *)(state + 0x22)) {
                        label.iconFlags = 0;
                        label.palette = 3;
                    } else {
                        label.iconFlags = 0;
                        label.palette = 2;
                    }
                    scaledAlpha = (f32)(u32)*(u8 *)(row + 0x1352) * opacityScale;
                    datEntryDrawRow(position.xy, 0.0f, (u8)scaledAlpha, (u8 *)&label);
                }
            }
        }
    }
    if (((*(s32 *)(state + 0x14) & 0x100) != 0) && (*(s16 *)(state + 0xC3E) != 0)) {
        position.xy.x = 223.0f + (originX + *(f32 *)(state + 0x1318));
        selection = *(s16 *)(state + 0x22);
        position.xy.y = 21.0f + (*(f32 *)(state + 0x131C) + (originY + 34.0f * (f32)selection));
        scaledAlpha = (f32)(u32)*(u8 *)(state + 0x15F2) * opacityScale;
        alphaByte = (u8)scaledAlpha;
        itemId = *(s16 *)(state + 0x24);
        detailLabel.itemId = ((s16 *)(state + 0x3E))[(itemId + selection) * 2];
        detailLabel.quantity = ((s16 *)(state + 0x40))[(itemId + *(s16 *)(state + 0x22)) * 2];
        detailLabel.priceMode = -1;
        detailLabel.drawName = 1;
        /* comparisonItem is only consumed when statistics are enabled. */
        detailLabel.drawStats = 0;
        detailLabel.palette = 3;
        detailLabel.iconFlags = 1;
        detailLabel.layout = 4;

        radarDrawEntryCard(state, position, alphaByte & 0xFF, (s16 *)&detailLabel);
    }
    position.xy.x = 640.0f + (originX + *(f32 *)(state + 0x1828));
    position.xy.y = 400.0f + (originY + *(f32 *)(state + 0x182C));
    value = (f32)*(u8 *)(state + 0x1832);
    scaledAlpha = value * opacityScale;
    alphaByte = (u8)scaledAlpha;
    sdkSpriteDrawFooter(position.xy, 0.0f, (u8)(alphaByte & 0xFF), *(s16 *)(state + 0xC40), *(s32 *)(state + 0x1BE4));
}

#pragma pop
/* measured: opt_common_subs off preserves the retail base+offset accesses in
   the two-record callback loop. */
#pragma opt_common_subs off
/* measured: opt_common_subs on closes the callback-loop probe. */
#pragma opt_common_subs on
extern u8 D_005E5BF0[];
extern u8 D_005E6290[];
extern u8 D_005E65E0[];
extern u8 D_005E6930[];
extern u8 D_005E6C80[];
extern u8 D_005E6FD0[];
extern u8 D_005E7320[];

/* measured: opt_common_subs off preserves retail's first-loop base/index
   addressing and setup order; on reverts immediately after the switch. */
#pragma opt_common_subs off
/* measured: closes opt_loop_invariants for func_0012ff60. */
#pragma opt_loop_invariants off
