.section .text
.set noat
.set noreorder
glabel func_001da380
    /* DA380 001DA380 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA384 001DA384 0000BFFF */  sd         $31, 0x0($29)
    /* DA388 001DA388 3000828C */  lw         $2, 0x30($4)
    /* DA38C 001DA38C A2004290 */  lbu        $2, 0xA2($2)
    /* DA390 001DA390 04004014 */  bnez       $2, .L001DA3A4
    /* DA394 001DA394 00000000 */   nop
    /* DA398 001DA398 01000224 */  addiu      $2, $0, 0x1
    /* DA39C 001DA39C 02000010 */  b          .L001DA3A8
    /* DA3A0 001DA3A0 00000000 */   nop
  .L001DA3A4:
    /* DA3A4 001DA3A4 2D100000 */  daddu      $2, $0, $0
  .L001DA3A8:
    /* DA3A8 001DA3A8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DA3AC 001DA3AC 01000224 */  addiu      $2, $0, 0x1
    /* DA3B0 001DA3B0 04106200 */  sllv       $2, $2, $3
    /* DA3B4 001DA3B4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA3B8 001DA3B8 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA3BC 001DA3BC 2D400000 */  daddu      $8, $0, $0
    /* DA3C0 001DA3C0 1E00093C */  lui        $9, %hi(func_001da230)
    /* DA3C4 001DA3C4 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DA3C8 001DA3C8 3465070C */  jal        func_001d94d0
    /* DA3CC 001DA3CC 00000000 */   nop
    /* DA3D0 001DA3D0 0000BFDF */  ld         $31, 0x0($29)
    /* DA3D4 001DA3D4 1000BD27 */  addiu      $29, $29, 0x10
    /* DA3D8 001DA3D8 0800E003 */  jr         $31
    /* DA3DC 001DA3DC 00000000 */   nop
.size func_001da380, 0x60
