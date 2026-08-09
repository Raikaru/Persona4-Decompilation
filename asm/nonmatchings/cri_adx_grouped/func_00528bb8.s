.section .text
.set noat
.set noreorder
glabel func_00528bb8
    /* 428BB8 00528BB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 428BBC 00528BBC 2D188000 */  daddu      $3, $4, $0
    /* 428BC0 00528BC0 0000BFFF */  sd         $31, 0x0($29)
    /* 428BC4 00528BC4 2D38C000 */  daddu      $7, $6, $0
    /* 428BC8 00528BC8 4800628C */  lw         $2, 0x48($3)
    /* 428BCC 00528BCC FDFF4224 */  addiu      $2, $2, -0x3
    /* 428BD0 00528BD0 0200422C */  sltiu      $2, $2, 0x2
    /* 428BD4 00528BD4 04004014 */  bnez       $2, .L00528BE8
    /* 428BD8 00528BD8 2D30A000 */   daddu     $6, $5, $0
    /* 428BDC 00528BDC 0000A0AC */  sw         $0, 0x0($5)
    /* 428BE0 00528BE0 03000010 */  b          .L00528BF0
    /* 428BE4 00528BE4 2D100000 */   daddu     $2, $0, $0
  .L00528BE8:
    /* 428BE8 00528BE8 1C56140C */  jal        func_00515870
    /* 428BEC 00528BEC D820658C */   lw        $5, 0x20D8($3)
  .L00528BF0:
    /* 428BF0 00528BF0 0000BFDF */  ld         $31, 0x0($29)
    /* 428BF4 00528BF4 0800E003 */  jr         $31
    /* 428BF8 00528BF8 1000BD27 */   addiu     $29, $29, 0x10
    /* 428BFC 00528BFC 00000000 */  nop
.size func_00528bb8, 0x48
