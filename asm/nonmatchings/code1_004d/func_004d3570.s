.section .text
.set noat
.set noreorder
glabel func_004d3570
    /* 3D3570 004D3570 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3574 004D3574 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3578 004D3578 0000BFDF */  ld         $31, 0x0($29)
    /* 3D357C 004D357C DE9C1308 */  j          func_004e7378
    /* 3D3580 004D3580 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3584 004D3584 00000000 */  nop
.size func_004d3570, 0x18
