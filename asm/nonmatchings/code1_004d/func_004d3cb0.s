.section .text
.set noat
.set noreorder
glabel func_004d3cb0
    /* 3D3CB0 004D3CB0 7200023C */  lui        $2, %hi(D_00724E80)
    /* 3D3CB4 004D3CB4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3CB8 004D3CB8 804E428C */  lw         $2, %lo(D_00724E80)($2)
    /* 3D3CBC 004D3CBC 03004010 */  beqz       $2, .L004D3CCC
    /* 3D3CC0 004D3CC0 0000BFFF */   sd        $31, 0x0($29)
    /* 3D3CC4 004D3CC4 09F84000 */  jalr       $2
    /* 3D3CC8 004D3CC8 00000000 */   nop
  .L004D3CCC:
    /* 3D3CCC 004D3CCC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3CD0 004D3CD0 0800E003 */  jr         $31
    /* 3D3CD4 004D3CD4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d3cb0, 0x28
