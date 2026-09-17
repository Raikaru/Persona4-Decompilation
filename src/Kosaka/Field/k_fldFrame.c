/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "include_asm.h"
#include "type.h"
#include "Kosaka/k_clump_internal.h"
#include "Kosaka/k_fldFrame_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u8* iGpffff9db0;
extern s32 func_00145270(s32 arg0);
extern u8* func_001452b0(s32 arg0);
extern s32 func_0014a160(void);
extern s32 func_0014a200(void);
extern s32 func_0014a270(void);
extern void* func_00155280(void);
extern s32 func_001687d0(s32 arg0);
extern s32 func_001687e0(s32 arg0);
extern s32 func_00169780(void* collisionWorld, f32* origin,
                         f32* vector, f32 fraction);
extern s32 func_0016a110(s32 collisionWorld, f32* origin,
                         f32* vector, f32 fraction, s32 fieldId);
extern u8* func_003e9700(s32 arg0);
extern u8* func_00457120(void);

extern void* func_00394d70(void* collisionWorld, void* intersection,
                           void* callback, void* param);
extern void func_003e40b0(f32* dst, const f32* src);
extern void func_0043f9c8(void* dst, s32 value, s32 size);

extern void func_00394e70(void* collision, void* state,
                          void* callback, void* param);
extern void* func_00169a30(const RwV3d* point, const void* triangle,
                           void* collector);

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;
extern void* func_0016b350(f32 fraction, const RwV3d* line,
                           void* unused, FldFrameRaycast* raycast);

// P3 counterpart fGpffff820c (gp -0x7DF4); P4 retail uses gp -0x7D4C,
// i.e. absolute 0x007690f0 - 0x7d4c = 0x007613a4.
extern f32 fGpffff82b4;
extern void* func_0016b430(void* collisionWorld, void* data);
extern void* func_0016b770(f32 fraction, const RwV3d* line,
                           void* unused, FldFrameRaycast* raycast);





// FUN_00169200
RwV3d* func_00169200(RwV3d* dst, const RwV3d* point,
                     const RwV3d* start, const RwV3d* end)
{
    RwV3d edge;
    f32 projection;
    f32 edgeLengthSquared;
    f32 fraction;

    edge.x = end->x - start->x;
    edge.y = end->y - start->y;
    edge.z = end->z - start->z;
    projection = point->x * edge.x + point->y * edge.y + point->z * edge.z -
                 (start->x * edge.x + start->y * edge.y + start->z * edge.z);

    if (projection <= 0.0f)
    {
        *dst = *start;
    }
    else
    {
        edgeLengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
        if (projection < edgeLengthSquared)
        {
            fraction = projection / edgeLengthSquared;
            dst->x = edge.x * fraction;
            dst->y = edge.y * fraction;
            dst->z = edge.z * fraction;
            dst->x += start->x;
            dst->y += start->y;
            dst->z += start->z;
        }
        else
        {
            *dst = *end;
        }
    }

    return dst;
}



/* measured: floor 155 differing words (reloc-masked), object 1112B vs 1120B window (8B retail zero tail). */
/* Floor: 209 differing words over 26 edits, 274 emitted against retail's
   277 (1112 bytes in an 1120-byte window with an 8-byte zero tail).  The
   previous archive measured 155 words but 270 alignment edits; this body
   aligns instruction for instruction except at one site per search loop.
   Levers: extern f32 fabsf(f32) gives retail's abs.s; func_00168ec0 and
   func_003e4180 keep their real prototypes; a separate edge distance
   preserves the second path's FPR live range; the search index, count,
   record and slot pointers are block-scoped per branch, which puts the
   index in $a0 and the count in $v1; the record and triangle copies are
   RwV3d struct assignments (paired lwc1/swc1); a miss falls out of the
   search into `index = -1` and a hit jumps past it, and the existing-entry
   branch is written first (`index >= 0`); the slot address is
   `(u8 *)(4 * index) + (u32)context + 0x600` so the scaled index is added
   first, while the record address stays base-first.
   WALL: the third equality test - retail emits `bc1f` to the increment and
   an unconditional `b` to the hit label, this build folds it into `bc1t`;
   every later branch displacement moves by two words.  Nested ifs, a
   negated `||` continue form, a found flag, opt_rebuildconditionals,
   opt_propagation, opt_lifetimes and opt_dead_code were measured. */
