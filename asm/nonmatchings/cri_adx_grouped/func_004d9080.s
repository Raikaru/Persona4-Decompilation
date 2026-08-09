.section .text
.set noat
.set noreorder
glabel func_004d9080
    /* 3D9080 004D9080 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9084 004D9084 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9088 004D9088 0000BFDF */  ld         $31, 0x0($29)
    /* 3D908C 004D908C 8EFD1208 */  j          func_004bf638
    /* 3D9090 004D9090 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9094 004D9094 00000000 */  nop
.size func_004d9080, 0x18
