.section .text
.set noat
.set noreorder
glabel func_003bcbe0
    /* 2BCBE0 003BCBE0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2BCBE4 003BCBE4 4000BFFF */  sd         $31, 0x40($29)
    /* 2BCBE8 003BCBE8 3000B37F */  sq         $19, 0x30($29)
    /* 2BCBEC 003BCBEC 2000B27F */  sq         $18, 0x20($29)
    /* 2BCBF0 003BCBF0 2D988000 */  daddu      $19, $4, $0
    /* 2BCBF4 003BCBF4 1000B17F */  sq         $17, 0x10($29)
    /* 2BCBF8 003BCBF8 0000B07F */  sq         $16, 0x0($29)
    /* 2BCBFC 003BCBFC 21806502 */  addu       $16, $19, $5
    /* 2BCC00 003BCC00 0400028E */  lw         $2, 0x4($16)
    /* 2BCC04 003BCC04 12004010 */  beqz       $2, .L003BCC50
    /* 2BCC08 003BCC08 00000000 */   nop
    /* 2BCC0C 003BCC0C 0000028E */  lw         $2, 0x0($16)
    /* 2BCC10 003BCC10 2A080200 */  slt        $1, $0, $2
    /* 2BCC14 003BCC14 0A002010 */  beqz       $1, .L003BCC40
    /* 2BCC18 003BCC18 2D900000 */   daddu     $18, $0, $0
    /* 2BCC1C 003BCC1C 2D880000 */  daddu      $17, $0, $0
  .L003BCC20:
    /* 2BCC20 003BCC20 0400028E */  lw         $2, 0x4($16)
    /* 2BCC24 003BCC24 A8EF0E0C */  jal        func_003bbea0
    /* 2BCC28 003BCC28 21205100 */   addu      $4, $2, $17
    /* 2BCC2C 003BCC2C 0000028E */  lw         $2, 0x0($16)
    /* 2BCC30 003BCC30 01005226 */  addiu      $18, $18, 0x1
    /* 2BCC34 003BCC34 2A104202 */  slt        $2, $18, $2
    /* 2BCC38 003BCC38 F9FF4014 */  bnez       $2, .L003BCC20
    /* 2BCC3C 003BCC3C 10003126 */   addiu     $17, $17, 0x10
  .L003BCC40:
    /* 2BCC40 003BCC40 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BCC44 003BCC44 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BCC48 003BCC48 09F84000 */  jalr       $2
    /* 2BCC4C 003BCC4C 0400048E */   lw        $4, 0x4($16)
  .L003BCC50:
    /* 2BCC50 003BCC50 040000AE */  sw         $0, 0x4($16)
    /* 2BCC54 003BCC54 2D106002 */  daddu      $2, $19, $0
    /* 2BCC58 003BCC58 000000AE */  sw         $0, 0x0($16)
    /* 2BCC5C 003BCC5C 4000BFDF */  ld         $31, 0x40($29)
    /* 2BCC60 003BCC60 3000B37B */  lq         $19, 0x30($29)
    /* 2BCC64 003BCC64 2000B27B */  lq         $18, 0x20($29)
    /* 2BCC68 003BCC68 1000B17B */  lq         $17, 0x10($29)
    /* 2BCC6C 003BCC6C 0000B07B */  lq         $16, 0x0($29)
    /* 2BCC70 003BCC70 0800E003 */  jr         $31
    /* 2BCC74 003BCC74 5000BD27 */   addiu     $29, $29, 0x50
    /* 2BCC78 003BCC78 00000000 */  nop
    /* 2BCC7C 003BCC7C 00000000 */  nop
.size func_003bcbe0, 0xa0
