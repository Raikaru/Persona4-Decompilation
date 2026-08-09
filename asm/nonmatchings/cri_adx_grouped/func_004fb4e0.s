.section .text
.set noat
.set noreorder
glabel func_004fb4e0
    /* 3FB4E0 004FB4E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB4E4 004FB4E4 7400043C */  lui        $4, %hi(D_00743CD0)
    /* 3FB4E8 004FB4E8 0000BFFF */  sd         $31, 0x0($29)
    /* 3FB4EC 004FB4EC D03C8424 */  addiu      $4, $4, %lo(D_00743CD0)
    /* 3FB4F0 004FB4F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3FB4F4 004FB4F4 40ED1308 */  j          func_004fb500
    /* 3FB4F8 004FB4F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FB4FC 004FB4FC 00000000 */  nop
.size func_004fb4e0, 0x20
