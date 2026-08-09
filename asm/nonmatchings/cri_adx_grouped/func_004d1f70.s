.section .text
.set noat
.set noreorder
glabel func_004d1f70
    /* 3D1F70 004D1F70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1F74 004D1F74 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1F78 004D1F78 0800BFFF */  sd         $31, 0x8($29)
    /* 3D1F7C 004D1F7C 3246130C */  jal        func_004d18c8
    /* 3D1F80 004D1F80 2D808000 */   daddu     $16, $4, $0
    /* 3D1F84 004D1F84 E847130C */  jal        func_004d1fa0
    /* 3D1F88 004D1F88 2D200002 */   daddu     $4, $16, $0
    /* 3D1F8C 004D1F8C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1F90 004D1F90 0800BFDF */  ld         $31, 0x8($29)
    /* 3D1F94 004D1F94 34461308 */  j          func_004d18d0
    /* 3D1F98 004D1F98 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D1F9C 004D1F9C 00000000 */  nop
.size func_004d1f70, 0x30
