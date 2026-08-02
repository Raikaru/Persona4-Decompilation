.section .text
.set noat
.set noreorder
glabel func_0044ee70
    /* 34EE70 0044EE70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 34EE74 0044EE74 2000BFFF */  sd         $31, 0x20($29)
    /* 34EE78 0044EE78 1000B17F */  sq         $17, 0x10($29)
    /* 34EE7C 0044EE7C 0000B07F */  sq         $16, 0x0($29)
    /* 34EE80 0044EE80 2D888000 */  daddu      $17, $4, $0
    /* 34EE84 0044EE84 88AE100C */  jal        func_0042ba20
    /* 34EE88 0044EE88 00000000 */   nop
    /* 34EE8C 0044EE8C 2D804000 */  daddu      $16, $2, $0
    /* 34EE90 0044EE90 06002016 */  bnez       $17, .L0044EEAC
    /* 34EE94 0044EE94 00000000 */   nop
    /* 34EE98 0044EE98 7100043C */  lui        $4, %hi(D_007104E0)
    /* 34EE9C 0044EE9C E0048424 */  addiu      $4, $4, %lo(D_007104E0)
    /* 34EEA0 0044EEA0 70060524 */  addiu      $5, $0, 0x670
    /* 34EEA4 0044EEA4 CCB5110C */  jal        func_0046d730
    /* 34EEA8 0044EEA8 00000000 */   nop
  .L0044EEAC:
    /* 34EEAC 0044EEAC FCFF228E */  lw         $2, -0x4($17)
    /* 34EEB0 0044EEB0 2CAC848F */  lw         $4, -0x53D4($28)
    /* 34EEB4 0044EEB4 1800838C */  lw         $3, 0x18($4)
    /* 34EEB8 0044EEB8 FFFF6324 */  addiu      $3, $3, -0x1
    /* 34EEBC 0044EEBC 180083AC */  sw         $3, 0x18($4)
    /* 34EEC0 0044EEC0 2CAC858F */  lw         $5, -0x53D4($28)
    /* 34EEC4 0044EEC4 1C00A48C */  lw         $4, 0x1C($5)
    /* 34EEC8 0044EEC8 0000438C */  lw         $3, 0x0($2)
    /* 34EECC 0044EECC 23188300 */  subu       $3, $4, $3
    /* 34EED0 0044EED0 1C00A3AC */  sw         $3, 0x1C($5)
    /* 34EED4 0044EED4 08004390 */  lbu        $3, 0x8($2)
    /* 34EED8 0044EED8 08006128 */  slti       $1, $3, 0x8
    /* 34EEDC 0044EEDC 13002010 */  beqz       $1, .L0044EF2C
    /* 34EEE0 0044EEE0 00000000 */   nop
    /* 34EEE4 0044EEE4 2CAC848F */  lw         $4, -0x53D4($28)
    /* 34EEE8 0044EEE8 80180300 */  sll        $3, $3, 2
    /* 34EEEC 0044EEEC 21286400 */  addu       $5, $3, $4
    /* 34EEF0 0044EEF0 3800A48C */  lw         $4, 0x38($5)
    /* 34EEF4 0044EEF4 0000438C */  lw         $3, 0x0($2)
    /* 34EEF8 0044EEF8 23188300 */  subu       $3, $4, $3
    /* 34EEFC 0044EEFC 3800A3AC */  sw         $3, 0x38($5)
    /* 34EF00 0044EF00 04004394 */  lhu        $3, 0x4($2)
    /* 34EF04 0044EF04 18006424 */  addiu      $4, $3, 0x18
    /* 34EF08 0044EF08 0000438C */  lw         $3, 0x0($2)
    /* 34EF0C 0044EF0C 23286400 */  subu       $5, $3, $4
    /* 34EF10 0044EF10 08004390 */  lbu        $3, 0x8($2)
    /* 34EF14 0044EF14 80200300 */  sll        $4, $3, 2
    /* 34EF18 0044EF18 2CAC838F */  lw         $3, -0x53D4($28)
    /* 34EF1C 0044EF1C 21208300 */  addu       $4, $4, $3
    /* 34EF20 0044EF20 5800838C */  lw         $3, 0x58($4)
    /* 34EF24 0044EF24 23186500 */  subu       $3, $3, $5
    /* 34EF28 0044EF28 580083AC */  sw         $3, 0x58($4)
  .L0044EF2C:
    /* 34EF2C 0044EF2C 0C004424 */  addiu      $4, $2, 0xC
    /* 34EF30 0044EF30 483A110C */  jal        func_0044e920
    /* 34EF34 0044EF34 00000000 */   nop
    /* 34EF38 0044EF38 080040A4 */  sh         $0, 0x8($2)
    /* 34EF3C 0044EF3C 2D204000 */  daddu      $4, $2, $0
    /* 34EF40 0044EF40 42FB100C */  jal        func_0043ed08
    /* 34EF44 0044EF44 00000000 */   nop
    /* 34EF48 0044EF48 03000012 */  beqz       $16, .L0044EF58
    /* 34EF4C 0044EF4C 00000000 */   nop
    /* 34EF50 0044EF50 9CAE100C */  jal        func_0042ba70
    /* 34EF54 0044EF54 00000000 */   nop
  .L0044EF58:
    /* 34EF58 0044EF58 2000BFDF */  ld         $31, 0x20($29)
    /* 34EF5C 0044EF5C 1000B17B */  lq         $17, 0x10($29)
    /* 34EF60 0044EF60 0000B07B */  lq         $16, 0x0($29)
    /* 34EF64 0044EF64 3000BD27 */  addiu      $29, $29, 0x30
    /* 34EF68 0044EF68 0800E003 */  jr         $31
    /* 34EF6C 0044EF6C 00000000 */   nop
.size func_0044ee70, 0x100
