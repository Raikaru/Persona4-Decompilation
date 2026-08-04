.section .text
.set noat
.set noreorder
glabel func_00110fc0
    /* 10FC0 00110FC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10FC4 00110FC4 0000BFFF */  sd         $31, 0x0($29)
    /* 10FC8 00110FC8 5881090C */  jal        func_00260560
    /* 10FCC 00110FCC 00000000 */   nop
    /* 10FD0 00110FD0 01000424 */  addiu      $4, $0, 0x1
    /* 10FD4 00110FD4 2D288000 */  daddu      $5, $4, $0
    /* 10FD8 00110FD8 4889040C */  jal        func_00122520
    /* 10FDC 00110FDC 00000000 */   nop
    /* 10FE0 00110FE0 1B000424 */  addiu      $4, $0, 0x1B
    /* 10FE4 00110FE4 2D280000 */  daddu      $5, $0, $0
    /* 10FE8 00110FE8 2D300000 */  daddu      $6, $0, $0
    /* 10FEC 00110FEC 08000724 */  addiu      $7, $0, 0x8
    /* 10FF0 00110FF0 680A040C */  jal        func_001029a0
    /* 10FF4 00110FF4 00000000 */   nop
    /* 10FF8 00110FF8 0000BFDF */  ld         $31, 0x0($29)
    /* 10FFC 00110FFC 1000BD27 */  addiu      $29, $29, 0x10
    /* 11000 00111000 0800E003 */  jr         $31
    /* 11004 00111004 00000000 */   nop
    /* 11008 00111008 00000000 */  nop
    /* 1100C 0011100C 00000000 */  nop
.size func_00110fc0, 0x50
