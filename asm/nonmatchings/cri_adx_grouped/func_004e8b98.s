.section .text
.set noat
.set noreorder
glabel func_004e8b98
    /* 3E8B98 004E8B98 2D18A000 */  daddu      $3, $5, $0
    /* 3E8B9C 004E8B9C 2D288000 */  daddu      $5, $4, $0
    /* 3E8BA0 004E8BA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E8BA4 004E8BA4 7300023C */  lui        $2, %hi(D_00734370)
    /* 3E8BA8 004E8BA8 0000BFFF */  sd         $31, 0x0($29)
    /* 3E8BAC 004E8BAC 70434724 */  addiu      $7, $2, %lo(D_00734370)
    /* 3E8BB0 004E8BB0 000060AC */  sw         $0, 0x0($3)
    /* 3E8BB4 004E8BB4 2D206000 */  daddu      $4, $3, $0
    /* 3E8BB8 004E8BB8 040060AC */  sw         $0, 0x4($3)
    /* 3E8BBC 004E8BBC 0000E28C */  lw         $2, 0x0($7)
    /* 3E8BC0 004E8BC0 05004010 */  beqz       $2, .L004E8BD8
    /* 3E8BC4 004E8BC4 2D304000 */   daddu     $6, $2, $0
    /* 3E8BC8 004E8BC8 0400E78C */  lw         $7, 0x4($7)
    /* 3E8BCC 004E8BCC 0000BFDF */  ld         $31, 0x0($29)
    /* 3E8BD0 004E8BD0 AAA21308 */  j          func_004e8aa8
    /* 3E8BD4 004E8BD4 1000BD27 */   addiu     $29, $29, 0x10
  .L004E8BD8:
    /* 3E8BD8 004E8BD8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E8BDC 004E8BDC 0800E003 */  jr         $31
    /* 3E8BE0 004E8BE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E8BE4 004E8BE4 00000000 */  nop
.size func_004e8b98, 0x50
