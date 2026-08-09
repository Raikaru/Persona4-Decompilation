.section .text
.set noat
.set noreorder
glabel func_004fb3e8
    /* 3FB3E8 004FB3E8 7400023C */  lui        $2, %hi(D_00743CB4)
    /* 3FB3EC 004FB3EC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB3F0 004FB3F0 B43C428C */  lw         $2, %lo(D_00743CB4)($2)
    /* 3FB3F4 004FB3F4 03004010 */  beqz       $2, .L004FB404
    /* 3FB3F8 004FB3F8 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB3FC 004FB3FC 09F84000 */  jalr       $2
    /* 3FB400 004FB400 00000000 */   nop
  .L004FB404:
    /* 3FB404 004FB404 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB408 004FB408 0800E003 */  jr         $31
    /* 3FB40C 004FB40C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb3e8, 0x28
