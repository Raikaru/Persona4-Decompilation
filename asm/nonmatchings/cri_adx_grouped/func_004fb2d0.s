.section .text
.set noat
.set noreorder
glabel func_004fb2d0
    /* 3FB2D0 004FB2D0 7400023C */  lui        $2, %hi(D_00743C94)
    /* 3FB2D4 004FB2D4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB2D8 004FB2D8 943C428C */  lw         $2, %lo(D_00743C94)($2)
    /* 3FB2DC 004FB2DC 03004010 */  beqz       $2, .L004FB2EC
    /* 3FB2E0 004FB2E0 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB2E4 004FB2E4 09F84000 */  jalr       $2
    /* 3FB2E8 004FB2E8 00000000 */   nop
  .L004FB2EC:
    /* 3FB2EC 004FB2EC 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB2F0 004FB2F0 0800E003 */  jr         $31
    /* 3FB2F4 004FB2F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb2d0, 0x28
