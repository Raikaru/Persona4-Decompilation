.section .text
.set noat
.set noreorder
glabel func_003cbc90
    /* 2CBC90 003CBC90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2CBC94 003CBC94 2000BFFF */  sd         $31, 0x20($29)
    /* 2CBC98 003CBC98 1000B17F */  sq         $17, 0x10($29)
    /* 2CBC9C 003CBC9C 0000B07F */  sq         $16, 0x0($29)
    /* 2CBCA0 003CBCA0 2D888000 */  daddu      $17, $4, $0
    /* 2CBCA4 003CBCA4 0CB7828F */  lw         $2, -0x48F4($28)
    /* 2CBCA8 003CBCA8 0400A48C */  lw         $4, 0x4($5)
    /* 2CBCAC 003CBCAC 03008010 */  beqz       $4, .L003CBCBC
    /* 2CBCB0 003CBCB0 2180A200 */   addu      $16, $5, $2
    /* 2CBCB4 003CBCB4 A0A50F0C */  jal        func_003e9680
    /* 2CBCB8 003CBCB8 00000000 */   nop
  .L003CBCBC:
    /* 2CBCBC 003CBCBC 000011AE */  sw         $17, 0x0($16)
    /* 2CBCC0 003CBCC0 2D102002 */  daddu      $2, $17, $0
    /* 2CBCC4 003CBCC4 2000BFDF */  ld         $31, 0x20($29)
    /* 2CBCC8 003CBCC8 1000B17B */  lq         $17, 0x10($29)
    /* 2CBCCC 003CBCCC 0000B07B */  lq         $16, 0x0($29)
    /* 2CBCD0 003CBCD0 0800E003 */  jr         $31
    /* 2CBCD4 003CBCD4 3000BD27 */   addiu     $29, $29, 0x30
    /* 2CBCD8 003CBCD8 00000000 */  nop
    /* 2CBCDC 003CBCDC 00000000 */  nop
.size func_003cbc90, 0x50
