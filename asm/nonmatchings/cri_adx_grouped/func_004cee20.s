.section .text
.set noat
.set noreorder
glabel func_004cee20
    /* 3CEE20 004CEE20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEE24 004CEE24 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEE28 004CEE28 0400848C */  lw         $4, 0x4($4)
    /* 3CEE2C 004CEE2C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEE30 004CEE30 200F1308 */  j          func_004c3c80
    /* 3CEE34 004CEE34 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cee20, 0x18
