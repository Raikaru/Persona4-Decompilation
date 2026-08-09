.section .text
.set noat
.set noreorder
glabel func_001daa50
    /* DAA50 001DAA50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DAA54 001DAA54 0000BFFF */  sd         $31, 0x0($29)
    /* DAA58 001DAA58 3000828C */  lw         $2, 0x30($4)
    /* DAA5C 001DAA5C A2004290 */  lbu        $2, 0xA2($2)
    /* DAA60 001DAA60 04004014 */  bnez       $2, .L001DAA74
    /* DAA64 001DAA64 00000000 */   nop
    /* DAA68 001DAA68 01000224 */  addiu      $2, $0, 0x1
    /* DAA6C 001DAA6C 02000010 */  b          .L001DAA78
    /* DAA70 001DAA70 00000000 */   nop
  .L001DAA74:
    /* DAA74 001DAA74 2D100000 */  daddu      $2, $0, $0
  .L001DAA78:
    /* DAA78 001DAA78 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DAA7C 001DAA7C 01000224 */  addiu      $2, $0, 0x1
    /* DAA80 001DAA80 04106200 */  sllv       $2, $2, $3
    /* DAA84 001DAA84 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DAA88 001DAA88 1800073C */  lui        $7, (0x180000 >> 16)
    /* DAA8C 001DAA8C 2D400000 */  daddu      $8, $0, $0
    /* DAA90 001DAA90 1E00093C */  lui        $9, %hi(func_001da230)
    /* DAA94 001DAA94 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DAA98 001DAA98 3465070C */  jal        func_001d94d0
    /* DAA9C 001DAA9C 00000000 */   nop
    /* DAAA0 001DAAA0 0000BFDF */  ld         $31, 0x0($29)
    /* DAAA4 001DAAA4 1000BD27 */  addiu      $29, $29, 0x10
    /* DAAA8 001DAAA8 0800E003 */  jr         $31
    /* DAAAC 001DAAAC 00000000 */   nop
.size func_001daa50, 0x60
