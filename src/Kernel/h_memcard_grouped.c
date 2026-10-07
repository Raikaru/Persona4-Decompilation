/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
void func_004647a0(void);
void func_004647b0(void);
void func_004653f0(void);

/* Source unit: src/Kernel/h_memcard_004647a0.c (1 function markers) */

extern s32 D_00764BC0;

// FUN_004647A0
void func_004647a0(void)
{
    D_00764BC0 = 9;
}

/* Source unit: src/Kernel/h_memcard_004647b0.c (1 function markers) */

extern s32 D_00764BC0;

// FUN_004647B0
void func_004647b0(void)
{
    D_00764BC0 = 4;
}

/* Source unit: src/Kernel/h_memcard_004653f0.c (1 function markers) */

extern s32 D_00764B9C;

extern s32 D_00764BBC;
extern s32 D_00764BB8;
extern void *D_00764BAC;
extern s32 D_00764BB4;
extern s32 D_00764BA4;
extern s32 func_00464670(s32 *command, s32 *result, s32 *error);
extern s32 sceMc2GetInfoAsync(s32 socket, s32 *status);
extern void sprintf(void *dst, const void *fmt, ...);
extern s32 func_00431d78(s32 socket, const char *name, void *result);
extern void func_00440b68(const void *fmt, ...);
extern s32 func_00431b58(s32 socket);
extern s32 func_00432288(s32 socket, const char *name, const void *data, u32 offset, u32 size);
extern s32 func_004323a8(s32 socket, const char *name);
extern s32 func_004326b8(s32 socket, void *data);
extern void memcpy(void *dst, void *src, s32 size);
extern void memset(void *dst, s32 value, s32 size);
extern void strcpy(void *dst, const void *src);
extern void strcat(void *dst, void *src);
extern s32 func_00455f70(s32 arg0, s32 *arg1);
extern char D_007127B0[];
extern char D_007127D0[];
extern char D_00712800[];
extern char D_00712820[];
extern char D_00712840[];
extern char D_00712860[];
extern char D_00712880[];
extern char D_00712890[];
extern char D_007126A0[];
extern char D_007126E0[];
extern char D_00712710[];
extern char D_00712740[];
extern char *D_00712760[];
extern char *D_00712764[];
extern char *D_00712768[];
extern char *D_00712770[];
extern char D_007640F8[8];
extern s32 D_008E4B20[];
extern s32 D_008E4B24[];
extern char D_008E4A20[];
extern char D_008E4900[];
extern char D_008E4410[];
extern s16 D_008E4416[];
extern s32 D_008E441C[];
extern char D_008E4420[];
extern char D_008E4460[];
extern char D_008E4490[];
extern char D_008E44C0[];
extern char D_008E44D0[];
extern char D_008E4514[];
extern char D_008E4554[];
extern char D_008E4594[];
/* Memory-card operation states retain retail's poll/response dispatch.
 * The write API consumes unsigned 32-bit byte offsets and lengths.
 * Retail does not check whether the loaded icon archive contains icon.ico:
 * after func_00455f70 it passes the returned pointer and reads `out` from
 * 0x10($sp) at 0x0046514C even when the lookup did not write it. This body
 * keeps that uninitialised read, as retail does.
 * See docs/probe_archive/Memcard_004647c0_recovery_20260929.md. */
