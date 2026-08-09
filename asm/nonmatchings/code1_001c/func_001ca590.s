.section .text
.set noat
.set noreorder
glabel func_001ca590
    /* CA590 001CA590 60FEBD27 */  addiu      $29, $29, -0x1A0
    /* CA594 001CA594 5000BFFF */  sd         $31, 0x50($29)
    /* CA598 001CA598 4000B27F */  sq         $18, 0x40($29)
    /* CA59C 001CA59C 3000B17F */  sq         $17, 0x30($29)
    /* CA5A0 001CA5A0 2000B07F */  sq         $16, 0x20($29)
    /* CA5A4 001CA5A4 1000B8E7 */  swc1       $f24, 0x10($29)
    /* CA5A8 001CA5A8 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* CA5AC 001CA5AC 0800B6E7 */  swc1       $f22, 0x8($29)
    /* CA5B0 001CA5B0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CA5B4 001CA5B4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CA5B8 001CA5B8 2D908000 */  daddu      $18, $4, $0
    /* CA5BC 001CA5BC C6650046 */  mov.s      $f23, $f12
    /* CA5C0 001CA5C0 066E0046 */  mov.s      $f24, $f13
    /* CA5C4 001CA5C4 E000828C */  lw         $2, 0xE0($4)
    /* CA5C8 001CA5C8 3000508C */  lw         $16, 0x30($2)
    /* CA5CC 001CA5CC 3800428C */  lw         $2, 0x38($2)
    /* CA5D0 001CA5D0 3000518C */  lw         $17, 0x30($2)
    /* CA5D4 001CA5D4 6000A427 */  addiu      $4, $29, 0x60
    /* CA5D8 001CA5D8 9C004526 */  addiu      $5, $18, 0x9C
    /* CA5DC 001CA5DC 58F5060C */  jal        func_001bd560
    /* CA5E0 001CA5E0 00000000 */   nop
    /* CA5E4 001CA5E4 DC0000C6 */  lwc1       $f0, 0xDC($16)
    /* CA5E8 001CA5E8 2801A0E7 */  swc1       $f0, 0x128($29)
    /* CA5EC 001CA5EC 840001C6 */  lwc1       $f1, 0x84($16)
    /* CA5F0 001CA5F0 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CA5F4 001CA5F4 02080046 */  mul.s      $f0, $f1, $f0
    /* CA5F8 001CA5F8 2C01A0E7 */  swc1       $f0, 0x12C($29)
    /* CA5FC 001CA5FC E40000C6 */  lwc1       $f0, 0xE4($16)
    /* CA600 001CA600 3001A0E7 */  swc1       $f0, 0x130($29)
    /* CA604 001CA604 2D202002 */  daddu      $4, $17, $0
    /* CA608 001CA608 1801A527 */  addiu      $5, $29, 0x118
    /* CA60C 001CA60C 1456060C */  jal        func_00195850
    /* CA610 001CA610 00000000 */   nop
    /* CA614 001CA614 2C0006C6 */  lwc1       $f6, 0x2C($16)
    /* CA618 001CA618 8C0000C6 */  lwc1       $f0, 0x8C($16)
    /* CA61C 001CA61C 42000646 */  mul.s      $f1, $f0, $f6
    /* CA620 001CA620 188185C7 */  lwc1       $f5, -0x7EE8($28)
    /* CA624 001CA624 2C01A0C7 */  lwc1       $f0, 0x12C($29)
    /* CA628 001CA628 00188044 */  mtc1       $0, $f3
    /* CA62C 001CA62C 00000000 */  nop
    /* CA630 001CA630 18180046 */  adda.s     $f3, $f0
    /* CA634 001CA634 1C290146 */  madd.s     $f4, $f5, $f1
    /* CA638 001CA638 2C0022C6 */  lwc1       $f2, 0x2C($17)
    /* CA63C 001CA63C 8C0020C6 */  lwc1       $f0, 0x8C($17)
    /* CA640 001CA640 42000246 */  mul.s      $f1, $f0, $f2
    /* CA644 001CA644 1C01A0C7 */  lwc1       $f0, 0x11C($29)
    /* CA648 001CA648 18180046 */  adda.s     $f3, $f0
    /* CA64C 001CA64C 1C280146 */  madd.s     $f0, $f5, $f1
    /* CA650 001CA650 00250046 */  add.s      $f20, $f4, $f0
    /* CA654 001CA654 E80001C6 */  lwc1       $f1, 0xE8($16)
    /* CA658 001CA658 900000C6 */  lwc1       $f0, 0x90($16)
    /* CA65C 001CA65C 18180146 */  adda.s     $f3, $f1
    /* CA660 001CA660 1E000646 */  madda.s    $f0, $f6
    /* CA664 001CA664 900020C6 */  lwc1       $f0, 0x90($17)
    /* CA668 001CA668 9C050246 */  madd.s     $f22, $f0, $f2
    /* CA66C 001CA66C 1C01A0AF */  sw         $0, 0x11C($29)
    /* CA670 001CA670 2C01A0AF */  sw         $0, 0x12C($29)
    /* CA674 001CA674 DC0001C6 */  lwc1       $f1, 0xDC($16)
    /* CA678 001CA678 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* CA67C 001CA67C 01080046 */  sub.s      $f0, $f1, $f0
    /* CA680 001CA680 6801A0E7 */  swc1       $f0, 0x168($29)
    /* CA684 001CA684 E00000C6 */  lwc1       $f0, 0xE0($16)
    /* CA688 001CA688 01000346 */  sub.s      $f0, $f0, $f3
    /* CA68C 001CA68C 6C01A0E7 */  swc1       $f0, 0x16C($29)
    /* CA690 001CA690 E40001C6 */  lwc1       $f1, 0xE4($16)
    /* CA694 001CA694 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CA698 001CA698 01080046 */  sub.s      $f0, $f1, $f0
    /* CA69C 001CA69C 7001A0E7 */  swc1       $f0, 0x170($29)
    /* CA6A0 001CA6A0 6801A427 */  addiu      $4, $29, 0x168
    /* CA6A4 001CA6A4 2D288000 */  daddu      $5, $4, $0
    /* CA6A8 001CA6A8 2C900F0C */  jal        func_003e40b0
    /* CA6AC 001CA6AC 00000000 */   nop
    /* CA6B0 001CA6B0 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CA6B4 001CA6B4 00008244 */  mtc1       $2, $f0
    /* CA6B8 001CA6B8 00000000 */  nop
    /* CA6BC 001CA6BC 42001646 */  mul.s      $f1, $f0, $f22
    /* CA6C0 001CA6C0 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* CA6C4 001CA6C4 C2000146 */  mul.s      $f3, $f0, $f1
    /* CA6C8 001CA6C8 4801A3E7 */  swc1       $f3, 0x148($29)
    /* CA6CC 001CA6CC 6C01A0C7 */  lwc1       $f0, 0x16C($29)
    /* CA6D0 001CA6D0 82000146 */  mul.s      $f2, $f0, $f1
    /* CA6D4 001CA6D4 4C01A2E7 */  swc1       $f2, 0x14C($29)
    /* CA6D8 001CA6D8 7001A0C7 */  lwc1       $f0, 0x170($29)
    /* CA6DC 001CA6DC 42000146 */  mul.s      $f1, $f0, $f1
    /* CA6E0 001CA6E0 5001A1E7 */  swc1       $f1, 0x150($29)
    /* CA6E4 001CA6E4 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* CA6E8 001CA6E8 00180046 */  add.s      $f0, $f3, $f0
    /* CA6EC 001CA6EC 4801A0E7 */  swc1       $f0, 0x148($29)
    /* CA6F0 001CA6F0 1C01A0C7 */  lwc1       $f0, 0x11C($29)
    /* CA6F4 001CA6F4 00100046 */  add.s      $f0, $f2, $f0
    /* CA6F8 001CA6F8 4C01A0E7 */  swc1       $f0, 0x14C($29)
    /* CA6FC 001CA6FC 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CA700 001CA700 00080046 */  add.s      $f0, $f1, $f0
    /* CA704 001CA704 5001A0E7 */  swc1       $f0, 0x150($29)
    /* CA708 001CA708 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CA70C 001CA70C 00088244 */  mtc1       $2, $f1
    /* CA710 001CA710 00000000 */  nop
    /* CA714 001CA714 420D1446 */  mul.s      $f21, $f1, $f20
    /* CA718 001CA718 4C01B5E7 */  swc1       $f21, 0x14C($29)
    /* CA71C 001CA71C E80000C6 */  lwc1       $f0, 0xE8($16)
    /* CA720 001CA720 02080046 */  mul.s      $f0, $f1, $f0
    /* CA724 001CA724 0C0140E6 */  swc1       $f0, 0x10C($18)
    /* CA728 001CA728 4801A2C7 */  lwc1       $f2, 0x148($29)
    /* CA72C 001CA72C 4C01A1C7 */  lwc1       $f1, 0x14C($29)
    /* CA730 001CA730 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CA734 001CA734 000142E6 */  swc1       $f2, 0x100($18)
    /* CA738 001CA738 040141E6 */  swc1       $f1, 0x104($18)
    /* CA73C 001CA73C 080140E6 */  swc1       $f0, 0x108($18)
    /* CA740 001CA740 7001A0C7 */  lwc1       $f0, 0x170($29)
    /* CA744 001CA744 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CA748 001CA748 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* CA74C 001CA74C 07000046 */  neg.s      $f0, $f0
    /* CA750 001CA750 0401A0E7 */  swc1       $f0, 0x104($29)
    /* CA754 001CA754 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* CA758 001CA758 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CA75C 001CA75C 01080046 */  sub.s      $f0, $f1, $f0
    /* CA760 001CA760 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CA764 001CA764 6800A1C7 */  lwc1       $f1, 0x68($29)
    /* CA768 001CA768 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CA76C 001CA76C 01080046 */  sub.s      $f0, $f1, $f0
    /* CA770 001CA770 0C01A0E7 */  swc1       $f0, 0x10C($29)
    /* CA774 001CA774 0001A427 */  addiu      $4, $29, 0x100
    /* CA778 001CA778 2D288000 */  daddu      $5, $4, $0
    /* CA77C 001CA77C 78900F0C */  jal        func_003e41e0
    /* CA780 001CA780 00000000 */   nop
    /* CA784 001CA784 0801A427 */  addiu      $4, $29, 0x108
    /* CA788 001CA788 2D288000 */  daddu      $5, $4, $0
    /* CA78C 001CA78C 78900F0C */  jal        func_003e41e0
    /* CA790 001CA790 00000000 */   nop
    /* CA794 001CA794 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* CA798 001CA798 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CA79C 001CA79C 01080046 */  sub.s      $f0, $f1, $f0
    /* CA7A0 001CA7A0 7801A0E7 */  swc1       $f0, 0x178($29)
    /* CA7A4 001CA7A4 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* CA7A8 001CA7A8 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* CA7AC 001CA7AC 01080046 */  sub.s      $f0, $f1, $f0
    /* CA7B0 001CA7B0 7C01A0E7 */  swc1       $f0, 0x17C($29)
    /* CA7B4 001CA7B4 6800A1C7 */  lwc1       $f1, 0x68($29)
    /* CA7B8 001CA7B8 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CA7BC 001CA7BC 01080046 */  sub.s      $f0, $f1, $f0
    /* CA7C0 001CA7C0 8001A0E7 */  swc1       $f0, 0x180($29)
    /* CA7C4 001CA7C4 0001A3C7 */  lwc1       $f3, 0x100($29)
    /* CA7C8 001CA7C8 0801A2C7 */  lwc1       $f2, 0x108($29)
    /* CA7CC 001CA7CC 0401A1C7 */  lwc1       $f1, 0x104($29)
    /* CA7D0 001CA7D0 0C01A0C7 */  lwc1       $f0, 0x10C($29)
    /* CA7D4 001CA7D4 1A080046 */  mula.s     $f1, $f0
    /* CA7D8 001CA7D8 00008044 */  mtc1       $0, $f0
    /* CA7DC 001CA7DC 5C180246 */  madd.s     $f1, $f3, $f2
    /* CA7E0 001CA7E0 34080046 */  c.lt.s     $f1, $f0
    /* CA7E4 001CA7E4 0A000145 */  bc1t       .L001CA810
    /* CA7E8 001CA7E8 00000000 */   nop
    /* CA7EC 001CA7EC A000A427 */  addiu      $4, $29, 0xA0
    /* CA7F0 001CA7F0 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CA7F4 001CA7F4 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CA7F8 001CA7F8 06BB0046 */  mov.s      $f12, $f23
    /* CA7FC 001CA7FC 2D300000 */  daddu      $6, $0, $0
    /* CA800 001CA800 1C820F0C */  jal        func_003e0870
    /* CA804 001CA804 00000000 */   nop
    /* CA808 001CA808 08000010 */  b          .L001CA82C
    /* CA80C 001CA80C 00000000 */   nop
  .L001CA810:
    /* CA810 001CA810 07BB0046 */  neg.s      $f12, $f23
    /* CA814 001CA814 A000A427 */  addiu      $4, $29, 0xA0
    /* CA818 001CA818 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CA81C 001CA81C E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CA820 001CA820 2D300000 */  daddu      $6, $0, $0
    /* CA824 001CA824 1C820F0C */  jal        func_003e0870
    /* CA828 001CA828 00000000 */   nop
  .L001CA82C:
    /* CA82C 001CA82C 7801A427 */  addiu      $4, $29, 0x178
    /* CA830 001CA830 2D288000 */  daddu      $5, $4, $0
    /* CA834 001CA834 A000A627 */  addiu      $6, $29, 0xA0
    /* CA838 001CA838 C8900F0C */  jal        func_003e4320
    /* CA83C 001CA83C 00000000 */   nop
    /* CA840 001CA840 7801A1C7 */  lwc1       $f1, 0x178($29)
    /* CA844 001CA844 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CA848 001CA848 00080046 */  add.s      $f0, $f1, $f0
    /* CA84C 001CA84C 7801A0E7 */  swc1       $f0, 0x178($29)
    /* CA850 001CA850 7C01A1C7 */  lwc1       $f1, 0x17C($29)
    /* CA854 001CA854 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* CA858 001CA858 00080046 */  add.s      $f0, $f1, $f0
    /* CA85C 001CA85C 7C01A0E7 */  swc1       $f0, 0x17C($29)
    /* CA860 001CA860 8001A1C7 */  lwc1       $f1, 0x180($29)
    /* CA864 001CA864 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CA868 001CA868 00080046 */  add.s      $f0, $f1, $f0
    /* CA86C 001CA86C 8001A0E7 */  swc1       $f0, 0x180($29)
    /* CA870 001CA870 8800A427 */  addiu      $4, $29, 0x88
    /* CA874 001CA874 7801A527 */  addiu      $5, $29, 0x178
    /* CA878 001CA878 4801A627 */  addiu      $6, $29, 0x148
    /* CA87C 001CA87C 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CA880 001CA880 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CA884 001CA884 E0F5060C */  jal        func_001bd780
    /* CA888 001CA888 00000000 */   nop
    /* CA88C 001CA88C C843023C */  lui        $2, (0x43C80000 >> 16)
    /* CA890 001CA890 00008244 */  mtc1       $2, $f0
    /* CA894 001CA894 00000000 */  nop
    /* CA898 001CA898 34B00046 */  c.lt.s     $f22, $f0
    /* CA89C 001CA89C 02000045 */  bc1f       .L001CA8A8
    /* CA8A0 001CA8A0 00000000 */   nop
    /* CA8A4 001CA8A4 86050046 */  mov.s      $f22, $f0
  .L001CA8A8:
    /* CA8A8 001CA8A8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CA8AC 001CA8AC 00088244 */  mtc1       $2, $f1
    /* CA8B0 001CA8B0 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* CA8B4 001CA8B4 42080046 */  mul.s      $f1, $f1, $f0
    /* CA8B8 001CA8B8 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CA8BC 001CA8BC 02030146 */  mul.s      $f12, $f0, $f1
    /* CA8C0 001CA8C0 1A2E110C */  jal        func_0044b868
    /* CA8C4 001CA8C4 00000000 */   nop
    /* CA8C8 001CA8C8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CA8CC 001CA8CC 00088244 */  mtc1       $2, $f1
    /* CA8D0 001CA8D0 00000000 */  nop
    /* CA8D4 001CA8D4 42081646 */  mul.s      $f1, $f1, $f22
    /* CA8D8 001CA8D8 C30D0046 */  div.s      $f23, $f1, $f0
    /* CA8DC 001CA8DC 7801A427 */  addiu      $4, $29, 0x178
    /* CA8E0 001CA8E0 6100053C */  lui        $5, %hi(D_0060A100)
    /* CA8E4 001CA8E4 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CA8E8 001CA8E8 01000624 */  addiu      $6, $0, 0x1
    /* CA8EC 001CA8EC 8800A727 */  addiu      $7, $29, 0x88
    /* CA8F0 001CA8F0 D0720F0C */  jal        func_003dcb40
    /* CA8F4 001CA8F4 00000000 */   nop
    /* CA8F8 001CA8F8 7C01A0C7 */  lwc1       $f0, 0x17C($29)
    /* CA8FC 001CA8FC 6C01A0E7 */  swc1       $f0, 0x16C($29)
    /* CA900 001CA900 6801A427 */  addiu      $4, $29, 0x168
    /* CA904 001CA904 2D288000 */  daddu      $5, $4, $0
    /* CA908 001CA908 2C900F0C */  jal        func_003e40b0
    /* CA90C 001CA90C 00000000 */   nop
    /* CA910 001CA910 6801A4C7 */  lwc1       $f4, 0x168($29)
    /* CA914 001CA914 7001A5C7 */  lwc1       $f5, 0x170($29)
    /* CA918 001CA918 8001A3C7 */  lwc1       $f3, 0x180($29)
    /* CA91C 001CA91C 7801A2C7 */  lwc1       $f2, 0x178($29)
    /* CA920 001CA920 7C01A1C7 */  lwc1       $f1, 0x17C($29)
    /* CA924 001CA924 6C01A0C7 */  lwc1       $f0, 0x16C($29)
    /* CA928 001CA928 1A080046 */  mula.s     $f1, $f0
    /* CA92C 001CA92C 00008044 */  mtc1       $0, $f0
    /* CA930 001CA930 1E100446 */  madda.s    $f2, $f4
    /* CA934 001CA934 1C1D0546 */  madd.s     $f20, $f3, $f5
    /* CA938 001CA938 34A00046 */  c.lt.s     $f20, $f0
    /* CA93C 001CA93C 0A000145 */  bc1t       .L001CA968
    /* CA940 001CA940 00000000 */   nop
    /* CA944 001CA944 900001C6 */  lwc1       $f1, 0x90($16)
    /* CA948 001CA948 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CA94C 001CA94C 820D0046 */  mul.s      $f22, $f1, $f0
    /* CA950 001CA950 2801A2DF */  ld         $2, 0x128($29)
    /* CA954 001CA954 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* CA958 001CA958 3801A2FF */  sd         $2, 0x138($29)
    /* CA95C 001CA95C 4001A0E7 */  swc1       $f0, 0x140($29)
    /* CA960 001CA960 08000010 */  b          .L001CA984
    /* CA964 001CA964 00000000 */   nop
  .L001CA968:
    /* CA968 001CA968 900021C6 */  lwc1       $f1, 0x90($17)
    /* CA96C 001CA96C 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CA970 001CA970 820D0046 */  mul.s      $f22, $f1, $f0
    /* CA974 001CA974 1801A2DF */  ld         $2, 0x118($29)
    /* CA978 001CA978 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CA97C 001CA97C 3801A2FF */  sd         $2, 0x138($29)
    /* CA980 001CA980 4001A0E7 */  swc1       $f0, 0x140($29)
  .L001CA984:
    /* CA984 001CA984 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* CA988 001CA988 00088044 */  mtc1       $0, $f1
    /* CA98C 001CA98C 00000000 */  nop
    /* CA990 001CA990 18080046 */  adda.s     $f1, $f0
    /* CA994 001CA994 DC281646 */  madd.s     $f3, $f5, $f22
    /* CA998 001CA998 8801A3E7 */  swc1       $f3, 0x188($29)
    /* CA99C 001CA99C 4C01A2C7 */  lwc1       $f2, 0x14C($29)
    /* CA9A0 001CA9A0 8C01A2E7 */  swc1       $f2, 0x18C($29)
    /* CA9A4 001CA9A4 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CA9A8 001CA9A8 18080046 */  adda.s     $f1, $f0
    /* CA9AC 001CA9AC 5D201646 */  msub.s     $f1, $f4, $f22
    /* CA9B0 001CA9B0 9001A1E7 */  swc1       $f1, 0x190($29)
    /* CA9B4 001CA9B4 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CA9B8 001CA9B8 01180046 */  sub.s      $f0, $f3, $f0
    /* CA9BC 001CA9BC 5801A0E7 */  swc1       $f0, 0x158($29)
    /* CA9C0 001CA9C0 01100246 */  sub.s      $f0, $f2, $f2
    /* CA9C4 001CA9C4 5C01A0E7 */  swc1       $f0, 0x15C($29)
    /* CA9C8 001CA9C8 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CA9CC 001CA9CC 01080046 */  sub.s      $f0, $f1, $f0
    /* CA9D0 001CA9D0 6001A0E7 */  swc1       $f0, 0x160($29)
    /* CA9D4 001CA9D4 5801A427 */  addiu      $4, $29, 0x158
    /* CA9D8 001CA9D8 2D288000 */  daddu      $5, $4, $0
    /* CA9DC 001CA9DC 2C900F0C */  jal        func_003e40b0
    /* CA9E0 001CA9E0 00000000 */   nop
    /* CA9E4 001CA9E4 6001A6C7 */  lwc1       $f6, 0x160($29)
    /* CA9E8 001CA9E8 7001A5C7 */  lwc1       $f5, 0x170($29)
    /* CA9EC 001CA9EC 5801A4C7 */  lwc1       $f4, 0x158($29)
    /* CA9F0 001CA9F0 6801A2C7 */  lwc1       $f2, 0x168($29)
    /* CA9F4 001CA9F4 5C01A1C7 */  lwc1       $f1, 0x15C($29)
    /* CA9F8 001CA9F8 6C01A0C7 */  lwc1       $f0, 0x16C($29)
    /* CA9FC 001CA9FC 1A080046 */  mula.s     $f1, $f0
    /* CAA00 001CAA00 00188044 */  mtc1       $0, $f3
    /* CAA04 001CAA04 00000000 */  nop
    /* CAA08 001CAA08 1E200246 */  madda.s    $f4, $f2
    /* CAA0C 001CAA0C 9C300546 */  madd.s     $f2, $f6, $f5
    /* CAA10 001CAA10 45A00046 */  abs.s      $f1, $f20
    /* CAA14 001CAA14 05100046 */  abs.s      $f0, $f2
    /* CAA18 001CAA18 36080046 */  c.le.s     $f1, $f0
    /* CAA1C 001CAA1C 61000145 */  bc1t       .L001CABA4
    /* CAA20 001CAA20 00000000 */   nop
    /* CAA24 001CAA24 32180246 */  c.eq.s     $f3, $f2
    /* CAA28 001CAA28 5E000145 */  bc1t       .L001CABA4
    /* CAA2C 001CAA2C 00000000 */   nop
    /* CAA30 001CAA30 32181446 */  c.eq.s     $f3, $f20
    /* CAA34 001CAA34 5B000145 */  bc1t       .L001CABA4
    /* CAA38 001CAA38 00000000 */   nop
    /* CAA3C 001CAA3C 4801A1C7 */  lwc1       $f1, 0x148($29)
    /* CAA40 001CAA40 3801A0C7 */  lwc1       $f0, 0x138($29)
    /* CAA44 001CAA44 01080046 */  sub.s      $f0, $f1, $f0
    /* CAA48 001CAA48 9801A0E7 */  swc1       $f0, 0x198($29)
    /* CAA4C 001CAA4C 4001B4C7 */  lwc1       $f20, 0x140($29)
    /* CAA50 001CAA50 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CAA54 001CAA54 01001446 */  sub.s      $f0, $f0, $f20
    /* CAA58 001CAA58 9C01A0E7 */  swc1       $f0, 0x19C($29)
    /* CAA5C 001CAA5C 9801A427 */  addiu      $4, $29, 0x198
    /* CAA60 001CAA60 6C900F0C */  jal        func_003e41b0
    /* CAA64 001CAA64 00000000 */   nop
    /* CAA68 001CAA68 02A80046 */  mul.s      $f0, $f21, $f0
    /* CAA6C 001CAA6C 00000000 */  nop
    /* CAA70 001CAA70 43001746 */  div.s      $f1, $f0, $f23
    /* CAA74 001CAA74 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* CAA78 001CAA78 00000146 */  add.s      $f0, $f0, $f1
    /* CAA7C 001CAA7C 8C01A0E7 */  swc1       $f0, 0x18C($29)
    /* CAA80 001CAA80 7001A2C7 */  lwc1       $f2, 0x170($29)
    /* CAA84 001CAA84 3801A0C7 */  lwc1       $f0, 0x138($29)
    /* CAA88 001CAA88 00088044 */  mtc1       $0, $f1
    /* CAA8C 001CAA8C 00000000 */  nop
    /* CAA90 001CAA90 18080046 */  adda.s     $f1, $f0
    /* CAA94 001CAA94 1C101646 */  madd.s     $f0, $f2, $f22
    /* CAA98 001CAA98 8801A0E7 */  swc1       $f0, 0x188($29)
    /* CAA9C 001CAA9C 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* CAAA0 001CAAA0 18081446 */  adda.s     $f1, $f20
    /* CAAA4 001CAAA4 1D001646 */  msub.s     $f0, $f0, $f22
    /* CAAA8 001CAAA8 9001A0E7 */  swc1       $f0, 0x190($29)
    /* CAAAC 001CAAAC E000A427 */  addiu      $4, $29, 0xE0
    /* CAAB0 001CAAB0 8801A527 */  addiu      $5, $29, 0x188
    /* CAAB4 001CAAB4 4801A627 */  addiu      $6, $29, 0x148
    /* CAAB8 001CAAB8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CAABC 001CAABC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CAAC0 001CAAC0 E0F5060C */  jal        func_001bd780
    /* CAAC4 001CAAC4 00000000 */   nop
    /* CAAC8 001CAAC8 6C00A427 */  addiu      $4, $29, 0x6C
    /* CAACC 001CAACC E000A527 */  addiu      $5, $29, 0xE0
    /* CAAD0 001CAAD0 ACB0070C */  jal        func_001ec2b0
    /* CAAD4 001CAAD4 00000000 */   nop
    /* CAAD8 001CAAD8 46050046 */  mov.s      $f21, $f0
    /* CAADC 001CAADC 7001A2C7 */  lwc1       $f2, 0x170($29)
    /* CAAE0 001CAAE0 3801A0C7 */  lwc1       $f0, 0x138($29)
    /* CAAE4 001CAAE4 00088044 */  mtc1       $0, $f1
    /* CAAE8 001CAAE8 00000000 */  nop
    /* CAAEC 001CAAEC 18080046 */  adda.s     $f1, $f0
    /* CAAF0 001CAAF0 1D101646 */  msub.s     $f0, $f2, $f22
    /* CAAF4 001CAAF4 8801A0E7 */  swc1       $f0, 0x188($29)
    /* CAAF8 001CAAF8 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* CAAFC 001CAAFC 18081446 */  adda.s     $f1, $f20
    /* CAB00 001CAB00 1C001646 */  madd.s     $f0, $f0, $f22
    /* CAB04 001CAB04 9001A0E7 */  swc1       $f0, 0x190($29)
    /* CAB08 001CAB08 F000A427 */  addiu      $4, $29, 0xF0
    /* CAB0C 001CAB0C 8801A527 */  addiu      $5, $29, 0x188
    /* CAB10 001CAB10 4801A627 */  addiu      $6, $29, 0x148
    /* CAB14 001CAB14 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CAB18 001CAB18 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CAB1C 001CAB1C E0F5060C */  jal        func_001bd780
    /* CAB20 001CAB20 00000000 */   nop
    /* CAB24 001CAB24 6C00A427 */  addiu      $4, $29, 0x6C
    /* CAB28 001CAB28 F000A527 */  addiu      $5, $29, 0xF0
    /* CAB2C 001CAB2C ACB0070C */  jal        func_001ec2b0
    /* CAB30 001CAB30 00000000 */   nop
    /* CAB34 001CAB34 34A80046 */  c.lt.s     $f21, $f0
    /* CAB38 001CAB38 0B000045 */  bc1f       .L001CAB68
    /* CAB3C 001CAB3C 00000000 */   nop
    /* CAB40 001CAB40 E000A3C7 */  lwc1       $f3, 0xE0($29)
    /* CAB44 001CAB44 E400A2C7 */  lwc1       $f2, 0xE4($29)
    /* CAB48 001CAB48 E800A1C7 */  lwc1       $f1, 0xE8($29)
    /* CAB4C 001CAB4C EC00A0C7 */  lwc1       $f0, 0xEC($29)
    /* CAB50 001CAB50 8800A3E7 */  swc1       $f3, 0x88($29)
    /* CAB54 001CAB54 8C00A2E7 */  swc1       $f2, 0x8C($29)
    /* CAB58 001CAB58 9000A1E7 */  swc1       $f1, 0x90($29)
    /* CAB5C 001CAB5C 9400A0E7 */  swc1       $f0, 0x94($29)
    /* CAB60 001CAB60 09000010 */  b          .L001CAB88
    /* CAB64 001CAB64 00000000 */   nop
  .L001CAB68:
    /* CAB68 001CAB68 F000A3C7 */  lwc1       $f3, 0xF0($29)
    /* CAB6C 001CAB6C F400A2C7 */  lwc1       $f2, 0xF4($29)
    /* CAB70 001CAB70 F800A1C7 */  lwc1       $f1, 0xF8($29)
    /* CAB74 001CAB74 FC00A0C7 */  lwc1       $f0, 0xFC($29)
    /* CAB78 001CAB78 8800A3E7 */  swc1       $f3, 0x88($29)
    /* CAB7C 001CAB7C 8C00A2E7 */  swc1       $f2, 0x8C($29)
    /* CAB80 001CAB80 9000A1E7 */  swc1       $f1, 0x90($29)
    /* CAB84 001CAB84 9400A0E7 */  swc1       $f0, 0x94($29)
  .L001CAB88:
    /* CAB88 001CAB88 7801A427 */  addiu      $4, $29, 0x178
    /* CAB8C 001CAB8C 6100053C */  lui        $5, %hi(D_0060A100)
    /* CAB90 001CAB90 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CAB94 001CAB94 01000624 */  addiu      $6, $0, 0x1
    /* CAB98 001CAB98 8800A727 */  addiu      $7, $29, 0x88
    /* CAB9C 001CAB9C D0720F0C */  jal        func_003dcb40
    /* CABA0 001CABA0 00000000 */   nop
  .L001CABA4:
    /* CABA4 001CABA4 7801A0C7 */  lwc1       $f0, 0x178($29)
    /* CABA8 001CABA8 02001746 */  mul.s      $f0, $f0, $f23
    /* CABAC 001CABAC 7801A0E7 */  swc1       $f0, 0x178($29)
    /* CABB0 001CABB0 7C01A0C7 */  lwc1       $f0, 0x17C($29)
    /* CABB4 001CABB4 02001746 */  mul.s      $f0, $f0, $f23
    /* CABB8 001CABB8 7C01A0E7 */  swc1       $f0, 0x17C($29)
    /* CABBC 001CABBC 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* CABC0 001CABC0 02001746 */  mul.s      $f0, $f0, $f23
    /* CABC4 001CABC4 8001A0E7 */  swc1       $f0, 0x180($29)
    /* CABC8 001CABC8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CABCC 001CABCC 00088244 */  mtc1       $2, $f1
    /* CABD0 001CABD0 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* CABD4 001CABD4 42080046 */  mul.s      $f1, $f1, $f0
    /* CABD8 001CABD8 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CABDC 001CABDC 02030146 */  mul.s      $f12, $f0, $f1
    /* CABE0 001CABE0 1A2E110C */  jal        func_0044b868
    /* CABE4 001CABE4 00000000 */   nop
    /* CABE8 001CABE8 42B80046 */  mul.s      $f1, $f23, $f0
    /* CABEC 001CABEC 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* CABF0 001CABF0 00008244 */  mtc1       $2, $f0
    /* CABF4 001CABF4 00000000 */  nop
    /* CABF8 001CABF8 020D0046 */  mul.s      $f20, $f1, $f0
    /* CABFC 001CABFC 7801A0C7 */  lwc1       $f0, 0x178($29)
    /* CAC00 001CAC00 9801A0E7 */  swc1       $f0, 0x198($29)
    /* CAC04 001CAC04 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* CAC08 001CAC08 9C01A0E7 */  swc1       $f0, 0x19C($29)
    /* CAC0C 001CAC0C 9801A427 */  addiu      $4, $29, 0x198
    /* CAC10 001CAC10 2D288000 */  daddu      $5, $4, $0
    /* CAC14 001CAC14 78900F0C */  jal        func_003e41e0
    /* CAC18 001CAC18 00000000 */   nop
    /* CAC1C 001CAC1C 9C01A1C7 */  lwc1       $f1, 0x19C($29)
    /* CAC20 001CAC20 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CAC24 001CAC24 00108044 */  mtc1       $0, $f2
    /* CAC28 001CAC28 00000000 */  nop
    /* CAC2C 001CAC2C 18100046 */  adda.s     $f2, $f0
    /* CAC30 001CAC30 DC081446 */  madd.s     $f3, $f1, $f20
    /* CAC34 001CAC34 4801A3E7 */  swc1       $f3, 0x148($29)
    /* CAC38 001CAC38 9801A1C7 */  lwc1       $f1, 0x198($29)
    /* CAC3C 001CAC3C 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CAC40 001CAC40 18100046 */  adda.s     $f2, $f0
    /* CAC44 001CAC44 9D081446 */  msub.s     $f2, $f1, $f20
    /* CAC48 001CAC48 5001A2E7 */  swc1       $f2, 0x150($29)
    /* CAC4C 001CAC4C 7801A0C7 */  lwc1       $f0, 0x178($29)
    /* CAC50 001CAC50 00180046 */  add.s      $f0, $f3, $f0
    /* CAC54 001CAC54 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* CAC58 001CAC58 4C01A1C7 */  lwc1       $f1, 0x14C($29)
    /* CAC5C 001CAC5C 7C01A0C7 */  lwc1       $f0, 0x17C($29)
    /* CAC60 001CAC60 00080046 */  add.s      $f0, $f1, $f0
    /* CAC64 001CAC64 8000A0E7 */  swc1       $f0, 0x80($29)
    /* CAC68 001CAC68 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* CAC6C 001CAC6C 00100046 */  add.s      $f0, $f2, $f0
    /* CAC70 001CAC70 8400A0E7 */  swc1       $f0, 0x84($29)
    /* CAC74 001CAC74 2D204002 */  daddu      $4, $18, $0
    /* CAC78 001CAC78 6000A527 */  addiu      $5, $29, 0x60
    /* CAC7C 001CAC7C 7C00A627 */  addiu      $6, $29, 0x7C
    /* CAC80 001CAC80 01000724 */  addiu      $7, $0, 0x1
    /* CAC84 001CAC84 08EB060C */  jal        func_001bac20
    /* CAC88 001CAC88 00000000 */   nop
    /* CAC8C 001CAC8C 2D204002 */  daddu      $4, $18, $0
    /* CAC90 001CAC90 06C30046 */  mov.s      $f12, $f24
    /* CAC94 001CAC94 BCEF060C */  jal        func_001bbef0
    /* CAC98 001CAC98 00000000 */   nop
    /* CAC9C 001CAC9C 5000BFDF */  ld         $31, 0x50($29)
    /* CACA0 001CACA0 4000B27B */  lq         $18, 0x40($29)
    /* CACA4 001CACA4 3000B17B */  lq         $17, 0x30($29)
    /* CACA8 001CACA8 2000B07B */  lq         $16, 0x20($29)
    /* CACAC 001CACAC 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* CACB0 001CACB0 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* CACB4 001CACB4 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* CACB8 001CACB8 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CACBC 001CACBC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CACC0 001CACC0 A001BD27 */  addiu      $29, $29, 0x1A0
    /* CACC4 001CACC4 0800E003 */  jr         $31
    /* CACC8 001CACC8 00000000 */   nop
    /* CACCC 001CACCC 00000000 */  nop
.size func_001ca590, 0x740
