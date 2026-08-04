.section .text
.set noat
.set noreorder
glabel func_0019bf10
    /* 9BF10 0019BF10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 9BF14 0019BF14 1000BFFF */  sd         $31, 0x10($29)
    /* 9BF18 0019BF18 0000B07F */  sq         $16, 0x0($29)
    /* 9BF1C 0019BF1C 2D808000 */  daddu      $16, $4, $0
    /* 9BF20 0019BF20 0000858C */  lw         $5, 0x0($4)
    /* 9BF24 0019BF24 A000A394 */  lhu        $3, 0xA0($5)
    /* 9BF28 0019BF28 01006324 */  addiu      $3, $3, 0x1
    /* 9BF2C 0019BF2C A000A3A4 */  sh         $3, 0xA0($5)
    /* 9BF30 0019BF30 08008394 */  lhu        $3, 0x8($4)
    /* 9BF34 0019BF34 10006330 */  andi       $3, $3, 0x10
    /* 9BF38 0019BF38 09006014 */  bnez       $3, .L0019BF60
    /* 9BF3C 0019BF3C 00000000 */   nop
    /* 9BF40 0019BF40 000AA48C */  lw         $4, 0xA00($5)
    /* 9BF44 0019BF44 D002838C */  lw         $3, 0x2D0($4)
    /* 9BF48 0019BF48 03006014 */  bnez       $3, .L0019BF58
    /* 9BF4C 0019BF4C 00000000 */   nop
    /* 9BF50 0019BF50 5CF4110C */  jal        func_0047d170
    /* 9BF54 0019BF54 00000000 */   nop
  .L0019BF58:
    /* 9BF58 0019BF58 01000324 */  addiu      $3, $0, 0x1
    /* 9BF5C 0019BF5C 0C0003AE */  sw         $3, 0xC($16)
  .L0019BF60:
    /* 9BF60 0019BF60 1000BFDF */  ld         $31, 0x10($29)
    /* 9BF64 0019BF64 0000B07B */  lq         $16, 0x0($29)
    /* 9BF68 0019BF68 2000BD27 */  addiu      $29, $29, 0x20
    /* 9BF6C 0019BF6C 0800E003 */  jr         $31
    /* 9BF70 0019BF70 00000000 */   nop
    /* 9BF74 0019BF74 00000000 */  nop
    /* 9BF78 0019BF78 00000000 */  nop
    /* 9BF7C 0019BF7C 00000000 */  nop
.size func_0019bf10, 0x70
