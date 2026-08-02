.section .text
.set noat
.set noreorder
glabel func_001dd570
    /* DD570 001DD570 10FFBD27 */  addiu      $29, $29, -0xF0
    /* DD574 001DD574 9000BFFF */  sd         $31, 0x90($29)
    /* DD578 001DD578 8000BE7F */  sq         $30, 0x80($29)
    /* DD57C 001DD57C 7000B77F */  sq         $23, 0x70($29)
    /* DD580 001DD580 6000B67F */  sq         $22, 0x60($29)
    /* DD584 001DD584 5000B57F */  sq         $21, 0x50($29)
    /* DD588 001DD588 4000B47F */  sq         $20, 0x40($29)
    /* DD58C 001DD58C 3000B37F */  sq         $19, 0x30($29)
    /* DD590 001DD590 2000B27F */  sq         $18, 0x20($29)
    /* DD594 001DD594 1000B17F */  sq         $17, 0x10($29)
    /* DD598 001DD598 0000B07F */  sq         $16, 0x0($29)
    /* DD59C 001DD59C 2DA88000 */  daddu      $21, $4, $0
    /* DD5A0 001DD5A0 2DA0A000 */  daddu      $20, $5, $0
    /* DD5A4 001DD5A4 DC00A6AF */  sw         $6, 0xDC($29)
    /* DD5A8 001DD5A8 2DB8E000 */  daddu      $23, $7, $0
    /* DD5AC 001DD5AC 2D900000 */  daddu      $18, $0, $0
    /* DD5B0 001DD5B0 3000908C */  lw         $16, 0x30($4)
    /* DD5B4 001DD5B4 640A048E */  lw         $4, 0xA64($16)
    /* DD5B8 001DD5B8 2D280000 */  daddu      $5, $0, $0
    /* DD5BC 001DD5BC 38F6080C */  jal        func_0023d8e0
    /* DD5C0 001DD5C0 00000000 */   nop
    /* DD5C4 001DD5C4 3C2C0200 */  dsll32     $5, $2, 16
    /* DD5C8 001DD5C8 3F2C0500 */  dsra32     $5, $5, 16
    /* DD5CC 001DD5CC 2D208002 */  daddu      $4, $20, $0
    /* DD5D0 001DD5D0 01000624 */  addiu      $6, $0, 0x1
    /* DD5D4 001DD5D4 D86C070C */  jal        func_001db360
    /* DD5D8 001DD5D8 00000000 */   nop
    /* DD5DC 001DD5DC 04004010 */  beqz       $2, .L001DD5F0
    /* DD5E0 001DD5E0 00000000 */   nop
    /* DD5E4 001DD5E4 E000A0A7 */  sh         $0, 0xE0($29)
    /* DD5E8 001DD5E8 01004226 */  addiu      $2, $18, 0x1
    /* DD5EC 001DD5EC FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DD5F0:
    /* DD5F0 001DD5F0 640A048E */  lw         $4, 0xA64($16)
    /* DD5F4 001DD5F4 4CF8080C */  jal        func_0023e130
    /* DD5F8 001DD5F8 00000000 */   nop
    /* DD5FC 001DD5FC FFFF5130 */  andi       $17, $2, 0xFFFF
    /* DD600 001DD600 640A048E */  lw         $4, 0xA64($16)
    /* DD604 001DD604 50F8080C */  jal        func_0023e140
    /* DD608 001DD608 00000000 */   nop
    /* DD60C 001DD60C C000A27F */  sq         $2, 0xC0($29)
    /* DD610 001DD610 2D980000 */  daddu      $19, $0, $0
    /* DD614 001DD614 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* DD618 001DD618 B000A27F */  sq         $2, 0xB0($29)
    /* DD61C 001DD61C 73000010 */  b          .L001DD7EC
    /* DD620 001DD620 00000000 */   nop
  .L001DD624:
    /* DD624 001DD624 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* DD628 001DD628 40180200 */  sll        $3, $2, 1
    /* DD62C 001DD62C C000A27B */  lq         $2, 0xC0($29)
    /* DD630 001DD630 21F04300 */  addu       $30, $2, $3
    /* DD634 001DD634 0000C597 */  lhu        $5, 0x0($30)
    /* DD638 001DD638 6A00A010 */  beqz       $5, .L001DD7E4
    /* DD63C 001DD63C 00000000 */   nop
    /* DD640 001DD640 B801A128 */  slti       $1, $5, 0x1B8
    /* DD644 001DD644 67002010 */  beqz       $1, .L001DD7E4
    /* DD648 001DD648 00000000 */   nop
    /* DD64C 001DD64C 640A048E */  lw         $4, 0xA64($16)
    /* DD650 001DD650 38F6080C */  jal        func_0023d8e0
    /* DD654 001DD654 00000000 */   nop
    /* DD658 001DD658 3C140200 */  dsll32     $2, $2, 16
    /* DD65C 001DD65C 3F140200 */  dsra32     $2, $2, 16
    /* DD660 001DD660 A000A27F */  sq         $2, 0xA0($29)
    /* DD664 001DD664 28264070 */  paddub     $4, $2, $0
    /* DD668 001DD668 B8F5080C */  jal        func_0023d6e0
    /* DD66C 001DD66C 00000000 */   nop
    /* DD670 001DD670 0600E016 */  bnez       $23, .L001DD68C
    /* DD674 001DD674 00000000 */   nop
    /* DD678 001DD678 7E004230 */  andi       $2, $2, 0x7E
    /* DD67C 001DD67C 14004014 */  bnez       $2, .L001DD6D0
    /* DD680 001DD680 00000000 */   nop
    /* DD684 001DD684 57000010 */  b          .L001DD7E4
    /* DD688 001DD688 00000000 */   nop
  .L001DD68C:
    /* DD68C 001DD68C 01000324 */  addiu      $3, $0, 0x1
    /* DD690 001DD690 0900E316 */  bne        $23, $3, .L001DD6B8
    /* DD694 001DD694 00000000 */   nop
    /* DD698 001DD698 7E004330 */  andi       $3, $2, 0x7E
    /* DD69C 001DD69C 51006010 */  beqz       $3, .L001DD7E4
    /* DD6A0 001DD6A0 00000000 */   nop
    /* DD6A4 001DD6A4 02004230 */  andi       $2, $2, 0x2
    /* DD6A8 001DD6A8 09004010 */  beqz       $2, .L001DD6D0
    /* DD6AC 001DD6AC 00000000 */   nop
    /* DD6B0 001DD6B0 4C000010 */  b          .L001DD7E4
    /* DD6B4 001DD6B4 00000000 */   nop
  .L001DD6B8:
    /* DD6B8 001DD6B8 02000324 */  addiu      $3, $0, 0x2
    /* DD6BC 001DD6BC 0400E316 */  bne        $23, $3, .L001DD6D0
    /* DD6C0 001DD6C0 00000000 */   nop
    /* DD6C4 001DD6C4 02004230 */  andi       $2, $2, 0x2
    /* DD6C8 001DD6C8 46004010 */  beqz       $2, .L001DD7E4
    /* DD6CC 001DD6CC 00000000 */   nop
  .L001DD6D0:
    /* DD6D0 001DD6D0 0000D197 */  lhu        $17, 0x0($30)
    /* DD6D4 001DD6D4 4002222A */  slti       $2, $17, 0x240
    /* DD6D8 001DD6D8 06004014 */  bnez       $2, .L001DD6F4
    /* DD6DC 001DD6DC 00000000 */   nop
    /* DD6E0 001DD6E0 6100043C */  lui        $4, %hi(D_006095E0)
    /* DD6E4 001DD6E4 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* DD6E8 001DD6E8 5F040524 */  addiu      $5, $0, 0x45F
    /* DD6EC 001DD6EC CCB5110C */  jal        func_0046d730
    /* DD6F0 001DD6F0 00000000 */   nop
  .L001DD6F4:
    /* DD6F4 001DD6F4 3000B68E */  lw         $22, 0x30($21)
    /* DD6F8 001DD6F8 B801212A */  slti       $1, $17, 0x1B8
    /* DD6FC 001DD6FC 1D002010 */  beqz       $1, .L001DD774
    /* DD700 001DD700 00000000 */   nop
    /* DD704 001DD704 640AC48E */  lw         $4, 0xA64($22)
    /* DD708 001DD708 0800023C */  lui        $2, (0x80008 >> 16)
    /* DD70C 001DD70C 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* DD710 001DD710 C4C9080C */  jal        func_00232710
    /* DD714 001DD714 00000000 */   nop
    /* DD718 001DD718 04004010 */  beqz       $2, .L001DD72C
    /* DD71C 001DD71C 00000000 */   nop
    /* DD720 001DD720 2D100000 */  daddu      $2, $0, $0
    /* DD724 001DD724 1D000010 */  b          .L001DD79C
    /* DD728 001DD728 00000000 */   nop
  .L001DD72C:
    /* DD72C 001DD72C 640AC48E */  lw         $4, 0xA64($22)
    /* DD730 001DD730 2D282002 */  daddu      $5, $17, $0
    /* DD734 001DD734 CCC9080C */  jal        func_00232730
    /* DD738 001DD738 00000000 */   nop
    /* DD73C 001DD73C 04004014 */  bnez       $2, .L001DD750
    /* DD740 001DD740 00000000 */   nop
    /* DD744 001DD744 2D100000 */  daddu      $2, $0, $0
    /* DD748 001DD748 14000010 */  b          .L001DD79C
    /* DD74C 001DD74C 00000000 */   nop
  .L001DD750:
    /* DD750 001DD750 640AC48E */  lw         $4, 0xA64($22)
    /* DD754 001DD754 2D282002 */  daddu      $5, $17, $0
    /* DD758 001DD758 70F7080C */  jal        func_0023ddc0
    /* DD75C 001DD75C 00000000 */   nop
    /* DD760 001DD760 0D004010 */  beqz       $2, .L001DD798
    /* DD764 001DD764 00000000 */   nop
    /* DD768 001DD768 2D100000 */  daddu      $2, $0, $0
    /* DD76C 001DD76C 0B000010 */  b          .L001DD79C
    /* DD770 001DD770 00000000 */   nop
  .L001DD774:
    /* DD774 001DD774 640AC48E */  lw         $4, 0xA64($22)
    /* DD778 001DD778 2D282002 */  daddu      $5, $17, $0
    /* DD77C 001DD77C CCC9080C */  jal        func_00232730
    /* DD780 001DD780 00000000 */   nop
    /* DD784 001DD784 04004014 */  bnez       $2, .L001DD798
    /* DD788 001DD788 00000000 */   nop
    /* DD78C 001DD78C 2D100000 */  daddu      $2, $0, $0
    /* DD790 001DD790 02000010 */  b          .L001DD79C
    /* DD794 001DD794 00000000 */   nop
  .L001DD798:
    /* DD798 001DD798 01000224 */  addiu      $2, $0, 0x1
  .L001DD79C:
    /* DD79C 001DD79C 11004010 */  beqz       $2, .L001DD7E4
    /* DD7A0 001DD7A0 00000000 */   nop
    /* DD7A4 001DD7A4 A000A27B */  lq         $2, 0xA0($29)
    /* DD7A8 001DD7A8 3C2C0200 */  dsll32     $5, $2, 16
    /* DD7AC 001DD7AC 3F2C0500 */  dsra32     $5, $5, 16
    /* DD7B0 001DD7B0 2D208002 */  daddu      $4, $20, $0
    /* DD7B4 001DD7B4 01000624 */  addiu      $6, $0, 0x1
    /* DD7B8 001DD7B8 D86C070C */  jal        func_001db360
    /* DD7BC 001DD7BC 00000000 */   nop
    /* DD7C0 001DD7C0 08004010 */  beqz       $2, .L001DD7E4
    /* DD7C4 001DD7C4 00000000 */   nop
    /* DD7C8 001DD7C8 0000C397 */  lhu        $3, 0x0($30)
    /* DD7CC 001DD7CC FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DD7D0 001DD7D0 40100200 */  sll        $2, $2, 1
    /* DD7D4 001DD7D4 21105D00 */  addu       $2, $2, $29
    /* DD7D8 001DD7D8 E00043A4 */  sh         $3, 0xE0($2)
    /* DD7DC 001DD7DC 01004226 */  addiu      $2, $18, 0x1
    /* DD7E0 001DD7E0 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DD7E4:
    /* DD7E4 001DD7E4 01006226 */  addiu      $2, $19, 0x1
    /* DD7E8 001DD7E8 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001DD7EC:
    /* DD7EC 001DD7EC FFFF6332 */  andi       $3, $19, 0xFFFF
    /* DD7F0 001DD7F0 B000A27B */  lq         $2, 0xB0($29)
    /* DD7F4 001DD7F4 2A106200 */  slt        $2, $3, $2
    /* DD7F8 001DD7F8 8AFF4014 */  bnez       $2, .L001DD624
    /* DD7FC 001DD7FC 00000000 */   nop
    /* DD800 001DD800 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DD804 001DD804 35004018 */  blez       $2, .L001DD8DC
    /* DD808 001DD808 00000000 */   nop
    /* DD80C 001DD80C 01000824 */  addiu      $8, $0, 0x1
    /* DD810 001DD810 DC00A28F */  lw         $2, 0xDC($29)
    /* DD814 001DD814 17004810 */  beq        $2, $8, .L001DD874
    /* DD818 001DD818 00000000 */   nop
    /* DD81C 001DD81C 03004010 */  beqz       $2, .L001DD82C
    /* DD820 001DD820 00000000 */   nop
    /* DD824 001DD824 24000010 */  b          .L001DD8B8
    /* DD828 001DD828 00000000 */   nop
  .L001DD82C:
    /* DD82C 001DD82C 2D20A002 */  daddu      $4, $21, $0
    /* DD830 001DD830 2D288002 */  daddu      $5, $20, $0
    /* DD834 001DD834 E000A627 */  addiu      $6, $29, 0xE0
    /* DD838 001DD838 2D384002 */  daddu      $7, $18, $0
    /* DD83C 001DD83C 2D400000 */  daddu      $8, $0, $0
    /* DD840 001DD840 7074070C */  jal        func_001dd1c0
    /* DD844 001DD844 00000000 */   nop
    /* DD848 001DD848 22004104 */  bgez       $2, .L001DD8D4
    /* DD84C 001DD84C 00000000 */   nop
    /* DD850 001DD850 2D20A002 */  daddu      $4, $21, $0
    /* DD854 001DD854 2D288002 */  daddu      $5, $20, $0
    /* DD858 001DD858 E000A627 */  addiu      $6, $29, 0xE0
    /* DD85C 001DD85C 2D384002 */  daddu      $7, $18, $0
    /* DD860 001DD860 01000824 */  addiu      $8, $0, 0x1
    /* DD864 001DD864 7074070C */  jal        func_001dd1c0
    /* DD868 001DD868 00000000 */   nop
    /* DD86C 001DD86C 19000010 */  b          .L001DD8D4
    /* DD870 001DD870 00000000 */   nop
  .L001DD874:
    /* DD874 001DD874 2D20A002 */  daddu      $4, $21, $0
    /* DD878 001DD878 2D288002 */  daddu      $5, $20, $0
    /* DD87C 001DD87C E000A627 */  addiu      $6, $29, 0xE0
    /* DD880 001DD880 2D384002 */  daddu      $7, $18, $0
    /* DD884 001DD884 7074070C */  jal        func_001dd1c0
    /* DD888 001DD888 00000000 */   nop
    /* DD88C 001DD88C 11004104 */  bgez       $2, .L001DD8D4
    /* DD890 001DD890 00000000 */   nop
    /* DD894 001DD894 2D20A002 */  daddu      $4, $21, $0
    /* DD898 001DD898 2D288002 */  daddu      $5, $20, $0
    /* DD89C 001DD89C E000A627 */  addiu      $6, $29, 0xE0
    /* DD8A0 001DD8A0 2D384002 */  daddu      $7, $18, $0
    /* DD8A4 001DD8A4 2D400000 */  daddu      $8, $0, $0
    /* DD8A8 001DD8A8 7074070C */  jal        func_001dd1c0
    /* DD8AC 001DD8AC 00000000 */   nop
    /* DD8B0 001DD8B0 08000010 */  b          .L001DD8D4
    /* DD8B4 001DD8B4 00000000 */   nop
  .L001DD8B8:
    /* DD8B8 001DD8B8 2D20A002 */  daddu      $4, $21, $0
    /* DD8BC 001DD8BC 2D288002 */  daddu      $5, $20, $0
    /* DD8C0 001DD8C0 E000A627 */  addiu      $6, $29, 0xE0
    /* DD8C4 001DD8C4 2D384002 */  daddu      $7, $18, $0
    /* DD8C8 001DD8C8 FFFF0834 */  ori        $8, $0, 0xFFFF
    /* DD8CC 001DD8CC 7074070C */  jal        func_001dd1c0
    /* DD8D0 001DD8D0 00000000 */   nop
  .L001DD8D4:
    /* DD8D4 001DD8D4 02000010 */  b          .L001DD8E0
    /* DD8D8 001DD8D8 00000000 */   nop
  .L001DD8DC:
    /* DD8DC 001DD8DC FFFF0224 */  addiu      $2, $0, -0x1
  .L001DD8E0:
    /* DD8E0 001DD8E0 9000BFDF */  ld         $31, 0x90($29)
    /* DD8E4 001DD8E4 8000BE7B */  lq         $30, 0x80($29)
    /* DD8E8 001DD8E8 7000B77B */  lq         $23, 0x70($29)
    /* DD8EC 001DD8EC 6000B67B */  lq         $22, 0x60($29)
    /* DD8F0 001DD8F0 5000B57B */  lq         $21, 0x50($29)
    /* DD8F4 001DD8F4 4000B47B */  lq         $20, 0x40($29)
    /* DD8F8 001DD8F8 3000B37B */  lq         $19, 0x30($29)
    /* DD8FC 001DD8FC 2000B27B */  lq         $18, 0x20($29)
    /* DD900 001DD900 1000B17B */  lq         $17, 0x10($29)
    /* DD904 001DD904 0000B07B */  lq         $16, 0x0($29)
    /* DD908 001DD908 F000BD27 */  addiu      $29, $29, 0xF0
    /* DD90C 001DD90C 0800E003 */  jr         $31
    /* DD910 001DD910 00000000 */   nop
    /* DD914 001DD914 00000000 */  nop
    /* DD918 001DD918 00000000 */  nop
    /* DD91C 001DD91C 00000000 */  nop
.size func_001dd570, 0x3b0
