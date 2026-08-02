.section .text
.set noat
.set noreorder
glabel func_001dfd60
    /* DFD60 001DFD60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DFD64 001DFD64 1000BFFF */  sd         $31, 0x10($29)
    /* DFD68 001DFD68 0000B07F */  sq         $16, 0x0($29)
    /* DFD6C 001DFD6C 2D200000 */  daddu      $4, $0, $0
    /* DFD70 001DFD70 00730A0C */  jal        func_0029cc00
    /* DFD74 001DFD74 00000000 */   nop
    /* DFD78 001DFD78 3C1A0200 */  dsll32     $3, $2, 8
    /* DFD7C 001DFD7C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFD80 001DFD80 0010023C */  lui        $2, (0x10000000 >> 16)
    /* DFD84 001DFD84 25806200 */  or         $16, $3, $2
    /* DFD88 001DFD88 14740A0C */  jal        func_0029d050
    /* DFD8C 001DFD8C 00000000 */   nop
    /* DFD90 001DFD90 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFD94 001DFD94 24180302 */  and        $3, $16, $3
    /* DFD98 001DFD98 021E0300 */  srl        $3, $3, 24
    /* DFD9C 001DFD9C 3C2A1000 */  dsll32     $5, $16, 8
    /* DFDA0 001DFDA0 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFDA4 001DFDA4 04006014 */  bnez       $3, .L001DFDB8
    /* DFDA8 001DFDA8 00000000 */   nop
    /* DFDAC 001DFDAC 2D100000 */  daddu      $2, $0, $0
    /* DFDB0 001DFDB0 0B000010 */  b          .L001DFDE0
    /* DFDB4 001DFDB4 00000000 */   nop
  .L001DFDB8:
    /* DFDB8 001DFDB8 2D204000 */  daddu      $4, $2, $0
    /* DFDBC 001DFDBC 40100300 */  sll        $2, $3, 1
    /* DFDC0 001DFDC0 21104300 */  addu       $2, $2, $3
    /* DFDC4 001DFDC4 80180200 */  sll        $3, $2, 2
    /* DFDC8 001DFDC8 6100023C */  lui        $2, %hi(D_00609850)
    /* DFDCC 001DFDCC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFDD0 001DFDD0 21104300 */  addu       $2, $2, $3
    /* DFDD4 001DFDD4 0000428C */  lw         $2, 0x0($2)
    /* DFDD8 001DFDD8 09F84000 */  jalr       $2
    /* DFDDC 001DFDDC 00000000 */   nop
  .L001DFDE0:
    /* DFDE0 001DFDE0 2B200200 */  sltu       $4, $0, $2
    /* DFDE4 001DFDE4 D4730A0C */  jal        func_0029cf50
    /* DFDE8 001DFDE8 00000000 */   nop
    /* DFDEC 001DFDEC 01000224 */  addiu      $2, $0, 0x1
    /* DFDF0 001DFDF0 1000BFDF */  ld         $31, 0x10($29)
    /* DFDF4 001DFDF4 0000B07B */  lq         $16, 0x0($29)
    /* DFDF8 001DFDF8 2000BD27 */  addiu      $29, $29, 0x20
    /* DFDFC 001DFDFC 0800E003 */  jr         $31
    /* DFE00 001DFE00 00000000 */   nop
    /* DFE04 001DFE04 00000000 */  nop
    /* DFE08 001DFE08 00000000 */  nop
    /* DFE0C 001DFE0C 00000000 */  nop
.size func_001dfd60, 0xb0
