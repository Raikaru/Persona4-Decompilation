.section .text
.set noat
.set noreorder
glabel func_001f4ce0
    /* F4CE0 001F4CE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* F4CE4 001F4CE4 1000BFFF */  sd         $31, 0x10($29)
    /* F4CE8 001F4CE8 0000B07F */  sq         $16, 0x0($29)
    /* F4CEC 001F4CEC 2D808000 */  daddu      $16, $4, $0
    /* F4CF0 001F4CF0 3000848C */  lw         $4, 0x30($4)
    /* F4CF4 001F4CF4 A2008290 */  lbu        $2, 0xA2($4)
    /* F4CF8 001F4CF8 04004010 */  beqz       $2, .L001F4D0C
    /* F4CFC 001F4CFC 00000000 */   nop
    /* F4D00 001F4D00 FFFF0224 */  addiu      $2, $0, -0x1
    /* F4D04 001F4D04 4B000010 */  b          .L001F4E34
    /* F4D08 001F4D08 00000000 */   nop
  .L001F4D0C:
    /* F4D0C 001F4D0C ACB3828F */  lw         $2, -0x4C54($28)
    /* F4D10 001F4D10 1000438C */  lw         $3, 0x10($2)
    /* F4D14 001F4D14 0020023C */  lui        $2, (0x20000000 >> 16)
    /* F4D18 001F4D18 24106200 */  and        $2, $3, $2
    /* F4D1C 001F4D1C 27004010 */  beqz       $2, .L001F4DBC
    /* F4D20 001F4D20 00000000 */   nop
    /* F4D24 001F4D24 68BE070C */  jal        func_001ef9a0
    /* F4D28 001F4D28 00000000 */   nop
    /* F4D2C 001F4D2C 0B020324 */  addiu      $3, $0, 0x20B
    /* F4D30 001F4D30 1F004314 */  bne        $2, $3, .L001F4DB0
    /* F4D34 001F4D34 00000000 */   nop
    /* F4D38 001F4D38 3000028E */  lw         $2, 0x30($16)
    /* F4D3C 001F4D3C A4004294 */  lhu        $2, 0xA4($2)
    /* F4D40 001F4D40 0900412C */  sltiu      $1, $2, 0x9
    /* F4D44 001F4D44 1A002010 */  beqz       $1, .L001F4DB0
    /* F4D48 001F4D48 00000000 */   nop
    /* F4D4C 001F4D4C 7400033C */  lui        $3, %hi(jtbl_007474D0)
    /* F4D50 001F4D50 D0746324 */  addiu      $3, $3, %lo(jtbl_007474D0)
    /* F4D54 001F4D54 80100200 */  sll        $2, $2, 2
    /* F4D58 001F4D58 21104300 */  addu       $2, $2, $3
    /* F4D5C 001F4D5C 0000428C */  lw         $2, 0x0($2)
    /* F4D60 001F4D60 08004000 */  jr         $2
    /* F4D64 001F4D64 00000000 */   nop
    /* F4D68 001F4D68 8C010224 */  addiu      $2, $0, 0x18C
    /* F4D6C 001F4D6C 31000010 */  b          .L001F4E34
    /* F4D70 001F4D70 00000000 */   nop
    /* F4D74 001F4D74 8D010224 */  addiu      $2, $0, 0x18D
    /* F4D78 001F4D78 2E000010 */  b          .L001F4E34
    /* F4D7C 001F4D7C 00000000 */   nop
    /* F4D80 001F4D80 8E010224 */  addiu      $2, $0, 0x18E
    /* F4D84 001F4D84 2B000010 */  b          .L001F4E34
    /* F4D88 001F4D88 00000000 */   nop
    /* F4D8C 001F4D8C 8F010224 */  addiu      $2, $0, 0x18F
    /* F4D90 001F4D90 28000010 */  b          .L001F4E34
    /* F4D94 001F4D94 00000000 */   nop
    /* F4D98 001F4D98 90010224 */  addiu      $2, $0, 0x190
    /* F4D9C 001F4D9C 25000010 */  b          .L001F4E34
    /* F4DA0 001F4DA0 00000000 */   nop
    /* F4DA4 001F4DA4 8A010224 */  addiu      $2, $0, 0x18A
    /* F4DA8 001F4DA8 22000010 */  b          .L001F4E34
    /* F4DAC 001F4DAC 00000000 */   nop
  .L001F4DB0:
    /* F4DB0 001F4DB0 FFFF0224 */  addiu      $2, $0, -0x1
    /* F4DB4 001F4DB4 1F000010 */  b          .L001F4E34
    /* F4DB8 001F4DB8 00000000 */   nop
  .L001F4DBC:
    /* F4DBC 001F4DBC A4008294 */  lhu        $2, 0xA4($4)
    /* F4DC0 001F4DC0 0900412C */  sltiu      $1, $2, 0x9
    /* F4DC4 001F4DC4 1A002010 */  beqz       $1, .L001F4E30
    /* F4DC8 001F4DC8 00000000 */   nop
    /* F4DCC 001F4DCC 7400033C */  lui        $3, %hi(jtbl_007474A0)
    /* F4DD0 001F4DD0 A0746324 */  addiu      $3, $3, %lo(jtbl_007474A0)
    /* F4DD4 001F4DD4 80100200 */  sll        $2, $2, 2
    /* F4DD8 001F4DD8 21104300 */  addu       $2, $2, $3
    /* F4DDC 001F4DDC 0000428C */  lw         $2, 0x0($2)
    /* F4DE0 001F4DE0 08004000 */  jr         $2
    /* F4DE4 001F4DE4 00000000 */   nop
    /* F4DE8 001F4DE8 26000224 */  addiu      $2, $0, 0x26
    /* F4DEC 001F4DEC 11000010 */  b          .L001F4E34
    /* F4DF0 001F4DF0 00000000 */   nop
    /* F4DF4 001F4DF4 27000224 */  addiu      $2, $0, 0x27
    /* F4DF8 001F4DF8 0E000010 */  b          .L001F4E34
    /* F4DFC 001F4DFC 00000000 */   nop
    /* F4E00 001F4E00 28000224 */  addiu      $2, $0, 0x28
    /* F4E04 001F4E04 0B000010 */  b          .L001F4E34
    /* F4E08 001F4E08 00000000 */   nop
    /* F4E0C 001F4E0C 29000224 */  addiu      $2, $0, 0x29
    /* F4E10 001F4E10 08000010 */  b          .L001F4E34
    /* F4E14 001F4E14 00000000 */   nop
    /* F4E18 001F4E18 2A000224 */  addiu      $2, $0, 0x2A
    /* F4E1C 001F4E1C 05000010 */  b          .L001F4E34
    /* F4E20 001F4E20 00000000 */   nop
    /* F4E24 001F4E24 2B000224 */  addiu      $2, $0, 0x2B
    /* F4E28 001F4E28 02000010 */  b          .L001F4E34
    /* F4E2C 001F4E2C 00000000 */   nop
  .L001F4E30:
    /* F4E30 001F4E30 FFFF0224 */  addiu      $2, $0, -0x1
  .L001F4E34:
    /* F4E34 001F4E34 1000BFDF */  ld         $31, 0x10($29)
    /* F4E38 001F4E38 0000B07B */  lq         $16, 0x0($29)
    /* F4E3C 001F4E3C 2000BD27 */  addiu      $29, $29, 0x20
    /* F4E40 001F4E40 0800E003 */  jr         $31
    /* F4E44 001F4E44 00000000 */   nop
    /* F4E48 001F4E48 00000000 */  nop
    /* F4E4C 001F4E4C 00000000 */  nop
.size func_001f4ce0, 0x170
