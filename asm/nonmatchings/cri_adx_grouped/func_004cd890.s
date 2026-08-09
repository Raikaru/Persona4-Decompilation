.section .text
.set noat
.set noreorder
glabel func_004cd890
    /* 3CD890 004CD890 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD894 004CD894 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD898 004CD898 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD89C 004CD89C 3AB41308 */  j          func_004ed0e8
    /* 3CD8A0 004CD8A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD8A4 004CD8A4 00000000 */  nop
.size func_004cd890, 0x18
