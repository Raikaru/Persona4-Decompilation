.section .text
.set noat
.set noreorder
glabel func_001db680
    /* DB680 001DB680 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB684 001DB684 0000BFFF */  sd         $31, 0x0($29)
    /* DB688 001DB688 3000828C */  lw         $2, 0x30($4)
    /* DB68C 001DB68C A2004290 */  lbu        $2, 0xA2($2)
    /* DB690 001DB690 04004014 */  bnez       $2, .L001DB6A4
    /* DB694 001DB694 00000000 */   nop
    /* DB698 001DB698 01000224 */  addiu      $2, $0, 0x1
    /* DB69C 001DB69C 02000010 */  b          .L001DB6A8
    /* DB6A0 001DB6A0 00000000 */   nop
  .L001DB6A4:
    /* DB6A4 001DB6A4 2D100000 */  daddu      $2, $0, $0
  .L001DB6A8:
    /* DB6A8 001DB6A8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DB6AC 001DB6AC 01000224 */  addiu      $2, $0, 0x1
    /* DB6B0 001DB6B0 04106200 */  sllv       $2, $2, $3
    /* DB6B4 001DB6B4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DB6B8 001DB6B8 1800073C */  lui        $7, (0x180000 >> 16)
    /* DB6BC 001DB6BC 0A000824 */  addiu      $8, $0, 0xA
    /* DB6C0 001DB6C0 1E00093C */  lui        $9, %hi(func_001db580)
    /* DB6C4 001DB6C4 80B52925 */  addiu      $9, $9, %lo(func_001db580)
    /* DB6C8 001DB6C8 3465070C */  jal        func_001d94d0
    /* DB6CC 001DB6CC 00000000 */   nop
    /* DB6D0 001DB6D0 0000BFDF */  ld         $31, 0x0($29)
    /* DB6D4 001DB6D4 1000BD27 */  addiu      $29, $29, 0x10
    /* DB6D8 001DB6D8 0800E003 */  jr         $31
    /* DB6DC 001DB6DC 00000000 */   nop
.size func_001db680, 0x60
