.section .text
.set noat
.set noreorder
glabel func_0013fb50
    /* 3FB50 0013FB50 90FFBD27 */  addiu      $29, $29, -0x70
    /* 3FB54 0013FB54 6000BFFF */  sd         $31, 0x60($29)
    /* 3FB58 0013FB58 5000B57F */  sq         $21, 0x50($29)
    /* 3FB5C 0013FB5C 4000B47F */  sq         $20, 0x40($29)
    /* 3FB60 0013FB60 3000B37F */  sq         $19, 0x30($29)
    /* 3FB64 0013FB64 2000B27F */  sq         $18, 0x20($29)
    /* 3FB68 0013FB68 1000B17F */  sq         $17, 0x10($29)
    /* 3FB6C 0013FB6C 0000B07F */  sq         $16, 0x0($29)
    /* 3FB70 0013FB70 2DA88000 */  daddu      $21, $4, $0
    /* 3FB74 0013FB74 2D280000 */  daddu      $5, $0, $0
    /* 3FB78 0013FB78 B0180624 */  addiu      $6, $0, 0x18B0
    /* 3FB7C 0013FB7C 72FE100C */  jal        func_0043f9c8
    /* 3FB80 0013FB80 00000000 */   nop
    /* 3FB84 0013FB84 0400A0AE */  sw         $0, 0x4($21)
    /* 3FB88 0013FB88 0800A0AE */  sw         $0, 0x8($21)
    /* 3FB8C 0013FB8C FF000224 */  addiu      $2, $0, 0xFF
    /* 3FB90 0013FB90 0000A2A2 */  sb         $2, 0x0($21)
    /* 3FB94 0013FB94 1400A0AE */  sw         $0, 0x14($21)
    /* 3FB98 0013FB98 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3FB9C 0013FB9C 1800A2AE */  sw         $2, 0x18($21)
    /* 3FBA0 0013FBA0 2D180000 */  daddu      $3, $0, $0
    /* 3FBA4 0013FBA4 07000010 */  b          .L0013FBC4
    /* 3FBA8 0013FBA8 00000000 */   nop
  .L0013FBAC:
    /* 3FBAC 0013FBAC 40100200 */  sll        $2, $2, 1
    /* 3FBB0 0013FBB0 2110A202 */  addu       $2, $21, $2
    /* 3FBB4 0013FBB4 340040A4 */  sh         $0, 0x34($2)
    /* 3FBB8 0013FBB8 01006224 */  addiu      $2, $3, 0x1
    /* 3FBBC 0013FBBC 3C1C0200 */  dsll32     $3, $2, 16
    /* 3FBC0 0013FBC0 3F1C0300 */  dsra32     $3, $3, 16
  .L0013FBC4:
    /* 3FBC4 0013FBC4 3C140300 */  dsll32     $2, $3, 16
    /* 3FBC8 0013FBC8 3F140200 */  dsra32     $2, $2, 16
    /* 3FBCC 0013FBCC F7FF4018 */  blez       $2, .L0013FBAC
    /* 3FBD0 0013FBD0 00000000 */   nop
    /* 3FBD4 0013FBD4 2D380000 */  daddu      $7, $0, $0
    /* 3FBD8 0013FBD8 5F00063C */  lui        $6, %hi(D_005EDEA0)
    /* 3FBDC 0013FBDC A0DEC624 */  addiu      $6, $6, %lo(D_005EDEA0)
    /* 3FBE0 0013FBE0 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 3FBE4 0013FBE4 00088244 */  mtc1       $2, $f1
    /* 3FBE8 0013FBE8 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 3FBEC 0013FBEC 36000010 */  b          .L0013FCC8
    /* 3FBF0 0013FBF0 00000000 */   nop
  .L0013FBF4:
    /* 3FBF4 0013FBF4 3C240700 */  dsll32     $4, $7, 16
    /* 3FBF8 0013FBF8 3F240400 */  dsra32     $4, $4, 16
    /* 3FBFC 0013FBFC C0100400 */  sll        $2, $4, 3
    /* 3FC00 0013FC00 23104400 */  subu       $2, $2, $4
    /* 3FC04 0013FC04 80100200 */  sll        $2, $2, 2
    /* 3FC08 0013FC08 2128C200 */  addu       $5, $6, $2
    /* 3FC0C 0013FC0C 40100400 */  sll        $2, $4, 1
    /* 3FC10 0013FC10 21104400 */  addu       $2, $2, $4
    /* 3FC14 0013FC14 00110200 */  sll        $2, $2, 4
    /* 3FC18 0013FC18 2120A202 */  addu       $4, $21, $2
    /* 3FC1C 0013FC1C 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 3FC20 0013FC20 500080E4 */  swc1       $f0, 0x50($4)
    /* 3FC24 0013FC24 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 3FC28 0013FC28 540080E4 */  swc1       $f0, 0x54($4)
    /* 3FC2C 0013FC2C 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* 3FC30 0013FC30 36080046 */  c.le.s     $f1, $f0
    /* 3FC34 0013FC34 07000145 */  bc1t       .L0013FC54
    /* 3FC38 0013FC38 00000000 */   nop
    /* 3FC3C 0013FC3C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3FC40 0013FC40 00000244 */  mfc1       $2, $f0
    /* 3FC44 0013FC44 00000000 */  nop
    /* 3FC48 0013FC48 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 3FC4C 0013FC4C 07000010 */  b          .L0013FC6C
    /* 3FC50 0013FC50 00000000 */   nop
  .L0013FC54:
    /* 3FC54 0013FC54 01000146 */  sub.s      $f0, $f0, $f1
    /* 3FC58 0013FC58 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3FC5C 0013FC5C 00000244 */  mfc1       $2, $f0
    /* 3FC60 0013FC60 00000000 */  nop
    /* 3FC64 0013FC64 25104300 */  or         $2, $2, $3
    /* 3FC68 0013FC68 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L0013FC6C:
    /* 3FC6C 0013FC6C 600082A4 */  sh         $2, 0x60($4)
    /* 3FC70 0013FC70 0C00A0C4 */  lwc1       $f0, 0xC($5)
    /* 3FC74 0013FC74 36080046 */  c.le.s     $f1, $f0
    /* 3FC78 0013FC78 07000145 */  bc1t       .L0013FC98
    /* 3FC7C 0013FC7C 00000000 */   nop
    /* 3FC80 0013FC80 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3FC84 0013FC84 00000244 */  mfc1       $2, $f0
    /* 3FC88 0013FC88 00000000 */  nop
    /* 3FC8C 0013FC8C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 3FC90 0013FC90 07000010 */  b          .L0013FCB0
    /* 3FC94 0013FC94 00000000 */   nop
  .L0013FC98:
    /* 3FC98 0013FC98 01000146 */  sub.s      $f0, $f0, $f1
    /* 3FC9C 0013FC9C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3FCA0 0013FCA0 00000244 */  mfc1       $2, $f0
    /* 3FCA4 0013FCA4 00000000 */  nop
    /* 3FCA8 0013FCA8 25104300 */  or         $2, $2, $3
    /* 3FCAC 0013FCAC FFFF4230 */  andi       $2, $2, 0xFFFF
  .L0013FCB0:
    /* 3FCB0 0013FCB0 660082A4 */  sh         $2, 0x66($4)
    /* 3FCB4 0013FCB4 1000A290 */  lbu        $2, 0x10($5)
    /* 3FCB8 0013FCB8 5A0082A0 */  sb         $2, 0x5A($4)
    /* 3FCBC 0013FCBC 0100E224 */  addiu      $2, $7, 0x1
    /* 3FCC0 0013FCC0 3C3C0200 */  dsll32     $7, $2, 16
    /* 3FCC4 0013FCC4 3F3C0700 */  dsra32     $7, $7, 16
  .L0013FCC8:
    /* 3FCC8 0013FCC8 3C140700 */  dsll32     $2, $7, 16
    /* 3FCCC 0013FCCC 3F140200 */  dsra32     $2, $2, 16
    /* 3FCD0 0013FCD0 29004228 */  slti       $2, $2, 0x29
    /* 3FCD4 0013FCD4 C7FF4014 */  bnez       $2, .L0013FBF4
    /* 3FCD8 0013FCD8 00000000 */   nop
    /* 3FCDC 0013FCDC 2D380000 */  daddu      $7, $0, $0
    /* 3FCE0 0013FCE0 09000424 */  addiu      $4, $0, 0x9
    /* 3FCE4 0013FCE4 0C000324 */  addiu      $3, $0, 0xC
    /* 3FCE8 0013FCE8 12000010 */  b          .L0013FD34
    /* 3FCEC 0013FCEC 00000000 */   nop
  .L0013FCF0:
    /* 3FCF0 0013FCF0 3C340700 */  dsll32     $6, $7, 16
    /* 3FCF4 0013FCF4 3F340600 */  dsra32     $6, $6, 16
    /* 3FCF8 0013FCF8 80100600 */  sll        $2, $6, 2
    /* 3FCFC 0013FCFC 21104600 */  addu       $2, $2, $6
    /* 3FD00 0013FD00 80100200 */  sll        $2, $2, 2
    /* 3FD04 0013FD04 2128A202 */  addu       $5, $21, $2
    /* 3FD08 0013FD08 1A00C400 */  div        $0, $6, $4
    /* 3FD0C 0013FD0C 10100000 */  mfhi       $2
    /* 3FD10 0013FD10 A40FA2AC */  sw         $2, 0xFA4($5)
    /* 3FD14 0013FD14 AC0FA4AC */  sw         $4, 0xFAC($5)
    /* 3FD18 0013FD18 1A00C400 */  div        $0, $6, $4
    /* 3FD1C 0013FD1C 12100000 */  mflo       $2
    /* 3FD20 0013FD20 A80FA2AC */  sw         $2, 0xFA8($5)
    /* 3FD24 0013FD24 B00FA3AC */  sw         $3, 0xFB0($5)
    /* 3FD28 0013FD28 0100E224 */  addiu      $2, $7, 0x1
    /* 3FD2C 0013FD2C 3C3C0200 */  dsll32     $7, $2, 16
    /* 3FD30 0013FD30 3F3C0700 */  dsra32     $7, $7, 16
  .L0013FD34:
    /* 3FD34 0013FD34 3C140700 */  dsll32     $2, $7, 16
    /* 3FD38 0013FD38 3F140200 */  dsra32     $2, $2, 16
    /* 3FD3C 0013FD3C 6C004228 */  slti       $2, $2, 0x6C
    /* 3FD40 0013FD40 EBFF4014 */  bnez       $2, .L0013FCF0
    /* 3FD44 0013FD44 00000000 */   nop
    /* 3FD48 0013FD48 2200A426 */  addiu      $4, $21, 0x22
    /* 3FD4C 0013FD4C 044F0D0C */  jal        func_00353c10
    /* 3FD50 0013FD50 00000000 */   nop
    /* 3FD54 0013FD54 3200A2A6 */  sh         $2, 0x32($21)
    /* 3FD58 0013FD58 5E00043C */  lui        $4, %hi(D_005E5830)
    /* 3FD5C 0013FD5C 30588424 */  addiu      $4, $4, %lo(D_005E5830)
    /* 3FD60 0013FD60 DCA9110C */  jal        func_0046a770
    /* 3FD64 0013FD64 00000000 */   nop
    /* 3FD68 0013FD68 2DA04000 */  daddu      $20, $2, $0
    /* 3FD6C 0013FD6C 06008016 */  bnez       $20, .L0013FD88
    /* 3FD70 0013FD70 00000000 */   nop
    /* 3FD74 0013FD74 5F00043C */  lui        $4, %hi(D_005EF6C8)
    /* 3FD78 0013FD78 C8F68424 */  addiu      $4, $4, %lo(D_005EF6C8)
    /* 3FD7C 0013FD7C EB010524 */  addiu      $5, $0, 0x1EB
    /* 3FD80 0013FD80 CCB5110C */  jal        func_0046d730
    /* 3FD84 0013FD84 00000000 */   nop
  .L0013FD88:
    /* 3FD88 0013FD88 5E00043C */  lui        $4, %hi(D_005E5850)
    /* 3FD8C 0013FD8C 50588424 */  addiu      $4, $4, %lo(D_005E5850)
    /* 3FD90 0013FD90 DCA9110C */  jal        func_0046a770
    /* 3FD94 0013FD94 00000000 */   nop
    /* 3FD98 0013FD98 2D984000 */  daddu      $19, $2, $0
    /* 3FD9C 0013FD9C 06006016 */  bnez       $19, .L0013FDB8
    /* 3FDA0 0013FDA0 00000000 */   nop
    /* 3FDA4 0013FDA4 5F00043C */  lui        $4, %hi(D_005EF6C8)
    /* 3FDA8 0013FDA8 C8F68424 */  addiu      $4, $4, %lo(D_005EF6C8)
    /* 3FDAC 0013FDAC ED010524 */  addiu      $5, $0, 0x1ED
    /* 3FDB0 0013FDB0 CCB5110C */  jal        func_0046d730
    /* 3FDB4 0013FDB4 00000000 */   nop
  .L0013FDB8:
    /* 3FDB8 0013FDB8 5E00043C */  lui        $4, %hi(D_005E57F0)
    /* 3FDBC 0013FDBC F0578424 */  addiu      $4, $4, %lo(D_005E57F0)
    /* 3FDC0 0013FDC0 DCA9110C */  jal        func_0046a770
    /* 3FDC4 0013FDC4 00000000 */   nop
    /* 3FDC8 0013FDC8 2D904000 */  daddu      $18, $2, $0
    /* 3FDCC 0013FDCC 7418A2AE */  sw         $2, 0x1874($21)
    /* 3FDD0 0013FDD0 06004016 */  bnez       $18, .L0013FDEC
    /* 3FDD4 0013FDD4 00000000 */   nop
    /* 3FDD8 0013FDD8 5F00043C */  lui        $4, %hi(D_005EF6C8)
    /* 3FDDC 0013FDDC C8F68424 */  addiu      $4, $4, %lo(D_005EF6C8)
    /* 3FDE0 0013FDE0 EF010524 */  addiu      $5, $0, 0x1EF
    /* 3FDE4 0013FDE4 CCB5110C */  jal        func_0046d730
    /* 3FDE8 0013FDE8 00000000 */   nop
  .L0013FDEC:
    /* 3FDEC 0013FDEC 5E00043C */  lui        $4, %hi(D_005E5810)
    /* 3FDF0 0013FDF0 10588424 */  addiu      $4, $4, %lo(D_005E5810)
    /* 3FDF4 0013FDF4 DCA9110C */  jal        func_0046a770
    /* 3FDF8 0013FDF8 00000000 */   nop
    /* 3FDFC 0013FDFC 06004014 */  bnez       $2, .L0013FE18
    /* 3FE00 0013FE00 00000000 */   nop
    /* 3FE04 0013FE04 5F00043C */  lui        $4, %hi(D_005EF6C8)
    /* 3FE08 0013FE08 C8F68424 */  addiu      $4, $4, %lo(D_005EF6C8)
    /* 3FE0C 0013FE0C F1010524 */  addiu      $5, $0, 0x1F1
    /* 3FE10 0013FE10 CCB5110C */  jal        func_0046d730
    /* 3FE14 0013FE14 00000000 */   nop
  .L0013FE18:
    /* 3FE18 0013FE18 2D800000 */  daddu      $16, $0, $0
    /* 3FE1C 0013FE1C 3D000010 */  b          .L0013FF14
    /* 3FE20 0013FE20 00000000 */   nop
  .L0013FE24:
    /* 3FE24 0013FE24 03006128 */  slti       $1, $3, 0x3
    /* 3FE28 0013FE28 10002010 */  beqz       $1, .L0013FE6C
    /* 3FE2C 0013FE2C 00000000 */   nop
    /* 3FE30 0013FE30 3C1C1000 */  dsll32     $3, $16, 16
    /* 3FE34 0013FE34 3F1C0300 */  dsra32     $3, $3, 16
    /* 3FE38 0013FE38 80100300 */  sll        $2, $3, 2
    /* 3FE3C 0013FE3C 2110A202 */  addu       $2, $21, $2
    /* 3FE40 0013FE40 10185124 */  addiu      $17, $2, 0x1810
    /* 3FE44 0013FE44 5F00023C */  lui        $2, %hi(D_005EDA00)
    /* 3FE48 0013FE48 00DA4224 */  addiu      $2, $2, %lo(D_005EDA00)
    /* 3FE4C 0013FE4C 21104300 */  addu       $2, $2, $3
    /* 3FE50 0013FE50 00004590 */  lbu        $5, 0x0($2)
    /* 3FE54 0013FE54 2D208002 */  daddu      $4, $20, $0
    /* 3FE58 0013FE58 80B4110C */  jal        func_0046d200
    /* 3FE5C 0013FE5C 00000000 */   nop
    /* 3FE60 0013FE60 000022AE */  sw         $2, 0x0($17)
    /* 3FE64 0013FE64 20000010 */  b          .L0013FEE8
    /* 3FE68 0013FE68 00000000 */   nop
  .L0013FE6C:
    /* 3FE6C 0013FE6C 18006128 */  slti       $1, $3, 0x18
    /* 3FE70 0013FE70 10002010 */  beqz       $1, .L0013FEB4
    /* 3FE74 0013FE74 00000000 */   nop
    /* 3FE78 0013FE78 3C1C1000 */  dsll32     $3, $16, 16
    /* 3FE7C 0013FE7C 3F1C0300 */  dsra32     $3, $3, 16
    /* 3FE80 0013FE80 80100300 */  sll        $2, $3, 2
    /* 3FE84 0013FE84 2110A202 */  addu       $2, $21, $2
    /* 3FE88 0013FE88 10185124 */  addiu      $17, $2, 0x1810
    /* 3FE8C 0013FE8C 5F00023C */  lui        $2, %hi(D_005EDA00)
    /* 3FE90 0013FE90 00DA4224 */  addiu      $2, $2, %lo(D_005EDA00)
    /* 3FE94 0013FE94 21104300 */  addu       $2, $2, $3
    /* 3FE98 0013FE98 00004590 */  lbu        $5, 0x0($2)
    /* 3FE9C 0013FE9C 2D206002 */  daddu      $4, $19, $0
    /* 3FEA0 0013FEA0 80B4110C */  jal        func_0046d200
    /* 3FEA4 0013FEA4 00000000 */   nop
    /* 3FEA8 0013FEA8 000022AE */  sw         $2, 0x0($17)
    /* 3FEAC 0013FEAC 0E000010 */  b          .L0013FEE8
    /* 3FEB0 0013FEB0 00000000 */   nop
  .L0013FEB4:
    /* 3FEB4 0013FEB4 3C1C1000 */  dsll32     $3, $16, 16
    /* 3FEB8 0013FEB8 3F1C0300 */  dsra32     $3, $3, 16
    /* 3FEBC 0013FEBC 80100300 */  sll        $2, $3, 2
    /* 3FEC0 0013FEC0 2110A202 */  addu       $2, $21, $2
    /* 3FEC4 0013FEC4 10185124 */  addiu      $17, $2, 0x1810
    /* 3FEC8 0013FEC8 5F00023C */  lui        $2, %hi(D_005EDA00)
    /* 3FECC 0013FECC 00DA4224 */  addiu      $2, $2, %lo(D_005EDA00)
    /* 3FED0 0013FED0 21104300 */  addu       $2, $2, $3
    /* 3FED4 0013FED4 00004590 */  lbu        $5, 0x0($2)
    /* 3FED8 0013FED8 2D204002 */  daddu      $4, $18, $0
    /* 3FEDC 0013FEDC 80B4110C */  jal        func_0046d200
    /* 3FEE0 0013FEE0 00000000 */   nop
    /* 3FEE4 0013FEE4 000022AE */  sw         $2, 0x0($17)
  .L0013FEE8:
    /* 3FEE8 0013FEE8 0000228E */  lw         $2, 0x0($17)
    /* 3FEEC 0013FEEC 06004014 */  bnez       $2, .L0013FF08
    /* 3FEF0 0013FEF0 00000000 */   nop
    /* 3FEF4 0013FEF4 5F00043C */  lui        $4, %hi(D_005EF6C8)
    /* 3FEF8 0013FEF8 C8F68424 */  addiu      $4, $4, %lo(D_005EF6C8)
    /* 3FEFC 0013FEFC FD010524 */  addiu      $5, $0, 0x1FD
    /* 3FF00 0013FF00 CCB5110C */  jal        func_0046d730
    /* 3FF04 0013FF04 00000000 */   nop
  .L0013FF08:
    /* 3FF08 0013FF08 01000226 */  addiu      $2, $16, 0x1
    /* 3FF0C 0013FF0C 3C840200 */  dsll32     $16, $2, 16
    /* 3FF10 0013FF10 3F841000 */  dsra32     $16, $16, 16
  .L0013FF14:
    /* 3FF14 0013FF14 3C1C1000 */  dsll32     $3, $16, 16
    /* 3FF18 0013FF18 3F1C0300 */  dsra32     $3, $3, 16
    /* 3FF1C 0013FF1C 19006228 */  slti       $2, $3, 0x19
    /* 3FF20 0013FF20 C0FF4014 */  bnez       $2, .L0013FE24
    /* 3FF24 0013FF24 00000000 */   nop
    /* 3FF28 0013FF28 2D200000 */  daddu      $4, $0, $0
    /* 3FF2C 0013FF2C 01000524 */  addiu      $5, $0, 0x1
    /* 3FF30 0013FF30 94520D0C */  jal        func_00354a50
    /* 3FF34 0013FF34 00000000 */   nop
    /* 3FF38 0013FF38 3C00A2AE */  sw         $2, 0x3C($21)
    /* 3FF3C 0013FF3C 2D20A002 */  daddu      $4, $21, $0
    /* 3FF40 0013FF40 2D280000 */  daddu      $5, $0, $0
    /* 3FF44 0013FF44 6007050C */  jal        func_00141d80
    /* 3FF48 0013FF48 00000000 */   nop
    /* 3FF4C 0013FF4C 6000BFDF */  ld         $31, 0x60($29)
    /* 3FF50 0013FF50 5000B57B */  lq         $21, 0x50($29)
    /* 3FF54 0013FF54 4000B47B */  lq         $20, 0x40($29)
    /* 3FF58 0013FF58 3000B37B */  lq         $19, 0x30($29)
    /* 3FF5C 0013FF5C 2000B27B */  lq         $18, 0x20($29)
    /* 3FF60 0013FF60 1000B17B */  lq         $17, 0x10($29)
    /* 3FF64 0013FF64 0000B07B */  lq         $16, 0x0($29)
    /* 3FF68 0013FF68 7000BD27 */  addiu      $29, $29, 0x70
    /* 3FF6C 0013FF6C 0800E003 */  jr         $31
    /* 3FF70 0013FF70 00000000 */   nop
    /* 3FF74 0013FF74 00000000 */  nop
    /* 3FF78 0013FF78 00000000 */  nop
    /* 3FF7C 0013FF7C 00000000 */  nop
.size func_0013fb50, 0x430