// FUN_004647C0
s32 func_004647c0(void)
{
    s32 cardMode;
    s32 cardCode;
    s32 cardError;
    s32 out;
    void *data;

    func_00440b68(D_007127B0, D_00764BC0);
    switch (D_00764BC0)
    {
    case 0:
        cardMode = 0;
        cardCode = 0;
        if (func_00464670(&cardMode, &cardCode, &cardError) == -1)
        {
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            D_00764BC0 = 1;
        }
        goto done;
    case 1:
        if (func_00464670(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError == 0)
            {
                switch (cardCode)
                {
                case 0x9003:
                    return -3;
                case 0x6F:
                    return -5;
                case 0x13:
                    return -5;
                case 0x9001:
                    return -4;
                case 0x2F:
                    D_00764BC0 = 3;
                    return 2;
                default:
                    break;
                }
            }
            if (D_008E4B20[0] != 2)
            {
                return -1;
            }
            if (D_008E4B24[0] == 0)
            {
                D_00764BC0 = 3;
                return 2;
            }
            sprintf(D_008E4A20, D_007127D0, D_00764BB8, D_00764BB8);
            func_00431d78(D_00764BA4, D_008E4A20, D_008E4900);
            D_00764BC0 = 2;
        }
        goto done;
    case 3:
        switch (func_00464670(&cardMode, &cardCode, &cardError))
        {
        case 1:
            if ((cardError == 0) && (cardCode != 0x2F))
            {
                switch (cardCode)
                {
                case 0x9003:
                    return -3;
                case 0x6F:
                    return -3;
                case 0x16:
                    return -3;
                case 0x13:
                    return -3;
                case 0x9002:
                    return -4;
                default:
                    break;
                }

            }
            break;
        case -1:
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            break;
        default:
            break;
        }
        return 2;
    case 4:
        switch (func_00464670(&cardMode, &cardCode, &cardError))
        {
        case 1:
            /* Retail tests the result twice here, not cardError. */
            if ((cardCode == 0) && (cardCode != 0x2F))
            {
                switch (cardCode)
                {
                case 0x9003:
                case 0x6F:
                case 0x13:
                    return -3;
                case 0x9001:
                    return -4;
                default:
                    break;
                }
            }
            break;
        case -1:
            func_00431b58(D_00764BA4);
            D_00764BC0 = 5;
            break;
        default:
            break;
        }
        goto done;
    case 5:
        switch (func_00464670(&cardMode, &cardCode, &cardError))
        {
        case 1:
            if (cardError != 0)
            {
                D_00764BC0 = 6;
                return 4;
            }
            return -3;
            break;
        case -1:
            D_00764BC0 = 6;
            break;
        default:
            break;
        }
        goto done;
    case 2:
        if (func_00464670(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError == 0)
            {
                switch (cardCode)
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
                    D_00764BC0 = 6;
                    goto done;
                case 0x9002:
                    return -4;
                default:
                    break;
                }
            }
            else
            {
                D_00764BC0 = 8;
                return 1;
            }
        }
        goto done;
    case 8:
        switch (func_00464670(&cardMode, &cardCode, &cardError))
        {
        case 1:
            if ((cardError == 0))
            {
                switch (cardCode)
                {
                case 0x9003:
                    return -3;
                case 0x6F:
                    return -3;
                case 0x13:
                    return -3;
                case 0x9001:
                    return -4;
                case 0x2F:
                    return -3;
                default:
                    break;
                }

            }
            break;
        case -1:
            sceMc2GetInfoAsync(D_00764BA4, D_008E4B20);
            break;
        default:
            break;
        }
        return 1;
    case 9:
        switch (func_00464670(&cardMode, &cardCode, &cardError))
        {
        case 1:
            if (cardError != 0)
            {
                D_00764BC0 = 6;
            }
            else
            {
                switch (cardCode)
                {
                case 0x9003:
                    return -3;
                case 0x6F:
                    return -3;
                case 0x13:
                    return -3;
                case 0x9001:
                    return -4;
                case 0x2F:
                    return -3;
                default:
                    break;
                }
            }
            break;
        case -1:
            D_00764BC0 = 6;
            break;
        default:
            break;
        }
        goto done;
    case 6:
        sprintf(D_008E4A20, D_00712800, D_00764BB8);
        func_00440b68(D_00712820, func_004326b8(D_00764BA4, D_008E4A20));
        D_00764BC0 = 7;
        return 5;
    case 7:
        if (func_00464670(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError != 0)
            {
                D_00764BC0 = 10;
            }
            else
            {
                switch (cardCode)
                {
                case 0x11:
                    D_00764BC0 = 10;
                    goto done;
                case 0x1C:
                    return -6;
                case 0x9002:
                    return -4;
                default:
                    return -3;
                }
            }
        }
        goto done;
    case 10:
        switch (D_00764BBC)
        {
        case 0:
            sprintf(D_008E4A20, D_007127D0, D_00764BB8, D_00764BB8);
            break;
        case 1:
            sprintf(D_008E4A20, D_00712840, D_00764BB8);
            break;
        case 2:
            sprintf(D_008E4A20, D_00712860, D_00764BB8);
            break;
        default:
            break;
        }
        func_004323a8(D_00764BA4, D_008E4A20);
        D_00764BC0 = 11;
        goto done;
    case 11:
        if (func_00464670(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError != 0)
            {
                D_00764BC0 = 12;
            }
            else
            {
                switch (cardCode)
                {
                case 0x11:
                    D_00764BC0 = 12;
                    goto done;
                case 0x1C:
                    return -6;
                case 0x9002:
                    return -4;
                default:
                    return -3;
                }
            }
        }
        goto done;
    case 12:
        switch (D_00764BBC)
        {
        case 0:
            sprintf(D_008E4A20, D_007127D0, D_00764BB8, D_00764BB8);
            func_00432288(D_00764BA4, D_008E4A20, D_00764BAC, 0, D_00764BB4);
            break;
        case 1:
            sprintf(D_008E4A20, D_00712840, D_00764BB8);
            data = (void *)func_00455f70((s32)D_00712880, &out);
            func_00432288(D_00764BA4, D_008E4A20, data, 0, out);
            break;
        case 2:
            sprintf(D_008E4A20, D_00712860, D_00764BB8);
            memset(D_008E4410, 0, 0x3C4);
            strcpy(D_008E4410, D_007640F8);
            if ((u32)D_00764BB8 < 0x10U)
            {
                strcpy(D_008E44D0, D_00712890);
                strcat(D_008E44D0, D_00712770[D_00764BB8]);
            }
            D_008E4416[0] = 0x12;
            D_008E441C[0] = 0x60;
            memcpy(D_008E4420, D_007126A0, 0x40);
            memcpy(D_008E4460, D_007126E0, 0x30);
            memcpy(D_008E4490, D_00712710, 0x30);
            memcpy(D_008E44C0, D_00712740, 0x10);
            strcpy(D_008E4514, D_00712760[0]);
            strcpy(D_008E4554, D_00712764[0]);
            strcpy(D_008E4594, D_00712768[0]);
            func_00432288(D_00764BA4, D_008E4A20, D_008E4410, 0, 0x3C4);
            break;
        default:
            break;
        }
        D_00764BC0 = 13;
        goto done;
    case 13:
        if (func_00464670(&cardMode, &cardCode, &cardError) == 1)
        {
            if (cardError != 0)
            {
                if (D_00764BBC == 2)
                {
                    return 100;
                }
                D_00764BBC++;
                D_00764BC0 = 10;
            }
            else
            {
                switch (cardCode)
                {
                case 0x11:
                    D_00764BC0 = 12;
                    goto done;
                case 0x1C:
                    return -6;
                case 0x9002:
                    return -4;
                default:
                    return -3;
                }
            }
        }
        goto done;
    default:
        goto done;
    }
done:
    return 0;
}

// FUN_004653F0
void func_004653f0(void)
{
    D_00764B9C = 1;
}
