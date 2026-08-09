.section .text
.set noat
.set noreorder
glabel func_004d5dc8
    /* 3D5DC8 004D5DC8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D5DCC 004D5DCC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5DD0 004D5DD0 2D808000 */  daddu      $16, $4, $0
    /* 3D5DD4 004D5DD4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D5DD8 004D5DD8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D5DDC 004D5DDC 3615130C */  jal        func_004c54d8
    /* 3D5DE0 004D5DE0 2D88A000 */   daddu     $17, $5, $0
    /* 3D5DE4 004D5DE4 2D200002 */  daddu      $4, $16, $0
    /* 3D5DE8 004D5DE8 8257130C */  jal        func_004d5e08
    /* 3D5DEC 004D5DEC 2D282002 */   daddu     $5, $17, $0
    /* 3D5DF0 004D5DF0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5DF4 004D5DF4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D5DF8 004D5DF8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D5DFC 004D5DFC 38151308 */  j          func_004c54e0
    /* 3D5E00 004D5E00 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D5E04 004D5E04 00000000 */  nop
.size func_004d5dc8, 0x40
