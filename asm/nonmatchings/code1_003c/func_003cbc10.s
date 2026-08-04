.section .text
.set noat
.set noreorder
glabel func_003cbc10
    /* 2CBC10 003CBC10 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2CBC14 003CBC14 2000BFFF */  sd         $31, 0x20($29)
    /* 2CBC18 003CBC18 1000B17F */  sq         $17, 0x10($29)
    /* 2CBC1C 003CBC1C 0000B07F */  sq         $16, 0x0($29)
    /* 2CBC20 003CBC20 2D888000 */  daddu      $17, $4, $0
    /* 2CBC24 003CBC24 08B7828F */  lw         $2, -0x48F8($28)
    /* 2CBC28 003CBC28 0400A48C */  lw         $4, 0x4($5)
    /* 2CBC2C 003CBC2C 03008010 */  beqz       $4, .L003CBC3C
    /* 2CBC30 003CBC30 2180A200 */   addu      $16, $5, $2
    /* 2CBC34 003CBC34 A0A50F0C */  jal        func_003e9680
    /* 2CBC38 003CBC38 00000000 */   nop
  .L003CBC3C:
    /* 2CBC3C 003CBC3C 0C0011AE */  sw         $17, 0xC($16)
    /* 2CBC40 003CBC40 2D102002 */  daddu      $2, $17, $0
    /* 2CBC44 003CBC44 2000BFDF */  ld         $31, 0x20($29)
    /* 2CBC48 003CBC48 1000B17B */  lq         $17, 0x10($29)
    /* 2CBC4C 003CBC4C 0000B07B */  lq         $16, 0x0($29)
    /* 2CBC50 003CBC50 0800E003 */  jr         $31
    /* 2CBC54 003CBC54 3000BD27 */   addiu     $29, $29, 0x30
    /* 2CBC58 003CBC58 00000000 */  nop
    /* 2CBC5C 003CBC5C 00000000 */  nop
.size func_003cbc10, 0x50
