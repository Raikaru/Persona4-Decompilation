.section .text
.set noat
.set noreorder
glabel func_0051bba0
    /* 41BBA0 0051BBA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41BBA4 0051BBA4 80000324 */  addiu      $3, $0, 0x80
    /* 41BBA8 0051BBA8 0000BFFF */  sd         $31, 0x0($29)
    /* 41BBAC 0051BBAC 0500A528 */  slti       $5, $5, 0x5
    /* 41BBB0 0051BBB0 0900C310 */  beq        $6, $3, .L0051BBD8
    /* 41BBB4 0051BBB4 01000224 */   addiu     $2, $0, 0x1
    /* 41BBB8 0051BBB8 0700A050 */  beql       $5, $0, .L0051BBD8
    /* 41BBBC 0051BBBC 2D100000 */   daddu     $2, $0, $0
    /* 41BBC0 0051BBC0 FA6E140C */  jal        func_0051bbe8
    /* 41BBC4 0051BBC4 00000000 */   nop
    /* 41BBC8 0051BBC8 01000324 */  addiu      $3, $0, 0x1
    /* 41BBCC 0051BBCC 03004310 */  beq        $2, $3, .L0051BBDC
    /* 41BBD0 0051BBD0 0000BFDF */   ld        $31, 0x0($29)
    /* 41BBD4 0051BBD4 2D100000 */  daddu      $2, $0, $0
  .L0051BBD8:
    /* 41BBD8 0051BBD8 0000BFDF */  ld         $31, 0x0($29)
  .L0051BBDC:
    /* 41BBDC 0051BBDC 0800E003 */  jr         $31
    /* 41BBE0 0051BBE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 41BBE4 0051BBE4 00000000 */  nop
.size func_0051bba0, 0x48