// FUN_00169320 NONMATCHING
#ifdef NON_MATCHING
void* func_00169320(RwV3d* point, void* unused, RwV3d* triangle, u8* context)
{
    extern f32 fabsf(f32 x);
    extern s32 func_00168ec0(void *arg0, void *arg1, void *arg2);
    extern f32 func_003e4180(f32 *vec);
    typedef struct FldFrameTriangle
    {
        RwV3d vector;
        u8 gap[0x10];
        RwV3d* normal;
    } FldFrameTriangle;
    FldFrameTriangle* triangleData;
    RwV3d projected;
    RwV3d edgePoint;
    RwV3d delta;
    RwV3d* normal;
    f32 projection;
    f32 distance;
    f32 edgedist;
    s32 i;
    f32 tx;
    f32 ty;
    f32 tz;
    triangleData = (FldFrameTriangle*)triangle;
    ty = triangleData->vector.y;
    tx = triangleData->vector.x;
    tz = triangleData->vector.z;
    normal = triangleData->normal;
    projection = normal->x * tx + normal->y * ty + normal->z * tz - (point->x * tx + point->y * ty + point->z * tz);
    projected.x = tx * projection;
    projected.y = ty * projection;
    projected.z = tz * projection;
    projected.x += point->x;
    projected.y += point->y;
    projected.z += point->z;
    if (func_00168ec0(&projected, (u8*)triangle + 0x1c, triangle) != 0)
    {
        distance = fabsf(projection);
        {
        s32 index;
        s32 count;
        f32* record;
        f32* fraction;
        index = 0;
        count = *(s32*)(context + 0xb04);
        while (index < count)
        {
            record = (f32*)(context + 12 * index);
            if (record[192] == triangle->x && record[193] == triangle->y && record[194] == triangle->z)
                goto found1;
            index++;
        }
        index = -1;
found1:
        if (index >= 0)
        {
            fraction = (f32*)((u8*)(4 * index) + (u32)context + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * index);
                *(RwV3d*)record = projected;
                *(RwV3d*)(record + 192) = *triangle;
                *fraction = distance;
            }
        }
        else
        {
            fraction = (f32*)((u8*)(4 * count) + (u32)context + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * count);
                *(RwV3d*)record = projected;
                record = (f32*)((u8*)(12 * *(s32*)(context + 0xb04)) + (u32)context);
                *(RwV3d*)(record + 192) = *triangle;
                fraction = (f32*)((u8*)(4 * *(s32*)(context + 0xb04)) + (u32)context + 0x600);
                *fraction = distance;
                (*(s32*)(context + 0xb04))++;
            }
        }
    }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            func_00169200(&edgePoint, &projected, *(RwV3d**)((u8*)triangle + 0x1c + 4 * i), *(RwV3d**)((u8*)triangle + 0x1c + 4 * ((i + 1) % 3)));
            delta.x = point->x - edgePoint.x;
            delta.y = point->y - edgePoint.y;
            delta.z = point->z - edgePoint.z;
            edgedist = func_003e4180((f32*)&delta);
            {
            s32 index;
            s32 count;
            f32* record;
            f32* fraction;
            index = 0;
            count = *(s32*)(context + 0xb04);
            while (index < count)
            {
                record = (f32*)(context + 12 * index);
                if (record[192] == triangle->x && record[193] == triangle->y && record[194] == triangle->z)
                    goto found2;
                index++;
            }
            index = -1;
found2:
            if (index >= 0)
            {
                fraction = (f32*)((u8*)(4 * index) + (u32)context + 0x600);
                if (edgedist < *fraction)
                {
                    record = (f32*)(context + 12 * index);
                    *(RwV3d*)record = edgePoint;
                    *(RwV3d*)(record + 192) = *triangle;
                    *fraction = edgedist;
                }
            }
            else
            {
                fraction = (f32*)((u8*)(4 * count) + (u32)context + 0x600);
                if (edgedist < *fraction)
                {
                    record = (f32*)(context + 12 * count);
                    *(RwV3d*)record = projected;
                    record = (f32*)((u8*)(12 * *(s32*)(context + 0xb04)) + (u32)context);
                    *(RwV3d*)(record + 192) = *triangle;
                    fraction = (f32*)((u8*)(4 * *(s32*)(context + 0xb04)) + (u32)context + 0x600);
                    *fraction = edgedist;
                    (*(s32*)(context + 0xb04))++;
                }
            }
            }
        }
    }
    return triangle;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_00169320);
