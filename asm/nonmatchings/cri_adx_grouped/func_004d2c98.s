.section .text
.set noat
.set noreorder
glabel func_004d2c98
    /* 3D2C98 004D2C98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2C9C 004D2C9C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2CA0 004D2CA0 2D808000 */  daddu      $16, $4, $0
    /* 3D2CA4 004D2CA4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2CA8 004D2CA8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D2CAC 004D2CAC 3246130C */  jal        func_004d18c8
    /* 3D2CB0 004D2CB0 2D88A000 */   daddu     $17, $5, $0
    /* 3D2CB4 004D2CB4 2D200002 */  daddu      $4, $16, $0
    /* 3D2CB8 004D2CB8 384B130C */  jal        func_004d2ce0
    /* 3D2CBC 004D2CBC 2D282002 */   daddu     $5, $17, $0
    /* 3D2CC0 004D2CC0 3446130C */  jal        func_004d18d0
    /* 3D2CC4 004D2CC4 2D804000 */   daddu     $16, $2, $0
    /* 3D2CC8 004D2CC8 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2CCC 004D2CCC 2D100002 */  daddu      $2, $16, $0
    /* 3D2CD0 004D2CD0 1000BFDF */  ld         $31, 0x10($29)
    /* 3D2CD4 004D2CD4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2CD8 004D2CD8 0800E003 */  jr         $31
    /* 3D2CDC 004D2CDC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d2c98, 0x48
