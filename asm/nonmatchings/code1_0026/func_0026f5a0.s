.section .text
.set noat
.set noreorder
glabel func_0026f5a0
    /* 16F5A0 0026F5A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 16F5A4 0026F5A4 0000BFFF */  sd         $31, 0x0($29)
    /* 16F5A8 0026F5A8 A8D1090C */  jal        func_002746a0
    /* 16F5AC 0026F5AC 00000000 */   nop
    /* 16F5B0 0026F5B0 02000324 */  addiu      $3, $0, 0x2
    /* 16F5B4 0026F5B4 04004310 */  beq        $2, $3, .L0026F5C8
    /* 16F5B8 0026F5B8 00000000 */   nop
    /* 16F5BC 0026F5BC 2D100000 */  daddu      $2, $0, $0
    /* 16F5C0 0026F5C0 02000010 */  b          .L0026F5CC
    /* 16F5C4 0026F5C4 00000000 */   nop
  .L0026F5C8:
    /* 16F5C8 0026F5C8 2D100000 */  daddu      $2, $0, $0
  .L0026F5CC:
    /* 16F5CC 0026F5CC 0000BFDF */  ld         $31, 0x0($29)
    /* 16F5D0 0026F5D0 1000BD27 */  addiu      $29, $29, 0x10
    /* 16F5D4 0026F5D4 0800E003 */  jr         $31
    /* 16F5D8 0026F5D8 00000000 */   nop
    /* 16F5DC 0026F5DC 00000000 */  nop
.size func_0026f5a0, 0x40
