.section .text
.set noat
.set noreorder
glabel func_001bcd40
    /* BCD40 001BCD40 90FEBD27 */  addiu      $29, $29, -0x170
    /* BCD44 001BCD44 A000BFFF */  sd         $31, 0xA0($29)
    /* BCD48 001BCD48 9000BE7F */  sq         $30, 0x90($29)
    /* BCD4C 001BCD4C 8000B77F */  sq         $23, 0x80($29)
    /* BCD50 001BCD50 7000B67F */  sq         $22, 0x70($29)
    /* BCD54 001BCD54 6000B57F */  sq         $21, 0x60($29)
    /* BCD58 001BCD58 5000B47F */  sq         $20, 0x50($29)
    /* BCD5C 001BCD5C 4000B37F */  sq         $19, 0x40($29)
    /* BCD60 001BCD60 3000B27F */  sq         $18, 0x30($29)
    /* BCD64 001BCD64 2000B17F */  sq         $17, 0x20($29)
    /* BCD68 001BCD68 1000B07F */  sq         $16, 0x10($29)
    /* BCD6C 001BCD6C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BCD70 001BCD70 2DA08000 */  daddu      $20, $4, $0
    /* BCD74 001BCD74 2D98A000 */  daddu      $19, $5, $0
    /* BCD78 001BCD78 2DA8C000 */  daddu      $21, $6, $0
    /* BCD7C 001BCD7C 06650046 */  mov.s      $f20, $f12
    /* BCD80 001BCD80 ACB3838F */  lw         $3, -0x4C54($28)
    /* BCD84 001BCD84 1000648C */  lw         $4, 0x10($3)
    /* BCD88 001BCD88 04008430 */  andi       $4, $4, 0x4
    /* BCD8C 001BCD8C 4E018014 */  bnez       $4, .L001BD2C8
    /* BCD90 001BCD90 00000000 */   nop
    /* BCD94 001BCD94 0D006012 */  beqz       $19, .L001BCDCC
    /* BCD98 001BCD98 00000000 */   nop
    /* BCD9C 001BCD9C 0B00A012 */  beqz       $21, .L001BCDCC
    /* BCDA0 001BCDA0 00000000 */   nop
    /* BCDA4 001BCDA4 000060C6 */  lwc1       $f0, 0x0($19)
    /* BCDA8 001BCDA8 4001A0E7 */  swc1       $f0, 0x140($29)
    /* BCDAC 001BCDAC 080060C6 */  lwc1       $f0, 0x8($19)
    /* BCDB0 001BCDB0 4401A0E7 */  swc1       $f0, 0x144($29)
    /* BCDB4 001BCDB4 0000A0C6 */  lwc1       $f0, 0x0($21)
    /* BCDB8 001BCDB8 4801A0E7 */  swc1       $f0, 0x148($29)
    /* BCDBC 001BCDBC 0800A0C6 */  lwc1       $f0, 0x8($21)
    /* BCDC0 001BCDC0 4C01A0E7 */  swc1       $f0, 0x14C($29)
    /* BCDC4 001BCDC4 02000010 */  b          .L001BCDD0
    /* BCDC8 001BCDC8 00000000 */   nop
  .L001BCDCC:
    /* BCDCC 001BCDCC 00A08044 */  mtc1       $0, $f20
  .L001BCDD0:
    /* BCDD0 001BCDD0 2D200000 */  daddu      $4, $0, $0
    /* BCDD4 001BCDD4 FFFFE530 */  andi       $5, $7, 0xFFFF
    /* BCDD8 001BCDD8 1000A530 */  andi       $5, $5, 0x10
    /* BCDDC 001BCDDC 1600A010 */  beqz       $5, .L001BCE38
    /* BCDE0 001BCDE0 00000000 */   nop
    /* BCDE4 001BCDE4 2D480000 */  daddu      $9, $0, $0
    /* BCDE8 001BCDE8 6A008896 */  lhu        $8, 0x6A($20)
    /* BCDEC 001BCDEC 01000624 */  addiu      $6, $0, 0x1
    /* BCDF0 001BCDF0 0D000010 */  b          .L001BCE28
    /* BCDF4 001BCDF4 00000000 */   nop
  .L001BCDF8:
    /* BCDF8 001BCDF8 FFFF2531 */  andi       $5, $9, 0xFFFF
    /* BCDFC 001BCDFC 80280500 */  sll        $5, $5, 2
    /* BCE00 001BCE00 21288502 */  addu       $5, $20, $5
    /* BCE04 001BCE04 3800A58C */  lw         $5, 0x38($5)
    /* BCE08 001BCE08 3000A58C */  lw         $5, 0x30($5)
    /* BCE0C 001BCE0C A200A590 */  lbu        $5, 0xA2($5)
    /* BCE10 001BCE10 0428A600 */  sllv       $5, $6, $5
    /* BCE14 001BCE14 FFFFA530 */  andi       $5, $5, 0xFFFF
    /* BCE18 001BCE18 25208500 */  or         $4, $4, $5
    /* BCE1C 001BCE1C FFFF8430 */  andi       $4, $4, 0xFFFF
    /* BCE20 001BCE20 01002525 */  addiu      $5, $9, 0x1
    /* BCE24 001BCE24 FFFFA930 */  andi       $9, $5, 0xFFFF
  .L001BCE28:
    /* BCE28 001BCE28 FFFF2531 */  andi       $5, $9, 0xFFFF
    /* BCE2C 001BCE2C 2A28A800 */  slt        $5, $5, $8
    /* BCE30 001BCE30 F1FFA014 */  bnez       $5, .L001BCDF8
    /* BCE34 001BCE34 00000000 */   nop
  .L001BCE38:
    /* BCE38 001BCE38 7401728C */  lw         $18, 0x174($3)
    /* BCE3C 001BCE3C FFFFE530 */  andi       $5, $7, 0xFFFF
    /* BCE40 001BCE40 2000B730 */  andi       $23, $5, 0x20
    /* BCE44 001BCE44 4000B030 */  andi       $16, $5, 0x40
    /* BCE48 001BCE48 0001BE30 */  andi       $30, $5, 0x100
    /* BCE4C 001BCE4C 0004A330 */  andi       $3, $5, 0x400
    /* BCE50 001BCE50 3001A37F */  sq         $3, 0x130($29)
    /* BCE54 001BCE54 0400A330 */  andi       $3, $5, 0x4
    /* BCE58 001BCE58 2001A37F */  sq         $3, 0x120($29)
    /* BCE5C 001BCE5C 0100A330 */  andi       $3, $5, 0x1
    /* BCE60 001BCE60 1001A37F */  sq         $3, 0x110($29)
    /* BCE64 001BCE64 FFFF8330 */  andi       $3, $4, 0xFFFF
    /* BCE68 001BCE68 0001A37F */  sq         $3, 0x100($29)
    /* BCE6C 001BCE6C 0008A330 */  andi       $3, $5, 0x800
    /* BCE70 001BCE70 F000A37F */  sq         $3, 0xF0($29)
    /* BCE74 001BCE74 0200A330 */  andi       $3, $5, 0x2
    /* BCE78 001BCE78 E000A37F */  sq         $3, 0xE0($29)
    /* BCE7C 001BCE7C 0800A330 */  andi       $3, $5, 0x8
    /* BCE80 001BCE80 D000A37F */  sq         $3, 0xD0($29)
    /* BCE84 001BCE84 8000A330 */  andi       $3, $5, 0x80
    /* BCE88 001BCE88 C000A37F */  sq         $3, 0xC0($29)
    /* BCE8C 001BCE8C 0002A330 */  andi       $3, $5, 0x200
    /* BCE90 001BCE90 B000A37F */  sq         $3, 0xB0($29)
    /* BCE94 001BCE94 0A010010 */  b          .L001BD2C0
    /* BCE98 001BCE98 00000000 */   nop
  .L001BCE9C:
    /* BCE9C 001BCE9C 1A004396 */  lhu        $3, 0x1A($18)
    /* BCEA0 001BCEA0 01006330 */  andi       $3, $3, 0x1
    /* BCEA4 001BCEA4 05016010 */  beqz       $3, .L001BD2BC
    /* BCEA8 001BCEA8 00000000 */   nop
    /* BCEAC 001BCEAC 3000518E */  lw         $17, 0x30($18)
    /* BCEB0 001BCEB0 9C00238E */  lw         $3, 0x9C($17)
    /* BCEB4 001BCEB4 08006330 */  andi       $3, $3, 0x8
    /* BCEB8 001BCEB8 00016010 */  beqz       $3, .L001BD2BC
    /* BCEBC 001BCEBC 00000000 */   nop
    /* BCEC0 001BCEC0 1100E012 */  beqz       $23, .L001BCF08
    /* BCEC4 001BCEC4 00000000 */   nop
    /* BCEC8 001BCEC8 0F005412 */  beq        $18, $20, .L001BCF08
    /* BCECC 001BCECC 00000000 */   nop
    /* BCED0 001BCED0 2D202002 */  daddu      $4, $17, $0
    /* BCED4 001BCED4 02000524 */  addiu      $5, $0, 0x2
    /* BCED8 001BCED8 F053060C */  jal        func_00194fc0
    /* BCEDC 001BCEDC 00000000 */   nop
    /* BCEE0 001BCEE0 2D202002 */  daddu      $4, $17, $0
    /* BCEE4 001BCEE4 04000524 */  addiu      $5, $0, 0x4
    /* BCEE8 001BCEE8 E853060C */  jal        func_00194fa0
    /* BCEEC 001BCEEC 00000000 */   nop
    /* BCEF0 001BCEF0 F2000016 */  bnez       $16, .L001BD2BC
    /* BCEF4 001BCEF4 00000000 */   nop
    /* BCEF8 001BCEF8 FF000324 */  addiu      $3, $0, 0xFF
    /* BCEFC 001BCEFC 370023A2 */  sb         $3, 0x37($17)
    /* BCF00 001BCF00 EE000010 */  b          .L001BD2BC
    /* BCF04 001BCF04 00000000 */   nop
  .L001BCF08:
    /* BCF08 001BCF08 1200C013 */  beqz       $30, .L001BCF54
    /* BCF0C 001BCF0C 00000000 */   nop
    /* BCF10 001BCF10 2D202002 */  daddu      $4, $17, $0
    /* BCF14 001BCF14 02000524 */  addiu      $5, $0, 0x2
    /* BCF18 001BCF18 F053060C */  jal        func_00194fc0
    /* BCF1C 001BCF1C 00000000 */   nop
    /* BCF20 001BCF20 3001A37B */  lq         $3, 0x130($29)
    /* BCF24 001BCF24 05006010 */  beqz       $3, .L001BCF3C
    /* BCF28 001BCF28 00000000 */   nop
    /* BCF2C 001BCF2C 2D202002 */  daddu      $4, $17, $0
    /* BCF30 001BCF30 04000524 */  addiu      $5, $0, 0x4
    /* BCF34 001BCF34 E853060C */  jal        func_00194fa0
    /* BCF38 001BCF38 00000000 */   nop
  .L001BCF3C:
    /* BCF3C 001BCF3C DF000016 */  bnez       $16, .L001BD2BC
    /* BCF40 001BCF40 00000000 */   nop
    /* BCF44 001BCF44 FF000324 */  addiu      $3, $0, 0xFF
    /* BCF48 001BCF48 370023A2 */  sb         $3, 0x37($17)
    /* BCF4C 001BCF4C DB000010 */  b          .L001BD2BC
    /* BCF50 001BCF50 00000000 */   nop
  .L001BCF54:
    /* BCF54 001BCF54 ACB3838F */  lw         $3, -0x4C54($28)
    /* BCF58 001BCF58 7001638C */  lw         $3, 0x170($3)
    /* BCF5C 001BCF5C 12004316 */  bne        $18, $3, .L001BCFA8
    /* BCF60 001BCF60 00000000 */   nop
    /* BCF64 001BCF64 2001A37B */  lq         $3, 0x120($29)
    /* BCF68 001BCF68 0F006010 */  beqz       $3, .L001BCFA8
    /* BCF6C 001BCF6C 00000000 */   nop
    /* BCF70 001BCF70 2D202002 */  daddu      $4, $17, $0
    /* BCF74 001BCF74 02000524 */  addiu      $5, $0, 0x2
    /* BCF78 001BCF78 F053060C */  jal        func_00194fc0
    /* BCF7C 001BCF7C 00000000 */   nop
    /* BCF80 001BCF80 2D202002 */  daddu      $4, $17, $0
    /* BCF84 001BCF84 04000524 */  addiu      $5, $0, 0x4
    /* BCF88 001BCF88 E853060C */  jal        func_00194fa0
    /* BCF8C 001BCF8C 00000000 */   nop
    /* BCF90 001BCF90 CA000016 */  bnez       $16, .L001BD2BC
    /* BCF94 001BCF94 00000000 */   nop
    /* BCF98 001BCF98 FF000324 */  addiu      $3, $0, 0xFF
    /* BCF9C 001BCF9C 370023A2 */  sb         $3, 0x37($17)
    /* BCFA0 001BCFA0 C6000010 */  b          .L001BD2BC
    /* BCFA4 001BCFA4 00000000 */   nop
  .L001BCFA8:
    /* BCFA8 001BCFA8 77008012 */  beqz       $20, .L001BD188
    /* BCFAC 001BCFAC 00000000 */   nop
    /* BCFB0 001BCFB0 12005416 */  bne        $18, $20, .L001BCFFC
    /* BCFB4 001BCFB4 00000000 */   nop
    /* BCFB8 001BCFB8 1001A37B */  lq         $3, 0x110($29)
    /* BCFBC 001BCFBC 0F006010 */  beqz       $3, .L001BCFFC
    /* BCFC0 001BCFC0 00000000 */   nop
    /* BCFC4 001BCFC4 2D202002 */  daddu      $4, $17, $0
    /* BCFC8 001BCFC8 02000524 */  addiu      $5, $0, 0x2
    /* BCFCC 001BCFCC F053060C */  jal        func_00194fc0
    /* BCFD0 001BCFD0 00000000 */   nop
    /* BCFD4 001BCFD4 2D202002 */  daddu      $4, $17, $0
    /* BCFD8 001BCFD8 04000524 */  addiu      $5, $0, 0x4
    /* BCFDC 001BCFDC E853060C */  jal        func_00194fa0
    /* BCFE0 001BCFE0 00000000 */   nop
    /* BCFE4 001BCFE4 B5000016 */  bnez       $16, .L001BD2BC
    /* BCFE8 001BCFE8 00000000 */   nop
    /* BCFEC 001BCFEC FF000324 */  addiu      $3, $0, 0xFF
    /* BCFF0 001BCFF0 370023A2 */  sb         $3, 0x37($17)
    /* BCFF4 001BCFF4 B1000010 */  b          .L001BD2BC
    /* BCFF8 001BCFF8 00000000 */   nop
  .L001BCFFC:
    /* BCFFC 001BCFFC A2002492 */  lbu        $4, 0xA2($17)
    /* BD000 001BD000 01000324 */  addiu      $3, $0, 0x1
    /* BD004 001BD004 04208300 */  sllv       $4, $3, $4
    /* BD008 001BD008 0001A37B */  lq         $3, 0x100($29)
    /* BD00C 001BD00C 24186400 */  and        $3, $3, $4
    /* BD010 001BD010 0F006010 */  beqz       $3, .L001BD050
    /* BD014 001BD014 00000000 */   nop
    /* BD018 001BD018 2D202002 */  daddu      $4, $17, $0
    /* BD01C 001BD01C 02000524 */  addiu      $5, $0, 0x2
    /* BD020 001BD020 F053060C */  jal        func_00194fc0
    /* BD024 001BD024 00000000 */   nop
    /* BD028 001BD028 2D202002 */  daddu      $4, $17, $0
    /* BD02C 001BD02C 04000524 */  addiu      $5, $0, 0x4
    /* BD030 001BD030 E853060C */  jal        func_00194fa0
    /* BD034 001BD034 00000000 */   nop
    /* BD038 001BD038 A0000016 */  bnez       $16, .L001BD2BC
    /* BD03C 001BD03C 00000000 */   nop
    /* BD040 001BD040 FF000324 */  addiu      $3, $0, 0xFF
    /* BD044 001BD044 370023A2 */  sb         $3, 0x37($17)
    /* BD048 001BD048 9C000010 */  b          .L001BD2BC
    /* BD04C 001BD04C 00000000 */   nop
  .L001BD050:
    /* BD050 001BD050 F000A37B */  lq         $3, 0xF0($29)
    /* BD054 001BD054 13006010 */  beqz       $3, .L001BD0A4
    /* BD058 001BD058 00000000 */   nop
    /* BD05C 001BD05C 58C5060C */  jal        func_001b1560
    /* BD060 001BD060 00000000 */   nop
    /* BD064 001BD064 0F004216 */  bne        $18, $2, .L001BD0A4
    /* BD068 001BD068 00000000 */   nop
    /* BD06C 001BD06C 2D202002 */  daddu      $4, $17, $0
    /* BD070 001BD070 02000524 */  addiu      $5, $0, 0x2
    /* BD074 001BD074 F053060C */  jal        func_00194fc0
    /* BD078 001BD078 00000000 */   nop
    /* BD07C 001BD07C 2D202002 */  daddu      $4, $17, $0
    /* BD080 001BD080 04000524 */  addiu      $5, $0, 0x4
    /* BD084 001BD084 E853060C */  jal        func_00194fa0
    /* BD088 001BD088 00000000 */   nop
    /* BD08C 001BD08C 8B000016 */  bnez       $16, .L001BD2BC
    /* BD090 001BD090 00000000 */   nop
    /* BD094 001BD094 FF000324 */  addiu      $3, $0, 0xFF
    /* BD098 001BD098 370023A2 */  sb         $3, 0x37($17)
    /* BD09C 001BD09C 87000010 */  b          .L001BD2BC
    /* BD0A0 001BD0A0 00000000 */   nop
  .L001BD0A4:
    /* BD0A4 001BD0A4 E000A37B */  lq         $3, 0xE0($29)
    /* BD0A8 001BD0A8 25006010 */  beqz       $3, .L001BD140
    /* BD0AC 001BD0AC 00000000 */   nop
    /* BD0B0 001BD0B0 2D280000 */  daddu      $5, $0, $0
    /* BD0B4 001BD0B4 6A008496 */  lhu        $4, 0x6A($20)
    /* BD0B8 001BD0B8 17000010 */  b          .L001BD118
    /* BD0BC 001BD0BC 00000000 */   nop
  .L001BD0C0:
    /* BD0C0 001BD0C0 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* BD0C4 001BD0C4 80180300 */  sll        $3, $3, 2
    /* BD0C8 001BD0C8 21188302 */  addu       $3, $20, $3
    /* BD0CC 001BD0CC 3800638C */  lw         $3, 0x38($3)
    /* BD0D0 001BD0D0 0F004316 */  bne        $18, $3, .L001BD110
    /* BD0D4 001BD0D4 00000000 */   nop
    /* BD0D8 001BD0D8 2D202002 */  daddu      $4, $17, $0
    /* BD0DC 001BD0DC 02000524 */  addiu      $5, $0, 0x2
    /* BD0E0 001BD0E0 F053060C */  jal        func_00194fc0
    /* BD0E4 001BD0E4 00000000 */   nop
    /* BD0E8 001BD0E8 2D202002 */  daddu      $4, $17, $0
    /* BD0EC 001BD0EC 04000524 */  addiu      $5, $0, 0x4
    /* BD0F0 001BD0F0 E853060C */  jal        func_00194fa0
    /* BD0F4 001BD0F4 00000000 */   nop
    /* BD0F8 001BD0F8 0B000016 */  bnez       $16, .L001BD128
    /* BD0FC 001BD0FC 00000000 */   nop
    /* BD100 001BD100 FF000324 */  addiu      $3, $0, 0xFF
    /* BD104 001BD104 370023A2 */  sb         $3, 0x37($17)
    /* BD108 001BD108 07000010 */  b          .L001BD128
    /* BD10C 001BD10C 00000000 */   nop
  .L001BD110:
    /* BD110 001BD110 0100A324 */  addiu      $3, $5, 0x1
    /* BD114 001BD114 FFFF6530 */  andi       $5, $3, 0xFFFF
  .L001BD118:
    /* BD118 001BD118 FFFFB630 */  andi       $22, $5, 0xFFFF
    /* BD11C 001BD11C 2A18C402 */  slt        $3, $22, $4
    /* BD120 001BD120 E7FF6014 */  bnez       $3, .L001BD0C0
    /* BD124 001BD124 00000000 */   nop
  .L001BD128:
    /* BD128 001BD128 6A008396 */  lhu        $3, 0x6A($20)
    /* BD12C 001BD12C 6300C316 */  bne        $22, $3, .L001BD2BC
    /* BD130 001BD130 00000000 */   nop
    /* BD134 001BD134 8800838E */  lw         $3, 0x88($20)
    /* BD138 001BD138 60004312 */  beq        $18, $3, .L001BD2BC
    /* BD13C 001BD13C 00000000 */   nop
  .L001BD140:
    /* BD140 001BD140 A2002492 */  lbu        $4, 0xA2($17)
    /* BD144 001BD144 3000838E */  lw         $3, 0x30($20)
    /* BD148 001BD148 A2006390 */  lbu        $3, 0xA2($3)
    /* BD14C 001BD14C 0E008314 */  bne        $4, $3, .L001BD188
    /* BD150 001BD150 00000000 */   nop
    /* BD154 001BD154 D000A37B */  lq         $3, 0xD0($29)
    /* BD158 001BD158 0B006010 */  beqz       $3, .L001BD188
    /* BD15C 001BD15C 00000000 */   nop
    /* BD160 001BD160 2D202002 */  daddu      $4, $17, $0
    /* BD164 001BD164 02000524 */  addiu      $5, $0, 0x2
    /* BD168 001BD168 F053060C */  jal        func_00194fc0
    /* BD16C 001BD16C 00000000 */   nop
    /* BD170 001BD170 52000016 */  bnez       $16, .L001BD2BC
    /* BD174 001BD174 00000000 */   nop
    /* BD178 001BD178 FF000324 */  addiu      $3, $0, 0xFF
    /* BD17C 001BD17C 370023A2 */  sb         $3, 0x37($17)
    /* BD180 001BD180 4E000010 */  b          .L001BD2BC
    /* BD184 001BD184 00000000 */   nop
  .L001BD188:
    /* BD188 001BD188 39006012 */  beqz       $19, .L001BD270
    /* BD18C 001BD18C 00000000 */   nop
    /* BD190 001BD190 3700A012 */  beqz       $21, .L001BD270
    /* BD194 001BD194 00000000 */   nop
    /* BD198 001BD198 2D202002 */  daddu      $4, $17, $0
    /* BD19C 001BD19C 6001A527 */  addiu      $5, $29, 0x160
    /* BD1A0 001BD1A0 1456060C */  jal        func_00195850
    /* BD1A4 001BD1A4 00000000 */   nop
    /* BD1A8 001BD1A8 6001A0C7 */  lwc1       $f0, 0x160($29)
    /* BD1AC 001BD1AC 5001A0E7 */  swc1       $f0, 0x150($29)
    /* BD1B0 001BD1B0 6801A0C7 */  lwc1       $f0, 0x168($29)
    /* BD1B4 001BD1B4 5401A0E7 */  swc1       $f0, 0x154($29)
    /* BD1B8 001BD1B8 4001A427 */  addiu      $4, $29, 0x140
    /* BD1BC 001BD1BC 4801A527 */  addiu      $5, $29, 0x148
    /* BD1C0 001BD1C0 5001A627 */  addiu      $6, $29, 0x150
    /* BD1C4 001BD1C4 5801A727 */  addiu      $7, $29, 0x158
    /* BD1C8 001BD1C8 F4B0070C */  jal        func_001ec3d0
    /* BD1CC 001BD1CC 00000000 */   nop
    /* BD1D0 001BD1D0 900023C6 */  lwc1       $f3, 0x90($17)
    /* BD1D4 001BD1D4 2C0022C6 */  lwc1       $f2, 0x2C($17)
    /* BD1D8 001BD1D8 00088044 */  mtc1       $0, $f1
    /* BD1DC 001BD1DC 00000000 */  nop
    /* BD1E0 001BD1E0 18080046 */  adda.s     $f1, $f0
    /* BD1E4 001BD1E4 DD180246 */  msub.s     $f3, $f3, $f2
    /* BD1E8 001BD1E8 5801A2C7 */  lwc1       $f2, 0x158($29)
    /* BD1EC 001BD1EC 4001A1C7 */  lwc1       $f1, 0x140($29)
    /* BD1F0 001BD1F0 34080246 */  c.lt.s     $f1, $f2
    /* BD1F4 001BD1F4 05000145 */  bc1t       .L001BD20C
    /* BD1F8 001BD1F8 00000000 */   nop
    /* BD1FC 001BD1FC 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* BD200 001BD200 36000246 */  c.le.s     $f0, $f2
    /* BD204 001BD204 08000145 */  bc1t       .L001BD228
    /* BD208 001BD208 00000000 */   nop
  .L001BD20C:
    /* BD20C 001BD20C 36080246 */  c.le.s     $f1, $f2
    /* BD210 001BD210 2A000045 */  bc1f       .L001BD2BC
    /* BD214 001BD214 00000000 */   nop
    /* BD218 001BD218 4801A0C7 */  lwc1       $f0, 0x148($29)
    /* BD21C 001BD21C 34000246 */  c.lt.s     $f0, $f2
    /* BD220 001BD220 26000145 */  bc1t       .L001BD2BC
    /* BD224 001BD224 00000000 */   nop
  .L001BD228:
    /* BD228 001BD228 5C01A2C7 */  lwc1       $f2, 0x15C($29)
    /* BD22C 001BD22C 4401A1C7 */  lwc1       $f1, 0x144($29)
    /* BD230 001BD230 34080246 */  c.lt.s     $f1, $f2
    /* BD234 001BD234 05000145 */  bc1t       .L001BD24C
    /* BD238 001BD238 00000000 */   nop
    /* BD23C 001BD23C 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* BD240 001BD240 36000246 */  c.le.s     $f0, $f2
    /* BD244 001BD244 0B000145 */  bc1t       .L001BD274
    /* BD248 001BD248 00000000 */   nop
  .L001BD24C:
    /* BD24C 001BD24C 36080246 */  c.le.s     $f1, $f2
    /* BD250 001BD250 1A000045 */  bc1f       .L001BD2BC
    /* BD254 001BD254 00000000 */   nop
    /* BD258 001BD258 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* BD25C 001BD25C 34000246 */  c.lt.s     $f0, $f2
    /* BD260 001BD260 04000045 */  bc1f       .L001BD274
    /* BD264 001BD264 00000000 */   nop
    /* BD268 001BD268 14000010 */  b          .L001BD2BC
    /* BD26C 001BD26C 00000000 */   nop
  .L001BD270:
    /* BD270 001BD270 00188044 */  mtc1       $0, $f3
  .L001BD274:
    /* BD274 001BD274 36181446 */  c.le.s     $f3, $f20
    /* BD278 001BD278 10000045 */  bc1f       .L001BD2BC
    /* BD27C 001BD27C 00000000 */   nop
    /* BD280 001BD280 2D202002 */  daddu      $4, $17, $0
    /* BD284 001BD284 02000524 */  addiu      $5, $0, 0x2
    /* BD288 001BD288 E853060C */  jal        func_00194fa0
    /* BD28C 001BD28C 00000000 */   nop
    /* BD290 001BD290 C000A37B */  lq         $3, 0xC0($29)
    /* BD294 001BD294 02006014 */  bnez       $3, .L001BD2A0
    /* BD298 001BD298 00000000 */   nop
    /* BD29C 001BD29C 370020A2 */  sb         $0, 0x37($17)
  .L001BD2A0:
    /* BD2A0 001BD2A0 B000A37B */  lq         $3, 0xB0($29)
    /* BD2A4 001BD2A4 05006010 */  beqz       $3, .L001BD2BC
    /* BD2A8 001BD2A8 00000000 */   nop
    /* BD2AC 001BD2AC 2D202002 */  daddu      $4, $17, $0
    /* BD2B0 001BD2B0 04000524 */  addiu      $5, $0, 0x4
    /* BD2B4 001BD2B4 F053060C */  jal        func_00194fc0
    /* BD2B8 001BD2B8 00000000 */   nop
  .L001BD2BC:
    /* BD2BC 001BD2BC 5004528E */  lw         $18, 0x450($18)
  .L001BD2C0:
    /* BD2C0 001BD2C0 F6FE4016 */  bnez       $18, .L001BCE9C
    /* BD2C4 001BD2C4 00000000 */   nop
  .L001BD2C8:
    /* BD2C8 001BD2C8 A000BFDF */  ld         $31, 0xA0($29)
    /* BD2CC 001BD2CC 9000BE7B */  lq         $30, 0x90($29)
    /* BD2D0 001BD2D0 8000B77B */  lq         $23, 0x80($29)
    /* BD2D4 001BD2D4 7000B67B */  lq         $22, 0x70($29)
    /* BD2D8 001BD2D8 6000B57B */  lq         $21, 0x60($29)
    /* BD2DC 001BD2DC 5000B47B */  lq         $20, 0x50($29)
    /* BD2E0 001BD2E0 4000B37B */  lq         $19, 0x40($29)
    /* BD2E4 001BD2E4 3000B27B */  lq         $18, 0x30($29)
    /* BD2E8 001BD2E8 2000B17B */  lq         $17, 0x20($29)
    /* BD2EC 001BD2EC 1000B07B */  lq         $16, 0x10($29)
    /* BD2F0 001BD2F0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* BD2F4 001BD2F4 7001BD27 */  addiu      $29, $29, 0x170
    /* BD2F8 001BD2F8 0800E003 */  jr         $31
    /* BD2FC 001BD2FC 00000000 */   nop
.size func_001bcd40, 0x5c0
