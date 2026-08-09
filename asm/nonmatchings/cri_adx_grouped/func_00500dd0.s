.section .text
.set noat
.set noreorder
glabel func_00500dd0
    /* 400DD0 00500DD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 400DD4 00500DD4 0000BFFF */  sd         $31, 0x0($29)
    /* 400DD8 00500DD8 8203140C */  jal        func_00500e08
    /* 400DDC 00500DDC 00000000 */   nop
    /* 400DE0 00500DE0 2D184000 */  daddu      $3, $2, $0
    /* 400DE4 00500DE4 04006010 */  beqz       $3, .L00500DF8
    /* 400DE8 00500DE8 2D206000 */   daddu     $4, $3, $0
    /* 400DEC 00500DEC 0000BFDF */  ld         $31, 0x0($29)
    /* 400DF0 00500DF0 96031408 */  j          func_00500e58
    /* 400DF4 00500DF4 1000BD27 */   addiu     $29, $29, 0x10
  .L00500DF8:
    /* 400DF8 00500DF8 0000BFDF */  ld         $31, 0x0($29)
    /* 400DFC 00500DFC 0800E003 */  jr         $31
    /* 400E00 00500E00 1000BD27 */   addiu     $29, $29, 0x10
    /* 400E04 00500E04 00000000 */  nop
.size func_00500dd0, 0x38
