.section .text
.set noat
.set noreorder
glabel func_0011dc50
    /* 1DC50 0011DC50 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1DC54 0011DC54 2000BFFF */  sd         $31, 0x20($29)
    /* 1DC58 0011DC58 1000B07F */  sq         $16, 0x10($29)
    /* 1DC5C 0011DC5C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1DC60 0011DC60 3800908C */  lw         $16, 0x38($4)
    /* 1DC64 0011DC64 F878040C */  jal        func_0011e3e0
    /* 1DC68 0011DC68 00000000 */   nop
    /* 1DC6C 0011DC6C 30004010 */  beqz       $2, .L0011DD30
    /* 1DC70 0011DC70 00000000 */   nop
    /* 1DC74 0011DC74 0400038E */  lw         $3, 0x4($16)
    /* 1DC78 0011DC78 2D006010 */  beqz       $3, .L0011DD30
    /* 1DC7C 0011DC7C 00000000 */   nop
    /* 1DC80 0011DC80 1000038E */  lw         $3, 0x10($16)
    /* 1DC84 0011DC84 00008344 */  mtc1       $3, $f0
    /* 1DC88 0011DC88 00000000 */  nop
    /* 1DC8C 0011DC8C 20008046 */  cvt.s.w    $f0, $f0
    /* 1DC90 0011DC90 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1DC94 0011DC94 00108244 */  mtc1       $2, $f2
    /* 1DC98 0011DC98 00000000 */  nop
    /* 1DC9C 0011DC9C 34000246 */  c.lt.s     $f0, $f2
    /* 1DCA0 0011DCA0 17000045 */  bc1f       .L0011DD00
    /* 1DCA4 0011DCA4 00000000 */   nop
    /* 1DCA8 0011DCA8 01006224 */  addiu      $2, $3, 0x1
    /* 1DCAC 0011DCAC 100002AE */  sw         $2, 0x10($16)
    /* 1DCB0 0011DCB0 200014C6 */  lwc1       $f20, 0x20($16)
    /* 1DCB4 0011DCB4 100000C6 */  lwc1       $f0, 0x10($16)
    /* 1DCB8 0011DCB8 60008046 */  cvt.s.w    $f1, $f0
    /* 1DCBC 0011DCBC 948080C7 */  lwc1       $f0, -0x7F6C($28)
    /* 1DCC0 0011DCC0 02000146 */  mul.s      $f0, $f0, $f1
    /* 1DCC4 0011DCC4 03030246 */  div.s      $f12, $f0, $f2
    /* 1DCC8 0011DCC8 00000000 */  nop
    /* 1DCCC 0011DCCC 00000000 */  nop
    /* 1DCD0 0011DCD0 00000000 */  nop
    /* 1DCD4 0011DCD4 EC2D110C */  jal        func_0044b7b0
    /* 1DCD8 0011DCD8 00000000 */   nop
    /* 1DCDC 0011DCDC 300001C6 */  lwc1       $f1, 0x30($16)
    /* 1DCE0 0011DCE0 81081446 */  sub.s      $f2, $f1, $f20
    /* 1DCE4 0011DCE4 00088044 */  mtc1       $0, $f1
    /* 1DCE8 0011DCE8 00000000 */  nop
    /* 1DCEC 0011DCEC 18081446 */  adda.s     $f1, $f20
    /* 1DCF0 0011DCF0 1C100046 */  madd.s     $f0, $f2, $f0
    /* 1DCF4 0011DCF4 280000E6 */  swc1       $f0, 0x28($16)
    /* 1DCF8 0011DCF8 03000010 */  b          .L0011DD08
    /* 1DCFC 0011DCFC 00000000 */   nop
  .L0011DD00:
    /* 1DD00 0011DD00 300000C6 */  lwc1       $f0, 0x30($16)
    /* 1DD04 0011DD04 280000E6 */  swc1       $f0, 0x28($16)
  .L0011DD08:
    /* 1DD08 0011DD08 0800048E */  lw         $4, 0x8($16)
    /* 1DD0C 0011DD0C 18000CC6 */  lwc1       $f12, 0x18($16)
    /* 1DD10 0011DD10 2D288000 */  daddu      $5, $4, $0
    /* 1DD14 0011DD14 28000DC6 */  lwc1       $f13, 0x28($16)
    /* 1DD18 0011DD18 2C000EC6 */  lwc1       $f14, 0x2C($16)
    /* 1DD1C 0011DD1C 00020624 */  addiu      $6, $0, 0x200
    /* 1DD20 0011DD20 2D38C000 */  daddu      $7, $6, $0
    /* 1DD24 0011DD24 5000088E */  lw         $8, 0x50($16)
    /* 1DD28 0011DD28 6C75040C */  jal        func_0011d5b0
    /* 1DD2C 0011DD2C 00000000 */   nop
  .L0011DD30:
    /* 1DD30 0011DD30 2000BFDF */  ld         $31, 0x20($29)
    /* 1DD34 0011DD34 1000B07B */  lq         $16, 0x10($29)
    /* 1DD38 0011DD38 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1DD3C 0011DD3C 3000BD27 */  addiu      $29, $29, 0x30
    /* 1DD40 0011DD40 0800E003 */  jr         $31
    /* 1DD44 0011DD44 00000000 */   nop
    /* 1DD48 0011DD48 00000000 */  nop
    /* 1DD4C 0011DD4C 00000000 */  nop
.size func_0011dc50, 0x100
