.section .text
.set noat
.set noreorder
glabel func_004d8ec8
    /* 3D8EC8 004D8EC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8ECC 004D8ECC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8ED0 004D8ED0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8ED4 004D8ED4 7CFC1208 */  j          func_004bf1f0
    /* 3D8ED8 004D8ED8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8EDC 004D8EDC 00000000 */  nop
.size func_004d8ec8, 0x18
