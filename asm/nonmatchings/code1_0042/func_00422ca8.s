.section .text
.set noat
.set noreorder
glabel func_00422ca8
    /* 322CA8 00422CA8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322CAC 00422CAC 0000A4AF */  sw         $4, 0x0($29)
    /* 322CB0 00422CB0 2D28A003 */  daddu      $5, $29, $0
    /* 322CB4 00422CB4 1000BFFF */  sd         $31, 0x10($29)
    /* 322CB8 00422CB8 0487100C */  jal        func_00421c10
    /* 322CBC 00422CBC F7FF0424 */   addiu     $4, $0, -0x9
    /* 322CC0 00422CC0 1000BFDF */  ld         $31, 0x10($29)
    /* 322CC4 00422CC4 0800E003 */  jr         $31
    /* 322CC8 00422CC8 2000BD27 */   addiu     $29, $29, 0x20
    /* 322CCC 00422CCC 00000000 */  nop
.size func_00422ca8, 0x28
