.section .text
.set noat
.set noreorder
glabel func_00421fe0
    /* 321FE0 00421FE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 321FE4 00421FE4 0000BFFF */  sd         $31, 0x0($29)
    /* 321FE8 00421FE8 14F7100C */  jal        func_0043dc50
    /* 321FEC 00421FEC 00000000 */   nop
    /* 321FF0 00421FF0 05000324 */  addiu      $3, $0, 0x5
    /* 321FF4 00421FF4 0000BFDF */  ld         $31, 0x0($29)
    /* 321FF8 00421FF8 000043AC */  sw         $3, 0x0($2)
    /* 321FFC 00421FFC FFFF0224 */  addiu      $2, $0, -0x1
    /* 322000 00422000 0800E003 */  jr         $31
    /* 322004 00422004 1000BD27 */   addiu     $29, $29, 0x10
.size func_00421fe0, 0x28
