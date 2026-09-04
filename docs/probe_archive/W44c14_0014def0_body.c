/*
 * W44c14 probe archive: func_0014def0 (0x0014def0)
 * object: 940B; retail window: 944B; best nd: 203 (reloc-masked)
 * differing offsets: 0x74/0x78 (global load spelling), 0x1F8-0x37C
 *   (loop index/base and conversion temporary register colouring), and
 *   0x390-0x3A4 (tail alignment/register cascade).
 * levers tried: interleaved EE/FPU parameter declaration order; grouped and
 *   address-of/volatile/cast global-pointer spellings; recipe-A s32/u32
 *   conversion copy; s16 and s32 loop counters; loop-local declaration
 *   permutations; direct stores; scoped opt_propagation probe; float-local
 *   declaration order. The archived body is the best compiled no-macro
 *   candidate without temporary pragmas.
 */
void func_0014def0(s32 arg0, u8 *arg1,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, u8 *arg2, s32 arg3,
                   f32 fparg5, f32 fparg6, f32 fparg7, s32 arg4,
                   f32 arg_sp0)
{
    extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
    volatile f32 *global;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 var_f3;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    s32 var_5;
    s32 v;
    u32 c;
    u8 *temp_4;
    u8 *temp_2_5;
 
 
 

    global = &D_008872F8[0];
    var_f3 = *(f32 *)((u8 *)global + 0) - fparg2;
    if (fparg2 == 0.0f) {
        var_f3 = *(f32 *)((u8 *)global + 0) - *(f32 *)(func_00457120() + 0x80);
    }
    temp_f2 = 1.0f / var_f3;
    switch (arg4) {
    case 0:
        *(f32 *)(arg1 + 0) = fparg0;
        *(f32 *)(arg1 + 4) = fparg1;
        *(f32 *)(arg1 + 8) = var_f3;
        temp_f1 = fparg0 + fparg3;
        *(f32 *)(arg1 + 0x40) = temp_f1;
        *(f32 *)(arg1 + 0x44) = fparg1;
        *(f32 *)(arg1 + 0x48) = var_f3;
        *(f32 *)(arg1 + 0x80) = fparg0;
        temp_f0 = fparg1 + fparg4;
        *(f32 *)(arg1 + 0x84) = temp_f0;
        *(f32 *)(arg1 + 0x88) = var_f3;
        *(f32 *)(arg1 + 0xC0) = temp_f1;
        *(f32 *)(arg1 + 0xC4) = temp_f0;
        *(f32 *)(arg1 + 0xC8) = var_f3;
        break;
    case 1:
        *(f32 *)(arg1 + 0x40) = fparg0;
        *(f32 *)(arg1 + 0x44) = fparg1;
        *(f32 *)(arg1 + 0x48) = var_f3;
        temp_f1_2 = fparg0 + fparg3;
        *(f32 *)(arg1 + 0xC0) = temp_f1_2;
        *(f32 *)(arg1 + 0xC4) = fparg1;
        *(f32 *)(arg1 + 0xC8) = var_f3;
        *(f32 *)(arg1 + 0) = fparg0;
        temp_f0_2 = fparg1 + fparg4;
        *(f32 *)(arg1 + 4) = temp_f0_2;
        *(f32 *)(arg1 + 8) = var_f3;
        *(f32 *)(arg1 + 0x80) = temp_f1_2;
        *(f32 *)(arg1 + 0x84) = temp_f0_2;
        *(f32 *)(arg1 + 0x88) = var_f3;
        break;
    case 2:
        *(f32 *)(arg1 + 0xC0) = fparg0;
        *(f32 *)(arg1 + 0xC4) = fparg1;
        *(f32 *)(arg1 + 0xC8) = var_f3;
        temp_f1_3 = fparg0 + fparg3;
        *(f32 *)(arg1 + 0x80) = temp_f1_3;
        *(f32 *)(arg1 + 0x84) = fparg1;
        *(f32 *)(arg1 + 0x88) = var_f3;
        *(f32 *)(arg1 + 0x40) = fparg0;
        temp_f0_3 = fparg1 + fparg4;
        *(f32 *)(arg1 + 0x44) = temp_f0_3;
        *(f32 *)(arg1 + 0x48) = var_f3;
        *(f32 *)(arg1 + 0) = temp_f1_3;
        *(f32 *)(arg1 + 4) = temp_f0_3;
        *(f32 *)(arg1 + 8) = var_f3;
        break;
    case 3:
        *(f32 *)(arg1 + 0x80) = fparg0;
        *(f32 *)(arg1 + 0x84) = fparg1;
        *(f32 *)(arg1 + 0x88) = var_f3;
        temp_f1_4 = fparg0 + fparg3;
        *(f32 *)(arg1 + 0) = temp_f1_4;
        *(f32 *)(arg1 + 4) = fparg1;
        *(f32 *)(arg1 + 8) = var_f3;
        *(f32 *)(arg1 + 0xC0) = fparg0;
        temp_f0_4 = fparg1 + fparg4;
        *(f32 *)(arg1 + 0xC4) = temp_f0_4;
        *(f32 *)(arg1 + 0xC8) = var_f3;
        *(f32 *)(arg1 + 0x40) = temp_f1_4;
        *(f32 *)(arg1 + 0x44) = temp_f0_4;
        *(f32 *)(arg1 + 0x48) = var_f3;
        break;
    }
    *(f32 *)(arg1 + 0x18) = temp_f2;
    *(f32 *)(arg1 + 0x58) = temp_f2;
    *(f32 *)(arg1 + 0x98) = temp_f2;
    *(f32 *)(arg1 + 0xD8) = temp_f2;
    var_5 = 0;
    goto loop_test;
loop_body:
    temp_4 = arg1 + (var_5 << 6);
    v = *(u8 *)(arg2 + 0);
    if (v >= 0) {
        var_f0 = (f32)v;
    } else {
        c = v;
        c = (c >> 1) | (c & 1);
        var_f0 = (f32)(s32)c;
        var_f0 += var_f0;
    }
    *(f32 *)(temp_4 + 0x20) = var_f0;
    v = *(u8 *)(arg2 + 1);
    if (v >= 0) {
        var_f0 = (f32)v;
    } else {
        c = v;
        c = (c >> 1) | (c & 1);
        var_f0 = (f32)(s32)c;
        var_f0 += var_f0;
    }
    *(f32 *)(temp_4 + 0x24) = var_f0;
    v = *(u8 *)(arg2 + 2);
    if (v >= 0) {
        var_f0 = (f32)v;
    } else {
        c = v;
        c = (c >> 1) | (c & 1);
        var_f0 = (f32)(s32)c;
        var_f0 += var_f0;
    }
    *(f32 *)(temp_4 + 0x28) = var_f0;
    v = *(u8 *)(arg2 + 3);
    if (v >= 0) {
        var_f0 = (f32)v;
    } else {
        c = v;
        c = (c >> 1) | (c & 1);
        var_f0 = (f32)(s32)c;
        var_f0 += var_f0;
    }
    *(f32 *)(temp_4 + 0x2C) = var_f0;
    var_5++;
loop_test:
    if (var_5 < 4) {
        goto loop_body;
    }
    *(s32 *)(arg1 + 0x100) = arg3;
    *(f32 *)(arg1 + 0x104) = temp_f2;
    *(f32 *)(arg1 + 0x108) = fparg5;
    *(f32 *)(arg1 + 0x10C) = fparg6;
    *(f32 *)(arg1 + 0x110) = fparg7;
    *(f32 *)(arg1 + 0x114) = arg_sp0;
    *(s32 *)(arg1 + 0x118) = arg4;
    temp_2_5 = func_00461390((void *)arg0, 4, arg1, 4);
    *(void **)(temp_2_5 + 8) = (void *)func_0014dd80;
    *(u8 **)(temp_2_5 + 0x10) = arg1;
}
