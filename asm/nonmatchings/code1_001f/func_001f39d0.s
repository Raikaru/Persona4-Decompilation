.section .text
.set noat
.set noreorder
glabel func_001f39d0
    /* F39D0 001F39D0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* F39D4 001F39D4 2000BFFF */  sd         $31, 0x20($29)
    /* F39D8 001F39D8 1000B17F */  sq         $17, 0x10($29)
    /* F39DC 001F39DC 0000B07F */  sq         $16, 0x0($29)
    /* F39E0 001F39E0 0000848C */  lw         $4, 0x0($4)
    /* F39E4 001F39E4 3000908C */  lw         $16, 0x30($4)
    /* F39E8 001F39E8 6C008394 */  lhu        $3, 0x6C($4)
    /* F39EC 001F39EC 01000224 */  addiu      $2, $0, 0x1
    /* F39F0 001F39F0 3C006210 */  beq        $3, $2, .L001F3AE4
    /* F39F4 001F39F4 00000000 */   nop
    /* F39F8 001F39F8 09000224 */  addiu      $2, $0, 0x9
    /* F39FC 001F39FC 39006210 */  beq        $3, $2, .L001F3AE4
    /* F3A00 001F3A00 00000000 */   nop
    /* F3A04 001F3A04 03000224 */  addiu      $2, $0, 0x3
    /* F3A08 001F3A08 28006210 */  beq        $3, $2, .L001F3AAC
    /* F3A0C 001F3A0C 00000000 */   nop
    /* F3A10 001F3A10 02000224 */  addiu      $2, $0, 0x2
    /* F3A14 001F3A14 03006210 */  beq        $3, $2, .L001F3A24
    /* F3A18 001F3A18 00000000 */   nop
    /* F3A1C 001F3A1C 31000010 */  b          .L001F3AE4
    /* F3A20 001F3A20 00000000 */   nop
  .L001F3A24:
    /* F3A24 001F3A24 6E009194 */  lhu        $17, 0x6E($4)
    /* F3A28 001F3A28 640A048E */  lw         $4, 0xA64($16)
    /* F3A2C 001F3A2C 2D282002 */  daddu      $5, $17, $0
    /* F3A30 001F3A30 6CF6080C */  jal        func_0023d9b0
    /* F3A34 001F3A34 00000000 */   nop
    /* F3A38 001F3A38 2A004010 */  beqz       $2, .L001F3AE4
    /* F3A3C 001F3A3C 00000000 */   nop
    /* F3A40 001F3A40 B8B3858F */  lw         $5, -0x4C48($28)
    /* F3A44 001F3A44 FFFF2432 */  andi       $4, $17, 0xFFFF
    /* F3A48 001F3A48 80180400 */  sll        $3, $4, 2
    /* F3A4C 001F3A4C 21186400 */  addu       $3, $3, $4
    /* F3A50 001F3A50 C0180300 */  sll        $3, $3, 3
    /* F3A54 001F3A54 21186500 */  addu       $3, $3, $5
    /* F3A58 001F3A58 03006490 */  lbu        $4, 0x3($3)
    /* F3A5C 001F3A5C 02000324 */  addiu      $3, $0, 0x2
    /* F3A60 001F3A60 0C008310 */  beq        $4, $3, .L001F3A94
    /* F3A64 001F3A64 00000000 */   nop
    /* F3A68 001F3A68 01000324 */  addiu      $3, $0, 0x1
    /* F3A6C 001F3A6C 03008310 */  beq        $4, $3, .L001F3A7C
    /* F3A70 001F3A70 00000000 */   nop
    /* F3A74 001F3A74 1B000010 */  b          .L001F3AE4
    /* F3A78 001F3A78 00000000 */   nop
  .L001F3A7C:
    /* F3A7C 001F3A7C 23280200 */  negu       $5, $2
    /* F3A80 001F3A80 640A048E */  lw         $4, 0xA64($16)
    /* F3A84 001F3A84 68C9080C */  jal        func_002325a0
    /* F3A88 001F3A88 00000000 */   nop
    /* F3A8C 001F3A8C 15000010 */  b          .L001F3AE4
    /* F3A90 001F3A90 00000000 */   nop
  .L001F3A94:
    /* F3A94 001F3A94 23280200 */  negu       $5, $2
    /* F3A98 001F3A98 640A048E */  lw         $4, 0xA64($16)
    /* F3A9C 001F3A9C 84C9080C */  jal        func_00232610
    /* F3AA0 001F3AA0 00000000 */   nop
    /* F3AA4 001F3AA4 0F000010 */  b          .L001F3AE4
    /* F3AA8 001F3AA8 00000000 */   nop
  .L001F3AAC:
    /* F3AAC 001F3AAC A2000292 */  lbu        $2, 0xA2($16)
    /* F3AB0 001F3AB0 0C004014 */  bnez       $2, .L001F3AE4
    /* F3AB4 001F3AB4 00000000 */   nop
    /* F3AB8 001F3AB8 70008284 */  lh         $2, 0x70($4)
    /* F3ABC 001F3ABC 2D804000 */  daddu      $16, $2, $0
    /* F3AC0 001F3AC0 2D200002 */  daddu      $4, $16, $0
    /* F3AC4 001F3AC4 8019040C */  jal        func_00106600
    /* F3AC8 001F3AC8 00000000 */   nop
    /* F3ACC 001F3ACC FF004230 */  andi       $2, $2, 0xFF
    /* F3AD0 001F3AD0 FFFF4224 */  addiu      $2, $2, -0x1
    /* F3AD4 001F3AD4 FF004530 */  andi       $5, $2, 0xFF
    /* F3AD8 001F3AD8 2D200002 */  daddu      $4, $16, $0
    /* F3ADC 001F3ADC 8819040C */  jal        func_00106620
    /* F3AE0 001F3AE0 00000000 */   nop
  .L001F3AE4:
    /* F3AE4 001F3AE4 01000224 */  addiu      $2, $0, 0x1
    /* F3AE8 001F3AE8 2000BFDF */  ld         $31, 0x20($29)
    /* F3AEC 001F3AEC 1000B17B */  lq         $17, 0x10($29)
    /* F3AF0 001F3AF0 0000B07B */  lq         $16, 0x0($29)
    /* F3AF4 001F3AF4 3000BD27 */  addiu      $29, $29, 0x30
    /* F3AF8 001F3AF8 0800E003 */  jr         $31
    /* F3AFC 001F3AFC 00000000 */   nop
.size func_001f39d0, 0x130
