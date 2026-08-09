.section .text
.set noat
.set noreorder
glabel func_004d3c88
    /* 3D3C88 004D3C88 7200023C */  lui        $2, %hi(D_00724E78)
    /* 3D3C8C 004D3C8C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3C90 004D3C90 784E428C */  lw         $2, %lo(D_00724E78)($2)
    /* 3D3C94 004D3C94 03004010 */  beqz       $2, .L004D3CA4
    /* 3D3C98 004D3C98 0000BFFF */   sd        $31, 0x0($29)
    /* 3D3C9C 004D3C9C 09F84000 */  jalr       $2
    /* 3D3CA0 004D3CA0 00000000 */   nop
  .L004D3CA4:
    /* 3D3CA4 004D3CA4 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3CA8 004D3CA8 0800E003 */  jr         $31
    /* 3D3CAC 004D3CAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d3c88, 0x28
