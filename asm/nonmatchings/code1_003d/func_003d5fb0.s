.section .text
.set noat
.set noreorder
glabel func_003d5fb0
    /* 2D5FB0 003D5FB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D5FB4 003D5FB4 0400023C */  lui        $2, (0x40000 >> 16)
    /* 2D5FB8 003D5FB8 1000BFFF */  sd         $31, 0x10($29)
    /* 2D5FBC 003D5FBC 0000B07F */  sq         $16, 0x0($29)
    /* 2D5FC0 003D5FC0 0400838C */  lw         $3, 0x4($4)
    /* 2D5FC4 003D5FC4 2D808000 */  daddu      $16, $4, $0
    /* 2D5FC8 003D5FC8 25286200 */  or         $5, $3, $2
    /* 2D5FCC 003D5FCC 747D0F0C */  jal        func_003df5d0
    /* 2D5FD0 003D5FD0 04000424 */   addiu     $4, $0, 0x4
    /* 2D5FD4 003D5FD4 100002AE */  sw         $2, 0x10($16)
    /* 2D5FD8 003D5FD8 1000028E */  lw         $2, 0x10($16)
    /* 2D5FDC 003D5FDC 03004014 */  bnez       $2, .L003D5FEC
    /* 2D5FE0 003D5FE0 00000000 */   nop
    /* 2D5FE4 003D5FE4 03000010 */  b          .L003D5FF4
    /* 2D5FE8 003D5FE8 2D100000 */   daddu     $2, $0, $0
  .L003D5FEC:
    /* 2D5FEC 003D5FEC 140000AE */  sw         $0, 0x14($16)
    /* 2D5FF0 003D5FF0 2D100002 */  daddu      $2, $16, $0
  .L003D5FF4:
    /* 2D5FF4 003D5FF4 1000BFDF */  ld         $31, 0x10($29)
    /* 2D5FF8 003D5FF8 0000B07B */  lq         $16, 0x0($29)
    /* 2D5FFC 003D5FFC 0800E003 */  jr         $31
    /* 2D6000 003D6000 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D6004 003D6004 00000000 */  nop
    /* 2D6008 003D6008 00000000 */  nop
    /* 2D600C 003D600C 00000000 */  nop
.size func_003d5fb0, 0x60
