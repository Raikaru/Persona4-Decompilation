.section .text
.set noat
.set noreorder
glabel func_005074a8
    /* 4074A8 005074A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4074AC 005074AC 0000BFFF */  sd         $31, 0x0($29)
    /* 4074B0 005074B0 0000BFDF */  ld         $31, 0x0($29)
    /* 4074B4 005074B4 64EC1308 */  j          func_004fb190
    /* 4074B8 005074B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4074BC 005074BC 00000000 */  nop
.size func_005074a8, 0x18
