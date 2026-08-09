.section .text
.set noat
.set noreorder
glabel func_0052bfb0
    /* 42BFB0 0052BFB0 7400023C */  lui        $2, %hi(D_00746138)
    /* 42BFB4 0052BFB4 2D300000 */  daddu      $6, $0, $0
    /* 42BFB8 0052BFB8 38614224 */  addiu      $2, $2, %lo(D_00746138)
    /* 42BFBC 0052BFBC 0800458C */  lw         $5, 0x8($2)
    /* 42BFC0 0052BFC0 0C00A018 */  blez       $5, .L0052BFF4
    /* 42BFC4 0052BFC4 0C004224 */   addiu     $2, $2, 0xC
    /* 42BFC8 0052BFC8 2D204000 */  daddu      $4, $2, $0
    /* 42BFCC 0052BFCC 00000000 */  nop
  .L0052BFD0:
    /* 42BFD0 0052BFD0 0000838C */  lw         $3, 0x0($4)
    /* 42BFD4 0052BFD4 2D108000 */  daddu      $2, $4, $0
    /* 42BFD8 0052BFD8 07006010 */  beqz       $3, .L0052BFF8
    /* 42BFDC 0052BFDC 4C008424 */   addiu     $4, $4, 0x4C
    /* 42BFE0 0052BFE0 0100C624 */  addiu      $6, $6, 0x1
    /* 42BFE4 0052BFE4 2A10C500 */  slt        $2, $6, $5
    /* 42BFE8 0052BFE8 00000000 */  nop
    /* 42BFEC 0052BFEC F8FF4014 */  bnez       $2, .L0052BFD0
    /* 42BFF0 0052BFF0 00000000 */   nop
  .L0052BFF4:
    /* 42BFF4 0052BFF4 2D100000 */  daddu      $2, $0, $0
  .L0052BFF8:
    /* 42BFF8 0052BFF8 0800E003 */  jr         $31
    /* 42BFFC 0052BFFC 00000000 */   nop
.size func_0052bfb0, 0x50
