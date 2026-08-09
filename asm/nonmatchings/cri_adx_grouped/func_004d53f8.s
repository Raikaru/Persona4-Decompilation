.section .text
.set noat
.set noreorder
glabel func_004d53f8
    /* 3D53F8 004D53F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D53FC 004D53FC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5400 004D5400 0800BFFF */  sd         $31, 0x8($29)
    /* 3D5404 004D5404 3615130C */  jal        func_004c54d8
    /* 3D5408 004D5408 2D808000 */   daddu     $16, $4, $0
    /* 3D540C 004D540C 0E55130C */  jal        func_004d5438
    /* 3D5410 004D5410 2D200002 */   daddu     $4, $16, $0
    /* 3D5414 004D5414 3815130C */  jal        func_004c54e0
    /* 3D5418 004D5418 2D804000 */   daddu     $16, $2, $0
    /* 3D541C 004D541C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5420 004D5420 2D100002 */  daddu      $2, $16, $0
    /* 3D5424 004D5424 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5428 004D5428 0800E003 */  jr         $31
    /* 3D542C 004D542C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d53f8, 0x38
