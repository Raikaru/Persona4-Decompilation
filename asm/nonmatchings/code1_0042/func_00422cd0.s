.section .text
.set noat
.set noreorder
glabel func_00422cd0
    /* 322CD0 00422CD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 322CD4 00422CD4 0000A4AF */  sw         $4, 0x0($29)
    /* 322CD8 00422CD8 2D28A003 */  daddu      $5, $29, $0
    /* 322CDC 00422CDC 1000BFFF */  sd         $31, 0x10($29)
    /* 322CE0 00422CE0 0487100C */  jal        func_00421c10
    /* 322CE4 00422CE4 10000424 */   addiu     $4, $0, 0x10
    /* 322CE8 00422CE8 1000BFDF */  ld         $31, 0x10($29)
    /* 322CEC 00422CEC 0800E003 */  jr         $31
    /* 322CF0 00422CF0 2000BD27 */   addiu     $29, $29, 0x20
    /* 322CF4 00422CF4 00000000 */  nop
.size func_00422cd0, 0x28
