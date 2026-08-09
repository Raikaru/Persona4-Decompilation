.section .text
.set noat
.set noreorder
glabel func_004bd720
    /* 3BD720 004BD720 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD724 004BD724 04008010 */  beqz       $4, .L004BD738
    /* 3BD728 004BD728 0000BFFF */   sd        $31, 0x0($29)
    /* 3BD72C 004BD72C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD730 004BD730 7EF61208 */  j          func_004bd9f8
    /* 3BD734 004BD734 1000BD27 */   addiu     $29, $29, 0x10
  .L004BD738:
    /* 3BD738 004BD738 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD73C 004BD73C 0800E003 */  jr         $31
    /* 3BD740 004BD740 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD744 004BD744 00000000 */  nop
.size func_004bd720, 0x28
