.section .text
.set noat
.set noreorder
glabel func_004d8fa0
    /* 3D8FA0 004D8FA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8FA4 004D8FA4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8FA8 004D8FA8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8FAC 004D8FAC 8EFC1208 */  j          func_004bf238
    /* 3D8FB0 004D8FB0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8FB4 004D8FB4 00000000 */  nop
.size func_004d8fa0, 0x18
