.section .text
.set noat
.set noreorder
glabel func_003ef6f0
    /* 2EF6F0 003EF6F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2EF6F4 003EF6F4 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF6F8 003EF6F8 0000BFFF */  sd         $31, 0x0($29)
    /* 2EF6FC 003EF6FC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF700 003EF700 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF704 003EF704 21104300 */  addu       $2, $2, $3
    /* 2EF708 003EF708 3000428C */  lw         $2, 0x30($2)
    /* 2EF70C 003EF70C 05004010 */  beqz       $2, .L003EF724
    /* 2EF710 003EF710 00000000 */   nop
    /* 2EF714 003EF714 09F84000 */  jalr       $2
    /* 2EF718 003EF718 00000000 */   nop
    /* 2EF71C 003EF71C 03000010 */  b          .L003EF72C
    /* 2EF720 003EF720 0000BFDF */   ld        $31, 0x0($29)
  .L003EF724:
    /* 2EF724 003EF724 2D100000 */  daddu      $2, $0, $0
    /* 2EF728 003EF728 0000BFDF */  ld         $31, 0x0($29)
  .L003EF72C:
    /* 2EF72C 003EF72C 0800E003 */  jr         $31
    /* 2EF730 003EF730 1000BD27 */   addiu     $29, $29, 0x10
    /* 2EF734 003EF734 00000000 */  nop
    /* 2EF738 003EF738 00000000 */  nop
    /* 2EF73C 003EF73C 00000000 */  nop
.size func_003ef6f0, 0x50
