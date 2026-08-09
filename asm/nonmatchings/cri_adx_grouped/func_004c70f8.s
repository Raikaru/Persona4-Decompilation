.section .text
.set noat
.set noreorder
glabel func_004c70f8
    /* 3C70F8 004C70F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C70FC 004C70FC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7100 004C7100 0800BFFF */  sd         $31, 0x8($29)
    /* 3C7104 004C7104 8A1C130C */  jal        func_004c7228
    /* 3C7108 004C7108 2D808000 */   daddu     $16, $4, $0
    /* 3C710C 004C710C 4C1C130C */  jal        func_004c7130
    /* 3C7110 004C7110 2D200002 */   daddu     $4, $16, $0
    /* 3C7114 004C7114 8C1C130C */  jal        func_004c7230
    /* 3C7118 004C7118 2D804000 */   daddu     $16, $2, $0
    /* 3C711C 004C711C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C7120 004C7120 2D100002 */  daddu      $2, $16, $0
    /* 3C7124 004C7124 0000B0DF */  ld         $16, 0x0($29)
    /* 3C7128 004C7128 0800E003 */  jr         $31
    /* 3C712C 004C712C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c70f8, 0x38
