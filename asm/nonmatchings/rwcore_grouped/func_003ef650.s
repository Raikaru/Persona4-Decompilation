.section .text
.set noat
.set noreorder
glabel func_003ef650
    /* 2EF650 003EF650 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2EF654 003EF654 08008824 */  addiu      $8, $4, 0x8
    /* 2EF658 003EF658 0000BFFF */  sd         $31, 0x0($29)
    /* 2EF65C 003EF65C 0800898C */  lw         $9, 0x8($4)
    /* 2EF660 003EF660 09002811 */  beq        $9, $8, .L003EF688
    /* 2EF664 003EF664 2D58A000 */   daddu     $11, $5, $0
  .L003EF668:
    /* 2EF668 003EF668 F8FF2A25 */  addiu      $10, $9, -0x8
    /* 2EF66C 003EF66C 10004425 */  addiu      $4, $10, 0x10
    /* 2EF670 003EF670 07008014 */  bnez       $4, .L003EF690
    /* 2EF674 003EF674 00000000 */   nop
  .L003EF678:
    /* 2EF678 003EF678 0000298D */  lw         $9, 0x0($9)
    /* 2EF67C 003EF67C 00000000 */  nop
    /* 2EF680 003EF680 F9FF2815 */  bne        $9, $8, .L003EF668
    /* 2EF684 003EF684 00000000 */   nop
  .L003EF688:
    /* 2EF688 003EF688 06000010 */  b          .L003EF6A4
    /* 2EF68C 003EF68C 2D100000 */   daddu     $2, $0, $0
  .L003EF690:
    /* 2EF690 003EF690 9CBB0F0C */  jal        func_003eee70
    /* 2EF694 003EF694 2D286001 */   daddu     $5, $11, $0
    /* 2EF698 003EF698 F7FF4010 */  beqz       $2, .L003EF678
    /* 2EF69C 003EF69C 00000000 */   nop
    /* 2EF6A0 003EF6A0 2D104001 */  daddu      $2, $10, $0
  .L003EF6A4:
    /* 2EF6A4 003EF6A4 0000BFDF */  ld         $31, 0x0($29)
    /* 2EF6A8 003EF6A8 0800E003 */  jr         $31
    /* 2EF6AC 003EF6AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_003ef650, 0x60
