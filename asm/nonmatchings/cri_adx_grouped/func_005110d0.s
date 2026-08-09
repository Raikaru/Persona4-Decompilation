.section .text
.set noat
.set noreorder
glabel func_005110d0
    /* 4110D0 005110D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4110D4 005110D4 2D200000 */  daddu      $4, $0, $0
    /* 4110D8 005110D8 0000BFFF */  sd         $31, 0x0($29)
    /* 4110DC 005110DC C8C4130C */  jal        func_004f1320
    /* 4110E0 005110E0 2D280000 */   daddu     $5, $0, $0
    /* 4110E4 005110E4 2D200000 */  daddu      $4, $0, $0
    /* 4110E8 005110E8 0000BFDF */  ld         $31, 0x0($29)
    /* 4110EC 005110EC 2D280000 */  daddu      $5, $0, $0
    /* 4110F0 005110F0 CEC41308 */  j          func_004f1338
    /* 4110F4 005110F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_005110d0, 0x28
