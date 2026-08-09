.section .text
.set noat
.set noreorder
glabel func_004e15a8
    /* 3E15A8 004E15A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E15AC 004E15AC 2D288000 */  daddu      $5, $4, $0
    /* 3E15B0 004E15B0 0000BFFF */  sd         $31, 0x0($29)
    /* 3E15B4 004E15B4 7300043C */  lui        $4, %hi(D_00731BF8)
    /* 3E15B8 004E15B8 F81B8424 */  addiu      $4, $4, %lo(D_00731BF8)
    /* 3E15BC 004E15BC 2D300000 */  daddu      $6, $0, $0
    /* 3E15C0 004E15C0 0000BFDF */  ld         $31, 0x0($29)
    /* 3E15C4 004E15C4 5E851308 */  j          func_004e1578
    /* 3E15C8 004E15C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E15CC 004E15CC 00000000 */  nop
.size func_004e15a8, 0x28
