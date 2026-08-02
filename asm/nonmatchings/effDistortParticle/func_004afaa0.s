.section .text
.set noat
.set noreorder
glabel func_004afaa0
    /* 3AFAA0 004AFAA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AFAA4 004AFAA4 2000BFFF */  sd         $31, 0x20($29)
    /* 3AFAA8 004AFAA8 1000B17F */  sq         $17, 0x10($29)
    /* 3AFAAC 004AFAAC 0000B07F */  sq         $16, 0x0($29)
    /* 3AFAB0 004AFAB0 2D888000 */  daddu      $17, $4, $0
    /* 3AFAB4 004AFAB4 2D80A000 */  daddu      $16, $5, $0
    /* 3AFAB8 004AFAB8 6000A38C */  lw         $3, 0x60($5)
    /* 3AFABC 004AFABC 06006014 */  bnez       $3, .L004AFAD8
    /* 3AFAC0 004AFAC0 00000000 */   nop
    /* 3AFAC4 004AFAC4 7100043C */  lui        $4, %hi(D_00714550)
    /* 3AFAC8 004AFAC8 50458424 */  addiu      $4, $4, %lo(D_00714550)
    /* 3AFACC 004AFACC DA000524 */  addiu      $5, $0, 0xDA
    /* 3AFAD0 004AFAD0 CCB5110C */  jal        func_0046d730
    /* 3AFAD4 004AFAD4 00000000 */   nop
  .L004AFAD8:
    /* 3AFAD8 004AFAD8 6000048E */  lw         $4, 0x60($16)
    /* 3AFADC 004AFADC 600024AE */  sw         $4, 0x60($17)
    /* 3AFAE0 004AFAE0 5400838C */  lw         $3, 0x54($4)
    /* 3AFAE4 004AFAE4 01006324 */  addiu      $3, $3, 0x1
    /* 3AFAE8 004AFAE8 540083AC */  sw         $3, 0x54($4)
    /* 3AFAEC 004AFAEC 2000BFDF */  ld         $31, 0x20($29)
    /* 3AFAF0 004AFAF0 1000B17B */  lq         $17, 0x10($29)
    /* 3AFAF4 004AFAF4 0000B07B */  lq         $16, 0x0($29)
    /* 3AFAF8 004AFAF8 3000BD27 */  addiu      $29, $29, 0x30
    /* 3AFAFC 004AFAFC 0800E003 */  jr         $31
    /* 3AFB00 004AFB00 00000000 */   nop
    /* 3AFB04 004AFB04 00000000 */  nop
    /* 3AFB08 004AFB08 00000000 */  nop
    /* 3AFB0C 004AFB0C 00000000 */  nop
.size func_004afaa0, 0x70
