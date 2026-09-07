/* Source unit: src/mt_scene/mt_scene_00145260.c (1 function markers) */
#include "include_asm.h"
#include "type.h"

extern u8* PTR_DAT_00762ea0;
extern s32 func_00147530(s32 resourceManager, u64 resourceId);
extern void func_00146a10(s32 resource, u64 position, u64 angles, u64 flags);

extern u32 D_00764580;
extern u32 D_00764584;
extern u32 D_00764588;
extern u32 D_0076458C;
extern void func_004b1590();



// FUN_00145260
u32 func_00145260(void)
{
    return *(u32*)(PTR_DAT_00762ea0 + 8);
}



// FUN_00146E60
void func_00146e60(u64 resourceId, u64 position, u64 angles)
{
    s32 resource;

    if (*(s32*)(PTR_DAT_00762ea0 + 8) == 0)
    {
        resource = 0;
    }
    else
    {
        resource = func_00147530(*(s32*)(PTR_DAT_00762ea0 + 8), resourceId);
    }

    if (resource != 0)
    {
        (func_00146a10)(resource, position, angles, 0);
    }
}



// FUN_00146EE0
void func_00146ee0(u64 resourceId, u64 angles)
{
    s32 resource;

    if (*(s32*)(PTR_DAT_00762ea0 + 8) == 0)
    {
        resource = 0;
    }
    else
    {
        resource = func_00147530(*(s32*)(PTR_DAT_00762ea0 + 8), resourceId);
    }

    if (resource != 0)
    {
        (func_00146a10)(resource, 0, 0, angles);
    }
}


/* measured: removing this pragma takes func_0026d400 nd 0 -> nd 17 (object 60 -> 56, window 64). */
#pragma optimization_level 1

// FUN_0026D400
u32 func_0026d400(float* param_1)
{
    if (*(u16*)&D_00764580 == 0)
    {
        return 0;
    }

    param_1[0] = *(float*)(uintptr_t)0x00881500;
    param_1[1] = *(float*)(uintptr_t)0x00881504;
    return 1;
}
#pragma optimization_level 2



/* measured: b210 -O2, 824 executable bytes / 832B window; all 28
   relocations resolve exactly, including the 0.01f literal and 0.6f pair.
   Expiry disables first; the following disabled update clears the outputs. */
// FUN_0026D440
void func_0026d440(void)
{
    extern u32 func_003b7060(void);
    extern f32 fabsf(f32);
    extern f32 D_00881500[4];
    extern s32 D_00881504[], D_00881508[], D_0088150C[];
    f32 delta[2];
    f32 initial[2] = {0.6f, 0.6f};
    s32 i;
    f32 *output;
    f32 step;
    s32 timing;

    if (*(u16 *)&D_00764580 == 0) {
        D_00881500[0] = 0.0f;
        D_00881504[0] = 0;
        D_00881508[0] = 0;
        D_0088150C[0] = 0;
        return;
    }
    if (*(s16 *)&D_00764584 == 0) {
        *(u16 *)&D_00764580 = 0;
        return;
    }
    delta[0] = 0.01f * (f32)(u32)*(u16 *)&D_00764588;
    delta[1] = 0.01f * (f32)(u32)*(u16 *)&D_0076458C;
    for (i = 0; i < 2; i++) {
        f32 d = delta[i];
        if (d != 0.0f) {
            f32 random = (f32)func_003b7060() / 2147483648.0f;
            f32 amplitude = delta[i];
            step = 0.5f * amplitude + 0.5f * (amplitude * random);
            output = D_00881500 + i;
            if (!(fabsf(*output) < delta[i] * initial[i])) {
                if (*output <= 0.0f) *output += step;
                else *output -= step;
            } else {
                *output = 0.0f + *output + 2.0f * (step * ((f32)func_003b7060() / 2147483648.0f - 0.5f));
            }
            if (*output < -d) *output = -d;
            if (!(*output <= d)) *output = d;
        }
    }
    timing = *(s16 *)&D_00764584;
    if (timing > 0) {
        s32 divisor = timing + 5;
        s32 value = *(u16 *)&D_00764588;
        *(u16 *)&D_00764588 = value - (u16)((s32)value / divisor);
        value = *(u16 *)&D_0076458C;
        *(u16 *)&D_0076458C = value - (u16)((s32)value / divisor);
    }
    if (timing > 0) *(s16 *)&D_00764584 = *(s16 *)&D_00764584 - 1;
}

// FUN_0026D780
void func_0026d780(s32 first, s32 second)
{
    if (second == 0)
    {
        *(u16*)&D_00764580 = 0;
    }
    else
    {
        *(u16*)&D_00764580 = 1;
        if (first == 0)
        {
            *(s16*)&D_00764584 = -1;
        }
        else
        {
            *(u16*)&D_00764584 = (s16)first;
        }
        *(u16*)&D_0076458C = second * 10;
        *(u16*)&D_00764588 = (*(u16*)&D_0076458C << 2) / 10;
        func_004b1590(first, (s16)second);
    }
}