#endif
/* Floor: 88 differing words (reloc-masked fndiff), obj 664B/window 688B, 166 vs 169
   instrs, 52 fnalign edits plus 2 reloc-only. Cold start from the retail window;
   nearest archives (LFF2 nd340, LaneFldFrame non-MATCH) contributed only the buffer
   shape. Work struct mirrors sibling func_0016abc0's measured query-work pattern
   (records/mode/count/hitCount/gap/scratch/zero/input/inputCopy/inputTail/type):
   retail offsets fix records[0xB00], count +0xB04, endpoint copy 0xBB0->0xBC0 (lq/sq
   via u_long128), type +0xB78 and delta +0xB80, so the 0x48 interior and the 8-byte
   tail are sized, not invented; mode/hitCount/gap/scratch/zero/tail are unstored on
   this path (retail writes neither) and documented here, not asserted as used. The
   nested query sub-struct carries the u_long128 alignment that pads 0x2C->0x30 and
   lands delta at +0xB80; the main loop reads the copy (displacement proof: retail
   loads 0xBC0/0xBCC, never 0xBB0). Frame 0xBF0, save set s0-s4 and all 6 retail
   relocations (2x memset, 69320 HI/LO, 394d70, 3e40b0 at identical offsets) match;
   the 2 extra object GPRELs are link-time small-data for fGpffff82b4.
   WALLS: (1) saved rotation retail i/result/vector/cw/rec in $s0..$s4 vs build
   cw/i/result/vector/rec: cw sits 4th vs 1st, everything else identical. Stable
   across 12 probes: two struct models, three decl orders, s32/void* handle, union
   copy reads, block/function-scope pointer, dot associations, scheduler scopes.
   A void* local copy is copy-propagated away (neutral); only a true prototype
   change moves it, and void* is kept anyway as the semantic truth (world pointer
   into a void* callee, sibling 0016a0c0 precedent) with the sole caller 0016a960
   verified MATCH. (2) scale CSE: retail recomputes the fractions address post-call
   in a $v0 temp with split +0x60/+0x600 (7-vs-4, the 3-instruction shortfall); this
   build carries the folded +0x660 address in dead-cw $s0 across func_003e40b0.
   Killed: fq-temp split (110, +17 via an extra saved live range), result=0 late
   (163, destroys the early-zero prologue), yoda zero-checks (neutral), scoped
   schedule off (neutral), commute/scope CSE splits (neutral). (3) zero-check FPR:
   $f1-zero retail vs $f2-zero build plus cascade. s32 loop index throughout (no
   spurious dsll32/dsra32). Production stays ASM; func_00169320 and func_0016abc0
   untouched. */
// FUN_00169780 NONMATCHING
#ifdef NON_MATCHING
s32 func_00169780(void* collisionWorld, f32* origin,
                  f32* vector, f32 fraction)
{
    extern void* func_00169320(RwV3d* point, void* unused, RwV3d* triangle,
                              u8* context);
    typedef struct FldFrameWork69780
    {
        u8 records[0xb00];
        s32 mode;
        s32 count;
        s32 hitCount;
        u8 gap[0xc];
        u8 scratch[0x20];
        u8 zero[0x18];
        f32 input[4];
        struct
        {
            union
            {
                u_long128 bits;
                f32 f[4];
            } copy;
            u8 tail[8];
            s32 type;
        } query;
        RwV3d delta;
    } FldFrameWork69780;
    FldFrameWork69780 work;
    f32 px, py, pz;
    f32 scale;
    f32 dot;
    s32 i;
    s32 result;

    result = 0;
    work.input[0] = origin[0] + vector[0];
    work.input[1] = origin[1] + vector[1];
    work.input[2] = origin[2] + vector[2];
    work.input[3] = fraction;
    work.query.type = 3;
    work.query.copy.bits = *(u_long128*)work.input;
    for (i = 0; i < 64; i++)
    {
        u8* rec = work.records + 12 * i;
        func_0043f9c8(rec, 0, 12);
        func_0043f9c8(rec + 0x300, 0, 12);
        *(f32*)(work.records + 0x600 + 4 * i) = fGpffff82b4;
    }
    work.count = 0;
    if (collisionWorld == NULL)
    {
        return 0;
    }
    func_00394d70(collisionWorld, &work.query.copy, func_00169320, work.records);
    for (i = 0; i < work.count; i++)
    {
        if (((f32*)(work.records + 0x600))[i] < fGpffff82b4)
        {
            RwV3d* point = (RwV3d*)(work.records + 12 * i);
            work.delta.x = work.query.copy.f[0] - point->x;
            work.delta.y = work.query.copy.f[1] - point->y;
            work.delta.z = work.query.copy.f[2] - point->z;
            func_003e40b0(&work.delta.x, &work.delta.x);
            scale = work.query.copy.f[3] - ((f32*)(work.records + 0x600))[i];
            px = work.delta.x * scale;
            py = work.delta.y * scale;
            pz = work.delta.z * scale;
            dot = vector[0] * work.delta.x + vector[1] * work.delta.y + vector[2] * work.delta.z;
            if (dot < 0.0f)
            {
                px = work.delta.x * dot;
                py = work.delta.y * dot;
                pz = work.delta.z * dot;
                vector[0] -= px;
                vector[1] -= py;
                vector[2] -= pz;
                result = 1;
            }
            if (vector[0] == 0.0f && vector[1] == 0.0f && vector[2] == 0.0f)
            {
                vector[0] += px;
                vector[1] += py;
                vector[2] += pz;
                result = 1;
            }
        }
    }
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_00169780);
#endif
// FUN_00169A30
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_00169a30);
// FUN_0016A0C0
void* func_0016a0c0(void* collisionWorld, void* state)
{
    *(void**)((u8*)state + 0xb34) = collisionWorld;
    func_00394e70(collisionWorld, (u8*)state + 0xb18,
                  func_00169a30, state);
    return collisionWorld;
}



