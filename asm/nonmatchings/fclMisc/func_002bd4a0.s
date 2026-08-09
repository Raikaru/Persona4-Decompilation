.section .text
.set noat
.set noreorder
glabel func_002bd4a0
    /* 1BD4A0 002BD4A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BD4A4 002BD4A4 1000BFFF */  sd         $31, 0x10($29)
    /* 1BD4A8 002BD4A8 0000B07F */  sq         $16, 0x0($29)
    /* 1BD4AC 002BD4AC 2D808000 */  daddu      $16, $4, $0
    /* 1BD4B0 002BD4B0 09000012 */  beqz       $16, .L002BD4D8
    /* 1BD4B4 002BD4B4 00000000 */   nop
    /* 1BD4B8 002BD4B8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BD4BC 002BD4BC 000002AE */  sw         $2, 0x0($16)
    /* 1BD4C0 002BD4C0 040000A2 */  sb         $0, 0x4($16)
    /* 1BD4C4 002BD4C4 050000A2 */  sb         $0, 0x5($16)
    /* 1BD4C8 002BD4C8 080002AE */  sw         $2, 0x8($16)
    /* 1BD4CC 002BD4CC 01000224 */  addiu      $2, $0, 0x1
    /* 1BD4D0 002BD4D0 0C0002A2 */  sb         $2, 0xC($16)
    /* 1BD4D4 002BD4D4 0D0002A2 */  sb         $2, 0xD($16)
  .L002BD4D8:
    /* 1BD4D8 002BD4D8 0000028E */  lw         $2, 0x0($16)
    /* 1BD4DC 002BD4DC 0C004104 */  bgez       $2, .L002BD510
    /* 1BD4E0 002BD4E0 00000000 */   nop
    /* 1BD4E4 002BD4E4 2D20A000 */  daddu      $4, $5, $0
    /* 1BD4E8 002BD4E8 34DD090C */  jal        func_002774d0
    /* 1BD4EC 002BD4EC 00000000 */   nop
    /* 1BD4F0 002BD4F0 000002AE */  sw         $2, 0x0($16)
    /* 1BD4F4 002BD4F4 2D204000 */  daddu      $4, $2, $0
    /* 1BD4F8 002BD4F8 02000524 */  addiu      $5, $0, 0x2
    /* 1BD4FC 002BD4FC 84E1090C */  jal        func_00278610
    /* 1BD500 002BD500 00000000 */   nop
    /* 1BD504 002BD504 01000224 */  addiu      $2, $0, 0x1
    /* 1BD508 002BD508 02000010 */  b          .L002BD514
    /* 1BD50C 002BD50C 00000000 */   nop
  .L002BD510:
    /* 1BD510 002BD510 2D100000 */  daddu      $2, $0, $0
  .L002BD514:
    /* 1BD514 002BD514 1000BFDF */  ld         $31, 0x10($29)
    /* 1BD518 002BD518 0000B07B */  lq         $16, 0x0($29)
    /* 1BD51C 002BD51C 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BD520 002BD520 0800E003 */  jr         $31
    /* 1BD524 002BD524 00000000 */   nop
    /* 1BD528 002BD528 00000000 */  nop
    /* 1BD52C 002BD52C 00000000 */  nop
.size func_002bd4a0, 0x90
