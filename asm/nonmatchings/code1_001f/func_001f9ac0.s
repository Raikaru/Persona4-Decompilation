.section .text
.set noat
.set noreorder
glabel func_001f9ac0
    /* F9AC0 001F9AC0 0400828C */  lw         $2, 0x4($4)
    /* F9AC4 001F9AC4 1C004014 */  bnez       $2, .L001F9B38
    /* F9AC8 001F9AC8 00000000 */   nop
    /* F9ACC 001F9ACC 08008294 */  lhu        $2, 0x8($4)
    /* F9AD0 001F9AD0 04004014 */  bnez       $2, .L001F9AE4
    /* F9AD4 001F9AD4 00000000 */   nop
    /* F9AD8 001F9AD8 6C000224 */  addiu      $2, $0, 0x6C
    /* F9ADC 001F9ADC 02000010 */  b          .L001F9AE8
    /* F9AE0 001F9AE0 00000000 */   nop
  .L001F9AE4:
    /* F9AE4 001F9AE4 69000224 */  addiu      $2, $0, 0x69
  .L001F9AE8:
    /* F9AE8 001F9AE8 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* F9AEC 001F9AEC 69000224 */  addiu      $2, $0, 0x69
    /* F9AF0 001F9AF0 0B006210 */  beq        $3, $2, .L001F9B20
    /* F9AF4 001F9AF4 00000000 */   nop
    /* F9AF8 001F9AF8 6C000224 */  addiu      $2, $0, 0x6C
    /* F9AFC 001F9AFC 03006210 */  beq        $3, $2, .L001F9B0C
    /* F9B00 001F9B00 00000000 */   nop
    /* F9B04 001F9B04 09000010 */  b          .L001F9B2C
    /* F9B08 001F9B08 00000000 */   nop
  .L001F9B0C:
    /* F9B0C 001F9B0C 05000324 */  addiu      $3, $0, 0x5
    /* F9B10 001F9B10 ACB3828F */  lw         $2, -0x4C54($28)
    /* F9B14 001F9B14 3A0B43A4 */  sh         $3, 0xB3A($2)
    /* F9B18 001F9B18 04000010 */  b          .L001F9B2C
    /* F9B1C 001F9B1C 00000000 */   nop
  .L001F9B20:
    /* F9B20 001F9B20 04000324 */  addiu      $3, $0, 0x4
    /* F9B24 001F9B24 ACB3828F */  lw         $2, -0x4C54($28)
    /* F9B28 001F9B28 3A0B43A4 */  sh         $3, 0xB3A($2)
  .L001F9B2C:
    /* F9B2C 001F9B2C 000080AC */  sw         $0, 0x0($4)
    /* F9B30 001F9B30 01000224 */  addiu      $2, $0, 0x1
    /* F9B34 001F9B34 040082AC */  sw         $2, 0x4($4)
  .L001F9B38:
    /* F9B38 001F9B38 0000828C */  lw         $2, 0x0($4)
    /* F9B3C 001F9B3C 0A004010 */  beqz       $2, .L001F9B68
    /* F9B40 001F9B40 00000000 */   nop
    /* F9B44 001F9B44 ACB3828F */  lw         $2, -0x4C54($28)
    /* F9B48 001F9B48 380B4294 */  lhu        $2, 0xB38($2)
    /* F9B4C 001F9B4C 01004230 */  andi       $2, $2, 0x1
    /* F9B50 001F9B50 2B100200 */  sltu       $2, $0, $2
    /* F9B54 001F9B54 07004010 */  beqz       $2, .L001F9B74
    /* F9B58 001F9B58 00000000 */   nop
    /* F9B5C 001F9B5C 01000224 */  addiu      $2, $0, 0x1
    /* F9B60 001F9B60 05000010 */  b          .L001F9B78
    /* F9B64 001F9B64 00000000 */   nop
  .L001F9B68:
    /* F9B68 001F9B68 01000224 */  addiu      $2, $0, 0x1
    /* F9B6C 001F9B6C 02000010 */  b          .L001F9B78
    /* F9B70 001F9B70 00000000 */   nop
  .L001F9B74:
    /* F9B74 001F9B74 2D100000 */  daddu      $2, $0, $0
  .L001F9B78:
    /* F9B78 001F9B78 0800E003 */  jr         $31
    /* F9B7C 001F9B7C 00000000 */   nop
.size func_001f9ac0, 0xc0
