.section .text
.set noat
.set noreorder
glabel func_001ee610
    /* EE610 001EE610 20FBBD27 */  addiu      $29, $29, -0x4E0
    /* EE614 001EE614 7000BFFF */  sd         $31, 0x70($29)
    /* EE618 001EE618 6000B57F */  sq         $21, 0x60($29)
    /* EE61C 001EE61C 5000B47F */  sq         $20, 0x50($29)
    /* EE620 001EE620 4000B37F */  sq         $19, 0x40($29)
    /* EE624 001EE624 3000B27F */  sq         $18, 0x30($29)
    /* EE628 001EE628 2000B17F */  sq         $17, 0x20($29)
    /* EE62C 001EE62C 1000B07F */  sq         $16, 0x10($29)
    /* EE630 001EE630 0400B5E7 */  swc1       $f21, 0x4($29)
    /* EE634 001EE634 0000B4E7 */  swc1       $f20, 0x0($29)
    /* EE638 001EE638 2DA08000 */  daddu      $20, $4, $0
    /* EE63C 001EE63C 2D900000 */  daddu      $18, $0, $0
    /* EE640 001EE640 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE644 001EE644 0C097024 */  addiu      $16, $3, 0x90C
    /* EE648 001EE648 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* EE64C 001EE64C 00008244 */  mtc1       $2, $f0
    /* EE650 001EE650 00000000 */  nop
    /* EE654 001EE654 02050C46 */  mul.s      $f20, $f0, $f12
    /* EE658 001EE658 E4076424 */  addiu      $4, $3, 0x7E4
    /* EE65C 001EE65C 14096524 */  addiu      $5, $3, 0x914
    /* EE660 001EE660 06A30046 */  mov.s      $f12, $f20
    /* EE664 001EE664 94B3070C */  jal        func_001ece50
    /* EE668 001EE668 00000000 */   nop
    /* EE66C 001EE66C 0D004014 */  bnez       $2, .L001EE6A4
    /* EE670 001EE670 00000000 */   nop
    /* EE674 001EE674 ACB3828F */  lw         $2, -0x4C54($28)
    /* EE678 001EE678 140941C4 */  lwc1       $f1, 0x914($2)
    /* EE67C 001EE67C 180940C4 */  lwc1       $f0, 0x918($2)
    /* EE680 001EE680 8000A1E7 */  swc1       $f1, 0x80($29)
    /* EE684 001EE684 8400A0E7 */  swc1       $f0, 0x84($29)
    /* EE688 001EE688 E40741C4 */  lwc1       $f1, 0x7E4($2)
    /* EE68C 001EE68C E80740C4 */  lwc1       $f0, 0x7E8($2)
    /* EE690 001EE690 8800A1E7 */  swc1       $f1, 0x88($29)
    /* EE694 001EE694 8C00A0E7 */  swc1       $f0, 0x8C($29)
    /* EE698 001EE698 02001224 */  addiu      $18, $0, 0x2
    /* EE69C 001EE69C 8E000010 */  b          .L001EE8D8
    /* EE6A0 001EE6A0 00000000 */   nop
  .L001EE6A4:
    /* EE6A4 001EE6A4 8A000010 */  b          .L001EE8D0
    /* EE6A8 001EE6A8 00000000 */   nop
  .L001EE6AC:
    /* EE6AC 001EE6AC 1600401A */  blez       $18, .L001EE708
    /* EE6B0 001EE6B0 00000000 */   nop
    /* EE6B4 001EE6B4 2D880002 */  daddu      $17, $16, $0
    /* EE6B8 001EE6B8 0A000010 */  b          .L001EE6E4
    /* EE6BC 001EE6BC 00000000 */   nop
  .L001EE6C0:
    /* EE6C0 001EE6C0 C804A427 */  addiu      $4, $29, 0x4C8
    /* EE6C4 001EE6C4 08000526 */  addiu      $5, $16, 0x8
    /* EE6C8 001EE6C8 06A30046 */  mov.s      $f12, $f20
    /* EE6CC 001EE6CC 94B3070C */  jal        func_001ece50
    /* EE6D0 001EE6D0 00000000 */   nop
    /* EE6D4 001EE6D4 05004014 */  bnez       $2, .L001EE6EC
    /* EE6D8 001EE6D8 00000000 */   nop
    /* EE6DC 001EE6DC 2D880002 */  daddu      $17, $16, $0
    /* EE6E0 001EE6E0 2C00108E */  lw         $16, 0x2C($16)
  .L001EE6E4:
    /* EE6E4 001EE6E4 F6FF0016 */  bnez       $16, .L001EE6C0
    /* EE6E8 001EE6E8 00000000 */   nop
  .L001EE6EC:
    /* EE6EC 001EE6EC 2D802002 */  daddu      $16, $17, $0
    /* EE6F0 001EE6F0 080021C6 */  lwc1       $f1, 0x8($17)
    /* EE6F4 001EE6F4 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* EE6F8 001EE6F8 C804A1E7 */  swc1       $f1, 0x4C8($29)
    /* EE6FC 001EE6FC CC04A0E7 */  swc1       $f0, 0x4CC($29)
    /* EE700 001EE700 05000010 */  b          .L001EE718
    /* EE704 001EE704 00000000 */   nop
  .L001EE708:
    /* EE708 001EE708 080001C6 */  lwc1       $f1, 0x8($16)
    /* EE70C 001EE70C 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* EE710 001EE710 C804A1E7 */  swc1       $f1, 0x4C8($29)
    /* EE714 001EE714 CC04A0E7 */  swc1       $f0, 0x4CC($29)
  .L001EE718:
    /* EE718 001EE718 A804A527 */  addiu      $5, $29, 0x4A8
    /* EE71C 001EE71C A804A1C7 */  lwc1       $f1, 0x4A8($29)
    /* EE720 001EE720 AC04A0C7 */  lwc1       $f0, 0x4AC($29)
    /* EE724 001EE724 A004A1E7 */  swc1       $f1, 0x4A0($29)
    /* EE728 001EE728 A404A0E7 */  swc1       $f0, 0x4A4($29)
    /* EE72C 001EE72C C804A1C7 */  lwc1       $f1, 0x4C8($29)
    /* EE730 001EE730 D804A0C7 */  lwc1       $f0, 0x4D8($29)
    /* EE734 001EE734 C1080046 */  sub.s      $f3, $f1, $f0
    /* EE738 001EE738 A804A3E7 */  swc1       $f3, 0x4A8($29)
    /* EE73C 001EE73C CC04A1C7 */  lwc1       $f1, 0x4CC($29)
    /* EE740 001EE740 DC04A0C7 */  lwc1       $f0, 0x4DC($29)
    /* EE744 001EE744 81080046 */  sub.s      $f2, $f1, $f0
    /* EE748 001EE748 AC04A2E7 */  swc1       $f2, 0x4AC($29)
    /* EE74C 001EE74C A004A1C7 */  lwc1       $f1, 0x4A0($29)
    /* EE750 001EE750 A404A0C7 */  lwc1       $f0, 0x4A4($29)
    /* EE754 001EE754 1A000246 */  mula.s     $f0, $f2
    /* EE758 001EE758 5C080346 */  madd.s     $f1, $f1, $f3
    /* EE75C 001EE75C 0200412A */  slti       $1, $18, 0x2
    /* EE760 001EE760 4B002014 */  bnez       $1, .L001EE890
    /* EE764 001EE764 00000000 */   nop
    /* EE768 001EE768 348380C7 */  lwc1       $f0, -0x7CCC($28)
    /* EE76C 001EE76C 36080046 */  c.le.s     $f1, $f0
    /* EE770 001EE770 47000045 */  bc1f       .L001EE890
    /* EE774 001EE774 00000000 */   nop
    /* EE778 001EE778 B004A427 */  addiu      $4, $29, 0x4B0
    /* EE77C 001EE77C 78900F0C */  jal        func_003e41e0
    /* EE780 001EE780 00000000 */   nop
    /* EE784 001EE784 46050046 */  mov.s      $f21, $f0
    /* EE788 001EE788 B804A427 */  addiu      $4, $29, 0x4B8
    /* EE78C 001EE78C A004A527 */  addiu      $5, $29, 0x4A0
    /* EE790 001EE790 78900F0C */  jal        func_003e41e0
    /* EE794 001EE794 00000000 */   nop
    /* EE798 001EE798 7A43023C */  lui        $2, (0x437A0000 >> 16)
    /* EE79C 001EE79C 00088244 */  mtc1       $2, $f1
    /* EE7A0 001EE7A0 00000000 */  nop
    /* EE7A4 001EE7A4 34A80146 */  c.lt.s     $f21, $f1
    /* EE7A8 001EE7A8 07000045 */  bc1f       .L001EE7C8
    /* EE7AC 001EE7AC 00000000 */   nop
    /* EE7B0 001EE7B0 34000146 */  c.lt.s     $f0, $f1
    /* EE7B4 001EE7B4 04000045 */  bc1f       .L001EE7C8
    /* EE7B8 001EE7B8 00000000 */   nop
    /* EE7BC 001EE7BC FFFF5226 */  addiu      $18, $18, -0x1
    /* EE7C0 001EE7C0 29000010 */  b          .L001EE868
    /* EE7C4 001EE7C4 00000000 */   nop
  .L001EE7C8:
    /* EE7C8 001EE7C8 388381C7 */  lwc1       $f1, -0x7CC8($28)
    /* EE7CC 001EE7CC 82081546 */  mul.s      $f2, $f1, $f21
    /* EE7D0 001EE7D0 B004A1C7 */  lwc1       $f1, 0x4B0($29)
    /* EE7D4 001EE7D4 C2080246 */  mul.s      $f3, $f1, $f2
    /* EE7D8 001EE7D8 D004A3E7 */  swc1       $f3, 0x4D0($29)
    /* EE7DC 001EE7DC B404A1C7 */  lwc1       $f1, 0x4B4($29)
    /* EE7E0 001EE7E0 82080246 */  mul.s      $f2, $f1, $f2
    /* EE7E4 001EE7E4 D404A2E7 */  swc1       $f2, 0x4D4($29)
    /* EE7E8 001EE7E8 C0101200 */  sll        $2, $18, 3
    /* EE7EC 001EE7EC 21105D00 */  addu       $2, $2, $29
    /* EE7F0 001EE7F0 80004224 */  addiu      $2, $2, 0x80
    /* EE7F4 001EE7F4 F8FF41C4 */  lwc1       $f1, -0x8($2)
    /* EE7F8 001EE7F8 40180146 */  add.s      $f1, $f3, $f1
    /* EE7FC 001EE7FC D004A1E7 */  swc1       $f1, 0x4D0($29)
    /* EE800 001EE800 FCFF41C4 */  lwc1       $f1, -0x4($2)
    /* EE804 001EE804 40100146 */  add.s      $f1, $f2, $f1
    /* EE808 001EE808 D404A1E7 */  swc1       $f1, 0x4D4($29)
    /* EE80C 001EE80C D004A2C7 */  lwc1       $f2, 0x4D0($29)
    /* EE810 001EE810 D404A1C7 */  lwc1       $f1, 0x4D4($29)
    /* EE814 001EE814 000042E4 */  swc1       $f2, 0x0($2)
    /* EE818 001EE818 040041E4 */  swc1       $f1, 0x4($2)
    /* EE81C 001EE81C FC8081C7 */  lwc1       $f1, -0x7F04($28)
    /* EE820 001EE820 42080046 */  mul.s      $f1, $f1, $f0
    /* EE824 001EE824 B804A0C7 */  lwc1       $f0, 0x4B8($29)
    /* EE828 001EE828 82000146 */  mul.s      $f2, $f0, $f1
    /* EE82C 001EE82C D004A2E7 */  swc1       $f2, 0x4D0($29)
    /* EE830 001EE830 BC04A0C7 */  lwc1       $f0, 0x4BC($29)
    /* EE834 001EE834 42000146 */  mul.s      $f1, $f0, $f1
    /* EE838 001EE838 D404A1E7 */  swc1       $f1, 0x4D4($29)
    /* EE83C 001EE83C F0FF40C4 */  lwc1       $f0, -0x10($2)
    /* EE840 001EE840 00100046 */  add.s      $f0, $f2, $f0
    /* EE844 001EE844 D004A0E7 */  swc1       $f0, 0x4D0($29)
    /* EE848 001EE848 F4FF40C4 */  lwc1       $f0, -0xC($2)
    /* EE84C 001EE84C 00080046 */  add.s      $f0, $f1, $f0
    /* EE850 001EE850 D404A0E7 */  swc1       $f0, 0x4D4($29)
    /* EE854 001EE854 D004A1C7 */  lwc1       $f1, 0x4D0($29)
    /* EE858 001EE858 D404A0C7 */  lwc1       $f0, 0x4D4($29)
    /* EE85C 001EE85C F8FF41E4 */  swc1       $f1, -0x8($2)
    /* EE860 001EE860 FCFF40E4 */  swc1       $f0, -0x4($2)
    /* EE864 001EE864 01005226 */  addiu      $18, $18, 0x1
  .L001EE868:
    /* EE868 001EE868 C0101200 */  sll        $2, $18, 3
    /* EE86C 001EE86C 21105D00 */  addu       $2, $2, $29
    /* EE870 001EE870 80004224 */  addiu      $2, $2, 0x80
    /* EE874 001EE874 C804A1C7 */  lwc1       $f1, 0x4C8($29)
    /* EE878 001EE878 CC04A0C7 */  lwc1       $f0, 0x4CC($29)
    /* EE87C 001EE87C 000041E4 */  swc1       $f1, 0x0($2)
    /* EE880 001EE880 040040E4 */  swc1       $f0, 0x4($2)
    /* EE884 001EE884 01005226 */  addiu      $18, $18, 0x1
    /* EE888 001EE888 09000010 */  b          .L001EE8B0
    /* EE88C 001EE88C 00000000 */   nop
  .L001EE890:
    /* EE890 001EE890 C0101200 */  sll        $2, $18, 3
    /* EE894 001EE894 21105D00 */  addu       $2, $2, $29
    /* EE898 001EE898 80004224 */  addiu      $2, $2, 0x80
    /* EE89C 001EE89C C804A1C7 */  lwc1       $f1, 0x4C8($29)
    /* EE8A0 001EE8A0 CC04A0C7 */  lwc1       $f0, 0x4CC($29)
    /* EE8A4 001EE8A4 000041E4 */  swc1       $f1, 0x0($2)
    /* EE8A8 001EE8A8 040040E4 */  swc1       $f0, 0x4($2)
    /* EE8AC 001EE8AC 01005226 */  addiu      $18, $18, 0x1
  .L001EE8B0:
    /* EE8B0 001EE8B0 C0101200 */  sll        $2, $18, 3
    /* EE8B4 001EE8B4 21105D00 */  addu       $2, $2, $29
    /* EE8B8 001EE8B8 78004224 */  addiu      $2, $2, 0x78
    /* EE8BC 001EE8BC 000041C4 */  lwc1       $f1, 0x0($2)
    /* EE8C0 001EE8C0 040040C4 */  lwc1       $f0, 0x4($2)
    /* EE8C4 001EE8C4 D804A1E7 */  swc1       $f1, 0x4D8($29)
    /* EE8C8 001EE8C8 DC04A0E7 */  swc1       $f0, 0x4DC($29)
    /* EE8CC 001EE8CC 2C00108E */  lw         $16, 0x2C($16)
  .L001EE8D0:
    /* EE8D0 001EE8D0 76FF0016 */  bnez       $16, .L001EE6AC
    /* EE8D4 001EE8D4 00000000 */   nop
  .L001EE8D8:
    /* EE8D8 001EE8D8 0200412A */  slti       $1, $18, 0x2
    /* EE8DC 001EE8DC 04002010 */  beqz       $1, .L001EE8F0
    /* EE8E0 001EE8E0 00000000 */   nop
    /* EE8E4 001EE8E4 2D100000 */  daddu      $2, $0, $0
    /* EE8E8 001EE8E8 CC000010 */  b          .L001EEC1C
    /* EE8EC 001EE8EC 00000000 */   nop
  .L001EE8F0:
    /* EE8F0 001EE8F0 0300412A */  slti       $1, $18, 0x3
    /* EE8F4 001EE8F4 0D002010 */  beqz       $1, .L001EE92C
    /* EE8F8 001EE8F8 00000000 */   nop
    /* EE8FC 001EE8FC 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* EE900 001EE900 8C00A0C7 */  lwc1       $f0, 0x8C($29)
    /* EE904 001EE904 000081E6 */  swc1       $f1, 0x0($20)
    /* EE908 001EE908 040080E6 */  swc1       $f0, 0x4($20)
    /* EE90C 001EE90C 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* EE910 001EE910 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* EE914 001EE914 080081E6 */  swc1       $f1, 0x8($20)
    /* EE918 001EE918 0C0080E6 */  swc1       $f0, 0xC($20)
    /* EE91C 001EE91C 02000224 */  addiu      $2, $0, 0x2
    /* EE920 001EE920 000482A6 */  sh         $2, 0x400($20)
    /* EE924 001EE924 BC000010 */  b          .L001EEC18
    /* EE928 001EE928 00000000 */   nop
  .L001EE92C:
    /* EE92C 001EE92C 2D880000 */  daddu      $17, $0, $0
    /* EE930 001EE930 FFFF5326 */  addiu      $19, $18, -0x1
    /* EE934 001EE934 C0101200 */  sll        $2, $18, 3
    /* EE938 001EE938 21105D00 */  addu       $2, $2, $29
    /* EE93C 001EE93C 80005524 */  addiu      $21, $2, 0x80
    /* EE940 001EE940 8400B4C7 */  lwc1       $f20, 0x84($29)
  .L001EE944:
    /* EE944 001EE944 01006226 */  addiu      $2, $19, 0x1
    /* EE948 001EE948 2A105200 */  slt        $2, $2, $18
    /* EE94C 001EE94C 07004014 */  bnez       $2, .L001EE96C
    /* EE950 001EE950 00000000 */   nop
    /* EE954 001EE954 F8FFA1C6 */  lwc1       $f1, -0x8($21)
    /* EE958 001EE958 FCFFA0C6 */  lwc1       $f0, -0x4($21)
    /* EE95C 001EE95C 8004A1E7 */  swc1       $f1, 0x480($29)
    /* EE960 001EE960 8404A0E7 */  swc1       $f0, 0x484($29)
    /* EE964 001EE964 08000010 */  b          .L001EE988
    /* EE968 001EE968 00000000 */   nop
  .L001EE96C:
    /* EE96C 001EE96C C0101300 */  sll        $2, $19, 3
    /* EE970 001EE970 21105D00 */  addu       $2, $2, $29
    /* EE974 001EE974 88004224 */  addiu      $2, $2, 0x88
    /* EE978 001EE978 000041C4 */  lwc1       $f1, 0x0($2)
    /* EE97C 001EE97C 040040C4 */  lwc1       $f0, 0x4($2)
    /* EE980 001EE980 8004A1E7 */  swc1       $f1, 0x480($29)
    /* EE984 001EE984 8404A0E7 */  swc1       $f0, 0x484($29)
  .L001EE988:
    /* EE988 001EE988 C0101300 */  sll        $2, $19, 3
    /* EE98C 001EE98C 21105D00 */  addu       $2, $2, $29
    /* EE990 001EE990 80005024 */  addiu      $16, $2, 0x80
    /* EE994 001EE994 000001C6 */  lwc1       $f1, 0x0($16)
    /* EE998 001EE998 040000C6 */  lwc1       $f0, 0x4($16)
    /* EE99C 001EE99C 8804A1E7 */  swc1       $f1, 0x488($29)
    /* EE9A0 001EE9A0 8C04A0E7 */  swc1       $f0, 0x48C($29)
    /* EE9A4 001EE9A4 FFFF6226 */  addiu      $2, $19, -0x1
    /* EE9A8 001EE9A8 1F004104 */  bgez       $2, .L001EEA28
    /* EE9AC 001EE9AC 00000000 */   nop
    /* EE9B0 001EE9B0 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* EE9B4 001EE9B4 8804A0C7 */  lwc1       $f0, 0x488($29)
    /* EE9B8 001EE9B8 01080046 */  sub.s      $f0, $f1, $f0
    /* EE9BC 001EE9BC C004A0E7 */  swc1       $f0, 0x4C0($29)
    /* EE9C0 001EE9C0 8C04A0C7 */  lwc1       $f0, 0x48C($29)
    /* EE9C4 001EE9C4 01A00046 */  sub.s      $f0, $f20, $f0
    /* EE9C8 001EE9C8 C404A0E7 */  swc1       $f0, 0x4C4($29)
    /* EE9CC 001EE9CC C004A427 */  addiu      $4, $29, 0x4C0
    /* EE9D0 001EE9D0 2D288000 */  daddu      $5, $4, $0
    /* EE9D4 001EE9D4 78900F0C */  jal        func_003e41e0
    /* EE9D8 001EE9D8 00000000 */   nop
    /* EE9DC 001EE9DC 9643023C */  lui        $2, (0x43960000 >> 16)
    /* EE9E0 001EE9E0 00088244 */  mtc1       $2, $f1
    /* EE9E4 001EE9E4 C004A0C7 */  lwc1       $f0, 0x4C0($29)
    /* EE9E8 001EE9E8 82000146 */  mul.s      $f2, $f0, $f1
    /* EE9EC 001EE9EC C004A2E7 */  swc1       $f2, 0x4C0($29)
    /* EE9F0 001EE9F0 C404A0C7 */  lwc1       $f0, 0x4C4($29)
    /* EE9F4 001EE9F4 42000146 */  mul.s      $f1, $f0, $f1
    /* EE9F8 001EE9F8 C404A1E7 */  swc1       $f1, 0x4C4($29)
    /* EE9FC 001EE9FC 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* EEA00 001EEA00 00100046 */  add.s      $f0, $f2, $f0
    /* EEA04 001EEA04 C004A0E7 */  swc1       $f0, 0x4C0($29)
    /* EEA08 001EEA08 00081446 */  add.s      $f0, $f1, $f20
    /* EEA0C 001EEA0C C404A0E7 */  swc1       $f0, 0x4C4($29)
    /* EEA10 001EEA10 C004A1C7 */  lwc1       $f1, 0x4C0($29)
    /* EEA14 001EEA14 C404A0C7 */  lwc1       $f0, 0x4C4($29)
    /* EEA18 001EEA18 9004A1E7 */  swc1       $f1, 0x490($29)
    /* EEA1C 001EEA1C 9404A0E7 */  swc1       $f0, 0x494($29)
    /* EEA20 001EEA20 05000010 */  b          .L001EEA38
    /* EEA24 001EEA24 00000000 */   nop
  .L001EEA28:
    /* EEA28 001EEA28 F8FF01C6 */  lwc1       $f1, -0x8($16)
    /* EEA2C 001EEA2C FCFF00C6 */  lwc1       $f0, -0x4($16)
    /* EEA30 001EEA30 9004A1E7 */  swc1       $f1, 0x490($29)
    /* EEA34 001EEA34 9404A0E7 */  swc1       $f0, 0x494($29)
  .L001EEA38:
    /* EEA38 001EEA38 FEFF6226 */  addiu      $2, $19, -0x2
    /* EEA3C 001EEA3C 1F004104 */  bgez       $2, .L001EEABC
    /* EEA40 001EEA40 00000000 */   nop
    /* EEA44 001EEA44 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* EEA48 001EEA48 8804A0C7 */  lwc1       $f0, 0x488($29)
    /* EEA4C 001EEA4C 01080046 */  sub.s      $f0, $f1, $f0
    /* EEA50 001EEA50 C004A0E7 */  swc1       $f0, 0x4C0($29)
    /* EEA54 001EEA54 8C04A0C7 */  lwc1       $f0, 0x48C($29)
    /* EEA58 001EEA58 01A00046 */  sub.s      $f0, $f20, $f0
    /* EEA5C 001EEA5C C404A0E7 */  swc1       $f0, 0x4C4($29)
    /* EEA60 001EEA60 C004A427 */  addiu      $4, $29, 0x4C0
    /* EEA64 001EEA64 2D288000 */  daddu      $5, $4, $0
    /* EEA68 001EEA68 78900F0C */  jal        func_003e41e0
    /* EEA6C 001EEA6C 00000000 */   nop
    /* EEA70 001EEA70 FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* EEA74 001EEA74 00088244 */  mtc1       $2, $f1
    /* EEA78 001EEA78 C004A0C7 */  lwc1       $f0, 0x4C0($29)
    /* EEA7C 001EEA7C 82000146 */  mul.s      $f2, $f0, $f1
    /* EEA80 001EEA80 C004A2E7 */  swc1       $f2, 0x4C0($29)
    /* EEA84 001EEA84 C404A0C7 */  lwc1       $f0, 0x4C4($29)
    /* EEA88 001EEA88 42000146 */  mul.s      $f1, $f0, $f1
    /* EEA8C 001EEA8C C404A1E7 */  swc1       $f1, 0x4C4($29)
    /* EEA90 001EEA90 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* EEA94 001EEA94 00100046 */  add.s      $f0, $f2, $f0
    /* EEA98 001EEA98 C004A0E7 */  swc1       $f0, 0x4C0($29)
    /* EEA9C 001EEA9C 00081446 */  add.s      $f0, $f1, $f20
    /* EEAA0 001EEAA0 C404A0E7 */  swc1       $f0, 0x4C4($29)
    /* EEAA4 001EEAA4 C004A1C7 */  lwc1       $f1, 0x4C0($29)
    /* EEAA8 001EEAA8 C404A0C7 */  lwc1       $f0, 0x4C4($29)
    /* EEAAC 001EEAAC 9804A1E7 */  swc1       $f1, 0x498($29)
    /* EEAB0 001EEAB0 9C04A0E7 */  swc1       $f0, 0x49C($29)
    /* EEAB4 001EEAB4 05000010 */  b          .L001EEACC
    /* EEAB8 001EEAB8 00000000 */   nop
  .L001EEABC:
    /* EEABC 001EEABC F0FF01C6 */  lwc1       $f1, -0x10($16)
    /* EEAC0 001EEAC0 F4FF00C6 */  lwc1       $f0, -0xC($16)
    /* EEAC4 001EEAC4 9804A1E7 */  swc1       $f1, 0x498($29)
    /* EEAC8 001EEAC8 9C04A0E7 */  swc1       $f0, 0x49C($29)
  .L001EEACC:
    /* EEACC 001EEACC C0101100 */  sll        $2, $17, 3
    /* EEAD0 001EEAD0 21188202 */  addu       $3, $20, $2
    /* EEAD4 001EEAD4 000001C6 */  lwc1       $f1, 0x0($16)
    /* EEAD8 001EEAD8 040000C6 */  lwc1       $f0, 0x4($16)
    /* EEADC 001EEADC 000061E4 */  swc1       $f1, 0x0($3)
    /* EEAE0 001EEAE0 040060E4 */  swc1       $f0, 0x4($3)
    /* EEAE4 001EEAE4 8804ADC7 */  lwc1       $f13, 0x488($29)
    /* EEAE8 001EEAE8 9004ACC7 */  lwc1       $f12, 0x490($29)
    /* EEAEC 001EEAEC 9804ABC7 */  lwc1       $f11, 0x498($29)
    /* EEAF0 001EEAF0 C0BC023C */  lui        $2, (0xBCC00000 >> 16)
    /* EEAF4 001EEAF4 00508244 */  mtc1       $2, $f10
    /* EEAF8 001EEAF8 683E023C */  lui        $2, (0x3E680000 >> 16)
    /* EEAFC 001EEAFC 00088244 */  mtc1       $2, $f1
    /* EEB00 001EEB00 90BD023C */  lui        $2, (0xBD900000 >> 16)
    /* EEB04 001EEB04 00488244 */  mtc1       $2, $f9
    /* EEB08 001EEB08 8004A8C7 */  lwc1       $f8, 0x480($29)
    /* EEB0C 001EEB0C 5E3F023C */  lui        $2, (0x3F5E0000 >> 16)
    /* EEB10 001EEB10 00388244 */  mtc1       $2, $f7
    /* EEB14 001EEB14 00000000 */  nop
    /* EEB18 001EEB18 1A380D46 */  mula.s     $f7, $f13
    /* EEB1C 001EEB1C 1E480846 */  madda.s    $f9, $f8
    /* EEB20 001EEB20 1E080C46 */  madda.s    $f1, $f12
    /* EEB24 001EEB24 1C500B46 */  madd.s     $f0, $f10, $f11
    /* EEB28 001EEB28 D004A0E7 */  swc1       $f0, 0x4D0($29)
    /* EEB2C 001EEB2C 8C04A6C7 */  lwc1       $f6, 0x48C($29)
    /* EEB30 001EEB30 8404A5C7 */  lwc1       $f5, 0x484($29)
    /* EEB34 001EEB34 9404A4C7 */  lwc1       $f4, 0x494($29)
    /* EEB38 001EEB38 9C04A3C7 */  lwc1       $f3, 0x49C($29)
    /* EEB3C 001EEB3C 1A380646 */  mula.s     $f7, $f6
    /* EEB40 001EEB40 1E480546 */  madda.s    $f9, $f5
    /* EEB44 001EEB44 1E080446 */  madda.s    $f1, $f4
    /* EEB48 001EEB48 1C500346 */  madd.s     $f0, $f10, $f3
    /* EEB4C 001EEB4C D404A0E7 */  swc1       $f0, 0x4D4($29)
    /* EEB50 001EEB50 D004A1C7 */  lwc1       $f1, 0x4D0($29)
    /* EEB54 001EEB54 D404A0C7 */  lwc1       $f0, 0x4D4($29)
    /* EEB58 001EEB58 080061E4 */  swc1       $f1, 0x8($3)
    /* EEB5C 001EEB5C 0C0060E4 */  swc1       $f0, 0xC($3)
    /* EEB60 001EEB60 80BD023C */  lui        $2, (0xBD800000 >> 16)
    /* EEB64 001EEB64 00108244 */  mtc1       $2, $f2
    /* EEB68 001EEB68 103F023C */  lui        $2, (0x3F100000 >> 16)
    /* EEB6C 001EEB6C 00088244 */  mtc1       $2, $f1
    /* EEB70 001EEB70 00000000 */  nop
    /* EEB74 001EEB74 1A080D46 */  mula.s     $f1, $f13
    /* EEB78 001EEB78 1E100846 */  madda.s    $f2, $f8
    /* EEB7C 001EEB7C 1E080C46 */  madda.s    $f1, $f12
    /* EEB80 001EEB80 1C100B46 */  madd.s     $f0, $f2, $f11
    /* EEB84 001EEB84 D004A0E7 */  swc1       $f0, 0x4D0($29)
    /* EEB88 001EEB88 1A080646 */  mula.s     $f1, $f6
    /* EEB8C 001EEB8C 1E100546 */  madda.s    $f2, $f5
    /* EEB90 001EEB90 1E080446 */  madda.s    $f1, $f4
    /* EEB94 001EEB94 1C100346 */  madd.s     $f0, $f2, $f3
    /* EEB98 001EEB98 D404A0E7 */  swc1       $f0, 0x4D4($29)
    /* EEB9C 001EEB9C D004A1C7 */  lwc1       $f1, 0x4D0($29)
    /* EEBA0 001EEBA0 D404A0C7 */  lwc1       $f0, 0x4D4($29)
    /* EEBA4 001EEBA4 100061E4 */  swc1       $f1, 0x10($3)
    /* EEBA8 001EEBA8 140060E4 */  swc1       $f0, 0x14($3)
    /* EEBAC 001EEBAC 3C8381C7 */  lwc1       $f1, -0x7CC4($28)
    /* EEBB0 001EEBB0 1A080D46 */  mula.s     $f1, $f13
    /* EEBB4 001EEBB4 1E500846 */  madda.s    $f10, $f8
    /* EEBB8 001EEBB8 1E380C46 */  madda.s    $f7, $f12
    /* EEBBC 001EEBBC 1C480B46 */  madd.s     $f0, $f9, $f11
    /* EEBC0 001EEBC0 D004A0E7 */  swc1       $f0, 0x4D0($29)
    /* EEBC4 001EEBC4 1A080646 */  mula.s     $f1, $f6
    /* EEBC8 001EEBC8 1E500546 */  madda.s    $f10, $f5
    /* EEBCC 001EEBCC 1E380446 */  madda.s    $f7, $f4
    /* EEBD0 001EEBD0 1C480346 */  madd.s     $f0, $f9, $f3
    /* EEBD4 001EEBD4 D404A0E7 */  swc1       $f0, 0x4D4($29)
    /* EEBD8 001EEBD8 D004A1C7 */  lwc1       $f1, 0x4D0($29)
    /* EEBDC 001EEBDC D404A0C7 */  lwc1       $f0, 0x4D4($29)
    /* EEBE0 001EEBE0 180061E4 */  swc1       $f1, 0x18($3)
    /* EEBE4 001EEBE4 1C0060E4 */  swc1       $f0, 0x1C($3)
    /* EEBE8 001EEBE8 04003126 */  addiu      $17, $17, 0x4
    /* EEBEC 001EEBEC FFFF7326 */  addiu      $19, $19, -0x1
    /* EEBF0 001EEBF0 54FF601E */  bgtz       $19, .L001EE944
    /* EEBF4 001EEBF4 00000000 */   nop
    /* EEBF8 001EEBF8 C0101100 */  sll        $2, $17, 3
    /* EEBFC 001EEBFC 21108202 */  addu       $2, $20, $2
    /* EEC00 001EEC00 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* EEC04 001EEC04 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* EEC08 001EEC08 000041E4 */  swc1       $f1, 0x0($2)
    /* EEC0C 001EEC0C 040040E4 */  swc1       $f0, 0x4($2)
    /* EEC10 001EEC10 01002226 */  addiu      $2, $17, 0x1
    /* EEC14 001EEC14 000482A6 */  sh         $2, 0x400($20)
  .L001EEC18:
    /* EEC18 001EEC18 01000224 */  addiu      $2, $0, 0x1
  .L001EEC1C:
    /* EEC1C 001EEC1C 7000BFDF */  ld         $31, 0x70($29)
    /* EEC20 001EEC20 6000B57B */  lq         $21, 0x60($29)
    /* EEC24 001EEC24 5000B47B */  lq         $20, 0x50($29)
    /* EEC28 001EEC28 4000B37B */  lq         $19, 0x40($29)
    /* EEC2C 001EEC2C 3000B27B */  lq         $18, 0x30($29)
    /* EEC30 001EEC30 2000B17B */  lq         $17, 0x20($29)
    /* EEC34 001EEC34 1000B07B */  lq         $16, 0x10($29)
    /* EEC38 001EEC38 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* EEC3C 001EEC3C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* EEC40 001EEC40 E004BD27 */  addiu      $29, $29, 0x4E0
    /* EEC44 001EEC44 0800E003 */  jr         $31
    /* EEC48 001EEC48 00000000 */   nop
    /* EEC4C 001EEC4C 00000000 */  nop
.size func_001ee610, 0x640
