.section .text
.set noat
.set noreorder
glabel func_004fb490
    /* 3FB490 004FB490 7400023C */  lui        $2, %hi(D_00743CC4)
    /* 3FB494 004FB494 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB498 004FB498 C43C428C */  lw         $2, %lo(D_00743CC4)($2)
    /* 3FB49C 004FB49C 03004010 */  beqz       $2, .L004FB4AC
    /* 3FB4A0 004FB4A0 0000BFFF */   sd        $31, 0x0($29)
    /* 3FB4A4 004FB4A4 09F84000 */  jalr       $2
    /* 3FB4A8 004FB4A8 00000000 */   nop
  .L004FB4AC:
    /* 3FB4AC 004FB4AC 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB4B0 004FB4B0 0800E003 */  jr         $31
    /* 3FB4B4 004FB4B4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004fb490, 0x28
