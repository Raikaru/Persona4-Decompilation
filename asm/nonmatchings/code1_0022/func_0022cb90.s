.section .text
.set noat
.set noreorder
glabel func_0022cb90
    /* 12CB90 0022CB90 A2008390 */  lbu        $3, 0xA2($4)
    /* 12CB94 0022CB94 01000224 */  addiu      $2, $0, 0x1
    /* 12CB98 0022CB98 04006210 */  beq        $3, $2, .L0022CBAC
    /* 12CB9C 0022CB9C 00000000 */   nop
    /* 12CBA0 0022CBA0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 12CBA4 0022CBA4 38000010 */  b          .L0022CC88
    /* 12CBA8 0022CBA8 00000000 */   nop
  .L0022CBAC:
    /* 12CBAC 0022CBAC ACB3878F */  lw         $7, -0x4C54($28)
    /* 12CBB0 0022CBB0 300CE68C */  lw         $6, 0xC30($7)
    /* 12CBB4 0022CBB4 0400C014 */  bnez       $6, .L0022CBC8
    /* 12CBB8 0022CBB8 00000000 */   nop
    /* 12CBBC 0022CBBC FFFF0224 */  addiu      $2, $0, -0x1
    /* 12CBC0 0022CBC0 31000010 */  b          .L0022CC88
    /* 12CBC4 0022CBC4 00000000 */   nop
  .L0022CBC8:
    /* 12CBC8 0022CBC8 A4008394 */  lhu        $3, 0xA4($4)
    /* 12CBCC 0022CBCC 0F010224 */  addiu      $2, $0, 0x10F
    /* 12CBD0 0022CBD0 11006210 */  beq        $3, $2, .L0022CC18
    /* 12CBD4 0022CBD4 00000000 */   nop
    /* 12CBD8 0022CBD8 11010224 */  addiu      $2, $0, 0x111
    /* 12CBDC 0022CBDC 09006210 */  beq        $3, $2, .L0022CC04
    /* 12CBE0 0022CBE0 00000000 */   nop
    /* 12CBE4 0022CBE4 10010224 */  addiu      $2, $0, 0x110
    /* 12CBE8 0022CBE8 06006210 */  beq        $3, $2, .L0022CC04
    /* 12CBEC 0022CBEC 00000000 */   nop
    /* 12CBF0 0022CBF0 0D010224 */  addiu      $2, $0, 0x10D
    /* 12CBF4 0022CBF4 03006210 */  beq        $3, $2, .L0022CC04
    /* 12CBF8 0022CBF8 00000000 */   nop
    /* 12CBFC 0022CBFC 18000010 */  b          .L0022CC60
    /* 12CC00 0022CC00 00000000 */   nop
  .L0022CC04:
    /* 12CC04 0022CC04 FFFFA230 */  andi       $2, $5, 0xFFFF
    /* 12CC08 0022CC08 2110C200 */  addu       $2, $6, $2
    /* 12CC0C 0022CC0C 00004290 */  lbu        $2, 0x0($2)
    /* 12CC10 0022CC10 1D000010 */  b          .L0022CC88
    /* 12CC14 0022CC14 00000000 */   nop
  .L0022CC18:
    /* 12CC18 0022CC18 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* 12CC1C 0022CC1C 04006010 */  beqz       $3, .L0022CC30
    /* 12CC20 0022CC20 00000000 */   nop
    /* 12CC24 0022CC24 12000224 */  addiu      $2, $0, 0x12
    /* 12CC28 0022CC28 08006214 */  bne        $3, $2, .L0022CC4C
    /* 12CC2C 0022CC2C 00000000 */   nop
  .L0022CC30:
    /* 12CC30 0022CC30 340CE384 */  lh         $3, 0xC34($7)
    /* 12CC34 0022CC34 03000224 */  addiu      $2, $0, 0x3
    /* 12CC38 0022CC38 04006210 */  beq        $3, $2, .L0022CC4C
    /* 12CC3C 0022CC3C 00000000 */   nop
    /* 12CC40 0022CC40 0B000224 */  addiu      $2, $0, 0xB
    /* 12CC44 0022CC44 10000010 */  b          .L0022CC88
    /* 12CC48 0022CC48 00000000 */   nop
  .L0022CC4C:
    /* 12CC4C 0022CC4C FFFFA230 */  andi       $2, $5, 0xFFFF
    /* 12CC50 0022CC50 2110C200 */  addu       $2, $6, $2
    /* 12CC54 0022CC54 00004290 */  lbu        $2, 0x0($2)
    /* 12CC58 0022CC58 0B000010 */  b          .L0022CC88
    /* 12CC5C 0022CC5C 00000000 */   nop
  .L0022CC60:
    /* 12CC60 0022CC60 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* 12CC64 0022CC64 100CE224 */  addiu      $2, $7, 0xC10
    /* 12CC68 0022CC68 21104300 */  addu       $2, $2, $3
    /* 12CC6C 0022CC6C 00004280 */  lb         $2, 0x0($2)
    /* 12CC70 0022CC70 03004004 */  bltz       $2, .L0022CC80
    /* 12CC74 0022CC74 00000000 */   nop
    /* 12CC78 0022CC78 03000010 */  b          .L0022CC88
    /* 12CC7C 0022CC7C 00000000 */   nop
  .L0022CC80:
    /* 12CC80 0022CC80 2110C300 */  addu       $2, $6, $3
    /* 12CC84 0022CC84 00004290 */  lbu        $2, 0x0($2)
  .L0022CC88:
    /* 12CC88 0022CC88 0800E003 */  jr         $31
    /* 12CC8C 0022CC8C 00000000 */   nop
.size func_0022cb90, 0x100
