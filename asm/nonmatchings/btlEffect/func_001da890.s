.section .text
.set noat
.set noreorder
glabel func_001da890
    /* DA890 001DA890 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DA894 001DA894 0000BFFF */  sd         $31, 0x0($29)
    /* DA898 001DA898 3000828C */  lw         $2, 0x30($4)
    /* DA89C 001DA89C A2004290 */  lbu        $2, 0xA2($2)
    /* DA8A0 001DA8A0 04004014 */  bnez       $2, .L001DA8B4
    /* DA8A4 001DA8A4 00000000 */   nop
    /* DA8A8 001DA8A8 01000224 */  addiu      $2, $0, 0x1
    /* DA8AC 001DA8AC 02000010 */  b          .L001DA8B8
    /* DA8B0 001DA8B0 00000000 */   nop
  .L001DA8B4:
    /* DA8B4 001DA8B4 2D100000 */  daddu      $2, $0, $0
  .L001DA8B8:
    /* DA8B8 001DA8B8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DA8BC 001DA8BC 01000224 */  addiu      $2, $0, 0x1
    /* DA8C0 001DA8C0 04106200 */  sllv       $2, $2, $3
    /* DA8C4 001DA8C4 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DA8C8 001DA8C8 0800073C */  lui        $7, (0x80000 >> 16)
    /* DA8CC 001DA8CC 2D400000 */  daddu      $8, $0, $0
    /* DA8D0 001DA8D0 1E00093C */  lui        $9, %hi(func_001da7e0)
    /* DA8D4 001DA8D4 E0A72925 */  addiu      $9, $9, %lo(func_001da7e0)
    /* DA8D8 001DA8D8 3465070C */  jal        func_001d94d0
    /* DA8DC 001DA8DC 00000000 */   nop
    /* DA8E0 001DA8E0 0000BFDF */  ld         $31, 0x0($29)
    /* DA8E4 001DA8E4 1000BD27 */  addiu      $29, $29, 0x10
    /* DA8E8 001DA8E8 0800E003 */  jr         $31
    /* DA8EC 001DA8EC 00000000 */   nop
.size func_001da890, 0x60
