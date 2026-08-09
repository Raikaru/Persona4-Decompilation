.section .text
.set noat
.set noreorder
glabel func_004f9a58
    /* 3F9A58 004F9A58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9A5C 004F9A5C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9A60 004F9A60 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9A64 004F9A64 88C11308 */  j          func_004f0620
    /* 3F9A68 004F9A68 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F9A6C 004F9A6C 00000000 */  nop
.size func_004f9a58, 0x18
