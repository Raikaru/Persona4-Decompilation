.section .text
.set noat
.set noreorder
glabel func_001db0a0
    /* DB0A0 001DB0A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB0A4 001DB0A4 0000BFFF */  sd         $31, 0x0($29)
    /* DB0A8 001DB0A8 3000828C */  lw         $2, 0x30($4)
    /* DB0AC 001DB0AC A2004290 */  lbu        $2, 0xA2($2)
    /* DB0B0 001DB0B0 04004014 */  bnez       $2, .L001DB0C4
    /* DB0B4 001DB0B4 00000000 */   nop
    /* DB0B8 001DB0B8 01000224 */  addiu      $2, $0, 0x1
    /* DB0BC 001DB0BC 02000010 */  b          .L001DB0C8
    /* DB0C0 001DB0C0 00000000 */   nop
  .L001DB0C4:
    /* DB0C4 001DB0C4 2D100000 */  daddu      $2, $0, $0
  .L001DB0C8:
    /* DB0C8 001DB0C8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DB0CC 001DB0CC 01000224 */  addiu      $2, $0, 0x1
    /* DB0D0 001DB0D0 04106200 */  sllv       $2, $2, $3
    /* DB0D4 001DB0D4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DB0D8 001DB0D8 1800073C */  lui        $7, (0x180000 >> 16)
    /* DB0DC 001DB0DC 06000824 */  addiu      $8, $0, 0x6
    /* DB0E0 001DB0E0 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DB0E4 001DB0E4 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DB0E8 001DB0E8 3465070C */  jal        func_001d94d0
    /* DB0EC 001DB0EC 00000000 */   nop
    /* DB0F0 001DB0F0 0000BFDF */  ld         $31, 0x0($29)
    /* DB0F4 001DB0F4 1000BD27 */  addiu      $29, $29, 0x10
    /* DB0F8 001DB0F8 0800E003 */  jr         $31
    /* DB0FC 001DB0FC 00000000 */   nop
.size func_001db0a0, 0x60
