.section .text
.set noat
.set noreorder
glabel func_003d4f80
    /* 2D4F80 003D4F80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D4F84 003D4F84 1000BFFF */  sd         $31, 0x10($29)
    /* 2D4F88 003D4F88 0000B07F */  sq         $16, 0x0($29)
    /* 2D4F8C 003D4F8C 2D808000 */  daddu      $16, $4, $0
    /* 2D4F90 003D4F90 38B7848F */  lw         $4, -0x48C8($28)
    /* 2D4F94 003D4F94 04008010 */  beqz       $4, .L003D4FA8
    /* 2D4F98 003D4F98 34B780AF */   sw        $0, -0x48CC($28)
    /* 2D4F9C 003D4F9C BC840F0C */  jal        func_003e12f0
    /* 2D4FA0 003D4FA0 00000000 */   nop
    /* 2D4FA4 003D4FA4 38B780AF */  sw         $0, -0x48C8($28)
  .L003D4FA8:
    /* 2D4FA8 003D4FA8 2D100002 */  daddu      $2, $16, $0
    /* 2D4FAC 003D4FAC 1000BFDF */  ld         $31, 0x10($29)
    /* 2D4FB0 003D4FB0 0000B07B */  lq         $16, 0x0($29)
    /* 2D4FB4 003D4FB4 0800E003 */  jr         $31
    /* 2D4FB8 003D4FB8 2000BD27 */   addiu     $29, $29, 0x20
    /* 2D4FBC 003D4FBC 00000000 */  nop
.size func_003d4f80, 0x40
