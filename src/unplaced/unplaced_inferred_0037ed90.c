/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0037ed90-0037ed90 */

#include "include_asm.h"
#include "type.h"
extern s32 btlShuffleDrawTableLookup(s32 arg0, s32 arg1);
extern void btlShuffleDrawSetRotate(u8 *arg0, s32 arg1, f32 *arg2);
extern s32 btlShuffleCalcUpdateSpeed(u8 *arg0, u8 *arg1);
extern f32 RwV2dLength(f32 *arg0);
#pragma push
#pragma opt_propagation on
// FUN_0037ED90
s32 btlShuffleSeqFindNearestCard(u8 *arg0, s32 arg1) {
    f32 work[4];
    f32 screen[2];
    f32 delta[2];
    f32 target_x;
    f32 best_dist;
    f32 target_y;
    f32 dist;
    s32 count;
    s32 i;
    s32 best;

    target_x = (f32)((arg1 / 3 - 1) * 0x6B) + 314.0f;
    target_y = (f32)(arg1 % 3 - 1) * 120.0f + 236.0f;
    count = btlShuffleDrawTableLookup(*(s32 *)(arg0 + 0x1F304),
                          *(s32 *)(arg0 + 0x1F2FC));
    btlShuffleDrawSetRotate(arg0, 0, work);
    btlShuffleCalcUpdateSpeed((u8 *)work, (u8 *)screen);
    delta[0] = screen[0] - target_x;
    delta[1] = screen[1] - target_y;
    best_dist = RwV2dLength(delta);
    i = 1;
    best = 0;
    while (i < count) {
        btlShuffleDrawSetRotate(arg0, i, work);
        btlShuffleCalcUpdateSpeed((u8 *)work, (u8 *)screen);
        delta[0] = screen[0] - target_x;
        delta[1] = screen[1] - target_y;
        dist = RwV2dLength(delta);
        if (dist < best_dist) {
            best = i;
            best_dist = dist;
        }
        i++;
    }
    return best;
}
#pragma pop
