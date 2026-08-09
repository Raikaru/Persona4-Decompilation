.section .text
.set noat
.set noreorder
glabel func_00432fd0
    /* 332FD0 00432FD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 332FD4 00432FD4 1000BFFF */  sd         $31, 0x10($29)
    /* 332FD8 00432FD8 CAC7100C */  jal        func_00431f28
    /* 332FDC 00432FDC 00000000 */   nop
    /* 332FE0 00432FE0 2D184000 */  daddu      $3, $2, $0
    /* 332FE4 00432FE4 06006014 */  bnez       $3, .L00433000
    /* 332FE8 00432FE8 0000A2AF */   sw        $2, 0x0($29)
    /* 332FEC 00432FEC 2D200000 */  daddu      $4, $0, $0
    /* 332FF0 00432FF0 2D280000 */  daddu      $5, $0, $0
    /* 332FF4 00432FF4 86CB100C */  jal        func_00432e18
    /* 332FF8 00432FF8 2D30A003 */   daddu     $6, $29, $0
    /* 332FFC 00432FFC 0000A28F */  lw         $2, 0x0($29)
  .L00433000:
    /* 333000 00433000 1000BFDF */  ld         $31, 0x10($29)
    /* 333004 00433004 0800E003 */  jr         $31
    /* 333008 00433008 2000BD27 */   addiu     $29, $29, 0x20
    /* 33300C 0043300C 00000000 */  nop
.size func_00432fd0, 0x40
