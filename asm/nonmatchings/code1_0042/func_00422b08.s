.section .text
.set noat
.set noreorder
glabel func_00422b08
    /* 322B08 00422B08 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322B0C 00422B0C 0000A4AF */  sw         $4, 0x0($29)
    /* 322B10 00422B10 2D28A003 */  daddu      $5, $29, $0
    /* 322B14 00422B14 1000BFFF */  sd         $31, 0x10($29)
    /* 322B18 00422B18 0487100C */  jal        func_00421c10
    /* 322B1C 00422B1C 02000424 */   addiu     $4, $0, 0x2
    /* 322B20 00422B20 1000BFDF */  ld         $31, 0x10($29)
    /* 322B24 00422B24 0800E003 */  jr         $31
    /* 322B28 00422B28 2000BD27 */   addiu     $29, $29, 0x20
    /* 322B2C 00422B2C 00000000 */  nop
.size func_00422b08, 0x28
