.section .text
.set noat
.set noreorder
glabel func_001cef20
    /* CEF20 001CEF20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* CEF24 001CEF24 1000BFFF */  sd         $31, 0x10($29)
    /* CEF28 001CEF28 0000B07F */  sq         $16, 0x0($29)
    /* CEF2C 001CEF2C 2D808000 */  daddu      $16, $4, $0
    /* CEF30 001CEF30 68010424 */  addiu      $4, $0, 0x168
    /* CEF34 001CEF34 5CC7080C */  jal        func_00231d70
    /* CEF38 001CEF38 00000000 */   nop
    /* CEF3C 001CEF3C 06004004 */  bltz       $2, .L001CEF58
    /* CEF40 001CEF40 00000000 */   nop
    /* CEF44 001CEF44 00008244 */  mtc1       $2, $f0
    /* CEF48 001CEF48 00000000 */  nop
    /* CEF4C 001CEF4C 20008046 */  cvt.s.w    $f0, $f0
    /* CEF50 001CEF50 08000010 */  b          .L001CEF74
    /* CEF54 001CEF54 00000000 */   nop
  .L001CEF58:
    /* CEF58 001CEF58 42180200 */  srl        $3, $2, 1
    /* CEF5C 001CEF5C 01004230 */  andi       $2, $2, 0x1
    /* CEF60 001CEF60 25186200 */  or         $3, $3, $2
    /* CEF64 001CEF64 00008344 */  mtc1       $3, $f0
    /* CEF68 001CEF68 00000000 */  nop
    /* CEF6C 001CEF6C 20008046 */  cvt.s.w    $f0, $f0
    /* CEF70 001CEF70 00000046 */  add.s      $f0, $f0, $f0
  .L001CEF74:
    /* CEF74 001CEF74 000100E6 */  swc1       $f0, 0x100($16)
    /* CEF78 001CEF78 01000224 */  addiu      $2, $0, 0x1
    /* CEF7C 001CEF7C 200102AE */  sw         $2, 0x120($16)
    /* CEF80 001CEF80 00608044 */  mtc1       $0, $f12
    /* CEF84 001CEF84 E000048E */  lw         $4, 0xE0($16)
    /* CEF88 001CEF88 2D280000 */  daddu      $5, $0, $0
    /* CEF8C 001CEF8C 2D300000 */  daddu      $6, $0, $0
    /* CEF90 001CEF90 00010724 */  addiu      $7, $0, 0x100
    /* CEF94 001CEF94 50F3060C */  jal        func_001bcd40
    /* CEF98 001CEF98 00000000 */   nop
    /* CEF9C 001CEF9C 1000BFDF */  ld         $31, 0x10($29)
    /* CEFA0 001CEFA0 0000B07B */  lq         $16, 0x0($29)
    /* CEFA4 001CEFA4 2000BD27 */  addiu      $29, $29, 0x20
    /* CEFA8 001CEFA8 0800E003 */  jr         $31
    /* CEFAC 001CEFAC 00000000 */   nop
.size func_001cef20, 0x90
