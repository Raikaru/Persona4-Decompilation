.section .text
.set noat
.set noreorder
glabel func_002bbf80
    /* 1BBF80 002BBF80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BBF84 002BBF84 0000BFFF */  sd         $31, 0x0($29)
    /* 1BBF88 002BBF88 02000324 */  addiu      $3, $0, 0x2
    /* 1BBF8C 002BBF8C 1400A310 */  beq        $5, $3, .L002BBFE0
    /* 1BBF90 002BBF90 00000000 */   nop
    /* 1BBF94 002BBF94 01000224 */  addiu      $2, $0, 0x1
    /* 1BBF98 002BBF98 0B00A210 */  beq        $5, $2, .L002BBFC8
    /* 1BBF9C 002BBF9C 00000000 */   nop
    /* 1BBFA0 002BBFA0 0300A010 */  beqz       $5, .L002BBFB0
    /* 1BBFA4 002BBFA4 00000000 */   nop
    /* 1BBFA8 002BBFA8 11000010 */  b          .L002BBFF0
    /* 1BBFAC 002BBFAC 00000000 */   nop
  .L002BBFB0:
    /* 1BBFB0 002BBFB0 0000848C */  lw         $4, 0x0($4)
    /* 1BBFB4 002BBFB4 2D280000 */  daddu      $5, $0, $0
    /* 1BBFB8 002BBFB8 84E1090C */  jal        func_00278610
    /* 1BBFBC 002BBFBC 00000000 */   nop
    /* 1BBFC0 002BBFC0 0B000010 */  b          .L002BBFF0
    /* 1BBFC4 002BBFC4 00000000 */   nop
  .L002BBFC8:
    /* 1BBFC8 002BBFC8 0000848C */  lw         $4, 0x0($4)
    /* 1BBFCC 002BBFCC 2D286000 */  daddu      $5, $3, $0
    /* 1BBFD0 002BBFD0 84E1090C */  jal        func_00278610
    /* 1BBFD4 002BBFD4 00000000 */   nop
    /* 1BBFD8 002BBFD8 05000010 */  b          .L002BBFF0
    /* 1BBFDC 002BBFDC 00000000 */   nop
  .L002BBFE0:
    /* 1BBFE0 002BBFE0 0000848C */  lw         $4, 0x0($4)
    /* 1BBFE4 002BBFE4 01000524 */  addiu      $5, $0, 0x1
    /* 1BBFE8 002BBFE8 84E1090C */  jal        func_00278610
    /* 1BBFEC 002BBFEC 00000000 */   nop
  .L002BBFF0:
    /* 1BBFF0 002BBFF0 2D100000 */  daddu      $2, $0, $0
    /* 1BBFF4 002BBFF4 0000BFDF */  ld         $31, 0x0($29)
    /* 1BBFF8 002BBFF8 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BBFFC 002BBFFC 0800E003 */  jr         $31
    /* 1BC000 002BC000 00000000 */   nop
    /* 1BC004 002BC004 00000000 */  nop
    /* 1BC008 002BC008 00000000 */  nop
    /* 1BC00C 002BC00C 00000000 */  nop
.size func_002bbf80, 0x90
