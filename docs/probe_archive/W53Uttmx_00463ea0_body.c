/* target func_00463ea0 (0x00463ea0), retail window 608B. Production remains the original INCLUDE_ASM fallback: the exact probe below uses newly introduced direct inline-asm hardware waits, not an existing project DMA_DRAIN_WAIT macro/pattern, so it is policy-ineligible for production. */
/* Best hardware-assisted replay: object 604B/window 608B; tools/fndiff.py reports 1 differing word only because the retail window has one zero-tail nop; tools/verify.py reports MATCH normalized_diff 0 (retail zero-tail accepted). Commands: python tools/fndiff.py build/.probe_00463ea0_wait.c func_00463ea0 --addr 00463ea0; python tools/verify.py build/.probe_00463ea0_wait.c --show-mismatches. */
/* Best clean-C replay: object 456B/window 608B; tools/fndiff.py reports 110 differing words; tools/verify.py reports normalized_diff 262. Command: python tools/fndiff.py build/.probe_00463ea0_cf.c func_00463ea0 --addr 00463ea0. The no-pragma direct-MMIO probe was 528B/608B with 132 differing words; opt_loop_invariants reduced the all-polling form to 512B/608B with 111 words, while the hardware-shaped no-extra-channel-8-poll form below was the best clean-C floor at 110 words. */
/* Probes covered the Ghidra/IDA ABI (void, u32/u32/u32; first two signedness variants are address-only), direct volatile MMIO versus a hoisted volatile base pointer, while versus hardware-shaped bottom-tested control flow, qwc shift/constant expressions, local declaration order, and the allowed opt_loop_invariants pragma. The residual is the four privileged sync.l/sync.p plus COP0 condition-line bc0f waits (and their required delay nops); bc0f has no C-readable expression. */
// FUN_00463EA0
#pragma opt_loop_invariants on
void func_00463ea0(u32 arg0, u32 arg1, u32 arg2)
{
    extern void func_00421a60(s32 arg0);
    extern void func_003f4370(void);
    u32 dst;
    u32 src;
    u32 qwc;

    dst = arg0;
    src = arg1;
    qwc = arg2 >> 4;
    func_00421a60(0);
    func_003f4370();

    while (qwc >= 0x401U) {
        *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
        *(volatile u32 *)0x1000E010 = 0x200;
        *(volatile u32 *)0x1000D410 = src;
        *(volatile u32 *)0x1000D420 = 0x400;
        *(volatile u32 *)0x1000D480 = 0x70000000;
        *(volatile u32 *)0x1000E020 |= 0x200;
        *(volatile u32 *)0x1000D400 = 0x101;
        src += 0x4000;

        if ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
            *(volatile u32 *)0x1000E020 = 0x200;
            __asm__ volatile(
                ".set noreorder\n"
                "sync.l\n"
                "sync.p\n"
                "1:\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "bc0f 1b\n"
                "nop\n"
                ".set reorder\n");
            while ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
            }
        }

        *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
        *(volatile u32 *)0x1000E010 = 0x100;
        *(volatile u32 *)0x1000D010 = dst;
        *(volatile u32 *)0x1000D020 = 0x400;
        *(volatile u32 *)0x1000D080 = 0x70000000;
        *(volatile u32 *)0x1000E020 |= 0x100;
        *(volatile u32 *)0x1000D000 = 0x100;
        dst += 0x4000;
        qwc -= 0x400;

        if ((*(volatile u32 *)0x1000D000 & 0x100) != 0) {
            *(volatile u32 *)0x1000E020 = 0x100;
            __asm__ volatile(
                ".set noreorder\n"
                "sync.l\n"
                "sync.p\n"
                "1:\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "bc0f 1b\n"
                "nop\n"
                ".set reorder\n");
        }
    }

    *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
    *(volatile u32 *)0x1000E010 = 0x200;
    *(volatile u32 *)0x1000D410 = src;
    *(volatile u32 *)0x1000D420 = qwc;
    *(volatile u32 *)0x1000D480 = 0x70000000;
    *(volatile u32 *)0x1000E020 |= 0x200;
    *(volatile u32 *)0x1000D400 = 0x101;

    if ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
        *(volatile u32 *)0x1000E020 = 0x200;
        __asm__ volatile(
            ".set noreorder\n"
            "sync.l\n"
            "sync.p\n"
            "1:\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "bc0f 1b\n"
            "nop\n"
            ".set reorder\n");
        while ((*(volatile u32 *)0x1000D400 & 0x100) != 0) {
        }
    }

    *(volatile u32 *)0x1000E020 = 0xFFFFFC00U;
    *(volatile u32 *)0x1000E010 = 0x100;
    *(volatile u32 *)0x1000D010 = dst;
    *(volatile u32 *)0x1000D020 = qwc;
    *(volatile u32 *)0x1000D080 = 0x70000000;
    *(volatile u32 *)0x1000E020 |= 0x100;
    *(volatile u32 *)0x1000D000 = 0x100;

    if ((*(volatile u32 *)0x1000D000 & 0x100) != 0) {
        *(volatile u32 *)0x1000E020 = 0x100;
        __asm__ volatile(
            ".set noreorder\n"
            "sync.l\n"
            "sync.p\n"
            "1:\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "nop\n"
            "bc0f 1b\n"
            "nop\n"
            ".set reorder\n");
    }
}
#pragma opt_loop_invariants off
