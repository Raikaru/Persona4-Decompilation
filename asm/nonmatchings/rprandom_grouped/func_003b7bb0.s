.section .text
.set noat
.set noreorder
glabel func_003b7bb0
    /* 2B7BB0 003B7BB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2B7BB4 003B7BB4 2000BFFF */  sd         $31, 0x20($29)
    /* 2B7BB8 003B7BB8 1000B17F */  sq         $17, 0x10($29)
    /* 2B7BBC 003B7BBC 0000B07F */  sq         $16, 0x0($29)
    /* 2B7BC0 003B7BC0 2D888000 */  daddu      $17, $4, $0
    /* 2B7BC4 003B7BC4 1800848C */  lw         $4, 0x18($4)
    /* 2B7BC8 003B7BC8 08008010 */  beqz       $4, .L003B7BEC
    /* 2B7BCC 003B7BCC 2D80E000 */   daddu     $16, $7, $0
    /* 2B7BD0 003B7BD0 FCE00E0C */  jal        func_003b83f0
    /* 2B7BD4 003B7BD4 00000000 */   nop
    /* 2B7BD8 003B7BD8 04004010 */  beqz       $2, .L003B7BEC
    /* 2B7BDC 003B7BDC 00000000 */   nop
    /* 2B7BE0 003B7BE0 2D202002 */  daddu      $4, $17, $0
    /* 2B7BE4 003B7BE4 20DD0E0C */  jal        func_003b7480
    /* 2B7BE8 003B7BE8 2D280002 */   daddu     $5, $16, $0
  .L003B7BEC:
    /* 2B7BEC 003B7BEC 2000BFDF */  ld         $31, 0x20($29)
    /* 2B7BF0 003B7BF0 01000224 */  addiu      $2, $0, 0x1
    /* 2B7BF4 003B7BF4 1000B17B */  lq         $17, 0x10($29)
    /* 2B7BF8 003B7BF8 0000B07B */  lq         $16, 0x0($29)
    /* 2B7BFC 003B7BFC 0800E003 */  jr         $31
    /* 2B7C00 003B7C00 3000BD27 */   addiu     $29, $29, 0x30
    /* 2B7C04 003B7C04 00000000 */  nop
    /* 2B7C08 003B7C08 00000000 */  nop
    /* 2B7C0C 003B7C0C 00000000 */  nop
.size func_003b7bb0, 0x60
