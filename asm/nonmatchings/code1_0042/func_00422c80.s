.section .text
.set noat
.set noreorder
glabel func_00422c80
    /* 322C80 00422C80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322C84 00422C84 0000A4AF */  sw         $4, 0x0($29)
    /* 322C88 00422C88 2D28A003 */  daddu      $5, $29, $0
    /* 322C8C 00422C8C 1000BFFF */  sd         $31, 0x10($29)
    /* 322C90 00422C90 0487100C */  jal        func_00421c10
    /* 322C94 00422C94 F8FF0424 */   addiu     $4, $0, -0x8
    /* 322C98 00422C98 1000BFDF */  ld         $31, 0x10($29)
    /* 322C9C 00422C9C 0800E003 */  jr         $31
    /* 322CA0 00422CA0 2000BD27 */   addiu     $29, $29, 0x20
    /* 322CA4 00422CA4 00000000 */  nop
.size func_00422c80, 0x28
