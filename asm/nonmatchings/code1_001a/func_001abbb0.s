.section .text
.set noat
.set noreorder
glabel func_001abbb0
    /* ABBB0 001ABBB0 90FEBD27 */  addiu      $29, $29, -0x170
    /* ABBB4 001ABBB4 9000BFFF */  sd         $31, 0x90($29)
    /* ABBB8 001ABBB8 8000BE7F */  sq         $30, 0x80($29)
    /* ABBBC 001ABBBC 7000B77F */  sq         $23, 0x70($29)
    /* ABBC0 001ABBC0 6000B67F */  sq         $22, 0x60($29)
    /* ABBC4 001ABBC4 5000B57F */  sq         $21, 0x50($29)
    /* ABBC8 001ABBC8 4000B47F */  sq         $20, 0x40($29)
    /* ABBCC 001ABBCC 3000B37F */  sq         $19, 0x30($29)
    /* ABBD0 001ABBD0 2000B27F */  sq         $18, 0x20($29)
    /* ABBD4 001ABBD4 1000B17F */  sq         $17, 0x10($29)
    /* ABBD8 001ABBD8 0000B07F */  sq         $16, 0x0($29)
    /* ABBDC 001ABBDC 2DA08000 */  daddu      $20, $4, $0
    /* ABBE0 001ABBE0 6E009584 */  lh         $21, 0x6E($4)
    /* ABBE4 001ABBE4 000090DC */  ld         $16, 0x0($4)
    /* ABBE8 001ABBE8 EC80060C */  jal        func_001a03b0
    /* ABBEC 001ABBEC 00000000 */   nop
    /* ABBF0 001ABBF0 01000424 */  addiu      $4, $0, 0x1
    /* ABBF4 001ABBF4 544F070C */  jal        func_001d3d50
    /* ABBF8 001ABBF8 00000000 */   nop
    /* ABBFC 001ABBFC 2DB84000 */  daddu      $23, $2, $0
    /* ABC00 001ABC00 FFFFB232 */  andi       $18, $21, 0xFFFF
    /* ABC04 001ABC04 3000848E */  lw         $4, 0x30($20)
    /* ABC08 001ABC08 2D284002 */  daddu      $5, $18, $0
    /* ABC0C 001ABC0C 0408080C */  jal        func_00202010
    /* ABC10 001ABC10 00000000 */   nop
    /* ABC14 001ABC14 2D204000 */  daddu      $4, $2, $0
    /* ABC18 001ABC18 600050FC */  sd         $16, 0x60($2)
    /* ABC1C 001ABC1C 03000524 */  addiu      $5, $0, 0x3
    /* ABC20 001ABC20 6451060C */  jal        func_00194590
    /* ABC24 001ABC24 00000000 */   nop
    /* ABC28 001ABC28 2D208002 */  daddu      $4, $20, $0
    /* ABC2C 001ABC2C C8CE070C */  jal        func_001f3b20
    /* ABC30 001ABC30 00000000 */   nop
    /* ABC34 001ABC34 2D204000 */  daddu      $4, $2, $0
    /* ABC38 001ABC38 600050FC */  sd         $16, 0x60($2)
    /* ABC3C 001ABC3C 01000524 */  addiu      $5, $0, 0x1
    /* ABC40 001ABC40 6451060C */  jal        func_00194590
    /* ABC44 001ABC44 00000000 */   nop
    /* ABC48 001ABC48 2D208002 */  daddu      $4, $20, $0
    /* ABC4C 001ABC4C 2D280000 */  daddu      $5, $0, $0
    /* ABC50 001ABC50 1CCE070C */  jal        func_001f3870
    /* ABC54 001ABC54 00000000 */   nop
    /* ABC58 001ABC58 2D204000 */  daddu      $4, $2, $0
    /* ABC5C 001ABC5C 600050FC */  sd         $16, 0x60($2)
    /* ABC60 001ABC60 01000524 */  addiu      $5, $0, 0x1
    /* ABC64 001ABC64 6451060C */  jal        func_00194590
    /* ABC68 001ABC68 00000000 */   nop
    /* ABC6C 001ABC6C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* ABC70 001ABC70 00608244 */  mtc1       $2, $f12
    /* ABC74 001ABC74 3000848E */  lw         $4, 0x30($20)
    /* ABC78 001ABC78 08000524 */  addiu      $5, $0, 0x8
    /* ABC7C 001ABC7C 06000624 */  addiu      $6, $0, 0x6
    /* ABC80 001ABC80 2D380000 */  daddu      $7, $0, $0
    /* ABC84 001ABC84 B867060C */  jal        func_00199ee0
    /* ABC88 001ABC88 00000000 */   nop
    /* ABC8C 001ABC8C 2D984000 */  daddu      $19, $2, $0
    /* ABC90 001ABC90 600050FC */  sd         $16, 0x60($2)
    /* ABC94 001ABC94 2D206002 */  daddu      $4, $19, $0
    /* ABC98 001ABC98 2D280000 */  daddu      $5, $0, $0
    /* ABC9C 001ABC9C 6451060C */  jal        func_00194590
    /* ABCA0 001ABCA0 00000000 */   nop
    /* ABCA4 001ABCA4 2D208002 */  daddu      $4, $20, $0
    /* ABCA8 001ABCA8 15000524 */  addiu      $5, $0, 0x15
    /* ABCAC 001ABCAC 48F2060C */  jal        func_001bc920
    /* ABCB0 001ABCB0 00000000 */   nop
    /* ABCB4 001ABCB4 2D204000 */  daddu      $4, $2, $0
    /* ABCB8 001ABCB8 04000324 */  addiu      $3, $0, 0x4
    /* ABCBC 001ABCBC 000043A0 */  sb         $3, 0x0($2)
    /* ABCC0 001ABCC0 580063DE */  ld         $3, 0x58($19)
    /* ABCC4 001ABCC4 080043FC */  sd         $3, 0x8($2)
    /* ABCC8 001ABCC8 600050FC */  sd         $16, 0x60($2)
    /* ABCCC 001ABCCC 2D280000 */  daddu      $5, $0, $0
    /* ABCD0 001ABCD0 6451060C */  jal        func_00194590
    /* ABCD4 001ABCD4 00000000 */   nop
    /* ABCD8 001ABCD8 580071DE */  ld         $17, 0x58($19)
    /* ABCDC 001ABCDC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* ABCE0 001ABCE0 00608244 */  mtc1       $2, $f12
    /* ABCE4 001ABCE4 3000848E */  lw         $4, 0x30($20)
    /* ABCE8 001ABCE8 08000524 */  addiu      $5, $0, 0x8
    /* ABCEC 001ABCEC 7064060C */  jal        func_001991c0
    /* ABCF0 001ABCF0 00000000 */   nop
    /* ABCF4 001ABCF4 3CF40200 */  dsll32     $30, $2, 16
    /* ABCF8 001ABCF8 3FF41E00 */  dsra32     $30, $30, 16
    /* ABCFC 001ABCFC 2D204002 */  daddu      $4, $18, $0
    /* ABD00 001ABD00 6C01A527 */  addiu      $5, $29, 0x16C
    /* ABD04 001ABD04 6801A627 */  addiu      $6, $29, 0x168
    /* ABD08 001ABD08 18DC060C */  jal        func_001b7060
    /* ABD0C 001ABD0C 00000000 */   nop
    /* ABD10 001ABD10 6C01A48F */  lw         $4, 0x16C($29)
    /* ABD14 001ABD14 6801A58F */  lw         $5, 0x168($29)
    /* ABD18 001ABD18 10000624 */  addiu      $6, $0, 0x10
    /* ABD1C 001ABD1C 20DE060C */  jal        func_001b7880
    /* ABD20 001ABD20 00000000 */   nop
    /* ABD24 001ABD24 2D204000 */  daddu      $4, $2, $0
    /* ABD28 001ABD28 04000324 */  addiu      $3, $0, 0x4
    /* ABD2C 001ABD2C 000043A0 */  sb         $3, 0x0($2)
    /* ABD30 001ABD30 080051FC */  sd         $17, 0x8($2)
    /* ABD34 001ABD34 600050FC */  sd         $16, 0x60($2)
    /* ABD38 001ABD38 01000524 */  addiu      $5, $0, 0x1
    /* ABD3C 001ABD3C 6451060C */  jal        func_00194590
    /* ABD40 001ABD40 00000000 */   nop
    /* ABD44 001ABD44 2D204002 */  daddu      $4, $18, $0
    /* ABD48 001ABD48 20DC060C */  jal        func_001b7080
    /* ABD4C 001ABD4C 00000000 */   nop
    /* ABD50 001ABD50 2DB04000 */  daddu      $22, $2, $0
    /* ABD54 001ABD54 2D204002 */  daddu      $4, $18, $0
    /* ABD58 001ABD58 6C01A527 */  addiu      $5, $29, 0x16C
    /* ABD5C 001ABD5C 6801A627 */  addiu      $6, $29, 0x168
    /* ABD60 001ABD60 28DC060C */  jal        func_001b70a0
    /* ABD64 001ABD64 00000000 */   nop
    /* ABD68 001ABD68 2D20C002 */  daddu      $4, $22, $0
    /* ABD6C 001ABD6C 6C01A58F */  lw         $5, 0x16C($29)
    /* ABD70 001ABD70 6801A68F */  lw         $6, 0x168($29)
    /* ABD74 001ABD74 10000724 */  addiu      $7, $0, 0x10
    /* ABD78 001ABD78 2D400000 */  daddu      $8, $0, $0
    /* ABD7C 001ABD7C FCE0060C */  jal        func_001b83f0
    /* ABD80 001ABD80 00000000 */   nop
    /* ABD84 001ABD84 2D204000 */  daddu      $4, $2, $0
    /* ABD88 001ABD88 04000324 */  addiu      $3, $0, 0x4
    /* ABD8C 001ABD8C 000043A0 */  sb         $3, 0x0($2)
    /* ABD90 001ABD90 080051FC */  sd         $17, 0x8($2)
    /* ABD94 001ABD94 600050FC */  sd         $16, 0x60($2)
    /* ABD98 001ABD98 01000524 */  addiu      $5, $0, 0x1
    /* ABD9C 001ABD9C 6451060C */  jal        func_00194590
    /* ABDA0 001ABDA0 00000000 */   nop
    /* ABDA4 001ABDA4 2D204002 */  daddu      $4, $18, $0
    /* ABDA8 001ABDA8 24DC060C */  jal        func_001b7090
    /* ABDAC 001ABDAC 00000000 */   nop
    /* ABDB0 001ABDB0 2D204000 */  daddu      $4, $2, $0
    /* ABDB4 001ABDB4 10000524 */  addiu      $5, $0, 0x10
    /* ABDB8 001ABDB8 58E5060C */  jal        func_001b9560
    /* ABDBC 001ABDBC 00000000 */   nop
    /* ABDC0 001ABDC0 2D204000 */  daddu      $4, $2, $0
    /* ABDC4 001ABDC4 04000324 */  addiu      $3, $0, 0x4
    /* ABDC8 001ABDC8 000043A0 */  sb         $3, 0x0($2)
    /* ABDCC 001ABDCC 080051FC */  sd         $17, 0x8($2)
    /* ABDD0 001ABDD0 600050FC */  sd         $16, 0x60($2)
    /* ABDD4 001ABDD4 01000524 */  addiu      $5, $0, 0x1
    /* ABDD8 001ABDD8 6451060C */  jal        func_00194590
    /* ABDDC 001ABDDC 00000000 */   nop
    /* ABDE0 001ABDE0 2D208002 */  daddu      $4, $20, $0
    /* ABDE4 001ABDE4 2D284002 */  daddu      $5, $18, $0
    /* ABDE8 001ABDE8 10000624 */  addiu      $6, $0, 0x10
    /* ABDEC 001ABDEC 78E7060C */  jal        func_001b9de0
    /* ABDF0 001ABDF0 00000000 */   nop
    /* ABDF4 001ABDF4 2D204000 */  daddu      $4, $2, $0
    /* ABDF8 001ABDF8 04000324 */  addiu      $3, $0, 0x4
    /* ABDFC 001ABDFC 000043A0 */  sb         $3, 0x0($2)
    /* ABE00 001ABE00 080051FC */  sd         $17, 0x8($2)
    /* ABE04 001ABE04 600050FC */  sd         $16, 0x60($2)
    /* ABE08 001ABE08 01000524 */  addiu      $5, $0, 0x1
    /* ABE0C 001ABE0C 6451060C */  jal        func_00194590
    /* ABE10 001ABE10 00000000 */   nop
    /* ABE14 001ABE14 2D204002 */  daddu      $4, $18, $0
    /* ABE18 001ABE18 E000A527 */  addiu      $5, $29, 0xE0
    /* ABE1C 001ABE1C 7C5A070C */  jal        func_001d69f0
    /* ABE20 001ABE20 00000000 */   nop
    /* ABE24 001ABE24 2D20E002 */  daddu      $4, $23, $0
    /* ABE28 001ABE28 E000A527 */  addiu      $5, $29, 0xE0
    /* ABE2C 001ABE2C 2D300000 */  daddu      $6, $0, $0
    /* ABE30 001ABE30 AC57070C */  jal        func_001d5eb0
    /* ABE34 001ABE34 00000000 */   nop
    /* ABE38 001ABE38 2D884000 */  daddu      $17, $2, $0
    /* ABE3C 001ABE3C 04000324 */  addiu      $3, $0, 0x4
    /* ABE40 001ABE40 000043A0 */  sb         $3, 0x0($2)
    /* ABE44 001ABE44 080040FC */  sd         $0, 0x8($2)
    /* ABE48 001ABE48 0600C327 */  addiu      $3, $30, 0x6
    /* ABE4C 001ABE4C 480043A4 */  sh         $3, 0x48($2)
    /* ABE50 001ABE50 600050FC */  sd         $16, 0x60($2)
    /* ABE54 001ABE54 2D202002 */  daddu      $4, $17, $0
    /* ABE58 001ABE58 01000524 */  addiu      $5, $0, 0x1
    /* ABE5C 001ABE5C 6451060C */  jal        func_00194590
    /* ABE60 001ABE60 00000000 */   nop
    /* ABE64 001ABE64 2D204002 */  daddu      $4, $18, $0
    /* ABE68 001ABE68 2D280000 */  daddu      $5, $0, $0
    /* ABE6C 001ABE6C 00E0070C */  jal        func_001f8000
    /* ABE70 001ABE70 00000000 */   nop
    /* ABE74 001ABE74 2DF04000 */  daddu      $30, $2, $0
    /* ABE78 001ABE78 04000324 */  addiu      $3, $0, 0x4
    /* ABE7C 001ABE7C 000043A0 */  sb         $3, 0x0($2)
    /* ABE80 001ABE80 580023DE */  ld         $3, 0x58($17)
    /* ABE84 001ABE84 080043FC */  sd         $3, 0x8($2)
    /* ABE88 001ABE88 2D20C003 */  daddu      $4, $30, $0
    /* ABE8C 001ABE8C 01000524 */  addiu      $5, $0, 0x1
    /* ABE90 001ABE90 6451060C */  jal        func_00194590
    /* ABE94 001ABE94 00000000 */   nop
    /* ABE98 001ABE98 3000858E */  lw         $5, 0x30($20)
    /* ABE9C 001ABE9C 2D20E002 */  daddu      $4, $23, $0
    /* ABEA0 001ABEA0 2D30A000 */  daddu      $6, $5, $0
    /* ABEA4 001ABEA4 2D380000 */  daddu      $7, $0, $0
    /* ABEA8 001ABEA8 2D400000 */  daddu      $8, $0, $0
    /* ABEAC 001ABEAC 9058070C */  jal        func_001d6240
    /* ABEB0 001ABEB0 00000000 */   nop
    /* ABEB4 001ABEB4 2D904000 */  daddu      $18, $2, $0
    /* ABEB8 001ABEB8 04000424 */  addiu      $4, $0, 0x4
    /* ABEBC 001ABEBC 000044A0 */  sb         $4, 0x0($2)
    /* ABEC0 001ABEC0 580023DE */  ld         $3, 0x58($17)
    /* ABEC4 001ABEC4 080043FC */  sd         $3, 0x8($2)
    /* ABEC8 001ABEC8 100044A0 */  sb         $4, 0x10($2)
    /* ABECC 001ABECC 5800C3DF */  ld         $3, 0x58($30)
    /* ABED0 001ABED0 180043FC */  sd         $3, 0x18($2)
    /* ABED4 001ABED4 2D204002 */  daddu      $4, $18, $0
    /* ABED8 001ABED8 02000524 */  addiu      $5, $0, 0x2
    /* ABEDC 001ABEDC 6451060C */  jal        func_00194590
    /* ABEE0 001ABEE0 00000000 */   nop
    /* ABEE4 001ABEE4 2D200000 */  daddu      $4, $0, $0
    /* ABEE8 001ABEE8 50E0070C */  jal        func_001f8140
    /* ABEEC 001ABEEC 00000000 */   nop
    /* ABEF0 001ABEF0 2D204000 */  daddu      $4, $2, $0
    /* ABEF4 001ABEF4 05000324 */  addiu      $3, $0, 0x5
    /* ABEF8 001ABEF8 000043A0 */  sb         $3, 0x0($2)
    /* ABEFC 001ABEFC 580043DE */  ld         $3, 0x58($18)
    /* ABF00 001ABF00 080043FC */  sd         $3, 0x8($2)
    /* ABF04 001ABF04 01000524 */  addiu      $5, $0, 0x1
    /* ABF08 001ABF08 6451060C */  jal        func_00194590
    /* ABF0C 001ABF0C 00000000 */   nop
    /* ABF10 001ABF10 580032DE */  ld         $18, 0x58($17)
    /* ABF14 001ABF14 D852060C */  jal        func_00194b60
    /* ABF18 001ABF18 00000000 */   nop
    /* ABF1C 001ABF1C 2D884000 */  daddu      $17, $2, $0
    /* ABF20 001ABF20 04000324 */  addiu      $3, $0, 0x4
    /* ABF24 001ABF24 000043A0 */  sb         $3, 0x0($2)
    /* ABF28 001ABF28 080052FC */  sd         $18, 0x8($2)
    /* ABF2C 001ABF2C 18000324 */  addiu      $3, $0, 0x18
    /* ABF30 001ABF30 480043A4 */  sh         $3, 0x48($2)
    /* ABF34 001ABF34 600050FC */  sd         $16, 0x60($2)
    /* ABF38 001ABF38 2D202002 */  daddu      $4, $17, $0
    /* ABF3C 001ABF3C 01000524 */  addiu      $5, $0, 0x1
    /* ABF40 001ABF40 6451060C */  jal        func_00194590
    /* ABF44 001ABF44 00000000 */   nop
    /* ABF48 001ABF48 ACB3828F */  lw         $2, -0x4C54($28)
    /* ABF4C 001ABF4C 400D448C */  lw         $4, 0xD40($2)
    /* ABF50 001ABF50 3000858E */  lw         $5, 0x30($20)
    /* ABF54 001ABF54 2D300000 */  daddu      $6, $0, $0
    /* ABF58 001ABF58 580027DE */  ld         $7, 0x58($17)
    /* ABF5C 001ABF5C 00010824 */  addiu      $8, $0, 0x100
    /* ABF60 001ABF60 7459070C */  jal        func_001d65d0
    /* ABF64 001ABF64 00000000 */   nop
    /* ABF68 001ABF68 2D884000 */  daddu      $17, $2, $0
    /* ABF6C 001ABF6C 04000324 */  addiu      $3, $0, 0x4
    /* ABF70 001ABF70 000043A0 */  sb         $3, 0x0($2)
    /* ABF74 001ABF74 580063DE */  ld         $3, 0x58($19)
    /* ABF78 001ABF78 080043FC */  sd         $3, 0x8($2)
    /* ABF7C 001ABF7C 600050FC */  sd         $16, 0x60($2)
    /* ABF80 001ABF80 2D202002 */  daddu      $4, $17, $0
    /* ABF84 001ABF84 01000524 */  addiu      $5, $0, 0x1
    /* ABF88 001ABF88 6451060C */  jal        func_00194590
    /* ABF8C 001ABF8C 00000000 */   nop
    /* ABF90 001ABF90 0A000424 */  addiu      $4, $0, 0xA
    /* ABF94 001ABF94 02000524 */  addiu      $5, $0, 0x2
    /* ABF98 001ABF98 07000624 */  addiu      $6, $0, 0x7
    /* ABF9C 001ABF9C 08DF070C */  jal        func_001f7c20
    /* ABFA0 001ABFA0 00000000 */   nop
    /* ABFA4 001ABFA4 2D204000 */  daddu      $4, $2, $0
    /* ABFA8 001ABFA8 04000324 */  addiu      $3, $0, 0x4
    /* ABFAC 001ABFAC 000043A0 */  sb         $3, 0x0($2)
    /* ABFB0 001ABFB0 580063DE */  ld         $3, 0x58($19)
    /* ABFB4 001ABFB4 080043FC */  sd         $3, 0x8($2)
    /* ABFB8 001ABFB8 01000524 */  addiu      $5, $0, 0x1
    /* ABFBC 001ABFBC 6451060C */  jal        func_00194590
    /* ABFC0 001ABFC0 00000000 */   nop
    /* ABFC4 001ABFC4 D000A0AF */  sw         $0, 0xD0($29)
    /* ABFC8 001ABFC8 2DB00000 */  daddu      $22, $0, $0
    /* ABFCC 001ABFCC 3C141500 */  dsll32     $2, $21, 16
    /* ABFD0 001ABFD0 3F140200 */  dsra32     $2, $2, 16
    /* ABFD4 001ABFD4 80100200 */  sll        $2, $2, 2
    /* ABFD8 001ABFD8 C000A27F */  sq         $2, 0xC0($29)
    /* ABFDC 001ABFDC C9000010 */  b          .L001AC304
    /* ABFE0 001ABFE0 00000000 */   nop
  .L001ABFE4:
    /* ABFE4 001ABFE4 FFFFC232 */  andi       $2, $22, 0xFFFF
    /* ABFE8 001ABFE8 40100200 */  sll        $2, $2, 1
    /* ABFEC 001ABFEC 21108202 */  addu       $2, $20, $2
    /* ABFF0 001ABFF0 76005594 */  lhu        $21, 0x76($2)
    /* ABFF4 001ABFF4 C800A012 */  beqz       $21, .L001AC318
    /* ABFF8 001ABFF8 00000000 */   nop
    /* ABFFC 001ABFFC 01000424 */  addiu      $4, $0, 0x1
    /* AC000 001AC000 2D28A002 */  daddu      $5, $21, $0
    /* AC004 001AC004 2D300000 */  daddu      $6, $0, $0
    /* AC008 001AC008 7C7D060C */  jal        func_0019f5f0
    /* AC00C 001AC00C 00000000 */   nop
    /* AC010 001AC010 B000A27F */  sq         $2, 0xB0($29)
    /* AC014 001AC014 3000538C */  lw         $19, 0x30($2)
    /* AC018 001AC018 ACB3828F */  lw         $2, -0x4C54($28)
    /* AC01C 001AC01C 680C448C */  lw         $4, 0xC68($2)
    /* AC020 001AC020 2D28A002 */  daddu      $5, $21, $0
    /* AC024 001AC024 E8C5080C */  jal        func_002317a0
    /* AC028 001AC028 00000000 */   nop
    /* AC02C 001AC02C 640A62AE */  sw         $2, 0xA64($19)
    /* AC030 001AC030 FFFFA532 */  andi       $5, $21, 0xFFFF
    /* AC034 001AC034 2D206002 */  daddu      $4, $19, $0
    /* AC038 001AC038 987A060C */  jal        func_0019ea60
    /* AC03C 001AC03C 00000000 */   nop
    /* AC040 001AC040 3000828E */  lw         $2, 0x30($20)
    /* AC044 001AC044 94004284 */  lh         $2, 0x94($2)
    /* AC048 001AC048 940062A6 */  sh         $2, 0x94($19)
    /* AC04C 001AC04C 3000828E */  lw         $2, 0x30($20)
    /* AC050 001AC050 96004284 */  lh         $2, 0x96($2)
    /* AC054 001AC054 960062A6 */  sh         $2, 0x96($19)
    /* AC058 001AC058 3000828E */  lw         $2, 0x30($20)
    /* AC05C 001AC05C 040042C4 */  lwc1       $f2, 0x4($2)
    /* AC060 001AC060 080041C4 */  lwc1       $f1, 0x8($2)
    /* AC064 001AC064 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* AC068 001AC068 040062E6 */  swc1       $f2, 0x4($19)
    /* AC06C 001AC06C 080061E6 */  swc1       $f1, 0x8($19)
    /* AC070 001AC070 0C0060E6 */  swc1       $f0, 0xC($19)
    /* AC074 001AC074 D000A28F */  lw         $2, 0xD0($29)
    /* AC078 001AC078 38004014 */  bnez       $2, .L001AC15C
    /* AC07C 001AC07C 00000000 */   nop
    /* AC080 001AC080 2D200000 */  daddu      $4, $0, $0
    /* AC084 001AC084 404E070C */  jal        func_001d3900
    /* AC088 001AC088 00000000 */   nop
    /* AC08C 001AC08C 2D204000 */  daddu      $4, $2, $0
    /* AC090 001AC090 04000324 */  addiu      $3, $0, 0x4
    /* AC094 001AC094 000043A0 */  sb         $3, 0x0($2)
    /* AC098 001AC098 080052FC */  sd         $18, 0x8($2)
    /* AC09C 001AC09C 600050FC */  sd         $16, 0x60($2)
    /* AC0A0 001AC0A0 2D280000 */  daddu      $5, $0, $0
    /* AC0A4 001AC0A4 6451060C */  jal        func_00194590
    /* AC0A8 001AC0A8 00000000 */   nop
    /* AC0AC 001AC0AC 01000424 */  addiu      $4, $0, 0x1
    /* AC0B0 001AC0B0 FF0F0524 */  addiu      $5, $0, 0xFFF
    /* AC0B4 001AC0B4 C04D070C */  jal        func_001d3700
    /* AC0B8 001AC0B8 00000000 */   nop
    /* AC0BC 001AC0BC 2D204000 */  daddu      $4, $2, $0
    /* AC0C0 001AC0C0 04000324 */  addiu      $3, $0, 0x4
    /* AC0C4 001AC0C4 000043A0 */  sb         $3, 0x0($2)
    /* AC0C8 001AC0C8 080052FC */  sd         $18, 0x8($2)
    /* AC0CC 001AC0CC 600050FC */  sd         $16, 0x60($2)
    /* AC0D0 001AC0D0 2D280000 */  daddu      $5, $0, $0
    /* AC0D4 001AC0D4 6451060C */  jal        func_00194590
    /* AC0D8 001AC0D8 00000000 */   nop
    /* AC0DC 001AC0DC BCB3838F */  lw         $3, -0x4C44($28)
    /* AC0E0 001AC0E0 C000A27B */  lq         $2, 0xC0($29)
    /* AC0E4 001AC0E4 21104300 */  addu       $2, $2, $3
    /* AC0E8 001AC0E8 02004294 */  lhu        $2, 0x2($2)
    /* AC0EC 001AC0EC 40004230 */  andi       $2, $2, 0x40
    /* AC0F0 001AC0F0 18004014 */  bnez       $2, .L001AC154
    /* AC0F4 001AC0F4 00000000 */   nop
    /* AC0F8 001AC0F8 05000424 */  addiu      $4, $0, 0x5
    /* AC0FC 001AC0FC 845E070C */  jal        func_001d7a10
    /* AC100 001AC100 00000000 */   nop
    /* AC104 001AC104 2D204000 */  daddu      $4, $2, $0
    /* AC108 001AC108 04000324 */  addiu      $3, $0, 0x4
    /* AC10C 001AC10C 000043A0 */  sb         $3, 0x0($2)
    /* AC110 001AC110 080052FC */  sd         $18, 0x8($2)
    /* AC114 001AC114 600050FC */  sd         $16, 0x60($2)
    /* AC118 001AC118 2D280000 */  daddu      $5, $0, $0
    /* AC11C 001AC11C 6451060C */  jal        func_00194590
    /* AC120 001AC120 00000000 */   nop
    /* AC124 001AC124 2D208002 */  daddu      $4, $20, $0
    /* AC128 001AC128 2D000524 */  addiu      $5, $0, 0x2D
    /* AC12C 001AC12C 48F2060C */  jal        func_001bc920
    /* AC130 001AC130 00000000 */   nop
    /* AC134 001AC134 2D204000 */  daddu      $4, $2, $0
    /* AC138 001AC138 04000324 */  addiu      $3, $0, 0x4
    /* AC13C 001AC13C 000043A0 */  sb         $3, 0x0($2)
    /* AC140 001AC140 080052FC */  sd         $18, 0x8($2)
    /* AC144 001AC144 600050FC */  sd         $16, 0x60($2)
    /* AC148 001AC148 2D280000 */  daddu      $5, $0, $0
    /* AC14C 001AC14C 6451060C */  jal        func_00194590
    /* AC150 001AC150 00000000 */   nop
  .L001AC154:
    /* AC154 001AC154 01000224 */  addiu      $2, $0, 0x1
    /* AC158 001AC158 D000A2AF */  sw         $2, 0xD0($29)
  .L001AC15C:
    /* AC15C 001AC15C 2D206002 */  daddu      $4, $19, $0
    /* AC160 001AC160 2D28A002 */  daddu      $5, $21, $0
    /* AC164 001AC164 7E000624 */  addiu      $6, $0, 0x7E
    /* AC168 001AC168 546D060C */  jal        func_0019b550
    /* AC16C 001AC16C 00000000 */   nop
    /* AC170 001AC170 2D884000 */  daddu      $17, $2, $0
    /* AC174 001AC174 04000324 */  addiu      $3, $0, 0x4
    /* AC178 001AC178 000043A0 */  sb         $3, 0x0($2)
    /* AC17C 001AC17C 080052FC */  sd         $18, 0x8($2)
    /* AC180 001AC180 600050FC */  sd         $16, 0x60($2)
    /* AC184 001AC184 2D202002 */  daddu      $4, $17, $0
    /* AC188 001AC188 01000524 */  addiu      $5, $0, 0x1
    /* AC18C 001AC18C 6451060C */  jal        func_00194590
    /* AC190 001AC190 00000000 */   nop
    /* AC194 001AC194 2D206002 */  daddu      $4, $19, $0
    /* AC198 001AC198 2D28A002 */  daddu      $5, $21, $0
    /* AC19C 001AC19C 10000624 */  addiu      $6, $0, 0x10
    /* AC1A0 001AC1A0 0C70060C */  jal        func_0019c030
    /* AC1A4 001AC1A4 00000000 */   nop
    /* AC1A8 001AC1A8 2D904000 */  daddu      $18, $2, $0
    /* AC1AC 001AC1AC 04000324 */  addiu      $3, $0, 0x4
    /* AC1B0 001AC1B0 000043A0 */  sb         $3, 0x0($2)
    /* AC1B4 001AC1B4 580023DE */  ld         $3, 0x58($17)
    /* AC1B8 001AC1B8 080043FC */  sd         $3, 0x8($2)
    /* AC1BC 001AC1BC 2D204002 */  daddu      $4, $18, $0
    /* AC1C0 001AC1C0 01000524 */  addiu      $5, $0, 0x1
    /* AC1C4 001AC1C4 6451060C */  jal        func_00194590
    /* AC1C8 001AC1C8 00000000 */   nop
    /* AC1CC 001AC1CC 2D20E002 */  daddu      $4, $23, $0
    /* AC1D0 001AC1D0 3000858E */  lw         $5, 0x30($20)
    /* AC1D4 001AC1D4 B000A27B */  lq         $2, 0xB0($29)
    /* AC1D8 001AC1D8 3000468C */  lw         $6, 0x30($2)
    /* AC1DC 001AC1DC 01000724 */  addiu      $7, $0, 0x1
    /* AC1E0 001AC1E0 00010824 */  addiu      $8, $0, 0x100
    /* AC1E4 001AC1E4 9058070C */  jal        func_001d6240
    /* AC1E8 001AC1E8 00000000 */   nop
    /* AC1EC 001AC1EC 2D884000 */  daddu      $17, $2, $0
    /* AC1F0 001AC1F0 04000424 */  addiu      $4, $0, 0x4
    /* AC1F4 001AC1F4 000044A0 */  sb         $4, 0x0($2)
    /* AC1F8 001AC1F8 580043DE */  ld         $3, 0x58($18)
    /* AC1FC 001AC1FC 080043FC */  sd         $3, 0x8($2)
    /* AC200 001AC200 100044A0 */  sb         $4, 0x10($2)
    /* AC204 001AC204 5800C3DF */  ld         $3, 0x58($30)
    /* AC208 001AC208 180043FC */  sd         $3, 0x18($2)
    /* AC20C 001AC20C 600050FC */  sd         $16, 0x60($2)
    /* AC210 001AC210 2D202002 */  daddu      $4, $17, $0
    /* AC214 001AC214 02000524 */  addiu      $5, $0, 0x2
    /* AC218 001AC218 6451060C */  jal        func_00194590
    /* AC21C 001AC21C 00000000 */   nop
    /* AC220 001AC220 01000424 */  addiu      $4, $0, 0x1
    /* AC224 001AC224 50E0070C */  jal        func_001f8140
    /* AC228 001AC228 00000000 */   nop
    /* AC22C 001AC22C 2D204000 */  daddu      $4, $2, $0
    /* AC230 001AC230 05000324 */  addiu      $3, $0, 0x5
    /* AC234 001AC234 000043A0 */  sb         $3, 0x0($2)
    /* AC238 001AC238 580023DE */  ld         $3, 0x58($17)
    /* AC23C 001AC23C 080043FC */  sd         $3, 0x8($2)
    /* AC240 001AC240 01000524 */  addiu      $5, $0, 0x1
    /* AC244 001AC244 6451060C */  jal        func_00194590
    /* AC248 001AC248 00000000 */   nop
    /* AC24C 001AC24C A000A27B */  lq         $2, 0xA0($29)
    /* AC250 001AC250 13004014 */  bnez       $2, .L001AC2A0
    /* AC254 001AC254 00000000 */   nop
    /* AC258 001AC258 78008296 */  lhu        $2, 0x78($20)
    /* AC25C 001AC25C 10004014 */  bnez       $2, .L001AC2A0
    /* AC260 001AC260 00000000 */   nop
    /* AC264 001AC264 B000A27B */  lq         $2, 0xB0($29)
    /* AC268 001AC268 3000448C */  lw         $4, 0x30($2)
    /* AC26C 001AC26C 9F000524 */  addiu      $5, $0, 0x9F
    /* AC270 001AC270 0009080C */  jal        func_00202400
    /* AC274 001AC274 00000000 */   nop
    /* AC278 001AC278 2D204000 */  daddu      $4, $2, $0
    /* AC27C 001AC27C 05000324 */  addiu      $3, $0, 0x5
    /* AC280 001AC280 000043A0 */  sb         $3, 0x0($2)
    /* AC284 001AC284 580023DE */  ld         $3, 0x58($17)
    /* AC288 001AC288 080043FC */  sd         $3, 0x8($2)
    /* AC28C 001AC28C 1C000324 */  addiu      $3, $0, 0x1C
    /* AC290 001AC290 480043A4 */  sh         $3, 0x48($2)
    /* AC294 001AC294 03000524 */  addiu      $5, $0, 0x3
    /* AC298 001AC298 6451060C */  jal        func_00194590
    /* AC29C 001AC29C 00000000 */   nop
  .L001AC2A0:
    /* AC2A0 001AC2A0 2D206002 */  daddu      $4, $19, $0
    /* AC2A4 001AC2A4 FFFF0524 */  addiu      $5, $0, -0x1
    /* AC2A8 001AC2A8 0C000624 */  addiu      $6, $0, 0xC
    /* AC2AC 001AC2AC 2D380000 */  daddu      $7, $0, $0
    /* AC2B0 001AC2B0 03000824 */  addiu      $8, $0, 0x3
    /* AC2B4 001AC2B4 01000924 */  addiu      $9, $0, 0x1
    /* AC2B8 001AC2B8 F86E060C */  jal        func_0019bbe0
    /* AC2BC 001AC2BC 00000000 */   nop
    /* AC2C0 001AC2C0 2D204000 */  daddu      $4, $2, $0
    /* AC2C4 001AC2C4 04000324 */  addiu      $3, $0, 0x4
    /* AC2C8 001AC2C8 000043A0 */  sb         $3, 0x0($2)
    /* AC2CC 001AC2CC 580043DE */  ld         $3, 0x58($18)
    /* AC2D0 001AC2D0 080043FC */  sd         $3, 0x8($2)
    /* AC2D4 001AC2D4 0B000324 */  addiu      $3, $0, 0xB
    /* AC2D8 001AC2D8 100043A0 */  sb         $3, 0x10($2)
    /* AC2DC 001AC2DC 580023DE */  ld         $3, 0x58($17)
    /* AC2E0 001AC2E0 180043FC */  sd         $3, 0x18($2)
    /* AC2E4 001AC2E4 01000524 */  addiu      $5, $0, 0x1
    /* AC2E8 001AC2E8 480045A4 */  sh         $5, 0x48($2)
    /* AC2EC 001AC2EC 600050FC */  sd         $16, 0x60($2)
    /* AC2F0 001AC2F0 6451060C */  jal        func_00194590
    /* AC2F4 001AC2F4 00000000 */   nop
    /* AC2F8 001AC2F8 580052DE */  ld         $18, 0x58($18)
    /* AC2FC 001AC2FC 0100C226 */  addiu      $2, $22, 0x1
    /* AC300 001AC300 FFFF5630 */  andi       $22, $2, 0xFFFF
  .L001AC304:
    /* AC304 001AC304 FFFFC232 */  andi       $2, $22, 0xFFFF
    /* AC308 001AC308 A000A27F */  sq         $2, 0xA0($29)
    /* AC30C 001AC30C 03004228 */  slti       $2, $2, 0x3
    /* AC310 001AC310 34FF4014 */  bnez       $2, .L001ABFE4
    /* AC314 001AC314 00000000 */   nop
  .L001AC318:
    /* AC318 001AC318 2D208002 */  daddu      $4, $20, $0
    /* AC31C 001AC31C 09000524 */  addiu      $5, $0, 0x9
    /* AC320 001AC320 2D300000 */  daddu      $6, $0, $0
    /* AC324 001AC324 2D380000 */  daddu      $7, $0, $0
    /* AC328 001AC328 2D400000 */  daddu      $8, $0, $0
    /* AC32C 001AC32C DCD7070C */  jal        func_001f5f70
    /* AC330 001AC330 00000000 */   nop
    /* AC334 001AC334 2D204000 */  daddu      $4, $2, $0
    /* AC338 001AC338 0B000324 */  addiu      $3, $0, 0xB
    /* AC33C 001AC33C 000043A0 */  sb         $3, 0x0($2)
    /* AC340 001AC340 580023DE */  ld         $3, 0x58($17)
    /* AC344 001AC344 080043FC */  sd         $3, 0x8($2)
    /* AC348 001AC348 01000524 */  addiu      $5, $0, 0x1
    /* AC34C 001AC34C 6451060C */  jal        func_00194590
    /* AC350 001AC350 00000000 */   nop
    /* AC354 001AC354 10000424 */  addiu      $4, $0, 0x10
    /* AC358 001AC358 88DF060C */  jal        func_001b7e20
    /* AC35C 001AC35C 00000000 */   nop
    /* AC360 001AC360 2D204000 */  daddu      $4, $2, $0
    /* AC364 001AC364 04000324 */  addiu      $3, $0, 0x4
    /* AC368 001AC368 000043A0 */  sb         $3, 0x0($2)
    /* AC36C 001AC36C 580023DE */  ld         $3, 0x58($17)
    /* AC370 001AC370 080043FC */  sd         $3, 0x8($2)
    /* AC374 001AC374 47004390 */  lbu        $3, 0x47($2)
    /* AC378 001AC378 DF006330 */  andi       $3, $3, 0xDF
    /* AC37C 001AC37C 470043A0 */  sb         $3, 0x47($2)
    /* AC380 001AC380 600050FC */  sd         $16, 0x60($2)
    /* AC384 001AC384 01000524 */  addiu      $5, $0, 0x1
    /* AC388 001AC388 6451060C */  jal        func_00194590
    /* AC38C 001AC38C 00000000 */   nop
    /* AC390 001AC390 10000424 */  addiu      $4, $0, 0x10
    /* AC394 001AC394 2D280000 */  daddu      $5, $0, $0
    /* AC398 001AC398 D8E4060C */  jal        func_001b9360
    /* AC39C 001AC39C 00000000 */   nop
    /* AC3A0 001AC3A0 2D204000 */  daddu      $4, $2, $0
    /* AC3A4 001AC3A4 04000324 */  addiu      $3, $0, 0x4
    /* AC3A8 001AC3A8 000043A0 */  sb         $3, 0x0($2)
    /* AC3AC 001AC3AC 580023DE */  ld         $3, 0x58($17)
    /* AC3B0 001AC3B0 080043FC */  sd         $3, 0x8($2)
    /* AC3B4 001AC3B4 47004390 */  lbu        $3, 0x47($2)
    /* AC3B8 001AC3B8 DF006330 */  andi       $3, $3, 0xDF
    /* AC3BC 001AC3BC 470043A0 */  sb         $3, 0x47($2)
    /* AC3C0 001AC3C0 600050FC */  sd         $16, 0x60($2)
    /* AC3C4 001AC3C4 01000524 */  addiu      $5, $0, 0x1
    /* AC3C8 001AC3C8 6451060C */  jal        func_00194590
    /* AC3CC 001AC3CC 00000000 */   nop
    /* AC3D0 001AC3D0 10000424 */  addiu      $4, $0, 0x10
    /* AC3D4 001AC3D4 68E6060C */  jal        func_001b99a0
    /* AC3D8 001AC3D8 00000000 */   nop
    /* AC3DC 001AC3DC 2D204000 */  daddu      $4, $2, $0
    /* AC3E0 001AC3E0 04000324 */  addiu      $3, $0, 0x4
    /* AC3E4 001AC3E4 000043A0 */  sb         $3, 0x0($2)
    /* AC3E8 001AC3E8 580023DE */  ld         $3, 0x58($17)
    /* AC3EC 001AC3EC 080043FC */  sd         $3, 0x8($2)
    /* AC3F0 001AC3F0 47004390 */  lbu        $3, 0x47($2)
    /* AC3F4 001AC3F4 DF006330 */  andi       $3, $3, 0xDF
    /* AC3F8 001AC3F8 470043A0 */  sb         $3, 0x47($2)
    /* AC3FC 001AC3FC 600050FC */  sd         $16, 0x60($2)
    /* AC400 001AC400 01000524 */  addiu      $5, $0, 0x1
    /* AC404 001AC404 6451060C */  jal        func_00194590
    /* AC408 001AC408 00000000 */   nop
    /* AC40C 001AC40C 08000424 */  addiu      $4, $0, 0x8
    /* AC410 001AC410 24E8060C */  jal        func_001ba090
    /* AC414 001AC414 00000000 */   nop
    /* AC418 001AC418 2D204000 */  daddu      $4, $2, $0
    /* AC41C 001AC41C 04000324 */  addiu      $3, $0, 0x4
    /* AC420 001AC420 000043A0 */  sb         $3, 0x0($2)
    /* AC424 001AC424 580023DE */  ld         $3, 0x58($17)
    /* AC428 001AC428 080043FC */  sd         $3, 0x8($2)
    /* AC42C 001AC42C 47004390 */  lbu        $3, 0x47($2)
    /* AC430 001AC430 DF006330 */  andi       $3, $3, 0xDF
    /* AC434 001AC434 470043A0 */  sb         $3, 0x47($2)
    /* AC438 001AC438 600050FC */  sd         $16, 0x60($2)
    /* AC43C 001AC43C 2D280000 */  daddu      $5, $0, $0
    /* AC440 001AC440 6451060C */  jal        func_00194590
    /* AC444 001AC444 00000000 */   nop
    /* AC448 001AC448 2D20E002 */  daddu      $4, $23, $0
    /* AC44C 001AC44C 804F070C */  jal        func_001d3e00
    /* AC450 001AC450 00000000 */   nop
    /* AC454 001AC454 2D208002 */  daddu      $4, $20, $0
    /* AC458 001AC458 38DA070C */  jal        func_001f68e0
    /* AC45C 001AC45C 00000000 */   nop
    /* AC460 001AC460 07004010 */  beqz       $2, .L001AC480
    /* AC464 001AC464 00000000 */   nop
    /* AC468 001AC468 2D208002 */  daddu      $4, $20, $0
    /* AC46C 001AC46C 1B000524 */  addiu      $5, $0, 0x1B
    /* AC470 001AC470 00C2060C */  jal        func_001b0800
    /* AC474 001AC474 00000000 */   nop
    /* AC478 001AC478 14000010 */  b          .L001AC4CC
    /* AC47C 001AC47C 00000000 */   nop
  .L001AC480:
    /* AC480 001AC480 6C008396 */  lhu        $3, 0x6C($20)
    /* AC484 001AC484 02000224 */  addiu      $2, $0, 0x2
    /* AC488 001AC488 09006210 */  beq        $3, $2, .L001AC4B0
    /* AC48C 001AC48C 00000000 */   nop
    /* AC490 001AC490 03000224 */  addiu      $2, $0, 0x3
    /* AC494 001AC494 06006210 */  beq        $3, $2, .L001AC4B0
    /* AC498 001AC498 00000000 */   nop
    /* AC49C 001AC49C 01000224 */  addiu      $2, $0, 0x1
    /* AC4A0 001AC4A0 03006210 */  beq        $3, $2, .L001AC4B0
    /* AC4A4 001AC4A4 00000000 */   nop
    /* AC4A8 001AC4A8 04000010 */  b          .L001AC4BC
    /* AC4AC 001AC4AC 00000000 */   nop
  .L001AC4B0:
    /* AC4B0 001AC4B0 20000564 */  daddiu     $5, $0, 0x20
    /* AC4B4 001AC4B4 02000010 */  b          .L001AC4C0
    /* AC4B8 001AC4B8 00000000 */   nop
  .L001AC4BC:
    /* AC4BC 001AC4BC 20000564 */  daddiu     $5, $0, 0x20
  .L001AC4C0:
    /* AC4C0 001AC4C0 2D208002 */  daddu      $4, $20, $0
    /* AC4C4 001AC4C4 00C2060C */  jal        func_001b0800
    /* AC4C8 001AC4C8 00000000 */   nop
  .L001AC4CC:
    /* AC4CC 001AC4CC 9000BFDF */  ld         $31, 0x90($29)
    /* AC4D0 001AC4D0 8000BE7B */  lq         $30, 0x80($29)
    /* AC4D4 001AC4D4 7000B77B */  lq         $23, 0x70($29)
    /* AC4D8 001AC4D8 6000B67B */  lq         $22, 0x60($29)
    /* AC4DC 001AC4DC 5000B57B */  lq         $21, 0x50($29)
    /* AC4E0 001AC4E0 4000B47B */  lq         $20, 0x40($29)
    /* AC4E4 001AC4E4 3000B37B */  lq         $19, 0x30($29)
    /* AC4E8 001AC4E8 2000B27B */  lq         $18, 0x20($29)
    /* AC4EC 001AC4EC 1000B17B */  lq         $17, 0x10($29)
    /* AC4F0 001AC4F0 0000B07B */  lq         $16, 0x0($29)
    /* AC4F4 001AC4F4 7001BD27 */  addiu      $29, $29, 0x170
    /* AC4F8 001AC4F8 0800E003 */  jr         $31
    /* AC4FC 001AC4FC 00000000 */   nop
.size func_001abbb0, 0x950
