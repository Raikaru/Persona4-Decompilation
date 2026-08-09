.section .text
.set noat
.set noreorder
glabel func_0043a6b8
    /* 33A6B8 0043A6B8 8B00023C */  lui        $2, %hi(D_008AC788)
    /* 33A6BC 0043A6BC 2D180000 */  daddu      $3, $0, $0
    /* 33A6C0 0043A6C0 88C74424 */  addiu      $4, $2, %lo(D_008AC788)
    /* 33A6C4 0043A6C4 00000000 */  nop
  .L0043A6C8:
    /* 33A6C8 0043A6C8 0000828C */  lw         $2, 0x0($4)
    /* 33A6CC 0043A6CC 03004054 */  bnel       $2, $0, .L0043A6DC
    /* 33A6D0 0043A6D0 01006324 */   addiu     $3, $3, 0x1
    /* 33A6D4 0043A6D4 0800E003 */  jr         $31
    /* 33A6D8 0043A6D8 2D106000 */   daddu     $2, $3, $0
  .L0043A6DC:
    /* 33A6DC 0043A6DC 02006228 */  slti       $2, $3, 0x2
    /* 33A6E0 0043A6E0 F9FF4014 */  bnez       $2, .L0043A6C8
    /* 33A6E4 0043A6E4 24008424 */   addiu     $4, $4, 0x24
    /* 33A6E8 0043A6E8 0800E003 */  jr         $31
    /* 33A6EC 0043A6EC FFFF0224 */   addiu     $2, $0, -0x1
.size func_0043a6b8, 0x38
