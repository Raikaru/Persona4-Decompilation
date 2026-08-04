.section .text
.set noat
.set noreorder
glabel func_0017bc60
    /* 7BC60 0017BC60 50FFBD27 */  addiu      $29, $29, -0xB0
    /* 7BC64 0017BC64 5000BFFF */  sd         $31, 0x50($29)
    /* 7BC68 0017BC68 4000B37F */  sq         $19, 0x40($29)
    /* 7BC6C 0017BC6C 3000B27F */  sq         $18, 0x30($29)
    /* 7BC70 0017BC70 2000B17F */  sq         $17, 0x20($29)
    /* 7BC74 0017BC74 1000B07F */  sq         $16, 0x10($29)
    /* 7BC78 0017BC78 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 7BC7C 0017BC7C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 7BC80 0017BC80 2D90A000 */  daddu      $18, $5, $0
    /* 7BC84 0017BC84 2402A28C */  lw         $2, 0x224($5)
    /* 7BC88 0017BC88 3800428C */  lw         $2, 0x38($2)
    /* 7BC8C 0017BC8C 4400518C */  lw         $17, 0x44($2)
    /* 7BC90 0017BC90 180054C4 */  lwc1       $f20, 0x18($2)
    /* 7BC94 0017BC94 6401A48C */  lw         $4, 0x164($5)
    /* 7BC98 0017BC98 BCE8110C */  jal        func_0047a2f0
    /* 7BC9C 0017BC9C 00000000 */   nop
    /* 7BCA0 0017BCA0 300042C4 */  lwc1       $f2, 0x30($2)
    /* 7BCA4 0017BCA4 340041C4 */  lwc1       $f1, 0x34($2)
    /* 7BCA8 0017BCA8 380040C4 */  lwc1       $f0, 0x38($2)
    /* 7BCAC 0017BCAC A000A2E7 */  swc1       $f2, 0xA0($29)
    /* 7BCB0 0017BCB0 A400A1E7 */  swc1       $f1, 0xA4($29)
    /* 7BCB4 0017BCB4 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 7BCB8 0017BCB8 2402438E */  lw         $3, 0x224($18)
    /* 7BCBC 0017BCBC 3800638C */  lw         $3, 0x38($3)
    /* 7BCC0 0017BCC0 0000638C */  lw         $3, 0x0($3)
    /* 7BCC4 0017BCC4 C7006018 */  blez       $3, .L0017BFE4
    /* 7BCC8 0017BCC8 00000000 */   nop
    /* 7BCCC 0017BCCC 2800438E */  lw         $3, 0x28($18)
    /* 7BCD0 0017BCD0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 7BCD4 0017BCD4 24106200 */  and        $2, $3, $2
    /* 7BCD8 0017BCD8 21004010 */  beqz       $2, .L0017BD60
    /* 7BCDC 0017BCDC 00000000 */   nop
    /* 7BCE0 0017BCE0 04003026 */  addiu      $16, $17, 0x4
    /* 7BCE4 0017BCE4 0400338E */  lw         $19, 0x4($17)
    /* 7BCE8 0017BCE8 900142C6 */  lwc1       $f2, 0x190($18)
    /* 7BCEC 0017BCEC 940141C6 */  lwc1       $f1, 0x194($18)
    /* 7BCF0 0017BCF0 980140C6 */  lwc1       $f0, 0x198($18)
    /* 7BCF4 0017BCF4 100062E6 */  swc1       $f2, 0x10($19)
    /* 7BCF8 0017BCF8 140061E6 */  swc1       $f1, 0x14($19)
    /* 7BCFC 0017BCFC 180060E6 */  swc1       $f0, 0x18($19)
    /* 7BD00 0017BD00 A00142C6 */  lwc1       $f2, 0x1A0($18)
    /* 7BD04 0017BD04 A40141C6 */  lwc1       $f1, 0x1A4($18)
    /* 7BD08 0017BD08 A80140C6 */  lwc1       $f0, 0x1A8($18)
    /* 7BD0C 0017BD0C 200062E6 */  swc1       $f2, 0x20($19)
    /* 7BD10 0017BD10 240061E6 */  swc1       $f1, 0x24($19)
    /* 7BD14 0017BD14 280060E6 */  swc1       $f0, 0x28($19)
    /* 7BD18 0017BD18 B00142C6 */  lwc1       $f2, 0x1B0($18)
    /* 7BD1C 0017BD1C B40141C6 */  lwc1       $f1, 0x1B4($18)
    /* 7BD20 0017BD20 B80140C6 */  lwc1       $f0, 0x1B8($18)
    /* 7BD24 0017BD24 300062E6 */  swc1       $f2, 0x30($19)
    /* 7BD28 0017BD28 340061E6 */  swc1       $f1, 0x34($19)
    /* 7BD2C 0017BD2C 380060E6 */  swc1       $f0, 0x38($19)
    /* 7BD30 0017BD30 9000A427 */  addiu      $4, $29, 0x90
    /* 7BD34 0017BD34 E0800F0C */  jal        func_003e0380
    /* 7BD38 0017BD38 00000000 */   nop
    /* 7BD3C 0017BD3C 10006426 */  addiu      $4, $19, 0x10
    /* 7BD40 0017BD40 9000A527 */  addiu      $5, $29, 0x90
    /* 7BD44 0017BD44 F8800F0C */  jal        func_003e03e0
    /* 7BD48 0017BD48 00000000 */   nop
    /* 7BD4C 0017BD4C 10006426 */  addiu      $4, $19, 0x10
    /* 7BD50 0017BD50 74810F0C */  jal        func_003e05d0
    /* 7BD54 0017BD54 00000000 */   nop
    /* 7BD58 0017BD58 21000010 */  b          .L0017BDE0
    /* 7BD5C 0017BD5C 00000000 */   nop
  .L0017BD60:
    /* 7BD60 0017BD60 542B050C */  jal        func_0014ad50
    /* 7BD64 0017BD64 00000000 */   nop
    /* 7BD68 0017BD68 04003026 */  addiu      $16, $17, 0x4
    /* 7BD6C 0017BD6C 0400338E */  lw         $19, 0x4($17)
    /* 7BD70 0017BD70 000042C4 */  lwc1       $f2, 0x0($2)
    /* 7BD74 0017BD74 040041C4 */  lwc1       $f1, 0x4($2)
    /* 7BD78 0017BD78 080040C4 */  lwc1       $f0, 0x8($2)
    /* 7BD7C 0017BD7C 100062E6 */  swc1       $f2, 0x10($19)
    /* 7BD80 0017BD80 140061E6 */  swc1       $f1, 0x14($19)
    /* 7BD84 0017BD84 180060E6 */  swc1       $f0, 0x18($19)
    /* 7BD88 0017BD88 100042C4 */  lwc1       $f2, 0x10($2)
    /* 7BD8C 0017BD8C 140041C4 */  lwc1       $f1, 0x14($2)
    /* 7BD90 0017BD90 180040C4 */  lwc1       $f0, 0x18($2)
    /* 7BD94 0017BD94 200062E6 */  swc1       $f2, 0x20($19)
    /* 7BD98 0017BD98 240061E6 */  swc1       $f1, 0x24($19)
    /* 7BD9C 0017BD9C 280060E6 */  swc1       $f0, 0x28($19)
    /* 7BDA0 0017BDA0 200042C4 */  lwc1       $f2, 0x20($2)
    /* 7BDA4 0017BDA4 240041C4 */  lwc1       $f1, 0x24($2)
    /* 7BDA8 0017BDA8 280040C4 */  lwc1       $f0, 0x28($2)
    /* 7BDAC 0017BDAC 300062E6 */  swc1       $f2, 0x30($19)
    /* 7BDB0 0017BDB0 340061E6 */  swc1       $f1, 0x34($19)
    /* 7BDB4 0017BDB4 380060E6 */  swc1       $f0, 0x38($19)
    /* 7BDB8 0017BDB8 8000A427 */  addiu      $4, $29, 0x80
    /* 7BDBC 0017BDBC E0800F0C */  jal        func_003e0380
    /* 7BDC0 0017BDC0 00000000 */   nop
    /* 7BDC4 0017BDC4 10006426 */  addiu      $4, $19, 0x10
    /* 7BDC8 0017BDC8 8000A527 */  addiu      $5, $29, 0x80
    /* 7BDCC 0017BDCC F8800F0C */  jal        func_003e03e0
    /* 7BDD0 0017BDD0 00000000 */   nop
    /* 7BDD4 0017BDD4 10006426 */  addiu      $4, $19, 0x10
    /* 7BDD8 0017BDD8 74810F0C */  jal        func_003e05d0
    /* 7BDDC 0017BDDC 00000000 */   nop
  .L0017BDE0:
    /* 7BDE0 0017BDE0 6C8280C7 */  lwc1       $f0, -0x7D94($28)
    /* 7BDE4 0017BDE4 42051446 */  mul.s      $f21, $f0, $f20
    /* 7BDE8 0017BDE8 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 7BDEC 0017BDEC 00008244 */  mtc1       $2, $f0
    /* 7BDF0 0017BDF0 00000000 */  nop
    /* 7BDF4 0017BDF4 02031546 */  mul.s      $f12, $f0, $f21
    /* 7BDF8 0017BDF8 2D202002 */  daddu      $4, $17, $0
    /* 7BDFC 0017BDFC 70A00F0C */  jal        func_003e81c0
    /* 7BE00 0017BE00 00000000 */   nop
    /* 7BE04 0017BE04 148280C7 */  lwc1       $f0, -0x7DEC($28)
    /* 7BE08 0017BE08 02031546 */  mul.s      $f12, $f0, $f21
    /* 7BE0C 0017BE0C 2D202002 */  daddu      $4, $17, $0
    /* 7BE10 0017BE10 60A00F0C */  jal        func_003e8180
    /* 7BE14 0017BE14 00000000 */   nop
    /* 7BE18 0017BE18 5828050C */  jal        func_0014a160
    /* 7BE1C 0017BE1C 00000000 */   nop
    /* 7BE20 0017BE20 01000324 */  addiu      $3, $0, 0x1
    /* 7BE24 0017BE24 0B004314 */  bne        $2, $3, .L0017BE54
    /* 7BE28 0017BE28 00000000 */   nop
    /* 7BE2C 0017BE2C 6C8280C7 */  lwc1       $f0, -0x7D94($28)
    /* 7BE30 0017BE30 42001446 */  mul.s      $f1, $f0, $f20
    /* 7BE34 0017BE34 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 7BE38 0017BE38 00008244 */  mtc1       $2, $f0
    /* 7BE3C 0017BE3C 00000000 */  nop
    /* 7BE40 0017BE40 02000146 */  mul.s      $f0, $f0, $f1
    /* 7BE44 0017BE44 7800A0E7 */  swc1       $f0, 0x78($29)
    /* 7BE48 0017BE48 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* 7BE4C 0017BE4C 07000010 */  b          .L0017BE6C
    /* 7BE50 0017BE50 00000000 */   nop
  .L0017BE54:
    /* 7BE54 0017BE54 6C8280C7 */  lwc1       $f0, -0x7D94($28)
    /* 7BE58 0017BE58 42001446 */  mul.s      $f1, $f0, $f20
    /* 7BE5C 0017BE5C 608380C7 */  lwc1       $f0, -0x7CA0($28)
    /* 7BE60 0017BE60 02000146 */  mul.s      $f0, $f0, $f1
    /* 7BE64 0017BE64 7800A0E7 */  swc1       $f0, 0x78($29)
    /* 7BE68 0017BE68 7C00A0E7 */  swc1       $f0, 0x7C($29)
  .L0017BE6C:
    /* 7BE6C 0017BE6C 2D202002 */  daddu      $4, $17, $0
    /* 7BE70 0017BE70 7800A527 */  addiu      $5, $29, 0x78
    /* 7BE74 0017BE74 E8A00F0C */  jal        func_003e83a0
    /* 7BE78 0017BE78 00000000 */   nop
    /* 7BE7C 0017BE7C A400A1C7 */  lwc1       $f1, 0xA4($29)
    /* 7BE80 0017BE80 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 7BE84 0017BE84 00008244 */  mtc1       $2, $f0
    /* 7BE88 0017BE88 00000000 */  nop
    /* 7BE8C 0017BE8C 03A00046 */  div.s      $f0, $f20, $f0
    /* 7BE90 0017BE90 00090046 */  add.s      $f4, $f1, $f0
    /* 7BE94 0017BE94 A400A4E7 */  swc1       $f4, 0xA4($29)
    /* 7BE98 0017BE98 0000108E */  lw         $16, 0x0($16)
    /* 7BE9C 0017BE9C 400000C6 */  lwc1       $f0, 0x40($16)
    /* 7BEA0 0017BEA0 C7000046 */  neg.s      $f3, $f0
    /* 7BEA4 0017BEA4 6800A3E7 */  swc1       $f3, 0x68($29)
    /* 7BEA8 0017BEA8 440000C6 */  lwc1       $f0, 0x44($16)
    /* 7BEAC 0017BEAC 87000046 */  neg.s      $f2, $f0
    /* 7BEB0 0017BEB0 6C00A2E7 */  swc1       $f2, 0x6C($29)
    /* 7BEB4 0017BEB4 480000C6 */  lwc1       $f0, 0x48($16)
    /* 7BEB8 0017BEB8 47000046 */  neg.s      $f1, $f0
    /* 7BEBC 0017BEBC 7000A1E7 */  swc1       $f1, 0x70($29)
    /* 7BEC0 0017BEC0 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* 7BEC4 0017BEC4 80190046 */  add.s      $f6, $f3, $f0
    /* 7BEC8 0017BEC8 6800A6E7 */  swc1       $f6, 0x68($29)
    /* 7BECC 0017BECC 40110446 */  add.s      $f5, $f2, $f4
    /* 7BED0 0017BED0 6C00A5E7 */  swc1       $f5, 0x6C($29)
    /* 7BED4 0017BED4 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* 7BED8 0017BED8 00090046 */  add.s      $f4, $f1, $f0
    /* 7BEDC 0017BEDC 7000A4E7 */  swc1       $f4, 0x70($29)
    /* 7BEE0 0017BEE0 300003C6 */  lwc1       $f3, 0x30($16)
    /* 7BEE4 0017BEE4 00BF023C */  lui        $2, (0xBF000000 >> 16)
    /* 7BEE8 0017BEE8 00088244 */  mtc1       $2, $f1
    /* 7BEEC 0017BEEC 840020C6 */  lwc1       $f0, 0x84($17)
    /* 7BEF0 0017BEF0 82080046 */  mul.s      $f2, $f1, $f0
    /* 7BEF4 0017BEF4 00088044 */  mtc1       $0, $f1
    /* 7BEF8 0017BEF8 00000000 */  nop
    /* 7BEFC 0017BEFC 18080646 */  adda.s     $f1, $f6
    /* 7BF00 0017BF00 1C180246 */  madd.s     $f0, $f3, $f2
    /* 7BF04 0017BF04 6800A0E7 */  swc1       $f0, 0x68($29)
    /* 7BF08 0017BF08 340000C6 */  lwc1       $f0, 0x34($16)
    /* 7BF0C 0017BF0C 18080546 */  adda.s     $f1, $f5
    /* 7BF10 0017BF10 1C000246 */  madd.s     $f0, $f0, $f2
    /* 7BF14 0017BF14 6C00A0E7 */  swc1       $f0, 0x6C($29)
    /* 7BF18 0017BF18 380000C6 */  lwc1       $f0, 0x38($16)
    /* 7BF1C 0017BF1C 18080446 */  adda.s     $f1, $f4
    /* 7BF20 0017BF20 1C000246 */  madd.s     $f0, $f0, $f2
    /* 7BF24 0017BF24 7000A0E7 */  swc1       $f0, 0x70($29)
    /* 7BF28 0017BF28 2D200002 */  daddu      $4, $16, $0
    /* 7BF2C 0017BF2C 6800A527 */  addiu      $5, $29, 0x68
    /* 7BF30 0017BF30 02000624 */  addiu      $6, $0, 0x2
    /* 7BF34 0017BF34 04A70F0C */  jal        func_003e9c10
    /* 7BF38 0017BF38 00000000 */   nop
    /* 7BF3C 0017BF3C 2D200002 */  daddu      $4, $16, $0
    /* 7BF40 0017BF40 C0A50F0C */  jal        func_003e9700
    /* 7BF44 0017BF44 00000000 */   nop
    /* 7BF48 0017BF48 2D204000 */  daddu      $4, $2, $0
    /* 7BF4C 0017BF4C 2D284000 */  daddu      $5, $2, $0
    /* 7BF50 0017BF50 9C810F0C */  jal        func_003e0670
    /* 7BF54 0017BF54 00000000 */   nop
    /* 7BF58 0017BF58 2D202002 */  daddu      $4, $17, $0
    /* 7BF5C 0017BF5C 08B38527 */  addiu      $5, $28, -0x4CF8
    /* 7BF60 0017BF60 03000624 */  addiu      $6, $0, 0x3
    /* 7BF64 0017BF64 A8A00F0C */  jal        func_003e82a0
    /* 7BF68 0017BF68 00000000 */   nop
    /* 7BF6C 0017BF6C 2D202002 */  daddu      $4, $17, $0
    /* 7BF70 0017BF70 48A00F0C */  jal        func_003e8120
    /* 7BF74 0017BF74 00000000 */   nop
    /* 7BF78 0017BF78 15004010 */  beqz       $2, .L0017BFD0
    /* 7BF7C 0017BF7C 00000000 */   nop
    /* 7BF80 0017BF80 2402428E */  lw         $2, 0x224($18)
    /* 7BF84 0017BF84 3800428C */  lw         $2, 0x38($2)
    /* 7BF88 0017BF88 48005024 */  addiu      $16, $2, 0x48
    /* 7BF8C 0017BF8C 6401448E */  lw         $4, 0x164($18)
    /* 7BF90 0017BF90 94E8110C */  jal        func_0047a250
    /* 7BF94 0017BF94 00000000 */   nop
    /* 7BF98 0017BF98 00004590 */  lbu        $5, 0x0($2)
    /* 7BF9C 0017BF9C 01004490 */  lbu        $4, 0x1($2)
    /* 7BFA0 0017BFA0 02004390 */  lbu        $3, 0x2($2)
    /* 7BFA4 0017BFA4 03004290 */  lbu        $2, 0x3($2)
    /* 7BFA8 0017BFA8 000005A2 */  sb         $5, 0x0($16)
    /* 7BFAC 0017BFAC 010004A2 */  sb         $4, 0x1($16)
    /* 7BFB0 0017BFB0 020003A2 */  sb         $3, 0x2($16)
    /* 7BFB4 0017BFB4 030002A2 */  sb         $2, 0x3($16)
    /* 7BFB8 0017BFB8 6401448E */  lw         $4, 0x164($18)
    /* 7BFBC 0017BFBC 4C9F8527 */  addiu      $5, $28, -0x60B4
    /* 7BFC0 0017BFC0 88E8110C */  jal        func_0047a220
    /* 7BFC4 0017BFC4 00000000 */   nop
    /* 7BFC8 0017BFC8 06000010 */  b          .L0017BFE4
    /* 7BFCC 0017BFCC 00000000 */   nop
  .L0017BFD0:
    /* 7BFD0 0017BFD0 5F00043C */  lui        $4, %hi(D_005F18C0)
    /* 7BFD4 0017BFD4 C0188424 */  addiu      $4, $4, %lo(D_005F18C0)
    /* 7BFD8 0017BFD8 64070524 */  addiu      $5, $0, 0x764
    /* 7BFDC 0017BFDC CCB5110C */  jal        func_0046d730
    /* 7BFE0 0017BFE0 00000000 */   nop
  .L0017BFE4:
    /* 7BFE4 0017BFE4 5000BFDF */  ld         $31, 0x50($29)
    /* 7BFE8 0017BFE8 4000B37B */  lq         $19, 0x40($29)
    /* 7BFEC 0017BFEC 3000B27B */  lq         $18, 0x30($29)
    /* 7BFF0 0017BFF0 2000B17B */  lq         $17, 0x20($29)
    /* 7BFF4 0017BFF4 1000B07B */  lq         $16, 0x10($29)
    /* 7BFF8 0017BFF8 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 7BFFC 0017BFFC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 7C000 0017C000 B000BD27 */  addiu      $29, $29, 0xB0
    /* 7C004 0017C004 0800E003 */  jr         $31
    /* 7C008 0017C008 00000000 */   nop
    /* 7C00C 0017C00C 00000000 */  nop
.size func_0017bc60, 0x3b0
