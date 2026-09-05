/* IDA-backed field selection; production remains ASM.
 * docs/ida_headstart/src/Kosaka/Field/k_fldFrame.c:976-1027, corrected against
 * retail assembly and canonical helpers. MWCCPS2 b210: object 460B/window
 * 480B, 93 differing words; ABI-corrected old body gives 428B/480B, 97 words.
 * Remaining differences include guard/branch folding and argument setup.
 * The second input is an output-normal pointer, not an s64 value, and the
 * task getter has no arguments. Reload the default object after the field
 * queries; compare their results with 1, not general truth. Preserve the
 * unsigned 16-bit list key and first-match preferred/fallback selection.
 * Multiplication avoids signed-negative-shift UB for valid negative cells.
 * A 32-bit native smoke passes 13,440 cases: guards, short-circuit queries,
 * changed global context, unsigned keys, duplicate precedence, float grid
 * boundaries, pointer identities, fraction bits, return values and outputs.
 */
#pragma push
#pragma opt_loop_invariants on
extern s32 func_0016abc0(s32 collisionWorld, f32* point, f32* normal,
                         f32* vector, f32 fraction);

s32 func_0016b080(f32* point, f32* normal, f32* vector, f32 fraction)
{
    s32 result;
    s32 collisionWorld;
    s32 fieldX;
    s32 fieldZ;
    u16 key;

    result = 0;
    if (*(u8**)(iGpffff9db0 + 0x28) != NULL &&
        (*(u32*)*(u8**)(iGpffff9db0 + 0x28) & 1) == 0)
    {
        collisionWorld = 0;
        if (func_0014a200() == 1 || func_0014a270() == 1)
        {
            u8* map;
            u8* node;
            map = func_003e9700(*(s32*)(func_00457120() + 4));
            fieldX = (s32)((*(f32*)(map + 0x30) + 600.0f) / 1200.0f);
            fieldZ = (s32)((*(f32*)(map + 0x38) + 600.0f) / 1200.0f);
            key = *(u16*)((u8*)func_00155280() + (fieldZ * 256) +
                         (fieldX * 16) + 0x56);
            for (node = func_001452b0(12); node != NULL;
                 node = *(u8**)(node + 0x138))
            {
                if (*(u16*)node == key)
                {
                    u8* selected = *(u8**)(node + 0x1a0);
                    collisionWorld = *(s32*)(selected + 0x14);
                    if (collisionWorld == 0)
                        collisionWorld = *(s32*)(selected + 8);
                    break;
                }
            }
            return func_0016abc0(collisionWorld, point, normal, vector, fraction);
        }
        else
        {
            u8* selected = *(u8**)(iGpffff9db0 + 0x28);
            s32 fallbackWorld = *(s32*)(selected + 0x14);
            if (fallbackWorld == 0)
                fallbackWorld = *(s32*)(selected + 8);
            return func_0016abc0(fallbackWorld, point, normal, vector, fraction);
        }
    }
    return result;
}
#pragma pop
