.section .text
.set noat
.set noreorder
glabel func_004bf590
    /* 3BF590 004BF590 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BF594 004BF594 2D288000 */  daddu      $5, $4, $0
    /* 3BF598 004BF598 0000BFFF */  sd         $31, 0x0($29)
    /* 3BF59C 004BF59C 5000A28C */  lw         $2, 0x50($5)
    /* 3BF5A0 004BF5A0 07004054 */  bnel       $2, $0, .L004BF5C0
    /* 3BF5A4 004BF5A4 9400A48C */   lw        $4, 0x94($5)
    /* 3BF5A8 004BF5A8 7500043C */  lui        $4, %hi(D_00757140)
    /* 3BF5AC 004BF5AC A8F5120C */  jal        func_004bd6a0
    /* 3BF5B0 004BF5B0 40718424 */   addiu     $4, $4, %lo(D_00757140)
    /* 3BF5B4 004BF5B4 06000010 */  b          .L004BF5D0
    /* 3BF5B8 004BF5B8 2D100000 */   daddu     $2, $0, $0
    /* 3BF5BC 004BF5BC 00000000 */  nop
  .L004BF5C0:
    /* 3BF5C0 004BF5C0 01000324 */  addiu      $3, $0, 0x1
    /* 3BF5C4 004BF5C4 02008310 */  beq        $4, $3, .L004BF5D0
    /* 3BF5C8 004BF5C8 2D100000 */   daddu     $2, $0, $0
    /* 3BF5CC 004BF5CC A000A28C */  lw         $2, 0xA0($5)
  .L004BF5D0:
    /* 3BF5D0 004BF5D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3BF5D4 004BF5D4 0800E003 */  jr         $31
    /* 3BF5D8 004BF5D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BF5DC 004BF5DC 00000000 */  nop
.size func_004bf590, 0x50
