.section .text
.set noat
.set noreorder
glabel func_004f99f8
    /* 3F99F8 004F99F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F99FC 004F99FC 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9A00 004F9A00 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9A04 004F9A04 88C11308 */  j          func_004f0620
    /* 3F9A08 004F9A08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F9A0C 004F9A0C 00000000 */  nop
.size func_004f99f8, 0x18
