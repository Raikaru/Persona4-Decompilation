.section .text
.set noat
.set noreorder
glabel func_0052bc28
    /* 42BC28 0052BC28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BC2C 0052BC2C 0000BFFF */  sd         $31, 0x0($29)
    /* 42BC30 0052BC30 3000848C */  lw         $4, 0x30($4)
    /* 42BC34 0052BC34 0000BFDF */  ld         $31, 0x0($29)
    /* 42BC38 0052BC38 9AA91408 */  j          func_0052a668
    /* 42BC3C 0052BC3C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052bc28, 0x18
