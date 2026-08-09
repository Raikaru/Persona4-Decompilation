.section .text
.set noat
.set noreorder
glabel func_001da730
    /* DA730 001DA730 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA734 001DA734 0000BFFF */  sd         $31, 0x0($29)
    /* DA738 001DA738 3000828C */  lw         $2, 0x30($4)
    /* DA73C 001DA73C A2004390 */  lbu        $3, 0xA2($2)
    /* DA740 001DA740 01000224 */  addiu      $2, $0, 0x1
    /* DA744 001DA744 04106200 */  sllv       $2, $2, $3
    /* DA748 001DA748 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA74C 001DA74C 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA750 001DA750 2D400000 */  daddu      $8, $0, $0
    /* DA754 001DA754 1E00093C */  lui        $9, %hi(func_001da6f0)
    /* DA758 001DA758 F0A62925 */  addiu      $9, $9, %lo(func_001da6f0)
    /* DA75C 001DA75C 3465070C */  jal        func_001d94d0
    /* DA760 001DA760 00000000 */   nop
    /* DA764 001DA764 0000BFDF */  ld         $31, 0x0($29)
    /* DA768 001DA768 1000BD27 */  addiu      $29, $29, 0x10
    /* DA76C 001DA76C 0800E003 */  jr         $31
    /* DA770 001DA770 00000000 */   nop
    /* DA774 001DA774 00000000 */  nop
    /* DA778 001DA778 00000000 */  nop
    /* DA77C 001DA77C 00000000 */  nop
.size func_001da730, 0x50
