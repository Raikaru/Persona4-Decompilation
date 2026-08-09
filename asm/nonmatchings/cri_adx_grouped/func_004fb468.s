.section .text
.set noat
.set noreorder
glabel func_004fb468
    /* 3FB468 004FB468 7400023C */  lui        $2, %hi(D_00743CC0)
    /* 3FB46C 004FB46C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB470 004FB470 C03C428C */  lw         $2, %lo(D_00743CC0)($2)
    /* 3FB474 004FB474 03004010 */  beqz       $2, .L004FB484
    /* 3FB478 004FB478 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB47C 004FB47C 09F84000 */  jalr       $2
    /* 3FB480 004FB480 00000000 */   nop
  .L004FB484:
    /* 3FB484 004FB484 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB488 004FB488 0800E003 */  jr         $31
    /* 3FB48C 004FB48C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb468, 0x28
