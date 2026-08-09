.section .text
.set noat
.set noreorder
glabel func_001da540
    /* DA540 001DA540 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA544 001DA544 0000BFFF */  sd         $31, 0x0($29)
    /* DA548 001DA548 3000828C */  lw         $2, 0x30($4)
    /* DA54C 001DA54C A2004390 */  lbu        $3, 0xA2($2)
    /* DA550 001DA550 01000224 */  addiu      $2, $0, 0x1
    /* DA554 001DA554 04106200 */  sllv       $2, $2, $3
    /* DA558 001DA558 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA55C 001DA55C 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA560 001DA560 2D400000 */  daddu      $8, $0, $0
    /* DA564 001DA564 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DA568 001DA568 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DA56C 001DA56C 3465070C */  jal        func_001d94d0
    /* DA570 001DA570 00000000 */   nop
    /* DA574 001DA574 0000BFDF */  ld         $31, 0x0($29)
    /* DA578 001DA578 1000BD27 */  addiu      $29, $29, 0x10
    /* DA57C 001DA57C 0800E003 */  jr         $31
    /* DA580 001DA580 00000000 */   nop
    /* DA584 001DA584 00000000 */  nop
    /* DA588 001DA588 00000000 */  nop
    /* DA58C 001DA58C 00000000 */  nop
.size func_001da540, 0x50
