.section .text
.set noat
.set noreorder
glabel func_004fb2a8
    /* 3FB2A8 004FB2A8 7400023C */  lui        $2, %hi(D_00743C98)
    /* 3FB2AC 004FB2AC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB2B0 004FB2B0 983C428C */  lw         $2, %lo(D_00743C98)($2)
    /* 3FB2B4 004FB2B4 03004010 */  beqz       $2, .L004FB2C4
    /* 3FB2B8 004FB2B8 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB2BC 004FB2BC 09F84000 */  jalr       $2
    /* 3FB2C0 004FB2C0 00000000 */   nop
  .L004FB2C4:
    /* 3FB2C4 004FB2C4 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB2C8 004FB2C8 0800E003 */  jr         $31
    /* 3FB2CC 004FB2CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb2a8, 0x28
