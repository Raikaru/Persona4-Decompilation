.section .text
.set noat
.set noreorder
glabel func_004de1b0
    /* 3DE1B0 004DE1B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE1B4 004DE1B4 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE1B8 004DE1B8 0000848C */  lw         $4, 0x0($4)
    /* 3DE1BC 004DE1BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE1C0 004DE1C0 1A691308 */  j          func_004da468
    /* 3DE1C4 004DE1C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de1b0, 0x18
