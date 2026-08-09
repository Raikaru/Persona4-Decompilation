.section .text
.set noat
.set noreorder
glabel func_004d4fe0
    /* 3D4FE0 004D4FE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D4FE4 004D4FE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4FE8 004D4FE8 2D808000 */  daddu      $16, $4, $0
    /* 3D4FEC 004D4FEC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D4FF0 004D4FF0 1000BFFF */  sd         $31, 0x10($29)
    /* 3D4FF4 004D4FF4 3615130C */  jal        func_004c54d8
    /* 3D4FF8 004D4FF8 2D88A000 */   daddu     $17, $5, $0
    /* 3D4FFC 004D4FFC 2D200002 */  daddu      $4, $16, $0
    /* 3D5000 004D5000 0854130C */  jal        func_004d5020
    /* 3D5004 004D5004 2D282002 */   daddu     $5, $17, $0
    /* 3D5008 004D5008 0000B0DF */  ld         $16, 0x0($29)
    /* 3D500C 004D500C 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5010 004D5010 1000BFDF */  ld         $31, 0x10($29)
    /* 3D5014 004D5014 38151308 */  j          func_004c54e0
    /* 3D5018 004D5018 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D501C 004D501C 00000000 */  nop
.size func_004d4fe0, 0x40
