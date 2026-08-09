.section .text
.set noat
.set noreorder
glabel func_0043eaf8
    /* 33EAF8 0043EAF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33EAFC 0043EAFC 2D788000 */  daddu      $15, $4, $0
    /* 33EB00 0043EB00 0000BFFF */  sd         $31, 0x0($29)
    /* 33EB04 0043EB04 71000E3C */  lui        $14, %hi(D_00710070)
    /* 33EB08 0043EB08 2D30A000 */  daddu      $6, $5, $0
    /* 33EB0C 0043EB0C 7000C48D */  lw         $4, %lo(D_00710070)($14)
    /* 33EB10 0043EB10 0000BFDF */  ld         $31, 0x0($29)
    /* 33EB14 0043EB14 2D28E001 */  daddu      $5, $15, $0
    /* 33EB18 0043EB18 98FA1008 */  j          func_0043ea60
    /* 33EB1C 0043EB1C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043eaf8, 0x28
