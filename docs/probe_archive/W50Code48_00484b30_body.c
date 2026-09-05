/* Corrected hardware-only initializer candidate; production remains ASM.
 * MWCCPS2 b210: object 120B / window 128B / normalized_diff 6 bytes.
 * fndiff reports 8 words: six emitted words use v1 rather than retail v0
 * for the 5.0 constant and D_00713CE0 copy; two missing words are zero tails.
 * VF0 is the immutable vector (0,0,0,1), not a zero quadword. The old archive
 * was semantically wrong at destination offsets 0x0c,0x1c,0x4c,0x5c.
 * Only four genuine COP2 stores use asm. Each has a memory clobber; VF0 is
 * read, not modified. All other writes, address calculations and the copy
 * remain C. Source and destination retain retail's 16-byte alignment.
 * Scalar types, aggregate/address lifetimes, grouped stores, precise memory
 * outputs with/without whole-memory clobbers and a typed record view did
 * not close the residual. No CPU asm, register bindings or padding used.
 */
#pragma push
/* measured: propagation off preserves the retail aggregate-copy sequence. */
#pragma opt_propagation off
void func_00484b30(u8 *arg0)
{
    s32 temp;
    u_long128 *quadSrc;

    func_0043f9c8(arg0, 0, 0x80);
    __asm__ volatile("sqc2 $vf0, 0(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 $vf0, 16(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 $vf0, 64(%0)" : : "r"(arg0) : "memory");
    temp = 0x40A00000;
    *(s32 *)(arg0 + 0x44) = temp;
    __asm__ volatile("sqc2 $vf0, 80(%0)" : : "r"(arg0) : "memory");
    quadSrc = (u_long128 *)(void *)D_00713CE0;
    *(u_long128 *)(arg0 + 0x20) = *quadSrc;
    temp = 0x3F800000;
    *(s32 *)(arg0 + 0x60) = temp;
    *(s32 *)(arg0 + 0x74) = temp;
    temp = -1;
    *(s32 *)(arg0 + 0x64) = temp;
    temp = 0x80;
    *(s32 *)(arg0 + 0x68) = temp;
}
#pragma pop
