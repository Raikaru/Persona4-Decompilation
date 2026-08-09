.section .text
.set noat
.set noreorder
glabel func_004bf498
    /* 3BF498 004BF498 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BF49C 004BF49C 2D288000 */  daddu      $5, $4, $0
    /* 3BF4A0 004BF4A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3BF4A4 004BF4A4 5000A28C */  lw         $2, 0x50($5)
    /* 3BF4A8 004BF4A8 07004054 */  bnel       $2, $0, .L004BF4C8
    /* 3BF4AC 004BF4AC 9400A48C */   lw        $4, 0x94($5)
    /* 3BF4B0 004BF4B0 7500043C */  lui        $4, %hi(D_007570D8)
    /* 3BF4B4 004BF4B4 A8F5120C */  jal        func_004bd6a0
    /* 3BF4B8 004BF4B8 D8708424 */   addiu     $4, $4, %lo(D_007570D8)
    /* 3BF4BC 004BF4BC 11000010 */  b          .L004BF504
    /* 3BF4C0 004BF4C0 2D100000 */   daddu     $2, $0, $0
    /* 3BF4C4 004BF4C4 00000000 */  nop
  .L004BF4C8:
    /* 3BF4C8 004BF4C8 01000324 */  addiu      $3, $0, 0x1
    /* 3BF4CC 004BF4CC 0D008310 */  beq        $4, $3, .L004BF504
    /* 3BF4D0 004BF4D0 2D100000 */   daddu     $2, $0, $0
    /* 3BF4D4 004BF4D4 1000A28C */  lw         $2, 0x10($5)
    /* 3BF4D8 004BF4D8 A000A38C */  lw         $3, 0xA0($5)
    /* 3BF4DC 004BF4DC 01004224 */  addiu      $2, $2, 0x1
    /* 3BF4E0 004BF4E0 2A184300 */  slt        $3, $2, $3
    /* 3BF4E4 004BF4E4 0A100300 */  movz       $2, $0, $3
    /* 3BF4E8 004BF4E8 80100200 */  sll        $2, $2, 2
    /* 3BF4EC 004BF4EC 2110A200 */  addu       $2, $5, $2
    /* 3BF4F0 004BF4F0 0000448C */  lw         $4, 0x0($2)
    /* 3BF4F4 004BF4F4 0000838C */  lw         $3, 0x0($4)
    /* 3BF4F8 004BF4F8 3C00628C */  lw         $2, 0x3C($3)
    /* 3BF4FC 004BF4FC 09F84000 */  jalr       $2
    /* 3BF500 004BF500 00000000 */   nop
  .L004BF504:
    /* 3BF504 004BF504 0000BFDF */  ld         $31, 0x0($29)
    /* 3BF508 004BF508 0800E003 */  jr         $31
    /* 3BF50C 004BF50C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bf498, 0x78
