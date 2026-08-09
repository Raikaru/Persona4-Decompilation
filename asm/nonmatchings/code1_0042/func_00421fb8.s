.section .text
.set noat
.set noreorder
glabel func_00421fb8
    /* 321FB8 00421FB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 321FBC 00421FBC 01000224 */  addiu      $2, $0, 0x1
    /* 321FC0 00421FC0 03008214 */  bne        $4, $2, .L00421FD0
    /* 321FC4 00421FC4 0000BFFF */   sd        $31, 0x0($29)
    /* 321FC8 00421FC8 36B0100C */  jal        func_0042c0d8
    /* 321FCC 00421FCC 2D20A000 */   daddu     $4, $5, $0
  .L00421FD0:
    /* 321FD0 00421FD0 0000BFDF */  ld         $31, 0x0($29)
    /* 321FD4 00421FD4 2D100000 */  daddu      $2, $0, $0
    /* 321FD8 00421FD8 0800E003 */  jr         $31
    /* 321FDC 00421FDC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00421fb8, 0x28
