.section .text
.set noat
.set noreorder
glabel func_00510ef8
    /* 410EF8 00510EF8 2D18A000 */  daddu      $3, $5, $0
    /* 410EFC 00510EFC 2D108000 */  daddu      $2, $4, $0
    /* 410F00 00510F00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 410F04 00510F04 2D38C000 */  daddu      $7, $6, $0
    /* 410F08 00510F08 2D200000 */  daddu      $4, $0, $0
    /* 410F0C 00510F0C 2D284000 */  daddu      $5, $2, $0
    /* 410F10 00510F10 0000BFFF */  sd         $31, 0x0($29)
    /* 410F14 00510F14 98C2130C */  jal        func_004f0a60
    /* 410F18 00510F18 2D306000 */   daddu     $6, $3, $0
    /* 410F1C 00510F1C 9300033C */  lui        $3, %hi(D_00932C80)
    /* 410F20 00510F20 0000BFDF */  ld         $31, 0x0($29)
    /* 410F24 00510F24 802C62AC */  sw         $2, %lo(D_00932C80)($3)
    /* 410F28 00510F28 0800E003 */  jr         $31
    /* 410F2C 00510F2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00510ef8, 0x38
