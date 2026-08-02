.section .text
.set noat
.set noreorder
glabel func_001dfaa0
    /* DFAA0 001DFAA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DFAA4 001DFAA4 1000BFFF */  sd         $31, 0x10($29)
    /* DFAA8 001DFAA8 0000B07F */  sq         $16, 0x0($29)
    /* DFAAC 001DFAAC 2D200000 */  daddu      $4, $0, $0
    /* DFAB0 001DFAB0 00730A0C */  jal        func_0029cc00
    /* DFAB4 001DFAB4 00000000 */   nop
    /* DFAB8 001DFAB8 3C1A0200 */  dsll32     $3, $2, 8
    /* DFABC 001DFABC 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFAC0 001DFAC0 000C023C */  lui        $2, (0xC000000 >> 16)
    /* DFAC4 001DFAC4 25806200 */  or         $16, $3, $2
    /* DFAC8 001DFAC8 14740A0C */  jal        func_0029d050
    /* DFACC 001DFACC 00000000 */   nop
    /* DFAD0 001DFAD0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFAD4 001DFAD4 24180302 */  and        $3, $16, $3
    /* DFAD8 001DFAD8 021E0300 */  srl        $3, $3, 24
    /* DFADC 001DFADC 3C2A1000 */  dsll32     $5, $16, 8
    /* DFAE0 001DFAE0 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFAE4 001DFAE4 04006014 */  bnez       $3, .L001DFAF8
    /* DFAE8 001DFAE8 00000000 */   nop
    /* DFAEC 001DFAEC 2D100000 */  daddu      $2, $0, $0
    /* DFAF0 001DFAF0 0B000010 */  b          .L001DFB20
    /* DFAF4 001DFAF4 00000000 */   nop
  .L001DFAF8:
    /* DFAF8 001DFAF8 2D204000 */  daddu      $4, $2, $0
    /* DFAFC 001DFAFC 40100300 */  sll        $2, $3, 1
    /* DFB00 001DFB00 21104300 */  addu       $2, $2, $3
    /* DFB04 001DFB04 80180200 */  sll        $3, $2, 2
    /* DFB08 001DFB08 6100023C */  lui        $2, %hi(D_00609850)
    /* DFB0C 001DFB0C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFB10 001DFB10 21104300 */  addu       $2, $2, $3
    /* DFB14 001DFB14 0000428C */  lw         $2, 0x0($2)
    /* DFB18 001DFB18 09F84000 */  jalr       $2
    /* DFB1C 001DFB1C 00000000 */   nop
  .L001DFB20:
    /* DFB20 001DFB20 2B200200 */  sltu       $4, $0, $2
    /* DFB24 001DFB24 D4730A0C */  jal        func_0029cf50
    /* DFB28 001DFB28 00000000 */   nop
    /* DFB2C 001DFB2C 01000224 */  addiu      $2, $0, 0x1
    /* DFB30 001DFB30 1000BFDF */  ld         $31, 0x10($29)
    /* DFB34 001DFB34 0000B07B */  lq         $16, 0x0($29)
    /* DFB38 001DFB38 2000BD27 */  addiu      $29, $29, 0x20
    /* DFB3C 001DFB3C 0800E003 */  jr         $31
    /* DFB40 001DFB40 00000000 */   nop
    /* DFB44 001DFB44 00000000 */  nop
    /* DFB48 001DFB48 00000000 */  nop
    /* DFB4C 001DFB4C 00000000 */  nop
.size func_001dfaa0, 0xb0