// FUN_0016A110
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016a110);
// FUN_0016A960
s32 func_0016a960(f32* origin, f32* vector, f32 fraction, s32 fieldId)
{
    u8* object;
    s32 collisionWorld;
    object = *(u8**)(iGpffff9db0 + 0x28);

    if (object == NULL)
    {
        return 0;
    }
    if ((*(s32*)object & 1) != 0)
    {
        return func_00169780((void*)(*(s32*)(object + 0xc)), origin, vector, fraction);
    }

    collisionWorld = 0;
    if (func_0014a200() == 1 ||
        (*(s32*)iGpffff9db0 >= 0x33 && *(s32*)iGpffff9db0 < 0x4f))
    {
        u8* entry;
        u8* field;
    s32 fieldX;
    s32 fieldY;
        s32 fieldFlags;
        entry = (u8*)func_001452b0(0xc);
        field = (u8*)func_00145270(fieldId);
        fieldFlags = fieldId & 0xffff;
        if (fieldFlags == 0xffff)
        {
            object = (u8*)func_003e9700(
                *(s32*)((u8*)func_00457120() + 4));
            fieldX = (s32)((*(f32*)(object + 0x30) + 600.0f) / 1200.0f);
            fieldY = (s32)((*(f32*)(object + 0x38) + 600.0f) / 1200.0f);
        }
        else
        {
            if (((fieldFlags & 0xffc00) >> 10) == 1)
            {
                s32* coordinate;
                coordinate = (s32*)(field + 0x220);
                fieldX = func_001687d0(*coordinate);
                fieldY = func_001687e0(*coordinate);
            }
            else
            {
                s32* coordinate;
                coordinate = (s32*)(field + 0x228);
                fieldX = func_001687d0(*coordinate);
                fieldY = func_001687e0(*coordinate);
            }
        }
        {
            u32 key;
            key = *(u16*)((u8*)func_00155280() + (fieldY << 8) +
                          (fieldX << 4) + 0x56);
            while (entry != NULL)
            {
                if (*(u16*)entry == key)
                {
                    collisionWorld = *(s32*)(*(u8**)(entry + 0x1a0) + 8);
                    break;
                }
                entry = *(u8**)(entry + 0x138);
            }
        }
    }
    else
    {
        collisionWorld = *(s32*)(*(u8**)(iGpffff9db0 + 0x28) + 8);
    }
    return func_0016a110(collisionWorld, origin, vector, fraction, fieldId);
}
/* measured: floor 211 differing words (reloc-masked), object 299 instrs vs retail 303 instrs (1196B vs 1212B, 4-instr deficit, 129 edits +3 reloc-only).
 * Signature (void*, RwV3d*, f32, RwV3d*, RwV3d*) copies the MATCHed func_0016b080 extern and caller setup.
 * Threshold D_007615DC (0x007615DC, gp-0x7B14) not fGpffff82b4; table D_005F1650[2*j] pairs; grid key search copies func_0016b540 raw u8* +0x1A0/+0x138/+8 pattern; 600.0f/1200.0f via f32; lq/sq via u_long128; bare &normal->x for func_003e40b0.
 * Probes (probe_variants, reloc-masked): baseline 227 -> scoped 7-word copy (separate n, temp v) 222 -> point temps px/py/pz + for-forms 219.
 * Declaration search (probe_search): 200 orders 227->218; 500 orders on v3 219->211; 300 orders on v6/v7 219->211 (best order kept).
 * Parent lever 1 (opt_loop_invariants on before for): grid for 219->219, final while 219->219, for-forms 219->219; OFF at -O2 baseline, measured no-op here.
 * Parent lever 2 (cast at call site moves setup): bare &normal->x vs (f32*)normal, 0.0f vs *(u32*), u8* rec vs f32* rec, header KClumpCallback vs void* shadow: v6 219 vs v7 219, no-op (no stack args).
 * WALL: param home-move daddu block order invariant per parent (declaration/initialiser/assignment/K&R/copy-local identical); retail recomputes &D[2*j] once while reusing +4 in $s6, this build CSEs both through offsets (fnalign retail[150:154] 4-instr deficit); saved-register colors $s0-$s7/$fp permuted after exhaustive search.
 * Floor keeps production INCLUDE_ASM; body is semantically faithful. */
