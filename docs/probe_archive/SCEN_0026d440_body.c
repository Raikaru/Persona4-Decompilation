/* object 1164B, window 832B, normalized_diff 276; exact fndiff differing offsets (reloc-masked): 0x0-0x30, 0x38, 0x40-0x150, 0x158-0x164, 0x16C-0x178, 0x180-0x1DC, 0x1E4-0x1EC, 0x1F4-0x1FC, 0x204-0x20C, 0x214-0x234, 0x23C-0x2B8, 0x2C4-0x310, 0x318-0x330, 0x338, 0x340-0x488; corrected declarations: block-scope func_003b7060(void) return s32, iGpffffb6f0[] float base, D_00761514 f32; levers ruled out by automatic oversized stop: further declaration/prologue tuning, loop-shape and aggregate-copy probes were not attempted because this reconstruction exceeds the retail window. */
void func_0026d440(void)
{
    extern s32 func_003b7060(void);
    extern f32 iGpffffb6f0[];
    extern f32 D_00761514;
    f32 initial0;
    f32 initial1;
    f32 delta0;
    f32 delta1;
    f32 current;
    f32 randomFloat;
    f32 step;
    f32 *output;
    s32 randomValue;
    s32 i;
    s16 timer;
    u16 value0;
    u16 value1;
    s32 divisor;

    initial0 = iGpffffb6f0[0];
    initial1 = iGpffffb6f0[1];
    if (*(u16 *)&D_00764580 == 0)
    {
        *(f32 *)(uintptr_t)0x00881500 = 0.0f;
        *(s32 *)(uintptr_t)0x00881504 = 0;
        *(s32 *)(uintptr_t)0x00881508 = 0;
        *(s32 *)(uintptr_t)0x0088150C = 0;
        return;
    }

    timer = *(s16 *)&D_00764584;
    if (timer == 0)
    {
        *(u16 *)&D_00764580 = 0;
        return;
    }

    value0 = *(u16 *)&D_00764588;
    if ((s16)value0 < 0)
    {
        randomFloat = (f32)(((u32)value0 >> 1) | (value0 & 1));
        randomFloat += randomFloat;
    }
    else
    {
        randomFloat = (f32)value0;
    }
    delta0 = D_00761514 * randomFloat;

    value1 = *(u16 *)&D_0076458C;
    if ((s16)value1 < 0)
    {
        randomFloat = (f32)(((u32)value1 >> 1) | (value1 & 1));
        randomFloat += randomFloat;
    }
    else
    {
        randomFloat = (f32)value1;
    }
    delta1 = D_00761514 * randomFloat;

    for (i = 0; i < 2; i++)
    {
        f32 delta;
        f32 initial;

        if (i == 0)
        {
            delta = delta0;
            initial = initial0;
        }
        else
        {
            delta = delta1;
            initial = initial1;
        }
        current = delta;
        if (current != 0.0f)
        {
            randomValue = func_003b7060();
            if (randomValue < 0)
            {
                randomFloat = (f32)(((u32)randomValue >> 1) | (randomValue & 1));
                randomFloat += randomFloat;
            }
            else
            {
                randomFloat = (f32)randomValue;
            }
            randomFloat /= 2147483648.0f;
            step = (0.5f * (current * randomFloat)) + (0.5f * current);
            output = (f32 *)(uintptr_t)0x00881500 + i;
            current = *output;
            if (!(fabsf(current) < (delta * initial)))
            {
                if (current <= 0.0f)
                {
                    *output = current + step;
                }
                else
                {
                    *output = current - step;
                }
            }
            else
            {
                randomValue = func_003b7060();
                if (randomValue < 0)
                {
                    randomFloat = (f32)(((u32)randomValue >> 1) | (randomValue & 1));
                    randomFloat += randomFloat;
                }
                else
                {
                    randomFloat = (f32)randomValue;
                }
                randomFloat /= 2147483648.0f;
                *output = current + (2.0f * step * (randomFloat - 0.5f));
            }
            if (*output < -delta)
            {
                *output = -delta;
            }
            if (!(*output <= delta))
            {
                *output = delta;
            }
        }
    }

    timer = *(s16 *)&D_00764584;
    if (timer > 0)
    {
        divisor = timer + 5;
        value0 = *(u16 *)&D_00764588;
        *(u16 *)&D_00764588 =
            (u16)(value0 - (((s32)value0 / divisor) & 0xFFFF));
        value1 = *(u16 *)&D_0076458C;
        *(u16 *)&D_0076458C =
            (u16)(value1 - (((s32)value1 / divisor) & 0xFFFF));
    }
    if (timer > 0)
    {
        *(s16 *)&D_00764584 = timer - 1;
    }
}
