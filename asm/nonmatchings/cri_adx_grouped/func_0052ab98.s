.section .text
.set noat
.set noreorder
glabel func_0052ab98
    /* 42AB98 0052AB98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42AB9C 0052AB9C 0000BFFF */  sd         $31, 0x0($29)
    /* 42ABA0 0052ABA0 3800868C */  lw         $6, 0x38($4)
    /* 42ABA4 0052ABA4 4C00A58C */  lw         $5, 0x4C($5)
    /* 42ABA8 0052ABA8 3000848C */  lw         $4, 0x30($4)
    /* 42ABAC 0052ABAC 0000BFDF */  ld         $31, 0x0($29)
    /* 42ABB0 0052ABB0 6AA91408 */  j          func_0052a5a8
    /* 42ABB4 0052ABB4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052ab98, 0x20
