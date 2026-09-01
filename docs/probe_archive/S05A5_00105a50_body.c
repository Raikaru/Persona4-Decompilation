// Best measured body for func_00105a50.
// object/window: 576B/576B
// normalized_diff: 34 words
// differing offsets: 116,120,124,128,140,144,148,152,156,160,164,168,172,176,180,184,196,200,328,336,340,352,356,360,364,368,372,376,380,384,388,408,412,416
// ruled-out: separate s32 i/j plus index locals (140 words); u8 i/j in while form (size 616B); function-scope PersonaWork pointer (size 608B); explicit rawArg local (size 608B); fused single-counter loops (46 words); Ghidra goto loops with s32 j only (101 words); signed i (107 words); s32 i (106 words).
s32 func_00105a50(s16 arg0)
{
    extern s32 func_00109430();
    extern PersonaWork *func_0010a900(u16 pcId);
    extern void func_0046d730(const char *file, s32 line);
    s32 value;
    s32 value3;
    u8 i;
    u8 index;
    s32 j;
    u8 index2;
    if (arg0 == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value = func_00109430(persona);
    }
    index = 0;
    i = 0;
    j = 0;
    goto first_test;
first_body:
    if (value < D_005DD6E0[j & 0xFF]) {
        index = i;
        goto first_done;
    }
    i = (i + 1) & 0xFF;
    j = (j + 1) & 0xFF;
first_test:
    if ((j & 0xFF) < 0x63)
        goto first_body;
    index = 0x63;
first_done:
    if ((index & 0xFF) == 0x63)
        return 0;
    if (arg0 == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value = func_00109430(persona);
    }
    index2 = 0;
    i = 0;
    j = 0;
    goto second_test;
second_body:
    if (value < D_005DD6E0[j & 0xFF]) {
        index2 = i;
        goto second_done;
    }
    i = (i + 1) & 0xFF;
    j = (j + 1) & 0xFF;
second_test:
    if ((j & 0xFF) < 0x63)
        goto second_body;
    index2 = 0x63;
second_done:
    value3 = D_005DD6DC[((index2 & 0xFF) + 1) & 0xFF];
    if (arg0 == 1)
        value = D_00797400[0];
    else {
        PersonaWork *persona = func_0010a900((u16)arg0);
        if (persona == 0)
            func_0046d730((const char *)D_005E4298, 0x1B8);
        value = func_00109430(persona);
    }
    return value3 - value;
}
