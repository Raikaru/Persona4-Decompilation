.section .text
.set noat
.set noreorder
glabel func_0014b490
    /* 4B490 0014B490 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4B494 0014B494 0000BFFF */  sd         $31, 0x0($29)
    /* 4B498 0014B498 14000424 */  addiu      $4, $0, 0x14
    /* 4B49C 0014B49C AC14050C */  jal        func_001452b0
    /* 4B4A0 0014B4A0 00000000 */   nop
    /* 4B4A4 0014B4A4 2D180000 */  daddu      $3, $0, $0
    /* 4B4A8 0014B4A8 02004010 */  beqz       $2, .L0014B4B4
    /* 4B4AC 0014B4AC 00000000 */   nop
    /* 4B4B0 0014B4B0 4C01438C */  lw         $3, 0x14C($2)
  .L0014B4B4:
    /* 4B4B4 0014B4B4 2D106000 */  daddu      $2, $3, $0
    /* 4B4B8 0014B4B8 0000BFDF */  ld         $31, 0x0($29)
    /* 4B4BC 0014B4BC 1000BD27 */  addiu      $29, $29, 0x10
    /* 4B4C0 0014B4C0 0800E003 */  jr         $31
    /* 4B4C4 0014B4C4 00000000 */   nop
    /* 4B4C8 0014B4C8 00000000 */  nop
    /* 4B4CC 0014B4CC 00000000 */  nop
.size func_0014b490, 0x40
