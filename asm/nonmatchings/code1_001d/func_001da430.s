.section .text
.set noat
.set noreorder
glabel func_001da430
    /* DA430 001DA430 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA434 001DA434 0000BFFF */  sd         $31, 0x0($29)
    /* DA438 001DA438 3000828C */  lw         $2, 0x30($4)
    /* DA43C 001DA43C A2004290 */  lbu        $2, 0xA2($2)
    /* DA440 001DA440 04004014 */  bnez       $2, .L001DA454
    /* DA444 001DA444 00000000 */   nop
    /* DA448 001DA448 01000224 */  addiu      $2, $0, 0x1
    /* DA44C 001DA44C 02000010 */  b          .L001DA458
    /* DA450 001DA450 00000000 */   nop
  .L001DA454:
    /* DA454 001DA454 2D100000 */  daddu      $2, $0, $0
  .L001DA458:
    /* DA458 001DA458 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DA45C 001DA45C 01000224 */  addiu      $2, $0, 0x1
    /* DA460 001DA460 04106200 */  sllv       $2, $2, $3
    /* DA464 001DA464 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA468 001DA468 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA46C 001DA46C 2D400000 */  daddu      $8, $0, $0
    /* DA470 001DA470 1E00093C */  lui        $9, %hi(func_001da270)
    /* DA474 001DA474 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DA478 001DA478 3465070C */  jal        func_001d94d0
    /* DA47C 001DA47C 00000000 */   nop
    /* DA480 001DA480 0000BFDF */  ld         $31, 0x0($29)
    /* DA484 001DA484 1000BD27 */  addiu      $29, $29, 0x10
    /* DA488 001DA488 0800E003 */  jr         $31
    /* DA48C 001DA48C 00000000 */   nop
.size func_001da430, 0x60
