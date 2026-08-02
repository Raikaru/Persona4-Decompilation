.section .text
.set noat
.set noreorder
glabel func_0047aa10
    /* 37AA10 0047AA10 0000A2C4 */  lwc1       $f2, 0x0($5)
    /* 37AA14 0047AA14 0400A1C4 */  lwc1       $f1, 0x4($5)
    /* 37AA18 0047AA18 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 37AA1C 0047AA1C 700182E4 */  swc1       $f2, 0x170($4)
    /* 37AA20 0047AA20 740181E4 */  swc1       $f1, 0x174($4)
    /* 37AA24 0047AA24 780180E4 */  swc1       $f0, 0x178($4)
    /* 37AA28 0047AA28 0800E003 */  jr         $31
    /* 37AA2C 0047AA2C 00000000 */   nop
.size func_0047aa10, 0x20
