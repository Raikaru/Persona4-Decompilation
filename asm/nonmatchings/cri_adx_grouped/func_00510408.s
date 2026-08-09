.section .text
.set noat
.set noreorder
glabel func_00510408
    /* 410408 00510408 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41040C 0051040C 0000BFFF */  sd         $31, 0x0($29)
    /* 410410 00510410 4800848C */  lw         $4, 0x48($4)
    /* 410414 00510414 0000BFDF */  ld         $31, 0x0($29)
    /* 410418 00510418 6AA51308 */  j          func_004e95a8
    /* 41041C 0051041C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00510408, 0x18
