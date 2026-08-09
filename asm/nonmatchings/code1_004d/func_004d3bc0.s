.section .text
.set noat
.set noreorder
glabel func_004d3bc0
    /* 3D3BC0 004D3BC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D3BC4 004D3BC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D3BC8 004D3BC8 2D808000 */  daddu      $16, $4, $0
    /* 3D3BCC 004D3BCC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D3BD0 004D3BD0 1000BFFF */  sd         $31, 0x10($29)
    /* 3D3BD4 004D3BD4 3615130C */  jal        func_004c54d8
    /* 3D3BD8 004D3BD8 2D88A000 */   daddu     $17, $5, $0
    /* 3D3BDC 004D3BDC 2D200002 */  daddu      $4, $16, $0
    /* 3D3BE0 004D3BE0 024F130C */  jal        func_004d3c08
    /* 3D3BE4 004D3BE4 2D282002 */   daddu     $5, $17, $0
    /* 3D3BE8 004D3BE8 3815130C */  jal        func_004c54e0
    /* 3D3BEC 004D3BEC 2D804000 */   daddu     $16, $2, $0
    /* 3D3BF0 004D3BF0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D3BF4 004D3BF4 2D100002 */  daddu      $2, $16, $0
    /* 3D3BF8 004D3BF8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D3BFC 004D3BFC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D3C00 004D3C00 0800E003 */  jr         $31
    /* 3D3C04 004D3C04 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d3bc0, 0x48
