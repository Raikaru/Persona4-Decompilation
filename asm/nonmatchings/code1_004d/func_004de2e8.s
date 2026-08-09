.section .text
.set noat
.set noreorder
glabel func_004de2e8
    /* 3DE2E8 004DE2E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE2EC 004DE2EC 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE2F0 004DE2F0 0E7F130C */  jal        func_004dfc38
    /* 3DE2F4 004DE2F4 00000000 */   nop
    /* 3DE2F8 004DE2F8 BA84130C */  jal        func_004e12e8
    /* 3DE2FC 004DE2FC 00000000 */   nop
    /* 3DE300 004DE300 2D100000 */  daddu      $2, $0, $0
    /* 3DE304 004DE304 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE308 004DE308 0800E003 */  jr         $31
    /* 3DE30C 004DE30C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de2e8, 0x28
