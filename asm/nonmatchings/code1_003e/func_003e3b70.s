.section .text
.set noat
.set noreorder
glabel func_003e3b70
    /* 2E3B70 003E3B70 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2E3B74 003E3B74 3000BFFF */  sd         $31, 0x30($29)
    /* 2E3B78 003E3B78 2000B27F */  sq         $18, 0x20($29)
    /* 2E3B7C 003E3B7C 1000B17F */  sq         $17, 0x10($29)
    /* 2E3B80 003E3B80 2D908000 */  daddu      $18, $4, $0
    /* 2E3B84 003E3B84 0000B07F */  sq         $16, 0x0($29)
    /* 2E3B88 003E3B88 1000908C */  lw         $16, 0x10($4)
    /* 2E3B8C 003E3B8C 18000012 */  beqz       $16, .L003E3BF0
    /* 2E3B90 003E3B90 2D88A000 */   daddu     $17, $5, $0
  .L003E3B94:
    /* 2E3B94 003E3B94 0000058E */  lw         $5, 0x0($16)
    /* 2E3B98 003E3B98 0400068E */  lw         $6, 0x4($16)
    /* 2E3B9C 003E3B9C 2000028E */  lw         $2, 0x20($16)
    /* 2E3BA0 003E3BA0 09F84000 */  jalr       $2
    /* 2E3BA4 003E3BA4 2D202002 */   daddu     $4, $17, $0
    /* 2E3BA8 003E3BA8 0E004014 */  bnez       $2, .L003E3BE4
    /* 2E3BAC 003E3BAC 00000000 */   nop
    /* 2E3BB0 003E3BB0 3400108E */  lw         $16, 0x34($16)
    /* 2E3BB4 003E3BB4 10000012 */  beqz       $16, .L003E3BF8
    /* 2E3BB8 003E3BB8 00000000 */   nop
  .L003E3BBC:
    /* 2E3BBC 003E3BBC 0000058E */  lw         $5, 0x0($16)
    /* 2E3BC0 003E3BC0 0400068E */  lw         $6, 0x4($16)
    /* 2E3BC4 003E3BC4 2400028E */  lw         $2, 0x24($16)
    /* 2E3BC8 003E3BC8 09F84000 */  jalr       $2
    /* 2E3BCC 003E3BCC 2D202002 */   daddu     $4, $17, $0
    /* 2E3BD0 003E3BD0 3400108E */  lw         $16, 0x34($16)
    /* 2E3BD4 003E3BD4 F9FF0016 */  bnez       $16, .L003E3BBC
    /* 2E3BD8 003E3BD8 00000000 */   nop
    /* 2E3BDC 003E3BDC 07000010 */  b          .L003E3BFC
    /* 2E3BE0 003E3BE0 2D100000 */   daddu     $2, $0, $0
  .L003E3BE4:
    /* 2E3BE4 003E3BE4 3000108E */  lw         $16, 0x30($16)
    /* 2E3BE8 003E3BE8 EAFF0016 */  bnez       $16, .L003E3B94
    /* 2E3BEC 003E3BEC 00000000 */   nop
  .L003E3BF0:
    /* 2E3BF0 003E3BF0 02000010 */  b          .L003E3BFC
    /* 2E3BF4 003E3BF4 2D104002 */   daddu     $2, $18, $0
  .L003E3BF8:
    /* 2E3BF8 003E3BF8 2D100000 */  daddu      $2, $0, $0
  .L003E3BFC:
    /* 2E3BFC 003E3BFC 3000BFDF */  ld         $31, 0x30($29)
    /* 2E3C00 003E3C00 2000B27B */  lq         $18, 0x20($29)
    /* 2E3C04 003E3C04 1000B17B */  lq         $17, 0x10($29)
    /* 2E3C08 003E3C08 0000B07B */  lq         $16, 0x0($29)
    /* 2E3C0C 003E3C0C 0800E003 */  jr         $31
    /* 2E3C10 003E3C10 4000BD27 */   addiu     $29, $29, 0x40
    /* 2E3C14 003E3C14 00000000 */  nop
    /* 2E3C18 003E3C18 00000000 */  nop
    /* 2E3C1C 003E3C1C 00000000 */  nop
.size func_003e3b70, 0xb0
