.section .text
.set noat
.set noreorder
glabel func_004da4c8
    /* 3DA4C8 004DA4C8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DA4CC 004DA4CC 0800B1FF */  sd         $17, 0x8($29)
    /* 3DA4D0 004DA4D0 2D88A000 */  daddu      $17, $5, $0
    /* 3DA4D4 004DA4D4 0000B0FF */  sd         $16, 0x0($29)
    /* 3DA4D8 004DA4D8 2D808000 */  daddu      $16, $4, $0
    /* 3DA4DC 004DA4DC 1000BFFF */  sd         $31, 0x10($29)
    /* 3DA4E0 004DA4E0 520A110C */  jal        func_00442948
    /* 3DA4E4 004DA4E4 2D202002 */   daddu     $4, $17, $0
    /* 3DA4E8 004DA4E8 2D202002 */  daddu      $4, $17, $0
    /* 3DA4EC 004DA4EC 220A0626 */  addiu      $6, $16, 0xA22
    /* 3DA4F0 004DA4F0 240A0726 */  addiu      $7, $16, 0xA24
    /* 3DA4F4 004DA4F4 260A0826 */  addiu      $8, $16, 0xA26
    /* 3DA4F8 004DA4F8 C866130C */  jal        func_004d9b20
    /* 3DA4FC 004DA4FC 2D284000 */   daddu     $5, $2, $0
    /* 3DA500 004DA500 200A00A6 */  sh         $0, 0xA20($16)
    /* 3DA504 004DA504 0800B1DF */  ld         $17, 0x8($29)
    /* 3DA508 004DA508 0000B0DF */  ld         $16, 0x0($29)
    /* 3DA50C 004DA50C 1000BFDF */  ld         $31, 0x10($29)
    /* 3DA510 004DA510 0800E003 */  jr         $31
    /* 3DA514 004DA514 2000BD27 */   addiu     $29, $29, 0x20
.size func_004da4c8, 0x50
