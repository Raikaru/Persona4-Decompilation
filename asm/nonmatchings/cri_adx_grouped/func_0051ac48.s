.section .text
.set noat
.set noreorder
glabel func_0051ac48
    /* 41AC48 0051AC48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41AC4C 0051AC4C 2D30A000 */  daddu      $6, $5, $0
    /* 41AC50 0051AC50 0000BFFF */  sd         $31, 0x0($29)
    /* 41AC54 0051AC54 CC1F858C */  lw         $5, 0x1FCC($4)
    /* 41AC58 0051AC58 0000BFDF */  ld         $31, 0x0($29)
    /* 41AC5C 0051AC5C 60561408 */  j          func_00515980
    /* 41AC60 0051AC60 1000BD27 */   addiu     $29, $29, 0x10
    /* 41AC64 0051AC64 00000000 */  nop
.size func_0051ac48, 0x20
