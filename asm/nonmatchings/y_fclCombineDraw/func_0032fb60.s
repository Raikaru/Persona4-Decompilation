.section .text
.set noat
.set noreorder
glabel func_0032fb60
    /* 22FB60 0032FB60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 22FB64 0032FB64 1000BFFF */  sd         $31, 0x10($29)
    /* 22FB68 0032FB68 0000B07F */  sq         $16, 0x0($29)
    /* 22FB6C 0032FB6C 2D808000 */  daddu      $16, $4, $0
    /* 22FB70 0032FB70 06130424 */  addiu      $4, $0, 0x1306
    /* 22FB74 0032FB74 CC18040C */  jal        func_00106330
    /* 22FB78 0032FB78 00000000 */   nop
    /* 22FB7C 0032FB7C 0A004010 */  beqz       $2, .L0032FBA8
    /* 22FB80 0032FB80 00000000 */   nop
    /* 22FB84 0032FB84 3C1E1000 */  dsll32     $3, $16, 24
    /* 22FB88 0032FB88 3F1E0300 */  dsra32     $3, $3, 24
    /* 22FB8C 0032FB8C 7500023C */  lui        $2, %hi(D_00749530)
    /* 22FB90 0032FB90 30954224 */  addiu      $2, $2, %lo(D_00749530)
    /* 22FB94 0032FB94 21104300 */  addu       $2, $2, $3
    /* 22FB98 0032FB98 00004280 */  lb         $2, 0x0($2)
    /* 22FB9C 0032FB9C FCFF4224 */  addiu      $2, $2, -0x4
    /* 22FBA0 0032FBA0 3C860200 */  dsll32     $16, $2, 24
    /* 22FBA4 0032FBA4 3F861000 */  dsra32     $16, $16, 24
  .L0032FBA8:
    /* 22FBA8 0032FBA8 2D100002 */  daddu      $2, $16, $0
    /* 22FBAC 0032FBAC 1000BFDF */  ld         $31, 0x10($29)
    /* 22FBB0 0032FBB0 0000B07B */  lq         $16, 0x0($29)
    /* 22FBB4 0032FBB4 2000BD27 */  addiu      $29, $29, 0x20
    /* 22FBB8 0032FBB8 0800E003 */  jr         $31
    /* 22FBBC 0032FBBC 00000000 */   nop
.size func_0032fb60, 0x60
