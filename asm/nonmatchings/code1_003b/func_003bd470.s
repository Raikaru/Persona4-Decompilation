.section .text
.set noat
.set noreorder
glabel func_003bd470
    /* 2BD470 003BD470 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BD474 003BD474 04000624 */  addiu      $6, $0, 0x4
    /* 2BD478 003BD478 2000BFFF */  sd         $31, 0x20($29)
    /* 2BD47C 003BD47C 1000B17F */  sq         $17, 0x10($29)
    /* 2BD480 003BD480 0000B07F */  sq         $16, 0x0($29)
    /* 2BD484 003BD484 2D888000 */  daddu      $17, $4, $0
    /* 2BD488 003BD488 2D80A000 */  daddu      $16, $5, $0
    /* 2BD48C 003BD48C D87C0F0C */  jal        func_003df360
    /* 2BD490 003BD490 A4B68527 */   addiu     $5, $28, -0x495C
    /* 2BD494 003BD494 06004010 */  beqz       $2, .L003BD4B0
    /* 2BD498 003BD498 00000000 */   nop
    /* 2BD49C 003BD49C 08000224 */  addiu      $2, $0, 0x8
    /* 2BD4A0 003BD4A0 05000212 */  beq        $16, $2, .L003BD4B8
    /* 2BD4A4 003BD4A4 00000000 */   nop
  .L003BD4A8:
    /* 2BD4A8 003BD4A8 0A000010 */  b          .L003BD4D4
    /* 2BD4AC 003BD4AC 2D102002 */   daddu     $2, $17, $0
  .L003BD4B0:
    /* 2BD4B0 003BD4B0 08000010 */  b          .L003BD4D4
    /* 2BD4B4 003BD4B4 2D100000 */   daddu     $2, $0, $0
  .L003BD4B8:
    /* 2BD4B8 003BD4B8 2D202002 */  daddu      $4, $17, $0
    /* 2BD4BC 003BD4BC A0B68527 */  addiu      $5, $28, -0x4960
    /* 2BD4C0 003BD4C0 D87C0F0C */  jal        func_003df360
    /* 2BD4C4 003BD4C4 04000624 */   addiu     $6, $0, 0x4
    /* 2BD4C8 003BD4C8 F7FF4014 */  bnez       $2, .L003BD4A8
    /* 2BD4CC 003BD4CC 00000000 */   nop
    /* 2BD4D0 003BD4D0 2D100000 */  daddu      $2, $0, $0
  .L003BD4D4:
    /* 2BD4D4 003BD4D4 2000BFDF */  ld         $31, 0x20($29)
    /* 2BD4D8 003BD4D8 1000B17B */  lq         $17, 0x10($29)
    /* 2BD4DC 003BD4DC 0000B07B */  lq         $16, 0x0($29)
    /* 2BD4E0 003BD4E0 0800E003 */  jr         $31
    /* 2BD4E4 003BD4E4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2BD4E8 003BD4E8 00000000 */  nop
    /* 2BD4EC 003BD4EC 00000000 */  nop
.size func_003bd470, 0x80
