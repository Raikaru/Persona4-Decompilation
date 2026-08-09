.section .text
.set noat
.set noreorder
glabel func_004d6c68
    /* 3D6C68 004D6C68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6C6C 004D6C6C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D6C70 004D6C70 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6C74 004D6C74 143B1308 */  j          func_004cec50
    /* 3D6C78 004D6C78 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D6C7C 004D6C7C 00000000 */  nop
.size func_004d6c68, 0x18
