.section .text
.set noat
.set noreorder
glabel func_004d9008
    /* 3D9008 004D9008 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D900C 004D900C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9010 004D9010 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9014 004D9014 0EFD1208 */  j          func_004bf438
    /* 3D9018 004D9018 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D901C 004D901C 00000000 */  nop
.size func_004d9008, 0x18
