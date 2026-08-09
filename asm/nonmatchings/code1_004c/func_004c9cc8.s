.section .text
.set noat
.set noreorder
glabel func_004c9cc8
    /* 3C9CC8 004C9CC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9CCC 004C9CCC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9CD0 004C9CD0 0800BFFF */  sd         $31, 0x8($29)
    /* 3C9CD4 004C9CD4 4627130C */  jal        func_004c9d18
    /* 3C9CD8 004C9CD8 2D808000 */   daddu     $16, $4, $0
    /* 3C9CDC 004C9CDC 4027130C */  jal        func_004c9d00
    /* 3C9CE0 004C9CE0 2D200002 */   daddu     $4, $16, $0
    /* 3C9CE4 004C9CE4 4C27130C */  jal        func_004c9d30
    /* 3C9CE8 004C9CE8 2D804000 */   daddu     $16, $2, $0
    /* 3C9CEC 004C9CEC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C9CF0 004C9CF0 2D100002 */  daddu      $2, $16, $0
    /* 3C9CF4 004C9CF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9CF8 004C9CF8 0800E003 */  jr         $31
    /* 3C9CFC 004C9CFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c9cc8, 0x38
