.section .text
.set noat
.set noreorder
glabel func_004fb398
    /* 3FB398 004FB398 7400023C */  lui        $2, %hi(D_00743CAC)
    /* 3FB39C 004FB39C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB3A0 004FB3A0 AC3C428C */  lw         $2, %lo(D_00743CAC)($2)
    /* 3FB3A4 004FB3A4 03004010 */  beqz       $2, .L004FB3B4
    /* 3FB3A8 004FB3A8 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB3AC 004FB3AC 09F84000 */  jalr       $2
    /* 3FB3B0 004FB3B0 00000000 */   nop
  .L004FB3B4:
    /* 3FB3B4 004FB3B4 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB3B8 004FB3B8 0800E003 */  jr         $31
    /* 3FB3BC 004FB3BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb398, 0x28
