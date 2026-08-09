.section .text
.set noat
.set noreorder
glabel func_004e1ba0
    /* 3E1BA0 004E1BA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3E1BA4 004E1BA4 9200023C */  lui        $2, %hi(D_00923444)
    /* 3E1BA8 004E1BA8 2000BFFF */  sd         $31, 0x20($29)
    /* 3E1BAC 004E1BAC 0000B0FF */  sd         $16, 0x0($29)
    /* 3E1BB0 004E1BB0 2D800000 */  daddu      $16, $0, $0
    /* 3E1BB4 004E1BB4 0800B1FF */  sd         $17, 0x8($29)
    /* 3E1BB8 004E1BB8 44345124 */  addiu      $17, $2, %lo(D_00923444)
    /* 3E1BBC 004E1BBC 1000B2FF */  sd         $18, 0x10($29)
    /* 3E1BC0 004E1BC0 2D90A000 */  daddu      $18, $5, $0
    /* 3E1BC4 004E1BC4 1800B3FF */  sd         $19, 0x18($29)
    /* 3E1BC8 004E1BC8 2D988000 */  daddu      $19, $4, $0
    /* 3E1BCC 004E1BCC 2D282002 */  daddu      $5, $17, $0
  .L004E1BD0:
    /* 3E1BD0 004E1BD0 10003126 */  addiu      $17, $17, 0x10
    /* 3E1BD4 004E1BD4 2D206002 */  daddu      $4, $19, $0
    /* 3E1BD8 004E1BD8 0C0B110C */  jal        func_00442c30
    /* 3E1BDC 004E1BDC 2D304002 */   daddu     $6, $18, $0
    /* 3E1BE0 004E1BE0 03004014 */  bnez       $2, .L004E1BF0
    /* 3E1BE4 004E1BE4 01001026 */   addiu     $16, $16, 0x1
    /* 3E1BE8 004E1BE8 05000010 */  b          .L004E1C00
    /* 3E1BEC 004E1BEC 01000224 */   addiu     $2, $0, 0x1
  .L004E1BF0:
    /* 3E1BF0 004E1BF0 2000022A */  slti       $2, $16, 0x20
    /* 3E1BF4 004E1BF4 F6FF4014 */  bnez       $2, .L004E1BD0
    /* 3E1BF8 004E1BF8 2D282002 */   daddu     $5, $17, $0
    /* 3E1BFC 004E1BFC 2D100000 */  daddu      $2, $0, $0
  .L004E1C00:
    /* 3E1C00 004E1C00 0000B0DF */  ld         $16, 0x0($29)
    /* 3E1C04 004E1C04 0800B1DF */  ld         $17, 0x8($29)
    /* 3E1C08 004E1C08 1000B2DF */  ld         $18, 0x10($29)
    /* 3E1C0C 004E1C0C 1800B3DF */  ld         $19, 0x18($29)
    /* 3E1C10 004E1C10 2000BFDF */  ld         $31, 0x20($29)
    /* 3E1C14 004E1C14 0800E003 */  jr         $31
    /* 3E1C18 004E1C18 3000BD27 */   addiu     $29, $29, 0x30
    /* 3E1C1C 004E1C1C 00000000 */  nop
.size func_004e1ba0, 0x80
