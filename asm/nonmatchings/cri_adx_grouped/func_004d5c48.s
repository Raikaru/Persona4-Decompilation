.section .text
.set noat
.set noreorder
glabel func_004d5c48
    /* 3D5C48 004D5C48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5C4C 004D5C4C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D5C50 004D5C50 3615130C */  jal        func_004c54d8
    /* 3D5C54 004D5C54 00000000 */   nop
    /* 3D5C58 004D5C58 1C57130C */  jal        func_004d5c70
    /* 3D5C5C 004D5C5C 00000000 */   nop
    /* 3D5C60 004D5C60 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5C64 004D5C64 38151308 */  j          func_004c54e0
    /* 3D5C68 004D5C68 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D5C6C 004D5C6C 00000000 */  nop
.size func_004d5c48, 0x28
