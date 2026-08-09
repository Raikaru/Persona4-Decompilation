.section .text
.set noat
.set noreorder
glabel func_004fb200
    /* 3FB200 004FB200 7400023C */  lui        $2, %hi(D_00743C84)
    /* 3FB204 004FB204 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB208 004FB208 843C428C */  lw         $2, %lo(D_00743C84)($2)
    /* 3FB20C 004FB20C 03004010 */  beqz       $2, .L004FB21C
    /* 3FB210 004FB210 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB214 004FB214 09F84000 */  jalr       $2
    /* 3FB218 004FB218 00000000 */   nop
  .L004FB21C:
    /* 3FB21C 004FB21C 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB220 004FB220 0800E003 */  jr         $31
    /* 3FB224 004FB224 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb200, 0x28
