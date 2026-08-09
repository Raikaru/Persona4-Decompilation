.section .text
.set noat
.set noreorder
glabel func_004d22c8
    /* 3D22C8 004D22C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D22CC 004D22CC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D22D0 004D22D0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D22D4 004D22D4 3246130C */  jal        func_004d18c8
    /* 3D22D8 004D22D8 2D808000 */   daddu     $16, $4, $0
    /* 3D22DC 004D22DC BE48130C */  jal        func_004d22f8
    /* 3D22E0 004D22E0 2D200002 */   daddu     $4, $16, $0
    /* 3D22E4 004D22E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D22E8 004D22E8 0800BFDF */  ld         $31, 0x8($29)
    /* 3D22EC 004D22EC 34461308 */  j          func_004d18d0
    /* 3D22F0 004D22F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D22F4 004D22F4 00000000 */  nop
.size func_004d22c8, 0x30
