.section .text
.set noat
.set noreorder
glabel func_001eb4a0
    /* EB4A0 001EB4A0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* EB4A4 001EB4A4 5000BFFF */  sd         $31, 0x50($29)
    /* EB4A8 001EB4A8 4000B47F */  sq         $20, 0x40($29)
    /* EB4AC 001EB4AC 3000B37F */  sq         $19, 0x30($29)
    /* EB4B0 001EB4B0 2000B27F */  sq         $18, 0x20($29)
    /* EB4B4 001EB4B4 1000B17F */  sq         $17, 0x10($29)
    /* EB4B8 001EB4B8 0000B07F */  sq         $16, 0x0($29)
    /* EB4BC 001EB4BC 2D888000 */  daddu      $17, $4, $0
    /* EB4C0 001EB4C0 2D80A000 */  daddu      $16, $5, $0
    /* EB4C4 001EB4C4 2DA0C000 */  daddu      $20, $6, $0
    /* EB4C8 001EB4C8 3200A0A4 */  sh         $0, 0x32($5)
    /* EB4CC 001EB4CC 3600A0A4 */  sh         $0, 0x36($5)
    /* EB4D0 001EB4D0 3800A0A4 */  sh         $0, 0x38($5)
    /* EB4D4 001EB4D4 3400A0A4 */  sh         $0, 0x34($5)
    /* EB4D8 001EB4D8 5000A0AC */  sw         $0, 0x50($5)
    /* EB4DC 001EB4DC 5400A0AC */  sw         $0, 0x54($5)
    /* EB4E0 001EB4E0 5800A0AC */  sw         $0, 0x58($5)
    /* EB4E4 001EB4E4 3E000426 */  addiu      $4, $16, 0x3E
    /* EB4E8 001EB4E8 2D280000 */  daddu      $5, $0, $0
    /* EB4EC 001EB4EC 06000624 */  addiu      $6, $0, 0x6
    /* EB4F0 001EB4F0 72FE100C */  jal        func_0043f9c8
    /* EB4F4 001EB4F4 00000000 */   nop
    /* EB4F8 001EB4F8 2D300000 */  daddu      $6, $0, $0
    /* EB4FC 001EB4FC 2D980000 */  daddu      $19, $0, $0
    /* EB500 001EB500 3C1B1400 */  dsll32     $3, $20, 12
    /* EB504 001EB504 3E1B0300 */  dsrl32     $3, $3, 12
    /* EB508 001EB508 00010224 */  addiu      $2, $0, 0x100
    /* EB50C 001EB50C 5D006210 */  beq        $3, $2, .L001EB684
    /* EB510 001EB510 00000000 */   nop
    /* EB514 001EB514 02000224 */  addiu      $2, $0, 0x2
    /* EB518 001EB518 57006210 */  beq        $3, $2, .L001EB678
    /* EB51C 001EB51C 00000000 */   nop
    /* EB520 001EB520 04000224 */  addiu      $2, $0, 0x4
    /* EB524 001EB524 3D006210 */  beq        $3, $2, .L001EB61C
    /* EB528 001EB528 00000000 */   nop
    /* EB52C 001EB52C 10000224 */  addiu      $2, $0, 0x10
    /* EB530 001EB530 03006210 */  beq        $3, $2, .L001EB540
    /* EB534 001EB534 00000000 */   nop
    /* EB538 001EB538 55000010 */  b          .L001EB690
    /* EB53C 001EB53C 00000000 */   nop
  .L001EB540:
    /* EB540 001EB540 3000248E */  lw         $4, 0x30($17)
    /* EB544 001EB544 A2008390 */  lbu        $3, 0xA2($4)
    /* EB548 001EB548 01000224 */  addiu      $2, $0, 0x1
    /* EB54C 001EB54C 15006214 */  bne        $3, $2, .L001EB5A4
    /* EB550 001EB550 00000000 */   nop
    /* EB554 001EB554 A4008394 */  lhu        $3, 0xA4($4)
    /* EB558 001EB558 00110300 */  sll        $2, $3, 4
    /* EB55C 001EB55C 23104300 */  subu       $2, $2, $3
    /* EB560 001EB560 80180200 */  sll        $3, $2, 2
    /* EB564 001EB564 C4B3828F */  lw         $2, -0x4C3C($28)
    /* EB568 001EB568 21104300 */  addu       $2, $2, $3
    /* EB56C 001EB56C 00004294 */  lhu        $2, 0x0($2)
    /* EB570 001EB570 00204230 */  andi       $2, $2, 0x2000
    /* EB574 001EB574 08004014 */  bnez       $2, .L001EB598
    /* EB578 001EB578 00000000 */   nop
    /* EB57C 001EB57C 1A002296 */  lhu        $2, 0x1A($17)
    /* EB580 001EB580 00404230 */  andi       $2, $2, 0x4000
    /* EB584 001EB584 04004014 */  bnez       $2, .L001EB598
    /* EB588 001EB588 00000000 */   nop
    /* EB58C 001EB58C 2D900000 */  daddu      $18, $0, $0
    /* EB590 001EB590 0C000010 */  b          .L001EB5C4
    /* EB594 001EB594 00000000 */   nop
  .L001EB598:
    /* EB598 001EB598 02001264 */  daddiu     $18, $0, 0x2
    /* EB59C 001EB59C 09000010 */  b          .L001EB5C4
    /* EB5A0 001EB5A0 00000000 */   nop
  .L001EB5A4:
    /* EB5A4 001EB5A4 B417040C */  jal        func_00105ed0
    /* EB5A8 001EB5A8 00000000 */   nop
    /* EB5AC 001EB5AC 04004010 */  beqz       $2, .L001EB5C0
    /* EB5B0 001EB5B0 00000000 */   nop
    /* EB5B4 001EB5B4 2D900000 */  daddu      $18, $0, $0
    /* EB5B8 001EB5B8 02000010 */  b          .L001EB5C4
    /* EB5BC 001EB5BC 00000000 */   nop
  .L001EB5C0:
    /* EB5C0 001EB5C0 02001264 */  daddiu     $18, $0, 0x2
  .L001EB5C4:
    /* EB5C4 001EB5C4 2D202002 */  daddu      $4, $17, $0
    /* EB5C8 001EB5C8 01000524 */  addiu      $5, $0, 0x1
    /* EB5CC 001EB5CC 6100023C */  lui        $2, %hi(D_006098BC)
    /* EB5D0 001EB5D0 BC98428C */  lw         $2, %lo(D_006098BC)($2)
    /* EB5D4 001EB5D4 09F84000 */  jalr       $2
    /* EB5D8 001EB5D8 00000000 */   nop
    /* EB5DC 001EB5DC 03004010 */  beqz       $2, .L001EB5EC
    /* EB5E0 001EB5E0 00000000 */   nop
    /* EB5E4 001EB5E4 01004226 */  addiu      $2, $18, 0x1
    /* EB5E8 001EB5E8 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001EB5EC:
    /* EB5EC 001EB5EC 3000228E */  lw         $2, 0x30($17)
    /* EB5F0 001EB5F0 A2004290 */  lbu        $2, 0xA2($2)
    /* EB5F4 001EB5F4 05004014 */  bnez       $2, .L001EB60C
    /* EB5F8 001EB5F8 00000000 */   nop
    /* EB5FC 001EB5FC 6100063C */  lui        $6, %hi(D_00609E50)
    /* EB600 001EB600 509EC624 */  addiu      $6, $6, %lo(D_00609E50)
    /* EB604 001EB604 22000010 */  b          .L001EB690
    /* EB608 001EB608 00000000 */   nop
  .L001EB60C:
    /* EB60C 001EB60C 6100063C */  lui        $6, %hi(D_00609EF0)
    /* EB610 001EB610 F09EC624 */  addiu      $6, $6, %lo(D_00609EF0)
    /* EB614 001EB614 1E000010 */  b          .L001EB690
    /* EB618 001EB618 00000000 */   nop
  .L001EB61C:
    /* EB61C 001EB61C 3000238E */  lw         $3, 0x30($17)
    /* EB620 001EB620 A2006290 */  lbu        $2, 0xA2($3)
    /* EB624 001EB624 08004014 */  bnez       $2, .L001EB648
    /* EB628 001EB628 00000000 */   nop
    /* EB62C 001EB62C A4006394 */  lhu        $3, 0xA4($3)
    /* EB630 001EB630 01000224 */  addiu      $2, $0, 0x1
    /* EB634 001EB634 04006214 */  bne        $3, $2, .L001EB648
    /* EB638 001EB638 00000000 */   nop
    /* EB63C 001EB63C FFFF5230 */  andi       $18, $2, 0xFFFF
    /* EB640 001EB640 09000010 */  b          .L001EB668
    /* EB644 001EB644 00000000 */   nop
  .L001EB648:
    /* EB648 001EB648 2D202002 */  daddu      $4, $17, $0
    /* EB64C 001EB64C 2D280000 */  daddu      $5, $0, $0
    /* EB650 001EB650 6100023C */  lui        $2, %hi(D_00609934)
    /* EB654 001EB654 3499428C */  lw         $2, %lo(D_00609934)($2)
    /* EB658 001EB658 09F84000 */  jalr       $2
    /* EB65C 001EB65C 00000000 */   nop
    /* EB660 001EB660 01004238 */  xori       $2, $2, 0x1
    /* EB664 001EB664 2B900200 */  sltu       $18, $0, $2
  .L001EB668:
    /* EB668 001EB668 6100063C */  lui        $6, %hi(D_00609F90)
    /* EB66C 001EB66C 909FC624 */  addiu      $6, $6, %lo(D_00609F90)
    /* EB670 001EB670 07000010 */  b          .L001EB690
    /* EB674 001EB674 00000000 */   nop
  .L001EB678:
    /* EB678 001EB678 D0A49327 */  addiu      $19, $28, -0x5B30
    /* EB67C 001EB67C 04000010 */  b          .L001EB690
    /* EB680 001EB680 00000000 */   nop
  .L001EB684:
    /* EB684 001EB684 2D900000 */  daddu      $18, $0, $0
    /* EB688 001EB688 6100063C */  lui        $6, %hi(D_0060A030)
    /* EB68C 001EB68C 30A0C624 */  addiu      $6, $6, %lo(D_0060A030)
  .L001EB690:
    /* EB690 001EB690 3300C010 */  beqz       $6, .L001EB760
    /* EB694 001EB694 00000000 */   nop
    /* EB698 001EB698 2D200000 */  daddu      $4, $0, $0
    /* EB69C 001EB69C 2D280000 */  daddu      $5, $0, $0
    /* EB6A0 001EB6A0 FFFF4332 */  andi       $3, $18, 0xFFFF
    /* EB6A4 001EB6A4 80100300 */  sll        $2, $3, 2
    /* EB6A8 001EB6A8 21104300 */  addu       $2, $2, $3
    /* EB6AC 001EB6AC C0100200 */  sll        $2, $2, 3
    /* EB6B0 001EB6B0 2190C200 */  addu       $18, $6, $2
    /* EB6B4 001EB6B4 09000010 */  b          .L001EB6DC
    /* EB6B8 001EB6B8 00000000 */   nop
  .L001EB6BC:
    /* EB6BC 001EB6BC FFFFA230 */  andi       $2, $5, 0xFFFF
    /* EB6C0 001EB6C0 C0100200 */  sll        $2, $2, 3
    /* EB6C4 001EB6C4 21104202 */  addu       $2, $18, $2
    /* EB6C8 001EB6C8 00004290 */  lbu        $2, 0x0($2)
    /* EB6CC 001EB6CC 21108200 */  addu       $2, $4, $2
    /* EB6D0 001EB6D0 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* EB6D4 001EB6D4 0100A224 */  addiu      $2, $5, 0x1
    /* EB6D8 001EB6D8 FFFF4530 */  andi       $5, $2, 0xFFFF
  .L001EB6DC:
    /* EB6DC 001EB6DC FFFFA230 */  andi       $2, $5, 0xFFFF
    /* EB6E0 001EB6E0 05004228 */  slti       $2, $2, 0x5
    /* EB6E4 001EB6E4 F5FF4014 */  bnez       $2, .L001EB6BC
    /* EB6E8 001EB6E8 00000000 */   nop
    /* EB6EC 001EB6EC 2D980000 */  daddu      $19, $0, $0
    /* EB6F0 001EB6F0 FFFF8430 */  andi       $4, $4, 0xFFFF
    /* EB6F4 001EB6F4 5CC7080C */  jal        func_00231d70
    /* EB6F8 001EB6F8 00000000 */   nop
    /* EB6FC 001EB6FC FFFF4530 */  andi       $5, $2, 0xFFFF
    /* EB700 001EB700 2D380000 */  daddu      $7, $0, $0
    /* EB704 001EB704 2D300000 */  daddu      $6, $0, $0
    /* EB708 001EB708 11000010 */  b          .L001EB750
    /* EB70C 001EB70C 00000000 */   nop
  .L001EB710:
    /* EB710 001EB710 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* EB714 001EB714 C0100200 */  sll        $2, $2, 3
    /* EB718 001EB718 21204202 */  addu       $4, $18, $2
    /* EB71C 001EB71C 00008390 */  lbu        $3, 0x0($4)
    /* EB720 001EB720 2110E300 */  addu       $2, $7, $3
    /* EB724 001EB724 FFFF4730 */  andi       $7, $2, 0xFFFF
    /* EB728 001EB728 2A08E500 */  slt        $1, $7, $5
    /* EB72C 001EB72C 06002014 */  bnez       $1, .L001EB748
    /* EB730 001EB730 00000000 */   nop
    /* EB734 001EB734 04006018 */  blez       $3, .L001EB748
    /* EB738 001EB738 00000000 */   nop
    /* EB73C 001EB73C 2D988000 */  daddu      $19, $4, $0
    /* EB740 001EB740 07000010 */  b          .L001EB760
    /* EB744 001EB744 00000000 */   nop
  .L001EB748:
    /* EB748 001EB748 0100C224 */  addiu      $2, $6, 0x1
    /* EB74C 001EB74C FFFF4630 */  andi       $6, $2, 0xFFFF
  .L001EB750:
    /* EB750 001EB750 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* EB754 001EB754 05004228 */  slti       $2, $2, 0x5
    /* EB758 001EB758 EDFF4014 */  bnez       $2, .L001EB710
    /* EB75C 001EB75C 00000000 */   nop
  .L001EB760:
    /* EB760 001EB760 2D202002 */  daddu      $4, $17, $0
    /* EB764 001EB764 2D280002 */  daddu      $5, $16, $0
    /* EB768 001EB768 02006696 */  lhu        $6, 0x2($19)
    /* EB76C 001EB76C 9079070C */  jal        func_001de640
    /* EB770 001EB770 00000000 */   nop
    /* EB774 001EB774 0400638E */  lw         $3, 0x4($19)
    /* EB778 001EB778 3C2A0300 */  dsll32     $5, $3, 8
    /* EB77C 001EB77C 3E2A0500 */  dsrl32     $5, $5, 8
    /* EB780 001EB780 2D202002 */  daddu      $4, $17, $0
    /* EB784 001EB784 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* EB788 001EB788 24106200 */  and        $2, $3, $2
    /* EB78C 001EB78C 02160200 */  srl        $2, $2, 24
    /* EB790 001EB790 C0180200 */  sll        $3, $2, 3
    /* EB794 001EB794 6100023C */  lui        $2, %hi(D_00609CE0)
    /* EB798 001EB798 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* EB79C 001EB79C 21104300 */  addu       $2, $2, $3
    /* EB7A0 001EB7A0 0000428C */  lw         $2, 0x0($2)
    /* EB7A4 001EB7A4 09F84000 */  jalr       $2
    /* EB7A8 001EB7A8 00000000 */   nop
    /* EB7AC 001EB7AC 07004014 */  bnez       $2, .L001EB7CC
    /* EB7B0 001EB7B0 00000000 */   nop
    /* EB7B4 001EB7B4 2D202002 */  daddu      $4, $17, $0
    /* EB7B8 001EB7B8 2D280000 */  daddu      $5, $0, $0
    /* EB7BC 001EB7BC 6100023C */  lui        $2, %hi(D_00609CE0)
    /* EB7C0 001EB7C0 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* EB7C4 001EB7C4 09F84000 */  jalr       $2
    /* EB7C8 001EB7C8 00000000 */   nop
  .L001EB7CC:
    /* EB7CC 001EB7CC 5000BFDF */  ld         $31, 0x50($29)
    /* EB7D0 001EB7D0 4000B47B */  lq         $20, 0x40($29)
    /* EB7D4 001EB7D4 3000B37B */  lq         $19, 0x30($29)
    /* EB7D8 001EB7D8 2000B27B */  lq         $18, 0x20($29)
    /* EB7DC 001EB7DC 1000B17B */  lq         $17, 0x10($29)
    /* EB7E0 001EB7E0 0000B07B */  lq         $16, 0x0($29)
    /* EB7E4 001EB7E4 6000BD27 */  addiu      $29, $29, 0x60
    /* EB7E8 001EB7E8 0800E003 */  jr         $31
    /* EB7EC 001EB7EC 00000000 */   nop
.size func_001eb4a0, 0x350
