.section .text
.set noat
.set noreorder
glabel func_004ef770
    /* 3EF770 004EF770 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EF774 004EF774 06008014 */  bnez       $4, .L004EF790
    /* 3EF778 004EF778 0000BFFF */   sd        $31, 0x0($29)
    /* 3EF77C 004EF77C 7600043C */  lui        $4, %hi(D_0075D048)
    /* 3EF780 004EF780 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EF784 004EF784 48D08424 */  addiu      $4, $4, %lo(D_0075D048)
    /* 3EF788 004EF788 08000010 */  b          .L004EF7AC
    /* 3EF78C 004EF78C F8CEA524 */   addiu     $5, $5, %lo(D_0075CEF8)
  .L004EF790:
    /* 3EF790 004EF790 04008280 */  lb         $2, 0x4($4)
    /* 3EF794 004EF794 0A004054 */  bnel       $2, $0, .L004EF7C0
    /* 3EF798 004EF798 80100500 */   sll       $2, $5, 2
    /* 3EF79C 004EF79C 7600043C */  lui        $4, %hi(D_0075D058)
    /* 3EF7A0 004EF7A0 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EF7A4 004EF7A4 58D08424 */  addiu      $4, $4, %lo(D_0075D058)
    /* 3EF7A8 004EF7A8 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
  .L004EF7AC:
    /* 3EF7AC 004EF7AC B6BA130C */  jal        func_004eead8
    /* 3EF7B0 004EF7B0 00000000 */   nop
    /* 3EF7B4 004EF7B4 0E000010 */  b          .L004EF7F0
    /* 3EF7B8 004EF7B8 2D100000 */   daddu     $2, $0, $0
    /* 3EF7BC 004EF7BC 00000000 */  nop
  .L004EF7C0:
    /* 3EF7C0 004EF7C0 21104400 */  addu       $2, $2, $4
    /* 3EF7C4 004EF7C4 1800428C */  lw         $2, 0x18($2)
    /* 3EF7C8 004EF7C8 08004010 */  beqz       $2, .L004EF7EC
    /* 3EF7CC 004EF7CC 2D180000 */   daddu     $3, $0, $0
  .L004EF7D0:
    /* 3EF7D0 004EF7D0 0000428C */  lw         $2, 0x0($2)
    /* 3EF7D4 004EF7D4 00000000 */  nop
    /* 3EF7D8 004EF7D8 00000000 */  nop
    /* 3EF7DC 004EF7DC 00000000 */  nop
    /* 3EF7E0 004EF7E0 00000000 */  nop
    /* 3EF7E4 004EF7E4 FAFF4014 */  bnez       $2, .L004EF7D0
    /* 3EF7E8 004EF7E8 01006324 */   addiu     $3, $3, 0x1
  .L004EF7EC:
    /* 3EF7EC 004EF7EC 2D106000 */  daddu      $2, $3, $0
  .L004EF7F0:
    /* 3EF7F0 004EF7F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF7F4 004EF7F4 0800E003 */  jr         $31
    /* 3EF7F8 004EF7F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EF7FC 004EF7FC 00000000 */  nop
.size func_004ef770, 0x90
