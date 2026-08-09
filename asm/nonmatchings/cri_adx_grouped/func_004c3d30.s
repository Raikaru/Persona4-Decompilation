.section .text
.set noat
.set noreorder
glabel func_004c3d30
    /* 3C3D30 004C3D30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C3D34 004C3D34 0000B0FF */  sd         $16, 0x0($29)
    /* 3C3D38 004C3D38 2D808000 */  daddu      $16, $4, $0
    /* 3C3D3C 004C3D3C 0800BFFF */  sd         $31, 0x8($29)
    /* 3C3D40 004C3D40 AC000526 */  addiu      $5, $16, 0xAC
    /* 3C3D44 004C3D44 B0000626 */  addiu      $6, $16, 0xB0
    /* 3C3D48 004C3D48 5462130C */  jal        func_004d8950
    /* 3C3D4C 004C3D4C 0800048E */   lw        $4, 0x8($16)
    /* 3C3D50 004C3D50 0800048E */  lw         $4, 0x8($16)
    /* 3C3D54 004C3D54 AA000786 */  lh         $7, 0xAA($16)
    /* 3C3D58 004C3D58 A6000586 */  lh         $5, 0xA6($16)
    /* 3C3D5C 004C3D5C A8000686 */  lh         $6, 0xA8($16)
    /* 3C3D60 004C3D60 0800BFDF */  ld         $31, 0x8($29)
    /* 3C3D64 004C3D64 0000B0DF */  ld         $16, 0x0($29)
    /* 3C3D68 004C3D68 68621308 */  j          func_004d89a0
    /* 3C3D6C 004C3D6C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c3d30, 0x40
