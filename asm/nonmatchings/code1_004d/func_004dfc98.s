.section .text
.set noat
.set noreorder
glabel func_004dfc98
    /* 3DFC98 004DFC98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DFC9C 004DFC9C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DFCA0 004DFCA0 2D808000 */  daddu      $16, $4, $0
    /* 3DFCA4 004DFCA4 0800B1FF */  sd         $17, 0x8($29)
    /* 3DFCA8 004DFCA8 1000BFFF */  sd         $31, 0x10($29)
    /* 3DFCAC 004DFCAC E080130C */  jal        func_004e0380
    /* 3DFCB0 004DFCB0 2D88A000 */   daddu     $17, $5, $0
    /* 3DFCB4 004DFCB4 2D200002 */  daddu      $4, $16, $0
    /* 3DFCB8 004DFCB8 367F130C */  jal        func_004dfcd8
    /* 3DFCBC 004DFCBC 2D282002 */   daddu     $5, $17, $0
    /* 3DFCC0 004DFCC0 0000B0DF */  ld         $16, 0x0($29)
    /* 3DFCC4 004DFCC4 0800B1DF */  ld         $17, 0x8($29)
    /* 3DFCC8 004DFCC8 1000BFDF */  ld         $31, 0x10($29)
    /* 3DFCCC 004DFCCC E6801308 */  j          func_004e0398
    /* 3DFCD0 004DFCD0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DFCD4 004DFCD4 00000000 */  nop
.size func_004dfc98, 0x40
