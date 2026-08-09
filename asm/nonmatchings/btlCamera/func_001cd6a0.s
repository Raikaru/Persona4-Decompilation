.section .text
.set noat
.set noreorder
glabel func_001cd6a0
    /* CD6A0 001CD6A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CD6A4 001CD6A4 0000BFFF */  sd         $31, 0x0($29)
    /* CD6A8 001CD6A8 ACF7060C */  jal        func_001bdeb0
    /* CD6AC 001CD6AC 00000000 */   nop
    /* CD6B0 001CD6B0 0000BFDF */  ld         $31, 0x0($29)
    /* CD6B4 001CD6B4 1000BD27 */  addiu      $29, $29, 0x10
    /* CD6B8 001CD6B8 0800E003 */  jr         $31
    /* CD6BC 001CD6BC 00000000 */   nop
.size func_001cd6a0, 0x20
