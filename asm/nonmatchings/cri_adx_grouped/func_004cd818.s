.section .text
.set noat
.set noreorder
glabel func_004cd818
    /* 3CD818 004CD818 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD81C 004CD81C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD820 004CD820 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD824 004CD824 D8B31308 */  j          func_004ecf60
    /* 3CD828 004CD828 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD82C 004CD82C 00000000 */  nop
.size func_004cd818, 0x18
