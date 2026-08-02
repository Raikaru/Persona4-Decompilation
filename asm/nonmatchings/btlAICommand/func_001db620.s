.section .text
.set noat
.set noreorder
glabel func_001db620
    /* DB620 001DB620 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DB624 001DB624 0000BFFF */  sd         $31, 0x0($29)
    /* DB628 001DB628 3000828C */  lw         $2, 0x30($4)
    /* DB62C 001DB62C A2004290 */  lbu        $2, 0xA2($2)
    /* DB630 001DB630 04004014 */  bnez       $2, .L001DB644
    /* DB634 001DB634 00000000 */   nop
    /* DB638 001DB638 01000224 */  addiu      $2, $0, 0x1
    /* DB63C 001DB63C 02000010 */  b          .L001DB648
    /* DB640 001DB640 00000000 */   nop
  .L001DB644:
    /* DB644 001DB644 2D100000 */  daddu      $2, $0, $0
  .L001DB648:
    /* DB648 001DB648 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* DB64C 001DB64C 01000224 */  addiu      $2, $0, 0x1
    /* DB650 001DB650 04106200 */  sllv       $2, $2, $3
    /* DB654 001DB654 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DB658 001DB658 0800073C */  lui        $7, (0x80000 >> 16)
    /* DB65C 001DB65C 0A000824 */  addiu      $8, $0, 0xA
    /* DB660 001DB660 1E00093C */  lui        $9, %hi(func_001db580)
    /* DB664 001DB664 80B52925 */  addiu      $9, $9, %lo(func_001db580)
    /* DB668 001DB668 3465070C */  jal        func_001d94d0
    /* DB66C 001DB66C 00000000 */   nop
    /* DB670 001DB670 0000BFDF */  ld         $31, 0x0($29)
    /* DB674 001DB674 1000BD27 */  addiu      $29, $29, 0x10
    /* DB678 001DB678 0800E003 */  jr         $31
    /* DB67C 001DB67C 00000000 */   nop
.size func_001db620, 0x60
