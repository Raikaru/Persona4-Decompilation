.section .text
.set noat
.set noreorder
glabel func_004de1c8
    /* 3DE1C8 004DE1C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE1CC 004DE1CC 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE1D0 004DE1D0 0000848C */  lw         $4, 0x0($4)
    /* 3DE1D4 004DE1D4 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE1D8 004DE1D8 20691308 */  j          func_004da480
    /* 3DE1DC 004DE1DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de1c8, 0x18
