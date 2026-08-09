.section .text
.set noat
.set noreorder
glabel func_004cee38
    /* 3CEE38 004CEE38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEE3C 004CEE3C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEE40 004CEE40 0400848C */  lw         $4, 0x4($4)
    /* 3CEE44 004CEE44 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEE48 004CEE48 240F1308 */  j          func_004c3c90
    /* 3CEE4C 004CEE4C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cee38, 0x18
