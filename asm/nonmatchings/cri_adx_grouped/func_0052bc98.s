.section .text
.set noat
.set noreorder
glabel func_0052bc98
    /* 42BC98 0052BC98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BC9C 0052BC9C 0000BFFF */  sd         $31, 0x0($29)
    /* 42BCA0 0052BCA0 3000848C */  lw         $4, 0x30($4)
    /* 42BCA4 0052BCA4 0000BFDF */  ld         $31, 0x0($29)
    /* 42BCA8 0052BCA8 B0A91408 */  j          func_0052a6c0
    /* 42BCAC 0052BCAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052bc98, 0x18
