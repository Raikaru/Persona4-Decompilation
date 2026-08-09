.section .text
.set noat
.set noreorder
glabel func_004f9b28
    /* 3F9B28 004F9B28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9B2C 004F9B2C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F9B30 004F9B30 D4E6130C */  jal        func_004f9b50
    /* 3F9B34 004F9B34 00000000 */   nop
    /* 3F9B38 004F9B38 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9B3C 004F9B3C 80000424 */  addiu      $4, $0, 0x80
    /* 3F9B40 004F9B40 000040AC */  sw         $0, 0x0($2)
    /* 3F9B44 004F9B44 D8E61308 */  j          func_004f9b60
    /* 3F9B48 004F9B48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F9B4C 004F9B4C 00000000 */  nop
.size func_004f9b28, 0x28
