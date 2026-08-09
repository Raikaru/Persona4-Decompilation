.section .text
.set noat
.set noreorder
glabel func_004e39e8
    /* 3E39E8 004E39E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E39EC 004E39EC 0000BFFF */  sd         $31, 0x0($29)
    /* 3E39F0 004E39F0 8691130C */  jal        func_004e4618
    /* 3E39F4 004E39F4 00130424 */   addiu     $4, $0, 0x1300
    /* 3E39F8 004E39F8 F2B9100C */  jal        func_0042e7c8
    /* 3E39FC 004E39FC 2D200000 */   daddu     $4, $0, $0
    /* 3E3A00 004E3A00 01130424 */  addiu      $4, $0, 0x1301
    /* 3E3A04 004E3A04 0000BFDF */  ld         $31, 0x0($29)
    /* 3E3A08 004E3A08 86911308 */  j          func_004e4618
    /* 3E3A0C 004E3A0C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e39e8, 0x28
