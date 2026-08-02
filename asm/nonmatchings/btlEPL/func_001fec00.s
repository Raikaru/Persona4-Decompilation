.section .text
.set noat
.set noreorder
glabel func_001fec00
    /* FEC00 001FEC00 60FFBD27 */  addiu      $29, $29, -0xA0
    /* FEC04 001FEC04 6000BFFF */  sd         $31, 0x60($29)
    /* FEC08 001FEC08 5000B47F */  sq         $20, 0x50($29)
    /* FEC0C 001FEC0C 4000B37F */  sq         $19, 0x40($29)
    /* FEC10 001FEC10 3000B27F */  sq         $18, 0x30($29)
    /* FEC14 001FEC14 2000B17F */  sq         $17, 0x20($29)
    /* FEC18 001FEC18 1000B07F */  sq         $16, 0x10($29)
    /* FEC1C 001FEC1C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* FEC20 001FEC20 3000938C */  lw         $19, 0x30($4)
    /* FEC24 001FEC24 3800928C */  lw         $18, 0x38($4)
    /* FEC28 001FEC28 2800918C */  lw         $17, 0x28($4)
    /* FEC2C 001FEC2C 0000508E */  lw         $16, 0x0($18)
    /* FEC30 001FEC30 2B081102 */  sltu       $1, $16, $17
    /* FEC34 001FEC34 03002010 */  beqz       $1, .L001FEC44
    /* FEC38 001FEC38 00000000 */   nop
    /* FEC3C 001FEC3C A6010016 */  bnez       $16, .L001FF2D8
    /* FEC40 001FEC40 00000000 */   nop
  .L001FEC44:
    /* FEC44 001FEC44 2DA00000 */  daddu      $20, $0, $0
    /* FEC48 001FEC48 5E000012 */  beqz       $16, .L001FEDC4
    /* FEC4C 001FEC4C 00000000 */   nop
    /* FEC50 001FEC50 04004496 */  lhu        $4, 0x4($18)
    /* FEC54 001FEC54 2B089100 */  sltu       $1, $4, $17
    /* FEC58 001FEC58 2C002014 */  bnez       $1, .L001FED0C
    /* FEC5C 001FEC5C 00000000 */   nop
    /* FEC60 001FEC60 25008018 */  blez       $4, .L001FECF8
    /* FEC64 001FEC64 00000000 */   nop
    /* FEC68 001FEC68 06002006 */  bltz       $17, .L001FEC84
    /* FEC6C 001FEC6C 00000000 */   nop
    /* FEC70 001FEC70 00009144 */  mtc1       $17, $f0
    /* FEC74 001FEC74 00000000 */  nop
    /* FEC78 001FEC78 60008046 */  cvt.s.w    $f1, $f0
    /* FEC7C 001FEC7C 08000010 */  b          .L001FECA0
    /* FEC80 001FEC80 00000000 */   nop
  .L001FEC84:
    /* FEC84 001FEC84 42181100 */  srl        $3, $17, 1
    /* FEC88 001FEC88 01002232 */  andi       $2, $17, 0x1
    /* FEC8C 001FEC8C 25186200 */  or         $3, $3, $2
    /* FEC90 001FEC90 00008344 */  mtc1       $3, $f0
    /* FEC94 001FEC94 00000000 */  nop
    /* FEC98 001FEC98 60008046 */  cvt.s.w    $f1, $f0
    /* FEC9C 001FEC9C 40080146 */  add.s      $f1, $f1, $f1
  .L001FECA0:
    /* FECA0 001FECA0 06008004 */  bltz       $4, .L001FECBC
    /* FECA4 001FECA4 00000000 */   nop
    /* FECA8 001FECA8 00008444 */  mtc1       $4, $f0
    /* FECAC 001FECAC 00000000 */  nop
    /* FECB0 001FECB0 20008046 */  cvt.s.w    $f0, $f0
    /* FECB4 001FECB4 08000010 */  b          .L001FECD8
    /* FECB8 001FECB8 00000000 */   nop
  .L001FECBC:
    /* FECBC 001FECBC 42180400 */  srl        $3, $4, 1
    /* FECC0 001FECC0 01008230 */  andi       $2, $4, 0x1
    /* FECC4 001FECC4 25186200 */  or         $3, $3, $2
    /* FECC8 001FECC8 00008344 */  mtc1       $3, $f0
    /* FECCC 001FECCC 00000000 */  nop
    /* FECD0 001FECD0 20008046 */  cvt.s.w    $f0, $f0
    /* FECD4 001FECD4 00000046 */  add.s      $f0, $f0, $f0
  .L001FECD8:
    /* FECD8 001FECD8 00000000 */  nop
    /* FECDC 001FECDC 00000000 */  nop
    /* FECE0 001FECE0 030D0046 */  div.s      $f20, $f1, $f0
    /* FECE4 001FECE4 00000000 */  nop
    /* FECE8 001FECE8 00000000 */  nop
    /* FECEC 001FECEC 00000000 */  nop
    /* FECF0 001FECF0 03000010 */  b          .L001FED00
    /* FECF4 001FECF4 00000000 */   nop
  .L001FECF8:
    /* FECF8 001FECF8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FECFC 001FECFC 00A08244 */  mtc1       $2, $f20
  .L001FED00:
    /* FED00 001FED00 01001464 */  daddiu     $20, $0, 0x1
    /* FED04 001FED04 2F000010 */  b          .L001FEDC4
    /* FED08 001FED08 00000000 */   nop
  .L001FED0C:
    /* FED0C 001FED0C 06004496 */  lhu        $4, 0x6($18)
    /* FED10 001FED10 23100402 */  subu       $2, $16, $4
    /* FED14 001FED14 2B102202 */  sltu       $2, $17, $2
    /* FED18 001FED18 2A004014 */  bnez       $2, .L001FEDC4
    /* FED1C 001FED1C 00000000 */   nop
    /* FED20 001FED20 26008018 */  blez       $4, .L001FEDBC
    /* FED24 001FED24 00000000 */   nop
    /* FED28 001FED28 23101102 */  subu       $2, $16, $17
    /* FED2C 001FED2C 06004004 */  bltz       $2, .L001FED48
    /* FED30 001FED30 00000000 */   nop
    /* FED34 001FED34 00008244 */  mtc1       $2, $f0
    /* FED38 001FED38 00000000 */  nop
    /* FED3C 001FED3C 60008046 */  cvt.s.w    $f1, $f0
    /* FED40 001FED40 08000010 */  b          .L001FED64
    /* FED44 001FED44 00000000 */   nop
  .L001FED48:
    /* FED48 001FED48 42180200 */  srl        $3, $2, 1
    /* FED4C 001FED4C 01004230 */  andi       $2, $2, 0x1
    /* FED50 001FED50 25186200 */  or         $3, $3, $2
    /* FED54 001FED54 00008344 */  mtc1       $3, $f0
    /* FED58 001FED58 00000000 */  nop
    /* FED5C 001FED5C 60008046 */  cvt.s.w    $f1, $f0
    /* FED60 001FED60 40080146 */  add.s      $f1, $f1, $f1
  .L001FED64:
    /* FED64 001FED64 06008004 */  bltz       $4, .L001FED80
    /* FED68 001FED68 00000000 */   nop
    /* FED6C 001FED6C 00008444 */  mtc1       $4, $f0
    /* FED70 001FED70 00000000 */  nop
    /* FED74 001FED74 20008046 */  cvt.s.w    $f0, $f0
    /* FED78 001FED78 08000010 */  b          .L001FED9C
    /* FED7C 001FED7C 00000000 */   nop
  .L001FED80:
    /* FED80 001FED80 42180400 */  srl        $3, $4, 1
    /* FED84 001FED84 01008230 */  andi       $2, $4, 0x1
    /* FED88 001FED88 25186200 */  or         $3, $3, $2
    /* FED8C 001FED8C 00008344 */  mtc1       $3, $f0
    /* FED90 001FED90 00000000 */  nop
    /* FED94 001FED94 20008046 */  cvt.s.w    $f0, $f0
    /* FED98 001FED98 00000046 */  add.s      $f0, $f0, $f0
  .L001FED9C:
    /* FED9C 001FED9C 00000000 */  nop
    /* FEDA0 001FEDA0 00000000 */  nop
    /* FEDA4 001FEDA4 030D0046 */  div.s      $f20, $f1, $f0
    /* FEDA8 001FEDA8 00000000 */  nop
    /* FEDAC 001FEDAC 00000000 */  nop
    /* FEDB0 001FEDB0 00000000 */  nop
    /* FEDB4 001FEDB4 02000010 */  b          .L001FEDC0
    /* FEDB8 001FEDB8 00000000 */   nop
  .L001FEDBC:
    /* FEDBC 001FEDBC 00A08044 */  mtc1       $0, $f20
  .L001FEDC0:
    /* FEDC0 001FEDC0 02001464 */  daddiu     $20, $0, 0x2
  .L001FEDC4:
    /* FEDC4 001FEDC4 14DC060C */  jal        func_001b7050
    /* FEDC8 001FEDC8 00000000 */   nop
    /* FEDCC 001FEDCC FF008432 */  andi       $4, $20, 0xFF
    /* FEDD0 001FEDD0 02000324 */  addiu      $3, $0, 0x2
    /* FEDD4 001FEDD4 CB008310 */  beq        $4, $3, .L001FF104
    /* FEDD8 001FEDD8 00000000 */   nop
    /* FEDDC 001FEDDC 01000324 */  addiu      $3, $0, 0x1
    /* FEDE0 001FEDE0 51008310 */  beq        $4, $3, .L001FEF28
    /* FEDE4 001FEDE4 00000000 */   nop
    /* FEDE8 001FEDE8 03008010 */  beqz       $4, .L001FEDF8
    /* FEDEC 001FEDEC 00000000 */   nop
    /* FEDF0 001FEDF0 39010010 */  b          .L001FF2D8
    /* FEDF4 001FEDF4 00000000 */   nop
  .L001FEDF8:
    /* FEDF8 001FEDF8 37012016 */  bnez       $17, .L001FF2D8
    /* FEDFC 001FEDFC 00000000 */   nop
    /* FEE00 001FEE00 0800438E */  lw         $3, 0x8($18)
    /* FEE04 001FEE04 9C00A3AF */  sw         $3, 0x9C($29)
    /* FEE08 001FEE08 9C00A393 */  lbu        $3, 0x9C($29)
    /* FEE0C 001FEE0C 06006004 */  bltz       $3, .L001FEE28
    /* FEE10 001FEE10 00000000 */   nop
    /* FEE14 001FEE14 00008344 */  mtc1       $3, $f0
    /* FEE18 001FEE18 00000000 */  nop
    /* FEE1C 001FEE1C 60008046 */  cvt.s.w    $f1, $f0
    /* FEE20 001FEE20 08000010 */  b          .L001FEE44
    /* FEE24 001FEE24 00000000 */   nop
  .L001FEE28:
    /* FEE28 001FEE28 42200300 */  srl        $4, $3, 1
    /* FEE2C 001FEE2C 01006330 */  andi       $3, $3, 0x1
    /* FEE30 001FEE30 25208300 */  or         $4, $4, $3
    /* FEE34 001FEE34 00008444 */  mtc1       $4, $f0
    /* FEE38 001FEE38 00000000 */  nop
    /* FEE3C 001FEE3C 60008046 */  cvt.s.w    $f1, $f0
    /* FEE40 001FEE40 40080146 */  add.s      $f1, $f1, $f1
  .L001FEE44:
    /* FEE44 001FEE44 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FEE48 001FEE48 02000146 */  mul.s      $f0, $f0, $f1
    /* FEE4C 001FEE4C 8000A0E7 */  swc1       $f0, 0x80($29)
    /* FEE50 001FEE50 9D00A393 */  lbu        $3, 0x9D($29)
    /* FEE54 001FEE54 06006004 */  bltz       $3, .L001FEE70
    /* FEE58 001FEE58 00000000 */   nop
    /* FEE5C 001FEE5C 00008344 */  mtc1       $3, $f0
    /* FEE60 001FEE60 00000000 */  nop
    /* FEE64 001FEE64 60008046 */  cvt.s.w    $f1, $f0
    /* FEE68 001FEE68 08000010 */  b          .L001FEE8C
    /* FEE6C 001FEE6C 00000000 */   nop
  .L001FEE70:
    /* FEE70 001FEE70 42200300 */  srl        $4, $3, 1
    /* FEE74 001FEE74 01006330 */  andi       $3, $3, 0x1
    /* FEE78 001FEE78 25208300 */  or         $4, $4, $3
    /* FEE7C 001FEE7C 00008444 */  mtc1       $4, $f0
    /* FEE80 001FEE80 00000000 */  nop
    /* FEE84 001FEE84 60008046 */  cvt.s.w    $f1, $f0
    /* FEE88 001FEE88 40080146 */  add.s      $f1, $f1, $f1
  .L001FEE8C:
    /* FEE8C 001FEE8C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FEE90 001FEE90 02000146 */  mul.s      $f0, $f0, $f1
    /* FEE94 001FEE94 8400A0E7 */  swc1       $f0, 0x84($29)
    /* FEE98 001FEE98 9E00A393 */  lbu        $3, 0x9E($29)
    /* FEE9C 001FEE9C 06006004 */  bltz       $3, .L001FEEB8
    /* FEEA0 001FEEA0 00000000 */   nop
    /* FEEA4 001FEEA4 00008344 */  mtc1       $3, $f0
    /* FEEA8 001FEEA8 00000000 */  nop
    /* FEEAC 001FEEAC 60008046 */  cvt.s.w    $f1, $f0
    /* FEEB0 001FEEB0 08000010 */  b          .L001FEED4
    /* FEEB4 001FEEB4 00000000 */   nop
  .L001FEEB8:
    /* FEEB8 001FEEB8 42200300 */  srl        $4, $3, 1
    /* FEEBC 001FEEBC 01006330 */  andi       $3, $3, 0x1
    /* FEEC0 001FEEC0 25208300 */  or         $4, $4, $3
    /* FEEC4 001FEEC4 00008444 */  mtc1       $4, $f0
    /* FEEC8 001FEEC8 00000000 */  nop
    /* FEECC 001FEECC 60008046 */  cvt.s.w    $f1, $f0
    /* FEED0 001FEED0 40080146 */  add.s      $f1, $f1, $f1
  .L001FEED4:
    /* FEED4 001FEED4 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FEED8 001FEED8 02000146 */  mul.s      $f0, $f0, $f1
    /* FEEDC 001FEEDC 8800A0E7 */  swc1       $f0, 0x88($29)
    /* FEEE0 001FEEE0 9F00A393 */  lbu        $3, 0x9F($29)
    /* FEEE4 001FEEE4 01006004 */  bltz       $3, .L001FEEEC
    /* FEEE8 001FEEE8 00000000 */   nop
  .L001FEEEC:
    /* FEEEC 001FEEEC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FEEF0 001FEEF0 8C00A3AF */  sw         $3, 0x8C($29)
    /* FEEF4 001FEEF4 8000A427 */  addiu      $4, $29, 0x80
    /* FEEF8 001FEEF8 8000A3C7 */  lwc1       $f3, 0x80($29)
    /* FEEFC 001FEEFC 8400A2C7 */  lwc1       $f2, 0x84($29)
    /* FEF00 001FEF00 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* FEF04 001FEF04 8C00A0C7 */  lwc1       $f0, 0x8C($29)
    /* FEF08 001FEF08 000043E4 */  swc1       $f3, 0x0($2)
    /* FEF0C 001FEF0C 040042E4 */  swc1       $f2, 0x4($2)
    /* FEF10 001FEF10 080041E4 */  swc1       $f1, 0x8($2)
    /* FEF14 001FEF14 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FEF18 001FEF18 B025050C */  jal        func_001496c0
    /* FEF1C 001FEF1C 00000000 */   nop
    /* FEF20 001FEF20 ED000010 */  b          .L001FF2D8
    /* FEF24 001FEF24 00000000 */   nop
  .L001FEF28:
    /* FEF28 001FEF28 09002016 */  bnez       $17, .L001FEF50
    /* FEF2C 001FEF2C 00000000 */   nop
    /* FEF30 001FEF30 000043C4 */  lwc1       $f3, 0x0($2)
    /* FEF34 001FEF34 040042C4 */  lwc1       $f2, 0x4($2)
    /* FEF38 001FEF38 080041C4 */  lwc1       $f1, 0x8($2)
    /* FEF3C 001FEF3C 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* FEF40 001FEF40 000063E6 */  swc1       $f3, 0x0($19)
    /* FEF44 001FEF44 040062E6 */  swc1       $f2, 0x4($19)
    /* FEF48 001FEF48 080061E6 */  swc1       $f1, 0x8($19)
    /* FEF4C 001FEF4C 0C0060E6 */  swc1       $f0, 0xC($19)
  .L001FEF50:
    /* FEF50 001FEF50 0800438E */  lw         $3, 0x8($18)
    /* FEF54 001FEF54 9C00A3AF */  sw         $3, 0x9C($29)
    /* FEF58 001FEF58 9C00A393 */  lbu        $3, 0x9C($29)
    /* FEF5C 001FEF5C 06006004 */  bltz       $3, .L001FEF78
    /* FEF60 001FEF60 00000000 */   nop
    /* FEF64 001FEF64 00008344 */  mtc1       $3, $f0
    /* FEF68 001FEF68 00000000 */  nop
    /* FEF6C 001FEF6C 60008046 */  cvt.s.w    $f1, $f0
    /* FEF70 001FEF70 08000010 */  b          .L001FEF94
    /* FEF74 001FEF74 00000000 */   nop
  .L001FEF78:
    /* FEF78 001FEF78 42200300 */  srl        $4, $3, 1
    /* FEF7C 001FEF7C 01006330 */  andi       $3, $3, 0x1
    /* FEF80 001FEF80 25208300 */  or         $4, $4, $3
    /* FEF84 001FEF84 00008444 */  mtc1       $4, $f0
    /* FEF88 001FEF88 00000000 */  nop
    /* FEF8C 001FEF8C 60008046 */  cvt.s.w    $f1, $f0
    /* FEF90 001FEF90 40080146 */  add.s      $f1, $f1, $f1
  .L001FEF94:
    /* FEF94 001FEF94 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FEF98 001FEF98 02000146 */  mul.s      $f0, $f0, $f1
    /* FEF9C 001FEF9C 8000A0E7 */  swc1       $f0, 0x80($29)
    /* FEFA0 001FEFA0 9D00A393 */  lbu        $3, 0x9D($29)
    /* FEFA4 001FEFA4 06006004 */  bltz       $3, .L001FEFC0
    /* FEFA8 001FEFA8 00000000 */   nop
    /* FEFAC 001FEFAC 00008344 */  mtc1       $3, $f0
    /* FEFB0 001FEFB0 00000000 */  nop
    /* FEFB4 001FEFB4 60008046 */  cvt.s.w    $f1, $f0
    /* FEFB8 001FEFB8 08000010 */  b          .L001FEFDC
    /* FEFBC 001FEFBC 00000000 */   nop
  .L001FEFC0:
    /* FEFC0 001FEFC0 42200300 */  srl        $4, $3, 1
    /* FEFC4 001FEFC4 01006330 */  andi       $3, $3, 0x1
    /* FEFC8 001FEFC8 25208300 */  or         $4, $4, $3
    /* FEFCC 001FEFCC 00008444 */  mtc1       $4, $f0
    /* FEFD0 001FEFD0 00000000 */  nop
    /* FEFD4 001FEFD4 60008046 */  cvt.s.w    $f1, $f0
    /* FEFD8 001FEFD8 40080146 */  add.s      $f1, $f1, $f1
  .L001FEFDC:
    /* FEFDC 001FEFDC AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FEFE0 001FEFE0 02000146 */  mul.s      $f0, $f0, $f1
    /* FEFE4 001FEFE4 8400A0E7 */  swc1       $f0, 0x84($29)
    /* FEFE8 001FEFE8 9E00A393 */  lbu        $3, 0x9E($29)
    /* FEFEC 001FEFEC 06006004 */  bltz       $3, .L001FF008
    /* FEFF0 001FEFF0 00000000 */   nop
    /* FEFF4 001FEFF4 00008344 */  mtc1       $3, $f0
    /* FEFF8 001FEFF8 00000000 */  nop
    /* FEFFC 001FEFFC 60008046 */  cvt.s.w    $f1, $f0
    /* FF000 001FF000 08000010 */  b          .L001FF024
    /* FF004 001FF004 00000000 */   nop
  .L001FF008:
    /* FF008 001FF008 42200300 */  srl        $4, $3, 1
    /* FF00C 001FF00C 01006330 */  andi       $3, $3, 0x1
    /* FF010 001FF010 25208300 */  or         $4, $4, $3
    /* FF014 001FF014 00008444 */  mtc1       $4, $f0
    /* FF018 001FF018 00000000 */  nop
    /* FF01C 001FF01C 60008046 */  cvt.s.w    $f1, $f0
    /* FF020 001FF020 40080146 */  add.s      $f1, $f1, $f1
  .L001FF024:
    /* FF024 001FF024 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF028 001FF028 02000146 */  mul.s      $f0, $f0, $f1
    /* FF02C 001FF02C 8800A0E7 */  swc1       $f0, 0x88($29)
    /* FF030 001FF030 9F00A393 */  lbu        $3, 0x9F($29)
    /* FF034 001FF034 06006004 */  bltz       $3, .L001FF050
    /* FF038 001FF038 00000000 */   nop
    /* FF03C 001FF03C 00008344 */  mtc1       $3, $f0
    /* FF040 001FF040 00000000 */  nop
    /* FF044 001FF044 60008046 */  cvt.s.w    $f1, $f0
    /* FF048 001FF048 08000010 */  b          .L001FF06C
    /* FF04C 001FF04C 00000000 */   nop
  .L001FF050:
    /* FF050 001FF050 42200300 */  srl        $4, $3, 1
    /* FF054 001FF054 01006330 */  andi       $3, $3, 0x1
    /* FF058 001FF058 25208300 */  or         $4, $4, $3
    /* FF05C 001FF05C 00008444 */  mtc1       $4, $f0
    /* FF060 001FF060 00000000 */  nop
    /* FF064 001FF064 60008046 */  cvt.s.w    $f1, $f0
    /* FF068 001FF068 40080146 */  add.s      $f1, $f1, $f1
  .L001FF06C:
    /* FF06C 001FF06C AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF070 001FF070 02000146 */  mul.s      $f0, $f0, $f1
    /* FF074 001FF074 8C00A0E7 */  swc1       $f0, 0x8C($29)
    /* FF078 001FF078 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FF07C 001FF07C 00008344 */  mtc1       $3, $f0
    /* FF080 001FF080 00000000 */  nop
    /* FF084 001FF084 41001446 */  sub.s      $f1, $f0, $f20
    /* FF088 001FF088 000060C6 */  lwc1       $f0, 0x0($19)
    /* FF08C 001FF08C 42010146 */  mul.s      $f5, $f0, $f1
    /* FF090 001FF090 040060C6 */  lwc1       $f0, 0x4($19)
    /* FF094 001FF094 02010146 */  mul.s      $f4, $f0, $f1
    /* FF098 001FF098 080060C6 */  lwc1       $f0, 0x8($19)
    /* FF09C 001FF09C 1A000146 */  mula.s     $f0, $f1
    /* FF0A0 001FF0A0 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* FF0A4 001FF0A4 C2001446 */  mul.s      $f3, $f0, $f20
    /* FF0A8 001FF0A8 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* FF0AC 001FF0AC 82001446 */  mul.s      $f2, $f0, $f20
    /* FF0B0 001FF0B0 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* FF0B4 001FF0B4 00280346 */  add.s      $f0, $f5, $f3
    /* FF0B8 001FF0B8 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FF0BC 001FF0BC 00200246 */  add.s      $f0, $f4, $f2
    /* FF0C0 001FF0C0 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FF0C4 001FF0C4 1C081446 */  madd.s     $f0, $f1, $f20
    /* FF0C8 001FF0C8 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FF0CC 001FF0CC 7C00A3AF */  sw         $3, 0x7C($29)
    /* FF0D0 001FF0D0 7000A427 */  addiu      $4, $29, 0x70
    /* FF0D4 001FF0D4 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FF0D8 001FF0D8 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FF0DC 001FF0DC 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FF0E0 001FF0E0 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FF0E4 001FF0E4 000043E4 */  swc1       $f3, 0x0($2)
    /* FF0E8 001FF0E8 040042E4 */  swc1       $f2, 0x4($2)
    /* FF0EC 001FF0EC 080041E4 */  swc1       $f1, 0x8($2)
    /* FF0F0 001FF0F0 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FF0F4 001FF0F4 B025050C */  jal        func_001496c0
    /* FF0F8 001FF0F8 00000000 */   nop
    /* FF0FC 001FF0FC 76000010 */  b          .L001FF2D8
    /* FF100 001FF100 00000000 */   nop
  .L001FF104:
    /* FF104 001FF104 06004396 */  lhu        $3, 0x6($18)
    /* FF108 001FF108 23180302 */  subu       $3, $16, $3
    /* FF10C 001FF10C 09002316 */  bne        $17, $3, .L001FF134
    /* FF110 001FF110 00000000 */   nop
    /* FF114 001FF114 000043C4 */  lwc1       $f3, 0x0($2)
    /* FF118 001FF118 040042C4 */  lwc1       $f2, 0x4($2)
    /* FF11C 001FF11C 080041C4 */  lwc1       $f1, 0x8($2)
    /* FF120 001FF120 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* FF124 001FF124 000063E6 */  swc1       $f3, 0x0($19)
    /* FF128 001FF128 040062E6 */  swc1       $f2, 0x4($19)
    /* FF12C 001FF12C 080061E6 */  swc1       $f1, 0x8($19)
    /* FF130 001FF130 0C0060E6 */  swc1       $f0, 0xC($19)
  .L001FF134:
    /* FF134 001FF134 08B18393 */  lbu        $3, -0x4EF8($28)
    /* FF138 001FF138 06006004 */  bltz       $3, .L001FF154
    /* FF13C 001FF13C 00000000 */   nop
    /* FF140 001FF140 00008344 */  mtc1       $3, $f0
    /* FF144 001FF144 00000000 */  nop
    /* FF148 001FF148 60008046 */  cvt.s.w    $f1, $f0
    /* FF14C 001FF14C 08000010 */  b          .L001FF170
    /* FF150 001FF150 00000000 */   nop
  .L001FF154:
    /* FF154 001FF154 42200300 */  srl        $4, $3, 1
    /* FF158 001FF158 01006330 */  andi       $3, $3, 0x1
    /* FF15C 001FF15C 25208300 */  or         $4, $4, $3
    /* FF160 001FF160 00008444 */  mtc1       $4, $f0
    /* FF164 001FF164 00000000 */  nop
    /* FF168 001FF168 60008046 */  cvt.s.w    $f1, $f0
    /* FF16C 001FF16C 40080146 */  add.s      $f1, $f1, $f1
  .L001FF170:
    /* FF170 001FF170 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF174 001FF174 02000146 */  mul.s      $f0, $f0, $f1
    /* FF178 001FF178 8000A0E7 */  swc1       $f0, 0x80($29)
    /* FF17C 001FF17C 09B18393 */  lbu        $3, -0x4EF7($28)
    /* FF180 001FF180 06006004 */  bltz       $3, .L001FF19C
    /* FF184 001FF184 00000000 */   nop
    /* FF188 001FF188 00008344 */  mtc1       $3, $f0
    /* FF18C 001FF18C 00000000 */  nop
    /* FF190 001FF190 60008046 */  cvt.s.w    $f1, $f0
    /* FF194 001FF194 08000010 */  b          .L001FF1B8
    /* FF198 001FF198 00000000 */   nop
  .L001FF19C:
    /* FF19C 001FF19C 42200300 */  srl        $4, $3, 1
    /* FF1A0 001FF1A0 01006330 */  andi       $3, $3, 0x1
    /* FF1A4 001FF1A4 25208300 */  or         $4, $4, $3
    /* FF1A8 001FF1A8 00008444 */  mtc1       $4, $f0
    /* FF1AC 001FF1AC 00000000 */  nop
    /* FF1B0 001FF1B0 60008046 */  cvt.s.w    $f1, $f0
    /* FF1B4 001FF1B4 40080146 */  add.s      $f1, $f1, $f1
  .L001FF1B8:
    /* FF1B8 001FF1B8 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF1BC 001FF1BC 02000146 */  mul.s      $f0, $f0, $f1
    /* FF1C0 001FF1C0 8400A0E7 */  swc1       $f0, 0x84($29)
    /* FF1C4 001FF1C4 0AB18393 */  lbu        $3, -0x4EF6($28)
    /* FF1C8 001FF1C8 06006004 */  bltz       $3, .L001FF1E4
    /* FF1CC 001FF1CC 00000000 */   nop
    /* FF1D0 001FF1D0 00008344 */  mtc1       $3, $f0
    /* FF1D4 001FF1D4 00000000 */  nop
    /* FF1D8 001FF1D8 60008046 */  cvt.s.w    $f1, $f0
    /* FF1DC 001FF1DC 08000010 */  b          .L001FF200
    /* FF1E0 001FF1E0 00000000 */   nop
  .L001FF1E4:
    /* FF1E4 001FF1E4 42200300 */  srl        $4, $3, 1
    /* FF1E8 001FF1E8 01006330 */  andi       $3, $3, 0x1
    /* FF1EC 001FF1EC 25208300 */  or         $4, $4, $3
    /* FF1F0 001FF1F0 00008444 */  mtc1       $4, $f0
    /* FF1F4 001FF1F4 00000000 */  nop
    /* FF1F8 001FF1F8 60008046 */  cvt.s.w    $f1, $f0
    /* FF1FC 001FF1FC 40080146 */  add.s      $f1, $f1, $f1
  .L001FF200:
    /* FF200 001FF200 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF204 001FF204 02000146 */  mul.s      $f0, $f0, $f1
    /* FF208 001FF208 8800A0E7 */  swc1       $f0, 0x88($29)
    /* FF20C 001FF20C 0BB18393 */  lbu        $3, -0x4EF5($28)
    /* FF210 001FF210 06006004 */  bltz       $3, .L001FF22C
    /* FF214 001FF214 00000000 */   nop
    /* FF218 001FF218 00008344 */  mtc1       $3, $f0
    /* FF21C 001FF21C 00000000 */  nop
    /* FF220 001FF220 60008046 */  cvt.s.w    $f1, $f0
    /* FF224 001FF224 08000010 */  b          .L001FF248
    /* FF228 001FF228 00000000 */   nop
  .L001FF22C:
    /* FF22C 001FF22C 42200300 */  srl        $4, $3, 1
    /* FF230 001FF230 01006330 */  andi       $3, $3, 0x1
    /* FF234 001FF234 25208300 */  or         $4, $4, $3
    /* FF238 001FF238 00008444 */  mtc1       $4, $f0
    /* FF23C 001FF23C 00000000 */  nop
    /* FF240 001FF240 60008046 */  cvt.s.w    $f1, $f0
    /* FF244 001FF244 40080146 */  add.s      $f1, $f1, $f1
  .L001FF248:
    /* FF248 001FF248 AC8180C7 */  lwc1       $f0, -0x7E54($28)
    /* FF24C 001FF24C 02000146 */  mul.s      $f0, $f0, $f1
    /* FF250 001FF250 8C00A0E7 */  swc1       $f0, 0x8C($29)
    /* FF254 001FF254 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* FF258 001FF258 00008344 */  mtc1       $3, $f0
    /* FF25C 001FF25C 00000000 */  nop
    /* FF260 001FF260 41001446 */  sub.s      $f1, $f0, $f20
    /* FF264 001FF264 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* FF268 001FF268 42010146 */  mul.s      $f5, $f0, $f1
    /* FF26C 001FF26C 8400A0C7 */  lwc1       $f0, 0x84($29)
    /* FF270 001FF270 02010146 */  mul.s      $f4, $f0, $f1
    /* FF274 001FF274 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* FF278 001FF278 1A000146 */  mula.s     $f0, $f1
    /* FF27C 001FF27C 000060C6 */  lwc1       $f0, 0x0($19)
    /* FF280 001FF280 C2001446 */  mul.s      $f3, $f0, $f20
    /* FF284 001FF284 040060C6 */  lwc1       $f0, 0x4($19)
    /* FF288 001FF288 82001446 */  mul.s      $f2, $f0, $f20
    /* FF28C 001FF28C 080061C6 */  lwc1       $f1, 0x8($19)
    /* FF290 001FF290 00280346 */  add.s      $f0, $f5, $f3
    /* FF294 001FF294 7000A0E7 */  swc1       $f0, 0x70($29)
    /* FF298 001FF298 00200246 */  add.s      $f0, $f4, $f2
    /* FF29C 001FF29C 7400A0E7 */  swc1       $f0, 0x74($29)
    /* FF2A0 001FF2A0 1C081446 */  madd.s     $f0, $f1, $f20
    /* FF2A4 001FF2A4 7800A0E7 */  swc1       $f0, 0x78($29)
    /* FF2A8 001FF2A8 7C00A3AF */  sw         $3, 0x7C($29)
    /* FF2AC 001FF2AC 7000A427 */  addiu      $4, $29, 0x70
    /* FF2B0 001FF2B0 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* FF2B4 001FF2B4 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* FF2B8 001FF2B8 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* FF2BC 001FF2BC 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* FF2C0 001FF2C0 000043E4 */  swc1       $f3, 0x0($2)
    /* FF2C4 001FF2C4 040042E4 */  swc1       $f2, 0x4($2)
    /* FF2C8 001FF2C8 080041E4 */  swc1       $f1, 0x8($2)
    /* FF2CC 001FF2CC 0C0040E4 */  swc1       $f0, 0xC($2)
    /* FF2D0 001FF2D0 B025050C */  jal        func_001496c0
    /* FF2D4 001FF2D4 00000000 */   nop
  .L001FF2D8:
    /* FF2D8 001FF2D8 6000BFDF */  ld         $31, 0x60($29)
    /* FF2DC 001FF2DC 5000B47B */  lq         $20, 0x50($29)
    /* FF2E0 001FF2E0 4000B37B */  lq         $19, 0x40($29)
    /* FF2E4 001FF2E4 3000B27B */  lq         $18, 0x30($29)
    /* FF2E8 001FF2E8 2000B17B */  lq         $17, 0x20($29)
    /* FF2EC 001FF2EC 1000B07B */  lq         $16, 0x10($29)
    /* FF2F0 001FF2F0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* FF2F4 001FF2F4 A000BD27 */  addiu      $29, $29, 0xA0
    /* FF2F8 001FF2F8 0800E003 */  jr         $31
    /* FF2FC 001FF2FC 00000000 */   nop
.size func_001fec00, 0x700
