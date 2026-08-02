.section .text
.set noat
.set noreorder
glabel func_001dfe10
    /* DFE10 001DFE10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DFE14 001DFE14 1000BFFF */  sd         $31, 0x10($29)
    /* DFE18 001DFE18 0000B07F */  sq         $16, 0x0($29)
    /* DFE1C 001DFE1C 2D200000 */  daddu      $4, $0, $0
    /* DFE20 001DFE20 00730A0C */  jal        func_0029cc00
    /* DFE24 001DFE24 00000000 */   nop
    /* DFE28 001DFE28 3C1A0200 */  dsll32     $3, $2, 8
    /* DFE2C 001DFE2C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFE30 001DFE30 0011023C */  lui        $2, (0x11000000 >> 16)
    /* DFE34 001DFE34 25806200 */  or         $16, $3, $2
    /* DFE38 001DFE38 14740A0C */  jal        func_0029d050
    /* DFE3C 001DFE3C 00000000 */   nop
    /* DFE40 001DFE40 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFE44 001DFE44 24180302 */  and        $3, $16, $3
    /* DFE48 001DFE48 021E0300 */  srl        $3, $3, 24
    /* DFE4C 001DFE4C 3C2A1000 */  dsll32     $5, $16, 8
    /* DFE50 001DFE50 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFE54 001DFE54 04006014 */  bnez       $3, .L001DFE68
    /* DFE58 001DFE58 00000000 */   nop
    /* DFE5C 001DFE5C 2D100000 */  daddu      $2, $0, $0
    /* DFE60 001DFE60 0B000010 */  b          .L001DFE90
    /* DFE64 001DFE64 00000000 */   nop
  .L001DFE68:
    /* DFE68 001DFE68 2D204000 */  daddu      $4, $2, $0
    /* DFE6C 001DFE6C 40100300 */  sll        $2, $3, 1
    /* DFE70 001DFE70 21104300 */  addu       $2, $2, $3
    /* DFE74 001DFE74 80180200 */  sll        $3, $2, 2
    /* DFE78 001DFE78 6100023C */  lui        $2, %hi(D_00609850)
    /* DFE7C 001DFE7C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFE80 001DFE80 21104300 */  addu       $2, $2, $3
    /* DFE84 001DFE84 0000428C */  lw         $2, 0x0($2)
    /* DFE88 001DFE88 09F84000 */  jalr       $2
    /* DFE8C 001DFE8C 00000000 */   nop
  .L001DFE90:
    /* DFE90 001DFE90 2B200200 */  sltu       $4, $0, $2
    /* DFE94 001DFE94 D4730A0C */  jal        func_0029cf50
    /* DFE98 001DFE98 00000000 */   nop
    /* DFE9C 001DFE9C 01000224 */  addiu      $2, $0, 0x1
    /* DFEA0 001DFEA0 1000BFDF */  ld         $31, 0x10($29)
    /* DFEA4 001DFEA4 0000B07B */  lq         $16, 0x0($29)
    /* DFEA8 001DFEA8 2000BD27 */  addiu      $29, $29, 0x20
    /* DFEAC 001DFEAC 0800E003 */  jr         $31
    /* DFEB0 001DFEB0 00000000 */   nop
    /* DFEB4 001DFEB4 00000000 */  nop
    /* DFEB8 001DFEB8 00000000 */  nop
    /* DFEBC 001DFEBC 00000000 */  nop
.size func_001dfe10, 0xb0
