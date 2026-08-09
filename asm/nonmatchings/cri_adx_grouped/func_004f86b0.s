.section .text
.set noat
.set noreorder
glabel func_004f86b0
    /* 3F86B0 004F86B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F86B4 004F86B4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F86B8 004F86B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F86BC 004F86BC 38C71308 */  j          func_004f1ce0
    /* 3F86C0 004F86C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F86C4 004F86C4 00000000 */  nop
.size func_004f86b0, 0x18
