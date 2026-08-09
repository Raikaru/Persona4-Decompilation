.section .text
.set noat
.set noreorder
glabel func_004d3528
    /* 3D3528 004D3528 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D352C 004D352C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3530 004D3530 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3534 004D3534 969C1308 */  j          func_004e7258
    /* 3D3538 004D3538 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D353C 004D353C 00000000 */  nop
.size func_004d3528, 0x18
