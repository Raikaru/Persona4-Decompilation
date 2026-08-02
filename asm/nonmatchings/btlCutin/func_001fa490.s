.section .text
.set noat
.set noreorder
glabel func_001fa490
    /* FA490 001FA490 D0FEBD27 */  addiu      $29, $29, -0x130
    /* FA494 001FA494 1000BFFF */  sd         $31, 0x10($29)
    /* FA498 001FA498 0000B07F */  sq         $16, 0x0($29)
    /* FA49C 001FA49C 2D808000 */  daddu      $16, $4, $0
    /* FA4A0 001FA4A0 2C18040C */  jal        func_001060b0
    /* FA4A4 001FA4A4 00000000 */   nop
    /* FA4A8 001FA4A8 3C240200 */  dsll32     $4, $2, 16
    /* FA4AC 001FA4AC 3F240400 */  dsra32     $4, $4, 16
    /* FA4B0 001FA4B0 5843040C */  jal        func_00110d60
    /* FA4B4 001FA4B4 00000000 */   nop
    /* FA4B8 001FA4B8 01004330 */  andi       $3, $2, 0x1
    /* FA4BC 001FA4BC 2B280300 */  sltu       $5, $0, $3
    /* FA4C0 001FA4C0 00000496 */  lhu        $4, 0x0($16)
    /* FA4C4 001FA4C4 05000324 */  addiu      $3, $0, 0x5
    /* FA4C8 001FA4C8 39008310 */  beq        $4, $3, .L001FA5B0
    /* FA4CC 001FA4CC 00000000 */   nop
    /* FA4D0 001FA4D0 03000324 */  addiu      $3, $0, 0x3
    /* FA4D4 001FA4D4 1E008310 */  beq        $4, $3, .L001FA550
    /* FA4D8 001FA4D8 00000000 */   nop
    /* FA4DC 001FA4DC 01000324 */  addiu      $3, $0, 0x1
    /* FA4E0 001FA4E0 03008310 */  beq        $4, $3, .L001FA4F0
    /* FA4E4 001FA4E4 00000000 */   nop
    /* FA4E8 001FA4E8 54000010 */  b          .L001FA63C
    /* FA4EC 001FA4EC 00000000 */   nop
  .L001FA4F0:
    /* FA4F0 001FA4F0 02000686 */  lh         $6, 0x2($16)
    /* FA4F4 001FA4F4 80180500 */  sll        $3, $5, 2
    /* FA4F8 001FA4F8 30A58227 */  addiu      $2, $28, -0x5AD0
    /* FA4FC 001FA4FC 21104300 */  addu       $2, $2, $3
    /* FA500 001FA500 2000A427 */  addiu      $4, $29, 0x20
    /* FA504 001FA504 6200053C */  lui        $5, %hi(D_00625190)
    /* FA508 001FA508 9051A524 */  addiu      $5, $5, %lo(D_00625190)
    /* FA50C 001FA50C 0000478C */  lw         $7, 0x0($2)
    /* FA510 001FA510 2208110C */  jal        func_00442088
    /* FA514 001FA514 00000000 */   nop
    /* FA518 001FA518 28A58427 */  addiu      $4, $28, -0x5AD8
    /* FA51C 001FA51C 6200053C */  lui        $5, %hi(D_00625090)
    /* FA520 001FA520 9050A524 */  addiu      $5, $5, %lo(D_00625090)
    /* FA524 001FA524 52010624 */  addiu      $6, $0, 0x152
    /* FA528 001FA528 DA02110C */  jal        func_00440b68
    /* FA52C 001FA52C 00000000 */   nop
    /* FA530 001FA530 2000A427 */  addiu      $4, $29, 0x20
    /* FA534 001FA534 2D280000 */  daddu      $5, $0, $0
    /* FA538 001FA538 9852110C */  jal        func_00454a60
    /* FA53C 001FA53C 00000000 */   nop
    /* FA540 001FA540 ACB3838F */  lw         $3, -0x4C54($28)
    /* FA544 001FA544 840B62AC */  sw         $2, 0xB84($3)
    /* FA548 001FA548 3C000010 */  b          .L001FA63C
    /* FA54C 001FA54C 00000000 */   nop
  .L001FA550:
    /* FA550 001FA550 02000686 */  lh         $6, 0x2($16)
    /* FA554 001FA554 80180500 */  sll        $3, $5, 2
    /* FA558 001FA558 30A58227 */  addiu      $2, $28, -0x5AD0
    /* FA55C 001FA55C 21104300 */  addu       $2, $2, $3
    /* FA560 001FA560 2000A427 */  addiu      $4, $29, 0x20
    /* FA564 001FA564 6200053C */  lui        $5, %hi(D_006251C0)
    /* FA568 001FA568 C051A524 */  addiu      $5, $5, %lo(D_006251C0)
    /* FA56C 001FA56C 0000478C */  lw         $7, 0x0($2)
    /* FA570 001FA570 2208110C */  jal        func_00442088
    /* FA574 001FA574 00000000 */   nop
    /* FA578 001FA578 28A58427 */  addiu      $4, $28, -0x5AD8
    /* FA57C 001FA57C 6200053C */  lui        $5, %hi(D_00625090)
    /* FA580 001FA580 9050A524 */  addiu      $5, $5, %lo(D_00625090)
    /* FA584 001FA584 58010624 */  addiu      $6, $0, 0x158
    /* FA588 001FA588 DA02110C */  jal        func_00440b68
    /* FA58C 001FA58C 00000000 */   nop
    /* FA590 001FA590 2000A427 */  addiu      $4, $29, 0x20
    /* FA594 001FA594 2D280000 */  daddu      $5, $0, $0
    /* FA598 001FA598 9852110C */  jal        func_00454a60
    /* FA59C 001FA59C 00000000 */   nop
    /* FA5A0 001FA5A0 ACB3838F */  lw         $3, -0x4C54($28)
    /* FA5A4 001FA5A4 840B62AC */  sw         $2, 0xB84($3)
    /* FA5A8 001FA5A8 24000010 */  b          .L001FA63C
    /* FA5AC 001FA5AC 00000000 */   nop
  .L001FA5B0:
    /* FA5B0 001FA5B0 38000424 */  addiu      $4, $0, 0x38
    /* FA5B4 001FA5B4 CC18040C */  jal        func_00106330
    /* FA5B8 001FA5B8 00000000 */   nop
    /* FA5BC 001FA5BC 14004010 */  beqz       $2, .L001FA610
    /* FA5C0 001FA5C0 00000000 */   nop
    /* FA5C4 001FA5C4 05000224 */  addiu      $2, $0, 0x5
    /* FA5C8 001FA5C8 2C01A2A7 */  sh         $2, 0x12C($29)
    /* FA5CC 001FA5CC 2C18040C */  jal        func_001060b0
    /* FA5D0 001FA5D0 00000000 */   nop
    /* FA5D4 001FA5D4 3C240200 */  dsll32     $4, $2, 16
    /* FA5D8 001FA5D8 3F240400 */  dsra32     $4, $4, 16
    /* FA5DC 001FA5DC 5843040C */  jal        func_00110d60
    /* FA5E0 001FA5E0 00000000 */   nop
    /* FA5E4 001FA5E4 01004230 */  andi       $2, $2, 0x1
    /* FA5E8 001FA5E8 05004010 */  beqz       $2, .L001FA600
    /* FA5EC 001FA5EC 00000000 */   nop
    /* FA5F0 001FA5F0 1E000224 */  addiu      $2, $0, 0x1E
    /* FA5F4 001FA5F4 2E01A2A7 */  sh         $2, 0x12E($29)
    /* FA5F8 001FA5F8 09000010 */  b          .L001FA620
    /* FA5FC 001FA5FC 00000000 */   nop
  .L001FA600:
    /* FA600 001FA600 14000224 */  addiu      $2, $0, 0x14
    /* FA604 001FA604 2E01A2A7 */  sh         $2, 0x12E($29)
    /* FA608 001FA608 05000010 */  b          .L001FA620
    /* FA60C 001FA60C 00000000 */   nop
  .L001FA610:
    /* FA610 001FA610 08000224 */  addiu      $2, $0, 0x8
    /* FA614 001FA614 2C01A2A7 */  sh         $2, 0x12C($29)
    /* FA618 001FA618 1E000224 */  addiu      $2, $0, 0x1E
    /* FA61C 001FA61C 2E01A2A7 */  sh         $2, 0x12E($29)
  .L001FA620:
    /* FA620 001FA620 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA624 001FA624 C80D448C */  lw         $4, 0xDC8($2)
    /* FA628 001FA628 2C01A58F */  lw         $5, 0x12C($29)
    /* FA62C 001FA62C 8883040C */  jal        func_00120e20
    /* FA630 001FA630 00000000 */   nop
    /* FA634 001FA634 ACB3838F */  lw         $3, -0x4C54($28)
    /* FA638 001FA638 880B62AC */  sw         $2, 0xB88($3)
  .L001FA63C:
    /* FA63C 001FA63C 00000496 */  lhu        $4, 0x0($16)
    /* FA640 001FA640 ACB3838F */  lw         $3, -0x4C54($28)
    /* FA644 001FA644 7C0B64A4 */  sh         $4, 0xB7C($3)
    /* FA648 001FA648 1000BFDF */  ld         $31, 0x10($29)
    /* FA64C 001FA64C 0000B07B */  lq         $16, 0x0($29)
    /* FA650 001FA650 3001BD27 */  addiu      $29, $29, 0x130
    /* FA654 001FA654 0800E003 */  jr         $31
    /* FA658 001FA658 00000000 */   nop
    /* FA65C 001FA65C 00000000 */  nop
.size func_001fa490, 0x1d0
