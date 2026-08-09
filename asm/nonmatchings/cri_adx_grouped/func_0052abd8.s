.section .text
.set noat
.set noreorder
glabel func_0052abd8
    /* 42ABD8 0052ABD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42ABDC 0052ABDC 0000BFFF */  sd         $31, 0x0($29)
    /* 42ABE0 0052ABE0 3800868C */  lw         $6, 0x38($4)
    /* 42ABE4 0052ABE4 4C00A58C */  lw         $5, 0x4C($5)
    /* 42ABE8 0052ABE8 3000848C */  lw         $4, 0x30($4)
    /* 42ABEC 0052ABEC 0000BFDF */  ld         $31, 0x0($29)
    /* 42ABF0 0052ABF0 8AA91408 */  j          func_0052a628
    /* 42ABF4 0052ABF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052abd8, 0x20
