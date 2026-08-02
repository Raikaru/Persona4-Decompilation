.section .text
.set noat
.set noreorder
glabel func_0011bdc0
    /* 1BDC0 0011BDC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BDC4 0011BDC4 1000BFFF */  sd         $31, 0x10($29)
    /* 1BDC8 0011BDC8 0000B07F */  sq         $16, 0x0($29)
    /* 1BDCC 0011BDCC 3800908C */  lw         $16, 0x38($4)
    /* 1BDD0 0011BDD0 3405038E */  lw         $3, 0x534($16)
    /* 1BDD4 0011BDD4 02006330 */  andi       $3, $3, 0x2
    /* 1BDD8 0011BDD8 48006014 */  bnez       $3, .L0011BEFC
    /* 1BDDC 0011BDDC 00000000 */   nop
    /* 1BDE0 0011BDE0 2D200002 */  daddu      $4, $16, $0
    /* 1BDE4 0011BDE4 906E040C */  jal        func_0011ba40
    /* 1BDE8 0011BDE8 00000000 */   nop
    /* 1BDEC 0011BDEC 080500A6 */  sh         $0, 0x508($16)
    /* 1BDF0 0011BDF0 05050292 */  lbu        $2, 0x505($16)
    /* 1BDF4 0011BDF4 040502A2 */  sb         $2, 0x504($16)
    /* 1BDF8 0011BDF8 FF000224 */  addiu      $2, $0, 0xFF
    /* 1BDFC 0011BDFC 060502A2 */  sb         $2, 0x506($16)
    /* 1BE00 0011BE00 2D200002 */  daddu      $4, $16, $0
    /* 1BE04 0011BE04 04000524 */  addiu      $5, $0, 0x4
    /* 1BE08 0011BE08 A86A040C */  jal        func_0011aaa0
    /* 1BE0C 0011BE0C 00000000 */   nop
    /* 1BE10 0011BE10 FC0401C6 */  lwc1       $f1, 0x4FC($16)
    /* 1BE14 0011BE14 0343023C */  lui        $2, (0x43030000 >> 16)
    /* 1BE18 0011BE18 00008244 */  mtc1       $2, $f0
    /* 1BE1C 0011BE1C 00000000 */  nop
    /* 1BE20 0011BE20 00000146 */  add.s      $f0, $f0, $f1
    /* 1BE24 0011BE24 2000A0E7 */  swc1       $f0, 0x20($29)
    /* 1BE28 0011BE28 000501C6 */  lwc1       $f1, 0x500($16)
    /* 1BE2C 0011BE2C 6CC2023C */  lui        $2, (0xC26C0000 >> 16)
    /* 1BE30 0011BE30 00008244 */  mtc1       $2, $f0
    /* 1BE34 0011BE34 00000000 */  nop
    /* 1BE38 0011BE38 00000146 */  add.s      $f0, $f0, $f1
    /* 1BE3C 0011BE3C 2400A0E7 */  swc1       $f0, 0x24($29)
    /* 1BE40 0011BE40 F804048E */  lw         $4, 0x4F8($16)
    /* 1BE44 0011BE44 2800A527 */  addiu      $5, $29, 0x28
    /* 1BE48 0011BE48 A077040C */  jal        func_0011de80
    /* 1BE4C 0011BE4C 00000000 */   nop
    /* 1BE50 0011BE50 00088044 */  mtc1       $0, $f1
    /* 1BE54 0011BE54 00000000 */  nop
    /* 1BE58 0011BE58 32080046 */  c.eq.s     $f1, $f0
    /* 1BE5C 0011BE5C 07000145 */  bc1t       .L0011BE7C
    /* 1BE60 0011BE60 00000000 */   nop
    /* 1BE64 0011BE64 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1BE68 0011BE68 00088244 */  mtc1       $2, $f1
    /* 1BE6C 0011BE6C 00000000 */  nop
    /* 1BE70 0011BE70 32080046 */  c.eq.s     $f1, $f0
    /* 1BE74 0011BE74 18000045 */  bc1f       .L0011BED8
    /* 1BE78 0011BE78 00000000 */   nop
  .L0011BE7C:
    /* 1BE7C 0011BE7C 03030224 */  addiu      $2, $0, 0x303
    /* 1BE80 0011BE80 00008244 */  mtc1       $2, $f0
    /* 1BE84 0011BE84 00000000 */  nop
    /* 1BE88 0011BE88 60008046 */  cvt.s.w    $f1, $f0
    /* 1BE8C 0011BE8C FC0400C6 */  lwc1       $f0, 0x4FC($16)
    /* 1BE90 0011BE90 00080046 */  add.s      $f0, $f1, $f0
    /* 1BE94 0011BE94 2800A0E7 */  swc1       $f0, 0x28($29)
    /* 1BE98 0011BE98 000501C6 */  lwc1       $f1, 0x500($16)
    /* 1BE9C 0011BE9C 6CC2023C */  lui        $2, (0xC26C0000 >> 16)
    /* 1BEA0 0011BEA0 00008244 */  mtc1       $2, $f0
    /* 1BEA4 0011BEA4 00000000 */  nop
    /* 1BEA8 0011BEA8 00000146 */  add.s      $f0, $f0, $f1
    /* 1BEAC 0011BEAC 2C00A0E7 */  swc1       $f0, 0x2C($29)
    /* 1BEB0 0011BEB0 F804048E */  lw         $4, 0x4F8($16)
    /* 1BEB4 0011BEB4 2800A527 */  addiu      $5, $29, 0x28
    /* 1BEB8 0011BEB8 2000A627 */  addiu      $6, $29, 0x20
    /* 1BEBC 0011BEBC AC78040C */  jal        func_0011e2b0
    /* 1BEC0 0011BEC0 00000000 */   nop
    /* 1BEC4 0011BEC4 F804048E */  lw         $4, 0x4F8($16)
    /* 1BEC8 0011BEC8 DC78040C */  jal        func_0011e370
    /* 1BECC 0011BECC 00000000 */   nop
    /* 1BED0 0011BED0 06000010 */  b          .L0011BEEC
    /* 1BED4 0011BED4 00000000 */   nop
  .L0011BED8:
    /* 1BED8 0011BED8 F804048E */  lw         $4, 0x4F8($16)
    /* 1BEDC 0011BEDC 2800A527 */  addiu      $5, $29, 0x28
    /* 1BEE0 0011BEE0 2000A627 */  addiu      $6, $29, 0x20
    /* 1BEE4 0011BEE4 AC78040C */  jal        func_0011e2b0
    /* 1BEE8 0011BEE8 00000000 */   nop
  .L0011BEEC:
    /* 1BEEC 0011BEEC 3405048E */  lw         $4, 0x534($16)
    /* 1BEF0 0011BEF0 2000033C */  lui        $3, (0x200000 >> 16)
    /* 1BEF4 0011BEF4 25188300 */  or         $3, $4, $3
    /* 1BEF8 0011BEF8 340503AE */  sw         $3, 0x534($16)
  .L0011BEFC:
    /* 1BEFC 0011BEFC 1000BFDF */  ld         $31, 0x10($29)
    /* 1BF00 0011BF00 0000B07B */  lq         $16, 0x0($29)
    /* 1BF04 0011BF04 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BF08 0011BF08 0800E003 */  jr         $31
    /* 1BF0C 0011BF0C 00000000 */   nop
.size func_0011bdc0, 0x150
