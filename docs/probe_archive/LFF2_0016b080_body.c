/* IDA-backed field selection; production remains ASM.
 * MWCCPS2 b210, full owner profile: 476B / 480B, 72 differing masked words
 * (71 emitted differences and the omitted zero tail at 0x1dc).
 * Thirty-five source-shape probes improved the former 460B/93-word floor.
 * A typed resource/list prefix, cached initial guard, lexical float placement
 * and common-subexpression disabling are retained. Remaining differences:
 * null/disabled guard folding, duplicated FP constants and preferred/fallback
 * joins. The final default call and epilogue align with retail.
 * Integer arguments remain a0/a1/a2; fraction independently occupies f12.
 * The callee declaration below needs cohort-wide lexical-order migration.
 * Camera/map/frame getter pointer contracts also remain an integration issue;
 * the separate func_0014a270 signed return repair is now in production.
 * Signed grid strides use multiplication, not undefined negative shifts.
 * Reload the default resource after the field queries, compare modes with 1,
 * retain the unsigned key and stop at the first matching list node.
 * The earlier raw-pointer spelling passed 13,440 native32 cases. This
 * revision has compiler/disassembly evidence, not a new native smoke claim.
 */
#pragma push
/* measured: hoisting on and common-subexpression elimination off give 72 words. */
#pragma opt_loop_invariants on
#pragma opt_common_subs off
extern s32 func_0016abc0(s32 collisionWorld, f32* point, f32 fraction, f32* normal,
                         f32* vector);

typedef struct FldSelectionResource
{
    u32 flags;
    u32 unknown04;
    s32 fallback;
    u32 unknown0c;
    u32 unknown10;
    s32 preferred;
} FldSelectionResource;
typedef struct FldSelectionNode
{
    u16 id;
    u8 unknown002[0x136];
    struct FldSelectionNode* next;
    u8 unknown13c[0x64];
    FldSelectionResource* resource;
} FldSelectionNode;

s32 func_0016b080(f32* point, f32 fraction, f32* normal, f32* vector)
{
    s32 result;
    s32 collisionWorld;
    s32 fieldX;
    s32 fieldZ;
    u16 key;

    u8* object;
    result = 0;
    object = *(u8**)(iGpffff9db0 + 0x28);
    if (object == NULL)
        goto finished;
    if ((*(u32*)object & 1) == 0)
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
                    collisionWorld = selected->preferred;
                    if (collisionWorld == 0)
                        collisionWorld = selected->fallback;
                    break;
                }
            }
            result = func_0016abc0(collisionWorld, point, fraction, normal, vector);
        }
        else
        {
            FldSelectionResource* selected = *(FldSelectionResource**)(iGpffff9db0 + 0x28);
            s32 fallbackWorld = selected->preferred;
            if (fallbackWorld == 0)
                fallbackWorld = selected->fallback;
            result = func_0016abc0(fallbackWorld, point, fraction, normal, vector);
        }
    }
finished:
    return result;
}
#pragma pop
