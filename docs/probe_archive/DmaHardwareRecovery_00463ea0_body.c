/* MATCH: src/Kernel/sdkUttmx.c, MWCCPS2 b210 -O2 with loop invariants.
 * 604 executable bytes / 608B window; both call relocations resolve exactly;
 * four zero alignment bytes. Hardware-only sync/COP0 waits use memory
 * clobbers; ordinary address arithmetic and MMIO control remain C.
 * Current STYLE permits this bounded hardware operation. The old W53
 * archive remains historical evidence, not a current policy prohibition.
 * Keep the retail seven-instruction wait loops conservatively; see
 * https://www.spinics.net/lists/mips/msg71675.html for revision caveats.
 * Integrated C/retail-word/compiled-word model: 280 cases, 79940 instructions,
 * 1540 condition polls, 550 delayed DMA9 polls, ten rejected mutations.
 * Only byte counts 0..15 issue a final zero-QWC pair. Nonzero exact chunk
 * multiples finish with a full pair. Models do not prove physical hardware,
 * cache preparation, concurrent activity or high-address bus mapping.
 */
// FUN_00463EA0
#pragma push
#pragma opt_loop_invariants on
void func_00463ea0(u32 destination, u32 source, u32 byte_count)
{
    extern void func_00421a60(s32 arg0);
    extern void func_003f4370(void);
    u32 dst;
    u32 src;
    u32 qwc;

    dst = destination;
    src = source;
    qwc = byte_count >> 4;
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
                ".set reorder\n" : : : "memory");
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
                ".set reorder\n" : : : "memory");
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
            ".set reorder\n" : : : "memory");
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
            ".set reorder\n" : : : "memory");
    }
}
#pragma pop
