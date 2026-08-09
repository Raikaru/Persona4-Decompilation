.section .text
.set noat
.set noreorder
glabel func_004d5440
    /* 3D5440 004D5440 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5444 004D5444 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5448 004D5448 0800BFFF */  sd         $31, 0x8($29)
    /* 3D544C 004D544C 3615130C */  jal        func_004c54d8
    /* 3D5450 004D5450 2D808000 */   daddu     $16, $4, $0
    /* 3D5454 004D5454 1C55130C */  jal        func_004d5470
    /* 3D5458 004D5458 2D200002 */   daddu     $4, $16, $0
    /* 3D545C 004D545C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5460 004D5460 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5464 004D5464 38151308 */  j          func_004c54e0
    /* 3D5468 004D5468 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D546C 004D546C 00000000 */  nop
.size func_004d5440, 0x30
