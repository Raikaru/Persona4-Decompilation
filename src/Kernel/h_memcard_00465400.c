#include "type.h"

extern s32 func_00464670(s32* mode, u32* result, s32* error);
extern s32 func_00431cb8(s32 socket, s32* status);
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
            func_00431cb8(D_00764BA4, D_008E4B20);
        }
    }
    else
    {
        status = func_00464670(&cardMode, (u32*)&cardCode, &cardError);
        if (status == 1)
        {
            func_00431cb8(D_00764BA4, D_008E4B20);
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
