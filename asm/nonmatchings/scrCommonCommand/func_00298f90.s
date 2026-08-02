.section .text
.set noat
.set noreorder
glabel func_00298f90
    /* 198F90 00298F90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 198F94 00298F94 0000BFFF */  sd         $31, 0x0($29)
    /* 198F98 00298F98 08740A0C */  jal        func_0029d020
    /* 198F9C 00298F9C 00000000 */   nop
    /* 198FA0 00298FA0 2B100200 */  sltu       $2, $0, $2
    /* 198FA4 00298FA4 0000BFDF */  ld         $31, 0x0($29)
    /* 198FA8 00298FA8 1000BD27 */  addiu      $29, $29, 0x10
    /* 198FAC 00298FAC 0800E003 */  jr         $31
    /* 198FB0 00298FB0 00000000 */   nop
    /* 198FB4 00298FB4 00000000 */  nop
    /* 198FB8 00298FB8 00000000 */  nop
    /* 198FBC 00298FBC 00000000 */  nop
.size func_00298f90, 0x30
