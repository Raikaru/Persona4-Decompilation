.section .text
.set noat
.set noreorder
glabel func_00422b60
    /* 322B60 00422B60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322B64 00422B64 0000A4AF */  sw         $4, 0x0($29)
    /* 322B68 00422B68 2D28A003 */  daddu      $5, $29, $0
    /* 322B6C 00422B6C 1000BFFF */  sd         $31, 0x10($29)
    /* 322B70 00422B70 0487100C */  jal        func_00421c10
    /* 322B74 00422B74 04000424 */   addiu     $4, $0, 0x4
    /* 322B78 00422B78 1000BFDF */  ld         $31, 0x10($29)
    /* 322B7C 00422B7C 0800E003 */  jr         $31
    /* 322B80 00422B80 2000BD27 */   addiu     $29, $29, 0x20
    /* 322B84 00422B84 00000000 */  nop
.size func_00422b60, 0x28