/* fresh 2026-09-17: cur 211wd confirmed; fnalign 303v299 (4 short, 50 ops); dead-arm N/A (shortfall deletes are straight-line: [150:154] 4-instr address recompute sll/lui/addiu/addu (allocator-pressure wall, base rematerialized not reused), [216:219] 3x sw-zero (store-scheduling wall), [224:226] const remat (loop-invariants no-op stays banked), [264:266] loop-structural + 13/15-block unroll divergence; [84:88] bnez+move+b vs beqz tail-merge is peephole wall (same family as Main 169320 bc1f/b vs bc1t); no compare/branch/store delete site); parent 4938e0 levers N/A (no 0xFFFF-at-calls + frame-reg symptom (frame matches, no sq/lq pair); line-88 || is two different calls ==1 (no adjacent-const fold, no addiu+sltiu emitted); no COP2); index-commute skipped (compiler canonicalizes 2*j==j*2, base-reuse is pressure not syntax); prior 500-order/colours/CSE/scheduling walls stand. Guard kept as floor. */
// FUN_0016ABC0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0016abc0(void* collisionWorld, const RwV3d* point, f32 radius, RwV3d* normal, RwV3d* vector)
{
    extern u8* func_001452b0(s32 arg0);
    extern void func_0043f9c8(void* dst, s32 value, s32 size);
    extern s32 func_0014a200(void);
    extern s32 func_0014a270(void);
    extern u8* func_00457120(void);
    extern u8* func_003e9700(s32 arg0);
    extern void* func_00155280(void);
    extern void* func_0047a310(s32 arg0);
    extern void func_003e40b0(f32* dst, const f32* src);
    extern f32 D_007615DC;
    extern s32 D_005F1650[];
    typedef struct FldFrameQueryWork
    {
        u8 records[0xb00];
        s32 mode;
        s32 count;
        s32 hitCount;
        u8 gap[0xc];
        u8 scratch[0x20];
        u8 zero[0x18];
        f32 input[4];
        u_long128 inputCopy;
        u8 inputTail[8];
        s32 intersectionType;
    } FldFrameQueryWork;
    FldFrameQueryWork work;
    u16 id;
    f32 py;
    f32 px;
    f32* dimensions;
    u8* node;
    u8* list;
    s32 foundCount;
    s32 i;
    f32* entry;
    void* table;
    s32 x;
    f32 threshold;
    s32 z;
    s32 result;
    s32 j;
    void* target;
    f32 pz;

    result = 0;
    list = func_001452b0(10);
    func_001452b0(3);
    func_001452b0(1);
    px = point->x;
    py = point->y;
    pz = point->z;
    work.input[0] = px;
    work.input[1] = py;
    work.input[2] = pz;
    work.input[3] = radius;
    work.intersectionType = 3;
    work.inputCopy = *(u_long128*)work.input;
    for (i = 0; i < 64; i++)
    {
        u8* rec = work.records + 12 * i;
        func_0043f9c8(rec, 0, 12);
        func_0043f9c8(rec + 0x300, 0, 12);
        *(f32*)(work.records + 0x600 + 4 * i) = D_007615DC;
        *(s32*)(work.records + 0xa00 + 4 * i) = 0;
    }
    work.hitCount = 0;
    work.count = 0;
    {
        s32* src = (s32*)&work.inputCopy;
        s32* dst = (s32*)work.scratch;
        s32 n = 7;
        do
        {
            s32 v = *src;
            src++;
            n--;
            *dst = v;
            dst++;
        } while (n > 0);
    }
    func_0043f9c8(work.zero, 0, 12);
    if (collisionWorld != 0)
    {
        work.mode = 1;
        func_003bff30(collisionWorld, func_0016a0c0, work.records);
        if (func_0014a200() == 1 || func_0014a270() == 1)
        {
            dimensions = (f32*)func_003e9700(*(s32*)((u8*)func_00457120() + 4));
            x = (s32)((dimensions[12] + 600.0f) / 1200.0f);
            z = (s32)((dimensions[14] + 600.0f) / 1200.0f);
            for (j = 0; j < 4; j++)
            {
                s32* offsets = &D_005F1650[2 * j];
                table = func_00155280();
                if (*(u8*)((u8*)table + ((z + offsets[1]) << 8) + 16 * (x + offsets[0]) + 84) == 1)
                {
                    table = func_00155280();
                    id = *(u16*)((u8*)table + ((z + offsets[1]) << 8) + 16 * (x + offsets[0]) + 86);
                    target = 0;
                    node = func_001452b0(12);
                    while (node != 0)
                    {
                        if (*(u16*)node == id)
                        {
                            target = *(void**)(*(u8**)(node + 0x1a0) + 8);
                            break;
                        }
                        node = *(u8**)(node + 0x138);
                    }
                    if (target != 0)
                        func_003bff30(target, func_0016a0c0, work.records);
                }
            }
            while (list != 0)
            {
                if ((*(s32*)(list + 0x28) & 2) != 0 && *(s32*)(list + 0x150) == 1)
                {
                    target = func_0047a310(*(s32*)(list + 0x144));
                    func_003bff30(target, func_0016a0c0, work.records);
                }
                list = *(u8**)(list + 0x138);
            }
        }
        normal->x = 0.0f;
        normal->y = 0.0f;
        normal->z = 0.0f;
        vector->x = 0.0f;
        vector->y = 0.0f;
        vector->z = 0.0f;
        foundCount = 0;
        threshold = D_007615DC;
        for (i = 0; i < work.count; i++)
        {
            entry = (f32*)(work.records + 12 * i);
            if (*(f32*)(work.records + 0x600 + 4 * i) < threshold)
            {
                normal->x += entry[192];
                normal->y += entry[193];
                normal->z += entry[194];
                vector->x += entry[0];
                vector->y += entry[1];
                vector->z += entry[2];
                foundCount++;
                result = 1;
            }
        }
        if (result == 1)
        {
            func_003e40b0(&normal->x, &normal->x);
            threshold = (f32)foundCount;
            vector->x /= threshold;
            vector->y /= threshold;
            vector->z /= threshold;
        }
        return result;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016abc0);
#endif
/* 476/480 bytes; ten resolved relocations; four zero alignment bytes.
 * Write the preferred/fallback selection through the caller's real output. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs on
extern s32 func_0016abc0(void* collisionWorld, const RwV3d* point, f32 radius,
                         RwV3d* normal, RwV3d* vector);

typedef struct FldSelectionResource
{
    u32 flags;
    u32 unknown04;
    void* fallback;
    u32 unknown0c;
    u32 unknown10;
    void* preferred;
} FldSelectionResource;
typedef struct FldSelectionNode
{
    u16 id;
    u8 unknown002[0x136];
    struct FldSelectionNode* next;
    u8 unknown13c[0x64];
    FldSelectionResource* resource;
} FldSelectionNode;

static inline void fldFrameSelectWorld(FldSelectionResource* selected, void** dst)
{
    void* world = selected->preferred;
    if (world != 0)
    {
        *dst = world;
        return;
    }
    *dst = selected->fallback;
}

// FUN_0016B080
s32 func_0016b080(const RwV3d* point, f32 radius, RwV3d* normal, RwV3d* vector)
{
    s32 result;
    void* collisionWorld;
    s32 fieldX;
    s32 fieldZ;
    u16 key;

    FldSelectionResource* object;
    result = 0;
    object = *(FldSelectionResource**)(iGpffff9db0 + 0x28);
    if (object == NULL)
        return result;
    if ((object->flags & 1) == 0)
    {
        collisionWorld = 0;
        if (func_0014a200() == 1 || func_0014a270() == 1)
        {
            u8* map;
            FldSelectionNode* node;
            map = func_003e9700(*(s32*)(func_00457120() + 4));
            fieldX = (s32)((((const RwV3d*)(map + 0x30))->x + 600.0f) / 1200.0f);
            fieldZ = (s32)((((const RwV3d*)(map + 0x30))->z + 600.0f) / 1200.0f);
            key = *(u16*)((u8*)func_00155280() + (fieldZ * 256) +
                         (fieldX * 16) + 0x56);
            for (node = (FldSelectionNode*)func_001452b0(12); node != NULL;
                 node = node->next)
            {
                if (node->id == key)
                {
                    FldSelectionResource* selected = node->resource;
                    fldFrameSelectWorld(selected, &collisionWorld);
                    break;
                }
            }
            result = func_0016abc0(collisionWorld, point, radius, normal, vector);
        }
        else
        {
            FldSelectionResource* selected = *(FldSelectionResource**)(iGpffff9db0 + 0x28);
            void* fallbackWorld;
            fldFrameSelectWorld(selected, &fallbackWorld);
            result = func_0016abc0(fallbackWorld, point, radius, normal, vector);
        }
    }
    return result;
}
#pragma pop

/* measured: propagation probe for func_0016b260 register scheduling. */
#pragma opt_propagation off
// FUN_0016B260
void* func_0016b260(const RwV3d* line, void* unused,
                    const void* triangle, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d start;
        RwV3d end;
    } FldFrameLine;
    RwV3d delta;
    FldFrameLine lineCopy;
    const RwV3d* normal;
    const RwV3d* point;
    f32 startX;
    f32 deltaX;
    f32 startY;
    f32 deltaY;
    f32 startZ;
    f32 deltaZ;
    f32 normalX;
    f32 normalY;
    f32 normalZ;
    f32 numerator;
    f32 denominator;
    f32 fraction;

    lineCopy = *(const FldFrameLine*)line;
    startX = lineCopy.start.x;
    deltaX = startX - lineCopy.end.x;
    startY = lineCopy.start.y;
    deltaY = startY - lineCopy.end.y;
    startZ = lineCopy.start.z;
    deltaZ = startZ - lineCopy.end.z;
    normal = (const RwV3d*)triangle;
    normalY = normal->y;
    normalX = normal->x;
    normalZ = normal->z;
    denominator = normalX * deltaX + normalY * deltaY + normalZ * deltaZ;
    point = *(const RwV3d**)((const u8*)triangle + 0x1c);
    numerator = -(-(normalX * point->x + normalY * point->y +
                    normalZ * point->z) +
                   (normalX * startX + normalY * startY +
                    normalZ * startZ));
    fraction = numerator / denominator;
    raycast->hitPointDst->x = fraction * deltaX + startX;
    raycast->hitPointDst->y = fraction * deltaY + startY;
    raycast->hitPointDst->z = fraction * deltaZ + startZ;
    raycast->didHit = 1;
    return 0;
}
#pragma opt_propagation on
// FUN_0016B350
void* func_0016b350(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    FldFrameLine lineCopy;
    RwV3d segment;

    lineCopy = *(const FldFrameLine*)line;
    if (raycast->nearestFraction > fraction)
    {
        segment.x = lineCopy.point[1].x - lineCopy.point[0].x;
        segment.y = lineCopy.point[1].y - lineCopy.point[0].y;
        segment.z = lineCopy.point[1].z - lineCopy.point[0].z;
        segment.x *= fraction;
        segment.y *= fraction;
        segment.z *= fraction;
        segment.x += lineCopy.point[0].x;
        segment.y += lineCopy.point[0].y;
        segment.z += lineCopy.point[0].z;
        *raycast->hitPointDst = segment;
        raycast->didHit = 1;
        raycast->nearestFraction = fraction;
    }
    return unused;
}



