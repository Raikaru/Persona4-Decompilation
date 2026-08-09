.section .text
.set noat
.set noreorder
glabel func_0018bc20
    /* 8BC20 0018BC20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 8BC24 0018BC24 2000BFFF */  sd         $31, 0x20($29)
    /* 8BC28 0018BC28 1000B07F */  sq         $16, 0x10($29)
    /* 8BC2C 0018BC2C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 8BC30 0018BC30 3800908C */  lw         $16, 0x38($4)
    /* 8BC34 0018BC34 0C00028E */  lw         $2, 0xC($16)
    /* 8BC38 0018BC38 6401448C */  lw         $4, 0x164($2)
    /* 8BC3C 0018BC3C BCE8110C */  jal        func_0047a2f0
    /* 8BC40 0018BC40 00000000 */   nop
    /* 8BC44 0018BC44 30000426 */  addiu      $4, $16, 0x30
    /* 8BC48 0018BC48 200042C4 */  lwc1       $f2, 0x20($2)
    /* 8BC4C 0018BC4C 240041C4 */  lwc1       $f1, 0x24($2)
    /* 8BC50 0018BC50 280040C4 */  lwc1       $f0, 0x28($2)
    /* 8BC54 0018BC54 300002E6 */  swc1       $f2, 0x30($16)
    /* 8BC58 0018BC58 340001E6 */  swc1       $f1, 0x34($16)
    /* 8BC5C 0018BC5C 380000E6 */  swc1       $f0, 0x38($16)
    /* 8BC60 0018BC60 2D288000 */  daddu      $5, $4, $0
    /* 8BC64 0018BC64 2C900F0C */  jal        func_003e40b0
    /* 8BC68 0018BC68 00000000 */   nop
    /* 8BC6C 0018BC6C 0C00028E */  lw         $2, 0xC($16)
    /* 8BC70 0018BC70 6401448C */  lw         $4, 0x164($2)
    /* 8BC74 0018BC74 BCE8110C */  jal        func_0047a2f0
    /* 8BC78 0018BC78 00000000 */   nop
    /* 8BC7C 0018BC7C 300054C4 */  lwc1       $f20, 0x30($2)
    /* 8BC80 0018BC80 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 8BC84 0018BC84 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 8BC88 0018BC88 BCE8110C */  jal        func_0047a2f0
    /* 8BC8C 0018BC8C 00000000 */   nop
    /* 8BC90 0018BC90 300040C4 */  lwc1       $f0, 0x30($2)
    /* 8BC94 0018BC94 01001446 */  sub.s      $f0, $f0, $f20
    /* 8BC98 0018BC98 3C0000E6 */  swc1       $f0, 0x3C($16)
    /* 8BC9C 0018BC9C 0C00028E */  lw         $2, 0xC($16)
    /* 8BCA0 0018BCA0 6401448C */  lw         $4, 0x164($2)
    /* 8BCA4 0018BCA4 BCE8110C */  jal        func_0047a2f0
    /* 8BCA8 0018BCA8 00000000 */   nop
    /* 8BCAC 0018BCAC 340054C4 */  lwc1       $f20, 0x34($2)
    /* 8BCB0 0018BCB0 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 8BCB4 0018BCB4 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 8BCB8 0018BCB8 BCE8110C */  jal        func_0047a2f0
    /* 8BCBC 0018BCBC 00000000 */   nop
    /* 8BCC0 0018BCC0 340040C4 */  lwc1       $f0, 0x34($2)
    /* 8BCC4 0018BCC4 01001446 */  sub.s      $f0, $f0, $f20
    /* 8BCC8 0018BCC8 400000E6 */  swc1       $f0, 0x40($16)
    /* 8BCCC 0018BCCC 0C00028E */  lw         $2, 0xC($16)
    /* 8BCD0 0018BCD0 6401448C */  lw         $4, 0x164($2)
    /* 8BCD4 0018BCD4 BCE8110C */  jal        func_0047a2f0
    /* 8BCD8 0018BCD8 00000000 */   nop
    /* 8BCDC 0018BCDC 380054C4 */  lwc1       $f20, 0x38($2)
    /* 8BCE0 0018BCE0 7F00023C */  lui        $2, %hi(D_007EFA00)
    /* 8BCE4 0018BCE4 00FA448C */  lw         $4, %lo(D_007EFA00)($2)
    /* 8BCE8 0018BCE8 BCE8110C */  jal        func_0047a2f0
    /* 8BCEC 0018BCEC 00000000 */   nop
    /* 8BCF0 0018BCF0 380040C4 */  lwc1       $f0, 0x38($2)
    /* 8BCF4 0018BCF4 01001446 */  sub.s      $f0, $f0, $f20
    /* 8BCF8 0018BCF8 440000E6 */  swc1       $f0, 0x44($16)
    /* 8BCFC 0018BCFC 3C000426 */  addiu      $4, $16, 0x3C
    /* 8BD00 0018BD00 2D288000 */  daddu      $5, $4, $0
    /* 8BD04 0018BD04 2C900F0C */  jal        func_003e40b0
    /* 8BD08 0018BD08 00000000 */   nop
    /* 8BD0C 0018BD0C 380005C6 */  lwc1       $f5, 0x38($16)
    /* 8BD10 0018BD10 440004C6 */  lwc1       $f4, 0x44($16)
    /* 8BD14 0018BD14 300003C6 */  lwc1       $f3, 0x30($16)
    /* 8BD18 0018BD18 3C0002C6 */  lwc1       $f2, 0x3C($16)
    /* 8BD1C 0018BD1C 340001C6 */  lwc1       $f1, 0x34($16)
    /* 8BD20 0018BD20 400000C6 */  lwc1       $f0, 0x40($16)
    /* 8BD24 0018BD24 1A080046 */  mula.s     $f1, $f0
    /* 8BD28 0018BD28 1E180246 */  madda.s    $f3, $f2
    /* 8BD2C 0018BD2C 5C280446 */  madd.s     $f1, $f5, $f4
    /* 8BD30 0018BD30 188280C7 */  lwc1       $f0, -0x7DE8($28)
    /* 8BD34 0018BD34 34080046 */  c.lt.s     $f1, $f0
    /* 8BD38 0018BD38 15000045 */  bc1f       .L0018BD90
    /* 8BD3C 0018BD3C 00000000 */   nop
    /* 8BD40 0018BD40 0C00028E */  lw         $2, 0xC($16)
    /* 8BD44 0018BD44 6401448C */  lw         $4, 0x164($2)
    /* 8BD48 0018BD48 2D280000 */  daddu      $5, $0, $0
    /* 8BD4C 0018BD4C 0CE7110C */  jal        func_00479c30
    /* 8BD50 0018BD50 00000000 */   nop
    /* 8BD54 0018BD54 3C140200 */  dsll32     $2, $2, 16
    /* 8BD58 0018BD58 3F140200 */  dsra32     $2, $2, 16
    /* 8BD5C 0018BD5C 2C0002AE */  sw         $2, 0x2C($16)
    /* 8BD60 0018BD60 0C00028E */  lw         $2, 0xC($16)
    /* 8BD64 0018BD64 6401448C */  lw         $4, 0x164($2)
    /* 8BD68 0018BD68 2D280000 */  daddu      $5, $0, $0
    /* 8BD6C 0018BD6C 01000624 */  addiu      $6, $0, 0x1
    /* 8BD70 0018BD70 04000724 */  addiu      $7, $0, 0x4
    /* 8BD74 0018BD74 2D40C000 */  daddu      $8, $6, $0
    /* 8BD78 0018BD78 50E6110C */  jal        func_00479940
    /* 8BD7C 0018BD7C 00000000 */   nop
    /* 8BD80 0018BD80 05000324 */  addiu      $3, $0, 0x5
    /* 8BD84 0018BD84 000003AE */  sw         $3, 0x0($16)
    /* 8BD88 0018BD88 0B000010 */  b          .L0018BDB8
    /* 8BD8C 0018BD8C 00000000 */   nop
  .L0018BD90:
    /* 8BD90 0018BD90 0C00028E */  lw         $2, 0xC($16)
    /* 8BD94 0018BD94 6401448C */  lw         $4, 0x164($2)
    /* 8BD98 0018BD98 2D280000 */  daddu      $5, $0, $0
    /* 8BD9C 0018BD9C 03000624 */  addiu      $6, $0, 0x3
    /* 8BDA0 0018BDA0 08000724 */  addiu      $7, $0, 0x8
    /* 8BDA4 0018BDA4 2D400000 */  daddu      $8, $0, $0
    /* 8BDA8 0018BDA8 50E6110C */  jal        func_00479940
    /* 8BDAC 0018BDAC 00000000 */   nop
    /* 8BDB0 0018BDB0 07000324 */  addiu      $3, $0, 0x7
    /* 8BDB4 0018BDB4 000003AE */  sw         $3, 0x0($16)
  .L0018BDB8:
    /* 8BDB8 0018BDB8 2000BFDF */  ld         $31, 0x20($29)
    /* 8BDBC 0018BDBC 1000B07B */  lq         $16, 0x10($29)
    /* 8BDC0 0018BDC0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 8BDC4 0018BDC4 3000BD27 */  addiu      $29, $29, 0x30
    /* 8BDC8 0018BDC8 0800E003 */  jr         $31
    /* 8BDCC 0018BDCC 00000000 */   nop
.size func_0018bc20, 0x1b0
