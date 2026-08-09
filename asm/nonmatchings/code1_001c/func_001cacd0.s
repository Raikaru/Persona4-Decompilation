.section .text
.set noat
.set noreorder
glabel func_001cacd0
    /* CACD0 001CACD0 90FEBD27 */  addiu      $29, $29, -0x170
    /* CACD4 001CACD4 5000BFFF */  sd         $31, 0x50($29)
    /* CACD8 001CACD8 4000B27F */  sq         $18, 0x40($29)
    /* CACDC 001CACDC 3000B17F */  sq         $17, 0x30($29)
    /* CACE0 001CACE0 2000B07F */  sq         $16, 0x20($29)
    /* CACE4 001CACE4 1000B8E7 */  swc1       $f24, 0x10($29)
    /* CACE8 001CACE8 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* CACEC 001CACEC 0800B6E7 */  swc1       $f22, 0x8($29)
    /* CACF0 001CACF0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CACF4 001CACF4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CACF8 001CACF8 2D888000 */  daddu      $17, $4, $0
    /* CACFC 001CACFC 06660046 */  mov.s      $f24, $f12
    /* CAD00 001CAD00 C66D0046 */  mov.s      $f23, $f13
    /* CAD04 001CAD04 E000828C */  lw         $2, 0xE0($4)
    /* CAD08 001CAD08 3000508C */  lw         $16, 0x30($2)
    /* CAD0C 001CAD0C 3800428C */  lw         $2, 0x38($2)
    /* CAD10 001CAD10 3000528C */  lw         $18, 0x30($2)
    /* CAD14 001CAD14 6000A427 */  addiu      $4, $29, 0x60
    /* CAD18 001CAD18 9C002526 */  addiu      $5, $17, 0x9C
    /* CAD1C 001CAD1C 58F5060C */  jal        func_001bd560
    /* CAD20 001CAD20 00000000 */   nop
    /* CAD24 001CAD24 840001C6 */  lwc1       $f1, 0x84($16)
    /* CAD28 001CAD28 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CAD2C 001CAD2C 020D0046 */  mul.s      $f20, $f1, $f0
    /* CAD30 001CAD30 2D204002 */  daddu      $4, $18, $0
    /* CAD34 001CAD34 2001A527 */  addiu      $5, $29, 0x120
    /* CAD38 001CAD38 1456060C */  jal        func_00195850
    /* CAD3C 001CAD3C 00000000 */   nop
    /* CAD40 001CAD40 8C0001C6 */  lwc1       $f1, 0x8C($16)
    /* CAD44 001CAD44 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* CAD48 001CAD48 02080046 */  mul.s      $f0, $f1, $f0
    /* CAD4C 001CAD4C 188184C7 */  lwc1       $f4, -0x7EE8($28)
    /* CAD50 001CAD50 00108044 */  mtc1       $0, $f2
    /* CAD54 001CAD54 00000000 */  nop
    /* CAD58 001CAD58 18101446 */  adda.s     $f2, $f20
    /* CAD5C 001CAD5C DC200046 */  madd.s     $f3, $f4, $f0
    /* CAD60 001CAD60 8C0041C6 */  lwc1       $f1, 0x8C($18)
    /* CAD64 001CAD64 2C0040C6 */  lwc1       $f0, 0x2C($18)
    /* CAD68 001CAD68 42080046 */  mul.s      $f1, $f1, $f0
    /* CAD6C 001CAD6C 2401A0C7 */  lwc1       $f0, 0x124($29)
    /* CAD70 001CAD70 18100046 */  adda.s     $f2, $f0
    /* CAD74 001CAD74 1C200146 */  madd.s     $f0, $f4, $f1
    /* CAD78 001CAD78 401D0046 */  add.s      $f21, $f3, $f0
    /* CAD7C 001CAD7C 2401A0AF */  sw         $0, 0x124($29)
    /* CAD80 001CAD80 DC0001C6 */  lwc1       $f1, 0xDC($16)
    /* CAD84 001CAD84 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CAD88 001CAD88 01080046 */  sub.s      $f0, $f1, $f0
    /* CAD8C 001CAD8C 6001A0E7 */  swc1       $f0, 0x160($29)
    /* CAD90 001CAD90 E00000C6 */  lwc1       $f0, 0xE0($16)
    /* CAD94 001CAD94 01000246 */  sub.s      $f0, $f0, $f2
    /* CAD98 001CAD98 6401A0E7 */  swc1       $f0, 0x164($29)
    /* CAD9C 001CAD9C E40001C6 */  lwc1       $f1, 0xE4($16)
    /* CADA0 001CADA0 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* CADA4 001CADA4 01080046 */  sub.s      $f0, $f1, $f0
    /* CADA8 001CADA8 6801A0E7 */  swc1       $f0, 0x168($29)
    /* CADAC 001CADAC 6001A427 */  addiu      $4, $29, 0x160
    /* CADB0 001CADB0 2D288000 */  daddu      $5, $4, $0
    /* CADB4 001CADB4 2C900F0C */  jal        func_003e40b0
    /* CADB8 001CADB8 00000000 */   nop
    /* CADBC 001CADBC 06050046 */  mov.s      $f20, $f0
    /* CADC0 001CADC0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CADC4 001CADC4 00308244 */  mtc1       $2, $f6
    /* CADC8 001CADC8 00000000 */  nop
    /* CADCC 001CADCC 42301446 */  mul.s      $f1, $f6, $f20
    /* CADD0 001CADD0 6001A5C7 */  lwc1       $f5, 0x160($29)
    /* CADD4 001CADD4 82280146 */  mul.s      $f2, $f5, $f1
    /* CADD8 001CADD8 5001A2E7 */  swc1       $f2, 0x150($29)
    /* CADDC 001CADDC 6401A0C7 */  lwc1       $f0, 0x164($29)
    /* CADE0 001CADE0 02010146 */  mul.s      $f4, $f0, $f1
    /* CADE4 001CADE4 5401A4E7 */  swc1       $f4, 0x154($29)
    /* CADE8 001CADE8 6801A3C7 */  lwc1       $f3, 0x168($29)
    /* CADEC 001CADEC 42180146 */  mul.s      $f1, $f3, $f1
    /* CADF0 001CADF0 5801A1E7 */  swc1       $f1, 0x158($29)
    /* CADF4 001CADF4 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CADF8 001CADF8 80100046 */  add.s      $f2, $f2, $f0
    /* CADFC 001CADFC 5001A2E7 */  swc1       $f2, 0x150($29)
    /* CAE00 001CAE00 2401A0C7 */  lwc1       $f0, 0x124($29)
    /* CAE04 001CAE04 00200046 */  add.s      $f0, $f4, $f0
    /* CAE08 001CAE08 5401A0E7 */  swc1       $f0, 0x154($29)
    /* CAE0C 001CAE0C 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* CAE10 001CAE10 40080046 */  add.s      $f1, $f1, $f0
    /* CAE14 001CAE14 5801A1E7 */  swc1       $f1, 0x158($29)
    /* CAE18 001CAE18 42351546 */  mul.s      $f21, $f6, $f21
    /* CAE1C 001CAE1C 5401B5E7 */  swc1       $f21, 0x154($29)
    /* CAE20 001CAE20 1001A3E7 */  swc1       $f3, 0x110($29)
    /* CAE24 001CAE24 07280046 */  neg.s      $f0, $f5
    /* CAE28 001CAE28 1401A0E7 */  swc1       $f0, 0x114($29)
    /* CAE2C 001CAE2C 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* CAE30 001CAE30 01000246 */  sub.s      $f0, $f0, $f2
    /* CAE34 001CAE34 1801A0E7 */  swc1       $f0, 0x118($29)
    /* CAE38 001CAE38 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* CAE3C 001CAE3C 01000146 */  sub.s      $f0, $f0, $f1
    /* CAE40 001CAE40 1C01A0E7 */  swc1       $f0, 0x11C($29)
    /* CAE44 001CAE44 1001A427 */  addiu      $4, $29, 0x110
    /* CAE48 001CAE48 2D288000 */  daddu      $5, $4, $0
    /* CAE4C 001CAE4C 78900F0C */  jal        func_003e41e0
    /* CAE50 001CAE50 00000000 */   nop
    /* CAE54 001CAE54 1801A427 */  addiu      $4, $29, 0x118
    /* CAE58 001CAE58 2D288000 */  daddu      $5, $4, $0
    /* CAE5C 001CAE5C 78900F0C */  jal        func_003e41e0
    /* CAE60 001CAE60 00000000 */   nop
    /* CAE64 001CAE64 1001A3C7 */  lwc1       $f3, 0x110($29)
    /* CAE68 001CAE68 1801A2C7 */  lwc1       $f2, 0x118($29)
    /* CAE6C 001CAE6C 1401A1C7 */  lwc1       $f1, 0x114($29)
    /* CAE70 001CAE70 1C01A0C7 */  lwc1       $f0, 0x11C($29)
    /* CAE74 001CAE74 1A080046 */  mula.s     $f1, $f0
    /* CAE78 001CAE78 00008044 */  mtc1       $0, $f0
    /* CAE7C 001CAE7C 9C1D0246 */  madd.s     $f22, $f3, $f2
    /* CAE80 001CAE80 34B00046 */  c.lt.s     $f22, $f0
    /* CAE84 001CAE84 0E000145 */  bc1t       .L001CAEC0
    /* CAE88 001CAE88 00000000 */   nop
    /* CAE8C 001CAE8C 188180C7 */  lwc1       $f0, -0x7EE8($28)
    /* CAE90 001CAE90 42001446 */  mul.s      $f1, $f0, $f20
    /* CAE94 001CAE94 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* CAE98 001CAE98 02000146 */  mul.s      $f0, $f0, $f1
    /* CAE9C 001CAE9C 5001A0E7 */  swc1       $f0, 0x150($29)
    /* CAEA0 001CAEA0 6401A0C7 */  lwc1       $f0, 0x164($29)
    /* CAEA4 001CAEA4 02000146 */  mul.s      $f0, $f0, $f1
    /* CAEA8 001CAEA8 5401A0E7 */  swc1       $f0, 0x154($29)
    /* CAEAC 001CAEAC 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* CAEB0 001CAEB0 02000146 */  mul.s      $f0, $f0, $f1
    /* CAEB4 001CAEB4 5801A0E7 */  swc1       $f0, 0x158($29)
    /* CAEB8 001CAEB8 0E000010 */  b          .L001CAEF4
    /* CAEBC 001CAEBC 00000000 */   nop
  .L001CAEC0:
    /* CAEC0 001CAEC0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CAEC4 001CAEC4 00008244 */  mtc1       $2, $f0
    /* CAEC8 001CAEC8 00000000 */  nop
    /* CAECC 001CAECC 42001446 */  mul.s      $f1, $f0, $f20
    /* CAED0 001CAED0 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* CAED4 001CAED4 02000146 */  mul.s      $f0, $f0, $f1
    /* CAED8 001CAED8 5001A0E7 */  swc1       $f0, 0x150($29)
    /* CAEDC 001CAEDC 6401A0C7 */  lwc1       $f0, 0x164($29)
    /* CAEE0 001CAEE0 02000146 */  mul.s      $f0, $f0, $f1
    /* CAEE4 001CAEE4 5401A0E7 */  swc1       $f0, 0x154($29)
    /* CAEE8 001CAEE8 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* CAEEC 001CAEEC 02000146 */  mul.s      $f0, $f0, $f1
    /* CAEF0 001CAEF0 5801A0E7 */  swc1       $f0, 0x158($29)
  .L001CAEF4:
    /* CAEF4 001CAEF4 5001A1C7 */  lwc1       $f1, 0x150($29)
    /* CAEF8 001CAEF8 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* CAEFC 001CAEFC 00080046 */  add.s      $f0, $f1, $f0
    /* CAF00 001CAF00 5001A0E7 */  swc1       $f0, 0x150($29)
    /* CAF04 001CAF04 5401A1C7 */  lwc1       $f1, 0x154($29)
    /* CAF08 001CAF08 2401A0C7 */  lwc1       $f0, 0x124($29)
    /* CAF0C 001CAF0C 00080046 */  add.s      $f0, $f1, $f0
    /* CAF10 001CAF10 5401A0E7 */  swc1       $f0, 0x154($29)
    /* CAF14 001CAF14 5801A1C7 */  lwc1       $f1, 0x158($29)
    /* CAF18 001CAF18 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* CAF1C 001CAF1C 00080046 */  add.s      $f0, $f1, $f0
    /* CAF20 001CAF20 5801A0E7 */  swc1       $f0, 0x158($29)
    /* CAF24 001CAF24 5401B5E7 */  swc1       $f21, 0x154($29)
    /* CAF28 001CAF28 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CAF2C 001CAF2C 00088244 */  mtc1       $2, $f1
    /* CAF30 001CAF30 E80000C6 */  lwc1       $f0, 0xE8($16)
    /* CAF34 001CAF34 02080046 */  mul.s      $f0, $f1, $f0
    /* CAF38 001CAF38 0C0120E6 */  swc1       $f0, 0x10C($17)
    /* CAF3C 001CAF3C 5001A2C7 */  lwc1       $f2, 0x150($29)
    /* CAF40 001CAF40 5401A1C7 */  lwc1       $f1, 0x154($29)
    /* CAF44 001CAF44 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* CAF48 001CAF48 000122E6 */  swc1       $f2, 0x100($17)
    /* CAF4C 001CAF4C 040121E6 */  swc1       $f1, 0x104($17)
    /* CAF50 001CAF50 080120E6 */  swc1       $f0, 0x108($17)
    /* CAF54 001CAF54 6000A1C7 */  lwc1       $f1, 0x60($29)
    /* CAF58 001CAF58 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CAF5C 001CAF5C 01080046 */  sub.s      $f0, $f1, $f0
    /* CAF60 001CAF60 3001A0E7 */  swc1       $f0, 0x130($29)
    /* CAF64 001CAF64 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* CAF68 001CAF68 5401A0C7 */  lwc1       $f0, 0x154($29)
    /* CAF6C 001CAF6C 01080046 */  sub.s      $f0, $f1, $f0
    /* CAF70 001CAF70 3401A0E7 */  swc1       $f0, 0x134($29)
    /* CAF74 001CAF74 6800A1C7 */  lwc1       $f1, 0x68($29)
    /* CAF78 001CAF78 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* CAF7C 001CAF7C 01080046 */  sub.s      $f0, $f1, $f0
    /* CAF80 001CAF80 3801A0E7 */  swc1       $f0, 0x138($29)
    /* CAF84 001CAF84 4040023C */  lui        $2, (0x40400000 >> 16)
    /* CAF88 001CAF88 00008244 */  mtc1       $2, $f0
    /* CAF8C 001CAF8C 00000000 */  nop
    /* CAF90 001CAF90 43C50046 */  div.s      $f21, $f24, $f0
    /* CAF94 001CAF94 00000000 */  nop
    /* CAF98 001CAF98 06AD0046 */  mov.s      $f20, $f21
    /* CAF9C 001CAF9C 01001064 */  daddiu     $16, $0, 0x1
    /* CAFA0 001CAFA0 36000010 */  b          .L001CB07C
    /* CAFA4 001CAFA4 00000000 */   nop
  .L001CAFA8:
    /* CAFA8 001CAFA8 00008044 */  mtc1       $0, $f0
    /* CAFAC 001CAFAC 00000000 */  nop
    /* CAFB0 001CAFB0 34B00046 */  c.lt.s     $f22, $f0
    /* CAFB4 001CAFB4 0A000145 */  bc1t       .L001CAFE0
    /* CAFB8 001CAFB8 00000000 */   nop
    /* CAFBC 001CAFBC D000A427 */  addiu      $4, $29, 0xD0
    /* CAFC0 001CAFC0 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CAFC4 001CAFC4 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CAFC8 001CAFC8 06AB0046 */  mov.s      $f12, $f21
    /* CAFCC 001CAFCC 2D300000 */  daddu      $6, $0, $0
    /* CAFD0 001CAFD0 1C820F0C */  jal        func_003e0870
    /* CAFD4 001CAFD4 00000000 */   nop
    /* CAFD8 001CAFD8 08000010 */  b          .L001CAFFC
    /* CAFDC 001CAFDC 00000000 */   nop
  .L001CAFE0:
    /* CAFE0 001CAFE0 07AB0046 */  neg.s      $f12, $f21
    /* CAFE4 001CAFE4 D000A427 */  addiu      $4, $29, 0xD0
    /* CAFE8 001CAFE8 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CAFEC 001CAFEC E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CAFF0 001CAFF0 2D300000 */  daddu      $6, $0, $0
    /* CAFF4 001CAFF4 1C820F0C */  jal        func_003e0870
    /* CAFF8 001CAFF8 00000000 */   nop
  .L001CAFFC:
    /* CAFFC 001CAFFC 4001A427 */  addiu      $4, $29, 0x140
    /* CB000 001CB000 3001A527 */  addiu      $5, $29, 0x130
    /* CB004 001CB004 D000A627 */  addiu      $6, $29, 0xD0
    /* CB008 001CB008 C8900F0C */  jal        func_003e4320
    /* CB00C 001CB00C 00000000 */   nop
    /* CB010 001CB010 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* CB014 001CB014 C0100300 */  sll        $2, $3, 3
    /* CB018 001CB018 23104300 */  subu       $2, $2, $3
    /* CB01C 001CB01C 80100200 */  sll        $2, $2, 2
    /* CB020 001CB020 21105D00 */  addu       $2, $2, $29
    /* CB024 001CB024 60004524 */  addiu      $5, $2, 0x60
    /* CB028 001CB028 4001A1C7 */  lwc1       $f1, 0x140($29)
    /* CB02C 001CB02C 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* CB030 001CB030 00080046 */  add.s      $f0, $f1, $f0
    /* CB034 001CB034 0000A0E4 */  swc1       $f0, 0x0($5)
    /* CB038 001CB038 4401A1C7 */  lwc1       $f1, 0x144($29)
    /* CB03C 001CB03C 5401A0C7 */  lwc1       $f0, 0x154($29)
    /* CB040 001CB040 00080046 */  add.s      $f0, $f1, $f0
    /* CB044 001CB044 0400A0E4 */  swc1       $f0, 0x4($5)
    /* CB048 001CB048 4801A1C7 */  lwc1       $f1, 0x148($29)
    /* CB04C 001CB04C 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* CB050 001CB050 00080046 */  add.s      $f0, $f1, $f0
    /* CB054 001CB054 0800A0E4 */  swc1       $f0, 0x8($5)
    /* CB058 001CB058 0C00A424 */  addiu      $4, $5, 0xC
    /* CB05C 001CB05C 5001A627 */  addiu      $6, $29, 0x150
    /* CB060 001CB060 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CB064 001CB064 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CB068 001CB068 E0F5060C */  jal        func_001bd780
    /* CB06C 001CB06C 00000000 */   nop
    /* CB070 001CB070 40AD1446 */  add.s      $f21, $f21, $f20
    /* CB074 001CB074 01000226 */  addiu      $2, $16, 0x1
    /* CB078 001CB078 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001CB07C:
    /* CB07C 001CB07C FFFF0232 */  andi       $2, $16, 0xFFFF
    /* CB080 001CB080 04004228 */  slti       $2, $2, 0x4
    /* CB084 001CB084 C8FF4014 */  bnez       $2, .L001CAFA8
    /* CB088 001CB088 00000000 */   nop
    /* CB08C 001CB08C 2D202002 */  daddu      $4, $17, $0
    /* CB090 001CB090 6000A527 */  addiu      $5, $29, 0x60
    /* CB094 001CB094 7C00A627 */  addiu      $6, $29, 0x7C
    /* CB098 001CB098 9800A727 */  addiu      $7, $29, 0x98
    /* CB09C 001CB09C B400A827 */  addiu      $8, $29, 0xB4
    /* CB0A0 001CB0A0 01000924 */  addiu      $9, $0, 0x1
    /* CB0A4 001CB0A4 F4EC060C */  jal        func_001bb3d0
    /* CB0A8 001CB0A8 00000000 */   nop
    /* CB0AC 001CB0AC 2D202002 */  daddu      $4, $17, $0
    /* CB0B0 001CB0B0 06BB0046 */  mov.s      $f12, $f23
    /* CB0B4 001CB0B4 BCEF060C */  jal        func_001bbef0
    /* CB0B8 001CB0B8 00000000 */   nop
    /* CB0BC 001CB0BC 5000BFDF */  ld         $31, 0x50($29)
    /* CB0C0 001CB0C0 4000B27B */  lq         $18, 0x40($29)
    /* CB0C4 001CB0C4 3000B17B */  lq         $17, 0x30($29)
    /* CB0C8 001CB0C8 2000B07B */  lq         $16, 0x20($29)
    /* CB0CC 001CB0CC 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* CB0D0 001CB0D0 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* CB0D4 001CB0D4 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* CB0D8 001CB0D8 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CB0DC 001CB0DC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CB0E0 001CB0E0 7001BD27 */  addiu      $29, $29, 0x170
    /* CB0E4 001CB0E4 0800E003 */  jr         $31
    /* CB0E8 001CB0E8 00000000 */   nop
    /* CB0EC 001CB0EC 00000000 */  nop
.size func_001cacd0, 0x420
