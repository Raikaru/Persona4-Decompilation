.section .text
.set noat
.set noreorder
glabel func_004bf438
    /* 3BF438 004BF438 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BF43C 004BF43C 2D288000 */  daddu      $5, $4, $0
    /* 3BF440 004BF440 0000BFFF */  sd         $31, 0x0($29)
    /* 3BF444 004BF444 5000A28C */  lw         $2, 0x50($5)
    /* 3BF448 004BF448 07004054 */  bnel       $2, $0, .L004BF468
    /* 3BF44C 004BF44C 9400A48C */   lw        $4, 0x94($5)
    /* 3BF450 004BF450 7500043C */  lui        $4, %hi(D_007570A0)
    /* 3BF454 004BF454 A8F5120C */  jal        func_004bd6a0
    /* 3BF458 004BF458 A0708424 */   addiu     $4, $4, %lo(D_007570A0)
    /* 3BF45C 004BF45C 0B000010 */  b          .L004BF48C
    /* 3BF460 004BF460 2D100000 */   daddu     $2, $0, $0
    /* 3BF464 004BF464 00000000 */  nop
  .L004BF468:
    /* 3BF468 004BF468 01000324 */  addiu      $3, $0, 0x1
    /* 3BF46C 004BF46C 07008310 */  beq        $4, $3, .L004BF48C
    /* 3BF470 004BF470 2D100000 */   daddu     $2, $0, $0
    /* 3BF474 004BF474 0800A28C */  lw         $2, 0x8($5)
    /* 3BF478 004BF478 0000438C */  lw         $3, 0x0($2)
    /* 3BF47C 004BF47C 2D204000 */  daddu      $4, $2, $0
    /* 3BF480 004BF480 3C00628C */  lw         $2, 0x3C($3)
    /* 3BF484 004BF484 09F84000 */  jalr       $2
    /* 3BF488 004BF488 00000000 */   nop
  .L004BF48C:
    /* 3BF48C 004BF48C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BF490 004BF490 0800E003 */  jr         $31
    /* 3BF494 004BF494 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bf438, 0x60
