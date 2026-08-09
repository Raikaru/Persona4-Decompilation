.section .text
.set noat
.set noreorder
glabel func_001da490
    /* DA490 001DA490 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA494 001DA494 0000BFFF */  sd         $31, 0x0($29)
    /* DA498 001DA498 3000828C */  lw         $2, 0x30($4)
    /* DA49C 001DA49C A2004390 */  lbu        $3, 0xA2($2)
    /* DA4A0 001DA4A0 01000224 */  addiu      $2, $0, 0x1
    /* DA4A4 001DA4A4 04106200 */  sllv       $2, $2, $3
    /* DA4A8 001DA4A8 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA4AC 001DA4AC 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA4B0 001DA4B0 2D400000 */  daddu      $8, $0, $0
    /* DA4B4 001DA4B4 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DA4B8 001DA4B8 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DA4BC 001DA4BC 3465070C */  jal        func_001d94d0
    /* DA4C0 001DA4C0 00000000 */   nop
    /* DA4C4 001DA4C4 0000BFDF */  ld         $31, 0x0($29)
    /* DA4C8 001DA4C8 1000BD27 */  addiu      $29, $29, 0x10
    /* DA4CC 001DA4CC 0800E003 */  jr         $31
    /* DA4D0 001DA4D0 00000000 */   nop
    /* DA4D4 001DA4D4 00000000 */  nop
    /* DA4D8 001DA4D8 00000000 */  nop
    /* DA4DC 001DA4DC 00000000 */  nop
.size func_001da490, 0x50
