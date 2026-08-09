.section .text
.set noat
.set noreorder
glabel func_001cb380
    /* CB380 001CB380 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CB384 001CB384 0000BFFF */  sd         $31, 0x0($29)
    /* CB388 001CB388 ACF7060C */  jal        func_001bdeb0
    /* CB38C 001CB38C 00000000 */   nop
    /* CB390 001CB390 0000BFDF */  ld         $31, 0x0($29)
    /* CB394 001CB394 1000BD27 */  addiu      $29, $29, 0x10
    /* CB398 001CB398 0800E003 */  jr         $31
    /* CB39C 001CB39C 00000000 */   nop
.size func_001cb380, 0x20
