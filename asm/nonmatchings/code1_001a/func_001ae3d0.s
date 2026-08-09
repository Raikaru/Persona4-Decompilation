.section .text
.set noat
.set noreorder
glabel func_001ae3d0
    /* AE3D0 001AE3D0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* AE3D4 001AE3D4 3000BFFF */  sd         $31, 0x30($29)
    /* AE3D8 001AE3D8 2000B27F */  sq         $18, 0x20($29)
    /* AE3DC 001AE3DC 1000B17F */  sq         $17, 0x10($29)
    /* AE3E0 001AE3E0 0000B07F */  sq         $16, 0x0($29)
    /* AE3E4 001AE3E4 2D908000 */  daddu      $18, $4, $0
    /* AE3E8 001AE3E8 ACB3828F */  lw         $2, -0x4C54($28)
    /* AE3EC 001AE3EC 7401508C */  lw         $16, 0x174($2)
    /* AE3F0 001AE3F0 11000010 */  b          .L001AE438
    /* AE3F4 001AE3F4 00000000 */   nop
  .L001AE3F8:
    /* AE3F8 001AE3F8 2D200002 */  daddu      $4, $16, $0
    /* AE3FC 001AE3FC 7C81060C */  jal        func_001a05f0
    /* AE400 001AE400 00000000 */   nop
    /* AE404 001AE404 0B004010 */  beqz       $2, .L001AE434
    /* AE408 001AE408 00000000 */   nop
    /* AE40C 001AE40C 3000028E */  lw         $2, 0x30($16)
    /* AE410 001AE410 0C0A448C */  lw         $4, 0xA0C($2)
    /* AE414 001AE414 A86D060C */  jal        func_0019b6a0
    /* AE418 001AE418 00000000 */   nop
    /* AE41C 001AE41C 2D204000 */  daddu      $4, $2, $0
    /* AE420 001AE420 000003DE */  ld         $3, 0x0($16)
    /* AE424 001AE424 600043FC */  sd         $3, 0x60($2)
    /* AE428 001AE428 01000524 */  addiu      $5, $0, 0x1
    /* AE42C 001AE42C 6451060C */  jal        func_00194590
    /* AE430 001AE430 00000000 */   nop
  .L001AE434:
    /* AE434 001AE434 5004108E */  lw         $16, 0x450($16)
  .L001AE438:
    /* AE438 001AE438 EFFF0016 */  bnez       $16, .L001AE3F8
    /* AE43C 001AE43C 00000000 */   nop
    /* AE440 001AE440 2D880000 */  daddu      $17, $0, $0
    /* AE444 001AE444 3000428E */  lw         $2, 0x30($18)
    /* AE448 001AE448 A2004290 */  lbu        $2, 0xA2($2)
    /* AE44C 001AE44C 04004014 */  bnez       $2, .L001AE460
    /* AE450 001AE450 00000000 */   nop
    /* AE454 001AE454 2D304002 */  daddu      $6, $18, $0
    /* AE458 001AE458 02000010 */  b          .L001AE464
    /* AE45C 001AE45C 00000000 */   nop
  .L001AE460:
    /* AE460 001AE460 3800468E */  lw         $6, 0x38($18)
  .L001AE464:
    /* AE464 001AE464 1500C010 */  beqz       $6, .L001AE4BC
    /* AE468 001AE468 00000000 */   nop
    /* AE46C 001AE46C 2D280000 */  daddu      $5, $0, $0
    /* AE470 001AE470 ACB3848F */  lw         $4, -0x4C54($28)
    /* AE474 001AE474 580C8394 */  lhu        $3, 0xC58($4)
    /* AE478 001AE478 0C000010 */  b          .L001AE4AC
    /* AE47C 001AE47C 00000000 */   nop
  .L001AE480:
    /* AE480 001AE480 FFFFA230 */  andi       $2, $5, 0xFFFF
    /* AE484 001AE484 80100200 */  sll        $2, $2, 2
    /* AE488 001AE488 21108200 */  addu       $2, $4, $2
    /* AE48C 001AE48C 480C428C */  lw         $2, 0xC48($2)
    /* AE490 001AE490 04004614 */  bne        $2, $6, .L001AE4A4
    /* AE494 001AE494 00000000 */   nop
    /* AE498 001AE498 2D88C000 */  daddu      $17, $6, $0
    /* AE49C 001AE49C 07000010 */  b          .L001AE4BC
    /* AE4A0 001AE4A0 00000000 */   nop
  .L001AE4A4:
    /* AE4A4 001AE4A4 0100A224 */  addiu      $2, $5, 0x1
    /* AE4A8 001AE4A8 FFFF4530 */  andi       $5, $2, 0xFFFF
  .L001AE4AC:
    /* AE4AC 001AE4AC FFFFA230 */  andi       $2, $5, 0xFFFF
    /* AE4B0 001AE4B0 2A104300 */  slt        $2, $2, $3
    /* AE4B4 001AE4B4 F2FF4014 */  bnez       $2, .L001AE480
    /* AE4B8 001AE4B8 00000000 */   nop
  .L001AE4BC:
    /* AE4BC 001AE4BC 0A002016 */  bnez       $17, .L001AE4E8
    /* AE4C0 001AE4C0 00000000 */   nop
    /* AE4C4 001AE4C4 ACB3828F */  lw         $2, -0x4C54($28)
    /* AE4C8 001AE4C8 580C4494 */  lhu        $4, 0xC58($2)
    /* AE4CC 001AE4CC 5CC7080C */  jal        func_00231d70
    /* AE4D0 001AE4D0 00000000 */   nop
    /* AE4D4 001AE4D4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* AE4D8 001AE4D8 ACB3838F */  lw         $3, -0x4C54($28)
    /* AE4DC 001AE4DC 80100200 */  sll        $2, $2, 2
    /* AE4E0 001AE4E0 21104300 */  addu       $2, $2, $3
    /* AE4E4 001AE4E4 480C518C */  lw         $17, 0xC48($2)
  .L001AE4E8:
    /* AE4E8 001AE4E8 01000224 */  addiu      $2, $0, 0x1
    /* AE4EC 001AE4EC 4000A2A7 */  sh         $2, 0x40($29)
    /* AE4F0 001AE4F0 3000228E */  lw         $2, 0x30($17)
    /* AE4F4 001AE4F4 A4004294 */  lhu        $2, 0xA4($2)
    /* AE4F8 001AE4F8 4200A2A7 */  sh         $2, 0x42($29)
    /* AE4FC 001AE4FC 4000A427 */  addiu      $4, $29, 0x40
    /* AE500 001AE500 C8E9070C */  jal        func_001fa720
    /* AE504 001AE504 00000000 */   nop
    /* AE508 001AE508 2D204000 */  daddu      $4, $2, $0
    /* AE50C 001AE50C 000043DE */  ld         $3, 0x0($18)
    /* AE510 001AE510 600043FC */  sd         $3, 0x60($2)
    /* AE514 001AE514 01000524 */  addiu      $5, $0, 0x1
    /* AE518 001AE518 6451060C */  jal        func_00194590
    /* AE51C 001AE51C 00000000 */   nop
    /* AE520 001AE520 3000428E */  lw         $2, 0x30($18)
    /* AE524 001AE524 A2004290 */  lbu        $2, 0xA2($2)
    /* AE528 001AE528 04004010 */  beqz       $2, .L001AE53C
    /* AE52C 001AE52C 00000000 */   nop
    /* AE530 001AE530 2D100000 */  daddu      $2, $0, $0
    /* AE534 001AE534 1C000010 */  b          .L001AE5A8
    /* AE538 001AE538 00000000 */   nop
  .L001AE53C:
    /* AE53C 001AE53C ACB3828F */  lw         $2, -0x4C54($28)
    /* AE540 001AE540 700A4384 */  lh         $3, 0xA70($2)
    /* AE544 001AE544 FFFF0224 */  addiu      $2, $0, -0x1
    /* AE548 001AE548 16006210 */  beq        $3, $2, .L001AE5A4
    /* AE54C 001AE54C 00000000 */   nop
    /* AE550 001AE550 02000424 */  addiu      $4, $0, 0x2
    /* AE554 001AE554 0800053C */  lui        $5, (0x80000 >> 16)
    /* AE558 001AE558 C8BD070C */  jal        func_001ef720
    /* AE55C 001AE55C 00000000 */   nop
    /* AE560 001AE560 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* AE564 001AE564 ACB3838F */  lw         $3, -0x4C54($28)
    /* AE568 001AE568 720A6284 */  lh         $2, 0xA72($3)
    /* AE56C 001AE56C 43100200 */  sra        $2, $2, 1
    /* AE570 001AE570 2B104400 */  sltu       $2, $2, $4
    /* AE574 001AE574 0B004014 */  bnez       $2, .L001AE5A4
    /* AE578 001AE578 00000000 */   nop
    /* AE57C 001AE57C 700A7084 */  lh         $16, 0xA70($3)
    /* AE580 001AE580 6845070C */  jal        func_001d15a0
    /* AE584 001AE584 00000000 */   nop
    /* AE588 001AE588 3C140200 */  dsll32     $2, $2, 16
    /* AE58C 001AE58C 3F140200 */  dsra32     $2, $2, 16
    /* AE590 001AE590 04000212 */  beq        $16, $2, .L001AE5A4
    /* AE594 001AE594 00000000 */   nop
    /* AE598 001AE598 01000224 */  addiu      $2, $0, 0x1
    /* AE59C 001AE59C 02000010 */  b          .L001AE5A8
    /* AE5A0 001AE5A0 00000000 */   nop
  .L001AE5A4:
    /* AE5A4 001AE5A4 2D100000 */  daddu      $2, $0, $0
  .L001AE5A8:
    /* AE5A8 001AE5A8 0A004010 */  beqz       $2, .L001AE5D4
    /* AE5AC 001AE5AC 00000000 */   nop
    /* AE5B0 001AE5B0 01000424 */  addiu      $4, $0, 0x1
    /* AE5B4 001AE5B4 404E070C */  jal        func_001d3900
    /* AE5B8 001AE5B8 00000000 */   nop
    /* AE5BC 001AE5BC 2D204000 */  daddu      $4, $2, $0
    /* AE5C0 001AE5C0 000043DE */  ld         $3, 0x0($18)
    /* AE5C4 001AE5C4 600043FC */  sd         $3, 0x60($2)
    /* AE5C8 001AE5C8 2D280000 */  daddu      $5, $0, $0
    /* AE5CC 001AE5CC 6451060C */  jal        func_00194590
    /* AE5D0 001AE5D0 00000000 */   nop
  .L001AE5D4:
    /* AE5D4 001AE5D4 ACB3828F */  lw         $2, -0x4C54($28)
    /* AE5D8 001AE5D8 7001438C */  lw         $3, 0x170($2)
    /* AE5DC 001AE5DC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AE5E0 001AE5E0 00608244 */  mtc1       $2, $f12
    /* AE5E4 001AE5E4 3000648C */  lw         $4, 0x30($3)
    /* AE5E8 001AE5E8 2D280000 */  daddu      $5, $0, $0
    /* AE5EC 001AE5EC 2D300000 */  daddu      $6, $0, $0
    /* AE5F0 001AE5F0 01000724 */  addiu      $7, $0, 0x1
    /* AE5F4 001AE5F4 B867060C */  jal        func_00199ee0
    /* AE5F8 001AE5F8 00000000 */   nop
    /* AE5FC 001AE5FC 2D204000 */  daddu      $4, $2, $0
    /* AE600 001AE600 000043DE */  ld         $3, 0x0($18)
    /* AE604 001AE604 600043FC */  sd         $3, 0x60($2)
    /* AE608 001AE608 2D280000 */  daddu      $5, $0, $0
    /* AE60C 001AE60C 6451060C */  jal        func_00194590
    /* AE610 001AE610 00000000 */   nop
    /* AE614 001AE614 2D800000 */  daddu      $16, $0, $0
    /* AE618 001AE618 15000010 */  b          .L001AE670
    /* AE61C 001AE61C 00000000 */   nop
  .L001AE620:
    /* AE620 001AE620 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* AE624 001AE624 80100200 */  sll        $2, $2, 2
    /* AE628 001AE628 21108200 */  addu       $2, $4, $2
    /* AE62C 001AE62C 480C438C */  lw         $3, 0xC48($2)
    /* AE630 001AE630 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AE634 001AE634 00608244 */  mtc1       $2, $f12
    /* AE638 001AE638 3000648C */  lw         $4, 0x30($3)
    /* AE63C 001AE63C 2D280000 */  daddu      $5, $0, $0
    /* AE640 001AE640 2D300000 */  daddu      $6, $0, $0
    /* AE644 001AE644 01000724 */  addiu      $7, $0, 0x1
    /* AE648 001AE648 B867060C */  jal        func_00199ee0
    /* AE64C 001AE64C 00000000 */   nop
    /* AE650 001AE650 2D204000 */  daddu      $4, $2, $0
    /* AE654 001AE654 000043DE */  ld         $3, 0x0($18)
    /* AE658 001AE658 600043FC */  sd         $3, 0x60($2)
    /* AE65C 001AE65C 2D280000 */  daddu      $5, $0, $0
    /* AE660 001AE660 6451060C */  jal        func_00194590
    /* AE664 001AE664 00000000 */   nop
    /* AE668 001AE668 01000226 */  addiu      $2, $16, 0x1
    /* AE66C 001AE66C FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001AE670:
    /* AE670 001AE670 ACB3848F */  lw         $4, -0x4C54($28)
    /* AE674 001AE674 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* AE678 001AE678 580C8294 */  lhu        $2, 0xC58($4)
    /* AE67C 001AE67C 2A106200 */  slt        $2, $3, $2
    /* AE680 001AE680 E7FF4014 */  bnez       $2, .L001AE620
    /* AE684 001AE684 00000000 */   nop
    /* AE688 001AE688 03000424 */  addiu      $4, $0, 0x3
    /* AE68C 001AE68C FF0F0524 */  addiu      $5, $0, 0xFFF
    /* AE690 001AE690 C04D070C */  jal        func_001d3700
    /* AE694 001AE694 00000000 */   nop
    /* AE698 001AE698 2D204000 */  daddu      $4, $2, $0
    /* AE69C 001AE69C 000043DE */  ld         $3, 0x0($18)
    /* AE6A0 001AE6A0 600043FC */  sd         $3, 0x60($2)
    /* AE6A4 001AE6A4 2D280000 */  daddu      $5, $0, $0
    /* AE6A8 001AE6A8 6451060C */  jal        func_00194590
    /* AE6AC 001AE6AC 00000000 */   nop
    /* AE6B0 001AE6B0 2D200000 */  daddu      $4, $0, $0
    /* AE6B4 001AE6B4 03000524 */  addiu      $5, $0, 0x3
    /* AE6B8 001AE6B8 7C7A060C */  jal        func_0019e9f0
    /* AE6BC 001AE6BC 00000000 */   nop
    /* AE6C0 001AE6C0 2D204000 */  daddu      $4, $2, $0
    /* AE6C4 001AE6C4 000043DE */  ld         $3, 0x0($18)
    /* AE6C8 001AE6C8 600043FC */  sd         $3, 0x60($2)
    /* AE6CC 001AE6CC 01000524 */  addiu      $5, $0, 0x1
    /* AE6D0 001AE6D0 6451060C */  jal        func_00194590
    /* AE6D4 001AE6D4 00000000 */   nop
    /* AE6D8 001AE6D8 2D200000 */  daddu      $4, $0, $0
    /* AE6DC 001AE6DC 03000524 */  addiu      $5, $0, 0x3
    /* AE6E0 001AE6E0 F079060C */  jal        func_0019e7c0
    /* AE6E4 001AE6E4 00000000 */   nop
    /* AE6E8 001AE6E8 2D204000 */  daddu      $4, $2, $0
    /* AE6EC 001AE6EC 000043DE */  ld         $3, 0x0($18)
    /* AE6F0 001AE6F0 600043FC */  sd         $3, 0x60($2)
    /* AE6F4 001AE6F4 01000524 */  addiu      $5, $0, 0x1
    /* AE6F8 001AE6F8 6451060C */  jal        func_00194590
    /* AE6FC 001AE6FC 00000000 */   nop
    /* AE700 001AE700 2D204002 */  daddu      $4, $18, $0
    /* AE704 001AE704 404F070C */  jal        func_001d3d00
    /* AE708 001AE708 00000000 */   nop
    /* AE70C 001AE70C 2D204000 */  daddu      $4, $2, $0
    /* AE710 001AE710 000043DE */  ld         $3, 0x0($18)
    /* AE714 001AE714 600043FC */  sd         $3, 0x60($2)
    /* AE718 001AE718 2D280000 */  daddu      $5, $0, $0
    /* AE71C 001AE71C 6451060C */  jal        func_00194590
    /* AE720 001AE720 00000000 */   nop
    /* AE724 001AE724 2D200000 */  daddu      $4, $0, $0
    /* AE728 001AE728 24E8060C */  jal        func_001ba090
    /* AE72C 001AE72C 00000000 */   nop
    /* AE730 001AE730 2D204000 */  daddu      $4, $2, $0
    /* AE734 001AE734 000043DE */  ld         $3, 0x0($18)
    /* AE738 001AE738 600043FC */  sd         $3, 0x60($2)
    /* AE73C 001AE73C 2D280000 */  daddu      $5, $0, $0
    /* AE740 001AE740 6451060C */  jal        func_00194590
    /* AE744 001AE744 00000000 */   nop
    /* AE748 001AE748 2D204002 */  daddu      $4, $18, $0
    /* AE74C 001AE74C 07000524 */  addiu      $5, $0, 0x7
    /* AE750 001AE750 48F2060C */  jal        func_001bc920
    /* AE754 001AE754 00000000 */   nop
    /* AE758 001AE758 2D204000 */  daddu      $4, $2, $0
    /* AE75C 001AE75C 000043DE */  ld         $3, 0x0($18)
    /* AE760 001AE760 600043FC */  sd         $3, 0x60($2)
    /* AE764 001AE764 2D280000 */  daddu      $5, $0, $0
    /* AE768 001AE768 6451060C */  jal        func_00194590
    /* AE76C 001AE76C 00000000 */   nop
    /* AE770 001AE770 ACB3848F */  lw         $4, -0x4C54($28)
    /* AE774 001AE774 0C00838C */  lw         $3, 0xC($4)
    /* AE778 001AE778 BFFF023C */  lui        $2, (0xFFBFFFFF >> 16)
    /* AE77C 001AE77C FFFF4234 */  ori        $2, $2, (0xFFBFFFFF & 0xFFFF)
    /* AE780 001AE780 24106200 */  and        $2, $3, $2
    /* AE784 001AE784 0C0082AC */  sw         $2, 0xC($4)
    /* AE788 001AE788 ACB3828F */  lw         $2, -0x4C54($28)
    /* AE78C 001AE78C 180040A4 */  sh         $0, 0x18($2)
    /* AE790 001AE790 18AE070C */  jal        func_001eb860
    /* AE794 001AE794 00000000 */   nop
    /* AE798 001AE798 01000324 */  addiu      $3, $0, 0x1
    /* AE79C 001AE79C 0B004314 */  bne        $2, $3, .L001AE7CC
    /* AE7A0 001AE7A0 00000000 */   nop
    /* AE7A4 001AE7A4 ACB3848F */  lw         $4, -0x4C54($28)
    /* AE7A8 001AE7A8 0C00838C */  lw         $3, 0xC($4)
    /* AE7AC 001AE7AC FFDF0224 */  addiu      $2, $0, -0x2001
    /* AE7B0 001AE7B0 24106200 */  and        $2, $3, $2
    /* AE7B4 001AE7B4 0C0082AC */  sw         $2, 0xC($4)
    /* AE7B8 001AE7B8 ACB3828F */  lw         $2, -0x4C54($28)
    /* AE7BC 001AE7BC D40D448C */  lw         $4, 0xDD4($2)
    /* AE7C0 001AE7C0 2D280000 */  daddu      $5, $0, $0
    /* AE7C4 001AE7C4 9048080C */  jal        func_00212240
    /* AE7C8 001AE7C8 00000000 */   nop
  .L001AE7CC:
    /* AE7CC 001AE7CC 1C0451AE */  sw         $17, 0x41C($18)
    /* AE7D0 001AE7D0 200440AE */  sw         $0, 0x420($18)
    /* AE7D4 001AE7D4 240440AE */  sw         $0, 0x424($18)
    /* AE7D8 001AE7D8 280440AE */  sw         $0, 0x428($18)
    /* AE7DC 001AE7DC 0C000324 */  addiu      $3, $0, 0xC
    /* AE7E0 001AE7E0 2C0443A6 */  sh         $3, 0x42C($18)
    /* AE7E4 001AE7E4 3000BFDF */  ld         $31, 0x30($29)
    /* AE7E8 001AE7E8 2000B27B */  lq         $18, 0x20($29)
    /* AE7EC 001AE7EC 1000B17B */  lq         $17, 0x10($29)
    /* AE7F0 001AE7F0 0000B07B */  lq         $16, 0x0($29)
    /* AE7F4 001AE7F4 5000BD27 */  addiu      $29, $29, 0x50
    /* AE7F8 001AE7F8 0800E003 */  jr         $31
    /* AE7FC 001AE7FC 00000000 */   nop
.size func_001ae3d0, 0x430
