.section .text
.set noat
.set noreorder
glabel func_0051e5c8
    /* 41E5C8 0051E5C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41E5CC 0051E5CC 2D30A000 */  daddu      $6, $5, $0
    /* 41E5D0 0051E5D0 0000BFFF */  sd         $31, 0x0($29)
    /* 41E5D4 0051E5D4 6053140C */  jal        func_00514d80
    /* 41E5D8 0051E5D8 C81F858C */   lw        $5, 0x1FC8($4)
    /* 41E5DC 0051E5DC 0000BFDF */  ld         $31, 0x0($29)
    /* 41E5E0 0051E5E0 0800E003 */  jr         $31
    /* 41E5E4 0051E5E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0051e5c8, 0x20
