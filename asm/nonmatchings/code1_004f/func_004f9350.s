.section .text
.set noat
.set noreorder
glabel func_004f9350
    /* 3F9350 004F9350 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9354 004F9354 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9358 004F9358 0000BFDF */  ld         $31, 0x0($29)
    /* 3F935C 004F935C 66E41308 */  j          func_004f9198
    /* 3F9360 004F9360 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F9364 004F9364 00000000 */  nop
.size func_004f9350, 0x18
