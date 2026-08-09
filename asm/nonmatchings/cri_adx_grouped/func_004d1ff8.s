.section .text
.set noat
.set noreorder
glabel func_004d1ff8
    /* 3D1FF8 004D1FF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D1FFC 004D1FFC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2000 004D2000 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2004 004D2004 3246130C */  jal        func_004d18c8
    /* 3D2008 004D2008 2D808000 */   daddu     $16, $4, $0
    /* 3D200C 004D200C 0C48130C */  jal        func_004d2030
    /* 3D2010 004D2010 2D200002 */   daddu     $4, $16, $0
    /* 3D2014 004D2014 3446130C */  jal        func_004d18d0
    /* 3D2018 004D2018 2D804000 */   daddu     $16, $2, $0
    /* 3D201C 004D201C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2020 004D2020 2D100002 */  daddu      $2, $16, $0
    /* 3D2024 004D2024 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2028 004D2028 0800E003 */  jr         $31
    /* 3D202C 004D202C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d1ff8, 0x38
