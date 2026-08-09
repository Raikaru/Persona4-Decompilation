.section .text
.set noat
.set noreorder
glabel func_004d3c60
    /* 3D3C60 004D3C60 7200023C */  lui        $2, %hi(D_00724E74)
    /* 3D3C64 004D3C64 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3C68 004D3C68 744E428C */  lw         $2, %lo(D_00724E74)($2)
    /* 3D3C6C 004D3C6C 03004010 */  beqz       $2, .L004D3C7C
    /* 3D3C70 004D3C70 0000BFFF */   sd        $31, 0x0($29)
    /* 3D3C74 004D3C74 09F84000 */  jalr       $2
    /* 3D3C78 004D3C78 00000000 */   nop
  .L004D3C7C:
    /* 3D3C7C 004D3C7C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3C80 004D3C80 0800E003 */  jr         $31
    /* 3D3C84 004D3C84 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d3c60, 0x28
