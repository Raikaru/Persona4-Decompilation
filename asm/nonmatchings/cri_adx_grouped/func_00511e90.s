.section .text
.set noat
.set noreorder
glabel func_00511e90
    /* 411E90 00511E90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411E94 00511E94 0000BFFF */  sd         $31, 0x0($29)
    /* 411E98 00511E98 F42C140C */  jal        func_0050b3d0
    /* 411E9C 00511E9C 00000000 */   nop
    /* 411EA0 00511EA0 2400428C */  lw         $2, 0x24($2)
    /* 411EA4 00511EA4 0000BFDF */  ld         $31, 0x0($29)
    /* 411EA8 00511EA8 0800E003 */  jr         $31
    /* 411EAC 00511EAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511e90, 0x20
