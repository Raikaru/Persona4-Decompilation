.section .text
.set noat
.set noreorder
glabel func_004da050
    /* 3DA050 004DA050 70FFBD27 */  addiu      $29, $29, -0x90
    /* 3DA054 004DA054 5800B1FF */  sd         $17, 0x58($29)
    /* 3DA058 004DA058 7000B4FF */  sd         $20, 0x70($29)
    /* 3DA05C 004DA05C 2DA08000 */  daddu      $20, $4, $0
    /* 3DA060 004DA060 5000B0FF */  sd         $16, 0x50($29)
    /* 3DA064 004DA064 6000B2FF */  sd         $18, 0x60($29)
    /* 3DA068 004DA068 6800B3FF */  sd         $19, 0x68($29)
    /* 3DA06C 004DA06C 7800B5FF */  sd         $21, 0x78($29)
    /* 3DA070 004DA070 8000BFFF */  sd         $31, 0x80($29)
    /* 3DA074 004DA074 AC01938E */  lw         $19, 0x1AC($20)
    /* 3DA078 004DA078 56006012 */  beqz       $19, .L004DA1D4
    /* 3DA07C 004DA07C E4019126 */   addiu     $17, $20, 0x1E4
    /* 3DA080 004DA080 9200153C */  lui        $21, %hi(D_00922EF0)
    /* 3DA084 004DA084 2D20A003 */  daddu      $4, $29, $0
    /* 3DA088 004DA088 2D280000 */  daddu      $5, $0, $0
    /* 3DA08C 004DA08C 40000624 */  addiu      $6, $0, 0x40
    /* 3DA090 004DA090 72FE100C */  jal        func_0043f9c8
    /* 3DA094 004DA094 F02EB026 */   addiu     $16, $21, %lo(D_00922EF0)
    /* 3DA098 004DA098 04001226 */  addiu      $18, $16, 0x4
    /* 3DA09C 004DA09C 08001212 */  beq        $16, $18, .L004DA0C0
    /* 3DA0A0 004DA0A0 4000A0AF */   sw        $0, 0x40($29)
    /* 3DA0A4 004DA0A4 2D206002 */  daddu      $4, $19, $0
  .L004DA0A8:
    /* 3DA0A8 004DA0A8 F265130C */  jal        func_004d97c8
    /* 3DA0AC 004DA0AC 08000524 */   addiu     $5, $0, 0x8
    /* 3DA0B0 004DA0B0 000002A2 */  sb         $2, 0x0($16)
    /* 3DA0B4 004DA0B4 01001026 */  addiu      $16, $16, 0x1
    /* 3DA0B8 004DA0B8 FBFF1216 */  bne        $16, $18, .L004DA0A8
    /* 3DA0BC 004DA0BC 2D206002 */   daddu     $4, $19, $0
  .L004DA0C0:
    /* 3DA0C0 004DA0C0 F02EA426 */  addiu      $4, $21, %lo(D_00922EF0)
    /* 3DA0C4 004DA0C4 04000524 */  addiu      $5, $0, 0x4
    /* 3DA0C8 004DA0C8 4000A627 */  addiu      $6, $29, 0x40
    /* 3DA0CC 004DA0CC 6C28130C */  jal        func_004ca1b0
    /* 3DA0D0 004DA0D0 2D380000 */   daddu     $7, $0, $0
    /* 3DA0D4 004DA0D4 4000A38F */  lw         $3, 0x40($29)
    /* 3DA0D8 004DA0D8 21904302 */  addu       $18, $18, $3
    /* 3DA0DC 004DA0DC 09001212 */  beq        $16, $18, .L004DA104
    /* 3DA0E0 004DA0E0 F02EA426 */   addiu     $4, $21, %lo(D_00922EF0)
    /* 3DA0E4 004DA0E4 2D206002 */  daddu      $4, $19, $0
  .L004DA0E8:
    /* 3DA0E8 004DA0E8 F265130C */  jal        func_004d97c8
    /* 3DA0EC 004DA0EC 08000524 */   addiu     $5, $0, 0x8
    /* 3DA0F0 004DA0F0 000002A2 */  sb         $2, 0x0($16)
    /* 3DA0F4 004DA0F4 01001026 */  addiu      $16, $16, 0x1
    /* 3DA0F8 004DA0F8 FBFF1216 */  bne        $16, $18, .L004DA0E8
    /* 3DA0FC 004DA0FC 2D206002 */   daddu     $4, $19, $0
    /* 3DA100 004DA100 F02EA426 */  addiu      $4, $21, %lo(D_00922EF0)
  .L004DA104:
    /* 3DA104 004DA104 00020524 */  addiu      $5, $0, 0x200
    /* 3DA108 004DA108 4000A627 */  addiu      $6, $29, 0x40
    /* 3DA10C 004DA10C 6C28130C */  jal        func_004ca1b0
    /* 3DA110 004DA110 2D38A003 */   daddu     $7, $29, $0
    /* 3DA114 004DA114 2F004004 */  bltz       $2, .L004DA1D4
    /* 3DA118 004DA118 3D00A783 */   lb        $7, 0x3D($29)
    /* 3DA11C 004DA11C 01000624 */  addiu      $6, $0, 0x1
    /* 3DA120 004DA120 0300A383 */  lb         $3, 0x3($29)
    /* 3DA124 004DA124 0400A48F */  lw         $4, 0x4($29)
    /* 3DA128 004DA128 1000E528 */  slti       $5, $7, 0x10
    /* 3DA12C 004DA12C 0800A28F */  lw         $2, 0x8($29)
    /* 3DA130 004DA130 2B00A86B */  ldl        $8, 0x2B($29)
    /* 3DA134 004DA134 2400A86F */  ldr        $8, 0x24($29)
    /* 3DA138 004DA138 2F00A98B */  lwl        $9, 0x2F($29)
    /* 3DA13C 004DA13C 2C00A99B */  lwr        $9, 0x2C($29)
    /* 3DA140 004DA140 230028B2 */  sdl        $8, 0x23($17)
    /* 3DA144 004DA144 1C0028B6 */  sdr        $8, 0x1C($17)
    /* 3DA148 004DA148 270029AA */  swl        $9, 0x27($17)
    /* 3DA14C 004DA14C 240029BA */  swr        $9, 0x24($17)
    /* 3DA150 004DA150 040023AE */  sw         $3, 0x4($17)
    /* 3DA154 004DA154 3700A86B */  ldl        $8, 0x37($29)
    /* 3DA158 004DA158 3000A86F */  ldr        $8, 0x30($29)
    /* 3DA15C 004DA15C 3B00A98B */  lwl        $9, 0x3B($29)
    /* 3DA160 004DA160 3800A99B */  lwr        $9, 0x38($29)
    /* 3DA164 004DA164 2F0028B2 */  sdl        $8, 0x2F($17)
    /* 3DA168 004DA168 280028B6 */  sdr        $8, 0x28($17)
    /* 3DA16C 004DA16C 330029AA */  swl        $9, 0x33($17)
    /* 3DA170 004DA170 300029BA */  swr        $9, 0x30($17)
    /* 3DA174 004DA174 080024AE */  sw         $4, 0x8($17)
    /* 3DA178 004DA178 0C0022AE */  sw         $2, 0xC($17)
    /* 3DA17C 004DA17C 0800A014 */  bnez       $5, .L004DA1A0
    /* 3DA180 004DA180 000026AE */   sw        $6, 0x0($17)
    /* 3DA184 004DA184 340020A6 */  sh         $0, 0x34($17)
    /* 3DA188 004DA188 3A002626 */  addiu      $6, $17, 0x3A
    /* 3DA18C 004DA18C 36002426 */  addiu      $4, $17, 0x36
    /* 3DA190 004DA190 3667130C */  jal        func_004d9cd8
    /* 3DA194 004DA194 38002526 */   addiu     $5, $17, 0x38
    /* 3DA198 004DA198 0F000010 */  b          .L004DA1D8
    /* 3DA19C 004DA19C 5000B0DF */   ld        $16, 0x50($29)
  .L004DA1A0:
    /* 3DA1A0 004DA1A0 0800E228 */  slti       $2, $7, 0x8
    /* 3DA1A4 004DA1A4 08004014 */  bnez       $2, .L004DA1C8
    /* 3DA1A8 004DA1A8 34002426 */   addiu     $4, $17, 0x34
    /* 3DA1AC 004DA1AC 270A826A */  ldl        $2, 0xA27($20)
    /* 3DA1B0 004DA1B0 200A826E */  ldr        $2, 0xA20($20)
    /* 3DA1B4 004DA1B4 3B0022B2 */  sdl        $2, 0x3B($17)
    /* 3DA1B8 004DA1B8 340022B6 */  sdr        $2, 0x34($17)
    /* 3DA1BC 004DA1BC 06000010 */  b          .L004DA1D8
    /* 3DA1C0 004DA1C0 5000B0DF */   ld        $16, 0x50($29)
    /* 3DA1C4 004DA1C4 00000000 */  nop
  .L004DA1C8:
    /* 3DA1C8 004DA1C8 2D280000 */  daddu      $5, $0, $0
    /* 3DA1CC 004DA1CC 72FE100C */  jal        func_0043f9c8
    /* 3DA1D0 004DA1D0 08000624 */   addiu     $6, $0, 0x8
  .L004DA1D4:
    /* 3DA1D4 004DA1D4 5000B0DF */  ld         $16, 0x50($29)
  .L004DA1D8:
    /* 3DA1D8 004DA1D8 5800B1DF */  ld         $17, 0x58($29)
    /* 3DA1DC 004DA1DC 6000B2DF */  ld         $18, 0x60($29)
    /* 3DA1E0 004DA1E0 6800B3DF */  ld         $19, 0x68($29)
    /* 3DA1E4 004DA1E4 7000B4DF */  ld         $20, 0x70($29)
    /* 3DA1E8 004DA1E8 7800B5DF */  ld         $21, 0x78($29)
    /* 3DA1EC 004DA1EC 8000BFDF */  ld         $31, 0x80($29)
    /* 3DA1F0 004DA1F0 0800E003 */  jr         $31
    /* 3DA1F4 004DA1F4 9000BD27 */   addiu     $29, $29, 0x90
.size func_004da050, 0x1a8
