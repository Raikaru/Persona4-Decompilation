.section .text
.set noat
.set noreorder
glabel func_001be990
    /* BE990 001BE990 60FEBD27 */  addiu      $29, $29, -0x1A0
    /* BE994 001BE994 5000BFFF */  sd         $31, 0x50($29)
    /* BE998 001BE998 4000B37F */  sq         $19, 0x40($29)
    /* BE99C 001BE99C 3000B27F */  sq         $18, 0x30($29)
    /* BE9A0 001BE9A0 2000B17F */  sq         $17, 0x20($29)
    /* BE9A4 001BE9A4 1000B07F */  sq         $16, 0x10($29)
    /* BE9A8 001BE9A8 0800B6E7 */  swc1       $f22, 0x8($29)
    /* BE9AC 001BE9AC 0400B5E7 */  swc1       $f21, 0x4($29)
    /* BE9B0 001BE9B0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BE9B4 001BE9B4 2D988000 */  daddu      $19, $4, $0
    /* BE9B8 001BE9B8 2D90C000 */  daddu      $18, $6, $0
    /* BE9BC 001BE9BC 2D80E000 */  daddu      $16, $7, $0
    /* BE9C0 001BE9C0 E000848C */  lw         $4, 0xE0($4)
    /* BE9C4 001BE9C4 3000918C */  lw         $17, 0x30($4)
    /* BE9C8 001BE9C8 6E01A014 */  bnez       $5, .L001BEF84
    /* BE9CC 001BE9CC 00000000 */   nop
    /* BE9D0 001BE9D0 6000A427 */  addiu      $4, $29, 0x60
    /* BE9D4 001BE9D4 9C006526 */  addiu      $5, $19, 0x9C
    /* BE9D8 001BE9D8 58F5060C */  jal        func_001bd560
    /* BE9DC 001BE9DC 00000000 */   nop
    /* BE9E0 001BE9E0 900021C6 */  lwc1       $f1, 0x90($17)
    /* BE9E4 001BE9E4 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* BE9E8 001BE9E8 820D0046 */  mul.s      $f22, $f1, $f0
    /* BE9EC 001BE9EC 2D202002 */  daddu      $4, $17, $0
    /* BE9F0 001BE9F0 7001A527 */  addiu      $5, $29, 0x170
    /* BE9F4 001BE9F4 1456060C */  jal        func_00195850
    /* BE9F8 001BE9F8 00000000 */   nop
    /* BE9FC 001BE9FC 8001A427 */  addiu      $4, $29, 0x180
    /* BEA00 001BEA00 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* BEA04 001BEA04 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* BEA08 001BEA08 01000624 */  addiu      $6, $0, 0x1
    /* BEA0C 001BEA0C 1C002726 */  addiu      $7, $17, 0x1C
    /* BEA10 001BEA10 D0720F0C */  jal        func_003dcb40
    /* BEA14 001BEA14 00000000 */   nop
    /* BEA18 001BEA18 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BEA1C 001BEA1C 00008244 */  mtc1       $2, $f0
    /* BEA20 001BEA20 00000000 */  nop
    /* BEA24 001BEA24 42001646 */  mul.s      $f1, $f0, $f22
    /* BEA28 001BEA28 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* BEA2C 001BEA2C C2000146 */  mul.s      $f3, $f0, $f1
    /* BEA30 001BEA30 9001A3E7 */  swc1       $f3, 0x190($29)
    /* BEA34 001BEA34 8401A0C7 */  lwc1       $f0, 0x184($29)
    /* BEA38 001BEA38 82000146 */  mul.s      $f2, $f0, $f1
    /* BEA3C 001BEA3C 9401A2E7 */  swc1       $f2, 0x194($29)
    /* BEA40 001BEA40 8801A0C7 */  lwc1       $f0, 0x188($29)
    /* BEA44 001BEA44 42000146 */  mul.s      $f1, $f0, $f1
    /* BEA48 001BEA48 9801A1E7 */  swc1       $f1, 0x198($29)
    /* BEA4C 001BEA4C 7001A0C7 */  lwc1       $f0, 0x170($29)
    /* BEA50 001BEA50 00000346 */  add.s      $f0, $f0, $f3
    /* BEA54 001BEA54 4001A0E7 */  swc1       $f0, 0x140($29)
    /* BEA58 001BEA58 7401A0C7 */  lwc1       $f0, 0x174($29)
    /* BEA5C 001BEA5C C0000246 */  add.s      $f3, $f0, $f2
    /* BEA60 001BEA60 4401A3E7 */  swc1       $f3, 0x144($29)
    /* BEA64 001BEA64 7801A0C7 */  lwc1       $f0, 0x178($29)
    /* BEA68 001BEA68 00000146 */  add.s      $f0, $f0, $f1
    /* BEA6C 001BEA6C 4801A0E7 */  swc1       $f0, 0x148($29)
    /* BEA70 001BEA70 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* BEA74 001BEA74 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* BEA78 001BEA78 82080046 */  mul.s      $f2, $f1, $f0
    /* BEA7C 001BEA7C 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* BEA80 001BEA80 00088244 */  mtc1       $2, $f1
    /* BEA84 001BEA84 00008044 */  mtc1       $0, $f0
    /* BEA88 001BEA88 00000000 */  nop
    /* BEA8C 001BEA8C 18000346 */  adda.s     $f0, $f3
    /* BEA90 001BEA90 1C080246 */  madd.s     $f0, $f1, $f2
    /* BEA94 001BEA94 4401A0E7 */  swc1       $f0, 0x144($29)
    /* BEA98 001BEA98 03000424 */  addiu      $4, $0, 0x3
    /* BEA9C 001BEA9C 2D280000 */  daddu      $5, $0, $0
    /* BEAA0 001BEAA0 2D300000 */  daddu      $6, $0, $0
    /* BEAA4 001BEAA4 9C01A727 */  addiu      $7, $29, 0x19C
    /* BEAA8 001BEAA8 2D400000 */  daddu      $8, $0, $0
    /* BEAAC 001BEAAC 01000924 */  addiu      $9, $0, 0x1
    /* BEAB0 001BEAB0 1058060C */  jal        func_00196040
    /* BEAB4 001BEAB4 00000000 */   nop
    /* BEAB8 001BEAB8 6000A2DF */  ld         $2, 0x60($29)
    /* BEABC 001BEABC 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* BEAC0 001BEAC0 9001A2FF */  sd         $2, 0x190($29)
    /* BEAC4 001BEAC4 9801A0E7 */  swc1       $f0, 0x198($29)
    /* BEAC8 001BEAC8 9401A2C7 */  lwc1       $f2, 0x194($29)
    /* BEACC 001BEACC 9C01A0C7 */  lwc1       $f0, 0x19C($29)
    /* BEAD0 001BEAD0 34000246 */  c.lt.s     $f0, $f2
    /* BEAD4 001BEAD4 04000045 */  bc1f       .L001BEAE8
    /* BEAD8 001BEAD8 00000000 */   nop
    /* BEADC 001BEADC 9401A0E7 */  swc1       $f0, 0x194($29)
    /* BEAE0 001BEAE0 08000010 */  b          .L001BEB04
    /* BEAE4 001BEAE4 00000000 */   nop
  .L001BEAE8:
    /* BEAE8 001BEAE8 2C0021C6 */  lwc1       $f1, 0x2C($17)
    /* BEAEC 001BEAEC 8C0020C6 */  lwc1       $f0, 0x8C($17)
    /* BEAF0 001BEAF0 02000146 */  mul.s      $f0, $f0, $f1
    /* BEAF4 001BEAF4 36000246 */  c.le.s     $f0, $f2
    /* BEAF8 001BEAF8 02000145 */  bc1t       .L001BEB04
    /* BEAFC 001BEAFC 00000000 */   nop
    /* BEB00 001BEB00 9401A0E7 */  swc1       $f0, 0x194($29)
  .L001BEB04:
    /* BEB04 001BEB04 8800A427 */  addiu      $4, $29, 0x88
    /* BEB08 001BEB08 9001A527 */  addiu      $5, $29, 0x190
    /* BEB0C 001BEB0C 4001A627 */  addiu      $6, $29, 0x140
    /* BEB10 001BEB10 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BEB14 001BEB14 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BEB18 001BEB18 E0F5060C */  jal        func_001bd780
    /* BEB1C 001BEB1C 00000000 */   nop
    /* BEB20 001BEB20 6C00A427 */  addiu      $4, $29, 0x6C
    /* BEB24 001BEB24 8800A527 */  addiu      $5, $29, 0x88
    /* BEB28 001BEB28 ACB0070C */  jal        func_001ec2b0
    /* BEB2C 001BEB2C 00000000 */   nop
    /* BEB30 001BEB30 00089244 */  mtc1       $18, $f1
    /* BEB34 001BEB34 00000000 */  nop
    /* BEB38 001BEB38 60088046 */  cvt.s.w    $f1, $f1
    /* BEB3C 001BEB3C 908182C7 */  lwc1       $f2, -0x7E70($28)
    /* BEB40 001BEB40 02150146 */  mul.s      $f20, $f2, $f1
    /* BEB44 001BEB44 36001446 */  c.le.s     $f0, $f20
    /* BEB48 001BEB48 91000145 */  bc1t       .L001BED90
    /* BEB4C 001BEB4C 00000000 */   nop
    /* BEB50 001BEB50 00089044 */  mtc1       $16, $f1
    /* BEB54 001BEB54 00000000 */  nop
    /* BEB58 001BEB58 60088046 */  cvt.s.w    $f1, $f1
    /* BEB5C 001BEB5C 42100146 */  mul.s      $f1, $f2, $f1
    /* BEB60 001BEB60 36000146 */  c.le.s     $f0, $f1
    /* BEB64 001BEB64 04000145 */  bc1t       .L001BEB78
    /* BEB68 001BEB68 00000000 */   nop
    /* BEB6C 001BEB6C 2D100000 */  daddu      $2, $0, $0
    /* BEB70 001BEB70 FD010010 */  b          .L001BF368
    /* BEB74 001BEB74 00000000 */   nop
  .L001BEB78:
    /* BEB78 001BEB78 00000000 */  nop
    /* BEB7C 001BEB7C 00000000 */  nop
    /* BEB80 001BEB80 43A50046 */  div.s      $f21, $f20, $f0
    /* BEB84 001BEB84 6C00A427 */  addiu      $4, $29, 0x6C
    /* BEB88 001BEB88 8800A527 */  addiu      $5, $29, 0x88
    /* BEB8C 001BEB8C A000A627 */  addiu      $6, $29, 0xA0
    /* BEB90 001BEB90 1C730F0C */  jal        func_003dcc70
    /* BEB94 001BEB94 00000000 */   nop
    /* BEB98 001BEB98 00588044 */  mtc1       $0, $f11
    /* BEB9C 001BEB9C 00000000 */  nop
    /* BEBA0 001BEBA0 36A80B46 */  c.le.s     $f21, $f11
    /* BEBA4 001BEBA4 0B000045 */  bc1f       .L001BEBD4
    /* BEBA8 001BEBA8 00000000 */   nop
    /* BEBAC 001BEBAC 6C00A3C7 */  lwc1       $f3, 0x6C($29)
    /* BEBB0 001BEBB0 7000A2C7 */  lwc1       $f2, 0x70($29)
    /* BEBB4 001BEBB4 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* BEBB8 001BEBB8 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* BEBBC 001BEBBC E000A3E7 */  swc1       $f3, 0xE0($29)
    /* BEBC0 001BEBC0 E400A2E7 */  swc1       $f2, 0xE4($29)
    /* BEBC4 001BEBC4 E800A1E7 */  swc1       $f1, 0xE8($29)
    /* BEBC8 001BEBC8 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* BEBCC 001BEBCC 56000010 */  b          .L001BED28
    /* BEBD0 001BEBD0 00000000 */   nop
  .L001BEBD4:
    /* BEBD4 001BEBD4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BEBD8 001BEBD8 00008244 */  mtc1       $2, $f0
    /* BEBDC 001BEBDC 00000000 */  nop
    /* BEBE0 001BEBE0 36001546 */  c.le.s     $f0, $f21
    /* BEBE4 001BEBE4 0B000045 */  bc1f       .L001BEC14
    /* BEBE8 001BEBE8 00000000 */   nop
    /* BEBEC 001BEBEC 8800A3C7 */  lwc1       $f3, 0x88($29)
    /* BEBF0 001BEBF0 8C00A2C7 */  lwc1       $f2, 0x8C($29)
    /* BEBF4 001BEBF4 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* BEBF8 001BEBF8 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* BEBFC 001BEBFC E000A3E7 */  swc1       $f3, 0xE0($29)
    /* BEC00 001BEC00 E400A2E7 */  swc1       $f2, 0xE4($29)
    /* BEC04 001BEC04 E800A1E7 */  swc1       $f1, 0xE8($29)
    /* BEC08 001BEC08 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* BEC0C 001BEC0C 46000010 */  b          .L001BED28
    /* BEC10 001BEC10 00000000 */   nop
  .L001BEC14:
    /* BEC14 001BEC14 01001546 */  sub.s      $f0, $f0, $f21
    /* BEC18 001BEC18 C400A28F */  lw         $2, 0xC4($29)
    /* BEC1C 001BEC1C 26004014 */  bnez       $2, .L001BECB8
    /* BEC20 001BEC20 00000000 */   nop
    /* BEC24 001BEC24 C000AAC7 */  lwc1       $f10, 0xC0($29)
    /* BEC28 001BEC28 02010A46 */  mul.s      $f4, $f0, $f10
    /* BEC2C 001BEC2C C2200446 */  mul.s      $f3, $f4, $f4
    /* BEC30 001BEC30 948189C7 */  lwc1       $f9, -0x7E6C($28)
    /* BEC34 001BEC34 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* BEC38 001BEC38 18580846 */  adda.s     $f11, $f8
    /* BEC3C 001BEC3C 1C480346 */  madd.s     $f0, $f9, $f3
    /* BEC40 001BEC40 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* BEC44 001BEC44 18580746 */  adda.s     $f11, $f7
    /* BEC48 001BEC48 1C180046 */  madd.s     $f0, $f3, $f0
    /* BEC4C 001BEC4C 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* BEC50 001BEC50 18580646 */  adda.s     $f11, $f6
    /* BEC54 001BEC54 1C180046 */  madd.s     $f0, $f3, $f0
    /* BEC58 001BEC58 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* BEC5C 001BEC5C 18580546 */  adda.s     $f11, $f5
    /* BEC60 001BEC60 1C180046 */  madd.s     $f0, $f3, $f0
    /* BEC64 001BEC64 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* BEC68 001BEC68 18580246 */  adda.s     $f11, $f2
    /* BEC6C 001BEC6C 5C180046 */  madd.s     $f1, $f3, $f0
    /* BEC70 001BEC70 02180446 */  mul.s      $f0, $f3, $f4
    /* BEC74 001BEC74 18580446 */  adda.s     $f11, $f4
    /* BEC78 001BEC78 1C000146 */  madd.s     $f0, $f0, $f1
    /* BEC7C 001BEC7C 02A90A46 */  mul.s      $f4, $f21, $f10
    /* BEC80 001BEC80 C2200446 */  mul.s      $f3, $f4, $f4
    /* BEC84 001BEC84 18580846 */  adda.s     $f11, $f8
    /* BEC88 001BEC88 5C480346 */  madd.s     $f1, $f9, $f3
    /* BEC8C 001BEC8C 18580746 */  adda.s     $f11, $f7
    /* BEC90 001BEC90 5C180146 */  madd.s     $f1, $f3, $f1
    /* BEC94 001BEC94 18580646 */  adda.s     $f11, $f6
    /* BEC98 001BEC98 5C180146 */  madd.s     $f1, $f3, $f1
    /* BEC9C 001BEC9C 18580546 */  adda.s     $f11, $f5
    /* BECA0 001BECA0 5C180146 */  madd.s     $f1, $f3, $f1
    /* BECA4 001BECA4 18580246 */  adda.s     $f11, $f2
    /* BECA8 001BECA8 9C180146 */  madd.s     $f2, $f3, $f1
    /* BECAC 001BECAC 42180446 */  mul.s      $f1, $f3, $f4
    /* BECB0 001BECB0 18580446 */  adda.s     $f11, $f4
    /* BECB4 001BECB4 5C0D0246 */  madd.s     $f21, $f1, $f2
  .L001BECB8:
    /* BECB8 001BECB8 A000A1C7 */  lwc1       $f1, 0xA0($29)
    /* BECBC 001BECBC 42090046 */  mul.s      $f5, $f1, $f0
    /* BECC0 001BECC0 E000A5E7 */  swc1       $f5, 0xE0($29)
    /* BECC4 001BECC4 A400A1C7 */  lwc1       $f1, 0xA4($29)
    /* BECC8 001BECC8 02090046 */  mul.s      $f4, $f1, $f0
    /* BECCC 001BECCC E400A4E7 */  swc1       $f4, 0xE4($29)
    /* BECD0 001BECD0 A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* BECD4 001BECD4 C2080046 */  mul.s      $f3, $f1, $f0
    /* BECD8 001BECD8 E800A3E7 */  swc1       $f3, 0xE8($29)
    /* BECDC 001BECDC B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* BECE0 001BECE0 00108044 */  mtc1       $0, $f2
    /* BECE4 001BECE4 00000000 */  nop
    /* BECE8 001BECE8 18100546 */  adda.s     $f2, $f5
    /* BECEC 001BECEC 5C081546 */  madd.s     $f1, $f1, $f21
    /* BECF0 001BECF0 E000A1E7 */  swc1       $f1, 0xE0($29)
    /* BECF4 001BECF4 B400A1C7 */  lwc1       $f1, 0xB4($29)
    /* BECF8 001BECF8 18100446 */  adda.s     $f2, $f4
    /* BECFC 001BECFC 5C081546 */  madd.s     $f1, $f1, $f21
    /* BED00 001BED00 E400A1E7 */  swc1       $f1, 0xE4($29)
    /* BED04 001BED04 B800A1C7 */  lwc1       $f1, 0xB8($29)
    /* BED08 001BED08 18100346 */  adda.s     $f2, $f3
    /* BED0C 001BED0C 5C081546 */  madd.s     $f1, $f1, $f21
    /* BED10 001BED10 E800A1E7 */  swc1       $f1, 0xE8($29)
    /* BED14 001BED14 AC00A2C7 */  lwc1       $f2, 0xAC($29)
    /* BED18 001BED18 BC00A1C7 */  lwc1       $f1, 0xBC($29)
    /* BED1C 001BED1C 1A081546 */  mula.s     $f1, $f21
    /* BED20 001BED20 1C100046 */  madd.s     $f0, $f2, $f0
    /* BED24 001BED24 EC00A0E7 */  swc1       $f0, 0xEC($29)
  .L001BED28:
    /* BED28 001BED28 8001A427 */  addiu      $4, $29, 0x180
    /* BED2C 001BED2C 6100053C */  lui        $5, %hi(D_0060A100)
    /* BED30 001BED30 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* BED34 001BED34 01000624 */  addiu      $6, $0, 0x1
    /* BED38 001BED38 E000A727 */  addiu      $7, $29, 0xE0
    /* BED3C 001BED3C D0720F0C */  jal        func_003dcb40
    /* BED40 001BED40 00000000 */   nop
    /* BED44 001BED44 4001A1C7 */  lwc1       $f1, 0x140($29)
    /* BED48 001BED48 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* BED4C 001BED4C 00080046 */  add.s      $f0, $f1, $f0
    /* BED50 001BED50 9001A0E7 */  swc1       $f0, 0x190($29)
    /* BED54 001BED54 4401A1C7 */  lwc1       $f1, 0x144($29)
    /* BED58 001BED58 8401A0C7 */  lwc1       $f0, 0x184($29)
    /* BED5C 001BED5C 00080046 */  add.s      $f0, $f1, $f0
    /* BED60 001BED60 9401A0E7 */  swc1       $f0, 0x194($29)
    /* BED64 001BED64 4801A1C7 */  lwc1       $f1, 0x148($29)
    /* BED68 001BED68 8801A0C7 */  lwc1       $f0, 0x188($29)
    /* BED6C 001BED6C 00080046 */  add.s      $f0, $f1, $f0
    /* BED70 001BED70 9801A0E7 */  swc1       $f0, 0x198($29)
    /* BED74 001BED74 8800A427 */  addiu      $4, $29, 0x88
    /* BED78 001BED78 9001A527 */  addiu      $5, $29, 0x190
    /* BED7C 001BED7C 4001A627 */  addiu      $6, $29, 0x140
    /* BED80 001BED80 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BED84 001BED84 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BED88 001BED88 E0F5060C */  jal        func_001bd780
    /* BED8C 001BED8C 00000000 */   nop
  .L001BED90:
    /* BED90 001BED90 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* BED94 001BED94 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* BED98 001BED98 01080046 */  sub.s      $f0, $f1, $f0
    /* BED9C 001BED9C 8001A0E7 */  swc1       $f0, 0x180($29)
    /* BEDA0 001BEDA0 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* BEDA4 001BEDA4 4401A0C7 */  lwc1       $f0, 0x144($29)
    /* BEDA8 001BEDA8 01080046 */  sub.s      $f0, $f1, $f0
    /* BEDAC 001BEDAC 8401A0E7 */  swc1       $f0, 0x184($29)
    /* BEDB0 001BEDB0 6800A1C7 */  lwc1       $f1, 0x68($29)
    /* BEDB4 001BEDB4 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* BEDB8 001BEDB8 01080046 */  sub.s      $f0, $f1, $f0
    /* BEDBC 001BEDBC 8801A0E7 */  swc1       $f0, 0x188($29)
    /* BEDC0 001BEDC0 8001A427 */  addiu      $4, $29, 0x180
    /* BEDC4 001BEDC4 2D288000 */  daddu      $5, $4, $0
    /* BEDC8 001BEDC8 2C900F0C */  jal        func_003e40b0
    /* BEDCC 001BEDCC 00000000 */   nop
    /* BEDD0 001BEDD0 708181C7 */  lwc1       $f1, -0x7E90($28)
    /* BEDD4 001BEDD4 42050146 */  mul.s      $f21, $f0, $f1
    /* BEDD8 001BEDD8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BEDDC 001BEDDC 00088244 */  mtc1       $2, $f1
    /* BEDE0 001BEDE0 B80060C6 */  lwc1       $f0, 0xB8($19)
    /* BEDE4 001BEDE4 020B0046 */  mul.s      $f12, $f1, $f0
    /* BEDE8 001BEDE8 1A2E110C */  jal        func_0044b868
    /* BEDEC 001BEDEC 00000000 */   nop
    /* BEDF0 001BEDF0 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* BEDF4 001BEDF4 00088244 */  mtc1       $2, $f1
    /* BEDF8 001BEDF8 00000000 */  nop
    /* BEDFC 001BEDFC 42081646 */  mul.s      $f1, $f1, $f22
    /* BEE00 001BEE00 03080046 */  div.s      $f0, $f1, $f0
    /* BEE04 001BEE04 00000000 */  nop
    /* BEE08 001BEE08 00000000 */  nop
    /* BEE0C 001BEE0C 36001546 */  c.le.s     $f0, $f21
    /* BEE10 001BEE10 02000145 */  bc1t       .L001BEE1C
    /* BEE14 001BEE14 00000000 */   nop
    /* BEE18 001BEE18 46050046 */  mov.s      $f21, $f0
  .L001BEE1C:
    /* BEE1C 001BEE1C 26020224 */  addiu      $2, $0, 0x226
    /* BEE20 001BEE20 00008244 */  mtc1       $2, $f0
    /* BEE24 001BEE24 00000000 */  nop
    /* BEE28 001BEE28 20008046 */  cvt.s.w    $f0, $f0
    /* BEE2C 001BEE2C 34A80046 */  c.lt.s     $f21, $f0
    /* BEE30 001BEE30 02000045 */  bc1f       .L001BEE3C
    /* BEE34 001BEE34 00000000 */   nop
    /* BEE38 001BEE38 46050046 */  mov.s      $f21, $f0
  .L001BEE3C:
    /* BEE3C 001BEE3C 8001A427 */  addiu      $4, $29, 0x180
    /* BEE40 001BEE40 6100053C */  lui        $5, %hi(D_0060A100)
    /* BEE44 001BEE44 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* BEE48 001BEE48 01000624 */  addiu      $6, $0, 0x1
    /* BEE4C 001BEE4C 8800A727 */  addiu      $7, $29, 0x88
    /* BEE50 001BEE50 D0720F0C */  jal        func_003dcb40
    /* BEE54 001BEE54 00000000 */   nop
    /* BEE58 001BEE58 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* BEE5C 001BEE5C C2001546 */  mul.s      $f3, $f0, $f21
    /* BEE60 001BEE60 9001A3E7 */  swc1       $f3, 0x190($29)
    /* BEE64 001BEE64 8401A0C7 */  lwc1       $f0, 0x184($29)
    /* BEE68 001BEE68 82001546 */  mul.s      $f2, $f0, $f21
    /* BEE6C 001BEE6C 9401A2E7 */  swc1       $f2, 0x194($29)
    /* BEE70 001BEE70 8801A0C7 */  lwc1       $f0, 0x188($29)
    /* BEE74 001BEE74 42001546 */  mul.s      $f1, $f0, $f21
    /* BEE78 001BEE78 9801A1E7 */  swc1       $f1, 0x198($29)
    /* BEE7C 001BEE7C 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* BEE80 001BEE80 00000346 */  add.s      $f0, $f0, $f3
    /* BEE84 001BEE84 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* BEE88 001BEE88 4401A0C7 */  lwc1       $f0, 0x144($29)
    /* BEE8C 001BEE8C 00000246 */  add.s      $f0, $f0, $f2
    /* BEE90 001BEE90 8000A0E7 */  swc1       $f0, 0x80($29)
    /* BEE94 001BEE94 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* BEE98 001BEE98 00000146 */  add.s      $f0, $f0, $f1
    /* BEE9C 001BEE9C 8400A0E7 */  swc1       $f0, 0x84($29)
    /* BEEA0 001BEEA0 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* BEEA4 001BEEA4 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* BEEA8 001BEEA8 00008244 */  mtc1       $2, $f0
    /* BEEAC 001BEEAC 00000000 */  nop
    /* BEEB0 001BEEB0 34080046 */  c.lt.s     $f1, $f0
    /* BEEB4 001BEEB4 02000045 */  bc1f       .L001BEEC0
    /* BEEB8 001BEEB8 00000000 */   nop
    /* BEEBC 001BEEBC 6400A0E7 */  swc1       $f0, 0x64($29)
  .L001BEEC0:
    /* BEEC0 001BEEC0 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* BEEC4 001BEEC4 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* BEEC8 001BEEC8 00008244 */  mtc1       $2, $f0
    /* BEECC 001BEECC 00000000 */  nop
    /* BEED0 001BEED0 34080046 */  c.lt.s     $f1, $f0
    /* BEED4 001BEED4 02000045 */  bc1f       .L001BEEE0
    /* BEED8 001BEED8 00000000 */   nop
    /* BEEDC 001BEEDC 8000A0E7 */  swc1       $f0, 0x80($29)
  .L001BEEE0:
    /* BEEE0 001BEEE0 6C00A427 */  addiu      $4, $29, 0x6C
    /* BEEE4 001BEEE4 8800A527 */  addiu      $5, $29, 0x88
    /* BEEE8 001BEEE8 ACB0070C */  jal        func_001ec2b0
    /* BEEEC 001BEEEC 00000000 */   nop
    /* BEEF0 001BEEF0 308195C7 */  lwc1       $f21, -0x7ED0($28)
    /* BEEF4 001BEEF4 00088044 */  mtc1       $0, $f1
    /* BEEF8 001BEEF8 00000000 */  nop
    /* BEEFC 001BEEFC 36000146 */  c.le.s     $f0, $f1
    /* BEF00 001BEF00 14000145 */  bc1t       .L001BEF54
    /* BEF04 001BEF04 00000000 */   nop
    /* BEF08 001BEF08 00000000 */  nop
    /* BEF0C 001BEF0C 00000000 */  nop
    /* BEF10 001BEF10 43A00046 */  div.s      $f1, $f20, $f0
    /* BEF14 001BEF14 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BEF18 001BEF18 00008244 */  mtc1       $2, $f0
    /* BEF1C 001BEF1C 00000000 */  nop
    /* BEF20 001BEF20 36080046 */  c.le.s     $f1, $f0
    /* BEF24 001BEF24 05000145 */  bc1t       .L001BEF3C
    /* BEF28 001BEF28 00000000 */   nop
    /* BEF2C 001BEF2C 688180C7 */  lwc1       $f0, -0x7E98($28)
    /* BEF30 001BEF30 420D0046 */  mul.s      $f21, $f1, $f0
    /* BEF34 001BEF34 02000010 */  b          .L001BEF40
    /* BEF38 001BEF38 00000000 */   nop
  .L001BEF3C:
    /* BEF3C 001BEF3C 688195C7 */  lwc1       $f21, -0x7E98($28)
  .L001BEF40:
    /* BEF40 001BEF40 308180C7 */  lwc1       $f0, -0x7ED0($28)
    /* BEF44 001BEF44 36A80046 */  c.le.s     $f21, $f0
    /* BEF48 001BEF48 02000145 */  bc1t       .L001BEF54
    /* BEF4C 001BEF4C 00000000 */   nop
    /* BEF50 001BEF50 46050046 */  mov.s      $f21, $f0
  .L001BEF54:
    /* BEF54 001BEF54 2D206002 */  daddu      $4, $19, $0
    /* BEF58 001BEF58 6000A527 */  addiu      $5, $29, 0x60
    /* BEF5C 001BEF5C 7C00A627 */  addiu      $6, $29, 0x7C
    /* BEF60 001BEF60 01000724 */  addiu      $7, $0, 0x1
    /* BEF64 001BEF64 08EB060C */  jal        func_001bac20
    /* BEF68 001BEF68 00000000 */   nop
    /* BEF6C 001BEF6C 2D206002 */  daddu      $4, $19, $0
    /* BEF70 001BEF70 06AB0046 */  mov.s      $f12, $f21
    /* BEF74 001BEF74 BCEF060C */  jal        func_001bbef0
    /* BEF78 001BEF78 00000000 */   nop
    /* BEF7C 001BEF7C F9000010 */  b          .L001BF364
    /* BEF80 001BEF80 00000000 */   nop
  .L001BEF84:
    /* BEF84 001BEF84 FCC3070C */  jal        func_001f0ff0
    /* BEF88 001BEF88 00000000 */   nop
    /* BEF8C 001BEF8C 2D804000 */  daddu      $16, $2, $0
    /* BEF90 001BEF90 2D202002 */  daddu      $4, $17, $0
    /* BEF94 001BEF94 4001A527 */  addiu      $5, $29, 0x140
    /* BEF98 001BEF98 1456060C */  jal        func_00195850
    /* BEF9C 001BEF9C 00000000 */   nop
    /* BEFA0 001BEFA0 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* BEFA4 001BEFA4 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* BEFA8 001BEFA8 C2080046 */  mul.s      $f3, $f1, $f0
    /* BEFAC 001BEFAC 288182C7 */  lwc1       $f2, -0x7ED8($28)
    /* BEFB0 001BEFB0 4401A1C7 */  lwc1       $f1, 0x144($29)
    /* BEFB4 001BEFB4 00008044 */  mtc1       $0, $f0
    /* BEFB8 001BEFB8 00000000 */  nop
    /* BEFBC 001BEFBC 18000146 */  adda.s     $f0, $f1
    /* BEFC0 001BEFC0 1C100346 */  madd.s     $f0, $f2, $f3
    /* BEFC4 001BEFC4 4401A0E7 */  swc1       $f0, 0x144($29)
    /* BEFC8 001BEFC8 E000638E */  lw         $3, 0xE0($19)
    /* BEFCC 001BEFCC 6A006294 */  lhu        $2, 0x6A($3)
    /* BEFD0 001BEFD0 01000624 */  addiu      $6, $0, 0x1
    /* BEFD4 001BEFD4 0D004614 */  bne        $2, $6, .L001BF00C
    /* BEFD8 001BEFD8 00000000 */   nop
    /* BEFDC 001BEFDC 3800628C */  lw         $2, 0x38($3)
    /* BEFE0 001BEFE0 3000428C */  lw         $2, 0x30($2)
    /* BEFE4 001BEFE4 09002216 */  bne        $17, $2, .L001BF00C
    /* BEFE8 001BEFE8 00000000 */   nop
    /* BEFEC 001BEFEC 6001A427 */  addiu      $4, $29, 0x160
    /* BEFF0 001BEFF0 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* BEFF4 001BEFF4 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* BEFF8 001BEFF8 1C002726 */  addiu      $7, $17, 0x1C
    /* BEFFC 001BEFFC D0720F0C */  jal        func_003dcb40
    /* BF000 001BF000 00000000 */   nop
    /* BF004 001BF004 21000010 */  b          .L001BF08C
    /* BF008 001BF008 00000000 */   nop
  .L001BF00C:
    /* BF00C 001BF00C 08000012 */  beqz       $16, .L001BF030
    /* BF010 001BF010 00000000 */   nop
    /* BF014 001BF014 3800628C */  lw         $2, 0x38($3)
    /* BF018 001BF018 3000448C */  lw         $4, 0x30($2)
    /* BF01C 001BF01C 3001A527 */  addiu      $5, $29, 0x130
    /* BF020 001BF020 1456060C */  jal        func_00195850
    /* BF024 001BF024 00000000 */   nop
    /* BF028 001BF028 0C000010 */  b          .L001BF05C
    /* BF02C 001BF02C 00000000 */   nop
  .L001BF030:
    /* BF030 001BF030 38006424 */  addiu      $4, $3, 0x38
    /* BF034 001BF034 10AD070C */  jal        func_001eb440
    /* BF038 001BF038 00000000 */   nop
    /* BF03C 001BF03C FFFF4430 */  andi       $4, $2, 0xFFFF
    /* BF040 001BF040 01000524 */  addiu      $5, $0, 0x1
    /* BF044 001BF044 3001A627 */  addiu      $6, $29, 0x130
    /* BF048 001BF048 2D380000 */  daddu      $7, $0, $0
    /* BF04C 001BF04C 2D400000 */  daddu      $8, $0, $0
    /* BF050 001BF050 2D48A000 */  daddu      $9, $5, $0
    /* BF054 001BF054 1058060C */  jal        func_00196040
    /* BF058 001BF058 00000000 */   nop
  .L001BF05C:
    /* BF05C 001BF05C D000A427 */  addiu      $4, $29, 0xD0
    /* BF060 001BF060 4001A527 */  addiu      $5, $29, 0x140
    /* BF064 001BF064 3001A627 */  addiu      $6, $29, 0x130
    /* BF068 001BF068 70B0070C */  jal        func_001ec1c0
    /* BF06C 001BF06C 00000000 */   nop
    /* BF070 001BF070 6001A427 */  addiu      $4, $29, 0x160
    /* BF074 001BF074 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* BF078 001BF078 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* BF07C 001BF07C 01000624 */  addiu      $6, $0, 0x1
    /* BF080 001BF080 D000A727 */  addiu      $7, $29, 0xD0
    /* BF084 001BF084 D0720F0C */  jal        func_003dcb40
    /* BF088 001BF088 00000000 */   nop
  .L001BF08C:
    /* BF08C 001BF08C 2C0021C6 */  lwc1       $f1, 0x2C($17)
    /* BF090 001BF090 900020C6 */  lwc1       $f0, 0x90($17)
    /* BF094 001BF094 42000146 */  mul.s      $f1, $f0, $f1
    /* BF098 001BF098 8040023C */  lui        $2, (0x40800000 >> 16)
    /* BF09C 001BF09C 00008244 */  mtc1       $2, $f0
    /* BF0A0 001BF0A0 00000000 */  nop
    /* BF0A4 001BF0A4 82050146 */  mul.s      $f22, $f0, $f1
    /* BF0A8 001BF0A8 2040023C */  lui        $2, (0x40200000 >> 16)
    /* BF0AC 001BF0AC 00008244 */  mtc1       $2, $f0
    /* BF0B0 001BF0B0 00000000 */  nop
    /* BF0B4 001BF0B4 02050146 */  mul.s      $f20, $f0, $f1
    /* BF0B8 001BF0B8 03000424 */  addiu      $4, $0, 0x3
    /* BF0BC 001BF0BC 5CC7080C */  jal        func_00231d70
    /* BF0C0 001BF0C0 00000000 */   nop
    /* BF0C4 001BF0C4 01000324 */  addiu      $3, $0, 0x1
    /* BF0C8 001BF0C8 09004310 */  beq        $2, $3, .L001BF0F0
    /* BF0CC 001BF0CC 00000000 */   nop
    /* BF0D0 001BF0D0 03004010 */  beqz       $2, .L001BF0E0
    /* BF0D4 001BF0D4 00000000 */   nop
    /* BF0D8 001BF0D8 09000010 */  b          .L001BF100
    /* BF0DC 001BF0DC 00000000 */   nop
  .L001BF0E0:
    /* BF0E0 001BF0E0 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* BF0E4 001BF0E4 00A88244 */  mtc1       $2, $f21
    /* BF0E8 001BF0E8 06000010 */  b          .L001BF104
    /* BF0EC 001BF0EC 00000000 */   nop
  .L001BF0F0:
    /* BF0F0 001BF0F0 F0C1023C */  lui        $2, (0xC1F00000 >> 16)
    /* BF0F4 001BF0F4 00A88244 */  mtc1       $2, $f21
    /* BF0F8 001BF0F8 02000010 */  b          .L001BF104
    /* BF0FC 001BF0FC 00000000 */   nop
  .L001BF100:
    /* BF100 001BF100 00A88044 */  mtc1       $0, $f21
  .L001BF104:
    /* BF104 001BF104 03000424 */  addiu      $4, $0, 0x3
    /* BF108 001BF108 5CC7080C */  jal        func_00231d70
    /* BF10C 001BF10C 00000000 */   nop
    /* BF110 001BF110 01000324 */  addiu      $3, $0, 0x1
    /* BF114 001BF114 09004310 */  beq        $2, $3, .L001BF13C
    /* BF118 001BF118 00000000 */   nop
    /* BF11C 001BF11C 03004010 */  beqz       $2, .L001BF12C
    /* BF120 001BF120 00000000 */   nop
    /* BF124 001BF124 09000010 */  b          .L001BF14C
    /* BF128 001BF128 00000000 */   nop
  .L001BF12C:
    /* BF12C 001BF12C 7041023C */  lui        $2, (0x41700000 >> 16)
    /* BF130 001BF130 00608244 */  mtc1       $2, $f12
    /* BF134 001BF134 06000010 */  b          .L001BF150
    /* BF138 001BF138 00000000 */   nop
  .L001BF13C:
    /* BF13C 001BF13C 70C1023C */  lui        $2, (0xC1700000 >> 16)
    /* BF140 001BF140 00608244 */  mtc1       $2, $f12
    /* BF144 001BF144 02000010 */  b          .L001BF150
    /* BF148 001BF148 00000000 */   nop
  .L001BF14C:
    /* BF14C 001BF14C 00608044 */  mtc1       $0, $f12
  .L001BF150:
    /* BF150 001BF150 F000A427 */  addiu      $4, $29, 0xF0
    /* BF154 001BF154 6100053C */  lui        $5, %hi(D_0060A0D0)
    /* BF158 001BF158 D0A0A524 */  addiu      $5, $5, %lo(D_0060A0D0)
    /* BF15C 001BF15C 2D300000 */  daddu      $6, $0, $0
    /* BF160 001BF160 1C820F0C */  jal        func_003e0870
    /* BF164 001BF164 00000000 */   nop
    /* BF168 001BF168 F000A427 */  addiu      $4, $29, 0xF0
    /* BF16C 001BF16C 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* BF170 001BF170 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* BF174 001BF174 06AB0046 */  mov.s      $f12, $f21
    /* BF178 001BF178 02000624 */  addiu      $6, $0, 0x2
    /* BF17C 001BF17C 1C820F0C */  jal        func_003e0870
    /* BF180 001BF180 00000000 */   nop
    /* BF184 001BF184 8001A427 */  addiu      $4, $29, 0x180
    /* BF188 001BF188 6001A527 */  addiu      $5, $29, 0x160
    /* BF18C 001BF18C F000A627 */  addiu      $6, $29, 0xF0
    /* BF190 001BF190 C8900F0C */  jal        func_003e4320
    /* BF194 001BF194 00000000 */   nop
    /* BF198 001BF198 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BF19C 001BF19C 00088244 */  mtc1       $2, $f1
    /* BF1A0 001BF1A0 B80060C6 */  lwc1       $f0, 0xB8($19)
    /* BF1A4 001BF1A4 42080046 */  mul.s      $f1, $f1, $f0
    /* BF1A8 001BF1A8 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* BF1AC 001BF1AC 02030146 */  mul.s      $f12, $f0, $f1
    /* BF1B0 001BF1B0 1A2E110C */  jal        func_0044b868
    /* BF1B4 001BF1B4 00000000 */   nop
    /* BF1B8 001BF1B8 00000000 */  nop
    /* BF1BC 001BF1BC 00000000 */  nop
    /* BF1C0 001BF1C0 43B00046 */  div.s      $f1, $f22, $f0
    /* BF1C4 001BF1C4 8001A0C7 */  lwc1       $f0, 0x180($29)
    /* BF1C8 001BF1C8 42010146 */  mul.s      $f5, $f0, $f1
    /* BF1CC 001BF1CC 8001A5E7 */  swc1       $f5, 0x180($29)
    /* BF1D0 001BF1D0 8401A0C7 */  lwc1       $f0, 0x184($29)
    /* BF1D4 001BF1D4 02010146 */  mul.s      $f4, $f0, $f1
    /* BF1D8 001BF1D8 8401A4E7 */  swc1       $f4, 0x184($29)
    /* BF1DC 001BF1DC 8801A0C7 */  lwc1       $f0, 0x188($29)
    /* BF1E0 001BF1E0 C2000146 */  mul.s      $f3, $f0, $f1
    /* BF1E4 001BF1E4 8801A3E7 */  swc1       $f3, 0x188($29)
    /* BF1E8 001BF1E8 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* BF1EC 001BF1EC 5001A0E7 */  swc1       $f0, 0x150($29)
    /* BF1F0 001BF1F0 4401A2C7 */  lwc1       $f2, 0x144($29)
    /* BF1F4 001BF1F4 5401A2E7 */  swc1       $f2, 0x154($29)
    /* BF1F8 001BF1F8 4801A1C7 */  lwc1       $f1, 0x148($29)
    /* BF1FC 001BF1FC 5801A1E7 */  swc1       $f1, 0x158($29)
    /* BF200 001BF200 00000546 */  add.s      $f0, $f0, $f5
    /* BF204 001BF204 6000A0E7 */  swc1       $f0, 0x60($29)
    /* BF208 001BF208 00100446 */  add.s      $f0, $f2, $f4
    /* BF20C 001BF20C 6400A0E7 */  swc1       $f0, 0x64($29)
    /* BF210 001BF210 00080346 */  add.s      $f0, $f1, $f3
    /* BF214 001BF214 6800A0E7 */  swc1       $f0, 0x68($29)
    /* BF218 001BF218 6C00A427 */  addiu      $4, $29, 0x6C
    /* BF21C 001BF21C 6000A527 */  addiu      $5, $29, 0x60
    /* BF220 001BF220 5001A627 */  addiu      $6, $29, 0x150
    /* BF224 001BF224 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BF228 001BF228 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BF22C 001BF22C E0F5060C */  jal        func_001bd780
    /* BF230 001BF230 00000000 */   nop
    /* BF234 001BF234 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BF238 001BF238 00088244 */  mtc1       $2, $f1
    /* BF23C 001BF23C B80060C6 */  lwc1       $f0, 0xB8($19)
    /* BF240 001BF240 42080046 */  mul.s      $f1, $f1, $f0
    /* BF244 001BF244 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* BF248 001BF248 02030146 */  mul.s      $f12, $f0, $f1
    /* BF24C 001BF24C 1A2E110C */  jal        func_0044b868
    /* BF250 001BF250 00000000 */   nop
    /* BF254 001BF254 00000000 */  nop
    /* BF258 001BF258 00000000 */  nop
    /* BF25C 001BF25C 43A00046 */  div.s      $f1, $f20, $f0
    /* BF260 001BF260 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* BF264 001BF264 42010146 */  mul.s      $f5, $f0, $f1
    /* BF268 001BF268 8001A5E7 */  swc1       $f5, 0x180($29)
    /* BF26C 001BF26C 6401A0C7 */  lwc1       $f0, 0x164($29)
    /* BF270 001BF270 02010146 */  mul.s      $f4, $f0, $f1
    /* BF274 001BF274 8401A4E7 */  swc1       $f4, 0x184($29)
    /* BF278 001BF278 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* BF27C 001BF27C C2000146 */  mul.s      $f3, $f0, $f1
    /* BF280 001BF280 8801A3E7 */  swc1       $f3, 0x188($29)
    /* BF284 001BF284 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* BF288 001BF288 5001A0E7 */  swc1       $f0, 0x150($29)
    /* BF28C 001BF28C 4401A2C7 */  lwc1       $f2, 0x144($29)
    /* BF290 001BF290 5401A2E7 */  swc1       $f2, 0x154($29)
    /* BF294 001BF294 4801A1C7 */  lwc1       $f1, 0x148($29)
    /* BF298 001BF298 5801A1E7 */  swc1       $f1, 0x158($29)
    /* BF29C 001BF29C 00000546 */  add.s      $f0, $f0, $f5
    /* BF2A0 001BF2A0 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* BF2A4 001BF2A4 00100446 */  add.s      $f0, $f2, $f4
    /* BF2A8 001BF2A8 8000A0E7 */  swc1       $f0, 0x80($29)
    /* BF2AC 001BF2AC 00080346 */  add.s      $f0, $f1, $f3
    /* BF2B0 001BF2B0 8400A0E7 */  swc1       $f0, 0x84($29)
    /* BF2B4 001BF2B4 8800A427 */  addiu      $4, $29, 0x88
    /* BF2B8 001BF2B8 7C00A527 */  addiu      $5, $29, 0x7C
    /* BF2BC 001BF2BC 5001A627 */  addiu      $6, $29, 0x150
    /* BF2C0 001BF2C0 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BF2C4 001BF2C4 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BF2C8 001BF2C8 E0F5060C */  jal        func_001bd780
    /* BF2CC 001BF2CC 00000000 */   nop
    /* BF2D0 001BF2D0 2D202002 */  daddu      $4, $17, $0
    /* BF2D4 001BF2D4 FCDC060C */  jal        func_001b73f0
    /* BF2D8 001BF2D8 00000000 */   nop
    /* BF2DC 001BF2DC 00608044 */  mtc1       $0, $f12
    /* BF2E0 001BF2E0 E000648E */  lw         $4, 0xE0($19)
    /* BF2E4 001BF2E4 2D280000 */  daddu      $5, $0, $0
    /* BF2E8 001BF2E8 2D300000 */  daddu      $6, $0, $0
    /* BF2EC 001BF2EC 01000724 */  addiu      $7, $0, 0x1
    /* BF2F0 001BF2F0 50F3060C */  jal        func_001bcd40
    /* BF2F4 001BF2F4 00000000 */   nop
    /* BF2F8 001BF2F8 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* BF2FC 001BF2FC C841023C */  lui        $2, (0x41C80000 >> 16)
    /* BF300 001BF300 00008244 */  mtc1       $2, $f0
    /* BF304 001BF304 00000000 */  nop
    /* BF308 001BF308 34080046 */  c.lt.s     $f1, $f0
    /* BF30C 001BF30C 02000045 */  bc1f       .L001BF318
    /* BF310 001BF310 00000000 */   nop
    /* BF314 001BF314 6400A0E7 */  swc1       $f0, 0x64($29)
  .L001BF318:
    /* BF318 001BF318 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* BF31C 001BF31C C841023C */  lui        $2, (0x41C80000 >> 16)
    /* BF320 001BF320 00008244 */  mtc1       $2, $f0
    /* BF324 001BF324 00000000 */  nop
    /* BF328 001BF328 34080046 */  c.lt.s     $f1, $f0
    /* BF32C 001BF32C 02000045 */  bc1f       .L001BF338
    /* BF330 001BF330 00000000 */   nop
    /* BF334 001BF334 8000A0E7 */  swc1       $f0, 0x80($29)
  .L001BF338:
    /* BF338 001BF338 2D206002 */  daddu      $4, $19, $0
    /* BF33C 001BF33C 6000A527 */  addiu      $5, $29, 0x60
    /* BF340 001BF340 7C00A627 */  addiu      $6, $29, 0x7C
    /* BF344 001BF344 01000724 */  addiu      $7, $0, 0x1
    /* BF348 001BF348 08EB060C */  jal        func_001bac20
    /* BF34C 001BF34C 00000000 */   nop
    /* BF350 001BF350 E03F023C */  lui        $2, (0x3FE00000 >> 16)
    /* BF354 001BF354 00608244 */  mtc1       $2, $f12
    /* BF358 001BF358 2D206002 */  daddu      $4, $19, $0
    /* BF35C 001BF35C BCEF060C */  jal        func_001bbef0
    /* BF360 001BF360 00000000 */   nop
  .L001BF364:
    /* BF364 001BF364 01000224 */  addiu      $2, $0, 0x1
  .L001BF368:
    /* BF368 001BF368 5000BFDF */  ld         $31, 0x50($29)
    /* BF36C 001BF36C 4000B37B */  lq         $19, 0x40($29)
    /* BF370 001BF370 3000B27B */  lq         $18, 0x30($29)
    /* BF374 001BF374 2000B17B */  lq         $17, 0x20($29)
    /* BF378 001BF378 1000B07B */  lq         $16, 0x10($29)
    /* BF37C 001BF37C 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* BF380 001BF380 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* BF384 001BF384 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* BF388 001BF388 A001BD27 */  addiu      $29, $29, 0x1A0
    /* BF38C 001BF38C 0800E003 */  jr         $31
    /* BF390 001BF390 00000000 */   nop
    /* BF394 001BF394 00000000 */  nop
    /* BF398 001BF398 00000000 */  nop
    /* BF39C 001BF39C 00000000 */  nop
.size func_001be990, 0xa10
