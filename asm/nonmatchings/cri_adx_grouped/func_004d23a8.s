.section .text
.set noat
.set noreorder
glabel func_004d23a8
    /* 3D23A8 004D23A8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D23AC 004D23AC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D23B0 004D23B0 2D808000 */  daddu      $16, $4, $0
    /* 3D23B4 004D23B4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D23B8 004D23B8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D23BC 004D23BC 3246130C */  jal        func_004d18c8
    /* 3D23C0 004D23C0 2D88A000 */   daddu     $17, $5, $0
    /* 3D23C4 004D23C4 2D200002 */  daddu      $4, $16, $0
    /* 3D23C8 004D23C8 FA48130C */  jal        func_004d23e8
    /* 3D23CC 004D23CC 2D282002 */   daddu     $5, $17, $0
    /* 3D23D0 004D23D0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D23D4 004D23D4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D23D8 004D23D8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D23DC 004D23DC 34461308 */  j          func_004d18d0
    /* 3D23E0 004D23E0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D23E4 004D23E4 00000000 */  nop
.size func_004d23a8, 0x40
