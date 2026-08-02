.section .text
.set noat
.set noreorder
glabel func_002b6b90
    /* 1B6B90 002B6B90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1B6B94 002B6B94 0000BFFF */  sd         $31, 0x0($29)
    /* 1B6B98 002B6B98 1800A5AF */  sw         $5, 0x18($29)
    /* 1B6B9C 002B6B9C 1C00A6AF */  sw         $6, 0x1C($29)
    /* 1B6BA0 002B6BA0 74B5828F */  lw         $2, -0x4A8C($28)
    /* 1B6BA4 002B6BA4 3800438C */  lw         $3, 0x38($2)
    /* 1B6BA8 002B6BA8 3C140400 */  dsll32     $2, $4, 16
    /* 1B6BAC 002B6BAC 3F140200 */  dsra32     $2, $2, 16
    /* 1B6BB0 002B6BB0 00120200 */  sll        $2, $2, 8
    /* 1B6BB4 002B6BB4 21106200 */  addu       $2, $3, $2
    /* 1B6BB8 002B6BB8 3C4C0900 */  dsll32     $9, $9, 16
    /* 1B6BBC 002B6BBC 3F4C0900 */  dsra32     $9, $9, 16
    /* 1B6BC0 002B6BC0 14004424 */  addiu      $4, $2, 0x14
    /* 1B6BC4 002B6BC4 DCE00A0C */  jal        func_002b8370
    /* 1B6BC8 002B6BC8 00000000 */   nop
    /* 1B6BCC 002B6BCC 0000BFDF */  ld         $31, 0x0($29)
    /* 1B6BD0 002B6BD0 2000BD27 */  addiu      $29, $29, 0x20
    /* 1B6BD4 002B6BD4 0800E003 */  jr         $31
    /* 1B6BD8 002B6BD8 00000000 */   nop
    /* 1B6BDC 002B6BDC 00000000 */  nop
.size func_002b6b90, 0x50
