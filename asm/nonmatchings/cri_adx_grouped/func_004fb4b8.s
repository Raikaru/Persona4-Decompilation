.section .text
.set noat
.set noreorder
glabel func_004fb4b8
    /* 3FB4B8 004FB4B8 7400023C */  lui        $2, %hi(D_00743CC8)
    /* 3FB4BC 004FB4BC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB4C0 004FB4C0 C83C428C */  lw         $2, %lo(D_00743CC8)($2)
    /* 3FB4C4 004FB4C4 03004010 */  beqz       $2, .L004FB4D4
    /* 3FB4C8 004FB4C8 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB4CC 004FB4CC 09F84000 */  jalr       $2
    /* 3FB4D0 004FB4D0 00000000 */   nop
  .L004FB4D4:
    /* 3FB4D4 004FB4D4 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB4D8 004FB4D8 0800E003 */  jr         $31
    /* 3FB4DC 004FB4DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb4b8, 0x28
