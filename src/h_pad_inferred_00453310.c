
#include "include_asm.h"
#include "type.h"
#include "sdk_pad_record.h"
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
extern void sdkPadRepeatButtonDispatch(s32 padIndex, u16 buttonMask, s32 timerIndex);
extern u8 D_008C0314[];
extern u8 D_008C0316[];
extern u8 D_008C031A[];
extern s16 D_008C030C[];
extern s16 D_008C030E[];
extern u8 D_008C031E[];
#pragma push
#pragma optimization_level 2
// Same body as sdkPadRepeatButton, run on the dispatch-stage held/edge words
// (D_008C0314..D_008C031E) instead of the cook-stage words. measured: retail addresses the held,
// pressed, repeat and timer words (D_008C0314/+2/+6/+0xA) as raw bytes, so typed record fields
// change how the addresses are built.
// FUN_00453310
void sdkPadRepeatButtonDispatch(s32 padIndex, u16 buttonMask, s32 timerIndex) {
    s32 recordOffset;
    s32 maskedButtons;
    u16 *repeatWord;
    u8 *repeatTimer;

    recordOffset = padIndex * 0x4A;
    maskedButtons = buttonMask & 0xFFFF;
    if (maskedButtons & ((u16 *)( D_008C0316 + recordOffset ))[0]) {
        D_008C031E[recordOffset + timerIndex] = 7;
        return;
    }
    if (maskedButtons & ((u16 *)( D_008C0314 + recordOffset ))[0]) {
        repeatTimer = D_008C031E + recordOffset;
        repeatTimer = repeatTimer + timerIndex;
        *repeatTimer -= 1;
        if (*repeatTimer == 0) {
            repeatWord = (u16 *)(D_008C031A + recordOffset);
            *repeatWord |= buttonMask;
            *repeatTimer = 3;
        }
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Alternate generated button pulses and idle intervals until the duration expires. */
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
/* Start a generated button sequence with independent on/off intervals. */
// FUN_004534F0
void sdkPadStartSequence(s16 duration, s16 buttons, s16 onFrames, s16 offFrames) {
    if (sdkPadSequenceEnabled() == 0) {
        return;
    }
    iGpffffba34 = duration;
    iGpffffba30 = 0;
    iGpffffba2c = onFrames;
    iGpffffba28 = offFrames;
    iGpffffba20 = buttons;
    iGpffffba1c = 2;
    iGpffffba24 = 0;
}
#pragma pop
