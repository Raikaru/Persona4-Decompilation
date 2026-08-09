.section .text
.set noat
.set noreorder
glabel func_001bfc00
    /* BFC00 001BFC00 80FEBD27 */  addiu      $29, $29, -0x180
    /* BFC04 001BFC04 4000BFFF */  sd         $31, 0x40($29)
    /* BFC08 001BFC08 3000B27F */  sq         $18, 0x30($29)
    /* BFC0C 001BFC0C 2000B17F */  sq         $17, 0x20($29)
    /* BFC10 001BFC10 1000B07F */  sq         $16, 0x10($29)
    /* BFC14 001BFC14 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* BFC18 001BFC18 0800B6E7 */  swc1       $f22, 0x8($29)
    /* BFC1C 001BFC1C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* BFC20 001BFC20 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BFC24 001BFC24 2D908000 */  daddu      $18, $4, $0
    /* BFC28 001BFC28 E000828C */  lw         $2, 0xE0($4)
    /* BFC2C 001BFC2C 3000508C */  lw         $16, 0x30($2)
    /* BFC30 001BFC30 3800428C */  lw         $2, 0x38($2)
    /* BFC34 001BFC34 3000518C */  lw         $17, 0x30($2)
    /* BFC38 001BFC38 5000A427 */  addiu      $4, $29, 0x50
    /* BFC3C 001BFC3C 9C004526 */  addiu      $5, $18, 0x9C
    /* BFC40 001BFC40 58F5060C */  jal        func_001bd560
    /* BFC44 001BFC44 00000000 */   nop
    /* BFC48 001BFC48 DC0000C6 */  lwc1       $f0, 0xDC($16)
    /* BFC4C 001BFC4C 0801A0E7 */  swc1       $f0, 0x108($29)
    /* BFC50 001BFC50 840001C6 */  lwc1       $f1, 0x84($16)
    /* BFC54 001BFC54 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* BFC58 001BFC58 02080046 */  mul.s      $f0, $f1, $f0
    /* BFC5C 001BFC5C 0C01A0E7 */  swc1       $f0, 0x10C($29)
    /* BFC60 001BFC60 E40000C6 */  lwc1       $f0, 0xE4($16)
    /* BFC64 001BFC64 1001A0E7 */  swc1       $f0, 0x110($29)
    /* BFC68 001BFC68 2D202002 */  daddu      $4, $17, $0
    /* BFC6C 001BFC6C F800A527 */  addiu      $5, $29, 0xF8
    /* BFC70 001BFC70 1456060C */  jal        func_00195850
    /* BFC74 001BFC74 00000000 */   nop
    /* BFC78 001BFC78 2C0006C6 */  lwc1       $f6, 0x2C($16)
    /* BFC7C 001BFC7C 8C0000C6 */  lwc1       $f0, 0x8C($16)
    /* BFC80 001BFC80 42000646 */  mul.s      $f1, $f0, $f6
    /* BFC84 001BFC84 188185C7 */  lwc1       $f5, -0x7EE8($28)
    /* BFC88 001BFC88 0C01A0C7 */  lwc1       $f0, 0x10C($29)
    /* BFC8C 001BFC8C 00188044 */  mtc1       $0, $f3
    /* BFC90 001BFC90 00000000 */  nop
    /* BFC94 001BFC94 18180046 */  adda.s     $f3, $f0
    /* BFC98 001BFC98 1C290146 */  madd.s     $f4, $f5, $f1
    /* BFC9C 001BFC9C 2C0022C6 */  lwc1       $f2, 0x2C($17)
    /* BFCA0 001BFCA0 8C0020C6 */  lwc1       $f0, 0x8C($17)
    /* BFCA4 001BFCA4 42000246 */  mul.s      $f1, $f0, $f2
    /* BFCA8 001BFCA8 FC00A0C7 */  lwc1       $f0, 0xFC($29)
    /* BFCAC 001BFCAC 18180046 */  adda.s     $f3, $f0
    /* BFCB0 001BFCB0 1C280146 */  madd.s     $f0, $f5, $f1
    /* BFCB4 001BFCB4 80250046 */  add.s      $f22, $f4, $f0
    /* BFCB8 001BFCB8 E80001C6 */  lwc1       $f1, 0xE8($16)
    /* BFCBC 001BFCBC 900000C6 */  lwc1       $f0, 0x90($16)
    /* BFCC0 001BFCC0 18180146 */  adda.s     $f3, $f1
    /* BFCC4 001BFCC4 1E000646 */  madda.s    $f0, $f6
    /* BFCC8 001BFCC8 900020C6 */  lwc1       $f0, 0x90($17)
    /* BFCCC 001BFCCC 1C050246 */  madd.s     $f20, $f0, $f2
    /* BFCD0 001BFCD0 FC00A0AF */  sw         $0, 0xFC($29)
    /* BFCD4 001BFCD4 0C01A0AF */  sw         $0, 0x10C($29)
    /* BFCD8 001BFCD8 DC0001C6 */  lwc1       $f1, 0xDC($16)
    /* BFCDC 001BFCDC F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* BFCE0 001BFCE0 01080046 */  sub.s      $f0, $f1, $f0
    /* BFCE4 001BFCE4 4801A0E7 */  swc1       $f0, 0x148($29)
    /* BFCE8 001BFCE8 E00000C6 */  lwc1       $f0, 0xE0($16)
    /* BFCEC 001BFCEC 01000346 */  sub.s      $f0, $f0, $f3
    /* BFCF0 001BFCF0 4C01A0E7 */  swc1       $f0, 0x14C($29)
    /* BFCF4 001BFCF4 E40001C6 */  lwc1       $f1, 0xE4($16)
    /* BFCF8 001BFCF8 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BFCFC 001BFCFC 01080046 */  sub.s      $f0, $f1, $f0
    /* BFD00 001BFD00 5001A0E7 */  swc1       $f0, 0x150($29)
    /* BFD04 001BFD04 4801A427 */  addiu      $4, $29, 0x148
    /* BFD08 001BFD08 2D288000 */  daddu      $5, $4, $0
    /* BFD0C 001BFD0C 2C900F0C */  jal        func_003e40b0
    /* BFD10 001BFD10 00000000 */   nop
    /* BFD14 001BFD14 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* BFD18 001BFD18 00008244 */  mtc1       $2, $f0
    /* BFD1C 001BFD1C 00000000 */  nop
    /* BFD20 001BFD20 42001446 */  mul.s      $f1, $f0, $f20
    /* BFD24 001BFD24 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* BFD28 001BFD28 C2000146 */  mul.s      $f3, $f0, $f1
    /* BFD2C 001BFD2C 2801A3E7 */  swc1       $f3, 0x128($29)
    /* BFD30 001BFD30 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* BFD34 001BFD34 82000146 */  mul.s      $f2, $f0, $f1
    /* BFD38 001BFD38 2C01A2E7 */  swc1       $f2, 0x12C($29)
    /* BFD3C 001BFD3C 5001A0C7 */  lwc1       $f0, 0x150($29)
    /* BFD40 001BFD40 42000146 */  mul.s      $f1, $f0, $f1
    /* BFD44 001BFD44 3001A1E7 */  swc1       $f1, 0x130($29)
    /* BFD48 001BFD48 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* BFD4C 001BFD4C 00180046 */  add.s      $f0, $f3, $f0
    /* BFD50 001BFD50 2801A0E7 */  swc1       $f0, 0x128($29)
    /* BFD54 001BFD54 FC00A0C7 */  lwc1       $f0, 0xFC($29)
    /* BFD58 001BFD58 00100046 */  add.s      $f0, $f2, $f0
    /* BFD5C 001BFD5C 2C01A0E7 */  swc1       $f0, 0x12C($29)
    /* BFD60 001BFD60 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* BFD64 001BFD64 00080046 */  add.s      $f0, $f1, $f0
    /* BFD68 001BFD68 3001A0E7 */  swc1       $f0, 0x130($29)
    /* BFD6C 001BFD6C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* BFD70 001BFD70 00088244 */  mtc1       $2, $f1
    /* BFD74 001BFD74 00000000 */  nop
    /* BFD78 001BFD78 420D1646 */  mul.s      $f21, $f1, $f22
    /* BFD7C 001BFD7C 2C01B5E7 */  swc1       $f21, 0x12C($29)
    /* BFD80 001BFD80 5801A527 */  addiu      $5, $29, 0x158
    /* BFD84 001BFD84 5000A2DF */  ld         $2, 0x50($29)
    /* BFD88 001BFD88 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* BFD8C 001BFD8C 5801A2FF */  sd         $2, 0x158($29)
    /* BFD90 001BFD90 6001A0E7 */  swc1       $f0, 0x160($29)
    /* BFD94 001BFD94 5C01B6E7 */  swc1       $f22, 0x15C($29)
    /* BFD98 001BFD98 E80000C6 */  lwc1       $f0, 0xE8($16)
    /* BFD9C 001BFD9C 02080046 */  mul.s      $f0, $f1, $f0
    /* BFDA0 001BFDA0 0C0140E6 */  swc1       $f0, 0x10C($18)
    /* BFDA4 001BFDA4 2801A627 */  addiu      $6, $29, 0x128
    /* BFDA8 001BFDA8 2801A2C7 */  lwc1       $f2, 0x128($29)
    /* BFDAC 001BFDAC 2C01A1C7 */  lwc1       $f1, 0x12C($29)
    /* BFDB0 001BFDB0 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* BFDB4 001BFDB4 000142E6 */  swc1       $f2, 0x100($18)
    /* BFDB8 001BFDB8 040141E6 */  swc1       $f1, 0x104($18)
    /* BFDBC 001BFDBC 080140E6 */  swc1       $f0, 0x108($18)
    /* BFDC0 001BFDC0 7800A427 */  addiu      $4, $29, 0x78
    /* BFDC4 001BFDC4 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* BFDC8 001BFDC8 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* BFDCC 001BFDCC E0F5060C */  jal        func_001bd780
    /* BFDD0 001BFDD0 00000000 */   nop
    /* BFDD4 001BFDD4 900002C6 */  lwc1       $f2, 0x90($16)
    /* BFDD8 001BFDD8 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* BFDDC 001BFDDC 00008044 */  mtc1       $0, $f0
    /* BFDE0 001BFDE0 00000000 */  nop
    /* BFDE4 001BFDE4 18001446 */  adda.s     $f0, $f20
    /* BFDE8 001BFDE8 1E100146 */  madda.s    $f2, $f1
    /* BFDEC 001BFDEC 900021C6 */  lwc1       $f1, 0x90($17)
    /* BFDF0 001BFDF0 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* BFDF4 001BFDF4 9C0D0046 */  madd.s     $f22, $f1, $f0
    /* BFDF8 001BFDF8 5C00A427 */  addiu      $4, $29, 0x5C
    /* BFDFC 001BFDFC 7800A527 */  addiu      $5, $29, 0x78
    /* BFE00 001BFE00 ACB0070C */  jal        func_001ec2b0
    /* BFE04 001BFE04 00000000 */   nop
    /* BFE08 001BFE08 5C8181C7 */  lwc1       $f1, -0x7EA4($28)
    /* BFE0C 001BFE0C 36000146 */  c.le.s     $f0, $f1
    /* BFE10 001BFE10 89000145 */  bc1t       .L001C0038
    /* BFE14 001BFE14 00000000 */   nop
    /* BFE18 001BFE18 00000000 */  nop
    /* BFE1C 001BFE1C 00000000 */  nop
    /* BFE20 001BFE20 030D0046 */  div.s      $f20, $f1, $f0
    /* BFE24 001BFE24 5C00A427 */  addiu      $4, $29, 0x5C
    /* BFE28 001BFE28 7800A527 */  addiu      $5, $29, 0x78
    /* BFE2C 001BFE2C 9000A627 */  addiu      $6, $29, 0x90
    /* BFE30 001BFE30 1C730F0C */  jal        func_003dcc70
    /* BFE34 001BFE34 00000000 */   nop
    /* BFE38 001BFE38 00588044 */  mtc1       $0, $f11
    /* BFE3C 001BFE3C 00000000 */  nop
    /* BFE40 001BFE40 36A00B46 */  c.le.s     $f20, $f11
    /* BFE44 001BFE44 0B000045 */  bc1f       .L001BFE74
    /* BFE48 001BFE48 00000000 */   nop
    /* BFE4C 001BFE4C 5C00A3C7 */  lwc1       $f3, 0x5C($29)
    /* BFE50 001BFE50 6000A2C7 */  lwc1       $f2, 0x60($29)
    /* BFE54 001BFE54 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* BFE58 001BFE58 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* BFE5C 001BFE5C E000A3E7 */  swc1       $f3, 0xE0($29)
    /* BFE60 001BFE60 E400A2E7 */  swc1       $f2, 0xE4($29)
    /* BFE64 001BFE64 E800A1E7 */  swc1       $f1, 0xE8($29)
    /* BFE68 001BFE68 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* BFE6C 001BFE6C 56000010 */  b          .L001BFFC8
    /* BFE70 001BFE70 00000000 */   nop
  .L001BFE74:
    /* BFE74 001BFE74 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BFE78 001BFE78 00008244 */  mtc1       $2, $f0
    /* BFE7C 001BFE7C 00000000 */  nop
    /* BFE80 001BFE80 36001446 */  c.le.s     $f0, $f20
    /* BFE84 001BFE84 0B000045 */  bc1f       .L001BFEB4
    /* BFE88 001BFE88 00000000 */   nop
    /* BFE8C 001BFE8C 7800A3C7 */  lwc1       $f3, 0x78($29)
    /* BFE90 001BFE90 7C00A2C7 */  lwc1       $f2, 0x7C($29)
    /* BFE94 001BFE94 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* BFE98 001BFE98 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* BFE9C 001BFE9C E000A3E7 */  swc1       $f3, 0xE0($29)
    /* BFEA0 001BFEA0 E400A2E7 */  swc1       $f2, 0xE4($29)
    /* BFEA4 001BFEA4 E800A1E7 */  swc1       $f1, 0xE8($29)
    /* BFEA8 001BFEA8 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* BFEAC 001BFEAC 46000010 */  b          .L001BFFC8
    /* BFEB0 001BFEB0 00000000 */   nop
  .L001BFEB4:
    /* BFEB4 001BFEB4 01001446 */  sub.s      $f0, $f0, $f20
    /* BFEB8 001BFEB8 B400A28F */  lw         $2, 0xB4($29)
    /* BFEBC 001BFEBC 26004014 */  bnez       $2, .L001BFF58
    /* BFEC0 001BFEC0 00000000 */   nop
    /* BFEC4 001BFEC4 B000AAC7 */  lwc1       $f10, 0xB0($29)
    /* BFEC8 001BFEC8 02010A46 */  mul.s      $f4, $f0, $f10
    /* BFECC 001BFECC C2200446 */  mul.s      $f3, $f4, $f4
    /* BFED0 001BFED0 808189C7 */  lwc1       $f9, -0x7E80($28)
    /* BFED4 001BFED4 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* BFED8 001BFED8 18580846 */  adda.s     $f11, $f8
    /* BFEDC 001BFEDC 1C480346 */  madd.s     $f0, $f9, $f3
    /* BFEE0 001BFEE0 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* BFEE4 001BFEE4 18580746 */  adda.s     $f11, $f7
    /* BFEE8 001BFEE8 1C180046 */  madd.s     $f0, $f3, $f0
    /* BFEEC 001BFEEC 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* BFEF0 001BFEF0 18580646 */  adda.s     $f11, $f6
    /* BFEF4 001BFEF4 1C180046 */  madd.s     $f0, $f3, $f0
    /* BFEF8 001BFEF8 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* BFEFC 001BFEFC 18580546 */  adda.s     $f11, $f5
    /* BFF00 001BFF00 1C180046 */  madd.s     $f0, $f3, $f0
    /* BFF04 001BFF04 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* BFF08 001BFF08 18580246 */  adda.s     $f11, $f2
    /* BFF0C 001BFF0C 5C180046 */  madd.s     $f1, $f3, $f0
    /* BFF10 001BFF10 02180446 */  mul.s      $f0, $f3, $f4
    /* BFF14 001BFF14 18580446 */  adda.s     $f11, $f4
    /* BFF18 001BFF18 1C000146 */  madd.s     $f0, $f0, $f1
    /* BFF1C 001BFF1C 02A10A46 */  mul.s      $f4, $f20, $f10
    /* BFF20 001BFF20 C2200446 */  mul.s      $f3, $f4, $f4
    /* BFF24 001BFF24 18580846 */  adda.s     $f11, $f8
    /* BFF28 001BFF28 5C480346 */  madd.s     $f1, $f9, $f3
    /* BFF2C 001BFF2C 18580746 */  adda.s     $f11, $f7
    /* BFF30 001BFF30 5C180146 */  madd.s     $f1, $f3, $f1
    /* BFF34 001BFF34 18580646 */  adda.s     $f11, $f6
    /* BFF38 001BFF38 5C180146 */  madd.s     $f1, $f3, $f1
    /* BFF3C 001BFF3C 18580546 */  adda.s     $f11, $f5
    /* BFF40 001BFF40 5C180146 */  madd.s     $f1, $f3, $f1
    /* BFF44 001BFF44 18580246 */  adda.s     $f11, $f2
    /* BFF48 001BFF48 9C180146 */  madd.s     $f2, $f3, $f1
    /* BFF4C 001BFF4C 42180446 */  mul.s      $f1, $f3, $f4
    /* BFF50 001BFF50 18580446 */  adda.s     $f11, $f4
    /* BFF54 001BFF54 1C0D0246 */  madd.s     $f20, $f1, $f2
  .L001BFF58:
    /* BFF58 001BFF58 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* BFF5C 001BFF5C 42090046 */  mul.s      $f5, $f1, $f0
    /* BFF60 001BFF60 E000A5E7 */  swc1       $f5, 0xE0($29)
    /* BFF64 001BFF64 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* BFF68 001BFF68 02090046 */  mul.s      $f4, $f1, $f0
    /* BFF6C 001BFF6C E400A4E7 */  swc1       $f4, 0xE4($29)
    /* BFF70 001BFF70 9800A1C7 */  lwc1       $f1, 0x98($29)
    /* BFF74 001BFF74 C2080046 */  mul.s      $f3, $f1, $f0
    /* BFF78 001BFF78 E800A3E7 */  swc1       $f3, 0xE8($29)
    /* BFF7C 001BFF7C A000A1C7 */  lwc1       $f1, 0xA0($29)
    /* BFF80 001BFF80 00108044 */  mtc1       $0, $f2
    /* BFF84 001BFF84 00000000 */  nop
    /* BFF88 001BFF88 18100546 */  adda.s     $f2, $f5
    /* BFF8C 001BFF8C 5C081446 */  madd.s     $f1, $f1, $f20
    /* BFF90 001BFF90 E000A1E7 */  swc1       $f1, 0xE0($29)
    /* BFF94 001BFF94 A400A1C7 */  lwc1       $f1, 0xA4($29)
    /* BFF98 001BFF98 18100446 */  adda.s     $f2, $f4
    /* BFF9C 001BFF9C 5C081446 */  madd.s     $f1, $f1, $f20
    /* BFFA0 001BFFA0 E400A1E7 */  swc1       $f1, 0xE4($29)
    /* BFFA4 001BFFA4 A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* BFFA8 001BFFA8 18100346 */  adda.s     $f2, $f3
    /* BFFAC 001BFFAC 5C081446 */  madd.s     $f1, $f1, $f20
    /* BFFB0 001BFFB0 E800A1E7 */  swc1       $f1, 0xE8($29)
    /* BFFB4 001BFFB4 9C00A2C7 */  lwc1       $f2, 0x9C($29)
    /* BFFB8 001BFFB8 AC00A1C7 */  lwc1       $f1, 0xAC($29)
    /* BFFBC 001BFFBC 1A081446 */  mula.s     $f1, $f20
    /* BFFC0 001BFFC0 1C100046 */  madd.s     $f0, $f2, $f0
    /* BFFC4 001BFFC4 EC00A0E7 */  swc1       $f0, 0xEC($29)
  .L001BFFC8:
    /* BFFC8 001BFFC8 5801A427 */  addiu      $4, $29, 0x158
    /* BFFCC 001BFFCC 6100053C */  lui        $5, %hi(D_0060A100)
    /* BFFD0 001BFFD0 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* BFFD4 001BFFD4 01000624 */  addiu      $6, $0, 0x1
    /* BFFD8 001BFFD8 E000A727 */  addiu      $7, $29, 0xE0
    /* BFFDC 001BFFDC D0720F0C */  jal        func_003dcb40
    /* BFFE0 001BFFE0 00000000 */   nop
    /* BFFE4 001BFFE4 5801A1C7 */  lwc1       $f1, 0x158($29)
    /* BFFE8 001BFFE8 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* BFFEC 001BFFEC 00080046 */  add.s      $f0, $f1, $f0
    /* BFFF0 001BFFF0 5801A0E7 */  swc1       $f0, 0x158($29)
    /* BFFF4 001BFFF4 5C01A1C7 */  lwc1       $f1, 0x15C($29)
    /* BFFF8 001BFFF8 2C01A0C7 */  lwc1       $f0, 0x12C($29)
    /* BFFFC 001BFFFC 00080046 */  add.s      $f0, $f1, $f0
    /* C0000 001C0000 5C01A0E7 */  swc1       $f0, 0x15C($29)
    /* C0004 001C0004 6001A1C7 */  lwc1       $f1, 0x160($29)
    /* C0008 001C0008 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C000C 001C000C 00080046 */  add.s      $f0, $f1, $f0
    /* C0010 001C0010 6001A0E7 */  swc1       $f0, 0x160($29)
    /* C0014 001C0014 7800A427 */  addiu      $4, $29, 0x78
    /* C0018 001C0018 5801A527 */  addiu      $5, $29, 0x158
    /* C001C 001C001C 2801A627 */  addiu      $6, $29, 0x128
    /* C0020 001C0020 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C0024 001C0024 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C0028 001C0028 E0F5060C */  jal        func_001bd780
    /* C002C 001C002C 00000000 */   nop
    /* C0030 001C0030 0C000010 */  b          .L001C0064
    /* C0034 001C0034 00000000 */   nop
  .L001C0038:
    /* C0038 001C0038 4C8081C7 */  lwc1       $f1, -0x7FB4($28)
    /* C003C 001C003C 34000146 */  c.lt.s     $f0, $f1
    /* C0040 001C0040 08000045 */  bc1f       .L001C0064
    /* C0044 001C0044 00000000 */   nop
    /* C0048 001C0048 7800A427 */  addiu      $4, $29, 0x78
    /* C004C 001C004C 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* C0050 001C0050 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* C0054 001C0054 60818CC7 */  lwc1       $f12, -0x7EA0($28)
    /* C0058 001C0058 02000624 */  addiu      $6, $0, 0x2
    /* C005C 001C005C D0710F0C */  jal        func_003dc740
    /* C0060 001C0060 00000000 */   nop
  .L001C0064:
    /* C0064 001C0064 1644023C */  lui        $2, (0x44160000 >> 16)
    /* C0068 001C0068 00008244 */  mtc1       $2, $f0
    /* C006C 001C006C 00000000 */  nop
    /* C0070 001C0070 34B00046 */  c.lt.s     $f22, $f0
    /* C0074 001C0074 02000045 */  bc1f       .L001C0080
    /* C0078 001C0078 00000000 */   nop
    /* C007C 001C007C 86050046 */  mov.s      $f22, $f0
  .L001C0080:
    /* C0080 001C0080 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C0084 001C0084 00088244 */  mtc1       $2, $f1
    /* C0088 001C0088 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* C008C 001C008C 42080046 */  mul.s      $f1, $f1, $f0
    /* C0090 001C0090 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C0094 001C0094 02030146 */  mul.s      $f12, $f0, $f1
    /* C0098 001C0098 1A2E110C */  jal        func_0044b868
    /* C009C 001C009C 00000000 */   nop
    /* C00A0 001C00A0 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* C00A4 001C00A4 00108244 */  mtc1       $2, $f2
    /* C00A8 001C00A8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C00AC 001C00AC 00088244 */  mtc1       $2, $f1
    /* C00B0 001C00B0 00000000 */  nop
    /* C00B4 001C00B4 42081646 */  mul.s      $f1, $f1, $f22
    /* C00B8 001C00B8 42100146 */  mul.s      $f1, $f2, $f1
    /* C00BC 001C00BC C30D0046 */  div.s      $f23, $f1, $f0
    /* C00C0 001C00C0 5801A427 */  addiu      $4, $29, 0x158
    /* C00C4 001C00C4 6100053C */  lui        $5, %hi(D_0060A100)
    /* C00C8 001C00C8 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* C00CC 001C00CC 01000624 */  addiu      $6, $0, 0x1
    /* C00D0 001C00D0 7800A727 */  addiu      $7, $29, 0x78
    /* C00D4 001C00D4 D0720F0C */  jal        func_003dcb40
    /* C00D8 001C00D8 00000000 */   nop
    /* C00DC 001C00DC 5C01A0C7 */  lwc1       $f0, 0x15C($29)
    /* C00E0 001C00E0 4C01A0E7 */  swc1       $f0, 0x14C($29)
    /* C00E4 001C00E4 4801A427 */  addiu      $4, $29, 0x148
    /* C00E8 001C00E8 2D288000 */  daddu      $5, $4, $0
    /* C00EC 001C00EC 2C900F0C */  jal        func_003e40b0
    /* C00F0 001C00F0 00000000 */   nop
    /* C00F4 001C00F4 4801A4C7 */  lwc1       $f4, 0x148($29)
    /* C00F8 001C00F8 5001A5C7 */  lwc1       $f5, 0x150($29)
    /* C00FC 001C00FC 6001A3C7 */  lwc1       $f3, 0x160($29)
    /* C0100 001C0100 5801A2C7 */  lwc1       $f2, 0x158($29)
    /* C0104 001C0104 5C01A1C7 */  lwc1       $f1, 0x15C($29)
    /* C0108 001C0108 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* C010C 001C010C 1A080046 */  mula.s     $f1, $f0
    /* C0110 001C0110 00008044 */  mtc1       $0, $f0
    /* C0114 001C0114 1E100446 */  madda.s    $f2, $f4
    /* C0118 001C0118 1C1D0546 */  madd.s     $f20, $f3, $f5
    /* C011C 001C011C 34A00046 */  c.lt.s     $f20, $f0
    /* C0120 001C0120 0A000145 */  bc1t       .L001C014C
    /* C0124 001C0124 00000000 */   nop
    /* C0128 001C0128 900001C6 */  lwc1       $f1, 0x90($16)
    /* C012C 001C012C 2C0000C6 */  lwc1       $f0, 0x2C($16)
    /* C0130 001C0130 820D0046 */  mul.s      $f22, $f1, $f0
    /* C0134 001C0134 0801A2DF */  ld         $2, 0x108($29)
    /* C0138 001C0138 1001A0C7 */  lwc1       $f0, 0x110($29)
    /* C013C 001C013C 1801A2FF */  sd         $2, 0x118($29)
    /* C0140 001C0140 2001A0E7 */  swc1       $f0, 0x120($29)
    /* C0144 001C0144 08000010 */  b          .L001C0168
    /* C0148 001C0148 00000000 */   nop
  .L001C014C:
    /* C014C 001C014C 900021C6 */  lwc1       $f1, 0x90($17)
    /* C0150 001C0150 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* C0154 001C0154 820D0046 */  mul.s      $f22, $f1, $f0
    /* C0158 001C0158 F800A2DF */  ld         $2, 0xF8($29)
    /* C015C 001C015C 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* C0160 001C0160 1801A2FF */  sd         $2, 0x118($29)
    /* C0164 001C0164 2001A0E7 */  swc1       $f0, 0x120($29)
  .L001C0168:
    /* C0168 001C0168 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* C016C 001C016C 00088044 */  mtc1       $0, $f1
    /* C0170 001C0170 00000000 */  nop
    /* C0174 001C0174 18080046 */  adda.s     $f1, $f0
    /* C0178 001C0178 DC281646 */  madd.s     $f3, $f5, $f22
    /* C017C 001C017C 6801A3E7 */  swc1       $f3, 0x168($29)
    /* C0180 001C0180 2C01A2C7 */  lwc1       $f2, 0x12C($29)
    /* C0184 001C0184 6C01A2E7 */  swc1       $f2, 0x16C($29)
    /* C0188 001C0188 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* C018C 001C018C 18080046 */  adda.s     $f1, $f0
    /* C0190 001C0190 5D201646 */  msub.s     $f1, $f4, $f22
    /* C0194 001C0194 7001A1E7 */  swc1       $f1, 0x170($29)
    /* C0198 001C0198 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C019C 001C019C 01180046 */  sub.s      $f0, $f3, $f0
    /* C01A0 001C01A0 3801A0E7 */  swc1       $f0, 0x138($29)
    /* C01A4 001C01A4 01100246 */  sub.s      $f0, $f2, $f2
    /* C01A8 001C01A8 3C01A0E7 */  swc1       $f0, 0x13C($29)
    /* C01AC 001C01AC 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C01B0 001C01B0 01080046 */  sub.s      $f0, $f1, $f0
    /* C01B4 001C01B4 4001A0E7 */  swc1       $f0, 0x140($29)
    /* C01B8 001C01B8 3801A427 */  addiu      $4, $29, 0x138
    /* C01BC 001C01BC 2D288000 */  daddu      $5, $4, $0
    /* C01C0 001C01C0 2C900F0C */  jal        func_003e40b0
    /* C01C4 001C01C4 00000000 */   nop
    /* C01C8 001C01C8 4001A6C7 */  lwc1       $f6, 0x140($29)
    /* C01CC 001C01CC 5001A5C7 */  lwc1       $f5, 0x150($29)
    /* C01D0 001C01D0 3801A4C7 */  lwc1       $f4, 0x138($29)
    /* C01D4 001C01D4 4801A2C7 */  lwc1       $f2, 0x148($29)
    /* C01D8 001C01D8 3C01A1C7 */  lwc1       $f1, 0x13C($29)
    /* C01DC 001C01DC 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* C01E0 001C01E0 1A080046 */  mula.s     $f1, $f0
    /* C01E4 001C01E4 00188044 */  mtc1       $0, $f3
    /* C01E8 001C01E8 00000000 */  nop
    /* C01EC 001C01EC 1E200246 */  madda.s    $f4, $f2
    /* C01F0 001C01F0 9C300546 */  madd.s     $f2, $f6, $f5
    /* C01F4 001C01F4 45A00046 */  abs.s      $f1, $f20
    /* C01F8 001C01F8 05100046 */  abs.s      $f0, $f2
    /* C01FC 001C01FC 36080046 */  c.le.s     $f1, $f0
    /* C0200 001C0200 61000145 */  bc1t       .L001C0388
    /* C0204 001C0204 00000000 */   nop
    /* C0208 001C0208 32180246 */  c.eq.s     $f3, $f2
    /* C020C 001C020C 5E000145 */  bc1t       .L001C0388
    /* C0210 001C0210 00000000 */   nop
    /* C0214 001C0214 32181446 */  c.eq.s     $f3, $f20
    /* C0218 001C0218 5B000145 */  bc1t       .L001C0388
    /* C021C 001C021C 00000000 */   nop
    /* C0220 001C0220 2801A1C7 */  lwc1       $f1, 0x128($29)
    /* C0224 001C0224 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* C0228 001C0228 01080046 */  sub.s      $f0, $f1, $f0
    /* C022C 001C022C 7801A0E7 */  swc1       $f0, 0x178($29)
    /* C0230 001C0230 2001B4C7 */  lwc1       $f20, 0x120($29)
    /* C0234 001C0234 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C0238 001C0238 01001446 */  sub.s      $f0, $f0, $f20
    /* C023C 001C023C 7C01A0E7 */  swc1       $f0, 0x17C($29)
    /* C0240 001C0240 7801A427 */  addiu      $4, $29, 0x178
    /* C0244 001C0244 6C900F0C */  jal        func_003e41b0
    /* C0248 001C0248 00000000 */   nop
    /* C024C 001C024C 02A80046 */  mul.s      $f0, $f21, $f0
    /* C0250 001C0250 00000000 */  nop
    /* C0254 001C0254 43001746 */  div.s      $f1, $f0, $f23
    /* C0258 001C0258 2C01A0C7 */  lwc1       $f0, 0x12C($29)
    /* C025C 001C025C 00000146 */  add.s      $f0, $f0, $f1
    /* C0260 001C0260 6C01A0E7 */  swc1       $f0, 0x16C($29)
    /* C0264 001C0264 5001A2C7 */  lwc1       $f2, 0x150($29)
    /* C0268 001C0268 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* C026C 001C026C 00088044 */  mtc1       $0, $f1
    /* C0270 001C0270 00000000 */  nop
    /* C0274 001C0274 18080046 */  adda.s     $f1, $f0
    /* C0278 001C0278 1C101646 */  madd.s     $f0, $f2, $f22
    /* C027C 001C027C 6801A0E7 */  swc1       $f0, 0x168($29)
    /* C0280 001C0280 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* C0284 001C0284 18081446 */  adda.s     $f1, $f20
    /* C0288 001C0288 1D001646 */  msub.s     $f0, $f0, $f22
    /* C028C 001C028C 7001A0E7 */  swc1       $f0, 0x170($29)
    /* C0290 001C0290 C000A427 */  addiu      $4, $29, 0xC0
    /* C0294 001C0294 6801A527 */  addiu      $5, $29, 0x168
    /* C0298 001C0298 2801A627 */  addiu      $6, $29, 0x128
    /* C029C 001C029C 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C02A0 001C02A0 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C02A4 001C02A4 E0F5060C */  jal        func_001bd780
    /* C02A8 001C02A8 00000000 */   nop
    /* C02AC 001C02AC 5C00A427 */  addiu      $4, $29, 0x5C
    /* C02B0 001C02B0 C000A527 */  addiu      $5, $29, 0xC0
    /* C02B4 001C02B4 ACB0070C */  jal        func_001ec2b0
    /* C02B8 001C02B8 00000000 */   nop
    /* C02BC 001C02BC 46050046 */  mov.s      $f21, $f0
    /* C02C0 001C02C0 5001A2C7 */  lwc1       $f2, 0x150($29)
    /* C02C4 001C02C4 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* C02C8 001C02C8 00088044 */  mtc1       $0, $f1
    /* C02CC 001C02CC 00000000 */  nop
    /* C02D0 001C02D0 18080046 */  adda.s     $f1, $f0
    /* C02D4 001C02D4 1D101646 */  msub.s     $f0, $f2, $f22
    /* C02D8 001C02D8 6801A0E7 */  swc1       $f0, 0x168($29)
    /* C02DC 001C02DC 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* C02E0 001C02E0 18081446 */  adda.s     $f1, $f20
    /* C02E4 001C02E4 1C001646 */  madd.s     $f0, $f0, $f22
    /* C02E8 001C02E8 7001A0E7 */  swc1       $f0, 0x170($29)
    /* C02EC 001C02EC D000A427 */  addiu      $4, $29, 0xD0
    /* C02F0 001C02F0 6801A527 */  addiu      $5, $29, 0x168
    /* C02F4 001C02F4 2801A627 */  addiu      $6, $29, 0x128
    /* C02F8 001C02F8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C02FC 001C02FC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C0300 001C0300 E0F5060C */  jal        func_001bd780
    /* C0304 001C0304 00000000 */   nop
    /* C0308 001C0308 5C00A427 */  addiu      $4, $29, 0x5C
    /* C030C 001C030C D000A527 */  addiu      $5, $29, 0xD0
    /* C0310 001C0310 ACB0070C */  jal        func_001ec2b0
    /* C0314 001C0314 00000000 */   nop
    /* C0318 001C0318 34A80046 */  c.lt.s     $f21, $f0
    /* C031C 001C031C 0B000045 */  bc1f       .L001C034C
    /* C0320 001C0320 00000000 */   nop
    /* C0324 001C0324 C000A3C7 */  lwc1       $f3, 0xC0($29)
    /* C0328 001C0328 C400A2C7 */  lwc1       $f2, 0xC4($29)
    /* C032C 001C032C C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* C0330 001C0330 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* C0334 001C0334 7800A3E7 */  swc1       $f3, 0x78($29)
    /* C0338 001C0338 7C00A2E7 */  swc1       $f2, 0x7C($29)
    /* C033C 001C033C 8000A1E7 */  swc1       $f1, 0x80($29)
    /* C0340 001C0340 8400A0E7 */  swc1       $f0, 0x84($29)
    /* C0344 001C0344 09000010 */  b          .L001C036C
    /* C0348 001C0348 00000000 */   nop
  .L001C034C:
    /* C034C 001C034C D000A3C7 */  lwc1       $f3, 0xD0($29)
    /* C0350 001C0350 D400A2C7 */  lwc1       $f2, 0xD4($29)
    /* C0354 001C0354 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* C0358 001C0358 DC00A0C7 */  lwc1       $f0, 0xDC($29)
    /* C035C 001C035C 7800A3E7 */  swc1       $f3, 0x78($29)
    /* C0360 001C0360 7C00A2E7 */  swc1       $f2, 0x7C($29)
    /* C0364 001C0364 8000A1E7 */  swc1       $f1, 0x80($29)
    /* C0368 001C0368 8400A0E7 */  swc1       $f0, 0x84($29)
  .L001C036C:
    /* C036C 001C036C 5801A427 */  addiu      $4, $29, 0x158
    /* C0370 001C0370 6100053C */  lui        $5, %hi(D_0060A100)
    /* C0374 001C0374 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* C0378 001C0378 01000624 */  addiu      $6, $0, 0x1
    /* C037C 001C037C 7800A727 */  addiu      $7, $29, 0x78
    /* C0380 001C0380 D0720F0C */  jal        func_003dcb40
    /* C0384 001C0384 00000000 */   nop
  .L001C0388:
    /* C0388 001C0388 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* C038C 001C038C 02001746 */  mul.s      $f0, $f0, $f23
    /* C0390 001C0390 5801A0E7 */  swc1       $f0, 0x158($29)
    /* C0394 001C0394 5C01A0C7 */  lwc1       $f0, 0x15C($29)
    /* C0398 001C0398 02001746 */  mul.s      $f0, $f0, $f23
    /* C039C 001C039C 5C01A0E7 */  swc1       $f0, 0x15C($29)
    /* C03A0 001C03A0 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* C03A4 001C03A4 02001746 */  mul.s      $f0, $f0, $f23
    /* C03A8 001C03A8 6001A0E7 */  swc1       $f0, 0x160($29)
    /* C03AC 001C03AC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C03B0 001C03B0 00088244 */  mtc1       $2, $f1
    /* C03B4 001C03B4 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* C03B8 001C03B8 42080046 */  mul.s      $f1, $f1, $f0
    /* C03BC 001C03BC 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C03C0 001C03C0 02030146 */  mul.s      $f12, $f0, $f1
    /* C03C4 001C03C4 1A2E110C */  jal        func_0044b868
    /* C03C8 001C03C8 00000000 */   nop
    /* C03CC 001C03CC 42B80046 */  mul.s      $f1, $f23, $f0
    /* C03D0 001C03D0 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* C03D4 001C03D4 00008244 */  mtc1       $2, $f0
    /* C03D8 001C03D8 00000000 */  nop
    /* C03DC 001C03DC 020D0046 */  mul.s      $f20, $f1, $f0
    /* C03E0 001C03E0 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* C03E4 001C03E4 7801A0E7 */  swc1       $f0, 0x178($29)
    /* C03E8 001C03E8 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* C03EC 001C03EC 7C01A0E7 */  swc1       $f0, 0x17C($29)
    /* C03F0 001C03F0 7801A427 */  addiu      $4, $29, 0x178
    /* C03F4 001C03F4 2D288000 */  daddu      $5, $4, $0
    /* C03F8 001C03F8 78900F0C */  jal        func_003e41e0
    /* C03FC 001C03FC 00000000 */   nop
    /* C0400 001C0400 7C01A1C7 */  lwc1       $f1, 0x17C($29)
    /* C0404 001C0404 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C0408 001C0408 00108044 */  mtc1       $0, $f2
    /* C040C 001C040C 00000000 */  nop
    /* C0410 001C0410 18100046 */  adda.s     $f2, $f0
    /* C0414 001C0414 DC081446 */  madd.s     $f3, $f1, $f20
    /* C0418 001C0418 2801A3E7 */  swc1       $f3, 0x128($29)
    /* C041C 001C041C 7801A1C7 */  lwc1       $f1, 0x178($29)
    /* C0420 001C0420 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C0424 001C0424 18100046 */  adda.s     $f2, $f0
    /* C0428 001C0428 9D081446 */  msub.s     $f2, $f1, $f20
    /* C042C 001C042C 3001A2E7 */  swc1       $f2, 0x130($29)
    /* C0430 001C0430 5801A0C7 */  lwc1       $f0, 0x158($29)
    /* C0434 001C0434 00180046 */  add.s      $f0, $f3, $f0
    /* C0438 001C0438 6C00A0E7 */  swc1       $f0, 0x6C($29)
    /* C043C 001C043C 2C01A1C7 */  lwc1       $f1, 0x12C($29)
    /* C0440 001C0440 5C01A0C7 */  lwc1       $f0, 0x15C($29)
    /* C0444 001C0444 00080046 */  add.s      $f0, $f1, $f0
    /* C0448 001C0448 7000A0E7 */  swc1       $f0, 0x70($29)
    /* C044C 001C044C 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* C0450 001C0450 00100046 */  add.s      $f0, $f2, $f0
    /* C0454 001C0454 7400A0E7 */  swc1       $f0, 0x74($29)
    /* C0458 001C0458 5000A427 */  addiu      $4, $29, 0x50
    /* C045C 001C045C 2D288000 */  daddu      $5, $4, $0
    /* C0460 001C0460 E8F0060C */  jal        func_001bc3a0
    /* C0464 001C0464 00000000 */   nop
    /* C0468 001C0468 6C00A427 */  addiu      $4, $29, 0x6C
    /* C046C 001C046C 2D288000 */  daddu      $5, $4, $0
    /* C0470 001C0470 E8F0060C */  jal        func_001bc3a0
    /* C0474 001C0474 00000000 */   nop
    /* C0478 001C0478 2D204002 */  daddu      $4, $18, $0
    /* C047C 001C047C 5000A527 */  addiu      $5, $29, 0x50
    /* C0480 001C0480 6C00A627 */  addiu      $6, $29, 0x6C
    /* C0484 001C0484 01000724 */  addiu      $7, $0, 0x1
    /* C0488 001C0488 08EB060C */  jal        func_001bac20
    /* C048C 001C048C 00000000 */   nop
    /* C0490 001C0490 0040023C */  lui        $2, (0x40000000 >> 16)
    /* C0494 001C0494 00608244 */  mtc1       $2, $f12
    /* C0498 001C0498 2D204002 */  daddu      $4, $18, $0
    /* C049C 001C049C BCEF060C */  jal        func_001bbef0
    /* C04A0 001C04A0 00000000 */   nop
    /* C04A4 001C04A4 4000BFDF */  ld         $31, 0x40($29)
    /* C04A8 001C04A8 3000B27B */  lq         $18, 0x30($29)
    /* C04AC 001C04AC 2000B17B */  lq         $17, 0x20($29)
    /* C04B0 001C04B0 1000B07B */  lq         $16, 0x10($29)
    /* C04B4 001C04B4 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* C04B8 001C04B8 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* C04BC 001C04BC 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* C04C0 001C04C0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* C04C4 001C04C4 8001BD27 */  addiu      $29, $29, 0x180
    /* C04C8 001C04C8 0800E003 */  jr         $31
    /* C04CC 001C04CC 00000000 */   nop
    /* C04D0 001C04D0 0800E003 */  jr         $31
    /* C04D4 001C04D4 00000000 */   nop
    /* C04D8 001C04D8 00000000 */  nop
    /* C04DC 001C04DC 00000000 */  nop
.size func_001bfc00, 0x8e0
