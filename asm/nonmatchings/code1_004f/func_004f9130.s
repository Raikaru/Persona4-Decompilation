.section .text
.set noat
.set noreorder
glabel func_004f9130
    /* 3F9130 004F9130 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9134 004F9134 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9138 004F9138 D8E3130C */  jal        func_004f8f60
    /* 3F913C 004F913C 00000000 */   nop
    /* 3F9140 004F9140 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9144 004F9144 2D100000 */  daddu      $2, $0, $0
    /* 3F9148 004F9148 0800E003 */  jr         $31
    /* 3F914C 004F914C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f9130, 0x20
