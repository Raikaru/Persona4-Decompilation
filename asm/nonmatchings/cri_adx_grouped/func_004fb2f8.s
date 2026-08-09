.section .text
.set noat
.set noreorder
glabel func_004fb2f8
    /* 3FB2F8 004FB2F8 7400023C */  lui        $2, %hi(D_00743C9C)
    /* 3FB2FC 004FB2FC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB300 004FB300 9C3C428C */  lw         $2, %lo(D_00743C9C)($2)
    /* 3FB304 004FB304 03004010 */  beqz       $2, .L004FB314
    /* 3FB308 004FB308 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB30C 004FB30C 09F84000 */  jalr       $2
    /* 3FB310 004FB310 00000000 */   nop
  .L004FB314:
    /* 3FB314 004FB314 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB318 004FB318 0800E003 */  jr         $31
    /* 3FB31C 004FB31C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb2f8, 0x28
