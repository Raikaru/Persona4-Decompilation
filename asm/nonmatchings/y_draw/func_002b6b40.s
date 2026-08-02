.section .text
.set noat
.set noreorder
glabel func_002b6b40
    /* 1B6B40 002B6B40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B6B44 002B6B44 0000BFFF */  sd         $31, 0x0($29)
    /* 1B6B48 002B6B48 74B5828F */  lw         $2, -0x4A8C($28)
    /* 1B6B4C 002B6B4C 3800438C */  lw         $3, 0x38($2)
    /* 1B6B50 002B6B50 3C140400 */  dsll32     $2, $4, 16
    /* 1B6B54 002B6B54 3F140200 */  dsra32     $2, $2, 16
    /* 1B6B58 002B6B58 00120200 */  sll        $2, $2, 8
    /* 1B6B5C 002B6B5C 21106200 */  addu       $2, $3, $2
    /* 1B6B60 002B6B60 3C3C0700 */  dsll32     $7, $7, 16
    /* 1B6B64 002B6B64 3F3C0700 */  dsra32     $7, $7, 16
    /* 1B6B68 002B6B68 14004424 */  addiu      $4, $2, 0x14
    /* 1B6B6C 002B6B6C D0E00A0C */  jal        func_002b8340
    /* 1B6B70 002B6B70 00000000 */   nop
    /* 1B6B74 002B6B74 0000BFDF */  ld         $31, 0x0($29)
    /* 1B6B78 002B6B78 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B6B7C 002B6B7C 0800E003 */  jr         $31
    /* 1B6B80 002B6B80 00000000 */   nop
    /* 1B6B84 002B6B84 00000000 */  nop
    /* 1B6B88 002B6B88 00000000 */  nop
    /* 1B6B8C 002B6B8C 00000000 */  nop
.size func_002b6b40, 0x50
