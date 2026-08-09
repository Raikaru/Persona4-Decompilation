.section .text
.set noat
.set noreorder
glabel func_0050cd00
    /* 40CD00 0050CD00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CD04 0050CD04 0000B0FF */  sd         $16, 0x0($29)
    /* 40CD08 0050CD08 0800BFFF */  sd         $31, 0x8($29)
    /* 40CD0C 0050CD0C D463100C */  jal        func_00418f50
    /* 40CD10 0050CD10 00000000 */   nop
    /* 40CD14 0050CD14 2D804000 */  daddu      $16, $2, $0
    /* 40CD18 0050CD18 2D200002 */  daddu      $4, $16, $0
    /* 40CD1C 0050CD1C 00000000 */  nop
  .L0050CD20:
    /* 40CD20 0050CD20 01000524 */  addiu      $5, $0, 0x1
    /* 40CD24 0050CD24 4865100C */  jal        func_00419520
    /* 40CD28 0050CD28 1E000624 */   addiu     $6, $0, 0x1E
    /* 40CD2C 0050CD2C FCFF4014 */  bnez       $2, .L0050CD20
    /* 40CD30 0050CD30 2D200002 */   daddu     $4, $16, $0
    /* 40CD34 0050CD34 0000B0DF */  ld         $16, 0x0($29)
    /* 40CD38 0050CD38 0800BFDF */  ld         $31, 0x8($29)
    /* 40CD3C 0050CD3C 0800E003 */  jr         $31
    /* 40CD40 0050CD40 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CD44 0050CD44 00000000 */  nop
.size func_0050cd00, 0x48
