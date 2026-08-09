.section .text
.set noat
.set noreorder
glabel func_004dee18
    /* 3DEE18 004DEE18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DEE1C 004DEE1C 06008014 */  bnez       $4, .L004DEE38
    /* 3DEE20 004DEE20 0000BFFF */   sd        $31, 0x0($29)
    /* 3DEE24 004DEE24 7600043C */  lui        $4, %hi(D_007597C8)
    /* 3DEE28 004DEE28 B078130C */  jal        func_004de2c0
    /* 3DEE2C 004DEE2C C8978424 */   addiu     $4, $4, %lo(D_007597C8)
    /* 3DEE30 004DEE30 02000010 */  b          .L004DEE3C
    /* 3DEE34 004DEE34 FFFF0224 */   addiu     $2, $0, -0x1
  .L004DEE38:
    /* 3DEE38 004DEE38 01008280 */  lb         $2, 0x1($4)
  .L004DEE3C:
    /* 3DEE3C 004DEE3C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DEE40 004DEE40 0800E003 */  jr         $31
    /* 3DEE44 004DEE44 1000BD27 */   addiu     $29, $29, 0x10
.size func_004dee18, 0x30
