.section .text
.set noat
.set noreorder
glabel func_001bdd80
    /* BDD80 001BDD80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* BDD84 001BDD84 2000BFFF */  sd         $31, 0x20($29)
    /* BDD88 001BDD88 1000B17F */  sq         $17, 0x10($29)
    /* BDD8C 001BDD8C 0000B07F */  sq         $16, 0x0($29)
    /* BDD90 001BDD90 2D888000 */  daddu      $17, $4, $0
    /* BDD94 001BDD94 2D80A000 */  daddu      $16, $5, $0
    /* BDD98 001BDD98 E000828C */  lw         $2, 0xE0($4)
    /* BDD9C 001BDD9C 3800428C */  lw         $2, 0x38($2)
    /* BDDA0 001BDDA0 340182AC */  sw         $2, 0x134($4)
    /* BDDA4 001BDDA4 E000828C */  lw         $2, 0xE0($4)
    /* BDDA8 001BDDA8 6A004294 */  lhu        $2, 0x6A($2)
    /* BDDAC 001BDDAC 400182A4 */  sh         $2, 0x140($4)
    /* BDDB0 001BDDB0 E000858C */  lw         $5, 0xE0($4)
    /* BDDB4 001BDDB4 FFFFC230 */  andi       $2, $6, 0xFFFF
    /* BDDB8 001BDDB8 01004234 */  ori        $2, $2, 0x1
    /* BDDBC 001BDDBC FFFF4830 */  andi       $8, $2, 0xFFFF
    /* BDDC0 001BDDC0 EC002426 */  addiu      $4, $17, 0xEC
    /* BDDC4 001BDDC4 3800A68C */  lw         $6, 0x38($5)
    /* BDDC8 001BDDC8 2D380002 */  daddu      $7, $16, $0
    /* BDDCC 001BDDCC 3C44070C */  jal        func_001d10f0
    /* BDDD0 001BDDD0 00000000 */   nop
    /* BDDD4 001BDDD4 01000292 */  lbu        $2, 0x1($16)
    /* BDDD8 001BDDD8 420122A6 */  sh         $2, 0x142($17)
    /* BDDDC 001BDDDC EC002426 */  addiu      $4, $17, 0xEC
    /* BDDE0 001BDDE0 8044070C */  jal        func_001d1200
    /* BDDE4 001BDDE4 00000000 */   nop
    /* BDDE8 001BDDE8 29004010 */  beqz       $2, .L001BDE90
    /* BDDEC 001BDDEC 00000000 */   nop
    /* BDDF0 001BDDF0 1C004294 */  lhu        $2, 0x1C($2)
    /* BDDF4 001BDDF4 01000724 */  addiu      $7, $0, 0x1
    /* BDDF8 001BDDF8 16004714 */  bne        $2, $7, .L001BDE54
    /* BDDFC 001BDDFC 00000000 */   nop
    /* BDE00 001BDE00 42012296 */  lhu        $2, 0x142($17)
    /* BDE04 001BDE04 02004230 */  andi       $2, $2, 0x2
    /* BDE08 001BDE08 12004014 */  bnez       $2, .L001BDE54
    /* BDE0C 001BDE0C 00000000 */   nop
    /* BDE10 001BDE10 00608044 */  mtc1       $0, $f12
    /* BDE14 001BDE14 E000248E */  lw         $4, 0xE0($17)
    /* BDE18 001BDE18 2D280000 */  daddu      $5, $0, $0
    /* BDE1C 001BDE1C 2D300000 */  daddu      $6, $0, $0
    /* BDE20 001BDE20 50F3060C */  jal        func_001bcd40
    /* BDE24 001BDE24 00000000 */   nop
    /* BDE28 001BDE28 00608044 */  mtc1       $0, $f12
    /* BDE2C 001BDE2C E000248E */  lw         $4, 0xE0($17)
    /* BDE30 001BDE30 2D280000 */  daddu      $5, $0, $0
    /* BDE34 001BDE34 2D300000 */  daddu      $6, $0, $0
    /* BDE38 001BDE38 08000724 */  addiu      $7, $0, 0x8
    /* BDE3C 001BDE3C 50F3060C */  jal        func_001bcd40
    /* BDE40 001BDE40 00000000 */   nop
    /* BDE44 001BDE44 01000324 */  addiu      $3, $0, 0x1
    /* BDE48 001BDE48 380123AE */  sw         $3, 0x138($17)
    /* BDE4C 001BDE4C 10000010 */  b          .L001BDE90
    /* BDE50 001BDE50 00000000 */   nop
  .L001BDE54:
    /* BDE54 001BDE54 00608044 */  mtc1       $0, $f12
    /* BDE58 001BDE58 42012296 */  lhu        $2, 0x142($17)
    /* BDE5C 001BDE5C 04004230 */  andi       $2, $2, 0x4
    /* BDE60 001BDE60 04004010 */  beqz       $2, .L001BDE74
    /* BDE64 001BDE64 00000000 */   nop
    /* BDE68 001BDE68 18000724 */  addiu      $7, $0, 0x18
    /* BDE6C 001BDE6C 02000010 */  b          .L001BDE78
    /* BDE70 001BDE70 00000000 */   nop
  .L001BDE74:
    /* BDE74 001BDE74 0A000724 */  addiu      $7, $0, 0xA
  .L001BDE78:
    /* BDE78 001BDE78 E000248E */  lw         $4, 0xE0($17)
    /* BDE7C 001BDE7C 2D280000 */  daddu      $5, $0, $0
    /* BDE80 001BDE80 2D300000 */  daddu      $6, $0, $0
    /* BDE84 001BDE84 50F3060C */  jal        func_001bcd40
    /* BDE88 001BDE88 00000000 */   nop
    /* BDE8C 001BDE8C 380120AE */  sw         $0, 0x138($17)
  .L001BDE90:
    /* BDE90 001BDE90 3C0120AE */  sw         $0, 0x13C($17)
    /* BDE94 001BDE94 2000BFDF */  ld         $31, 0x20($29)
    /* BDE98 001BDE98 1000B17B */  lq         $17, 0x10($29)
    /* BDE9C 001BDE9C 0000B07B */  lq         $16, 0x0($29)
    /* BDEA0 001BDEA0 3000BD27 */  addiu      $29, $29, 0x30
    /* BDEA4 001BDEA4 0800E003 */  jr         $31
    /* BDEA8 001BDEA8 00000000 */   nop
    /* BDEAC 001BDEAC 00000000 */  nop
.size func_001bdd80, 0x130
