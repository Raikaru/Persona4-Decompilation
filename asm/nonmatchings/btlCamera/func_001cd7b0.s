.section .text
.set noat
.set noreorder
glabel func_001cd7b0
    /* CD7B0 001CD7B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CD7B4 001CD7B4 0000BFFF */  sd         $31, 0x0($29)
    /* CD7B8 001CD7B8 ACF7060C */  jal        func_001bdeb0
    /* CD7BC 001CD7BC 00000000 */   nop
    /* CD7C0 001CD7C0 0000BFDF */  ld         $31, 0x0($29)
    /* CD7C4 001CD7C4 1000BD27 */  addiu      $29, $29, 0x10
    /* CD7C8 001CD7C8 0800E003 */  jr         $31
    /* CD7CC 001CD7CC 00000000 */   nop
.size func_001cd7b0, 0x20
