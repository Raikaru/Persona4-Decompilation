.section .text
.set noat
.set noreorder
glabel func_00512138
    /* 412138 00512138 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41213C 0051213C 2D280000 */  daddu      $5, $0, $0
    /* 412140 00512140 0000BFFF */  sd         $31, 0x0($29)
    /* 412144 00512144 0000BFDF */  ld         $31, 0x0($29)
    /* 412148 00512148 16471308 */  j          func_004d1c58
    /* 41214C 0051214C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00512138, 0x18
