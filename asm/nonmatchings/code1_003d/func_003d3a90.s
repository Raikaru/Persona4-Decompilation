.section .text
.set noat
.set noreorder
glabel func_003d3a90
    /* 2D3A90 003D3A90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2D3A94 003D3A94 1000BFFF */  sd         $31, 0x10($29)
    /* 2D3A98 003D3A98 0000B07F */  sq         $16, 0x0($29)
    /* 2D3A9C 003D3A9C 02008290 */  lbu        $2, 0x2($4)
    /* 2D3AA0 003D3AA0 02004230 */  andi       $2, $2, 0x2
    /* 2D3AA4 003D3AA4 03004014 */  bnez       $2, .L003D3AB4
    /* 2D3AA8 003D3AA8 2D808000 */   daddu     $16, $4, $0
  .L003D3AAC:
    /* 2D3AAC 003D3AAC 08000010 */  b          .L003D3AD0
    /* 2D3AB0 003D3AB0 2D100002 */   daddu     $2, $16, $0
  .L003D3AB4:
    /* 2D3AB4 003D3AB4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2D3AB8 003D3AB8 2D280000 */  daddu      $5, $0, $0
    /* 2D3ABC 003D3ABC 00608244 */  mtc1       $2, $f12
    /* 2D3AC0 003D3AC0 A03E0F0C */  jal        func_003cfa80
    /* 2D3AC4 003D3AC4 46630046 */   mov.s     $f13, $f12
    /* 2D3AC8 003D3AC8 F8FF0010 */  b          .L003D3AAC
    /* 2D3ACC 003D3ACC 00000000 */   nop
  .L003D3AD0:
    /* 2D3AD0 003D3AD0 1000BFDF */  ld         $31, 0x10($29)
    /* 2D3AD4 003D3AD4 0000B07B */  lq         $16, 0x0($29)
    /* 2D3AD8 003D3AD8 0800E003 */  jr         $31
    /* 2D3ADC 003D3ADC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003d3a90, 0x50
