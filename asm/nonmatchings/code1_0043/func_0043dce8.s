.section .text
.set noat
.set noreorder
glabel func_0043dce8
    /* 33DCE8 0043DCE8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 33DCEC 0043DCEC 0800B1FF */  sd         $17, 0x8($29)
    /* 33DCF0 0043DCF0 0000B0FF */  sd         $16, 0x0($29)
    /* 33DCF4 0043DCF4 1000B2FF */  sd         $18, 0x10($29)
    /* 33DCF8 0043DCF8 1800BFFF */  sd         $31, 0x18($29)
    /* 33DCFC 0043DCFC 0C008014 */  bnez       $4, .L0043DD30
    /* 33DD00 0043DD00 2D888000 */   daddu     $17, $4, $0
    /* 33DD04 0043DD04 71000F3C */  lui        $15, %hi(D_00710070)
    /* 33DD08 0043DD08 0000B0DF */  ld         $16, 0x0($29)
    /* 33DD0C 0043DD0C 7000E48D */  lw         $4, %lo(D_00710070)($15)
    /* 33DD10 0043DD10 4400053C */  lui        $5, %hi(func_0043dce8)
    /* 33DD14 0043DD14 0800B1DF */  ld         $17, 0x8($29)
    /* 33DD18 0043DD18 E8DCA524 */  addiu      $5, $5, %lo(func_0043dce8)
    /* 33DD1C 0043DD1C 1000B2DF */  ld         $18, 0x10($29)
    /* 33DD20 0043DD20 1800BFDF */  ld         $31, 0x18($29)
    /* 33DD24 0043DD24 74FA1008 */  j          func_0043e9d0
    /* 33DD28 0043DD28 2000BD27 */   addiu     $29, $29, 0x20
    /* 33DD2C 0043DD2C 00000000 */  nop
  .L0043DD30:
    /* 33DD30 0043DD30 5400848C */  lw         $4, 0x54($4)
    /* 33DD34 0043DD34 06008054 */  bnel       $4, $0, .L0043DD50
    /* 33DD38 0043DD38 38008F8C */   lw        $15, 0x38($4)
    /* 33DD3C 0043DD3C 71000F3C */  lui        $15, %hi(D_00710070)
    /* 33DD40 0043DD40 7000EE8D */  lw         $14, %lo(D_00710070)($15)
    /* 33DD44 0043DD44 54002EAE */  sw         $14, 0x54($17)
    /* 33DD48 0043DD48 2D20C001 */  daddu      $4, $14, $0
    /* 33DD4C 0043DD4C 38008F8C */  lw         $15, 0x38($4)
  .L0043DD50:
    /* 33DD50 0043DD50 0400E055 */  bnel       $15, $0, .L0043DD64
    /* 33DD54 0043DD54 0C002286 */   lh        $2, 0xC($17)
    /* 33DD58 0043DD58 F8F7100C */  jal        func_0043dfe0
    /* 33DD5C 0043DD5C 00000000 */   nop
    /* 33DD60 0043DD60 0C002286 */  lh         $2, 0xC($17)
  .L0043DD64:
    /* 33DD64 0043DD64 08004F30 */  andi       $15, $2, 0x8
    /* 33DD68 0043DD68 1700E051 */  beql       $15, $0, .L0043DDC8
    /* 33DD6C 0043DD6C 2D100000 */   daddu     $2, $0, $0
    /* 33DD70 0043DD70 1000328E */  lw         $18, 0x10($17)
    /* 33DD74 0043DD74 13004012 */  beqz       $18, .L0043DDC4
    /* 33DD78 0043DD78 03004E30 */   andi      $14, $2, 0x3
    /* 33DD7C 0043DD7C 00002F8E */  lw         $15, 0x0($17)
    /* 33DD80 0043DD80 2D680000 */  daddu      $13, $0, $0
    /* 33DD84 0043DD84 000032AE */  sw         $18, 0x0($17)
    /* 33DD88 0043DD88 0200C015 */  bnez       $14, .L0043DD94
    /* 33DD8C 0043DD8C 2380F201 */   subu      $16, $15, $18
    /* 33DD90 0043DD90 14002D8E */  lw         $13, 0x14($17)
  .L0043DD94:
    /* 33DD94 0043DD94 0B00001A */  blez       $16, .L0043DDC4
    /* 33DD98 0043DD98 08002DAE */   sw        $13, 0x8($17)
    /* 33DD9C 0043DD9C 2400228E */  lw         $2, 0x24($17)
  .L0043DDA0:
    /* 33DDA0 0043DDA0 2D284002 */  daddu      $5, $18, $0
    /* 33DDA4 0043DDA4 1C00248E */  lw         $4, 0x1C($17)
    /* 33DDA8 0043DDA8 09F84000 */  jalr       $2
    /* 33DDAC 0043DDAC 2D300002 */   daddu     $6, $16, $0
    /* 33DDB0 0043DDB0 23800202 */  subu       $16, $16, $2
    /* 33DDB4 0043DDB4 0A004018 */  blez       $2, .L0043DDE0
    /* 33DDB8 0043DDB8 21904202 */   addu      $18, $18, $2
    /* 33DDBC 0043DDBC F8FF005E */  bgtzl      $16, .L0043DDA0
    /* 33DDC0 0043DDC0 2400228E */   lw        $2, 0x24($17)
  .L0043DDC4:
    /* 33DDC4 0043DDC4 2D100000 */  daddu      $2, $0, $0
  .L0043DDC8:
    /* 33DDC8 0043DDC8 0000B0DF */  ld         $16, 0x0($29)
    /* 33DDCC 0043DDCC 0800B1DF */  ld         $17, 0x8($29)
    /* 33DDD0 0043DDD0 1000B2DF */  ld         $18, 0x10($29)
    /* 33DDD4 0043DDD4 1800BFDF */  ld         $31, 0x18($29)
    /* 33DDD8 0043DDD8 0800E003 */  jr         $31
    /* 33DDDC 0043DDDC 2000BD27 */   addiu     $29, $29, 0x20
  .L0043DDE0:
    /* 33DDE0 0043DDE0 0C002F96 */  lhu        $15, 0xC($17)
    /* 33DDE4 0043DDE4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 33DDE8 0043DDE8 4000EF35 */  ori        $15, $15, 0x40
    /* 33DDEC 0043DDEC F6FF0010 */  b          .L0043DDC8
    /* 33DDF0 0043DDF0 0C002FA6 */   sh        $15, 0xC($17)
    /* 33DDF4 0043DDF4 00000000 */  nop
.size func_0043dce8, 0x110
