.section .text
.set noat
.set noreorder
glabel func_004d5488
    /* 3D5488 004D5488 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D548C 004D548C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5490 004D5490 2D808000 */  daddu      $16, $4, $0
    /* 3D5494 004D5494 0800B1FF */  sd         $17, 0x8($29)
    /* 3D5498 004D5498 1000BFFF */  sd         $31, 0x10($29)
    /* 3D549C 004D549C 3615130C */  jal        func_004c54d8
    /* 3D54A0 004D54A0 2D88A000 */   daddu     $17, $5, $0
    /* 3D54A4 004D54A4 2D200002 */  daddu      $4, $16, $0
    /* 3D54A8 004D54A8 3255130C */  jal        func_004d54c8
    /* 3D54AC 004D54AC 2D282002 */   daddu     $5, $17, $0
    /* 3D54B0 004D54B0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D54B4 004D54B4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D54B8 004D54B8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D54BC 004D54BC 38151308 */  j          func_004c54e0
    /* 3D54C0 004D54C0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D54C4 004D54C4 00000000 */  nop
.size func_004d5488, 0x40
