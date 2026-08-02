.section .text
.set noat
.set noreorder
glabel func_0010ceb0
    /* CEB0 0010CEB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CEB4 0010CEB4 2000BFFF */  sd         $31, 0x20($29)
    /* CEB8 0010CEB8 1000B17F */  sq         $17, 0x10($29)
    /* CEBC 0010CEBC 0000B07F */  sq         $16, 0x0($29)
    /* CEC0 0010CEC0 2D808000 */  daddu      $16, $4, $0
    /* CEC4 0010CEC4 2D880000 */  daddu      $17, $0, $0
    /* CEC8 0010CEC8 06000016 */  bnez       $16, .L0010CEE4
    /* CECC 0010CECC 00000000 */   nop
    /* CED0 0010CED0 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CED4 0010CED4 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CED8 0010CED8 17070524 */  addiu      $5, $0, 0x717
    /* CEDC 0010CEDC CCB5110C */  jal        func_0046d730
    /* CEE0 0010CEE0 00000000 */   nop
  .L0010CEE4:
    /* CEE4 0010CEE4 2D180000 */  daddu      $3, $0, $0
    /* CEE8 0010CEE8 08000010 */  b          .L0010CF0C
    /* CEEC 0010CEEC 00000000 */   nop
  .L0010CEF0:
    /* CEF0 0010CEF0 40100300 */  sll        $2, $3, 1
    /* CEF4 0010CEF4 21100202 */  addu       $2, $16, $2
    /* CEF8 0010CEF8 0C004294 */  lhu        $2, 0xC($2)
    /* CEFC 0010CEFC 02004010 */  beqz       $2, .L0010CF08
    /* CF00 0010CF00 00000000 */   nop
    /* CF04 0010CF04 01003126 */  addiu      $17, $17, 0x1
  .L0010CF08:
    /* CF08 0010CF08 01006324 */  addiu      $3, $3, 0x1
  .L0010CF0C:
    /* CF0C 0010CF0C 08006228 */  slti       $2, $3, 0x8
    /* CF10 0010CF10 F7FF4014 */  bnez       $2, .L0010CEF0
    /* CF14 0010CF14 00000000 */   nop
    /* CF18 0010CF18 2D102002 */  daddu      $2, $17, $0
    /* CF1C 0010CF1C 2000BFDF */  ld         $31, 0x20($29)
    /* CF20 0010CF20 1000B17B */  lq         $17, 0x10($29)
    /* CF24 0010CF24 0000B07B */  lq         $16, 0x0($29)
    /* CF28 0010CF28 3000BD27 */  addiu      $29, $29, 0x30
    /* CF2C 0010CF2C 0800E003 */  jr         $31
    /* CF30 0010CF30 00000000 */   nop
    /* CF34 0010CF34 00000000 */  nop
    /* CF38 0010CF38 00000000 */  nop
    /* CF3C 0010CF3C 00000000 */  nop
.size func_0010ceb0, 0x90
