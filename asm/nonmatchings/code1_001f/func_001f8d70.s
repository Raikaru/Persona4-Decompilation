.section .text
.set noat
.set noreorder
glabel func_001f8d70
    /* F8D70 001F8D70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F8D74 001F8D74 1000BFFF */  sd         $31, 0x10($29)
    /* F8D78 001F8D78 0000B07F */  sq         $16, 0x0($29)
    /* F8D7C 001F8D7C 3000838C */  lw         $3, 0x30($4)
    /* F8D80 001F8D80 A2006290 */  lbu        $2, 0xA2($3)
    /* F8D84 001F8D84 04004010 */  beqz       $2, .L001F8D98
    /* F8D88 001F8D88 00000000 */   nop
    /* F8D8C 001F8D8C FFFF0224 */  addiu      $2, $0, -0x1
    /* F8D90 001F8D90 18000010 */  b          .L001F8DF4
    /* F8D94 001F8D94 00000000 */   nop
  .L001F8D98:
    /* F8D98 001F8D98 ACB3828F */  lw         $2, -0x4C54($28)
    /* F8D9C 001F8D9C 7001428C */  lw         $2, 0x170($2)
    /* F8DA0 001F8DA0 04004414 */  bne        $2, $4, .L001F8DB4
    /* F8DA4 001F8DA4 00000000 */   nop
    /* F8DA8 001F8DA8 FFFF0224 */  addiu      $2, $0, -0x1
    /* F8DAC 001F8DAC 11000010 */  b          .L001F8DF4
    /* F8DB0 001F8DB0 00000000 */   nop
  .L001F8DB4:
    /* F8DB4 001F8DB4 0400A010 */  beqz       $5, .L001F8DC8
    /* F8DB8 001F8DB8 00000000 */   nop
    /* F8DBC 001F8DBC FFFF0224 */  addiu      $2, $0, -0x1
    /* F8DC0 001F8DC0 0C000010 */  b          .L001F8DF4
    /* F8DC4 001F8DC4 00000000 */   nop
  .L001F8DC8:
    /* F8DC8 001F8DC8 A4006294 */  lhu        $2, 0xA4($3)
    /* F8DCC 001F8DCC 40180200 */  sll        $3, $2, 1
    /* F8DD0 001F8DD0 6200023C */  lui        $2, %hi(D_00624FC0)
    /* F8DD4 001F8DD4 C04F4224 */  addiu      $2, $2, %lo(D_00624FC0)
    /* F8DD8 001F8DD8 21104300 */  addu       $2, $2, $3
    /* F8DDC 001F8DDC 00004294 */  lhu        $2, 0x0($2)
    /* F8DE0 001F8DE0 2C005024 */  addiu      $16, $2, 0x2C
    /* F8DE4 001F8DE4 03000424 */  addiu      $4, $0, 0x3
    /* F8DE8 001F8DE8 5CC7080C */  jal        func_00231d70
    /* F8DEC 001F8DEC 00000000 */   nop
    /* F8DF0 001F8DF0 21100202 */  addu       $2, $16, $2
  .L001F8DF4:
    /* F8DF4 001F8DF4 1000BFDF */  ld         $31, 0x10($29)
    /* F8DF8 001F8DF8 0000B07B */  lq         $16, 0x0($29)
    /* F8DFC 001F8DFC 2000BD27 */  addiu      $29, $29, 0x20
    /* F8E00 001F8E00 0800E003 */  jr         $31
    /* F8E04 001F8E04 00000000 */   nop
    /* F8E08 001F8E08 00000000 */  nop
    /* F8E0C 001F8E0C 00000000 */  nop
.size func_001f8d70, 0xa0
