.section .text
.set noat
.set noreorder
glabel func_004d6270
    /* 3D6270 004D6270 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6274 004D6274 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6278 004D6278 0800BFFF */  sd         $31, 0x8($29)
    /* 3D627C 004D627C 3615130C */  jal        func_004c54d8
    /* 3D6280 004D6280 00000000 */   nop
    /* 3D6284 004D6284 AA58130C */  jal        func_004d62a8
    /* 3D6288 004D6288 00000000 */   nop
    /* 3D628C 004D628C 3815130C */  jal        func_004c54e0
    /* 3D6290 004D6290 2D804000 */   daddu     $16, $2, $0
    /* 3D6294 004D6294 0800BFDF */  ld         $31, 0x8($29)
    /* 3D6298 004D6298 2D100002 */  daddu      $2, $16, $0
    /* 3D629C 004D629C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D62A0 004D62A0 0800E003 */  jr         $31
    /* 3D62A4 004D62A4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d6270, 0x38
