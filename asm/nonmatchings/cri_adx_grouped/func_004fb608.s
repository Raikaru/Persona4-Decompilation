.section .text
.set noat
.set noreorder
glabel func_004fb608
    /* 3FB608 004FB608 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3FB60C 004FB60C 2D108000 */  daddu      $2, $4, $0
    /* 3FB610 004FB610 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB614 004FB614 2D80A000 */  daddu      $16, $5, $0
    /* 3FB618 004FB618 0800BFFF */  sd         $31, 0x8($29)
    /* 3FB61C 004FB61C 06004014 */  bnez       $2, .L004FB638
    /* 3FB620 004FB620 04004424 */   addiu     $4, $2, 0x4
    /* 3FB624 004FB624 7400043C */  lui        $4, %hi(D_00743CD0)
    /* 3FB628 004FB628 96ED130C */  jal        func_004fb658
    /* 3FB62C 004FB62C D03C8424 */   addiu     $4, $4, %lo(D_00743CD0)
    /* 3FB630 004FB630 04000010 */  b          .L004FB644
    /* 3FB634 004FB634 2D100002 */   daddu     $2, $16, $0
  .L004FB638:
    /* 3FB638 004FB638 96ED130C */  jal        func_004fb658
    /* 3FB63C 004FB63C 00000000 */   nop
    /* 3FB640 004FB640 2D100002 */  daddu      $2, $16, $0
  .L004FB644:
    /* 3FB644 004FB644 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB648 004FB648 0800BFDF */  ld         $31, 0x8($29)
    /* 3FB64C 004FB64C 0800E003 */  jr         $31
    /* 3FB650 004FB650 1000BD27 */   addiu     $29, $29, 0x10
    /* 3FB654 004FB654 00000000 */  nop
.size func_004fb608, 0x50
