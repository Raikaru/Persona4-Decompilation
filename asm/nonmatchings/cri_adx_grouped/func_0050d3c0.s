.section .text
.set noat
.set noreorder
glabel func_0050d3c0
    /* 40D3C0 0050D3C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D3C4 0050D3C4 0000BFFF */  sd         $31, 0x0($29)
    /* 40D3C8 0050D3C8 4000848C */  lw         $4, 0x40($4)
    /* 40D3CC 0050D3CC 0000BFDF */  ld         $31, 0x0($29)
    /* 40D3D0 0050D3D0 38481408 */  j          func_005120e0
    /* 40D3D4 0050D3D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050d3c0, 0x18
