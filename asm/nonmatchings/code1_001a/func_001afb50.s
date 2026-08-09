.section .text
.set noat
.set noreorder
glabel func_001afb50
    /* AFB50 001AFB50 C0FFBD27 */  addiu      $29, $29, -0x40
    /* AFB54 001AFB54 3000BFFF */  sd         $31, 0x30($29)
    /* AFB58 001AFB58 2000B27F */  sq         $18, 0x20($29)
    /* AFB5C 001AFB5C 1000B17F */  sq         $17, 0x10($29)
    /* AFB60 001AFB60 0000B07F */  sq         $16, 0x0($29)
    /* AFB64 001AFB64 2D908000 */  daddu      $18, $4, $0
    /* AFB68 001AFB68 ACB3838F */  lw         $3, -0x4C54($28)
    /* AFB6C 001AFB6C 0C00638C */  lw         $3, 0xC($3)
    /* AFB70 001AFB70 80006330 */  andi       $3, $3, 0x80
    /* AFB74 001AFB74 22016014 */  bnez       $3, .L001B0000
    /* AFB78 001AFB78 00000000 */   nop
    /* AFB7C 001AFB7C 18004396 */  lhu        $3, 0x18($18)
    /* AFB80 001AFB80 04006230 */  andi       $2, $3, 0x4
    /* AFB84 001AFB84 2B800200 */  sltu       $16, $0, $2
    /* AFB88 001AFB88 08006230 */  andi       $2, $3, 0x8
    /* AFB8C 001AFB8C 17004010 */  beqz       $2, .L001AFBEC
    /* AFB90 001AFB90 00000000 */   nop
    /* AFB94 001AFB94 D87F060C */  jal        func_0019ff60
    /* AFB98 001AFB98 00000000 */   nop
    /* AFB9C 001AFB9C 13004010 */  beqz       $2, .L001AFBEC
    /* AFBA0 001AFBA0 00000000 */   nop
    /* AFBA4 001AFBA4 04050424 */  addiu      $4, $0, 0x504
    /* AFBA8 001AFBA8 344F060C */  jal        func_00193cd0
    /* AFBAC 001AFBAC 00000000 */   nop
    /* AFBB0 001AFBB0 13014014 */  bnez       $2, .L001B0000
    /* AFBB4 001AFBB4 00000000 */   nop
    /* AFBB8 001AFBB8 06050424 */  addiu      $4, $0, 0x506
    /* AFBBC 001AFBBC 344F060C */  jal        func_00193cd0
    /* AFBC0 001AFBC0 00000000 */   nop
    /* AFBC4 001AFBC4 0E014014 */  bnez       $2, .L001B0000
    /* AFBC8 001AFBC8 00000000 */   nop
    /* AFBCC 001AFBCC 1E000224 */  addiu      $2, $0, 0x1E
    /* AFBD0 001AFBD0 160042A6 */  sh         $2, 0x16($18)
    /* AFBD4 001AFBD4 2D204002 */  daddu      $4, $18, $0
    /* AFBD8 001AFBD8 8CC3060C */  jal        func_001b0e30
    /* AFBDC 001AFBDC 00000000 */   nop
    /* AFBE0 001AFBE0 01001124 */  addiu      $17, $0, 0x1
    /* AFBE4 001AFBE4 05000010 */  b          .L001AFBFC
    /* AFBE8 001AFBE8 00000000 */   nop
  .L001AFBEC:
    /* AFBEC 001AFBEC 18004296 */  lhu        $2, 0x18($18)
    /* AFBF0 001AFBF0 F7FF4230 */  andi       $2, $2, 0xFFF7
    /* AFBF4 001AFBF4 180042A6 */  sh         $2, 0x18($18)
    /* AFBF8 001AFBF8 2D880000 */  daddu      $17, $0, $0
  .L001AFBFC:
    /* AFBFC 001AFBFC 18004296 */  lhu        $2, 0x18($18)
    /* AFC00 001AFC00 00804230 */  andi       $2, $2, 0x8000
    /* AFC04 001AFC04 06004014 */  bnez       $2, .L001AFC20
    /* AFC08 001AFC08 00000000 */   nop
    /* AFC0C 001AFC0C 04000016 */  bnez       $16, .L001AFC20
    /* AFC10 001AFC10 00000000 */   nop
    /* AFC14 001AFC14 2000428E */  lw         $2, 0x20($18)
    /* AFC18 001AFC18 01004224 */  addiu      $2, $2, 0x1
    /* AFC1C 001AFC1C 200042AE */  sw         $2, 0x20($18)
  .L001AFC20:
    /* AFC20 001AFC20 184C060C */  jal        func_00193060
    /* AFC24 001AFC24 00000000 */   nop
    /* AFC28 001AFC28 8D004014 */  bnez       $2, .L001AFE60
    /* AFC2C 001AFC2C 00000000 */   nop
    /* AFC30 001AFC30 18004296 */  lhu        $2, 0x18($18)
    /* AFC34 001AFC34 00804230 */  andi       $2, $2, 0x8000
    /* AFC38 001AFC38 61004014 */  bnez       $2, .L001AFDC0
    /* AFC3C 001AFC3C 00000000 */   nop
    /* AFC40 001AFC40 5F000016 */  bnez       $16, .L001AFDC0
    /* AFC44 001AFC44 00000000 */   nop
    /* AFC48 001AFC48 29004292 */  lbu        $2, 0x29($18)
    /* AFC4C 001AFC4C 11004018 */  blez       $2, .L001AFC94
    /* AFC50 001AFC50 00000000 */   nop
    /* AFC54 001AFC54 28004292 */  lbu        $2, 0x28($18)
    /* AFC58 001AFC58 0D004014 */  bnez       $2, .L001AFC90
    /* AFC5C 001AFC5C 00000000 */   nop
    /* AFC60 001AFC60 3000428E */  lw         $2, 0x30($18)
    /* AFC64 001AFC64 640A448C */  lw         $4, 0xA64($2)
    /* AFC68 001AFC68 2D280000 */  daddu      $5, $0, $0
    /* AFC6C 001AFC6C 3C0A090C */  jal        func_002428f0
    /* AFC70 001AFC70 00000000 */   nop
    /* AFC74 001AFC74 06004014 */  bnez       $2, .L001AFC90
    /* AFC78 001AFC78 00000000 */   nop
    /* AFC7C 001AFC7C 29004292 */  lbu        $2, 0x29($18)
    /* AFC80 001AFC80 FFFF4224 */  addiu      $2, $2, -0x1
    /* AFC84 001AFC84 290042A2 */  sb         $2, 0x29($18)
    /* AFC88 001AFC88 02000010 */  b          .L001AFC94
    /* AFC8C 001AFC8C 00000000 */   nop
  .L001AFC90:
    /* AFC90 001AFC90 290040A2 */  sb         $0, 0x29($18)
  .L001AFC94:
    /* AFC94 001AFC94 3000428E */  lw         $2, 0x30($18)
    /* AFC98 001AFC98 640A448C */  lw         $4, 0xA64($2)
    /* AFC9C 001AFC9C 2D280000 */  daddu      $5, $0, $0
    /* AFCA0 001AFCA0 3C0A090C */  jal        func_002428f0
    /* AFCA4 001AFCA4 00000000 */   nop
    /* AFCA8 001AFCA8 28004392 */  lbu        $3, 0x28($18)
    /* AFCAC 001AFCAC 04006014 */  bnez       $3, .L001AFCC0
    /* AFCB0 001AFCB0 00000000 */   nop
    /* AFCB4 001AFCB4 29004392 */  lbu        $3, 0x29($18)
    /* AFCB8 001AFCB8 03006010 */  beqz       $3, .L001AFCC8
    /* AFCBC 001AFCBC 00000000 */   nop
  .L001AFCC0:
    /* AFCC0 001AFCC0 37004010 */  beqz       $2, .L001AFDA0
    /* AFCC4 001AFCC4 00000000 */   nop
  .L001AFCC8:
    /* AFCC8 001AFCC8 06004010 */  beqz       $2, .L001AFCE4
    /* AFCCC 001AFCCC 00000000 */   nop
    /* AFCD0 001AFCD0 280040A2 */  sb         $0, 0x28($18)
    /* AFCD4 001AFCD4 290040A2 */  sb         $0, 0x29($18)
    /* AFCD8 001AFCD8 2D204002 */  daddu      $4, $18, $0
    /* AFCDC 001AFCDC 74C3060C */  jal        func_001b0dd0
    /* AFCE0 001AFCE0 00000000 */   nop
  .L001AFCE4:
    /* AFCE4 001AFCE4 1A004496 */  lhu        $4, 0x1A($18)
    /* AFCE8 001AFCE8 01008230 */  andi       $2, $4, 0x1
    /* AFCEC 001AFCEC 04004014 */  bnez       $2, .L001AFD00
    /* AFCF0 001AFCF0 00000000 */   nop
    /* AFCF4 001AFCF4 2D100000 */  daddu      $2, $0, $0
    /* AFCF8 001AFCF8 11000010 */  b          .L001AFD40
    /* AFCFC 001AFCFC 00000000 */   nop
  .L001AFD00:
    /* AFD00 001AFD00 3000428E */  lw         $2, 0x30($18)
    /* AFD04 001AFD04 0C0A438C */  lw         $3, 0xA0C($2)
    /* AFD08 001AFD08 10008230 */  andi       $2, $4, 0x10
    /* AFD0C 001AFD0C 04004014 */  bnez       $2, .L001AFD20
    /* AFD10 001AFD10 00000000 */   nop
    /* AFD14 001AFD14 2D100000 */  daddu      $2, $0, $0
    /* AFD18 001AFD18 09000010 */  b          .L001AFD40
    /* AFD1C 001AFD1C 00000000 */   nop
  .L001AFD20:
    /* AFD20 001AFD20 9800628C */  lw         $2, 0x98($3)
    /* AFD24 001AFD24 02004230 */  andi       $2, $2, 0x2
    /* AFD28 001AFD28 04004010 */  beqz       $2, .L001AFD3C
    /* AFD2C 001AFD2C 00000000 */   nop
    /* AFD30 001AFD30 01000224 */  addiu      $2, $0, 0x1
    /* AFD34 001AFD34 02000010 */  b          .L001AFD40
    /* AFD38 001AFD38 00000000 */   nop
  .L001AFD3C:
    /* AFD3C 001AFD3C 2D100000 */  daddu      $2, $0, $0
  .L001AFD40:
    /* AFD40 001AFD40 0B004010 */  beqz       $2, .L001AFD70
    /* AFD44 001AFD44 00000000 */   nop
    /* AFD48 001AFD48 3000428E */  lw         $2, 0x30($18)
    /* AFD4C 001AFD4C 0C0A448C */  lw         $4, 0xA0C($2)
    /* AFD50 001AFD50 A86D060C */  jal        func_0019b6a0
    /* AFD54 001AFD54 00000000 */   nop
    /* AFD58 001AFD58 2D204000 */  daddu      $4, $2, $0
    /* AFD5C 001AFD5C 000043DE */  ld         $3, 0x0($18)
    /* AFD60 001AFD60 600043FC */  sd         $3, 0x60($2)
    /* AFD64 001AFD64 01000524 */  addiu      $5, $0, 0x1
    /* AFD68 001AFD68 6451060C */  jal        func_00194590
    /* AFD6C 001AFD6C 00000000 */   nop
  .L001AFD70:
    /* AFD70 001AFD70 3000428E */  lw         $2, 0x30($18)
    /* AFD74 001AFD74 640A448C */  lw         $4, 0xA64($2)
    /* AFD78 001AFD78 44D4080C */  jal        func_00235110
    /* AFD7C 001AFD7C 00000000 */   nop
    /* AFD80 001AFD80 01000424 */  addiu      $4, $0, 0x1
    /* AFD84 001AFD84 80D6070C */  jal        func_001f5a00
    /* AFD88 001AFD88 00000000 */   nop
    /* AFD8C 001AFD8C 2D204002 */  daddu      $4, $18, $0
    /* AFD90 001AFD90 F0C4060C */  jal        func_001b13c0
    /* AFD94 001AFD94 00000000 */   nop
    /* AFD98 001AFD98 35000010 */  b          .L001AFE70
    /* AFD9C 001AFD9C 00000000 */   nop
  .L001AFDA0:
    /* AFDA0 001AFDA0 2D204002 */  daddu      $4, $18, $0
    /* AFDA4 001AFDA4 14C5060C */  jal        func_001b1450
    /* AFDA8 001AFDA8 00000000 */   nop
    /* AFDAC 001AFDAC 2D200000 */  daddu      $4, $0, $0
    /* AFDB0 001AFDB0 80D6070C */  jal        func_001f5a00
    /* AFDB4 001AFDB4 00000000 */   nop
    /* AFDB8 001AFDB8 2D000010 */  b          .L001AFE70
    /* AFDBC 001AFDBC 00000000 */   nop
  .L001AFDC0:
    /* AFDC0 001AFDC0 1A004496 */  lhu        $4, 0x1A($18)
    /* AFDC4 001AFDC4 01008230 */  andi       $2, $4, 0x1
    /* AFDC8 001AFDC8 04004014 */  bnez       $2, .L001AFDDC
    /* AFDCC 001AFDCC 00000000 */   nop
    /* AFDD0 001AFDD0 2D100000 */  daddu      $2, $0, $0
    /* AFDD4 001AFDD4 11000010 */  b          .L001AFE1C
    /* AFDD8 001AFDD8 00000000 */   nop
  .L001AFDDC:
    /* AFDDC 001AFDDC 3000428E */  lw         $2, 0x30($18)
    /* AFDE0 001AFDE0 0C0A438C */  lw         $3, 0xA0C($2)
    /* AFDE4 001AFDE4 10008230 */  andi       $2, $4, 0x10
    /* AFDE8 001AFDE8 04004014 */  bnez       $2, .L001AFDFC
    /* AFDEC 001AFDEC 00000000 */   nop
    /* AFDF0 001AFDF0 2D100000 */  daddu      $2, $0, $0
    /* AFDF4 001AFDF4 09000010 */  b          .L001AFE1C
    /* AFDF8 001AFDF8 00000000 */   nop
  .L001AFDFC:
    /* AFDFC 001AFDFC 9800628C */  lw         $2, 0x98($3)
    /* AFE00 001AFE00 02004230 */  andi       $2, $2, 0x2
    /* AFE04 001AFE04 04004010 */  beqz       $2, .L001AFE18
    /* AFE08 001AFE08 00000000 */   nop
    /* AFE0C 001AFE0C 01000224 */  addiu      $2, $0, 0x1
    /* AFE10 001AFE10 02000010 */  b          .L001AFE1C
    /* AFE14 001AFE14 00000000 */   nop
  .L001AFE18:
    /* AFE18 001AFE18 2D100000 */  daddu      $2, $0, $0
  .L001AFE1C:
    /* AFE1C 001AFE1C 0B004010 */  beqz       $2, .L001AFE4C
    /* AFE20 001AFE20 00000000 */   nop
    /* AFE24 001AFE24 3000428E */  lw         $2, 0x30($18)
    /* AFE28 001AFE28 0C0A448C */  lw         $4, 0xA0C($2)
    /* AFE2C 001AFE2C A86D060C */  jal        func_0019b6a0
    /* AFE30 001AFE30 00000000 */   nop
    /* AFE34 001AFE34 2D204000 */  daddu      $4, $2, $0
    /* AFE38 001AFE38 000043DE */  ld         $3, 0x0($18)
    /* AFE3C 001AFE3C 600043FC */  sd         $3, 0x60($2)
    /* AFE40 001AFE40 01000524 */  addiu      $5, $0, 0x1
    /* AFE44 001AFE44 6451060C */  jal        func_00194590
    /* AFE48 001AFE48 00000000 */   nop
  .L001AFE4C:
    /* AFE4C 001AFE4C 2D204002 */  daddu      $4, $18, $0
    /* AFE50 001AFE50 F0C4060C */  jal        func_001b13c0
    /* AFE54 001AFE54 00000000 */   nop
    /* AFE58 001AFE58 05000010 */  b          .L001AFE70
    /* AFE5C 001AFE5C 00000000 */   nop
  .L001AFE60:
    /* AFE60 001AFE60 ACB3838F */  lw         $3, -0x4C54($28)
    /* AFE64 001AFE64 0C00628C */  lw         $2, 0xC($3)
    /* AFE68 001AFE68 80004234 */  ori        $2, $2, 0x80
    /* AFE6C 001AFE6C 0C0062AC */  sw         $2, 0xC($3)
  .L001AFE70:
    /* AFE70 001AFE70 04000016 */  bnez       $16, .L001AFE84
    /* AFE74 001AFE74 00000000 */   nop
    /* AFE78 001AFE78 18004296 */  lhu        $2, 0x18($18)
    /* AFE7C 001AFE7C FF7F4230 */  andi       $2, $2, 0x7FFF
    /* AFE80 001AFE80 180042A6 */  sh         $2, 0x18($18)
  .L001AFE84:
    /* AFE84 001AFE84 ACB3828F */  lw         $2, -0x4C54($28)
    /* AFE88 001AFE88 0C00428C */  lw         $2, 0xC($2)
    /* AFE8C 001AFE8C 80004230 */  andi       $2, $2, 0x80
    /* AFE90 001AFE90 32004014 */  bnez       $2, .L001AFF5C
    /* AFE94 001AFE94 00000000 */   nop
    /* AFE98 001AFE98 07002012 */  beqz       $17, .L001AFEB8
    /* AFE9C 001AFE9C 00000000 */   nop
    /* AFEA0 001AFEA0 2D204002 */  daddu      $4, $18, $0
    /* AFEA4 001AFEA4 01000524 */  addiu      $5, $0, 0x1
    /* AFEA8 001AFEA8 00C2060C */  jal        func_001b0800
    /* AFEAC 001AFEAC 00000000 */   nop
    /* AFEB0 001AFEB0 53000010 */  b          .L001B0000
    /* AFEB4 001AFEB4 00000000 */   nop
  .L001AFEB8:
    /* AFEB8 001AFEB8 18004296 */  lhu        $2, 0x18($18)
    /* AFEBC 001AFEBC 20004230 */  andi       $2, $2, 0x20
    /* AFEC0 001AFEC0 07004014 */  bnez       $2, .L001AFEE0
    /* AFEC4 001AFEC4 00000000 */   nop
    /* AFEC8 001AFEC8 2D204002 */  daddu      $4, $18, $0
    /* AFECC 001AFECC 22000524 */  addiu      $5, $0, 0x22
    /* AFED0 001AFED0 00C2060C */  jal        func_001b0800
    /* AFED4 001AFED4 00000000 */   nop
    /* AFED8 001AFED8 49000010 */  b          .L001B0000
    /* AFEDC 001AFEDC 00000000 */   nop
  .L001AFEE0:
    /* AFEE0 001AFEE0 2D204002 */  daddu      $4, $18, $0
    /* AFEE4 001AFEE4 74C3060C */  jal        func_001b0dd0
    /* AFEE8 001AFEE8 00000000 */   nop
    /* AFEEC 001AFEEC 3000448E */  lw         $4, 0x30($18)
    /* AFEF0 001AFEF0 A2008390 */  lbu        $3, 0xA2($4)
    /* AFEF4 001AFEF4 01000224 */  addiu      $2, $0, 0x1
    /* AFEF8 001AFEF8 0A006214 */  bne        $3, $2, .L001AFF24
    /* AFEFC 001AFEFC 00000000 */   nop
    /* AFF00 001AFF00 640A848C */  lw         $4, 0xA64($4)
    /* AFF04 001AFF04 0800053C */  lui        $5, (0x80000 >> 16)
    /* AFF08 001AFF08 A0C9080C */  jal        func_00232680
    /* AFF0C 001AFF0C 00000000 */   nop
    /* AFF10 001AFF10 3000428E */  lw         $2, 0x30($18)
    /* AFF14 001AFF14 640A448C */  lw         $4, 0xA64($2)
    /* AFF18 001AFF18 2D280000 */  daddu      $5, $0, $0
    /* AFF1C 001AFF1C C8C7080C */  jal        func_00231f20
    /* AFF20 001AFF20 00000000 */   nop
  .L001AFF24:
    /* AFF24 001AFF24 184C060C */  jal        func_00193060
    /* AFF28 001AFF28 00000000 */   nop
    /* AFF2C 001AFF2C 05004010 */  beqz       $2, .L001AFF44
    /* AFF30 001AFF30 00000000 */   nop
    /* AFF34 001AFF34 ACB3838F */  lw         $3, -0x4C54($28)
    /* AFF38 001AFF38 0C00628C */  lw         $2, 0xC($3)
    /* AFF3C 001AFF3C 80004234 */  ori        $2, $2, 0x80
    /* AFF40 001AFF40 0C0062AC */  sw         $2, 0xC($3)
  .L001AFF44:
    /* AFF44 001AFF44 2D204002 */  daddu      $4, $18, $0
    /* AFF48 001AFF48 24000524 */  addiu      $5, $0, 0x24
    /* AFF4C 001AFF4C 00C2060C */  jal        func_001b0800
    /* AFF50 001AFF50 00000000 */   nop
    /* AFF54 001AFF54 2A000010 */  b          .L001B0000
    /* AFF58 001AFF58 00000000 */   nop
  .L001AFF5C:
    /* AFF5C 001AFF5C 18004296 */  lhu        $2, 0x18($18)
    /* AFF60 001AFF60 20004230 */  andi       $2, $2, 0x20
    /* AFF64 001AFF64 18004010 */  beqz       $2, .L001AFFC8
    /* AFF68 001AFF68 00000000 */   nop
    /* AFF6C 001AFF6C 2D204002 */  daddu      $4, $18, $0
    /* AFF70 001AFF70 74C3060C */  jal        func_001b0dd0
    /* AFF74 001AFF74 00000000 */   nop
    /* AFF78 001AFF78 3000448E */  lw         $4, 0x30($18)
    /* AFF7C 001AFF7C A2008390 */  lbu        $3, 0xA2($4)
    /* AFF80 001AFF80 01000224 */  addiu      $2, $0, 0x1
    /* AFF84 001AFF84 0A006214 */  bne        $3, $2, .L001AFFB0
    /* AFF88 001AFF88 00000000 */   nop
    /* AFF8C 001AFF8C 640A848C */  lw         $4, 0xA64($4)
    /* AFF90 001AFF90 0800053C */  lui        $5, (0x80000 >> 16)
    /* AFF94 001AFF94 A0C9080C */  jal        func_00232680
    /* AFF98 001AFF98 00000000 */   nop
    /* AFF9C 001AFF9C 3000428E */  lw         $2, 0x30($18)
    /* AFFA0 001AFFA0 640A448C */  lw         $4, 0xA64($2)
    /* AFFA4 001AFFA4 2D280000 */  daddu      $5, $0, $0
    /* AFFA8 001AFFA8 C8C7080C */  jal        func_00231f20
    /* AFFAC 001AFFAC 00000000 */   nop
  .L001AFFB0:
    /* AFFB0 001AFFB0 2D204002 */  daddu      $4, $18, $0
    /* AFFB4 001AFFB4 24000524 */  addiu      $5, $0, 0x24
    /* AFFB8 001AFFB8 00C2060C */  jal        func_001b0800
    /* AFFBC 001AFFBC 00000000 */   nop
    /* AFFC0 001AFFC0 0F000010 */  b          .L001B0000
    /* AFFC4 001AFFC4 00000000 */   nop
  .L001AFFC8:
    /* AFFC8 001AFFC8 3000428E */  lw         $2, 0x30($18)
    /* AFFCC 001AFFCC 640A448C */  lw         $4, 0xA64($2)
    /* AFFD0 001AFFD0 2D280000 */  daddu      $5, $0, $0
    /* AFFD4 001AFFD4 3C0A090C */  jal        func_002428f0
    /* AFFD8 001AFFD8 00000000 */   nop
    /* AFFDC 001AFFDC 08004010 */  beqz       $2, .L001B0000
    /* AFFE0 001AFFE0 00000000 */   nop
    /* AFFE4 001AFFE4 2D204002 */  daddu      $4, $18, $0
    /* AFFE8 001AFFE8 30CB070C */  jal        func_001f2cc0
    /* AFFEC 001AFFEC 00000000 */   nop
    /* AFFF0 001AFFF0 2D204002 */  daddu      $4, $18, $0
    /* AFFF4 001AFFF4 01000524 */  addiu      $5, $0, 0x1
    /* AFFF8 001AFFF8 00C2060C */  jal        func_001b0800
    /* AFFFC 001AFFFC 00000000 */   nop
  .L001B0000:
    /* B0000 001B0000 3000BFDF */  ld         $31, 0x30($29)
    /* B0004 001B0004 2000B27B */  lq         $18, 0x20($29)
    /* B0008 001B0008 1000B17B */  lq         $17, 0x10($29)
    /* B000C 001B000C 0000B07B */  lq         $16, 0x0($29)
    /* B0010 001B0010 4000BD27 */  addiu      $29, $29, 0x40
    /* B0014 001B0014 0800E003 */  jr         $31
    /* B0018 001B0018 00000000 */   nop
    /* B001C 001B001C 00000000 */  nop
.size func_001afb50, 0x4d0
