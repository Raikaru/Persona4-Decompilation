.section .text
.set noat
.set noreorder
glabel func_002b6af0
    /* 1B6AF0 002B6AF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B6AF4 002B6AF4 0000BFFF */  sd         $31, 0x0($29)
    /* 1B6AF8 002B6AF8 74B5828F */  lw         $2, -0x4A8C($28)
    /* 1B6AFC 002B6AFC 3800438C */  lw         $3, 0x38($2)
    /* 1B6B00 002B6B00 3C140400 */  dsll32     $2, $4, 16
    /* 1B6B04 002B6B04 3F140200 */  dsra32     $2, $2, 16
    /* 1B6B08 002B6B08 00120200 */  sll        $2, $2, 8
    /* 1B6B0C 002B6B0C 21106200 */  addu       $2, $3, $2
    /* 1B6B10 002B6B10 3C3C0700 */  dsll32     $7, $7, 16
    /* 1B6B14 002B6B14 3F3C0700 */  dsra32     $7, $7, 16
    /* 1B6B18 002B6B18 14004424 */  addiu      $4, $2, 0x14
    /* 1B6B1C 002B6B1C C0E00A0C */  jal        func_002b8300
    /* 1B6B20 002B6B20 00000000 */   nop
    /* 1B6B24 002B6B24 0000BFDF */  ld         $31, 0x0($29)
    /* 1B6B28 002B6B28 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B6B2C 002B6B2C 0800E003 */  jr         $31
    /* 1B6B30 002B6B30 00000000 */   nop
    /* 1B6B34 002B6B34 00000000 */  nop
    /* 1B6B38 002B6B38 00000000 */  nop
    /* 1B6B3C 002B6B3C 00000000 */  nop
.size func_002b6af0, 0x50
