.section .text
.set noat
.set noreorder
glabel func_003d79b0
    /* 2D79B0 003D79B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D79B4 003D79B4 1000BFFF */  sd         $31, 0x10($29)
    /* 2D79B8 003D79B8 0000B07F */  sq         $16, 0x0($29)
    /* 2D79BC 003D79BC 54600F0C */  jal        func_003d8150
    /* 2D79C0 003D79C0 2D808000 */   daddu     $16, $4, $0
    /* 2D79C4 003D79C4 10004010 */  beqz       $2, .L003D7A08
    /* 2D79C8 003D79C8 00000000 */   nop
    /* 2D79CC 003D79CC 4CB7838F */  lw         $3, -0x48B4($28)
    /* 2D79D0 003D79D0 0C000224 */  addiu      $2, $0, 0xC
    /* 2D79D4 003D79D4 04004224 */  addiu      $2, $2, 0x4
    /* 2D79D8 003D79D8 2D280000 */  daddu      $5, $0, $0
    /* 2D79DC 003D79DC 21200302 */  addu       $4, $16, $3
  .L003D79E0:
    /* 2D79E0 003D79E0 0800838C */  lw         $3, 0x8($4)
    /* 2D79E4 003D79E4 02006010 */  beqz       $3, .L003D79F0
    /* 2D79E8 003D79E8 00000000 */   nop
    /* 2D79EC 003D79EC 20004224 */  addiu      $2, $2, 0x20
  .L003D79F0:
    /* 2D79F0 003D79F0 0100A524 */  addiu      $5, $5, 0x1
    /* 2D79F4 003D79F4 0800A32C */  sltiu      $3, $5, 0x8
    /* 2D79F8 003D79F8 F9FF6014 */  bnez       $3, .L003D79E0
    /* 2D79FC 003D79FC 04008424 */   addiu     $4, $4, 0x4
    /* 2D7A00 003D7A00 03000010 */  b          .L003D7A10
    /* 2D7A04 003D7A04 1000BFDF */   ld        $31, 0x10($29)
  .L003D7A08:
    /* 2D7A08 003D7A08 2D100000 */  daddu      $2, $0, $0
    /* 2D7A0C 003D7A0C 1000BFDF */  ld         $31, 0x10($29)
  .L003D7A10:
    /* 2D7A10 003D7A10 0000B07B */  lq         $16, 0x0($29)
    /* 2D7A14 003D7A14 0800E003 */  jr         $31
    /* 2D7A18 003D7A18 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D7A1C 003D7A1C 00000000 */  nop
.size func_003d79b0, 0x70
