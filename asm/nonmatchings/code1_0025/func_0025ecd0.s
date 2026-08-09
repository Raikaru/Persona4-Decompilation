.section .text
.set noat
.set noreorder
glabel func_0025ecd0
    /* 15ECD0 0025ECD0 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 15ECD4 0025ECD4 B000BFFF */  sd         $31, 0xB0($29)
    /* 15ECD8 0025ECD8 A000BE7F */  sq         $30, 0xA0($29)
    /* 15ECDC 0025ECDC 9000B77F */  sq         $23, 0x90($29)
    /* 15ECE0 0025ECE0 8000B67F */  sq         $22, 0x80($29)
    /* 15ECE4 0025ECE4 7000B57F */  sq         $21, 0x70($29)
    /* 15ECE8 0025ECE8 6000B47F */  sq         $20, 0x60($29)
    /* 15ECEC 0025ECEC 5000B37F */  sq         $19, 0x50($29)
    /* 15ECF0 0025ECF0 4000B27F */  sq         $18, 0x40($29)
    /* 15ECF4 0025ECF4 3000B17F */  sq         $17, 0x30($29)
    /* 15ECF8 0025ECF8 2000B07F */  sq         $16, 0x20($29)
    /* 15ECFC 0025ECFC 1400B9E7 */  swc1       $f25, 0x14($29)
    /* 15ED00 0025ED00 1000B8E7 */  swc1       $f24, 0x10($29)
    /* 15ED04 0025ED04 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 15ED08 0025ED08 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 15ED0C 0025ED0C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 15ED10 0025ED10 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 15ED14 0025ED14 46660046 */  mov.s      $f25, $f12
    /* 15ED18 0025ED18 066E0046 */  mov.s      $f24, $f13
    /* 15ED1C 0025ED1C C6750046 */  mov.s      $f23, $f14
    /* 15ED20 0025ED20 2DA88000 */  daddu      $21, $4, $0
    /* 15ED24 0025ED24 2DA0A000 */  daddu      $20, $5, $0
    /* 15ED28 0025ED28 2D98C000 */  daddu      $19, $6, $0
    /* 15ED2C 0025ED2C 2D90E000 */  daddu      $18, $7, $0
    /* 15ED30 0025ED30 2D880001 */  daddu      $17, $8, $0
    /* 15ED34 0025ED34 2DB02001 */  daddu      $22, $9, $0
    /* 15ED38 0025ED38 2DB84001 */  daddu      $23, $10, $0
    /* 15ED3C 0025ED3C 867D0046 */  mov.s      $f22, $f15
    /* 15ED40 0025ED40 46850046 */  mov.s      $f21, $f16
    /* 15ED44 0025ED44 068D0046 */  mov.s      $f20, $f17
    /* 15ED48 0025ED48 2DF06001 */  daddu      $30, $11, $0
    /* 15ED4C 0025ED4C 6482110C */  jal        func_00460990
    /* 15ED50 0025ED50 00000000 */   nop
    /* 15ED54 0025ED54 2D804000 */  daddu      $16, $2, $0
    /* 15ED58 0025ED58 2D204002 */  daddu      $4, $18, $0
    /* 15ED5C 0025ED5C 2D286002 */  daddu      $5, $19, $0
    /* 15ED60 0025ED60 80B4110C */  jal        func_0046d200
    /* 15ED64 0025ED64 00000000 */   nop
    /* 15ED68 0025ED68 2D204000 */  daddu      $4, $2, $0
    /* 15ED6C 0025ED6C 080059E4 */  swc1       $f25, 0x8($2)
    /* 15ED70 0025ED70 0C0058E4 */  swc1       $f24, 0xC($2)
    /* 15ED74 0025ED74 240057E4 */  swc1       $f23, 0x24($2)
    /* 15ED78 0025ED78 FF000524 */  addiu      $5, $0, 0xFF
    /* 15ED7C 0025ED7C FF008332 */  andi       $3, $20, 0xFF
    /* 15ED80 0025ED80 2318A300 */  subu       $3, $5, $3
    /* 15ED84 0025ED84 110043A0 */  sb         $3, 0x11($2)
    /* 15ED88 0025ED88 021C1500 */  srl        $3, $21, 16
    /* 15ED8C 0025ED8C 280043A0 */  sb         $3, 0x28($2)
    /* 15ED90 0025ED90 021A1500 */  srl        $3, $21, 8
    /* 15ED94 0025ED94 290043A0 */  sb         $3, 0x29($2)
    /* 15ED98 0025ED98 2A0055A0 */  sb         $21, 0x2A($2)
    /* 15ED9C 0025ED9C 1C0056A4 */  sh         $22, 0x1C($2)
    /* 15EDA0 0025EDA0 1E0057A4 */  sh         $23, 0x1E($2)
    /* 15EDA4 0025EDA4 180056E4 */  swc1       $f22, 0x18($2)
    /* 15EDA8 0025EDA8 8045023C */  lui        $2, (0x45800000 >> 16)
    /* 15EDAC 0025EDAC 00008244 */  mtc1       $2, $f0
    /* 15EDB0 0025EDB0 00000000 */  nop
    /* 15EDB4 0025EDB4 42001546 */  mul.s      $f1, $f0, $f21
    /* 15EDB8 0025EDB8 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 15EDBC 0025EDBC 00008244 */  mtc1       $2, $f0
    /* 15EDC0 0025EDC0 00000000 */  nop
    /* 15EDC4 0025EDC4 36000146 */  c.le.s     $f0, $f1
    /* 15EDC8 0025EDC8 07000145 */  bc1t       .L0025EDE8
    /* 15EDCC 0025EDCC 00000000 */   nop
    /* 15EDD0 0025EDD0 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 15EDD4 0025EDD4 00000344 */  mfc1       $3, $f0
    /* 15EDD8 0025EDD8 00000000 */  nop
    /* 15EDDC 0025EDDC FFFF6330 */  andi       $3, $3, 0xFFFF
    /* 15EDE0 0025EDE0 07000010 */  b          .L0025EE00
    /* 15EDE4 0025EDE4 00000000 */   nop
  .L0025EDE8:
    /* 15EDE8 0025EDE8 01080046 */  sub.s      $f0, $f1, $f0
    /* 15EDEC 0025EDEC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 15EDF0 0025EDF0 00000344 */  mfc1       $3, $f0
    /* 15EDF4 0025EDF4 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 15EDF8 0025EDF8 25186200 */  or         $3, $3, $2
    /* 15EDFC 0025EDFC FFFF6330 */  andi       $3, $3, 0xFFFF
  .L0025EE00:
    /* 15EE00 0025EE00 200083A4 */  sh         $3, 0x20($4)
    /* 15EE04 0025EE04 8045023C */  lui        $2, (0x45800000 >> 16)
    /* 15EE08 0025EE08 00008244 */  mtc1       $2, $f0
    /* 15EE0C 0025EE0C 00000000 */  nop
    /* 15EE10 0025EE10 42001446 */  mul.s      $f1, $f0, $f20
    /* 15EE14 0025EE14 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 15EE18 0025EE18 00008244 */  mtc1       $2, $f0
    /* 15EE1C 0025EE1C 00000000 */  nop
    /* 15EE20 0025EE20 36000146 */  c.le.s     $f0, $f1
    /* 15EE24 0025EE24 07000145 */  bc1t       .L0025EE44
    /* 15EE28 0025EE28 00000000 */   nop
    /* 15EE2C 0025EE2C 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 15EE30 0025EE30 00000344 */  mfc1       $3, $f0
    /* 15EE34 0025EE34 00000000 */  nop
    /* 15EE38 0025EE38 FFFF6330 */  andi       $3, $3, 0xFFFF
    /* 15EE3C 0025EE3C 07000010 */  b          .L0025EE5C
    /* 15EE40 0025EE40 00000000 */   nop
  .L0025EE44:
    /* 15EE44 0025EE44 01080046 */  sub.s      $f0, $f1, $f0
    /* 15EE48 0025EE48 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 15EE4C 0025EE4C 00000344 */  mfc1       $3, $f0
    /* 15EE50 0025EE50 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 15EE54 0025EE54 25186200 */  or         $3, $3, $2
    /* 15EE58 0025EE58 FFFF6330 */  andi       $3, $3, 0xFFFF
  .L0025EE5C:
    /* 15EE5C 0025EE5C 220083A4 */  sh         $3, 0x22($4)
    /* 15EE60 0025EE60 20008294 */  lhu        $2, 0x20($4)
    /* 15EE64 0025EE64 17004010 */  beqz       $2, .L0025EEC4
    /* 15EE68 0025EE68 00000000 */   nop
    /* 15EE6C 0025EE6C 22008294 */  lhu        $2, 0x22($4)
    /* 15EE70 0025EE70 14004010 */  beqz       $2, .L0025EEC4
    /* 15EE74 0025EE74 00000000 */   nop
    /* 15EE78 0025EE78 01000224 */  addiu      $2, $0, 0x1
    /* 15EE7C 0025EE7C 07002216 */  bne        $17, $2, .L0025EE9C
    /* 15EE80 0025EE80 00000000 */   nop
    /* 15EE84 0025EE84 2600023C */  lui        $2, %hi(func_0025ec10)
    /* 15EE88 0025EE88 10EC4224 */  addiu      $2, $2, %lo(func_0025ec10)
    /* 15EE8C 0025EE8C 080002AE */  sw         $2, 0x8($16)
    /* 15EE90 0025EE90 100004AE */  sw         $4, 0x10($16)
    /* 15EE94 0025EE94 05000010 */  b          .L0025EEAC
    /* 15EE98 0025EE98 00000000 */   nop
  .L0025EE9C:
    /* 15EE9C 0025EE9C 2600023C */  lui        $2, %hi(func_0025ec50)
    /* 15EEA0 0025EEA0 50EC4224 */  addiu      $2, $2, %lo(func_0025ec50)
    /* 15EEA4 0025EEA4 080002AE */  sw         $2, 0x8($16)
    /* 15EEA8 0025EEA8 100004AE */  sw         $4, 0x10($16)
  .L0025EEAC:
    /* 15EEAC 0025EEAC 2D20C003 */  daddu      $4, $30, $0
    /* 15EEB0 0025EEB0 2D280002 */  daddu      $5, $16, $0
    /* 15EEB4 0025EEB4 B082110C */  jal        func_00460ac0
    /* 15EEB8 0025EEB8 00000000 */   nop
    /* 15EEBC 0025EEBC 03000010 */  b          .L0025EECC
    /* 15EEC0 0025EEC0 00000000 */   nop
  .L0025EEC4:
    /* 15EEC4 0025EEC4 A0B4110C */  jal        func_0046d280
    /* 15EEC8 0025EEC8 00000000 */   nop
  .L0025EECC:
    /* 15EECC 0025EECC 2D100000 */  daddu      $2, $0, $0
    /* 15EED0 0025EED0 B000BFDF */  ld         $31, 0xB0($29)
    /* 15EED4 0025EED4 A000BE7B */  lq         $30, 0xA0($29)
    /* 15EED8 0025EED8 9000B77B */  lq         $23, 0x90($29)
    /* 15EEDC 0025EEDC 8000B67B */  lq         $22, 0x80($29)
    /* 15EEE0 0025EEE0 7000B57B */  lq         $21, 0x70($29)
    /* 15EEE4 0025EEE4 6000B47B */  lq         $20, 0x60($29)
    /* 15EEE8 0025EEE8 5000B37B */  lq         $19, 0x50($29)
    /* 15EEEC 0025EEEC 4000B27B */  lq         $18, 0x40($29)
    /* 15EEF0 0025EEF0 3000B17B */  lq         $17, 0x30($29)
    /* 15EEF4 0025EEF4 2000B07B */  lq         $16, 0x20($29)
    /* 15EEF8 0025EEF8 1400B9C7 */  lwc1       $f25, 0x14($29)
    /* 15EEFC 0025EEFC 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* 15EF00 0025EF00 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 15EF04 0025EF04 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 15EF08 0025EF08 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 15EF0C 0025EF0C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 15EF10 0025EF10 C000BD27 */  addiu      $29, $29, 0xC0
    /* 15EF14 0025EF14 0800E003 */  jr         $31
    /* 15EF18 0025EF18 00000000 */   nop
    /* 15EF1C 0025EF1C 00000000 */  nop
.size func_0025ecd0, 0x250
