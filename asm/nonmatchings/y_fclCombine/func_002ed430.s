.section .text
.set noat
.set noreorder
glabel func_002ed430
    /* 1ED430 002ED430 A0FDBD27 */  addiu      $29, $29, -0x260
    /* 1ED434 002ED434 C000BFFF */  sd         $31, 0xC0($29)
    /* 1ED438 002ED438 B000BE7F */  sq         $30, 0xB0($29)
    /* 1ED43C 002ED43C A000B77F */  sq         $23, 0xA0($29)
    /* 1ED440 002ED440 9000B67F */  sq         $22, 0x90($29)
    /* 1ED444 002ED444 8000B57F */  sq         $21, 0x80($29)
    /* 1ED448 002ED448 7000B47F */  sq         $20, 0x70($29)
    /* 1ED44C 002ED44C 6000B37F */  sq         $19, 0x60($29)
    /* 1ED450 002ED450 5000B27F */  sq         $18, 0x50($29)
    /* 1ED454 002ED454 4000B17F */  sq         $17, 0x40($29)
    /* 1ED458 002ED458 3000B07F */  sq         $16, 0x30($29)
    /* 1ED45C 002ED45C 2000B4E7 */  swc1       $f20, 0x20($29)
    /* 1ED460 002ED460 2DA08000 */  daddu      $20, $4, $0
    /* 1ED464 002ED464 3800928C */  lw         $18, 0x38($4)
    /* 1ED468 002ED468 01004392 */  lbu        $3, 0x1($18)
    /* 1ED46C 002ED46C DDFF6324 */  addiu      $3, $3, -0x23
    /* 1ED470 002ED470 1500612C */  sltiu      $1, $3, 0x15
    /* 1ED474 002ED474 920E2010 */  beqz       $1, .L002F0EC0
    /* 1ED478 002ED478 00000000 */   nop
    /* 1ED47C 002ED47C 7500053C */  lui        $5, %hi(jtbl_00749110)
    /* 1ED480 002ED480 1091A524 */  addiu      $5, $5, %lo(jtbl_00749110)
    /* 1ED484 002ED484 80180300 */  sll        $3, $3, 2
    /* 1ED488 002ED488 21186500 */  addu       $3, $3, $5
    /* 1ED48C 002ED48C 0000638C */  lw         $3, 0x0($3)
    /* 1ED490 002ED490 08006000 */  jr         $3
    /* 1ED494 002ED494 00000000 */   nop
    /* 1ED498 002ED498 01000424 */  addiu      $4, $0, 0x1
    /* 1ED49C 002ED49C 2D280000 */  daddu      $5, $0, $0
    /* 1ED4A0 002ED4A0 84910B0C */  jal        func_002e4610
    /* 1ED4A4 002ED4A4 00000000 */   nop
    /* 1ED4A8 002ED4A8 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED4AC 002ED4AC 01000524 */  addiu      $5, $0, 0x1
    /* 1ED4B0 002ED4B0 84910B0C */  jal        func_002e4610
    /* 1ED4B4 002ED4B4 00000000 */   nop
    /* 1ED4B8 002ED4B8 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED4BC 002ED4BC 02000524 */  addiu      $5, $0, 0x2
    /* 1ED4C0 002ED4C0 84910B0C */  jal        func_002e4610
    /* 1ED4C4 002ED4C4 00000000 */   nop
    /* 1ED4C8 002ED4C8 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED4CC 002ED4CC 03000524 */  addiu      $5, $0, 0x3
    /* 1ED4D0 002ED4D0 84910B0C */  jal        func_002e4610
    /* 1ED4D4 002ED4D4 00000000 */   nop
    /* 1ED4D8 002ED4D8 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED4DC 002ED4DC 04000524 */  addiu      $5, $0, 0x4
    /* 1ED4E0 002ED4E0 84910B0C */  jal        func_002e4610
    /* 1ED4E4 002ED4E4 00000000 */   nop
    /* 1ED4E8 002ED4E8 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED4EC 002ED4EC 05000524 */  addiu      $5, $0, 0x5
    /* 1ED4F0 002ED4F0 84910B0C */  jal        func_002e4610
    /* 1ED4F4 002ED4F4 00000000 */   nop
    /* 1ED4F8 002ED4F8 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED4FC 002ED4FC 06000524 */  addiu      $5, $0, 0x6
    /* 1ED500 002ED500 84910B0C */  jal        func_002e4610
    /* 1ED504 002ED504 00000000 */   nop
    /* 1ED508 002ED508 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED50C 002ED50C 07000524 */  addiu      $5, $0, 0x7
    /* 1ED510 002ED510 84910B0C */  jal        func_002e4610
    /* 1ED514 002ED514 00000000 */   nop
    /* 1ED518 002ED518 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED51C 002ED51C 08000524 */  addiu      $5, $0, 0x8
    /* 1ED520 002ED520 84910B0C */  jal        func_002e4610
    /* 1ED524 002ED524 00000000 */   nop
    /* 1ED528 002ED528 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED52C 002ED52C 09000524 */  addiu      $5, $0, 0x9
    /* 1ED530 002ED530 84910B0C */  jal        func_002e4610
    /* 1ED534 002ED534 00000000 */   nop
    /* 1ED538 002ED538 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED53C 002ED53C 2D288000 */  daddu      $5, $4, $0
    /* 1ED540 002ED540 84910B0C */  jal        func_002e4610
    /* 1ED544 002ED544 00000000 */   nop
    /* 1ED548 002ED548 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED54C 002ED54C 0B000524 */  addiu      $5, $0, 0xB
    /* 1ED550 002ED550 84910B0C */  jal        func_002e4610
    /* 1ED554 002ED554 00000000 */   nop
    /* 1ED558 002ED558 0A000424 */  addiu      $4, $0, 0xA
    /* 1ED55C 002ED55C 0C000524 */  addiu      $5, $0, 0xC
    /* 1ED560 002ED560 84910B0C */  jal        func_002e4610
    /* 1ED564 002ED564 00000000 */   nop
    /* 1ED568 002ED568 2D200000 */  daddu      $4, $0, $0
    /* 1ED56C 002ED56C 0D000524 */  addiu      $5, $0, 0xD
    /* 1ED570 002ED570 84910B0C */  jal        func_002e4610
    /* 1ED574 002ED574 00000000 */   nop
    /* 1ED578 002ED578 2D208002 */  daddu      $4, $20, $0
    /* 1ED57C 002ED57C 01000524 */  addiu      $5, $0, 0x1
    /* 1ED580 002ED580 80550C0C */  jal        func_00315600
    /* 1ED584 002ED584 00000000 */   nop
    /* 1ED588 002ED588 24000324 */  addiu      $3, $0, 0x24
    /* 1ED58C 002ED58C 010043A2 */  sb         $3, 0x1($18)
    /* 1ED590 002ED590 4B0E0010 */  b          .L002F0EC0
    /* 1ED594 002ED594 00000000 */   nop
    /* 1ED598 002ED598 34640C0C */  jal        func_003190d0
    /* 1ED59C 002ED59C 00000000 */   nop
    /* 1ED5A0 002ED5A0 01000324 */  addiu      $3, $0, 0x1
    /* 1ED5A4 002ED5A4 460E4310 */  beq        $2, $3, .L002F0EC0
    /* 1ED5A8 002ED5A8 00000000 */   nop
    /* 1ED5AC 002ED5AC 2D200000 */  daddu      $4, $0, $0
    /* 1ED5B0 002ED5B0 1C920B0C */  jal        func_002e4870
    /* 1ED5B4 002ED5B4 00000000 */   nop
    /* 1ED5B8 002ED5B8 00004380 */  lb         $3, 0x0($2)
    /* 1ED5BC 002ED5BC 01000424 */  addiu      $4, $0, 0x1
    /* 1ED5C0 002ED5C0 3F0E6414 */  bne        $3, $4, .L002F0EC0
    /* 1ED5C4 002ED5C4 00000000 */   nop
    /* 1ED5C8 002ED5C8 1C920B0C */  jal        func_002e4870
    /* 1ED5CC 002ED5CC 00000000 */   nop
    /* 1ED5D0 002ED5D0 00004480 */  lb         $4, 0x0($2)
    /* 1ED5D4 002ED5D4 01000324 */  addiu      $3, $0, 0x1
    /* 1ED5D8 002ED5D8 390E8314 */  bne        $4, $3, .L002F0EC0
    /* 1ED5DC 002ED5DC 00000000 */   nop
    /* 1ED5E0 002ED5E0 02000424 */  addiu      $4, $0, 0x2
    /* 1ED5E4 002ED5E4 1C920B0C */  jal        func_002e4870
    /* 1ED5E8 002ED5E8 00000000 */   nop
    /* 1ED5EC 002ED5EC 00004480 */  lb         $4, 0x0($2)
    /* 1ED5F0 002ED5F0 01000324 */  addiu      $3, $0, 0x1
    /* 1ED5F4 002ED5F4 320E8314 */  bne        $4, $3, .L002F0EC0
    /* 1ED5F8 002ED5F8 00000000 */   nop
    /* 1ED5FC 002ED5FC 0D000424 */  addiu      $4, $0, 0xD
    /* 1ED600 002ED600 1C920B0C */  jal        func_002e4870
    /* 1ED604 002ED604 00000000 */   nop
    /* 1ED608 002ED608 00004480 */  lb         $4, 0x0($2)
    /* 1ED60C 002ED60C 01000324 */  addiu      $3, $0, 0x1
    /* 1ED610 002ED610 2B0E8314 */  bne        $4, $3, .L002F0EC0
    /* 1ED614 002ED614 00000000 */   nop
    /* 1ED618 002ED618 2D800000 */  daddu      $16, $0, $0
    /* 1ED61C 002ED61C 18000010 */  b          .L002ED680
    /* 1ED620 002ED620 00000000 */   nop
  .L002ED624:
    /* 1ED624 002ED624 5C02A427 */  addiu      $4, $29, 0x25C
    /* 1ED628 002ED628 2D280000 */  daddu      $5, $0, $0
    /* 1ED62C 002ED62C 2D300000 */  daddu      $6, $0, $0
    /* 1ED630 002ED630 99000724 */  addiu      $7, $0, 0x99
    /* 1ED634 002ED634 FF000824 */  addiu      $8, $0, 0xFF
    /* 1ED638 002ED638 98CA0A0C */  jal        func_002b2a60
    /* 1ED63C 002ED63C 00000000 */   nop
    /* 1ED640 002ED640 3C2E1000 */  dsll32     $5, $16, 24
    /* 1ED644 002ED644 3F2E0500 */  dsra32     $5, $5, 24
    /* 1ED648 002ED648 8801448E */  lw         $4, 0x188($18)
    /* 1ED64C 002ED64C 942B0D0C */  jal        func_0034ae50
    /* 1ED650 002ED650 00000000 */   nop
    /* 1ED654 002ED654 5C02A693 */  lbu        $6, 0x25C($29)
    /* 1ED658 002ED658 5D02A593 */  lbu        $5, 0x25D($29)
    /* 1ED65C 002ED65C 5E02A493 */  lbu        $4, 0x25E($29)
    /* 1ED660 002ED660 5F02A393 */  lbu        $3, 0x25F($29)
    /* 1ED664 002ED664 750046A0 */  sb         $6, 0x75($2)
    /* 1ED668 002ED668 760045A0 */  sb         $5, 0x76($2)
    /* 1ED66C 002ED66C 770044A0 */  sb         $4, 0x77($2)
    /* 1ED670 002ED670 780043A0 */  sb         $3, 0x78($2)
    /* 1ED674 002ED674 01000226 */  addiu      $2, $16, 0x1
    /* 1ED678 002ED678 3C840200 */  dsll32     $16, $2, 16
    /* 1ED67C 002ED67C 3F841000 */  dsra32     $16, $16, 16
  .L002ED680:
    /* 1ED680 002ED680 3C8C1000 */  dsll32     $17, $16, 16
    /* 1ED684 002ED684 3F8C1100 */  dsra32     $17, $17, 16
    /* 1ED688 002ED688 6C2D040C */  jal        func_0010b5b0
    /* 1ED68C 002ED68C 00000000 */   nop
    /* 1ED690 002ED690 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1ED694 002ED694 2A102202 */  slt        $2, $17, $2
    /* 1ED698 002ED698 E2FF4014 */  bnez       $2, .L002ED624
    /* 1ED69C 002ED69C 00000000 */   nop
    /* 1ED6A0 002ED6A0 2D208002 */  daddu      $4, $20, $0
    /* 1ED6A4 002ED6A4 93000524 */  addiu      $5, $0, 0x93
    /* 1ED6A8 002ED6A8 96000624 */  addiu      $6, $0, 0x96
    /* 1ED6AC 002ED6AC 7C810C0C */  jal        func_003205f0
    /* 1ED6B0 002ED6B0 00000000 */   nop
    /* 1ED6B4 002ED6B4 2D208002 */  daddu      $4, $20, $0
    /* 1ED6B8 002ED6B8 2D280000 */  daddu      $5, $0, $0
    /* 1ED6BC 002ED6BC E0820C0C */  jal        func_00320b80
    /* 1ED6C0 002ED6C0 00000000 */   nop
    /* 1ED6C4 002ED6C4 2D208002 */  daddu      $4, $20, $0
    /* 1ED6C8 002ED6C8 01000524 */  addiu      $5, $0, 0x1
    /* 1ED6CC 002ED6CC 2D300000 */  daddu      $6, $0, $0
    /* 1ED6D0 002ED6D0 1C590C0C */  jal        func_00316470
    /* 1ED6D4 002ED6D4 00000000 */   nop
    /* 1ED6D8 002ED6D8 0000A0FF */  sd         $0, 0x0($29)
    /* 1ED6DC 002ED6DC 0800A0FF */  sd         $0, 0x8($29)
    /* 1ED6E0 002ED6E0 1000A0FF */  sd         $0, 0x10($29)
    /* 1ED6E4 002ED6E4 2D208002 */  daddu      $4, $20, $0
    /* 1ED6E8 002ED6E8 2D280000 */  daddu      $5, $0, $0
    /* 1ED6EC 002ED6EC 2D300000 */  daddu      $6, $0, $0
    /* 1ED6F0 002ED6F0 2D380000 */  daddu      $7, $0, $0
    /* 1ED6F4 002ED6F4 2D400000 */  daddu      $8, $0, $0
    /* 1ED6F8 002ED6F8 01000924 */  addiu      $9, $0, 0x1
    /* 1ED6FC 002ED6FC 2D500000 */  daddu      $10, $0, $0
    /* 1ED700 002ED700 2D580000 */  daddu      $11, $0, $0
    /* 1ED704 002ED704 A05B0C0C */  jal        func_00316e80
    /* 1ED708 002ED708 00000000 */   nop
    /* 1ED70C 002ED70C FFFF0324 */  addiu      $3, $0, -0x1
    /* 1ED710 002ED710 290143A2 */  sb         $3, 0x129($18)
    /* 1ED714 002ED714 25000324 */  addiu      $3, $0, 0x25
    /* 1ED718 002ED718 010043A2 */  sb         $3, 0x1($18)
    /* 1ED71C 002ED71C E80D0010 */  b          .L002F0EC0
    /* 1ED720 002ED720 00000000 */   nop
    /* 1ED724 002ED724 27000524 */  addiu      $5, $0, 0x27
    /* 1ED728 002ED728 2D300000 */  daddu      $6, $0, $0
    /* 1ED72C 002ED72C B8840C0C */  jal        func_003212e0
    /* 1ED730 002ED730 00000000 */   nop
    /* 1ED734 002ED734 E20D0010 */  b          .L002F0EC0
    /* 1ED738 002ED738 00000000 */   nop
    /* 1ED73C 002ED73C 2D980000 */  daddu      $19, $0, $0
    /* 1ED740 002ED740 69000010 */  b          .L002ED8E8
    /* 1ED744 002ED744 00000000 */   nop
  .L002ED748:
    /* 1ED748 002ED748 3C8C1300 */  dsll32     $17, $19, 16
    /* 1ED74C 002ED74C 3F8C1100 */  dsra32     $17, $17, 16
    /* 1ED750 002ED750 1C023526 */  addiu      $21, $17, 0x21C
    /* 1ED754 002ED754 3C241500 */  dsll32     $4, $21, 16
    /* 1ED758 002ED758 3F240400 */  dsra32     $4, $4, 16
    /* 1ED75C 002ED75C 54D80A0C */  jal        func_002b6150
    /* 1ED760 002ED760 00000000 */   nop
    /* 1ED764 002ED764 42004284 */  lh         $2, 0x42($2)
    /* 1ED768 002ED768 00008244 */  mtc1       $2, $f0
    /* 1ED76C 002ED76C 00000000 */  nop
    /* 1ED770 002ED770 20058046 */  cvt.s.w    $f20, $f0
    /* 1ED774 002ED774 3C241500 */  dsll32     $4, $21, 16
    /* 1ED778 002ED778 3F240400 */  dsra32     $4, $4, 16
    /* 1ED77C 002ED77C 54D80A0C */  jal        func_002b6150
    /* 1ED780 002ED780 00000000 */   nop
    /* 1ED784 002ED784 40004284 */  lh         $2, 0x40($2)
    /* 1ED788 002ED788 00008244 */  mtc1       $2, $f0
    /* 1ED78C 002ED78C 00000000 */  nop
    /* 1ED790 002ED790 E0038046 */  cvt.s.w    $f15, $f0
    /* 1ED794 002ED794 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1ED798 002ED798 00608244 */  mtc1       $2, $f12
    /* 1ED79C 002ED79C 00688044 */  mtc1       $0, $f13
    /* 1ED7A0 002ED7A0 2D200000 */  daddu      $4, $0, $0
    /* 1ED7A4 002ED7A4 86A30046 */  mov.s      $f14, $f20
    /* 1ED7A8 002ED7A8 A8CA0A0C */  jal        func_002b2aa0
    /* 1ED7AC 002ED7AC 00000000 */   nop
    /* 1ED7B0 002ED7B0 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1ED7B4 002ED7B4 00088244 */  mtc1       $2, $f1
    /* 1ED7B8 002ED7B8 00000000 */  nop
    /* 1ED7BC 002ED7BC 36080046 */  c.le.s     $f1, $f0
    /* 1ED7C0 002ED7C0 07000145 */  bc1t       .L002ED7E0
    /* 1ED7C4 002ED7C4 00000000 */   nop
    /* 1ED7C8 002ED7C8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1ED7CC 002ED7CC 00000344 */  mfc1       $3, $f0
    /* 1ED7D0 002ED7D0 00000000 */  nop
    /* 1ED7D4 002ED7D4 FF006330 */  andi       $3, $3, 0xFF
    /* 1ED7D8 002ED7D8 07000010 */  b          .L002ED7F8
    /* 1ED7DC 002ED7DC 00000000 */   nop
  .L002ED7E0:
    /* 1ED7E0 002ED7E0 01000146 */  sub.s      $f0, $f0, $f1
    /* 1ED7E4 002ED7E4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1ED7E8 002ED7E8 00000344 */  mfc1       $3, $f0
    /* 1ED7EC 002ED7EC 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1ED7F0 002ED7F0 25186200 */  or         $3, $3, $2
    /* 1ED7F4 002ED7F4 FF006330 */  andi       $3, $3, 0xFF
  .L002ED7F8:
    /* 1ED7F8 002ED7F8 FF006730 */  andi       $7, $3, 0xFF
    /* 1ED7FC 002ED7FC 1E014286 */  lh         $2, 0x11E($18)
    /* 1ED800 002ED800 09005114 */  bne        $2, $17, .L002ED828
    /* 1ED804 002ED804 00000000 */   nop
    /* 1ED808 002ED808 2D000424 */  addiu      $4, $0, 0x2D
    /* 1ED80C 002ED80C 2D288000 */  daddu      $5, $4, $0
    /* 1ED810 002ED810 2D308000 */  daddu      $6, $4, $0
    /* 1ED814 002ED814 8CCA0A0C */  jal        func_002b2a30
    /* 1ED818 002ED818 00000000 */   nop
    /* 1ED81C 002ED81C 2D884000 */  daddu      $17, $2, $0
    /* 1ED820 002ED820 07000010 */  b          .L002ED840
    /* 1ED824 002ED824 00000000 */   nop
  .L002ED828:
    /* 1ED828 002ED828 CC000424 */  addiu      $4, $0, 0xCC
    /* 1ED82C 002ED82C FF000524 */  addiu      $5, $0, 0xFF
    /* 1ED830 002ED830 2D30A000 */  daddu      $6, $5, $0
    /* 1ED834 002ED834 8CCA0A0C */  jal        func_002b2a30
    /* 1ED838 002ED838 00000000 */   nop
    /* 1ED83C 002ED83C 2D884000 */  daddu      $17, $2, $0
  .L002ED840:
    /* 1ED840 002ED840 2D200000 */  daddu      $4, $0, $0
    /* 1ED844 002ED844 1C920B0C */  jal        func_002e4870
    /* 1ED848 002ED848 00000000 */   nop
    /* 1ED84C 002ED84C 0800428C */  lw         $2, 0x8($2)
    /* 1ED850 002ED850 2A080202 */  slt        $1, $16, $2
    /* 1ED854 002ED854 21002010 */  beqz       $1, .L002ED8DC
    /* 1ED858 002ED858 00000000 */   nop
    /* 1ED85C 002ED85C 40101000 */  sll        $2, $16, 1
    /* 1ED860 002ED860 21105000 */  addu       $2, $2, $16
    /* 1ED864 002ED864 C0100200 */  sll        $2, $2, 3
    /* 1ED868 002ED868 23105000 */  subu       $2, $2, $16
    /* 1ED86C 002ED86C 80004224 */  addiu      $2, $2, 0x80
    /* 1ED870 002ED870 00008244 */  mtc1       $2, $f0
    /* 1ED874 002ED874 00000000 */  nop
    /* 1ED878 002ED878 20058046 */  cvt.s.w    $f20, $f0
    /* 1ED87C 002ED87C 2D200000 */  daddu      $4, $0, $0
    /* 1ED880 002ED880 2D286002 */  daddu      $5, $19, $0
    /* 1ED884 002ED884 28920B0C */  jal        func_002e48a0
    /* 1ED888 002ED888 00000000 */   nop
    /* 1ED88C 002ED88C 02004394 */  lhu        $3, 0x2($2)
    /* 1ED890 002ED890 00110300 */  sll        $2, $3, 4
    /* 1ED894 002ED894 21184300 */  addu       $3, $2, $3
    /* 1ED898 002ED898 40B4828F */  lw         $2, -0x4BC0($28)
    /* 1ED89C 002ED89C 21384300 */  addu       $7, $2, $3
    /* 1ED8A0 002ED8A0 E242023C */  lui        $2, (0x42E20000 >> 16)
    /* 1ED8A4 002ED8A4 00608244 */  mtc1       $2, $f12
    /* 1ED8A8 002ED8A8 2C42023C */  lui        $2, (0x422C0000 >> 16)
    /* 1ED8AC 002ED8AC 00708244 */  mtc1       $2, $f14
    /* 1ED8B0 002ED8B0 46A30046 */  mov.s      $f13, $f20
    /* 1ED8B4 002ED8B4 2D202002 */  daddu      $4, $17, $0
    /* 1ED8B8 002ED8B8 2D280000 */  daddu      $5, $0, $0
    /* 1ED8BC 002ED8BC 02000624 */  addiu      $6, $0, 0x2
    /* 1ED8C0 002ED8C0 2D400000 */  daddu      $8, $0, $0
    /* 1ED8C4 002ED8C4 2D480000 */  daddu      $9, $0, $0
    /* 1ED8C8 002ED8C8 79000A3C */  lui        $10, %hi(D_00795E60)
    /* 1ED8CC 002ED8CC 605E4A25 */  addiu      $10, $10, %lo(D_00795E60)
    /* 1ED8D0 002ED8D0 15000B24 */  addiu      $11, $0, 0x15
    /* 1ED8D4 002ED8D4 08D6090C */  jal        func_00275820
    /* 1ED8D8 002ED8D8 00000000 */   nop
  .L002ED8DC:
    /* 1ED8DC 002ED8DC 01006226 */  addiu      $2, $19, 0x1
    /* 1ED8E0 002ED8E0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1ED8E4 002ED8E4 3F9C1300 */  dsra32     $19, $19, 16
  .L002ED8E8:
    /* 1ED8E8 002ED8E8 3C841300 */  dsll32     $16, $19, 16
    /* 1ED8EC 002ED8EC 3F841000 */  dsra32     $16, $16, 16
    /* 1ED8F0 002ED8F0 6C2D040C */  jal        func_0010b5b0
    /* 1ED8F4 002ED8F4 00000000 */   nop
    /* 1ED8F8 002ED8F8 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1ED8FC 002ED8FC 2A100202 */  slt        $2, $16, $2
    /* 1ED900 002ED900 91FF4014 */  bnez       $2, .L002ED748
    /* 1ED904 002ED904 00000000 */   nop
    /* 1ED908 002ED908 1C020424 */  addiu      $4, $0, 0x21C
    /* 1ED90C 002ED90C 54D80A0C */  jal        func_002b6150
    /* 1ED910 002ED910 00000000 */   nop
    /* 1ED914 002ED914 10004484 */  lh         $4, 0x10($2)
    /* 1ED918 002ED918 01000524 */  addiu      $5, $0, 0x1
    /* 1ED91C 002ED91C 5CDA0A0C */  jal        func_002b6970
    /* 1ED920 002ED920 00000000 */   nop
    /* 1ED924 002ED924 3C1C0200 */  dsll32     $3, $2, 16
    /* 1ED928 002ED928 3F1C0300 */  dsra32     $3, $3, 16
    /* 1ED92C 002ED92C 640D6014 */  bnez       $3, .L002F0EC0
    /* 1ED930 002ED930 00000000 */   nop
    /* 1ED934 002ED934 93010424 */  addiu      $4, $0, 0x193
    /* 1ED938 002ED938 54D80A0C */  jal        func_002b6150
    /* 1ED93C 002ED93C 00000000 */   nop
    /* 1ED940 002ED940 10004484 */  lh         $4, 0x10($2)
    /* 1ED944 002ED944 01000524 */  addiu      $5, $0, 0x1
    /* 1ED948 002ED948 5CDA0A0C */  jal        func_002b6970
    /* 1ED94C 002ED94C 00000000 */   nop
    /* 1ED950 002ED950 3C1C0200 */  dsll32     $3, $2, 16
    /* 1ED954 002ED954 3F1C0300 */  dsra32     $3, $3, 16
    /* 1ED958 002ED958 590D6014 */  bnez       $3, .L002F0EC0
    /* 1ED95C 002ED95C 00000000 */   nop
    /* 1ED960 002ED960 2D208002 */  daddu      $4, $20, $0
    /* 1ED964 002ED964 96000524 */  addiu      $5, $0, 0x96
    /* 1ED968 002ED968 93000624 */  addiu      $6, $0, 0x93
    /* 1ED96C 002ED96C 7C810C0C */  jal        func_003205f0
    /* 1ED970 002ED970 00000000 */   nop
    /* 1ED974 002ED974 2D208002 */  daddu      $4, $20, $0
    /* 1ED978 002ED978 2D280000 */  daddu      $5, $0, $0
    /* 1ED97C 002ED97C 9CAC0B0C */  jal        func_002eb270
    /* 1ED980 002ED980 00000000 */   nop
    /* 1ED984 002ED984 2D208002 */  daddu      $4, $20, $0
    /* 1ED988 002ED988 2D280000 */  daddu      $5, $0, $0
    /* 1ED98C 002ED98C 80550C0C */  jal        func_00315600
    /* 1ED990 002ED990 00000000 */   nop
    /* 1ED994 002ED994 000040A2 */  sb         $0, 0x0($18)
    /* 1ED998 002ED998 1A000324 */  addiu      $3, $0, 0x1A
    /* 1ED99C 002ED99C 010043A2 */  sb         $3, 0x1($18)
    /* 1ED9A0 002ED9A0 470D0010 */  b          .L002F0EC0
    /* 1ED9A4 002ED9A4 00000000 */   nop
    /* 1ED9A8 002ED9A8 4801448E */  lw         $4, 0x148($18)
    /* 1ED9AC 002ED9AC 98510C0C */  jal        func_00314660
    /* 1ED9B0 002ED9B0 00000000 */   nop
    /* 1ED9B4 002ED9B4 3C160200 */  dsll32     $2, $2, 24
    /* 1ED9B8 002ED9B8 3F160200 */  dsra32     $2, $2, 24
    /* 1ED9BC 002ED9BC 09004004 */  bltz       $2, .L002ED9E4
    /* 1ED9C0 002ED9C0 00000000 */   nop
    /* 1ED9C4 002ED9C4 4801448E */  lw         $4, 0x148($18)
    /* 1ED9C8 002ED9C8 98510C0C */  jal        func_00314660
    /* 1ED9CC 002ED9CC 00000000 */   nop
    /* 1ED9D0 002ED9D0 3C1E0200 */  dsll32     $3, $2, 24
    /* 1ED9D4 002ED9D4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1ED9D8 002ED9D8 06006128 */  slti       $1, $3, 0x6
    /* 1ED9DC 002ED9DC 380D2014 */  bnez       $1, .L002F0EC0
    /* 1ED9E0 002ED9E0 00000000 */   nop
  .L002ED9E4:
    /* 1ED9E4 002ED9E4 2D208002 */  daddu      $4, $20, $0
    /* 1ED9E8 002ED9E8 2D280000 */  daddu      $5, $0, $0
    /* 1ED9EC 002ED9EC 2A000624 */  addiu      $6, $0, 0x2A
    /* 1ED9F0 002ED9F0 26000724 */  addiu      $7, $0, 0x26
    /* 1ED9F4 002ED9F4 98870C0C */  jal        func_00321e60
    /* 1ED9F8 002ED9F8 00000000 */   nop
    /* 1ED9FC 002ED9FC 300D0010 */  b          .L002F0EC0
    /* 1EDA00 002EDA00 00000000 */   nop
    /* 1EDA04 002EDA04 1C020424 */  addiu      $4, $0, 0x21C
    /* 1EDA08 002EDA08 54D80A0C */  jal        func_002b6150
    /* 1EDA0C 002EDA0C 00000000 */   nop
    /* 1EDA10 002EDA10 10004484 */  lh         $4, 0x10($2)
    /* 1EDA14 002EDA14 01000524 */  addiu      $5, $0, 0x1
    /* 1EDA18 002EDA18 5CDA0A0C */  jal        func_002b6970
    /* 1EDA1C 002EDA1C 00000000 */   nop
    /* 1EDA20 002EDA20 3C240200 */  dsll32     $4, $2, 16
    /* 1EDA24 002EDA24 3F240400 */  dsra32     $4, $4, 16
    /* 1EDA28 002EDA28 01000324 */  addiu      $3, $0, 0x1
    /* 1EDA2C 002EDA2C 240D8310 */  beq        $4, $3, .L002F0EC0
    /* 1EDA30 002EDA30 00000000 */   nop
    /* 1EDA34 002EDA34 2D200000 */  daddu      $4, $0, $0
    /* 1EDA38 002EDA38 1E014586 */  lh         $5, 0x11E($18)
    /* 1EDA3C 002EDA3C 28920B0C */  jal        func_002e48a0
    /* 1EDA40 002EDA40 00000000 */   nop
    /* 1EDA44 002EDA44 4801448E */  lw         $4, 0x148($18)
    /* 1EDA48 002EDA48 2D284000 */  daddu      $5, $2, $0
    /* 1EDA4C 002EDA4C 2D300000 */  daddu      $6, $0, $0
    /* 1EDA50 002EDA50 2D380000 */  daddu      $7, $0, $0
    /* 1EDA54 002EDA54 14510C0C */  jal        func_00314450
    /* 1EDA58 002EDA58 00000000 */   nop
    /* 1EDA5C 002EDA5C 4801448E */  lw         $4, 0x148($18)
    /* 1EDA60 002EDA60 F4510C0C */  jal        func_003147d0
    /* 1EDA64 002EDA64 00000000 */   nop
    /* 1EDA68 002EDA68 2D204000 */  daddu      $4, $2, $0
    /* 1EDA6C 002EDA6C 01000524 */  addiu      $5, $0, 0x1
    /* 1EDA70 002EDA70 B871040C */  jal        func_0011c6e0
    /* 1EDA74 002EDA74 00000000 */   nop
    /* 1EDA78 002EDA78 4801448E */  lw         $4, 0x148($18)
    /* 1EDA7C 002EDA7C F4510C0C */  jal        func_003147d0
    /* 1EDA80 002EDA80 00000000 */   nop
    /* 1EDA84 002EDA84 2D804000 */  daddu      $16, $2, $0
    /* 1EDA88 002EDA88 FF000424 */  addiu      $4, $0, 0xFF
    /* 1EDA8C 002EDA8C 2D288000 */  daddu      $5, $4, $0
    /* 1EDA90 002EDA90 2D308000 */  daddu      $6, $4, $0
    /* 1EDA94 002EDA94 2D388000 */  daddu      $7, $4, $0
    /* 1EDA98 002EDA98 8CCA0A0C */  jal        func_002b2a30
    /* 1EDA9C 002EDA9C 00000000 */   nop
    /* 1EDAA0 002EDAA0 2D200002 */  daddu      $4, $16, $0
    /* 1EDAA4 002EDAA4 2D284000 */  daddu      $5, $2, $0
    /* 1EDAA8 002EDAA8 5074040C */  jal        func_0011d140
    /* 1EDAAC 002EDAAC 00000000 */   nop
    /* 1EDAB0 002EDAB0 29000324 */  addiu      $3, $0, 0x29
    /* 1EDAB4 002EDAB4 010043A2 */  sb         $3, 0x1($18)
    /* 1EDAB8 002EDAB8 010D0010 */  b          .L002F0EC0
    /* 1EDABC 002EDABC 00000000 */   nop
    /* 1EDAC0 002EDAC0 4801448E */  lw         $4, 0x148($18)
    /* 1EDAC4 002EDAC4 98510C0C */  jal        func_00314660
    /* 1EDAC8 002EDAC8 00000000 */   nop
    /* 1EDACC 002EDACC 3C1E0200 */  dsll32     $3, $2, 24
    /* 1EDAD0 002EDAD0 3F1E0300 */  dsra32     $3, $3, 24
    /* 1EDAD4 002EDAD4 05000224 */  addiu      $2, $0, 0x5
    /* 1EDAD8 002EDAD8 78006214 */  bne        $3, $2, .L002EDCBC
    /* 1EDADC 002EDADC 00000000 */   nop
    /* 1EDAE0 002EDAE0 4801448E */  lw         $4, 0x148($18)
    /* 1EDAE4 002EDAE4 F4510C0C */  jal        func_003147d0
    /* 1EDAE8 002EDAE8 00000000 */   nop
    /* 1EDAEC 002EDAEC 2D204000 */  daddu      $4, $2, $0
    /* 1EDAF0 002EDAF0 8471040C */  jal        func_0011c610
    /* 1EDAF4 002EDAF4 00000000 */   nop
    /* 1EDAF8 002EDAF8 01000324 */  addiu      $3, $0, 0x1
    /* 1EDAFC 002EDAFC 07004314 */  bne        $2, $3, .L002EDB1C
    /* 1EDB00 002EDB00 00000000 */   nop
    /* 1EDB04 002EDB04 4801448E */  lw         $4, 0x148($18)
    /* 1EDB08 002EDB08 F4510C0C */  jal        func_003147d0
    /* 1EDB0C 002EDB0C 00000000 */   nop
    /* 1EDB10 002EDB10 2D204000 */  daddu      $4, $2, $0
    /* 1EDB14 002EDB14 BC72040C */  jal        func_0011caf0
    /* 1EDB18 002EDB18 00000000 */   nop
  .L002EDB1C:
    /* 1EDB1C 002EDB1C 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 1EDB20 002EDB20 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 1EDB24 002EDB24 80006230 */  andi       $2, $3, 0x80
    /* 1EDB28 002EDB28 22004010 */  beqz       $2, .L002EDBB4
    /* 1EDB2C 002EDB2C 00000000 */   nop
    /* 1EDB30 002EDB30 4801448E */  lw         $4, 0x148($18)
    /* 1EDB34 002EDB34 F4510C0C */  jal        func_003147d0
    /* 1EDB38 002EDB38 00000000 */   nop
    /* 1EDB3C 002EDB3C 2D204000 */  daddu      $4, $2, $0
    /* 1EDB40 002EDB40 8471040C */  jal        func_0011c610
    /* 1EDB44 002EDB44 00000000 */   nop
    /* 1EDB48 002EDB48 0D004014 */  bnez       $2, .L002EDB80
    /* 1EDB4C 002EDB4C 00000000 */   nop
    /* 1EDB50 002EDB50 4801448E */  lw         $4, 0x148($18)
    /* 1EDB54 002EDB54 F4510C0C */  jal        func_003147d0
    /* 1EDB58 002EDB58 00000000 */   nop
    /* 1EDB5C 002EDB5C 2D204000 */  daddu      $4, $2, $0
    /* 1EDB60 002EDB60 8C71040C */  jal        func_0011c630
    /* 1EDB64 002EDB64 00000000 */   nop
    /* 1EDB68 002EDB68 4801448E */  lw         $4, 0x148($18)
    /* 1EDB6C 002EDB6C 2D280000 */  daddu      $5, $0, $0
    /* 1EDB70 002EDB70 D0510C0C */  jal        func_00314740
    /* 1EDB74 002EDB74 00000000 */   nop
    /* 1EDB78 002EDB78 50000010 */  b          .L002EDCBC
    /* 1EDB7C 002EDB7C 00000000 */   nop
  .L002EDB80:
    /* 1EDB80 002EDB80 4801448E */  lw         $4, 0x148($18)
    /* 1EDB84 002EDB84 F4510C0C */  jal        func_003147d0
    /* 1EDB88 002EDB88 00000000 */   nop
    /* 1EDB8C 002EDB8C 2D204000 */  daddu      $4, $2, $0
    /* 1EDB90 002EDB90 01000524 */  addiu      $5, $0, 0x1
    /* 1EDB94 002EDB94 B871040C */  jal        func_0011c6e0
    /* 1EDB98 002EDB98 00000000 */   nop
    /* 1EDB9C 002EDB9C 4801448E */  lw         $4, 0x148($18)
    /* 1EDBA0 002EDBA0 01000524 */  addiu      $5, $0, 0x1
    /* 1EDBA4 002EDBA4 D0510C0C */  jal        func_00314740
    /* 1EDBA8 002EDBA8 00000000 */   nop
    /* 1EDBAC 002EDBAC 43000010 */  b          .L002EDCBC
    /* 1EDBB0 002EDBB0 00000000 */   nop
  .L002EDBB4:
    /* 1EDBB4 002EDBB4 20006230 */  andi       $2, $3, 0x20
    /* 1EDBB8 002EDBB8 40004010 */  beqz       $2, .L002EDCBC
    /* 1EDBBC 002EDBBC 00000000 */   nop
    /* 1EDBC0 002EDBC0 4801448E */  lw         $4, 0x148($18)
    /* 1EDBC4 002EDBC4 F4510C0C */  jal        func_003147d0
    /* 1EDBC8 002EDBC8 00000000 */   nop
    /* 1EDBCC 002EDBCC 2D204000 */  daddu      $4, $2, $0
    /* 1EDBD0 002EDBD0 8471040C */  jal        func_0011c610
    /* 1EDBD4 002EDBD4 00000000 */   nop
    /* 1EDBD8 002EDBD8 01000324 */  addiu      $3, $0, 0x1
    /* 1EDBDC 002EDBDC 0E004314 */  bne        $2, $3, .L002EDC18
    /* 1EDBE0 002EDBE0 00000000 */   nop
    /* 1EDBE4 002EDBE4 4801448E */  lw         $4, 0x148($18)
    /* 1EDBE8 002EDBE8 F4510C0C */  jal        func_003147d0
    /* 1EDBEC 002EDBEC 00000000 */   nop
    /* 1EDBF0 002EDBF0 2D204000 */  daddu      $4, $2, $0
    /* 1EDBF4 002EDBF4 01000524 */  addiu      $5, $0, 0x1
    /* 1EDBF8 002EDBF8 B871040C */  jal        func_0011c6e0
    /* 1EDBFC 002EDBFC 00000000 */   nop
    /* 1EDC00 002EDC00 4801448E */  lw         $4, 0x148($18)
    /* 1EDC04 002EDC04 01000524 */  addiu      $5, $0, 0x1
    /* 1EDC08 002EDC08 D0510C0C */  jal        func_00314740
    /* 1EDC0C 002EDC0C 00000000 */   nop
    /* 1EDC10 002EDC10 2A000010 */  b          .L002EDCBC
    /* 1EDC14 002EDC14 00000000 */   nop
  .L002EDC18:
    /* 1EDC18 002EDC18 4801448E */  lw         $4, 0x148($18)
    /* 1EDC1C 002EDC1C 98510C0C */  jal        func_00314660
    /* 1EDC20 002EDC20 00000000 */   nop
    /* 1EDC24 002EDC24 3C260200 */  dsll32     $4, $2, 24
    /* 1EDC28 002EDC28 3F260400 */  dsra32     $4, $4, 24
    /* 1EDC2C 002EDC2C 05000324 */  addiu      $3, $0, 0x5
    /* 1EDC30 002EDC30 A30C8314 */  bne        $4, $3, .L002F0EC0
    /* 1EDC34 002EDC34 00000000 */   nop
    /* 1EDC38 002EDC38 2D200000 */  daddu      $4, $0, $0
    /* 1EDC3C 002EDC3C 01000524 */  addiu      $5, $0, 0x1
    /* 1EDC40 002EDC40 2D300000 */  daddu      $6, $0, $0
    /* 1EDC44 002EDC44 04000724 */  addiu      $7, $0, 0x4
    /* 1EDC48 002EDC48 D86B110C */  jal        func_0045af60
    /* 1EDC4C 002EDC4C 00000000 */   nop
    /* 1EDC50 002EDC50 4801448E */  lw         $4, 0x148($18)
    /* 1EDC54 002EDC54 03000524 */  addiu      $5, $0, 0x3
    /* 1EDC58 002EDC58 9C510C0C */  jal        func_00314670
    /* 1EDC5C 002EDC5C 00000000 */   nop
    /* 1EDC60 002EDC60 E4010424 */  addiu      $4, $0, 0x1E4
    /* 1EDC64 002EDC64 54D80A0C */  jal        func_002b6150
    /* 1EDC68 002EDC68 00000000 */   nop
    /* 1EDC6C 002EDC6C 10004484 */  lh         $4, 0x10($2)
    /* 1EDC70 002EDC70 2D280000 */  daddu      $5, $0, $0
    /* 1EDC74 002EDC74 5CDA0A0C */  jal        func_002b6970
    /* 1EDC78 002EDC78 00000000 */   nop
    /* 1EDC7C 002EDC7C 3C1C0200 */  dsll32     $3, $2, 16
    /* 1EDC80 002EDC80 3F1C0300 */  dsra32     $3, $3, 16
    /* 1EDC84 002EDC84 01000224 */  addiu      $2, $0, 0x1
    /* 1EDC88 002EDC88 0C006214 */  bne        $3, $2, .L002EDCBC
    /* 1EDC8C 002EDC8C 00000000 */   nop
    /* 1EDC90 002EDC90 E4010424 */  addiu      $4, $0, 0x1E4
    /* 1EDC94 002EDC94 54D80A0C */  jal        func_002b6150
    /* 1EDC98 002EDC98 00000000 */   nop
    /* 1EDC9C 002EDC9C E4010424 */  addiu      $4, $0, 0x1E4
    /* 1EDCA0 002EDCA0 6E004590 */  lbu        $5, 0x6E($2)
    /* 1EDCA4 002EDCA4 2D300000 */  daddu      $6, $0, $0
    /* 1EDCA8 002EDCA8 2D380000 */  daddu      $7, $0, $0
    /* 1EDCAC 002EDCAC 0A000824 */  addiu      $8, $0, 0xA
    /* 1EDCB0 002EDCB0 2D480000 */  daddu      $9, $0, $0
    /* 1EDCB4 002EDCB4 9CDA0A0C */  jal        func_002b6a70
    /* 1EDCB8 002EDCB8 00000000 */   nop
  .L002EDCBC:
    /* 1EDCBC 002EDCBC 4801448E */  lw         $4, 0x148($18)
    /* 1EDCC0 002EDCC0 98510C0C */  jal        func_00314660
    /* 1EDCC4 002EDCC4 00000000 */   nop
    /* 1EDCC8 002EDCC8 3C160200 */  dsll32     $2, $2, 24
    /* 1EDCCC 002EDCCC 3F160200 */  dsra32     $2, $2, 24
    /* 1EDCD0 002EDCD0 09004004 */  bltz       $2, .L002EDCF8
    /* 1EDCD4 002EDCD4 00000000 */   nop
    /* 1EDCD8 002EDCD8 4801448E */  lw         $4, 0x148($18)
    /* 1EDCDC 002EDCDC 98510C0C */  jal        func_00314660
    /* 1EDCE0 002EDCE0 00000000 */   nop
    /* 1EDCE4 002EDCE4 3C1E0200 */  dsll32     $3, $2, 24
    /* 1EDCE8 002EDCE8 3F1E0300 */  dsra32     $3, $3, 24
    /* 1EDCEC 002EDCEC 06006128 */  slti       $1, $3, 0x6
    /* 1EDCF0 002EDCF0 730C2014 */  bnez       $1, .L002F0EC0
    /* 1EDCF4 002EDCF4 00000000 */   nop
  .L002EDCF8:
    /* 1EDCF8 002EDCF8 2D800000 */  daddu      $16, $0, $0
    /* 1EDCFC 002EDCFC 23000010 */  b          .L002EDD8C
    /* 1EDD00 002EDD00 00000000 */   nop
  .L002EDD04:
    /* 1EDD04 002EDD04 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EDD08 002EDD08 00608244 */  mtc1       $2, $f12
    /* 1EDD0C 002EDD0C 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EDD10 002EDD10 00688244 */  mtc1       $2, $f13
    /* 1EDD14 002EDD14 2802A427 */  addiu      $4, $29, 0x228
    /* 1EDD18 002EDD18 5CCA0A0C */  jal        func_002b2970
    /* 1EDD1C 002EDD1C 00000000 */   nop
    /* 1EDD20 002EDD20 2D200000 */  daddu      $4, $0, $0
    /* 1EDD24 002EDD24 2D280002 */  daddu      $5, $16, $0
    /* 1EDD28 002EDD28 28920B0C */  jal        func_002e48a0
    /* 1EDD2C 002EDD2C 00000000 */   nop
    /* 1EDD30 002EDD30 02005394 */  lhu        $19, 0x2($2)
    /* 1EDD34 002EDD34 2D200000 */  daddu      $4, $0, $0
    /* 1EDD38 002EDD38 2D280002 */  daddu      $5, $16, $0
    /* 1EDD3C 002EDD3C 28920B0C */  jal        func_002e48a0
    /* 1EDD40 002EDD40 00000000 */   nop
    /* 1EDD44 002EDD44 04005190 */  lbu        $17, 0x4($2)
    /* 1EDD48 002EDD48 2D200000 */  daddu      $4, $0, $0
    /* 1EDD4C 002EDD4C 1C920B0C */  jal        func_002e4870
    /* 1EDD50 002EDD50 00000000 */   nop
    /* 1EDD54 002EDD54 08004B80 */  lb         $11, 0x8($2)
    /* 1EDD58 002EDD58 3C361000 */  dsll32     $6, $16, 24
    /* 1EDD5C 002EDD5C 3F360600 */  dsra32     $6, $6, 24
    /* 1EDD60 002EDD60 2D208002 */  daddu      $4, $20, $0
    /* 1EDD64 002EDD64 2802A5DF */  ld         $5, 0x228($29)
    /* 1EDD68 002EDD68 2D386002 */  daddu      $7, $19, $0
    /* 1EDD6C 002EDD6C 2D402002 */  daddu      $8, $17, $0
    /* 1EDD70 002EDD70 2D480000 */  daddu      $9, $0, $0
    /* 1EDD74 002EDD74 2D500000 */  daddu      $10, $0, $0
    /* 1EDD78 002EDD78 70640C0C */  jal        func_003191c0
    /* 1EDD7C 002EDD7C 00000000 */   nop
    /* 1EDD80 002EDD80 01000226 */  addiu      $2, $16, 0x1
    /* 1EDD84 002EDD84 3C840200 */  dsll32     $16, $2, 16
    /* 1EDD88 002EDD88 3F841000 */  dsra32     $16, $16, 16
  .L002EDD8C:
    /* 1EDD8C 002EDD8C 3C8C1000 */  dsll32     $17, $16, 16
    /* 1EDD90 002EDD90 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EDD94 002EDD94 6C2D040C */  jal        func_0010b5b0
    /* 1EDD98 002EDD98 00000000 */   nop
    /* 1EDD9C 002EDD9C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1EDDA0 002EDDA0 2A102202 */  slt        $2, $17, $2
    /* 1EDDA4 002EDDA4 D7FF4014 */  bnez       $2, .L002EDD04
    /* 1EDDA8 002EDDA8 00000000 */   nop
    /* 1EDDAC 002EDDAC 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EDDB0 002EDDB0 00608244 */  mtc1       $2, $f12
    /* 1EDDB4 002EDDB4 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EDDB8 002EDDB8 00688244 */  mtc1       $2, $f13
    /* 1EDDBC 002EDDBC 2002A427 */  addiu      $4, $29, 0x220
    /* 1EDDC0 002EDDC0 5CCA0A0C */  jal        func_002b2970
    /* 1EDDC4 002EDDC4 00000000 */   nop
    /* 1EDDC8 002EDDC8 2D208002 */  daddu      $4, $20, $0
    /* 1EDDCC 002EDDCC 2002A5DF */  ld         $5, 0x220($29)
    /* 1EDDD0 002EDDD0 2D300000 */  daddu      $6, $0, $0
    /* 1EDDD4 002EDDD4 2D380000 */  daddu      $7, $0, $0
    /* 1EDDD8 002EDDD8 2D400000 */  daddu      $8, $0, $0
    /* 1EDDDC 002EDDDC 2D480000 */  daddu      $9, $0, $0
    /* 1EDDE0 002EDDE0 2D500000 */  daddu      $10, $0, $0
    /* 1EDDE4 002EDDE4 6C790C0C */  jal        func_0031e5b0
    /* 1EDDE8 002EDDE8 00000000 */   nop
    /* 1EDDEC 002EDDEC 0000A0FF */  sd         $0, 0x0($29)
    /* 1EDDF0 002EDDF0 0800A0FF */  sd         $0, 0x8($29)
    /* 1EDDF4 002EDDF4 1000A0FF */  sd         $0, 0x10($29)
    /* 1EDDF8 002EDDF8 2D208002 */  daddu      $4, $20, $0
    /* 1EDDFC 002EDDFC 01000524 */  addiu      $5, $0, 0x1
    /* 1EDE00 002EDE00 2D300000 */  daddu      $6, $0, $0
    /* 1EDE04 002EDE04 2D380000 */  daddu      $7, $0, $0
    /* 1EDE08 002EDE08 2D400000 */  daddu      $8, $0, $0
    /* 1EDE0C 002EDE0C 2D48A000 */  daddu      $9, $5, $0
    /* 1EDE10 002EDE10 2D500000 */  daddu      $10, $0, $0
    /* 1EDE14 002EDE14 2D580000 */  daddu      $11, $0, $0
    /* 1EDE18 002EDE18 A05B0C0C */  jal        func_00316e80
    /* 1EDE1C 002EDE1C 00000000 */   nop
    /* 1EDE20 002EDE20 2D208002 */  daddu      $4, $20, $0
    /* 1EDE24 002EDE24 2D280000 */  daddu      $5, $0, $0
    /* 1EDE28 002EDE28 28860C0C */  jal        func_003218a0
    /* 1EDE2C 002EDE2C 00000000 */   nop
    /* 1EDE30 002EDE30 8C02448E */  lw         $4, 0x28C($18)
    /* 1EDE34 002EDE34 2D280000 */  daddu      $5, $0, $0
    /* 1EDE38 002EDE38 50D80A0C */  jal        func_002b6140
    /* 1EDE3C 002EDE3C 00000000 */   nop
    /* 1EDE40 002EDE40 9002448E */  lw         $4, 0x290($18)
    /* 1EDE44 002EDE44 2D280000 */  daddu      $5, $0, $0
    /* 1EDE48 002EDE48 50D80A0C */  jal        func_002b6140
    /* 1EDE4C 002EDE4C 00000000 */   nop
    /* 1EDE50 002EDE50 27000324 */  addiu      $3, $0, 0x27
    /* 1EDE54 002EDE54 010043A2 */  sb         $3, 0x1($18)
    /* 1EDE58 002EDE58 190C0010 */  b          .L002F0EC0
    /* 1EDE5C 002EDE5C 00000000 */   nop
    /* 1EDE60 002EDE60 7C000424 */  addiu      $4, $0, 0x7C
    /* 1EDE64 002EDE64 54D80A0C */  jal        func_002b6150
    /* 1EDE68 002EDE68 00000000 */   nop
    /* 1EDE6C 002EDE6C 6E005090 */  lbu        $16, 0x6E($2)
    /* 1EDE70 002EDE70 3800918E */  lw         $17, 0x38($20)
    /* 1EDE74 002EDE74 7C000424 */  addiu      $4, $0, 0x7C
    /* 1EDE78 002EDE78 54D80A0C */  jal        func_002b6150
    /* 1EDE7C 002EDE7C 00000000 */   nop
    /* 1EDE80 002EDE80 380041C4 */  lwc1       $f1, 0x38($2)
    /* 1EDE84 002EDE84 3C0040C4 */  lwc1       $f0, 0x3C($2)
    /* 1EDE88 002EDE88 5801A1E7 */  swc1       $f1, 0x158($29)
    /* 1EDE8C 002EDE8C 5C01A0E7 */  swc1       $f0, 0x15C($29)
    /* 1EDE90 002EDE90 CC000424 */  addiu      $4, $0, 0xCC
    /* 1EDE94 002EDE94 FF000524 */  addiu      $5, $0, 0xFF
    /* 1EDE98 002EDE98 2D30A000 */  daddu      $6, $5, $0
    /* 1EDE9C 002EDE9C 2D380002 */  daddu      $7, $16, $0
    /* 1EDEA0 002EDEA0 8CCA0A0C */  jal        func_002b2a30
    /* 1EDEA4 002EDEA4 00000000 */   nop
    /* 1EDEA8 002EDEA8 2D804000 */  daddu      $16, $2, $0
    /* 1EDEAC 002EDEAC 28012582 */  lb         $5, 0x128($17)
    /* 1EDEB0 002EDEB0 2D200000 */  daddu      $4, $0, $0
    /* 1EDEB4 002EDEB4 28920B0C */  jal        func_002e48a0
    /* 1EDEB8 002EDEB8 00000000 */   nop
    /* 1EDEBC 002EDEBC 02004394 */  lhu        $3, 0x2($2)
    /* 1EDEC0 002EDEC0 00110300 */  sll        $2, $3, 4
    /* 1EDEC4 002EDEC4 21184300 */  addu       $3, $2, $3
    /* 1EDEC8 002EDEC8 40B4828F */  lw         $2, -0x4BC0($28)
    /* 1EDECC 002EDECC 21384300 */  addu       $7, $2, $3
    /* 1EDED0 002EDED0 DE42023C */  lui        $2, (0x42DE0000 >> 16)
    /* 1EDED4 002EDED4 00088244 */  mtc1       $2, $f1
    /* 1EDED8 002EDED8 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* 1EDEDC 002EDEDC 000B0046 */  add.s      $f12, $f1, $f0
    /* 1EDEE0 002EDEE0 2C42023C */  lui        $2, (0x422C0000 >> 16)
    /* 1EDEE4 002EDEE4 00708244 */  mtc1       $2, $f14
    /* 1EDEE8 002EDEE8 5C01ADC7 */  lwc1       $f13, 0x15C($29)
    /* 1EDEEC 002EDEEC 2D200002 */  daddu      $4, $16, $0
    /* 1EDEF0 002EDEF0 2D280000 */  daddu      $5, $0, $0
    /* 1EDEF4 002EDEF4 02000624 */  addiu      $6, $0, 0x2
    /* 1EDEF8 002EDEF8 2D400000 */  daddu      $8, $0, $0
    /* 1EDEFC 002EDEFC 2D480000 */  daddu      $9, $0, $0
    /* 1EDF00 002EDF00 79000A3C */  lui        $10, %hi(D_00795E60)
    /* 1EDF04 002EDF04 605E4A25 */  addiu      $10, $10, %lo(D_00795E60)
    /* 1EDF08 002EDF08 15000B24 */  addiu      $11, $0, 0x15
    /* 1EDF0C 002EDF0C 08D6090C */  jal        func_00275820
    /* 1EDF10 002EDF10 00000000 */   nop
    /* 1EDF14 002EDF14 2D980000 */  daddu      $19, $0, $0
    /* 1EDF18 002EDF18 FA010010 */  b          .L002EE704
    /* 1EDF1C 002EDF1C 00000000 */   nop
  .L002EDF20:
    /* 1EDF20 002EDF20 3C2E1300 */  dsll32     $5, $19, 24
    /* 1EDF24 002EDF24 3F2E0500 */  dsra32     $5, $5, 24
    /* 1EDF28 002EDF28 29014782 */  lb         $7, 0x129($18)
    /* 1EDF2C 002EDF2C 2D208002 */  daddu      $4, $20, $0
    /* 1EDF30 002EDF30 28014682 */  lb         $6, 0x128($18)
    /* 1EDF34 002EDF34 2D400000 */  daddu      $8, $0, $0
    /* 1EDF38 002EDF38 8C750C0C */  jal        func_0031d630
    /* 1EDF3C 002EDF3C 00000000 */   nop
    /* 1EDF40 002EDF40 28014282 */  lb         $2, 0x128($18)
    /* 1EDF44 002EDF44 EC015010 */  beq        $2, $16, .L002EE6F8
    /* 1EDF48 002EDF48 00000000 */   nop
    /* 1EDF4C 002EDF4C 2D200000 */  daddu      $4, $0, $0
    /* 1EDF50 002EDF50 1C920B0C */  jal        func_002e4870
    /* 1EDF54 002EDF54 00000000 */   nop
    /* 1EDF58 002EDF58 28014482 */  lb         $4, 0x128($18)
    /* 1EDF5C 002EDF5C 40180400 */  sll        $3, $4, 1
    /* 1EDF60 002EDF60 21186400 */  addu       $3, $3, $4
    /* 1EDF64 002EDF64 80180300 */  sll        $3, $3, 2
    /* 1EDF68 002EDF68 21104300 */  addu       $2, $2, $3
    /* 1EDF6C 002EDF6C 21105000 */  addu       $2, $2, $16
    /* 1EDF70 002EDF70 14004280 */  lb         $2, 0x14($2)
    /* 1EDF74 002EDF74 E0014018 */  blez       $2, .L002EE6F8
    /* 1EDF78 002EDF78 00000000 */   nop
    /* 1EDF7C 002EDF7C 3C8C1300 */  dsll32     $17, $19, 16
    /* 1EDF80 002EDF80 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EDF84 002EDF84 70023726 */  addiu      $23, $17, 0x270
    /* 1EDF88 002EDF88 3C241700 */  dsll32     $4, $23, 16
    /* 1EDF8C 002EDF8C 3F240400 */  dsra32     $4, $4, 16
    /* 1EDF90 002EDF90 54D80A0C */  jal        func_002b6150
    /* 1EDF94 002EDF94 00000000 */   nop
    /* 1EDF98 002EDF98 42004284 */  lh         $2, 0x42($2)
    /* 1EDF9C 002EDF9C 00008244 */  mtc1       $2, $f0
    /* 1EDFA0 002EDFA0 00000000 */  nop
    /* 1EDFA4 002EDFA4 20058046 */  cvt.s.w    $f20, $f0
    /* 1EDFA8 002EDFA8 3C241700 */  dsll32     $4, $23, 16
    /* 1EDFAC 002EDFAC 3F240400 */  dsra32     $4, $4, 16
    /* 1EDFB0 002EDFB0 54D80A0C */  jal        func_002b6150
    /* 1EDFB4 002EDFB4 00000000 */   nop
    /* 1EDFB8 002EDFB8 40004284 */  lh         $2, 0x40($2)
    /* 1EDFBC 002EDFBC 00008244 */  mtc1       $2, $f0
    /* 1EDFC0 002EDFC0 00000000 */  nop
    /* 1EDFC4 002EDFC4 E0038046 */  cvt.s.w    $f15, $f0
    /* 1EDFC8 002EDFC8 00608044 */  mtc1       $0, $f12
    /* 1EDFCC 002EDFCC 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 1EDFD0 002EDFD0 00688244 */  mtc1       $2, $f13
    /* 1EDFD4 002EDFD4 2D200000 */  daddu      $4, $0, $0
    /* 1EDFD8 002EDFD8 86A30046 */  mov.s      $f14, $f20
    /* 1EDFDC 002EDFDC A8CA0A0C */  jal        func_002b2aa0
    /* 1EDFE0 002EDFE0 00000000 */   nop
    /* 1EDFE4 002EDFE4 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 1EDFE8 002EDFE8 00088244 */  mtc1       $2, $f1
    /* 1EDFEC 002EDFEC 00000000 */  nop
    /* 1EDFF0 002EDFF0 36080046 */  c.le.s     $f1, $f0
    /* 1EDFF4 002EDFF4 07000145 */  bc1t       .L002EE014
    /* 1EDFF8 002EDFF8 00000000 */   nop
    /* 1EDFFC 002EDFFC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1EE000 002EE000 00000344 */  mfc1       $3, $f0
    /* 1EE004 002EE004 00000000 */  nop
    /* 1EE008 002EE008 FF006330 */  andi       $3, $3, 0xFF
    /* 1EE00C 002EE00C 07000010 */  b          .L002EE02C
    /* 1EE010 002EE010 00000000 */   nop
  .L002EE014:
    /* 1EE014 002EE014 01000146 */  sub.s      $f0, $f0, $f1
    /* 1EE018 002EE018 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1EE01C 002EE01C 00000344 */  mfc1       $3, $f0
    /* 1EE020 002EE020 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 1EE024 002EE024 25186200 */  or         $3, $3, $2
    /* 1EE028 002EE028 FF006330 */  andi       $3, $3, 0xFF
  .L002EE02C:
    /* 1EE02C 002EE02C FF006230 */  andi       $2, $3, 0xFF
    /* 1EE030 002EE030 E000A2A3 */  sb         $2, 0xE0($29)
    /* 1EE034 002EE034 1E014286 */  lh         $2, 0x11E($18)
    /* 1EE038 002EE038 9E002216 */  bne        $17, $2, .L002EE2B4
    /* 1EE03C 002EE03C 00000000 */   nop
    /* 1EE040 002EE040 3C8C1300 */  dsll32     $17, $19, 16
    /* 1EE044 002EE044 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EE048 002EE048 7D023E26 */  addiu      $30, $17, 0x27D
    /* 1EE04C 002EE04C 70022226 */  addiu      $2, $17, 0x270
    /* 1EE050 002EE050 D000A27F */  sq         $2, 0xD0($29)
    /* 1EE054 002EE054 FF001524 */  addiu      $21, $0, 0xFF
    /* 1EE058 002EE058 3C241E00 */  dsll32     $4, $30, 16
    /* 1EE05C 002EE05C 3F240400 */  dsra32     $4, $4, 16
    /* 1EE060 002EE060 54D80A0C */  jal        func_002b6150
    /* 1EE064 002EE064 00000000 */   nop
    /* 1EE068 002EE068 6E0055A0 */  sb         $21, 0x6E($2)
    /* 1EE06C 002EE06C FF00B532 */  andi       $21, $21, 0xFF
    /* 1EE070 002EE070 D000A27B */  lq         $2, 0xD0($29)
    /* 1EE074 002EE074 3C240200 */  dsll32     $4, $2, 16
    /* 1EE078 002EE078 3F240400 */  dsra32     $4, $4, 16
    /* 1EE07C 002EE07C 54D80A0C */  jal        func_002b6150
    /* 1EE080 002EE080 00000000 */   nop
    /* 1EE084 002EE084 6E0055A0 */  sb         $21, 0x6E($2)
    /* 1EE088 002EE088 5802A427 */  addiu      $4, $29, 0x258
    /* 1EE08C 002EE08C CC000524 */  addiu      $5, $0, 0xCC
    /* 1EE090 002EE090 FF000624 */  addiu      $6, $0, 0xFF
    /* 1EE094 002EE094 33000724 */  addiu      $7, $0, 0x33
    /* 1EE098 002EE098 2D40C000 */  daddu      $8, $6, $0
    /* 1EE09C 002EE09C 98CA0A0C */  jal        func_002b2a60
    /* 1EE0A0 002EE0A0 00000000 */   nop
    /* 1EE0A4 002EE0A4 97022226 */  addiu      $2, $17, 0x297
    /* 1EE0A8 002EE0A8 3C240200 */  dsll32     $4, $2, 16
    /* 1EE0AC 002EE0AC 3F240400 */  dsra32     $4, $4, 16
    /* 1EE0B0 002EE0B0 54D80A0C */  jal        func_002b6150
    /* 1EE0B4 002EE0B4 00000000 */   nop
    /* 1EE0B8 002EE0B8 2DA84000 */  daddu      $21, $2, $0
    /* 1EE0BC 002EE0BC 5802A693 */  lbu        $6, 0x258($29)
    /* 1EE0C0 002EE0C0 5902A593 */  lbu        $5, 0x259($29)
    /* 1EE0C4 002EE0C4 5A02A493 */  lbu        $4, 0x25A($29)
    /* 1EE0C8 002EE0C8 5B02A393 */  lbu        $3, 0x25B($29)
    /* 1EE0CC 002EE0CC 850046A0 */  sb         $6, 0x85($2)
    /* 1EE0D0 002EE0D0 860045A0 */  sb         $5, 0x86($2)
    /* 1EE0D4 002EE0D4 870044A0 */  sb         $4, 0x87($2)
    /* 1EE0D8 002EE0D8 880043A0 */  sb         $3, 0x88($2)
    /* 1EE0DC 002EE0DC 8B022226 */  addiu      $2, $17, 0x28B
    /* 1EE0E0 002EE0E0 3C240200 */  dsll32     $4, $2, 16
    /* 1EE0E4 002EE0E4 3F240400 */  dsra32     $4, $4, 16
    /* 1EE0E8 002EE0E8 54D80A0C */  jal        func_002b6150
    /* 1EE0EC 002EE0EC 00000000 */   nop
    /* 1EE0F0 002EE0F0 2DB04000 */  daddu      $22, $2, $0
    /* 1EE0F4 002EE0F4 8500A692 */  lbu        $6, 0x85($21)
    /* 1EE0F8 002EE0F8 8600A592 */  lbu        $5, 0x86($21)
    /* 1EE0FC 002EE0FC 8700A492 */  lbu        $4, 0x87($21)
    /* 1EE100 002EE100 8800A392 */  lbu        $3, 0x88($21)
    /* 1EE104 002EE104 850046A0 */  sb         $6, 0x85($2)
    /* 1EE108 002EE108 860045A0 */  sb         $5, 0x86($2)
    /* 1EE10C 002EE10C 870044A0 */  sb         $4, 0x87($2)
    /* 1EE110 002EE110 880043A0 */  sb         $3, 0x88($2)
    /* 1EE114 002EE114 3C241E00 */  dsll32     $4, $30, 16
    /* 1EE118 002EE118 3F240400 */  dsra32     $4, $4, 16
    /* 1EE11C 002EE11C 54D80A0C */  jal        func_002b6150
    /* 1EE120 002EE120 00000000 */   nop
    /* 1EE124 002EE124 2DA84000 */  daddu      $21, $2, $0
    /* 1EE128 002EE128 8500C692 */  lbu        $6, 0x85($22)
    /* 1EE12C 002EE12C 8600C592 */  lbu        $5, 0x86($22)
    /* 1EE130 002EE130 8700C492 */  lbu        $4, 0x87($22)
    /* 1EE134 002EE134 8800C392 */  lbu        $3, 0x88($22)
    /* 1EE138 002EE138 850046A0 */  sb         $6, 0x85($2)
    /* 1EE13C 002EE13C 860045A0 */  sb         $5, 0x86($2)
    /* 1EE140 002EE140 870044A0 */  sb         $4, 0x87($2)
    /* 1EE144 002EE144 880043A0 */  sb         $3, 0x88($2)
    /* 1EE148 002EE148 D000A27B */  lq         $2, 0xD0($29)
    /* 1EE14C 002EE14C 3C240200 */  dsll32     $4, $2, 16
    /* 1EE150 002EE150 3F240400 */  dsra32     $4, $4, 16
    /* 1EE154 002EE154 54D80A0C */  jal        func_002b6150
    /* 1EE158 002EE158 00000000 */   nop
    /* 1EE15C 002EE15C 8500A692 */  lbu        $6, 0x85($21)
    /* 1EE160 002EE160 8600A592 */  lbu        $5, 0x86($21)
    /* 1EE164 002EE164 8700A492 */  lbu        $4, 0x87($21)
    /* 1EE168 002EE168 8800A392 */  lbu        $3, 0x88($21)
    /* 1EE16C 002EE16C 850046A0 */  sb         $6, 0x85($2)
    /* 1EE170 002EE170 860045A0 */  sb         $5, 0x86($2)
    /* 1EE174 002EE174 870044A0 */  sb         $4, 0x87($2)
    /* 1EE178 002EE178 880043A0 */  sb         $3, 0x88($2)
    /* 1EE17C 002EE17C 5402A427 */  addiu      $4, $29, 0x254
    /* 1EE180 002EE180 2D000524 */  addiu      $5, $0, 0x2D
    /* 1EE184 002EE184 2D30A000 */  daddu      $6, $5, $0
    /* 1EE188 002EE188 2D38A000 */  daddu      $7, $5, $0
    /* 1EE18C 002EE18C FF000824 */  addiu      $8, $0, 0xFF
    /* 1EE190 002EE190 98CA0A0C */  jal        func_002b2a60
    /* 1EE194 002EE194 00000000 */   nop
    /* 1EE198 002EE198 A3022226 */  addiu      $2, $17, 0x2A3
    /* 1EE19C 002EE19C 3C240200 */  dsll32     $4, $2, 16
    /* 1EE1A0 002EE1A0 3F240400 */  dsra32     $4, $4, 16
    /* 1EE1A4 002EE1A4 54D80A0C */  jal        func_002b6150
    /* 1EE1A8 002EE1A8 00000000 */   nop
    /* 1EE1AC 002EE1AC 5402A693 */  lbu        $6, 0x254($29)
    /* 1EE1B0 002EE1B0 5502A593 */  lbu        $5, 0x255($29)
    /* 1EE1B4 002EE1B4 5602A493 */  lbu        $4, 0x256($29)
    /* 1EE1B8 002EE1B8 5702A393 */  lbu        $3, 0x257($29)
    /* 1EE1BC 002EE1BC 850046A0 */  sb         $6, 0x85($2)
    /* 1EE1C0 002EE1C0 860045A0 */  sb         $5, 0x86($2)
    /* 1EE1C4 002EE1C4 870044A0 */  sb         $4, 0x87($2)
    /* 1EE1C8 002EE1C8 880043A0 */  sb         $3, 0x88($2)
    /* 1EE1CC 002EE1CC 5002A427 */  addiu      $4, $29, 0x250
    /* 1EE1D0 002EE1D0 2D000524 */  addiu      $5, $0, 0x2D
    /* 1EE1D4 002EE1D4 2D30A000 */  daddu      $6, $5, $0
    /* 1EE1D8 002EE1D8 2D38A000 */  daddu      $7, $5, $0
    /* 1EE1DC 002EE1DC FF000824 */  addiu      $8, $0, 0xFF
    /* 1EE1E0 002EE1E0 98CA0A0C */  jal        func_002b2a60
    /* 1EE1E4 002EE1E4 00000000 */   nop
    /* 1EE1E8 002EE1E8 0C002226 */  addiu      $2, $17, 0xC
    /* 1EE1EC 002EE1EC 3C2E0200 */  dsll32     $5, $2, 24
    /* 1EE1F0 002EE1F0 3F2E0500 */  dsra32     $5, $5, 24
    /* 1EE1F4 002EE1F4 BC02448E */  lw         $4, 0x2BC($18)
    /* 1EE1F8 002EE1F8 5002A68F */  lw         $6, 0x250($29)
    /* 1EE1FC 002EE1FC 5CEA0A0C */  jal        func_002ba970
    /* 1EE200 002EE200 00000000 */   nop
    /* 1EE204 002EE204 2D000424 */  addiu      $4, $0, 0x2D
    /* 1EE208 002EE208 2D288000 */  daddu      $5, $4, $0
    /* 1EE20C 002EE20C 2D308000 */  daddu      $6, $4, $0
    /* 1EE210 002EE210 E000A793 */  lbu        $7, 0xE0($29)
    /* 1EE214 002EE214 8CCA0A0C */  jal        func_002b2a30
    /* 1EE218 002EE218 00000000 */   nop
    /* 1EE21C 002EE21C 2DA84000 */  daddu      $21, $2, $0
    /* 1EE220 002EE220 2D200000 */  daddu      $4, $0, $0
    /* 1EE224 002EE224 1C920B0C */  jal        func_002e4870
    /* 1EE228 002EE228 00000000 */   nop
    /* 1EE22C 002EE22C 28014482 */  lb         $4, 0x128($18)
    /* 1EE230 002EE230 40180400 */  sll        $3, $4, 1
    /* 1EE234 002EE234 21186400 */  addu       $3, $3, $4
    /* 1EE238 002EE238 80180300 */  sll        $3, $3, 2
    /* 1EE23C 002EE23C 21104300 */  addu       $2, $2, $3
    /* 1EE240 002EE240 21105100 */  addu       $2, $2, $17
    /* 1EE244 002EE244 14004380 */  lb         $3, 0x14($2)
    /* 1EE248 002EE248 02000224 */  addiu      $2, $0, 0x2
    /* 1EE24C 002EE24C 05016214 */  bne        $3, $2, .L002EE664
    /* 1EE250 002EE250 00000000 */   nop
    /* 1EE254 002EE254 CF000424 */  addiu      $4, $0, 0xCF
    /* 1EE258 002EE258 2D280000 */  daddu      $5, $0, $0
    /* 1EE25C 002EE25C 01000624 */  addiu      $6, $0, 0x1
    /* 1EE260 002EE260 34DA0A0C */  jal        func_002b68d0
    /* 1EE264 002EE264 00000000 */   nop
    /* 1EE268 002EE268 D2000424 */  addiu      $4, $0, 0xD2
    /* 1EE26C 002EE26C 2D280000 */  daddu      $5, $0, $0
    /* 1EE270 002EE270 01000624 */  addiu      $6, $0, 0x1
    /* 1EE274 002EE274 34DA0A0C */  jal        func_002b68d0
    /* 1EE278 002EE278 00000000 */   nop
    /* 1EE27C 002EE27C 3C241700 */  dsll32     $4, $23, 16
    /* 1EE280 002EE280 3F240400 */  dsra32     $4, $4, 16
    /* 1EE284 002EE284 2D280000 */  daddu      $5, $0, $0
    /* 1EE288 002EE288 2D300000 */  daddu      $6, $0, $0
    /* 1EE28C 002EE28C 34DA0A0C */  jal        func_002b68d0
    /* 1EE290 002EE290 00000000 */   nop
    /* 1EE294 002EE294 3C241E00 */  dsll32     $4, $30, 16
    /* 1EE298 002EE298 3F240400 */  dsra32     $4, $4, 16
    /* 1EE29C 002EE29C 2D280000 */  daddu      $5, $0, $0
    /* 1EE2A0 002EE2A0 2D300000 */  daddu      $6, $0, $0
    /* 1EE2A4 002EE2A4 34DA0A0C */  jal        func_002b68d0
    /* 1EE2A8 002EE2A8 00000000 */   nop
    /* 1EE2AC 002EE2AC ED000010 */  b          .L002EE664
    /* 1EE2B0 002EE2B0 00000000 */   nop
  .L002EE2B4:
    /* 1EE2B4 002EE2B4 2D200000 */  daddu      $4, $0, $0
    /* 1EE2B8 002EE2B8 1C920B0C */  jal        func_002e4870
    /* 1EE2BC 002EE2BC 00000000 */   nop
    /* 1EE2C0 002EE2C0 28014482 */  lb         $4, 0x128($18)
    /* 1EE2C4 002EE2C4 40180400 */  sll        $3, $4, 1
    /* 1EE2C8 002EE2C8 21186400 */  addu       $3, $3, $4
    /* 1EE2CC 002EE2CC 80180300 */  sll        $3, $3, 2
    /* 1EE2D0 002EE2D0 21104300 */  addu       $2, $2, $3
    /* 1EE2D4 002EE2D4 21105000 */  addu       $2, $2, $16
    /* 1EE2D8 002EE2D8 14004380 */  lb         $3, 0x14($2)
    /* 1EE2DC 002EE2DC 02000224 */  addiu      $2, $0, 0x2
    /* 1EE2E0 002EE2E0 65006214 */  bne        $3, $2, .L002EE478
    /* 1EE2E4 002EE2E4 00000000 */   nop
    /* 1EE2E8 002EE2E8 3C8C1300 */  dsll32     $17, $19, 16
    /* 1EE2EC 002EE2EC 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EE2F0 002EE2F0 7D023526 */  addiu      $21, $17, 0x27D
    /* 1EE2F4 002EE2F4 70023626 */  addiu      $22, $17, 0x270
    /* 1EE2F8 002EE2F8 3C241500 */  dsll32     $4, $21, 16
    /* 1EE2FC 002EE2FC 3F240400 */  dsra32     $4, $4, 16
    /* 1EE300 002EE300 54D80A0C */  jal        func_002b6150
    /* 1EE304 002EE304 00000000 */   nop
    /* 1EE308 002EE308 6E0040A0 */  sb         $0, 0x6E($2)
    /* 1EE30C 002EE30C FF001730 */  andi       $23, $0, 0xFF
    /* 1EE310 002EE310 3C241600 */  dsll32     $4, $22, 16
    /* 1EE314 002EE314 3F240400 */  dsra32     $4, $4, 16
    /* 1EE318 002EE318 54D80A0C */  jal        func_002b6150
    /* 1EE31C 002EE31C 00000000 */   nop
    /* 1EE320 002EE320 6E0057A0 */  sb         $23, 0x6E($2)
    /* 1EE324 002EE324 4C02A427 */  addiu      $4, $29, 0x24C
    /* 1EE328 002EE328 FF000524 */  addiu      $5, $0, 0xFF
    /* 1EE32C 002EE32C 2D30A000 */  daddu      $6, $5, $0
    /* 1EE330 002EE330 2D38A000 */  daddu      $7, $5, $0
    /* 1EE334 002EE334 2D40A000 */  daddu      $8, $5, $0
    /* 1EE338 002EE338 98CA0A0C */  jal        func_002b2a60
    /* 1EE33C 002EE33C 00000000 */   nop
    /* 1EE340 002EE340 3C241500 */  dsll32     $4, $21, 16
    /* 1EE344 002EE344 3F240400 */  dsra32     $4, $4, 16
    /* 1EE348 002EE348 54D80A0C */  jal        func_002b6150
    /* 1EE34C 002EE34C 00000000 */   nop
    /* 1EE350 002EE350 2DA84000 */  daddu      $21, $2, $0
    /* 1EE354 002EE354 4C02A693 */  lbu        $6, 0x24C($29)
    /* 1EE358 002EE358 4D02A593 */  lbu        $5, 0x24D($29)
    /* 1EE35C 002EE35C 4E02A493 */  lbu        $4, 0x24E($29)
    /* 1EE360 002EE360 4F02A393 */  lbu        $3, 0x24F($29)
    /* 1EE364 002EE364 850046A0 */  sb         $6, 0x85($2)
    /* 1EE368 002EE368 860045A0 */  sb         $5, 0x86($2)
    /* 1EE36C 002EE36C 870044A0 */  sb         $4, 0x87($2)
    /* 1EE370 002EE370 880043A0 */  sb         $3, 0x88($2)
    /* 1EE374 002EE374 3C241600 */  dsll32     $4, $22, 16
    /* 1EE378 002EE378 3F240400 */  dsra32     $4, $4, 16
    /* 1EE37C 002EE37C 54D80A0C */  jal        func_002b6150
    /* 1EE380 002EE380 00000000 */   nop
    /* 1EE384 002EE384 8500A692 */  lbu        $6, 0x85($21)
    /* 1EE388 002EE388 8600A592 */  lbu        $5, 0x86($21)
    /* 1EE38C 002EE38C 8700A492 */  lbu        $4, 0x87($21)
    /* 1EE390 002EE390 8800A392 */  lbu        $3, 0x88($21)
    /* 1EE394 002EE394 850046A0 */  sb         $6, 0x85($2)
    /* 1EE398 002EE398 860045A0 */  sb         $5, 0x86($2)
    /* 1EE39C 002EE39C 870044A0 */  sb         $4, 0x87($2)
    /* 1EE3A0 002EE3A0 880043A0 */  sb         $3, 0x88($2)
    /* 1EE3A4 002EE3A4 4802A427 */  addiu      $4, $29, 0x248
    /* 1EE3A8 002EE3A8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1EE3AC 002EE3AC CC000624 */  addiu      $6, $0, 0xCC
    /* 1EE3B0 002EE3B0 FA000724 */  addiu      $7, $0, 0xFA
    /* 1EE3B4 002EE3B4 2D40A000 */  daddu      $8, $5, $0
    /* 1EE3B8 002EE3B8 98CA0A0C */  jal        func_002b2a60
    /* 1EE3BC 002EE3BC 00000000 */   nop
    /* 1EE3C0 002EE3C0 A3022226 */  addiu      $2, $17, 0x2A3
    /* 1EE3C4 002EE3C4 3C240200 */  dsll32     $4, $2, 16
    /* 1EE3C8 002EE3C8 3F240400 */  dsra32     $4, $4, 16
    /* 1EE3CC 002EE3CC 54D80A0C */  jal        func_002b6150
    /* 1EE3D0 002EE3D0 00000000 */   nop
    /* 1EE3D4 002EE3D4 4802A693 */  lbu        $6, 0x248($29)
    /* 1EE3D8 002EE3D8 4902A593 */  lbu        $5, 0x249($29)
    /* 1EE3DC 002EE3DC 4A02A493 */  lbu        $4, 0x24A($29)
    /* 1EE3E0 002EE3E0 4B02A393 */  lbu        $3, 0x24B($29)
    /* 1EE3E4 002EE3E4 850046A0 */  sb         $6, 0x85($2)
    /* 1EE3E8 002EE3E8 860045A0 */  sb         $5, 0x86($2)
    /* 1EE3EC 002EE3EC 870044A0 */  sb         $4, 0x87($2)
    /* 1EE3F0 002EE3F0 880043A0 */  sb         $3, 0x88($2)
    /* 1EE3F4 002EE3F4 4402A427 */  addiu      $4, $29, 0x244
    /* 1EE3F8 002EE3F8 FF000524 */  addiu      $5, $0, 0xFF
    /* 1EE3FC 002EE3FC CC000624 */  addiu      $6, $0, 0xCC
    /* 1EE400 002EE400 FA000724 */  addiu      $7, $0, 0xFA
    /* 1EE404 002EE404 2D40A000 */  daddu      $8, $5, $0
    /* 1EE408 002EE408 98CA0A0C */  jal        func_002b2a60
    /* 1EE40C 002EE40C 00000000 */   nop
    /* 1EE410 002EE410 0C002226 */  addiu      $2, $17, 0xC
    /* 1EE414 002EE414 3C2E0200 */  dsll32     $5, $2, 24
    /* 1EE418 002EE418 3F2E0500 */  dsra32     $5, $5, 24
    /* 1EE41C 002EE41C BC02448E */  lw         $4, 0x2BC($18)
    /* 1EE420 002EE420 4402A68F */  lw         $6, 0x244($29)
    /* 1EE424 002EE424 5CEA0A0C */  jal        func_002ba970
    /* 1EE428 002EE428 00000000 */   nop
    /* 1EE42C 002EE42C FF000424 */  addiu      $4, $0, 0xFF
    /* 1EE430 002EE430 CC000524 */  addiu      $5, $0, 0xCC
    /* 1EE434 002EE434 FA000624 */  addiu      $6, $0, 0xFA
    /* 1EE438 002EE438 E000A793 */  lbu        $7, 0xE0($29)
    /* 1EE43C 002EE43C 8CCA0A0C */  jal        func_002b2a30
    /* 1EE440 002EE440 00000000 */   nop
    /* 1EE444 002EE444 2DA84000 */  daddu      $21, $2, $0
    /* 1EE448 002EE448 CF000424 */  addiu      $4, $0, 0xCF
    /* 1EE44C 002EE44C 2D280000 */  daddu      $5, $0, $0
    /* 1EE450 002EE450 2D300000 */  daddu      $6, $0, $0
    /* 1EE454 002EE454 34DA0A0C */  jal        func_002b68d0
    /* 1EE458 002EE458 00000000 */   nop
    /* 1EE45C 002EE45C D2000424 */  addiu      $4, $0, 0xD2
    /* 1EE460 002EE460 2D280000 */  daddu      $5, $0, $0
    /* 1EE464 002EE464 2D300000 */  daddu      $6, $0, $0
    /* 1EE468 002EE468 34DA0A0C */  jal        func_002b68d0
    /* 1EE46C 002EE46C 00000000 */   nop
    /* 1EE470 002EE470 7C000010 */  b          .L002EE664
    /* 1EE474 002EE474 00000000 */   nop
  .L002EE478:
    /* 1EE478 002EE478 3C8C1300 */  dsll32     $17, $19, 16
    /* 1EE47C 002EE47C 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EE480 002EE480 7D023526 */  addiu      $21, $17, 0x27D
    /* 1EE484 002EE484 70023626 */  addiu      $22, $17, 0x270
    /* 1EE488 002EE488 CC001724 */  addiu      $23, $0, 0xCC
    /* 1EE48C 002EE48C 3C241500 */  dsll32     $4, $21, 16
    /* 1EE490 002EE490 3F240400 */  dsra32     $4, $4, 16
    /* 1EE494 002EE494 54D80A0C */  jal        func_002b6150
    /* 1EE498 002EE498 00000000 */   nop
    /* 1EE49C 002EE49C 6E0057A0 */  sb         $23, 0x6E($2)
    /* 1EE4A0 002EE4A0 FF00F732 */  andi       $23, $23, 0xFF
    /* 1EE4A4 002EE4A4 3C241600 */  dsll32     $4, $22, 16
    /* 1EE4A8 002EE4A8 3F240400 */  dsra32     $4, $4, 16
    /* 1EE4AC 002EE4AC 54D80A0C */  jal        func_002b6150
    /* 1EE4B0 002EE4B0 00000000 */   nop
    /* 1EE4B4 002EE4B4 6E0057A0 */  sb         $23, 0x6E($2)
    /* 1EE4B8 002EE4B8 4002A427 */  addiu      $4, $29, 0x240
    /* 1EE4BC 002EE4BC 49000524 */  addiu      $5, $0, 0x49
    /* 1EE4C0 002EE4C0 72000624 */  addiu      $6, $0, 0x72
    /* 1EE4C4 002EE4C4 FF000724 */  addiu      $7, $0, 0xFF
    /* 1EE4C8 002EE4C8 2D40E000 */  daddu      $8, $7, $0
    /* 1EE4CC 002EE4CC 98CA0A0C */  jal        func_002b2a60
    /* 1EE4D0 002EE4D0 00000000 */   nop
    /* 1EE4D4 002EE4D4 3C241500 */  dsll32     $4, $21, 16
    /* 1EE4D8 002EE4D8 3F240400 */  dsra32     $4, $4, 16
    /* 1EE4DC 002EE4DC 54D80A0C */  jal        func_002b6150
    /* 1EE4E0 002EE4E0 00000000 */   nop
    /* 1EE4E4 002EE4E4 2DA84000 */  daddu      $21, $2, $0
    /* 1EE4E8 002EE4E8 4002A693 */  lbu        $6, 0x240($29)
    /* 1EE4EC 002EE4EC 4102A593 */  lbu        $5, 0x241($29)
    /* 1EE4F0 002EE4F0 4202A493 */  lbu        $4, 0x242($29)
    /* 1EE4F4 002EE4F4 4302A393 */  lbu        $3, 0x243($29)
    /* 1EE4F8 002EE4F8 850046A0 */  sb         $6, 0x85($2)
    /* 1EE4FC 002EE4FC 860045A0 */  sb         $5, 0x86($2)
    /* 1EE500 002EE500 870044A0 */  sb         $4, 0x87($2)
    /* 1EE504 002EE504 880043A0 */  sb         $3, 0x88($2)
    /* 1EE508 002EE508 3C241600 */  dsll32     $4, $22, 16
    /* 1EE50C 002EE50C 3F240400 */  dsra32     $4, $4, 16
    /* 1EE510 002EE510 54D80A0C */  jal        func_002b6150
    /* 1EE514 002EE514 00000000 */   nop
    /* 1EE518 002EE518 8500A692 */  lbu        $6, 0x85($21)
    /* 1EE51C 002EE51C 8600A592 */  lbu        $5, 0x86($21)
    /* 1EE520 002EE520 8700A492 */  lbu        $4, 0x87($21)
    /* 1EE524 002EE524 8800A392 */  lbu        $3, 0x88($21)
    /* 1EE528 002EE528 850046A0 */  sb         $6, 0x85($2)
    /* 1EE52C 002EE52C 860045A0 */  sb         $5, 0x86($2)
    /* 1EE530 002EE530 870044A0 */  sb         $4, 0x87($2)
    /* 1EE534 002EE534 880043A0 */  sb         $3, 0x88($2)
    /* 1EE538 002EE538 3C02A427 */  addiu      $4, $29, 0x23C
    /* 1EE53C 002EE53C 49000524 */  addiu      $5, $0, 0x49
    /* 1EE540 002EE540 72000624 */  addiu      $6, $0, 0x72
    /* 1EE544 002EE544 FF000724 */  addiu      $7, $0, 0xFF
    /* 1EE548 002EE548 2D40E000 */  daddu      $8, $7, $0
    /* 1EE54C 002EE54C 98CA0A0C */  jal        func_002b2a60
    /* 1EE550 002EE550 00000000 */   nop
    /* 1EE554 002EE554 97022226 */  addiu      $2, $17, 0x297
    /* 1EE558 002EE558 3C240200 */  dsll32     $4, $2, 16
    /* 1EE55C 002EE55C 3F240400 */  dsra32     $4, $4, 16
    /* 1EE560 002EE560 54D80A0C */  jal        func_002b6150
    /* 1EE564 002EE564 00000000 */   nop
    /* 1EE568 002EE568 2DA84000 */  daddu      $21, $2, $0
    /* 1EE56C 002EE56C 3C02A693 */  lbu        $6, 0x23C($29)
    /* 1EE570 002EE570 3D02A593 */  lbu        $5, 0x23D($29)
    /* 1EE574 002EE574 3E02A493 */  lbu        $4, 0x23E($29)
    /* 1EE578 002EE578 3F02A393 */  lbu        $3, 0x23F($29)
    /* 1EE57C 002EE57C 850046A0 */  sb         $6, 0x85($2)
    /* 1EE580 002EE580 860045A0 */  sb         $5, 0x86($2)
    /* 1EE584 002EE584 870044A0 */  sb         $4, 0x87($2)
    /* 1EE588 002EE588 880043A0 */  sb         $3, 0x88($2)
    /* 1EE58C 002EE58C 8B022226 */  addiu      $2, $17, 0x28B
    /* 1EE590 002EE590 3C240200 */  dsll32     $4, $2, 16
    /* 1EE594 002EE594 3F240400 */  dsra32     $4, $4, 16
    /* 1EE598 002EE598 54D80A0C */  jal        func_002b6150
    /* 1EE59C 002EE59C 00000000 */   nop
    /* 1EE5A0 002EE5A0 8500A692 */  lbu        $6, 0x85($21)
    /* 1EE5A4 002EE5A4 8600A592 */  lbu        $5, 0x86($21)
    /* 1EE5A8 002EE5A8 8700A492 */  lbu        $4, 0x87($21)
    /* 1EE5AC 002EE5AC 8800A392 */  lbu        $3, 0x88($21)
    /* 1EE5B0 002EE5B0 850046A0 */  sb         $6, 0x85($2)
    /* 1EE5B4 002EE5B4 860045A0 */  sb         $5, 0x86($2)
    /* 1EE5B8 002EE5B8 870044A0 */  sb         $4, 0x87($2)
    /* 1EE5BC 002EE5BC 880043A0 */  sb         $3, 0x88($2)
    /* 1EE5C0 002EE5C0 3802A427 */  addiu      $4, $29, 0x238
    /* 1EE5C4 002EE5C4 2D280000 */  daddu      $5, $0, $0
    /* 1EE5C8 002EE5C8 2D300000 */  daddu      $6, $0, $0
    /* 1EE5CC 002EE5CC 66000724 */  addiu      $7, $0, 0x66
    /* 1EE5D0 002EE5D0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1EE5D4 002EE5D4 98CA0A0C */  jal        func_002b2a60
    /* 1EE5D8 002EE5D8 00000000 */   nop
    /* 1EE5DC 002EE5DC A3022226 */  addiu      $2, $17, 0x2A3
    /* 1EE5E0 002EE5E0 3C240200 */  dsll32     $4, $2, 16
    /* 1EE5E4 002EE5E4 3F240400 */  dsra32     $4, $4, 16
    /* 1EE5E8 002EE5E8 54D80A0C */  jal        func_002b6150
    /* 1EE5EC 002EE5EC 00000000 */   nop
    /* 1EE5F0 002EE5F0 3802A693 */  lbu        $6, 0x238($29)
    /* 1EE5F4 002EE5F4 3902A593 */  lbu        $5, 0x239($29)
    /* 1EE5F8 002EE5F8 3A02A493 */  lbu        $4, 0x23A($29)
    /* 1EE5FC 002EE5FC 3B02A393 */  lbu        $3, 0x23B($29)
    /* 1EE600 002EE600 850046A0 */  sb         $6, 0x85($2)
    /* 1EE604 002EE604 860045A0 */  sb         $5, 0x86($2)
    /* 1EE608 002EE608 870044A0 */  sb         $4, 0x87($2)
    /* 1EE60C 002EE60C 880043A0 */  sb         $3, 0x88($2)
    /* 1EE610 002EE610 3402A427 */  addiu      $4, $29, 0x234
    /* 1EE614 002EE614 CC000524 */  addiu      $5, $0, 0xCC
    /* 1EE618 002EE618 FF000624 */  addiu      $6, $0, 0xFF
    /* 1EE61C 002EE61C 2D38C000 */  daddu      $7, $6, $0
    /* 1EE620 002EE620 2D40C000 */  daddu      $8, $6, $0
    /* 1EE624 002EE624 98CA0A0C */  jal        func_002b2a60
    /* 1EE628 002EE628 00000000 */   nop
    /* 1EE62C 002EE62C 0C002226 */  addiu      $2, $17, 0xC
    /* 1EE630 002EE630 3C2E0200 */  dsll32     $5, $2, 24
    /* 1EE634 002EE634 3F2E0500 */  dsra32     $5, $5, 24
    /* 1EE638 002EE638 BC02448E */  lw         $4, 0x2BC($18)
    /* 1EE63C 002EE63C 3402A68F */  lw         $6, 0x234($29)
    /* 1EE640 002EE640 5CEA0A0C */  jal        func_002ba970
    /* 1EE644 002EE644 00000000 */   nop
    /* 1EE648 002EE648 CC000424 */  addiu      $4, $0, 0xCC
    /* 1EE64C 002EE64C FF000524 */  addiu      $5, $0, 0xFF
    /* 1EE650 002EE650 2D30A000 */  daddu      $6, $5, $0
    /* 1EE654 002EE654 E000A793 */  lbu        $7, 0xE0($29)
    /* 1EE658 002EE658 8CCA0A0C */  jal        func_002b2a30
    /* 1EE65C 002EE65C 00000000 */   nop
    /* 1EE660 002EE660 2DA84000 */  daddu      $21, $2, $0
  .L002EE664:
    /* 1EE664 002EE664 40101000 */  sll        $2, $16, 1
    /* 1EE668 002EE668 21105000 */  addu       $2, $2, $16
    /* 1EE66C 002EE66C C0100200 */  sll        $2, $2, 3
    /* 1EE670 002EE670 23105000 */  subu       $2, $2, $16
    /* 1EE674 002EE674 80004224 */  addiu      $2, $2, 0x80
    /* 1EE678 002EE678 00008244 */  mtc1       $2, $f0
    /* 1EE67C 002EE67C 00000000 */  nop
    /* 1EE680 002EE680 20058046 */  cvt.s.w    $f20, $f0
    /* 1EE684 002EE684 28014282 */  lb         $2, 0x128($18)
    /* 1EE688 002EE688 01004224 */  addiu      $2, $2, 0x1
    /* 1EE68C 002EE68C 3C260200 */  dsll32     $4, $2, 24
    /* 1EE690 002EE690 3F260400 */  dsra32     $4, $4, 24
    /* 1EE694 002EE694 2D286002 */  daddu      $5, $19, $0
    /* 1EE698 002EE698 28920B0C */  jal        func_002e48a0
    /* 1EE69C 002EE69C 00000000 */   nop
    /* 1EE6A0 002EE6A0 02004394 */  lhu        $3, 0x2($2)
    /* 1EE6A4 002EE6A4 00110300 */  sll        $2, $3, 4
    /* 1EE6A8 002EE6A8 21184300 */  addu       $3, $2, $3
    /* 1EE6AC 002EE6AC 40B4828F */  lw         $2, -0x4BC0($28)
    /* 1EE6B0 002EE6B0 21384300 */  addu       $7, $2, $3
    /* 1EE6B4 002EE6B4 95010224 */  addiu      $2, $0, 0x195
    /* 1EE6B8 002EE6B8 00008244 */  mtc1       $2, $f0
    /* 1EE6BC 002EE6BC 00000000 */  nop
    /* 1EE6C0 002EE6C0 20038046 */  cvt.s.w    $f12, $f0
    /* 1EE6C4 002EE6C4 2C42023C */  lui        $2, (0x422C0000 >> 16)
    /* 1EE6C8 002EE6C8 00708244 */  mtc1       $2, $f14
    /* 1EE6CC 002EE6CC 46A30046 */  mov.s      $f13, $f20
    /* 1EE6D0 002EE6D0 2D20A002 */  daddu      $4, $21, $0
    /* 1EE6D4 002EE6D4 2D280000 */  daddu      $5, $0, $0
    /* 1EE6D8 002EE6D8 02000624 */  addiu      $6, $0, 0x2
    /* 1EE6DC 002EE6DC 2D400000 */  daddu      $8, $0, $0
    /* 1EE6E0 002EE6E0 2D480000 */  daddu      $9, $0, $0
    /* 1EE6E4 002EE6E4 79000A3C */  lui        $10, %hi(D_00795E60)
    /* 1EE6E8 002EE6E8 605E4A25 */  addiu      $10, $10, %lo(D_00795E60)
    /* 1EE6EC 002EE6EC 15000B24 */  addiu      $11, $0, 0x15
    /* 1EE6F0 002EE6F0 08D6090C */  jal        func_00275820
    /* 1EE6F4 002EE6F4 00000000 */   nop
  .L002EE6F8:
    /* 1EE6F8 002EE6F8 01006226 */  addiu      $2, $19, 0x1
    /* 1EE6FC 002EE6FC 3C9C0200 */  dsll32     $19, $2, 16
    /* 1EE700 002EE700 3F9C1300 */  dsra32     $19, $19, 16
  .L002EE704:
    /* 1EE704 002EE704 3C841300 */  dsll32     $16, $19, 16
    /* 1EE708 002EE708 3F841000 */  dsra32     $16, $16, 16
    /* 1EE70C 002EE70C 6C2D040C */  jal        func_0010b5b0
    /* 1EE710 002EE710 00000000 */   nop
    /* 1EE714 002EE714 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1EE718 002EE718 2A100202 */  slt        $2, $16, $2
    /* 1EE71C 002EE71C 00FE4014 */  bnez       $2, .L002EDF20
    /* 1EE720 002EE720 00000000 */   nop
    /* 1EE724 002EE724 4801448E */  lw         $4, 0x148($18)
    /* 1EE728 002EE728 98510C0C */  jal        func_00314660
    /* 1EE72C 002EE72C 00000000 */   nop
    /* 1EE730 002EE730 3C160200 */  dsll32     $2, $2, 24
    /* 1EE734 002EE734 3F160200 */  dsra32     $2, $2, 24
    /* 1EE738 002EE738 09004004 */  bltz       $2, .L002EE760
    /* 1EE73C 002EE73C 00000000 */   nop
    /* 1EE740 002EE740 4801448E */  lw         $4, 0x148($18)
    /* 1EE744 002EE744 98510C0C */  jal        func_00314660
    /* 1EE748 002EE748 00000000 */   nop
    /* 1EE74C 002EE74C 3C1E0200 */  dsll32     $3, $2, 24
    /* 1EE750 002EE750 3F1E0300 */  dsra32     $3, $3, 24
    /* 1EE754 002EE754 06006128 */  slti       $1, $3, 0x6
    /* 1EE758 002EE758 D9092014 */  bnez       $1, .L002F0EC0
    /* 1EE75C 002EE75C 00000000 */   nop
  .L002EE760:
    /* 1EE760 002EE760 C7010424 */  addiu      $4, $0, 0x1C7
    /* 1EE764 002EE764 54D80A0C */  jal        func_002b6150
    /* 1EE768 002EE768 00000000 */   nop
    /* 1EE76C 002EE76C 10004484 */  lh         $4, 0x10($2)
    /* 1EE770 002EE770 2D280000 */  daddu      $5, $0, $0
    /* 1EE774 002EE774 5CDA0A0C */  jal        func_002b6970
    /* 1EE778 002EE778 00000000 */   nop
    /* 1EE77C 002EE77C 3C240200 */  dsll32     $4, $2, 16
    /* 1EE780 002EE780 3F240400 */  dsra32     $4, $4, 16
    /* 1EE784 002EE784 01000324 */  addiu      $3, $0, 0x1
    /* 1EE788 002EE788 0B008314 */  bne        $4, $3, .L002EE7B8
    /* 1EE78C 002EE78C 00000000 */   nop
    /* 1EE790 002EE790 2D208002 */  daddu      $4, $20, $0
    /* 1EE794 002EE794 C7010524 */  addiu      $5, $0, 0x1C7
    /* 1EE798 002EE798 2D300000 */  daddu      $6, $0, $0
    /* 1EE79C 002EE79C 04910C0C */  jal        func_00324410
    /* 1EE7A0 002EE7A0 00000000 */   nop
    /* 1EE7A4 002EE7A4 2D208002 */  daddu      $4, $20, $0
    /* 1EE7A8 002EE7A8 E8020524 */  addiu      $5, $0, 0x2E8
    /* 1EE7AC 002EE7AC 01000624 */  addiu      $6, $0, 0x1
    /* 1EE7B0 002EE7B0 04910C0C */  jal        func_00324410
    /* 1EE7B4 002EE7B4 00000000 */   nop
  .L002EE7B8:
    /* 1EE7B8 002EE7B8 8C00033C */  lui        $3, %hi(D_008C027A)
    /* 1EE7BC 002EE7BC 7A026494 */  lhu        $4, %lo(D_008C027A)($3)
    /* 1EE7C0 002EE7C0 00108330 */  andi       $3, $4, 0x1000
    /* 1EE7C4 002EE7C4 19006010 */  beqz       $3, .L002EE82C
    /* 1EE7C8 002EE7C8 00000000 */   nop
    /* 1EE7CC 002EE7CC 2D200000 */  daddu      $4, $0, $0
    /* 1EE7D0 002EE7D0 1C920B0C */  jal        func_002e4870
    /* 1EE7D4 002EE7D4 00000000 */   nop
    /* 1EE7D8 002EE7D8 0800428C */  lw         $2, 0x8($2)
    /* 1EE7DC 002EE7DC FFFF4224 */  addiu      $2, $2, -0x1
    /* 1EE7E0 002EE7E0 3C3C0200 */  dsll32     $7, $2, 16
    /* 1EE7E4 002EE7E4 3F3C0700 */  dsra32     $7, $7, 16
    /* 1EE7E8 002EE7E8 1E014486 */  lh         $4, 0x11E($18)
    /* 1EE7EC 002EE7EC 01000524 */  addiu      $5, $0, 0x1
    /* 1EE7F0 002EE7F0 2D300000 */  daddu      $6, $0, $0
    /* 1EE7F4 002EE7F4 02000824 */  addiu      $8, $0, 0x2
    /* 1EE7F8 002EE7F8 40CB0A0C */  jal        func_002b2d00
    /* 1EE7FC 002EE7FC 00000000 */   nop
    /* 1EE800 002EE800 3C160200 */  dsll32     $2, $2, 24
    /* 1EE804 002EE804 3F160200 */  dsra32     $2, $2, 24
    /* 1EE808 002EE808 1E0142A6 */  sh         $2, 0x11E($18)
    /* 1EE80C 002EE80C 2D200000 */  daddu      $4, $0, $0
    /* 1EE810 002EE810 2D280000 */  daddu      $5, $0, $0
    /* 1EE814 002EE814 2D300000 */  daddu      $6, $0, $0
    /* 1EE818 002EE818 2D380000 */  daddu      $7, $0, $0
    /* 1EE81C 002EE81C D86B110C */  jal        func_0045af60
    /* 1EE820 002EE820 00000000 */   nop
    /* 1EE824 002EE824 A6090010 */  b          .L002F0EC0
    /* 1EE828 002EE828 00000000 */   nop
  .L002EE82C:
    /* 1EE82C 002EE82C 00408330 */  andi       $3, $4, 0x4000
    /* 1EE830 002EE830 19006010 */  beqz       $3, .L002EE898
    /* 1EE834 002EE834 00000000 */   nop
    /* 1EE838 002EE838 2D200000 */  daddu      $4, $0, $0
    /* 1EE83C 002EE83C 1C920B0C */  jal        func_002e4870
    /* 1EE840 002EE840 00000000 */   nop
    /* 1EE844 002EE844 0800428C */  lw         $2, 0x8($2)
    /* 1EE848 002EE848 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1EE84C 002EE84C 3C340200 */  dsll32     $6, $2, 16
    /* 1EE850 002EE850 3F340600 */  dsra32     $6, $6, 16
    /* 1EE854 002EE854 1E014486 */  lh         $4, 0x11E($18)
    /* 1EE858 002EE858 01000524 */  addiu      $5, $0, 0x1
    /* 1EE85C 002EE85C 2D380000 */  daddu      $7, $0, $0
    /* 1EE860 002EE860 02000824 */  addiu      $8, $0, 0x2
    /* 1EE864 002EE864 2CCB0A0C */  jal        func_002b2cb0
    /* 1EE868 002EE868 00000000 */   nop
    /* 1EE86C 002EE86C 3C160200 */  dsll32     $2, $2, 24
    /* 1EE870 002EE870 3F160200 */  dsra32     $2, $2, 24
    /* 1EE874 002EE874 1E0142A6 */  sh         $2, 0x11E($18)
    /* 1EE878 002EE878 2D200000 */  daddu      $4, $0, $0
    /* 1EE87C 002EE87C 2D280000 */  daddu      $5, $0, $0
    /* 1EE880 002EE880 2D300000 */  daddu      $6, $0, $0
    /* 1EE884 002EE884 2D380000 */  daddu      $7, $0, $0
    /* 1EE888 002EE888 D86B110C */  jal        func_0045af60
    /* 1EE88C 002EE88C 00000000 */   nop
    /* 1EE890 002EE890 8B090010 */  b          .L002F0EC0
    /* 1EE894 002EE894 00000000 */   nop
  .L002EE898:
    /* 1EE898 002EE898 8C00033C */  lui        $3, %hi(D_008C024E)
    /* 1EE89C 002EE89C 4E026494 */  lhu        $4, %lo(D_008C024E)($3)
    /* 1EE8A0 002EE8A0 40008330 */  andi       $3, $4, 0x40
    /* 1EE8A4 002EE8A4 B5006010 */  beqz       $3, .L002EEB7C
    /* 1EE8A8 002EE8A8 00000000 */   nop
    /* 1EE8AC 002EE8AC 28014382 */  lb         $3, 0x128($18)
    /* 1EE8B0 002EE8B0 1E014286 */  lh         $2, 0x11E($18)
    /* 1EE8B4 002EE8B4 A9006210 */  beq        $3, $2, .L002EEB5C
    /* 1EE8B8 002EE8B8 00000000 */   nop
    /* 1EE8BC 002EE8BC 2D200000 */  daddu      $4, $0, $0
    /* 1EE8C0 002EE8C0 1C920B0C */  jal        func_002e4870
    /* 1EE8C4 002EE8C4 00000000 */   nop
    /* 1EE8C8 002EE8C8 28014482 */  lb         $4, 0x128($18)
    /* 1EE8CC 002EE8CC 40180400 */  sll        $3, $4, 1
    /* 1EE8D0 002EE8D0 21186400 */  addu       $3, $3, $4
    /* 1EE8D4 002EE8D4 80180300 */  sll        $3, $3, 2
    /* 1EE8D8 002EE8D8 21184300 */  addu       $3, $2, $3
    /* 1EE8DC 002EE8DC 1E014286 */  lh         $2, 0x11E($18)
    /* 1EE8E0 002EE8E0 21106200 */  addu       $2, $3, $2
    /* 1EE8E4 002EE8E4 14004280 */  lb         $2, 0x14($2)
    /* 1EE8E8 002EE8E8 9C004018 */  blez       $2, .L002EEB5C
    /* 1EE8EC 002EE8EC 00000000 */   nop
    /* 1EE8F0 002EE8F0 2D200000 */  daddu      $4, $0, $0
    /* 1EE8F4 002EE8F4 2D280000 */  daddu      $5, $0, $0
    /* 1EE8F8 002EE8F8 2D300000 */  daddu      $6, $0, $0
    /* 1EE8FC 002EE8FC 01000724 */  addiu      $7, $0, 0x1
    /* 1EE900 002EE900 D86B110C */  jal        func_0045af60
    /* 1EE904 002EE904 00000000 */   nop
    /* 1EE908 002EE908 2D880000 */  daddu      $17, $0, $0
    /* 1EE90C 002EE90C 49000010 */  b          .L002EEA34
    /* 1EE910 002EE910 00000000 */   nop
  .L002EE914:
    /* 1EE914 002EE914 49010224 */  addiu      $2, $0, 0x149
    /* 1EE918 002EE918 00008244 */  mtc1       $2, $f0
    /* 1EE91C 002EE91C 00000000 */  nop
    /* 1EE920 002EE920 20038046 */  cvt.s.w    $f12, $f0
    /* 1EE924 002EE924 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EE928 002EE928 00688244 */  mtc1       $2, $f13
    /* 1EE92C 002EE92C 1802A427 */  addiu      $4, $29, 0x218
    /* 1EE930 002EE930 5CCA0A0C */  jal        func_002b2970
    /* 1EE934 002EE934 00000000 */   nop
    /* 1EE938 002EE938 28014282 */  lb         $2, 0x128($18)
    /* 1EE93C 002EE93C 01004224 */  addiu      $2, $2, 0x1
    /* 1EE940 002EE940 3C260200 */  dsll32     $4, $2, 24
    /* 1EE944 002EE944 3F260400 */  dsra32     $4, $4, 24
    /* 1EE948 002EE948 2D282002 */  daddu      $5, $17, $0
    /* 1EE94C 002EE94C 28920B0C */  jal        func_002e48a0
    /* 1EE950 002EE950 00000000 */   nop
    /* 1EE954 002EE954 02005094 */  lhu        $16, 0x2($2)
    /* 1EE958 002EE958 28014282 */  lb         $2, 0x128($18)
    /* 1EE95C 002EE95C 01004224 */  addiu      $2, $2, 0x1
    /* 1EE960 002EE960 3C260200 */  dsll32     $4, $2, 24
    /* 1EE964 002EE964 3F260400 */  dsra32     $4, $4, 24
    /* 1EE968 002EE968 2D282002 */  daddu      $5, $17, $0
    /* 1EE96C 002EE96C 28920B0C */  jal        func_002e48a0
    /* 1EE970 002EE970 00000000 */   nop
    /* 1EE974 002EE974 04004990 */  lbu        $9, 0x4($2)
    /* 1EE978 002EE978 01000B24 */  addiu      $11, $0, 0x1
    /* 1EE97C 002EE97C 0000ABFF */  sd         $11, 0x0($29)
    /* 1EE980 002EE980 CC000224 */  addiu      $2, $0, 0xCC
    /* 1EE984 002EE984 0800A2FF */  sd         $2, 0x8($29)
    /* 1EE988 002EE988 3C3E1100 */  dsll32     $7, $17, 24
    /* 1EE98C 002EE98C 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EE990 002EE990 2D208002 */  daddu      $4, $20, $0
    /* 1EE994 002EE994 1802A5DF */  ld         $5, 0x218($29)
    /* 1EE998 002EE998 28014682 */  lb         $6, 0x128($18)
    /* 1EE99C 002EE99C 2D400002 */  daddu      $8, $16, $0
    /* 1EE9A0 002EE9A0 2D500000 */  daddu      $10, $0, $0
    /* 1EE9A4 002EE9A4 046B0C0C */  jal        func_0031ac10
    /* 1EE9A8 002EE9A8 00000000 */   nop
    /* 1EE9AC 002EE9AC 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EE9B0 002EE9B0 00608244 */  mtc1       $2, $f12
    /* 1EE9B4 002EE9B4 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EE9B8 002EE9B8 00688244 */  mtc1       $2, $f13
    /* 1EE9BC 002EE9BC 1002A427 */  addiu      $4, $29, 0x210
    /* 1EE9C0 002EE9C0 5CCA0A0C */  jal        func_002b2970
    /* 1EE9C4 002EE9C4 00000000 */   nop
    /* 1EE9C8 002EE9C8 2D200000 */  daddu      $4, $0, $0
    /* 1EE9CC 002EE9CC 2D282002 */  daddu      $5, $17, $0
    /* 1EE9D0 002EE9D0 28920B0C */  jal        func_002e48a0
    /* 1EE9D4 002EE9D4 00000000 */   nop
    /* 1EE9D8 002EE9D8 02005394 */  lhu        $19, 0x2($2)
    /* 1EE9DC 002EE9DC 2D200000 */  daddu      $4, $0, $0
    /* 1EE9E0 002EE9E0 2D282002 */  daddu      $5, $17, $0
    /* 1EE9E4 002EE9E4 28920B0C */  jal        func_002e48a0
    /* 1EE9E8 002EE9E8 00000000 */   nop
    /* 1EE9EC 002EE9EC 04005090 */  lbu        $16, 0x4($2)
    /* 1EE9F0 002EE9F0 2D200000 */  daddu      $4, $0, $0
    /* 1EE9F4 002EE9F4 1C920B0C */  jal        func_002e4870
    /* 1EE9F8 002EE9F8 00000000 */   nop
    /* 1EE9FC 002EE9FC 08004B80 */  lb         $11, 0x8($2)
    /* 1EEA00 002EEA00 3C361100 */  dsll32     $6, $17, 24
    /* 1EEA04 002EEA04 3F360600 */  dsra32     $6, $6, 24
    /* 1EEA08 002EEA08 2D208002 */  daddu      $4, $20, $0
    /* 1EEA0C 002EEA0C 1002A5DF */  ld         $5, 0x210($29)
    /* 1EEA10 002EEA10 2D386002 */  daddu      $7, $19, $0
    /* 1EEA14 002EEA14 2D400002 */  daddu      $8, $16, $0
    /* 1EEA18 002EEA18 2D480000 */  daddu      $9, $0, $0
    /* 1EEA1C 002EEA1C 01000A24 */  addiu      $10, $0, 0x1
    /* 1EEA20 002EEA20 70640C0C */  jal        func_003191c0
    /* 1EEA24 002EEA24 00000000 */   nop
    /* 1EEA28 002EEA28 01002226 */  addiu      $2, $17, 0x1
    /* 1EEA2C 002EEA2C 3C8C0200 */  dsll32     $17, $2, 16
    /* 1EEA30 002EEA30 3F8C1100 */  dsra32     $17, $17, 16
  .L002EEA34:
    /* 1EEA34 002EEA34 3C841100 */  dsll32     $16, $17, 16
    /* 1EEA38 002EEA38 3F841000 */  dsra32     $16, $16, 16
    /* 1EEA3C 002EEA3C 6C2D040C */  jal        func_0010b5b0
    /* 1EEA40 002EEA40 00000000 */   nop
    /* 1EEA44 002EEA44 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1EEA48 002EEA48 2A100202 */  slt        $2, $16, $2
    /* 1EEA4C 002EEA4C B1FF4014 */  bnez       $2, .L002EE914
    /* 1EEA50 002EEA50 00000000 */   nop
    /* 1EEA54 002EEA54 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EEA58 002EEA58 00608244 */  mtc1       $2, $f12
    /* 1EEA5C 002EEA5C D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EEA60 002EEA60 00688244 */  mtc1       $2, $f13
    /* 1EEA64 002EEA64 0802A427 */  addiu      $4, $29, 0x208
    /* 1EEA68 002EEA68 5CCA0A0C */  jal        func_002b2970
    /* 1EEA6C 002EEA6C 00000000 */   nop
    /* 1EEA70 002EEA70 2D208002 */  daddu      $4, $20, $0
    /* 1EEA74 002EEA74 0802A5DF */  ld         $5, 0x208($29)
    /* 1EEA78 002EEA78 2D300000 */  daddu      $6, $0, $0
    /* 1EEA7C 002EEA7C 01000724 */  addiu      $7, $0, 0x1
    /* 1EEA80 002EEA80 2D400000 */  daddu      $8, $0, $0
    /* 1EEA84 002EEA84 2D480000 */  daddu      $9, $0, $0
    /* 1EEA88 002EEA88 2D500000 */  daddu      $10, $0, $0
    /* 1EEA8C 002EEA8C 6C790C0C */  jal        func_0031e5b0
    /* 1EEA90 002EEA90 00000000 */   nop
    /* 1EEA94 002EEA94 49010224 */  addiu      $2, $0, 0x149
    /* 1EEA98 002EEA98 00008244 */  mtc1       $2, $f0
    /* 1EEA9C 002EEA9C 00000000 */  nop
    /* 1EEAA0 002EEAA0 20038046 */  cvt.s.w    $f12, $f0
    /* 1EEAA4 002EEAA4 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EEAA8 002EEAA8 00688244 */  mtc1       $2, $f13
    /* 1EEAAC 002EEAAC 0002A427 */  addiu      $4, $29, 0x200
    /* 1EEAB0 002EEAB0 5CCA0A0C */  jal        func_002b2970
    /* 1EEAB4 002EEAB4 00000000 */   nop
    /* 1EEAB8 002EEAB8 2D208002 */  daddu      $4, $20, $0
    /* 1EEABC 002EEABC 0002A5DF */  ld         $5, 0x200($29)
    /* 1EEAC0 002EEAC0 2D300000 */  daddu      $6, $0, $0
    /* 1EEAC4 002EEAC4 01000724 */  addiu      $7, $0, 0x1
    /* 1EEAC8 002EEAC8 887E0C0C */  jal        func_0031fa20
    /* 1EEACC 002EEACC 00000000 */   nop
    /* 1EEAD0 002EEAD0 2D208002 */  daddu      $4, $20, $0
    /* 1EEAD4 002EEAD4 01000524 */  addiu      $5, $0, 0x1
    /* 1EEAD8 002EEAD8 2D30A000 */  daddu      $6, $5, $0
    /* 1EEADC 002EEADC 1C590C0C */  jal        func_00316470
    /* 1EEAE0 002EEAE0 00000000 */   nop
    /* 1EEAE4 002EEAE4 0000A0FF */  sd         $0, 0x0($29)
    /* 1EEAE8 002EEAE8 0800A0FF */  sd         $0, 0x8($29)
    /* 1EEAEC 002EEAEC 1000A0FF */  sd         $0, 0x10($29)
    /* 1EEAF0 002EEAF0 2D208002 */  daddu      $4, $20, $0
    /* 1EEAF4 002EEAF4 2D280000 */  daddu      $5, $0, $0
    /* 1EEAF8 002EEAF8 2D300000 */  daddu      $6, $0, $0
    /* 1EEAFC 002EEAFC 2D380000 */  daddu      $7, $0, $0
    /* 1EEB00 002EEB00 2D400000 */  daddu      $8, $0, $0
    /* 1EEB04 002EEB04 01000924 */  addiu      $9, $0, 0x1
    /* 1EEB08 002EEB08 2D502001 */  daddu      $10, $9, $0
    /* 1EEB0C 002EEB0C 2D580000 */  daddu      $11, $0, $0
    /* 1EEB10 002EEB10 A05B0C0C */  jal        func_00316e80
    /* 1EEB14 002EEB14 00000000 */   nop
    /* 1EEB18 002EEB18 00608044 */  mtc1       $0, $f12
    /* 1EEB1C 002EEB1C 2D208002 */  daddu      $4, $20, $0
    /* 1EEB20 002EEB20 2D280000 */  daddu      $5, $0, $0
    /* 1EEB24 002EEB24 905C0C0C */  jal        func_00317240
    /* 1EEB28 002EEB28 00000000 */   nop
    /* 1EEB2C 002EEB2C 8C02448E */  lw         $4, 0x28C($18)
    /* 1EEB30 002EEB30 01000524 */  addiu      $5, $0, 0x1
    /* 1EEB34 002EEB34 50D80A0C */  jal        func_002b6140
    /* 1EEB38 002EEB38 00000000 */   nop
    /* 1EEB3C 002EEB3C 9002448E */  lw         $4, 0x290($18)
    /* 1EEB40 002EEB40 01000524 */  addiu      $5, $0, 0x1
    /* 1EEB44 002EEB44 50D80A0C */  jal        func_002b6140
    /* 1EEB48 002EEB48 00000000 */   nop
    /* 1EEB4C 002EEB4C 2E000324 */  addiu      $3, $0, 0x2E
    /* 1EEB50 002EEB50 010043A2 */  sb         $3, 0x1($18)
    /* 1EEB54 002EEB54 DA080010 */  b          .L002F0EC0
    /* 1EEB58 002EEB58 00000000 */   nop
  .L002EEB5C:
    /* 1EEB5C 002EEB5C 2D200000 */  daddu      $4, $0, $0
    /* 1EEB60 002EEB60 2D280000 */  daddu      $5, $0, $0
    /* 1EEB64 002EEB64 2D300000 */  daddu      $6, $0, $0
    /* 1EEB68 002EEB68 08000724 */  addiu      $7, $0, 0x8
    /* 1EEB6C 002EEB6C D86B110C */  jal        func_0045af60
    /* 1EEB70 002EEB70 00000000 */   nop
    /* 1EEB74 002EEB74 D2080010 */  b          .L002F0EC0
    /* 1EEB78 002EEB78 00000000 */   nop
  .L002EEB7C:
    /* 1EEB7C 002EEB7C 8C00033C */  lui        $3, %hi(D_008C024C)
    /* 1EEB80 002EEB80 4C026394 */  lhu        $3, %lo(D_008C024C)($3)
    /* 1EEB84 002EEB84 80006330 */  andi       $3, $3, 0x80
    /* 1EEB88 002EEB88 A5006010 */  beqz       $3, .L002EEE20
    /* 1EEB8C 002EEB8C 00000000 */   nop
    /* 1EEB90 002EEB90 1E015086 */  lh         $16, 0x11E($18)
    /* 1EEB94 002EEB94 2D200000 */  daddu      $4, $0, $0
    /* 1EEB98 002EEB98 1C920B0C */  jal        func_002e4870
    /* 1EEB9C 002EEB9C 00000000 */   nop
    /* 1EEBA0 002EEBA0 0800438C */  lw         $3, 0x8($2)
    /* 1EEBA4 002EEBA4 2A080302 */  slt        $1, $16, $3
    /* 1EEBA8 002EEBA8 C5082010 */  beqz       $1, .L002F0EC0
    /* 1EEBAC 002EEBAC 00000000 */   nop
    /* 1EEBB0 002EEBB0 2D200000 */  daddu      $4, $0, $0
    /* 1EEBB4 002EEBB4 01000524 */  addiu      $5, $0, 0x1
    /* 1EEBB8 002EEBB8 2D300000 */  daddu      $6, $0, $0
    /* 1EEBBC 002EEBBC 03000724 */  addiu      $7, $0, 0x3
    /* 1EEBC0 002EEBC0 D86B110C */  jal        func_0045af60
    /* 1EEBC4 002EEBC4 00000000 */   nop
    /* 1EEBC8 002EEBC8 2D880000 */  daddu      $17, $0, $0
    /* 1EEBCC 002EEBCC 49000010 */  b          .L002EECF4
    /* 1EEBD0 002EEBD0 00000000 */   nop
  .L002EEBD4:
    /* 1EEBD4 002EEBD4 49010224 */  addiu      $2, $0, 0x149
    /* 1EEBD8 002EEBD8 00008244 */  mtc1       $2, $f0
    /* 1EEBDC 002EEBDC 00000000 */  nop
    /* 1EEBE0 002EEBE0 20038046 */  cvt.s.w    $f12, $f0
    /* 1EEBE4 002EEBE4 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EEBE8 002EEBE8 00688244 */  mtc1       $2, $f13
    /* 1EEBEC 002EEBEC F801A427 */  addiu      $4, $29, 0x1F8
    /* 1EEBF0 002EEBF0 5CCA0A0C */  jal        func_002b2970
    /* 1EEBF4 002EEBF4 00000000 */   nop
    /* 1EEBF8 002EEBF8 28014282 */  lb         $2, 0x128($18)
    /* 1EEBFC 002EEBFC 01004224 */  addiu      $2, $2, 0x1
    /* 1EEC00 002EEC00 3C260200 */  dsll32     $4, $2, 24
    /* 1EEC04 002EEC04 3F260400 */  dsra32     $4, $4, 24
    /* 1EEC08 002EEC08 2D282002 */  daddu      $5, $17, $0
    /* 1EEC0C 002EEC0C 28920B0C */  jal        func_002e48a0
    /* 1EEC10 002EEC10 00000000 */   nop
    /* 1EEC14 002EEC14 02005094 */  lhu        $16, 0x2($2)
    /* 1EEC18 002EEC18 28014282 */  lb         $2, 0x128($18)
    /* 1EEC1C 002EEC1C 01004224 */  addiu      $2, $2, 0x1
    /* 1EEC20 002EEC20 3C260200 */  dsll32     $4, $2, 24
    /* 1EEC24 002EEC24 3F260400 */  dsra32     $4, $4, 24
    /* 1EEC28 002EEC28 2D282002 */  daddu      $5, $17, $0
    /* 1EEC2C 002EEC2C 28920B0C */  jal        func_002e48a0
    /* 1EEC30 002EEC30 00000000 */   nop
    /* 1EEC34 002EEC34 04004990 */  lbu        $9, 0x4($2)
    /* 1EEC38 002EEC38 01000B24 */  addiu      $11, $0, 0x1
    /* 1EEC3C 002EEC3C 0000ABFF */  sd         $11, 0x0($29)
    /* 1EEC40 002EEC40 CC000224 */  addiu      $2, $0, 0xCC
    /* 1EEC44 002EEC44 0800A2FF */  sd         $2, 0x8($29)
    /* 1EEC48 002EEC48 3C3E1100 */  dsll32     $7, $17, 24
    /* 1EEC4C 002EEC4C 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EEC50 002EEC50 2D208002 */  daddu      $4, $20, $0
    /* 1EEC54 002EEC54 F801A5DF */  ld         $5, 0x1F8($29)
    /* 1EEC58 002EEC58 28014682 */  lb         $6, 0x128($18)
    /* 1EEC5C 002EEC5C 2D400002 */  daddu      $8, $16, $0
    /* 1EEC60 002EEC60 2D500000 */  daddu      $10, $0, $0
    /* 1EEC64 002EEC64 046B0C0C */  jal        func_0031ac10
    /* 1EEC68 002EEC68 00000000 */   nop
    /* 1EEC6C 002EEC6C 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EEC70 002EEC70 00608244 */  mtc1       $2, $f12
    /* 1EEC74 002EEC74 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EEC78 002EEC78 00688244 */  mtc1       $2, $f13
    /* 1EEC7C 002EEC7C F001A427 */  addiu      $4, $29, 0x1F0
    /* 1EEC80 002EEC80 5CCA0A0C */  jal        func_002b2970
    /* 1EEC84 002EEC84 00000000 */   nop
    /* 1EEC88 002EEC88 2D200000 */  daddu      $4, $0, $0
    /* 1EEC8C 002EEC8C 2D282002 */  daddu      $5, $17, $0
    /* 1EEC90 002EEC90 28920B0C */  jal        func_002e48a0
    /* 1EEC94 002EEC94 00000000 */   nop
    /* 1EEC98 002EEC98 02005394 */  lhu        $19, 0x2($2)
    /* 1EEC9C 002EEC9C 2D200000 */  daddu      $4, $0, $0
    /* 1EECA0 002EECA0 2D282002 */  daddu      $5, $17, $0
    /* 1EECA4 002EECA4 28920B0C */  jal        func_002e48a0
    /* 1EECA8 002EECA8 00000000 */   nop
    /* 1EECAC 002EECAC 04005090 */  lbu        $16, 0x4($2)
    /* 1EECB0 002EECB0 2D200000 */  daddu      $4, $0, $0
    /* 1EECB4 002EECB4 1C920B0C */  jal        func_002e4870
    /* 1EECB8 002EECB8 00000000 */   nop
    /* 1EECBC 002EECBC 08004B80 */  lb         $11, 0x8($2)
    /* 1EECC0 002EECC0 3C361100 */  dsll32     $6, $17, 24
    /* 1EECC4 002EECC4 3F360600 */  dsra32     $6, $6, 24
    /* 1EECC8 002EECC8 2D208002 */  daddu      $4, $20, $0
    /* 1EECCC 002EECCC F001A5DF */  ld         $5, 0x1F0($29)
    /* 1EECD0 002EECD0 2D386002 */  daddu      $7, $19, $0
    /* 1EECD4 002EECD4 2D400002 */  daddu      $8, $16, $0
    /* 1EECD8 002EECD8 2D480000 */  daddu      $9, $0, $0
    /* 1EECDC 002EECDC 01000A24 */  addiu      $10, $0, 0x1
    /* 1EECE0 002EECE0 70640C0C */  jal        func_003191c0
    /* 1EECE4 002EECE4 00000000 */   nop
    /* 1EECE8 002EECE8 01002226 */  addiu      $2, $17, 0x1
    /* 1EECEC 002EECEC 3C8C0200 */  dsll32     $17, $2, 16
    /* 1EECF0 002EECF0 3F8C1100 */  dsra32     $17, $17, 16
  .L002EECF4:
    /* 1EECF4 002EECF4 3C841100 */  dsll32     $16, $17, 16
    /* 1EECF8 002EECF8 3F841000 */  dsra32     $16, $16, 16
    /* 1EECFC 002EECFC 6C2D040C */  jal        func_0010b5b0
    /* 1EED00 002EED00 00000000 */   nop
    /* 1EED04 002EED04 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1EED08 002EED08 2A100202 */  slt        $2, $16, $2
    /* 1EED0C 002EED0C B1FF4014 */  bnez       $2, .L002EEBD4
    /* 1EED10 002EED10 00000000 */   nop
    /* 1EED14 002EED14 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EED18 002EED18 00608244 */  mtc1       $2, $f12
    /* 1EED1C 002EED1C D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EED20 002EED20 00688244 */  mtc1       $2, $f13
    /* 1EED24 002EED24 E801A427 */  addiu      $4, $29, 0x1E8
    /* 1EED28 002EED28 5CCA0A0C */  jal        func_002b2970
    /* 1EED2C 002EED2C 00000000 */   nop
    /* 1EED30 002EED30 2D208002 */  daddu      $4, $20, $0
    /* 1EED34 002EED34 E801A5DF */  ld         $5, 0x1E8($29)
    /* 1EED38 002EED38 2D300000 */  daddu      $6, $0, $0
    /* 1EED3C 002EED3C 01000724 */  addiu      $7, $0, 0x1
    /* 1EED40 002EED40 2D400000 */  daddu      $8, $0, $0
    /* 1EED44 002EED44 2D480000 */  daddu      $9, $0, $0
    /* 1EED48 002EED48 2D500000 */  daddu      $10, $0, $0
    /* 1EED4C 002EED4C 6C790C0C */  jal        func_0031e5b0
    /* 1EED50 002EED50 00000000 */   nop
    /* 1EED54 002EED54 49010224 */  addiu      $2, $0, 0x149
    /* 1EED58 002EED58 00008244 */  mtc1       $2, $f0
    /* 1EED5C 002EED5C 00000000 */  nop
    /* 1EED60 002EED60 20038046 */  cvt.s.w    $f12, $f0
    /* 1EED64 002EED64 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EED68 002EED68 00688244 */  mtc1       $2, $f13
    /* 1EED6C 002EED6C E001A427 */  addiu      $4, $29, 0x1E0
    /* 1EED70 002EED70 5CCA0A0C */  jal        func_002b2970
    /* 1EED74 002EED74 00000000 */   nop
    /* 1EED78 002EED78 2D208002 */  daddu      $4, $20, $0
    /* 1EED7C 002EED7C E001A5DF */  ld         $5, 0x1E0($29)
    /* 1EED80 002EED80 2D300000 */  daddu      $6, $0, $0
    /* 1EED84 002EED84 01000724 */  addiu      $7, $0, 0x1
    /* 1EED88 002EED88 887E0C0C */  jal        func_0031fa20
    /* 1EED8C 002EED8C 00000000 */   nop
    /* 1EED90 002EED90 2D208002 */  daddu      $4, $20, $0
    /* 1EED94 002EED94 01000524 */  addiu      $5, $0, 0x1
    /* 1EED98 002EED98 2D30A000 */  daddu      $6, $5, $0
    /* 1EED9C 002EED9C 1C590C0C */  jal        func_00316470
    /* 1EEDA0 002EEDA0 00000000 */   nop
    /* 1EEDA4 002EEDA4 0000A0FF */  sd         $0, 0x0($29)
    /* 1EEDA8 002EEDA8 0800A0FF */  sd         $0, 0x8($29)
    /* 1EEDAC 002EEDAC 1000A0FF */  sd         $0, 0x10($29)
    /* 1EEDB0 002EEDB0 2D208002 */  daddu      $4, $20, $0
    /* 1EEDB4 002EEDB4 01000524 */  addiu      $5, $0, 0x1
    /* 1EEDB8 002EEDB8 2D30A000 */  daddu      $6, $5, $0
    /* 1EEDBC 002EEDBC 2D380000 */  daddu      $7, $0, $0
    /* 1EEDC0 002EEDC0 2D400000 */  daddu      $8, $0, $0
    /* 1EEDC4 002EEDC4 2D48A000 */  daddu      $9, $5, $0
    /* 1EEDC8 002EEDC8 2D50A000 */  daddu      $10, $5, $0
    /* 1EEDCC 002EEDCC 2D580000 */  daddu      $11, $0, $0
    /* 1EEDD0 002EEDD0 A05B0C0C */  jal        func_00316e80
    /* 1EEDD4 002EEDD4 00000000 */   nop
    /* 1EEDD8 002EEDD8 7042023C */  lui        $2, (0x42700000 >> 16)
    /* 1EEDDC 002EEDDC 00608244 */  mtc1       $2, $f12
    /* 1EEDE0 002EEDE0 2D208002 */  daddu      $4, $20, $0
    /* 1EEDE4 002EEDE4 2D280000 */  daddu      $5, $0, $0
    /* 1EEDE8 002EEDE8 905C0C0C */  jal        func_00317240
    /* 1EEDEC 002EEDEC 00000000 */   nop
    /* 1EEDF0 002EEDF0 8C02448E */  lw         $4, 0x28C($18)
    /* 1EEDF4 002EEDF4 01000524 */  addiu      $5, $0, 0x1
    /* 1EEDF8 002EEDF8 50D80A0C */  jal        func_002b6140
    /* 1EEDFC 002EEDFC 00000000 */   nop
    /* 1EEE00 002EEE00 9002448E */  lw         $4, 0x290($18)
    /* 1EEE04 002EEE04 01000524 */  addiu      $5, $0, 0x1
    /* 1EEE08 002EEE08 50D80A0C */  jal        func_002b6140
    /* 1EEE0C 002EEE0C 00000000 */   nop
    /* 1EEE10 002EEE10 2B000324 */  addiu      $3, $0, 0x2B
    /* 1EEE14 002EEE14 010043A2 */  sb         $3, 0x1($18)
    /* 1EEE18 002EEE18 29080010 */  b          .L002F0EC0
    /* 1EEE1C 002EEE1C 00000000 */   nop
  .L002EEE20:
    /* 1EEE20 002EEE20 20008330 */  andi       $3, $4, 0x20
    /* 1EEE24 002EEE24 26086010 */  beqz       $3, .L002F0EC0
    /* 1EEE28 002EEE28 00000000 */   nop
    /* 1EEE2C 002EEE2C 1E014582 */  lb         $5, 0x11E($18)
    /* 1EEE30 002EEE30 2D208002 */  daddu      $4, $20, $0
    /* 1EEE34 002EEE34 2D300000 */  daddu      $6, $0, $0
    /* 1EEE38 002EEE38 FF000724 */  addiu      $7, $0, 0xFF
    /* 1EEE3C 002EEE3C 7C770C0C */  jal        func_0031ddf0
    /* 1EEE40 002EEE40 00000000 */   nop
    /* 1EEE44 002EEE44 28014282 */  lb         $2, 0x128($18)
    /* 1EEE48 002EEE48 1E0142A6 */  sh         $2, 0x11E($18)
    /* 1EEE4C 002EEE4C 2D284000 */  daddu      $5, $2, $0
    /* 1EEE50 002EEE50 2D208002 */  daddu      $4, $20, $0
    /* 1EEE54 002EEE54 01000624 */  addiu      $6, $0, 0x1
    /* 1EEE58 002EEE58 FF000724 */  addiu      $7, $0, 0xFF
    /* 1EEE5C 002EEE5C 7C770C0C */  jal        func_0031ddf0
    /* 1EEE60 002EEE60 00000000 */   nop
    /* 1EEE64 002EEE64 2D200000 */  daddu      $4, $0, $0
    /* 1EEE68 002EEE68 2D280000 */  daddu      $5, $0, $0
    /* 1EEE6C 002EEE6C 2D300000 */  daddu      $6, $0, $0
    /* 1EEE70 002EEE70 02000724 */  addiu      $7, $0, 0x2
    /* 1EEE74 002EEE74 D86B110C */  jal        func_0045af60
    /* 1EEE78 002EEE78 00000000 */   nop
    /* 1EEE7C 002EEE7C 2D208002 */  daddu      $4, $20, $0
    /* 1EEE80 002EEE80 93000524 */  addiu      $5, $0, 0x93
    /* 1EEE84 002EEE84 94000624 */  addiu      $6, $0, 0x94
    /* 1EEE88 002EEE88 7C810C0C */  jal        func_003205f0
    /* 1EEE8C 002EEE8C 00000000 */   nop
    /* 1EEE90 002EEE90 6400103C */  lui        $16, %hi(D_00640C10)
    /* 1EEE94 002EEE94 100C1026 */  addiu      $16, $16, %lo(D_00640C10)
    /* 1EEE98 002EEE98 D801A427 */  addiu      $4, $29, 0x1D8
    /* 1EEE9C 002EEE9C 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EEEA0 002EEEA0 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EEEA4 002EEEA4 5CCA0A0C */  jal        func_002b2970
    /* 1EEEA8 002EEEA8 00000000 */   nop
    /* 1EEEAC 002EEEAC BEC3023C */  lui        $2, (0xC3BE0000 >> 16)
    /* 1EEEB0 002EEEB0 00608244 */  mtc1       $2, $f12
    /* 1EEEB4 002EEEB4 D001A427 */  addiu      $4, $29, 0x1D0
    /* 1EEEB8 002EEEB8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EEEBC 002EEEBC 5CCA0A0C */  jal        func_002b2970
    /* 1EEEC0 002EEEC0 00000000 */   nop
    /* 1EEEC4 002EEEC4 28014582 */  lb         $5, 0x128($18)
    /* 1EEEC8 002EEEC8 2D208002 */  daddu      $4, $20, $0
    /* 1EEECC 002EEECC D801A6DF */  ld         $6, 0x1D8($29)
    /* 1EEED0 002EEED0 D001A7DF */  ld         $7, 0x1D0($29)
    /* 1EEED4 002EEED4 AC700C0C */  jal        func_0031c2b0
    /* 1EEED8 002EEED8 00000000 */   nop
    /* 1EEEDC 002EEEDC 49010224 */  addiu      $2, $0, 0x149
    /* 1EEEE0 002EEEE0 00008244 */  mtc1       $2, $f0
    /* 1EEEE4 002EEEE4 00000000 */  nop
    /* 1EEEE8 002EEEE8 20038046 */  cvt.s.w    $f12, $f0
    /* 1EEEEC 002EEEEC D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EEEF0 002EEEF0 00688244 */  mtc1       $2, $f13
    /* 1EEEF4 002EEEF4 C801A427 */  addiu      $4, $29, 0x1C8
    /* 1EEEF8 002EEEF8 5CCA0A0C */  jal        func_002b2970
    /* 1EEEFC 002EEEFC 00000000 */   nop
    /* 1EEF00 002EEF00 2D208002 */  daddu      $4, $20, $0
    /* 1EEF04 002EEF04 C801A5DF */  ld         $5, 0x1C8($29)
    /* 1EEF08 002EEF08 2D300000 */  daddu      $6, $0, $0
    /* 1EEF0C 002EEF0C 01000724 */  addiu      $7, $0, 0x1
    /* 1EEF10 002EEF10 887E0C0C */  jal        func_0031fa20
    /* 1EEF14 002EEF14 00000000 */   nop
    /* 1EEF18 002EEF18 2D880000 */  daddu      $17, $0, $0
    /* 1EEF1C 002EEF1C 2A000010 */  b          .L002EEFC8
    /* 1EEF20 002EEF20 00000000 */   nop
  .L002EEF24:
    /* 1EEF24 002EEF24 49010224 */  addiu      $2, $0, 0x149
    /* 1EEF28 002EEF28 00008244 */  mtc1       $2, $f0
    /* 1EEF2C 002EEF2C 00000000 */  nop
    /* 1EEF30 002EEF30 20038046 */  cvt.s.w    $f12, $f0
    /* 1EEF34 002EEF34 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EEF38 002EEF38 00688244 */  mtc1       $2, $f13
    /* 1EEF3C 002EEF3C C001A427 */  addiu      $4, $29, 0x1C0
    /* 1EEF40 002EEF40 5CCA0A0C */  jal        func_002b2970
    /* 1EEF44 002EEF44 00000000 */   nop
    /* 1EEF48 002EEF48 28014282 */  lb         $2, 0x128($18)
    /* 1EEF4C 002EEF4C 01004224 */  addiu      $2, $2, 0x1
    /* 1EEF50 002EEF50 3C260200 */  dsll32     $4, $2, 24
    /* 1EEF54 002EEF54 3F260400 */  dsra32     $4, $4, 24
    /* 1EEF58 002EEF58 2D282002 */  daddu      $5, $17, $0
    /* 1EEF5C 002EEF5C 28920B0C */  jal        func_002e48a0
    /* 1EEF60 002EEF60 00000000 */   nop
    /* 1EEF64 002EEF64 02005094 */  lhu        $16, 0x2($2)
    /* 1EEF68 002EEF68 28014282 */  lb         $2, 0x128($18)
    /* 1EEF6C 002EEF6C 01004224 */  addiu      $2, $2, 0x1
    /* 1EEF70 002EEF70 3C260200 */  dsll32     $4, $2, 24
    /* 1EEF74 002EEF74 3F260400 */  dsra32     $4, $4, 24
    /* 1EEF78 002EEF78 2D282002 */  daddu      $5, $17, $0
    /* 1EEF7C 002EEF7C 28920B0C */  jal        func_002e48a0
    /* 1EEF80 002EEF80 00000000 */   nop
    /* 1EEF84 002EEF84 04004990 */  lbu        $9, 0x4($2)
    /* 1EEF88 002EEF88 01000B24 */  addiu      $11, $0, 0x1
    /* 1EEF8C 002EEF8C 0000ABFF */  sd         $11, 0x0($29)
    /* 1EEF90 002EEF90 CC000224 */  addiu      $2, $0, 0xCC
    /* 1EEF94 002EEF94 0800A2FF */  sd         $2, 0x8($29)
    /* 1EEF98 002EEF98 3C3E1100 */  dsll32     $7, $17, 24
    /* 1EEF9C 002EEF9C 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EEFA0 002EEFA0 2D208002 */  daddu      $4, $20, $0
    /* 1EEFA4 002EEFA4 C001A5DF */  ld         $5, 0x1C0($29)
    /* 1EEFA8 002EEFA8 28014682 */  lb         $6, 0x128($18)
    /* 1EEFAC 002EEFAC 2D400002 */  daddu      $8, $16, $0
    /* 1EEFB0 002EEFB0 2D500000 */  daddu      $10, $0, $0
    /* 1EEFB4 002EEFB4 046B0C0C */  jal        func_0031ac10
    /* 1EEFB8 002EEFB8 00000000 */   nop
    /* 1EEFBC 002EEFBC 01002226 */  addiu      $2, $17, 0x1
    /* 1EEFC0 002EEFC0 3C8C0200 */  dsll32     $17, $2, 16
    /* 1EEFC4 002EEFC4 3F8C1100 */  dsra32     $17, $17, 16
  .L002EEFC8:
    /* 1EEFC8 002EEFC8 3C841100 */  dsll32     $16, $17, 16
    /* 1EEFCC 002EEFCC 3F841000 */  dsra32     $16, $16, 16
    /* 1EEFD0 002EEFD0 6C2D040C */  jal        func_0010b5b0
    /* 1EEFD4 002EEFD4 00000000 */   nop
    /* 1EEFD8 002EEFD8 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1EEFDC 002EEFDC 2A100202 */  slt        $2, $16, $2
    /* 1EEFE0 002EEFE0 D0FF4014 */  bnez       $2, .L002EEF24
    /* 1EEFE4 002EEFE4 00000000 */   nop
    /* 1EEFE8 002EEFE8 2D208002 */  daddu      $4, $20, $0
    /* 1EEFEC 002EEFEC 03000524 */  addiu      $5, $0, 0x3
    /* 1EEFF0 002EEFF0 28860C0C */  jal        func_003218a0
    /* 1EEFF4 002EEFF4 00000000 */   nop
    /* 1EEFF8 002EEFF8 27000324 */  addiu      $3, $0, 0x27
    /* 1EEFFC 002EEFFC 010043A2 */  sb         $3, 0x1($18)
    /* 1EF000 002EF000 AF070010 */  b          .L002F0EC0
    /* 1EF004 002EF004 00000000 */   nop
    /* 1EF008 002EF008 7C000424 */  addiu      $4, $0, 0x7C
    /* 1EF00C 002EF00C 54D80A0C */  jal        func_002b6150
    /* 1EF010 002EF010 00000000 */   nop
    /* 1EF014 002EF014 380041C4 */  lwc1       $f1, 0x38($2)
    /* 1EF018 002EF018 3C0040C4 */  lwc1       $f0, 0x3C($2)
    /* 1EF01C 002EF01C 5001A1E7 */  swc1       $f1, 0x150($29)
    /* 1EF020 002EF020 5401A0E7 */  swc1       $f0, 0x154($29)
    /* 1EF024 002EF024 CC000424 */  addiu      $4, $0, 0xCC
    /* 1EF028 002EF028 FF000524 */  addiu      $5, $0, 0xFF
    /* 1EF02C 002EF02C 2D30A000 */  daddu      $6, $5, $0
    /* 1EF030 002EF030 2D38A000 */  daddu      $7, $5, $0
    /* 1EF034 002EF034 8CCA0A0C */  jal        func_002b2a30
    /* 1EF038 002EF038 00000000 */   nop
    /* 1EF03C 002EF03C 2D804000 */  daddu      $16, $2, $0
    /* 1EF040 002EF040 28014582 */  lb         $5, 0x128($18)
    /* 1EF044 002EF044 2D200000 */  daddu      $4, $0, $0
    /* 1EF048 002EF048 28920B0C */  jal        func_002e48a0
    /* 1EF04C 002EF04C 00000000 */   nop
    /* 1EF050 002EF050 02004394 */  lhu        $3, 0x2($2)
    /* 1EF054 002EF054 00110300 */  sll        $2, $3, 4
    /* 1EF058 002EF058 21184300 */  addu       $3, $2, $3
    /* 1EF05C 002EF05C 40B4828F */  lw         $2, -0x4BC0($28)
    /* 1EF060 002EF060 21384300 */  addu       $7, $2, $3
    /* 1EF064 002EF064 DE42023C */  lui        $2, (0x42DE0000 >> 16)
    /* 1EF068 002EF068 00088244 */  mtc1       $2, $f1
    /* 1EF06C 002EF06C 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* 1EF070 002EF070 000B0046 */  add.s      $f12, $f1, $f0
    /* 1EF074 002EF074 2C42023C */  lui        $2, (0x422C0000 >> 16)
    /* 1EF078 002EF078 00708244 */  mtc1       $2, $f14
    /* 1EF07C 002EF07C 5401ADC7 */  lwc1       $f13, 0x154($29)
    /* 1EF080 002EF080 2D200002 */  daddu      $4, $16, $0
    /* 1EF084 002EF084 2D280000 */  daddu      $5, $0, $0
    /* 1EF088 002EF088 02000624 */  addiu      $6, $0, 0x2
    /* 1EF08C 002EF08C 2D400000 */  daddu      $8, $0, $0
    /* 1EF090 002EF090 2D480000 */  daddu      $9, $0, $0
    /* 1EF094 002EF094 79000A3C */  lui        $10, %hi(D_00795E60)
    /* 1EF098 002EF098 605E4A25 */  addiu      $10, $10, %lo(D_00795E60)
    /* 1EF09C 002EF09C 15000B24 */  addiu      $11, $0, 0x15
    /* 1EF0A0 002EF0A0 08D6090C */  jal        func_00275820
    /* 1EF0A4 002EF0A4 00000000 */   nop
    /* 1EF0A8 002EF0A8 1C020424 */  addiu      $4, $0, 0x21C
    /* 1EF0AC 002EF0AC 54D80A0C */  jal        func_002b6150
    /* 1EF0B0 002EF0B0 00000000 */   nop
    /* 1EF0B4 002EF0B4 10004484 */  lh         $4, 0x10($2)
    /* 1EF0B8 002EF0B8 01000524 */  addiu      $5, $0, 0x1
    /* 1EF0BC 002EF0BC 5CDA0A0C */  jal        func_002b6970
    /* 1EF0C0 002EF0C0 00000000 */   nop
    /* 1EF0C4 002EF0C4 3C240200 */  dsll32     $4, $2, 16
    /* 1EF0C8 002EF0C8 3F240400 */  dsra32     $4, $4, 16
    /* 1EF0CC 002EF0CC 01000324 */  addiu      $3, $0, 0x1
    /* 1EF0D0 002EF0D0 7B078310 */  beq        $4, $3, .L002F0EC0
    /* 1EF0D4 002EF0D4 00000000 */   nop
    /* 1EF0D8 002EF0D8 2D200000 */  daddu      $4, $0, $0
    /* 1EF0DC 002EF0DC 1E014586 */  lh         $5, 0x11E($18)
    /* 1EF0E0 002EF0E0 28920B0C */  jal        func_002e48a0
    /* 1EF0E4 002EF0E4 00000000 */   nop
    /* 1EF0E8 002EF0E8 4801448E */  lw         $4, 0x148($18)
    /* 1EF0EC 002EF0EC 2D284000 */  daddu      $5, $2, $0
    /* 1EF0F0 002EF0F0 2D300000 */  daddu      $6, $0, $0
    /* 1EF0F4 002EF0F4 2D380000 */  daddu      $7, $0, $0
    /* 1EF0F8 002EF0F8 14510C0C */  jal        func_00314450
    /* 1EF0FC 002EF0FC 00000000 */   nop
    /* 1EF100 002EF100 4801448E */  lw         $4, 0x148($18)
    /* 1EF104 002EF104 F4510C0C */  jal        func_003147d0
    /* 1EF108 002EF108 00000000 */   nop
    /* 1EF10C 002EF10C 2D204000 */  daddu      $4, $2, $0
    /* 1EF110 002EF110 01000524 */  addiu      $5, $0, 0x1
    /* 1EF114 002EF114 B871040C */  jal        func_0011c6e0
    /* 1EF118 002EF118 00000000 */   nop
    /* 1EF11C 002EF11C 4801448E */  lw         $4, 0x148($18)
    /* 1EF120 002EF120 F4510C0C */  jal        func_003147d0
    /* 1EF124 002EF124 00000000 */   nop
    /* 1EF128 002EF128 2D804000 */  daddu      $16, $2, $0
    /* 1EF12C 002EF12C FF000424 */  addiu      $4, $0, 0xFF
    /* 1EF130 002EF130 2D288000 */  daddu      $5, $4, $0
    /* 1EF134 002EF134 2D308000 */  daddu      $6, $4, $0
    /* 1EF138 002EF138 2D388000 */  daddu      $7, $4, $0
    /* 1EF13C 002EF13C 8CCA0A0C */  jal        func_002b2a30
    /* 1EF140 002EF140 00000000 */   nop
    /* 1EF144 002EF144 2D200002 */  daddu      $4, $16, $0
    /* 1EF148 002EF148 2D284000 */  daddu      $5, $2, $0
    /* 1EF14C 002EF14C 5074040C */  jal        func_0011d140
    /* 1EF150 002EF150 00000000 */   nop
    /* 1EF154 002EF154 2C000324 */  addiu      $3, $0, 0x2C
    /* 1EF158 002EF158 010043A2 */  sb         $3, 0x1($18)
    /* 1EF15C 002EF15C 58070010 */  b          .L002F0EC0
    /* 1EF160 002EF160 00000000 */   nop
    /* 1EF164 002EF164 7C000424 */  addiu      $4, $0, 0x7C
    /* 1EF168 002EF168 54D80A0C */  jal        func_002b6150
    /* 1EF16C 002EF16C 00000000 */   nop
    /* 1EF170 002EF170 380041C4 */  lwc1       $f1, 0x38($2)
    /* 1EF174 002EF174 3C0040C4 */  lwc1       $f0, 0x3C($2)
    /* 1EF178 002EF178 4801A1E7 */  swc1       $f1, 0x148($29)
    /* 1EF17C 002EF17C 4C01A0E7 */  swc1       $f0, 0x14C($29)
    /* 1EF180 002EF180 CC000424 */  addiu      $4, $0, 0xCC
    /* 1EF184 002EF184 FF000524 */  addiu      $5, $0, 0xFF
    /* 1EF188 002EF188 2D30A000 */  daddu      $6, $5, $0
    /* 1EF18C 002EF18C 2D38A000 */  daddu      $7, $5, $0
    /* 1EF190 002EF190 8CCA0A0C */  jal        func_002b2a30
    /* 1EF194 002EF194 00000000 */   nop
    /* 1EF198 002EF198 2D804000 */  daddu      $16, $2, $0
    /* 1EF19C 002EF19C 28014582 */  lb         $5, 0x128($18)
    /* 1EF1A0 002EF1A0 2D200000 */  daddu      $4, $0, $0
    /* 1EF1A4 002EF1A4 28920B0C */  jal        func_002e48a0
    /* 1EF1A8 002EF1A8 00000000 */   nop
    /* 1EF1AC 002EF1AC 02004394 */  lhu        $3, 0x2($2)
    /* 1EF1B0 002EF1B0 00110300 */  sll        $2, $3, 4
    /* 1EF1B4 002EF1B4 21184300 */  addu       $3, $2, $3
    /* 1EF1B8 002EF1B8 40B4828F */  lw         $2, -0x4BC0($28)
    /* 1EF1BC 002EF1BC 21384300 */  addu       $7, $2, $3
    /* 1EF1C0 002EF1C0 DE42023C */  lui        $2, (0x42DE0000 >> 16)
    /* 1EF1C4 002EF1C4 00088244 */  mtc1       $2, $f1
    /* 1EF1C8 002EF1C8 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* 1EF1CC 002EF1CC 000B0046 */  add.s      $f12, $f1, $f0
    /* 1EF1D0 002EF1D0 2C42023C */  lui        $2, (0x422C0000 >> 16)
    /* 1EF1D4 002EF1D4 00708244 */  mtc1       $2, $f14
    /* 1EF1D8 002EF1D8 4C01ADC7 */  lwc1       $f13, 0x14C($29)
    /* 1EF1DC 002EF1DC 2D200002 */  daddu      $4, $16, $0
    /* 1EF1E0 002EF1E0 2D280000 */  daddu      $5, $0, $0
    /* 1EF1E4 002EF1E4 02000624 */  addiu      $6, $0, 0x2
    /* 1EF1E8 002EF1E8 2D400000 */  daddu      $8, $0, $0
    /* 1EF1EC 002EF1EC 2D480000 */  daddu      $9, $0, $0
    /* 1EF1F0 002EF1F0 79000A3C */  lui        $10, %hi(D_00795E60)
    /* 1EF1F4 002EF1F4 605E4A25 */  addiu      $10, $10, %lo(D_00795E60)
    /* 1EF1F8 002EF1F8 15000B24 */  addiu      $11, $0, 0x15
    /* 1EF1FC 002EF1FC 08D6090C */  jal        func_00275820
    /* 1EF200 002EF200 00000000 */   nop
    /* 1EF204 002EF204 4801448E */  lw         $4, 0x148($18)
    /* 1EF208 002EF208 98510C0C */  jal        func_00314660
    /* 1EF20C 002EF20C 00000000 */   nop
    /* 1EF210 002EF210 3C1E0200 */  dsll32     $3, $2, 24
    /* 1EF214 002EF214 3F1E0300 */  dsra32     $3, $3, 24
    /* 1EF218 002EF218 05000224 */  addiu      $2, $0, 0x5
    /* 1EF21C 002EF21C 78006214 */  bne        $3, $2, .L002EF400
    /* 1EF220 002EF220 00000000 */   nop
    /* 1EF224 002EF224 4801448E */  lw         $4, 0x148($18)
    /* 1EF228 002EF228 F4510C0C */  jal        func_003147d0
    /* 1EF22C 002EF22C 00000000 */   nop
    /* 1EF230 002EF230 2D204000 */  daddu      $4, $2, $0
    /* 1EF234 002EF234 8471040C */  jal        func_0011c610
    /* 1EF238 002EF238 00000000 */   nop
    /* 1EF23C 002EF23C 01000324 */  addiu      $3, $0, 0x1
    /* 1EF240 002EF240 07004314 */  bne        $2, $3, .L002EF260
    /* 1EF244 002EF244 00000000 */   nop
    /* 1EF248 002EF248 4801448E */  lw         $4, 0x148($18)
    /* 1EF24C 002EF24C F4510C0C */  jal        func_003147d0
    /* 1EF250 002EF250 00000000 */   nop
    /* 1EF254 002EF254 2D204000 */  daddu      $4, $2, $0
    /* 1EF258 002EF258 BC72040C */  jal        func_0011caf0
    /* 1EF25C 002EF25C 00000000 */   nop
  .L002EF260:
    /* 1EF260 002EF260 8C00023C */  lui        $2, %hi(D_008C024E)
    /* 1EF264 002EF264 4E024394 */  lhu        $3, %lo(D_008C024E)($2)
    /* 1EF268 002EF268 80006230 */  andi       $2, $3, 0x80
    /* 1EF26C 002EF26C 22004010 */  beqz       $2, .L002EF2F8
    /* 1EF270 002EF270 00000000 */   nop
    /* 1EF274 002EF274 4801448E */  lw         $4, 0x148($18)
    /* 1EF278 002EF278 F4510C0C */  jal        func_003147d0
    /* 1EF27C 002EF27C 00000000 */   nop
    /* 1EF280 002EF280 2D204000 */  daddu      $4, $2, $0
    /* 1EF284 002EF284 8471040C */  jal        func_0011c610
    /* 1EF288 002EF288 00000000 */   nop
    /* 1EF28C 002EF28C 0D004014 */  bnez       $2, .L002EF2C4
    /* 1EF290 002EF290 00000000 */   nop
    /* 1EF294 002EF294 4801448E */  lw         $4, 0x148($18)
    /* 1EF298 002EF298 F4510C0C */  jal        func_003147d0
    /* 1EF29C 002EF29C 00000000 */   nop
    /* 1EF2A0 002EF2A0 2D204000 */  daddu      $4, $2, $0
    /* 1EF2A4 002EF2A4 8C71040C */  jal        func_0011c630
    /* 1EF2A8 002EF2A8 00000000 */   nop
    /* 1EF2AC 002EF2AC 4801448E */  lw         $4, 0x148($18)
    /* 1EF2B0 002EF2B0 2D280000 */  daddu      $5, $0, $0
    /* 1EF2B4 002EF2B4 D0510C0C */  jal        func_00314740
    /* 1EF2B8 002EF2B8 00000000 */   nop
    /* 1EF2BC 002EF2BC 50000010 */  b          .L002EF400
    /* 1EF2C0 002EF2C0 00000000 */   nop
  .L002EF2C4:
    /* 1EF2C4 002EF2C4 4801448E */  lw         $4, 0x148($18)
    /* 1EF2C8 002EF2C8 F4510C0C */  jal        func_003147d0
    /* 1EF2CC 002EF2CC 00000000 */   nop
    /* 1EF2D0 002EF2D0 2D204000 */  daddu      $4, $2, $0
    /* 1EF2D4 002EF2D4 01000524 */  addiu      $5, $0, 0x1
    /* 1EF2D8 002EF2D8 B871040C */  jal        func_0011c6e0
    /* 1EF2DC 002EF2DC 00000000 */   nop
    /* 1EF2E0 002EF2E0 4801448E */  lw         $4, 0x148($18)
    /* 1EF2E4 002EF2E4 01000524 */  addiu      $5, $0, 0x1
    /* 1EF2E8 002EF2E8 D0510C0C */  jal        func_00314740
    /* 1EF2EC 002EF2EC 00000000 */   nop
    /* 1EF2F0 002EF2F0 43000010 */  b          .L002EF400
    /* 1EF2F4 002EF2F4 00000000 */   nop
  .L002EF2F8:
    /* 1EF2F8 002EF2F8 20006230 */  andi       $2, $3, 0x20
    /* 1EF2FC 002EF2FC 40004010 */  beqz       $2, .L002EF400
    /* 1EF300 002EF300 00000000 */   nop
    /* 1EF304 002EF304 4801448E */  lw         $4, 0x148($18)
    /* 1EF308 002EF308 F4510C0C */  jal        func_003147d0
    /* 1EF30C 002EF30C 00000000 */   nop
    /* 1EF310 002EF310 2D204000 */  daddu      $4, $2, $0
    /* 1EF314 002EF314 8471040C */  jal        func_0011c610
    /* 1EF318 002EF318 00000000 */   nop
    /* 1EF31C 002EF31C 01000324 */  addiu      $3, $0, 0x1
    /* 1EF320 002EF320 0E004314 */  bne        $2, $3, .L002EF35C
    /* 1EF324 002EF324 00000000 */   nop
    /* 1EF328 002EF328 4801448E */  lw         $4, 0x148($18)
    /* 1EF32C 002EF32C F4510C0C */  jal        func_003147d0
    /* 1EF330 002EF330 00000000 */   nop
    /* 1EF334 002EF334 2D204000 */  daddu      $4, $2, $0
    /* 1EF338 002EF338 01000524 */  addiu      $5, $0, 0x1
    /* 1EF33C 002EF33C B871040C */  jal        func_0011c6e0
    /* 1EF340 002EF340 00000000 */   nop
    /* 1EF344 002EF344 4801448E */  lw         $4, 0x148($18)
    /* 1EF348 002EF348 01000524 */  addiu      $5, $0, 0x1
    /* 1EF34C 002EF34C D0510C0C */  jal        func_00314740
    /* 1EF350 002EF350 00000000 */   nop
    /* 1EF354 002EF354 2A000010 */  b          .L002EF400
    /* 1EF358 002EF358 00000000 */   nop
  .L002EF35C:
    /* 1EF35C 002EF35C 4801448E */  lw         $4, 0x148($18)
    /* 1EF360 002EF360 98510C0C */  jal        func_00314660
    /* 1EF364 002EF364 00000000 */   nop
    /* 1EF368 002EF368 3C260200 */  dsll32     $4, $2, 24
    /* 1EF36C 002EF36C 3F260400 */  dsra32     $4, $4, 24
    /* 1EF370 002EF370 05000324 */  addiu      $3, $0, 0x5
    /* 1EF374 002EF374 D2068314 */  bne        $4, $3, .L002F0EC0
    /* 1EF378 002EF378 00000000 */   nop
    /* 1EF37C 002EF37C 2D200000 */  daddu      $4, $0, $0
    /* 1EF380 002EF380 01000524 */  addiu      $5, $0, 0x1
    /* 1EF384 002EF384 2D300000 */  daddu      $6, $0, $0
    /* 1EF388 002EF388 04000724 */  addiu      $7, $0, 0x4
    /* 1EF38C 002EF38C D86B110C */  jal        func_0045af60
    /* 1EF390 002EF390 00000000 */   nop
    /* 1EF394 002EF394 4801448E */  lw         $4, 0x148($18)
    /* 1EF398 002EF398 03000524 */  addiu      $5, $0, 0x3
    /* 1EF39C 002EF39C 9C510C0C */  jal        func_00314670
    /* 1EF3A0 002EF3A0 00000000 */   nop
    /* 1EF3A4 002EF3A4 E4010424 */  addiu      $4, $0, 0x1E4
    /* 1EF3A8 002EF3A8 54D80A0C */  jal        func_002b6150
    /* 1EF3AC 002EF3AC 00000000 */   nop
    /* 1EF3B0 002EF3B0 10004484 */  lh         $4, 0x10($2)
    /* 1EF3B4 002EF3B4 2D280000 */  daddu      $5, $0, $0
    /* 1EF3B8 002EF3B8 5CDA0A0C */  jal        func_002b6970
    /* 1EF3BC 002EF3BC 00000000 */   nop
    /* 1EF3C0 002EF3C0 3C1C0200 */  dsll32     $3, $2, 16
    /* 1EF3C4 002EF3C4 3F1C0300 */  dsra32     $3, $3, 16
    /* 1EF3C8 002EF3C8 01000224 */  addiu      $2, $0, 0x1
    /* 1EF3CC 002EF3CC 0C006214 */  bne        $3, $2, .L002EF400
    /* 1EF3D0 002EF3D0 00000000 */   nop
    /* 1EF3D4 002EF3D4 E4010424 */  addiu      $4, $0, 0x1E4
    /* 1EF3D8 002EF3D8 54D80A0C */  jal        func_002b6150
    /* 1EF3DC 002EF3DC 00000000 */   nop
    /* 1EF3E0 002EF3E0 E4010424 */  addiu      $4, $0, 0x1E4
    /* 1EF3E4 002EF3E4 6E004590 */  lbu        $5, 0x6E($2)
    /* 1EF3E8 002EF3E8 2D300000 */  daddu      $6, $0, $0
    /* 1EF3EC 002EF3EC 2D380000 */  daddu      $7, $0, $0
    /* 1EF3F0 002EF3F0 0A000824 */  addiu      $8, $0, 0xA
    /* 1EF3F4 002EF3F4 2D480000 */  daddu      $9, $0, $0
    /* 1EF3F8 002EF3F8 9CDA0A0C */  jal        func_002b6a70
    /* 1EF3FC 002EF3FC 00000000 */   nop
  .L002EF400:
    /* 1EF400 002EF400 4801448E */  lw         $4, 0x148($18)
    /* 1EF404 002EF404 98510C0C */  jal        func_00314660
    /* 1EF408 002EF408 00000000 */   nop
    /* 1EF40C 002EF40C 3C160200 */  dsll32     $2, $2, 24
    /* 1EF410 002EF410 3F160200 */  dsra32     $2, $2, 24
    /* 1EF414 002EF414 09004004 */  bltz       $2, .L002EF43C
    /* 1EF418 002EF418 00000000 */   nop
    /* 1EF41C 002EF41C 4801448E */  lw         $4, 0x148($18)
    /* 1EF420 002EF420 98510C0C */  jal        func_00314660
    /* 1EF424 002EF424 00000000 */   nop
    /* 1EF428 002EF428 3C1E0200 */  dsll32     $3, $2, 24
    /* 1EF42C 002EF42C 3F1E0300 */  dsra32     $3, $3, 24
    /* 1EF430 002EF430 06006128 */  slti       $1, $3, 0x6
    /* 1EF434 002EF434 A2062014 */  bnez       $1, .L002F0EC0
    /* 1EF438 002EF438 00000000 */   nop
  .L002EF43C:
    /* 1EF43C 002EF43C 2D880000 */  daddu      $17, $0, $0
    /* 1EF440 002EF440 4A000010 */  b          .L002EF56C
    /* 1EF444 002EF444 00000000 */   nop
  .L002EF448:
    /* 1EF448 002EF448 49010224 */  addiu      $2, $0, 0x149
    /* 1EF44C 002EF44C 00008244 */  mtc1       $2, $f0
    /* 1EF450 002EF450 00000000 */  nop
    /* 1EF454 002EF454 20038046 */  cvt.s.w    $f12, $f0
    /* 1EF458 002EF458 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EF45C 002EF45C 00688244 */  mtc1       $2, $f13
    /* 1EF460 002EF460 B801A427 */  addiu      $4, $29, 0x1B8
    /* 1EF464 002EF464 5CCA0A0C */  jal        func_002b2970
    /* 1EF468 002EF468 00000000 */   nop
    /* 1EF46C 002EF46C 28014282 */  lb         $2, 0x128($18)
    /* 1EF470 002EF470 01004224 */  addiu      $2, $2, 0x1
    /* 1EF474 002EF474 3C260200 */  dsll32     $4, $2, 24
    /* 1EF478 002EF478 3F260400 */  dsra32     $4, $4, 24
    /* 1EF47C 002EF47C 2D282002 */  daddu      $5, $17, $0
    /* 1EF480 002EF480 28920B0C */  jal        func_002e48a0
    /* 1EF484 002EF484 00000000 */   nop
    /* 1EF488 002EF488 02005094 */  lhu        $16, 0x2($2)
    /* 1EF48C 002EF48C 28014282 */  lb         $2, 0x128($18)
    /* 1EF490 002EF490 01004224 */  addiu      $2, $2, 0x1
    /* 1EF494 002EF494 3C260200 */  dsll32     $4, $2, 24
    /* 1EF498 002EF498 3F260400 */  dsra32     $4, $4, 24
    /* 1EF49C 002EF49C 2D282002 */  daddu      $5, $17, $0
    /* 1EF4A0 002EF4A0 28920B0C */  jal        func_002e48a0
    /* 1EF4A4 002EF4A4 00000000 */   nop
    /* 1EF4A8 002EF4A8 04004990 */  lbu        $9, 0x4($2)
    /* 1EF4AC 002EF4AC 01000224 */  addiu      $2, $0, 0x1
    /* 1EF4B0 002EF4B0 0000A2FF */  sd         $2, 0x0($29)
    /* 1EF4B4 002EF4B4 CC000224 */  addiu      $2, $0, 0xCC
    /* 1EF4B8 002EF4B8 0800A2FF */  sd         $2, 0x8($29)
    /* 1EF4BC 002EF4BC 3C3E1100 */  dsll32     $7, $17, 24
    /* 1EF4C0 002EF4C0 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EF4C4 002EF4C4 2D208002 */  daddu      $4, $20, $0
    /* 1EF4C8 002EF4C8 B801A5DF */  ld         $5, 0x1B8($29)
    /* 1EF4CC 002EF4CC 28014682 */  lb         $6, 0x128($18)
    /* 1EF4D0 002EF4D0 2D400002 */  daddu      $8, $16, $0
    /* 1EF4D4 002EF4D4 2D500000 */  daddu      $10, $0, $0
    /* 1EF4D8 002EF4D8 2D580000 */  daddu      $11, $0, $0
    /* 1EF4DC 002EF4DC 046B0C0C */  jal        func_0031ac10
    /* 1EF4E0 002EF4E0 00000000 */   nop
    /* 1EF4E4 002EF4E4 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EF4E8 002EF4E8 00608244 */  mtc1       $2, $f12
    /* 1EF4EC 002EF4EC 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1EF4F0 002EF4F0 00688244 */  mtc1       $2, $f13
    /* 1EF4F4 002EF4F4 B001A427 */  addiu      $4, $29, 0x1B0
    /* 1EF4F8 002EF4F8 5CCA0A0C */  jal        func_002b2970
    /* 1EF4FC 002EF4FC 00000000 */   nop
    /* 1EF500 002EF500 2D200000 */  daddu      $4, $0, $0
    /* 1EF504 002EF504 2D282002 */  daddu      $5, $17, $0
    /* 1EF508 002EF508 28920B0C */  jal        func_002e48a0
    /* 1EF50C 002EF50C 00000000 */   nop
    /* 1EF510 002EF510 02005394 */  lhu        $19, 0x2($2)
    /* 1EF514 002EF514 2D200000 */  daddu      $4, $0, $0
    /* 1EF518 002EF518 2D282002 */  daddu      $5, $17, $0
    /* 1EF51C 002EF51C 28920B0C */  jal        func_002e48a0
    /* 1EF520 002EF520 00000000 */   nop
    /* 1EF524 002EF524 04005090 */  lbu        $16, 0x4($2)
    /* 1EF528 002EF528 2D200000 */  daddu      $4, $0, $0
    /* 1EF52C 002EF52C 1C920B0C */  jal        func_002e4870
    /* 1EF530 002EF530 00000000 */   nop
    /* 1EF534 002EF534 08004B80 */  lb         $11, 0x8($2)
    /* 1EF538 002EF538 3C361100 */  dsll32     $6, $17, 24
    /* 1EF53C 002EF53C 3F360600 */  dsra32     $6, $6, 24
    /* 1EF540 002EF540 2D208002 */  daddu      $4, $20, $0
    /* 1EF544 002EF544 B001A5DF */  ld         $5, 0x1B0($29)
    /* 1EF548 002EF548 2D386002 */  daddu      $7, $19, $0
    /* 1EF54C 002EF54C 2D400002 */  daddu      $8, $16, $0
    /* 1EF550 002EF550 2D480000 */  daddu      $9, $0, $0
    /* 1EF554 002EF554 2D500000 */  daddu      $10, $0, $0
    /* 1EF558 002EF558 70640C0C */  jal        func_003191c0
    /* 1EF55C 002EF55C 00000000 */   nop
    /* 1EF560 002EF560 01002226 */  addiu      $2, $17, 0x1
    /* 1EF564 002EF564 3C8C0200 */  dsll32     $17, $2, 16
    /* 1EF568 002EF568 3F8C1100 */  dsra32     $17, $17, 16
  .L002EF56C:
    /* 1EF56C 002EF56C 3C841100 */  dsll32     $16, $17, 16
    /* 1EF570 002EF570 3F841000 */  dsra32     $16, $16, 16
    /* 1EF574 002EF574 6C2D040C */  jal        func_0010b5b0
    /* 1EF578 002EF578 00000000 */   nop
    /* 1EF57C 002EF57C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1EF580 002EF580 2A100202 */  slt        $2, $16, $2
    /* 1EF584 002EF584 B0FF4014 */  bnez       $2, .L002EF448
    /* 1EF588 002EF588 00000000 */   nop
    /* 1EF58C 002EF58C 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EF590 002EF590 00608244 */  mtc1       $2, $f12
    /* 1EF594 002EF594 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EF598 002EF598 00688244 */  mtc1       $2, $f13
    /* 1EF59C 002EF59C A801A427 */  addiu      $4, $29, 0x1A8
    /* 1EF5A0 002EF5A0 5CCA0A0C */  jal        func_002b2970
    /* 1EF5A4 002EF5A4 00000000 */   nop
    /* 1EF5A8 002EF5A8 2D208002 */  daddu      $4, $20, $0
    /* 1EF5AC 002EF5AC A801A5DF */  ld         $5, 0x1A8($29)
    /* 1EF5B0 002EF5B0 2D300000 */  daddu      $6, $0, $0
    /* 1EF5B4 002EF5B4 2D380000 */  daddu      $7, $0, $0
    /* 1EF5B8 002EF5B8 2D400000 */  daddu      $8, $0, $0
    /* 1EF5BC 002EF5BC 2D480000 */  daddu      $9, $0, $0
    /* 1EF5C0 002EF5C0 2D500000 */  daddu      $10, $0, $0
    /* 1EF5C4 002EF5C4 6C790C0C */  jal        func_0031e5b0
    /* 1EF5C8 002EF5C8 00000000 */   nop
    /* 1EF5CC 002EF5CC 49010224 */  addiu      $2, $0, 0x149
    /* 1EF5D0 002EF5D0 00008244 */  mtc1       $2, $f0
    /* 1EF5D4 002EF5D4 00000000 */  nop
    /* 1EF5D8 002EF5D8 20038046 */  cvt.s.w    $f12, $f0
    /* 1EF5DC 002EF5DC D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1EF5E0 002EF5E0 00688244 */  mtc1       $2, $f13
    /* 1EF5E4 002EF5E4 A001A427 */  addiu      $4, $29, 0x1A0
    /* 1EF5E8 002EF5E8 5CCA0A0C */  jal        func_002b2970
    /* 1EF5EC 002EF5EC 00000000 */   nop
    /* 1EF5F0 002EF5F0 2D208002 */  daddu      $4, $20, $0
    /* 1EF5F4 002EF5F4 A001A5DF */  ld         $5, 0x1A0($29)
    /* 1EF5F8 002EF5F8 2D300000 */  daddu      $6, $0, $0
    /* 1EF5FC 002EF5FC 2D380000 */  daddu      $7, $0, $0
    /* 1EF600 002EF600 887E0C0C */  jal        func_0031fa20
    /* 1EF604 002EF604 00000000 */   nop
    /* 1EF608 002EF608 2D208002 */  daddu      $4, $20, $0
    /* 1EF60C 002EF60C 01000524 */  addiu      $5, $0, 0x1
    /* 1EF610 002EF610 2D300000 */  daddu      $6, $0, $0
    /* 1EF614 002EF614 1C590C0C */  jal        func_00316470
    /* 1EF618 002EF618 00000000 */   nop
    /* 1EF61C 002EF61C 0000A0FF */  sd         $0, 0x0($29)
    /* 1EF620 002EF620 0800A0FF */  sd         $0, 0x8($29)
    /* 1EF624 002EF624 1000A0FF */  sd         $0, 0x10($29)
    /* 1EF628 002EF628 2D208002 */  daddu      $4, $20, $0
    /* 1EF62C 002EF62C 01000524 */  addiu      $5, $0, 0x1
    /* 1EF630 002EF630 2D300000 */  daddu      $6, $0, $0
    /* 1EF634 002EF634 2D380000 */  daddu      $7, $0, $0
    /* 1EF638 002EF638 2D400000 */  daddu      $8, $0, $0
    /* 1EF63C 002EF63C 2D48A000 */  daddu      $9, $5, $0
    /* 1EF640 002EF640 2D500000 */  daddu      $10, $0, $0
    /* 1EF644 002EF644 2D580000 */  daddu      $11, $0, $0
    /* 1EF648 002EF648 A05B0C0C */  jal        func_00316e80
    /* 1EF64C 002EF64C 00000000 */   nop
    /* 1EF650 002EF650 8C02448E */  lw         $4, 0x28C($18)
    /* 1EF654 002EF654 2D280000 */  daddu      $5, $0, $0
    /* 1EF658 002EF658 50D80A0C */  jal        func_002b6140
    /* 1EF65C 002EF65C 00000000 */   nop
    /* 1EF660 002EF660 9002448E */  lw         $4, 0x290($18)
    /* 1EF664 002EF664 2D280000 */  daddu      $5, $0, $0
    /* 1EF668 002EF668 50D80A0C */  jal        func_002b6140
    /* 1EF66C 002EF66C 00000000 */   nop
    /* 1EF670 002EF670 2A000324 */  addiu      $3, $0, 0x2A
    /* 1EF674 002EF674 010043A2 */  sb         $3, 0x1($18)
    /* 1EF678 002EF678 11060010 */  b          .L002F0EC0
    /* 1EF67C 002EF67C 00000000 */   nop
    /* 1EF680 002EF680 7C000424 */  addiu      $4, $0, 0x7C
    /* 1EF684 002EF684 54D80A0C */  jal        func_002b6150
    /* 1EF688 002EF688 00000000 */   nop
    /* 1EF68C 002EF68C 6E005090 */  lbu        $16, 0x6E($2)
    /* 1EF690 002EF690 3800918E */  lw         $17, 0x38($20)
    /* 1EF694 002EF694 7C000424 */  addiu      $4, $0, 0x7C
    /* 1EF698 002EF698 54D80A0C */  jal        func_002b6150
    /* 1EF69C 002EF69C 00000000 */   nop
    /* 1EF6A0 002EF6A0 380041C4 */  lwc1       $f1, 0x38($2)
    /* 1EF6A4 002EF6A4 3C0040C4 */  lwc1       $f0, 0x3C($2)
    /* 1EF6A8 002EF6A8 4001A1E7 */  swc1       $f1, 0x140($29)
    /* 1EF6AC 002EF6AC 4401A0E7 */  swc1       $f0, 0x144($29)
    /* 1EF6B0 002EF6B0 CC000424 */  addiu      $4, $0, 0xCC
    /* 1EF6B4 002EF6B4 FF000524 */  addiu      $5, $0, 0xFF
    /* 1EF6B8 002EF6B8 2D30A000 */  daddu      $6, $5, $0
    /* 1EF6BC 002EF6BC 2D380002 */  daddu      $7, $16, $0
    /* 1EF6C0 002EF6C0 8CCA0A0C */  jal        func_002b2a30
    /* 1EF6C4 002EF6C4 00000000 */   nop
    /* 1EF6C8 002EF6C8 2D804000 */  daddu      $16, $2, $0
    /* 1EF6CC 002EF6CC 28012582 */  lb         $5, 0x128($17)
    /* 1EF6D0 002EF6D0 2D200000 */  daddu      $4, $0, $0
    /* 1EF6D4 002EF6D4 28920B0C */  jal        func_002e48a0
    /* 1EF6D8 002EF6D8 00000000 */   nop
    /* 1EF6DC 002EF6DC 02004394 */  lhu        $3, 0x2($2)
    /* 1EF6E0 002EF6E0 00110300 */  sll        $2, $3, 4
    /* 1EF6E4 002EF6E4 21184300 */  addu       $3, $2, $3
    /* 1EF6E8 002EF6E8 40B4828F */  lw         $2, -0x4BC0($28)
    /* 1EF6EC 002EF6EC 21384300 */  addu       $7, $2, $3
    /* 1EF6F0 002EF6F0 DE42023C */  lui        $2, (0x42DE0000 >> 16)
    /* 1EF6F4 002EF6F4 00088244 */  mtc1       $2, $f1
    /* 1EF6F8 002EF6F8 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* 1EF6FC 002EF6FC 000B0046 */  add.s      $f12, $f1, $f0
    /* 1EF700 002EF700 2C42023C */  lui        $2, (0x422C0000 >> 16)
    /* 1EF704 002EF704 00708244 */  mtc1       $2, $f14
    /* 1EF708 002EF708 4401ADC7 */  lwc1       $f13, 0x144($29)
    /* 1EF70C 002EF70C 2D200002 */  daddu      $4, $16, $0
    /* 1EF710 002EF710 2D280000 */  daddu      $5, $0, $0
    /* 1EF714 002EF714 02000624 */  addiu      $6, $0, 0x2
    /* 1EF718 002EF718 2D400000 */  daddu      $8, $0, $0
    /* 1EF71C 002EF71C 2D480000 */  daddu      $9, $0, $0
    /* 1EF720 002EF720 79000A3C */  lui        $10, %hi(D_00795E60)
    /* 1EF724 002EF724 605E4A25 */  addiu      $10, $10, %lo(D_00795E60)
    /* 1EF728 002EF728 15000B24 */  addiu      $11, $0, 0x15
    /* 1EF72C 002EF72C 08D6090C */  jal        func_00275820
    /* 1EF730 002EF730 00000000 */   nop
    /* 1EF734 002EF734 1C020424 */  addiu      $4, $0, 0x21C
    /* 1EF738 002EF738 54D80A0C */  jal        func_002b6150
    /* 1EF73C 002EF73C 00000000 */   nop
    /* 1EF740 002EF740 10004484 */  lh         $4, 0x10($2)
    /* 1EF744 002EF744 01000524 */  addiu      $5, $0, 0x1
    /* 1EF748 002EF748 5CDA0A0C */  jal        func_002b6970
    /* 1EF74C 002EF74C 00000000 */   nop
    /* 1EF750 002EF750 3C240200 */  dsll32     $4, $2, 16
    /* 1EF754 002EF754 3F240400 */  dsra32     $4, $4, 16
    /* 1EF758 002EF758 01000324 */  addiu      $3, $0, 0x1
    /* 1EF75C 002EF75C D8058310 */  beq        $4, $3, .L002F0EC0
    /* 1EF760 002EF760 00000000 */   nop
    /* 1EF764 002EF764 28014282 */  lb         $2, 0x128($18)
    /* 1EF768 002EF768 01004224 */  addiu      $2, $2, 0x1
    /* 1EF76C 002EF76C F90242A2 */  sb         $2, 0x2F9($18)
    /* 1EF770 002EF770 1E014286 */  lh         $2, 0x11E($18)
    /* 1EF774 002EF774 FA0242A2 */  sb         $2, 0x2FA($18)
    /* 1EF778 002EF778 3C860200 */  dsll32     $16, $2, 24
    /* 1EF77C 002EF77C 3F861000 */  dsra32     $16, $16, 24
    /* 1EF780 002EF780 F9024482 */  lb         $4, 0x2F9($18)
    /* 1EF784 002EF784 2D280002 */  daddu      $5, $16, $0
    /* 1EF788 002EF788 28920B0C */  jal        func_002e48a0
    /* 1EF78C 002EF78C 00000000 */   nop
    /* 1EF790 002EF790 2D884000 */  daddu      $17, $2, $0
    /* 1EF794 002EF794 F9024482 */  lb         $4, 0x2F9($18)
    /* 1EF798 002EF798 1C920B0C */  jal        func_002e4870
    /* 1EF79C 002EF79C 00000000 */   nop
    /* 1EF7A0 002EF7A0 3C1E1000 */  dsll32     $3, $16, 24
    /* 1EF7A4 002EF7A4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1EF7A8 002EF7A8 21804300 */  addu       $16, $2, $3
    /* 1EF7AC 002EF7AC FA024582 */  lb         $5, 0x2FA($18)
    /* 1EF7B0 002EF7B0 F9024482 */  lb         $4, 0x2F9($18)
    /* 1EF7B4 002EF7B4 28920B0C */  jal        func_002e48a0
    /* 1EF7B8 002EF7B8 00000000 */   nop
    /* 1EF7BC 002EF7BC 02004394 */  lhu        $3, 0x2($2)
    /* 1EF7C0 002EF7C0 C0100300 */  sll        $2, $3, 3
    /* 1EF7C4 002EF7C4 23104300 */  subu       $2, $2, $3
    /* 1EF7C8 002EF7C8 40180200 */  sll        $3, $2, 1
    /* 1EF7CC 002EF7CC D4B3828F */  lw         $2, -0x4C2C($28)
    /* 1EF7D0 002EF7D0 21106200 */  addu       $2, $3, $2
    /* 1EF7D4 002EF7D4 02004490 */  lbu        $4, 0x2($2)
    /* 1EF7D8 002EF7D8 DC1D090C */  jal        func_00247770
    /* 1EF7DC 002EF7DC 00000000 */   nop
    /* 1EF7E0 002EF7E0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1EF7E4 002EF7E4 3F9C1300 */  dsra32     $19, $19, 16
    /* 1EF7E8 002EF7E8 FA024582 */  lb         $5, 0x2FA($18)
    /* 1EF7EC 002EF7EC F9024482 */  lb         $4, 0x2F9($18)
    /* 1EF7F0 002EF7F0 28920B0C */  jal        func_002e48a0
    /* 1EF7F4 002EF7F4 00000000 */   nop
    /* 1EF7F8 002EF7F8 2D206002 */  daddu      $4, $19, $0
    /* 1EF7FC 002EF7FC 2D284000 */  daddu      $5, $2, $0
    /* 1EF800 002EF800 2D300000 */  daddu      $6, $0, $0
    /* 1EF804 002EF804 4C460C0C */  jal        func_00311930
    /* 1EF808 002EF808 00000000 */   nop
    /* 1EF80C 002EF80C 4801448E */  lw         $4, 0x148($18)
    /* 1EF810 002EF810 2D282002 */  daddu      $5, $17, $0
    /* 1EF814 002EF814 E4020682 */  lb         $6, 0x2E4($16)
    /* 1EF818 002EF818 2D384000 */  daddu      $7, $2, $0
    /* 1EF81C 002EF81C 01000824 */  addiu      $8, $0, 0x1
    /* 1EF820 002EF820 34510C0C */  jal        func_003144d0
    /* 1EF824 002EF824 00000000 */   nop
    /* 1EF828 002EF828 4801448E */  lw         $4, 0x148($18)
    /* 1EF82C 002EF82C F4510C0C */  jal        func_003147d0
    /* 1EF830 002EF830 00000000 */   nop
    /* 1EF834 002EF834 2D804000 */  daddu      $16, $2, $0
    /* 1EF838 002EF838 FF000424 */  addiu      $4, $0, 0xFF
    /* 1EF83C 002EF83C 2D288000 */  daddu      $5, $4, $0
    /* 1EF840 002EF840 2D308000 */  daddu      $6, $4, $0
    /* 1EF844 002EF844 2D388000 */  daddu      $7, $4, $0
    /* 1EF848 002EF848 8CCA0A0C */  jal        func_002b2a30
    /* 1EF84C 002EF84C 00000000 */   nop
    /* 1EF850 002EF850 2D200002 */  daddu      $4, $16, $0
    /* 1EF854 002EF854 2D284000 */  daddu      $5, $2, $0
    /* 1EF858 002EF858 5074040C */  jal        func_0011d140
    /* 1EF85C 002EF85C 00000000 */   nop
    /* 1EF860 002EF860 FA024582 */  lb         $5, 0x2FA($18)
    /* 1EF864 002EF864 F9024482 */  lb         $4, 0x2F9($18)
    /* 1EF868 002EF868 28920B0C */  jal        func_002e48a0
    /* 1EF86C 002EF86C 00000000 */   nop
    /* 1EF870 002EF870 04005090 */  lbu        $16, 0x4($2)
    /* 1EF874 002EF874 01000424 */  addiu      $4, $0, 0x1
    /* 1EF878 002EF878 1C13040C */  jal        func_00104c70
    /* 1EF87C 002EF87C 00000000 */   nop
    /* 1EF880 002EF880 FF004230 */  andi       $2, $2, 0xFF
    /* 1EF884 002EF884 2A085000 */  slt        $1, $2, $16
    /* 1EF888 002EF888 0F002010 */  beqz       $1, .L002EF8C8
    /* 1EF88C 002EF88C 00000000 */   nop
    /* 1EF890 002EF890 4801448E */  lw         $4, 0x148($18)
    /* 1EF894 002EF894 F4510C0C */  jal        func_003147d0
    /* 1EF898 002EF898 00000000 */   nop
    /* 1EF89C 002EF89C 2D804000 */  daddu      $16, $2, $0
    /* 1EF8A0 002EF8A0 14000424 */  addiu      $4, $0, 0x14
    /* 1EF8A4 002EF8A4 2D288000 */  daddu      $5, $4, $0
    /* 1EF8A8 002EF8A8 2D308000 */  daddu      $6, $4, $0
    /* 1EF8AC 002EF8AC FF000724 */  addiu      $7, $0, 0xFF
    /* 1EF8B0 002EF8B0 8CCA0A0C */  jal        func_002b2a30
    /* 1EF8B4 002EF8B4 00000000 */   nop
    /* 1EF8B8 002EF8B8 2D200002 */  daddu      $4, $16, $0
    /* 1EF8BC 002EF8BC 2D284000 */  daddu      $5, $2, $0
    /* 1EF8C0 002EF8C0 5074040C */  jal        func_0011d140
    /* 1EF8C4 002EF8C4 00000000 */   nop
  .L002EF8C8:
    /* 1EF8C8 002EF8C8 4801448E */  lw         $4, 0x148($18)
    /* 1EF8CC 002EF8CC F4510C0C */  jal        func_003147d0
    /* 1EF8D0 002EF8D0 00000000 */   nop
    /* 1EF8D4 002EF8D4 2D204000 */  daddu      $4, $2, $0
    /* 1EF8D8 002EF8D8 01000524 */  addiu      $5, $0, 0x1
    /* 1EF8DC 002EF8DC B871040C */  jal        func_0011c6e0
    /* 1EF8E0 002EF8E0 00000000 */   nop
    /* 1EF8E4 002EF8E4 2D208002 */  daddu      $4, $20, $0
    /* 1EF8E8 002EF8E8 03000524 */  addiu      $5, $0, 0x3
    /* 1EF8EC 002EF8EC 2D300000 */  daddu      $6, $0, $0
    /* 1EF8F0 002EF8F0 14950C0C */  jal        func_00325450
    /* 1EF8F4 002EF8F4 00000000 */   nop
    /* 1EF8F8 002EF8F8 2D000324 */  addiu      $3, $0, 0x2D
    /* 1EF8FC 002EF8FC 010043A2 */  sb         $3, 0x1($18)
    /* 1EF900 002EF900 6F050010 */  b          .L002F0EC0
    /* 1EF904 002EF904 00000000 */   nop
    /* 1EF908 002EF908 4801448E */  lw         $4, 0x148($18)
    /* 1EF90C 002EF90C 98510C0C */  jal        func_00314660
    /* 1EF910 002EF910 00000000 */   nop
    /* 1EF914 002EF914 3C260200 */  dsll32     $4, $2, 24
    /* 1EF918 002EF918 3F260400 */  dsra32     $4, $4, 24
    /* 1EF91C 002EF91C 0D000324 */  addiu      $3, $0, 0xD
    /* 1EF920 002EF920 67058314 */  bne        $4, $3, .L002F0EC0
    /* 1EF924 002EF924 00000000 */   nop
    /* 1EF928 002EF928 4801448E */  lw         $4, 0x148($18)
    /* 1EF92C 002EF92C F4510C0C */  jal        func_003147d0
    /* 1EF930 002EF930 00000000 */   nop
    /* 1EF934 002EF934 2D204000 */  daddu      $4, $2, $0
    /* 1EF938 002EF938 8471040C */  jal        func_0011c610
    /* 1EF93C 002EF93C 00000000 */   nop
    /* 1EF940 002EF940 01000324 */  addiu      $3, $0, 0x1
    /* 1EF944 002EF944 07004314 */  bne        $2, $3, .L002EF964
    /* 1EF948 002EF948 00000000 */   nop
    /* 1EF94C 002EF94C 4801448E */  lw         $4, 0x148($18)
    /* 1EF950 002EF950 F4510C0C */  jal        func_003147d0
    /* 1EF954 002EF954 00000000 */   nop
    /* 1EF958 002EF958 2D204000 */  daddu      $4, $2, $0
    /* 1EF95C 002EF95C BC72040C */  jal        func_0011caf0
    /* 1EF960 002EF960 00000000 */   nop
  .L002EF964:
    /* 1EF964 002EF964 8C00033C */  lui        $3, %hi(D_008C024E)
    /* 1EF968 002EF968 4E026494 */  lhu        $4, %lo(D_008C024E)($3)
    /* 1EF96C 002EF96C 40008330 */  andi       $3, $4, 0x40
    /* 1EF970 002EF970 0B006010 */  beqz       $3, .L002EF9A0
    /* 1EF974 002EF974 00000000 */   nop
    /* 1EF978 002EF978 2F000224 */  addiu      $2, $0, 0x2F
    /* 1EF97C 002EF97C 010042A2 */  sb         $2, 0x1($18)
    /* 1EF980 002EF980 2D200000 */  daddu      $4, $0, $0
    /* 1EF984 002EF984 2D280000 */  daddu      $5, $0, $0
    /* 1EF988 002EF988 2D300000 */  daddu      $6, $0, $0
    /* 1EF98C 002EF98C 01000724 */  addiu      $7, $0, 0x1
    /* 1EF990 002EF990 D86B110C */  jal        func_0045af60
    /* 1EF994 002EF994 00000000 */   nop
    /* 1EF998 002EF998 49050010 */  b          .L002F0EC0
    /* 1EF99C 002EF99C 00000000 */   nop
  .L002EF9A0:
    /* 1EF9A0 002EF9A0 80008330 */  andi       $3, $4, 0x80
    /* 1EF9A4 002EF9A4 22006010 */  beqz       $3, .L002EFA30
    /* 1EF9A8 002EF9A8 00000000 */   nop
    /* 1EF9AC 002EF9AC 4801448E */  lw         $4, 0x148($18)
    /* 1EF9B0 002EF9B0 F4510C0C */  jal        func_003147d0
    /* 1EF9B4 002EF9B4 00000000 */   nop
    /* 1EF9B8 002EF9B8 2D204000 */  daddu      $4, $2, $0
    /* 1EF9BC 002EF9BC 8471040C */  jal        func_0011c610
    /* 1EF9C0 002EF9C0 00000000 */   nop
    /* 1EF9C4 002EF9C4 0D004014 */  bnez       $2, .L002EF9FC
    /* 1EF9C8 002EF9C8 00000000 */   nop
    /* 1EF9CC 002EF9CC 4801448E */  lw         $4, 0x148($18)
    /* 1EF9D0 002EF9D0 F4510C0C */  jal        func_003147d0
    /* 1EF9D4 002EF9D4 00000000 */   nop
    /* 1EF9D8 002EF9D8 2D204000 */  daddu      $4, $2, $0
    /* 1EF9DC 002EF9DC 8C71040C */  jal        func_0011c630
    /* 1EF9E0 002EF9E0 00000000 */   nop
    /* 1EF9E4 002EF9E4 4801448E */  lw         $4, 0x148($18)
    /* 1EF9E8 002EF9E8 2D280000 */  daddu      $5, $0, $0
    /* 1EF9EC 002EF9EC D0510C0C */  jal        func_00314740
    /* 1EF9F0 002EF9F0 00000000 */   nop
    /* 1EF9F4 002EF9F4 32050010 */  b          .L002F0EC0
    /* 1EF9F8 002EF9F8 00000000 */   nop
  .L002EF9FC:
    /* 1EF9FC 002EF9FC 4801448E */  lw         $4, 0x148($18)
    /* 1EFA00 002EFA00 F4510C0C */  jal        func_003147d0
    /* 1EFA04 002EFA04 00000000 */   nop
    /* 1EFA08 002EFA08 2D204000 */  daddu      $4, $2, $0
    /* 1EFA0C 002EFA0C 01000524 */  addiu      $5, $0, 0x1
    /* 1EFA10 002EFA10 B871040C */  jal        func_0011c6e0
    /* 1EFA14 002EFA14 00000000 */   nop
    /* 1EFA18 002EFA18 4801448E */  lw         $4, 0x148($18)
    /* 1EFA1C 002EFA1C 01000524 */  addiu      $5, $0, 0x1
    /* 1EFA20 002EFA20 D0510C0C */  jal        func_00314740
    /* 1EFA24 002EFA24 00000000 */   nop
    /* 1EFA28 002EFA28 25050010 */  b          .L002F0EC0
    /* 1EFA2C 002EFA2C 00000000 */   nop
  .L002EFA30:
    /* 1EFA30 002EFA30 20008330 */  andi       $3, $4, 0x20
    /* 1EFA34 002EFA34 2F006010 */  beqz       $3, .L002EFAF4
    /* 1EFA38 002EFA38 00000000 */   nop
    /* 1EFA3C 002EFA3C 4801448E */  lw         $4, 0x148($18)
    /* 1EFA40 002EFA40 F4510C0C */  jal        func_003147d0
    /* 1EFA44 002EFA44 00000000 */   nop
    /* 1EFA48 002EFA48 2D204000 */  daddu      $4, $2, $0
    /* 1EFA4C 002EFA4C 8471040C */  jal        func_0011c610
    /* 1EFA50 002EFA50 00000000 */   nop
    /* 1EFA54 002EFA54 01000324 */  addiu      $3, $0, 0x1
    /* 1EFA58 002EFA58 0E004314 */  bne        $2, $3, .L002EFA94
    /* 1EFA5C 002EFA5C 00000000 */   nop
    /* 1EFA60 002EFA60 4801448E */  lw         $4, 0x148($18)
    /* 1EFA64 002EFA64 F4510C0C */  jal        func_003147d0
    /* 1EFA68 002EFA68 00000000 */   nop
    /* 1EFA6C 002EFA6C 2D204000 */  daddu      $4, $2, $0
    /* 1EFA70 002EFA70 01000524 */  addiu      $5, $0, 0x1
    /* 1EFA74 002EFA74 B871040C */  jal        func_0011c6e0
    /* 1EFA78 002EFA78 00000000 */   nop
    /* 1EFA7C 002EFA7C 4801448E */  lw         $4, 0x148($18)
    /* 1EFA80 002EFA80 01000524 */  addiu      $5, $0, 0x1
    /* 1EFA84 002EFA84 D0510C0C */  jal        func_00314740
    /* 1EFA88 002EFA88 00000000 */   nop
    /* 1EFA8C 002EFA8C 0C050010 */  b          .L002F0EC0
    /* 1EFA90 002EFA90 00000000 */   nop
  .L002EFA94:
    /* 1EFA94 002EFA94 35000224 */  addiu      $2, $0, 0x35
    /* 1EFA98 002EFA98 010042A2 */  sb         $2, 0x1($18)
    /* 1EFA9C 002EFA9C 4801448E */  lw         $4, 0x148($18)
    /* 1EFAA0 002EFAA0 0B000524 */  addiu      $5, $0, 0xB
    /* 1EFAA4 002EFAA4 9C510C0C */  jal        func_00314670
    /* 1EFAA8 002EFAA8 00000000 */   nop
    /* 1EFAAC 002EFAAC 2D208002 */  daddu      $4, $20, $0
    /* 1EFAB0 002EFAB0 03000524 */  addiu      $5, $0, 0x3
    /* 1EFAB4 002EFAB4 01000624 */  addiu      $6, $0, 0x1
    /* 1EFAB8 002EFAB8 14950C0C */  jal        func_00325450
    /* 1EFABC 002EFABC 00000000 */   nop
    /* 1EFAC0 002EFAC0 00608044 */  mtc1       $0, $f12
    /* 1EFAC4 002EFAC4 2D208002 */  daddu      $4, $20, $0
    /* 1EFAC8 002EFAC8 01000524 */  addiu      $5, $0, 0x1
    /* 1EFACC 002EFACC 905C0C0C */  jal        func_00317240
    /* 1EFAD0 002EFAD0 00000000 */   nop
    /* 1EFAD4 002EFAD4 2D200000 */  daddu      $4, $0, $0
    /* 1EFAD8 002EFAD8 2D280000 */  daddu      $5, $0, $0
    /* 1EFADC 002EFADC 2D300000 */  daddu      $6, $0, $0
    /* 1EFAE0 002EFAE0 02000724 */  addiu      $7, $0, 0x2
    /* 1EFAE4 002EFAE4 D86B110C */  jal        func_0045af60
    /* 1EFAE8 002EFAE8 00000000 */   nop
    /* 1EFAEC 002EFAEC F4040010 */  b          .L002F0EC0
    /* 1EFAF0 002EFAF0 00000000 */   nop
  .L002EFAF4:
    /* 1EFAF4 002EFAF4 08008330 */  andi       $3, $4, 0x8
    /* 1EFAF8 002EFAF8 E0006010 */  beqz       $3, .L002EFE7C
    /* 1EFAFC 002EFAFC 00000000 */   nop
    /* 1EFB00 002EFB00 22014282 */  lb         $2, 0x122($18)
    /* 1EFB04 002EFB04 02000524 */  addiu      $5, $0, 0x2
    /* 1EFB08 002EFB08 06004510 */  beq        $2, $5, .L002EFB24
    /* 1EFB0C 002EFB0C 00000000 */   nop
    /* 1EFB10 002EFB10 2D200000 */  daddu      $4, $0, $0
    /* 1EFB14 002EFB14 2D300000 */  daddu      $6, $0, $0
    /* 1EFB18 002EFB18 05000724 */  addiu      $7, $0, 0x5
    /* 1EFB1C 002EFB1C D86B110C */  jal        func_0045af60
    /* 1EFB20 002EFB20 00000000 */   nop
  .L002EFB24:
    /* 1EFB24 002EFB24 22014482 */  lb         $4, 0x122($18)
    /* 1EFB28 002EFB28 01000524 */  addiu      $5, $0, 0x1
    /* 1EFB2C 002EFB2C 02000624 */  addiu      $6, $0, 0x2
    /* 1EFB30 002EFB30 2D380000 */  daddu      $7, $0, $0
    /* 1EFB34 002EFB34 2D40A000 */  daddu      $8, $5, $0
    /* 1EFB38 002EFB38 2CCB0A0C */  jal        func_002b2cb0
    /* 1EFB3C 002EFB3C 00000000 */   nop
    /* 1EFB40 002EFB40 220142A2 */  sb         $2, 0x122($18)
    /* 1EFB44 002EFB44 51010424 */  addiu      $4, $0, 0x151
    /* 1EFB48 002EFB48 54D80A0C */  jal        func_002b6150
    /* 1EFB4C 002EFB4C 00000000 */   nop
    /* 1EFB50 002EFB50 2D804000 */  daddu      $16, $2, $0
    /* 1EFB54 002EFB54 22014382 */  lb         $3, 0x122($18)
    /* 1EFB58 002EFB58 C0100300 */  sll        $2, $3, 3
    /* 1EFB5C 002EFB5C 21104300 */  addu       $2, $2, $3
    /* 1EFB60 002EFB60 C0100200 */  sll        $2, $2, 3
    /* 1EFB64 002EFB64 23104300 */  subu       $2, $2, $3
    /* 1EFB68 002EFB68 40100200 */  sll        $2, $2, 1
    /* 1EFB6C 002EFB6C 6A004224 */  addiu      $2, $2, 0x6A
    /* 1EFB70 002EFB70 00008244 */  mtc1       $2, $f0
    /* 1EFB74 002EFB74 00000000 */  nop
    /* 1EFB78 002EFB78 20038046 */  cvt.s.w    $f12, $f0
    /* 1EFB7C 002EFB7C 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EFB80 002EFB80 00688244 */  mtc1       $2, $f13
    /* 1EFB84 002EFB84 9801A427 */  addiu      $4, $29, 0x198
    /* 1EFB88 002EFB88 5CCA0A0C */  jal        func_002b2970
    /* 1EFB8C 002EFB8C 00000000 */   nop
    /* 1EFB90 002EFB90 51010424 */  addiu      $4, $0, 0x151
    /* 1EFB94 002EFB94 3800056E */  ldr        $5, 0x38($16)
    /* 1EFB98 002EFB98 3F00056A */  ldl        $5, 0x3F($16)
    /* 1EFB9C 002EFB9C 9801A6DF */  ld         $6, 0x198($29)
    /* 1EFBA0 002EFBA0 01000724 */  addiu      $7, $0, 0x1
    /* 1EFBA4 002EFBA4 04000824 */  addiu      $8, $0, 0x4
    /* 1EFBA8 002EFBA8 2D480000 */  daddu      $9, $0, $0
    /* 1EFBAC 002EFBAC 7CDA0A0C */  jal        func_002b69f0
    /* 1EFBB0 002EFBB0 00000000 */   nop
    /* 1EFBB4 002EFBB4 E0020424 */  addiu      $4, $0, 0x2E0
    /* 1EFBB8 002EFBB8 54D80A0C */  jal        func_002b6150
    /* 1EFBBC 002EFBBC 00000000 */   nop
    /* 1EFBC0 002EFBC0 2D804000 */  daddu      $16, $2, $0
    /* 1EFBC4 002EFBC4 22014382 */  lb         $3, 0x122($18)
    /* 1EFBC8 002EFBC8 C0100300 */  sll        $2, $3, 3
    /* 1EFBCC 002EFBCC 21104300 */  addu       $2, $2, $3
    /* 1EFBD0 002EFBD0 C0100200 */  sll        $2, $2, 3
    /* 1EFBD4 002EFBD4 23104300 */  subu       $2, $2, $3
    /* 1EFBD8 002EFBD8 40100200 */  sll        $2, $2, 1
    /* 1EFBDC 002EFBDC 6A004224 */  addiu      $2, $2, 0x6A
    /* 1EFBE0 002EFBE0 00008244 */  mtc1       $2, $f0
    /* 1EFBE4 002EFBE4 00000000 */  nop
    /* 1EFBE8 002EFBE8 20038046 */  cvt.s.w    $f12, $f0
    /* 1EFBEC 002EFBEC 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EFBF0 002EFBF0 00688244 */  mtc1       $2, $f13
    /* 1EFBF4 002EFBF4 9001A427 */  addiu      $4, $29, 0x190
    /* 1EFBF8 002EFBF8 5CCA0A0C */  jal        func_002b2970
    /* 1EFBFC 002EFBFC 00000000 */   nop
    /* 1EFC00 002EFC00 E0020424 */  addiu      $4, $0, 0x2E0
    /* 1EFC04 002EFC04 3800056E */  ldr        $5, 0x38($16)
    /* 1EFC08 002EFC08 3F00056A */  ldl        $5, 0x3F($16)
    /* 1EFC0C 002EFC0C 9001A6DF */  ld         $6, 0x190($29)
    /* 1EFC10 002EFC10 01000724 */  addiu      $7, $0, 0x1
    /* 1EFC14 002EFC14 04000824 */  addiu      $8, $0, 0x4
    /* 1EFC18 002EFC18 2D480000 */  daddu      $9, $0, $0
    /* 1EFC1C 002EFC1C 7CDA0A0C */  jal        func_002b69f0
    /* 1EFC20 002EFC20 00000000 */   nop
    /* 1EFC24 002EFC24 22014482 */  lb         $4, 0x122($18)
    /* 1EFC28 002EFC28 02000324 */  addiu      $3, $0, 0x2
    /* 1EFC2C 002EFC2C 3E008310 */  beq        $4, $3, .L002EFD28
    /* 1EFC30 002EFC30 00000000 */   nop
    /* 1EFC34 002EFC34 01000324 */  addiu      $3, $0, 0x1
    /* 1EFC38 002EFC38 20008310 */  beq        $4, $3, .L002EFCBC
    /* 1EFC3C 002EFC3C 00000000 */   nop
    /* 1EFC40 002EFC40 03008010 */  beqz       $4, .L002EFC50
    /* 1EFC44 002EFC44 00000000 */   nop
    /* 1EFC48 002EFC48 9D040010 */  b          .L002F0EC0
    /* 1EFC4C 002EFC4C 00000000 */   nop
  .L002EFC50:
    /* 1EFC50 002EFC50 4801448E */  lw         $4, 0x148($18)
    /* 1EFC54 002EFC54 F4510C0C */  jal        func_003147d0
    /* 1EFC58 002EFC58 00000000 */   nop
    /* 1EFC5C 002EFC5C 2D804000 */  daddu      $16, $2, $0
    /* 1EFC60 002EFC60 FF000424 */  addiu      $4, $0, 0xFF
    /* 1EFC64 002EFC64 2D288000 */  daddu      $5, $4, $0
    /* 1EFC68 002EFC68 2D308000 */  daddu      $6, $4, $0
    /* 1EFC6C 002EFC6C 2D388000 */  daddu      $7, $4, $0
    /* 1EFC70 002EFC70 8CCA0A0C */  jal        func_002b2a30
    /* 1EFC74 002EFC74 00000000 */   nop
    /* 1EFC78 002EFC78 2D200002 */  daddu      $4, $16, $0
    /* 1EFC7C 002EFC7C 2D284000 */  daddu      $5, $2, $0
    /* 1EFC80 002EFC80 5074040C */  jal        func_0011d140
    /* 1EFC84 002EFC84 00000000 */   nop
    /* 1EFC88 002EFC88 28014582 */  lb         $5, 0x128($18)
    /* 1EFC8C 002EFC8C 2D200000 */  daddu      $4, $0, $0
    /* 1EFC90 002EFC90 28920B0C */  jal        func_002e48a0
    /* 1EFC94 002EFC94 00000000 */   nop
    /* 1EFC98 002EFC98 4801448E */  lw         $4, 0x148($18)
    /* 1EFC9C 002EFC9C 2D284000 */  daddu      $5, $2, $0
    /* 1EFCA0 002EFCA0 2D300000 */  daddu      $6, $0, $0
    /* 1EFCA4 002EFCA4 2D380000 */  daddu      $7, $0, $0
    /* 1EFCA8 002EFCA8 01000824 */  addiu      $8, $0, 0x1
    /* 1EFCAC 002EFCAC 34510C0C */  jal        func_003144d0
    /* 1EFCB0 002EFCB0 00000000 */   nop
    /* 1EFCB4 002EFCB4 82040010 */  b          .L002F0EC0
    /* 1EFCB8 002EFCB8 00000000 */   nop
  .L002EFCBC:
    /* 1EFCBC 002EFCBC 4801448E */  lw         $4, 0x148($18)
    /* 1EFCC0 002EFCC0 F4510C0C */  jal        func_003147d0
    /* 1EFCC4 002EFCC4 00000000 */   nop
    /* 1EFCC8 002EFCC8 2D804000 */  daddu      $16, $2, $0
    /* 1EFCCC 002EFCCC FF000424 */  addiu      $4, $0, 0xFF
    /* 1EFCD0 002EFCD0 2D288000 */  daddu      $5, $4, $0
    /* 1EFCD4 002EFCD4 2D308000 */  daddu      $6, $4, $0
    /* 1EFCD8 002EFCD8 2D388000 */  daddu      $7, $4, $0
    /* 1EFCDC 002EFCDC 8CCA0A0C */  jal        func_002b2a30
    /* 1EFCE0 002EFCE0 00000000 */   nop
    /* 1EFCE4 002EFCE4 2D200002 */  daddu      $4, $16, $0
    /* 1EFCE8 002EFCE8 2D284000 */  daddu      $5, $2, $0
    /* 1EFCEC 002EFCEC 5074040C */  jal        func_0011d140
    /* 1EFCF0 002EFCF0 00000000 */   nop
    /* 1EFCF4 002EFCF4 2D200000 */  daddu      $4, $0, $0
    /* 1EFCF8 002EFCF8 1E014586 */  lh         $5, 0x11E($18)
    /* 1EFCFC 002EFCFC 28920B0C */  jal        func_002e48a0
    /* 1EFD00 002EFD00 00000000 */   nop
    /* 1EFD04 002EFD04 4801448E */  lw         $4, 0x148($18)
    /* 1EFD08 002EFD08 2D284000 */  daddu      $5, $2, $0
    /* 1EFD0C 002EFD0C 2D300000 */  daddu      $6, $0, $0
    /* 1EFD10 002EFD10 2D380000 */  daddu      $7, $0, $0
    /* 1EFD14 002EFD14 01000824 */  addiu      $8, $0, 0x1
    /* 1EFD18 002EFD18 34510C0C */  jal        func_003144d0
    /* 1EFD1C 002EFD1C 00000000 */   nop
    /* 1EFD20 002EFD20 67040010 */  b          .L002F0EC0
    /* 1EFD24 002EFD24 00000000 */   nop
  .L002EFD28:
    /* 1EFD28 002EFD28 4801448E */  lw         $4, 0x148($18)
    /* 1EFD2C 002EFD2C F4510C0C */  jal        func_003147d0
    /* 1EFD30 002EFD30 00000000 */   nop
    /* 1EFD34 002EFD34 2D804000 */  daddu      $16, $2, $0
    /* 1EFD38 002EFD38 FF000424 */  addiu      $4, $0, 0xFF
    /* 1EFD3C 002EFD3C 2D288000 */  daddu      $5, $4, $0
    /* 1EFD40 002EFD40 2D308000 */  daddu      $6, $4, $0
    /* 1EFD44 002EFD44 2D388000 */  daddu      $7, $4, $0
    /* 1EFD48 002EFD48 8CCA0A0C */  jal        func_002b2a30
    /* 1EFD4C 002EFD4C 00000000 */   nop
    /* 1EFD50 002EFD50 2D200002 */  daddu      $4, $16, $0
    /* 1EFD54 002EFD54 2D284000 */  daddu      $5, $2, $0
    /* 1EFD58 002EFD58 5074040C */  jal        func_0011d140
    /* 1EFD5C 002EFD5C 00000000 */   nop
    /* 1EFD60 002EFD60 FA024582 */  lb         $5, 0x2FA($18)
    /* 1EFD64 002EFD64 F9024482 */  lb         $4, 0x2F9($18)
    /* 1EFD68 002EFD68 28920B0C */  jal        func_002e48a0
    /* 1EFD6C 002EFD6C 00000000 */   nop
    /* 1EFD70 002EFD70 04005090 */  lbu        $16, 0x4($2)
    /* 1EFD74 002EFD74 01000424 */  addiu      $4, $0, 0x1
    /* 1EFD78 002EFD78 1C13040C */  jal        func_00104c70
    /* 1EFD7C 002EFD7C 00000000 */   nop
    /* 1EFD80 002EFD80 FF004230 */  andi       $2, $2, 0xFF
    /* 1EFD84 002EFD84 2A085000 */  slt        $1, $2, $16
    /* 1EFD88 002EFD88 0F002010 */  beqz       $1, .L002EFDC8
    /* 1EFD8C 002EFD8C 00000000 */   nop
    /* 1EFD90 002EFD90 4801448E */  lw         $4, 0x148($18)
    /* 1EFD94 002EFD94 F4510C0C */  jal        func_003147d0
    /* 1EFD98 002EFD98 00000000 */   nop
    /* 1EFD9C 002EFD9C 2D804000 */  daddu      $16, $2, $0
    /* 1EFDA0 002EFDA0 14000424 */  addiu      $4, $0, 0x14
    /* 1EFDA4 002EFDA4 2D288000 */  daddu      $5, $4, $0
    /* 1EFDA8 002EFDA8 2D308000 */  daddu      $6, $4, $0
    /* 1EFDAC 002EFDAC FF000724 */  addiu      $7, $0, 0xFF
    /* 1EFDB0 002EFDB0 8CCA0A0C */  jal        func_002b2a30
    /* 1EFDB4 002EFDB4 00000000 */   nop
    /* 1EFDB8 002EFDB8 2D200002 */  daddu      $4, $16, $0
    /* 1EFDBC 002EFDBC 2D284000 */  daddu      $5, $2, $0
    /* 1EFDC0 002EFDC0 5074040C */  jal        func_0011d140
    /* 1EFDC4 002EFDC4 00000000 */   nop
  .L002EFDC8:
    /* 1EFDC8 002EFDC8 FA025082 */  lb         $16, 0x2FA($18)
    /* 1EFDCC 002EFDCC F9024482 */  lb         $4, 0x2F9($18)
    /* 1EFDD0 002EFDD0 2D280002 */  daddu      $5, $16, $0
    /* 1EFDD4 002EFDD4 28920B0C */  jal        func_002e48a0
    /* 1EFDD8 002EFDD8 00000000 */   nop
    /* 1EFDDC 002EFDDC 2D884000 */  daddu      $17, $2, $0
    /* 1EFDE0 002EFDE0 F9024482 */  lb         $4, 0x2F9($18)
    /* 1EFDE4 002EFDE4 1C920B0C */  jal        func_002e4870
    /* 1EFDE8 002EFDE8 00000000 */   nop
    /* 1EFDEC 002EFDEC 3C1E1000 */  dsll32     $3, $16, 24
    /* 1EFDF0 002EFDF0 3F1E0300 */  dsra32     $3, $3, 24
    /* 1EFDF4 002EFDF4 21804300 */  addu       $16, $2, $3
    /* 1EFDF8 002EFDF8 FA024582 */  lb         $5, 0x2FA($18)
    /* 1EFDFC 002EFDFC F9024482 */  lb         $4, 0x2F9($18)
    /* 1EFE00 002EFE00 28920B0C */  jal        func_002e48a0
    /* 1EFE04 002EFE04 00000000 */   nop
    /* 1EFE08 002EFE08 02004394 */  lhu        $3, 0x2($2)
    /* 1EFE0C 002EFE0C C0100300 */  sll        $2, $3, 3
    /* 1EFE10 002EFE10 23104300 */  subu       $2, $2, $3
    /* 1EFE14 002EFE14 40180200 */  sll        $3, $2, 1
    /* 1EFE18 002EFE18 D4B3828F */  lw         $2, -0x4C2C($28)
    /* 1EFE1C 002EFE1C 21106200 */  addu       $2, $3, $2
    /* 1EFE20 002EFE20 02004490 */  lbu        $4, 0x2($2)
    /* 1EFE24 002EFE24 DC1D090C */  jal        func_00247770
    /* 1EFE28 002EFE28 00000000 */   nop
    /* 1EFE2C 002EFE2C 3C9C0200 */  dsll32     $19, $2, 16
    /* 1EFE30 002EFE30 3F9C1300 */  dsra32     $19, $19, 16
    /* 1EFE34 002EFE34 FA024582 */  lb         $5, 0x2FA($18)
    /* 1EFE38 002EFE38 F9024482 */  lb         $4, 0x2F9($18)
    /* 1EFE3C 002EFE3C 28920B0C */  jal        func_002e48a0
    /* 1EFE40 002EFE40 00000000 */   nop
    /* 1EFE44 002EFE44 2D206002 */  daddu      $4, $19, $0
    /* 1EFE48 002EFE48 2D284000 */  daddu      $5, $2, $0
    /* 1EFE4C 002EFE4C 2D300000 */  daddu      $6, $0, $0
    /* 1EFE50 002EFE50 4C460C0C */  jal        func_00311930
    /* 1EFE54 002EFE54 00000000 */   nop
    /* 1EFE58 002EFE58 4801448E */  lw         $4, 0x148($18)
    /* 1EFE5C 002EFE5C 2D282002 */  daddu      $5, $17, $0
    /* 1EFE60 002EFE60 E4020682 */  lb         $6, 0x2E4($16)
    /* 1EFE64 002EFE64 2D384000 */  daddu      $7, $2, $0
    /* 1EFE68 002EFE68 01000824 */  addiu      $8, $0, 0x1
    /* 1EFE6C 002EFE6C 34510C0C */  jal        func_003144d0
    /* 1EFE70 002EFE70 00000000 */   nop
    /* 1EFE74 002EFE74 12040010 */  b          .L002F0EC0
    /* 1EFE78 002EFE78 00000000 */   nop
  .L002EFE7C:
    /* 1EFE7C 002EFE7C 04008330 */  andi       $3, $4, 0x4
    /* 1EFE80 002EFE80 0F046010 */  beqz       $3, .L002F0EC0
    /* 1EFE84 002EFE84 00000000 */   nop
    /* 1EFE88 002EFE88 22014282 */  lb         $2, 0x122($18)
    /* 1EFE8C 002EFE8C 07004010 */  beqz       $2, .L002EFEAC
    /* 1EFE90 002EFE90 00000000 */   nop
    /* 1EFE94 002EFE94 2D200000 */  daddu      $4, $0, $0
    /* 1EFE98 002EFE98 02000524 */  addiu      $5, $0, 0x2
    /* 1EFE9C 002EFE9C 2D300000 */  daddu      $6, $0, $0
    /* 1EFEA0 002EFEA0 05000724 */  addiu      $7, $0, 0x5
    /* 1EFEA4 002EFEA4 D86B110C */  jal        func_0045af60
    /* 1EFEA8 002EFEA8 00000000 */   nop
  .L002EFEAC:
    /* 1EFEAC 002EFEAC 22014482 */  lb         $4, 0x122($18)
    /* 1EFEB0 002EFEB0 01000524 */  addiu      $5, $0, 0x1
    /* 1EFEB4 002EFEB4 2D300000 */  daddu      $6, $0, $0
    /* 1EFEB8 002EFEB8 02000724 */  addiu      $7, $0, 0x2
    /* 1EFEBC 002EFEBC 2D40A000 */  daddu      $8, $5, $0
    /* 1EFEC0 002EFEC0 40CB0A0C */  jal        func_002b2d00
    /* 1EFEC4 002EFEC4 00000000 */   nop
    /* 1EFEC8 002EFEC8 220142A2 */  sb         $2, 0x122($18)
    /* 1EFECC 002EFECC 51010424 */  addiu      $4, $0, 0x151
    /* 1EFED0 002EFED0 54D80A0C */  jal        func_002b6150
    /* 1EFED4 002EFED4 00000000 */   nop
    /* 1EFED8 002EFED8 2D804000 */  daddu      $16, $2, $0
    /* 1EFEDC 002EFEDC 22014382 */  lb         $3, 0x122($18)
    /* 1EFEE0 002EFEE0 C0100300 */  sll        $2, $3, 3
    /* 1EFEE4 002EFEE4 21104300 */  addu       $2, $2, $3
    /* 1EFEE8 002EFEE8 C0100200 */  sll        $2, $2, 3
    /* 1EFEEC 002EFEEC 23104300 */  subu       $2, $2, $3
    /* 1EFEF0 002EFEF0 40100200 */  sll        $2, $2, 1
    /* 1EFEF4 002EFEF4 6A004224 */  addiu      $2, $2, 0x6A
    /* 1EFEF8 002EFEF8 00008244 */  mtc1       $2, $f0
    /* 1EFEFC 002EFEFC 00000000 */  nop
    /* 1EFF00 002EFF00 20038046 */  cvt.s.w    $f12, $f0
    /* 1EFF04 002EFF04 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EFF08 002EFF08 00688244 */  mtc1       $2, $f13
    /* 1EFF0C 002EFF0C 8801A427 */  addiu      $4, $29, 0x188
    /* 1EFF10 002EFF10 5CCA0A0C */  jal        func_002b2970
    /* 1EFF14 002EFF14 00000000 */   nop
    /* 1EFF18 002EFF18 51010424 */  addiu      $4, $0, 0x151
    /* 1EFF1C 002EFF1C 3800056E */  ldr        $5, 0x38($16)
    /* 1EFF20 002EFF20 3F00056A */  ldl        $5, 0x3F($16)
    /* 1EFF24 002EFF24 8801A6DF */  ld         $6, 0x188($29)
    /* 1EFF28 002EFF28 01000724 */  addiu      $7, $0, 0x1
    /* 1EFF2C 002EFF2C 04000824 */  addiu      $8, $0, 0x4
    /* 1EFF30 002EFF30 2D480000 */  daddu      $9, $0, $0
    /* 1EFF34 002EFF34 7CDA0A0C */  jal        func_002b69f0
    /* 1EFF38 002EFF38 00000000 */   nop
    /* 1EFF3C 002EFF3C E0020424 */  addiu      $4, $0, 0x2E0
    /* 1EFF40 002EFF40 54D80A0C */  jal        func_002b6150
    /* 1EFF44 002EFF44 00000000 */   nop
    /* 1EFF48 002EFF48 2D804000 */  daddu      $16, $2, $0
    /* 1EFF4C 002EFF4C 22014382 */  lb         $3, 0x122($18)
    /* 1EFF50 002EFF50 C0100300 */  sll        $2, $3, 3
    /* 1EFF54 002EFF54 21104300 */  addu       $2, $2, $3
    /* 1EFF58 002EFF58 C0100200 */  sll        $2, $2, 3
    /* 1EFF5C 002EFF5C 23104300 */  subu       $2, $2, $3
    /* 1EFF60 002EFF60 40100200 */  sll        $2, $2, 1
    /* 1EFF64 002EFF64 6A004224 */  addiu      $2, $2, 0x6A
    /* 1EFF68 002EFF68 00008244 */  mtc1       $2, $f0
    /* 1EFF6C 002EFF6C 00000000 */  nop
    /* 1EFF70 002EFF70 20038046 */  cvt.s.w    $f12, $f0
    /* 1EFF74 002EFF74 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1EFF78 002EFF78 00688244 */  mtc1       $2, $f13
    /* 1EFF7C 002EFF7C 8001A427 */  addiu      $4, $29, 0x180
    /* 1EFF80 002EFF80 5CCA0A0C */  jal        func_002b2970
    /* 1EFF84 002EFF84 00000000 */   nop
    /* 1EFF88 002EFF88 E0020424 */  addiu      $4, $0, 0x2E0
    /* 1EFF8C 002EFF8C 3800056E */  ldr        $5, 0x38($16)
    /* 1EFF90 002EFF90 3F00056A */  ldl        $5, 0x3F($16)
    /* 1EFF94 002EFF94 8001A6DF */  ld         $6, 0x180($29)
    /* 1EFF98 002EFF98 01000724 */  addiu      $7, $0, 0x1
    /* 1EFF9C 002EFF9C 04000824 */  addiu      $8, $0, 0x4
    /* 1EFFA0 002EFFA0 2D480000 */  daddu      $9, $0, $0
    /* 1EFFA4 002EFFA4 7CDA0A0C */  jal        func_002b69f0
    /* 1EFFA8 002EFFA8 00000000 */   nop
    /* 1EFFAC 002EFFAC 22014482 */  lb         $4, 0x122($18)
    /* 1EFFB0 002EFFB0 02000324 */  addiu      $3, $0, 0x2
    /* 1EFFB4 002EFFB4 3E008310 */  beq        $4, $3, .L002F00B0
    /* 1EFFB8 002EFFB8 00000000 */   nop
    /* 1EFFBC 002EFFBC 01000324 */  addiu      $3, $0, 0x1
    /* 1EFFC0 002EFFC0 20008310 */  beq        $4, $3, .L002F0044
    /* 1EFFC4 002EFFC4 00000000 */   nop
    /* 1EFFC8 002EFFC8 03008010 */  beqz       $4, .L002EFFD8
    /* 1EFFCC 002EFFCC 00000000 */   nop
    /* 1EFFD0 002EFFD0 BB030010 */  b          .L002F0EC0
    /* 1EFFD4 002EFFD4 00000000 */   nop
  .L002EFFD8:
    /* 1EFFD8 002EFFD8 4801448E */  lw         $4, 0x148($18)
    /* 1EFFDC 002EFFDC F4510C0C */  jal        func_003147d0
    /* 1EFFE0 002EFFE0 00000000 */   nop
    /* 1EFFE4 002EFFE4 2D804000 */  daddu      $16, $2, $0
    /* 1EFFE8 002EFFE8 FF000424 */  addiu      $4, $0, 0xFF
    /* 1EFFEC 002EFFEC 2D288000 */  daddu      $5, $4, $0
    /* 1EFFF0 002EFFF0 2D308000 */  daddu      $6, $4, $0
    /* 1EFFF4 002EFFF4 2D388000 */  daddu      $7, $4, $0
    /* 1EFFF8 002EFFF8 8CCA0A0C */  jal        func_002b2a30
    /* 1EFFFC 002EFFFC 00000000 */   nop
    /* 1F0000 002F0000 2D200002 */  daddu      $4, $16, $0
    /* 1F0004 002F0004 2D284000 */  daddu      $5, $2, $0
    /* 1F0008 002F0008 5074040C */  jal        func_0011d140
    /* 1F000C 002F000C 00000000 */   nop
    /* 1F0010 002F0010 28014582 */  lb         $5, 0x128($18)
    /* 1F0014 002F0014 2D200000 */  daddu      $4, $0, $0
    /* 1F0018 002F0018 28920B0C */  jal        func_002e48a0
    /* 1F001C 002F001C 00000000 */   nop
    /* 1F0020 002F0020 4801448E */  lw         $4, 0x148($18)
    /* 1F0024 002F0024 2D284000 */  daddu      $5, $2, $0
    /* 1F0028 002F0028 2D300000 */  daddu      $6, $0, $0
    /* 1F002C 002F002C 2D380000 */  daddu      $7, $0, $0
    /* 1F0030 002F0030 01000824 */  addiu      $8, $0, 0x1
    /* 1F0034 002F0034 34510C0C */  jal        func_003144d0
    /* 1F0038 002F0038 00000000 */   nop
    /* 1F003C 002F003C A0030010 */  b          .L002F0EC0
    /* 1F0040 002F0040 00000000 */   nop
  .L002F0044:
    /* 1F0044 002F0044 4801448E */  lw         $4, 0x148($18)
    /* 1F0048 002F0048 F4510C0C */  jal        func_003147d0
    /* 1F004C 002F004C 00000000 */   nop
    /* 1F0050 002F0050 2D804000 */  daddu      $16, $2, $0
    /* 1F0054 002F0054 FF000424 */  addiu      $4, $0, 0xFF
    /* 1F0058 002F0058 2D288000 */  daddu      $5, $4, $0
    /* 1F005C 002F005C 2D308000 */  daddu      $6, $4, $0
    /* 1F0060 002F0060 2D388000 */  daddu      $7, $4, $0
    /* 1F0064 002F0064 8CCA0A0C */  jal        func_002b2a30
    /* 1F0068 002F0068 00000000 */   nop
    /* 1F006C 002F006C 2D200002 */  daddu      $4, $16, $0
    /* 1F0070 002F0070 2D284000 */  daddu      $5, $2, $0
    /* 1F0074 002F0074 5074040C */  jal        func_0011d140
    /* 1F0078 002F0078 00000000 */   nop
    /* 1F007C 002F007C 2D200000 */  daddu      $4, $0, $0
    /* 1F0080 002F0080 1E014586 */  lh         $5, 0x11E($18)
    /* 1F0084 002F0084 28920B0C */  jal        func_002e48a0
    /* 1F0088 002F0088 00000000 */   nop
    /* 1F008C 002F008C 4801448E */  lw         $4, 0x148($18)
    /* 1F0090 002F0090 2D284000 */  daddu      $5, $2, $0
    /* 1F0094 002F0094 2D300000 */  daddu      $6, $0, $0
    /* 1F0098 002F0098 2D380000 */  daddu      $7, $0, $0
    /* 1F009C 002F009C 01000824 */  addiu      $8, $0, 0x1
    /* 1F00A0 002F00A0 34510C0C */  jal        func_003144d0
    /* 1F00A4 002F00A4 00000000 */   nop
    /* 1F00A8 002F00A8 85030010 */  b          .L002F0EC0
    /* 1F00AC 002F00AC 00000000 */   nop
  .L002F00B0:
    /* 1F00B0 002F00B0 4801448E */  lw         $4, 0x148($18)
    /* 1F00B4 002F00B4 F4510C0C */  jal        func_003147d0
    /* 1F00B8 002F00B8 00000000 */   nop
    /* 1F00BC 002F00BC 2D804000 */  daddu      $16, $2, $0
    /* 1F00C0 002F00C0 FF000424 */  addiu      $4, $0, 0xFF
    /* 1F00C4 002F00C4 2D288000 */  daddu      $5, $4, $0
    /* 1F00C8 002F00C8 2D308000 */  daddu      $6, $4, $0
    /* 1F00CC 002F00CC 2D388000 */  daddu      $7, $4, $0
    /* 1F00D0 002F00D0 8CCA0A0C */  jal        func_002b2a30
    /* 1F00D4 002F00D4 00000000 */   nop
    /* 1F00D8 002F00D8 2D200002 */  daddu      $4, $16, $0
    /* 1F00DC 002F00DC 2D284000 */  daddu      $5, $2, $0
    /* 1F00E0 002F00E0 5074040C */  jal        func_0011d140
    /* 1F00E4 002F00E4 00000000 */   nop
    /* 1F00E8 002F00E8 FA024582 */  lb         $5, 0x2FA($18)
    /* 1F00EC 002F00EC F9024482 */  lb         $4, 0x2F9($18)
    /* 1F00F0 002F00F0 28920B0C */  jal        func_002e48a0
    /* 1F00F4 002F00F4 00000000 */   nop
    /* 1F00F8 002F00F8 04005090 */  lbu        $16, 0x4($2)
    /* 1F00FC 002F00FC 01000424 */  addiu      $4, $0, 0x1
    /* 1F0100 002F0100 1C13040C */  jal        func_00104c70
    /* 1F0104 002F0104 00000000 */   nop
    /* 1F0108 002F0108 FF004230 */  andi       $2, $2, 0xFF
    /* 1F010C 002F010C 2A085000 */  slt        $1, $2, $16
    /* 1F0110 002F0110 0F002010 */  beqz       $1, .L002F0150
    /* 1F0114 002F0114 00000000 */   nop
    /* 1F0118 002F0118 4801448E */  lw         $4, 0x148($18)
    /* 1F011C 002F011C F4510C0C */  jal        func_003147d0
    /* 1F0120 002F0120 00000000 */   nop
    /* 1F0124 002F0124 2D804000 */  daddu      $16, $2, $0
    /* 1F0128 002F0128 14000424 */  addiu      $4, $0, 0x14
    /* 1F012C 002F012C 2D288000 */  daddu      $5, $4, $0
    /* 1F0130 002F0130 2D308000 */  daddu      $6, $4, $0
    /* 1F0134 002F0134 FF000724 */  addiu      $7, $0, 0xFF
    /* 1F0138 002F0138 8CCA0A0C */  jal        func_002b2a30
    /* 1F013C 002F013C 00000000 */   nop
    /* 1F0140 002F0140 2D200002 */  daddu      $4, $16, $0
    /* 1F0144 002F0144 2D284000 */  daddu      $5, $2, $0
    /* 1F0148 002F0148 5074040C */  jal        func_0011d140
    /* 1F014C 002F014C 00000000 */   nop
  .L002F0150:
    /* 1F0150 002F0150 FA025082 */  lb         $16, 0x2FA($18)
    /* 1F0154 002F0154 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0158 002F0158 2D280002 */  daddu      $5, $16, $0
    /* 1F015C 002F015C 28920B0C */  jal        func_002e48a0
    /* 1F0160 002F0160 00000000 */   nop
    /* 1F0164 002F0164 2D884000 */  daddu      $17, $2, $0
    /* 1F0168 002F0168 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F016C 002F016C 1C920B0C */  jal        func_002e4870
    /* 1F0170 002F0170 00000000 */   nop
    /* 1F0174 002F0174 3C1E1000 */  dsll32     $3, $16, 24
    /* 1F0178 002F0178 3F1E0300 */  dsra32     $3, $3, 24
    /* 1F017C 002F017C 21804300 */  addu       $16, $2, $3
    /* 1F0180 002F0180 FA024582 */  lb         $5, 0x2FA($18)
    /* 1F0184 002F0184 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0188 002F0188 28920B0C */  jal        func_002e48a0
    /* 1F018C 002F018C 00000000 */   nop
    /* 1F0190 002F0190 02004394 */  lhu        $3, 0x2($2)
    /* 1F0194 002F0194 C0100300 */  sll        $2, $3, 3
    /* 1F0198 002F0198 23104300 */  subu       $2, $2, $3
    /* 1F019C 002F019C 40180200 */  sll        $3, $2, 1
    /* 1F01A0 002F01A0 D4B3828F */  lw         $2, -0x4C2C($28)
    /* 1F01A4 002F01A4 21106200 */  addu       $2, $3, $2
    /* 1F01A8 002F01A8 02004490 */  lbu        $4, 0x2($2)
    /* 1F01AC 002F01AC DC1D090C */  jal        func_00247770
    /* 1F01B0 002F01B0 00000000 */   nop
    /* 1F01B4 002F01B4 3C9C0200 */  dsll32     $19, $2, 16
    /* 1F01B8 002F01B8 3F9C1300 */  dsra32     $19, $19, 16
    /* 1F01BC 002F01BC FA024582 */  lb         $5, 0x2FA($18)
    /* 1F01C0 002F01C0 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F01C4 002F01C4 28920B0C */  jal        func_002e48a0
    /* 1F01C8 002F01C8 00000000 */   nop
    /* 1F01CC 002F01CC 2D206002 */  daddu      $4, $19, $0
    /* 1F01D0 002F01D0 2D284000 */  daddu      $5, $2, $0
    /* 1F01D4 002F01D4 2D300000 */  daddu      $6, $0, $0
    /* 1F01D8 002F01D8 4C460C0C */  jal        func_00311930
    /* 1F01DC 002F01DC 00000000 */   nop
    /* 1F01E0 002F01E0 4801448E */  lw         $4, 0x148($18)
    /* 1F01E4 002F01E4 2D282002 */  daddu      $5, $17, $0
    /* 1F01E8 002F01E8 E4020682 */  lb         $6, 0x2E4($16)
    /* 1F01EC 002F01EC 2D384000 */  daddu      $7, $2, $0
    /* 1F01F0 002F01F0 01000824 */  addiu      $8, $0, 0x1
    /* 1F01F4 002F01F4 34510C0C */  jal        func_003144d0
    /* 1F01F8 002F01F8 00000000 */   nop
    /* 1F01FC 002F01FC 30030010 */  b          .L002F0EC0
    /* 1F0200 002F0200 00000000 */   nop
    /* 1F0204 002F0204 7C000424 */  addiu      $4, $0, 0x7C
    /* 1F0208 002F0208 54D80A0C */  jal        func_002b6150
    /* 1F020C 002F020C 00000000 */   nop
    /* 1F0210 002F0210 6E005090 */  lbu        $16, 0x6E($2)
    /* 1F0214 002F0214 3800918E */  lw         $17, 0x38($20)
    /* 1F0218 002F0218 7C000424 */  addiu      $4, $0, 0x7C
    /* 1F021C 002F021C 54D80A0C */  jal        func_002b6150
    /* 1F0220 002F0220 00000000 */   nop
    /* 1F0224 002F0224 380041C4 */  lwc1       $f1, 0x38($2)
    /* 1F0228 002F0228 3C0040C4 */  lwc1       $f0, 0x3C($2)
    /* 1F022C 002F022C 3801A1E7 */  swc1       $f1, 0x138($29)
    /* 1F0230 002F0230 3C01A0E7 */  swc1       $f0, 0x13C($29)
    /* 1F0234 002F0234 CC000424 */  addiu      $4, $0, 0xCC
    /* 1F0238 002F0238 FF000524 */  addiu      $5, $0, 0xFF
    /* 1F023C 002F023C 2D30A000 */  daddu      $6, $5, $0
    /* 1F0240 002F0240 2D380002 */  daddu      $7, $16, $0
    /* 1F0244 002F0244 8CCA0A0C */  jal        func_002b2a30
    /* 1F0248 002F0248 00000000 */   nop
    /* 1F024C 002F024C 2D804000 */  daddu      $16, $2, $0
    /* 1F0250 002F0250 28012582 */  lb         $5, 0x128($17)
    /* 1F0254 002F0254 2D200000 */  daddu      $4, $0, $0
    /* 1F0258 002F0258 28920B0C */  jal        func_002e48a0
    /* 1F025C 002F025C 00000000 */   nop
    /* 1F0260 002F0260 02004394 */  lhu        $3, 0x2($2)
    /* 1F0264 002F0264 00110300 */  sll        $2, $3, 4
    /* 1F0268 002F0268 21184300 */  addu       $3, $2, $3
    /* 1F026C 002F026C 40B4828F */  lw         $2, -0x4BC0($28)
    /* 1F0270 002F0270 21384300 */  addu       $7, $2, $3
    /* 1F0274 002F0274 DE42023C */  lui        $2, (0x42DE0000 >> 16)
    /* 1F0278 002F0278 00088244 */  mtc1       $2, $f1
    /* 1F027C 002F027C 3801A0C7 */  lwc1       $f0, 0x138($29)
    /* 1F0280 002F0280 000B0046 */  add.s      $f12, $f1, $f0
    /* 1F0284 002F0284 2C42023C */  lui        $2, (0x422C0000 >> 16)
    /* 1F0288 002F0288 00708244 */  mtc1       $2, $f14
    /* 1F028C 002F028C 3C01ADC7 */  lwc1       $f13, 0x13C($29)
    /* 1F0290 002F0290 2D200002 */  daddu      $4, $16, $0
    /* 1F0294 002F0294 2D280000 */  daddu      $5, $0, $0
    /* 1F0298 002F0298 02000624 */  addiu      $6, $0, 0x2
    /* 1F029C 002F029C 2D400000 */  daddu      $8, $0, $0
    /* 1F02A0 002F02A0 2D480000 */  daddu      $9, $0, $0
    /* 1F02A4 002F02A4 79000A3C */  lui        $10, %hi(D_00795E60)
    /* 1F02A8 002F02A8 605E4A25 */  addiu      $10, $10, %lo(D_00795E60)
    /* 1F02AC 002F02AC 15000B24 */  addiu      $11, $0, 0x15
    /* 1F02B0 002F02B0 08D6090C */  jal        func_00275820
    /* 1F02B4 002F02B4 00000000 */   nop
    /* 1F02B8 002F02B8 4801448E */  lw         $4, 0x148($18)
    /* 1F02BC 002F02BC 98510C0C */  jal        func_00314660
    /* 1F02C0 002F02C0 00000000 */   nop
    /* 1F02C4 002F02C4 3C260200 */  dsll32     $4, $2, 24
    /* 1F02C8 002F02C8 3F260400 */  dsra32     $4, $4, 24
    /* 1F02CC 002F02CC 0E000324 */  addiu      $3, $0, 0xE
    /* 1F02D0 002F02D0 FB028314 */  bne        $4, $3, .L002F0EC0
    /* 1F02D4 002F02D4 00000000 */   nop
    /* 1F02D8 002F02D8 2D208002 */  daddu      $4, $20, $0
    /* 1F02DC 002F02DC 01000524 */  addiu      $5, $0, 0x1
    /* 1F02E0 002F02E0 2D300000 */  daddu      $6, $0, $0
    /* 1F02E4 002F02E4 1C590C0C */  jal        func_00316470
    /* 1F02E8 002F02E8 00000000 */   nop
    /* 1F02EC 002F02EC 0000A0FF */  sd         $0, 0x0($29)
    /* 1F02F0 002F02F0 0800A0FF */  sd         $0, 0x8($29)
    /* 1F02F4 002F02F4 1000A0FF */  sd         $0, 0x10($29)
    /* 1F02F8 002F02F8 2D208002 */  daddu      $4, $20, $0
    /* 1F02FC 002F02FC 2D280000 */  daddu      $5, $0, $0
    /* 1F0300 002F0300 2D300000 */  daddu      $6, $0, $0
    /* 1F0304 002F0304 2D380000 */  daddu      $7, $0, $0
    /* 1F0308 002F0308 2D400000 */  daddu      $8, $0, $0
    /* 1F030C 002F030C 01000924 */  addiu      $9, $0, 0x1
    /* 1F0310 002F0310 2D500000 */  daddu      $10, $0, $0
    /* 1F0314 002F0314 2D580000 */  daddu      $11, $0, $0
    /* 1F0318 002F0318 A05B0C0C */  jal        func_00316e80
    /* 1F031C 002F031C 00000000 */   nop
    /* 1F0320 002F0320 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1F0324 002F0324 290142A2 */  sb         $2, 0x129($18)
    /* 1F0328 002F0328 2D880000 */  daddu      $17, $0, $0
    /* 1F032C 002F032C 4A000010 */  b          .L002F0458
    /* 1F0330 002F0330 00000000 */   nop
  .L002F0334:
    /* 1F0334 002F0334 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1F0338 002F0338 00608244 */  mtc1       $2, $f12
    /* 1F033C 002F033C 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1F0340 002F0340 00688244 */  mtc1       $2, $f13
    /* 1F0344 002F0344 7801A427 */  addiu      $4, $29, 0x178
    /* 1F0348 002F0348 5CCA0A0C */  jal        func_002b2970
    /* 1F034C 002F034C 00000000 */   nop
    /* 1F0350 002F0350 2D200000 */  daddu      $4, $0, $0
    /* 1F0354 002F0354 2D282002 */  daddu      $5, $17, $0
    /* 1F0358 002F0358 28920B0C */  jal        func_002e48a0
    /* 1F035C 002F035C 00000000 */   nop
    /* 1F0360 002F0360 02005394 */  lhu        $19, 0x2($2)
    /* 1F0364 002F0364 2D200000 */  daddu      $4, $0, $0
    /* 1F0368 002F0368 2D282002 */  daddu      $5, $17, $0
    /* 1F036C 002F036C 28920B0C */  jal        func_002e48a0
    /* 1F0370 002F0370 00000000 */   nop
    /* 1F0374 002F0374 04005090 */  lbu        $16, 0x4($2)
    /* 1F0378 002F0378 2D200000 */  daddu      $4, $0, $0
    /* 1F037C 002F037C 1C920B0C */  jal        func_002e4870
    /* 1F0380 002F0380 00000000 */   nop
    /* 1F0384 002F0384 08004B80 */  lb         $11, 0x8($2)
    /* 1F0388 002F0388 3C361100 */  dsll32     $6, $17, 24
    /* 1F038C 002F038C 3F360600 */  dsra32     $6, $6, 24
    /* 1F0390 002F0390 2D208002 */  daddu      $4, $20, $0
    /* 1F0394 002F0394 7801A5DF */  ld         $5, 0x178($29)
    /* 1F0398 002F0398 2D386002 */  daddu      $7, $19, $0
    /* 1F039C 002F039C 2D400002 */  daddu      $8, $16, $0
    /* 1F03A0 002F03A0 2D480000 */  daddu      $9, $0, $0
    /* 1F03A4 002F03A4 2D500000 */  daddu      $10, $0, $0
    /* 1F03A8 002F03A8 70640C0C */  jal        func_003191c0
    /* 1F03AC 002F03AC 00000000 */   nop
    /* 1F03B0 002F03B0 49010224 */  addiu      $2, $0, 0x149
    /* 1F03B4 002F03B4 00008244 */  mtc1       $2, $f0
    /* 1F03B8 002F03B8 00000000 */  nop
    /* 1F03BC 002F03BC 20038046 */  cvt.s.w    $f12, $f0
    /* 1F03C0 002F03C0 0043023C */  lui        $2, (0x43000000 >> 16)
    /* 1F03C4 002F03C4 00688244 */  mtc1       $2, $f13
    /* 1F03C8 002F03C8 7001A427 */  addiu      $4, $29, 0x170
    /* 1F03CC 002F03CC 5CCA0A0C */  jal        func_002b2970
    /* 1F03D0 002F03D0 00000000 */   nop
    /* 1F03D4 002F03D4 28014282 */  lb         $2, 0x128($18)
    /* 1F03D8 002F03D8 01004224 */  addiu      $2, $2, 0x1
    /* 1F03DC 002F03DC 3C260200 */  dsll32     $4, $2, 24
    /* 1F03E0 002F03E0 3F260400 */  dsra32     $4, $4, 24
    /* 1F03E4 002F03E4 2D282002 */  daddu      $5, $17, $0
    /* 1F03E8 002F03E8 28920B0C */  jal        func_002e48a0
    /* 1F03EC 002F03EC 00000000 */   nop
    /* 1F03F0 002F03F0 02005094 */  lhu        $16, 0x2($2)
    /* 1F03F4 002F03F4 28014282 */  lb         $2, 0x128($18)
    /* 1F03F8 002F03F8 01004224 */  addiu      $2, $2, 0x1
    /* 1F03FC 002F03FC 3C260200 */  dsll32     $4, $2, 24
    /* 1F0400 002F0400 3F260400 */  dsra32     $4, $4, 24
    /* 1F0404 002F0404 2D282002 */  daddu      $5, $17, $0
    /* 1F0408 002F0408 28920B0C */  jal        func_002e48a0
    /* 1F040C 002F040C 00000000 */   nop
    /* 1F0410 002F0410 04004990 */  lbu        $9, 0x4($2)
    /* 1F0414 002F0414 01000224 */  addiu      $2, $0, 0x1
    /* 1F0418 002F0418 0000A2FF */  sd         $2, 0x0($29)
    /* 1F041C 002F041C CC000224 */  addiu      $2, $0, 0xCC
    /* 1F0420 002F0420 0800A2FF */  sd         $2, 0x8($29)
    /* 1F0424 002F0424 3C3E1100 */  dsll32     $7, $17, 24
    /* 1F0428 002F0428 3F3E0700 */  dsra32     $7, $7, 24
    /* 1F042C 002F042C 2D208002 */  daddu      $4, $20, $0
    /* 1F0430 002F0430 7001A5DF */  ld         $5, 0x170($29)
    /* 1F0434 002F0434 28014682 */  lb         $6, 0x128($18)
    /* 1F0438 002F0438 2D400002 */  daddu      $8, $16, $0
    /* 1F043C 002F043C 2D500000 */  daddu      $10, $0, $0
    /* 1F0440 002F0440 2D580000 */  daddu      $11, $0, $0
    /* 1F0444 002F0444 046B0C0C */  jal        func_0031ac10
    /* 1F0448 002F0448 00000000 */   nop
    /* 1F044C 002F044C 01002226 */  addiu      $2, $17, 0x1
    /* 1F0450 002F0450 3C8C0200 */  dsll32     $17, $2, 16
    /* 1F0454 002F0454 3F8C1100 */  dsra32     $17, $17, 16
  .L002F0458:
    /* 1F0458 002F0458 3C841100 */  dsll32     $16, $17, 16
    /* 1F045C 002F045C 3F841000 */  dsra32     $16, $16, 16
    /* 1F0460 002F0460 6C2D040C */  jal        func_0010b5b0
    /* 1F0464 002F0464 00000000 */   nop
    /* 1F0468 002F0468 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 1F046C 002F046C 2A100202 */  slt        $2, $16, $2
    /* 1F0470 002F0470 B0FF4014 */  bnez       $2, .L002F0334
    /* 1F0474 002F0474 00000000 */   nop
    /* 1F0478 002F0478 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 1F047C 002F047C 00608244 */  mtc1       $2, $f12
    /* 1F0480 002F0480 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1F0484 002F0484 00688244 */  mtc1       $2, $f13
    /* 1F0488 002F0488 6801A427 */  addiu      $4, $29, 0x168
    /* 1F048C 002F048C 5CCA0A0C */  jal        func_002b2970
    /* 1F0490 002F0490 00000000 */   nop
    /* 1F0494 002F0494 2D208002 */  daddu      $4, $20, $0
    /* 1F0498 002F0498 6801A5DF */  ld         $5, 0x168($29)
    /* 1F049C 002F049C 2D300000 */  daddu      $6, $0, $0
    /* 1F04A0 002F04A0 2D380000 */  daddu      $7, $0, $0
    /* 1F04A4 002F04A4 2D400000 */  daddu      $8, $0, $0
    /* 1F04A8 002F04A8 2D480000 */  daddu      $9, $0, $0
    /* 1F04AC 002F04AC 2D500000 */  daddu      $10, $0, $0
    /* 1F04B0 002F04B0 6C790C0C */  jal        func_0031e5b0
    /* 1F04B4 002F04B4 00000000 */   nop
    /* 1F04B8 002F04B8 49010224 */  addiu      $2, $0, 0x149
    /* 1F04BC 002F04BC 00008244 */  mtc1       $2, $f0
    /* 1F04C0 002F04C0 00000000 */  nop
    /* 1F04C4 002F04C4 20038046 */  cvt.s.w    $f12, $f0
    /* 1F04C8 002F04C8 D042023C */  lui        $2, (0x42D00000 >> 16)
    /* 1F04CC 002F04CC 00688244 */  mtc1       $2, $f13
    /* 1F04D0 002F04D0 6001A427 */  addiu      $4, $29, 0x160
    /* 1F04D4 002F04D4 5CCA0A0C */  jal        func_002b2970
    /* 1F04D8 002F04D8 00000000 */   nop
    /* 1F04DC 002F04DC 2D208002 */  daddu      $4, $20, $0
    /* 1F04E0 002F04E0 6001A5DF */  ld         $5, 0x160($29)
    /* 1F04E4 002F04E4 2D300000 */  daddu      $6, $0, $0
    /* 1F04E8 002F04E8 2D380000 */  daddu      $7, $0, $0
    /* 1F04EC 002F04EC 887E0C0C */  jal        func_0031fa20
    /* 1F04F0 002F04F0 00000000 */   nop
    /* 1F04F4 002F04F4 8C02448E */  lw         $4, 0x28C($18)
    /* 1F04F8 002F04F8 2D280000 */  daddu      $5, $0, $0
    /* 1F04FC 002F04FC 50D80A0C */  jal        func_002b6140
    /* 1F0500 002F0500 00000000 */   nop
    /* 1F0504 002F0504 9002448E */  lw         $4, 0x290($18)
    /* 1F0508 002F0508 2D280000 */  daddu      $5, $0, $0
    /* 1F050C 002F050C 50D80A0C */  jal        func_002b6140
    /* 1F0510 002F0510 00000000 */   nop
    /* 1F0514 002F0514 2A000324 */  addiu      $3, $0, 0x2A
    /* 1F0518 002F0518 010043A2 */  sb         $3, 0x1($18)
    /* 1F051C 002F051C 68020010 */  b          .L002F0EC0
    /* 1F0520 002F0520 00000000 */   nop
    /* 1F0524 002F0524 FA024582 */  lb         $5, 0x2FA($18)
    /* 1F0528 002F0528 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F052C 002F052C 28920B0C */  jal        func_002e48a0
    /* 1F0530 002F0530 00000000 */   nop
    /* 1F0534 002F0534 02005094 */  lhu        $16, 0x2($2)
    /* 1F0538 002F0538 FA024582 */  lb         $5, 0x2FA($18)
    /* 1F053C 002F053C F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0540 002F0540 28920B0C */  jal        func_002e48a0
    /* 1F0544 002F0544 00000000 */   nop
    /* 1F0548 002F0548 04005190 */  lbu        $17, 0x4($2)
    /* 1F054C 002F054C 01000424 */  addiu      $4, $0, 0x1
    /* 1F0550 002F0550 1C13040C */  jal        func_00104c70
    /* 1F0554 002F0554 00000000 */   nop
    /* 1F0558 002F0558 FF004230 */  andi       $2, $2, 0xFF
    /* 1F055C 002F055C 2A085100 */  slt        $1, $2, $17
    /* 1F0560 002F0560 0A002010 */  beqz       $1, .L002F058C
    /* 1F0564 002F0564 00000000 */   nop
    /* 1F0568 002F0568 2D208002 */  daddu      $4, $20, $0
    /* 1F056C 002F056C 26000524 */  addiu      $5, $0, 0x26
    /* 1F0570 002F0570 2D300000 */  daddu      $6, $0, $0
    /* 1F0574 002F0574 58420C0C */  jal        func_00310960
    /* 1F0578 002F0578 00000000 */   nop
    /* 1F057C 002F057C 31000324 */  addiu      $3, $0, 0x31
    /* 1F0580 002F0580 010043A2 */  sb         $3, 0x1($18)
    /* 1F0584 002F0584 4E020010 */  b          .L002F0EC0
    /* 1F0588 002F0588 00000000 */   nop
  .L002F058C:
    /* 1F058C 002F058C FA024582 */  lb         $5, 0x2FA($18)
    /* 1F0590 002F0590 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0594 002F0594 28920B0C */  jal        func_002e48a0
    /* 1F0598 002F0598 00000000 */   nop
    /* 1F059C 002F059C 02004584 */  lh         $5, 0x2($2)
    /* 1F05A0 002F05A0 2D200000 */  daddu      $4, $0, $0
    /* 1F05A4 002F05A4 EC940B0C */  jal        func_002e53b0
    /* 1F05A8 002F05A8 00000000 */   nop
    /* 1F05AC 002F05AC 01000324 */  addiu      $3, $0, 0x1
    /* 1F05B0 002F05B0 0A004314 */  bne        $2, $3, .L002F05DC
    /* 1F05B4 002F05B4 00000000 */   nop
    /* 1F05B8 002F05B8 2D208002 */  daddu      $4, $20, $0
    /* 1F05BC 002F05BC 27000524 */  addiu      $5, $0, 0x27
    /* 1F05C0 002F05C0 2D300000 */  daddu      $6, $0, $0
    /* 1F05C4 002F05C4 58420C0C */  jal        func_00310960
    /* 1F05C8 002F05C8 00000000 */   nop
    /* 1F05CC 002F05CC 31000324 */  addiu      $3, $0, 0x31
    /* 1F05D0 002F05D0 010043A2 */  sb         $3, 0x1($18)
    /* 1F05D4 002F05D4 3A020010 */  b          .L002F0EC0
    /* 1F05D8 002F05D8 00000000 */   nop
  .L002F05DC:
    /* 1F05DC 002F05DC 2D200002 */  daddu      $4, $16, $0
    /* 1F05E0 002F05E0 D417040C */  jal        func_00105f50
    /* 1F05E4 002F05E4 00000000 */   nop
    /* 1F05E8 002F05E8 3C160200 */  dsll32     $2, $2, 24
    /* 1F05EC 002F05EC 3F160200 */  dsra32     $2, $2, 24
    /* 1F05F0 002F05F0 07004014 */  bnez       $2, .L002F0610
    /* 1F05F4 002F05F4 00000000 */   nop
    /* 1F05F8 002F05F8 2D208002 */  daddu      $4, $20, $0
    /* 1F05FC 002F05FC 2D280002 */  daddu      $5, $16, $0
    /* 1F0600 002F0600 84420C0C */  jal        func_00310a10
    /* 1F0604 002F0604 00000000 */   nop
    /* 1F0608 002F0608 0D000010 */  b          .L002F0640
    /* 1F060C 002F060C 00000000 */   nop
  .L002F0610:
    /* 1F0610 002F0610 2D200002 */  daddu      $4, $16, $0
    /* 1F0614 002F0614 D417040C */  jal        func_00105f50
    /* 1F0618 002F0618 00000000 */   nop
    /* 1F061C 002F061C 3C160200 */  dsll32     $2, $2, 24
    /* 1F0620 002F0620 3F160200 */  dsra32     $2, $2, 24
    /* 1F0624 002F0624 2E004224 */  addiu      $2, $2, 0x2E
    /* 1F0628 002F0628 3C2E0200 */  dsll32     $5, $2, 24
    /* 1F062C 002F062C 3F2E0500 */  dsra32     $5, $5, 24
    /* 1F0630 002F0630 2D208002 */  daddu      $4, $20, $0
    /* 1F0634 002F0634 01000624 */  addiu      $6, $0, 0x1
    /* 1F0638 002F0638 58420C0C */  jal        func_00310960
    /* 1F063C 002F063C 00000000 */   nop
  .L002F0640:
    /* 1F0640 002F0640 30000324 */  addiu      $3, $0, 0x30
    /* 1F0644 002F0644 010043A2 */  sb         $3, 0x1($18)
    /* 1F0648 002F0648 1D020010 */  b          .L002F0EC0
    /* 1F064C 002F064C 00000000 */   nop
    /* 1F0650 002F0650 0D004482 */  lb         $4, 0xD($18)
    /* 1F0654 002F0654 A0ED0A0C */  jal        func_002bb680
    /* 1F0658 002F0658 00000000 */   nop
    /* 1F065C 002F065C 06004010 */  beqz       $2, .L002F0678
    /* 1F0660 002F0660 00000000 */   nop
    /* 1F0664 002F0664 0D004482 */  lb         $4, 0xD($18)
    /* 1F0668 002F0668 3CEF0A0C */  jal        func_002bbcf0
    /* 1F066C 002F066C 00000000 */   nop
    /* 1F0670 002F0670 13020010 */  b          .L002F0EC0
    /* 1F0674 002F0674 00000000 */   nop
  .L002F0678:
    /* 1F0678 002F0678 0D004482 */  lb         $4, 0xD($18)
    /* 1F067C 002F067C 70EC0A0C */  jal        func_002bb1c0
    /* 1F0680 002F0680 00000000 */   nop
    /* 1F0684 002F0684 09004014 */  bnez       $2, .L002F06AC
    /* 1F0688 002F0688 00000000 */   nop
    /* 1F068C 002F068C 33000224 */  addiu      $2, $0, 0x33
    /* 1F0690 002F0690 010042A2 */  sb         $2, 0x1($18)
    /* 1F0694 002F0694 01000424 */  addiu      $4, $0, 0x1
    /* 1F0698 002F0698 0A000524 */  addiu      $5, $0, 0xA
    /* 1F069C 002F069C 4889040C */  jal        func_00122520
    /* 1F06A0 002F06A0 00000000 */   nop
    /* 1F06A4 002F06A4 03000010 */  b          .L002F06B4
    /* 1F06A8 002F06A8 00000000 */   nop
  .L002F06AC:
    /* 1F06AC 002F06AC 2D000224 */  addiu      $2, $0, 0x2D
    /* 1F06B0 002F06B0 010042A2 */  sb         $2, 0x1($18)
  .L002F06B4:
    /* 1F06B4 002F06B4 0D004482 */  lb         $4, 0xD($18)
    /* 1F06B8 002F06B8 54ED0A0C */  jal        func_002bb550
    /* 1F06BC 002F06BC 00000000 */   nop
    /* 1F06C0 002F06C0 FF010010 */  b          .L002F0EC0
    /* 1F06C4 002F06C4 00000000 */   nop
    /* 1F06C8 002F06C8 0D004482 */  lb         $4, 0xD($18)
    /* 1F06CC 002F06CC A0ED0A0C */  jal        func_002bb680
    /* 1F06D0 002F06D0 00000000 */   nop
    /* 1F06D4 002F06D4 06004010 */  beqz       $2, .L002F06F0
    /* 1F06D8 002F06D8 00000000 */   nop
    /* 1F06DC 002F06DC 0D004482 */  lb         $4, 0xD($18)
    /* 1F06E0 002F06E0 3CEF0A0C */  jal        func_002bbcf0
    /* 1F06E4 002F06E4 00000000 */   nop
    /* 1F06E8 002F06E8 F5010010 */  b          .L002F0EC0
    /* 1F06EC 002F06EC 00000000 */   nop
  .L002F06F0:
    /* 1F06F0 002F06F0 0D004482 */  lb         $4, 0xD($18)
    /* 1F06F4 002F06F4 54ED0A0C */  jal        func_002bb550
    /* 1F06F8 002F06F8 00000000 */   nop
    /* 1F06FC 002F06FC 2D000324 */  addiu      $3, $0, 0x2D
    /* 1F0700 002F0700 010043A2 */  sb         $3, 0x1($18)
    /* 1F0704 002F0704 EE010010 */  b          .L002F0EC0
    /* 1F0708 002F0708 00000000 */   nop
    /* 1F070C 002F070C C889040C */  jal        func_00122720
    /* 1F0710 002F0710 00000000 */   nop
    /* 1F0714 002F0714 EA014010 */  beqz       $2, .L002F0EC0
    /* 1F0718 002F0718 00000000 */   nop
    /* 1F071C 002F071C 4801448E */  lw         $4, 0x148($18)
    /* 1F0720 002F0720 0B000524 */  addiu      $5, $0, 0xB
    /* 1F0724 002F0724 9C510C0C */  jal        func_00314670
    /* 1F0728 002F0728 00000000 */   nop
    /* 1F072C 002F072C 4801448E */  lw         $4, 0x148($18)
    /* 1F0730 002F0730 A0510C0C */  jal        func_00314680
    /* 1F0734 002F0734 00000000 */   nop
    /* 1F0738 002F0738 2D208002 */  daddu      $4, $20, $0
    /* 1F073C 002F073C 03000524 */  addiu      $5, $0, 0x3
    /* 1F0740 002F0740 01000624 */  addiu      $6, $0, 0x1
    /* 1F0744 002F0744 14950C0C */  jal        func_00325450
    /* 1F0748 002F0748 00000000 */   nop
    /* 1F074C 002F074C 2D800000 */  daddu      $16, $0, $0
    /* 1F0750 002F0750 09000010 */  b          .L002F0778
    /* 1F0754 002F0754 00000000 */   nop
  .L002F0758:
    /* 1F0758 002F0758 2D200002 */  daddu      $4, $16, $0
    /* 1F075C 002F075C 2D280000 */  daddu      $5, $0, $0
    /* 1F0760 002F0760 01000624 */  addiu      $6, $0, 0x1
    /* 1F0764 002F0764 34DA0A0C */  jal        func_002b68d0
    /* 1F0768 002F0768 00000000 */   nop
    /* 1F076C 002F076C 01000326 */  addiu      $3, $16, 0x1
    /* 1F0770 002F0770 3C840300 */  dsll32     $16, $3, 16
    /* 1F0774 002F0774 3F841000 */  dsra32     $16, $16, 16
  .L002F0778:
    /* 1F0778 002F0778 3C1C1000 */  dsll32     $3, $16, 16
    /* 1F077C 002F077C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1F0780 002F0780 0C036328 */  slti       $3, $3, 0x30C
    /* 1F0784 002F0784 F4FF6014 */  bnez       $3, .L002F0758
    /* 1F0788 002F0788 00000000 */   nop
    /* 1F078C 002F078C 32000324 */  addiu      $3, $0, 0x32
    /* 1F0790 002F0790 010043A2 */  sb         $3, 0x1($18)
    /* 1F0794 002F0794 CA010010 */  b          .L002F0EC0
    /* 1F0798 002F0798 00000000 */   nop
    /* 1F079C 002F079C 4801448E */  lw         $4, 0x148($18)
    /* 1F07A0 002F07A0 98510C0C */  jal        func_00314660
    /* 1F07A4 002F07A4 00000000 */   nop
    /* 1F07A8 002F07A8 3C260200 */  dsll32     $4, $2, 24
    /* 1F07AC 002F07AC 3F260400 */  dsra32     $4, $4, 24
    /* 1F07B0 002F07B0 0E000324 */  addiu      $3, $0, 0xE
    /* 1F07B4 002F07B4 C2018314 */  bne        $4, $3, .L002F0EC0
    /* 1F07B8 002F07B8 00000000 */   nop
    /* 1F07BC 002F07BC 34000324 */  addiu      $3, $0, 0x34
    /* 1F07C0 002F07C0 010043A2 */  sb         $3, 0x1($18)
    /* 1F07C4 002F07C4 BE010010 */  b          .L002F0EC0
    /* 1F07C8 002F07C8 00000000 */   nop
    /* 1F07CC 002F07CC 02001024 */  addiu      $16, $0, 0x2
    /* 1F07D0 002F07D0 2D200000 */  daddu      $4, $0, $0
    /* 1F07D4 002F07D4 1C920B0C */  jal        func_002e4870
    /* 1F07D8 002F07D8 00000000 */   nop
    /* 1F07DC 002F07DC 28014482 */  lb         $4, 0x128($18)
    /* 1F07E0 002F07E0 40180400 */  sll        $3, $4, 1
    /* 1F07E4 002F07E4 21186400 */  addu       $3, $3, $4
    /* 1F07E8 002F07E8 80180300 */  sll        $3, $3, 2
    /* 1F07EC 002F07EC 21184300 */  addu       $3, $2, $3
    /* 1F07F0 002F07F0 1E014286 */  lh         $2, 0x11E($18)
    /* 1F07F4 002F07F4 21106200 */  addu       $2, $3, $2
    /* 1F07F8 002F07F8 14004380 */  lb         $3, 0x14($2)
    /* 1F07FC 002F07FC 2D100002 */  daddu      $2, $16, $0
    /* 1F0800 002F0800 02006214 */  bne        $3, $2, .L002F080C
    /* 1F0804 002F0804 00000000 */   nop
    /* 1F0808 002F0808 2D800000 */  daddu      $16, $0, $0
  .L002F080C:
    /* 1F080C 002F080C 61140424 */  addiu      $4, $0, 0x1461
    /* 1F0810 002F0810 CC18040C */  jal        func_00106330
    /* 1F0814 002F0814 00000000 */   nop
    /* 1F0818 002F0818 22004014 */  bnez       $2, .L002F08A4
    /* 1F081C 002F081C 00000000 */   nop
    /* 1F0820 002F0820 2D200002 */  daddu      $4, $16, $0
    /* 1F0824 002F0824 F04A0C0C */  jal        func_00312bc0
    /* 1F0828 002F0828 00000000 */   nop
    /* 1F082C 002F082C 01000324 */  addiu      $3, $0, 0x1
    /* 1F0830 002F0830 15004314 */  bne        $2, $3, .L002F0888
    /* 1F0834 002F0834 00000000 */   nop
    /* 1F0838 002F0838 18DC0E0C */  jal        func_003b7060
    /* 1F083C 002F083C 00000000 */   nop
    /* 1F0840 002F0840 E8030324 */  addiu      $3, $0, 0x3E8
    /* 1F0844 002F0844 1B004300 */  divu       $0, $2, $3
    /* 1F0848 002F0848 10180000 */  mfhi       $3
    /* 1F084C 002F084C F401612C */  sltiu      $1, $3, 0x1F4
    /* 1F0850 002F0850 07002010 */  beqz       $1, .L002F0870
    /* 1F0854 002F0854 00000000 */   nop
    /* 1F0858 002F0858 36000324 */  addiu      $3, $0, 0x36
    /* 1F085C 002F085C 010043A2 */  sb         $3, 0x1($18)
    /* 1F0860 002F0860 01000324 */  addiu      $3, $0, 0x1
    /* 1F0864 002F0864 B20043A2 */  sb         $3, 0xB2($18)
    /* 1F0868 002F0868 95010010 */  b          .L002F0EC0
    /* 1F086C 002F086C 00000000 */   nop
  .L002F0870:
    /* 1F0870 002F0870 37000324 */  addiu      $3, $0, 0x37
    /* 1F0874 002F0874 010043A2 */  sb         $3, 0x1($18)
    /* 1F0878 002F0878 02000324 */  addiu      $3, $0, 0x2
    /* 1F087C 002F087C B20043A2 */  sb         $3, 0xB2($18)
    /* 1F0880 002F0880 8F010010 */  b          .L002F0EC0
    /* 1F0884 002F0884 00000000 */   nop
  .L002F0888:
    /* 1F0888 002F0888 B20040A2 */  sb         $0, 0xB2($18)
    /* 1F088C 002F088C 0D000324 */  addiu      $3, $0, 0xD
    /* 1F0890 002F0890 000043A2 */  sb         $3, 0x0($18)
    /* 1F0894 002F0894 C5000324 */  addiu      $3, $0, 0xC5
    /* 1F0898 002F0898 010043A2 */  sb         $3, 0x1($18)
    /* 1F089C 002F089C 88010010 */  b          .L002F0EC0
    /* 1F08A0 002F08A0 00000000 */   nop
  .L002F08A4:
    /* 1F08A4 002F08A4 36000324 */  addiu      $3, $0, 0x36
    /* 1F08A8 002F08A8 010043A2 */  sb         $3, 0x1($18)
    /* 1F08AC 002F08AC 01000324 */  addiu      $3, $0, 0x1
    /* 1F08B0 002F08B0 B20043A2 */  sb         $3, 0xB2($18)
    /* 1F08B4 002F08B4 82010010 */  b          .L002F0EC0
    /* 1F08B8 002F08B8 00000000 */   nop
    /* 1F08BC 002F08BC 1001A427 */  addiu      $4, $29, 0x110
    /* 1F08C0 002F08C0 2D280000 */  daddu      $5, $0, $0
    /* 1F08C4 002F08C4 1A000624 */  addiu      $6, $0, 0x1A
    /* 1F08C8 002F08C8 72FE100C */  jal        func_0043f9c8
    /* 1F08CC 002F08CC 00000000 */   nop
    /* 1F08D0 002F08D0 2D800000 */  daddu      $16, $0, $0
    /* 1F08D4 002F08D4 0C000010 */  b          .L002F0908
    /* 1F08D8 002F08D8 00000000 */   nop
  .L002F08DC:
    /* 1F08DC 002F08DC 2D200000 */  daddu      $4, $0, $0
    /* 1F08E0 002F08E0 2D280002 */  daddu      $5, $16, $0
    /* 1F08E4 002F08E4 28920B0C */  jal        func_002e48a0
    /* 1F08E8 002F08E8 00000000 */   nop
    /* 1F08EC 002F08EC 02004394 */  lhu        $3, 0x2($2)
    /* 1F08F0 002F08F0 40101100 */  sll        $2, $17, 1
    /* 1F08F4 002F08F4 21105D00 */  addu       $2, $2, $29
    /* 1F08F8 002F08F8 100143A4 */  sh         $3, 0x110($2)
    /* 1F08FC 002F08FC 01000226 */  addiu      $2, $16, 0x1
    /* 1F0900 002F0900 3C840200 */  dsll32     $16, $2, 16
    /* 1F0904 002F0904 3F841000 */  dsra32     $16, $16, 16
  .L002F0908:
    /* 1F0908 002F0908 3C8C1000 */  dsll32     $17, $16, 16
    /* 1F090C 002F090C 3F8C1100 */  dsra32     $17, $17, 16
    /* 1F0910 002F0910 2D200000 */  daddu      $4, $0, $0
    /* 1F0914 002F0914 1C920B0C */  jal        func_002e4870
    /* 1F0918 002F0918 00000000 */   nop
    /* 1F091C 002F091C 0800428C */  lw         $2, 0x8($2)
    /* 1F0920 002F0920 2A102202 */  slt        $2, $17, $2
    /* 1F0924 002F0924 EDFF4014 */  bnez       $2, .L002F08DC
    /* 1F0928 002F0928 00000000 */   nop
    /* 1F092C 002F092C FA024582 */  lb         $5, 0x2FA($18)
    /* 1F0930 002F0930 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0934 002F0934 28920B0C */  jal        func_002e48a0
    /* 1F0938 002F0938 00000000 */   nop
    /* 1F093C 002F093C 02005094 */  lhu        $16, 0x2($2)
    /* 1F0940 002F0940 2D200000 */  daddu      $4, $0, $0
    /* 1F0944 002F0944 1C920B0C */  jal        func_002e4870
    /* 1F0948 002F0948 00000000 */   nop
    /* 1F094C 002F094C 0800428C */  lw         $2, 0x8($2)
    /* 1F0950 002F0950 40100200 */  sll        $2, $2, 1
    /* 1F0954 002F0954 21105D00 */  addu       $2, $2, $29
    /* 1F0958 002F0958 100150A4 */  sh         $16, 0x110($2)
    /* 1F095C 002F095C 01000424 */  addiu      $4, $0, 0x1
    /* 1F0960 002F0960 1C13040C */  jal        func_00104c70
    /* 1F0964 002F0964 00000000 */   nop
    /* 1F0968 002F0968 3C360200 */  dsll32     $6, $2, 24
    /* 1F096C 002F096C 3F360600 */  dsra32     $6, $6, 24
    /* 1F0970 002F0970 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0974 002F0974 1001A527 */  addiu      $5, $29, 0x110
    /* 1F0978 002F0978 B8960B0C */  jal        func_002e5ae0
    /* 1F097C 002F097C 00000000 */   nop
    /* 1F0980 002F0980 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0984 002F0984 1C920B0C */  jal        func_002e4870
    /* 1F0988 002F0988 00000000 */   nop
    /* 1F098C 002F098C 0800508C */  lw         $16, 0x8($2)
    /* 1F0990 002F0990 18DC0E0C */  jal        func_003b7060
    /* 1F0994 002F0994 00000000 */   nop
    /* 1F0998 002F0998 1B005000 */  divu       $0, $2, $16
    /* 1F099C 002F099C 10180000 */  mfhi       $3
    /* 1F09A0 002F09A0 80100300 */  sll        $2, $3, 2
    /* 1F09A4 002F09A4 21104300 */  addu       $2, $2, $3
    /* 1F09A8 002F09A8 40800200 */  sll        $16, $2, 1
    /* 1F09AC 002F09AC 0D000424 */  addiu      $4, $0, 0xD
    /* 1F09B0 002F09B0 1C920B0C */  jal        func_002e4870
    /* 1F09B4 002F09B4 00000000 */   nop
    /* 1F09B8 002F09B8 0800428C */  lw         $2, 0x8($2)
    /* 1F09BC 002F09BC 1B000202 */  divu       $0, $16, $2
    /* 1F09C0 002F09C0 10100000 */  mfhi       $2
    /* 1F09C4 002F09C4 3C9E0200 */  dsll32     $19, $2, 24
    /* 1F09C8 002F09C8 3F9E1300 */  dsra32     $19, $19, 24
    /* 1F09CC 002F09CC 28014282 */  lb         $2, 0x128($18)
    /* 1F09D0 002F09D0 01004224 */  addiu      $2, $2, 0x1
    /* 1F09D4 002F09D4 F90242A2 */  sb         $2, 0x2F9($18)
    /* 1F09D8 002F09D8 1E014286 */  lh         $2, 0x11E($18)
    /* 1F09DC 002F09DC FA0242A2 */  sb         $2, 0x2FA($18)
    /* 1F09E0 002F09E0 2D880000 */  daddu      $17, $0, $0
    /* 1F09E4 002F09E4 3A000010 */  b          .L002F0AD0
    /* 1F09E8 002F09E8 00000000 */   nop
  .L002F09EC:
    /* 1F09EC 002F09EC 3C841100 */  dsll32     $16, $17, 16
    /* 1F09F0 002F09F0 3F841000 */  dsra32     $16, $16, 16
    /* 1F09F4 002F09F4 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F09F8 002F09F8 1C920B0C */  jal        func_002e4870
    /* 1F09FC 002F09FC 00000000 */   nop
    /* 1F0A00 002F0A00 FA024382 */  lb         $3, 0x2FA($18)
    /* 1F0A04 002F0A04 21104300 */  addu       $2, $2, $3
    /* 1F0A08 002F0A08 E4024480 */  lb         $4, 0x2E4($2)
    /* 1F0A0C 002F0A0C 01000324 */  addiu      $3, $0, 0x1
    /* 1F0A10 002F0A10 04100302 */  sllv       $2, $3, $16
    /* 1F0A14 002F0A14 FF004230 */  andi       $2, $2, 0xFF
    /* 1F0A18 002F0A18 24104400 */  and        $2, $2, $4
    /* 1F0A1C 002F0A1C 07100202 */  srav       $2, $2, $16
    /* 1F0A20 002F0A20 28004314 */  bne        $2, $3, .L002F0AC4
    /* 1F0A24 002F0A24 00000000 */   nop
    /* 1F0A28 002F0A28 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0A2C 002F0A2C 2D286002 */  daddu      $5, $19, $0
    /* 1F0A30 002F0A30 28920B0C */  jal        func_002e48a0
    /* 1F0A34 002F0A34 00000000 */   nop
    /* 1F0A38 002F0A38 2D204000 */  daddu      $4, $2, $0
    /* 1F0A3C 002F0A3C AC33040C */  jal        func_0010ceb0
    /* 1F0A40 002F0A40 00000000 */   nop
    /* 1F0A44 002F0A44 08004128 */  slti       $1, $2, 0x8
    /* 1F0A48 002F0A48 1E002010 */  beqz       $1, .L002F0AC4
    /* 1F0A4C 002F0A4C 00000000 */   nop
    /* 1F0A50 002F0A50 28014282 */  lb         $2, 0x128($18)
    /* 1F0A54 002F0A54 01004224 */  addiu      $2, $2, 0x1
    /* 1F0A58 002F0A58 3C260200 */  dsll32     $4, $2, 24
    /* 1F0A5C 002F0A5C 3F260400 */  dsra32     $4, $4, 24
    /* 1F0A60 002F0A60 1E014586 */  lh         $5, 0x11E($18)
    /* 1F0A64 002F0A64 28920B0C */  jal        func_002e48a0
    /* 1F0A68 002F0A68 00000000 */   nop
    /* 1F0A6C 002F0A6C 40181400 */  sll        $3, $20, 1
    /* 1F0A70 002F0A70 21104300 */  addu       $2, $2, $3
    /* 1F0A74 002F0A74 0C005094 */  lhu        $16, 0xC($2)
    /* 1F0A78 002F0A78 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0A7C 002F0A7C 2D286002 */  daddu      $5, $19, $0
    /* 1F0A80 002F0A80 28920B0C */  jal        func_002e48a0
    /* 1F0A84 002F0A84 00000000 */   nop
    /* 1F0A88 002F0A88 2D204000 */  daddu      $4, $2, $0
    /* 1F0A8C 002F0A8C 2D280002 */  daddu      $5, $16, $0
    /* 1F0A90 002F0A90 8433040C */  jal        func_0010ce10
    /* 1F0A94 002F0A94 00000000 */   nop
    /* 1F0A98 002F0A98 FFFF0324 */  addiu      $3, $0, -0x1
    /* 1F0A9C 002F0A9C 09004314 */  bne        $2, $3, .L002F0AC4
    /* 1F0AA0 002F0AA0 00000000 */   nop
    /* 1F0AA4 002F0AA4 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0AA8 002F0AA8 2D286002 */  daddu      $5, $19, $0
    /* 1F0AAC 002F0AAC 28920B0C */  jal        func_002e48a0
    /* 1F0AB0 002F0AB0 00000000 */   nop
    /* 1F0AB4 002F0AB4 2D204000 */  daddu      $4, $2, $0
    /* 1F0AB8 002F0AB8 2D280002 */  daddu      $5, $16, $0
    /* 1F0ABC 002F0ABC 0833040C */  jal        func_0010cc20
    /* 1F0AC0 002F0AC0 00000000 */   nop
  .L002F0AC4:
    /* 1F0AC4 002F0AC4 01002226 */  addiu      $2, $17, 0x1
    /* 1F0AC8 002F0AC8 3C8C0200 */  dsll32     $17, $2, 16
    /* 1F0ACC 002F0ACC 3F8C1100 */  dsra32     $17, $17, 16
  .L002F0AD0:
    /* 1F0AD0 002F0AD0 3CA41100 */  dsll32     $20, $17, 16
    /* 1F0AD4 002F0AD4 3FA41400 */  dsra32     $20, $20, 16
    /* 1F0AD8 002F0AD8 0800822A */  slti       $2, $20, 0x8
    /* 1F0ADC 002F0ADC C3FF4014 */  bnez       $2, .L002F09EC
    /* 1F0AE0 002F0AE0 00000000 */   nop
    /* 1F0AE4 002F0AE4 0D000224 */  addiu      $2, $0, 0xD
    /* 1F0AE8 002F0AE8 F90242A2 */  sb         $2, 0x2F9($18)
    /* 1F0AEC 002F0AEC FA0253A2 */  sb         $19, 0x2FA($18)
    /* 1F0AF0 002F0AF0 3C2E1300 */  dsll32     $5, $19, 24
    /* 1F0AF4 002F0AF4 3F2E0500 */  dsra32     $5, $5, 24
    /* 1F0AF8 002F0AF8 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0AFC 002F0AFC 28920B0C */  jal        func_002e48a0
    /* 1F0B00 002F0B00 00000000 */   nop
    /* 1F0B04 002F0B04 2D804000 */  daddu      $16, $2, $0
    /* 1F0B08 002F0B08 28014282 */  lb         $2, 0x128($18)
    /* 1F0B0C 002F0B0C 01004224 */  addiu      $2, $2, 0x1
    /* 1F0B10 002F0B10 3C260200 */  dsll32     $4, $2, 24
    /* 1F0B14 002F0B14 3F260400 */  dsra32     $4, $4, 24
    /* 1F0B18 002F0B18 1C920B0C */  jal        func_002e4870
    /* 1F0B1C 002F0B1C 00000000 */   nop
    /* 1F0B20 002F0B20 1E014386 */  lh         $3, 0x11E($18)
    /* 1F0B24 002F0B24 21104300 */  addu       $2, $2, $3
    /* 1F0B28 002F0B28 4801448E */  lw         $4, 0x148($18)
    /* 1F0B2C 002F0B2C 2D280002 */  daddu      $5, $16, $0
    /* 1F0B30 002F0B30 E4024680 */  lb         $6, 0x2E4($2)
    /* 1F0B34 002F0B34 BC510C0C */  jal        func_003146f0
    /* 1F0B38 002F0B38 00000000 */   nop
    /* 1F0B3C 002F0B3C 0D000324 */  addiu      $3, $0, 0xD
    /* 1F0B40 002F0B40 000043A2 */  sb         $3, 0x0($18)
    /* 1F0B44 002F0B44 C5000324 */  addiu      $3, $0, 0xC5
    /* 1F0B48 002F0B48 010043A2 */  sb         $3, 0x1($18)
    /* 1F0B4C 002F0B4C DC000010 */  b          .L002F0EC0
    /* 1F0B50 002F0B50 00000000 */   nop
    /* 1F0B54 002F0B54 63001324 */  addiu      $19, $0, 0x63
    /* 1F0B58 002F0B58 F000A427 */  addiu      $4, $29, 0xF0
    /* 1F0B5C 002F0B5C 2D280000 */  daddu      $5, $0, $0
    /* 1F0B60 002F0B60 1A000624 */  addiu      $6, $0, 0x1A
    /* 1F0B64 002F0B64 72FE100C */  jal        func_0043f9c8
    /* 1F0B68 002F0B68 00000000 */   nop
    /* 1F0B6C 002F0B6C 2D800000 */  daddu      $16, $0, $0
    /* 1F0B70 002F0B70 0C000010 */  b          .L002F0BA4
    /* 1F0B74 002F0B74 00000000 */   nop
  .L002F0B78:
    /* 1F0B78 002F0B78 2D200000 */  daddu      $4, $0, $0
    /* 1F0B7C 002F0B7C 2D280002 */  daddu      $5, $16, $0
    /* 1F0B80 002F0B80 28920B0C */  jal        func_002e48a0
    /* 1F0B84 002F0B84 00000000 */   nop
    /* 1F0B88 002F0B88 02004394 */  lhu        $3, 0x2($2)
    /* 1F0B8C 002F0B8C 40101100 */  sll        $2, $17, 1
    /* 1F0B90 002F0B90 21105D00 */  addu       $2, $2, $29
    /* 1F0B94 002F0B94 F00043A4 */  sh         $3, 0xF0($2)
    /* 1F0B98 002F0B98 01000226 */  addiu      $2, $16, 0x1
    /* 1F0B9C 002F0B9C 3C840200 */  dsll32     $16, $2, 16
    /* 1F0BA0 002F0BA0 3F841000 */  dsra32     $16, $16, 16
  .L002F0BA4:
    /* 1F0BA4 002F0BA4 3C8C1000 */  dsll32     $17, $16, 16
    /* 1F0BA8 002F0BA8 3F8C1100 */  dsra32     $17, $17, 16
    /* 1F0BAC 002F0BAC 2D200000 */  daddu      $4, $0, $0
    /* 1F0BB0 002F0BB0 1C920B0C */  jal        func_002e4870
    /* 1F0BB4 002F0BB4 00000000 */   nop
    /* 1F0BB8 002F0BB8 0800428C */  lw         $2, 0x8($2)
    /* 1F0BBC 002F0BBC 2A102202 */  slt        $2, $17, $2
    /* 1F0BC0 002F0BC0 EDFF4014 */  bnez       $2, .L002F0B78
    /* 1F0BC4 002F0BC4 00000000 */   nop
    /* 1F0BC8 002F0BC8 28014282 */  lb         $2, 0x128($18)
    /* 1F0BCC 002F0BCC 01004224 */  addiu      $2, $2, 0x1
    /* 1F0BD0 002F0BD0 3C260200 */  dsll32     $4, $2, 24
    /* 1F0BD4 002F0BD4 3F260400 */  dsra32     $4, $4, 24
    /* 1F0BD8 002F0BD8 1E014586 */  lh         $5, 0x11E($18)
    /* 1F0BDC 002F0BDC 28920B0C */  jal        func_002e48a0
    /* 1F0BE0 002F0BE0 00000000 */   nop
    /* 1F0BE4 002F0BE4 02005094 */  lhu        $16, 0x2($2)
    /* 1F0BE8 002F0BE8 2D200000 */  daddu      $4, $0, $0
    /* 1F0BEC 002F0BEC 1C920B0C */  jal        func_002e4870
    /* 1F0BF0 002F0BF0 00000000 */   nop
    /* 1F0BF4 002F0BF4 0800428C */  lw         $2, 0x8($2)
    /* 1F0BF8 002F0BF8 40100200 */  sll        $2, $2, 1
    /* 1F0BFC 002F0BFC 21105D00 */  addu       $2, $2, $29
    /* 1F0C00 002F0C00 F00050A4 */  sh         $16, 0xF0($2)
    /* 1F0C04 002F0C04 01000424 */  addiu      $4, $0, 0x1
    /* 1F0C08 002F0C08 1C13040C */  jal        func_00104c70
    /* 1F0C0C 002F0C0C 00000000 */   nop
    /* 1F0C10 002F0C10 3C360200 */  dsll32     $6, $2, 24
    /* 1F0C14 002F0C14 3F360600 */  dsra32     $6, $6, 24
    /* 1F0C18 002F0C18 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0C1C 002F0C1C F000A527 */  addiu      $5, $29, 0xF0
    /* 1F0C20 002F0C20 A0980B0C */  jal        func_002e6280
    /* 1F0C24 002F0C24 00000000 */   nop
    /* 1F0C28 002F0C28 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0C2C 002F0C2C 1C920B0C */  jal        func_002e4870
    /* 1F0C30 002F0C30 00000000 */   nop
    /* 1F0C34 002F0C34 0800438C */  lw         $3, 0x8($2)
    /* 1F0C38 002F0C38 0C006014 */  bnez       $3, .L002F0C6C
    /* 1F0C3C 002F0C3C 00000000 */   nop
    /* 1F0C40 002F0C40 28014382 */  lb         $3, 0x128($18)
    /* 1F0C44 002F0C44 01006324 */  addiu      $3, $3, 0x1
    /* 1F0C48 002F0C48 F90243A2 */  sb         $3, 0x2F9($18)
    /* 1F0C4C 002F0C4C 1E014386 */  lh         $3, 0x11E($18)
    /* 1F0C50 002F0C50 FA0243A2 */  sb         $3, 0x2FA($18)
    /* 1F0C54 002F0C54 36000324 */  addiu      $3, $0, 0x36
    /* 1F0C58 002F0C58 010043A2 */  sb         $3, 0x1($18)
    /* 1F0C5C 002F0C5C 01000324 */  addiu      $3, $0, 0x1
    /* 1F0C60 002F0C60 B20043A2 */  sb         $3, 0xB2($18)
    /* 1F0C64 002F0C64 96000010 */  b          .L002F0EC0
    /* 1F0C68 002F0C68 00000000 */   nop
  .L002F0C6C:
    /* 1F0C6C 002F0C6C 0D000224 */  addiu      $2, $0, 0xD
    /* 1F0C70 002F0C70 F90242A2 */  sb         $2, 0x2F9($18)
    /* 1F0C74 002F0C74 2D880000 */  daddu      $17, $0, $0
    /* 1F0C78 002F0C78 2F000010 */  b          .L002F0D38
    /* 1F0C7C 002F0C7C 00000000 */   nop
  .L002F0C80:
    /* 1F0C80 002F0C80 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0C84 002F0C84 2D282002 */  daddu      $5, $17, $0
    /* 1F0C88 002F0C88 28920B0C */  jal        func_002e48a0
    /* 1F0C8C 002F0C8C 00000000 */   nop
    /* 1F0C90 002F0C90 04005090 */  lbu        $16, 0x4($2)
    /* 1F0C94 002F0C94 01000424 */  addiu      $4, $0, 0x1
    /* 1F0C98 002F0C98 1C13040C */  jal        func_00104c70
    /* 1F0C9C 002F0C9C 00000000 */   nop
    /* 1F0CA0 002F0CA0 FF004230 */  andi       $2, $2, 0xFF
    /* 1F0CA4 002F0CA4 2A100202 */  slt        $2, $16, $2
    /* 1F0CA8 002F0CA8 04004014 */  bnez       $2, .L002F0CBC
    /* 1F0CAC 002F0CAC 00000000 */   nop
    /* 1F0CB0 002F0CB0 FA0251A2 */  sb         $17, 0x2FA($18)
    /* 1F0CB4 002F0CB4 29000010 */  b          .L002F0D5C
    /* 1F0CB8 002F0CB8 00000000 */   nop
  .L002F0CBC:
    /* 1F0CBC 002F0CBC 3C841300 */  dsll32     $16, $19, 16
    /* 1F0CC0 002F0CC0 3F841000 */  dsra32     $16, $16, 16
    /* 1F0CC4 002F0CC4 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0CC8 002F0CC8 2D282002 */  daddu      $5, $17, $0
    /* 1F0CCC 002F0CCC 28920B0C */  jal        func_002e48a0
    /* 1F0CD0 002F0CD0 00000000 */   nop
    /* 1F0CD4 002F0CD4 04005490 */  lbu        $20, 0x4($2)
    /* 1F0CD8 002F0CD8 01000424 */  addiu      $4, $0, 0x1
    /* 1F0CDC 002F0CDC 1C13040C */  jal        func_00104c70
    /* 1F0CE0 002F0CE0 00000000 */   nop
    /* 1F0CE4 002F0CE4 FF004230 */  andi       $2, $2, 0xFF
    /* 1F0CE8 002F0CE8 23105400 */  subu       $2, $2, $20
    /* 1F0CEC 002F0CEC 2A085000 */  slt        $1, $2, $16
    /* 1F0CF0 002F0CF0 0E002010 */  beqz       $1, .L002F0D2C
    /* 1F0CF4 002F0CF4 00000000 */   nop
    /* 1F0CF8 002F0CF8 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0CFC 002F0CFC 2D282002 */  daddu      $5, $17, $0
    /* 1F0D00 002F0D00 28920B0C */  jal        func_002e48a0
    /* 1F0D04 002F0D04 00000000 */   nop
    /* 1F0D08 002F0D08 04005090 */  lbu        $16, 0x4($2)
    /* 1F0D0C 002F0D0C 01000424 */  addiu      $4, $0, 0x1
    /* 1F0D10 002F0D10 1C13040C */  jal        func_00104c70
    /* 1F0D14 002F0D14 00000000 */   nop
    /* 1F0D18 002F0D18 FF004230 */  andi       $2, $2, 0xFF
    /* 1F0D1C 002F0D1C 23105000 */  subu       $2, $2, $16
    /* 1F0D20 002F0D20 3C9C0200 */  dsll32     $19, $2, 16
    /* 1F0D24 002F0D24 3F9C1300 */  dsra32     $19, $19, 16
    /* 1F0D28 002F0D28 FA0251A2 */  sb         $17, 0x2FA($18)
  .L002F0D2C:
    /* 1F0D2C 002F0D2C 01002226 */  addiu      $2, $17, 0x1
    /* 1F0D30 002F0D30 3C8C0200 */  dsll32     $17, $2, 16
    /* 1F0D34 002F0D34 3F8C1100 */  dsra32     $17, $17, 16
  .L002F0D38:
    /* 1F0D38 002F0D38 3C841100 */  dsll32     $16, $17, 16
    /* 1F0D3C 002F0D3C 3F841000 */  dsra32     $16, $16, 16
    /* 1F0D40 002F0D40 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0D44 002F0D44 1C920B0C */  jal        func_002e4870
    /* 1F0D48 002F0D48 00000000 */   nop
    /* 1F0D4C 002F0D4C 0800428C */  lw         $2, 0x8($2)
    /* 1F0D50 002F0D50 2A100202 */  slt        $2, $16, $2
    /* 1F0D54 002F0D54 CAFF4014 */  bnez       $2, .L002F0C80
    /* 1F0D58 002F0D58 00000000 */   nop
  .L002F0D5C:
    /* 1F0D5C 002F0D5C FA025382 */  lb         $19, 0x2FA($18)
    /* 1F0D60 002F0D60 28014282 */  lb         $2, 0x128($18)
    /* 1F0D64 002F0D64 01004224 */  addiu      $2, $2, 0x1
    /* 1F0D68 002F0D68 F90242A2 */  sb         $2, 0x2F9($18)
    /* 1F0D6C 002F0D6C 2D880000 */  daddu      $17, $0, $0
    /* 1F0D70 002F0D70 37000010 */  b          .L002F0E50
    /* 1F0D74 002F0D74 00000000 */   nop
  .L002F0D78:
    /* 1F0D78 002F0D78 3C841100 */  dsll32     $16, $17, 16
    /* 1F0D7C 002F0D7C 3F841000 */  dsra32     $16, $16, 16
    /* 1F0D80 002F0D80 F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0D84 002F0D84 1C920B0C */  jal        func_002e4870
    /* 1F0D88 002F0D88 00000000 */   nop
    /* 1F0D8C 002F0D8C 1E014386 */  lh         $3, 0x11E($18)
    /* 1F0D90 002F0D90 21104300 */  addu       $2, $2, $3
    /* 1F0D94 002F0D94 E4024480 */  lb         $4, 0x2E4($2)
    /* 1F0D98 002F0D98 01000324 */  addiu      $3, $0, 0x1
    /* 1F0D9C 002F0D9C 04100302 */  sllv       $2, $3, $16
    /* 1F0DA0 002F0DA0 FF004230 */  andi       $2, $2, 0xFF
    /* 1F0DA4 002F0DA4 24104400 */  and        $2, $2, $4
    /* 1F0DA8 002F0DA8 07100202 */  srav       $2, $2, $16
    /* 1F0DAC 002F0DAC 25004314 */  bne        $2, $3, .L002F0E44
    /* 1F0DB0 002F0DB0 00000000 */   nop
    /* 1F0DB4 002F0DB4 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0DB8 002F0DB8 2D286002 */  daddu      $5, $19, $0
    /* 1F0DBC 002F0DBC 28920B0C */  jal        func_002e48a0
    /* 1F0DC0 002F0DC0 00000000 */   nop
    /* 1F0DC4 002F0DC4 2D204000 */  daddu      $4, $2, $0
    /* 1F0DC8 002F0DC8 AC33040C */  jal        func_0010ceb0
    /* 1F0DCC 002F0DCC 00000000 */   nop
    /* 1F0DD0 002F0DD0 08004128 */  slti       $1, $2, 0x8
    /* 1F0DD4 002F0DD4 1B002010 */  beqz       $1, .L002F0E44
    /* 1F0DD8 002F0DD8 00000000 */   nop
    /* 1F0DDC 002F0DDC F9024482 */  lb         $4, 0x2F9($18)
    /* 1F0DE0 002F0DE0 1E014586 */  lh         $5, 0x11E($18)
    /* 1F0DE4 002F0DE4 28920B0C */  jal        func_002e48a0
    /* 1F0DE8 002F0DE8 00000000 */   nop
    /* 1F0DEC 002F0DEC 40181400 */  sll        $3, $20, 1
    /* 1F0DF0 002F0DF0 21104300 */  addu       $2, $2, $3
    /* 1F0DF4 002F0DF4 0C005094 */  lhu        $16, 0xC($2)
    /* 1F0DF8 002F0DF8 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0DFC 002F0DFC 2D286002 */  daddu      $5, $19, $0
    /* 1F0E00 002F0E00 28920B0C */  jal        func_002e48a0
    /* 1F0E04 002F0E04 00000000 */   nop
    /* 1F0E08 002F0E08 2D204000 */  daddu      $4, $2, $0
    /* 1F0E0C 002F0E0C 2D280002 */  daddu      $5, $16, $0
    /* 1F0E10 002F0E10 8433040C */  jal        func_0010ce10
    /* 1F0E14 002F0E14 00000000 */   nop
    /* 1F0E18 002F0E18 FFFF0324 */  addiu      $3, $0, -0x1
    /* 1F0E1C 002F0E1C 09004314 */  bne        $2, $3, .L002F0E44
    /* 1F0E20 002F0E20 00000000 */   nop
    /* 1F0E24 002F0E24 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0E28 002F0E28 2D286002 */  daddu      $5, $19, $0
    /* 1F0E2C 002F0E2C 28920B0C */  jal        func_002e48a0
    /* 1F0E30 002F0E30 00000000 */   nop
    /* 1F0E34 002F0E34 2D204000 */  daddu      $4, $2, $0
    /* 1F0E38 002F0E38 2D280002 */  daddu      $5, $16, $0
    /* 1F0E3C 002F0E3C 0833040C */  jal        func_0010cc20
    /* 1F0E40 002F0E40 00000000 */   nop
  .L002F0E44:
    /* 1F0E44 002F0E44 01002226 */  addiu      $2, $17, 0x1
    /* 1F0E48 002F0E48 3C8C0200 */  dsll32     $17, $2, 16
    /* 1F0E4C 002F0E4C 3F8C1100 */  dsra32     $17, $17, 16
  .L002F0E50:
    /* 1F0E50 002F0E50 3CA41100 */  dsll32     $20, $17, 16
    /* 1F0E54 002F0E54 3FA41400 */  dsra32     $20, $20, 16
    /* 1F0E58 002F0E58 0800822A */  slti       $2, $20, 0x8
    /* 1F0E5C 002F0E5C C6FF4014 */  bnez       $2, .L002F0D78
    /* 1F0E60 002F0E60 00000000 */   nop
    /* 1F0E64 002F0E64 0D000424 */  addiu      $4, $0, 0xD
    /* 1F0E68 002F0E68 F90244A2 */  sb         $4, 0x2F9($18)
    /* 1F0E6C 002F0E6C FA024582 */  lb         $5, 0x2FA($18)
    /* 1F0E70 002F0E70 28920B0C */  jal        func_002e48a0
    /* 1F0E74 002F0E74 00000000 */   nop
    /* 1F0E78 002F0E78 2D804000 */  daddu      $16, $2, $0
    /* 1F0E7C 002F0E7C 28014282 */  lb         $2, 0x128($18)
    /* 1F0E80 002F0E80 01004224 */  addiu      $2, $2, 0x1
    /* 1F0E84 002F0E84 3C260200 */  dsll32     $4, $2, 24
    /* 1F0E88 002F0E88 3F260400 */  dsra32     $4, $4, 24
    /* 1F0E8C 002F0E8C 1C920B0C */  jal        func_002e4870
    /* 1F0E90 002F0E90 00000000 */   nop
    /* 1F0E94 002F0E94 1E014386 */  lh         $3, 0x11E($18)
    /* 1F0E98 002F0E98 21104300 */  addu       $2, $2, $3
    /* 1F0E9C 002F0E9C 4801448E */  lw         $4, 0x148($18)
    /* 1F0EA0 002F0EA0 2D280002 */  daddu      $5, $16, $0
    /* 1F0EA4 002F0EA4 E4024680 */  lb         $6, 0x2E4($2)
    /* 1F0EA8 002F0EA8 BC510C0C */  jal        func_003146f0
    /* 1F0EAC 002F0EAC 00000000 */   nop
    /* 1F0EB0 002F0EB0 0D000324 */  addiu      $3, $0, 0xD
    /* 1F0EB4 002F0EB4 000043A2 */  sb         $3, 0x0($18)
    /* 1F0EB8 002F0EB8 C5000324 */  addiu      $3, $0, 0xC5
    /* 1F0EBC 002F0EBC 010043A2 */  sb         $3, 0x1($18)
  .L002F0EC0:
    /* 1F0EC0 002F0EC0 C000BFDF */  ld         $31, 0xC0($29)
    /* 1F0EC4 002F0EC4 B000BE7B */  lq         $30, 0xB0($29)
    /* 1F0EC8 002F0EC8 A000B77B */  lq         $23, 0xA0($29)
    /* 1F0ECC 002F0ECC 9000B67B */  lq         $22, 0x90($29)
    /* 1F0ED0 002F0ED0 8000B57B */  lq         $21, 0x80($29)
    /* 1F0ED4 002F0ED4 7000B47B */  lq         $20, 0x70($29)
    /* 1F0ED8 002F0ED8 6000B37B */  lq         $19, 0x60($29)
    /* 1F0EDC 002F0EDC 5000B27B */  lq         $18, 0x50($29)
    /* 1F0EE0 002F0EE0 4000B17B */  lq         $17, 0x40($29)
    /* 1F0EE4 002F0EE4 3000B07B */  lq         $16, 0x30($29)
    /* 1F0EE8 002F0EE8 2000B4C7 */  lwc1       $f20, 0x20($29)
    /* 1F0EEC 002F0EEC 6002BD27 */  addiu      $29, $29, 0x260
    /* 1F0EF0 002F0EF0 0800E003 */  jr         $31
    /* 1F0EF4 002F0EF4 00000000 */   nop
    /* 1F0EF8 002F0EF8 00000000 */  nop
    /* 1F0EFC 002F0EFC 00000000 */  nop
.size func_002ed430, 0x3ad0
