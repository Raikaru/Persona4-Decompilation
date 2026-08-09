.section .text
.set noat
.set noreorder
glabel func_001f6c40
    /* F6C40 001F6C40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* F6C44 001F6C44 2000BFFF */  sd         $31, 0x20($29)
    /* F6C48 001F6C48 1000B17F */  sq         $17, 0x10($29)
    /* F6C4C 001F6C4C 0000B07F */  sq         $16, 0x0($29)
    /* F6C50 001F6C50 2D888000 */  daddu      $17, $4, $0
    /* F6C54 001F6C54 2D80A000 */  daddu      $16, $5, $0
    /* F6C58 001F6C58 16000012 */  beqz       $16, .L001F6CB4
    /* F6C5C 001F6C5C 00000000 */   nop
    /* F6C60 001F6C60 3000228E */  lw         $2, 0x30($17)
    /* F6C64 001F6C64 640A448C */  lw         $4, 0xA64($2)
    /* F6C68 001F6C68 B8C9080C */  jal        func_002326e0
    /* F6C6C 001F6C6C 00000000 */   nop
    /* F6C70 001F6C70 2D300000 */  daddu      $6, $0, $0
    /* F6C74 001F6C74 01000524 */  addiu      $5, $0, 0x1
    /* F6C78 001F6C78 0B000010 */  b          .L001F6CA8
    /* F6C7C 001F6C7C 00000000 */   nop
  .L001F6C80:
    /* F6C80 001F6C80 0420C500 */  sllv       $4, $5, $6
    /* F6C84 001F6C84 24180402 */  and        $3, $16, $4
    /* F6C88 001F6C88 06006010 */  beqz       $3, .L001F6CA4
    /* F6C8C 001F6C8C 00000000 */   nop
    /* F6C90 001F6C90 24184400 */  and        $3, $2, $4
    /* F6C94 001F6C94 03006014 */  bnez       $3, .L001F6CA4
    /* F6C98 001F6C98 00000000 */   nop
    /* F6C9C 001F6C9C 21182602 */  addu       $3, $17, $6
    /* F6CA0 001F6CA0 F60360A0 */  sb         $0, 0x3F6($3)
  .L001F6CA4:
    /* F6CA4 001F6CA4 0100C624 */  addiu      $6, $6, 0x1
  .L001F6CA8:
    /* F6CA8 001F6CA8 1800C32C */  sltiu      $3, $6, 0x18
    /* F6CAC 001F6CAC F4FF6014 */  bnez       $3, .L001F6C80
    /* F6CB0 001F6CB0 00000000 */   nop
  .L001F6CB4:
    /* F6CB4 001F6CB4 2000BFDF */  ld         $31, 0x20($29)
    /* F6CB8 001F6CB8 1000B17B */  lq         $17, 0x10($29)
    /* F6CBC 001F6CBC 0000B07B */  lq         $16, 0x0($29)
    /* F6CC0 001F6CC0 3000BD27 */  addiu      $29, $29, 0x30
    /* F6CC4 001F6CC4 0800E003 */  jr         $31
    /* F6CC8 001F6CC8 00000000 */   nop
    /* F6CCC 001F6CCC 00000000 */  nop
.size func_001f6c40, 0x90
