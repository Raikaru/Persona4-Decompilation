/* Field collision dispatcher; production remains ASM.
 * MWCCPS2 3.0.1 b210, -O2 -Iinclude, complete current k_fldFrame.c owner:
 * 476 emitted bytes / 480-byte retail window, ten resolved relocations,
 * one executable-word difference at +0x134. Retail branches to +0x154;
 * this candidate branches to +0x140, which then branches to +0x154.
 * The final four retail bytes are zero alignment, not missing executable code.
 * No bytes were appended and no instructions or relocations were patched.
 *
 * A real null-root early return and the shared inline preferred/fallback
 * selector remove the previous guard/constant/selection residuals. The
 * previous retained candidate reproduced 78 fully relocated word differences
 * (its older 72-word figure used relocation masking).
 * All 15 other emitted owner functions, including ten existing C matches,
 * retain their bytes and relocation identities.
 *
 * Native 64-bit ASan/UBSan/function smoke: 1,492,992 cases covering signed
 * grid boundaries, exact mode == 1 checks, cached initial guard, root reload,
 * provider mutations, full unsigned keys, first duplicate including a null
 * collection, preferred/fallback selection, and aliased hit-output vectors.
 * This uses native typed pointer layouts, not a claim of retail execution.
 * The matrix getter receives the owner's existing packed 32-bit frame handle.
 * Radius occupies f12 independently of the three integer pointer arguments.
 * Collection addresses are pointers; signed grid strides use multiplication.
 */
#pragma push
/* Measured full-owner loop-invariant and common-subexpression profile. */
#pragma opt_loop_invariants on
#pragma opt_common_subs on
extern s32 func_0016abc0(void* collisionWorld, f32* point, f32 radius, f32* normal,
                         f32* vector);

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

static inline void* fldSelectionWorld(FldSelectionResource* selected)
{
    void* world = selected->preferred;
    if (world != 0)
        return world;
    return selected->fallback;
}

s32 func_0016b080(f32* point, f32 radius, f32* normal, f32* vector)
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
            fieldX = (s32)((*(f32*)(map + 0x30) + 600.0f) / 1200.0f);
            fieldZ = (s32)((*(f32*)(map + 0x38) + 600.0f) / 1200.0f);
            key = *(u16*)((u8*)func_00155280() + (fieldZ * 256) +
                         (fieldX * 16) + 0x56);
            for (node = (FldSelectionNode*)func_001452b0(12); node != NULL;
                 node = node->next)
            {
                if (node->id == key)
                {
                    FldSelectionResource* selected = node->resource;
                    collisionWorld = fldSelectionWorld(selected);
                    break;
                }
            }
            result = func_0016abc0(collisionWorld, point, radius, normal, vector);
        }
        else
        {
            FldSelectionResource* selected = *(FldSelectionResource**)(iGpffff9db0 + 0x28);
            void* fallbackWorld = fldSelectionWorld(selected);
            result = func_0016abc0(fallbackWorld, point, radius, normal, vector);
        }
    }
    return result;
}
#pragma pop
