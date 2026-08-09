.section .text
.set noat
.set noreorder
glabel func_004cee08
    /* 3CEE08 004CEE08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEE0C 004CEE0C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEE10 004CEE10 0400848C */  lw         $4, 0x4($4)
    /* 3CEE14 004CEE14 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEE18 004CEE18 1E0F1308 */  j          func_004c3c78
    /* 3CEE1C 004CEE1C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cee08, 0x18
