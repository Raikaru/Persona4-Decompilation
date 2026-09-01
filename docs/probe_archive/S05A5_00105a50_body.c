s32 func_00105a50(s16 arg0)
{
    extern s32 func_00109430(void *arg0);
    extern PersonaWork *func_0010a900(u16 pcId);
    extern void func_0046d730(const char *file, s32 line);
    s32 value1;
    s32 value2;
    s32 value3;
    s32 i;
    s32 j;
    s32 index;
    s32 index2;

    if (arg0 == 1)
        value1 = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value1 = func_00109430(persona);
    }
    i = 0;
    j = 0;
    while ((j & 0xFF) < 0x63) {
        if (value1 < D_005DD6E0[j & 0xFF]) {
            index = i & 0xFF;
            break;
        }
        i = (i + 1) & 0xFF;
        j = (j + 1) & 0xFF;
    }
    if ((j & 0xFF) >= 0x63)
        index = 0x63;
    if ((index & 0xFF) == 0x63)
        return 0;
    if (arg0 == 1)
        value2 = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value2 = func_00109430(persona);
    }
    i = 0;
    j = 0;
    while ((j & 0xFF) < 0x63) {
        if (value2 < D_005DD6E0[j & 0xFF]) {
            index2 = i & 0xFF;
            break;
        }
        i = (i + 1) & 0xFF;
        j = (j + 1) & 0xFF;
    }
    if ((j & 0xFF) >= 0x63)
        index2 = 0x63;
    value3 = D_005DD6DC[((index2 & 0xFF) + 1) & 0xFF];
    if (arg0 == 1)
        value1 = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value1 = func_00109430(persona);
    }
    return value3 - value1;
}
