.section .text
.set noat
.set noreorder
glabel func_004cd860
    /* 3CD860 004CD860 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD864 004CD864 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD868 004CD868 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD86C 004CD86C 08B41308 */  j          func_004ed020
    /* 3CD870 004CD870 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD874 004CD874 00000000 */  nop
.size func_004cd860, 0x18
