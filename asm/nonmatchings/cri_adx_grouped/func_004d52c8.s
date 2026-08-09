.section .text
.set noat
.set noreorder
glabel func_004d52c8
    /* 3D52C8 004D52C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D52CC 004D52CC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D52D0 004D52D0 D43B130C */  jal        func_004cef50
    /* 3D52D4 004D52D4 0400848C */   lw        $4, 0x4($4)
    /* 3D52D8 004D52D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D52DC 004D52DC 0800E003 */  jr         $31
    /* 3D52E0 004D52E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D52E4 004D52E4 00000000 */  nop
.size func_004d52c8, 0x20