// FUN_0016B430
void* func_0016b430(void* collisionWorld, void* data)
{
    FldFrameRaycast* raycast = data;
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, &raycast->line[0],
                  func_0016b350, raycast);
    return collisionWorld;
}



// FUN_0016B480
u32 func_0016b480(void* collisionWorld, const RwV3d* line,
                  RwV3d* hitPointDst)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    typedef struct FldFrameIntersection
    {
        FldFrameLine line;
        u32 type;
    } FldFrameIntersection;
    FldFrameLine lineCopy __attribute__((aligned(16)));
    FldFrameIntersection intersection __attribute__((aligned(16)));
    FldFrameRaycast raycast;

    lineCopy = *(const FldFrameLine*)line;
    raycast.hitPointDst = hitPointDst;
    raycast.didHit = 0;
    raycast.nearestFraction = fGpffff82b4;
    intersection.type = 1;
    intersection.line = lineCopy;
    *(FldFrameIntersection*)&raycast.line[0] = intersection;

    if (collisionWorld == NULL)
    {
        return 0;
    }
    func_003bff30(collisionWorld, func_0016b430, &raycast);
    return raycast.didHit;
}



/* Snapshot both endpoints before any provider call. Grid lookup uses start X/Z;
   the non-grid path reloads the root after the mode query. Branch-local full
   raycast state reproduces all 560 retail bytes and 12 relocations without
   artificial alignment. A hit writes all three destination components. */
