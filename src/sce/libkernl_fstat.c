/* libkernl.a glue.o: the EE device stat stub returns a fixed device mode. */

// FUN_00421F98
int fstat(const char *path, void *statbuf)
{
    *(unsigned long long *)((char *)statbuf + 0x48) = 0;
    *(unsigned int *)((char *)statbuf + 4) = 0x2000;
    return 0;
}
