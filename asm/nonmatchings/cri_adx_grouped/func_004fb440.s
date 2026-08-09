.section .text
.set noat
.set noreorder
glabel func_004fb440
    /* 3FB440 004FB440 7400023C */  lui        $2, %hi(D_00743CBC)
    /* 3FB444 004FB444 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB448 004FB448 BC3C428C */  lw         $2, %lo(D_00743CBC)($2)
    /* 3FB44C 004FB44C 03004010 */  beqz       $2, .L004FB45C
    /* 3FB450 004FB450 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB454 004FB454 09F84000 */  jalr       $2
    /* 3FB458 004FB458 00000000 */   nop
  .L004FB45C:
    /* 3FB45C 004FB45C 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB460 004FB460 0800E003 */  jr         $31
    /* 3FB464 004FB464 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb440, 0x28
