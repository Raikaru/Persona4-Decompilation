/* Source unit: src/Kernel/h_memcard_00464650.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

extern s32 D_00764BBC; /* sMemcardMode */
extern s32 D_00764BA0; /* sMemcardAsync */
extern s32 D_00764BB8; /* sMemcardFile */
extern void* D_00764BAC; /* sMemcardBuffer */
extern s32 D_00764BB4; /* sMemcardBufferSize */
extern s32 D_00764BC0; /* sMemcardSeqMode */
extern s32 D_00764BA8;
extern s32 iGpffffbab0;

extern s32 func_00464670(s32* mode, u32* result, s32* error);
extern s32 sceMc2GetInfoAsync(s32 socket, s32* status);
extern s32 D_00764B9C;
extern s32 D_00764BA4;
extern s32 D_008E4B20[];
extern s32 D_008E4B24[];
extern s32 D_00764BB0; /* sMemcardBufferSize */
extern s32 iGpffffbaa8;
extern s32 iGpffffbaa4;
extern char D_00712950[];
extern char D_007127D0[];
extern char D_008E4900[];
extern char D_008E4A20[];
extern s32 D_008E4B28[];
extern void func_00442088(void* dst, const void* fmt, s32 arg2, s32 arg3);
extern void func_00431d78(s32 socket, void* data, void* result);
 



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



// FUN_00465590
INCLUDE_ASM("asm/nonmatchings/h_memcard", func_00465590);
// FUN_004659F0
void func_004659F0(s32 file)
{
    D_00764BC0 = 0;
    D_00764BA8 = file;
    D_00764BA0 = 0;
    D_00764BB8 = 0;
    iGpffffbab0 = 0;
}
// FUN_00465A10
INCLUDE_ASM("asm/nonmatchings/h_memcard", func_00465a10);
// FUN_00465F20
void func_00465F20(void)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = 0;
}
/* measured: plain C reproduces the complete 800-byte state machine except for the final-state result setup order (retail loads iGpffffbaa8 before materializing 100; b210 reverses those two instructions). Object 796B/window 800B, normalized_diff 6. Committed at nd 6. */
// FUN_00465F40 NONMATCHING
#ifdef NON_MATCHING
s32 func_00465f40(void)
{
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 temp_3;
    s32 temp_3_2;
    s32 var_2;
    s32 temp_6;

    func_00440b68(D_00712950, D_00764BC0);
    temp_3 = D_00764BC0;
    switch (temp_3)
    {
    case 0:
        iGpffffbaa8 = -1;
        sp1C = 0;
        sp18 = 0;
        iGpffffbaa4 = 0;
        if (func_00464670(&sp1C, (u32*)&sp18, &sp14) == -1)
        {
            sceMc2GetInfoAsync(D_00764BA4, (s32*)D_008E4B20);
            D_00764BC0 = 1;
        }
default:
        goto block_44;
    case 1:
        if (func_00464670(&sp1C, (u32*)&sp18, &sp14) == 1)
        {
            if (sp14 == 0)
            {
                switch (sp18)
                {
                case 0x6F:
                    return -5;
                case 0x13:
                    return -5;
                case 0x9003:
                    sceMc2GetInfoAsync(D_00764BA4, (s32*)D_008E4B20);
                    goto block_44;
                case 0x2F:
                    return 100;
                default:
                    return -9;
                }
            }
            else
            {
                if (D_008E4B20[0] == 2)
                {
                    if (D_008E4B28[0] >= 0xE6)
                    {
                        return 100;
                    }
                    D_00764BC0 = 2;
                    goto block_44;
                }
                return -1;
            }
        }
        else
        {
            goto block_44;
        }
        break;
    case 2:
        if (func_00464670(&sp1C, (u32*)&sp18, &sp14) == -1)
        {
            temp_6 = D_00764BB8;
            func_00442088(D_008E4A20, D_007127D0, temp_6, temp_6);
            func_00431d78(D_00764BA4, D_008E4A20, D_008E4900);
            D_00764BC0 = 3;
        }
        goto block_44;
    case 3:
        if (func_00464670(&sp1C, (u32*)&sp18, &sp14) == 1)
        {
            if (sp14 == 0)
            {
                switch (sp18)
                {
                case 0x9003:
                    return -5;
                case 0x6F:
                    return -5;
                case 0x16:
                    return -5;
                case 0x13:
                    return -5;
                case 2:
                    temp_3_2 = D_00764BB8 + 1;
                    D_00764BB8 = temp_3_2;
                    if (temp_3_2 == 0x10)
                    {
                        temp_6 = iGpffffbaa8;
                        var_2 = 100;
                        if (temp_6 != 100)
                        {
                            var_2 = -6;
                        }
                        return var_2;
                    }
                    D_00764BC0 = 2;
                    goto block_44;
                default:
                    goto block_44;
                }
            }
            else
            {
                return 100;
            }
        }
        else
        {
            goto block_44;
        }
        break;
    }
block_44:
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/h_memcard", func_00465f40);
#endif



// FUN_00466260
void func_00466260(s32 slot)
{
    D_00764BC0 = 0;
    D_00764BBC = 0;
    D_00764BB8 = slot;
}
