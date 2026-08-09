.section .text
.set noat
.set noreorder
glabel func_0044e0a8
    /* 34E0A8 0044E0A8 80FFBD27 */  addiu      $29, $29, -0x80
    /* 34E0AC 0044E0AC 6000A4FF */  sd         $4, 0x60($29)
    /* 34E0B0 0044E0B0 6800A5FF */  sd         $5, 0x68($29)
    /* 34E0B4 0044E0B4 7800BFFF */  sd         $31, 0x78($29)
    /* 34E0B8 0044E0B8 6000A427 */  addiu      $4, $29, 0x60
    /* 34E0BC 0044E0BC 7000B0FF */  sd         $16, 0x70($29)
    /* 34E0C0 0044E0C0 7C37110C */  jal        func_0044ddf0
    /* 34E0C4 0044E0C4 2D28A003 */   daddu     $5, $29, $0
    /* 34E0C8 0044E0C8 2000B027 */  addiu      $16, $29, 0x20
    /* 34E0CC 0044E0CC 6800A427 */  addiu      $4, $29, 0x68
    /* 34E0D0 0044E0D0 7C37110C */  jal        func_0044ddf0
    /* 34E0D4 0044E0D4 2D280002 */   daddu     $5, $16, $0
    /* 34E0D8 0044E0D8 2D280002 */  daddu      $5, $16, $0
    /* 34E0DC 0044E0DC 4000A627 */  addiu      $6, $29, 0x40
    /* 34E0E0 0044E0E0 A037110C */  jal        func_0044de80
    /* 34E0E4 0044E0E4 2D20A003 */   daddu     $4, $29, $0
    /* 34E0E8 0044E0E8 4637110C */  jal        func_0044dd18
    /* 34E0EC 0044E0EC 2D204000 */   daddu     $4, $2, $0
    /* 34E0F0 0044E0F0 7000B0DF */  ld         $16, 0x70($29)
    /* 34E0F4 0044E0F4 7800BFDF */  ld         $31, 0x78($29)
    /* 34E0F8 0044E0F8 0800E003 */  jr         $31
    /* 34E0FC 0044E0FC 8000BD27 */   addiu     $29, $29, 0x80
.size func_0044e0a8, 0x58
