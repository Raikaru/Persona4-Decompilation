.section .text
.set noat
.set noreorder
glabel func_001db040
    /* DB040 001DB040 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB044 001DB044 0000BFFF */  sd         $31, 0x0($29)
    /* DB048 001DB048 3000828C */  lw         $2, 0x30($4)
    /* DB04C 001DB04C A2004290 */  lbu        $2, 0xA2($2)
    /* DB050 001DB050 04004014 */  bnez       $2, .L001DB064
    /* DB054 001DB054 00000000 */   nop
    /* DB058 001DB058 01000224 */  addiu      $2, $0, 0x1
    /* DB05C 001DB05C 02000010 */  b          .L001DB068
    /* DB060 001DB060 00000000 */   nop
  .L001DB064:
    /* DB064 001DB064 2D100000 */  daddu      $2, $0, $0
  .L001DB068:
    /* DB068 001DB068 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DB06C 001DB06C 01000224 */  addiu      $2, $0, 0x1
    /* DB070 001DB070 04106200 */  sllv       $2, $2, $3
    /* DB074 001DB074 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DB078 001DB078 0800073C */  lui        $7, (0x80000 >> 16)
    /* DB07C 001DB07C 06000824 */  addiu      $8, $0, 0x6
    /* DB080 001DB080 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DB084 001DB084 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DB088 001DB088 3465070C */  jal        func_001d94d0
    /* DB08C 001DB08C 00000000 */   nop
    /* DB090 001DB090 0000BFDF */  ld         $31, 0x0($29)
    /* DB094 001DB094 1000BD27 */  addiu      $29, $29, 0x10
    /* DB098 001DB098 0800E003 */  jr         $31
    /* DB09C 001DB09C 00000000 */   nop
.size func_001db040, 0x60
