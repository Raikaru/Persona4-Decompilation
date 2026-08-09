.section .text
.set noat
.set noreorder
glabel func_001eed10
    /* EED10 001EED10 50FFBD27 */  addiu      $29, $29, -0xB0
    /* EED14 001EED14 9000BFFF */  sd         $31, 0x90($29)
    /* EED18 001EED18 8000B77F */  sq         $23, 0x80($29)
    /* EED1C 001EED1C 7000B67F */  sq         $22, 0x70($29)
    /* EED20 001EED20 6000B57F */  sq         $21, 0x60($29)
    /* EED24 001EED24 5000B47F */  sq         $20, 0x50($29)
    /* EED28 001EED28 4000B37F */  sq         $19, 0x40($29)
    /* EED2C 001EED2C 3000B27F */  sq         $18, 0x30($29)
    /* EED30 001EED30 2000B17F */  sq         $17, 0x20($29)
    /* EED34 001EED34 1000B07F */  sq         $16, 0x10($29)
    /* EED38 001EED38 0000B4E7 */  swc1       $f20, 0x0($29)
    /* EED3C 001EED3C 2DA08000 */  daddu      $20, $4, $0
    /* EED40 001EED40 2D88A000 */  daddu      $17, $5, $0
    /* EED44 001EED44 2D80C000 */  daddu      $16, $6, $0
    /* EED48 001EED48 06650046 */  mov.s      $f20, $f12
    /* EED4C 001EED4C 01000224 */  addiu      $2, $0, 0x1
    /* EED50 001EED50 040482A0 */  sb         $2, 0x404($4)
    /* EED54 001EED54 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* EED58 001EED58 00008244 */  mtc1       $2, $f0
    /* EED5C 001EED5C 00000000 */  nop
    /* EED60 001EED60 02031446 */  mul.s      $f12, $f0, $f20
    /* EED64 001EED64 2D202002 */  daddu      $4, $17, $0
    /* EED68 001EED68 2D280002 */  daddu      $5, $16, $0
    /* EED6C 001EED6C 94B3070C */  jal        func_001ece50
    /* EED70 001EED70 00000000 */   nop
    /* EED74 001EED74 0F004014 */  bnez       $2, .L001EEDB4
    /* EED78 001EED78 00000000 */   nop
    /* EED7C 001EED7C 000021C6 */  lwc1       $f1, 0x0($17)
    /* EED80 001EED80 040020C6 */  lwc1       $f0, 0x4($17)
    /* EED84 001EED84 000081E6 */  swc1       $f1, 0x0($20)
    /* EED88 001EED88 040080E6 */  swc1       $f0, 0x4($20)
    /* EED8C 001EED8C 000001C6 */  lwc1       $f1, 0x0($16)
    /* EED90 001EED90 040000C6 */  lwc1       $f0, 0x4($16)
    /* EED94 001EED94 080081E6 */  swc1       $f1, 0x8($20)
    /* EED98 001EED98 0C0080E6 */  swc1       $f0, 0xC($20)
    /* EED9C 001EED9C 02000224 */  addiu      $2, $0, 0x2
    /* EEDA0 001EEDA0 000482A6 */  sh         $2, 0x400($20)
    /* EEDA4 001EEDA4 040482A2 */  sb         $2, 0x404($20)
    /* EEDA8 001EEDA8 01000224 */  addiu      $2, $0, 0x1
    /* EEDAC 001EEDAC CB000010 */  b          .L001EF0DC
    /* EEDB0 001EEDB0 00000000 */   nop
  .L001EEDB4:
    /* EEDB4 001EEDB4 000480A6 */  sh         $0, 0x400($20)
    /* EEDB8 001EEDB8 ACB3828F */  lw         $2, -0x4C54($28)
    /* EEDBC 001EEDBC 000021C6 */  lwc1       $f1, 0x0($17)
    /* EEDC0 001EEDC0 040020C6 */  lwc1       $f0, 0x4($17)
    /* EEDC4 001EEDC4 E40741E4 */  swc1       $f1, 0x7E4($2)
    /* EEDC8 001EEDC8 E80740E4 */  swc1       $f0, 0x7E8($2)
    /* EEDCC 001EEDCC 000001C6 */  lwc1       $f1, 0x0($16)
    /* EEDD0 001EEDD0 040000C6 */  lwc1       $f0, 0x4($16)
    /* EEDD4 001EEDD4 140941E4 */  swc1       $f1, 0x914($2)
    /* EEDD8 001EEDD8 180940E4 */  swc1       $f0, 0x918($2)
    /* EEDDC 001EEDDC 06A30046 */  mov.s      $f12, $f20
    /* EEDE0 001EEDE0 C0B5070C */  jal        func_001ed700
    /* EEDE4 001EEDE4 00000000 */   nop
    /* EEDE8 001EEDE8 ACB3838F */  lw         $3, -0x4C54($28)
    /* EEDEC 001EEDEC 0C08628C */  lw         $2, 0x80C($3)
    /* EEDF0 001EEDF0 04004010 */  beqz       $2, .L001EEE04
    /* EEDF4 001EEDF4 00000000 */   nop
    /* EEDF8 001EEDF8 3C09628C */  lw         $2, 0x93C($3)
    /* EEDFC 001EEDFC 06004014 */  bnez       $2, .L001EEE18
    /* EEE00 001EEE00 00000000 */   nop
  .L001EEE04:
    /* EEE04 001EEE04 03000224 */  addiu      $2, $0, 0x3
    /* EEE08 001EEE08 040482A2 */  sb         $2, 0x404($20)
    /* EEE0C 001EEE0C 2D100000 */  daddu      $2, $0, $0
    /* EEE10 001EEE10 B2000010 */  b          .L001EF0DC
    /* EEE14 001EEE14 00000000 */   nop
  .L001EEE18:
    /* EEE18 001EEE18 3C0A60AC */  sw         $0, 0xA3C($3)
    /* EEE1C 001EEE1C ACB3828F */  lw         $2, -0x4C54($28)
    /* EEE20 001EEE20 400A40AC */  sw         $0, 0xA40($2)
    /* EEE24 001EEE24 ACB3828F */  lw         $2, -0x4C54($28)
    /* EEE28 001EEE28 F80740AC */  sw         $0, 0x7F8($2)
    /* EEE2C 001EEE2C ACB3828F */  lw         $2, -0x4C54($28)
    /* EEE30 001EEE30 E40741C4 */  lwc1       $f1, 0x7E4($2)
    /* EEE34 001EEE34 140940C4 */  lwc1       $f0, 0x914($2)
    /* EEE38 001EEE38 01080046 */  sub.s      $f0, $f1, $f0
    /* EEE3C 001EEE3C A800A0E7 */  swc1       $f0, 0xA8($29)
    /* EEE40 001EEE40 E80741C4 */  lwc1       $f1, 0x7E8($2)
    /* EEE44 001EEE44 180940C4 */  lwc1       $f0, 0x918($2)
    /* EEE48 001EEE48 01080046 */  sub.s      $f0, $f1, $f0
    /* EEE4C 001EEE4C AC00A0E7 */  swc1       $f0, 0xAC($29)
    /* EEE50 001EEE50 A800A427 */  addiu      $4, $29, 0xA8
    /* EEE54 001EEE54 6C900F0C */  jal        func_003e41b0
    /* EEE58 001EEE58 00000000 */   nop
    /* EEE5C 001EEE5C ACB3828F */  lw         $2, -0x4C54($28)
    /* EEE60 001EEE60 FC0740E4 */  swc1       $f0, 0x7FC($2)
    /* EEE64 001EEE64 ACB3828F */  lw         $2, -0x4C54($28)
    /* EEE68 001EEE68 080840AC */  sw         $0, 0x808($2)
    /* EEE6C 001EEE6C ACB3838F */  lw         $3, -0x4C54($28)
    /* EEE70 001EEE70 3C0A628C */  lw         $2, 0xA3C($3)
    /* EEE74 001EEE74 000862AC */  sw         $2, 0x800($3)
    /* EEE78 001EEE78 ACB3838F */  lw         $3, -0x4C54($28)
    /* EEE7C 001EEE7C DC076224 */  addiu      $2, $3, 0x7DC
    /* EEE80 001EEE80 3C0A62AC */  sw         $2, 0xA3C($3)
    /* EEE84 001EEE84 2D900000 */  daddu      $18, $0, $0
    /* EEE88 001EEE88 83000010 */  b          .L001EF098
    /* EEE8C 001EEE8C 00000000 */   nop
  .L001EEE90:
    /* EEE90 001EEE90 18BB070C */  jal        func_001eec60
    /* EEE94 001EEE94 00000000 */   nop
    /* EEE98 001EEE98 2D804000 */  daddu      $16, $2, $0
    /* EEE9C 001EEE9C ACB3828F */  lw         $2, -0x4C54($28)
    /* EEEA0 001EEEA0 0C094224 */  addiu      $2, $2, 0x90C
    /* EEEA4 001EEEA4 04000216 */  bne        $16, $2, .L001EEEB8
    /* EEEA8 001EEEA8 00000000 */   nop
    /* EEEAC 001EEEAC 01001224 */  addiu      $18, $0, 0x1
    /* EEEB0 001EEEB0 7D000010 */  b          .L001EF0A8
    /* EEEB4 001EEEB4 00000000 */   nop
  .L001EEEB8:
    /* EEEB8 001EEEB8 2D980000 */  daddu      $19, $0, $0
    /* EEEBC 001EEEBC 6A000010 */  b          .L001EF068
    /* EEEC0 001EEEC0 00000000 */   nop
  .L001EEEC4:
    /* EEEC4 001EEEC4 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* EEEC8 001EEEC8 80100200 */  sll        $2, $2, 2
    /* EEECC 001EEECC 21100202 */  addu       $2, $16, $2
    /* EEED0 001EEED0 1C0001C6 */  lwc1       $f1, 0x1C($16)
    /* EEED4 001EEED4 B00040C4 */  lwc1       $f0, 0xB0($2)
    /* EEED8 001EEED8 00080046 */  add.s      $f0, $f1, $f0
    /* EEEDC 001EEEDC ACB3828F */  lw         $2, -0x4C54($28)
    /* EEEE0 001EEEE0 3C0A448C */  lw         $4, 0xA3C($2)
    /* EEEE4 001EEEE4 07000010 */  b          .L001EEF04
    /* EEEE8 001EEEE8 00000000 */   nop
  .L001EEEEC:
    /* EEEEC 001EEEEC 04008314 */  bne        $4, $3, .L001EEF00
    /* EEEF0 001EEEF0 00000000 */   nop
    /* EEEF4 001EEEF4 01001124 */  addiu      $17, $0, 0x1
    /* EEEF8 001EEEF8 05000010 */  b          .L001EEF10
    /* EEEFC 001EEEFC 00000000 */   nop
  .L001EEF00:
    /* EEF00 001EEF00 2400848C */  lw         $4, 0x24($4)
  .L001EEF04:
    /* EEF04 001EEF04 F9FF8014 */  bnez       $4, .L001EEEEC
    /* EEF08 001EEF08 00000000 */   nop
    /* EEF0C 001EEF0C 2D880000 */  daddu      $17, $0, $0
  .L001EEF10:
    /* EEF10 001EEF10 400A428C */  lw         $2, 0xA40($2)
    /* EEF14 001EEF14 07000010 */  b          .L001EEF34
    /* EEF18 001EEF18 00000000 */   nop
  .L001EEF1C:
    /* EEF1C 001EEF1C 04004314 */  bne        $2, $3, .L001EEF30
    /* EEF20 001EEF20 00000000 */   nop
    /* EEF24 001EEF24 01001524 */  addiu      $21, $0, 0x1
    /* EEF28 001EEF28 05000010 */  b          .L001EEF40
    /* EEF2C 001EEF2C 00000000 */   nop
  .L001EEF30:
    /* EEF30 001EEF30 2800428C */  lw         $2, 0x28($2)
  .L001EEF34:
    /* EEF34 001EEF34 F9FF4014 */  bnez       $2, .L001EEF1C
    /* EEF38 001EEF38 00000000 */   nop
    /* EEF3C 001EEF3C 2DA80000 */  daddu      $21, $0, $0
  .L001EEF40:
    /* EEF40 001EEF40 03002016 */  bnez       $17, .L001EEF50
    /* EEF44 001EEF44 00000000 */   nop
    /* EEF48 001EEF48 0400A012 */  beqz       $21, .L001EEF5C
    /* EEF4C 001EEF4C 00000000 */   nop
  .L001EEF50:
    /* EEF50 001EEF50 36080046 */  c.le.s     $f1, $f0
    /* EEF54 001EEF54 42000145 */  bc1t       .L001EF060
    /* EEF58 001EEF58 00000000 */   nop
  .L001EEF5C:
    /* EEF5C 001EEF5C FFFF6232 */  andi       $2, $19, 0xFFFF
    /* EEF60 001EEF60 80100200 */  sll        $2, $2, 2
    /* EEF64 001EEF64 21200202 */  addu       $4, $16, $2
    /* EEF68 001EEF68 30009624 */  addiu      $22, $4, 0x30
    /* EEF6C 001EEF6C 1C0060E4 */  swc1       $f0, 0x1C($3)
    /* EEF70 001EEF70 3000828C */  lw         $2, 0x30($4)
    /* EEF74 001EEF74 200040E4 */  swc1       $f0, 0x20($2)
    /* EEF78 001EEF78 ACB3838F */  lw         $3, -0x4C54($28)
    /* EEF7C 001EEF7C 3000828C */  lw         $2, 0x30($4)
    /* EEF80 001EEF80 080041C4 */  lwc1       $f1, 0x8($2)
    /* EEF84 001EEF84 140960C4 */  lwc1       $f0, 0x914($3)
    /* EEF88 001EEF88 01080046 */  sub.s      $f0, $f1, $f0
    /* EEF8C 001EEF8C A000A0E7 */  swc1       $f0, 0xA0($29)
    /* EEF90 001EEF90 0C0041C4 */  lwc1       $f1, 0xC($2)
    /* EEF94 001EEF94 180960C4 */  lwc1       $f0, 0x918($3)
    /* EEF98 001EEF98 01080046 */  sub.s      $f0, $f1, $f0
    /* EEF9C 001EEF9C A400A0E7 */  swc1       $f0, 0xA4($29)
    /* EEFA0 001EEFA0 A000A427 */  addiu      $4, $29, 0xA0
    /* EEFA4 001EEFA4 6C900F0C */  jal        func_003e41b0
    /* EEFA8 001EEFA8 00000000 */   nop
    /* EEFAC 001EEFAC 0000C28E */  lw         $2, 0x0($22)
    /* EEFB0 001EEFB0 200041C4 */  lwc1       $f1, 0x20($2)
    /* EEFB4 001EEFB4 00080046 */  add.s      $f0, $f1, $f0
    /* EEFB8 001EEFB8 200040E4 */  swc1       $f0, 0x20($2)
    /* EEFBC 001EEFBC 0000C28E */  lw         $2, 0x0($22)
    /* EEFC0 001EEFC0 2C0050AC */  sw         $16, 0x2C($2)
    /* EEFC4 001EEFC4 1A00A012 */  beqz       $21, .L001EF030
    /* EEFC8 001EEFC8 00000000 */   nop
    /* EEFCC 001EEFCC 0000E48E */  lw         $4, 0x0($23)
    /* EEFD0 001EEFD0 2D280000 */  daddu      $5, $0, $0
    /* EEFD4 001EEFD4 ACB3828F */  lw         $2, -0x4C54($28)
    /* EEFD8 001EEFD8 400A4324 */  addiu      $3, $2, 0xA40
    /* EEFDC 001EEFDC 400A428C */  lw         $2, 0xA40($2)
    /* EEFE0 001EEFE0 05000010 */  b          .L001EEFF8
    /* EEFE4 001EEFE4 00000000 */   nop
  .L001EEFE8:
    /* EEFE8 001EEFE8 07004410 */  beq        $2, $4, .L001EF008
    /* EEFEC 001EEFEC 00000000 */   nop
    /* EEFF0 001EEFF0 2D284000 */  daddu      $5, $2, $0
    /* EEFF4 001EEFF4 2800428C */  lw         $2, 0x28($2)
  .L001EEFF8:
    /* EEFF8 001EEFF8 00000000 */  nop
    /* EEFFC 001EEFFC 00000000 */  nop
    /* EF000 001EF000 F9FF4014 */  bnez       $2, .L001EEFE8
    /* EF004 001EF004 00000000 */   nop
  .L001EF008:
    /* EF008 001EF008 09004010 */  beqz       $2, .L001EF030
    /* EF00C 001EF00C 00000000 */   nop
    /* EF010 001EF010 0500A010 */  beqz       $5, .L001EF028
    /* EF014 001EF014 00000000 */   nop
    /* EF018 001EF018 2800428C */  lw         $2, 0x28($2)
    /* EF01C 001EF01C 2800A2AC */  sw         $2, 0x28($5)
    /* EF020 001EF020 03000010 */  b          .L001EF030
    /* EF024 001EF024 00000000 */   nop
  .L001EF028:
    /* EF028 001EF028 2800428C */  lw         $2, 0x28($2)
    /* EF02C 001EF02C 000062AC */  sw         $2, 0x0($3)
  .L001EF030:
    /* EF030 001EF030 0B002016 */  bnez       $17, .L001EF060
    /* EF034 001EF034 00000000 */   nop
    /* EF038 001EF038 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* EF03C 001EF03C 80100200 */  sll        $2, $2, 2
    /* EF040 001EF040 21200202 */  addu       $4, $16, $2
    /* EF044 001EF044 ACB3828F */  lw         $2, -0x4C54($28)
    /* EF048 001EF048 3C0A438C */  lw         $3, 0xA3C($2)
    /* EF04C 001EF04C 3000828C */  lw         $2, 0x30($4)
    /* EF050 001EF050 240043AC */  sw         $3, 0x24($2)
    /* EF054 001EF054 3000838C */  lw         $3, 0x30($4)
    /* EF058 001EF058 ACB3828F */  lw         $2, -0x4C54($28)
    /* EF05C 001EF05C 3C0A43AC */  sw         $3, 0xA3C($2)
  .L001EF060:
    /* EF060 001EF060 01006226 */  addiu      $2, $19, 0x1
    /* EF064 001EF064 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001EF068:
    /* EF068 001EF068 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* EF06C 001EF06C 80100200 */  sll        $2, $2, 2
    /* EF070 001EF070 21100202 */  addu       $2, $16, $2
    /* EF074 001EF074 30005724 */  addiu      $23, $2, 0x30
    /* EF078 001EF078 3000438C */  lw         $3, 0x30($2)
    /* EF07C 001EF07C 91FF6014 */  bnez       $3, .L001EEEC4
    /* EF080 001EF080 00000000 */   nop
    /* EF084 001EF084 ACB3828F */  lw         $2, -0x4C54($28)
    /* EF088 001EF088 400A428C */  lw         $2, 0xA40($2)
    /* EF08C 001EF08C 280002AE */  sw         $2, 0x28($16)
    /* EF090 001EF090 ACB3828F */  lw         $2, -0x4C54($28)
    /* EF094 001EF094 400A50AC */  sw         $16, 0xA40($2)
  .L001EF098:
    /* EF098 001EF098 ACB3828F */  lw         $2, -0x4C54($28)
    /* EF09C 001EF09C 3C0A428C */  lw         $2, 0xA3C($2)
    /* EF0A0 001EF0A0 7BFF4014 */  bnez       $2, .L001EEE90
    /* EF0A4 001EF0A4 00000000 */   nop
  .L001EF0A8:
    /* EF0A8 001EF0A8 09004012 */  beqz       $18, .L001EF0D0
    /* EF0AC 001EF0AC 00000000 */   nop
    /* EF0B0 001EF0B0 2D208002 */  daddu      $4, $20, $0
    /* EF0B4 001EF0B4 06A30046 */  mov.s      $f12, $f20
    /* EF0B8 001EF0B8 84B9070C */  jal        func_001ee610
    /* EF0BC 001EF0BC 00000000 */   nop
    /* EF0C0 001EF0C0 02000224 */  addiu      $2, $0, 0x2
    /* EF0C4 001EF0C4 040482A2 */  sb         $2, 0x404($20)
    /* EF0C8 001EF0C8 03000010 */  b          .L001EF0D8
    /* EF0CC 001EF0CC 00000000 */   nop
  .L001EF0D0:
    /* EF0D0 001EF0D0 03000224 */  addiu      $2, $0, 0x3
    /* EF0D4 001EF0D4 040482A2 */  sb         $2, 0x404($20)
  .L001EF0D8:
    /* EF0D8 001EF0D8 2D104002 */  daddu      $2, $18, $0
  .L001EF0DC:
    /* EF0DC 001EF0DC 9000BFDF */  ld         $31, 0x90($29)
    /* EF0E0 001EF0E0 8000B77B */  lq         $23, 0x80($29)
    /* EF0E4 001EF0E4 7000B67B */  lq         $22, 0x70($29)
    /* EF0E8 001EF0E8 6000B57B */  lq         $21, 0x60($29)
    /* EF0EC 001EF0EC 5000B47B */  lq         $20, 0x50($29)
    /* EF0F0 001EF0F0 4000B37B */  lq         $19, 0x40($29)
    /* EF0F4 001EF0F4 3000B27B */  lq         $18, 0x30($29)
    /* EF0F8 001EF0F8 2000B17B */  lq         $17, 0x20($29)
    /* EF0FC 001EF0FC 1000B07B */  lq         $16, 0x10($29)
    /* EF100 001EF100 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* EF104 001EF104 B000BD27 */  addiu      $29, $29, 0xB0
    /* EF108 001EF108 0800E003 */  jr         $31
    /* EF10C 001EF10C 00000000 */   nop
.size func_001eed10, 0x400
