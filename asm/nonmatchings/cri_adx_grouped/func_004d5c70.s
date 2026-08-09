.section .text
.set noat
.set noreorder
glabel func_004d5c70
    /* 3D5C70 004D5C70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5C74 004D5C74 0000BFFF */  sd         $31, 0x0($29)
    /* 3D5C78 004D5C78 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5C7C 004D5C7C D6561308 */  j          func_004d5b58
    /* 3D5C80 004D5C80 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D5C84 004D5C84 00000000 */  nop
.size func_004d5c70, 0x18
