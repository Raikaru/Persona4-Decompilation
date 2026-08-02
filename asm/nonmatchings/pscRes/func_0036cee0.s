.section .text
.set noat
.set noreorder
glabel func_0036cee0
    /* 26CEE0 0036CEE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26CEE4 0036CEE4 1000BFFF */  sd         $31, 0x10($29)
    /* 26CEE8 0036CEE8 0000B07F */  sq         $16, 0x0($29)
    /* 26CEEC 0036CEEC ACB5828F */  lw         $2, -0x4A54($28)
    /* 26CEF0 0036CEF0 06004014 */  bnez       $2, .L0036CF0C
    /* 26CEF4 0036CEF4 00000000 */   nop
    /* 26CEF8 0036CEF8 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26CEFC 0036CEFC E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26CF00 0036CF00 75000524 */  addiu      $5, $0, 0x75
    /* 26CF04 0036CF04 CCB5110C */  jal        func_0046d730
    /* 26CF08 0036CF08 00000000 */   nop
  .L0036CF0C:
    /* 26CF0C 0036CF0C ACB5838F */  lw         $3, -0x4A54($28)
    /* 26CF10 0036CF10 2D800000 */  daddu      $16, $0, $0
    /* 26CF14 0036CF14 09000010 */  b          .L0036CF3C
    /* 26CF18 0036CF18 00000000 */   nop
  .L0036CF1C:
    /* 26CF1C 0036CF1C 00111000 */  sll        $2, $16, 4
    /* 26CF20 0036CF20 21106200 */  addu       $2, $3, $2
    /* 26CF24 0036CF24 9401428C */  lw         $2, 0x194($2)
    /* 26CF28 0036CF28 27104000 */  not        $2, $2
    /* 26CF2C 0036CF2C 01004230 */  andi       $2, $2, 0x1
    /* 26CF30 0036CF30 05004014 */  bnez       $2, .L0036CF48
    /* 26CF34 0036CF34 00000000 */   nop
    /* 26CF38 0036CF38 01001026 */  addiu      $16, $16, 0x1
  .L0036CF3C:
    /* 26CF3C 0036CF3C 1000022A */  slti       $2, $16, 0x10
    /* 26CF40 0036CF40 F6FF4014 */  bnez       $2, .L0036CF1C
    /* 26CF44 0036CF44 00000000 */   nop
  .L0036CF48:
    /* 26CF48 0036CF48 1000022A */  slti       $2, $16, 0x10
    /* 26CF4C 0036CF4C 06004014 */  bnez       $2, .L0036CF68
    /* 26CF50 0036CF50 00000000 */   nop
    /* 26CF54 0036CF54 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26CF58 0036CF58 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26CF5C 0036CF5C 2B030524 */  addiu      $5, $0, 0x32B
    /* 26CF60 0036CF60 CCB5110C */  jal        func_0046d730
    /* 26CF64 0036CF64 00000000 */   nop
  .L0036CF68:
    /* 26CF68 0036CF68 2D100002 */  daddu      $2, $16, $0
    /* 26CF6C 0036CF6C 1000BFDF */  ld         $31, 0x10($29)
    /* 26CF70 0036CF70 0000B07B */  lq         $16, 0x0($29)
    /* 26CF74 0036CF74 2000BD27 */  addiu      $29, $29, 0x20
    /* 26CF78 0036CF78 0800E003 */  jr         $31
    /* 26CF7C 0036CF7C 00000000 */   nop
.size func_0036cee0, 0xa0
