.section .text
.set noat
.set noreorder
glabel func_004f6870
    /* 3F6870 004F6870 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F6874 004F6874 0000BFFF */  sd         $31, 0x0($29)
    /* 3F6878 004F6878 0000BFDF */  ld         $31, 0x0($29)
    /* 3F687C 004F687C 96E61308 */  j          func_004f9a58
    /* 3F6880 004F6880 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F6884 004F6884 00000000 */  nop
.size func_004f6870, 0x18
