.section .text
.set noat
.set noreorder
glabel func_004d1d70
    /* 3D1D70 004D1D70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3D1D74 004D1D74 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1D78 004D1D78 2D808000 */  daddu      $16, $4, $0
    /* 3D1D7C 004D1D7C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D1D80 004D1D80 2D88A000 */  daddu      $17, $5, $0
    /* 3D1D84 004D1D84 1000B2FF */  sd         $18, 0x10($29)
    /* 3D1D88 004D1D88 2D90C000 */  daddu      $18, $6, $0
    /* 3D1D8C 004D1D8C 1800B3FF */  sd         $19, 0x18($29)
    /* 3D1D90 004D1D90 2D98E000 */  daddu      $19, $7, $0
    /* 3D1D94 004D1D94 2000B4FF */  sd         $20, 0x20($29)
    /* 3D1D98 004D1D98 2800BFFF */  sd         $31, 0x28($29)
    /* 3D1D9C 004D1D9C 3246130C */  jal        func_004d18c8
    /* 3D1DA0 004D1DA0 2DA00001 */   daddu     $20, $8, $0
    /* 3D1DA4 004D1DA4 2D200002 */  daddu      $4, $16, $0
    /* 3D1DA8 004D1DA8 2D282002 */  daddu      $5, $17, $0
    /* 3D1DAC 004D1DAC 2D304002 */  daddu      $6, $18, $0
    /* 3D1DB0 004D1DB0 2D386002 */  daddu      $7, $19, $0
    /* 3D1DB4 004D1DB4 7847130C */  jal        func_004d1de0
    /* 3D1DB8 004D1DB8 2D408002 */   daddu     $8, $20, $0
    /* 3D1DBC 004D1DBC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1DC0 004D1DC0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D1DC4 004D1DC4 1000B2DF */  ld         $18, 0x10($29)
    /* 3D1DC8 004D1DC8 1800B3DF */  ld         $19, 0x18($29)
    /* 3D1DCC 004D1DCC 2000B4DF */  ld         $20, 0x20($29)
    /* 3D1DD0 004D1DD0 2800BFDF */  ld         $31, 0x28($29)
    /* 3D1DD4 004D1DD4 34461308 */  j          func_004d18d0
    /* 3D1DD8 004D1DD8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3D1DDC 004D1DDC 00000000 */  nop
.size func_004d1d70, 0x70
