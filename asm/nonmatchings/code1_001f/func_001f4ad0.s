.section .text
.set noat
.set noreorder
glabel func_001f4ad0
    /* F4AD0 001F4AD0 3000838C */  lw         $3, 0x30($4)
    /* F4AD4 001F4AD4 A2006290 */  lbu        $2, 0xA2($3)
    /* F4AD8 001F4AD8 04004010 */  beqz       $2, .L001F4AEC
    /* F4ADC 001F4ADC 00000000 */   nop
    /* F4AE0 001F4AE0 FFFF0224 */  addiu      $2, $0, -0x1
    /* F4AE4 001F4AE4 22000010 */  b          .L001F4B70
    /* F4AE8 001F4AE8 00000000 */   nop
  .L001F4AEC:
    /* F4AEC 001F4AEC A4006294 */  lhu        $2, 0xA4($3)
    /* F4AF0 001F4AF0 0900412C */  sltiu      $1, $2, 0x9
    /* F4AF4 001F4AF4 1D002010 */  beqz       $1, .L001F4B6C
    /* F4AF8 001F4AF8 00000000 */   nop
    /* F4AFC 001F4AFC 7400033C */  lui        $3, %hi(jtbl_00747410)
    /* F4B00 001F4B00 10746324 */  addiu      $3, $3, %lo(jtbl_00747410)
    /* F4B04 001F4B04 80100200 */  sll        $2, $2, 2
    /* F4B08 001F4B08 21104300 */  addu       $2, $2, $3
    /* F4B0C 001F4B0C 0000428C */  lw         $2, 0x0($2)
    /* F4B10 001F4B10 08004000 */  jr         $2
    /* F4B14 001F4B14 00000000 */   nop
    /* F4B18 001F4B18 58010224 */  addiu      $2, $0, 0x158
    /* F4B1C 001F4B1C 14000010 */  b          .L001F4B70
    /* F4B20 001F4B20 00000000 */   nop
    /* F4B24 001F4B24 59010224 */  addiu      $2, $0, 0x159
    /* F4B28 001F4B28 11000010 */  b          .L001F4B70
    /* F4B2C 001F4B2C 00000000 */   nop
    /* F4B30 001F4B30 5A010224 */  addiu      $2, $0, 0x15A
    /* F4B34 001F4B34 0E000010 */  b          .L001F4B70
    /* F4B38 001F4B38 00000000 */   nop
    /* F4B3C 001F4B3C 5B010224 */  addiu      $2, $0, 0x15B
    /* F4B40 001F4B40 0B000010 */  b          .L001F4B70
    /* F4B44 001F4B44 00000000 */   nop
    /* F4B48 001F4B48 5C010224 */  addiu      $2, $0, 0x15C
    /* F4B4C 001F4B4C 08000010 */  b          .L001F4B70
    /* F4B50 001F4B50 00000000 */   nop
    /* F4B54 001F4B54 5D010224 */  addiu      $2, $0, 0x15D
    /* F4B58 001F4B58 05000010 */  b          .L001F4B70
    /* F4B5C 001F4B5C 00000000 */   nop
    /* F4B60 001F4B60 5E010224 */  addiu      $2, $0, 0x15E
    /* F4B64 001F4B64 02000010 */  b          .L001F4B70
    /* F4B68 001F4B68 00000000 */   nop
  .L001F4B6C:
    /* F4B6C 001F4B6C FFFF0224 */  addiu      $2, $0, -0x1
  .L001F4B70:
    /* F4B70 001F4B70 0800E003 */  jr         $31
    /* F4B74 001F4B74 00000000 */   nop
    /* F4B78 001F4B78 00000000 */  nop
    /* F4B7C 001F4B7C 00000000 */  nop
.size func_001f4ad0, 0xb0
