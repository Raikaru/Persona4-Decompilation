.section .text
.set noat
.set noreorder
glabel func_004d8eb0
    /* 3D8EB0 004D8EB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8EB4 004D8EB4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8EB8 004D8EB8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8EBC 004D8EBC 7AFC1208 */  j          func_004bf1e8
    /* 3D8EC0 004D8EC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8EC4 004D8EC4 00000000 */  nop
.size func_004d8eb0, 0x18
