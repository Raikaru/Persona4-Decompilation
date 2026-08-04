.section .text
.set noat
.set noreorder
glabel func_0035aec0
    /* 25AEC0 0035AEC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 25AEC4 0035AEC4 1000BFFF */  sd         $31, 0x10($29)
    /* 25AEC8 0035AEC8 0000B07F */  sq         $16, 0x0($29)
    /* 25AECC 0035AECC 3800908C */  lw         $16, 0x38($4)
    /* 25AED0 0035AED0 2C00028E */  lw         $2, 0x2C($16)
    /* 25AED4 0035AED4 08004014 */  bnez       $2, .L0035AEF8
    /* 25AED8 0035AED8 00000000 */   nop
    /* 25AEDC 0035AEDC 20000282 */  lb         $2, 0x20($16)
    /* 25AEE0 0035AEE0 05004010 */  beqz       $2, .L0035AEF8
    /* 25AEE4 0035AEE4 00000000 */   nop
    /* 25AEE8 0035AEE8 30000426 */  addiu      $4, $16, 0x30
    /* 25AEEC 0035AEEC 0C520D0C */  jal        func_00354830
    /* 25AEF0 0035AEF0 00000000 */   nop
    /* 25AEF4 0035AEF4 2C0002AE */  sw         $2, 0x2C($16)
  .L0035AEF8:
    /* 25AEF8 0035AEF8 2D100000 */  daddu      $2, $0, $0
    /* 25AEFC 0035AEFC 1000BFDF */  ld         $31, 0x10($29)
    /* 25AF00 0035AF00 0000B07B */  lq         $16, 0x0($29)
    /* 25AF04 0035AF04 2000BD27 */  addiu      $29, $29, 0x20
    /* 25AF08 0035AF08 0800E003 */  jr         $31
    /* 25AF0C 0035AF0C 00000000 */   nop
.size func_0035aec0, 0x50
