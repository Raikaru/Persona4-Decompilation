/* Read-only filesystem state entry points. */
extern unsigned int DAT_00743c34[];
extern unsigned int DAT_00743c38[];

// FUN_004F8A80
unsigned int func_004f8a80(void)
{
    return 0;
}

// FUN_004F8A88
unsigned int func_004f8a88(unsigned int first, unsigned int second)
{
    DAT_00743c34[0] = first;
    DAT_00743c38[0] = second;
    return 0;
}

// FUN_004F8AA0
unsigned int func_004f8aa0(unsigned int value)
{
    void (*callback)(unsigned int, unsigned int) =
        (void (*)(unsigned int, unsigned int))DAT_00743c34[0];
    if (callback != 0)
        callback(DAT_00743c38[0], value);
    return 0;
}
