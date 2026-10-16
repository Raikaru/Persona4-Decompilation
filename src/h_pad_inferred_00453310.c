/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/h_pad.c; members 00453310-004534f0 */

#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "rw_types_internal.h"
extern s16 iGpffffba1c;
extern s16 iGpffffba20;
extern s16 iGpffffba24;
extern s16 iGpffffba28;
extern s16 iGpffffba2c;
extern s16 iGpffffba30;
extern s16 iGpffffba34;
extern void sdkPadStepSequence(void);
extern void sdkPadRepeatButtonDispatch(s32 arg0, u16 arg1, s32 arg2);
extern u8 D_008C0314[];
extern u8 D_008C0316[];
extern u8 D_008C031A[];
extern s16 D_008C030C[];
extern s16 D_008C030E[];
extern u8 D_008C031E[];
#pragma push
#pragma optimization_level 2
// Same body as sdkPadRepeatButton (sdkTask_inferred.c), run on the dispatch-stage held/edge words (D_008C0314..D_008C031E) instead of the cook-stage words.
// FUN_00453310
void sdkPadRepeatButtonDispatch(s32 arg0, u16 arg1, s32 arg2) {
    s32 off;
    s32 bits;
    u16 *word;
    u8 *timer;

    off = arg0 * 0x4A;
    bits = arg1 & 0xFFFF;
    if (bits & *(u16 *)(D_008C0316 + off)) {
        *(u8 *)(D_008C031E + off + arg2) = 7;
        return;
    }
    if (bits & *(u16 *)(D_008C0314 + off)) {
        timer = D_008C031E + off;
        timer = timer + arg2;
        *timer -= 1;
        if (*timer == 0) {
            word = (u16 *)(D_008C031A + off);
            *word |= arg1;
            *timer = 3;
        }
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// FUN_004533D0
void sdkPadStepSequence(void)
{
    s16 remaining;
    s16 phase;
    s16 pending;

    phase = iGpffffba1c;
    switch (phase) {
    case 0:
        iGpffffba34 = 0;
        iGpffffba2c = 0;
        iGpffffba20 = 0;
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        iGpffffba1c = (s16)(phase + 1);
        return;
    case 1:
        D_008C030C[0] = 0;
        D_008C030E[0] = 0;
        return;
    case 2:
        if (iGpffffba34 == 0) {
            iGpffffba1c = 1;
            return;
        }
        remaining = iGpffffba30;
        if (remaining == 0) {
            if (iGpffffba24 == 0) {
                pending = iGpffffba20;
                D_008C030C[0] = pending & 1;
                D_008C030E[0] = pending & 0xFF;
                iGpffffba30 = iGpffffba2c;
                iGpffffba24 = 1;
            } else {
                D_008C030C[0] = 0;
                D_008C030E[0] = 0;
                iGpffffba30 = iGpffffba28;
                iGpffffba24 = 0;
            }
        } else {
            iGpffffba30 = (s16)(remaining - 1);
        }
        iGpffffba34 -= 1;
        return;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// FUN_004534F0
void sdkPadStartSequence(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    if (sdkPadSequenceEnabled() == 0) {
        return;
    }
    iGpffffba34 = arg0;
    iGpffffba30 = 0;
    iGpffffba2c = arg2;
    iGpffffba28 = arg3;
    iGpffffba20 = arg1;
    iGpffffba1c = 2;
    iGpffffba24 = 0;
}
#pragma pop
