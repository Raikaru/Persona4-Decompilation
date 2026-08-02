.section .text
.set noat
.set noreorder
glabel func_0024ba60
    /* 14BA60 0024BA60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 14BA64 0024BA64 2000BFFF */  sd         $31, 0x20($29)
    /* 14BA68 0024BA68 1000B17F */  sq         $17, 0x10($29)
    /* 14BA6C 0024BA6C 0000B07F */  sq         $16, 0x0($29)
    /* 14BA70 0024BA70 2D888000 */  daddu      $17, $4, $0
    /* 14BA74 0024BA74 6300043C */  lui        $4, %hi(D_00635A78)
    /* 14BA78 0024BA78 785A8424 */  addiu      $4, $4, %lo(D_00635A78)
    /* 14BA7C 0024BA7C E048110C */  jal        func_00452380
    /* 14BA80 0024BA80 00000000 */   nop
    /* 14BA84 0024BA84 2D804000 */  daddu      $16, $2, $0
    /* 14BA88 0024BA88 04002006 */  bltz       $17, .L0024BA9C
    /* 14BA8C 0024BA8C 00000000 */   nop
    /* 14BA90 0024BA90 0500232A */  slti       $3, $17, 0x5
    /* 14BA94 0024BA94 06006014 */  bnez       $3, .L0024BAB0
    /* 14BA98 0024BA98 00000000 */   nop
  .L0024BA9C:
    /* 14BA9C 0024BA9C 6300043C */  lui        $4, %hi(D_006359F0)
    /* 14BAA0 0024BAA0 F0598424 */  addiu      $4, $4, %lo(D_006359F0)
    /* 14BAA4 0024BAA4 B2030524 */  addiu      $5, $0, 0x3B2
    /* 14BAA8 0024BAA8 CCB5110C */  jal        func_0046d730
    /* 14BAAC 0024BAAC 00000000 */   nop
  .L0024BAB0:
    /* 14BAB0 0024BAB0 0D000012 */  beqz       $16, .L0024BAE8
    /* 14BAB4 0024BAB4 00000000 */   nop
    /* 14BAB8 0024BAB8 2D200002 */  daddu      $4, $16, $0
    /* 14BABC 0024BABC 5849110C */  jal        func_00452560
    /* 14BAC0 0024BAC0 00000000 */   nop
    /* 14BAC4 0024BAC4 80181100 */  sll        $3, $17, 2
    /* 14BAC8 0024BAC8 21186200 */  addu       $3, $3, $2
    /* 14BACC 0024BACC 0C007024 */  addiu      $16, $3, 0xC
    /* 14BAD0 0024BAD0 0C00648C */  lw         $4, 0xC($3)
    /* 14BAD4 0024BAD4 04008010 */  beqz       $4, .L0024BAE8
    /* 14BAD8 0024BAD8 00000000 */   nop
    /* 14BADC 0024BADC 2048110C */  jal        func_00452080
    /* 14BAE0 0024BAE0 00000000 */   nop
    /* 14BAE4 0024BAE4 000000AE */  sw         $0, 0x0($16)
  .L0024BAE8:
    /* 14BAE8 0024BAE8 2000BFDF */  ld         $31, 0x20($29)
    /* 14BAEC 0024BAEC 1000B17B */  lq         $17, 0x10($29)
    /* 14BAF0 0024BAF0 0000B07B */  lq         $16, 0x0($29)
    /* 14BAF4 0024BAF4 3000BD27 */  addiu      $29, $29, 0x30
    /* 14BAF8 0024BAF8 0800E003 */  jr         $31
    /* 14BAFC 0024BAFC 00000000 */   nop
.size func_0024ba60, 0xa0
