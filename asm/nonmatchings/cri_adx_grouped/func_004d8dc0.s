.section .text
.set noat
.set noreorder
glabel func_004d8dc0
    /* 3D8DC0 004D8DC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8DC4 004D8DC4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8DC8 004D8DC8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8DCC 004D8DCC 7CFB1208 */  j          func_004bedf0
    /* 3D8DD0 004D8DD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8DD4 004D8DD4 00000000 */  nop
.size func_004d8dc0, 0x18
