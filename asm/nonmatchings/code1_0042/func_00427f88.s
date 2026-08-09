.section .text
.set noat
.set noreorder
glabel func_00427f88
    /* 327F88 00427F88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 327F8C 00427F8C 0000BFFF */  sd         $31, 0x0($29)
    /* 327F90 00427F90 769F100C */  jal        func_00427dd8
    /* 327F94 00427F94 06000524 */   addiu     $5, $0, 0x6
    /* 327F98 00427F98 0000BFDF */  ld         $31, 0x0($29)
    /* 327F9C 00427F9C 0800E003 */  jr         $31
    /* 327FA0 00427FA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 327FA4 00427FA4 00000000 */  nop
.size func_00427f88, 0x20
