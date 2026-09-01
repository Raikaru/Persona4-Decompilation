/* object_size=416 window=416 normalized_diff=2 differing_offsets=0xF4,0xF8; best body after pointer/source-shape probes. */
/* Probed: m2c-prelude expansion/removal; declaration order; local width/signedness; direct/reversed addu operand order; pointer temp and integer-domain address forms; stack-base expressions via sp60/arg0/frame address; offset reassociation/cancellation; split pointer increments; indexed/struct/aggregate buffer forms; pointer type/register/volatile qualifiers; optimization_level 1; opt_common_subs off; opt_propagation off; schedule off; opt_peephole off; live-pointer self-use, duplicate dereference, pointer conditions, pointer-in-store identity, call-live pointer, loop-carried/base pointer, array-pointer indexing, volatile pointer lifetime; direct sp60 base with var_19 then +0x60 (obj 416, 3 differing words); explicit base (-0x60) then var_19 then +0x60 inside condition (obj 416, 3 differing words); pointer update +0x60 before var_19 (obj 420 > window, nd 135); pointer hoist before condition (22 differing words). No live MATCH; retained body remains nd 2 at offsets 0xF4/0xF8. */
void func_00450050(s64 arg0, s32 arg1, ...) {
    va_list args;
    s8 sp60[0x100];
    f32 arg0hi;
    s32 var_19;
    s32 var_18;
    s32 var_17;
    s32 temp_16;
    s8 temp_5;
    u8 *read;

    arg0hi = *(f32 *)((u8 *)&arg0 + 4);
    va_start(args, arg1);
    func_00446ed8(sp60, (void *)arg1, args);
    var_18 = (s32)(*(f32 *)&arg0);
    var_17 = (s32)arg0hi;
    var_19 = 0;
    temp_16 = var_18;
    while (var_19 < 0x100) {
        if ((*(f32 *)&arg0 < 53.0f) && (arg0hi < 40.0f) && (var_18 < 0x35) && (var_17 < 0x28)) {
            read = (u8 *)((u8 *)sp60 - 0x60) + var_19;
            read += 0x60;
            temp_5 = *(s8 *)read;
            if (temp_5 != 0) {
                if (temp_5 == 0xA) {
                    var_18 = temp_16;
                    var_17 += 1;
                } else {
                    if ((var_17 == 0x27) && (var_18 >= 0x35)) {
                        func_00440b68((char *)&iGpffffac30 + 0x10, temp_5);
                    } else {
                        *(u8 *)((u32)D_008BF720 + (u32)(var_17 * 0x35) + (u32)var_18) = temp_5;
                    }
                    var_18 += 1;
                }
                var_19 += 1;
                continue;
            }
        }
        break;
    }
}
