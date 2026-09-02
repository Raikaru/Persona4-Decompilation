void func_0026d440(void)
{
    extern s32 func_003b7060(void);
    extern f32 fabsf(f32);
    extern f32 D_007639E0;
    extern f32 D_007639E4;
    extern f32 D_00761514;
    f32 delta[2];
    f32 initial[2];
    s32 i;
    f32 *output;
    f32 step;
    s32 randomValue;

    initial[0] = D_007639E0;
    initial[1] = D_007639E4;

    if (*(u16 *)&D_00764580 == 0)
    {
        *(f32 *)(uintptr_t)0x00881500 = 0.0f;
        *(s32 *)(uintptr_t)0x00881504 = 0;
        *(s32 *)(uintptr_t)0x00881508 = 0;
        *(s32 *)(uintptr_t)0x0088150C = 0;
        return;
    }

    if (*(s16 *)&D_00764584 == 0)
    {
        *(u16 *)&D_00764580 = 0;
        return;
    }

    {
        u16 value0 = *(u16 *)&D_00764588;
        f32 r;

        if ((s16)value0 < 0)
        {
            r = (f32)(s32)(((u32)value0 >> 1) | (value0 & 1));
            r += r;
        }
        else
        {
            r = (f32)(s32)value0;
        }
        delta[0] = D_00761514 * r;
    }

    {
        u16 value1 = *(u16 *)&D_0076458C;
        f32 r;

        if ((s16)value1 < 0)
        {
            r = (f32)(s32)(((u32)value1 >> 1) | (value1 & 1));
            r += r;
        }
        else
        {
            r = (f32)(s32)value1;
        }
        delta[1] = D_00761514 * r;
    }

    for (i = 0; i < 2; i++)
    {
        f32 d = delta[i];

        if (d == 0.0f)
        {
            continue;
        }

        randomValue = func_003b7060();
        {
            f32 r;

            if (randomValue < 0)
            {
                r = (f32)(s32)(((u32)randomValue >> 1) | (randomValue & 1));
                r += r;
            }
            else
            {
                r = (f32)(s32)randomValue;
            }
            step = (0.5f * (d * (r / 2147483648.0f))) + (0.5f * d);
        }

        output = (f32 *)(uintptr_t)0x00881500 + i;

        if (fabsf(*output) >= d * initial[i])
        {
            if (*output <= 0.0f)
            {
                *output += step;
            }
            else
            {
                *output -= step;
            }
        }
        else
        {
            randomValue = func_003b7060();
            {
                f32 r;

                if (randomValue < 0)
                {
                    r = (f32)(s32)(((u32)randomValue >> 1) | (randomValue & 1));
                    r += r;
                }
                else
                {
                    r = (f32)(s32)randomValue;
                }
                *output = *output + (2.0f * step * ((r / 2147483648.0f) - 0.5f));
            }
        }

        if (*output < -d)
        {
            *output = -d;
        }
        if (*output > d)
        {
            *output = d;
        }
    }

    if (*(s16 *)&D_00764584 > 0)
    {
        s32 divisor = (s32)(*(s16 *)&D_00764584) + 5;
        u16 value0 = *(u16 *)&D_00764588;
        *(u16 *)&D_00764588 =
            (u16)(value0 - (((s32)value0 / divisor) & 0xFFFF));
        value0 = *(u16 *)&D_0076458C;
        *(u16 *)&D_0076458C =
            (u16)(value0 - (((s32)value0 / divisor) & 0xFFFF));
    }

    if (*(s16 *)&D_00764584 > 0)
    {
        *(s16 *)&D_00764584 = *(s16 *)&D_00764584 - 1;
    }
}
