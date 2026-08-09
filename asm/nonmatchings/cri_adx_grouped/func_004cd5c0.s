.section .text
.set noat
.set noreorder
glabel func_004cd5c0
    /* 3CD5C0 004CD5C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD5C4 004CD5C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD5C8 004CD5C8 0C00848C */  lw         $4, 0xC($4)
    /* 3CD5CC 004CD5CC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD5D0 004CD5D0 50B01308 */  j          func_004ec140
    /* 3CD5D4 004CD5D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd5c0, 0x18
