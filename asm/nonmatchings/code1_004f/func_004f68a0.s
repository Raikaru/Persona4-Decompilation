.section .text
.set noat
.set noreorder
glabel func_004f68a0
    /* 3F68A0 004F68A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F68A4 004F68A4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F68A8 004F68A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F68AC 004F68AC 7EE61308 */  j          func_004f99f8
    /* 3F68B0 004F68B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F68B4 004F68B4 00000000 */  nop
.size func_004f68a0, 0x18
