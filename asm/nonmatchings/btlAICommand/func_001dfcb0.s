.section .text
.set noat
.set noreorder
glabel func_001dfcb0
    /* DFCB0 001DFCB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DFCB4 001DFCB4 1000BFFF */  sd         $31, 0x10($29)
    /* DFCB8 001DFCB8 0000B07F */  sq         $16, 0x0($29)
    /* DFCBC 001DFCBC 2D200000 */  daddu      $4, $0, $0
    /* DFCC0 001DFCC0 00730A0C */  jal        func_0029cc00
    /* DFCC4 001DFCC4 00000000 */   nop
    /* DFCC8 001DFCC8 3C1A0200 */  dsll32     $3, $2, 8
    /* DFCCC 001DFCCC 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFCD0 001DFCD0 000F023C */  lui        $2, (0xF000000 >> 16)
    /* DFCD4 001DFCD4 25806200 */  or         $16, $3, $2
    /* DFCD8 001DFCD8 14740A0C */  jal        func_0029d050
    /* DFCDC 001DFCDC 00000000 */   nop
    /* DFCE0 001DFCE0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFCE4 001DFCE4 24180302 */  and        $3, $16, $3
    /* DFCE8 001DFCE8 021E0300 */  srl        $3, $3, 24
    /* DFCEC 001DFCEC 3C2A1000 */  dsll32     $5, $16, 8
    /* DFCF0 001DFCF0 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFCF4 001DFCF4 04006014 */  bnez       $3, .L001DFD08
    /* DFCF8 001DFCF8 00000000 */   nop
    /* DFCFC 001DFCFC 2D100000 */  daddu      $2, $0, $0
    /* DFD00 001DFD00 0B000010 */  b          .L001DFD30
    /* DFD04 001DFD04 00000000 */   nop
  .L001DFD08:
    /* DFD08 001DFD08 2D204000 */  daddu      $4, $2, $0
    /* DFD0C 001DFD0C 40100300 */  sll        $2, $3, 1
    /* DFD10 001DFD10 21104300 */  addu       $2, $2, $3
    /* DFD14 001DFD14 80180200 */  sll        $3, $2, 2
    /* DFD18 001DFD18 6100023C */  lui        $2, %hi(D_00609850)
    /* DFD1C 001DFD1C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFD20 001DFD20 21104300 */  addu       $2, $2, $3
    /* DFD24 001DFD24 0000428C */  lw         $2, 0x0($2)
    /* DFD28 001DFD28 09F84000 */  jalr       $2
    /* DFD2C 001DFD2C 00000000 */   nop
  .L001DFD30:
    /* DFD30 001DFD30 2B200200 */  sltu       $4, $0, $2
    /* DFD34 001DFD34 D4730A0C */  jal        func_0029cf50
    /* DFD38 001DFD38 00000000 */   nop
    /* DFD3C 001DFD3C 01000224 */  addiu      $2, $0, 0x1
    /* DFD40 001DFD40 1000BFDF */  ld         $31, 0x10($29)
    /* DFD44 001DFD44 0000B07B */  lq         $16, 0x0($29)
    /* DFD48 001DFD48 2000BD27 */  addiu      $29, $29, 0x20
    /* DFD4C 001DFD4C 0800E003 */  jr         $31
    /* DFD50 001DFD50 00000000 */   nop
    /* DFD54 001DFD54 00000000 */  nop
    /* DFD58 001DFD58 00000000 */  nop
    /* DFD5C 001DFD5C 00000000 */  nop
.size func_001dfcb0, 0xb0
