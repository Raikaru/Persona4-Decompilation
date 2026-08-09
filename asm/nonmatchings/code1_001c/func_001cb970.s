.section .text
.set noat
.set noreorder
glabel func_001cb970
    /* CB970 001CB970 A0FEBD27 */  addiu      $29, $29, -0x160
    /* CB974 001CB974 8000BFFF */  sd         $31, 0x80($29)
    /* CB978 001CB978 7000B57F */  sq         $21, 0x70($29)
    /* CB97C 001CB97C 6000B47F */  sq         $20, 0x60($29)
    /* CB980 001CB980 5000B37F */  sq         $19, 0x50($29)
    /* CB984 001CB984 4000B27F */  sq         $18, 0x40($29)
    /* CB988 001CB988 3000B17F */  sq         $17, 0x30($29)
    /* CB98C 001CB98C 2000B07F */  sq         $16, 0x20($29)
    /* CB990 001CB990 1000B8E7 */  swc1       $f24, 0x10($29)
    /* CB994 001CB994 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* CB998 001CB998 0800B6E7 */  swc1       $f22, 0x8($29)
    /* CB99C 001CB99C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CB9A0 001CB9A0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CB9A4 001CB9A4 2DA08000 */  daddu      $20, $4, $0
    /* CB9A8 001CB9A8 06660046 */  mov.s      $f24, $f12
    /* CB9AC 001CB9AC 2D98A000 */  daddu      $19, $5, $0
    /* CB9B0 001CB9B0 E000828C */  lw         $2, 0xE0($4)
    /* CB9B4 001CB9B4 3000528C */  lw         $18, 0x30($2)
    /* CB9B8 001CB9B8 3800428C */  lw         $2, 0x38($2)
    /* CB9BC 001CB9BC 3000518C */  lw         $17, 0x30($2)
    /* CB9C0 001CB9C0 2D204002 */  daddu      $4, $18, $0
    /* CB9C4 001CB9C4 5001A527 */  addiu      $5, $29, 0x150
    /* CB9C8 001CB9C8 7456060C */  jal        func_001959d0
    /* CB9CC 001CB9CC 00000000 */   nop
    /* CB9D0 001CB9D0 2D202002 */  daddu      $4, $17, $0
    /* CB9D4 001CB9D4 4001A527 */  addiu      $5, $29, 0x140
    /* CB9D8 001CB9D8 7456060C */  jal        func_001959d0
    /* CB9DC 001CB9DC 00000000 */   nop
    /* CB9E0 001CB9E0 5001A1C7 */  lwc1       $f1, 0x150($29)
    /* CB9E4 001CB9E4 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* CB9E8 001CB9E8 01080046 */  sub.s      $f0, $f1, $f0
    /* CB9EC 001CB9EC 1001A0E7 */  swc1       $f0, 0x110($29)
    /* CB9F0 001CB9F0 5401A1C7 */  lwc1       $f1, 0x154($29)
    /* CB9F4 001CB9F4 4401A0C7 */  lwc1       $f0, 0x144($29)
    /* CB9F8 001CB9F8 01080046 */  sub.s      $f0, $f1, $f0
    /* CB9FC 001CB9FC 1401A0E7 */  swc1       $f0, 0x114($29)
    /* CBA00 001CBA00 5801A1C7 */  lwc1       $f1, 0x158($29)
    /* CBA04 001CBA04 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CBA08 001CBA08 01080046 */  sub.s      $f0, $f1, $f0
    /* CBA0C 001CBA0C 1801A0E7 */  swc1       $f0, 0x118($29)
    /* CBA10 001CBA10 1001A427 */  addiu      $4, $29, 0x110
    /* CBA14 001CBA14 2D288000 */  daddu      $5, $4, $0
    /* CBA18 001CBA18 2C900F0C */  jal        func_003e40b0
    /* CBA1C 001CBA1C 00000000 */   nop
    /* CBA20 001CBA20 06050046 */  mov.s      $f20, $f0
    /* CBA24 001CBA24 9C0081C6 */  lwc1       $f1, 0x9C($20)
    /* CBA28 001CBA28 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CBA2C 001CBA2C 01080046 */  sub.s      $f0, $f1, $f0
    /* CBA30 001CBA30 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* CBA34 001CBA34 A40081C6 */  lwc1       $f1, 0xA4($20)
    /* CBA38 001CBA38 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* CBA3C 001CBA3C 01080046 */  sub.s      $f0, $f1, $f0
    /* CBA40 001CBA40 DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* CBA44 001CBA44 D800A427 */  addiu      $4, $29, 0xD8
    /* CBA48 001CBA48 2D288000 */  daddu      $5, $4, $0
    /* CBA4C 001CBA4C 78900F0C */  jal        func_003e41e0
    /* CBA50 001CBA50 00000000 */   nop
    /* CBA54 001CBA54 1001A3C7 */  lwc1       $f3, 0x110($29)
    /* CBA58 001CBA58 D000A3E7 */  swc1       $f3, 0xD0($29)
    /* CBA5C 001CBA5C 1801A2C7 */  lwc1       $f2, 0x118($29)
    /* CBA60 001CBA60 D400A2E7 */  swc1       $f2, 0xD4($29)
    /* CBA64 001CBA64 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* CBA68 001CBA68 DC00A0C7 */  lwc1       $f0, 0xDC($29)
    /* CBA6C 001CBA6C 1A100046 */  mula.s     $f2, $f0
    /* CBA70 001CBA70 00008044 */  mtc1       $0, $f0
    /* CBA74 001CBA74 00000000 */  nop
    /* CBA78 001CBA78 5C180146 */  madd.s     $f1, $f3, $f1
    /* CBA7C 001CBA7C 10006012 */  beqz       $19, .L001CBAC0
    /* CBA80 001CBA80 00000000 */   nop
    /* CBA84 001CBA84 ACB3828F */  lw         $2, -0x4C54($28)
    /* CBA88 001CBA88 0C00438C */  lw         $3, 0xC($2)
    /* CBA8C 001CBA8C 2000023C */  lui        $2, (0x200000 >> 16)
    /* CBA90 001CBA90 24106200 */  and        $2, $3, $2
    /* CBA94 001CBA94 04004010 */  beqz       $2, .L001CBAA8
    /* CBA98 001CBA98 00000000 */   nop
    /* CBA9C 001CBA9C 040180AE */  sw         $0, 0x104($20)
    /* CBAA0 001CBAA0 07000010 */  b          .L001CBAC0
    /* CBAA4 001CBAA4 00000000 */   nop
  .L001CBAA8:
    /* CBAA8 001CBAA8 34080046 */  c.lt.s     $f1, $f0
    /* CBAAC 001CBAAC 01000224 */  addiu      $2, $0, 0x1
    /* CBAB0 001CBAB0 02000045 */  bc1f       .L001CBABC
    /* CBAB4 001CBAB4 00000000 */   nop
    /* CBAB8 001CBAB8 2D100000 */  daddu      $2, $0, $0
  .L001CBABC:
    /* CBABC 001CBABC 040182AE */  sw         $2, 0x104($20)
  .L001CBAC0:
    /* CBAC0 001CBAC0 0401838E */  lw         $3, 0x104($20)
    /* CBAC4 001CBAC4 01000224 */  addiu      $2, $0, 0x1
    /* CBAC8 001CBAC8 26006214 */  bne        $3, $2, .L001CBB64
    /* CBACC 001CBACC 00000000 */   nop
    /* CBAD0 001CBAD0 2D804002 */  daddu      $16, $18, $0
    /* CBAD4 001CBAD4 2DA82002 */  daddu      $21, $17, $0
    /* CBAD8 001CBAD8 5001A2DF */  ld         $2, 0x150($29)
    /* CBADC 001CBADC 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* CBAE0 001CBAE0 3001A2FF */  sd         $2, 0x130($29)
    /* CBAE4 001CBAE4 3801A0E7 */  swc1       $f0, 0x138($29)
    /* CBAE8 001CBAE8 900041C6 */  lwc1       $f1, 0x90($18)
    /* CBAEC 001CBAEC 2C0040C6 */  lwc1       $f0, 0x2C($18)
    /* CBAF0 001CBAF0 42080046 */  mul.s      $f1, $f1, $f0
    /* CBAF4 001CBAF4 A03F023C */  lui        $2, (0x3FA00000 >> 16)
    /* CBAF8 001CBAF8 00008244 */  mtc1       $2, $f0
    /* CBAFC 001CBAFC 00000000 */  nop
    /* CBB00 001CBB00 C2050146 */  mul.s      $f23, $f0, $f1
    /* CBB04 001CBB04 388196C7 */  lwc1       $f22, -0x7EC8($28)
    /* CBB08 001CBB08 288180C7 */  lwc1       $f0, -0x7ED8($28)
    /* CBB0C 001CBB0C 42001446 */  mul.s      $f1, $f0, $f20
    /* CBB10 001CBB10 1001A2C7 */  lwc1       $f2, 0x110($29)
    /* CBB14 001CBB14 02100146 */  mul.s      $f0, $f2, $f1
    /* CBB18 001CBB18 2001A0E7 */  swc1       $f0, 0x120($29)
    /* CBB1C 001CBB1C 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* CBB20 001CBB20 02000146 */  mul.s      $f0, $f0, $f1
    /* CBB24 001CBB24 2401A0E7 */  swc1       $f0, 0x124($29)
    /* CBB28 001CBB28 1801A3C7 */  lwc1       $f3, 0x118($29)
    /* CBB2C 001CBB2C 02180146 */  mul.s      $f0, $f3, $f1
    /* CBB30 001CBB30 2801A0E7 */  swc1       $f0, 0x128($29)
    /* CBB34 001CBB34 3401A1C7 */  lwc1       $f1, 0x134($29)
    /* CBB38 001CBB38 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* CBB3C 001CBB3C 00008244 */  mtc1       $2, $f0
    /* CBB40 001CBB40 00000000 */  nop
    /* CBB44 001CBB44 34080046 */  c.lt.s     $f1, $f0
    /* CBB48 001CBB48 02000045 */  bc1f       .L001CBB54
    /* CBB4C 001CBB4C 00000000 */   nop
    /* CBB50 001CBB50 3401A0E7 */  swc1       $f0, 0x134($29)
  .L001CBB54:
    /* CBB54 001CBB54 3401B4C7 */  lwc1       $f20, 0x134($29)
    /* CBB58 001CBB58 0401B4E7 */  swc1       $f20, 0x104($29)
    /* CBB5C 001CBB5C 3E000010 */  b          .L001CBC58
    /* CBB60 001CBB60 00000000 */   nop
  .L001CBB64:
    /* CBB64 001CBB64 2D802002 */  daddu      $16, $17, $0
    /* CBB68 001CBB68 2DA84002 */  daddu      $21, $18, $0
    /* CBB6C 001CBB6C 4001A2DF */  ld         $2, 0x140($29)
    /* CBB70 001CBB70 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CBB74 001CBB74 3001A2FF */  sd         $2, 0x130($29)
    /* CBB78 001CBB78 3801A0E7 */  swc1       $f0, 0x138($29)
    /* CBB7C 001CBB7C 2C0022C6 */  lwc1       $f2, 0x2C($17)
    /* CBB80 001CBB80 900020C6 */  lwc1       $f0, 0x90($17)
    /* CBB84 001CBB84 42000246 */  mul.s      $f1, $f0, $f2
    /* CBB88 001CBB88 288180C7 */  lwc1       $f0, -0x7ED8($28)
    /* CBB8C 001CBB8C C2050146 */  mul.s      $f23, $f0, $f1
    /* CBB90 001CBB90 2040023C */  lui        $2, (0x40200000 >> 16)
    /* CBB94 001CBB94 00B08244 */  mtc1       $2, $f22
    /* CBB98 001CBB98 8C0020C6 */  lwc1       $f0, 0x8C($17)
    /* CBB9C 001CBB9C C2000246 */  mul.s      $f3, $f0, $f2
    /* CBBA0 001CBBA0 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CBBA4 001CBBA4 00108244 */  mtc1       $2, $f2
    /* CBBA8 001CBBA8 5401A1C7 */  lwc1       $f1, 0x154($29)
    /* CBBAC 001CBBAC 00008044 */  mtc1       $0, $f0
    /* CBBB0 001CBBB0 00000000 */  nop
    /* CBBB4 001CBBB4 18000146 */  adda.s     $f0, $f1
    /* CBBB8 001CBBB8 5D100346 */  msub.s     $f1, $f2, $f3
    /* CBBBC 001CBBBC 5401A1E7 */  swc1       $f1, 0x154($29)
    /* CBBC0 001CBBC0 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* CBBC4 001CBBC4 00008244 */  mtc1       $2, $f0
    /* CBBC8 001CBBC8 00000000 */  nop
    /* CBBCC 001CBBCC 34080046 */  c.lt.s     $f1, $f0
    /* CBBD0 001CBBD0 02000045 */  bc1f       .L001CBBDC
    /* CBBD4 001CBBD4 00000000 */   nop
    /* CBBD8 001CBBD8 5401A0E7 */  swc1       $f0, 0x154($29)
  .L001CBBDC:
    /* CBBDC 001CBBDC 5001A1C7 */  lwc1       $f1, 0x150($29)
    /* CBBE0 001CBBE0 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* CBBE4 001CBBE4 01080046 */  sub.s      $f0, $f1, $f0
    /* CBBE8 001CBBE8 1001A0E7 */  swc1       $f0, 0x110($29)
    /* CBBEC 001CBBEC 5401A1C7 */  lwc1       $f1, 0x154($29)
    /* CBBF0 001CBBF0 4401A0C7 */  lwc1       $f0, 0x144($29)
    /* CBBF4 001CBBF4 01080046 */  sub.s      $f0, $f1, $f0
    /* CBBF8 001CBBF8 1401A0E7 */  swc1       $f0, 0x114($29)
    /* CBBFC 001CBBFC 5801A1C7 */  lwc1       $f1, 0x158($29)
    /* CBC00 001CBC00 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CBC04 001CBC04 01080046 */  sub.s      $f0, $f1, $f0
    /* CBC08 001CBC08 1801A0E7 */  swc1       $f0, 0x118($29)
    /* CBC0C 001CBC0C 1001A427 */  addiu      $4, $29, 0x110
    /* CBC10 001CBC10 2D288000 */  daddu      $5, $4, $0
    /* CBC14 001CBC14 2C900F0C */  jal        func_003e40b0
    /* CBC18 001CBC18 00000000 */   nop
    /* CBC1C 001CBC1C 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CBC20 001CBC20 00088244 */  mtc1       $2, $f1
    /* CBC24 001CBC24 00000000 */  nop
    /* CBC28 001CBC28 42080046 */  mul.s      $f1, $f1, $f0
    /* CBC2C 001CBC2C 1001A2C7 */  lwc1       $f2, 0x110($29)
    /* CBC30 001CBC30 02100146 */  mul.s      $f0, $f2, $f1
    /* CBC34 001CBC34 2001A0E7 */  swc1       $f0, 0x120($29)
    /* CBC38 001CBC38 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* CBC3C 001CBC3C 02000146 */  mul.s      $f0, $f0, $f1
    /* CBC40 001CBC40 2401A0E7 */  swc1       $f0, 0x124($29)
    /* CBC44 001CBC44 1801A3C7 */  lwc1       $f3, 0x118($29)
    /* CBC48 001CBC48 02180146 */  mul.s      $f0, $f3, $f1
    /* CBC4C 001CBC4C 2801A0E7 */  swc1       $f0, 0x128($29)
    /* CBC50 001CBC50 3401B4C7 */  lwc1       $f20, 0x134($29)
    /* CBC54 001CBC54 0401B4E7 */  swc1       $f20, 0x104($29)
  .L001CBC58:
    /* CBC58 001CBC58 2001A1C7 */  lwc1       $f1, 0x120($29)
    /* CBC5C 001CBC5C 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* CBC60 001CBC60 00080046 */  add.s      $f0, $f1, $f0
    /* CBC64 001CBC64 2001A0E7 */  swc1       $f0, 0x120($29)
    /* CBC68 001CBC68 2401A1C7 */  lwc1       $f1, 0x124($29)
    /* CBC6C 001CBC6C 4401A0C7 */  lwc1       $f0, 0x144($29)
    /* CBC70 001CBC70 00080046 */  add.s      $f0, $f1, $f0
    /* CBC74 001CBC74 2401A0E7 */  swc1       $f0, 0x124($29)
    /* CBC78 001CBC78 2801A1C7 */  lwc1       $f1, 0x128($29)
    /* CBC7C 001CBC7C 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* CBC80 001CBC80 00080046 */  add.s      $f0, $f1, $f0
    /* CBC84 001CBC84 2801A0E7 */  swc1       $f0, 0x128($29)
    /* CBC88 001CBC88 D000A3E7 */  swc1       $f3, 0xD0($29)
    /* CBC8C 001CBC8C 87100046 */  neg.s      $f2, $f2
    /* CBC90 001CBC90 D400A2E7 */  swc1       $f2, 0xD4($29)
    /* CBC94 001CBC94 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* CBC98 001CBC98 DC00A0C7 */  lwc1       $f0, 0xDC($29)
    /* CBC9C 001CBC9C 1A100046 */  mula.s     $f2, $f0
    /* CBCA0 001CBCA0 00008044 */  mtc1       $0, $f0
    /* CBCA4 001CBCA4 00000000 */  nop
    /* CBCA8 001CBCA8 5C180146 */  madd.s     $f1, $f3, $f1
    /* CBCAC 001CBCAC 07006012 */  beqz       $19, .L001CBCCC
    /* CBCB0 001CBCB0 00000000 */   nop
    /* CBCB4 001CBCB4 34080046 */  c.lt.s     $f1, $f0
    /* CBCB8 001CBCB8 01000224 */  addiu      $2, $0, 0x1
    /* CBCBC 001CBCBC 02000045 */  bc1f       .L001CBCC8
    /* CBCC0 001CBCC0 00000000 */   nop
    /* CBCC4 001CBCC4 2D100000 */  daddu      $2, $0, $0
  .L001CBCC8:
    /* CBCC8 001CBCC8 080182AE */  sw         $2, 0x108($20)
  .L001CBCCC:
    /* CBCCC 001CBCCC 0801838E */  lw         $3, 0x108($20)
    /* CBCD0 001CBCD0 01000224 */  addiu      $2, $0, 0x1
    /* CBCD4 001CBCD4 0F006214 */  bne        $3, $2, .L001CBD14
    /* CBCD8 001CBCD8 00000000 */   nop
    /* CBCDC 001CBCDC 1801A2C7 */  lwc1       $f2, 0x118($29)
    /* CBCE0 001CBCE0 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* CBCE4 001CBCE4 00088044 */  mtc1       $0, $f1
    /* CBCE8 001CBCE8 00000000 */  nop
    /* CBCEC 001CBCEC 18080046 */  adda.s     $f1, $f0
    /* CBCF0 001CBCF0 1C101746 */  madd.s     $f0, $f2, $f23
    /* CBCF4 001CBCF4 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CBCF8 001CBCF8 3801B5C7 */  lwc1       $f21, 0x138($29)
    /* CBCFC 001CBCFC 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* CBD00 001CBD00 18081546 */  adda.s     $f1, $f21
    /* CBD04 001CBD04 1D001746 */  msub.s     $f0, $f0, $f23
    /* CBD08 001CBD08 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CBD0C 001CBD0C 0D000010 */  b          .L001CBD44
    /* CBD10 001CBD10 00000000 */   nop
  .L001CBD14:
    /* CBD14 001CBD14 1801A2C7 */  lwc1       $f2, 0x118($29)
    /* CBD18 001CBD18 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* CBD1C 001CBD1C 00088044 */  mtc1       $0, $f1
    /* CBD20 001CBD20 00000000 */  nop
    /* CBD24 001CBD24 18080046 */  adda.s     $f1, $f0
    /* CBD28 001CBD28 1D101746 */  msub.s     $f0, $f2, $f23
    /* CBD2C 001CBD2C 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CBD30 001CBD30 3801B5C7 */  lwc1       $f21, 0x138($29)
    /* CBD34 001CBD34 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* CBD38 001CBD38 18081546 */  adda.s     $f1, $f21
    /* CBD3C 001CBD3C 1C001746 */  madd.s     $f0, $f0, $f23
    /* CBD40 001CBD40 0801A0E7 */  swc1       $f0, 0x108($29)
  .L001CBD44:
    /* CBD44 001CBD44 B800A427 */  addiu      $4, $29, 0xB8
    /* CBD48 001CBD48 0001A527 */  addiu      $5, $29, 0x100
    /* CBD4C 001CBD4C 2001A627 */  addiu      $6, $29, 0x120
    /* CBD50 001CBD50 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CBD54 001CBD54 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CBD58 001CBD58 E0F5060C */  jal        func_001bd780
    /* CBD5C 001CBD5C 00000000 */   nop
    /* CBD60 001CBD60 1001A427 */  addiu      $4, $29, 0x110
    /* CBD64 001CBD64 6100053C */  lui        $5, %hi(D_0060A100)
    /* CBD68 001CBD68 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CBD6C 001CBD6C 01000624 */  addiu      $6, $0, 0x1
    /* CBD70 001CBD70 B800A727 */  addiu      $7, $29, 0xB8
    /* CBD74 001CBD74 D0720F0C */  jal        func_003dcb40
    /* CBD78 001CBD78 00000000 */   nop
    /* CBD7C 001CBD7C 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CBD80 001CBD80 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* CBD84 001CBD84 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* CBD88 001CBD88 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* CBD8C 001CBD8C 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CBD90 001CBD90 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* CBD94 001CBD94 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CBD98 001CBD98 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* CBD9C 001CBD9C 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* CBDA0 001CBDA0 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* CBDA4 001CBDA4 FC00B5E7 */  swc1       $f21, 0xFC($29)
    /* CBDA8 001CBDA8 E000A427 */  addiu      $4, $29, 0xE0
    /* CBDAC 001CBDAC E800A527 */  addiu      $5, $29, 0xE8
    /* CBDB0 001CBDB0 F800A627 */  addiu      $6, $29, 0xF8
    /* CBDB4 001CBDB4 F000A727 */  addiu      $7, $29, 0xF0
    /* CBDB8 001CBDB8 F4B0070C */  jal        func_001ec3d0
    /* CBDBC 001CBDBC 00000000 */   nop
    /* CBDC0 001CBDC0 900002C6 */  lwc1       $f2, 0x90($16)
    /* CBDC4 001CBDC4 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* CBDC8 001CBDC8 82100146 */  mul.s      $f2, $f2, $f1
    /* CBDCC 001CBDCC 00088044 */  mtc1       $0, $f1
    /* CBDD0 001CBDD0 00000000 */  nop
    /* CBDD4 001CBDD4 18080046 */  adda.s     $f1, $f0
    /* CBDD8 001CBDD8 5CB50246 */  madd.s     $f21, $f22, $f2
    /* CBDDC 001CBDDC F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CBDE0 001CBDE0 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CBDE4 001CBDE4 0401B4E7 */  swc1       $f20, 0x104($29)
    /* CBDE8 001CBDE8 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CBDEC 001CBDEC 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CBDF0 001CBDF0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CBDF4 001CBDF4 00088244 */  mtc1       $2, $f1
    /* CBDF8 001CBDF8 B80080C6 */  lwc1       $f0, 0xB8($20)
    /* CBDFC 001CBDFC 42080046 */  mul.s      $f1, $f1, $f0
    /* CBE00 001CBE00 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CBE04 001CBE04 02030146 */  mul.s      $f12, $f0, $f1
    /* CBE08 001CBE08 1A2E110C */  jal        func_0044b868
    /* CBE0C 001CBE0C 00000000 */   nop
    /* CBE10 001CBE10 00000000 */  nop
    /* CBE14 001CBE14 00000000 */  nop
    /* CBE18 001CBE18 83A80046 */  div.s      $f2, $f21, $f0
    /* CBE1C 001CBE1C FA43023C */  lui        $2, (0x43FA0000 >> 16)
    /* CBE20 001CBE20 00008244 */  mtc1       $2, $f0
    /* CBE24 001CBE24 00000000 */  nop
    /* CBE28 001CBE28 34100046 */  c.lt.s     $f2, $f0
    /* CBE2C 001CBE2C 02000045 */  bc1f       .L001CBE38
    /* CBE30 001CBE30 00000000 */   nop
    /* CBE34 001CBE34 86000046 */  mov.s      $f2, $f0
  .L001CBE38:
    /* CBE38 001CBE38 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* CBE3C 001CBE3C C2000246 */  mul.s      $f3, $f0, $f2
    /* CBE40 001CBE40 1001A3E7 */  swc1       $f3, 0x110($29)
    /* CBE44 001CBE44 1401A0C7 */  lwc1       $f0, 0x114($29)
    /* CBE48 001CBE48 42000246 */  mul.s      $f1, $f0, $f2
    /* CBE4C 001CBE4C 1401A1E7 */  swc1       $f1, 0x114($29)
    /* CBE50 001CBE50 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* CBE54 001CBE54 82000246 */  mul.s      $f2, $f0, $f2
    /* CBE58 001CBE58 1801A2E7 */  swc1       $f2, 0x118($29)
    /* CBE5C 001CBE5C 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CBE60 001CBE60 00000346 */  add.s      $f0, $f0, $f3
    /* CBE64 001CBE64 AC00A0E7 */  swc1       $f0, 0xAC($29)
    /* CBE68 001CBE68 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* CBE6C 001CBE6C 40000146 */  add.s      $f1, $f0, $f1
    /* CBE70 001CBE70 B000A1E7 */  swc1       $f1, 0xB0($29)
    /* CBE74 001CBE74 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CBE78 001CBE78 00000246 */  add.s      $f0, $f0, $f2
    /* CBE7C 001CBE7C B400A0E7 */  swc1       $f0, 0xB4($29)
    /* CBE80 001CBE80 4841023C */  lui        $2, (0x41480000 >> 16)
    /* CBE84 001CBE84 00008244 */  mtc1       $2, $f0
    /* CBE88 001CBE88 00000000 */  nop
    /* CBE8C 001CBE8C 34080046 */  c.lt.s     $f1, $f0
    /* CBE90 001CBE90 02000045 */  bc1f       .L001CBE9C
    /* CBE94 001CBE94 00000000 */   nop
    /* CBE98 001CBE98 B000A0E7 */  swc1       $f0, 0xB0($29)
  .L001CBE9C:
    /* CBE9C 001CBE9C 9000A427 */  addiu      $4, $29, 0x90
    /* CBEA0 001CBEA0 9C008526 */  addiu      $5, $20, 0x9C
    /* CBEA4 001CBEA4 58F5060C */  jal        func_001bd560
    /* CBEA8 001CBEA8 00000000 */   nop
    /* CBEAC 001CBEAC 18006012 */  beqz       $19, .L001CBF10
    /* CBEB0 001CBEB0 00000000 */   nop
    /* CBEB4 001CBEB4 9C00A427 */  addiu      $4, $29, 0x9C
    /* CBEB8 001CBEB8 B800A527 */  addiu      $5, $29, 0xB8
    /* CBEBC 001CBEBC ACB0070C */  jal        func_001ec2b0
    /* CBEC0 001CBEC0 00000000 */   nop
    /* CBEC4 001CBEC4 DC8081C7 */  lwc1       $f1, -0x7F24($28)
    /* CBEC8 001CBEC8 36000146 */  c.le.s     $f0, $f1
    /* CBECC 001CBECC 08000145 */  bc1t       .L001CBEF0
    /* CBED0 001CBED0 00000000 */   nop
    /* CBED4 001CBED4 9000A427 */  addiu      $4, $29, 0x90
    /* CBED8 001CBED8 AC00A527 */  addiu      $5, $29, 0xAC
    /* CBEDC 001CBEDC 78F5060C */  jal        func_001bd5e0
    /* CBEE0 001CBEE0 00000000 */   nop
    /* CBEE4 001CBEE4 03000764 */  daddiu     $7, $0, 0x3
    /* CBEE8 001CBEE8 02000010 */  b          .L001CBEF4
    /* CBEEC 001CBEEC 00000000 */   nop
  .L001CBEF0:
    /* CBEF0 001CBEF0 83000764 */  daddiu     $7, $0, 0x83
  .L001CBEF4:
    /* CBEF4 001CBEF4 4842023C */  lui        $2, (0x42480000 >> 16)
    /* CBEF8 001CBEF8 00608244 */  mtc1       $2, $f12
    /* CBEFC 001CBEFC E000848E */  lw         $4, 0xE0($20)
    /* CBF00 001CBF00 0400A526 */  addiu      $5, $21, 0x4
    /* CBF04 001CBF04 AC00A627 */  addiu      $6, $29, 0xAC
    /* CBF08 001CBF08 50F3060C */  jal        func_001bcd40
    /* CBF0C 001CBF0C 00000000 */   nop
  .L001CBF10:
    /* CBF10 001CBF10 2D208002 */  daddu      $4, $20, $0
    /* CBF14 001CBF14 9000A527 */  addiu      $5, $29, 0x90
    /* CBF18 001CBF18 AC00A627 */  addiu      $6, $29, 0xAC
    /* CBF1C 001CBF1C 01000724 */  addiu      $7, $0, 0x1
    /* CBF20 001CBF20 08EB060C */  jal        func_001bac20
    /* CBF24 001CBF24 00000000 */   nop
    /* CBF28 001CBF28 2D208002 */  daddu      $4, $20, $0
    /* CBF2C 001CBF2C 06C30046 */  mov.s      $f12, $f24
    /* CBF30 001CBF30 BCEF060C */  jal        func_001bbef0
    /* CBF34 001CBF34 00000000 */   nop
    /* CBF38 001CBF38 8000BFDF */  ld         $31, 0x80($29)
    /* CBF3C 001CBF3C 7000B57B */  lq         $21, 0x70($29)
    /* CBF40 001CBF40 6000B47B */  lq         $20, 0x60($29)
    /* CBF44 001CBF44 5000B37B */  lq         $19, 0x50($29)
    /* CBF48 001CBF48 4000B27B */  lq         $18, 0x40($29)
    /* CBF4C 001CBF4C 3000B17B */  lq         $17, 0x30($29)
    /* CBF50 001CBF50 2000B07B */  lq         $16, 0x20($29)
    /* CBF54 001CBF54 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* CBF58 001CBF58 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* CBF5C 001CBF5C 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* CBF60 001CBF60 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CBF64 001CBF64 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CBF68 001CBF68 6001BD27 */  addiu      $29, $29, 0x160
    /* CBF6C 001CBF6C 0800E003 */  jr         $31
    /* CBF70 001CBF70 00000000 */   nop
    /* CBF74 001CBF74 00000000 */  nop
    /* CBF78 001CBF78 00000000 */  nop
    /* CBF7C 001CBF7C 00000000 */  nop
.size func_001cb970, 0x610
