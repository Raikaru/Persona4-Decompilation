.section .text
.set noat
.set noreorder
glabel func_004de318
    /* 3DE318 004DE318 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE31C 004DE31C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE320 004DE320 BA78130C */  jal        func_004de2e8
    /* 3DE324 004DE324 2D200000 */   daddu     $4, $0, $0
    /* 3DE328 004DE328 C478130C */  jal        func_004de310
    /* 3DE32C 004DE32C 2D200000 */   daddu     $4, $0, $0
    /* 3DE330 004DE330 2D100000 */  daddu      $2, $0, $0
    /* 3DE334 004DE334 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE338 004DE338 0800E003 */  jr         $31
    /* 3DE33C 004DE33C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de318, 0x28
