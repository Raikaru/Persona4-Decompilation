.section .text
.set noat
.set noreorder
glabel func_004de198
    /* 3DE198 004DE198 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE19C 004DE19C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE1A0 004DE1A0 0000848C */  lw         $4, 0x0($4)
    /* 3DE1A4 004DE1A4 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE1A8 004DE1A8 18691308 */  j          func_004da460
    /* 3DE1AC 004DE1AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de198, 0x18
