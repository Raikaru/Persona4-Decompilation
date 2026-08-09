.section .text
.set noat
.set noreorder
glabel func_004c91d0
    /* 3C91D0 004C91D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C91D4 004C91D4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C91D8 004C91D8 0800BFFF */  sd         $31, 0x8($29)
    /* 3C91DC 004C91DC 4627130C */  jal        func_004c9d18
    /* 3C91E0 004C91E0 2D808000 */   daddu     $16, $4, $0
    /* 3C91E4 004C91E4 8224130C */  jal        func_004c9208
    /* 3C91E8 004C91E8 2D200002 */   daddu     $4, $16, $0
    /* 3C91EC 004C91EC 4C27130C */  jal        func_004c9d30
    /* 3C91F0 004C91F0 2D804000 */   daddu     $16, $2, $0
    /* 3C91F4 004C91F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3C91F8 004C91F8 2D100002 */  daddu      $2, $16, $0
    /* 3C91FC 004C91FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9200 004C9200 0800E003 */  jr         $31
    /* 3C9204 004C9204 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c91d0, 0x38
