.section .text
.set noat
.set noreorder
glabel func_0018bed0
    /* 8BED0 0018BED0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 8BED4 0018BED4 2000BFFF */  sd         $31, 0x20($29)
    /* 8BED8 0018BED8 1000B17F */  sq         $17, 0x10($29)
    /* 8BEDC 0018BEDC 0000B07F */  sq         $16, 0x0($29)
    /* 8BEE0 0018BEE0 2D88A000 */  daddu      $17, $5, $0
    /* 8BEE4 0018BEE4 3800908C */  lw         $16, 0x38($4)
    /* 8BEE8 0018BEE8 A054050C */  jal        func_00155280
    /* 8BEEC 0018BEEC 00000000 */   nop
    /* 8BEF0 0018BEF0 5000038E */  lw         $3, 0x50($16)
    /* 8BEF4 0018BEF4 80180300 */  sll        $3, $3, 2
    /* 8BEF8 0018BEF8 21184300 */  addu       $3, $2, $3
    /* 8BEFC 0018BEFC 3400638C */  lw         $3, 0x34($3)
    /* 8BF00 0018BF00 0B006010 */  beqz       $3, .L0018BF30
    /* 8BF04 0018BF04 00000000 */   nop
    /* 8BF08 0018BF08 A054050C */  jal        func_00155280
    /* 8BF0C 0018BF0C 00000000 */   nop
    /* 8BF10 0018BF10 5000038E */  lw         $3, 0x50($16)
    /* 8BF14 0018BF14 80180300 */  sll        $3, $3, 2
    /* 8BF18 0018BF18 21104300 */  addu       $2, $2, $3
    /* 8BF1C 0018BF1C 3400448C */  lw         $4, 0x34($2)
    /* 8BF20 0018BF20 5400058E */  lw         $5, 0x54($16)
    /* 8BF24 0018BF24 2D302002 */  daddu      $6, $17, $0
    /* 8BF28 0018BF28 3C3A050C */  jal        func_0014e8f0
    /* 8BF2C 0018BF2C 00000000 */   nop
  .L0018BF30:
    /* 8BF30 0018BF30 2000BFDF */  ld         $31, 0x20($29)
    /* 8BF34 0018BF34 1000B17B */  lq         $17, 0x10($29)
    /* 8BF38 0018BF38 0000B07B */  lq         $16, 0x0($29)
    /* 8BF3C 0018BF3C 3000BD27 */  addiu      $29, $29, 0x30
    /* 8BF40 0018BF40 0800E003 */  jr         $31
    /* 8BF44 0018BF44 00000000 */   nop
    /* 8BF48 0018BF48 00000000 */  nop
    /* 8BF4C 0018BF4C 00000000 */  nop
.size func_0018bed0, 0x80
