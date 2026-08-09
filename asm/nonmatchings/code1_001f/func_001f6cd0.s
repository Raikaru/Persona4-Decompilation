.section .text
.set noat
.set noreorder
glabel func_001f6cd0
    /* F6CD0 001F6CD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F6CD4 001F6CD4 1000BFFF */  sd         $31, 0x10($29)
    /* F6CD8 001F6CD8 0000B07F */  sq         $16, 0x0($29)
    /* F6CDC 001F6CDC 2D808000 */  daddu      $16, $4, $0
    /* F6CE0 001F6CE0 3000828C */  lw         $2, 0x30($4)
    /* F6CE4 001F6CE4 640A448C */  lw         $4, 0xA64($2)
    /* F6CE8 001F6CE8 B8C9080C */  jal        func_002326e0
    /* F6CEC 001F6CEC 00000000 */   nop
    /* F6CF0 001F6CF0 2D300000 */  daddu      $6, $0, $0
    /* F6CF4 001F6CF4 01000524 */  addiu      $5, $0, 0x1
    /* F6CF8 001F6CF8 0E000010 */  b          .L001F6D34
    /* F6CFC 001F6CFC 00000000 */   nop
  .L001F6D00:
    /* F6D00 001F6D00 0418C500 */  sllv       $3, $5, $6
    /* F6D04 001F6D04 24184300 */  and        $3, $2, $3
    /* F6D08 001F6D08 09006010 */  beqz       $3, .L001F6D30
    /* F6D0C 001F6D0C 00000000 */   nop
    /* F6D10 001F6D10 21180602 */  addu       $3, $16, $6
    /* F6D14 001F6D14 F6036424 */  addiu      $4, $3, 0x3F6
    /* F6D18 001F6D18 F6036390 */  lbu        $3, 0x3F6($3)
    /* F6D1C 001F6D1C FF006128 */  slti       $1, $3, 0xFF
    /* F6D20 001F6D20 03002010 */  beqz       $1, .L001F6D30
    /* F6D24 001F6D24 00000000 */   nop
    /* F6D28 001F6D28 01006324 */  addiu      $3, $3, 0x1
    /* F6D2C 001F6D2C 000083A0 */  sb         $3, 0x0($4)
  .L001F6D30:
    /* F6D30 001F6D30 0100C624 */  addiu      $6, $6, 0x1
  .L001F6D34:
    /* F6D34 001F6D34 1800C32C */  sltiu      $3, $6, 0x18
    /* F6D38 001F6D38 F1FF6014 */  bnez       $3, .L001F6D00
    /* F6D3C 001F6D3C 00000000 */   nop
    /* F6D40 001F6D40 1000BFDF */  ld         $31, 0x10($29)
    /* F6D44 001F6D44 0000B07B */  lq         $16, 0x0($29)
    /* F6D48 001F6D48 2000BD27 */  addiu      $29, $29, 0x20
    /* F6D4C 001F6D4C 0800E003 */  jr         $31
    /* F6D50 001F6D50 00000000 */   nop
    /* F6D54 001F6D54 00000000 */  nop
    /* F6D58 001F6D58 00000000 */  nop
    /* F6D5C 001F6D5C 00000000 */  nop
.size func_001f6cd0, 0x90
