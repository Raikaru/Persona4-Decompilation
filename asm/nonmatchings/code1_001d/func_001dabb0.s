.section .text
.set noat
.set noreorder
glabel func_001dabb0
    /* DABB0 001DABB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DABB4 001DABB4 0000BFFF */  sd         $31, 0x0($29)
    /* DABB8 001DABB8 3000828C */  lw         $2, 0x30($4)
    /* DABBC 001DABBC A2004290 */  lbu        $2, 0xA2($2)
    /* DABC0 001DABC0 04004014 */  bnez       $2, .L001DABD4
    /* DABC4 001DABC4 00000000 */   nop
    /* DABC8 001DABC8 01000224 */  addiu      $2, $0, 0x1
    /* DABCC 001DABCC 02000010 */  b          .L001DABD8
    /* DABD0 001DABD0 00000000 */   nop
  .L001DABD4:
    /* DABD4 001DABD4 2D100000 */  daddu      $2, $0, $0
  .L001DABD8:
    /* DABD8 001DABD8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DABDC 001DABDC 01000224 */  addiu      $2, $0, 0x1
    /* DABE0 001DABE0 04106200 */  sllv       $2, $2, $3
    /* DABE4 001DABE4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DABE8 001DABE8 1800073C */  lui        $7, (0x180000 >> 16)
    /* DABEC 001DABEC 2D400000 */  daddu      $8, $0, $0
    /* DABF0 001DABF0 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DABF4 001DABF4 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DABF8 001DABF8 3465070C */  jal        func_001d94d0
    /* DABFC 001DABFC 00000000 */   nop
    /* DAC00 001DAC00 0000BFDF */  ld         $31, 0x0($29)
    /* DAC04 001DAC04 1000BD27 */  addiu      $29, $29, 0x10
    /* DAC08 001DAC08 0800E003 */  jr         $31
    /* DAC0C 001DAC0C 00000000 */   nop
.size func_001dabb0, 0x60
