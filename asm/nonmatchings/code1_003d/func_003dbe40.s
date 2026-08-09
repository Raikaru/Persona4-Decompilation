.section .text
.set noat
.set noreorder
glabel func_003dbe40
    /* 2DBE40 003DBE40 20FFBD27 */  addiu      $29, $29, -0xE0
    /* 2DBE44 003DBE44 04000624 */  addiu      $6, $0, 0x4
    /* 2DBE48 003DBE48 9000BFFF */  sd         $31, 0x90($29)
    /* 2DBE4C 003DBE4C DC00A527 */  addiu      $5, $29, 0xDC
    /* 2DBE50 003DBE50 8000BE7F */  sq         $30, 0x80($29)
    /* 2DBE54 003DBE54 7000B77F */  sq         $23, 0x70($29)
    /* 2DBE58 003DBE58 6000B67F */  sq         $22, 0x60($29)
    /* 2DBE5C 003DBE5C 5000B57F */  sq         $21, 0x50($29)
    /* 2DBE60 003DBE60 4000B47F */  sq         $20, 0x40($29)
    /* 2DBE64 003DBE64 2DA88000 */  daddu      $21, $4, $0
    /* 2DBE68 003DBE68 3000B37F */  sq         $19, 0x30($29)
    /* 2DBE6C 003DBE6C 2000B27F */  sq         $18, 0x20($29)
    /* 2DBE70 003DBE70 1000B17F */  sq         $17, 0x10($29)
    /* 2DBE74 003DBE74 0000B07F */  sq         $16, 0x0($29)
    /* 2DBE78 003DBE78 448A0F0C */  jal        func_003e2910
    /* 2DBE7C 003DBE7C B000A0AF */   sw        $0, 0xB0($29)
    /* 2DBE80 003DBE80 04000324 */  addiu      $3, $0, 0x4
    /* 2DBE84 003DBE84 03004310 */  beq        $2, $3, .L003DBE94
    /* 2DBE88 003DBE88 00000000 */   nop
    /* 2DBE8C 003DBE8C 2C010010 */  b          .L003DC340
    /* 2DBE90 003DBE90 2D100000 */   daddu     $2, $0, $0
  .L003DBE94:
    /* 2DBE94 003DBE94 0100023C */  lui        $2, (0x101B3 >> 16)
    /* 2DBE98 003DBE98 DC00A38F */  lw         $3, 0xDC($29)
    /* 2DBE9C 003DBE9C B3014534 */  ori        $5, $2, (0x101B3 & 0xFFFF)
    /* 2DBEA0 003DBEA0 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2DBEA4 003DBEA4 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2DBEA8 003DBEA8 09F84000 */  jalr       $2
    /* 2DBEAC 003DBEAC 80200300 */   sll       $4, $3, 2
    /* 2DBEB0 003DBEB0 2DA04000 */  daddu      $20, $2, $0
    /* 2DBEB4 003DBEB4 29008012 */  beqz       $20, .L003DBF5C
    /* 2DBEB8 003DBEB8 00000000 */   nop
    /* 2DBEBC 003DBEBC DC00A28F */  lw         $2, 0xDC($29)
    /* 2DBEC0 003DBEC0 2A080200 */  slt        $1, $0, $2
    /* 2DBEC4 003DBEC4 1C002010 */  beqz       $1, .L003DBF38
    /* 2DBEC8 003DBEC8 2D880000 */   daddu     $17, $0, $0
    /* 2DBECC 003DBECC 2D808002 */  daddu      $16, $20, $0
  .L003DBED0:
    /* 2DBED0 003DBED0 2D20A002 */  daddu      $4, $21, $0
    /* 2DBED4 003DBED4 18000524 */  addiu      $5, $0, 0x18
    /* 2DBED8 003DBED8 2D300000 */  daddu      $6, $0, $0
    /* 2DBEDC 003DBEDC 147C0F0C */  jal        func_003df050
    /* 2DBEE0 003DBEE0 2D380000 */   daddu     $7, $0, $0
    /* 2DBEE4 003DBEE4 03004014 */  bnez       $2, .L003DBEF4
    /* 2DBEE8 003DBEE8 00000000 */   nop
    /* 2DBEEC 003DBEEC 14010010 */  b          .L003DC340
    /* 2DBEF0 003DBEF0 2D100000 */   daddu     $2, $0, $0
  .L003DBEF4:
    /* 2DBEF4 003DBEF4 FCAE0F0C */  jal        func_003ebbf0
    /* 2DBEF8 003DBEF8 2D20A002 */   daddu     $4, $21, $0
    /* 2DBEFC 003DBEFC 000002AE */  sw         $2, 0x0($16)
    /* 2DBF00 003DBF00 0000048E */  lw         $4, 0x0($16)
    /* 2DBF04 003DBF04 21008010 */  beqz       $4, .L003DBF8C
    /* 2DBF08 003DBF08 00000000 */   nop
    /* 2DBF0C 003DBF0C 0000828C */  lw         $2, 0x0($4)
    /* 2DBF10 003DBF10 02004230 */  andi       $2, $2, 0x2
    /* 2DBF14 003DBF14 1F004010 */  beqz       $2, .L003DBF94
    /* 2DBF18 003DBF18 00000000 */   nop
    /* 2DBF1C 003DBF1C 00000000 */  nop
  .L003DBF20:
    /* 2DBF20 003DBF20 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DBF24 003DBF24 01003126 */  addiu      $17, $17, 0x1
    /* 2DBF28 003DBF28 2A102202 */  slt        $2, $17, $2
    /* 2DBF2C 003DBF2C E8FF4014 */  bnez       $2, .L003DBED0
    /* 2DBF30 003DBF30 04001026 */   addiu     $16, $16, 0x4
    /* 2DBF34 003DBF34 00000000 */  nop
  .L003DBF38:
    /* 2DBF38 003DBF38 2D20A002 */  daddu      $4, $21, $0
    /* 2DBF3C 003DBF3C 06000524 */  addiu      $5, $0, 0x6
    /* 2DBF40 003DBF40 2D300000 */  daddu      $6, $0, $0
    /* 2DBF44 003DBF44 147C0F0C */  jal        func_003df050
    /* 2DBF48 003DBF48 2D380000 */   daddu     $7, $0, $0
    /* 2DBF4C 003DBF4C 16004014 */  bnez       $2, .L003DBFA8
    /* 2DBF50 003DBF50 00000000 */   nop
    /* 2DBF54 003DBF54 FA000010 */  b          .L003DC340
    /* 2DBF58 003DBF58 2D100000 */   daddu     $2, $0, $0
  .L003DBF5C:
    /* 2DBF5C 003DBF5C DC00A38F */  lw         $3, 0xDC($29)
    /* 2DBF60 003DBF60 B3010224 */  addiu      $2, $0, 0x1B3
    /* 2DBF64 003DBF64 C000A2AF */  sw         $2, 0xC0($29)
    /* 2DBF68 003DBF68 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2DBF6C 003DBF6C 13004434 */  ori        $4, $2, (0x80000013 & 0xFFFF)
    /* 2DBF70 003DBF70 647D0F0C */  jal        func_003df590
    /* 2DBF74 003DBF74 80280300 */   sll       $5, $3, 2
    /* 2DBF78 003DBF78 C400A2AF */  sw         $2, 0xC4($29)
    /* 2DBF7C 003DBF7C 347D0F0C */  jal        func_003df4d0
    /* 2DBF80 003DBF80 C000A427 */   addiu     $4, $29, 0xC0
    /* 2DBF84 003DBF84 EE000010 */  b          .L003DC340
    /* 2DBF88 003DBF88 2D100000 */   daddu     $2, $0, $0
  .L003DBF8C:
    /* 2DBF8C 003DBF8C EC000010 */  b          .L003DC340
    /* 2DBF90 003DBF90 2D100000 */   daddu     $2, $0, $0
  .L003DBF94:
    /* 2DBF94 003DBF94 78AF0F0C */  jal        func_003ebde0
    /* 2DBF98 003DBF98 00000000 */   nop
    /* 2DBF9C 003DBF9C E0FF0010 */  b          .L003DBF20
    /* 2DBFA0 003DBFA0 00000000 */   nop
    /* 2DBFA4 003DBFA4 00000000 */  nop
  .L003DBFA8:
    /* 2DBFA8 003DBFA8 F06E0F0C */  jal        func_003dbbc0
    /* 2DBFAC 003DBFAC 2D20A002 */   daddu     $4, $21, $0
    /* 2DBFB0 003DBFB0 9C004010 */  beqz       $2, .L003DC224
    /* 2DBFB4 003DBFB4 A000A2AF */   sw        $2, 0xA0($29)
    /* 2DBFB8 003DBFB8 0000838E */  lw         $3, 0x0($20)
    /* 2DBFBC 003DBFBC 04001024 */  addiu      $16, $0, 0x4
    /* 2DBFC0 003DBFC0 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DBFC4 003DBFC4 0400638C */  lw         $3, 0x4($3)
    /* 2DBFC8 003DBFC8 02004128 */  slti       $1, $2, 0x2
    /* 2DBFCC 003DBFCC D800A3AF */  sw         $3, 0xD8($29)
    /* 2DBFD0 003DBFD0 0000838E */  lw         $3, 0x0($20)
    /* 2DBFD4 003DBFD4 0800638C */  lw         $3, 0x8($3)
    /* 2DBFD8 003DBFD8 D400A3AF */  sw         $3, 0xD4($29)
    /* 2DBFDC 003DBFDC 0000838E */  lw         $3, 0x0($20)
    /* 2DBFE0 003DBFE0 0C00638C */  lw         $3, 0xC($3)
    /* 2DBFE4 003DBFE4 03002014 */  bnez       $1, .L003DBFF4
    /* 2DBFE8 003DBFE8 D000A3AF */   sw        $3, 0xD0($29)
    /* 2DBFEC 003DBFEC 0A000010 */  b          .L003DC018
    /* 2DBFF0 003DBFF0 00801036 */   ori       $16, $16, 0x8000
  .L003DBFF4:
    /* 2DBFF4 003DBFF4 A000A28F */  lw         $2, 0xA0($29)
    /* 2DBFF8 003DBFF8 50004390 */  lbu        $3, 0x50($2)
    /* 2DBFFC 003DBFFC 01000224 */  addiu      $2, $0, 0x1
    /* 2DC000 003DC000 05006210 */  beq        $3, $2, .L003DC018
    /* 2DC004 003DC004 00000000 */   nop
    /* 2DC008 003DC008 02000224 */  addiu      $2, $0, 0x2
    /* 2DC00C 003DC00C 02006210 */  beq        $3, $2, .L003DC018
    /* 2DC010 003DC010 00000000 */   nop
    /* 2DC014 003DC014 00901036 */  ori        $16, $16, 0x9000
  .L003DC018:
    /* 2DC018 003DC018 0000848E */  lw         $4, 0x0($20)
    /* 2DC01C 003DC01C 2D280002 */  daddu      $5, $16, $0
    /* 2DC020 003DC020 D800A627 */  addiu      $6, $29, 0xD8
    /* 2DC024 003DC024 D400A727 */  addiu      $7, $29, 0xD4
    /* 2DC028 003DC028 D000A827 */  addiu      $8, $29, 0xD0
    /* 2DC02C 003DC02C 7CB00F0C */  jal        func_003ec1f0
    /* 2DC030 003DC030 CC00A927 */   addiu     $9, $29, 0xCC
    /* 2DC034 003DC034 CC00A28F */  lw         $2, 0xCC($29)
    /* 2DC038 003DC038 D800A48F */  lw         $4, 0xD8($29)
    /* 2DC03C 003DC03C D400A58F */  lw         $5, 0xD4($29)
    /* 2DC040 003DC040 D000A68F */  lw         $6, 0xD0($29)
    /* 2DC044 003DC044 64B10F0C */  jal        func_003ec590
    /* 2DC048 003DC048 25380202 */   or        $7, $16, $2
    /* 2DC04C 003DC04C 2D984000 */  daddu      $19, $2, $0
    /* 2DC050 003DC050 76006012 */  beqz       $19, .L003DC22C
    /* 2DC054 003DC054 00000000 */   nop
    /* 2DC058 003DC058 0000838E */  lw         $3, 0x0($20)
    /* 2DC05C 003DC05C 0C00728E */  lw         $18, 0xC($19)
    /* 2DC060 003DC060 0400628C */  lw         $2, 0x4($3)
    /* 2DC064 003DC064 05005214 */  bne        $2, $18, .L003DC07C
    /* 2DC068 003DC068 00000000 */   nop
    /* 2DC06C 003DC06C 0800638C */  lw         $3, 0x8($3)
    /* 2DC070 003DC070 1000628E */  lw         $2, 0x10($19)
    /* 2DC074 003DC074 34006210 */  beq        $3, $2, .L003DC148
    /* 2DC078 003DC078 00000000 */   nop
  .L003DC07C:
    /* 2DC07C 003DC07C D000A38F */  lw         $3, 0xD0($29)
    /* 2DC080 003DC080 08000224 */  addiu      $2, $0, 0x8
    /* 2DC084 003DC084 11006214 */  bne        $3, $2, .L003DC0CC
    /* 2DC088 003DC088 1000718E */   lw        $17, 0x10($19)
    /* 2DC08C 003DC08C CCB00F0C */  jal        func_003ec330
    /* 2DC090 003DC090 2D206002 */   daddu     $4, $19, $0
    /* 2DC094 003DC094 00050736 */  ori        $7, $16, 0x500
    /* 2DC098 003DC098 2D204002 */  daddu      $4, $18, $0
    /* 2DC09C 003DC09C 2D282002 */  daddu      $5, $17, $0
    /* 2DC0A0 003DC0A0 64B10F0C */  jal        func_003ec590
    /* 2DC0A4 003DC0A4 20000624 */   addiu     $6, $0, 0x20
    /* 2DC0A8 003DC0A8 2D984000 */  daddu      $19, $2, $0
    /* 2DC0AC 003DC0AC 07006016 */  bnez       $19, .L003DC0CC
    /* 2DC0B0 003DC0B0 00000000 */   nop
    /* 2DC0B4 003DC0B4 00010736 */  ori        $7, $16, 0x100
    /* 2DC0B8 003DC0B8 2D204002 */  daddu      $4, $18, $0
    /* 2DC0BC 003DC0BC 2D282002 */  daddu      $5, $17, $0
    /* 2DC0C0 003DC0C0 64B10F0C */  jal        func_003ec590
    /* 2DC0C4 003DC0C4 10000624 */   addiu     $6, $0, 0x10
    /* 2DC0C8 003DC0C8 2D984000 */  daddu      $19, $2, $0
  .L003DC0CC:
    /* 2DC0CC 003DC0CC 08B10F0C */  jal        func_003ec420
    /* 2DC0D0 003DC0D0 2D206002 */   daddu     $4, $19, $0
    /* 2DC0D4 003DC0D4 2DF04000 */  daddu      $30, $2, $0
    /* 2DC0D8 003DC0D8 2A081E00 */  slt        $1, $0, $30
    /* 2DC0DC 003DC0DC 1A002010 */  beqz       $1, .L003DC148
    /* 2DC0E0 003DC0E0 2DB00000 */   daddu     $22, $0, $0
    /* 2DC0E4 003DC0E4 2D808002 */  daddu      $16, $20, $0
  .L003DC0E8:
    /* 2DC0E8 003DC0E8 0000048E */  lw         $4, 0x0($16)
    /* 2DC0EC 003DC0EC 2D284002 */  daddu      $5, $18, $0
    /* 2DC0F0 003DC0F0 B4B40F0C */  jal        func_003ed2d0
    /* 2DC0F4 003DC0F4 2D302002 */   daddu     $6, $17, $0
    /* 2DC0F8 003DC0F8 2DB84000 */  daddu      $23, $2, $0
    /* 2DC0FC 003DC0FC 0300E016 */  bnez       $23, .L003DC10C
    /* 2DC100 003DC100 00000000 */   nop
    /* 2DC104 003DC104 8E000010 */  b          .L003DC340
    /* 2DC108 003DC108 2D100000 */   daddu     $2, $0, $0
  .L003DC10C:
    /* 2DC10C 003DC10C DCA80F0C */  jal        func_003ea370
    /* 2DC110 003DC110 0000048E */   lw        $4, 0x0($16)
    /* 2DC114 003DC114 0200412A */  slti       $1, $18, 0x2
    /* 2DC118 003DC118 03002014 */  bnez       $1, .L003DC128
    /* 2DC11C 003DC11C 000017AE */   sw        $23, 0x0($16)
    /* 2DC120 003DC120 43901200 */  sra        $18, $18, 1
    /* 2DC124 003DC124 00000000 */  nop
  .L003DC128:
    /* 2DC128 003DC128 0200212A */  slti       $1, $17, 0x2
    /* 2DC12C 003DC12C 02002014 */  bnez       $1, .L003DC138
    /* 2DC130 003DC130 00000000 */   nop
    /* 2DC134 003DC134 43881100 */  sra        $17, $17, 1
  .L003DC138:
    /* 2DC138 003DC138 0100D626 */  addiu      $22, $22, 0x1
    /* 2DC13C 003DC13C 2A10DE02 */  slt        $2, $22, $30
    /* 2DC140 003DC140 E9FF4014 */  bnez       $2, .L003DC0E8
    /* 2DC144 003DC144 04001026 */   addiu     $16, $16, 0x4
  .L003DC148:
    /* 2DC148 003DC148 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DC14C 003DC14C 02004128 */  slti       $1, $2, 0x2
    /* 2DC150 003DC150 49002010 */  beqz       $1, .L003DC278
    /* 2DC154 003DC154 00000000 */   nop
  .L003DC158:
    /* 2DC158 003DC158 08B10F0C */  jal        func_003ec420
    /* 2DC15C 003DC15C 2D206002 */   daddu     $4, $19, $0
    /* 2DC160 003DC160 2D804000 */  daddu      $16, $2, $0
    /* 2DC164 003DC164 2A081000 */  slt        $1, $0, $16
    /* 2DC168 003DC168 1B002010 */  beqz       $1, .L003DC1D8
    /* 2DC16C 003DC16C 2D880000 */   daddu     $17, $0, $0
    /* 2DC170 003DC170 2D908002 */  daddu      $18, $20, $0
  .L003DC174:
    /* 2DC174 003DC174 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DC178 003DC178 17002212 */  beq        $17, $2, .L003DC1D8
    /* 2DC17C 003DC17C 00000000 */   nop
    /* 2DC180 003DC180 FF002532 */  andi       $5, $17, 0xFF
    /* 2DC184 003DC184 2D206002 */  daddu      $4, $19, $0
    /* 2DC188 003DC188 A8B10F0C */  jal        func_003ec6a0
    /* 2DC18C 003DC18C 01000624 */   addiu     $6, $0, 0x1
    /* 2DC190 003DC190 41004010 */  beqz       $2, .L003DC298
    /* 2DC194 003DC194 00000000 */   nop
    /* 2DC198 003DC198 0000458E */  lw         $5, 0x0($18)
    /* 2DC19C 003DC19C 60B00F0C */  jal        func_003ec180
    /* 2DC1A0 003DC1A0 2D206002 */   daddu     $4, $19, $0
    /* 2DC1A4 003DC1A4 3E004010 */  beqz       $2, .L003DC2A0
    /* 2DC1A8 003DC1A8 00000000 */   nop
    /* 2DC1AC 003DC1AC A8B00F0C */  jal        func_003ec2a0
    /* 2DC1B0 003DC1B0 2D206002 */   daddu     $4, $19, $0
    /* 2DC1B4 003DC1B4 3C004010 */  beqz       $2, .L003DC2A8
    /* 2DC1B8 003DC1B8 00000000 */   nop
    /* 2DC1BC 003DC1BC DCA80F0C */  jal        func_003ea370
    /* 2DC1C0 003DC1C0 0000448E */   lw        $4, 0x0($18)
    /* 2DC1C4 003DC1C4 01003126 */  addiu      $17, $17, 0x1
    /* 2DC1C8 003DC1C8 2A103002 */  slt        $2, $17, $16
    /* 2DC1CC 003DC1CC E9FF4014 */  bnez       $2, .L003DC174
    /* 2DC1D0 003DC1D0 04005226 */   addiu     $18, $18, 0x4
    /* 2DC1D4 003DC1D4 00000000 */  nop
  .L003DC1D8:
    /* 2DC1D8 003DC1D8 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DC1DC 003DC1DC 02004128 */  slti       $1, $2, 0x2
    /* 2DC1E0 003DC1E0 33002010 */  beqz       $1, .L003DC2B0
    /* 2DC1E4 003DC1E4 00000000 */   nop
  .L003DC1E8:
    /* 2DC1E8 003DC1E8 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DC1EC 003DC1EC 2A082202 */  slt        $1, $17, $2
    /* 2DC1F0 003DC1F0 35002010 */  beqz       $1, .L003DC2C8
    /* 2DC1F4 003DC1F4 00000000 */   nop
    /* 2DC1F8 003DC1F8 80101100 */  sll        $2, $17, 2
    /* 2DC1FC 003DC1FC 21808202 */  addu       $16, $20, $2
  .L003DC200:
    /* 2DC200 003DC200 DCA80F0C */  jal        func_003ea370
    /* 2DC204 003DC204 0000048E */   lw        $4, 0x0($16)
    /* 2DC208 003DC208 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DC20C 003DC20C 01003126 */  addiu      $17, $17, 0x1
    /* 2DC210 003DC210 2A102202 */  slt        $2, $17, $2
    /* 2DC214 003DC214 FAFF4014 */  bnez       $2, .L003DC200
    /* 2DC218 003DC218 04001026 */   addiu     $16, $16, 0x4
    /* 2DC21C 003DC21C 2A000010 */  b          .L003DC2C8
    /* 2DC220 003DC220 00000000 */   nop
  .L003DC224:
    /* 2DC224 003DC224 46000010 */  b          .L003DC340
    /* 2DC228 003DC228 2D100000 */   daddu     $2, $0, $0
  .L003DC22C:
    /* 2DC22C 003DC22C DC00A28F */  lw         $2, 0xDC($29)
    /* 2DC230 003DC230 2A080200 */  slt        $1, $0, $2
    /* 2DC234 003DC234 0A002010 */  beqz       $1, .L003DC260
    /* 2DC238 003DC238 2D800000 */   daddu     $16, $0, $0
    /* 2DC23C 003DC23C 2D888002 */  daddu      $17, $20, $0
  .L003DC240:
    /* 2DC240 003DC240 DCA80F0C */  jal        func_003ea370
    /* 2DC244 003DC244 0000248E */   lw        $4, 0x0($17)
    /* 2DC248 003DC248 DC00A28F */  lw         $2, 0xDC($29)
    /* 2DC24C 003DC24C 01001026 */  addiu      $16, $16, 0x1
    /* 2DC250 003DC250 2A100202 */  slt        $2, $16, $2
    /* 2DC254 003DC254 FAFF4014 */  bnez       $2, .L003DC240
    /* 2DC258 003DC258 04003126 */   addiu     $17, $17, 0x4
    /* 2DC25C 003DC25C 00000000 */  nop
  .L003DC260:
    /* 2DC260 003DC260 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2DC264 003DC264 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2DC268 003DC268 09F84000 */  jalr       $2
    /* 2DC26C 003DC26C 2D208002 */   daddu     $4, $20, $0
    /* 2DC270 003DC270 33000010 */  b          .L003DC340
    /* 2DC274 003DC274 2D100000 */   daddu     $2, $0, $0
  .L003DC278:
    /* 2DC278 003DC278 23006392 */  lbu        $3, 0x23($19)
    /* 2DC27C 003DC27C 10006230 */  andi       $2, $3, 0x10
    /* 2DC280 003DC280 B000A2AF */  sw         $2, 0xB0($29)
    /* 2DC284 003DC284 27104000 */  not        $2, $2
    /* 2DC288 003DC288 FF004230 */  andi       $2, $2, 0xFF
    /* 2DC28C 003DC28C 24106200 */  and        $2, $3, $2
    /* 2DC290 003DC290 B1FF0010 */  b          .L003DC158
    /* 2DC294 003DC294 230062A2 */   sb        $2, 0x23($19)
  .L003DC298:
    /* 2DC298 003DC298 29000010 */  b          .L003DC340
    /* 2DC29C 003DC29C 2D100000 */   daddu     $2, $0, $0
  .L003DC2A0:
    /* 2DC2A0 003DC2A0 27000010 */  b          .L003DC340
    /* 2DC2A4 003DC2A4 2D100000 */   daddu     $2, $0, $0
  .L003DC2A8:
    /* 2DC2A8 003DC2A8 25000010 */  b          .L003DC340
    /* 2DC2AC 003DC2AC 2D100000 */   daddu     $2, $0, $0
  .L003DC2B0:
    /* 2DC2B0 003DC2B0 B000A293 */  lbu        $2, 0xB0($29)
    /* 2DC2B4 003DC2B4 2D184000 */  daddu      $3, $2, $0
    /* 2DC2B8 003DC2B8 23006292 */  lbu        $2, 0x23($19)
    /* 2DC2BC 003DC2BC 25104300 */  or         $2, $2, $3
    /* 2DC2C0 003DC2C0 C9FF0010 */  b          .L003DC1E8
    /* 2DC2C4 003DC2C4 230062A2 */   sb        $2, 0x23($19)
  .L003DC2C8:
    /* 2DC2C8 003DC2C8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2DC2CC 003DC2CC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2DC2D0 003DC2D0 09F84000 */  jalr       $2
    /* 2DC2D4 003DC2D4 2D208002 */   daddu     $4, $20, $0
    /* 2DC2D8 003DC2D8 A000A48F */  lw         $4, 0xA0($29)
    /* 2DC2DC 003DC2DC 20BC0F0C */  jal        func_003ef080
    /* 2DC2E0 003DC2E0 2D286002 */   daddu     $5, $19, $0
    /* 2DC2E4 003DC2E4 A000A68F */  lw         $6, 0xA0($29)
    /* 2DC2E8 003DC2E8 7100043C */  lui        $4, %hi(D_0070B800)
    /* 2DC2EC 003DC2EC 2D28A002 */  daddu      $5, $21, $0
    /* 2DC2F0 003DC2F0 448C0F0C */  jal        func_003e3110
    /* 2DC2F4 003DC2F4 00B88424 */   addiu     $4, $4, %lo(D_0070B800)
    /* 2DC2F8 003DC2F8 07004014 */  bnez       $2, .L003DC318
    /* 2DC2FC 003DC2FC 00000000 */   nop
    /* 2DC300 003DC300 A000A0AF */  sw         $0, 0xA0($29)
  .L003DC304:
    /* 2DC304 003DC304 A000A28F */  lw         $2, 0xA0($29)
  .L003DC308:
    /* 2DC308 003DC308 0C004010 */  beqz       $2, .L003DC33C
    /* 2DC30C 003DC30C 00000000 */   nop
    /* 2DC310 003DC310 0B000010 */  b          .L003DC340
    /* 2DC314 003DC314 01000224 */   addiu     $2, $0, 0x1
  .L003DC318:
    /* 2DC318 003DC318 B4BD0F0C */  jal        func_003ef6d0
    /* 2DC31C 003DC31C 00000000 */   nop
    /* 2DC320 003DC320 F8FF4010 */  beqz       $2, .L003DC304
    /* 2DC324 003DC324 00000000 */   nop
    /* 2DC328 003DC328 A000A58F */  lw         $5, 0xA0($29)
    /* 2DC32C 003DC32C 6CBD0F0C */  jal        func_003ef5b0
    /* 2DC330 003DC330 2D204000 */   daddu     $4, $2, $0
    /* 2DC334 003DC334 F4FF0010 */  b          .L003DC308
    /* 2DC338 003DC338 A000A28F */   lw        $2, 0xA0($29)
  .L003DC33C:
    /* 2DC33C 003DC33C 2D100000 */  daddu      $2, $0, $0
  .L003DC340:
    /* 2DC340 003DC340 9000BFDF */  ld         $31, 0x90($29)
    /* 2DC344 003DC344 8000BE7B */  lq         $30, 0x80($29)
    /* 2DC348 003DC348 7000B77B */  lq         $23, 0x70($29)
    /* 2DC34C 003DC34C 6000B67B */  lq         $22, 0x60($29)
    /* 2DC350 003DC350 5000B57B */  lq         $21, 0x50($29)
    /* 2DC354 003DC354 4000B47B */  lq         $20, 0x40($29)
    /* 2DC358 003DC358 3000B37B */  lq         $19, 0x30($29)
    /* 2DC35C 003DC35C 2000B27B */  lq         $18, 0x20($29)
    /* 2DC360 003DC360 1000B17B */  lq         $17, 0x10($29)
    /* 2DC364 003DC364 0000B07B */  lq         $16, 0x0($29)
    /* 2DC368 003DC368 0800E003 */  jr         $31
    /* 2DC36C 003DC36C E000BD27 */   addiu     $29, $29, 0xE0
.size func_003dbe40, 0x530
