.section .text
.set noat
.set noreorder
glabel func_002b6a70
    /* 1B6A70 002B6A70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B6A74 002B6A74 0000BFFF */  sd         $31, 0x0($29)
    /* 1B6A78 002B6A78 74B5828F */  lw         $2, -0x4A8C($28)
    /* 1B6A7C 002B6A7C 3800438C */  lw         $3, 0x38($2)
    /* 1B6A80 002B6A80 3C140400 */  dsll32     $2, $4, 16
    /* 1B6A84 002B6A84 3F140200 */  dsra32     $2, $2, 16
    /* 1B6A88 002B6A88 00120200 */  sll        $2, $2, 8
    /* 1B6A8C 002B6A8C 21106200 */  addu       $2, $3, $2
    /* 1B6A90 002B6A90 3C4C0900 */  dsll32     $9, $9, 16
    /* 1B6A94 002B6A94 3F4C0900 */  dsra32     $9, $9, 16
    /* 1B6A98 002B6A98 14004424 */  addiu      $4, $2, 0x14
    /* 1B6A9C 002B6A9C B4E00A0C */  jal        func_002b82d0
    /* 1B6AA0 002B6AA0 00000000 */   nop
    /* 1B6AA4 002B6AA4 0000BFDF */  ld         $31, 0x0($29)
    /* 1B6AA8 002B6AA8 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B6AAC 002B6AAC 0800E003 */  jr         $31
    /* 1B6AB0 002B6AB0 00000000 */   nop
    /* 1B6AB4 002B6AB4 00000000 */  nop
    /* 1B6AB8 002B6AB8 00000000 */  nop
    /* 1B6ABC 002B6ABC 00000000 */  nop
.size func_002b6a70, 0x50
