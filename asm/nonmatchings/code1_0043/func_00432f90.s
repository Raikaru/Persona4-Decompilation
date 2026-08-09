.section .text
.set noat
.set noreorder
glabel func_00432f90
    /* 332F90 00432F90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 332F94 00432F94 1000BFFF */  sd         $31, 0x10($29)
    /* 332F98 00432F98 02C7100C */  jal        func_00431c08
    /* 332F9C 00432F9C 00000000 */   nop
    /* 332FA0 00432FA0 2D184000 */  daddu      $3, $2, $0
    /* 332FA4 00432FA4 06006014 */  bnez       $3, .L00432FC0
    /* 332FA8 00432FA8 0000A2AF */   sw        $2, 0x0($29)
    /* 332FAC 00432FAC 2D200000 */  daddu      $4, $0, $0
    /* 332FB0 00432FB0 2D280000 */  daddu      $5, $0, $0
    /* 332FB4 00432FB4 86CB100C */  jal        func_00432e18
    /* 332FB8 00432FB8 2D30A003 */   daddu     $6, $29, $0
    /* 332FBC 00432FBC 0000A28F */  lw         $2, 0x0($29)
  .L00432FC0:
    /* 332FC0 00432FC0 1000BFDF */  ld         $31, 0x10($29)
    /* 332FC4 00432FC4 0800E003 */  jr         $31
    /* 332FC8 00432FC8 2000BD27 */   addiu     $29, $29, 0x20
    /* 332FCC 00432FCC 00000000 */  nop
.size func_00432f90, 0x40
