.section .text
.set noat
.set noreorder
glabel func_0036be00
    /* 26BE00 0036BE00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26BE04 0036BE04 1000BFFF */  sd         $31, 0x10($29)
    /* 26BE08 0036BE08 0000B07F */  sq         $16, 0x0($29)
    /* 26BE0C 0036BE0C ACB5828F */  lw         $2, -0x4A54($28)
    /* 26BE10 0036BE10 06004014 */  bnez       $2, .L0036BE2C
    /* 26BE14 0036BE14 00000000 */   nop
    /* 26BE18 0036BE18 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BE1C 0036BE1C E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BE20 0036BE20 75000524 */  addiu      $5, $0, 0x75
    /* 26BE24 0036BE24 CCB5110C */  jal        func_0046d730
    /* 26BE28 0036BE28 00000000 */   nop
  .L0036BE2C:
    /* 26BE2C 0036BE2C ACB5908F */  lw         $16, -0x4A54($28)
    /* 26BE30 0036BE30 1000028E */  lw         $2, 0x10($16)
    /* 26BE34 0036BE34 01004230 */  andi       $2, $2, 0x1
    /* 26BE38 0036BE38 06004014 */  bnez       $2, .L0036BE54
    /* 26BE3C 0036BE3C 00000000 */   nop
    /* 26BE40 0036BE40 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BE44 0036BE44 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BE48 0036BE48 55010524 */  addiu      $5, $0, 0x155
    /* 26BE4C 0036BE4C CCB5110C */  jal        func_0046d730
    /* 26BE50 0036BE50 00000000 */   nop
  .L0036BE54:
    /* 26BE54 0036BE54 0400028E */  lw         $2, 0x4($16)
    /* 26BE58 0036BE58 1000BFDF */  ld         $31, 0x10($29)
    /* 26BE5C 0036BE5C 0000B07B */  lq         $16, 0x0($29)
    /* 26BE60 0036BE60 2000BD27 */  addiu      $29, $29, 0x20
    /* 26BE64 0036BE64 0800E003 */  jr         $31
    /* 26BE68 0036BE68 00000000 */   nop
    /* 26BE6C 0036BE6C 00000000 */  nop
.size func_0036be00, 0x70
