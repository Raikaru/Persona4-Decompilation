.section .text
.set noat
.set noreorder
glabel func_004cce28
    /* 3CCE28 004CCE28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCE2C 004CCE2C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCE30 004CCE30 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCE34 004CCE34 88C11308 */  j          func_004f0620
    /* 3CCE38 004CCE38 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCE3C 004CCE3C 00000000 */  nop
.size func_004cce28, 0x18
