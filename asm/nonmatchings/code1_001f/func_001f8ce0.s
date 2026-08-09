.section .text
.set noat
.set noreorder
glabel func_001f8ce0
    /* F8CE0 001F8CE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F8CE4 001F8CE4 1000BFFF */  sd         $31, 0x10($29)
    /* F8CE8 001F8CE8 0000B07F */  sq         $16, 0x0($29)
    /* F8CEC 001F8CEC 3000838C */  lw         $3, 0x30($4)
    /* F8CF0 001F8CF0 A2006290 */  lbu        $2, 0xA2($3)
    /* F8CF4 001F8CF4 04004010 */  beqz       $2, .L001F8D08
    /* F8CF8 001F8CF8 00000000 */   nop
    /* F8CFC 001F8CFC FFFF0224 */  addiu      $2, $0, -0x1
    /* F8D00 001F8D00 13000010 */  b          .L001F8D50
    /* F8D04 001F8D04 00000000 */   nop
  .L001F8D08:
    /* F8D08 001F8D08 ACB3828F */  lw         $2, -0x4C54($28)
    /* F8D0C 001F8D0C 7001428C */  lw         $2, 0x170($2)
    /* F8D10 001F8D10 04004414 */  bne        $2, $4, .L001F8D24
    /* F8D14 001F8D14 00000000 */   nop
    /* F8D18 001F8D18 FFFF0224 */  addiu      $2, $0, -0x1
    /* F8D1C 001F8D1C 0C000010 */  b          .L001F8D50
    /* F8D20 001F8D20 00000000 */   nop
  .L001F8D24:
    /* F8D24 001F8D24 A4006294 */  lhu        $2, 0xA4($3)
    /* F8D28 001F8D28 40180200 */  sll        $3, $2, 1
    /* F8D2C 001F8D2C 6200023C */  lui        $2, %hi(D_00624FC0)
    /* F8D30 001F8D30 C04F4224 */  addiu      $2, $2, %lo(D_00624FC0)
    /* F8D34 001F8D34 21104300 */  addu       $2, $2, $3
    /* F8D38 001F8D38 00004294 */  lhu        $2, 0x0($2)
    /* F8D3C 001F8D3C 75005024 */  addiu      $16, $2, 0x75
    /* F8D40 001F8D40 03000424 */  addiu      $4, $0, 0x3
    /* F8D44 001F8D44 5CC7080C */  jal        func_00231d70
    /* F8D48 001F8D48 00000000 */   nop
    /* F8D4C 001F8D4C 21100202 */  addu       $2, $16, $2
  .L001F8D50:
    /* F8D50 001F8D50 1000BFDF */  ld         $31, 0x10($29)
    /* F8D54 001F8D54 0000B07B */  lq         $16, 0x0($29)
    /* F8D58 001F8D58 2000BD27 */  addiu      $29, $29, 0x20
    /* F8D5C 001F8D5C 0800E003 */  jr         $31
    /* F8D60 001F8D60 00000000 */   nop
    /* F8D64 001F8D64 00000000 */  nop
    /* F8D68 001F8D68 00000000 */  nop
    /* F8D6C 001F8D6C 00000000 */  nop
.size func_001f8ce0, 0x90
