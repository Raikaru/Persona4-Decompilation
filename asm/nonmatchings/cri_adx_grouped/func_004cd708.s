.section .text
.set noat
.set noreorder
glabel func_004cd708
    /* 3CD708 004CD708 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD70C 004CD70C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD710 004CD710 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD714 004CD714 46B21308 */  j          func_004ec918
    /* 3CD718 004CD718 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD71C 004CD71C 00000000 */  nop
.size func_004cd708, 0x18
