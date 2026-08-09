.section .text
.set noat
.set noreorder
glabel func_004d4f58
    /* 3D4F58 004D4F58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D4F5C 004D4F5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4F60 004D4F60 2D808000 */  daddu      $16, $4, $0
    /* 3D4F64 004D4F64 0800B1FF */  sd         $17, 0x8($29)
    /* 3D4F68 004D4F68 1000BFFF */  sd         $31, 0x10($29)
    /* 3D4F6C 004D4F6C 3615130C */  jal        func_004c54d8
    /* 3D4F70 004D4F70 2D88A000 */   daddu     $17, $5, $0
    /* 3D4F74 004D4F74 2D200002 */  daddu      $4, $16, $0
    /* 3D4F78 004D4F78 E853130C */  jal        func_004d4fa0
    /* 3D4F7C 004D4F7C 2D282002 */   daddu     $5, $17, $0
    /* 3D4F80 004D4F80 3815130C */  jal        func_004c54e0
    /* 3D4F84 004D4F84 2D804000 */   daddu     $16, $2, $0
    /* 3D4F88 004D4F88 0800B1DF */  ld         $17, 0x8($29)
    /* 3D4F8C 004D4F8C 2D100002 */  daddu      $2, $16, $0
    /* 3D4F90 004D4F90 1000BFDF */  ld         $31, 0x10($29)
    /* 3D4F94 004D4F94 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4F98 004D4F98 0800E003 */  jr         $31
    /* 3D4F9C 004D4F9C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d4f58, 0x48
