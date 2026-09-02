/* Best candidate archived after HoH458CE0Try34; target remained non-MATCH. */
/* Retail saved registers: $s0, $s1, $s2, $s3, $s4; $s1 = arg0, $s0 = arg1, $s4 = created property, $s3 = current item, $s2 = loop index/address. */
/* Tried: typed helper/global declarations; pointer-backed and array-backed float locals; scalar-address locals; opt_propagation off; opt_common_subs off; O0/O1/O2 probes; condition/literal/goto/struct/union forms. Best measured candidate was 36 differing words (reloc-masked), 516B object versus 544B retail window; opt_common_subs off duplicated clamp constants but disturbed prefix codegen. */

u8 *func_00458ce0(u8 *arg0, f32 *arg1)
{
    f32 values[3];
    s32 temp_2;
    s32 i;
    s32 current;
    u8 *temp_18;

    if (func_00457a90(arg0, D_00711890) == 0) {
        temp_18 = arg0 + 0xC;
        temp_2 = func_003bd000(arg0, func_003bcfa0(arg0, D_00711890, 2, 3));
        func_003bd0f0(temp_2, 0, *(f32 *)temp_18);
        func_003bd0f0(temp_2, 1, *(f32 *)(temp_18 + 4));
        func_003bd0f0(temp_2, 2, *(f32 *)(temp_18 + 8));
    }
    i = 0;
    while (i < func_003bcfb0(arg0)) {
        current = func_003bd000(arg0, i);
        if (func_004426e8(func_003bd040(current), D_00711890) == 0) {
            break;
        }
        i += 1;
    }
    if (current != 0) {
        *(f32 *)&values[0] = func_003bd090(current, 0);
        *(f32 *)&values[1] = func_003bd090(current, 1);
        *(f32 *)&values[2] = func_003bd090(current, 2);
        *(f32 *)&values[0] *= arg1[0];
        *(f32 *)&values[1] *= arg1[1];
        *(f32 *)&values[2] *= arg1[2];
        if (*(f32 *)&values[0] > 1.0f) {
            *(f32 *)&values[0] = 1.0f;
        }
        if (*(f32 *)&values[1] > 1.0f) {
            *(f32 *)&values[1] = 1.0f;
        }
        if (*(f32 *)&values[2] > 1.0f) {
            *(f32 *)&values[2] = 1.0f;
        }
        *(f32 *)(arg0 + 0xC) = *(f32 *)&values[0];
        *(f32 *)(arg0 + 0x10) = *(f32 *)&values[1];
        *(f32 *)(arg0 + 0x14) = *(f32 *)&values[2];
    }
    return arg0;
}
