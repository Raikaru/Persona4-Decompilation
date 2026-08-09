.section .text
.set noat
.set noreorder
glabel func_004fb228
    /* 3FB228 004FB228 7400023C */  lui        $2, %hi(D_00743C88)
    /* 3FB22C 004FB22C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB230 004FB230 883C428C */  lw         $2, %lo(D_00743C88)($2)
    /* 3FB234 004FB234 03004010 */  beqz       $2, .L004FB244
    /* 3FB238 004FB238 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB23C 004FB23C 09F84000 */  jalr       $2
    /* 3FB240 004FB240 00000000 */   nop
  .L004FB244:
    /* 3FB244 004FB244 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB248 004FB248 0800E003 */  jr         $31
    /* 3FB24C 004FB24C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb228, 0x28
