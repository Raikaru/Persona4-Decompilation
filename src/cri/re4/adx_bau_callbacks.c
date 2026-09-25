/* ADX bank-input callback registration and dispatch. */
extern unsigned int DAT_00714c20[];
extern unsigned int DAT_00714c24[];

// FUN_004C3120
unsigned int func_004c3120(void)
{
    return 0;
}

// FUN_004C3128
unsigned int func_004c3128(unsigned int first, unsigned int second)
{
    DAT_00714c20[0] = first;
    DAT_00714c24[0] = second;
    return 0;
}

// FUN_004C3140
unsigned int func_004c3140(unsigned int value)
{
    void (*callback)(unsigned int, unsigned int) =
        (void (*)(unsigned int, unsigned int))DAT_00714c20[0];
    if (callback != 0)
        callback(DAT_00714c24[0], value);
    return 0;
}
