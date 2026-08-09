.section .text
.set noat
.set noreorder
glabel func_004d1ce8
    /* 3D1CE8 004D1CE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1CEC 004D1CEC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1CF0 004D1CF0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D1CF4 004D1CF4 3246130C */  jal        func_004d18c8
    /* 3D1CF8 004D1CF8 2D808000 */   daddu     $16, $4, $0
    /* 3D1CFC 004D1CFC 4647130C */  jal        func_004d1d18
    /* 3D1D00 004D1D00 2D200002 */   daddu     $4, $16, $0
    /* 3D1D04 004D1D04 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1D08 004D1D08 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1D0C 004D1D0C 34461308 */  j          func_004d18d0
    /* 3D1D10 004D1D10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D1D14 004D1D14 00000000 */  nop
.size func_004d1ce8, 0x30
