.section .text
.set noat
.set noreorder
glabel func_004c9e20
    /* 3C9E20 004C9E20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9E24 004C9E24 0000BFFF */  sd         $31, 0x0($29)
    /* 3C9E28 004C9E28 3615130C */  jal        func_004c54d8
    /* 3C9E2C 004C9E2C 00000000 */   nop
    /* 3C9E30 004C9E30 9227130C */  jal        func_004c9e48
    /* 3C9E34 004C9E34 00000000 */   nop
    /* 3C9E38 004C9E38 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9E3C 004C9E3C 38151308 */  j          func_004c54e0
    /* 3C9E40 004C9E40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9E44 004C9E44 00000000 */  nop
.size func_004c9e20, 0x28
