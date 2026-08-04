.section .text
.set noat
.set noreorder
glabel func_0043a8a8
    /* 33A8A8 0043A8A8 8B00023C */  lui        $2, %hi(D_008AC788)
    /* 33A8AC 0043A8AC 2D180000 */  daddu      $3, $0, $0
    /* 33A8B0 0043A8B0 88C74524 */  addiu      $5, $2, %lo(D_008AC788)
    /* 33A8B4 0043A8B4 00000000 */  nop
  .L0043A8B8:
    /* 33A8B8 0043A8B8 0000A28C */  lw         $2, 0x0($5)
    /* 33A8BC 0043A8BC 06004050 */  beql       $2, $0, .L0043A8D8
    /* 33A8C0 0043A8C0 01006324 */   addiu     $3, $3, 0x1
    /* 33A8C4 0043A8C4 0400A28C */  lw         $2, 0x4($5)
    /* 33A8C8 0043A8C8 03004454 */  bnel       $2, $4, .L0043A8D8
    /* 33A8CC 0043A8CC 01006324 */   addiu     $3, $3, 0x1
    /* 33A8D0 0043A8D0 0800E003 */  jr         $31
    /* 33A8D4 0043A8D4 2D106000 */   daddu     $2, $3, $0
  .L0043A8D8:
    /* 33A8D8 0043A8D8 02006228 */  slti       $2, $3, 0x2
    /* 33A8DC 0043A8DC F6FF4014 */  bnez       $2, .L0043A8B8
    /* 33A8E0 0043A8E0 2400A524 */   addiu     $5, $5, 0x24
    /* 33A8E4 0043A8E4 0800E003 */  jr         $31
    /* 33A8E8 0043A8E8 FFFF0224 */   addiu     $2, $0, -0x1
    /* 33A8EC 0043A8EC 00000000 */  nop
.size func_0043a8a8, 0x48
