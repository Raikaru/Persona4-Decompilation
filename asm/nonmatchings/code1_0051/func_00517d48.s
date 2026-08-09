.section .text
.set noat
.set noreorder
glabel func_00517d48
    /* 417D48 00517D48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417D4C 00517D4C 0000BFFF */  sd         $31, 0x0($29)
    /* 417D50 00517D50 F085140C */  jal        func_005217c0
    /* 417D54 00517D54 00000000 */   nop
    /* 417D58 00517D58 0000BFDF */  ld         $31, 0x0($29)
    /* 417D5C 00517D5C 665B1408 */  j          func_00516d98
    /* 417D60 00517D60 1000BD27 */   addiu     $29, $29, 0x10
    /* 417D64 00517D64 00000000 */  nop
.size func_00517d48, 0x20
