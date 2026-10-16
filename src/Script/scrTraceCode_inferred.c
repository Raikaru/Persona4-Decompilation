/* Source unit: src/promoted/code1_0029.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))
#define va_end(ap) ((void)0)
extern u8 *iGpffffb510;
extern s32 iGpffffa7c8;

s32 mtMiscResourceValue(s32 arg0);


extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
extern char D_0063CB30[];
extern char D_0063D050[];



extern s32 D_0063CB50[];
extern u8 D_0063CFA0[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}
// lint: allow H011 -- measured: u16 prototype regresses func_00291a60 (145 diff, wide id args)
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, f32 farg0, s32 arg5, s32 arg6,
                          s32 arg7);
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 arg0, f32 farg0, f32 farg1, f32 farg2,
                          f32 farg3, s32 arg1, s32 arg2);
extern char D_0063C8F0[];
extern char D_0063C910[];
extern s32 D_0076462C;
extern u8 iGpffffa7e8;

extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];



extern void mtMiscCollectType1Records(u8 *arg0);
/* measured probe: close opt_propagation bracket after func_00291530. */





#pragma push

#pragma pop

/* Source unit: src/promoted/code1_0029.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0029.c; members 0029d010-0029d050 */

// Stores arg0 (a script label address) as the current label of the script context.
// FUN_0029D010
void scrSetCurrentLabel(s32 arg0)
{
    *(s32 *)(iGpffffb510 + 0x18) = arg0;
}

// FUN_0029D020
s32 scrGetCmdTimer(void)
{
    return *(s32 *)(iGpffffb510 + 0x138);
}

// FUN_0029D030
s32 func_0029d030(void)
{
    return *(s32 *)(iGpffffb510 + 0x130);
}

// Returns the script context (the iGpffffb510 block) that the battle and script
// code index into.
// FUN_0029D040
s32 scrGetContext(void)
{
    return (s32)iGpffffb510;
}

// Returns the AI state pointer stored in the script context at +0x154; battle AI
// commands use it as their action record.
// FUN_0029D050
s32 scrGetAiState(void)
{
    return *(s32 *)(iGpffffb510 + 0x154);
}

