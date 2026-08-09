.section .text
.set noat
.set noreorder
glabel func_00422bb8
    /* 322BB8 00422BB8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322BBC 00422BBC 0000A4AF */  sw         $4, 0x0($29)
    /* 322BC0 00422BC0 2D28A003 */  daddu      $5, $29, $0
    /* 322BC4 00422BC4 1000BFFF */  sd         $31, 0x10($29)
    /* 322BC8 00422BC8 0487100C */  jal        func_00421c10
    /* 322BCC 00422BCC 21000424 */   addiu     $4, $0, 0x21
    /* 322BD0 00422BD0 1000BFDF */  ld         $31, 0x10($29)
    /* 322BD4 00422BD4 0800E003 */  jr         $31
    /* 322BD8 00422BD8 2000BD27 */   addiu     $29, $29, 0x20
    /* 322BDC 00422BDC 00000000 */  nop
.size func_00422bb8, 0x28
