/* BEST HONEST BODY archive for func_0017ea10.
 * Object 808B; retail window 816B; normalized_diff 4.
 * Best candidate residual: retail's projection-copy words are
 * ld v0,0x50(sp); lwc1 f0,0x58(sp); sd v0,0x70(sp); swc1 f0,0x78(sp),
 * while default-propagation mixed field assignment emits ld; sd; lwc1; swc1.
 * The two omitted tail nops account for the remaining size words.
 * Applied aggregate-copy rule 6: aggregate assignment emits ld/ld/sd/sd
 * (nd6); named s64/f32 scalar staging and typed field stores reaches nd4.
 * Tried declaration/order/comma staging, pointer staging, COPY_SCALAR_PAIR,
 * helper-local/scoped/full opt_propagation probes, and compound literal;
 * full-function propagation-off changed unrelated load/control flow (nd121),
 * tight in-function pragma did not affect scheduling, and packed attributes
 * are rejected by MWCCPS2. Reverted after no nd0 closure. */

s32 func_0017ea10(u8 *arg0)
{
    FldAIVec3 d;
    FldAIProj out;
    f32 ab[6];
    f32 temp_f20;
    s32 var_17;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_2;
    u8 *temp_2_2;

    var_17 = 0;
    temp_16 = iGpffffb2c8 + (*(u8 *)(arg0 + 0x1CA) * 0x180) +
              (*(u16 *)(arg0 + 0x1C8) << 6);
    if (iGpffffb25c == 1) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0x1CB) == 0) {
        temp_18 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
        if (func_0014c4c0(temp_18 + 0x30,
                          func_0047a2f0(D_007EFA00[0]) + 0x30,
                          *(f32 *)(temp_16 + 0x14) / 3.0f) == 1) {
            var_17 = 1;
        }
        return var_17;
    }
    temp_2 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
    *(FldAIVec3 *)ab = *(FldAIVec3 *)(temp_2 + 0x30);
    temp_2_2 = func_0047a2f0(D_007EFA00[0]);
    *(FldAIVec3 *)(ab + 3) = *(FldAIVec3 *)(temp_2_2 + 0x30);
    ab[1] += 90.0f;
    ab[4] += 90.0f;
    if (func_0016b8a0(ab, &out) == 1) {
        return 0;
    }
    temp_2 = (u8 *)ab;
    temp_2_2 = (u8 *)&out;
    out.xy = *(s64 *)&ab[0];
    out.z = ab[2];
    *(FldAIVec3 *)ab = *(FldAIVec3 *)(ab + 3);
    *(FldAIVec3 *)(ab + 3) = *(FldAIVec3 *)&out;
    if (func_0016b8a0(temp_2, temp_2_2) == 1) {
        return 0;
    }
    temp_17 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
    if (func_0014bff0(temp_17, func_0047a2f0(D_007EFA00[0]) + 0x30,
                      *(f32 *)(temp_16 + 0xC)) == 1) {
        temp_f20 = *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0x50)) + 0x30);
        d.x = *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x30) - temp_f20;
        temp_f20 = *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0x50)) + 0x34);
        d.y = *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x34) - temp_f20;
        temp_f20 = *(f32 *)(func_0047a2f0(*(u8 **)(arg0 + 0x50)) + 0x38);
        d.z = *(f32 *)(func_0047a2f0(D_007EFA00[0]) + 0x38) - temp_f20;
        if (func_003e4180((f32 *)&d) < *(f32 *)(temp_16 + 0x10)) {
            return 1;
        }
    }
    temp_17 = func_0047a2f0(*(u8 **)(arg0 + 0x50));
    if (func_0014c4c0(temp_17 + 0x30,
                      func_0047a2f0(D_007EFA00[0]) + 0x30,
                      *(f32 *)(temp_16 + 0x14)) == 1) {
        return 1;
    }
    return 0;
}
