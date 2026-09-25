/* Read-only filesystem delegates with an intervening zero-result entrypoint. */
extern unsigned int func_004f2948();
extern unsigned int func_004f28b0();
extern unsigned int func_004f2548();

// FUN_004F86F0
unsigned int func_004f86f0(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    return func_004f2948(a0, a1, a2, a3);
}

// FUN_004F8708
unsigned long long func_004f8708(void)
{
    return 0;
}

// FUN_004F8710
unsigned int func_004f8710(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    return func_004f28b0(a0, a1, a2, a3);
}

// FUN_004F8728
unsigned int func_004f8728(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    return func_004f2548(a0, a1, a2, a3);
}
