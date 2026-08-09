.section .text
.set noat
.set noreorder
glabel func_004f9a70
    /* 3F9A70 004F9A70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9A74 004F9A74 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9A78 004F9A78 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9A7C 004F9A7C 64901308 */  j          func_004e4190
    /* 3F9A80 004F9A80 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F9A84 004F9A84 00000000 */  nop
.size func_004f9a70, 0x18
