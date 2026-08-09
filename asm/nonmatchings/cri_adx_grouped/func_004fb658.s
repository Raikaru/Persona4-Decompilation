.section .text
.set noat
.set noreorder
glabel func_004fb658
    /* 3FB658 004FB658 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB65C 004FB65C 2D10A000 */  daddu      $2, $5, $0
    /* 3FB660 004FB660 0000BFFF */  sd         $31, 0x0($29)
    /* 3FB664 004FB664 06004010 */  beqz       $2, .L004FB680
    /* 3FB668 004FB668 080082AC */   sw        $2, 0x8($4)
    /* 3FB66C 004FB66C 0000828C */  lw         $2, 0x0($4)
    /* 3FB670 004FB670 04004050 */  beql       $2, $0, .L004FB684
    /* 3FB674 004FB674 0000BFDF */   ld        $31, 0x0($29)
    /* 3FB678 004FB678 09F84000 */  jalr       $2
    /* 3FB67C 004FB67C 0400848C */   lw        $4, 0x4($4)
  .L004FB680:
    /* 3FB680 004FB680 0000BFDF */  ld         $31, 0x0($29)
  .L004FB684:
    /* 3FB684 004FB684 0800E003 */  jr         $31
    /* 3FB688 004FB688 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FB68C 004FB68C 00000000 */  nop
.size func_004fb658, 0x38
