.section .text
.set noat
.set noreorder
glabel func_0044e3b8
    /* 34E3B8 0044E3B8 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 34E3BC 0044E3BC 4000A4FF */  sd         $4, 0x40($29)
    /* 34E3C0 0044E3C0 4800A5FF */  sd         $5, 0x48($29)
    /* 34E3C4 0044E3C4 5800BFFF */  sd         $31, 0x58($29)
    /* 34E3C8 0044E3C8 4000A427 */  addiu      $4, $29, 0x40
    /* 34E3CC 0044E3CC 5000B0FF */  sd         $16, 0x50($29)
    /* 34E3D0 0044E3D0 7C37110C */  jal        func_0044ddf0
    /* 34E3D4 0044E3D4 2D28A003 */   daddu     $5, $29, $0
    /* 34E3D8 0044E3D8 2000B027 */  addiu      $16, $29, 0x20
    /* 34E3DC 0044E3DC 4800A427 */  addiu      $4, $29, 0x48
    /* 34E3E0 0044E3E0 7C37110C */  jal        func_0044ddf0
    /* 34E3E4 0044E3E4 2D280002 */   daddu     $5, $16, $0
    /* 34E3E8 0044E3E8 2D280002 */  daddu      $5, $16, $0
    /* 34E3EC 0044E3EC 0439110C */  jal        func_0044e410
    /* 34E3F0 0044E3F0 2D20A003 */   daddu     $4, $29, $0
    /* 34E3F4 0044E3F4 4637110C */  jal        func_0044dd18
    /* 34E3F8 0044E3F8 2D204000 */   daddu     $4, $2, $0
    /* 34E3FC 0044E3FC 5000B0DF */  ld         $16, 0x50($29)
    /* 34E400 0044E400 5800BFDF */  ld         $31, 0x58($29)
    /* 34E404 0044E404 0800E003 */  jr         $31
    /* 34E408 0044E408 6000BD27 */   addiu     $29, $29, 0x60
    /* 34E40C 0044E40C 00000000 */  nop
.size func_0044e3b8, 0x58
