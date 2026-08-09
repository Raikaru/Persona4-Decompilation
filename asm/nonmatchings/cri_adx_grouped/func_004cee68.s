.section .text
.set noat
.set noreorder
glabel func_004cee68
    /* 3CEE68 004CEE68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEE6C 004CEE6C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEE70 004CEE70 0400848C */  lw         $4, 0x4($4)
    /* 3CEE74 004CEE74 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEE78 004CEE78 260F1308 */  j          func_004c3c98
    /* 3CEE7C 004CEE7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cee68, 0x18
