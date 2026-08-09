.section .text
.set noat
.set noreorder
glabel func_004d5260
    /* 3D5260 004D5260 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5264 004D5264 0000BFFF */  sd         $31, 0x0($29)
    /* 3D5268 004D5268 BE3B130C */  jal        func_004ceef8
    /* 3D526C 004D526C 0400848C */   lw        $4, 0x4($4)
    /* 3D5270 004D5270 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5274 004D5274 0800E003 */  jr         $31
    /* 3D5278 004D5278 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D527C 004D527C 00000000 */  nop
.size func_004d5260, 0x20
