.section .text
.set noat
.set noreorder
glabel func_004cd608
    /* 3CD608 004CD608 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD60C 004CD60C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD610 004CD610 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD614 004CD614 7AB01308 */  j          func_004ec1e8
    /* 3CD618 004CD618 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD61C 004CD61C 00000000 */  nop
.size func_004cd608, 0x18
