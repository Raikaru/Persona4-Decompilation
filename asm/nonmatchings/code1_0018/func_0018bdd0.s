.section .text
.set noat
.set noreorder
glabel func_0018bdd0
    /* 8BDD0 0018BDD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8BDD4 0018BDD4 1000BFFF */  sd         $31, 0x10($29)
    /* 8BDD8 0018BDD8 0000B07F */  sq         $16, 0x0($29)
    /* 8BDDC 0018BDDC 3800908C */  lw         $16, 0x38($4)
    /* 8BDE0 0018BDE0 380005C6 */  lwc1       $f5, 0x38($16)
    /* 8BDE4 0018BDE4 440004C6 */  lwc1       $f4, 0x44($16)
    /* 8BDE8 0018BDE8 300003C6 */  lwc1       $f3, 0x30($16)
    /* 8BDEC 0018BDEC 3C0002C6 */  lwc1       $f2, 0x3C($16)
    /* 8BDF0 0018BDF0 340001C6 */  lwc1       $f1, 0x34($16)
    /* 8BDF4 0018BDF4 400000C6 */  lwc1       $f0, 0x40($16)
    /* 8BDF8 0018BDF8 1A080046 */  mula.s     $f1, $f0
    /* 8BDFC 0018BDFC 1E180246 */  madda.s    $f3, $f2
    /* 8BE00 0018BE00 5C280446 */  madd.s     $f1, $f5, $f4
    /* 8BE04 0018BE04 188280C7 */  lwc1       $f0, -0x7DE8($28)
    /* 8BE08 0018BE08 34080046 */  c.lt.s     $f1, $f0
    /* 8BE0C 0018BE0C 13000045 */  bc1f       .L0018BE5C
    /* 8BE10 0018BE10 00000000 */   nop
    /* 8BE14 0018BE14 300002C6 */  lwc1       $f2, 0x30($16)
    /* 8BE18 0018BE18 340001C6 */  lwc1       $f1, 0x34($16)
    /* 8BE1C 0018BE1C 380000C6 */  lwc1       $f0, 0x38($16)
    /* 8BE20 0018BE20 3C0002E6 */  swc1       $f2, 0x3C($16)
    /* 8BE24 0018BE24 400001E6 */  swc1       $f1, 0x40($16)
    /* 8BE28 0018BE28 440000E6 */  swc1       $f0, 0x44($16)
    /* 8BE2C 0018BE2C 0C00028E */  lw         $2, 0xC($16)
    /* 8BE30 0018BE30 6401448C */  lw         $4, 0x164($2)
    /* 8BE34 0018BE34 2D280000 */  daddu      $5, $0, $0
    /* 8BE38 0018BE38 01000624 */  addiu      $6, $0, 0x1
    /* 8BE3C 0018BE3C 04000724 */  addiu      $7, $0, 0x4
    /* 8BE40 0018BE40 2D40C000 */  daddu      $8, $6, $0
    /* 8BE44 0018BE44 50E6110C */  jal        func_00479940
    /* 8BE48 0018BE48 00000000 */   nop
    /* 8BE4C 0018BE4C 06000324 */  addiu      $3, $0, 0x6
    /* 8BE50 0018BE50 000003AE */  sw         $3, 0x0($16)
    /* 8BE54 0018BE54 0B000010 */  b          .L0018BE84
    /* 8BE58 0018BE58 00000000 */   nop
  .L0018BE5C:
    /* 8BE5C 0018BE5C 0C00028E */  lw         $2, 0xC($16)
    /* 8BE60 0018BE60 6401448C */  lw         $4, 0x164($2)
    /* 8BE64 0018BE64 2D280000 */  daddu      $5, $0, $0
    /* 8BE68 0018BE68 2D300000 */  daddu      $6, $0, $0
    /* 8BE6C 0018BE6C 08000724 */  addiu      $7, $0, 0x8
    /* 8BE70 0018BE70 01000824 */  addiu      $8, $0, 0x1
    /* 8BE74 0018BE74 50E6110C */  jal        func_00479940
    /* 8BE78 0018BE78 00000000 */   nop
    /* 8BE7C 0018BE7C 04000324 */  addiu      $3, $0, 0x4
    /* 8BE80 0018BE80 000003AE */  sw         $3, 0x0($16)
  .L0018BE84:
    /* 8BE84 0018BE84 1000BFDF */  ld         $31, 0x10($29)
    /* 8BE88 0018BE88 0000B07B */  lq         $16, 0x0($29)
    /* 8BE8C 0018BE8C 2000BD27 */  addiu      $29, $29, 0x20
    /* 8BE90 0018BE90 0800E003 */  jr         $31
    /* 8BE94 0018BE94 00000000 */   nop
    /* 8BE98 0018BE98 00000000 */  nop
    /* 8BE9C 0018BE9C 00000000 */  nop
.size func_0018bdd0, 0xd0
