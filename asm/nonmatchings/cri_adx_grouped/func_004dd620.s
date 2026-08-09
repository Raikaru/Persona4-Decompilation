.section .text
.set noat
.set noreorder
glabel func_004dd620
    /* 3DD620 004DD620 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DD624 004DD624 7300023C */  lui        $2, %hi(D_00729990)
    /* 3DD628 004DD628 0000B0FF */  sd         $16, 0x0($29)
    /* 3DD62C 004DD62C 90995024 */  addiu      $16, $2, %lo(D_00729990)
    /* 3DD630 004DD630 0000028E */  lw         $2, 0x0($16)
    /* 3DD634 004DD634 09004014 */  bnez       $2, .L004DD65C
    /* 3DD638 004DD638 0800BFFF */   sd        $31, 0x8($29)
    /* 3DD63C 004DD63C 7300043C */  lui        $4, %hi(D_00729998)
    /* 3DD640 004DD640 2D280000 */  daddu      $5, $0, $0
    /* 3DD644 004DD644 98998424 */  addiu      $4, $4, %lo(D_00729998)
    /* 3DD648 004DD648 72FE100C */  jal        func_0043f9c8
    /* 3DD64C 004DD64C 40000624 */   addiu     $6, $0, 0x40
    /* 3DD650 004DD650 9E75130C */  jal        func_004dd678
    /* 3DD654 004DD654 00000000 */   nop
    /* 3DD658 004DD658 0000028E */  lw         $2, 0x0($16)
  .L004DD65C:
    /* 3DD65C 004DD65C 01004224 */  addiu      $2, $2, 0x1
    /* 3DD660 004DD660 0800BFDF */  ld         $31, 0x8($29)
    /* 3DD664 004DD664 000002AE */  sw         $2, 0x0($16)
    /* 3DD668 004DD668 0000B0DF */  ld         $16, 0x0($29)
    /* 3DD66C 004DD66C 0800E003 */  jr         $31
    /* 3DD670 004DD670 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DD674 004DD674 00000000 */  nop
.size func_004dd620, 0x58
