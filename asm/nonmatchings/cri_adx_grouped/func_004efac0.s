.section .text
.set noat
.set noreorder
glabel func_004efac0
    /* 3EFAC0 004EFAC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFAC4 004EFAC4 10008224 */  addiu      $2, $4, 0x10
    /* 3EFAC8 004EFAC8 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFACC 004EFACC 2D80A000 */  daddu      $16, $5, $0
    /* 3EFAD0 004EFAD0 000002AE */  sw         $2, 0x0($16)
    /* 3EFAD4 004EFAD4 0800BFFF */  sd         $31, 0x8($29)
    /* 3EFAD8 004EFAD8 6CBE130C */  jal        func_004ef9b0
    /* 3EFADC 004EFADC 08008424 */   addiu     $4, $4, 0x8
    /* 3EFAE0 004EFAE0 040002AE */  sw         $2, 0x4($16)
    /* 3EFAE4 004EFAE4 0800BFDF */  ld         $31, 0x8($29)
    /* 3EFAE8 004EFAE8 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFAEC 004EFAEC 0800E003 */  jr         $31
    /* 3EFAF0 004EFAF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EFAF4 004EFAF4 00000000 */  nop
.size func_004efac0, 0x38
