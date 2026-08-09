.section .text
.set noat
.set noreorder
glabel func_003dc740
    /* 2DC740 003DC740 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 2DC744 003DC744 4000BFFF */  sd         $31, 0x40($29)
    /* 2DC748 003DC748 3000B27F */  sq         $18, 0x30($29)
    /* 2DC74C 003DC74C 2000B17F */  sq         $17, 0x20($29)
    /* 2DC750 003DC750 1000B07F */  sq         $16, 0x10($29)
    /* 2DC754 003DC754 2D888000 */  daddu      $17, $4, $0
    /* 2DC758 003DC758 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2DC75C 003DC75C E7002012 */  beqz       $17, .L003DCAFC
    /* 2DC760 003DC760 2D80A000 */   daddu     $16, $5, $0
    /* 2DC764 003DC764 E5000012 */  beqz       $16, .L003DCAFC
    /* 2DC768 003DC768 00000000 */   nop
    /* 2DC76C 003DC76C 02000224 */  addiu      $2, $0, 0x2
    /* 2DC770 003DC770 7B00C210 */  beq        $6, $2, .L003DC960
    /* 2DC774 003DC774 00000000 */   nop
    /* 2DC778 003DC778 01000224 */  addiu      $2, $0, 0x1
    /* 2DC77C 003DC77C 1D00C210 */  beq        $6, $2, .L003DC7F4
    /* 2DC780 003DC780 00000000 */   nop
    /* 2DC784 003DC784 0300C010 */  beqz       $6, .L003DC794
    /* 2DC788 003DC788 00000000 */   nop
    /* 2DC78C 003DC78C CF000010 */  b          .L003DCACC
    /* 2DC790 003DC790 95010324 */   addiu     $3, $0, 0x195
  .L003DC794:
    /* 2DC794 003DC794 0E3C023C */  lui        $2, (0x3C0EFA35 >> 16)
    /* 2DC798 003DC798 35FA4234 */  ori        $2, $2, (0x3C0EFA35 & 0xFFFF)
    /* 2DC79C 003DC79C 00008244 */  mtc1       $2, $f0
    /* 2DC7A0 003DC7A0 00000000 */  nop
    /* 2DC7A4 003DC7A4 02050C46 */  mul.s      $f20, $f0, $f12
    /* 2DC7A8 003DC7A8 EC2D110C */  jal        func_0044b7b0
    /* 2DC7AC 003DC7AC 06A30046 */   mov.s     $f12, $f20
    /* 2DC7B0 003DC7B0 06A30046 */  mov.s      $f12, $f20
    /* 2DC7B4 003DC7B4 842D110C */  jal        func_0044b610
    /* 2DC7B8 003DC7B8 06050046 */   mov.s     $f20, $f0
    /* 2DC7BC 003DC7BC 0C0020E6 */  swc1       $f0, 0xC($17)
    /* 2DC7C0 003DC7C0 2D280002 */  daddu      $5, $16, $0
    /* 2DC7C4 003DC7C4 2C900F0C */  jal        func_003e40b0
    /* 2DC7C8 003DC7C8 2D202002 */   daddu     $4, $17, $0
    /* 2DC7CC 003DC7CC 000020C6 */  lwc1       $f0, 0x0($17)
    /* 2DC7D0 003DC7D0 02001446 */  mul.s      $f0, $f0, $f20
    /* 2DC7D4 003DC7D4 000020E6 */  swc1       $f0, 0x0($17)
    /* 2DC7D8 003DC7D8 040020C6 */  lwc1       $f0, 0x4($17)
    /* 2DC7DC 003DC7DC 02001446 */  mul.s      $f0, $f0, $f20
    /* 2DC7E0 003DC7E0 040020E6 */  swc1       $f0, 0x4($17)
    /* 2DC7E4 003DC7E4 080020C6 */  lwc1       $f0, 0x8($17)
    /* 2DC7E8 003DC7E8 02001446 */  mul.s      $f0, $f0, $f20
    /* 2DC7EC 003DC7EC C1000010 */  b          .L003DCAF4
    /* 2DC7F0 003DC7F0 080020E6 */   swc1      $f0, 0x8($17)
  .L003DC7F4:
    /* 2DC7F4 003DC7F4 0E3C023C */  lui        $2, (0x3C0EFA35 >> 16)
    /* 2DC7F8 003DC7F8 35FA4234 */  ori        $2, $2, (0x3C0EFA35 & 0xFFFF)
    /* 2DC7FC 003DC7FC 00008244 */  mtc1       $2, $f0
    /* 2DC800 003DC800 040021C6 */  lwc1       $f1, 0x4($17)
    /* 2DC804 003DC804 02050C46 */  mul.s      $f20, $f0, $f12
    /* 2DC808 003DC808 7400A1E7 */  swc1       $f1, 0x74($29)
    /* 2DC80C 003DC80C 000022C6 */  lwc1       $f2, 0x0($17)
    /* 2DC810 003DC810 080021C6 */  lwc1       $f1, 0x8($17)
    /* 2DC814 003DC814 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* 2DC818 003DC818 06A30046 */  mov.s      $f12, $f20
    /* 2DC81C 003DC81C 7000A2E7 */  swc1       $f2, 0x70($29)
    /* 2DC820 003DC820 7800A1E7 */  swc1       $f1, 0x78($29)
    /* 2DC824 003DC824 EC2D110C */  jal        func_0044b7b0
    /* 2DC828 003DC828 7C00A0E7 */   swc1      $f0, 0x7C($29)
    /* 2DC82C 003DC82C 06A30046 */  mov.s      $f12, $f20
    /* 2DC830 003DC830 8C00B227 */  addiu      $18, $29, 0x8C
    /* 2DC834 003DC834 842D110C */  jal        func_0044b610
    /* 2DC838 003DC838 06050046 */   mov.s     $f20, $f0
    /* 2DC83C 003DC83C 000040E6 */  swc1       $f0, 0x0($18)
    /* 2DC840 003DC840 2D280002 */  daddu      $5, $16, $0
    /* 2DC844 003DC844 2C900F0C */  jal        func_003e40b0
    /* 2DC848 003DC848 8000A427 */   addiu     $4, $29, 0x80
    /* 2DC84C 003DC84C 8400A327 */  addiu      $3, $29, 0x84
    /* 2DC850 003DC850 8800A227 */  addiu      $2, $29, 0x88
    /* 2DC854 003DC854 000067C4 */  lwc1       $f7, 0x0($3)
    /* 2DC858 003DC858 8000A8C7 */  lwc1       $f8, 0x80($29)
    /* 2DC85C 003DC85C 000042C4 */  lwc1       $f2, 0x0($2)
    /* 2DC860 003DC860 7C00A5C7 */  lwc1       $f5, 0x7C($29)
    /* 2DC864 003DC864 000041C6 */  lwc1       $f1, 0x0($18)
    /* 2DC868 003DC868 7400A6C7 */  lwc1       $f6, 0x74($29)
    /* 2DC86C 003DC86C C2391446 */  mul.s      $f7, $f7, $f20
    /* 2DC870 003DC870 02421446 */  mul.s      $f8, $f8, $f20
    /* 2DC874 003DC874 82101446 */  mul.s      $f2, $f2, $f20
    /* 2DC878 003DC878 7000A4C7 */  lwc1       $f4, 0x70($29)
    /* 2DC87C 003DC87C 1A300746 */  mula.s     $f6, $f7
    /* 2DC880 003DC880 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* 2DC884 003DC884 42280146 */  mul.s      $f1, $f5, $f1
    /* 2DC888 003DC888 1E200846 */  madda.s    $f4, $f8
    /* 2DC88C 003DC88C 000042E4 */  swc1       $f2, 0x0($2)
    /* 2DC890 003DC890 9C000246 */  madd.s     $f2, $f0, $f2
    /* 2DC894 003DC894 41080246 */  sub.s      $f1, $f1, $f2
    /* 2DC898 003DC898 8000A8E7 */  swc1       $f8, 0x80($29)
    /* 2DC89C 003DC89C 000067E4 */  swc1       $f7, 0x0($3)
    /* 2DC8A0 003DC8A0 0C0021E6 */  swc1       $f1, 0xC($17)
    /* 2DC8A4 003DC8A4 000041C4 */  lwc1       $f1, 0x0($2)
    /* 2DC8A8 003DC8A8 000062C4 */  lwc1       $f2, 0x0($3)
    /* 2DC8AC 003DC8AC 00188044 */  mtc1       $0, $f3
    /* 2DC8B0 003DC8B0 1A300146 */  mula.s     $f6, $f1
    /* 2DC8B4 003DC8B4 5D000246 */  msub.s     $f1, $f0, $f2
    /* 2DC8B8 003DC8B8 000021E6 */  swc1       $f1, 0x0($17)
    /* 2DC8BC 003DC8BC 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* 2DC8C0 003DC8C0 000042C4 */  lwc1       $f2, 0x0($2)
    /* 2DC8C4 003DC8C4 1A000146 */  mula.s     $f0, $f1
    /* 2DC8C8 003DC8C8 5D200246 */  msub.s     $f1, $f4, $f2
    /* 2DC8CC 003DC8CC 040021E6 */  swc1       $f1, 0x4($17)
    /* 2DC8D0 003DC8D0 000061C4 */  lwc1       $f1, 0x0($3)
    /* 2DC8D4 003DC8D4 8000A2C7 */  lwc1       $f2, 0x80($29)
    /* 2DC8D8 003DC8D8 1A200146 */  mula.s     $f4, $f1
    /* 2DC8DC 003DC8DC 5D300246 */  msub.s     $f1, $f6, $f2
    /* 2DC8E0 003DC8E0 080021E6 */  swc1       $f1, 0x8($17)
    /* 2DC8E4 003DC8E4 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2DC8E8 003DC8E8 8000A2C7 */  lwc1       $f2, 0x80($29)
    /* 2DC8EC 003DC8EC 18180146 */  adda.s     $f3, $f1
    /* 2DC8F0 003DC8F0 5C100546 */  madd.s     $f1, $f2, $f5
    /* 2DC8F4 003DC8F4 000021E6 */  swc1       $f1, 0x0($17)
    /* 2DC8F8 003DC8F8 040021C6 */  lwc1       $f1, 0x4($17)
    /* 2DC8FC 003DC8FC 000062C4 */  lwc1       $f2, 0x0($3)
    /* 2DC900 003DC900 18180146 */  adda.s     $f3, $f1
    /* 2DC904 003DC904 5C100546 */  madd.s     $f1, $f2, $f5
    /* 2DC908 003DC908 040021E6 */  swc1       $f1, 0x4($17)
    /* 2DC90C 003DC90C 080021C6 */  lwc1       $f1, 0x8($17)
    /* 2DC910 003DC910 000042C4 */  lwc1       $f2, 0x0($2)
    /* 2DC914 003DC914 18180146 */  adda.s     $f3, $f1
    /* 2DC918 003DC918 5C100546 */  madd.s     $f1, $f2, $f5
    /* 2DC91C 003DC91C 080021E6 */  swc1       $f1, 0x8($17)
    /* 2DC920 003DC920 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2DC924 003DC924 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2DC928 003DC928 18180146 */  adda.s     $f3, $f1
    /* 2DC92C 003DC92C 5C200246 */  madd.s     $f1, $f4, $f2
    /* 2DC930 003DC930 000021E6 */  swc1       $f1, 0x0($17)
    /* 2DC934 003DC934 040021C6 */  lwc1       $f1, 0x4($17)
    /* 2DC938 003DC938 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2DC93C 003DC93C 18180146 */  adda.s     $f3, $f1
    /* 2DC940 003DC940 5C300246 */  madd.s     $f1, $f6, $f2
    /* 2DC944 003DC944 040021E6 */  swc1       $f1, 0x4($17)
    /* 2DC948 003DC948 080021C6 */  lwc1       $f1, 0x8($17)
    /* 2DC94C 003DC94C 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2DC950 003DC950 18180146 */  adda.s     $f3, $f1
    /* 2DC954 003DC954 1C000246 */  madd.s     $f0, $f0, $f2
    /* 2DC958 003DC958 66000010 */  b          .L003DCAF4
    /* 2DC95C 003DC95C 080020E6 */   swc1      $f0, 0x8($17)
  .L003DC960:
    /* 2DC960 003DC960 0E3C023C */  lui        $2, (0x3C0EFA35 >> 16)
    /* 2DC964 003DC964 35FA4234 */  ori        $2, $2, (0x3C0EFA35 & 0xFFFF)
    /* 2DC968 003DC968 00008244 */  mtc1       $2, $f0
    /* 2DC96C 003DC96C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 2DC970 003DC970 02050C46 */  mul.s      $f20, $f0, $f12
    /* 2DC974 003DC974 5400A1E7 */  swc1       $f1, 0x54($29)
    /* 2DC978 003DC978 000022C6 */  lwc1       $f2, 0x0($17)
    /* 2DC97C 003DC97C 080021C6 */  lwc1       $f1, 0x8($17)
    /* 2DC980 003DC980 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* 2DC984 003DC984 06A30046 */  mov.s      $f12, $f20
    /* 2DC988 003DC988 5000A2E7 */  swc1       $f2, 0x50($29)
    /* 2DC98C 003DC98C 5800A1E7 */  swc1       $f1, 0x58($29)
    /* 2DC990 003DC990 EC2D110C */  jal        func_0044b7b0
    /* 2DC994 003DC994 5C00A0E7 */   swc1      $f0, 0x5C($29)
    /* 2DC998 003DC998 06A30046 */  mov.s      $f12, $f20
    /* 2DC99C 003DC99C 6C00B227 */  addiu      $18, $29, 0x6C
    /* 2DC9A0 003DC9A0 842D110C */  jal        func_0044b610
    /* 2DC9A4 003DC9A4 06050046 */   mov.s     $f20, $f0
    /* 2DC9A8 003DC9A8 000040E6 */  swc1       $f0, 0x0($18)
    /* 2DC9AC 003DC9AC 2D280002 */  daddu      $5, $16, $0
    /* 2DC9B0 003DC9B0 2C900F0C */  jal        func_003e40b0
    /* 2DC9B4 003DC9B4 6000A427 */   addiu     $4, $29, 0x60
    /* 2DC9B8 003DC9B8 6400A327 */  addiu      $3, $29, 0x64
    /* 2DC9BC 003DC9BC 6800A227 */  addiu      $2, $29, 0x68
    /* 2DC9C0 003DC9C0 000067C4 */  lwc1       $f7, 0x0($3)
    /* 2DC9C4 003DC9C4 6000A8C7 */  lwc1       $f8, 0x60($29)
    /* 2DC9C8 003DC9C8 000042C4 */  lwc1       $f2, 0x0($2)
    /* 2DC9CC 003DC9CC 5C00A0C7 */  lwc1       $f0, 0x5C($29)
    /* 2DC9D0 003DC9D0 000041C6 */  lwc1       $f1, 0x0($18)
    /* 2DC9D4 003DC9D4 5400A6C7 */  lwc1       $f6, 0x54($29)
    /* 2DC9D8 003DC9D8 C2391446 */  mul.s      $f7, $f7, $f20
    /* 2DC9DC 003DC9DC 02421446 */  mul.s      $f8, $f8, $f20
    /* 2DC9E0 003DC9E0 82101446 */  mul.s      $f2, $f2, $f20
    /* 2DC9E4 003DC9E4 5000A4C7 */  lwc1       $f4, 0x50($29)
    /* 2DC9E8 003DC9E8 1A380646 */  mula.s     $f7, $f6
    /* 2DC9EC 003DC9EC 5800A5C7 */  lwc1       $f5, 0x58($29)
    /* 2DC9F0 003DC9F0 42080046 */  mul.s      $f1, $f1, $f0
    /* 2DC9F4 003DC9F4 1E400446 */  madda.s    $f8, $f4
    /* 2DC9F8 003DC9F8 000042E4 */  swc1       $f2, 0x0($2)
    /* 2DC9FC 003DC9FC 9C100546 */  madd.s     $f2, $f2, $f5
    /* 2DCA00 003DCA00 41080246 */  sub.s      $f1, $f1, $f2
    /* 2DCA04 003DCA04 6000A8E7 */  swc1       $f8, 0x60($29)
    /* 2DCA08 003DCA08 000067E4 */  swc1       $f7, 0x0($3)
    /* 2DCA0C 003DCA0C 0C0021E6 */  swc1       $f1, 0xC($17)
    /* 2DCA10 003DCA10 000061C4 */  lwc1       $f1, 0x0($3)
    /* 2DCA14 003DCA14 000042C4 */  lwc1       $f2, 0x0($2)
    /* 2DCA18 003DCA18 00188044 */  mtc1       $0, $f3
    /* 2DCA1C 003DCA1C 1A080546 */  mula.s     $f1, $f5
    /* 2DCA20 003DCA20 5D100646 */  msub.s     $f1, $f2, $f6
    /* 2DCA24 003DCA24 000021E6 */  swc1       $f1, 0x0($17)
    /* 2DCA28 003DCA28 000041C4 */  lwc1       $f1, 0x0($2)
    /* 2DCA2C 003DCA2C 6000A2C7 */  lwc1       $f2, 0x60($29)
    /* 2DCA30 003DCA30 1A080446 */  mula.s     $f1, $f4
    /* 2DCA34 003DCA34 5D100546 */  msub.s     $f1, $f2, $f5
    /* 2DCA38 003DCA38 040021E6 */  swc1       $f1, 0x4($17)
    /* 2DCA3C 003DCA3C 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* 2DCA40 003DCA40 000062C4 */  lwc1       $f2, 0x0($3)
    /* 2DCA44 003DCA44 1A080646 */  mula.s     $f1, $f6
    /* 2DCA48 003DCA48 5D100446 */  msub.s     $f1, $f2, $f4
    /* 2DCA4C 003DCA4C 080021E6 */  swc1       $f1, 0x8($17)
    /* 2DCA50 003DCA50 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2DCA54 003DCA54 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2DCA58 003DCA58 18180146 */  adda.s     $f3, $f1
    /* 2DCA5C 003DCA5C 5C200246 */  madd.s     $f1, $f4, $f2
    /* 2DCA60 003DCA60 000021E6 */  swc1       $f1, 0x0($17)
    /* 2DCA64 003DCA64 040021C6 */  lwc1       $f1, 0x4($17)
    /* 2DCA68 003DCA68 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2DCA6C 003DCA6C 18180146 */  adda.s     $f3, $f1
    /* 2DCA70 003DCA70 5C300246 */  madd.s     $f1, $f6, $f2
    /* 2DCA74 003DCA74 040021E6 */  swc1       $f1, 0x4($17)
    /* 2DCA78 003DCA78 080021C6 */  lwc1       $f1, 0x8($17)
    /* 2DCA7C 003DCA7C 000042C6 */  lwc1       $f2, 0x0($18)
    /* 2DCA80 003DCA80 18180146 */  adda.s     $f3, $f1
    /* 2DCA84 003DCA84 5C280246 */  madd.s     $f1, $f5, $f2
    /* 2DCA88 003DCA88 080021E6 */  swc1       $f1, 0x8($17)
    /* 2DCA8C 003DCA8C 000021C6 */  lwc1       $f1, 0x0($17)
    /* 2DCA90 003DCA90 6000A2C7 */  lwc1       $f2, 0x60($29)
    /* 2DCA94 003DCA94 18180146 */  adda.s     $f3, $f1
    /* 2DCA98 003DCA98 5C100046 */  madd.s     $f1, $f2, $f0
    /* 2DCA9C 003DCA9C 000021E6 */  swc1       $f1, 0x0($17)
    /* 2DCAA0 003DCAA0 040021C6 */  lwc1       $f1, 0x4($17)
    /* 2DCAA4 003DCAA4 000062C4 */  lwc1       $f2, 0x0($3)
    /* 2DCAA8 003DCAA8 18180146 */  adda.s     $f3, $f1
    /* 2DCAAC 003DCAAC 5C100046 */  madd.s     $f1, $f2, $f0
    /* 2DCAB0 003DCAB0 040021E6 */  swc1       $f1, 0x4($17)
    /* 2DCAB4 003DCAB4 080021C6 */  lwc1       $f1, 0x8($17)
    /* 2DCAB8 003DCAB8 000042C4 */  lwc1       $f2, 0x0($2)
    /* 2DCABC 003DCABC 18180146 */  adda.s     $f3, $f1
    /* 2DCAC0 003DCAC0 1C100046 */  madd.s     $f0, $f2, $f0
    /* 2DCAC4 003DCAC4 0B000010 */  b          .L003DCAF4
    /* 2DCAC8 003DCAC8 080020E6 */   swc1      $f0, 0x8($17)
  .L003DCACC:
    /* 2DCACC 003DCACC 0080023C */  lui        $2, (0x80000003 >> 16)
    /* 2DCAD0 003DCAD0 7100053C */  lui        $5, %hi(D_0070B6C0)
    /* 2DCAD4 003DCAD4 9800A3AF */  sw         $3, 0x98($29)
    /* 2DCAD8 003DCAD8 03004434 */  ori        $4, $2, (0x80000003 & 0xFFFF)
    /* 2DCADC 003DCADC 647D0F0C */  jal        func_003df590
    /* 2DCAE0 003DCAE0 C0B6A524 */   addiu     $5, $5, %lo(D_0070B6C0)
    /* 2DCAE4 003DCAE4 9C00A2AF */  sw         $2, 0x9C($29)
    /* 2DCAE8 003DCAE8 347D0F0C */  jal        func_003df4d0
    /* 2DCAEC 003DCAEC 9800A427 */   addiu     $4, $29, 0x98
    /* 2DCAF0 003DCAF0 2D880000 */  daddu      $17, $0, $0
  .L003DCAF4:
    /* 2DCAF4 003DCAF4 0B000010 */  b          .L003DCB24
    /* 2DCAF8 003DCAF8 2D102002 */   daddu     $2, $17, $0
  .L003DCAFC:
    /* 2DCAFC 003DCAFC 95010324 */  addiu      $3, $0, 0x195
    /* 2DCB00 003DCB00 0080023C */  lui        $2, (0x80000016 >> 16)
    /* 2DCB04 003DCB04 9000A3AF */  sw         $3, 0x90($29)
    /* 2DCB08 003DCB08 647D0F0C */  jal        func_003df590
    /* 2DCB0C 003DCB0C 16004434 */   ori       $4, $2, (0x80000016 & 0xFFFF)
    /* 2DCB10 003DCB10 9400A2AF */  sw         $2, 0x94($29)
    /* 2DCB14 003DCB14 347D0F0C */  jal        func_003df4d0
    /* 2DCB18 003DCB18 9000A427 */   addiu     $4, $29, 0x90
    /* 2DCB1C 003DCB1C F5FF0010 */  b          .L003DCAF4
    /* 2DCB20 003DCB20 2D880000 */   daddu     $17, $0, $0
  .L003DCB24:
    /* 2DCB24 003DCB24 4000BFDF */  ld         $31, 0x40($29)
    /* 2DCB28 003DCB28 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2DCB2C 003DCB2C 3000B27B */  lq         $18, 0x30($29)
    /* 2DCB30 003DCB30 2000B17B */  lq         $17, 0x20($29)
    /* 2DCB34 003DCB34 1000B07B */  lq         $16, 0x10($29)
    /* 2DCB38 003DCB38 0800E003 */  jr         $31
    /* 2DCB3C 003DCB3C A000BD27 */   addiu     $29, $29, 0xA0
.size func_003dc740, 0x400
