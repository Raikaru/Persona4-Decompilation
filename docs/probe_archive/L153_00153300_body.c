/* func_00153300: object 416B / retail window 416B / normalized_diff 4 / differing offsets 0x2C, 0x34. Best retained aggregate-cast body with corrected file-scope callee declarations and scoped legacy call prototypes. Retail emits `ld D_005EFE38`, then `lwc1 D_005EFE40`; aggregate copy still emits a second `ld D_005EFE38+8` and `sd`, so this remains a 2-word addressing/memory-width residual. Tried one at a time: array globals with indexed scalar reads (nd8); array-typed aggregate global copied whole (`D005EFE38Pair D_005EFE38[]; sp = D_005EFE38[0]`, nd4 same residual); separate adjacent s64 halves (`D_005EFE38[]`/`D_005EFE40[]`, nd8); packed aggregate array copy (nd4 same residual); aggregate copy followed by explicit D_005EFE40 overwrite (obj428, nd272); staged scalar load temporaries (nd8); const array declarations (nd4 same residual); typed s64/f32 stores through the existing destination pointer (obj416, nd5, first-load register/store residual); scalar D_005EFE40 declaration (obj412, GP-relative load); added split locals shifted the destination stack offset (obj404/416, nd10); byte-array destination grew to obj428. Previously ruled out: plain field assignments, declaration initializers, compound literals, two-stage load temps, pointer stores/types, reversed/packed/typed fields, scalar globals, memcpy, inline typed initializers, optimization pragmas, and permuter probes. Rechecks: direct scalar members in retail order remained obj416/fndiff 4; staged scalar temps with current declarations produced obj412/fndiff 91 (historical staged best fndiff 4); local `typedef signed __int128 s128` produced obj404/fndiff 82; using the float member first in the destination pointer and `#pragma opt_propagation off` both left aggregate fndiff 2. Ghidra types the source as undefined8 plus undefined4, and IDA as qword_5EFE38 plus flt_5EFE40; neither indicates a 128-bit value. No source body retained; bare INCLUDE_ASM fallback follows. */
// FUN_00153300
void func_00153300(s8 *arg0, f32 fparg0)
{
    extern void func_003e9d50(s32 a0, void *a1, f32 f12, s32 a3);
    extern void func_0047a1a0(void *a0, void *a1, f32 f12, s32 a2);
    void *ptr;
    struct {
        s64 sp40;
        f32 sp48;
    } sp;
    u16 temp_4;
    u32 var_16;
    u32 var_16_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_5;

    ptr = &sp.sp40;
    sp = *(typeof(sp) *)D_005EFE38;
    if (!(*(u32 *)arg0 & 1)) {
        temp_3 = *(u8 **)(arg0 + 8);
        if (temp_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3 + 4), ptr, fparg0, 2);
        }
        temp_3_2 = *(u8 **)(arg0 + 0x10);
        if (temp_3_2 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_2 + 4), &sp.sp40, fparg0, 2);
        }
        temp_3_3 = *(u8 **)(arg0 + 0x14);
        if (temp_3_3 != NULL) {
            func_003e9d50(*(s32 *)(temp_3_3 + 4), &sp.sp40, fparg0, 2);
        }
    }
    var_16 = 0;
    goto loop_test_11;
loop_body_11:
    temp_3_4 = *(u8 **)(arg0 + var_16 * 4 + 0x1C);
    if (temp_3_4 != NULL) {
        func_003e9d50(*(s32 *)(temp_3_4 + 4), &sp.sp40, fparg0, 2);
    }
    var_16 += 1;
loop_test_11:
    if (var_16 < *(u32 *)(arg0 + 0x18)) {
        goto loop_body_11;
    }
    var_16_2 = 0;
    goto loop_test_19;
loop_body_19:
    temp_5 = (u8 *)arg0 + var_16_2 * 0x18;
    temp_4 = *(u16 *)(temp_5 + 0x120);
    if (temp_4 == 0) {
        goto switch_body_a;
    }
    if (temp_4 != 2) {
        goto switch_case_1_test;
    }
switch_body_a:
    func_0047a1a0((void *)(*(s32 *)(temp_5 + 0x12C)), &sp.sp40, fparg0, 2);
    goto switch_end;
switch_case_1_test:
    if (temp_4 != 1) {
        goto switch_end;
    }
    func_004b1290(*(s32 *)(temp_5 + 0x130), 0.0f, fparg0, 0.0f);
switch_end:
    ;
    var_16_2 += 1;
loop_test_19:
    if (var_16_2 < *(u32 *)(arg0 + 0x11C)) {
        goto loop_body_19;
    }
}
