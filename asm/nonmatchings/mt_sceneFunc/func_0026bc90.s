.section .text
.set noat
.set noreorder
glabel func_0026bc90
    /* 16BC90 0026BC90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 16BC94 0026BC94 0000BFFF */  sd         $31, 0x0($29)
    /* 16BC98 0026BC98 2D300000 */  daddu      $6, $0, $0
    /* 16BC9C 0026BC9C 04008014 */  bnez       $4, .L0026BCB0
    /* 16BCA0 0026BCA0 00000000 */   nop
    /* 16BCA4 0026BCA4 2D100000 */  daddu      $2, $0, $0
    /* 16BCA8 0026BCA8 25000010 */  b          .L0026BD40
    /* 16BCAC 0026BCAC 00000000 */   nop
  .L0026BCB0:
    /* 16BCB0 0026BCB0 00008394 */  lhu        $3, 0x0($4)
    /* 16BCB4 0026BCB4 0F00023C */  lui        $2, (0xFFC00 >> 16)
    /* 16BCB8 0026BCB8 00FC4234 */  ori        $2, $2, (0xFFC00 & 0xFFFF)
    /* 16BCBC 0026BCBC 24106200 */  and        $2, $3, $2
    /* 16BCC0 0026BCC0 831A0200 */  sra        $3, $2, 10
    /* 16BCC4 0026BCC4 03000224 */  addiu      $2, $0, 0x3
    /* 16BCC8 0026BCC8 09006210 */  beq        $3, $2, .L0026BCF0
    /* 16BCCC 0026BCCC 00000000 */   nop
    /* 16BCD0 0026BCD0 01000224 */  addiu      $2, $0, 0x1
    /* 16BCD4 0026BCD4 03006210 */  beq        $3, $2, .L0026BCE4
    /* 16BCD8 0026BCD8 00000000 */   nop
    /* 16BCDC 0026BCDC 05000010 */  b          .L0026BCF4
    /* 16BCE0 0026BCE0 00000000 */   nop
  .L0026BCE4:
    /* 16BCE4 0026BCE4 2402868C */  lw         $6, 0x224($4)
    /* 16BCE8 0026BCE8 02000010 */  b          .L0026BCF4
    /* 16BCEC 0026BCEC 00000000 */   nop
  .L0026BCF0:
    /* 16BCF0 0026BCF0 3002868C */  lw         $6, 0x230($4)
  .L0026BCF4:
    /* 16BCF4 0026BCF4 0400C014 */  bnez       $6, .L0026BD08
    /* 16BCF8 0026BCF8 00000000 */   nop
    /* 16BCFC 0026BCFC 2D100000 */  daddu      $2, $0, $0
    /* 16BD00 0026BD00 0F000010 */  b          .L0026BD40
    /* 16BD04 0026BD04 00000000 */   nop
  .L0026BD08:
    /* 16BD08 0026BD08 01000224 */  addiu      $2, $0, 0x1
    /* 16BD0C 0026BD0C 0700A214 */  bne        $5, $2, .L0026BD2C
    /* 16BD10 0026BD10 00000000 */   nop
    /* 16BD14 0026BD14 2D20C000 */  daddu      $4, $6, $0
    /* 16BD18 0026BD18 2D280000 */  daddu      $5, $0, $0
    /* 16BD1C 0026BD1C 64EE050C */  jal        func_0017b990
    /* 16BD20 0026BD20 00000000 */   nop
    /* 16BD24 0026BD24 05000010 */  b          .L0026BD3C
    /* 16BD28 0026BD28 00000000 */   nop
  .L0026BD2C:
    /* 16BD2C 0026BD2C 2D20C000 */  daddu      $4, $6, $0
    /* 16BD30 0026BD30 2D284000 */  daddu      $5, $2, $0
    /* 16BD34 0026BD34 64EE050C */  jal        func_0017b990
    /* 16BD38 0026BD38 00000000 */   nop
  .L0026BD3C:
    /* 16BD3C 0026BD3C 01000224 */  addiu      $2, $0, 0x1
  .L0026BD40:
    /* 16BD40 0026BD40 0000BFDF */  ld         $31, 0x0($29)
    /* 16BD44 0026BD44 1000BD27 */  addiu      $29, $29, 0x10
    /* 16BD48 0026BD48 0800E003 */  jr         $31
    /* 16BD4C 0026BD4C 00000000 */   nop
.size func_0026bc90, 0xc0
