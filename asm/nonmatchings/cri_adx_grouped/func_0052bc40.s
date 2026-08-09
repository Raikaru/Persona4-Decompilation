.section .text
.set noat
.set noreorder
glabel func_0052bc40
    /* 42BC40 0052BC40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BC44 0052BC44 0000BFFF */  sd         $31, 0x0($29)
    /* 42BC48 0052BC48 3000848C */  lw         $4, 0x30($4)
    /* 42BC4C 0052BC4C 0000BFDF */  ld         $31, 0x0($29)
    /* 42BC50 0052BC50 A2A91408 */  j          func_0052a688
    /* 42BC54 0052BC54 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052bc40, 0x18
