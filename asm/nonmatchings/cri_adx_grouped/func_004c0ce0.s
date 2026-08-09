.section .text
.set noat
.set noreorder
glabel func_004c0ce0
    /* 3C0CE0 004C0CE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C0CE4 004C0CE4 1000B2FF */  sd         $18, 0x10($29)
    /* 3C0CE8 004C0CE8 0000B0FF */  sd         $16, 0x0($29)
    /* 3C0CEC 004C0CEC 0800B1FF */  sd         $17, 0x8($29)
    /* 3C0CF0 004C0CF0 1800BFFF */  sd         $31, 0x18($29)
    /* 3C0CF4 004C0CF4 9003130C */  jal        func_004c0e40
    /* 3C0CF8 004C0CF8 2D908000 */   daddu     $18, $4, $0
    /* 3C0CFC 004C0CFC 13004050 */  beql       $2, $0, .L004C0D4C
    /* 3C0D00 004C0D00 0000B0DF */   ld        $16, 0x0($29)
    /* 3C0D04 004C0D04 F603130C */  jal        func_004c0fd8
    /* 3C0D08 004C0D08 4000448E */   lw        $4, 0x40($18)
    /* 3C0D0C 004C0D0C 04004050 */  beql       $2, $0, .L004C0D20
    /* 3C0D10 004C0D10 2D804002 */   daddu     $16, $18, $0
    /* 3C0D14 004C0D14 0E04130C */  jal        func_004c1038
    /* 3C0D18 004C0D18 4000448E */   lw        $4, 0x40($18)
    /* 3C0D1C 004C0D1C 2D804002 */  daddu      $16, $18, $0
  .L004C0D20:
    /* 3C0D20 004C0D20 0F001124 */  addiu      $17, $0, 0xF
    /* 3C0D24 004C0D24 0000028E */  lw         $2, 0x0($16)
  .L004C0D28:
    /* 3C0D28 004C0D28 04001026 */  addiu      $16, $16, 0x4
    /* 3C0D2C 004C0D2C 03004010 */  beqz       $2, .L004C0D3C
    /* 3C0D30 004C0D30 2D284000 */   daddu     $5, $2, $0
    /* 3C0D34 004C0D34 5803130C */  jal        func_004c0d60
    /* 3C0D38 004C0D38 2D204002 */   daddu     $4, $18, $0
  .L004C0D3C:
    /* 3C0D3C 004C0D3C FFFF3126 */  addiu      $17, $17, -0x1
    /* 3C0D40 004C0D40 F9FF2306 */  bgezl      $17, .L004C0D28
    /* 3C0D44 004C0D44 0000028E */   lw        $2, 0x0($16)
    /* 3C0D48 004C0D48 0000B0DF */  ld         $16, 0x0($29)
  .L004C0D4C:
    /* 3C0D4C 004C0D4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3C0D50 004C0D50 1000B2DF */  ld         $18, 0x10($29)
    /* 3C0D54 004C0D54 1800BFDF */  ld         $31, 0x18($29)
    /* 3C0D58 004C0D58 0800E003 */  jr         $31
    /* 3C0D5C 004C0D5C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c0ce0, 0x80
