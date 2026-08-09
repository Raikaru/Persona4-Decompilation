.section .text
.set noat
.set noreorder
glabel func_004eeef8
    /* 3EEEF8 004EEEF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEEFC 004EEEFC 08008014 */  bnez       $4, .L004EEF20
    /* 3EEF00 004EEF00 0000BFFF */   sd        $31, 0x0($29)
    /* 3EEF04 004EEF04 7600043C */  lui        $4, %hi(D_0075CF68)
    /* 3EEF08 004EEF08 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EEF0C 004EEF0C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEF10 004EEF10 68CF8424 */  addiu      $4, $4, %lo(D_0075CF68)
    /* 3EEF14 004EEF14 F8CEA524 */  addiu      $5, $5, %lo(D_0075CEF8)
    /* 3EEF18 004EEF18 B6BA1308 */  j          func_004eead8
    /* 3EEF1C 004EEF1C 1000BD27 */   addiu     $29, $29, 0x10
  .L004EEF20:
    /* 3EEF20 004EEF20 04008280 */  lb         $2, 0x4($4)
    /* 3EEF24 004EEF24 08004014 */  bnez       $2, .L004EEF48
    /* 3EEF28 004EEF28 0000BFDF */   ld        $31, 0x0($29)
    /* 3EEF2C 004EEF2C 7600043C */  lui        $4, %hi(D_0075CF78)
    /* 3EEF30 004EEF30 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EEF34 004EEF34 78CF8424 */  addiu      $4, $4, %lo(D_0075CF78)
    /* 3EEF38 004EEF38 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
    /* 3EEF3C 004EEF3C B6BA1308 */  j          func_004eead8
    /* 3EEF40 004EEF40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEF44 004EEF44 00000000 */  nop
  .L004EEF48:
    /* 3EEF48 004EEF48 2C0086AC */  sw         $6, 0x2C($4)
    /* 3EEF4C 004EEF4C 280085AC */  sw         $5, 0x28($4)
    /* 3EEF50 004EEF50 0800E003 */  jr         $31
    /* 3EEF54 004EEF54 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eeef8, 0x60