// FUN_0016B540
u32 func_0016b540(const RwV3d* line, RwV3d* hitPointDst)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    typedef struct FldFrameIntersection
    {
        FldFrameLine line;
        u32 type;
    } FldFrameIntersection;
    FldFrameLine lineCopy;
    u8* object;
    void* collisionWorld;

    lineCopy = *(const FldFrameLine*)line;
    object = *(u8**)(iGpffff9db0 + 0x28);
    if (object == NULL)
    {
        return 0;
    }
    if ((*(u32*)object & 1) != 0)
    {
        FldFrameIntersection intersection;
        FldFrameRaycast raycast;
        u32 result;
        collisionWorld = *(void**)(object + 0xc);
        raycast.hitPointDst = hitPointDst;
        raycast.didHit = 0;
        intersection.type = 1;
        intersection.line = lineCopy;
        if (collisionWorld == NULL)
        {
            result = 0;
        }
        else
        {
            func_00394d70(collisionWorld, &intersection, func_0016b260, &raycast);
            result = raycast.didHit;
        }
        return result;
    }
    else
    {
        FldFrameIntersection intersection;
        FldFrameRaycast raycast;
        collisionWorld = NULL;
        if (func_0014a160() != 0)
        {
            u8* entry;
            u32 key;
            entry = func_001452b0(0xc);
            key = *(u16*)((u8*)func_00155280() +
                         (s32)((600.0f + lineCopy.point[0].z) / 1200.0f) * 0x100 +
                         (s32)((600.0f + lineCopy.point[0].x) / 1200.0f) * 0x10 + 0x56);
            while (entry != NULL)
            {
                if (*(u16*)entry == key)
                {
                    collisionWorld = *(void**)(*(u8**)(entry + 0x1a0) + 8);
                    break;
                }
                entry = *(u8**)(entry + 0x138);
            }
        }
        else
        {
            collisionWorld = *(void**)(*(u8**)(iGpffff9db0 + 0x28) + 8);
        }
        raycast.hitPointDst = hitPointDst;
        raycast.didHit = 0;
        raycast.nearestFraction = fGpffff82b4;
        intersection.type = 1;
        intersection.line = lineCopy;
        *(FldFrameIntersection*)&raycast.line[0] = intersection;
        if (collisionWorld == NULL)
        {
            return 0;
        }
        func_003bff30(collisionWorld, func_0016b430, &raycast);
        return raycast.didHit;
    }
}
// FUN_0016B770
void* func_0016b770(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    FldFrameLine lineCopy;
    RwV3d segment;

    lineCopy = *(const FldFrameLine*)line;
    if (raycast->nearestFraction > fraction)
    {
        segment.x = lineCopy.point[1].x - lineCopy.point[0].x;
        segment.y = lineCopy.point[1].y - lineCopy.point[0].y;
        segment.z = lineCopy.point[1].z - lineCopy.point[0].z;
        segment.x *= fraction;
        segment.y *= fraction;
        segment.z *= fraction;
        segment.x += lineCopy.point[0].x;
        segment.y += lineCopy.point[0].y;
        segment.z += lineCopy.point[0].z;
        *raycast->hitPointDst = segment;
        raycast->didHit = 1;
        raycast->nearestFraction = fraction;
    }
    return unused;
}



// FUN_0016B850
void* func_0016b850(void* collisionWorld, void* data)
{
    FldFrameRaycast* raycast = data;
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, &raycast->line[0],
                  func_0016b770, raycast);
    return collisionWorld;
}
