.section .text
.set noat
.set noreorder
glabel func_004cb3f8
    /* 3CB3F8 004CB3F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB3FC 004CB3FC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB400 004CB400 14C4130C */  jal        func_004f1050
    /* 3CB404 004CB404 00000000 */   nop
    /* 3CB408 004CB408 1AC4130C */  jal        func_004f1068
    /* 3CB40C 004CB40C 00000000 */   nop
    /* 3CB410 004CB410 20C4130C */  jal        func_004f1080
    /* 3CB414 004CB414 00000000 */   nop
    /* 3CB418 004CB418 26C4130C */  jal        func_004f1098
    /* 3CB41C 004CB41C 00000000 */   nop
    /* 3CB420 004CB420 2CC4130C */  jal        func_004f10b0
    /* 3CB424 004CB424 00000000 */   nop
    /* 3CB428 004CB428 32C4130C */  jal        func_004f10c8
    /* 3CB42C 004CB42C 00000000 */   nop
    /* 3CB430 004CB430 38C4130C */  jal        func_004f10e0
    /* 3CB434 004CB434 00000000 */   nop
    /* 3CB438 004CB438 3EC4130C */  jal        func_004f10f8
    /* 3CB43C 004CB43C 00000000 */   nop
    /* 3CB440 004CB440 2D100000 */  daddu      $2, $0, $0
    /* 3CB444 004CB444 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB448 004CB448 0800E003 */  jr         $31
    /* 3CB44C 004CB44C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb3f8, 0x58
