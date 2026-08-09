.section .text
.set noat
.set noreorder
glabel func_004fb348
    /* 3FB348 004FB348 7400023C */  lui        $2, %hi(D_00743CA4)
    /* 3FB34C 004FB34C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB350 004FB350 A43C428C */  lw         $2, %lo(D_00743CA4)($2)
    /* 3FB354 004FB354 03004010 */  beqz       $2, .L004FB364
    /* 3FB358 004FB358 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB35C 004FB35C 09F84000 */  jalr       $2
    /* 3FB360 004FB360 00000000 */   nop
  .L004FB364:
    /* 3FB364 004FB364 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB368 004FB368 0800E003 */  jr         $31
    /* 3FB36C 004FB36C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb348, 0x28
