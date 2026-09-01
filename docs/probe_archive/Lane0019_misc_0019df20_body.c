/* Attempted candidate for func_0019df20 (src/promoted/code1_0019.c).
 * Best clean-C form reaches object 520B/window 528B, normalized_diff 0 ONLY
 * with a `*(volatile f32 *)&angleN` read-back forcing angle1/angle2 to
 * actually spill to the stack before the func_0047a8a0 call (retail loads
 * them from stack via lwc1 rather than keeping the FPU-resident constant).
 * `volatile` on non-hardware data is banned by decomp_lint H001. Tried as
 * substitutes: #pragma opt_propagation off (nd 282), opt_lifetimes off
 * (nd 289), opt_scalarizeliveranges off (nd 289), peephole off (breaks
 * unrelated later functions in the file, nd 336 for this one too) -- none
 * reproduce the stack round-trip without the banned volatile idiom. Left
 * as bare INCLUDE_ASM. A legitimate lever (address-taken forcing, a real
 * struct wrapping both angles, or a different pragma) may exist but was not
 * found in this session's budget.
 */
s32 func_0019df20(u8 *arg0)
{
    u8 *unit;

    if ((*(u16 *)(arg0 + 0x10) & 1) != 0) {
        f32 angle1;
        f32 angle2;
        f32 call_angle1;
        f32 call_angle2;
        s32 enabled;

        unit = *(u8 **)(iGpffffb3ac + 0x17C);
        while (unit != NULL) {
            if ((*(s32 *)(unit + 0x9C) & 8) != 0) {
                if (&angle1 != NULL) {
                    angle1 = 70.0f;
                }
                if (&angle2 != NULL) {
                    angle2 =
                        (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) ==
                         unit) ? 70.0f : 60.0f;
                }
                call_angle2 = *(volatile f32 *)&angle2;
                call_angle1 = *(volatile f32 *)&angle1;
                enabled = *(s32 *)(unit + 0x98) & 2;
                if (enabled != 0) {
                    func_0047a8a0(*(u8 **)(unit + 0xA00),
                                   call_angle1, call_angle2);
                }
                if ((*(s32 *)(unit + 0x98) & 2) != 0) {
                    func_0047a890(*(u8 **)(unit + 0xA00), 0.25f);
                }
                *(s16 *)(unit + 0xB0) = 1;
                *(P4_95730_Vec3 *)(unit + 0xB8) =
                    *(P4_95730_Vec3 *)(arg0 + 4);
                func_0019d7a0(unit, 3);
            }
            unit = *(u8 **)(unit + 0xA68);
        }
    } else {
        f32 angle1;
        f32 angle2;
        f32 call_angle1;
        f32 call_angle2;
        s32 enabled;

        unit = *(u8 **)arg0;
        if (&angle1 != NULL) {
            angle1 = 70.0f;
        }
        if (&angle2 != NULL) {
            angle2 =
                (*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30) == unit) ?
                70.0f : 60.0f;
        }
        call_angle2 = *(volatile f32 *)&angle2;
        call_angle1 = *(volatile f32 *)&angle1;
        enabled = *(s32 *)(unit + 0x98) & 2;
        if (enabled != 0) {
            func_0047a8a0(*(u8 **)(unit + 0xA00),
                           call_angle1, call_angle2);
        }
        if ((*(s32 *)(unit + 0x98) & 2) != 0) {
            func_0047a890(*(u8 **)(unit + 0xA00), 0.25f);
        }
        *(s16 *)(unit + 0xB0) = 1;
        *(P4_95730_Vec3 *)(unit + 0xB8) =
            *(P4_95730_Vec3 *)(arg0 + 4);
        func_0019d7a0(unit, 3);
    }
    return 1;
}
