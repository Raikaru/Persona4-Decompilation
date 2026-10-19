/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0037ed90-0037ed90 */

#include "include_asm.h"
#include "type.h"
#include "btl_shuffle_state_internal.h"
extern s32 btlShuffleDrawTableLookup(s32 context, s32 gridIndex);
extern void btlShuffleDrawSetRotate(u8 *context, s32 gridIndex, f32 *pose);
extern s32 btlShuffleCalcUpdateSpeed(u8 *context, u8 *gridIndex);
extern f32 RwV2dLength(f32 *context);
#pragma push
#pragma opt_propagation on
/* Project every card and return the closest to the requested three-by-three grid point. */
// FUN_0037ED90
s32 btlShuffleSeqFindNearestCard(u8 *context, s32 gridIndex) {
    f32 work[4];
    f32 screen[2];
    f32 delta[2];
    f32 targetX;
    f32 bestDistance;
    f32 targetY;
    f32 distance;
    s32 count;
    s32 i;
    s32 best;

    targetX = (f32)((gridIndex / 3 - 1) * 0x6B) + 314.0f;
    targetY = (f32)(gridIndex % 3 - 1) * 120.0f + 236.0f;
    count = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount,
                          ((BtlShuffleContext *)context)->pattern);
    btlShuffleDrawSetRotate(context, 0, work);
    btlShuffleCalcUpdateSpeed((u8 *)work, (u8 *)screen);
    delta[0] = screen[0] - targetX;
    delta[1] = screen[1] - targetY;
    bestDistance = RwV2dLength(delta);
    i = 1;
    best = 0;
    while (i < count) {
        btlShuffleDrawSetRotate(context, i, work);
        btlShuffleCalcUpdateSpeed((u8 *)work, (u8 *)screen);
        delta[0] = screen[0] - targetX;
        delta[1] = screen[1] - targetY;
        distance = RwV2dLength(delta);
        if (distance < bestDistance) {
            best = i;
            bestDistance = distance;
        }
        i++;
    }
    return best;
}
#pragma pop
