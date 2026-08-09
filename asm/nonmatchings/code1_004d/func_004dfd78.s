.section .text
.set noat
.set noreorder
glabel func_004dfd78
    /* 3DFD78 004DFD78 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DFD7C 004DFD7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DFD80 004DFD80 2D808000 */  daddu      $16, $4, $0
    /* 3DFD84 004DFD84 0800B1FF */  sd         $17, 0x8($29)
    /* 3DFD88 004DFD88 2D88A000 */  daddu      $17, $5, $0
    /* 3DFD8C 004DFD8C 1000B2FF */  sd         $18, 0x10($29)
    /* 3DFD90 004DFD90 1800BFFF */  sd         $31, 0x18($29)
    /* 3DFD94 004DFD94 E080130C */  jal        func_004e0380
    /* 3DFD98 004DFD98 2D90C000 */   daddu     $18, $6, $0
    /* 3DFD9C 004DFD9C 2D200002 */  daddu      $4, $16, $0
    /* 3DFDA0 004DFDA0 2D282002 */  daddu      $5, $17, $0
    /* 3DFDA4 004DFDA4 727F130C */  jal        func_004dfdc8
    /* 3DFDA8 004DFDA8 2D304002 */   daddu     $6, $18, $0
    /* 3DFDAC 004DFDAC 0000B0DF */  ld         $16, 0x0($29)
    /* 3DFDB0 004DFDB0 0800B1DF */  ld         $17, 0x8($29)
    /* 3DFDB4 004DFDB4 1000B2DF */  ld         $18, 0x10($29)
    /* 3DFDB8 004DFDB8 1800BFDF */  ld         $31, 0x18($29)
    /* 3DFDBC 004DFDBC E6801308 */  j          func_004e0398
    /* 3DFDC0 004DFDC0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DFDC4 004DFDC4 00000000 */  nop
.size func_004dfd78, 0x50
