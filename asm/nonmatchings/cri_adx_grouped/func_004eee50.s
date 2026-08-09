.section .text
.set noat
.set noreorder
glabel func_004eee50
    /* 3EEE50 004EEE50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEE54 004EEE54 06008014 */  bnez       $4, .L004EEE70
    /* 3EEE58 004EEE58 0000BFFF */   sd        $31, 0x0($29)
    /* 3EEE5C 004EEE5C 7600043C */  lui        $4, %hi(D_0075CF48)
    /* 3EEE60 004EEE60 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EEE64 004EEE64 48CF8424 */  addiu      $4, $4, %lo(D_0075CF48)
    /* 3EEE68 004EEE68 08000010 */  b          .L004EEE8C
    /* 3EEE6C 004EEE6C F8CEA524 */   addiu     $5, $5, %lo(D_0075CEF8)
  .L004EEE70:
    /* 3EEE70 004EEE70 04008280 */  lb         $2, 0x4($4)
    /* 3EEE74 004EEE74 08004054 */  bnel       $2, $0, .L004EEE98
    /* 3EEE78 004EEE78 0800828C */   lw        $2, 0x8($4)
    /* 3EEE7C 004EEE7C 7600043C */  lui        $4, %hi(D_0075CF58)
    /* 3EEE80 004EEE80 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EEE84 004EEE84 58CF8424 */  addiu      $4, $4, %lo(D_0075CF58)
    /* 3EEE88 004EEE88 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
  .L004EEE8C:
    /* 3EEE8C 004EEE8C B6BA130C */  jal        func_004eead8
    /* 3EEE90 004EEE90 00000000 */   nop
    /* 3EEE94 004EEE94 2D100000 */  daddu      $2, $0, $0
  .L004EEE98:
    /* 3EEE98 004EEE98 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEE9C 004EEE9C 0800E003 */  jr         $31
    /* 3EEEA0 004EEEA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEEA4 004EEEA4 00000000 */  nop
.size func_004eee50, 0x58
