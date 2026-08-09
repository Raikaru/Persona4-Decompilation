.section .text
.set noat
.set noreorder
glabel func_004ea518
    /* 3EA518 004EA518 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA51C 004EA51C 2D108000 */  daddu      $2, $4, $0
    /* 3EA520 004EA520 07004014 */  bnez       $2, .L004EA540
    /* 3EA524 004EA524 0000BFFF */   sd        $31, 0x0($29)
    /* 3EA528 004EA528 7600053C */  lui        $5, %hi(D_0075BFC0)
    /* 3EA52C 004EA52C 9AA7130C */  jal        func_004e9e68
    /* 3EA530 004EA530 C0BFA524 */   addiu     $5, $5, %lo(D_0075BFC0)
    /* 3EA534 004EA534 03000010 */  b          .L004EA544
    /* 3EA538 004EA538 2D100000 */   daddu     $2, $0, $0
    /* 3EA53C 004EA53C 00000000 */  nop
  .L004EA540:
    /* 3EA540 004EA540 0400428C */  lw         $2, 0x4($2)
  .L004EA544:
    /* 3EA544 004EA544 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA548 004EA548 0800E003 */  jr         $31
    /* 3EA54C 004EA54C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ea518, 0x38
