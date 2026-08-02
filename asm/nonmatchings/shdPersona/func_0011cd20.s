.section .text
.set noat
.set noreorder
glabel func_0011cd20
    /* 1CD20 0011CD20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1CD24 0011CD24 1000BFFF */  sd         $31, 0x10($29)
    /* 1CD28 0011CD28 0000B07F */  sq         $16, 0x0($29)
    /* 1CD2C 0011CD2C 2D808000 */  daddu      $16, $4, $0
    /* 1CD30 0011CD30 18058284 */  lh         $2, 0x518($4)
    /* 1CD34 0011CD34 00008244 */  mtc1       $2, $f0
    /* 1CD38 0011CD38 00000000 */  nop
    /* 1CD3C 0011CD3C 60008046 */  cvt.s.w    $f1, $f0
    /* 1CD40 0011CD40 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* 1CD44 0011CD44 00008244 */  mtc1       $2, $f0
    /* 1CD48 0011CD48 00000000 */  nop
    /* 1CD4C 0011CD4C 36080046 */  c.le.s     $f1, $f0
    /* 1CD50 0011CD50 08000145 */  bc1t       .L0011CD74
    /* 1CD54 0011CD54 00000000 */   nop
    /* 1CD58 0011CD58 3405038E */  lw         $3, 0x534($16)
    /* 1CD5C 0011CD5C FFFF023C */  lui        $2, (0xFFFF7FFF >> 16)
    /* 1CD60 0011CD60 FF7F4234 */  ori        $2, $2, (0xFFFF7FFF & 0xFFFF)
    /* 1CD64 0011CD64 24106200 */  and        $2, $3, $2
    /* 1CD68 0011CD68 340502AE */  sw         $2, 0x534($16)
    /* 1CD6C 0011CD6C 05000010 */  b          .L0011CD84
    /* 1CD70 0011CD70 00000000 */   nop
  .L0011CD74:
    /* 1CD74 0011CD74 36080046 */  c.le.s     $f1, $f0
    /* 1CD78 0011CD78 02000145 */  bc1t       .L0011CD84
    /* 1CD7C 0011CD7C 00000000 */   nop
    /* 1CD80 0011CD80 46000046 */  mov.s      $f1, $f0
  .L0011CD84:
    /* 1CD84 0011CD84 FC8280C7 */  lwc1       $f0, -0x7D04($28)
    /* 1CD88 0011CD88 42000146 */  mul.s      $f1, $f0, $f1
    /* 1CD8C 0011CD8C C841023C */  lui        $2, (0x41C80000 >> 16)
    /* 1CD90 0011CD90 00008244 */  mtc1       $2, $f0
    /* 1CD94 0011CD94 00000000 */  nop
    /* 1CD98 0011CD98 030B0046 */  div.s      $f12, $f1, $f0
    /* 1CD9C 0011CD9C 00000000 */  nop
    /* 1CDA0 0011CDA0 00000000 */  nop
    /* 1CDA4 0011CDA4 00000000 */  nop
    /* 1CDA8 0011CDA8 EC2D110C */  jal        func_0044b7b0
    /* 1CDAC 0011CDAC 00000000 */   nop
    /* 1CDB0 0011CDB0 1C0500E6 */  swc1       $f0, 0x51C($16)
    /* 1CDB4 0011CDB4 1000BFDF */  ld         $31, 0x10($29)
    /* 1CDB8 0011CDB8 0000B07B */  lq         $16, 0x0($29)
    /* 1CDBC 0011CDBC 2000BD27 */  addiu      $29, $29, 0x20
    /* 1CDC0 0011CDC0 0800E003 */  jr         $31
    /* 1CDC4 0011CDC4 00000000 */   nop
    /* 1CDC8 0011CDC8 00000000 */  nop
    /* 1CDCC 0011CDCC 00000000 */  nop
.size func_0011cd20, 0xb0
