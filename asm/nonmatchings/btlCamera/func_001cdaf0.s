.section .text
.set noat
.set noreorder
glabel func_001cdaf0
    /* CDAF0 001CDAF0 10FFBD27 */  addiu      $29, $29, -0xF0
    /* CDAF4 001CDAF4 3000BFFF */  sd         $31, 0x30($29)
    /* CDAF8 001CDAF8 2000B17F */  sq         $17, 0x20($29)
    /* CDAFC 001CDAFC 1000B07F */  sq         $16, 0x10($29)
    /* CDB00 001CDB00 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CDB04 001CDB04 2D808000 */  daddu      $16, $4, $0
    /* CDB08 001CDB08 8000A427 */  addiu      $4, $29, 0x80
    /* CDB0C 001CDB0C 9C000526 */  addiu      $5, $16, 0x9C
    /* CDB10 001CDB10 58F5060C */  jal        func_001bd560
    /* CDB14 001CDB14 00000000 */   nop
    /* CDB18 001CDB18 58C5060C */  jal        func_001b1560
    /* CDB1C 001CDB1C 00000000 */   nop
    /* CDB20 001CDB20 3000518C */  lw         $17, 0x30($2)
    /* CDB24 001CDB24 2D202002 */  daddu      $4, $17, $0
    /* CDB28 001CDB28 E000A527 */  addiu      $5, $29, 0xE0
    /* CDB2C 001CDB2C 1456060C */  jal        func_00195850
    /* CDB30 001CDB30 00000000 */   nop
    /* CDB34 001CDB34 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* CDB38 001CDB38 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CDB3C 001CDB3C C2080046 */  mul.s      $f3, $f1, $f0
    /* CDB40 001CDB40 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CDB44 001CDB44 00108244 */  mtc1       $2, $f2
    /* CDB48 001CDB48 E400A1C7 */  lwc1       $f1, 0xE4($29)
    /* CDB4C 001CDB4C 00008044 */  mtc1       $0, $f0
    /* CDB50 001CDB50 00000000 */  nop
    /* CDB54 001CDB54 18000146 */  adda.s     $f0, $f1
    /* CDB58 001CDB58 1C100346 */  madd.s     $f0, $f2, $f3
    /* CDB5C 001CDB5C E400A0E7 */  swc1       $f0, 0xE4($29)
    /* CDB60 001CDB60 A800A427 */  addiu      $4, $29, 0xA8
    /* CDB64 001CDB64 8000A527 */  addiu      $5, $29, 0x80
    /* CDB68 001CDB68 E000A627 */  addiu      $6, $29, 0xE0
    /* CDB6C 001CDB6C 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CDB70 001CDB70 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CDB74 001CDB74 E0F5060C */  jal        func_001bd780
    /* CDB78 001CDB78 00000000 */   nop
    /* CDB7C 001CDB7C 8000A2C7 */  lwc1       $f2, 0x80($29)
    /* CDB80 001CDB80 8400A1C7 */  lwc1       $f1, 0x84($29)
    /* CDB84 001CDB84 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* CDB88 001CDB88 9C00A2E7 */  swc1       $f2, 0x9C($29)
    /* CDB8C 001CDB8C A000A1E7 */  swc1       $f1, 0xA0($29)
    /* CDB90 001CDB90 A400A0E7 */  swc1       $f0, 0xA4($29)
    /* CDB94 001CDB94 8C00A427 */  addiu      $4, $29, 0x8C
    /* CDB98 001CDB98 A800A527 */  addiu      $5, $29, 0xA8
    /* CDB9C 001CDB9C ACB0070C */  jal        func_001ec2b0
    /* CDBA0 001CDBA0 00000000 */   nop
    /* CDBA4 001CDBA4 848181C7 */  lwc1       $f1, -0x7E7C($28)
    /* CDBA8 001CDBA8 36000146 */  c.le.s     $f0, $f1
    /* CDBAC 001CDBAC 09000145 */  bc1t       .L001CDBD4
    /* CDBB0 001CDBB0 00000000 */   nop
    /* CDBB4 001CDBB4 00000000 */  nop
    /* CDBB8 001CDBB8 00000000 */  nop
    /* CDBBC 001CDBBC 030D0046 */  div.s      $f20, $f1, $f0
    /* CDBC0 001CDBC0 00000000 */  nop
    /* CDBC4 001CDBC4 00000000 */  nop
    /* CDBC8 001CDBC8 00000000 */  nop
    /* CDBCC 001CDBCC 02000010 */  b          .L001CDBD8
    /* CDBD0 001CDBD0 00000000 */   nop
  .L001CDBD4:
    /* CDBD4 001CDBD4 1C8194C7 */  lwc1       $f20, -0x7EE4($28)
  .L001CDBD8:
    /* CDBD8 001CDBD8 8C00A427 */  addiu      $4, $29, 0x8C
    /* CDBDC 001CDBDC A800A527 */  addiu      $5, $29, 0xA8
    /* CDBE0 001CDBE0 5000A627 */  addiu      $6, $29, 0x50
    /* CDBE4 001CDBE4 1C730F0C */  jal        func_003dcc70
    /* CDBE8 001CDBE8 00000000 */   nop
    /* CDBEC 001CDBEC 00588044 */  mtc1       $0, $f11
    /* CDBF0 001CDBF0 00000000 */  nop
    /* CDBF4 001CDBF4 36A00B46 */  c.le.s     $f20, $f11
    /* CDBF8 001CDBF8 0B000045 */  bc1f       .L001CDC28
    /* CDBFC 001CDBFC 00000000 */   nop
    /* CDC00 001CDC00 8C00A3C7 */  lwc1       $f3, 0x8C($29)
    /* CDC04 001CDC04 9000A2C7 */  lwc1       $f2, 0x90($29)
    /* CDC08 001CDC08 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* CDC0C 001CDC0C 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CDC10 001CDC10 4000A3E7 */  swc1       $f3, 0x40($29)
    /* CDC14 001CDC14 4400A2E7 */  swc1       $f2, 0x44($29)
    /* CDC18 001CDC18 4800A1E7 */  swc1       $f1, 0x48($29)
    /* CDC1C 001CDC1C 4C00A0E7 */  swc1       $f0, 0x4C($29)
    /* CDC20 001CDC20 56000010 */  b          .L001CDD7C
    /* CDC24 001CDC24 00000000 */   nop
  .L001CDC28:
    /* CDC28 001CDC28 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* CDC2C 001CDC2C 00008244 */  mtc1       $2, $f0
    /* CDC30 001CDC30 00000000 */  nop
    /* CDC34 001CDC34 36001446 */  c.le.s     $f0, $f20
    /* CDC38 001CDC38 0B000045 */  bc1f       .L001CDC68
    /* CDC3C 001CDC3C 00000000 */   nop
    /* CDC40 001CDC40 A800A3C7 */  lwc1       $f3, 0xA8($29)
    /* CDC44 001CDC44 AC00A2C7 */  lwc1       $f2, 0xAC($29)
    /* CDC48 001CDC48 B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* CDC4C 001CDC4C B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CDC50 001CDC50 4000A3E7 */  swc1       $f3, 0x40($29)
    /* CDC54 001CDC54 4400A2E7 */  swc1       $f2, 0x44($29)
    /* CDC58 001CDC58 4800A1E7 */  swc1       $f1, 0x48($29)
    /* CDC5C 001CDC5C 4C00A0E7 */  swc1       $f0, 0x4C($29)
    /* CDC60 001CDC60 46000010 */  b          .L001CDD7C
    /* CDC64 001CDC64 00000000 */   nop
  .L001CDC68:
    /* CDC68 001CDC68 01001446 */  sub.s      $f0, $f0, $f20
    /* CDC6C 001CDC6C 7400A28F */  lw         $2, 0x74($29)
    /* CDC70 001CDC70 26004014 */  bnez       $2, .L001CDD0C
    /* CDC74 001CDC74 00000000 */   nop
    /* CDC78 001CDC78 7000AAC7 */  lwc1       $f10, 0x70($29)
    /* CDC7C 001CDC7C 02010A46 */  mul.s      $f4, $f0, $f10
    /* CDC80 001CDC80 C2200446 */  mul.s      $f3, $f4, $f4
    /* CDC84 001CDC84 808189C7 */  lwc1       $f9, -0x7E80($28)
    /* CDC88 001CDC88 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* CDC8C 001CDC8C 18580846 */  adda.s     $f11, $f8
    /* CDC90 001CDC90 1C480346 */  madd.s     $f0, $f9, $f3
    /* CDC94 001CDC94 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* CDC98 001CDC98 18580746 */  adda.s     $f11, $f7
    /* CDC9C 001CDC9C 1C180046 */  madd.s     $f0, $f3, $f0
    /* CDCA0 001CDCA0 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* CDCA4 001CDCA4 18580646 */  adda.s     $f11, $f6
    /* CDCA8 001CDCA8 1C180046 */  madd.s     $f0, $f3, $f0
    /* CDCAC 001CDCAC 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* CDCB0 001CDCB0 18580546 */  adda.s     $f11, $f5
    /* CDCB4 001CDCB4 1C180046 */  madd.s     $f0, $f3, $f0
    /* CDCB8 001CDCB8 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* CDCBC 001CDCBC 18580246 */  adda.s     $f11, $f2
    /* CDCC0 001CDCC0 5C180046 */  madd.s     $f1, $f3, $f0
    /* CDCC4 001CDCC4 02180446 */  mul.s      $f0, $f3, $f4
    /* CDCC8 001CDCC8 18580446 */  adda.s     $f11, $f4
    /* CDCCC 001CDCCC 1C000146 */  madd.s     $f0, $f0, $f1
    /* CDCD0 001CDCD0 02A10A46 */  mul.s      $f4, $f20, $f10
    /* CDCD4 001CDCD4 C2200446 */  mul.s      $f3, $f4, $f4
    /* CDCD8 001CDCD8 18580846 */  adda.s     $f11, $f8
    /* CDCDC 001CDCDC 5C480346 */  madd.s     $f1, $f9, $f3
    /* CDCE0 001CDCE0 18580746 */  adda.s     $f11, $f7
    /* CDCE4 001CDCE4 5C180146 */  madd.s     $f1, $f3, $f1
    /* CDCE8 001CDCE8 18580646 */  adda.s     $f11, $f6
    /* CDCEC 001CDCEC 5C180146 */  madd.s     $f1, $f3, $f1
    /* CDCF0 001CDCF0 18580546 */  adda.s     $f11, $f5
    /* CDCF4 001CDCF4 5C180146 */  madd.s     $f1, $f3, $f1
    /* CDCF8 001CDCF8 18580246 */  adda.s     $f11, $f2
    /* CDCFC 001CDCFC 9C180146 */  madd.s     $f2, $f3, $f1
    /* CDD00 001CDD00 42180446 */  mul.s      $f1, $f3, $f4
    /* CDD04 001CDD04 18580446 */  adda.s     $f11, $f4
    /* CDD08 001CDD08 1C0D0246 */  madd.s     $f20, $f1, $f2
  .L001CDD0C:
    /* CDD0C 001CDD0C 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* CDD10 001CDD10 42090046 */  mul.s      $f5, $f1, $f0
    /* CDD14 001CDD14 4000A5E7 */  swc1       $f5, 0x40($29)
    /* CDD18 001CDD18 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* CDD1C 001CDD1C 02090046 */  mul.s      $f4, $f1, $f0
    /* CDD20 001CDD20 4400A4E7 */  swc1       $f4, 0x44($29)
    /* CDD24 001CDD24 5800A1C7 */  lwc1       $f1, 0x58($29)
    /* CDD28 001CDD28 C2080046 */  mul.s      $f3, $f1, $f0
    /* CDD2C 001CDD2C 4800A3E7 */  swc1       $f3, 0x48($29)
    /* CDD30 001CDD30 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* CDD34 001CDD34 00108044 */  mtc1       $0, $f2
    /* CDD38 001CDD38 00000000 */  nop
    /* CDD3C 001CDD3C 18100546 */  adda.s     $f2, $f5
    /* CDD40 001CDD40 5C081446 */  madd.s     $f1, $f1, $f20
    /* CDD44 001CDD44 4000A1E7 */  swc1       $f1, 0x40($29)
    /* CDD48 001CDD48 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* CDD4C 001CDD4C 18100446 */  adda.s     $f2, $f4
    /* CDD50 001CDD50 5C081446 */  madd.s     $f1, $f1, $f20
    /* CDD54 001CDD54 4400A1E7 */  swc1       $f1, 0x44($29)
    /* CDD58 001CDD58 6800A1C7 */  lwc1       $f1, 0x68($29)
    /* CDD5C 001CDD5C 18100346 */  adda.s     $f2, $f3
    /* CDD60 001CDD60 5C081446 */  madd.s     $f1, $f1, $f20
    /* CDD64 001CDD64 4800A1E7 */  swc1       $f1, 0x48($29)
    /* CDD68 001CDD68 5C00A2C7 */  lwc1       $f2, 0x5C($29)
    /* CDD6C 001CDD6C 6C00A1C7 */  lwc1       $f1, 0x6C($29)
    /* CDD70 001CDD70 1A081446 */  mula.s     $f1, $f20
    /* CDD74 001CDD74 1C100046 */  madd.s     $f0, $f2, $f0
    /* CDD78 001CDD78 4C00A0E7 */  swc1       $f0, 0x4C($29)
  .L001CDD7C:
    /* CDD7C 001CDD7C C000A427 */  addiu      $4, $29, 0xC0
    /* CDD80 001CDD80 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* CDD84 001CDD84 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* CDD88 001CDD88 01000624 */  addiu      $6, $0, 0x1
    /* CDD8C 001CDD8C 4000A727 */  addiu      $7, $29, 0x40
    /* CDD90 001CDD90 D0720F0C */  jal        func_003dcb40
    /* CDD94 001CDD94 00000000 */   nop
    /* CDD98 001CDD98 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* CDD9C 001CDD9C C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* CDDA0 001CDDA0 00080046 */  add.s      $f0, $f1, $f0
    /* CDDA4 001CDDA4 D000A0E7 */  swc1       $f0, 0xD0($29)
    /* CDDA8 001CDDA8 8400A1C7 */  lwc1       $f1, 0x84($29)
    /* CDDAC 001CDDAC C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* CDDB0 001CDDB0 00080046 */  add.s      $f0, $f1, $f0
    /* CDDB4 001CDDB4 D400A0E7 */  swc1       $f0, 0xD4($29)
    /* CDDB8 001CDDB8 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* CDDBC 001CDDBC C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* CDDC0 001CDDC0 00080046 */  add.s      $f0, $f1, $f0
    /* CDDC4 001CDDC4 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* CDDC8 001CDDC8 A800A427 */  addiu      $4, $29, 0xA8
    /* CDDCC 001CDDCC 8000A527 */  addiu      $5, $29, 0x80
    /* CDDD0 001CDDD0 D000A627 */  addiu      $6, $29, 0xD0
    /* CDDD4 001CDDD4 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CDDD8 001CDDD8 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CDDDC 001CDDDC E0F5060C */  jal        func_001bd780
    /* CDDE0 001CDDE0 00000000 */   nop
    /* CDDE4 001CDDE4 7042023C */  lui        $2, (0x42700000 >> 16)
    /* CDDE8 001CDDE8 00608244 */  mtc1       $2, $f12
    /* CDDEC 001CDDEC E000048E */  lw         $4, 0xE0($16)
    /* CDDF0 001CDDF0 8000A527 */  addiu      $5, $29, 0x80
    /* CDDF4 001CDDF4 E000A627 */  addiu      $6, $29, 0xE0
    /* CDDF8 001CDDF8 C0080724 */  addiu      $7, $0, 0x8C0
    /* CDDFC 001CDDFC 50F3060C */  jal        func_001bcd40
    /* CDE00 001CDE00 00000000 */   nop
    /* CDE04 001CDE04 2D200002 */  daddu      $4, $16, $0
    /* CDE08 001CDE08 8000A527 */  addiu      $5, $29, 0x80
    /* CDE0C 001CDE0C 9C00A627 */  addiu      $6, $29, 0x9C
    /* CDE10 001CDE10 01000724 */  addiu      $7, $0, 0x1
    /* CDE14 001CDE14 08EB060C */  jal        func_001bac20
    /* CDE18 001CDE18 00000000 */   nop
    /* CDE1C 001CDE1C 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* CDE20 001CDE20 00608244 */  mtc1       $2, $f12
    /* CDE24 001CDE24 2D200002 */  daddu      $4, $16, $0
    /* CDE28 001CDE28 BCEF060C */  jal        func_001bbef0
    /* CDE2C 001CDE2C 00000000 */   nop
    /* CDE30 001CDE30 3000BFDF */  ld         $31, 0x30($29)
    /* CDE34 001CDE34 2000B17B */  lq         $17, 0x20($29)
    /* CDE38 001CDE38 1000B07B */  lq         $16, 0x10($29)
    /* CDE3C 001CDE3C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CDE40 001CDE40 F000BD27 */  addiu      $29, $29, 0xF0
    /* CDE44 001CDE44 0800E003 */  jr         $31
    /* CDE48 001CDE48 00000000 */   nop
    /* CDE4C 001CDE4C 00000000 */  nop
.size func_001cdaf0, 0x360
