.section .text
.set noat
.set noreorder
glabel func_004d30b8
    /* 3D30B8 004D30B8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D30BC 004D30BC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D30C0 004D30C0 2D808000 */  daddu      $16, $4, $0
    /* 3D30C4 004D30C4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D30C8 004D30C8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D30CC 004D30CC 3246130C */  jal        func_004d18c8
    /* 3D30D0 004D30D0 2D88A000 */   daddu     $17, $5, $0
    /* 3D30D4 004D30D4 2D200002 */  daddu      $4, $16, $0
    /* 3D30D8 004D30D8 3E4C130C */  jal        func_004d30f8
    /* 3D30DC 004D30DC 2D282002 */   daddu     $5, $17, $0
    /* 3D30E0 004D30E0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D30E4 004D30E4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D30E8 004D30E8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D30EC 004D30EC 34461308 */  j          func_004d18d0
    /* 3D30F0 004D30F0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D30F4 004D30F4 00000000 */  nop
.size func_004d30b8, 0x40
