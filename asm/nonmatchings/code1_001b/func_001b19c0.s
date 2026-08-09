.section .text
.set noat
.set noreorder
glabel func_001b19c0
    /* B19C0 001B19C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* B19C4 001B19C4 1000BFFF */  sd         $31, 0x10($29)
    /* B19C8 001B19C8 0000B07F */  sq         $16, 0x0($29)
    /* B19CC 001B19CC 80DA060C */  jal        func_001b6a00
    /* B19D0 001B19D0 00000000 */   nop
    /* B19D4 001B19D4 4C004010 */  beqz       $2, .L001B1B08
    /* B19D8 001B19D8 00000000 */   nop
    /* B19DC 001B19DC 1C4F060C */  jal        func_00193c70
    /* B19E0 001B19E0 00000000 */   nop
    /* B19E4 001B19E4 48004014 */  bnez       $2, .L001B1B08
    /* B19E8 001B19E8 00000000 */   nop
    /* B19EC 001B19EC 01000424 */  addiu      $4, $0, 0x1
    /* B19F0 001B19F0 B828050C */  jal        func_0014a2e0
    /* B19F4 001B19F4 00000000 */   nop
    /* B19F8 001B19F8 48D8060C */  jal        func_001b6120
    /* B19FC 001B19FC 00000000 */   nop
    /* B1A00 001B1A00 38000424 */  addiu      $4, $0, 0x38
    /* B1A04 001B1A04 CC18040C */  jal        func_00106330
    /* B1A08 001B1A08 00000000 */   nop
    /* B1A0C 001B1A0C 04004010 */  beqz       $2, .L001B1A20
    /* B1A10 001B1A10 00000000 */   nop
    /* B1A14 001B1A14 01000224 */  addiu      $2, $0, 0x1
    /* B1A18 001B1A18 02000010 */  b          .L001B1A24
    /* B1A1C 001B1A1C 00000000 */   nop
  .L001B1A20:
    /* B1A20 001B1A20 2D100000 */  daddu      $2, $0, $0
  .L001B1A24:
    /* B1A24 001B1A24 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* B1A28 001B1A28 E0E6070C */  jal        func_001f9b80
    /* B1A2C 001B1A2C 00000000 */   nop
    /* B1A30 001B1A30 2D804000 */  daddu      $16, $2, $0
    /* B1A34 001B1A34 2D200002 */  daddu      $4, $16, $0
    /* B1A38 001B1A38 01000524 */  addiu      $5, $0, 0x1
    /* B1A3C 001B1A3C 6451060C */  jal        func_00194590
    /* B1A40 001B1A40 00000000 */   nop
    /* B1A44 001B1A44 ECE5070C */  jal        func_001f97b0
    /* B1A48 001B1A48 00000000 */   nop
    /* B1A4C 001B1A4C 2D204000 */  daddu      $4, $2, $0
    /* B1A50 001B1A50 04000324 */  addiu      $3, $0, 0x4
    /* B1A54 001B1A54 000043A0 */  sb         $3, 0x0($2)
    /* B1A58 001B1A58 580003DE */  ld         $3, 0x58($16)
    /* B1A5C 001B1A5C 080043FC */  sd         $3, 0x8($2)
    /* B1A60 001B1A60 01000524 */  addiu      $5, $0, 0x1
    /* B1A64 001B1A64 6451060C */  jal        func_00194590
    /* B1A68 001B1A68 00000000 */   nop
    /* B1A6C 001B1A6C 48AF080C */  jal        func_0022bd20
    /* B1A70 001B1A70 00000000 */   nop
    /* B1A74 001B1A74 13004010 */  beqz       $2, .L001B1AC4
    /* B1A78 001B1A78 00000000 */   nop
    /* B1A7C 001B1A7C 2CC1080C */  jal        func_002304b0
    /* B1A80 001B1A80 00000000 */   nop
    /* B1A84 001B1A84 2D204000 */  daddu      $4, $2, $0
    /* B1A88 001B1A88 01000524 */  addiu      $5, $0, 0x1
    /* B1A8C 001B1A8C 6451060C */  jal        func_00194590
    /* B1A90 001B1A90 00000000 */   nop
    /* B1A94 001B1A94 E4C1080C */  jal        func_00230790
    /* B1A98 001B1A98 00000000 */   nop
    /* B1A9C 001B1A9C FFFF0324 */  addiu      $3, $0, -0x1
    /* B1AA0 001B1AA0 08004310 */  beq        $2, $3, .L001B1AC4
    /* B1AA4 001B1AA4 00000000 */   nop
    /* B1AA8 001B1AA8 2D204000 */  daddu      $4, $2, $0
    /* B1AAC 001B1AAC 70C1080C */  jal        func_002305c0
    /* B1AB0 001B1AB0 00000000 */   nop
    /* B1AB4 001B1AB4 2D204000 */  daddu      $4, $2, $0
    /* B1AB8 001B1AB8 01000524 */  addiu      $5, $0, 0x1
    /* B1ABC 001B1ABC 6451060C */  jal        func_00194590
    /* B1AC0 001B1AC0 00000000 */   nop
  .L001B1AC4:
    /* B1AC4 001B1AC4 68BE070C */  jal        func_001ef9a0
    /* B1AC8 001B1AC8 00000000 */   nop
    /* B1ACC 001B1ACC 15020324 */  addiu      $3, $0, 0x215
    /* B1AD0 001B1AD0 06004310 */  beq        $2, $3, .L001B1AEC
    /* B1AD4 001B1AD4 00000000 */   nop
    /* B1AD8 001B1AD8 0B020324 */  addiu      $3, $0, 0x20B
    /* B1ADC 001B1ADC 03004310 */  beq        $2, $3, .L001B1AEC
    /* B1AE0 001B1AE0 00000000 */   nop
    /* B1AE4 001B1AE4 05000010 */  b          .L001B1AFC
    /* B1AE8 001B1AE8 00000000 */   nop
  .L001B1AEC:
    /* B1AEC 001B1AEC A0AA0A0C */  jal        func_002aaa80
    /* B1AF0 001B1AF0 00000000 */   nop
    /* B1AF4 001B1AF4 A0F0070C */  jal        func_001fc280
    /* B1AF8 001B1AF8 00000000 */   nop
  .L001B1AFC:
    /* B1AFC 001B1AFC 05000224 */  addiu      $2, $0, 0x5
    /* B1B00 001B1B00 02000010 */  b          .L001B1B0C
    /* B1B04 001B1B04 00000000 */   nop
  .L001B1B08:
    /* B1B08 001B1B08 2D100000 */  daddu      $2, $0, $0
  .L001B1B0C:
    /* B1B0C 001B1B0C 1000BFDF */  ld         $31, 0x10($29)
    /* B1B10 001B1B10 0000B07B */  lq         $16, 0x0($29)
    /* B1B14 001B1B14 2000BD27 */  addiu      $29, $29, 0x20
    /* B1B18 001B1B18 0800E003 */  jr         $31
    /* B1B1C 001B1B1C 00000000 */   nop
    /* B1B20 001B1B20 0800E003 */  jr         $31
    /* B1B24 001B1B24 00000000 */   nop
    /* B1B28 001B1B28 00000000 */  nop
    /* B1B2C 001B1B2C 00000000 */  nop
.size func_001b19c0, 0x170
