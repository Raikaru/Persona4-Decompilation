.section .text
.set noat
.set noreorder
glabel func_0050b3e0
    /* 40B3E0 0050B3E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B3E4 0050B3E4 2D20A000 */  daddu      $4, $5, $0
    /* 40B3E8 0050B3E8 0000BFFF */  sd         $31, 0x0($29)
    /* 40B3EC 0050B3EC 0000BFDF */  ld         $31, 0x0($29)
    /* 40B3F0 0050B3F0 88441408 */  j          func_00511220
    /* 40B3F4 0050B3F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b3e0, 0x18
