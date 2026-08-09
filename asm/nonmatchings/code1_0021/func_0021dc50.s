.section .text
.set noat
.set noreorder
glabel func_0021dc50
    /* 11DC50 0021DC50 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 11DC54 0021DC54 2000BFFF */  sd         $31, 0x20($29)
    /* 11DC58 0021DC58 1000B07F */  sq         $16, 0x10($29)
    /* 11DC5C 0021DC5C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 11DC60 0021DC60 2D80A000 */  daddu      $16, $5, $0
    /* 11DC64 0021DC64 D404080C */  jal        func_00201350
    /* 11DC68 0021DC68 00000000 */   nop
    /* 11DC6C 0021DC6C 000000C6 */  lwc1       $f0, 0x0($16)
    /* 11DC70 0021DC70 60008046 */  cvt.s.w    $f1, $f0
    /* 11DC74 0021DC74 4041023C */  lui        $2, (0x41400000 >> 16)
    /* 11DC78 0021DC78 00008244 */  mtc1       $2, $f0
    /* 11DC7C 0021DC7C 00000000 */  nop
    /* 11DC80 0021DC80 030D0046 */  div.s      $f20, $f1, $f0
    /* 11DC84 0021DC84 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 11DC88 0021DC88 00008244 */  mtc1       $2, $f0
    /* 11DC8C 0021DC8C 00000000 */  nop
    /* 11DC90 0021DC90 36A00046 */  c.le.s     $f20, $f0
    /* 11DC94 0021DC94 02000145 */  bc1t       .L0021DCA0
    /* 11DC98 0021DC98 00000000 */   nop
    /* 11DC9C 0021DC9C 06050046 */  mov.s      $f20, $f0
  .L0021DCA0:
    /* 11DCA0 0021DCA0 3800A0AF */  sw         $0, 0x38($29)
    /* 11DCA4 0021DCA4 FAC3023C */  lui        $2, (0xC3FA0000 >> 16)
    /* 11DCA8 0021DCA8 3C00A2AF */  sw         $2, 0x3C($29)
    /* 11DCAC 0021DCAC 7C838CC7 */  lwc1       $f12, -0x7C84($28)
    /* 11DCB0 0021DCB0 EC2D110C */  jal        func_0044b7b0
    /* 11DCB4 0021DCB4 00000000 */   nop
    /* 11DCB8 0021DCB8 4844023C */  lui        $2, (0x44480000 >> 16)
    /* 11DCBC 0021DCBC 00088244 */  mtc1       $2, $f1
    /* 11DCC0 0021DCC0 00000000 */  nop
    /* 11DCC4 0021DCC4 82080046 */  mul.s      $f2, $f1, $f0
    /* 11DCC8 0021DCC8 3800A1C7 */  lwc1       $f1, 0x38($29)
    /* 11DCCC 0021DCCC 00008044 */  mtc1       $0, $f0
    /* 11DCD0 0021DCD0 00000000 */  nop
    /* 11DCD4 0021DCD4 18000146 */  adda.s     $f0, $f1
    /* 11DCD8 0021DCD8 1CA00246 */  madd.s     $f0, $f20, $f2
    /* 11DCDC 0021DCDC 3800A0E7 */  swc1       $f0, 0x38($29)
    /* 11DCE0 0021DCE0 7C838CC7 */  lwc1       $f12, -0x7C84($28)
    /* 11DCE4 0021DCE4 842D110C */  jal        func_0044b610
    /* 11DCE8 0021DCE8 00000000 */   nop
    /* 11DCEC 0021DCEC 4844023C */  lui        $2, (0x44480000 >> 16)
    /* 11DCF0 0021DCF0 00088244 */  mtc1       $2, $f1
    /* 11DCF4 0021DCF4 00000000 */  nop
    /* 11DCF8 0021DCF8 42080046 */  mul.s      $f1, $f1, $f0
    /* 11DCFC 0021DCFC 3C00A0C7 */  lwc1       $f0, 0x3C($29)
    /* 11DD00 0021DD00 00608044 */  mtc1       $0, $f12
    /* 11DD04 0021DD04 00000000 */  nop
    /* 11DD08 0021DD08 18600046 */  adda.s     $f12, $f0
    /* 11DD0C 0021DD0C 1CA00146 */  madd.s     $f0, $f20, $f1
    /* 11DD10 0021DD10 3C00A0E7 */  swc1       $f0, 0x3C($29)
    /* 11DD14 0021DD14 DC050224 */  addiu      $2, $0, 0x5DC
    /* 11DD18 0021DD18 00008244 */  mtc1       $2, $f0
    /* 11DD1C 0021DD1C 00000000 */  nop
    /* 11DD20 0021DD20 60038046 */  cvt.s.w    $f13, $f0
    /* 11DD24 0021DD24 7A44023C */  lui        $2, (0x447A0000 >> 16)
    /* 11DD28 0021DD28 00708244 */  mtc1       $2, $f14
    /* 11DD2C 0021DD2C 3800A4DF */  ld         $4, 0x38($29)
    /* 11DD30 0021DD30 FF000524 */  addiu      $5, $0, 0xFF
    /* 11DD34 0021DD34 78838FC7 */  lwc1       $f15, -0x7C88($28)
    /* 11DD38 0021DD38 2D300000 */  daddu      $6, $0, $0
    /* 11DD3C 0021DD3C 24930D0C */  jal        func_00364c90
    /* 11DD40 0021DD40 00000000 */   nop
    /* 11DD44 0021DD44 2000BFDF */  ld         $31, 0x20($29)
    /* 11DD48 0021DD48 1000B07B */  lq         $16, 0x10($29)
    /* 11DD4C 0021DD4C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 11DD50 0021DD50 4000BD27 */  addiu      $29, $29, 0x40
    /* 11DD54 0021DD54 0800E003 */  jr         $31
    /* 11DD58 0021DD58 00000000 */   nop
    /* 11DD5C 0021DD5C 00000000 */  nop
.size func_0021dc50, 0x110
