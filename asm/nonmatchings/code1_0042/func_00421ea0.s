.section .text
.set noat
.set noreorder
glabel func_00421ea0
    /* 321EA0 00421EA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 321EA4 00421EA4 0000BFFF */  sd         $31, 0x0($29)
    /* 321EA8 00421EA8 14F7100C */  jal        func_0043dc50
    /* 321EAC 00421EAC 00000000 */   nop
    /* 321EB0 00421EB0 05000324 */  addiu      $3, $0, 0x5
    /* 321EB4 00421EB4 0000BFDF */  ld         $31, 0x0($29)
    /* 321EB8 00421EB8 000043AC */  sw         $3, 0x0($2)
    /* 321EBC 00421EBC FFFF0224 */  addiu      $2, $0, -0x1
    /* 321EC0 00421EC0 0800E003 */  jr         $31
    /* 321EC4 00421EC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00421ea0, 0x28
