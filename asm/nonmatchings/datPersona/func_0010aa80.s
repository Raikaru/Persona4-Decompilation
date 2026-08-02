.section .text
.set noat
.set noreorder
glabel func_0010aa80
    /* AA80 0010AA80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AA84 0010AA84 1000BFFF */  sd         $31, 0x10($29)
    /* AA88 0010AA88 0000B07F */  sq         $16, 0x0($29)
    /* AA8C 0010AA8C 2D808000 */  daddu      $16, $4, $0
    /* AA90 0010AA90 6C2D040C */  jal        func_0010b5b0
    /* AA94 0010AA94 00000000 */   nop
    /* AA98 0010AA98 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* AA9C 0010AA9C 2D380000 */  daddu      $7, $0, $0
    /* AAA0 0010AAA0 3C2C1000 */  dsll32     $5, $16, 16
    /* AAA4 0010AAA4 3F2C0500 */  dsra32     $5, $5, 16
    /* AAA8 0010AAA8 7900043C */  lui        $4, %hi(D_007973A0)
    /* AAAC 0010AAAC A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* AAB0 0010AAB0 13000010 */  b          .L0010AB00
    /* AAB4 0010AAB4 00000000 */   nop
  .L0010AAB8:
    /* AAB8 0010AAB8 FFFFE330 */  andi       $3, $7, 0xFFFF
    /* AABC 0010AABC 40100300 */  sll        $2, $3, 1
    /* AAC0 0010AAC0 21104300 */  addu       $2, $2, $3
    /* AAC4 0010AAC4 00110200 */  sll        $2, $2, 4
    /* AAC8 0010AAC8 21188200 */  addu       $3, $4, $2
    /* AACC 0010AACC EC0B6294 */  lhu        $2, 0xBEC($3)
    /* AAD0 0010AAD0 01004230 */  andi       $2, $2, 0x1
    /* AAD4 0010AAD4 08004010 */  beqz       $2, .L0010AAF8
    /* AAD8 0010AAD8 00000000 */   nop
    /* AADC 0010AADC EE0B6294 */  lhu        $2, 0xBEE($3)
    /* AAE0 0010AAE0 05004514 */  bne        $2, $5, .L0010AAF8
    /* AAE4 0010AAE4 00000000 */   nop
    /* AAE8 0010AAE8 3C140700 */  dsll32     $2, $7, 16
    /* AAEC 0010AAEC 3F140200 */  dsra32     $2, $2, 16
    /* AAF0 0010AAF0 08000010 */  b          .L0010AB14
    /* AAF4 0010AAF4 00000000 */   nop
  .L0010AAF8:
    /* AAF8 0010AAF8 0100E224 */  addiu      $2, $7, 0x1
    /* AAFC 0010AAFC FFFF4730 */  andi       $7, $2, 0xFFFF
  .L0010AB00:
    /* AB00 0010AB00 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AB04 0010AB04 2A104600 */  slt        $2, $2, $6
    /* AB08 0010AB08 EBFF4014 */  bnez       $2, .L0010AAB8
    /* AB0C 0010AB0C 00000000 */   nop
    /* AB10 0010AB10 FFFF0224 */  addiu      $2, $0, -0x1
  .L0010AB14:
    /* AB14 0010AB14 1000BFDF */  ld         $31, 0x10($29)
    /* AB18 0010AB18 0000B07B */  lq         $16, 0x0($29)
    /* AB1C 0010AB1C 2000BD27 */  addiu      $29, $29, 0x20
    /* AB20 0010AB20 0800E003 */  jr         $31
    /* AB24 0010AB24 00000000 */   nop
    /* AB28 0010AB28 00000000 */  nop
    /* AB2C 0010AB2C 00000000 */  nop
.size func_0010aa80, 0xb0
