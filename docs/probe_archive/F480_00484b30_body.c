object_size=120 bytes; retail_window=128 bytes; normalized_diff=6; fndiff differing-word count=8; differing word offsets=0x2c,0x30,0x38,0x3c,0x40,0x44; classification=non-floor register-colouring residual (fresh remeasurement unchanged from archive).

/* Fresh 2026-08-14 remeasurement: scoped verify produced obj 120B/window 128B/nd 6.
   The existing exhaustive ruled-out list remains applicable; no additional probe was retained. */
#pragma opt_propagation off
void func_00484b30(u8 *arg0)
{
    s32 temp;
    u_long128 *quadSrc;
    func_0043f9c8(arg0, 0, 0x80);
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(arg0) : "memory");
    __asm__ volatile("sqc2 vf0, 64(%0)" : : "r"(arg0) : "memory");
    temp = 0x40A00000;
    *(s32 *)(arg0 + 0x44) = temp;
    __asm__ volatile("sqc2 vf0, 80(%0)" : : "r"(arg0) : "memory");
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
#pragma opt_propagation on

Residual: candidate used $v1 for the 0x40a00000 constant and D_00713CE0 lq/sq sequence, while retail used $v0; all other words matched. Prior probes ruled out scalar/aggregate spelling, declaration order, pointer lifetime, address forms, propagation/optimization/scheduling pragmas, and typed aliases; no standalone MMI or COP1 accumulator-chain floor was present.
