.section .text
.set noat
.set noreorder
glabel func_0026cba0
    /* 16CBA0 0026CBA0 90FEBD27 */  addiu      $29, $29, -0x170
    /* 16CBA4 0026CBA4 2000BFFF */  sd         $31, 0x20($29)
    /* 16CBA8 0026CBA8 1000B07F */  sq         $16, 0x10($29)
    /* 16CBAC 0026CBAC 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 16CBB0 0026CBB0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 16CBB4 0026CBB4 2D808000 */  daddu      $16, $4, $0
    /* 16CBB8 0026CBB8 46650046 */  mov.s      $f21, $f12
    /* 16CBBC 0026CBBC 066D0046 */  mov.s      $f20, $f13
    /* 16CBC0 0026CBC0 0600022E */  sltiu      $2, $16, 0x6
    /* 16CBC4 0026CBC4 06004014 */  bnez       $2, .L0026CBE0
    /* 16CBC8 0026CBC8 00000000 */   nop
    /* 16CBCC 0026CBCC 6400043C */  lui        $4, %hi(D_0063B090)
    /* 16CBD0 0026CBD0 90B08424 */  addiu      $4, $4, %lo(D_0063B090)
    /* 16CBD4 0026CBD4 240A0524 */  addiu      $5, $0, 0xA24
    /* 16CBD8 0026CBD8 CCB5110C */  jal        func_0046d730
    /* 16CBDC 0026CBDC 00000000 */   nop
  .L0026CBE0:
    /* 16CBE0 0026CBE0 00008044 */  mtc1       $0, $f0
    /* 16CBE4 0026CBE4 00000000 */  nop
    /* 16CBE8 0026CBE8 32001546 */  c.eq.s     $f0, $f21
    /* 16CBEC 0026CBEC 05000045 */  bc1f       .L0026CC04
    /* 16CBF0 0026CBF0 00000000 */   nop
    /* 16CBF4 0026CBF4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 16CBF8 0026CBF8 00A08244 */  mtc1       $2, $f20
    /* 16CBFC 0026CBFC 04000010 */  b          .L0026CC10
    /* 16CC00 0026CC00 00000000 */   nop
  .L0026CC04:
    /* 16CC04 0026CC04 00000000 */  nop
    /* 16CC08 0026CC08 00000000 */  nop
    /* 16CC0C 0026CC0C 03A51546 */  div.s      $f20, $f20, $f21
  .L0026CC10:
    /* 16CC10 0026CC10 01000224 */  addiu      $2, $0, 0x1
    /* 16CC14 0026CC14 3000A2A3 */  sb         $2, 0x30($29)
    /* 16CC18 0026CC18 3400A0AF */  sw         $0, 0x34($29)
    /* 16CC1C 0026CC1C 3800A0AF */  sw         $0, 0x38($29)
    /* 16CC20 0026CC20 3C00A0AF */  sw         $0, 0x3C($29)
    /* 16CC24 0026CC24 2D200002 */  daddu      $4, $16, $0
    /* 16CC28 0026CC28 881D050C */  jal        func_00147620
    /* 16CC2C 0026CC2C 00000000 */   nop
    /* 16CC30 0026CC30 000040C4 */  lwc1       $f0, 0x0($2)
    /* 16CC34 0026CC34 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 16CC38 0026CC38 080040C4 */  lwc1       $f0, 0x8($2)
    /* 16CC3C 0026CC3C 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 16CC40 0026CC40 4800A0AF */  sw         $0, 0x48($29)
    /* 16CC44 0026CC44 040040C4 */  lwc1       $f0, 0x4($2)
    /* 16CC48 0026CC48 4C00A0E7 */  swc1       $f0, 0x4C($29)
    /* 16CC4C 0026CC4C 0C0040C4 */  lwc1       $f0, 0xC($2)
    /* 16CC50 0026CC50 5000A0E7 */  swc1       $f0, 0x50($29)
    /* 16CC54 0026CC54 5400A0AF */  sw         $0, 0x54($29)
    /* 16CC58 0026CC58 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 16CC5C 0026CC5C 5800A2AF */  sw         $2, 0x58($29)
    /* 16CC60 0026CC60 5C00A2AF */  sw         $2, 0x5C($29)
    /* 16CC64 0026CC64 6000A0AF */  sw         $0, 0x60($29)
    /* 16CC68 0026CC68 3000A427 */  addiu      $4, $29, 0x30
    /* 16CC6C 0026CC6C 06A30046 */  mov.s      $f12, $f20
    /* 16CC70 0026CC70 6001A527 */  addiu      $5, $29, 0x160
    /* 16CC74 0026CC74 84B2090C */  jal        func_0026ca10
    /* 16CC78 0026CC78 00000000 */   nop
    /* 16CC7C 0026CC7C 6401A0C7 */  lwc1       $f0, 0x164($29)
    /* 16CC80 0026CC80 02001546 */  mul.s      $f0, $f0, $f21
    /* 16CC84 0026CC84 2000BFDF */  ld         $31, 0x20($29)
    /* 16CC88 0026CC88 1000B07B */  lq         $16, 0x10($29)
    /* 16CC8C 0026CC8C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 16CC90 0026CC90 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 16CC94 0026CC94 7001BD27 */  addiu      $29, $29, 0x170
    /* 16CC98 0026CC98 0800E003 */  jr         $31
    /* 16CC9C 0026CC9C 00000000 */   nop
.size func_0026cba0, 0x100
