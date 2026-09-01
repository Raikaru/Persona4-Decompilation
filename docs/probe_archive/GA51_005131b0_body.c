/* measured: func_005131b0 without an asm barrier produced object 28B for the 32B retail window, normalized_diff 11; the ee-gcc tail-call layout differs, so this body was reverted to INCLUDE_ASM. */
void func_005131b0(u8 *arg0, u8 *arg1)
{
    func_00514d80(arg0, *(u8 **)(arg0 + 0x200C), arg1);
}
