.section .text
.set noat
.set noreorder
glabel func_004fb280
    /* 3FB280 004FB280 7400023C */  lui        $2, %hi(D_00743C90)
    /* 3FB284 004FB284 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB288 004FB288 903C428C */  lw         $2, %lo(D_00743C90)($2)
    /* 3FB28C 004FB28C 03004010 */  beqz       $2, .L004FB29C
    /* 3FB290 004FB290 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB294 004FB294 09F84000 */  jalr       $2
    /* 3FB298 004FB298 00000000 */   nop
  .L004FB29C:
    /* 3FB29C 004FB29C 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB2A0 004FB2A0 0800E003 */  jr         $31
    /* 3FB2A4 004FB2A4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb280, 0x28
