.section .text
.set noat
.set noreorder
glabel func_0036dc60
    /* 26DC60 0036DC60 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 26DC64 0036DC64 4000BFFF */  sd         $31, 0x40($29)
    /* 26DC68 0036DC68 3000B27F */  sq         $18, 0x30($29)
    /* 26DC6C 0036DC6C 2000B17F */  sq         $17, 0x20($29)
    /* 26DC70 0036DC70 1000B07F */  sq         $16, 0x10($29)
    /* 26DC74 0036DC74 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 26DC78 0036DC78 2D908000 */  daddu      $18, $4, $0
    /* 26DC7C 0036DC7C 2D88A000 */  daddu      $17, $5, $0
    /* 26DC80 0036DC80 06650046 */  mov.s      $f20, $f12
    /* 26DC84 0036DC84 2D80C000 */  daddu      $16, $6, $0
    /* 26DC88 0036DC88 06002016 */  bnez       $17, .L0036DCA4
    /* 26DC8C 0036DC8C 00000000 */   nop
    /* 26DC90 0036DC90 6500043C */  lui        $4, %hi(D_0064E5B0)
    /* 26DC94 0036DC94 B0E58424 */  addiu      $4, $4, %lo(D_0064E5B0)
    /* 26DC98 0036DC98 D4000524 */  addiu      $5, $0, 0xD4
    /* 26DC9C 0036DC9C CCB5110C */  jal        func_0046d730
    /* 26DCA0 0036DCA0 00000000 */   nop
  .L0036DCA4:
    /* 26DCA4 0036DCA4 06000016 */  bnez       $16, .L0036DCC0
    /* 26DCA8 0036DCA8 00000000 */   nop
    /* 26DCAC 0036DCAC 6500043C */  lui        $4, %hi(D_0064E5B0)
    /* 26DCB0 0036DCB0 B0E58424 */  addiu      $4, $4, %lo(D_0064E5B0)
    /* 26DCB4 0036DCB4 D5000524 */  addiu      $5, $0, 0xD5
    /* 26DCB8 0036DCB8 CCB5110C */  jal        func_0046d730
    /* 26DCBC 0036DCBC 00000000 */   nop
  .L0036DCC0:
    /* 26DCC0 0036DCC0 2D204002 */  daddu      $4, $18, $0
    /* 26DCC4 0036DCC4 06A30046 */  mov.s      $f12, $f20
    /* 26DCC8 0036DCC8 E4A90D0C */  jal        func_0036a790
    /* 26DCCC 0036DCCC 00000000 */   nop
    /* 26DCD0 0036DCD0 2D204002 */  daddu      $4, $18, $0
    /* 26DCD4 0036DCD4 2D282002 */  daddu      $5, $17, $0
    /* 26DCD8 0036DCD8 06030046 */  mov.s      $f12, $f0
    /* 26DCDC 0036DCDC 2D300002 */  daddu      $6, $16, $0
    /* 26DCE0 0036DCE0 ACA90D0C */  jal        func_0036a6b0
    /* 26DCE4 0036DCE4 00000000 */   nop
    /* 26DCE8 0036DCE8 4000BFDF */  ld         $31, 0x40($29)
    /* 26DCEC 0036DCEC 3000B27B */  lq         $18, 0x30($29)
    /* 26DCF0 0036DCF0 2000B17B */  lq         $17, 0x20($29)
    /* 26DCF4 0036DCF4 1000B07B */  lq         $16, 0x10($29)
    /* 26DCF8 0036DCF8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 26DCFC 0036DCFC 5000BD27 */  addiu      $29, $29, 0x50
    /* 26DD00 0036DD00 0800E003 */  jr         $31
    /* 26DD04 0036DD04 00000000 */   nop
    /* 26DD08 0036DD08 00000000 */  nop
    /* 26DD0C 0036DD0C 00000000 */  nop
.size func_0036dc60, 0xb0
