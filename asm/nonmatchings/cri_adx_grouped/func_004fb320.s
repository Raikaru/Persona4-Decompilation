.section .text
.set noat
.set noreorder
glabel func_004fb320
    /* 3FB320 004FB320 7400023C */  lui        $2, %hi(D_00743CA0)
    /* 3FB324 004FB324 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB328 004FB328 A03C428C */  lw         $2, %lo(D_00743CA0)($2)
    /* 3FB32C 004FB32C 03004010 */  beqz       $2, .L004FB33C
    /* 3FB330 004FB330 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB334 004FB334 09F84000 */  jalr       $2
    /* 3FB338 004FB338 00000000 */   nop
  .L004FB33C:
    /* 3FB33C 004FB33C 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB340 004FB340 0800E003 */  jr         $31
    /* 3FB344 004FB344 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb320, 0x28
