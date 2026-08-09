.section .text
.set noat
.set noreorder
glabel func_004e0598
    /* 3E0598 004E0598 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E059C 004E059C 0000B0FF */  sd         $16, 0x0($29)
    /* 3E05A0 004E05A0 0800BFFF */  sd         $31, 0x8($29)
    /* 3E05A4 004E05A4 E080130C */  jal        func_004e0380
    /* 3E05A8 004E05A8 2D808000 */   daddu     $16, $4, $0
    /* 3E05AC 004E05AC 01000224 */  addiu      $2, $0, 0x1
    /* 3E05B0 004E05B0 0800BFDF */  ld         $31, 0x8($29)
    /* 3E05B4 004E05B4 100000AE */  sw         $0, 0x10($16)
    /* 3E05B8 004E05B8 010002A2 */  sb         $2, 0x1($16)
    /* 3E05BC 004E05BC 080000AE */  sw         $0, 0x8($16)
    /* 3E05C0 004E05C0 0C0000AE */  sw         $0, 0xC($16)
    /* 3E05C4 004E05C4 0000B0DF */  ld         $16, 0x0($29)
    /* 3E05C8 004E05C8 E6801308 */  j          func_004e0398
    /* 3E05CC 004E05CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e0598, 0x38
