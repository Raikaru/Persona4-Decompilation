.section .text
.set noat
.set noreorder
glabel func_003d48d0
    /* 2D48D0 003D48D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D48D4 003D48D4 1000BFFF */  sd         $31, 0x10($29)
    /* 2D48D8 003D48D8 0000B07F */  sq         $16, 0x0($29)
    /* 2D48DC 003D48DC 2D808000 */  daddu      $16, $4, $0
    /* 2D48E0 003D48E0 21100502 */  addu       $2, $16, $5
    /* 2D48E4 003D48E4 0000448C */  lw         $4, 0x0($2)
    /* 2D48E8 003D48E8 03008010 */  beqz       $4, .L003D48F8
    /* 2D48EC 003D48EC 00000000 */   nop
    /* 2D48F0 003D48F0 E8370F0C */  jal        func_003cdfa0
    /* 2D48F4 003D48F4 00000000 */   nop
  .L003D48F8:
    /* 2D48F8 003D48F8 2D100002 */  daddu      $2, $16, $0
    /* 2D48FC 003D48FC 1000BFDF */  ld         $31, 0x10($29)
    /* 2D4900 003D4900 0000B07B */  lq         $16, 0x0($29)
    /* 2D4904 003D4904 0800E003 */  jr         $31
    /* 2D4908 003D4908 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D490C 003D490C 00000000 */  nop
.size func_003d48d0, 0x40
