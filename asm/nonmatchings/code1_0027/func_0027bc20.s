.section .text
.set noat
.set noreorder
glabel func_0027bc20
    /* 17BC20 0027BC20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BC24 0027BC24 1000BFFF */  sd         $31, 0x10($29)
    /* 17BC28 0027BC28 0000B07F */  sq         $16, 0x0($29)
    /* 17BC2C 0027BC2C 2D808000 */  daddu      $16, $4, $0
    /* 17BC30 0027BC30 10DE090C */  jal        func_00277840
    /* 17BC34 0027BC34 00000000 */   nop
    /* 17BC38 0027BC38 2D200002 */  daddu      $4, $16, $0
    /* 17BC3C 0027BC3C 10DE090C */  jal        func_00277840
    /* 17BC40 0027BC40 00000000 */   nop
    /* 17BC44 0027BC44 0000428C */  lw         $2, 0x0($2)
    /* 17BC48 0027BC48 07004010 */  beqz       $2, .L0027BC68
    /* 17BC4C 0027BC4C 00000000 */   nop
    /* 17BC50 0027BC50 2D200002 */  daddu      $4, $16, $0
    /* 17BC54 0027BC54 0B000524 */  addiu      $5, $0, 0xB
    /* 17BC58 0027BC58 09F84000 */  jalr       $2
    /* 17BC5C 0027BC5C 00000000 */   nop
    /* 17BC60 0027BC60 02000010 */  b          .L0027BC6C
    /* 17BC64 0027BC64 00000000 */   nop
  .L0027BC68:
    /* 17BC68 0027BC68 01000224 */  addiu      $2, $0, 0x1
  .L0027BC6C:
    /* 17BC6C 0027BC6C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BC70 0027BC70 0000B07B */  lq         $16, 0x0($29)
    /* 17BC74 0027BC74 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BC78 0027BC78 0800E003 */  jr         $31
    /* 17BC7C 0027BC7C 00000000 */   nop
.size func_0027bc20, 0x60
