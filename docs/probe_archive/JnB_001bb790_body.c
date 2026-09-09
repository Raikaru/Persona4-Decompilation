/* Exact current owner recovery: 296B/304B, zero differing bytes after
 * resolving all six relocations; eight zero-tail bytes. Production C.
 * A coefficient pointer plus scoped propagation-off retains the stack
 * address instruction. Loop-invariant extraction hoists positive zero.
 * The RwV3d seed copy preserves three loads before any output store.
 * Y/Z products precede X accumulation, including when output overlaps input.
 * IDA: docs/ida_headstart/src/Battle/btlMain.c:898-936.
 * The former literal-index floor was 296B/nd59. Fresh independent named-zero,
 * typed-sample, seven-float and Y/Z temporary candidates all give 300B/nd133.
 * A const zero or four-component coefficient vector ties 296B/nd59.
 * Loop extraction alone reaches 292B/nd114: only the zero-displacement
 * coefficient-address instruction is missing, shifting later instructions.
 * A natural element pointer with propagation disabled closes that final
 * instruction. The original f32[4] storage suffices; no wrapper, padding,
 * invented arithmetic or register binding is needed.
 * The complete owner now has 23 MATCH / 4 ASM; all 22 earlier matches survive.
 * Fresh native x86-64 Clang UB-trap smoke passes 15,360 cases: four ring
 * indices, twelve parameters, eight data patterns, 38 input/output overlap
 * positions, an external output and exact seed-object aliasing. Every arena,
 * external output and seed byte is checked. -ffp-contract=off models C
 * floating behavior, not EE COP1 execution. The 32-bit libc build was
 * unavailable (gnu/stubs-32.h missing); no fresh 32-bit runtime claim.
 */
extern RwV3d D_00881430;
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
void func_001bb790(u8 *arg0, f32 *arg1, f32 fparg0)
{
    f32 weights[4];
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 temp_f5;
    u16 i;
    s32 index;
    u8 *p;
    f32 *weight;

    f3 = 1.0f - fparg0;
    f1 = f3 * f3;
    weights[0] = f3 * f1;
    f0 = fparg0 * f1;
    f2 = 3.0f;
    weights[1] = f2 * f0;
    f1 = fparg0 * fparg0;
    f0 = f3 * f1;
    weights[2] = f2 * f0;
    weights[3] = fparg0 * f1;
    index = *(u16 *)(arg0 + 0x74);
    *(RwV3d *)arg1 = D_00881430;
    i = 0;
    while (i < 4) {
        weight = &weights[i];
        temp_f5 = *weight;
        p = arg0 + (u16)index * 0x1C;
        f4 = *(f32 *)(p + 8) * temp_f5;
        f3 = *(f32 *)(p + 0xC) * temp_f5;
        arg1[0] = (arg1[0] + 0.0f) + *(f32 *)(p + 4) * temp_f5;
        arg1[1] += f4;
        arg1[2] += f3;
        index = (u16)(index + 1);
        if (index >= 4) {
            index = 0;
        }
        i++;
    }
}
#pragma pop
