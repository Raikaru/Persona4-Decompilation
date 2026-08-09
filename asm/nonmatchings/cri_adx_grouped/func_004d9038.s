.section .text
.set noat
.set noreorder
glabel func_004d9038
    /* 3D9038 004D9038 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D903C 004D903C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9040 004D9040 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9044 004D9044 44FD1208 */  j          func_004bf510
    /* 3D9048 004D9048 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D904C 004D904C 00000000 */  nop
.size func_004d9038, 0x18
