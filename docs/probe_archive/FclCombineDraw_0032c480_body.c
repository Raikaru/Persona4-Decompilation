/* Research only; production func_0032c480 remains ASM.
 * MWCCPS2 b210 -O2 owner experiment: 472B/480B, exact emitted instructions
 * with the declarations below; only two omitted zero-tail words remain.
 * The private task-work getter closes the final pointer-load scheduling gap.
 * Twenty-one relocations were checked against retail symbols/addends.
 *
 * Integration blocker: this candidate needs the signed-halfword list-index
 * declaration. The existing MATCH func_0032b770 calls the same API with a
 * word index. Narrowing the owner declaration changes that loop from
 * 596B/608B to 604B/608B and breaks its match. Retaining the word declaration
 * leaves this candidate at 472B/480B with eight emitted differences: the
 * move-a0/lh-a1 pairs at +0x30/+0x34, +0x94/+0x98, +0x120/+0x124 and
 * +0x170/+0x174. Both-width caller/provider contracts must be reconciled;
 * do not install a block-local conflicting prototype to hide this problem.
 * A selected-record helper worsens the candidate; a selection-value helper
 * leaves those eight differences. Loop index narrowing and propagation
 * on/off do not preserve the existing loop match.
 *
 * Other required coherent migrations: func_00279350 queue is a pointer;
 * its owning definition and the float-preserving func_002bc7f0 bridge must
 * migrate together. func_0034a630 returns the task work pointer, not s32.
 * func_002e48a0 has u8* and u16* consumers; changing the latter requires
 * retaining their halfword offsets. iGpffffb440 is a string-table pointer.
 * Existing production byte opacity and float-first font contracts are used.
 *
 * Native C under undefined/function sanitizers: 125 cases passed. Covers
 * signed selection/mode boundaries, unsigned IDs, code+27 above 255, fresh
 * record lookups, model/work callback changes, byte clearing and final depth.
 * The color packer is pure and yields 0x000000FF for (0,0,0,255); no check
 * relies on unspecified nested-argument evaluation order. Native pointer
 * layouts adapt to the host; MWCC evidence establishes the retail offsets.
 */
#include "type.h"
#include "sdktask.h"
typedef struct { f32 x; f32 y; } FclVec2;
typedef struct {
    u8 reserved00[4];
    u8 *persona;
} CdfDrawWork;
typedef struct {
    u8 reserved00[0x11E];
    s16 selection;
    u8 reserved120[0x28];
    SdkTask *draw;
    u8 reserved14c[0x108];
    u8 *model;
} CdfCombineWork;

extern const char *iGpffffb440;
extern u8 D_00796310[];
extern u8 D_00796370[];
extern s32 func_002b2a30(u8, u8, u8, u8);
extern u8 *func_002e48a0(s8, s16);
extern int func_00275820(f32, f32, f32, int, int, int, const char *, int, int, void *, int);
extern u8 func_00109280(s32);
extern void func_002b2970(void *, f32, f32);
extern void func_00330e50(s32, s64, f32, s32, u8, s32, f32, f32, void *);
extern s8 func_00331640(void);
extern s32 func_00279350(f32, f32, f32, s32, s32, s32, s32, s32, s32, void *);
extern void func_0034a640(u8 *, u16, s64);
extern u8 *func_0034a630(u8 *);
extern void func_0011d1d0(u8 *, f32);

static inline u8 *cdfPersona(SdkTask *draw)
{
    return ((CdfDrawWork *)draw->work)->persona;
}
// FUN_0032C480
void func_0032c480(u8 *arg0)
{
    union { FclVec2 xy; s64 whole; } sp38;
    CdfCombineWork *obj;
    s32 n;

    obj = (CdfCombineWork *)((SdkTask *)arg0)->work;
    func_00275820(140.0f, 101.0f, 1.0f, func_002b2a30(0, 0, 0, 0xFF), 0, 2,
        iGpffffb440 + *(u16 *)(func_002e48a0(0, obj->selection) + 2) * 0x11,
        0, 0, D_00796310, 0x15);
    n = (s16)((func_00109280(*(u16 *)(func_002e48a0(0, obj->selection) + 2)) & 0xFF) + 0x1B);
    func_002b2970(&sp38.xy, 54.0f, 103.0f);
    func_00330e50(n, sp38.whole, 1.0f, 0xFF000000, 0xFF, 1, 1.0f, 1.0f, D_00796310);
    n = (s16)func_00331640();
    func_00279350(54.0f, 138.0f, 1.0f, -1, 1, 0, 1, n,
        *(u16 *)(func_002e48a0(0, obj->selection) + 2), D_00796370);
    func_0034a640(obj->model, *(u16 *)(func_002e48a0(0, obj->selection) + 2), 1);
    func_0034a630(obj->model)[1] = 0;
    func_0011d1d0(cdfPersona(obj->draw), 64000.0f);
}
