.section .text
.set noat
.set noreorder
glabel func_0050d3f0
    /* 40D3F0 0050D3F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D3F4 0050D3F4 0000BFFF */  sd         $31, 0x0($29)
    /* 40D3F8 0050D3F8 4000848C */  lw         $4, 0x40($4)
    /* 40D3FC 0050D3FC 0000BFDF */  ld         $31, 0x0($29)
    /* 40D400 0050D400 F0471408 */  j          func_00511fc0
    /* 40D404 0050D404 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050d3f0, 0x18
