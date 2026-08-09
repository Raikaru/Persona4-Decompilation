.section .text
.set noat
.set noreorder
glabel func_004f8710
    /* 3F8710 004F8710 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F8714 004F8714 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8718 004F8718 0000BFDF */  ld         $31, 0x0($29)
    /* 3F871C 004F871C 2CCA1308 */  j          func_004f28b0
    /* 3F8720 004F8720 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F8724 004F8724 00000000 */  nop
.size func_004f8710, 0x18
