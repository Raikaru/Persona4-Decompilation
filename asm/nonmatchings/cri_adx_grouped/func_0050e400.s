.section .text
.set noat
.set noreorder
glabel func_0050e400
    /* 40E400 0050E400 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40E404 0050E404 2D200000 */  daddu      $4, $0, $0
    /* 40E408 0050E408 3D000524 */  addiu      $5, $0, 0x3D
    /* 40E40C 0050E40C 1000BFFF */  sd         $31, 0x10($29)
    /* 40E410 0050E410 FE93140C */  jal        func_00524ff8
    /* 40E414 0050E414 2D30A003 */   daddu     $6, $29, $0
    /* 40E418 0050E418 0000A28F */  lw         $2, 0x0($29)
    /* 40E41C 0050E41C 1000BFDF */  ld         $31, 0x10($29)
    /* 40E420 0050E420 0800E003 */  jr         $31
    /* 40E424 0050E424 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050e400, 0x28
