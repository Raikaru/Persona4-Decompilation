.section .text
.set noat
.set noreorder
glabel func_0044e7a8
    /* 34E7A8 0044E7A8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 34E7AC 0044E7AC 0000A4AF */  sw         $4, 0x0($29)
    /* 34E7B0 0044E7B0 2000BFFF */  sd         $31, 0x20($29)
    /* 34E7B4 0044E7B4 0400A5AF */  sw         $5, 0x4($29)
    /* 34E7B8 0044E7B8 2D20A003 */  daddu      $4, $29, $0
    /* 34E7BC 0044E7BC 0800A6AF */  sw         $6, 0x8($29)
    /* 34E7C0 0044E7C0 4637110C */  jal        func_0044dd18
    /* 34E7C4 0044E7C4 1000A7FF */   sd        $7, 0x10($29)
    /* 34E7C8 0044E7C8 2000BFDF */  ld         $31, 0x20($29)
    /* 34E7CC 0044E7CC 0800E003 */  jr         $31
    /* 34E7D0 0044E7D0 3000BD27 */   addiu     $29, $29, 0x30
    /* 34E7D4 0044E7D4 00000000 */  nop
.size func_0044e7a8, 0x30
