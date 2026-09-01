/* object=468B window=480B normalized_diff=9; differing offsets=0x094 (addiu vs daddiu init), 0x0D8-0x0DF (func_003971d0 argument materialization order); classification=near-match after explicit preheader loop, u16 body index, switch case shape, and 16-byte stack aggregate; ruled out: no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump, or ee-gcc sd $sN prologue; corrected block-scope declarations for func_003bff30, func_00474df0, func_00477900/00476e10/00477510/00477660, func_00462ae0, func_003971d0 return, func_00479940, func_0047da30, and fGpffff80cc; best body retained only in this archive and source restored to bare INCLUDE_ASM. */
void func_00477ca0(u8* arg0)
{
    extern void func_003bff30(void*, void*, void*);
    extern u8* func_00477900(void*);
    extern void* func_00474df0(u8*, void*);
    extern u8* func_00476e10(void*);
    extern u8* func_00477510(void*);
    extern u8* func_00477660(void*, void*);
    extern s32 func_00462ae0(void*);
    extern u8* func_003971d0();
    extern void func_00479940(void*, s32, s32, s32, s32);
    extern void func_0047da30(u32*);
    extern f32 fGpffff80cc;
    f32 values[3];
    s32* temp_4;
    s32 var_17;
    u16 temp_3;
    u32 temp_4_2;
    u8* temp_16;

    func_003bff30(*(void**)(arg0 + 0xDC), (void*)func_00477900, (void*)0);
    if (*(s32*)(arg0 + 0x254) != 0) {
        func_00474df0(arg0 + 0x23C, *(void**)(arg0 + 0xDC));
    }
    if (func_00479ca0(arg0, 0) != 0) {
        func_00473710(arg0 + 0xEC, *(void**)(arg0 + 0xDC), 1);
        func_00479940(arg0, 0, 0, 0, 1);
        var_17 = (u64)1;
        goto loop_7_check;
loop_7_body:
        temp_16 = arg0 + ((u16)var_17 * 0xA4);
        if (*(s32*)(temp_16 + 0x120) != 0) {
            *(u16*)(temp_16 + 0xEC) = *(u16*)(temp_16 + 0xEC) | 2;
            temp_4 = *(s32**)(arg0 + 0x10C);
            *(s32*)(temp_16 + 0x10C) = (s32)func_003971d0((u8*)temp_4, 0, *temp_4, -1);
        }
        var_17 = (var_17 + 1) & 0xFFFF;
loop_7_check:
        if ((var_17 & 0xFFFF) < 2) {
            goto loop_7_body;
        }
    }
    *(s32*)(arg0 + 0xE0) = func_00462ae0(*(void**)(arg0 + 0xDC));
    func_003bff30(*(void**)(arg0 + 0xDC), (void*)func_00476e10, (void*)0);
    temp_3 = *(u16*)(arg0 + 0xD4);
    switch (temp_3) {
    case 1:
    case 2:
        values[0] = fGpffff80cc;
        values[2] = 1.0f;
        values[1] = fGpffff809c;
        func_003bff30(*(void**)(arg0 + 0xDC), (void*)func_00477660, values);
        break;
    default:
        func_003bff30(*(void**)(arg0 + 0xDC), (void*)func_00477510, (void*)0);
        break;
    }
    temp_4_2 = *(u32*)(arg0 + 0x2CC);
    if (temp_4_2 != 0) {
        func_0047da30((u32*)temp_4_2);
    }
}
