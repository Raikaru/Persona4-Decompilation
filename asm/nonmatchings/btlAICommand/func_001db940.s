.section .text
.set noat
.set noreorder
glabel func_001db940
    /* DB940 001DB940 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB944 001DB944 0000BFFF */  sd         $31, 0x0($29)
    /* DB948 001DB948 3000828C */  lw         $2, 0x30($4)
    /* DB94C 001DB94C A2004390 */  lbu        $3, 0xA2($2)
    /* DB950 001DB950 01000224 */  addiu      $2, $0, 0x1
    /* DB954 001DB954 04106200 */  sllv       $2, $2, $3
    /* DB958 001DB958 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DB95C 001DB95C 0800073C */  lui        $7, (0x80000 >> 16)
    /* DB960 001DB960 2D400000 */  daddu      $8, $0, $0
    /* DB964 001DB964 1E00093C */  lui        $9, %hi(func_001db900)
    /* DB968 001DB968 00B92925 */  addiu      $9, $9, %lo(func_001db900)
    /* DB96C 001DB96C 3465070C */  jal        func_001d94d0
    /* DB970 001DB970 00000000 */   nop
    /* DB974 001DB974 0000BFDF */  ld         $31, 0x0($29)
    /* DB978 001DB978 1000BD27 */  addiu      $29, $29, 0x10
    /* DB97C 001DB97C 0800E003 */  jr         $31
    /* DB980 001DB980 00000000 */   nop
    /* DB984 001DB984 00000000 */  nop
    /* DB988 001DB988 00000000 */  nop
    /* DB98C 001DB98C 00000000 */  nop
.size func_001db940, 0x50
