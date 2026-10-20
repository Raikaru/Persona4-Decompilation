#include "mdl_file_internal.h"
#include "btl_action_internal.h"
#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
extern MdlNameCallback iGpffffbb2c;
extern MdlTypeCallback iGpffffbb30;
extern MdlNameCallback iGpffffbb34;
extern MdlSetupCallback iGpffffbb38;
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];


struct MdlFlags78ec0;


extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;

typedef struct Code47Dispatch {
    void *unused;
    void *(*blend)(u8 *left, f32 left_time, u8 *right, f32 right_time,
                   f32 ratio);
    void *(*sample)(u8 *track, f32 time, u8 *defaults, f32 ratio);
    void (*apply)(void *result, void *target);
} Code47Dispatch;
typedef struct Code47Targets {
    void **items;
    u16 count;
} Code47Targets;
extern Code47Dispatch D_00713220[4];
/* Returns the shared sample scratch buffer D_00922C50. */
// FUN_0047F830
u8 *mdlGetSampleScratch(void)
{
    return D_00922C50;
}

/* measured: retail hoists loop invariants here; the count is a snapshot, while callback and item-
 * array loads are re-read after each callback. */
#pragma push
/* measured: retail hoists loop-invariant loads out of the row loop in mdlDispatchTrackRows. */
#pragma opt_loop_invariants on
/* Runs the four track row kinds against the targets list: a row with data on both sides is blended
 * with the matching right-hand row, otherwise it is sampled, and its apply callback writes the
 * result to every target. measured: retail hoists the loop-invariant row lookups out of the loop,
 * which needs loop-invariant optimization on. */
// FUN_0047F850
void mdlDispatchTrackRows(u8 *leftTrack, f32 leftTime, u8 *rightTrack, f32 rightTime,
                   f32 weight)
{
    u32 count;
    Code47Targets *targets;
    u32 kind;

    targets = (Code47Targets *)((MdlFileTrackSet *)leftTrack)->targets;
    count = targets->count;
    for (kind = 0; kind < 4; kind++) {
        s32 offset;
        u8 *left;
        u8 *right;

        offset = kind * 0x10;
        if (D_00713220[kind].apply == NULL) {
            continue;
        }
        left = leftTrack + offset;
        if ((s32)((MdlFileTrack *)left)->keys == 0) {
            continue;
        }
        right = rightTrack + offset;
        if ((s32)((MdlFileTrack *)right)->keys != 0) {
            void *result;
            u32 target;

            result = D_00713220[kind].blend(left, leftTime, right, rightTime, weight);
            for (target = 0; target < count; target++) {
                D_00713220[kind].apply(result, targets->items[target]);
            }
        } else {
            void *result;
            u32 target;

            result = D_00713220[kind].sample(left, leftTime, leftTrack + 0x40, weight);
            for (target = 0; target < count; target++) {
                D_00713220[kind].apply(result, targets->items[target]);
            }
        }
    }
}
#pragma pop
