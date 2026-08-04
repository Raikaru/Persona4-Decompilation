.section .text
.set noat
.set noreorder
glabel func_001da330
    /* DA330 001DA330 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA334 001DA334 0000BFFF */  sd         $31, 0x0($29)
    /* DA338 001DA338 3000828C */  lw         $2, 0x30($4)
    /* DA33C 001DA33C A2004390 */  lbu        $3, 0xA2($2)
    /* DA340 001DA340 01000224 */  addiu      $2, $0, 0x1
    /* DA344 001DA344 04106200 */  sllv       $2, $2, $3
    /* DA348 001DA348 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA34C 001DA34C 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA350 001DA350 2D400000 */  daddu      $8, $0, $0
    /* DA354 001DA354 1E00093C */  lui        $9, %hi(func_001da230)
    /* DA358 001DA358 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DA35C 001DA35C 3465070C */  jal        func_001d94d0
    /* DA360 001DA360 00000000 */   nop
    /* DA364 001DA364 0000BFDF */  ld         $31, 0x0($29)
    /* DA368 001DA368 1000BD27 */  addiu      $29, $29, 0x10
    /* DA36C 001DA36C 0800E003 */  jr         $31
    /* DA370 001DA370 00000000 */   nop
    /* DA374 001DA374 00000000 */  nop
    /* DA378 001DA378 00000000 */  nop
    /* DA37C 001DA37C 00000000 */  nop
.size func_001da330, 0x50
