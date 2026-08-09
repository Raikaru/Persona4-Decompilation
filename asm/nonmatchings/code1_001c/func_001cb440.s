.section .text
.set noat
.set noreorder
glabel func_001cb440
    /* CB440 001CB440 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CB444 001CB444 0000BFFF */  sd         $31, 0x0($29)
    /* CB448 001CB448 ACF7060C */  jal        func_001bdeb0
    /* CB44C 001CB44C 00000000 */   nop
    /* CB450 001CB450 0000BFDF */  ld         $31, 0x0($29)
    /* CB454 001CB454 1000BD27 */  addiu      $29, $29, 0x10
    /* CB458 001CB458 0800E003 */  jr         $31
    /* CB45C 001CB45C 00000000 */   nop
.size func_001cb440, 0x20
