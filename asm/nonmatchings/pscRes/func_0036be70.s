.section .text
.set noat
.set noreorder
glabel func_0036be70
    /* 26BE70 0036BE70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26BE74 0036BE74 1000BFFF */  sd         $31, 0x10($29)
    /* 26BE78 0036BE78 0000B07F */  sq         $16, 0x0($29)
    /* 26BE7C 0036BE7C ACB5828F */  lw         $2, -0x4A54($28)
    /* 26BE80 0036BE80 06004014 */  bnez       $2, .L0036BE9C
    /* 26BE84 0036BE84 00000000 */   nop
    /* 26BE88 0036BE88 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BE8C 0036BE8C E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BE90 0036BE90 75000524 */  addiu      $5, $0, 0x75
    /* 26BE94 0036BE94 CCB5110C */  jal        func_0046d730
    /* 26BE98 0036BE98 00000000 */   nop
  .L0036BE9C:
    /* 26BE9C 0036BE9C ACB5908F */  lw         $16, -0x4A54($28)
    /* 26BEA0 0036BEA0 1000028E */  lw         $2, 0x10($16)
    /* 26BEA4 0036BEA4 02004230 */  andi       $2, $2, 0x2
    /* 26BEA8 0036BEA8 06004014 */  bnez       $2, .L0036BEC4
    /* 26BEAC 0036BEAC 00000000 */   nop
    /* 26BEB0 0036BEB0 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BEB4 0036BEB4 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BEB8 0036BEB8 5F010524 */  addiu      $5, $0, 0x15F
    /* 26BEBC 0036BEBC CCB5110C */  jal        func_0046d730
    /* 26BEC0 0036BEC0 00000000 */   nop
  .L0036BEC4:
    /* 26BEC4 0036BEC4 0800028E */  lw         $2, 0x8($16)
    /* 26BEC8 0036BEC8 1000BFDF */  ld         $31, 0x10($29)
    /* 26BECC 0036BECC 0000B07B */  lq         $16, 0x0($29)
    /* 26BED0 0036BED0 2000BD27 */  addiu      $29, $29, 0x20
    /* 26BED4 0036BED4 0800E003 */  jr         $31
    /* 26BED8 0036BED8 00000000 */   nop
    /* 26BEDC 0036BEDC 00000000 */  nop
.size func_0036be70, 0x70
