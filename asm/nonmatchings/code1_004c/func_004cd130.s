.section .text
.set noat
.set noreorder
glabel func_004cd130
    /* 3CD130 004CD130 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD134 004CD134 07000424 */  addiu      $4, $0, 0x7
    /* 3CD138 004CD138 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD13C 004CD13C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD140 004CD140 90C31308 */  j          func_004f0e40
    /* 3CD144 004CD144 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd130, 0x18
