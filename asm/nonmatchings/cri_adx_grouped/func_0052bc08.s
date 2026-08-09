.section .text
.set noat
.set noreorder
glabel func_0052bc08
    /* 42BC08 0052BC08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BC0C 0052BC0C 0000BFFF */  sd         $31, 0x0($29)
    /* 42BC10 0052BC10 2400848C */  lw         $4, 0x24($4)
    /* 42BC14 0052BC14 4C00A58C */  lw         $5, 0x4C($5)
    /* 42BC18 0052BC18 0000BFDF */  ld         $31, 0x0($29)
    /* 42BC1C 0052BC1C 60B01408 */  j          func_0052c180
    /* 42BC20 0052BC20 1000BD27 */   addiu     $29, $29, 0x10
    /* 42BC24 0052BC24 00000000 */  nop
.size func_0052bc08, 0x20
