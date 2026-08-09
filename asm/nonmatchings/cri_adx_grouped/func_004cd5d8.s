.section .text
.set noat
.set noreorder
glabel func_004cd5d8
    /* 3CD5D8 004CD5D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD5DC 004CD5DC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD5E0 004CD5E0 0C00848C */  lw         $4, 0xC($4)
    /* 3CD5E4 004CD5E4 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD5E8 004CD5E8 64B01308 */  j          func_004ec190
    /* 3CD5EC 004CD5EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd5d8, 0x18
