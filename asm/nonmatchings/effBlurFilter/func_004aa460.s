.section .text
.set noat
.set noreorder
glabel func_004aa460
    /* 3AA460 004AA460 D0FEBD27 */  addiu      $29, $29, -0x130
    /* 3AA464 004AA464 1000BFFF */  sd         $31, 0x10($29)
    /* 3AA468 004AA468 0000B07F */  sq         $16, 0x0($29)
    /* 3AA46C 004AA46C 2400838C */  lw         $3, 0x24($4)
    /* 3AA470 004AA470 C0007024 */  addiu      $16, $3, 0xC0
    /* 3AA474 004AA474 C3006390 */  lbu        $3, 0xC3($3)
    /* 3AA478 004AA478 32006018 */  blez       $3, .L004AA544
    /* 3AA47C 004AA47C 00000000 */   nop
    /* 3AA480 004AA480 03000424 */  addiu      $4, $0, 0x3
    /* 3AA484 004AA484 2C01A527 */  addiu      $5, $29, 0x12C
    /* 3AA488 004AA488 A4D90F0C */  jal        func_003f6690
    /* 3AA48C 004AA48C 00000000 */   nop
    /* 3AA490 004AA490 2D200002 */  daddu      $4, $16, $0
    /* 3AA494 004AA494 2000A527 */  addiu      $5, $29, 0x20
    /* 3AA498 004AA498 10A1120C */  jal        func_004a8440
    /* 3AA49C 004AA49C 00000000 */   nop
    /* 3AA4A0 004AA4A0 8800103C */  lui        $16, %hi(D_00887300)
    /* 3AA4A4 004AA4A4 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* 3AA4A8 004AA4A8 01000424 */  addiu      $4, $0, 0x1
    /* 3AA4AC 004AA4AC 9200023C */  lui        $2, %hi(D_00922D90)
    /* 3AA4B0 004AA4B0 902D458C */  lw         $5, %lo(D_00922D90)($2)
    /* 3AA4B4 004AA4B4 0000028E */  lw         $2, 0x0($16)
    /* 3AA4B8 004AA4B8 09F84000 */  jalr       $2
    /* 3AA4BC 004AA4BC 00000000 */   nop
    /* 3AA4C0 004AA4C0 03000424 */  addiu      $4, $0, 0x3
    /* 3AA4C4 004AA4C4 0300023C */  lui        $2, (0x31001 >> 16)
    /* 3AA4C8 004AA4C8 01104534 */  ori        $5, $2, (0x31001 & 0xFFFF)
    /* 3AA4CC 004AA4CC 10D90F0C */  jal        func_003f6440
    /* 3AA4D0 004AA4D0 00000000 */   nop
    /* 3AA4D4 004AA4D4 FC060224 */  addiu      $2, $0, 0x6FC
    /* 3AA4D8 004AA4D8 3C180200 */  dsll32     $3, $2, 0
    /* 3AA4DC 004AA4DC 9F00023C */  lui        $2, (0x9FC00A >> 16)
    /* 3AA4E0 004AA4E0 0AC04234 */  ori        $2, $2, (0x9FC00A & 0xFFFF)
    /* 3AA4E4 004AA4E4 25204300 */  or         $4, $2, $3
    /* 3AA4E8 004AA4E8 1C28120C */  jal        func_0048a070
    /* 3AA4EC 004AA4EC 00000000 */   nop
    /* 3AA4F0 004AA4F0 03000424 */  addiu      $4, $0, 0x3
    /* 3AA4F4 004AA4F4 2000A527 */  addiu      $5, $29, 0x20
    /* 3AA4F8 004AA4F8 04000624 */  addiu      $6, $0, 0x4
    /* 3AA4FC 004AA4FC 7100073C */  lui        $7, %hi(D_00714368)
    /* 3AA500 004AA500 6843E724 */  addiu      $7, $7, %lo(D_00714368)
    /* 3AA504 004AA504 06000824 */  addiu      $8, $0, 0x6
    /* 3AA508 004AA508 8800023C */  lui        $2, %hi(D_00887314)
    /* 3AA50C 004AA50C 1473428C */  lw         $2, %lo(D_00887314)($2)
    /* 3AA510 004AA510 09F84000 */  jalr       $2
    /* 3AA514 004AA514 00000000 */   nop
    /* 3AA518 004AA518 3828120C */  jal        func_0048a0e0
    /* 3AA51C 004AA51C 00000000 */   nop
    /* 3AA520 004AA520 01000424 */  addiu      $4, $0, 0x1
    /* 3AA524 004AA524 2D280000 */  daddu      $5, $0, $0
    /* 3AA528 004AA528 0000028E */  lw         $2, 0x0($16)
    /* 3AA52C 004AA52C 09F84000 */  jalr       $2
    /* 3AA530 004AA530 00000000 */   nop
    /* 3AA534 004AA534 03000424 */  addiu      $4, $0, 0x3
    /* 3AA538 004AA538 2C01A58F */  lw         $5, 0x12C($29)
    /* 3AA53C 004AA53C 10D90F0C */  jal        func_003f6440
    /* 3AA540 004AA540 00000000 */   nop
  .L004AA544:
    /* 3AA544 004AA544 1000BFDF */  ld         $31, 0x10($29)
    /* 3AA548 004AA548 0000B07B */  lq         $16, 0x0($29)
    /* 3AA54C 004AA54C 3001BD27 */  addiu      $29, $29, 0x130
    /* 3AA550 004AA550 0800E003 */  jr         $31
    /* 3AA554 004AA554 00000000 */   nop
    /* 3AA558 004AA558 00000000 */  nop
    /* 3AA55C 004AA55C 00000000 */  nop
.size func_004aa460, 0x100
