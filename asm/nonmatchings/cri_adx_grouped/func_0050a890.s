.section .text
.set noat
.set noreorder
glabel func_0050a890
    /* 40A890 0050A890 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40A894 0050A894 1000B0FF */  sd         $16, 0x10($29)
    /* 40A898 0050A898 2D80E000 */  daddu      $16, $7, $0
    /* 40A89C 0050A89C 1800BFFF */  sd         $31, 0x18($29)
    /* 40A8A0 0050A8A0 4C68140C */  jal        func_0051a130
    /* 40A8A4 0050A8A4 2D38A003 */   daddu     $7, $29, $0
    /* 40A8A8 0050A8A8 2D280002 */  daddu      $5, $16, $0
    /* 40A8AC 0050A8AC 8E2A140C */  jal        func_0050aa38
    /* 40A8B0 0050A8B0 2D20A003 */   daddu     $4, $29, $0
    /* 40A8B4 0050A8B4 1000B0DF */  ld         $16, 0x10($29)
    /* 40A8B8 0050A8B8 1800BFDF */  ld         $31, 0x18($29)
    /* 40A8BC 0050A8BC 0800E003 */  jr         $31
    /* 40A8C0 0050A8C0 2000BD27 */   addiu     $29, $29, 0x20
    /* 40A8C4 0050A8C4 00000000 */  nop
.size func_0050a890, 0x38
