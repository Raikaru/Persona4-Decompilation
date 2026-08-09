.section .text
.set noat
.set noreorder
glabel func_001aed50
    /* AED50 001AED50 10FEBD27 */  addiu      $29, $29, -0x1F0
    /* AED54 001AED54 A000BFFF */  sd         $31, 0xA0($29)
    /* AED58 001AED58 9000BE7F */  sq         $30, 0x90($29)
    /* AED5C 001AED5C 8000B77F */  sq         $23, 0x80($29)
    /* AED60 001AED60 7000B67F */  sq         $22, 0x70($29)
    /* AED64 001AED64 6000B57F */  sq         $21, 0x60($29)
    /* AED68 001AED68 5000B47F */  sq         $20, 0x50($29)
    /* AED6C 001AED6C 4000B37F */  sq         $19, 0x40($29)
    /* AED70 001AED70 3000B27F */  sq         $18, 0x30($29)
    /* AED74 001AED74 2000B17F */  sq         $17, 0x20($29)
    /* AED78 001AED78 1000B07F */  sq         $16, 0x10($29)
    /* AED7C 001AED7C 2DA08000 */  daddu      $20, $4, $0
    /* AED80 001AED80 000090DC */  ld         $16, 0x0($4)
    /* AED84 001AED84 01000424 */  addiu      $4, $0, 0x1
    /* AED88 001AED88 544F070C */  jal        func_001d3d50
    /* AED8C 001AED8C 00000000 */   nop
    /* AED90 001AED90 2401A2AF */  sw         $2, 0x124($29)
    /* AED94 001AED94 ACB3828F */  lw         $2, -0x4C54($28)
    /* AED98 001AED98 7401518C */  lw         $17, 0x174($2)
    /* AED9C 001AED9C 0E000010 */  b          .L001AEDD8
    /* AEDA0 001AEDA0 00000000 */   nop
  .L001AEDA4:
    /* AEDA4 001AEDA4 28002292 */  lbu        $2, 0x28($17)
    /* AEDA8 001AEDA8 0A004010 */  beqz       $2, .L001AEDD4
    /* AEDAC 001AEDAC 00000000 */   nop
    /* AEDB0 001AEDB0 2D202002 */  daddu      $4, $17, $0
    /* AEDB4 001AEDB4 02000524 */  addiu      $5, $0, 0x2
    /* AEDB8 001AEDB8 1CCE070C */  jal        func_001f3870
    /* AEDBC 001AEDBC 00000000 */   nop
    /* AEDC0 001AEDC0 2D204000 */  daddu      $4, $2, $0
    /* AEDC4 001AEDC4 600050FC */  sd         $16, 0x60($2)
    /* AEDC8 001AEDC8 01000524 */  addiu      $5, $0, 0x1
    /* AEDCC 001AEDCC 6451060C */  jal        func_00194590
    /* AEDD0 001AEDD0 00000000 */   nop
  .L001AEDD4:
    /* AEDD4 001AEDD4 5004318E */  lw         $17, 0x450($17)
  .L001AEDD8:
    /* AEDD8 001AEDD8 F2FF2016 */  bnez       $17, .L001AEDA4
    /* AEDDC 001AEDDC 00000000 */   nop
    /* AEDE0 001AEDE0 6E009686 */  lh         $22, 0x6E($20)
    /* AEDE4 001AEDE4 38009E8E */  lw         $30, 0x38($20)
    /* AEDE8 001AEDE8 2D380000 */  daddu      $7, $0, $0
    /* AEDEC 001AEDEC ACB3868F */  lw         $6, -0x4C54($28)
    /* AEDF0 001AEDF0 580CC594 */  lhu        $5, 0xC58($6)
    /* AEDF4 001AEDF4 0A000010 */  b          .L001AEE20
    /* AEDF8 001AEDF8 00000000 */   nop
  .L001AEDFC:
    /* AEDFC 001AEDFC FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AEE00 001AEE00 80200200 */  sll        $4, $2, 2
    /* AEE04 001AEE04 2110C400 */  addu       $2, $6, $4
    /* AEE08 001AEE08 480C428C */  lw         $2, 0xC48($2)
    /* AEE0C 001AEE0C 3000438C */  lw         $3, 0x30($2)
    /* AEE10 001AEE10 21109D00 */  addu       $2, $4, $29
    /* AEE14 001AEE14 D80143AC */  sw         $3, 0x1D8($2)
    /* AEE18 001AEE18 0100E224 */  addiu      $2, $7, 0x1
    /* AEE1C 001AEE1C FFFF4730 */  andi       $7, $2, 0xFFFF
  .L001AEE20:
    /* AEE20 001AEE20 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AEE24 001AEE24 2A104500 */  slt        $2, $2, $5
    /* AEE28 001AEE28 F4FF4014 */  bnez       $2, .L001AEDFC
    /* AEE2C 001AEE2C 00000000 */   nop
    /* AEE30 001AEE30 07000010 */  b          .L001AEE50
    /* AEE34 001AEE34 00000000 */   nop
  .L001AEE38:
    /* AEE38 001AEE38 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AEE3C 001AEE3C 80100200 */  sll        $2, $2, 2
    /* AEE40 001AEE40 21105D00 */  addu       $2, $2, $29
    /* AEE44 001AEE44 D80140AC */  sw         $0, 0x1D8($2)
    /* AEE48 001AEE48 0100E224 */  addiu      $2, $7, 0x1
    /* AEE4C 001AEE4C FFFF4730 */  andi       $7, $2, 0xFFFF
  .L001AEE50:
    /* AEE50 001AEE50 FFFFE230 */  andi       $2, $7, 0xFFFF
    /* AEE54 001AEE54 0300422C */  sltiu      $2, $2, 0x3
    /* AEE58 001AEE58 F7FF4014 */  bnez       $2, .L001AEE38
    /* AEE5C 001AEE5C 00000000 */   nop
    /* AEE60 001AEE60 D801A48F */  lw         $4, 0x1D8($29)
    /* AEE64 001AEE64 DC01A58F */  lw         $5, 0x1DC($29)
    /* AEE68 001AEE68 E001A68F */  lw         $6, 0x1E0($29)
    /* AEE6C 001AEE6C FC5E070C */  jal        func_001d7bf0
    /* AEE70 001AEE70 00000000 */   nop
    /* AEE74 001AEE74 2D204000 */  daddu      $4, $2, $0
    /* AEE78 001AEE78 600050FC */  sd         $16, 0x60($2)
    /* AEE7C 001AEE7C 01000524 */  addiu      $5, $0, 0x1
    /* AEE80 001AEE80 6451060C */  jal        func_00194590
    /* AEE84 001AEE84 00000000 */   nop
    /* AEE88 001AEE88 C8E8070C */  jal        func_001fa320
    /* AEE8C 001AEE8C 00000000 */   nop
    /* AEE90 001AEE90 2D984000 */  daddu      $19, $2, $0
    /* AEE94 001AEE94 0A000424 */  addiu      $4, $0, 0xA
    /* AEE98 001AEE98 000044A0 */  sb         $4, 0x0($2)
    /* AEE9C 001AEE9C 000C0324 */  addiu      $3, $0, 0xC00
    /* AEEA0 001AEEA0 080043A4 */  sh         $3, 0x8($2)
    /* AEEA4 001AEEA4 100044A0 */  sb         $4, 0x10($2)
    /* AEEA8 001AEEA8 050C0324 */  addiu      $3, $0, 0xC05
    /* AEEAC 001AEEAC 180043A4 */  sh         $3, 0x18($2)
    /* AEEB0 001AEEB0 600050FC */  sd         $16, 0x60($2)
    /* AEEB4 001AEEB4 2D206002 */  daddu      $4, $19, $0
    /* AEEB8 001AEEB8 01000524 */  addiu      $5, $0, 0x1
    /* AEEBC 001AEEBC 6451060C */  jal        func_00194590
    /* AEEC0 001AEEC0 00000000 */   nop
    /* AEEC4 001AEEC4 0E000424 */  addiu      $4, $0, 0xE
    /* AEEC8 001AEEC8 04000524 */  addiu      $5, $0, 0x4
    /* AEECC 001AEECC 2D30A000 */  daddu      $6, $5, $0
    /* AEED0 001AEED0 08DF070C */  jal        func_001f7c20
    /* AEED4 001AEED4 00000000 */   nop
    /* AEED8 001AEED8 2D204000 */  daddu      $4, $2, $0
    /* AEEDC 001AEEDC 05000324 */  addiu      $3, $0, 0x5
    /* AEEE0 001AEEE0 000043A0 */  sb         $3, 0x0($2)
    /* AEEE4 001AEEE4 580063DE */  ld         $3, 0x58($19)
    /* AEEE8 001AEEE8 080043FC */  sd         $3, 0x8($2)
    /* AEEEC 001AEEEC 000083DE */  ld         $3, 0x0($20)
    /* AEEF0 001AEEF0 600043FC */  sd         $3, 0x60($2)
    /* AEEF4 001AEEF4 01000524 */  addiu      $5, $0, 0x1
    /* AEEF8 001AEEF8 6451060C */  jal        func_00194590
    /* AEEFC 001AEEFC 00000000 */   nop
    /* AEF00 001AEF00 580071DE */  ld         $17, 0x58($19)
    /* AEF04 001AEF04 3404848E */  lw         $4, 0x434($20)
    /* AEF08 001AEF08 07000524 */  addiu      $5, $0, 0x7
    /* AEF0C 001AEF0C 2D300000 */  daddu      $6, $0, $0
    /* AEF10 001AEF10 2D380000 */  daddu      $7, $0, $0
    /* AEF14 001AEF14 2D400000 */  daddu      $8, $0, $0
    /* AEF18 001AEF18 70E6070C */  jal        func_001f99c0
    /* AEF1C 001AEF1C 00000000 */   nop
    /* AEF20 001AEF20 2D204000 */  daddu      $4, $2, $0
    /* AEF24 001AEF24 05000324 */  addiu      $3, $0, 0x5
    /* AEF28 001AEF28 000043A0 */  sb         $3, 0x0($2)
    /* AEF2C 001AEF2C 580063DE */  ld         $3, 0x58($19)
    /* AEF30 001AEF30 080043FC */  sd         $3, 0x8($2)
    /* AEF34 001AEF34 3C000324 */  addiu      $3, $0, 0x3C
    /* AEF38 001AEF38 480043A4 */  sh         $3, 0x48($2)
    /* AEF3C 001AEF3C 000083DE */  ld         $3, 0x0($20)
    /* AEF40 001AEF40 600043FC */  sd         $3, 0x60($2)
    /* AEF44 001AEF44 01000524 */  addiu      $5, $0, 0x1
    /* AEF48 001AEF48 6451060C */  jal        func_00194590
    /* AEF4C 001AEF4C 00000000 */   nop
    /* AEF50 001AEF50 FFFFD332 */  andi       $19, $22, 0xFFFF
    /* AEF54 001AEF54 2D206002 */  daddu      $4, $19, $0
    /* AEF58 001AEF58 EC01A527 */  addiu      $5, $29, 0x1EC
    /* AEF5C 001AEF5C E801A627 */  addiu      $6, $29, 0x1E8
    /* AEF60 001AEF60 18DC060C */  jal        func_001b7060
    /* AEF64 001AEF64 00000000 */   nop
    /* AEF68 001AEF68 EC01A48F */  lw         $4, 0x1EC($29)
    /* AEF6C 001AEF6C E801A58F */  lw         $5, 0x1E8($29)
    /* AEF70 001AEF70 10000624 */  addiu      $6, $0, 0x10
    /* AEF74 001AEF74 20DE060C */  jal        func_001b7880
    /* AEF78 001AEF78 00000000 */   nop
    /* AEF7C 001AEF7C 2D204000 */  daddu      $4, $2, $0
    /* AEF80 001AEF80 05000324 */  addiu      $3, $0, 0x5
    /* AEF84 001AEF84 000043A0 */  sb         $3, 0x0($2)
    /* AEF88 001AEF88 080051FC */  sd         $17, 0x8($2)
    /* AEF8C 001AEF8C 3C000324 */  addiu      $3, $0, 0x3C
    /* AEF90 001AEF90 480043A4 */  sh         $3, 0x48($2)
    /* AEF94 001AEF94 600050FC */  sd         $16, 0x60($2)
    /* AEF98 001AEF98 01000524 */  addiu      $5, $0, 0x1
    /* AEF9C 001AEF9C 6451060C */  jal        func_00194590
    /* AEFA0 001AEFA0 00000000 */   nop
    /* AEFA4 001AEFA4 2D206002 */  daddu      $4, $19, $0
    /* AEFA8 001AEFA8 20DC060C */  jal        func_001b7080
    /* AEFAC 001AEFAC 00000000 */   nop
    /* AEFB0 001AEFB0 2DB84000 */  daddu      $23, $2, $0
    /* AEFB4 001AEFB4 2D206002 */  daddu      $4, $19, $0
    /* AEFB8 001AEFB8 EC01A527 */  addiu      $5, $29, 0x1EC
    /* AEFBC 001AEFBC E801A627 */  addiu      $6, $29, 0x1E8
    /* AEFC0 001AEFC0 28DC060C */  jal        func_001b70a0
    /* AEFC4 001AEFC4 00000000 */   nop
    /* AEFC8 001AEFC8 3C141600 */  dsll32     $2, $22, 16
    /* AEFCC 001AEFCC 3F140200 */  dsra32     $2, $2, 16
    /* AEFD0 001AEFD0 0001A2AF */  sw         $2, 0x100($29)
    /* AEFD4 001AEFD4 BCB3838F */  lw         $3, -0x4C44($28)
    /* AEFD8 001AEFD8 80100200 */  sll        $2, $2, 2
    /* AEFDC 001AEFDC 21104300 */  addu       $2, $2, $3
    /* AEFE0 001AEFE0 02004294 */  lhu        $2, 0x2($2)
    /* AEFE4 001AEFE4 02004230 */  andi       $2, $2, 0x2
    /* AEFE8 001AEFE8 2B100200 */  sltu       $2, $0, $2
    /* AEFEC 001AEFEC FFFF4830 */  andi       $8, $2, 0xFFFF
    /* AEFF0 001AEFF0 2D20E002 */  daddu      $4, $23, $0
    /* AEFF4 001AEFF4 EC01A58F */  lw         $5, 0x1EC($29)
    /* AEFF8 001AEFF8 E801A68F */  lw         $6, 0x1E8($29)
    /* AEFFC 001AEFFC 10000724 */  addiu      $7, $0, 0x10
    /* AF000 001AF000 FCE0060C */  jal        func_001b83f0
    /* AF004 001AF004 00000000 */   nop
    /* AF008 001AF008 2D204000 */  daddu      $4, $2, $0
    /* AF00C 001AF00C 05000324 */  addiu      $3, $0, 0x5
    /* AF010 001AF010 000043A0 */  sb         $3, 0x0($2)
    /* AF014 001AF014 080051FC */  sd         $17, 0x8($2)
    /* AF018 001AF018 3C000324 */  addiu      $3, $0, 0x3C
    /* AF01C 001AF01C 480043A4 */  sh         $3, 0x48($2)
    /* AF020 001AF020 600050FC */  sd         $16, 0x60($2)
    /* AF024 001AF024 01000524 */  addiu      $5, $0, 0x1
    /* AF028 001AF028 6451060C */  jal        func_00194590
    /* AF02C 001AF02C 00000000 */   nop
    /* AF030 001AF030 FFFFD632 */  andi       $22, $22, 0xFFFF
    /* AF034 001AF034 2D20C002 */  daddu      $4, $22, $0
    /* AF038 001AF038 24DC060C */  jal        func_001b7090
    /* AF03C 001AF03C 00000000 */   nop
    /* AF040 001AF040 2D204000 */  daddu      $4, $2, $0
    /* AF044 001AF044 10000524 */  addiu      $5, $0, 0x10
    /* AF048 001AF048 58E5060C */  jal        func_001b9560
    /* AF04C 001AF04C 00000000 */   nop
    /* AF050 001AF050 2D204000 */  daddu      $4, $2, $0
    /* AF054 001AF054 05000324 */  addiu      $3, $0, 0x5
    /* AF058 001AF058 000043A0 */  sb         $3, 0x0($2)
    /* AF05C 001AF05C 080051FC */  sd         $17, 0x8($2)
    /* AF060 001AF060 3C000324 */  addiu      $3, $0, 0x3C
    /* AF064 001AF064 480043A4 */  sh         $3, 0x48($2)
    /* AF068 001AF068 600050FC */  sd         $16, 0x60($2)
    /* AF06C 001AF06C 01000524 */  addiu      $5, $0, 0x1
    /* AF070 001AF070 6451060C */  jal        func_00194590
    /* AF074 001AF074 00000000 */   nop
    /* AF078 001AF078 2D208002 */  daddu      $4, $20, $0
    /* AF07C 001AF07C 2D28C002 */  daddu      $5, $22, $0
    /* AF080 001AF080 10000624 */  addiu      $6, $0, 0x10
    /* AF084 001AF084 78E7060C */  jal        func_001b9de0
    /* AF088 001AF088 00000000 */   nop
    /* AF08C 001AF08C 2D204000 */  daddu      $4, $2, $0
    /* AF090 001AF090 05000324 */  addiu      $3, $0, 0x5
    /* AF094 001AF094 000043A0 */  sb         $3, 0x0($2)
    /* AF098 001AF098 080051FC */  sd         $17, 0x8($2)
    /* AF09C 001AF09C 3C000324 */  addiu      $3, $0, 0x3C
    /* AF0A0 001AF0A0 480043A4 */  sh         $3, 0x48($2)
    /* AF0A4 001AF0A4 600050FC */  sd         $16, 0x60($2)
    /* AF0A8 001AF0A8 01000524 */  addiu      $5, $0, 0x1
    /* AF0AC 001AF0AC 6451060C */  jal        func_00194590
    /* AF0B0 001AF0B0 00000000 */   nop
    /* AF0B4 001AF0B4 2D20C002 */  daddu      $4, $22, $0
    /* AF0B8 001AF0B8 3001A527 */  addiu      $5, $29, 0x130
    /* AF0BC 001AF0BC 7C5A070C */  jal        func_001d69f0
    /* AF0C0 001AF0C0 00000000 */   nop
    /* AF0C4 001AF0C4 2401A48F */  lw         $4, 0x124($29)
    /* AF0C8 001AF0C8 3001A527 */  addiu      $5, $29, 0x130
    /* AF0CC 001AF0CC 2D300000 */  daddu      $6, $0, $0
    /* AF0D0 001AF0D0 AC57070C */  jal        func_001d5eb0
    /* AF0D4 001AF0D4 00000000 */   nop
    /* AF0D8 001AF0D8 2C01A2AF */  sw         $2, 0x12C($29)
    /* AF0DC 001AF0DC 05000324 */  addiu      $3, $0, 0x5
    /* AF0E0 001AF0E0 000043A0 */  sb         $3, 0x0($2)
    /* AF0E4 001AF0E4 080051FC */  sd         $17, 0x8($2)
    /* AF0E8 001AF0E8 3C000324 */  addiu      $3, $0, 0x3C
    /* AF0EC 001AF0EC 480043A4 */  sh         $3, 0x48($2)
    /* AF0F0 001AF0F0 600050FC */  sd         $16, 0x60($2)
    /* AF0F4 001AF0F4 2D204000 */  daddu      $4, $2, $0
    /* AF0F8 001AF0F8 01000524 */  addiu      $5, $0, 0x1
    /* AF0FC 001AF0FC 6451060C */  jal        func_00194590
    /* AF100 001AF100 00000000 */   nop
    /* AF104 001AF104 ACB3828F */  lw         $2, -0x4C54($28)
    /* AF108 001AF108 7801518C */  lw         $17, 0x178($2)
    /* AF10C 001AF10C 22000010 */  b          .L001AF198
    /* AF110 001AF110 00000000 */   nop
  .L001AF114:
    /* AF114 001AF114 640A248E */  lw         $4, 0xA64($17)
    /* AF118 001AF118 1000023C */  lui        $2, (0x100117 >> 16)
    /* AF11C 001AF11C 17014534 */  ori        $5, $2, (0x100117 & 0xFFFF)
    /* AF120 001AF120 C4C9080C */  jal        func_00232710
    /* AF124 001AF124 00000000 */   nop
    /* AF128 001AF128 07004014 */  bnez       $2, .L001AF148
    /* AF12C 001AF12C 00000000 */   nop
    /* AF130 001AF130 640A248E */  lw         $4, 0xA64($17)
    /* AF134 001AF134 2D280000 */  daddu      $5, $0, $0
    /* AF138 001AF138 3C0A090C */  jal        func_002428f0
    /* AF13C 001AF13C 00000000 */   nop
    /* AF140 001AF140 14004010 */  beqz       $2, .L001AF194
    /* AF144 001AF144 00000000 */   nop
  .L001AF148:
    /* AF148 001AF148 2D202002 */  daddu      $4, $17, $0
    /* AF14C 001AF14C FF00023C */  lui        $2, (0xFFFFFF >> 16)
    /* AF150 001AF150 FFFF4534 */  ori        $5, $2, (0xFFFFFF & 0xFFFF)
    /* AF154 001AF154 2D300000 */  daddu      $6, $0, $0
    /* AF158 001AF158 2D380000 */  daddu      $7, $0, $0
    /* AF15C 001AF15C 04000824 */  addiu      $8, $0, 0x4
    /* AF160 001AF160 2D480000 */  daddu      $9, $0, $0
    /* AF164 001AF164 F86E060C */  jal        func_0019bbe0
    /* AF168 001AF168 00000000 */   nop
    /* AF16C 001AF16C 2D204000 */  daddu      $4, $2, $0
    /* AF170 001AF170 04000324 */  addiu      $3, $0, 0x4
    /* AF174 001AF174 000043A0 */  sb         $3, 0x0($2)
    /* AF178 001AF178 2C01A38F */  lw         $3, 0x12C($29)
    /* AF17C 001AF17C 580063DC */  ld         $3, 0x58($3)
    /* AF180 001AF180 080043FC */  sd         $3, 0x8($2)
    /* AF184 001AF184 600050FC */  sd         $16, 0x60($2)
    /* AF188 001AF188 2D280000 */  daddu      $5, $0, $0
    /* AF18C 001AF18C 6451060C */  jal        func_00194590
    /* AF190 001AF190 00000000 */   nop
  .L001AF194:
    /* AF194 001AF194 6C0A318E */  lw         $17, 0xA6C($17)
  .L001AF198:
    /* AF198 001AF198 DEFF2016 */  bnez       $17, .L001AF114
    /* AF19C 001AF19C 00000000 */   nop
    /* AF1A0 001AF1A0 2401A48F */  lw         $4, 0x124($29)
    /* AF1A4 001AF1A4 3000858E */  lw         $5, 0x30($20)
    /* AF1A8 001AF1A8 3000C68F */  lw         $6, 0x30($30)
    /* AF1AC 001AF1AC 2D380000 */  daddu      $7, $0, $0
    /* AF1B0 001AF1B0 2D400000 */  daddu      $8, $0, $0
    /* AF1B4 001AF1B4 9058070C */  jal        func_001d6240
    /* AF1B8 001AF1B8 00000000 */   nop
    /* AF1BC 001AF1BC 2801A2AF */  sw         $2, 0x128($29)
    /* AF1C0 001AF1C0 04000324 */  addiu      $3, $0, 0x4
    /* AF1C4 001AF1C4 000043A0 */  sb         $3, 0x0($2)
    /* AF1C8 001AF1C8 2C01A38F */  lw         $3, 0x12C($29)
    /* AF1CC 001AF1CC 580063DC */  ld         $3, 0x58($3)
    /* AF1D0 001AF1D0 080043FC */  sd         $3, 0x8($2)
    /* AF1D4 001AF1D4 600050FC */  sd         $16, 0x60($2)
    /* AF1D8 001AF1D8 2D204000 */  daddu      $4, $2, $0
    /* AF1DC 001AF1DC 02000524 */  addiu      $5, $0, 0x2
    /* AF1E0 001AF1E0 6451060C */  jal        func_00194590
    /* AF1E4 001AF1E4 00000000 */   nop
    /* AF1E8 001AF1E8 01010324 */  addiu      $3, $0, 0x101
    /* AF1EC 001AF1EC 0001A28F */  lw         $2, 0x100($29)
    /* AF1F0 001AF1F0 0D004310 */  beq        $2, $3, .L001AF228
    /* AF1F4 001AF1F4 00000000 */   nop
    /* AF1F8 001AF1F8 00010324 */  addiu      $3, $0, 0x100
    /* AF1FC 001AF1FC 03004310 */  beq        $2, $3, .L001AF20C
    /* AF200 001AF200 00000000 */   nop
    /* AF204 001AF204 0F000010 */  b          .L001AF244
    /* AF208 001AF208 00000000 */   nop
  .L001AF20C:
    /* AF20C 001AF20C 02000424 */  addiu      $4, $0, 0x2
    /* AF210 001AF210 5F00053C */  lui        $5, %hi(D_005F6D38)
    /* AF214 001AF214 386DA524 */  addiu      $5, $5, %lo(D_005F6D38)
    /* AF218 001AF218 7CE0070C */  jal        func_001f81f0
    /* AF21C 001AF21C 00000000 */   nop
    /* AF220 001AF220 0D000010 */  b          .L001AF258
    /* AF224 001AF224 00000000 */   nop
  .L001AF228:
    /* AF228 001AF228 02000424 */  addiu      $4, $0, 0x2
    /* AF22C 001AF22C 5F00053C */  lui        $5, %hi(D_005F6D48)
    /* AF230 001AF230 486DA524 */  addiu      $5, $5, %lo(D_005F6D48)
    /* AF234 001AF234 7CE0070C */  jal        func_001f81f0
    /* AF238 001AF238 00000000 */   nop
    /* AF23C 001AF23C 06000010 */  b          .L001AF258
    /* AF240 001AF240 00000000 */   nop
  .L001AF244:
    /* AF244 001AF244 02000424 */  addiu      $4, $0, 0x2
    /* AF248 001AF248 5F00053C */  lui        $5, %hi(D_005F6D58)
    /* AF24C 001AF24C 586DA524 */  addiu      $5, $5, %lo(D_005F6D58)
    /* AF250 001AF250 7CE0070C */  jal        func_001f81f0
    /* AF254 001AF254 00000000 */   nop
  .L001AF258:
    /* AF258 001AF258 05000324 */  addiu      $3, $0, 0x5
    /* AF25C 001AF25C 000043A0 */  sb         $3, 0x0($2)
    /* AF260 001AF260 2801A38F */  lw         $3, 0x128($29)
    /* AF264 001AF264 580063DC */  ld         $3, 0x58($3)
    /* AF268 001AF268 080043FC */  sd         $3, 0x8($2)
    /* AF26C 001AF26C 600050FC */  sd         $16, 0x60($2)
    /* AF270 001AF270 2D204000 */  daddu      $4, $2, $0
    /* AF274 001AF274 01000524 */  addiu      $5, $0, 0x1
    /* AF278 001AF278 6451060C */  jal        func_00194590
    /* AF27C 001AF27C 00000000 */   nop
    /* AF280 001AF280 1001A0A7 */  sh         $0, 0x110($29)
    /* AF284 001AF284 2D206002 */  daddu      $4, $19, $0
    /* AF288 001AF288 28BD070C */  jal        func_001ef4a0
    /* AF28C 001AF28C 00000000 */   nop
    /* AF290 001AF290 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* AF294 001AF294 D000A27F */  sq         $2, 0xD0($29)
    /* AF298 001AF298 2DB80000 */  daddu      $23, $0, $0
    /* AF29C 001AF29C 3B010010 */  b          .L001AF78C
    /* AF2A0 001AF2A0 00000000 */   nop
  .L001AF2A4:
    /* AF2A4 001AF2A4 FFFFE232 */  andi       $2, $23, 0xFFFF
    /* AF2A8 001AF2A8 80100200 */  sll        $2, $2, 2
    /* AF2AC 001AF2AC 21108202 */  addu       $2, $20, $2
    /* AF2B0 001AF2B0 3800518C */  lw         $17, 0x38($2)
    /* AF2B4 001AF2B4 2D202002 */  daddu      $4, $17, $0
    /* AF2B8 001AF2B8 D0C0080C */  jal        func_00230340
    /* AF2BC 001AF2BC 00000000 */   nop
    /* AF2C0 001AF2C0 D8002426 */  addiu      $4, $17, 0xD8
    /* AF2C4 001AF2C4 FC50070C */  jal        func_001d43f0
    /* AF2C8 001AF2C8 00000000 */   nop
    /* AF2CC 001AF2CC 2DA84000 */  daddu      $21, $2, $0
    /* AF2D0 001AF2D0 E400228E */  lw         $2, 0xE4($17)
    /* AF2D4 001AF2D4 04004010 */  beqz       $2, .L001AF2E8
    /* AF2D8 001AF2D8 00000000 */   nop
    /* AF2DC 001AF2DC 2D988002 */  daddu      $19, $20, $0
    /* AF2E0 001AF2E0 02000010 */  b          .L001AF2EC
    /* AF2E4 001AF2E4 00000000 */   nop
  .L001AF2E8:
    /* AF2E8 001AF2E8 2D982002 */  daddu      $19, $17, $0
  .L001AF2EC:
    /* AF2EC 001AF2EC 3000648E */  lw         $4, 0x30($19)
    /* AF2F0 001AF2F0 D009080C */  jal        func_00202740
    /* AF2F4 001AF2F4 00000000 */   nop
    /* AF2F8 001AF2F8 2D204000 */  daddu      $4, $2, $0
    /* AF2FC 001AF2FC 600050FC */  sd         $16, 0x60($2)
    /* AF300 001AF300 01000524 */  addiu      $5, $0, 0x1
    /* AF304 001AF304 6451060C */  jal        func_00194590
    /* AF308 001AF308 00000000 */   nop
    /* AF30C 001AF30C 0010A836 */  ori        $8, $21, 0x1000
    /* AF310 001AF310 2401A48F */  lw         $4, 0x124($29)
    /* AF314 001AF314 3000858E */  lw         $5, 0x30($20)
    /* AF318 001AF318 3000668E */  lw         $6, 0x30($19)
    /* AF31C 001AF31C 01000724 */  addiu      $7, $0, 0x1
    /* AF320 001AF320 9058070C */  jal        func_001d6240
    /* AF324 001AF324 00000000 */   nop
    /* AF328 001AF328 2DA84000 */  daddu      $21, $2, $0
    /* AF32C 001AF32C 04000324 */  addiu      $3, $0, 0x4
    /* AF330 001AF330 000043A0 */  sb         $3, 0x0($2)
    /* AF334 001AF334 2C01A38F */  lw         $3, 0x12C($29)
    /* AF338 001AF338 580063DC */  ld         $3, 0x58($3)
    /* AF33C 001AF33C 080043FC */  sd         $3, 0x8($2)
    /* AF340 001AF340 1001A397 */  lhu        $3, 0x110($29)
    /* AF344 001AF344 480043A4 */  sh         $3, 0x48($2)
    /* AF348 001AF348 600050FC */  sd         $16, 0x60($2)
    /* AF34C 001AF34C 2D20A002 */  daddu      $4, $21, $0
    /* AF350 001AF350 02000524 */  addiu      $5, $0, 0x2
    /* AF354 001AF354 6451060C */  jal        func_00194590
    /* AF358 001AF358 00000000 */   nop
    /* AF35C 001AF35C 0A000424 */  addiu      $4, $0, 0xA
    /* AF360 001AF360 2D280000 */  daddu      $5, $0, $0
    /* AF364 001AF364 04000624 */  addiu      $6, $0, 0x4
    /* AF368 001AF368 08DF070C */  jal        func_001f7c20
    /* AF36C 001AF36C 00000000 */   nop
    /* AF370 001AF370 2D204000 */  daddu      $4, $2, $0
    /* AF374 001AF374 0B000324 */  addiu      $3, $0, 0xB
    /* AF378 001AF378 000043A0 */  sb         $3, 0x0($2)
    /* AF37C 001AF37C 5800A3DE */  ld         $3, 0x58($21)
    /* AF380 001AF380 080043FC */  sd         $3, 0x8($2)
    /* AF384 001AF384 01000524 */  addiu      $5, $0, 0x1
    /* AF388 001AF388 6451060C */  jal        func_00194590
    /* AF38C 001AF38C 00000000 */   nop
    /* AF390 001AF390 E400228E */  lw         $2, 0xE4($17)
    /* AF394 001AF394 11004010 */  beqz       $2, .L001AF3DC
    /* AF398 001AF398 00000000 */   nop
    /* AF39C 001AF39C ACB3828F */  lw         $2, -0x4C54($28)
    /* AF3A0 001AF3A0 280D448C */  lw         $4, 0xD28($2)
    /* AF3A4 001AF3A4 3000858E */  lw         $5, 0x30($20)
    /* AF3A8 001AF3A8 3000268E */  lw         $6, 0x30($17)
    /* AF3AC 001AF3AC 01000724 */  addiu      $7, $0, 0x1
    /* AF3B0 001AF3B0 2D400000 */  daddu      $8, $0, $0
    /* AF3B4 001AF3B4 9058070C */  jal        func_001d6240
    /* AF3B8 001AF3B8 00000000 */   nop
    /* AF3BC 001AF3BC 2D204000 */  daddu      $4, $2, $0
    /* AF3C0 001AF3C0 0B000324 */  addiu      $3, $0, 0xB
    /* AF3C4 001AF3C4 000043A0 */  sb         $3, 0x0($2)
    /* AF3C8 001AF3C8 5800A3DE */  ld         $3, 0x58($21)
    /* AF3CC 001AF3CC 080043FC */  sd         $3, 0x8($2)
    /* AF3D0 001AF3D0 01000524 */  addiu      $5, $0, 0x1
    /* AF3D4 001AF3D4 6451060C */  jal        func_00194590
    /* AF3D8 001AF3D8 00000000 */   nop
  .L001AF3DC:
    /* AF3DC 001AF3DC DC002396 */  lhu        $3, 0xDC($17)
    /* AF3E0 001AF3E0 00040224 */  addiu      $2, $0, 0x400
    /* AF3E4 001AF3E4 11006214 */  bne        $3, $2, .L001AF42C
    /* AF3E8 001AF3E8 00000000 */   nop
    /* AF3EC 001AF3EC ACB3828F */  lw         $2, -0x4C54($28)
    /* AF3F0 001AF3F0 2C0D448C */  lw         $4, 0xD2C($2)
    /* AF3F4 001AF3F4 3000858E */  lw         $5, 0x30($20)
    /* AF3F8 001AF3F8 3000668E */  lw         $6, 0x30($19)
    /* AF3FC 001AF3FC 01000724 */  addiu      $7, $0, 0x1
    /* AF400 001AF400 2D400000 */  daddu      $8, $0, $0
    /* AF404 001AF404 9058070C */  jal        func_001d6240
    /* AF408 001AF408 00000000 */   nop
    /* AF40C 001AF40C 2D204000 */  daddu      $4, $2, $0
    /* AF410 001AF410 0B000324 */  addiu      $3, $0, 0xB
    /* AF414 001AF414 000043A0 */  sb         $3, 0x0($2)
    /* AF418 001AF418 5800A3DE */  ld         $3, 0x58($21)
    /* AF41C 001AF41C 080043FC */  sd         $3, 0x8($2)
    /* AF420 001AF420 01000524 */  addiu      $5, $0, 0x1
    /* AF424 001AF424 6451060C */  jal        func_00194590
    /* AF428 001AF428 00000000 */   nop
  .L001AF42C:
    /* AF42C 001AF42C 2DB00000 */  daddu      $22, $0, $0
    /* AF430 001AF430 CA000010 */  b          .L001AF75C
    /* AF434 001AF434 00000000 */   nop
  .L001AF438:
    /* AF438 001AF438 FFFFC232 */  andi       $2, $22, 0xFFFF
    /* AF43C 001AF43C 40110200 */  sll        $2, $2, 5
    /* AF440 001AF440 21F02202 */  addu       $30, $17, $2
    /* AF444 001AF444 0C01C583 */  lb         $5, 0x10C($30)
    /* AF448 001AF448 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AF44C 001AF44C 00608244 */  mtc1       $2, $f12
    /* AF450 001AF450 3000648E */  lw         $4, 0x30($19)
    /* AF454 001AF454 2D300000 */  daddu      $6, $0, $0
    /* AF458 001AF458 2D380000 */  daddu      $7, $0, $0
    /* AF45C 001AF45C B867060C */  jal        func_00199ee0
    /* AF460 001AF460 00000000 */   nop
    /* AF464 001AF464 2D904000 */  daddu      $18, $2, $0
    /* AF468 001AF468 0B000324 */  addiu      $3, $0, 0xB
    /* AF46C 001AF46C 000043A0 */  sb         $3, 0x0($2)
    /* AF470 001AF470 5800A3DE */  ld         $3, 0x58($21)
    /* AF474 001AF474 080043FC */  sd         $3, 0x8($2)
    /* AF478 001AF478 600050FC */  sd         $16, 0x60($2)
    /* AF47C 001AF47C 2D204002 */  daddu      $4, $18, $0
    /* AF480 001AF480 2D280000 */  daddu      $5, $0, $0
    /* AF484 001AF484 6451060C */  jal        func_00194590
    /* AF488 001AF488 00000000 */   nop
    /* AF48C 001AF48C 3000248E */  lw         $4, 0x30($17)
    /* AF490 001AF490 3000858E */  lw         $5, 0x30($20)
    /* AF494 001AF494 02000624 */  addiu      $6, $0, 0x2
    /* AF498 001AF498 C060060C */  jal        func_00198300
    /* AF49C 001AF49C 00000000 */   nop
    /* AF4A0 001AF4A0 2D204000 */  daddu      $4, $2, $0
    /* AF4A4 001AF4A4 05000324 */  addiu      $3, $0, 0x5
    /* AF4A8 001AF4A8 000043A0 */  sb         $3, 0x0($2)
    /* AF4AC 001AF4AC 580043DE */  ld         $3, 0x58($18)
    /* AF4B0 001AF4B0 080043FC */  sd         $3, 0x8($2)
    /* AF4B4 001AF4B4 47004390 */  lbu        $3, 0x47($2)
    /* AF4B8 001AF4B8 DF006330 */  andi       $3, $3, 0xDF
    /* AF4BC 001AF4BC 470043A0 */  sb         $3, 0x47($2)
    /* AF4C0 001AF4C0 600050FC */  sd         $16, 0x60($2)
    /* AF4C4 001AF4C4 01000524 */  addiu      $5, $0, 0x1
    /* AF4C8 001AF4C8 6451060C */  jal        func_00194590
    /* AF4CC 001AF4CC 00000000 */   nop
    /* AF4D0 001AF4D0 F000C227 */  addiu      $2, $30, 0xF0
    /* AF4D4 001AF4D4 E000A2AF */  sw         $2, 0xE0($29)
    /* AF4D8 001AF4D8 2D208002 */  daddu      $4, $20, $0
    /* AF4DC 001AF4DC 2D286002 */  daddu      $5, $19, $0
    /* AF4E0 001AF4E0 2D304000 */  daddu      $6, $2, $0
    /* AF4E4 001AF4E4 DC002796 */  lhu        $7, 0xDC($17)
    /* AF4E8 001AF4E8 DE002896 */  lhu        $8, 0xDE($17)
    /* AF4EC 001AF4EC B8CD070C */  jal        func_001f36e0
    /* AF4F0 001AF4F0 00000000 */   nop
    /* AF4F4 001AF4F4 2D204000 */  daddu      $4, $2, $0
    /* AF4F8 001AF4F8 05000324 */  addiu      $3, $0, 0x5
    /* AF4FC 001AF4FC 000043A0 */  sb         $3, 0x0($2)
    /* AF500 001AF500 580043DE */  ld         $3, 0x58($18)
    /* AF504 001AF504 080043FC */  sd         $3, 0x8($2)
    /* AF508 001AF508 600050FC */  sd         $16, 0x60($2)
    /* AF50C 001AF50C 01000524 */  addiu      $5, $0, 0x1
    /* AF510 001AF510 6451060C */  jal        func_00194590
    /* AF514 001AF514 00000000 */   nop
    /* AF518 001AF518 2D202002 */  daddu      $4, $17, $0
    /* AF51C 001AF51C 54CE070C */  jal        func_001f3950
    /* AF520 001AF520 00000000 */   nop
    /* AF524 001AF524 2D204000 */  daddu      $4, $2, $0
    /* AF528 001AF528 05000324 */  addiu      $3, $0, 0x5
    /* AF52C 001AF52C 000043A0 */  sb         $3, 0x0($2)
    /* AF530 001AF530 580043DE */  ld         $3, 0x58($18)
    /* AF534 001AF534 080043FC */  sd         $3, 0x8($2)
    /* AF538 001AF538 600050FC */  sd         $16, 0x60($2)
    /* AF53C 001AF53C 01000524 */  addiu      $5, $0, 0x1
    /* AF540 001AF540 6451060C */  jal        func_00194590
    /* AF544 001AF544 00000000 */   nop
    /* AF548 001AF548 6A008296 */  lhu        $2, 0x6A($20)
    /* AF54C 001AF54C FFFF4324 */  addiu      $3, $2, -0x1
    /* AF550 001AF550 F000A28F */  lw         $2, 0xF0($29)
    /* AF554 001AF554 12004314 */  bne        $2, $3, .L001AF5A0
    /* AF558 001AF558 00000000 */   nop
    /* AF55C 001AF55C D9002292 */  lbu        $2, 0xD9($17)
    /* AF560 001AF560 FFFF4324 */  addiu      $3, $2, -0x1
    /* AF564 001AF564 B000A27B */  lq         $2, 0xB0($29)
    /* AF568 001AF568 0D004314 */  bne        $2, $3, .L001AF5A0
    /* AF56C 001AF56C 00000000 */   nop
    /* AF570 001AF570 2D208002 */  daddu      $4, $20, $0
    /* AF574 001AF574 54CE070C */  jal        func_001f3950
    /* AF578 001AF578 00000000 */   nop
    /* AF57C 001AF57C 2D204000 */  daddu      $4, $2, $0
    /* AF580 001AF580 05000324 */  addiu      $3, $0, 0x5
    /* AF584 001AF584 000043A0 */  sb         $3, 0x0($2)
    /* AF588 001AF588 580043DE */  ld         $3, 0x58($18)
    /* AF58C 001AF58C 080043FC */  sd         $3, 0x8($2)
    /* AF590 001AF590 600050FC */  sd         $16, 0x60($2)
    /* AF594 001AF594 01000524 */  addiu      $5, $0, 0x1
    /* AF598 001AF598 6451060C */  jal        func_00194590
    /* AF59C 001AF59C 00000000 */   nop
  .L001AF5A0:
    /* AF5A0 001AF5A0 B000A27B */  lq         $2, 0xB0($29)
    /* AF5A4 001AF5A4 16004014 */  bnez       $2, .L001AF600
    /* AF5A8 001AF5A8 00000000 */   nop
    /* AF5AC 001AF5AC E000A28F */  lw         $2, 0xE0($29)
    /* AF5B0 001AF5B0 0000428C */  lw         $2, 0x0($2)
    /* AF5B4 001AF5B4 12004010 */  beqz       $2, .L001AF600
    /* AF5B8 001AF5B8 00000000 */   nop
    /* AF5BC 001AF5BC 3000648E */  lw         $4, 0x30($19)
    /* AF5C0 001AF5C0 2D280000 */  daddu      $5, $0, $0
    /* AF5C4 001AF5C4 2D300000 */  daddu      $6, $0, $0
    /* AF5C8 001AF5C8 6409080C */  jal        func_00202590
    /* AF5CC 001AF5CC 00000000 */   nop
    /* AF5D0 001AF5D0 2D204000 */  daddu      $4, $2, $0
    /* AF5D4 001AF5D4 05000324 */  addiu      $3, $0, 0x5
    /* AF5D8 001AF5D8 000043A0 */  sb         $3, 0x0($2)
    /* AF5DC 001AF5DC 580043DE */  ld         $3, 0x58($18)
    /* AF5E0 001AF5E0 080043FC */  sd         $3, 0x8($2)
    /* AF5E4 001AF5E4 47004390 */  lbu        $3, 0x47($2)
    /* AF5E8 001AF5E8 DF006330 */  andi       $3, $3, 0xDF
    /* AF5EC 001AF5EC 470043A0 */  sb         $3, 0x47($2)
    /* AF5F0 001AF5F0 600050FC */  sd         $16, 0x60($2)
    /* AF5F4 001AF5F4 03000524 */  addiu      $5, $0, 0x3
    /* AF5F8 001AF5F8 6451060C */  jal        func_00194590
    /* AF5FC 001AF5FC 00000000 */   nop
  .L001AF600:
    /* AF600 001AF600 0E01C227 */  addiu      $2, $30, 0x10E
    /* AF604 001AF604 C000A27F */  sq         $2, 0xC0($29)
    /* AF608 001AF608 0E01C297 */  lhu        $2, 0x10E($30)
    /* AF60C 001AF60C 01004230 */  andi       $2, $2, 0x1
    /* AF610 001AF610 39004010 */  beqz       $2, .L001AF6F8
    /* AF614 001AF614 00000000 */   nop
    /* AF618 001AF618 B001A427 */  addiu      $4, $29, 0x1B0
    /* AF61C 001AF61C 84C2070C */  jal        func_001f0a10
    /* AF620 001AF620 00000000 */   nop
    /* AF624 001AF624 1000023C */  lui        $2, (0x100001 >> 16)
    /* AF628 001AF628 01004234 */  ori        $2, $2, (0x100001 & 0xFFFF)
    /* AF62C 001AF62C BC01A2AF */  sw         $2, 0x1BC($29)
    /* AF630 001AF630 2D202002 */  daddu      $4, $17, $0
    /* AF634 001AF634 2D282002 */  daddu      $5, $17, $0
    /* AF638 001AF638 B001A627 */  addiu      $6, $29, 0x1B0
    /* AF63C 001AF63C 01000724 */  addiu      $7, $0, 0x1
    /* AF640 001AF640 2D40E000 */  daddu      $8, $7, $0
    /* AF644 001AF644 B8CD070C */  jal        func_001f36e0
    /* AF648 001AF648 00000000 */   nop
    /* AF64C 001AF64C 2D204000 */  daddu      $4, $2, $0
    /* AF650 001AF650 04000324 */  addiu      $3, $0, 0x4
    /* AF654 001AF654 000043A0 */  sb         $3, 0x0($2)
    /* AF658 001AF658 580043DE */  ld         $3, 0x58($18)
    /* AF65C 001AF65C 080043FC */  sd         $3, 0x8($2)
    /* AF660 001AF660 600050FC */  sd         $16, 0x60($2)
    /* AF664 001AF664 01000524 */  addiu      $5, $0, 0x1
    /* AF668 001AF668 6451060C */  jal        func_00194590
    /* AF66C 001AF66C 00000000 */   nop
    /* AF670 001AF670 C000A27B */  lq         $2, 0xC0($29)
    /* AF674 001AF674 00004294 */  lhu        $2, 0x0($2)
    /* AF678 001AF678 02004230 */  andi       $2, $2, 0x2
    /* AF67C 001AF67C 1E004010 */  beqz       $2, .L001AF6F8
    /* AF680 001AF680 00000000 */   nop
    /* AF684 001AF684 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* AF688 001AF688 00608244 */  mtc1       $2, $f12
    /* AF68C 001AF68C 3000248E */  lw         $4, 0x30($17)
    /* AF690 001AF690 0B000524 */  addiu      $5, $0, 0xB
    /* AF694 001AF694 2D300000 */  daddu      $6, $0, $0
    /* AF698 001AF698 2D380000 */  daddu      $7, $0, $0
    /* AF69C 001AF69C B867060C */  jal        func_00199ee0
    /* AF6A0 001AF6A0 00000000 */   nop
    /* AF6A4 001AF6A4 2D204000 */  daddu      $4, $2, $0
    /* AF6A8 001AF6A8 04000324 */  addiu      $3, $0, 0x4
    /* AF6AC 001AF6AC 000043A0 */  sb         $3, 0x0($2)
    /* AF6B0 001AF6B0 580043DE */  ld         $3, 0x58($18)
    /* AF6B4 001AF6B4 080043FC */  sd         $3, 0x8($2)
    /* AF6B8 001AF6B8 600050FC */  sd         $16, 0x60($2)
    /* AF6BC 001AF6BC 2D280000 */  daddu      $5, $0, $0
    /* AF6C0 001AF6C0 6451060C */  jal        func_00194590
    /* AF6C4 001AF6C4 00000000 */   nop
    /* AF6C8 001AF6C8 3000248E */  lw         $4, 0x30($17)
    /* AF6CC 001AF6CC 606A060C */  jal        func_0019a980
    /* AF6D0 001AF6D0 00000000 */   nop
    /* AF6D4 001AF6D4 2D204000 */  daddu      $4, $2, $0
    /* AF6D8 001AF6D8 04000324 */  addiu      $3, $0, 0x4
    /* AF6DC 001AF6DC 000043A0 */  sb         $3, 0x0($2)
    /* AF6E0 001AF6E0 580043DE */  ld         $3, 0x58($18)
    /* AF6E4 001AF6E4 080043FC */  sd         $3, 0x8($2)
    /* AF6E8 001AF6E8 600050FC */  sd         $16, 0x60($2)
    /* AF6EC 001AF6EC 2D280000 */  daddu      $5, $0, $0
    /* AF6F0 001AF6F0 6451060C */  jal        func_00194590
    /* AF6F4 001AF6F4 00000000 */   nop
  .L001AF6F8:
    /* AF6F8 001AF6F8 0000A0FF */  sd         $0, 0x0($29)
    /* AF6FC 001AF6FC D9002A92 */  lbu        $10, 0xD9($17)
    /* AF700 001AF700 3000848E */  lw         $4, 0x30($20)
    /* AF704 001AF704 3000658E */  lw         $5, 0x30($19)
    /* AF708 001AF708 0001A68F */  lw         $6, 0x100($29)
    /* AF70C 001AF70C DC002796 */  lhu        $7, 0xDC($17)
    /* AF710 001AF710 DE002896 */  lhu        $8, 0xDE($17)
    /* AF714 001AF714 2D48C002 */  daddu      $9, $22, $0
    /* AF718 001AF718 E000AB8F */  lw         $11, 0xE0($29)
    /* AF71C 001AF71C 7807080C */  jal        func_00201de0
    /* AF720 001AF720 00000000 */   nop
    /* AF724 001AF724 2D204000 */  daddu      $4, $2, $0
    /* AF728 001AF728 05000324 */  addiu      $3, $0, 0x5
    /* AF72C 001AF72C 000043A0 */  sb         $3, 0x0($2)
    /* AF730 001AF730 580043DE */  ld         $3, 0x58($18)
    /* AF734 001AF734 080043FC */  sd         $3, 0x8($2)
    /* AF738 001AF738 47004390 */  lbu        $3, 0x47($2)
    /* AF73C 001AF73C DF006330 */  andi       $3, $3, 0xDF
    /* AF740 001AF740 470043A0 */  sb         $3, 0x47($2)
    /* AF744 001AF744 600050FC */  sd         $16, 0x60($2)
    /* AF748 001AF748 03000524 */  addiu      $5, $0, 0x3
    /* AF74C 001AF74C 6451060C */  jal        func_00194590
    /* AF750 001AF750 00000000 */   nop
    /* AF754 001AF754 0100C226 */  addiu      $2, $22, 0x1
    /* AF758 001AF758 FFFF5630 */  andi       $22, $2, 0xFFFF
  .L001AF75C:
    /* AF75C 001AF75C FFFFC232 */  andi       $2, $22, 0xFFFF
    /* AF760 001AF760 B000A27F */  sq         $2, 0xB0($29)
    /* AF764 001AF764 D9002392 */  lbu        $3, 0xD9($17)
    /* AF768 001AF768 2A104300 */  slt        $2, $2, $3
    /* AF76C 001AF76C 32FF4014 */  bnez       $2, .L001AF438
    /* AF770 001AF770 00000000 */   nop
    /* AF774 001AF774 1001A397 */  lhu        $3, 0x110($29)
    /* AF778 001AF778 D000A27B */  lq         $2, 0xD0($29)
    /* AF77C 001AF77C 21106200 */  addu       $2, $3, $2
    /* AF780 001AF780 1001A2A7 */  sh         $2, 0x110($29)
    /* AF784 001AF784 0100E226 */  addiu      $2, $23, 0x1
    /* AF788 001AF788 FFFF5730 */  andi       $23, $2, 0xFFFF
  .L001AF78C:
    /* AF78C 001AF78C FFFFE232 */  andi       $2, $23, 0xFFFF
    /* AF790 001AF790 F000A2AF */  sw         $2, 0xF0($29)
    /* AF794 001AF794 6A008396 */  lhu        $3, 0x6A($20)
    /* AF798 001AF798 2A104300 */  slt        $2, $2, $3
    /* AF79C 001AF79C C1FE4014 */  bnez       $2, .L001AF2A4
    /* AF7A0 001AF7A0 00000000 */   nop
    /* AF7A4 001AF7A4 ACB3828F */  lw         $2, -0x4C54($28)
    /* AF7A8 001AF7A8 7801518C */  lw         $17, 0x178($2)
    /* AF7AC 001AF7AC 22000010 */  b          .L001AF838
    /* AF7B0 001AF7B0 00000000 */   nop
  .L001AF7B4:
    /* AF7B4 001AF7B4 640A248E */  lw         $4, 0xA64($17)
    /* AF7B8 001AF7B8 1000023C */  lui        $2, (0x100117 >> 16)
    /* AF7BC 001AF7BC 17014534 */  ori        $5, $2, (0x100117 & 0xFFFF)
    /* AF7C0 001AF7C0 C4C9080C */  jal        func_00232710
    /* AF7C4 001AF7C4 00000000 */   nop
    /* AF7C8 001AF7C8 07004014 */  bnez       $2, .L001AF7E8
    /* AF7CC 001AF7CC 00000000 */   nop
    /* AF7D0 001AF7D0 640A248E */  lw         $4, 0xA64($17)
    /* AF7D4 001AF7D4 2D280000 */  daddu      $5, $0, $0
    /* AF7D8 001AF7D8 3C0A090C */  jal        func_002428f0
    /* AF7DC 001AF7DC 00000000 */   nop
    /* AF7E0 001AF7E0 14004010 */  beqz       $2, .L001AF834
    /* AF7E4 001AF7E4 00000000 */   nop
  .L001AF7E8:
    /* AF7E8 001AF7E8 2D202002 */  daddu      $4, $17, $0
    /* AF7EC 001AF7EC FFFF0524 */  addiu      $5, $0, -0x1
    /* AF7F0 001AF7F0 0C000624 */  addiu      $6, $0, 0xC
    /* AF7F4 001AF7F4 2D380000 */  daddu      $7, $0, $0
    /* AF7F8 001AF7F8 03000824 */  addiu      $8, $0, 0x3
    /* AF7FC 001AF7FC 2D480000 */  daddu      $9, $0, $0
    /* AF800 001AF800 F86E060C */  jal        func_0019bbe0
    /* AF804 001AF804 00000000 */   nop
    /* AF808 001AF808 2D204000 */  daddu      $4, $2, $0
    /* AF80C 001AF80C 0B000324 */  addiu      $3, $0, 0xB
    /* AF810 001AF810 000043A0 */  sb         $3, 0x0($2)
    /* AF814 001AF814 5800A3DE */  ld         $3, 0x58($21)
    /* AF818 001AF818 080043FC */  sd         $3, 0x8($2)
    /* AF81C 001AF81C 06000324 */  addiu      $3, $0, 0x6
    /* AF820 001AF820 480043A4 */  sh         $3, 0x48($2)
    /* AF824 001AF824 600050FC */  sd         $16, 0x60($2)
    /* AF828 001AF828 2D280000 */  daddu      $5, $0, $0
    /* AF82C 001AF82C 6451060C */  jal        func_00194590
    /* AF830 001AF830 00000000 */   nop
  .L001AF834:
    /* AF834 001AF834 6C0A318E */  lw         $17, 0xA6C($17)
  .L001AF838:
    /* AF838 001AF838 DEFF2016 */  bnez       $17, .L001AF7B4
    /* AF83C 001AF83C 00000000 */   nop
    /* AF840 001AF840 10000424 */  addiu      $4, $0, 0x10
    /* AF844 001AF844 88DF060C */  jal        func_001b7e20
    /* AF848 001AF848 00000000 */   nop
    /* AF84C 001AF84C 2D204000 */  daddu      $4, $2, $0
    /* AF850 001AF850 04000324 */  addiu      $3, $0, 0x4
    /* AF854 001AF854 000043A0 */  sb         $3, 0x0($2)
    /* AF858 001AF858 580043DE */  ld         $3, 0x58($18)
    /* AF85C 001AF85C 080043FC */  sd         $3, 0x8($2)
    /* AF860 001AF860 47004390 */  lbu        $3, 0x47($2)
    /* AF864 001AF864 DF006330 */  andi       $3, $3, 0xDF
    /* AF868 001AF868 470043A0 */  sb         $3, 0x47($2)
    /* AF86C 001AF86C 600050FC */  sd         $16, 0x60($2)
    /* AF870 001AF870 01000524 */  addiu      $5, $0, 0x1
    /* AF874 001AF874 6451060C */  jal        func_00194590
    /* AF878 001AF878 00000000 */   nop
    /* AF87C 001AF87C 10000424 */  addiu      $4, $0, 0x10
    /* AF880 001AF880 2D280000 */  daddu      $5, $0, $0
    /* AF884 001AF884 D8E4060C */  jal        func_001b9360
    /* AF888 001AF888 00000000 */   nop
    /* AF88C 001AF88C 2D204000 */  daddu      $4, $2, $0
    /* AF890 001AF890 04000324 */  addiu      $3, $0, 0x4
    /* AF894 001AF894 000043A0 */  sb         $3, 0x0($2)
    /* AF898 001AF898 580043DE */  ld         $3, 0x58($18)
    /* AF89C 001AF89C 080043FC */  sd         $3, 0x8($2)
    /* AF8A0 001AF8A0 47004390 */  lbu        $3, 0x47($2)
    /* AF8A4 001AF8A4 DF006330 */  andi       $3, $3, 0xDF
    /* AF8A8 001AF8A8 470043A0 */  sb         $3, 0x47($2)
    /* AF8AC 001AF8AC 600050FC */  sd         $16, 0x60($2)
    /* AF8B0 001AF8B0 01000524 */  addiu      $5, $0, 0x1
    /* AF8B4 001AF8B4 6451060C */  jal        func_00194590
    /* AF8B8 001AF8B8 00000000 */   nop
    /* AF8BC 001AF8BC 10000424 */  addiu      $4, $0, 0x10
    /* AF8C0 001AF8C0 68E6060C */  jal        func_001b99a0
    /* AF8C4 001AF8C4 00000000 */   nop
    /* AF8C8 001AF8C8 2D204000 */  daddu      $4, $2, $0
    /* AF8CC 001AF8CC 04000324 */  addiu      $3, $0, 0x4
    /* AF8D0 001AF8D0 000043A0 */  sb         $3, 0x0($2)
    /* AF8D4 001AF8D4 580043DE */  ld         $3, 0x58($18)
    /* AF8D8 001AF8D8 080043FC */  sd         $3, 0x8($2)
    /* AF8DC 001AF8DC 47004390 */  lbu        $3, 0x47($2)
    /* AF8E0 001AF8E0 DF006330 */  andi       $3, $3, 0xDF
    /* AF8E4 001AF8E4 470043A0 */  sb         $3, 0x47($2)
    /* AF8E8 001AF8E8 600050FC */  sd         $16, 0x60($2)
    /* AF8EC 001AF8EC 01000524 */  addiu      $5, $0, 0x1
    /* AF8F0 001AF8F0 6451060C */  jal        func_00194590
    /* AF8F4 001AF8F4 00000000 */   nop
    /* AF8F8 001AF8F8 08000424 */  addiu      $4, $0, 0x8
    /* AF8FC 001AF8FC 24E8060C */  jal        func_001ba090
    /* AF900 001AF900 00000000 */   nop
    /* AF904 001AF904 2D204000 */  daddu      $4, $2, $0
    /* AF908 001AF908 04000324 */  addiu      $3, $0, 0x4
    /* AF90C 001AF90C 000043A0 */  sb         $3, 0x0($2)
    /* AF910 001AF910 5800A3DE */  ld         $3, 0x58($21)
    /* AF914 001AF914 080043FC */  sd         $3, 0x8($2)
    /* AF918 001AF918 47004390 */  lbu        $3, 0x47($2)
    /* AF91C 001AF91C DF006330 */  andi       $3, $3, 0xDF
    /* AF920 001AF920 470043A0 */  sb         $3, 0x47($2)
    /* AF924 001AF924 600050FC */  sd         $16, 0x60($2)
    /* AF928 001AF928 2D280000 */  daddu      $5, $0, $0
    /* AF92C 001AF92C 6451060C */  jal        func_00194590
    /* AF930 001AF930 00000000 */   nop
    /* AF934 001AF934 2D200000 */  daddu      $4, $0, $0
    /* AF938 001AF938 2D280000 */  daddu      $5, $0, $0
    /* AF93C 001AF93C 2D300000 */  daddu      $6, $0, $0
    /* AF940 001AF940 FC5E070C */  jal        func_001d7bf0
    /* AF944 001AF944 00000000 */   nop
    /* AF948 001AF948 2D204000 */  daddu      $4, $2, $0
    /* AF94C 001AF94C 04000524 */  addiu      $5, $0, 0x4
    /* AF950 001AF950 000045A0 */  sb         $5, 0x0($2)
    /* AF954 001AF954 5800A3DE */  ld         $3, 0x58($21)
    /* AF958 001AF958 080043FC */  sd         $3, 0x8($2)
    /* AF95C 001AF95C 100045A0 */  sb         $5, 0x10($2)
    /* AF960 001AF960 2801A38F */  lw         $3, 0x128($29)
    /* AF964 001AF964 580063DC */  ld         $3, 0x58($3)
    /* AF968 001AF968 180043FC */  sd         $3, 0x18($2)
    /* AF96C 001AF96C 600050FC */  sd         $16, 0x60($2)
    /* AF970 001AF970 01000524 */  addiu      $5, $0, 0x1
    /* AF974 001AF974 6451060C */  jal        func_00194590
    /* AF978 001AF978 00000000 */   nop
    /* AF97C 001AF97C 2401A48F */  lw         $4, 0x124($29)
    /* AF980 001AF980 804F070C */  jal        func_001d3e00
    /* AF984 001AF984 00000000 */   nop
    /* AF988 001AF988 2D208002 */  daddu      $4, $20, $0
    /* AF98C 001AF98C 20000524 */  addiu      $5, $0, 0x20
    /* AF990 001AF990 00C2060C */  jal        func_001b0800
    /* AF994 001AF994 00000000 */   nop
    /* AF998 001AF998 A000BFDF */  ld         $31, 0xA0($29)
    /* AF99C 001AF99C 9000BE7B */  lq         $30, 0x90($29)
    /* AF9A0 001AF9A0 8000B77B */  lq         $23, 0x80($29)
    /* AF9A4 001AF9A4 7000B67B */  lq         $22, 0x70($29)
    /* AF9A8 001AF9A8 6000B57B */  lq         $21, 0x60($29)
    /* AF9AC 001AF9AC 5000B47B */  lq         $20, 0x50($29)
    /* AF9B0 001AF9B0 4000B37B */  lq         $19, 0x40($29)
    /* AF9B4 001AF9B4 3000B27B */  lq         $18, 0x30($29)
    /* AF9B8 001AF9B8 2000B17B */  lq         $17, 0x20($29)
    /* AF9BC 001AF9BC 1000B07B */  lq         $16, 0x10($29)
    /* AF9C0 001AF9C0 F001BD27 */  addiu      $29, $29, 0x1F0
    /* AF9C4 001AF9C4 0800E003 */  jr         $31
    /* AF9C8 001AF9C8 00000000 */   nop
    /* AF9CC 001AF9CC 00000000 */  nop
.size func_001aed50, 0xc80
