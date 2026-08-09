.section .text
.set noat
.set noreorder
glabel func_0052cf88
    /* 42CF88 0052CF88 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42CF8C 0052CF8C 2D108000 */  daddu      $2, $4, $0
    /* 42CF90 0052CF90 03004010 */  beqz       $2, .L0052CFA0
    /* 42CF94 0052CF94 1000BFFF */   sd        $31, 0x10($29)
    /* 42CF98 0052CF98 0300A104 */  bgez       $5, .L0052CFA8
    /* 42CF9C 0052CF9C 00000000 */   nop
  .L0052CFA0:
    /* 42CFA0 0052CFA0 07000010 */  b          .L0052CFC0
    /* 42CFA4 0052CFA4 2D100000 */   daddu     $2, $0, $0
  .L0052CFA8:
    /* 42CFA8 0052CFA8 10004380 */  lb         $3, 0x10($2)
    /* 42CFAC 0052CFAC 11004580 */  lb         $5, 0x11($2)
    /* 42CFB0 0052CFB0 0000A3A3 */  sb         $3, 0x0($29)
    /* 42CFB4 0052CFB4 0100A5A3 */  sb         $5, 0x1($29)
    /* 42CFB8 0052CFB8 ACF1100C */  jal        func_0043c6b0
    /* 42CFBC 0052CFBC 2D20A003 */   daddu     $4, $29, $0
  .L0052CFC0:
    /* 42CFC0 0052CFC0 1000BFDF */  ld         $31, 0x10($29)
    /* 42CFC4 0052CFC4 0800E003 */  jr         $31
    /* 42CFC8 0052CFC8 2000BD27 */   addiu     $29, $29, 0x20
    /* 42CFCC 0052CFCC 00000000 */  nop
.size func_0052cf88, 0x48
