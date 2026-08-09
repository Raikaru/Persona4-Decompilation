.section .text
.set noat
.set noreorder
glabel func_0042cb88
    /* 32CB88 0042CB88 0010033C */  lui        $3, (0x10001000 >> 16)
    /* 32CB8C 0042CB8C 7100043C */  lui        $4, %hi(D_0070DC88)
    /* 32CB90 0042CB90 00106334 */  ori        $3, $3, (0x10001000 & 0xFFFF)
    /* 32CB94 0042CB94 0000629C */  lwu        $2, 0x0($3)
    /* 32CB98 0042CB98 1000688C */  lw         $8, 0x10($3)
    /* 32CB9C 0042CB9C 88DC8ADC */  ld         $10, %lo(D_0070DC88)($4)
    /* 32CBA0 0042CBA0 00080931 */  andi       $9, $8, 0x800
    /* 32CBA4 0042CBA4 03002011 */  beqz       $9, .L0042CBB4
    /* 32CBA8 0042CBA8 02000924 */   addiu     $9, $0, 0x2
    /* 32CBAC 0042CBAC 0000629C */  lwu        $2, 0x0($3)
    /* 32CBB0 0042CBB0 01004A65 */  daddiu     $10, $10, 0x1
  .L0042CBB4:
    /* 32CBB4 0042CBB4 03000831 */  andi       $8, $8, 0x3
    /* 32CBB8 0042CBB8 38540A00 */  dsll       $10, $10, 16
    /* 32CBBC 0042CBBC 0A480800 */  movz       $9, $0, $8
    /* 32CBC0 0042CBC0 25104A00 */  or         $2, $2, $10
    /* 32CBC4 0042CBC4 14480901 */  dsllv      $9, $9, $8
    /* 32CBC8 0042CBC8 14102201 */  dsllv      $2, $2, $9
    /* 32CBCC 0042CBCC 0800E003 */  jr         $31
    /* 32CBD0 0042CBD0 00000000 */   nop
    /* 32CBD4 0042CBD4 00000000 */  nop
.size func_0042cb88, 0x50
