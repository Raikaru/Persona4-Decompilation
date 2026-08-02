.section .text
.set noat
.set noreorder
glabel func_0035dcc0
    /* 25DCC0 0035DCC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 25DCC4 0035DCC4 1000BFFF */  sd         $31, 0x10($29)
    /* 25DCC8 0035DCC8 0000B07F */  sq         $16, 0x0($29)
    /* 25DCCC 0035DCCC 01001024 */  addiu      $16, $0, 0x1
    /* 25DCD0 0035DCD0 2D280000 */  daddu      $5, $0, $0
    /* 25DCD4 0035DCD4 28008384 */  lh         $3, 0x28($4)
    /* 25DCD8 0035DCD8 0B000010 */  b          .L0035DD08
    /* 25DCDC 0035DCDC 00000000 */   nop
  .L0035DCE0:
    /* 25DCE0 0035DCE0 40100500 */  sll        $2, $5, 1
    /* 25DCE4 0035DCE4 21104500 */  addu       $2, $2, $5
    /* 25DCE8 0035DCE8 00110200 */  sll        $2, $2, 4
    /* 25DCEC 0035DCEC 21108200 */  addu       $2, $4, $2
    /* 25DCF0 0035DCF0 A400428C */  lw         $2, 0xA4($2)
    /* 25DCF4 0035DCF4 2A086200 */  slt        $1, $3, $2
    /* 25DCF8 0035DCF8 02002010 */  beqz       $1, .L0035DD04
    /* 25DCFC 0035DCFC 00000000 */   nop
    /* 25DD00 0035DD00 2D800000 */  daddu      $16, $0, $0
  .L0035DD04:
    /* 25DD04 0035DD04 0100A524 */  addiu      $5, $5, 0x1
  .L0035DD08:
    /* 25DD08 0035DD08 1200A228 */  slti       $2, $5, 0x12
    /* 25DD0C 0035DD0C F4FF4014 */  bnez       $2, .L0035DCE0
    /* 25DD10 0035DD10 00000000 */   nop
    /* 25DD14 0035DD14 84300D0C */  jal        func_0034c210
    /* 25DD18 0035DD18 00000000 */   nop
    /* 25DD1C 0035DD1C 24100202 */  and        $2, $16, $2
    /* 25DD20 0035DD20 1000BFDF */  ld         $31, 0x10($29)
    /* 25DD24 0035DD24 0000B07B */  lq         $16, 0x0($29)
    /* 25DD28 0035DD28 2000BD27 */  addiu      $29, $29, 0x20
    /* 25DD2C 0035DD2C 0800E003 */  jr         $31
    /* 25DD30 0035DD30 00000000 */   nop
    /* 25DD34 0035DD34 00000000 */  nop
    /* 25DD38 0035DD38 00000000 */  nop
    /* 25DD3C 0035DD3C 00000000 */  nop
.size func_0035dcc0, 0x80
