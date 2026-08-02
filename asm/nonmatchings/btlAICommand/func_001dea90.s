.section .text
.set noat
.set noreorder
glabel func_001dea90
    /* DEA90 001DEA90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DEA94 001DEA94 1000BFFF */  sd         $31, 0x10($29)
    /* DEA98 001DEA98 0000B07F */  sq         $16, 0x0($29)
    /* DEA9C 001DEA9C 3000828C */  lw         $2, 0x30($4)
    /* DEAA0 001DEAA0 A4004394 */  lhu        $3, 0xA4($2)
    /* DEAA4 001DEAA4 80100300 */  sll        $2, $3, 2
    /* DEAA8 001DEAA8 21104300 */  addu       $2, $2, $3
    /* DEAAC 001DEAAC C0100200 */  sll        $2, $2, 3
    /* DEAB0 001DEAB0 21104300 */  addu       $2, $2, $3
    /* DEAB4 001DEAB4 80180200 */  sll        $3, $2, 2
    /* DEAB8 001DEAB8 D0B3828F */  lw         $2, -0x4C30($28)
    /* DEABC 001DEABC 21204300 */  addu       $4, $2, $3
    /* DEAC0 001DEAC0 2D300000 */  daddu      $6, $0, $0
    /* DEAC4 001DEAC4 2D380000 */  daddu      $7, $0, $0
    /* DEAC8 001DEAC8 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* DEACC 001DEACC 80100300 */  sll        $2, $3, 2
    /* DEAD0 001DEAD0 21104300 */  addu       $2, $2, $3
    /* DEAD4 001DEAD4 C0100200 */  sll        $2, $2, 3
    /* DEAD8 001DEAD8 21808200 */  addu       $16, $4, $2
    /* DEADC 001DEADC 09000010 */  b          .L001DEB04
    /* DEAE0 001DEAE0 00000000 */   nop
  .L001DEAE4:
    /* DEAE4 001DEAE4 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* DEAE8 001DEAE8 C0100200 */  sll        $2, $2, 3
    /* DEAEC 001DEAEC 21100202 */  addu       $2, $16, $2
    /* DEAF0 001DEAF0 2C004290 */  lbu        $2, 0x2C($2)
    /* DEAF4 001DEAF4 2110C200 */  addu       $2, $6, $2
    /* DEAF8 001DEAF8 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DEAFC 001DEAFC 0100E224 */  addiu      $2, $7, 0x1
    /* DEB00 001DEB00 FFFF4730 */  andi       $7, $2, 0xFFFF
  .L001DEB04:
    /* DEB04 001DEB04 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* DEB08 001DEB08 05004228 */  slti       $2, $2, 0x5
    /* DEB0C 001DEB0C F5FF4014 */  bnez       $2, .L001DEAE4
    /* DEB10 001DEB10 00000000 */   nop
    /* DEB14 001DEB14 FFFFC430 */  andi       $4, $6, 0xFFFF
    /* DEB18 001DEB18 04008014 */  bnez       $4, .L001DEB2C
    /* DEB1C 001DEB1C 00000000 */   nop
    /* DEB20 001DEB20 A8A28227 */  addiu      $2, $28, -0x5D58
    /* DEB24 001DEB24 1D000010 */  b          .L001DEB9C
    /* DEB28 001DEB28 00000000 */   nop
  .L001DEB2C:
    /* DEB2C 001DEB2C 5CC7080C */  jal        func_00231d70
    /* DEB30 001DEB30 00000000 */   nop
    /* DEB34 001DEB34 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* DEB38 001DEB38 2D380000 */  daddu      $7, $0, $0
    /* DEB3C 001DEB3C 2D300000 */  daddu      $6, $0, $0
    /* DEB40 001DEB40 11000010 */  b          .L001DEB88
    /* DEB44 001DEB44 00000000 */   nop
  .L001DEB48:
    /* DEB48 001DEB48 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* DEB4C 001DEB4C C0100200 */  sll        $2, $2, 3
    /* DEB50 001DEB50 21200202 */  addu       $4, $16, $2
    /* DEB54 001DEB54 2C008390 */  lbu        $3, 0x2C($4)
    /* DEB58 001DEB58 2110E300 */  addu       $2, $7, $3
    /* DEB5C 001DEB5C FFFF4730 */  andi       $7, $2, 0xFFFF
    /* DEB60 001DEB60 2A08E500 */  slt        $1, $7, $5
    /* DEB64 001DEB64 06002014 */  bnez       $1, .L001DEB80
    /* DEB68 001DEB68 00000000 */   nop
    /* DEB6C 001DEB6C 04006018 */  blez       $3, .L001DEB80
    /* DEB70 001DEB70 00000000 */   nop
    /* DEB74 001DEB74 2C008224 */  addiu      $2, $4, 0x2C
    /* DEB78 001DEB78 08000010 */  b          .L001DEB9C
    /* DEB7C 001DEB7C 00000000 */   nop
  .L001DEB80:
    /* DEB80 001DEB80 0100C224 */  addiu      $2, $6, 0x1
    /* DEB84 001DEB84 FFFF4630 */  andi       $6, $2, 0xFFFF
  .L001DEB88:
    /* DEB88 001DEB88 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* DEB8C 001DEB8C 05004228 */  slti       $2, $2, 0x5
    /* DEB90 001DEB90 EDFF4014 */  bnez       $2, .L001DEB48
    /* DEB94 001DEB94 00000000 */   nop
    /* DEB98 001DEB98 2D100000 */  daddu      $2, $0, $0
  .L001DEB9C:
    /* DEB9C 001DEB9C 1000BFDF */  ld         $31, 0x10($29)
    /* DEBA0 001DEBA0 0000B07B */  lq         $16, 0x0($29)
    /* DEBA4 001DEBA4 2000BD27 */  addiu      $29, $29, 0x20
    /* DEBA8 001DEBA8 0800E003 */  jr         $31
    /* DEBAC 001DEBAC 00000000 */   nop
.size func_001dea90, 0x120
