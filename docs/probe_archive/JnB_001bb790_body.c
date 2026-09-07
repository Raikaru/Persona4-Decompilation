/* Current typed curve floor: 296B/304B, 59 differing bytes in 21 emitted
 * words, all six relocations resolved; eight zero-tail bytes. Production ASM.
 * Ordinary pointer arithmetic ties the former integer-punned candidate.
 * The RwV3d seed copy preserves three loads before any output store.
 * Y/Z products precede X accumulation, including when output overlaps input.
 * IDA: docs/ida_headstart/src/Battle/btlMain.c:898-936.
 * Residual: zero hoisting, the coefficient address's zero add, and resulting
 * loop scheduling/register allocation. Cursor grouping worsens to 32 fndiff
 * words; loop-invariant/basis forms give 40 and grouped work 56. A weighted
 * vector ties 23 fndiff words, including the two missing zero-tail words.
 * All 22 existing owner C matches and relocation lists remain intact.
 * Native Clang UB-trap smoke: 15,360 cases, valid ring indices 0..3,
 * coefficient boundaries, partial output overlap, seed-object aliasing and
 * whole-buffer preservation. C floating behavior, not an EE COP1 emulator.
 */
extern RwV3d D_00881430;
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
        temp_f5 = weights[i];
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
