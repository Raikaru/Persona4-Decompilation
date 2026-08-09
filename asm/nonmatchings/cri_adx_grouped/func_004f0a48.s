.section .text
.set noat
.set noreorder
glabel func_004f0a48
    /* 3F0A48 004F0A48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0A4C 004F0A4C 2D380000 */  daddu      $7, $0, $0
    /* 3F0A50 004F0A50 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0A54 004F0A54 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0A58 004F0A58 98C21308 */  j          func_004f0a60
    /* 3F0A5C 004F0A5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0a48, 0x18
