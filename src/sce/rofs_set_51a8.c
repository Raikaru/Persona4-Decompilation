/* Optional read-only filesystem state pair setter. */
extern unsigned int *D_00743A50;

// FUN_004F51A8
void func_004f51a8(unsigned int first, unsigned int second)
{
    volatile unsigned int *state = D_00743A50;
    if (state != 0) {
        state[17] = second;
        state[16] = first;
    }
}
