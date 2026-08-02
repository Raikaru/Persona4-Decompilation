.section .text
.set noat
.set noreorder
glabel func_0029ce90
    /* 19CE90 0029CE90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 19CE94 0029CE94 1000BFFF */  sd         $31, 0x10($29)
    /* 19CE98 0029CE98 0000B07F */  sq         $16, 0x0($29)
    /* 19CE9C 0029CE9C 10B5828F */  lw         $2, -0x4AF0($28)
    /* 19CEA0 0029CEA0 1C00438C */  lw         $3, 0x1C($2)
    /* 19CEA4 0029CEA4 01008224 */  addiu      $2, $4, 0x1
    /* 19CEA8 0029CEA8 23806200 */  subu       $16, $3, $2
    /* 19CEAC 0029CEAC 2A086200 */  slt        $1, $3, $2
    /* 19CEB0 0029CEB0 06002010 */  beqz       $1, .L0029CECC
    /* 19CEB4 0029CEB4 00000000 */   nop
    /* 19CEB8 0029CEB8 6400043C */  lui        $4, %hi(D_0063E068)
    /* 19CEBC 0029CEBC 68E08424 */  addiu      $4, $4, %lo(D_0063E068)
    /* 19CEC0 0029CEC0 4F040524 */  addiu      $5, $0, 0x44F
    /* 19CEC4 0029CEC4 CCB5110C */  jal        func_0046d730
    /* 19CEC8 0029CEC8 00000000 */   nop
  .L0029CECC:
    /* 19CECC 0029CECC 10B5848F */  lw         $4, -0x4AF0($28)
    /* 19CED0 0029CED0 21100402 */  addu       $2, $16, $4
    /* 19CED4 0029CED4 20004280 */  lb         $2, 0x20($2)
    /* 19CED8 0029CED8 0600412C */  sltiu      $1, $2, 0x6
    /* 19CEDC 0029CEDC 0D002010 */  beqz       $1, .L0029CF14
    /* 19CEE0 0029CEE0 00000000 */   nop
    /* 19CEE4 0029CEE4 7500033C */  lui        $3, %hi(jtbl_007485B0)
    /* 19CEE8 0029CEE8 B0856324 */  addiu      $3, $3, %lo(jtbl_007485B0)
    /* 19CEEC 0029CEEC 80100200 */  sll        $2, $2, 2
    /* 19CEF0 0029CEF0 21104300 */  addu       $2, $2, $3
    /* 19CEF4 0029CEF4 0000428C */  lw         $2, 0x0($2)
    /* 19CEF8 0029CEF8 08004000 */  jr         $2
    /* 19CEFC 0029CEFC 00000000 */   nop
    /* 19CF00 0029CF00 80101000 */  sll        $2, $16, 2
    /* 19CF04 0029CF04 21104400 */  addu       $2, $2, $4
    /* 19CF08 0029CF08 5000428C */  lw         $2, 0x50($2)
    /* 19CF0C 0029CF0C 09000010 */  b          .L0029CF34
    /* 19CF10 0029CF10 00000000 */   nop
  .L0029CF14:
    /* 19CF14 0029CF14 6400043C */  lui        $4, %hi(D_0063E3A0)
    /* 19CF18 0029CF18 A0E38424 */  addiu      $4, $4, %lo(D_0063E3A0)
    /* 19CF1C 0029CF1C 6400053C */  lui        $5, %hi(D_0063E068)
    /* 19CF20 0029CF20 68E0A524 */  addiu      $5, $5, %lo(D_0063E068)
    /* 19CF24 0029CF24 5A040624 */  addiu      $6, $0, 0x45A
    /* 19CF28 0029CF28 D0B5110C */  jal        func_0046d740
    /* 19CF2C 0029CF2C 00000000 */   nop
    /* 19CF30 0029CF30 2D100000 */  daddu      $2, $0, $0
  .L0029CF34:
    /* 19CF34 0029CF34 1000BFDF */  ld         $31, 0x10($29)
    /* 19CF38 0029CF38 0000B07B */  lq         $16, 0x0($29)
    /* 19CF3C 0029CF3C 2000BD27 */  addiu      $29, $29, 0x20
    /* 19CF40 0029CF40 0800E003 */  jr         $31
    /* 19CF44 0029CF44 00000000 */   nop
    /* 19CF48 0029CF48 00000000 */  nop
    /* 19CF4C 0029CF4C 00000000 */  nop
.size func_0029ce90, 0xc0
