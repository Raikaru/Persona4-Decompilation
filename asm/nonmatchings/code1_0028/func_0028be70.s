.section .text
.set noat
.set noreorder
glabel func_0028be70
    /* 18BE70 0028BE70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 18BE74 0028BE74 2000BFFF */  sd         $31, 0x20($29)
    /* 18BE78 0028BE78 1000B17F */  sq         $17, 0x10($29)
    /* 18BE7C 0028BE7C 0000B07F */  sq         $16, 0x0($29)
    /* 18BE80 0028BE80 2D888000 */  daddu      $17, $4, $0
    /* 18BE84 0028BE84 2D80A000 */  daddu      $16, $5, $0
    /* 18BE88 0028BE88 0200012A */  slti       $1, $16, 0x2
    /* 18BE8C 0028BE8C 11002010 */  beqz       $1, .L0028BED4
    /* 18BE90 0028BE90 00000000 */   nop
    /* 18BE94 0028BE94 01000324 */  addiu      $3, $0, 0x1
    /* 18BE98 0028BE98 0A000312 */  beq        $16, $3, .L0028BEC4
    /* 18BE9C 0028BE9C 00000000 */   nop
    /* 18BEA0 0028BEA0 03000012 */  beqz       $16, .L0028BEB0
    /* 18BEA4 0028BEA4 00000000 */   nop
    /* 18BEA8 0028BEA8 09000010 */  b          .L0028BED0
    /* 18BEAC 0028BEAC 00000000 */   nop
  .L0028BEB0:
    /* 18BEB0 0028BEB0 581E0424 */  addiu      $4, $0, 0x1E58
    /* 18BEB4 0028BEB4 98AF090C */  jal        func_0026be60
    /* 18BEB8 0028BEB8 00000000 */   nop
    /* 18BEBC 0028BEBC 04000010 */  b          .L0028BED0
    /* 18BEC0 0028BEC0 00000000 */   nop
  .L0028BEC4:
    /* 18BEC4 0028BEC4 591E0424 */  addiu      $4, $0, 0x1E59
    /* 18BEC8 0028BEC8 98AF090C */  jal        func_0026be60
    /* 18BECC 0028BECC 00000000 */   nop
  .L0028BED0:
    /* 18BED0 0028BED0 240530AE */  sw         $16, 0x524($17)
  .L0028BED4:
    /* 18BED4 0028BED4 2000BFDF */  ld         $31, 0x20($29)
    /* 18BED8 0028BED8 1000B17B */  lq         $17, 0x10($29)
    /* 18BEDC 0028BEDC 0000B07B */  lq         $16, 0x0($29)
    /* 18BEE0 0028BEE0 3000BD27 */  addiu      $29, $29, 0x30
    /* 18BEE4 0028BEE4 0800E003 */  jr         $31
    /* 18BEE8 0028BEE8 00000000 */   nop
    /* 18BEEC 0028BEEC 00000000 */  nop
.size func_0028be70, 0x80
