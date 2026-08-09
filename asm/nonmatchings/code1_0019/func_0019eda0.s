.section .text
.set noat
.set noreorder
glabel func_0019eda0
    /* 9EDA0 0019EDA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 9EDA4 0019EDA4 2000BFFF */  sd         $31, 0x20($29)
    /* 9EDA8 0019EDA8 1000B17F */  sq         $17, 0x10($29)
    /* 9EDAC 0019EDAC 0000B07F */  sq         $16, 0x0($29)
    /* 9EDB0 0019EDB0 2D888000 */  daddu      $17, $4, $0
    /* 9EDB4 0019EDB4 A4009094 */  lhu        $16, 0xA4($4)
    /* 9EDB8 0019EDB8 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* 9EDBC 0019EDBC 02000224 */  addiu      $2, $0, 0x2
    /* 9EDC0 0019EDC0 0C006210 */  beq        $3, $2, .L0019EDF4
    /* 9EDC4 0019EDC4 00000000 */   nop
    /* 9EDC8 0019EDC8 0A000224 */  addiu      $2, $0, 0xA
    /* 9EDCC 0019EDCC 06006210 */  beq        $3, $2, .L0019EDE8
    /* 9EDD0 0019EDD0 00000000 */   nop
    /* 9EDD4 0019EDD4 09000224 */  addiu      $2, $0, 0x9
    /* 9EDD8 0019EDD8 03006210 */  beq        $3, $2, .L0019EDE8
    /* 9EDDC 0019EDDC 00000000 */   nop
    /* 9EDE0 0019EDE0 0F000010 */  b          .L0019EE20
    /* 9EDE4 0019EDE4 00000000 */   nop
  .L0019EDE8:
    /* 9EDE8 0019EDE8 01000424 */  addiu      $4, $0, 0x1
    /* 9EDEC 0019EDEC 0D000010 */  b          .L0019EE24
    /* 9EDF0 0019EDF0 00000000 */   nop
  .L0019EDF4:
    /* 9EDF4 0019EDF4 640A248E */  lw         $4, 0xA64($17)
    /* 9EDF8 0019EDF8 09008010 */  beqz       $4, .L0019EE20
    /* 9EDFC 0019EDFC 00000000 */   nop
    /* 9EE00 0019EE00 1000053C */  lui        $5, (0x100000 >> 16)
    /* 9EE04 0019EE04 C4C9080C */  jal        func_00232710
    /* 9EE08 0019EE08 00000000 */   nop
    /* 9EE0C 0019EE0C 04004010 */  beqz       $2, .L0019EE20
    /* 9EE10 0019EE10 00000000 */   nop
    /* 9EE14 0019EE14 01000424 */  addiu      $4, $0, 0x1
    /* 9EE18 0019EE18 02000010 */  b          .L0019EE24
    /* 9EE1C 0019EE1C 00000000 */   nop
  .L0019EE20:
    /* 9EE20 0019EE20 2D200000 */  daddu      $4, $0, $0
  .L0019EE24:
    /* 9EE24 0019EE24 A2002392 */  lbu        $3, 0xA2($17)
    /* 9EE28 0019EE28 02000224 */  addiu      $2, $0, 0x2
    /* 9EE2C 0019EE2C 2C006210 */  beq        $3, $2, .L0019EEE0
    /* 9EE30 0019EE30 00000000 */   nop
    /* 9EE34 0019EE34 01000224 */  addiu      $2, $0, 0x1
    /* 9EE38 0019EE38 14006210 */  beq        $3, $2, .L0019EE8C
    /* 9EE3C 0019EE3C 00000000 */   nop
    /* 9EE40 0019EE40 03006010 */  beqz       $3, .L0019EE50
    /* 9EE44 0019EE44 00000000 */   nop
    /* 9EE48 0019EE48 2F000010 */  b          .L0019EF08
    /* 9EE4C 0019EE4C 00000000 */   nop
  .L0019EE50:
    /* 9EE50 0019EE50 08008010 */  beqz       $4, .L0019EE74
    /* 9EE54 0019EE54 00000000 */   nop
    /* 9EE58 0019EE58 4C010224 */  addiu      $2, $0, 0x14C
    /* 9EE5C 0019EE5C 18180202 */  mult       $3, $16, $2
    /* 9EE60 0019EE60 C0B3828F */  lw         $2, -0x4C40($28)
    /* 9EE64 0019EE64 21104300 */  addu       $2, $2, $3
    /* 9EE68 0019EE68 0A004224 */  addiu      $2, $2, 0xA
    /* 9EE6C 0019EE6C 05000010 */  b          .L0019EE84
    /* 9EE70 0019EE70 00000000 */   nop
  .L0019EE74:
    /* 9EE74 0019EE74 4C010224 */  addiu      $2, $0, 0x14C
    /* 9EE78 0019EE78 18180202 */  mult       $3, $16, $2
    /* 9EE7C 0019EE7C C0B3828F */  lw         $2, -0x4C40($28)
    /* 9EE80 0019EE80 21104300 */  addu       $2, $2, $3
  .L0019EE84:
    /* 9EE84 0019EE84 21000010 */  b          .L0019EF0C
    /* 9EE88 0019EE88 00000000 */   nop
  .L0019EE8C:
    /* 9EE8C 0019EE8C 0B008010 */  beqz       $4, .L0019EEBC
    /* 9EE90 0019EE90 00000000 */   nop
    /* 9EE94 0019EE94 C0101000 */  sll        $2, $16, 3
    /* 9EE98 0019EE98 23105000 */  subu       $2, $2, $16
    /* 9EE9C 0019EE9C 80100200 */  sll        $2, $2, 2
    /* 9EEA0 0019EEA0 21105000 */  addu       $2, $2, $16
    /* 9EEA4 0019EEA4 C0180200 */  sll        $3, $2, 3
    /* 9EEA8 0019EEA8 CCB3828F */  lw         $2, -0x4C34($28)
    /* 9EEAC 0019EEAC 21104300 */  addu       $2, $2, $3
    /* 9EEB0 0019EEB0 0A004224 */  addiu      $2, $2, 0xA
    /* 9EEB4 0019EEB4 08000010 */  b          .L0019EED8
    /* 9EEB8 0019EEB8 00000000 */   nop
  .L0019EEBC:
    /* 9EEBC 0019EEBC C0101000 */  sll        $2, $16, 3
    /* 9EEC0 0019EEC0 23105000 */  subu       $2, $2, $16
    /* 9EEC4 0019EEC4 80100200 */  sll        $2, $2, 2
    /* 9EEC8 0019EEC8 21105000 */  addu       $2, $2, $16
    /* 9EECC 0019EECC C0180200 */  sll        $3, $2, 3
    /* 9EED0 0019EED0 CCB3828F */  lw         $2, -0x4C34($28)
    /* 9EED4 0019EED4 21104300 */  addu       $2, $2, $3
  .L0019EED8:
    /* 9EED8 0019EED8 0C000010 */  b          .L0019EF0C
    /* 9EEDC 0019EEDC 00000000 */   nop
  .L0019EEE0:
    /* 9EEE0 0019EEE0 80101000 */  sll        $2, $16, 2
    /* 9EEE4 0019EEE4 21105000 */  addu       $2, $2, $16
    /* 9EEE8 0019EEE8 40100200 */  sll        $2, $2, 1
    /* 9EEEC 0019EEEC 21105000 */  addu       $2, $2, $16
    /* 9EEF0 0019EEF0 C0180200 */  sll        $3, $2, 3
    /* 9EEF4 0019EEF4 E0B3828F */  lw         $2, -0x4C20($28)
    /* 9EEF8 0019EEF8 21104300 */  addu       $2, $2, $3
    /* 9EEFC 0019EEFC 02004224 */  addiu      $2, $2, 0x2
    /* 9EF00 0019EF00 02000010 */  b          .L0019EF0C
    /* 9EF04 0019EF04 00000000 */   nop
  .L0019EF08:
    /* 9EF08 0019EF08 2D100000 */  daddu      $2, $0, $0
  .L0019EF0C:
    /* 9EF0C 0019EF0C 2000BFDF */  ld         $31, 0x20($29)
    /* 9EF10 0019EF10 1000B17B */  lq         $17, 0x10($29)
    /* 9EF14 0019EF14 0000B07B */  lq         $16, 0x0($29)
    /* 9EF18 0019EF18 3000BD27 */  addiu      $29, $29, 0x30
    /* 9EF1C 0019EF1C 0800E003 */  jr         $31
    /* 9EF20 0019EF20 00000000 */   nop
    /* 9EF24 0019EF24 00000000 */  nop
    /* 9EF28 0019EF28 00000000 */  nop
    /* 9EF2C 0019EF2C 00000000 */  nop
.size func_0019eda0, 0x190
