.section .text
.set noat
.set noreorder
glabel func_001afa50
    /* AFA50 001AFA50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AFA54 001AFA54 1000BFFF */  sd         $31, 0x10($29)
    /* AFA58 001AFA58 0000B07F */  sq         $16, 0x0($29)
    /* AFA5C 001AFA5C 2D808000 */  daddu      $16, $4, $0
    /* AFA60 001AFA60 18008294 */  lhu        $2, 0x18($4)
    /* AFA64 001AFA64 00404230 */  andi       $2, $2, 0x4000
    /* AFA68 001AFA68 0D004010 */  beqz       $2, .L001AFAA0
    /* AFA6C 001AFA6C 00000000 */   nop
    /* AFA70 001AFA70 ACB3848F */  lw         $4, -0x4C54($28)
    /* AFA74 001AFA74 0C00838C */  lw         $3, 0xC($4)
    /* AFA78 001AFA78 4000023C */  lui        $2, (0x400000 >> 16)
    /* AFA7C 001AFA7C 25106200 */  or         $2, $3, $2
    /* AFA80 001AFA80 0C0082AC */  sw         $2, 0xC($4)
    /* AFA84 001AFA84 ACB3838F */  lw         $3, -0x4C54($28)
    /* AFA88 001AFA88 18006294 */  lhu        $2, 0x18($3)
    /* AFA8C 001AFA8C 06004234 */  ori        $2, $2, 0x6
    /* AFA90 001AFA90 180062A4 */  sh         $2, 0x18($3)
    /* AFA94 001AFA94 18000296 */  lhu        $2, 0x18($16)
    /* AFA98 001AFA98 FFBF4230 */  andi       $2, $2, 0xBFFF
    /* AFA9C 001AFA9C 180002A6 */  sh         $2, 0x18($16)
  .L001AFAA0:
    /* AFAA0 001AFAA0 18000296 */  lhu        $2, 0x18($16)
    /* AFAA4 001AFAA4 FFFE4230 */  andi       $2, $2, 0xFEFF
    /* AFAA8 001AFAA8 180002A6 */  sh         $2, 0x18($16)
    /* AFAAC 001AFAAC 18000296 */  lhu        $2, 0x18($16)
    /* AFAB0 001AFAB0 00024230 */  andi       $2, $2, 0x200
    /* AFAB4 001AFAB4 0D004010 */  beqz       $2, .L001AFAEC
    /* AFAB8 001AFAB8 00000000 */   nop
    /* AFABC 001AFABC ACB3848F */  lw         $4, -0x4C54($28)
    /* AFAC0 001AFAC0 0C00838C */  lw         $3, 0xC($4)
    /* AFAC4 001AFAC4 4000023C */  lui        $2, (0x400000 >> 16)
    /* AFAC8 001AFAC8 25106200 */  or         $2, $3, $2
    /* AFACC 001AFACC 0C0082AC */  sw         $2, 0xC($4)
    /* AFAD0 001AFAD0 ACB3838F */  lw         $3, -0x4C54($28)
    /* AFAD4 001AFAD4 18006294 */  lhu        $2, 0x18($3)
    /* AFAD8 001AFAD8 20004234 */  ori        $2, $2, 0x20
    /* AFADC 001AFADC 180062A4 */  sh         $2, 0x18($3)
    /* AFAE0 001AFAE0 18000296 */  lhu        $2, 0x18($16)
    /* AFAE4 001AFAE4 FFFD4230 */  andi       $2, $2, 0xFDFF
    /* AFAE8 001AFAE8 180002A6 */  sh         $2, 0x18($16)
  .L001AFAEC:
    /* AFAEC 001AFAEC 2D200002 */  daddu      $4, $16, $0
    /* AFAF0 001AFAF0 20EB070C */  jal        func_001fac80
    /* AFAF4 001AFAF4 00000000 */   nop
    /* AFAF8 001AFAF8 0C004010 */  beqz       $2, .L001AFB2C
    /* AFAFC 001AFAFC 00000000 */   nop
    /* AFB00 001AFB00 2000023C */  lui        $2, %hi(func_001fad10)
    /* AFB04 001AFB04 10AD4224 */  addiu      $2, $2, %lo(func_001fad10)
    /* AFB08 001AFB08 400402AE */  sw         $2, 0x440($16)
    /* AFB0C 001AFB0C 21000224 */  addiu      $2, $0, 0x21
    /* AFB10 001AFB10 3C0402A6 */  sh         $2, 0x43C($16)
    /* AFB14 001AFB14 2D200002 */  daddu      $4, $16, $0
    /* AFB18 001AFB18 16000524 */  addiu      $5, $0, 0x16
    /* AFB1C 001AFB1C 00C2060C */  jal        func_001b0800
    /* AFB20 001AFB20 00000000 */   nop
    /* AFB24 001AFB24 04000010 */  b          .L001AFB38
    /* AFB28 001AFB28 00000000 */   nop
  .L001AFB2C:
    /* AFB2C 001AFB2C 18000396 */  lhu        $3, 0x18($16)
    /* AFB30 001AFB30 FFC76330 */  andi       $3, $3, 0xC7FF
    /* AFB34 001AFB34 180003A6 */  sh         $3, 0x18($16)
  .L001AFB38:
    /* AFB38 001AFB38 1000BFDF */  ld         $31, 0x10($29)
    /* AFB3C 001AFB3C 0000B07B */  lq         $16, 0x0($29)
    /* AFB40 001AFB40 2000BD27 */  addiu      $29, $29, 0x20
    /* AFB44 001AFB44 0800E003 */  jr         $31
    /* AFB48 001AFB48 00000000 */   nop
    /* AFB4C 001AFB4C 00000000 */  nop
.size func_001afa50, 0x100
