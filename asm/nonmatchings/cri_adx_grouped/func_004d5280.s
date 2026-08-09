.section .text
.set noat
.set noreorder
glabel func_004d5280
    /* 3D5280 004D5280 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D5284 004D5284 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5288 004D5288 2D808000 */  daddu      $16, $4, $0
    /* 3D528C 004D528C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D5290 004D5290 1000BFFF */  sd         $31, 0x10($29)
    /* 3D5294 004D5294 3615130C */  jal        func_004c54d8
    /* 3D5298 004D5298 2D88A000 */   daddu     $17, $5, $0
    /* 3D529C 004D529C 2D200002 */  daddu      $4, $16, $0
    /* 3D52A0 004D52A0 B254130C */  jal        func_004d52c8
    /* 3D52A4 004D52A4 2D282002 */   daddu     $5, $17, $0
    /* 3D52A8 004D52A8 3815130C */  jal        func_004c54e0
    /* 3D52AC 004D52AC 2D804000 */   daddu     $16, $2, $0
    /* 3D52B0 004D52B0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D52B4 004D52B4 2D100002 */  daddu      $2, $16, $0
    /* 3D52B8 004D52B8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D52BC 004D52BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D52C0 004D52C0 0800E003 */  jr         $31
    /* 3D52C4 004D52C4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d5280, 0x48
