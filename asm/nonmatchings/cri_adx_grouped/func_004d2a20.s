.section .text
.set noat
.set noreorder
glabel func_004d2a20
    /* 3D2A20 004D2A20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2A24 004D2A24 0000BFFF */  sd         $31, 0x0($29)
    /* 3D2A28 004D2A28 3246130C */  jal        func_004d18c8
    /* 3D2A2C 004D2A2C 00000000 */   nop
    /* 3D2A30 004D2A30 924A130C */  jal        func_004d2a48
    /* 3D2A34 004D2A34 00000000 */   nop
    /* 3D2A38 004D2A38 0000BFDF */  ld         $31, 0x0($29)
    /* 3D2A3C 004D2A3C 34461308 */  j          func_004d18d0
    /* 3D2A40 004D2A40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D2A44 004D2A44 00000000 */  nop
.size func_004d2a20, 0x28
