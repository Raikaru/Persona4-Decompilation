.section .text
.set noat
.set noreorder
glabel func_005110a0
    /* 4110A0 005110A0 5100043C */  lui        $4, %hi(func_005110f8)
    /* 4110A4 005110A4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4110A8 005110A8 2D280000 */  daddu      $5, $0, $0
    /* 4110AC 005110AC 0000BFFF */  sd         $31, 0x0($29)
    /* 4110B0 005110B0 C8C4130C */  jal        func_004f1320
    /* 4110B4 005110B4 F8108424 */   addiu     $4, $4, %lo(func_005110f8)
    /* 4110B8 005110B8 0000BFDF */  ld         $31, 0x0($29)
    /* 4110BC 005110BC 5100043C */  lui        $4, %hi(func_00511110)
    /* 4110C0 005110C0 10118424 */  addiu      $4, $4, %lo(func_00511110)
    /* 4110C4 005110C4 2D280000 */  daddu      $5, $0, $0
    /* 4110C8 005110C8 CEC41308 */  j          func_004f1338
    /* 4110CC 005110CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_005110a0, 0x30
