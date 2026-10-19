#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

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
extern s32 shdSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 * arg4, s32 arg5);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern f32 fGpffff8204;
extern u32 yTimeTrackAppendKey(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
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





/* Existing task-work layout. The tween fields are defined by 002a27c0;
 * 0029fbb0 uses the selection pairs, status halfwords and flash flags.
 * State preceding the background tween is outside this renderer's view. */





#pragma push

#pragma pop
extern s32 yTimeNameRevealRows(u8 *arg0);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002a; members 002a2e10-002a2e10 */

extern s32 yTimeLimitDraw(u8 *arg0);
/* measured: closes opt_propagation around func_002a1c80. */
/* measured: closes opt_common_subs around func_002a1c80. */
/* measured: closes no_branch_likely around func_002a1c80. */
/* measured: opt_loop_invariants on hoists the case-zero store constant into the
   preheader, matching retail's li $v1 before the loop-entry branch. */
/* measured: closes opt_loop_invariants around func_002a1fa0. */
// FUN_002A2E10
/* Draw one indexed glyph, using sprite 10 for an empty character. */
void yTimeDrawIndexedGlyph(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s8 * glyphs, s32 index, s32 unused, u8 * sprites) {
    s32 value;

    value = glyphs[index];
    if (value == 0) {
        value = 10;
    }
    shdSpriteDrawNow(x, y, depth, color, alpha, value, 0, sprites, 1);
}

