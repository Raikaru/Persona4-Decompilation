.section .text
.set noat
.set noreorder
glabel func_004d2dc8
    /* 3D2DC8 004D2DC8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2DCC 004D2DCC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2DD0 004D2DD0 2D808000 */  daddu      $16, $4, $0
    /* 3D2DD4 004D2DD4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2DD8 004D2DD8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D2DDC 004D2DDC 3246130C */  jal        func_004d18c8
    /* 3D2DE0 004D2DE0 2D88A000 */   daddu     $17, $5, $0
    /* 3D2DE4 004D2DE4 2D200002 */  daddu      $4, $16, $0
    /* 3D2DE8 004D2DE8 824B130C */  jal        func_004d2e08
    /* 3D2DEC 004D2DEC 2D282002 */   daddu     $5, $17, $0
    /* 3D2DF0 004D2DF0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2DF4 004D2DF4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2DF8 004D2DF8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D2DFC 004D2DFC 34461308 */  j          func_004d18d0
    /* 3D2E00 004D2E00 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D2E04 004D2E04 00000000 */  nop
.size func_004d2dc8, 0x40
