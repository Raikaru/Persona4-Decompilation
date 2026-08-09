.section .text
.set noat
.set noreorder
glabel func_004c3cf0
    /* 3C3CF0 004C3CF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C3CF4 004C3CF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C3CF8 004C3CF8 2D808000 */  daddu      $16, $4, $0
    /* 3C3CFC 004C3CFC 0800BFFF */  sd         $31, 0x8($29)
    /* 3C3D00 004C3D00 AC000526 */  addiu      $5, $16, 0xAC
    /* 3C3D04 004C3D04 B0000626 */  addiu      $6, $16, 0xB0
    /* 3C3D08 004C3D08 5E62130C */  jal        func_004d8978
    /* 3C3D0C 004C3D0C 0800048E */   lw        $4, 0x8($16)
    /* 3C3D10 004C3D10 0800048E */  lw         $4, 0x8($16)
    /* 3C3D14 004C3D14 AA000726 */  addiu      $7, $16, 0xAA
    /* 3C3D18 004C3D18 A6000526 */  addiu      $5, $16, 0xA6
    /* 3C3D1C 004C3D1C A8000626 */  addiu      $6, $16, 0xA8
    /* 3C3D20 004C3D20 0000B0DF */  ld         $16, 0x0($29)
    /* 3C3D24 004C3D24 0800BFDF */  ld         $31, 0x8($29)
    /* 3C3D28 004C3D28 6C621308 */  j          func_004d89b0
    /* 3C3D2C 004C3D2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c3cf0, 0x40
