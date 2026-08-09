.section .text
.set noat
.set noreorder
glabel func_004c9978
    /* 3C9978 004C9978 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C997C 004C997C 2D10E000 */  daddu      $2, $7, $0
    /* 3C9980 004C9980 2D480001 */  daddu      $9, $8, $0
    /* 3C9984 004C9984 2D404000 */  daddu      $8, $2, $0
    /* 3C9988 004C9988 1000BFFF */  sd         $31, 0x10($29)
    /* 3C998C 004C998C 8A26130C */  jal        func_004c9a28
    /* 3C9990 004C9990 2D38A003 */   daddu     $7, $29, $0
    /* 3C9994 004C9994 1000BFDF */  ld         $31, 0x10($29)
    /* 3C9998 004C9998 0800E003 */  jr         $31
    /* 3C999C 004C999C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c9978, 0x28
