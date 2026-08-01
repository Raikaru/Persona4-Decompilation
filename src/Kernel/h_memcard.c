/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00465400)
/* Source unit: src/Kernel/h_memcard_00465400.c (1 function markers) */
#include "type.h"

extern s32 func_00464670(s32* mode, u32* result, s32* error);
extern s32 sceMc2GetInfoAsync(s32 socket, s32* status);
extern s32 D_00764B9C;
extern s32 D_00764BA4;
extern s32 D_008E4B20[];
extern s32 D_008E4B24[];

// FUN_00465400
s32 func_00465400(void)
{
    s32 status;
    s32 cardMode;
    s32 cardCode;
    s32 cardError;

    if (D_00764B9C != 0)
    {
        status = func_00464670(&cardMode, (u32*)&cardCode, &cardError);
        if (status == -1)
        {
            D_00764B9C = 0;
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
        }
    }
    else
    {
        status = func_00464670(&cardMode, (u32*)&cardCode, &cardError);
        if (status == 1)
        {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            if (cardError == 0)
            {
                switch (cardCode)
                {
                    case 0x9003:
                        goto card_error_9003;
                    case 0x6f:
                        goto card_error_6f;
                    case 0x13:
                        goto card_error_13;
                    case 0x9001:
                        goto card_error_9001;
                    case 0x2f:
                        goto card_error_2f;
                    default:
                        goto card_state;
                }
            }
            goto card_state;
        }
    }
    goto card_done;

card_error_9003:
    return 3;
card_error_6f:
    return -5;
card_error_13:
    return -5;
card_error_9001:
    return -4;
card_error_2f:
    return -2;

card_state:
    if (D_008E4B20[0] != 2)
    {
        return -1;
    }
    if (D_008E4B24[0] == 0)
    {
        return -2;
    }
    goto card_done;

card_done:
    return 0;
}
#endif /* P4_UNIT_00465400 */

#if defined(P4_UNIT_00465F20)
/* Source unit: src/Kernel/h_memcard_00465f20.c (1 function markers) */
#include "type.h"

extern s32 D_00764BC0; /* sMemcardSeqMode */
extern s32 D_00764BBC; /* sMemcardMode */
extern s32 D_00764BB8; /* sMemcardFile */

// FUN_00465F20
void func_00465F20(void)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = 0;
}
#endif /* P4_UNIT_00465F20 */

#if defined(P4_UNIT_00466260)
/* Source unit: src/Kernel/h_memcard_00466260.c (1 function markers) */
#include "type.h"

extern s32 D_00764BC0; /* sMemcardSeqMode */
extern s32 D_00764BBC; /* sMemcardMode */
extern s32 D_00764BB8; /* sMemcardFile */

// FUN_00466260
void func_00466260(s32 slot)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = slot;
}
#endif /* P4_UNIT_00466260 */

#if defined(P4_UNIT_00464650)
/* Source unit: src/Kernel/h_memcard_00464650.c (1 function markers) */
#include "type.h"

extern s32 D_00764BBC; /* sMemcardMode */
extern s32 D_00764BA0; /* sMemcardAsync */
extern s32 D_00764BB8; /* sMemcardFile */
extern void* D_00764BAC; /* sMemcardBuffer */
extern s32 D_00764BB4; /* sMemcardBufferSize */
extern s32 D_00764BC0; /* sMemcardSeqMode */

// FUN_00464650
void func_00464650(s32 file, void* buffer, s32 size)
{
    D_00764BBC = 0;
    D_00764BA0 = 0;
    D_00764BB8 = file;
    D_00764BAC = buffer;
    D_00764BB4 = size;
    D_00764BC0 = 0;
}
#endif /* P4_UNIT_00464650 */

#if defined(P4_UNIT_00465570)
/* Source unit: src/Kernel/h_memcard_00465570.c (1 function markers) */
#include "type.h"

extern s32 D_00764BBC; /* sMemcardMode */
extern s32 D_00764BA0; /* sMemcardAsync */
extern s32 D_00764BB8; /* sMemcardFile */
extern void* D_00764BAC; /* sMemcardBuffer */
extern s32 D_00764BB0; /* sMemcardBufferSize */
extern s32 D_00764BC0; /* sMemcardSeqMode */

// FUN_00465570
void func_00465570(s32 file, void* buffer, s32 size)
{
    D_00764BBC = 0;
    D_00764BA0 = 0;
    D_00764BB8 = file;
    D_00764BAC = buffer;
    D_00764BB0 = size;
    D_00764BC0 = 0;
}
#endif /* P4_UNIT_00465570 */
