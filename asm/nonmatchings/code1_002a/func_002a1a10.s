.section .text
.set noat
.set noreorder
glabel func_002a1a10
    /* 1A1A10 002A1A10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1A1A14 002A1A14 1000BFFF */  sd         $31, 0x10($29)
    /* 1A1A18 002A1A18 0000B07F */  sq         $16, 0x0($29)
    /* 1A1A1C 002A1A1C 3800908C */  lw         $16, 0x38($4)
    /* 1A1A20 002A1A20 1000038E */  lw         $3, 0x10($16)
    /* 1A1A24 002A1A24 02000224 */  addiu      $2, $0, 0x2
    /* 1A1A28 002A1A28 2F006210 */  beq        $3, $2, .L002A1AE8
    /* 1A1A2C 002A1A2C 00000000 */   nop
    /* 1A1A30 002A1A30 01000224 */  addiu      $2, $0, 0x1
    /* 1A1A34 002A1A34 19006210 */  beq        $3, $2, .L002A1A9C
    /* 1A1A38 002A1A38 00000000 */   nop
    /* 1A1A3C 002A1A3C 03006010 */  beqz       $3, .L002A1A4C
    /* 1A1A40 002A1A40 00000000 */   nop
    /* 1A1A44 002A1A44 2E000010 */  b          .L002A1B00
    /* 1A1A48 002A1A48 00000000 */   nop
  .L002A1A4C:
    /* 1A1A4C 002A1A4C 2CB580AF */  sw         $0, -0x4AD4($28)
    /* 1A1A50 002A1A50 38ED0A0C */  jal        func_002bb4e0
    /* 1A1A54 002A1A54 00000000 */   nop
    /* 1A1A58 002A1A58 6400043C */  lui        $4, %hi(D_0063E630)
    /* 1A1A5C 002A1A5C 30E68424 */  addiu      $4, $4, %lo(D_0063E630)
    /* 1A1A60 002A1A60 B0EA0A0C */  jal        func_002baac0
    /* 1A1A64 002A1A64 00000000 */   nop
    /* 1A1A68 002A1A68 01000424 */  addiu      $4, $0, 0x1
    /* 1A1A6C 002A1A6C 44EB0A0C */  jal        func_002bad10
    /* 1A1A70 002A1A70 00000000 */   nop
    /* 1A1A74 002A1A74 2D200000 */  daddu      $4, $0, $0
    /* 1A1A78 002A1A78 D0EB0A0C */  jal        func_002baf40
    /* 1A1A7C 002A1A7C 00000000 */   nop
    /* 1A1A80 002A1A80 2D200000 */  daddu      $4, $0, $0
    /* 1A1A84 002A1A84 14EC0A0C */  jal        func_002bb050
    /* 1A1A88 002A1A88 00000000 */   nop
    /* 1A1A8C 002A1A8C 01000224 */  addiu      $2, $0, 0x1
    /* 1A1A90 002A1A90 100002AE */  sw         $2, 0x10($16)
    /* 1A1A94 002A1A94 1A000010 */  b          .L002A1B00
    /* 1A1A98 002A1A98 00000000 */   nop
  .L002A1A9C:
    /* 1A1A9C 002A1A9C 80ED0A0C */  jal        func_002bb600
    /* 1A1AA0 002A1AA0 00000000 */   nop
    /* 1A1AA4 002A1AA4 0C004010 */  beqz       $2, .L002A1AD8
    /* 1A1AA8 002A1AA8 00000000 */   nop
    /* 1A1AAC 002A1AAC 30EF0A0C */  jal        func_002bbcc0
    /* 1A1AB0 002A1AB0 00000000 */   nop
    /* 1A1AB4 002A1AB4 C0ED0A0C */  jal        func_002bb700
    /* 1A1AB8 002A1AB8 00000000 */   nop
    /* 1A1ABC 002A1ABC 10004014 */  bnez       $2, .L002A1B00
    /* 1A1AC0 002A1AC0 00000000 */   nop
    /* 1A1AC4 002A1AC4 38EC0A0C */  jal        func_002bb0e0
    /* 1A1AC8 002A1AC8 00000000 */   nop
    /* 1A1ACC 002A1ACC 2CB582AF */  sw         $2, -0x4AD4($28)
    /* 1A1AD0 002A1AD0 0B000010 */  b          .L002A1B00
    /* 1A1AD4 002A1AD4 00000000 */   nop
  .L002A1AD8:
    /* 1A1AD8 002A1AD8 02000224 */  addiu      $2, $0, 0x2
    /* 1A1ADC 002A1ADC 100002AE */  sw         $2, 0x10($16)
    /* 1A1AE0 002A1AE0 07000010 */  b          .L002A1B00
    /* 1A1AE4 002A1AE4 00000000 */   nop
  .L002A1AE8:
    /* 1A1AE8 002A1AE8 38ED0A0C */  jal        func_002bb4e0
    /* 1A1AEC 002A1AEC 00000000 */   nop
    /* 1A1AF0 002A1AF0 100000AE */  sw         $0, 0x10($16)
    /* 1A1AF4 002A1AF4 2CB5828F */  lw         $2, -0x4AD4($28)
    /* 1A1AF8 002A1AF8 02000010 */  b          .L002A1B04
    /* 1A1AFC 002A1AFC 00000000 */   nop
  .L002A1B00:
    /* 1A1B00 002A1B00 FFFF0224 */  addiu      $2, $0, -0x1
  .L002A1B04:
    /* 1A1B04 002A1B04 1000BFDF */  ld         $31, 0x10($29)
    /* 1A1B08 002A1B08 0000B07B */  lq         $16, 0x0($29)
    /* 1A1B0C 002A1B0C 2000BD27 */  addiu      $29, $29, 0x20
    /* 1A1B10 002A1B10 0800E003 */  jr         $31
    /* 1A1B14 002A1B14 00000000 */   nop
    /* 1A1B18 002A1B18 00000000 */  nop
    /* 1A1B1C 002A1B1C 00000000 */  nop
.size func_002a1a10, 0x110
