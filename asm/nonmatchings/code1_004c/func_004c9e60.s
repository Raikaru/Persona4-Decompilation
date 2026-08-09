.section .text
.set noat
.set noreorder
glabel func_004c9e60
    /* 3C9E60 004C9E60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9E64 004C9E64 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9E68 004C9E68 0800BFFF */  sd         $31, 0x8($29)
    /* 3C9E6C 004C9E6C 3615130C */  jal        func_004c54d8
    /* 3C9E70 004C9E70 00000000 */   nop
    /* 3C9E74 004C9E74 A627130C */  jal        func_004c9e98
    /* 3C9E78 004C9E78 00000000 */   nop
    /* 3C9E7C 004C9E7C 3815130C */  jal        func_004c54e0
    /* 3C9E80 004C9E80 2D804000 */   daddu     $16, $2, $0
    /* 3C9E84 004C9E84 0800BFDF */  ld         $31, 0x8($29)
    /* 3C9E88 004C9E88 2D100002 */  daddu      $2, $16, $0
    /* 3C9E8C 004C9E8C 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9E90 004C9E90 0800E003 */  jr         $31
    /* 3C9E94 004C9E94 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c9e60, 0x38
