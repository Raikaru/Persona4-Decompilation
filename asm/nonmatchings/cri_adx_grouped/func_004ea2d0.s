.section .text
.set noat
.set noreorder
glabel func_004ea2d0
    /* 3EA2D0 004EA2D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA2D4 004EA2D4 2D108000 */  daddu      $2, $4, $0
    /* 3EA2D8 004EA2D8 07004014 */  bnez       $2, .L004EA2F8
    /* 3EA2DC 004EA2DC 0000BFFF */   sd        $31, 0x0($29)
    /* 3EA2E0 004EA2E0 7600053C */  lui        $5, %hi(D_0075BF20)
    /* 3EA2E4 004EA2E4 9AA7130C */  jal        func_004e9e68
    /* 3EA2E8 004EA2E8 20BFA524 */   addiu     $5, $5, %lo(D_0075BF20)
    /* 3EA2EC 004EA2EC 03000010 */  b          .L004EA2FC
    /* 3EA2F0 004EA2F0 2D100000 */   daddu     $2, $0, $0
    /* 3EA2F4 004EA2F4 00000000 */  nop
  .L004EA2F8:
    /* 3EA2F8 004EA2F8 1000428C */  lw         $2, 0x10($2)
  .L004EA2FC:
    /* 3EA2FC 004EA2FC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA300 004EA300 0800E003 */  jr         $31
    /* 3EA304 004EA304 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ea2d0, 0x38
