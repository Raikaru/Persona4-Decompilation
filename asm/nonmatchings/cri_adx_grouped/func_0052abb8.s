.section .text
.set noat
.set noreorder
glabel func_0052abb8
    /* 42ABB8 0052ABB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42ABBC 0052ABBC 0000BFFF */  sd         $31, 0x0($29)
    /* 42ABC0 0052ABC0 3800868C */  lw         $6, 0x38($4)
    /* 42ABC4 0052ABC4 4C00A58C */  lw         $5, 0x4C($5)
    /* 42ABC8 0052ABC8 3000848C */  lw         $4, 0x30($4)
    /* 42ABCC 0052ABCC 0000BFDF */  ld         $31, 0x0($29)
    /* 42ABD0 0052ABD0 7CA91408 */  j          func_0052a5f0
    /* 42ABD4 0052ABD4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052abb8, 0x20
