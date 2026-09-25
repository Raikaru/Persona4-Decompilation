/* ADX stream decoder callback registration and dispatch. */
extern unsigned int DAT_00721d6c[];
extern unsigned int DAT_00721d70[];

// FUN_004CF068
unsigned int func_004cf068(void)
{
    return 0;
}

// FUN_004CF070
unsigned int func_004cf070(unsigned int first, unsigned int second)
{
    DAT_00721d6c[0] = first;
    DAT_00721d70[0] = second;
    return 0;
}

// FUN_004CF088
unsigned int func_004cf088(unsigned int value)
{
    void (*callback)(unsigned int, unsigned int) =
        (void (*)(unsigned int, unsigned int))DAT_00721d6c[0];
    if (callback != 0)
        callback(DAT_00721d70[0], value);
    return 0;
}
