.section .text
.set noat
.set noreorder
glabel func_001bf5e0
    /* BF5E0 001BF5E0 D0FEBD27 */  addiu      $29, $29, -0x130
    /* BF5E4 001BF5E4 4000BFFF */  sd         $31, 0x40($29)
    /* BF5E8 001BF5E8 3000B27F */  sq         $18, 0x30($29)
    /* BF5EC 001BF5EC 2000B17F */  sq         $17, 0x20($29)
    /* BF5F0 001BF5F0 1000B07F */  sq         $16, 0x10($29)
    /* BF5F4 001BF5F4 0400B5E7 */  swc1       $f21, 0x4($29)
    /* BF5F8 001BF5F8 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BF5FC 001BF5FC 2D888000 */  daddu      $17, $4, $0
    /* BF600 001BF600 E000828C */  lw         $2, 0xE0($4)
    /* BF604 001BF604 3000508C */  lw         $16, 0x30($2)
    /* BF608 001BF608 3800428C */  lw         $2, 0x38($2)
    /* BF60C 001BF60C 3000528C */  lw         $18, 0x30($2)
    /* BF610 001BF610 6000A427 */  addiu      $4, $29, 0x60
    /* BF614 001BF614 9C002526 */  addiu      $5, $17, 0x9C
    /* BF618 001BF618 58F5060C */  jal        func_001bd560
    /* BF61C 001BF61C 00000000 */   nop
    /* BF620 001BF620 2D200002 */  daddu      $4, $16, $0
    /* BF624 001BF624 F000A527 */  addiu      $5, $29, 0xF0
    /* BF628 001BF628 1456060C */  jal        func_00195850
    /* BF62C 001BF62C 00000000 */   nop
    /* BF630 001BF630 2D204002 */  daddu      $4, $18, $0
    /* BF634 001BF634 E000A527 */  addiu      $5, $29, 0xE0
    /* BF638 001BF638 1456060C */  jal        func_00195850
    /* BF63C 001BF63C 00000000 */   nop
    /* BF640 001BF640 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* BF644 001BF644 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* BF648 001BF648 C2080046 */  mul.s      $f3, $f1, $f0
    /* BF64C 001BF64C 3C8082C7 */  lwc1       $f2, -0x7FC4($28)
    /* BF650 001BF650 F400A1C7 */  lwc1       $f1, 0xF4($29)
    /* BF654 001BF654 00008044 */  mtc1       $0, $f0
    /* BF658 001BF658 00000000 */  nop
    /* BF65C 001BF65C 18000146 */  adda.s     $f0, $f1
    /* BF660 001BF660 5C100346 */  madd.s     $f1, $f2, $f3
    /* BF664 001BF664 F400A1E7 */  swc1       $f1, 0xF4($29)
    /* BF668 001BF668 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* BF66C 001BF66C 00008244 */  mtc1       $2, $f0
    /* BF670 001BF670 00000000 */  nop
    /* BF674 001BF674 34080046 */  c.lt.s     $f1, $f0
    /* BF678 001BF678 02000045 */  bc1f       .L001BF684
    /* BF67C 001BF67C 00000000 */   nop
    /* BF680 001BF680 F400A0E7 */  swc1       $f0, 0xF4($29)
  .L001BF684:
    /* BF684 001BF684 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* BF688 001BF688 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* BF68C 001BF68C 01080046 */  sub.s      $f0, $f1, $f0
    /* BF690 001BF690 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BF694 001BF694 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* BF698 001BF698 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* BF69C 001BF69C 01080046 */  sub.s      $f0, $f1, $f0
    /* BF6A0 001BF6A0 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BF6A4 001BF6A4 6800A1C7 */  lwc1       $f1, 0x68($29)
    /* BF6A8 001BF6A8 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* BF6AC 001BF6AC 01080046 */  sub.s      $f0, $f1, $f0
    /* BF6B0 001BF6B0 1801A0E7 */  swc1       $f0, 0x118($29)
    /* BF6B4 001BF6B4 1001A427 */  addiu      $4, $29, 0x110
    /* BF6B8 001BF6B8 60900F0C */  jal        func_003e4180
    /* BF6BC 001BF6BC 00000000 */   nop
    /* BF6C0 001BF6C0 FC8081C7 */  lwc1       $f1, -0x7F04($28)
    /* BF6C4 001BF6C4 42050146 */  mul.s      $f21, $f0, $f1
    /* BF6C8 001BF6C8 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* BF6CC 001BF6CC 5800A0E7 */  swc1       $f0, 0x58($29)
    /* BF6D0 001BF6D0 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* BF6D4 001BF6D4 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* BF6D8 001BF6D8 5800A427 */  addiu      $4, $29, 0x58
    /* BF6DC 001BF6DC 2D288000 */  daddu      $5, $4, $0
    /* BF6E0 001BF6E0 78900F0C */  jal        func_003e41e0
    /* BF6E4 001BF6E4 00000000 */   nop
    /* BF6E8 001BF6E8 F400A2C7 */  lwc1       $f2, 0xF4($29)
    /* BF6EC 001BF6EC E400A2E7 */  swc1       $f2, 0xE4($29)
    /* BF6F0 001BF6F0 E000A1C7 */  lwc1       $f1, 0xE0($29)
    /* BF6F4 001BF6F4 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* BF6F8 001BF6F8 01080046 */  sub.s      $f0, $f1, $f0
    /* BF6FC 001BF6FC 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BF700 001BF700 01100246 */  sub.s      $f0, $f2, $f2
    /* BF704 001BF704 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BF708 001BF708 E800A1C7 */  lwc1       $f1, 0xE8($29)
    /* BF70C 001BF70C F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* BF710 001BF710 01080046 */  sub.s      $f0, $f1, $f0
    /* BF714 001BF714 1801A0E7 */  swc1       $f0, 0x118($29)
    /* BF718 001BF718 1001A427 */  addiu      $4, $29, 0x110
    /* BF71C 001BF71C 2D288000 */  daddu      $5, $4, $0
    /* BF720 001BF720 2C900F0C */  jal        func_003e40b0
    /* BF724 001BF724 00000000 */   nop
    /* BF728 001BF728 1001A3C7 */  lwc1       $f3, 0x110($29)
    /* BF72C 001BF72C 5000A3E7 */  swc1       $f3, 0x50($29)
    /* BF730 001BF730 1801A2C7 */  lwc1       $f2, 0x118($29)
    /* BF734 001BF734 5400A2E7 */  swc1       $f2, 0x54($29)
    /* BF738 001BF738 5800A1C7 */  lwc1       $f1, 0x58($29)
    /* BF73C 001BF73C 5C00A0C7 */  lwc1       $f0, 0x5C($29)
    /* BF740 001BF740 1A100046 */  mula.s     $f2, $f0
    /* BF744 001BF744 00008044 */  mtc1       $0, $f0
    /* BF748 001BF748 00000000 */  nop
    /* BF74C 001BF74C 5C180146 */  madd.s     $f1, $f3, $f1
    /* BF750 001BF750 34080046 */  c.lt.s     $f1, $f0
    /* BF754 001BF754 08000045 */  bc1f       .L001BF778
    /* BF758 001BF758 00000000 */   nop
    /* BF75C 001BF75C 07180046 */  neg.s      $f0, $f3
    /* BF760 001BF760 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BF764 001BF764 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* BF768 001BF768 07000046 */  neg.s      $f0, $f0
    /* BF76C 001BF76C 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BF770 001BF770 07100046 */  neg.s      $f0, $f2
    /* BF774 001BF774 1801A0E7 */  swc1       $f0, 0x118($29)
  .L001BF778:
    /* BF778 001BF778 900001C6 */  lwc1       $f1, 0x90($16)
    /* BF77C 001BF77C 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* BF780 001BF780 420A0046 */  mul.s      $f9, $f1, $f0
    /* BF784 001BF784 1001A5C7 */  lwc1       $f5, 0x110($29)
    /* BF788 001BF788 02280946 */  mul.s      $f0, $f5, $f9
    /* BF78C 001BF78C 2001A0E7 */  swc1       $f0, 0x120($29)
    /* BF790 001BF790 1401A4C7 */  lwc1       $f4, 0x114($29)
    /* BF794 001BF794 82200946 */  mul.s      $f2, $f4, $f9
    /* BF798 001BF798 2401A2E7 */  swc1       $f2, 0x124($29)
    /* BF79C 001BF79C 1801A3C7 */  lwc1       $f3, 0x118($29)
    /* BF7A0 001BF7A0 42180946 */  mul.s      $f1, $f3, $f9
    /* BF7A4 001BF7A4 2801A1E7 */  swc1       $f1, 0x128($29)
    /* BF7A8 001BF7A8 F000A8C7 */  lwc1       $f8, 0xF0($29)
    /* BF7AC 001BF7AC 00400046 */  add.s      $f0, $f8, $f0
    /* BF7B0 001BF7B0 0001A0E7 */  swc1       $f0, 0x100($29)
    /* BF7B4 001BF7B4 F400A7C7 */  lwc1       $f7, 0xF4($29)
    /* BF7B8 001BF7B8 00380246 */  add.s      $f0, $f7, $f2
    /* BF7BC 001BF7BC 0401A0E7 */  swc1       $f0, 0x104($29)
    /* BF7C0 001BF7C0 F800A6C7 */  lwc1       $f6, 0xF8($29)
    /* BF7C4 001BF7C4 00300146 */  add.s      $f0, $f6, $f1
    /* BF7C8 001BF7C8 0801A0E7 */  swc1       $f0, 0x108($29)
    /* BF7CC 001BF7CC A040023C */  lui        $2, (0x40A00000 >> 16)
    /* BF7D0 001BF7D0 00008244 */  mtc1       $2, $f0
    /* BF7D4 001BF7D4 00000000 */  nop
    /* BF7D8 001BF7D8 42000946 */  mul.s      $f1, $f0, $f9
    /* BF7DC 001BF7DC 82280146 */  mul.s      $f2, $f5, $f1
    /* BF7E0 001BF7E0 1001A2E7 */  swc1       $f2, 0x110($29)
    /* BF7E4 001BF7E4 02200146 */  mul.s      $f0, $f4, $f1
    /* BF7E8 001BF7E8 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BF7EC 001BF7EC 42180146 */  mul.s      $f1, $f3, $f1
    /* BF7F0 001BF7F0 1801A1E7 */  swc1       $f1, 0x118($29)
    /* BF7F4 001BF7F4 40410246 */  add.s      $f5, $f8, $f2
    /* BF7F8 001BF7F8 2001A5E7 */  swc1       $f5, 0x120($29)
    /* BF7FC 001BF7FC 00380046 */  add.s      $f0, $f7, $f0
    /* BF800 001BF800 2401A0E7 */  swc1       $f0, 0x124($29)
    /* BF804 001BF804 00310146 */  add.s      $f4, $f6, $f1
    /* BF808 001BF808 2801A4E7 */  swc1       $f4, 0x128($29)
    /* BF80C 001BF80C 8C0041C6 */  lwc1       $f1, 0x8C($18)
    /* BF810 001BF810 2C0040C6 */  lwc1       $f0, 0x2C($18)
    /* BF814 001BF814 C2080046 */  mul.s      $f3, $f1, $f0
    /* BF818 001BF818 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BF81C 001BF81C 00108244 */  mtc1       $2, $f2
    /* BF820 001BF820 E400A1C7 */  lwc1       $f1, 0xE4($29)
    /* BF824 001BF824 00008044 */  mtc1       $0, $f0
    /* BF828 001BF828 00000000 */  nop
    /* BF82C 001BF82C 18000146 */  adda.s     $f0, $f1
    /* BF830 001BF830 5C100346 */  madd.s     $f1, $f2, $f3
    /* BF834 001BF834 2401A1E7 */  swc1       $f1, 0x124($29)
    /* BF838 001BF838 01280846 */  sub.s      $f0, $f5, $f8
    /* BF83C 001BF83C 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BF840 001BF840 01080746 */  sub.s      $f0, $f1, $f7
    /* BF844 001BF844 1401A0E7 */  swc1       $f0, 0x114($29)
    /* BF848 001BF848 01200646 */  sub.s      $f0, $f4, $f6
    /* BF84C 001BF84C 1801A0E7 */  swc1       $f0, 0x118($29)
    /* BF850 001BF850 1001A427 */  addiu      $4, $29, 0x110
    /* BF854 001BF854 2D288000 */  daddu      $5, $4, $0
    /* BF858 001BF858 2C900F0C */  jal        func_003e40b0
    /* BF85C 001BF85C 00000000 */   nop
    /* BF860 001BF860 8800A427 */  addiu      $4, $29, 0x88
    /* BF864 001BF864 2001A527 */  addiu      $5, $29, 0x120
    /* BF868 001BF868 0001A627 */  addiu      $6, $29, 0x100
    /* BF86C 001BF86C 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BF870 001BF870 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BF874 001BF874 E0F5060C */  jal        func_001bd780
    /* BF878 001BF878 00000000 */   nop
    /* BF87C 001BF87C 6C00A427 */  addiu      $4, $29, 0x6C
    /* BF880 001BF880 8800A527 */  addiu      $5, $29, 0x88
    /* BF884 001BF884 ACB0070C */  jal        func_001ec2b0
    /* BF888 001BF888 00000000 */   nop
    /* BF88C 001BF88C 588181C7 */  lwc1       $f1, -0x7EA8($28)
    /* BF890 001BF890 36000146 */  c.le.s     $f0, $f1
    /* BF894 001BF894 87000145 */  bc1t       .L001BFAB4
    /* BF898 001BF898 00000000 */   nop
    /* BF89C 001BF89C 00000000 */  nop
    /* BF8A0 001BF8A0 00000000 */  nop
    /* BF8A4 001BF8A4 030D0046 */  div.s      $f20, $f1, $f0
    /* BF8A8 001BF8A8 6C00A427 */  addiu      $4, $29, 0x6C
    /* BF8AC 001BF8AC 8800A527 */  addiu      $5, $29, 0x88
    /* BF8B0 001BF8B0 A000A627 */  addiu      $6, $29, 0xA0
    /* BF8B4 001BF8B4 1C730F0C */  jal        func_003dcc70
    /* BF8B8 001BF8B8 00000000 */   nop
    /* BF8BC 001BF8BC 00588044 */  mtc1       $0, $f11
    /* BF8C0 001BF8C0 00000000 */  nop
    /* BF8C4 001BF8C4 36A00B46 */  c.le.s     $f20, $f11
    /* BF8C8 001BF8C8 0B000045 */  bc1f       .L001BF8F8
    /* BF8CC 001BF8CC 00000000 */   nop
    /* BF8D0 001BF8D0 6C00A3C7 */  lwc1       $f3, 0x6C($29)
    /* BF8D4 001BF8D4 7000A2C7 */  lwc1       $f2, 0x70($29)
    /* BF8D8 001BF8D8 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* BF8DC 001BF8DC 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* BF8E0 001BF8E0 D000A3E7 */  swc1       $f3, 0xD0($29)
    /* BF8E4 001BF8E4 D400A2E7 */  swc1       $f2, 0xD4($29)
    /* BF8E8 001BF8E8 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* BF8EC 001BF8EC DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* BF8F0 001BF8F0 56000010 */  b          .L001BFA4C
    /* BF8F4 001BF8F4 00000000 */   nop
  .L001BF8F8:
    /* BF8F8 001BF8F8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BF8FC 001BF8FC 00008244 */  mtc1       $2, $f0
    /* BF900 001BF900 00000000 */  nop
    /* BF904 001BF904 36001446 */  c.le.s     $f0, $f20
    /* BF908 001BF908 0B000045 */  bc1f       .L001BF938
    /* BF90C 001BF90C 00000000 */   nop
    /* BF910 001BF910 8800A3C7 */  lwc1       $f3, 0x88($29)
    /* BF914 001BF914 8C00A2C7 */  lwc1       $f2, 0x8C($29)
    /* BF918 001BF918 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* BF91C 001BF91C 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* BF920 001BF920 D000A3E7 */  swc1       $f3, 0xD0($29)
    /* BF924 001BF924 D400A2E7 */  swc1       $f2, 0xD4($29)
    /* BF928 001BF928 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* BF92C 001BF92C DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* BF930 001BF930 46000010 */  b          .L001BFA4C
    /* BF934 001BF934 00000000 */   nop
  .L001BF938:
    /* BF938 001BF938 01001446 */  sub.s      $f0, $f0, $f20
    /* BF93C 001BF93C C400A28F */  lw         $2, 0xC4($29)
    /* BF940 001BF940 26004014 */  bnez       $2, .L001BF9DC
    /* BF944 001BF944 00000000 */   nop
    /* BF948 001BF948 C000AAC7 */  lwc1       $f10, 0xC0($29)
    /* BF94C 001BF94C 02010A46 */  mul.s      $f4, $f0, $f10
    /* BF950 001BF950 C2200446 */  mul.s      $f3, $f4, $f4
    /* BF954 001BF954 048189C7 */  lwc1       $f9, -0x7EFC($28)
    /* BF958 001BF958 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* BF95C 001BF95C 18580846 */  adda.s     $f11, $f8
    /* BF960 001BF960 1C480346 */  madd.s     $f0, $f9, $f3
    /* BF964 001BF964 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* BF968 001BF968 18580746 */  adda.s     $f11, $f7
    /* BF96C 001BF96C 1C180046 */  madd.s     $f0, $f3, $f0
    /* BF970 001BF970 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* BF974 001BF974 18580646 */  adda.s     $f11, $f6
    /* BF978 001BF978 1C180046 */  madd.s     $f0, $f3, $f0
    /* BF97C 001BF97C 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* BF980 001BF980 18580546 */  adda.s     $f11, $f5
    /* BF984 001BF984 1C180046 */  madd.s     $f0, $f3, $f0
    /* BF988 001BF988 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* BF98C 001BF98C 18580246 */  adda.s     $f11, $f2
    /* BF990 001BF990 5C180046 */  madd.s     $f1, $f3, $f0
    /* BF994 001BF994 02180446 */  mul.s      $f0, $f3, $f4
    /* BF998 001BF998 18580446 */  adda.s     $f11, $f4
    /* BF99C 001BF99C 1C000146 */  madd.s     $f0, $f0, $f1
    /* BF9A0 001BF9A0 02A10A46 */  mul.s      $f4, $f20, $f10
    /* BF9A4 001BF9A4 C2200446 */  mul.s      $f3, $f4, $f4
    /* BF9A8 001BF9A8 18580846 */  adda.s     $f11, $f8
    /* BF9AC 001BF9AC 5C480346 */  madd.s     $f1, $f9, $f3
    /* BF9B0 001BF9B0 18580746 */  adda.s     $f11, $f7
    /* BF9B4 001BF9B4 5C180146 */  madd.s     $f1, $f3, $f1
    /* BF9B8 001BF9B8 18580646 */  adda.s     $f11, $f6
    /* BF9BC 001BF9BC 5C180146 */  madd.s     $f1, $f3, $f1
    /* BF9C0 001BF9C0 18580546 */  adda.s     $f11, $f5
    /* BF9C4 001BF9C4 5C180146 */  madd.s     $f1, $f3, $f1
    /* BF9C8 001BF9C8 18580246 */  adda.s     $f11, $f2
    /* BF9CC 001BF9CC 9C180146 */  madd.s     $f2, $f3, $f1
    /* BF9D0 001BF9D0 42180446 */  mul.s      $f1, $f3, $f4
    /* BF9D4 001BF9D4 18580446 */  adda.s     $f11, $f4
    /* BF9D8 001BF9D8 1C0D0246 */  madd.s     $f20, $f1, $f2
  .L001BF9DC:
    /* BF9DC 001BF9DC A000A1C7 */  lwc1       $f1, 0xA0($29)
    /* BF9E0 001BF9E0 42090046 */  mul.s      $f5, $f1, $f0
    /* BF9E4 001BF9E4 D000A5E7 */  swc1       $f5, 0xD0($29)
    /* BF9E8 001BF9E8 A400A1C7 */  lwc1       $f1, 0xA4($29)
    /* BF9EC 001BF9EC 02090046 */  mul.s      $f4, $f1, $f0
    /* BF9F0 001BF9F0 D400A4E7 */  swc1       $f4, 0xD4($29)
    /* BF9F4 001BF9F4 A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* BF9F8 001BF9F8 C2080046 */  mul.s      $f3, $f1, $f0
    /* BF9FC 001BF9FC D800A3E7 */  swc1       $f3, 0xD8($29)
    /* BFA00 001BFA00 B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* BFA04 001BFA04 00108044 */  mtc1       $0, $f2
    /* BFA08 001BFA08 00000000 */  nop
    /* BFA0C 001BFA0C 18100546 */  adda.s     $f2, $f5
    /* BFA10 001BFA10 5C081446 */  madd.s     $f1, $f1, $f20
    /* BFA14 001BFA14 D000A1E7 */  swc1       $f1, 0xD0($29)
    /* BFA18 001BFA18 B400A1C7 */  lwc1       $f1, 0xB4($29)
    /* BFA1C 001BFA1C 18100446 */  adda.s     $f2, $f4
    /* BFA20 001BFA20 5C081446 */  madd.s     $f1, $f1, $f20
    /* BFA24 001BFA24 D400A1E7 */  swc1       $f1, 0xD4($29)
    /* BFA28 001BFA28 B800A1C7 */  lwc1       $f1, 0xB8($29)
    /* BFA2C 001BFA2C 18100346 */  adda.s     $f2, $f3
    /* BFA30 001BFA30 5C081446 */  madd.s     $f1, $f1, $f20
    /* BFA34 001BFA34 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* BFA38 001BFA38 AC00A2C7 */  lwc1       $f2, 0xAC($29)
    /* BFA3C 001BFA3C BC00A1C7 */  lwc1       $f1, 0xBC($29)
    /* BFA40 001BFA40 1A081446 */  mula.s     $f1, $f20
    /* BFA44 001BFA44 1C100046 */  madd.s     $f0, $f2, $f0
    /* BFA48 001BFA48 DC00A0E7 */  swc1       $f0, 0xDC($29)
  .L001BFA4C:
    /* BFA4C 001BFA4C 1001A427 */  addiu      $4, $29, 0x110
    /* BFA50 001BFA50 6100053C */  lui        $5, %hi(D_0060A100)
    /* BFA54 001BFA54 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* BFA58 001BFA58 01000624 */  addiu      $6, $0, 0x1
    /* BFA5C 001BFA5C D000A727 */  addiu      $7, $29, 0xD0
    /* BFA60 001BFA60 D0720F0C */  jal        func_003dcb40
    /* BFA64 001BFA64 00000000 */   nop
    /* BFA68 001BFA68 0001A1C7 */  lwc1       $f1, 0x100($29)
    /* BFA6C 001BFA6C 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* BFA70 001BFA70 00080046 */  add.s      $f0, $f1, $f0
    /* BFA74 001BFA74 2001A0E7 */  swc1       $f0, 0x120($29)
    /* BFA78 001BFA78 0401A1C7 */  lwc1       $f1, 0x104($29)
    /* BFA7C 001BFA7C 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* BFA80 001BFA80 00080046 */  add.s      $f0, $f1, $f0
    /* BFA84 001BFA84 2401A0E7 */  swc1       $f0, 0x124($29)
    /* BFA88 001BFA88 0801A1C7 */  lwc1       $f1, 0x108($29)
    /* BFA8C 001BFA8C 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* BFA90 001BFA90 00080046 */  add.s      $f0, $f1, $f0
    /* BFA94 001BFA94 2801A0E7 */  swc1       $f0, 0x128($29)
    /* BFA98 001BFA98 8800A427 */  addiu      $4, $29, 0x88
    /* BFA9C 001BFA9C 2001A527 */  addiu      $5, $29, 0x120
    /* BFAA0 001BFAA0 0001A627 */  addiu      $6, $29, 0x100
    /* BFAA4 001BFAA4 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BFAA8 001BFAA8 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BFAAC 001BFAAC E0F5060C */  jal        func_001bd780
    /* BFAB0 001BFAB0 00000000 */   nop
  .L001BFAB4:
    /* BFAB4 001BFAB4 1644023C */  lui        $2, (0x44160000 >> 16)
    /* BFAB8 001BFAB8 00008244 */  mtc1       $2, $f0
    /* BFABC 001BFABC 00000000 */  nop
    /* BFAC0 001BFAC0 34A80046 */  c.lt.s     $f21, $f0
    /* BFAC4 001BFAC4 02000045 */  bc1f       .L001BFAD0
    /* BFAC8 001BFAC8 00000000 */   nop
    /* BFACC 001BFACC 46050046 */  mov.s      $f21, $f0
  .L001BFAD0:
    /* BFAD0 001BFAD0 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* BFAD4 001BFAD4 C2001546 */  mul.s      $f3, $f0, $f21
    /* BFAD8 001BFAD8 1001A3E7 */  swc1       $f3, 0x110($29)
    /* BFADC 001BFADC 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* BFAE0 001BFAE0 82001546 */  mul.s      $f2, $f0, $f21
    /* BFAE4 001BFAE4 1401A2E7 */  swc1       $f2, 0x114($29)
    /* BFAE8 001BFAE8 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* BFAEC 001BFAEC 42001546 */  mul.s      $f1, $f0, $f21
    /* BFAF0 001BFAF0 1801A1E7 */  swc1       $f1, 0x118($29)
    /* BFAF4 001BFAF4 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BFAF8 001BFAF8 00000346 */  add.s      $f0, $f0, $f3
    /* BFAFC 001BFAFC 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* BFB00 001BFB00 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* BFB04 001BFB04 00000246 */  add.s      $f0, $f0, $f2
    /* BFB08 001BFB08 8000A0E7 */  swc1       $f0, 0x80($29)
    /* BFB0C 001BFB0C 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* BFB10 001BFB10 00000146 */  add.s      $f0, $f0, $f1
    /* BFB14 001BFB14 8400A0E7 */  swc1       $f0, 0x84($29)
    /* BFB18 001BFB18 2D202002 */  daddu      $4, $17, $0
    /* BFB1C 001BFB1C 6000A527 */  addiu      $5, $29, 0x60
    /* BFB20 001BFB20 7C00A627 */  addiu      $6, $29, 0x7C
    /* BFB24 001BFB24 01000724 */  addiu      $7, $0, 0x1
    /* BFB28 001BFB28 08EB060C */  jal        func_001bac20
    /* BFB2C 001BFB2C 00000000 */   nop
    /* BFB30 001BFB30 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BFB34 001BFB34 00608244 */  mtc1       $2, $f12
    /* BFB38 001BFB38 2D202002 */  daddu      $4, $17, $0
    /* BFB3C 001BFB3C BCEF060C */  jal        func_001bbef0
    /* BFB40 001BFB40 00000000 */   nop
    /* BFB44 001BFB44 4000BFDF */  ld         $31, 0x40($29)
    /* BFB48 001BFB48 3000B27B */  lq         $18, 0x30($29)
    /* BFB4C 001BFB4C 2000B17B */  lq         $17, 0x20($29)
    /* BFB50 001BFB50 1000B07B */  lq         $16, 0x10($29)
    /* BFB54 001BFB54 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* BFB58 001BFB58 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* BFB5C 001BFB5C 3001BD27 */  addiu      $29, $29, 0x130
    /* BFB60 001BFB60 0800E003 */  jr         $31
    /* BFB64 001BFB64 00000000 */   nop
    /* BFB68 001BFB68 00000000 */  nop
    /* BFB6C 001BFB6C 00000000 */  nop
.size func_001bf5e0, 0x590
