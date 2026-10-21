#include "include_asm.h"
#include "type.h"
#include "itf_mes_objects.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];

extern void itfMesListSetColor();
extern void itfMesListSetRangeFlag();


extern s32 D_008815B0[];


extern u16 D_008817E8[];
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern u8 iGpffffa738;
extern s8 D_0063BAB0[];

/* Sets the given flag on list entries whose key falls in the run from firstLine to lastLine. */
// FUN_0027A400
void itfMesListSetRangeFlag(run, firstLine, lastLine, value)
u8 *run;
s32 firstLine;
s32 lastLine;
s32 value;
{
    u8 *currentRun;
    u8 *glyph;
    s32 count;
    s32 key;
    s32 temp;

    currentRun = run;
    count = (lastLine - firstLine) - 1;
    key = ((FrFontTextRun *)currentRun)->y;
    goto outer_check;
outer_continue:
    currentRun = *(u8 **)&((FrFontTextRun *)currentRun)->previous;
    if (currentRun == NULL)
        goto done;
outer_body:
    temp = ((FrFontTextRun *)currentRun)->y;
    if (key != temp)
    {
        count -= 1;
        key = temp;
        goto outer_check;
    }
    goto outer_continue;
outer_check:
    if (count > 0)
        goto outer_body;
process:
    glyph = *(u8 **)&((FrFontTextRun *)currentRun)->firstGlyph;
    goto list_check;
list_body:
    *(s32 *)&((FrFontGlyphData *)glyph)->color = value;
    glyph = *(u8 **)&((FrFontGlyphData *)glyph)->next;
list_check:
    if (glyph != NULL)
        goto list_body;
    currentRun = *(u8 **)&((FrFontTextRun *)currentRun)->previous;
    if (currentRun == NULL)
        goto done;
    temp = ((FrFontTextRun *)currentRun)->y;
    if (key == temp)
        goto process;
done:
    return;
}

// Forwards to itfMesListSetColor; entry used by the window procedure.
// FUN_0027A490
void itfMesListSetColorEntry(void)
{
    itfMesListSetColor();
}

// Forwards to itfMesListSetRangeFlag; entry used by the window procedure.
// FUN_0027A4B0
void itfMesListSetRangeFlagEntry(void)
{
    itfMesListSetRangeFlag();
}

