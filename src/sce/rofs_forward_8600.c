/* Read-only filesystem transport entrypoints for the next contiguous range. */
extern unsigned int func_004f1a08();
extern unsigned int func_004f2398();
extern unsigned int func_004f23e0();

// FUN_004F8600
unsigned int func_004f8600(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    return func_004f1a08(a0, a1, a2, a3);
}

// FUN_004F8618
unsigned int func_004f8618(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    return func_004f2398(a0, a1, a2, a3);
}

// FUN_004F8630
unsigned int func_004f8630(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3)
{
    return func_004f23e0(a0, a1, a2, a3);
}
