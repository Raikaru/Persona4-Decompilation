.section .text
.set noat
.set noreorder
glabel func_00102d10
    /* 2D10 00102D10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2D14 00102D14 0000BFFF */  sd         $31, 0x0($29)
    /* 2D18 00102D18 640D040C */  jal        func_00103590
    /* 2D1C 00102D1C 00000000 */   nop
    /* 2D20 00102D20 0000BFDF */  ld         $31, 0x0($29)
    /* 2D24 00102D24 1000BD27 */  addiu      $29, $29, 0x10
    /* 2D28 00102D28 0800E003 */  jr         $31
    /* 2D2C 00102D2C 00000000 */   nop
.size func_00102d10, 0x20
