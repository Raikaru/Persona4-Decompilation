.section .text
.set noat
.set noreorder
glabel func_004cee50
    /* 3CEE50 004CEE50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEE54 004CEE54 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEE58 004CEE58 0400848C */  lw         $4, 0x4($4)
    /* 3CEE5C 004CEE5C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEE60 004CEE60 220F1308 */  j          func_004c3c88
    /* 3CEE64 004CEE64 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cee50, 0x18
