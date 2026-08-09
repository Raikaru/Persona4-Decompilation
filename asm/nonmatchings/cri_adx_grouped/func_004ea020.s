.section .text
.set noat
.set noreorder
glabel func_004ea020
    /* 3EA020 004EA020 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EA024 004EA024 1000BFFF */  sd         $31, 0x10($29)
    /* 3EA028 004EA028 ACA7130C */  jal        func_004e9eb0
    /* 3EA02C 004EA02C 2D28A003 */   daddu     $5, $29, $0
    /* 3EA030 004EA030 0000A28F */  lw         $2, 0x0($29)
    /* 3EA034 004EA034 1000BFDF */  ld         $31, 0x10($29)
    /* 3EA038 004EA038 0800E003 */  jr         $31
    /* 3EA03C 004EA03C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ea020, 0x20
