.section .text
.set noat
.set noreorder
glabel func_001dbf20
    /* DBF20 001DBF20 10FFBD27 */  addiu      $29, $29, -0xF0
    /* DBF24 001DBF24 8000BFFF */  sd         $31, 0x80($29)
    /* DBF28 001DBF28 7000B77F */  sq         $23, 0x70($29)
    /* DBF2C 001DBF2C 6000B67F */  sq         $22, 0x60($29)
    /* DBF30 001DBF30 5000B57F */  sq         $21, 0x50($29)
    /* DBF34 001DBF34 4000B47F */  sq         $20, 0x40($29)
    /* DBF38 001DBF38 3000B37F */  sq         $19, 0x30($29)
    /* DBF3C 001DBF3C 2000B27F */  sq         $18, 0x20($29)
    /* DBF40 001DBF40 1000B17F */  sq         $17, 0x10($29)
    /* DBF44 001DBF44 0000B07F */  sq         $16, 0x0($29)
    /* DBF48 001DBF48 2D808000 */  daddu      $16, $4, $0
    /* DBF4C 001DBF4C 98000526 */  addiu      $5, $16, 0x98
    /* DBF50 001DBF50 6E008694 */  lhu        $6, 0x6E($4)
    /* DBF54 001DBF54 2D380000 */  daddu      $7, $0, $0
    /* DBF58 001DBF58 C45F070C */  jal        func_001d7f10
    /* DBF5C 001DBF5C 00000000 */   nop
    /* DBF60 001DBF60 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DBF64 001DBF64 14004010 */  beqz       $2, .L001DBFB8
    /* DBF68 001DBF68 00000000 */   nop
    /* DBF6C 001DBF6C 2D200000 */  daddu      $4, $0, $0
    /* DBF70 001DBF70 08000010 */  b          .L001DBF94
    /* DBF74 001DBF74 00000000 */   nop
  .L001DBF78:
    /* DBF78 001DBF78 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DBF7C 001DBF7C 80100200 */  sll        $2, $2, 2
    /* DBF80 001DBF80 21180202 */  addu       $3, $16, $2
    /* DBF84 001DBF84 9800628C */  lw         $2, 0x98($3)
    /* DBF88 001DBF88 380062AC */  sw         $2, 0x38($3)
    /* DBF8C 001DBF8C 01008224 */  addiu      $2, $4, 0x1
    /* DBF90 001DBF90 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DBF94:
    /* DBF94 001DBF94 D0000396 */  lhu        $3, 0xD0($16)
    /* DBF98 001DBF98 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DBF9C 001DBF9C 2A104300 */  slt        $2, $2, $3
    /* DBFA0 001DBFA0 F5FF4014 */  bnez       $2, .L001DBF78
    /* DBFA4 001DBFA4 00000000 */   nop
    /* DBFA8 001DBFA8 6A0003A6 */  sh         $3, 0x6A($16)
    /* DBFAC 001DBFAC 01000224 */  addiu      $2, $0, 0x1
    /* DBFB0 001DBFB0 E6000010 */  b          .L001DC34C
    /* DBFB4 001DBFB4 00000000 */   nop
  .L001DBFB8:
    /* DBFB8 001DBFB8 D0001496 */  lhu        $20, 0xD0($16)
    /* DBFBC 001DBFBC 01000224 */  addiu      $2, $0, 0x1
    /* DBFC0 001DBFC0 06008216 */  bne        $20, $2, .L001DBFDC
    /* DBFC4 001DBFC4 00000000 */   nop
    /* DBFC8 001DBFC8 9800038E */  lw         $3, 0x98($16)
    /* DBFCC 001DBFCC 380003AE */  sw         $3, 0x38($16)
    /* DBFD0 001DBFD0 6A0002A6 */  sh         $2, 0x6A($16)
    /* DBFD4 001DBFD4 DC000010 */  b          .L001DC348
    /* DBFD8 001DBFD8 00000000 */   nop
  .L001DBFDC:
    /* DBFDC 001DBFDC 3000038E */  lw         $3, 0x30($16)
    /* DBFE0 001DBFE0 A2006390 */  lbu        $3, 0xA2($3)
    /* DBFE4 001DBFE4 15006214 */  bne        $3, $2, .L001DC03C
    /* DBFE8 001DBFE8 00000000 */   nop
    /* DBFEC 001DBFEC 2D280000 */  daddu      $5, $0, $0
    /* DBFF0 001DBFF0 0B000010 */  b          .L001DC020
    /* DBFF4 001DBFF4 00000000 */   nop
  .L001DBFF8:
    /* DBFF8 001DBFF8 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* DBFFC 001DBFFC 80180300 */  sll        $3, $3, 2
    /* DC000 001DC000 21180302 */  addu       $3, $16, $3
    /* DC004 001DC004 9800638C */  lw         $3, 0x98($3)
    /* DC008 001DC008 3000638C */  lw         $3, 0x30($3)
    /* DC00C 001DC00C A2006390 */  lbu        $3, 0xA2($3)
    /* DC010 001DC010 07006014 */  bnez       $3, .L001DC030
    /* DC014 001DC014 00000000 */   nop
    /* DC018 001DC018 0100A324 */  addiu      $3, $5, 0x1
    /* DC01C 001DC01C FFFF6530 */  andi       $5, $3, 0xFFFF
  .L001DC020:
    /* DC020 001DC020 FFFFA430 */  andi       $4, $5, 0xFFFF
    /* DC024 001DC024 2A189400 */  slt        $3, $4, $20
    /* DC028 001DC028 F3FF6014 */  bnez       $3, .L001DBFF8
    /* DC02C 001DC02C 00000000 */   nop
  .L001DC030:
    /* DC030 001DC030 02009414 */  bne        $4, $20, .L001DC03C
    /* DC034 001DC034 00000000 */   nop
    /* DC038 001DC038 2D100000 */  daddu      $2, $0, $0
  .L001DC03C:
    /* DC03C 001DC03C 6E000496 */  lhu        $4, 0x6E($16)
    /* DC040 001DC040 80180400 */  sll        $3, $4, 2
    /* DC044 001DC044 21186400 */  addu       $3, $3, $4
    /* DC048 001DC048 C0200300 */  sll        $4, $3, 3
    /* DC04C 001DC04C B8B3838F */  lw         $3, -0x4C48($28)
    /* DC050 001DC050 21188300 */  addu       $3, $4, $3
    /* DC054 001DC054 11006490 */  lbu        $4, 0x11($3)
    /* DC058 001DC058 10000324 */  addiu      $3, $0, 0x10
    /* DC05C 001DC05C 1A008310 */  beq        $4, $3, .L001DC0C8
    /* DC060 001DC060 00000000 */   nop
    /* DC064 001DC064 0E000324 */  addiu      $3, $0, 0xE
    /* DC068 001DC068 17008310 */  beq        $4, $3, .L001DC0C8
    /* DC06C 001DC06C 00000000 */   nop
    /* DC070 001DC070 0D000324 */  addiu      $3, $0, 0xD
    /* DC074 001DC074 14008310 */  beq        $4, $3, .L001DC0C8
    /* DC078 001DC078 00000000 */   nop
    /* DC07C 001DC07C 0C000324 */  addiu      $3, $0, 0xC
    /* DC080 001DC080 11008310 */  beq        $4, $3, .L001DC0C8
    /* DC084 001DC084 00000000 */   nop
    /* DC088 001DC088 0A000324 */  addiu      $3, $0, 0xA
    /* DC08C 001DC08C 0E008310 */  beq        $4, $3, .L001DC0C8
    /* DC090 001DC090 00000000 */   nop
    /* DC094 001DC094 08000324 */  addiu      $3, $0, 0x8
    /* DC098 001DC098 0B008310 */  beq        $4, $3, .L001DC0C8
    /* DC09C 001DC09C 00000000 */   nop
    /* DC0A0 001DC0A0 04000324 */  addiu      $3, $0, 0x4
    /* DC0A4 001DC0A4 08008310 */  beq        $4, $3, .L001DC0C8
    /* DC0A8 001DC0A8 00000000 */   nop
    /* DC0AC 001DC0AC 03000324 */  addiu      $3, $0, 0x3
    /* DC0B0 001DC0B0 05008310 */  beq        $4, $3, .L001DC0C8
    /* DC0B4 001DC0B4 00000000 */   nop
    /* DC0B8 001DC0B8 01000324 */  addiu      $3, $0, 0x1
    /* DC0BC 001DC0BC 02008310 */  beq        $4, $3, .L001DC0C8
    /* DC0C0 001DC0C0 00000000 */   nop
    /* DC0C4 001DC0C4 2D106000 */  daddu      $2, $3, $0
  .L001DC0C8:
    /* DC0C8 001DC0C8 04004014 */  bnez       $2, .L001DC0DC
    /* DC0CC 001DC0CC 00000000 */   nop
    /* DC0D0 001DC0D0 0500812A */  slti       $1, $20, 0x5
    /* DC0D4 001DC0D4 0D002014 */  bnez       $1, .L001DC10C
    /* DC0D8 001DC0D8 00000000 */   nop
  .L001DC0DC:
    /* DC0DC 001DC0DC FFFF8432 */  andi       $4, $20, 0xFFFF
    /* DC0E0 001DC0E0 5CC7080C */  jal        func_00231d70
    /* DC0E4 001DC0E4 00000000 */   nop
    /* DC0E8 001DC0E8 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DC0EC 001DC0EC 80100200 */  sll        $2, $2, 2
    /* DC0F0 001DC0F0 21105000 */  addu       $2, $2, $16
    /* DC0F4 001DC0F4 9800428C */  lw         $2, 0x98($2)
    /* DC0F8 001DC0F8 380002AE */  sw         $2, 0x38($16)
    /* DC0FC 001DC0FC 01000224 */  addiu      $2, $0, 0x1
    /* DC100 001DC100 6A0002A6 */  sh         $2, 0x6A($16)
    /* DC104 001DC104 90000010 */  b          .L001DC348
    /* DC108 001DC108 00000000 */   nop
  .L001DC10C:
    /* DC10C 001DC10C 2DA80000 */  daddu      $21, $0, $0
    /* DC110 001DC110 FFFF9332 */  andi       $19, $20, 0xFFFF
    /* DC114 001DC114 37000010 */  b          .L001DC1F4
    /* DC118 001DC118 00000000 */   nop
  .L001DC11C:
    /* DC11C 001DC11C FFFFB232 */  andi       $18, $21, 0xFFFF
    /* DC120 001DC120 80101200 */  sll        $2, $18, 2
    /* DC124 001DC124 21100202 */  addu       $2, $16, $2
    /* DC128 001DC128 98005724 */  addiu      $23, $2, 0x98
    /* DC12C 001DC12C 9800568C */  lw         $22, 0x98($2)
    /* DC130 001DC130 3000C28E */  lw         $2, 0x30($22)
    /* DC134 001DC134 640A448C */  lw         $4, 0xA64($2)
    /* DC138 001DC138 E0C7080C */  jal        func_00231f80
    /* DC13C 001DC13C 00000000 */   nop
    /* DC140 001DC140 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* DC144 001DC144 3000C28E */  lw         $2, 0x30($22)
    /* DC148 001DC148 640A448C */  lw         $4, 0xA64($2)
    /* DC14C 001DC14C B4C7080C */  jal        func_00231ed0
    /* DC150 001DC150 00000000 */   nop
    /* DC154 001DC154 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* DC158 001DC158 C0101200 */  sll        $2, $18, 3
    /* DC15C 001DC15C 21105D00 */  addu       $2, $2, $29
    /* DC160 001DC160 90004424 */  addiu      $4, $2, 0x90
    /* DC164 001DC164 0000E28E */  lw         $2, 0x0($23)
    /* DC168 001DC168 000082AC */  sw         $2, 0x0($4)
    /* DC16C 001DC16C 0600A004 */  bltz       $5, .L001DC188
    /* DC170 001DC170 00000000 */   nop
    /* DC174 001DC174 00008544 */  mtc1       $5, $f0
    /* DC178 001DC178 00000000 */  nop
    /* DC17C 001DC17C 60008046 */  cvt.s.w    $f1, $f0
    /* DC180 001DC180 08000010 */  b          .L001DC1A4
    /* DC184 001DC184 00000000 */   nop
  .L001DC188:
    /* DC188 001DC188 42180500 */  srl        $3, $5, 1
    /* DC18C 001DC18C 0100A230 */  andi       $2, $5, 0x1
    /* DC190 001DC190 25186200 */  or         $3, $3, $2
    /* DC194 001DC194 00008344 */  mtc1       $3, $f0
    /* DC198 001DC198 00000000 */  nop
    /* DC19C 001DC19C 60008046 */  cvt.s.w    $f1, $f0
    /* DC1A0 001DC1A0 40080146 */  add.s      $f1, $f1, $f1
  .L001DC1A4:
    /* DC1A4 001DC1A4 06002006 */  bltz       $17, .L001DC1C0
    /* DC1A8 001DC1A8 00000000 */   nop
    /* DC1AC 001DC1AC 00009144 */  mtc1       $17, $f0
    /* DC1B0 001DC1B0 00000000 */  nop
    /* DC1B4 001DC1B4 20008046 */  cvt.s.w    $f0, $f0
    /* DC1B8 001DC1B8 08000010 */  b          .L001DC1DC
    /* DC1BC 001DC1BC 00000000 */   nop
  .L001DC1C0:
    /* DC1C0 001DC1C0 42181100 */  srl        $3, $17, 1
    /* DC1C4 001DC1C4 01002232 */  andi       $2, $17, 0x1
    /* DC1C8 001DC1C8 25186200 */  or         $3, $3, $2
    /* DC1CC 001DC1CC 00008344 */  mtc1       $3, $f0
    /* DC1D0 001DC1D0 00000000 */  nop
    /* DC1D4 001DC1D4 20008046 */  cvt.s.w    $f0, $f0
    /* DC1D8 001DC1D8 00000046 */  add.s      $f0, $f0, $f0
  .L001DC1DC:
    /* DC1DC 001DC1DC 00000000 */  nop
    /* DC1E0 001DC1E0 00000000 */  nop
    /* DC1E4 001DC1E4 03080046 */  div.s      $f0, $f1, $f0
    /* DC1E8 001DC1E8 040080E4 */  swc1       $f0, 0x4($4)
    /* DC1EC 001DC1EC 0100A226 */  addiu      $2, $21, 0x1
    /* DC1F0 001DC1F0 FFFF5530 */  andi       $21, $2, 0xFFFF
  .L001DC1F4:
    /* DC1F4 001DC1F4 FFFFA232 */  andi       $2, $21, 0xFFFF
    /* DC1F8 001DC1F8 2A105300 */  slt        $2, $2, $19
    /* DC1FC 001DC1FC C7FF4014 */  bnez       $2, .L001DC11C
    /* DC200 001DC200 00000000 */   nop
    /* DC204 001DC204 FFFF6826 */  addiu      $8, $19, -0x1
    /* DC208 001DC208 01000424 */  addiu      $4, $0, 0x1
  .L001DC20C:
    /* DC20C 001DC20C 2D480000 */  daddu      $9, $0, $0
    /* DC210 001DC210 2D380000 */  daddu      $7, $0, $0
    /* DC214 001DC214 18000010 */  b          .L001DC278
    /* DC218 001DC218 00000000 */   nop
  .L001DC21C:
    /* DC21C 001DC21C C0100300 */  sll        $2, $3, 3
    /* DC220 001DC220 21105D00 */  addu       $2, $2, $29
    /* DC224 001DC224 90004324 */  addiu      $3, $2, 0x90
    /* DC228 001DC228 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* DC22C 001DC22C C0100200 */  sll        $2, $2, 3
    /* DC230 001DC230 21105D00 */  addu       $2, $2, $29
    /* DC234 001DC234 90004624 */  addiu      $6, $2, 0x90
    /* DC238 001DC238 0400C524 */  addiu      $5, $6, 0x4
    /* DC23C 001DC23C 0400C1C4 */  lwc1       $f1, 0x4($6)
    /* DC240 001DC240 0C0060C4 */  lwc1       $f0, 0xC($3)
    /* DC244 001DC244 34080046 */  c.lt.s     $f1, $f0
    /* DC248 001DC248 09000045 */  bc1f       .L001DC270
    /* DC24C 001DC24C 00000000 */   nop
    /* DC250 001DC250 0000C38C */  lw         $3, 0x0($6)
    /* DC254 001DC254 0800C28C */  lw         $2, 0x8($6)
    /* DC258 001DC258 0000C2AC */  sw         $2, 0x0($6)
    /* DC25C 001DC25C 0C00C0C4 */  lwc1       $f0, 0xC($6)
    /* DC260 001DC260 0000A0E4 */  swc1       $f0, 0x0($5)
    /* DC264 001DC264 0800C3AC */  sw         $3, 0x8($6)
    /* DC268 001DC268 0C00C1E4 */  swc1       $f1, 0xC($6)
    /* DC26C 001DC26C 2D488000 */  daddu      $9, $4, $0
  .L001DC270:
    /* DC270 001DC270 0100E224 */  addiu      $2, $7, 0x1
    /* DC274 001DC274 FFFF4730 */  andi       $7, $2, 0xFFFF
  .L001DC278:
    /* DC278 001DC278 FFFFE330 */  andi       $3, $7, 0xFFFF
    /* DC27C 001DC27C 2A106800 */  slt        $2, $3, $8
    /* DC280 001DC280 E6FF4014 */  bnez       $2, .L001DC21C
    /* DC284 001DC284 00000000 */   nop
    /* DC288 001DC288 E0FF2015 */  bnez       $9, .L001DC20C
    /* DC28C 001DC28C 00000000 */   nop
    /* DC290 001DC290 64000424 */  addiu      $4, $0, 0x64
    /* DC294 001DC294 5CC7080C */  jal        func_00231d70
    /* DC298 001DC298 00000000 */   nop
    /* DC29C 001DC29C FFFF4630 */  andi       $6, $2, 0xFFFF
    /* DC2A0 001DC2A0 2D400000 */  daddu      $8, $0, $0
    /* DC2A4 001DC2A4 2D380000 */  daddu      $7, $0, $0
    /* DC2A8 001DC2A8 FFFF8532 */  andi       $5, $20, 0xFFFF
    /* DC2AC 001DC2AC 80180500 */  sll        $3, $5, 2
    /* DC2B0 001DC2B0 6100023C */  lui        $2, %hi(D_006095F0)
    /* DC2B4 001DC2B4 F0954224 */  addiu      $2, $2, %lo(D_006095F0)
    /* DC2B8 001DC2B8 21204300 */  addu       $4, $2, $3
    /* DC2BC 001DC2BC 0A000010 */  b          .L001DC2E8
    /* DC2C0 001DC2C0 00000000 */   nop
  .L001DC2C4:
    /* DC2C4 001DC2C4 21108300 */  addu       $2, $4, $3
    /* DC2C8 001DC2C8 FCFF4290 */  lbu        $2, -0x4($2)
    /* DC2CC 001DC2CC 21100201 */  addu       $2, $8, $2
    /* DC2D0 001DC2D0 FFFF4830 */  andi       $8, $2, 0xFFFF
    /* DC2D4 001DC2D4 2A080601 */  slt        $1, $8, $6
    /* DC2D8 001DC2D8 07002010 */  beqz       $1, .L001DC2F8
    /* DC2DC 001DC2DC 00000000 */   nop
    /* DC2E0 001DC2E0 0100E224 */  addiu      $2, $7, 0x1
    /* DC2E4 001DC2E4 FFFF4730 */  andi       $7, $2, 0xFFFF
  .L001DC2E8:
    /* DC2E8 001DC2E8 FFFFE330 */  andi       $3, $7, 0xFFFF
    /* DC2EC 001DC2EC 2A106500 */  slt        $2, $3, $5
    /* DC2F0 001DC2F0 F4FF4014 */  bnez       $2, .L001DC2C4
    /* DC2F4 001DC2F4 00000000 */   nop
  .L001DC2F8:
    /* DC2F8 001DC2F8 0A006312 */  beq        $19, $3, .L001DC324
    /* DC2FC 001DC2FC 00000000 */   nop
    /* DC300 001DC300 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* DC304 001DC304 C0100200 */  sll        $2, $2, 3
    /* DC308 001DC308 21105D00 */  addu       $2, $2, $29
    /* DC30C 001DC30C 9000428C */  lw         $2, 0x90($2)
    /* DC310 001DC310 380002AE */  sw         $2, 0x38($16)
    /* DC314 001DC314 01000224 */  addiu      $2, $0, 0x1
    /* DC318 001DC318 6A0002A6 */  sh         $2, 0x6A($16)
    /* DC31C 001DC31C 0A000010 */  b          .L001DC348
    /* DC320 001DC320 00000000 */   nop
  .L001DC324:
    /* DC324 001DC324 FFFF8432 */  andi       $4, $20, 0xFFFF
    /* DC328 001DC328 5CC7080C */  jal        func_00231d70
    /* DC32C 001DC32C 00000000 */   nop
    /* DC330 001DC330 C0100200 */  sll        $2, $2, 3
    /* DC334 001DC334 21105D00 */  addu       $2, $2, $29
    /* DC338 001DC338 9000428C */  lw         $2, 0x90($2)
    /* DC33C 001DC33C 380002AE */  sw         $2, 0x38($16)
    /* DC340 001DC340 01000224 */  addiu      $2, $0, 0x1
    /* DC344 001DC344 6A0002A6 */  sh         $2, 0x6A($16)
  .L001DC348:
    /* DC348 001DC348 01000224 */  addiu      $2, $0, 0x1
  .L001DC34C:
    /* DC34C 001DC34C 8000BFDF */  ld         $31, 0x80($29)
    /* DC350 001DC350 7000B77B */  lq         $23, 0x70($29)
    /* DC354 001DC354 6000B67B */  lq         $22, 0x60($29)
    /* DC358 001DC358 5000B57B */  lq         $21, 0x50($29)
    /* DC35C 001DC35C 4000B47B */  lq         $20, 0x40($29)
    /* DC360 001DC360 3000B37B */  lq         $19, 0x30($29)
    /* DC364 001DC364 2000B27B */  lq         $18, 0x20($29)
    /* DC368 001DC368 1000B17B */  lq         $17, 0x10($29)
    /* DC36C 001DC36C 0000B07B */  lq         $16, 0x0($29)
    /* DC370 001DC370 F000BD27 */  addiu      $29, $29, 0xF0
    /* DC374 001DC374 0800E003 */  jr         $31
    /* DC378 001DC378 00000000 */   nop
    /* DC37C 001DC37C 00000000 */  nop
.size func_001dbf20, 0x460
