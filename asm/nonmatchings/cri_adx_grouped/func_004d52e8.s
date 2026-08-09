.section .text
.set noat
.set noreorder
glabel func_004d52e8
    /* 3D52E8 004D52E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D52EC 004D52EC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D52F0 004D52F0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D52F4 004D52F4 3615130C */  jal        func_004c54d8
    /* 3D52F8 004D52F8 2D808000 */   daddu     $16, $4, $0
    /* 3D52FC 004D52FC C854130C */  jal        func_004d5320
    /* 3D5300 004D5300 2D200002 */   daddu     $4, $16, $0
    /* 3D5304 004D5304 3815130C */  jal        func_004c54e0
    /* 3D5308 004D5308 2D804000 */   daddu     $16, $2, $0
    /* 3D530C 004D530C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5310 004D5310 2D100002 */  daddu      $2, $16, $0
    /* 3D5314 004D5314 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5318 004D5318 0800E003 */  jr         $31
    /* 3D531C 004D531C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d52e8, 0x38
