.section .text
.set noat
.set noreorder
glabel func_0042cbd8
    /* 32CBD8 0042CBD8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 32CBDC 0042CBDC 0000B0FF */  sd         $16, 0x0($29)
    /* 32CBE0 0042CBE0 1000BFFF */  sd         $31, 0x10($29)
    /* 32CBE4 0042CBE4 88AE100C */  jal        func_0042ba20
    /* 32CBE8 0042CBE8 00000000 */   nop
    /* 32CBEC 0042CBEC 0010033C */  lui        $3, (0x10001000 >> 16)
    /* 32CBF0 0042CBF0 7100043C */  lui        $4, %hi(D_0070DC88)
    /* 32CBF4 0042CBF4 00106334 */  ori        $3, $3, (0x10001000 & 0xFFFF)
    /* 32CBF8 0042CBF8 0000709C */  lwu        $16, 0x0($3)
    /* 32CBFC 0042CBFC 1000688C */  lw         $8, 0x10($3)
    /* 32CC00 0042CC00 88DC8ADC */  ld         $10, %lo(D_0070DC88)($4)
    /* 32CC04 0042CC04 00080931 */  andi       $9, $8, 0x800
    /* 32CC08 0042CC08 03002011 */  beqz       $9, .L0042CC18
    /* 32CC0C 0042CC0C 02000924 */   addiu     $9, $0, 0x2
    /* 32CC10 0042CC10 0000709C */  lwu        $16, 0x0($3)
    /* 32CC14 0042CC14 01004A65 */  daddiu     $10, $10, 0x1
  .L0042CC18:
    /* 32CC18 0042CC18 03000831 */  andi       $8, $8, 0x3
    /* 32CC1C 0042CC1C 38540A00 */  dsll       $10, $10, 16
    /* 32CC20 0042CC20 0A480800 */  movz       $9, $0, $8
    /* 32CC24 0042CC24 25800A02 */  or         $16, $16, $10
    /* 32CC28 0042CC28 14480901 */  dsllv      $9, $9, $8
    /* 32CC2C 0042CC2C 14803001 */  dsllv      $16, $16, $9
    /* 32CC30 0042CC30 04004010 */  beqz       $2, .L0042CC44
    /* 32CC34 0042CC34 2D100002 */   daddu     $2, $16, $0
    /* 32CC38 0042CC38 9CAE100C */  jal        func_0042ba70
    /* 32CC3C 0042CC3C 00000000 */   nop
    /* 32CC40 0042CC40 2D100002 */  daddu      $2, $16, $0
  .L0042CC44:
    /* 32CC44 0042CC44 1000BFDF */  ld         $31, 0x10($29)
    /* 32CC48 0042CC48 0000B0DF */  ld         $16, 0x0($29)
    /* 32CC4C 0042CC4C 0800E003 */  jr         $31
    /* 32CC50 0042CC50 2000BD27 */   addiu     $29, $29, 0x20
    /* 32CC54 0042CC54 00000000 */  nop
.size func_0042cbd8, 0x80
