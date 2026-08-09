.section .text
.set noat
.set noreorder
glabel func_004d1f00
    /* 3D1F00 004D1F00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1F04 004D1F04 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1F08 004D1F08 0800BFFF */  sd         $31, 0x8($29)
    /* 3D1F0C 004D1F0C 3246130C */  jal        func_004d18c8
    /* 3D1F10 004D1F10 2D808000 */   daddu     $16, $4, $0
    /* 3D1F14 004D1F14 CC47130C */  jal        func_004d1f30
    /* 3D1F18 004D1F18 2D200002 */   daddu     $4, $16, $0
    /* 3D1F1C 004D1F1C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1F20 004D1F20 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1F24 004D1F24 34461308 */  j          func_004d18d0
    /* 3D1F28 004D1F28 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D1F2C 004D1F2C 00000000 */  nop
.size func_004d1f00, 0x30
