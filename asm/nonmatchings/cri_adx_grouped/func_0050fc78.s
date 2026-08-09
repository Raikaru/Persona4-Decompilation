.section .text
.set noat
.set noreorder
glabel func_0050fc78
    /* 40FC78 0050FC78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FC7C 0050FC7C 0000BFFF */  sd         $31, 0x0($29)
    /* 40FC80 0050FC80 A800848C */  lw         $4, 0xA8($4)
    /* 40FC84 0050FC84 0000BFDF */  ld         $31, 0x0($29)
    /* 40FC88 0050FC88 4CAB1408 */  j          func_0052ad30
    /* 40FC8C 0050FC8C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050fc78, 0x18
