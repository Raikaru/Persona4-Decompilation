.section .text
.set noat
.set noreorder
glabel func_004fb1a0
    /* 3FB1A0 004FB1A0 7400033C */  lui        $3, %hi(D_00743C7C)
    /* 3FB1A4 004FB1A4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB1A8 004FB1A8 7C3C638C */  lw         $3, %lo(D_00743C7C)($3)
    /* 3FB1AC 004FB1AC 2D100000 */  daddu      $2, $0, $0
    /* 3FB1B0 004FB1B0 03006010 */  beqz       $3, .L004FB1C0
    /* 3FB1B4 004FB1B4 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB1B8 004FB1B8 09F86000 */  jalr       $3
    /* 3FB1BC 004FB1BC 00000000 */   nop
  .L004FB1C0:
    /* 3FB1C0 004FB1C0 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB1C4 004FB1C4 0800E003 */  jr         $31
    /* 3FB1C8 004FB1C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FB1CC 004FB1CC 00000000 */  nop
.size func_004fb1a0, 0x30
