.section .text
.set noat
.set noreorder
glabel func_001da4e0
    /* DA4E0 001DA4E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA4E4 001DA4E4 0000BFFF */  sd         $31, 0x0($29)
    /* DA4E8 001DA4E8 3000828C */  lw         $2, 0x30($4)
    /* DA4EC 001DA4EC A2004290 */  lbu        $2, 0xA2($2)
    /* DA4F0 001DA4F0 04004014 */  bnez       $2, .L001DA504
    /* DA4F4 001DA4F4 00000000 */   nop
    /* DA4F8 001DA4F8 01000224 */  addiu      $2, $0, 0x1
    /* DA4FC 001DA4FC 02000010 */  b          .L001DA508
    /* DA500 001DA500 00000000 */   nop
  .L001DA504:
    /* DA504 001DA504 2D100000 */  daddu      $2, $0, $0
  .L001DA508:
    /* DA508 001DA508 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DA50C 001DA50C 01000224 */  addiu      $2, $0, 0x1
    /* DA510 001DA510 04106200 */  sllv       $2, $2, $3
    /* DA514 001DA514 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA518 001DA518 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA51C 001DA51C 2D400000 */  daddu      $8, $0, $0
    /* DA520 001DA520 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DA524 001DA524 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DA528 001DA528 3465070C */  jal        func_001d94d0
    /* DA52C 001DA52C 00000000 */   nop
    /* DA530 001DA530 0000BFDF */  ld         $31, 0x0($29)
    /* DA534 001DA534 1000BD27 */  addiu      $29, $29, 0x10
    /* DA538 001DA538 0800E003 */  jr         $31
    /* DA53C 001DA53C 00000000 */   nop
.size func_001da4e0, 0x60
