.section .text
.set noat
.set noreorder
glabel func_0050fc90
    /* 40FC90 0050FC90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FC94 0050FC94 0000BFFF */  sd         $31, 0x0($29)
    /* 40FC98 0050FC98 A800848C */  lw         $4, 0xA8($4)
    /* 40FC9C 0050FC9C 0000BFDF */  ld         $31, 0x0($29)
    /* 40FCA0 0050FCA0 50AB1408 */  j          func_0052ad40
    /* 40FCA4 0050FCA4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050fc90, 0x18
