.section .text
.set noat
.set noreorder
glabel func_004cf710
    /* 3CF710 004CF710 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF714 004CF714 7200043C */  lui        $4, %hi(D_00723548)
    /* 3CF718 004CF718 0000BFFF */  sd         $31, 0x0($29)
    /* 3CF71C 004CF71C 2D280000 */  daddu      $5, $0, $0
    /* 3CF720 004CF720 48358424 */  addiu      $4, $4, %lo(D_00723548)
    /* 3CF724 004CF724 C0000624 */  addiu      $6, $0, 0xC0
    /* 3CF728 004CF728 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF72C 004CF72C 72FE1008 */  j          func_0043f9c8
    /* 3CF730 004CF730 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CF734 004CF734 00000000 */  nop
.size func_004cf710, 0x28
