.section .text
.set noat
.set noreorder
glabel func_004a6d90
    /* 3A6D90 004A6D90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3A6D94 004A6D94 0000BFFF */  sd         $31, 0x0($29)
    /* 3A6D98 004A6D98 2411120C */  jal        func_00484490
    /* 3A6D9C 004A6D9C 00000000 */   nop
    /* 3A6DA0 004A6DA0 2D204000 */  daddu      $4, $2, $0
    /* 3A6DA4 004A6DA4 009B120C */  jal        func_004a6c00
    /* 3A6DA8 004A6DA8 00000000 */   nop
    /* 3A6DAC 004A6DAC 0000BFDF */  ld         $31, 0x0($29)
    /* 3A6DB0 004A6DB0 1000BD27 */  addiu      $29, $29, 0x10
    /* 3A6DB4 004A6DB4 0800E003 */  jr         $31
    /* 3A6DB8 004A6DB8 00000000 */   nop
    /* 3A6DBC 004A6DBC 00000000 */  nop
.size func_004a6d90, 0x30
