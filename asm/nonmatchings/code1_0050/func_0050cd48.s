.section .text
.set noat
.set noreorder
glabel func_0050cd48
    /* 40CD48 0050CD48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CD4C 0050CD4C 0000B0FF */  sd         $16, 0x0($29)
    /* 40CD50 0050CD50 0800BFFF */  sd         $31, 0x8($29)
    /* 40CD54 0050CD54 D463100C */  jal        func_00418f50
    /* 40CD58 0050CD58 2D80A000 */   daddu     $16, $5, $0
    /* 40CD5C 0050CD5C 2D204000 */  daddu      $4, $2, $0
    /* 40CD60 0050CD60 01000524 */  addiu      $5, $0, 0x1
    /* 40CD64 0050CD64 4865100C */  jal        func_00419520
    /* 40CD68 0050CD68 1E000624 */   addiu     $6, $0, 0x1E
    /* 40CD6C 0050CD6C 000002AE */  sw         $2, 0x0($16)
    /* 40CD70 0050CD70 0800BFDF */  ld         $31, 0x8($29)
    /* 40CD74 0050CD74 0000B0DF */  ld         $16, 0x0($29)
    /* 40CD78 0050CD78 0800E003 */  jr         $31
    /* 40CD7C 0050CD7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050cd48, 0x38
