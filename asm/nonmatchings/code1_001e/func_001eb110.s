.section .text
.set noat
.set noreorder
glabel func_001eb110
    /* EB110 001EB110 E0FDBD27 */  addiu      $29, $29, -0x220
    /* EB114 001EB114 1000BFFF */  sd         $31, 0x10($29)
    /* EB118 001EB118 0000B07F */  sq         $16, 0x0($29)
    /* EB11C 001EB11C 2D200000 */  daddu      $4, $0, $0
    /* EB120 001EB120 00730A0C */  jal        func_0029cc00
    /* EB124 001EB124 00000000 */   nop
    /* EB128 001EB128 2D804000 */  daddu      $16, $2, $0
    /* EB12C 001EB12C 01000424 */  addiu      $4, $0, 0x1
    /* EB130 001EB130 00730A0C */  jal        func_0029cc00
    /* EB134 001EB134 00000000 */   nop
    /* EB138 001EB138 01000324 */  addiu      $3, $0, 0x1
    /* EB13C 001EB13C 0F004310 */  beq        $2, $3, .L001EB17C
    /* EB140 001EB140 00000000 */   nop
    /* EB144 001EB144 03004010 */  beqz       $2, .L001EB154
    /* EB148 001EB148 00000000 */   nop
    /* EB14C 001EB14C 19000010 */  b          .L001EB1B4
    /* EB150 001EB150 00000000 */   nop
  .L001EB154:
    /* EB154 001EB154 B4C1080C */  jal        func_002306d0
    /* EB158 001EB158 00000000 */   nop
    /* EB15C 001EB15C 2D204000 */  daddu      $4, $2, $0
    /* EB160 001EB160 02000324 */  addiu      $3, $0, 0x2
    /* EB164 001EB164 480043A4 */  sh         $3, 0x48($2)
    /* EB168 001EB168 01000524 */  addiu      $5, $0, 0x1
    /* EB16C 001EB16C 6451060C */  jal        func_00194590
    /* EB170 001EB170 00000000 */   nop
    /* EB174 001EB174 0F000010 */  b          .L001EB1B4
    /* EB178 001EB178 00000000 */   nop
  .L001EB17C:
    /* EB17C 001EB17C 2000A427 */  addiu      $4, $29, 0x20
    /* EB180 001EB180 6100053C */  lui        $5, %hi(D_00609E40)
    /* EB184 001EB184 409EA524 */  addiu      $5, $5, %lo(D_00609E40)
    /* EB188 001EB188 2D300002 */  daddu      $6, $16, $0
    /* EB18C 001EB18C 2208110C */  jal        func_00442088
    /* EB190 001EB190 00000000 */   nop
    /* EB194 001EB194 02000424 */  addiu      $4, $0, 0x2
    /* EB198 001EB198 2000A527 */  addiu      $5, $29, 0x20
    /* EB19C 001EB19C 7CE0070C */  jal        func_001f81f0
    /* EB1A0 001EB1A0 00000000 */   nop
    /* EB1A4 001EB1A4 2D204000 */  daddu      $4, $2, $0
    /* EB1A8 001EB1A8 01000524 */  addiu      $5, $0, 0x1
    /* EB1AC 001EB1AC 6451060C */  jal        func_00194590
    /* EB1B0 001EB1B0 00000000 */   nop
  .L001EB1B4:
    /* EB1B4 001EB1B4 01000224 */  addiu      $2, $0, 0x1
    /* EB1B8 001EB1B8 1000BFDF */  ld         $31, 0x10($29)
    /* EB1BC 001EB1BC 0000B07B */  lq         $16, 0x0($29)
    /* EB1C0 001EB1C0 2002BD27 */  addiu      $29, $29, 0x220
    /* EB1C4 001EB1C4 0800E003 */  jr         $31
    /* EB1C8 001EB1C8 00000000 */   nop
    /* EB1CC 001EB1CC 00000000 */  nop
.size func_001eb110, 0xc0
