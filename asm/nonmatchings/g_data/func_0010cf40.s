.section .text
.set noat
.set noreorder
glabel func_0010cf40
    /* CF40 0010CF40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CF44 0010CF44 2000BFFF */  sd         $31, 0x20($29)
    /* CF48 0010CF48 1000B17F */  sq         $17, 0x10($29)
    /* CF4C 0010CF4C 0000B07F */  sq         $16, 0x0($29)
    /* CF50 0010CF50 2D888000 */  daddu      $17, $4, $0
    /* CF54 0010CF54 3C840500 */  dsll32     $16, $5, 16
    /* CF58 0010CF58 3F841000 */  dsra32     $16, $16, 16
    /* CF5C 0010CF5C 0800022A */  slti       $2, $16, 0x8
    /* CF60 0010CF60 06004014 */  bnez       $2, .L0010CF7C
    /* CF64 0010CF64 00000000 */   nop
    /* CF68 0010CF68 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CF6C 0010CF6C 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CF70 0010CF70 23070524 */  addiu      $5, $0, 0x723
    /* CF74 0010CF74 CCB5110C */  jal        func_0046d730
    /* CF78 0010CF78 00000000 */   nop
  .L0010CF7C:
    /* CF7C 0010CF7C 40101000 */  sll        $2, $16, 1
    /* CF80 0010CF80 21105100 */  addu       $2, $2, $17
    /* CF84 0010CF84 0C004294 */  lhu        $2, 0xC($2)
    /* CF88 0010CF88 2000BFDF */  ld         $31, 0x20($29)
    /* CF8C 0010CF8C 1000B17B */  lq         $17, 0x10($29)
    /* CF90 0010CF90 0000B07B */  lq         $16, 0x0($29)
    /* CF94 0010CF94 3000BD27 */  addiu      $29, $29, 0x30
    /* CF98 0010CF98 0800E003 */  jr         $31
    /* CF9C 0010CF9C 00000000 */   nop
.size func_0010cf40, 0x60
