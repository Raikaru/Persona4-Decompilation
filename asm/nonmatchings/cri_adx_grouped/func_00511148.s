.section .text
.set noat
.set noreorder
glabel func_00511148
    /* 411148 00511148 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41114C 0051114C 0000BFFF */  sd         $31, 0x0($29)
    /* 411150 00511150 0000BFDF */  ld         $31, 0x0($29)
    /* 411154 00511154 ACC11308 */  j          func_004f06b0
    /* 411158 00511158 1000BD27 */   addiu     $29, $29, 0x10
    /* 41115C 0051115C 00000000 */  nop
.size func_00511148, 0x18
