.section .text
.set noat
.set noreorder
glabel func_004fb1d0
    /* 3FB1D0 004FB1D0 7400033C */  lui        $3, %hi(D_00743C80)
    /* 3FB1D4 004FB1D4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB1D8 004FB1D8 803C638C */  lw         $3, %lo(D_00743C80)($3)
    /* 3FB1DC 004FB1DC 2D100000 */  daddu      $2, $0, $0
    /* 3FB1E0 004FB1E0 03006010 */  beqz       $3, .L004FB1F0
    /* 3FB1E4 004FB1E4 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB1E8 004FB1E8 09F86000 */  jalr       $3
    /* 3FB1EC 004FB1EC 00000000 */   nop
  .L004FB1F0:
    /* 3FB1F0 004FB1F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB1F4 004FB1F4 0800E003 */  jr         $31
    /* 3FB1F8 004FB1F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FB1FC 004FB1FC 00000000 */  nop
.size func_004fb1d0, 0x30
