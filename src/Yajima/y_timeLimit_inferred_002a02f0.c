#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
#include "name_entry_internal.h"
#include "kwln_task_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u16 *D_00764658;

extern u8 D_0063E918[];

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];

extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern f32 fGpffff8204;
extern u32 yTimeTrackAppendKey(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern void yTimeLimitDrawButton(u8 *arg0, s32 arg1);
extern u8 D_007485D0[];
extern s32 iGpffffb530;

extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;




struct RwMatrixTag;
extern void sflDataDrawQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s32 centerX, s16 centerY,
                          const struct RwMatrixTag *matrix, void *queue);
extern f32 fGpffff855c;
extern u8 D_0063EDF0[];
extern u8 D_0063EDF8[];
extern u8 D_0063EE00[];
extern u8 D_0063EE08[];
extern u8 D_0063EE10[];
extern u8 D_0063EE18[];
extern u8 D_0063EE20[];
extern u8 D_0063EE28[];
extern u8 D_0063EE30[];
extern u8 D_0063EE38[];
extern u8 D_00882F28[];
extern u8 D_00882F2C[];
typedef signed __int128 s128;
extern s32 (*D_0063E8C0[])(u8 *, s32);
extern s128 D_0063E8D0;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 *iGpffffb540;
extern u8 iGpffffa7e8;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002a; members 002a02f0-002a02f0 */

// FUN_002A02F0
/* Reset six selection statuses when requested, then draw the five populated name-entry slots. */
void yTimeNameDrawSelections(u8 *task, s32 preserveStatus) {
    NameEntryWork *work;
    s32 i;

    work = (NameEntryWork *)((KwlnTask *)task)->work;
    if ((preserveStatus == 0) && (work->inputState != 1)) {
        for (i = 0; i < 6; i++) {
            /* MATCH requires the byte-domain row address; the typed selectionStatus[i][0] access changed codegen. */
            *(s16 *)((u8 *)work + (i * 4) + 0x1C38) = 0;
        }
    }
    yTimeLimitDrawButton(task, 0);
    yTimeLimitDrawButton(task, 1);
    yTimeLimitDrawButton(task, 2);
    yTimeLimitDrawButton(task, 4);
    yTimeLimitDrawButton(task, 5);
}

