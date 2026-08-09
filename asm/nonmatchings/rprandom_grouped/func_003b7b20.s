.section .text
.set noat
.set noreorder
glabel func_003b7b20
    /* 2B7B20 003B7B20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2B7B24 003B7B24 2000BFFF */  sd         $31, 0x20($29)
    /* 2B7B28 003B7B28 1000B17F */  sq         $17, 0x10($29)
    /* 2B7B2C 003B7B2C 0000B07F */  sq         $16, 0x0($29)
    /* 2B7B30 003B7B30 01001124 */  addiu      $17, $0, 0x1
    /* 2B7B34 003B7B34 2D808000 */  daddu      $16, $4, $0
    /* 2B7B38 003B7B38 58A20F0C */  jal        func_003e8960
    /* 2B7B3C 003B7B3C 20010424 */   addiu     $4, $0, 0x120
    /* 2B7B40 003B7B40 FFFF0324 */  addiu      $3, $0, -0x1
    /* 2B7B44 003B7B44 0D004314 */  bne        $2, $3, .L003B7B7C
    /* 2B7B48 003B7B48 00000000 */   nop
  .L003B7B4C:
    /* 2B7B4C 003B7B4C 1800048E */  lw         $4, 0x18($16)
    /* 2B7B50 003B7B50 08008010 */  beqz       $4, .L003B7B74
    /* 2B7B54 003B7B54 00000000 */   nop
    /* 2B7B58 003B7B58 FCE00E0C */  jal        func_003b83f0
    /* 2B7B5C 003B7B5C 00000000 */   nop
    /* 2B7B60 003B7B60 04004010 */  beqz       $2, .L003B7B74
    /* 2B7B64 003B7B64 00000000 */   nop
    /* 2B7B68 003B7B68 2D200002 */  daddu      $4, $16, $0
    /* 2B7B6C 003B7B6C 20DD0E0C */  jal        func_003b7480
    /* 2B7B70 003B7B70 2D282002 */   daddu     $5, $17, $0
  .L003B7B74:
    /* 2B7B74 003B7B74 09000010 */  b          .L003B7B9C
    /* 2B7B78 003B7B78 01000224 */   addiu     $2, $0, 0x1
  .L003B7B7C:
    /* 2B7B7C 003B7B7C E0060F0C */  jal        func_003c1b80
    /* 2B7B80 003B7B80 20010424 */   addiu     $4, $0, 0x120
    /* 2B7B84 003B7B84 21100202 */  addu       $2, $16, $2
    /* 2B7B88 003B7B88 00004290 */  lbu        $2, 0x0($2)
    /* 2B7B8C 003B7B8C EFFF4010 */  beqz       $2, .L003B7B4C
    /* 2B7B90 003B7B90 00000000 */   nop
    /* 2B7B94 003B7B94 EDFF0010 */  b          .L003B7B4C
    /* 2B7B98 003B7B98 02001124 */   addiu     $17, $0, 0x2
  .L003B7B9C:
    /* 2B7B9C 003B7B9C 2000BFDF */  ld         $31, 0x20($29)
    /* 2B7BA0 003B7BA0 1000B17B */  lq         $17, 0x10($29)
    /* 2B7BA4 003B7BA4 0000B07B */  lq         $16, 0x0($29)
    /* 2B7BA8 003B7BA8 0800E003 */  jr         $31
    /* 2B7BAC 003B7BAC 3000BD27 */   addiu     $29, $29, 0x30
.size func_003b7b20, 0x90
