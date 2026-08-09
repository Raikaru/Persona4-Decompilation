.section .text
.set noat
.set noreorder
glabel func_0048abd0
    /* 38ABD0 0048ABD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 38ABD4 0048ABD4 0900E014 */  bnez       $7, .L0048ABFC
    /* 38ABD8 0048ABD8 00000000 */   nop
    /* 38ABDC 0048ABDC 0400828C */  lw         $2, 0x4($4)
    /* 38ABE0 0048ABE0 3C1A0200 */  dsll32     $3, $2, 8
    /* 38ABE4 0048ABE4 3E1A0300 */  dsrl32     $3, $3, 8
    /* 38ABE8 0048ABE8 0000A28C */  lw         $2, 0x0($5)
    /* 38ABEC 0048ABEC 00160200 */  sll        $2, $2, 24
    /* 38ABF0 0048ABF0 25106200 */  or         $2, $3, $2
    /* 38ABF4 0048ABF4 F8000010 */  b          .L0048AFD8
    /* 38ABF8 0048ABF8 00000000 */   nop
  .L0048ABFC:
    /* 38ABFC 0048ABFC 00008744 */  mtc1       $7, $f0
    /* 38AC00 0048AC00 00000000 */  nop
    /* 38AC04 0048AC04 20008046 */  cvt.s.w    $f0, $f0
    /* 38AC08 0048AC08 00008390 */  lbu        $3, 0x0($4)
    /* 38AC0C 0048AC0C 02000224 */  addiu      $2, $0, 0x2
    /* 38AC10 0048AC10 39006210 */  beq        $3, $2, .L0048ACF8
    /* 38AC14 0048AC14 00000000 */   nop
    /* 38AC18 0048AC18 01000224 */  addiu      $2, $0, 0x1
    /* 38AC1C 0048AC1C 10006210 */  beq        $3, $2, .L0048AC60
    /* 38AC20 0048AC20 00000000 */   nop
    /* 38AC24 0048AC24 03006010 */  beqz       $3, .L0048AC34
    /* 38AC28 0048AC28 00000000 */   nop
    /* 38AC2C 0048AC2C 70000010 */  b          .L0048ADF0
    /* 38AC30 0048AC30 00000000 */   nop
  .L0048AC34:
    /* 38AC34 0048AC34 0400898C */  lw         $9, 0x4($4)
    /* 38AC38 0048AC38 0800848C */  lw         $4, 0x8($4)
    /* 38AC3C 0048AC3C 00088644 */  mtc1       $6, $f1
    /* 38AC40 0048AC40 00000000 */  nop
    /* 38AC44 0048AC44 60088046 */  cvt.s.w    $f1, $f1
    /* 38AC48 0048AC48 C3080046 */  div.s      $f3, $f1, $f0
    /* 38AC4C 0048AC4C 00000000 */  nop
    /* 38AC50 0048AC50 00000000 */  nop
    /* 38AC54 0048AC54 00000000 */  nop
    /* 38AC58 0048AC58 68000010 */  b          .L0048ADFC
    /* 38AC5C 0048AC5C 00000000 */   nop
  .L0048AC60:
    /* 38AC60 0048AC60 100081C4 */  lwc1       $f1, 0x10($4)
    /* 38AC64 0048AC64 42080046 */  mul.s      $f1, $f1, $f0
    /* 38AC68 0048AC68 64080046 */  .word      0x46000864                    # cvt.w.s    $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 38AC6C 0048AC6C 00080344 */  mfc1       $3, $f1
    /* 38AC70 0048AC70 00000000 */  nop
    /* 38AC74 0048AC74 2A08C300 */  slt        $1, $6, $3
    /* 38AC78 0048AC78 0F002010 */  beqz       $1, .L0048ACB8
    /* 38AC7C 0048AC7C 00000000 */   nop
    /* 38AC80 0048AC80 0400898C */  lw         $9, 0x4($4)
    /* 38AC84 0048AC84 0C00848C */  lw         $4, 0xC($4)
    /* 38AC88 0048AC88 00088644 */  mtc1       $6, $f1
    /* 38AC8C 0048AC8C 00000000 */  nop
    /* 38AC90 0048AC90 A0088046 */  cvt.s.w    $f2, $f1
    /* 38AC94 0048AC94 00088344 */  mtc1       $3, $f1
    /* 38AC98 0048AC98 00000000 */  nop
    /* 38AC9C 0048AC9C 60088046 */  cvt.s.w    $f1, $f1
    /* 38ACA0 0048ACA0 C3100146 */  div.s      $f3, $f2, $f1
    /* 38ACA4 0048ACA4 00000000 */  nop
    /* 38ACA8 0048ACA8 00000000 */  nop
    /* 38ACAC 0048ACAC 00000000 */  nop
    /* 38ACB0 0048ACB0 52000010 */  b          .L0048ADFC
    /* 38ACB4 0048ACB4 00000000 */   nop
  .L0048ACB8:
    /* 38ACB8 0048ACB8 0C00898C */  lw         $9, 0xC($4)
    /* 38ACBC 0048ACBC 0800848C */  lw         $4, 0x8($4)
    /* 38ACC0 0048ACC0 2310E300 */  subu       $2, $7, $3
    /* 38ACC4 0048ACC4 00088244 */  mtc1       $2, $f1
    /* 38ACC8 0048ACC8 00000000 */  nop
    /* 38ACCC 0048ACCC A0088046 */  cvt.s.w    $f2, $f1
    /* 38ACD0 0048ACD0 2310C300 */  subu       $2, $6, $3
    /* 38ACD4 0048ACD4 00088244 */  mtc1       $2, $f1
    /* 38ACD8 0048ACD8 00000000 */  nop
    /* 38ACDC 0048ACDC 60088046 */  cvt.s.w    $f1, $f1
    /* 38ACE0 0048ACE0 C3080246 */  div.s      $f3, $f1, $f2
    /* 38ACE4 0048ACE4 00000000 */  nop
    /* 38ACE8 0048ACE8 00000000 */  nop
    /* 38ACEC 0048ACEC 00000000 */  nop
    /* 38ACF0 0048ACF0 42000010 */  b          .L0048ADFC
    /* 38ACF4 0048ACF4 00000000 */   nop
  .L0048ACF8:
    /* 38ACF8 0048ACF8 100081C4 */  lwc1       $f1, 0x10($4)
    /* 38ACFC 0048ACFC 42080046 */  mul.s      $f1, $f1, $f0
    /* 38AD00 0048AD00 64080046 */  .word      0x46000864                    # cvt.w.s    $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 38AD04 0048AD04 00080844 */  mfc1       $8, $f1
    /* 38AD08 0048AD08 00000000 */  nop
    /* 38AD0C 0048AD0C 2A08C800 */  slt        $1, $6, $8
    /* 38AD10 0048AD10 0F002010 */  beqz       $1, .L0048AD50
    /* 38AD14 0048AD14 00000000 */   nop
    /* 38AD18 0048AD18 0400898C */  lw         $9, 0x4($4)
    /* 38AD1C 0048AD1C 0C00848C */  lw         $4, 0xC($4)
    /* 38AD20 0048AD20 00088644 */  mtc1       $6, $f1
    /* 38AD24 0048AD24 00000000 */  nop
    /* 38AD28 0048AD28 A0088046 */  cvt.s.w    $f2, $f1
    /* 38AD2C 0048AD2C 00088844 */  mtc1       $8, $f1
    /* 38AD30 0048AD30 00000000 */  nop
    /* 38AD34 0048AD34 60088046 */  cvt.s.w    $f1, $f1
    /* 38AD38 0048AD38 C3100146 */  div.s      $f3, $f2, $f1
    /* 38AD3C 0048AD3C 00000000 */  nop
    /* 38AD40 0048AD40 00000000 */  nop
    /* 38AD44 0048AD44 00000000 */  nop
    /* 38AD48 0048AD48 2C000010 */  b          .L0048ADFC
    /* 38AD4C 0048AD4C 00000000 */   nop
  .L0048AD50:
    /* 38AD50 0048AD50 180081C4 */  lwc1       $f1, 0x18($4)
    /* 38AD54 0048AD54 42080046 */  mul.s      $f1, $f1, $f0
    /* 38AD58 0048AD58 64080046 */  .word      0x46000864                    # cvt.w.s    $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 38AD5C 0048AD5C 00080344 */  mfc1       $3, $f1
    /* 38AD60 0048AD60 00000000 */  nop
    /* 38AD64 0048AD64 2A08C300 */  slt        $1, $6, $3
    /* 38AD68 0048AD68 11002010 */  beqz       $1, .L0048ADB0
    /* 38AD6C 0048AD6C 00000000 */   nop
    /* 38AD70 0048AD70 0C00898C */  lw         $9, 0xC($4)
    /* 38AD74 0048AD74 1400848C */  lw         $4, 0x14($4)
    /* 38AD78 0048AD78 23106800 */  subu       $2, $3, $8
    /* 38AD7C 0048AD7C 00088244 */  mtc1       $2, $f1
    /* 38AD80 0048AD80 00000000 */  nop
    /* 38AD84 0048AD84 A0088046 */  cvt.s.w    $f2, $f1
    /* 38AD88 0048AD88 2310C800 */  subu       $2, $6, $8
    /* 38AD8C 0048AD8C 00088244 */  mtc1       $2, $f1
    /* 38AD90 0048AD90 00000000 */  nop
    /* 38AD94 0048AD94 60088046 */  cvt.s.w    $f1, $f1
    /* 38AD98 0048AD98 C3080246 */  div.s      $f3, $f1, $f2
    /* 38AD9C 0048AD9C 00000000 */  nop
    /* 38ADA0 0048ADA0 00000000 */  nop
    /* 38ADA4 0048ADA4 00000000 */  nop
    /* 38ADA8 0048ADA8 14000010 */  b          .L0048ADFC
    /* 38ADAC 0048ADAC 00000000 */   nop
  .L0048ADB0:
    /* 38ADB0 0048ADB0 1400898C */  lw         $9, 0x14($4)
    /* 38ADB4 0048ADB4 0800848C */  lw         $4, 0x8($4)
    /* 38ADB8 0048ADB8 2310E300 */  subu       $2, $7, $3
    /* 38ADBC 0048ADBC 00088244 */  mtc1       $2, $f1
    /* 38ADC0 0048ADC0 00000000 */  nop
    /* 38ADC4 0048ADC4 A0088046 */  cvt.s.w    $f2, $f1
    /* 38ADC8 0048ADC8 2310C300 */  subu       $2, $6, $3
    /* 38ADCC 0048ADCC 00088244 */  mtc1       $2, $f1
    /* 38ADD0 0048ADD0 00000000 */  nop
    /* 38ADD4 0048ADD4 60088046 */  cvt.s.w    $f1, $f1
    /* 38ADD8 0048ADD8 C3080246 */  div.s      $f3, $f1, $f2
    /* 38ADDC 0048ADDC 00000000 */  nop
    /* 38ADE0 0048ADE0 00000000 */  nop
    /* 38ADE4 0048ADE4 00000000 */  nop
    /* 38ADE8 0048ADE8 04000010 */  b          .L0048ADFC
    /* 38ADEC 0048ADEC 00000000 */   nop
  .L0048ADF0:
    /* 38ADF0 0048ADF0 0400898C */  lw         $9, 0x4($4)
    /* 38ADF4 0048ADF4 0800848C */  lw         $4, 0x8($4)
    /* 38ADF8 0048ADF8 00188044 */  mtc1       $0, $f3
  .L0048ADFC:
    /* 38ADFC 0048ADFC 0C00A4AF */  sw         $4, 0xC($29)
    /* 38AE00 0048AE00 0C00A227 */  addiu      $2, $29, 0xC
    /* 38AE04 0048AE04 448081C7 */  lwc1       $f1, -0x7FBC($28)
    /* 38AE08 0048AE08 0000428C */  lw         $2, 0x0($2)
    /* 38AE0C 0048AE0C 88160270 */  pextlb     $2, $0, $2
    /* 38AE10 0048AE10 88150270 */  pextlh     $2, $0, $2
    /* 38AE14 0048AE14 0050A248 */  qmtc2.ni   $2, $vf10
    /* 38AE18 0048AE18 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 38AE1C 0048AE1C 00080244 */  mfc1       $2, $f1
    /* 38AE20 0048AE20 00000000 */  nop
    /* 38AE24 0048AE24 0010A248 */  qmtc2.ni   $2, $vf2
    /* 38AE28 0048AE28 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 38AE2C 0048AE2C 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 38AE30 0048AE30 0800A9AF */  sw         $9, 0x8($29)
    /* 38AE34 0048AE34 0800A227 */  addiu      $2, $29, 0x8
    /* 38AE38 0048AE38 0000428C */  lw         $2, 0x0($2)
    /* 38AE3C 0048AE3C 88160270 */  pextlb     $2, $0, $2
    /* 38AE40 0048AE40 88150270 */  pextlh     $2, $0, $2
    /* 38AE44 0048AE44 0050A248 */  qmtc2.ni   $2, $vf10
    /* 38AE48 0048AE48 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 38AE4C 0048AE4C 00080244 */  mfc1       $2, $f1
    /* 38AE50 0048AE50 00000000 */  nop
    /* 38AE54 0048AE54 0010A248 */  qmtc2.ni   $2, $vf2
    /* 38AE58 0048AE58 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 38AE5C 0048AE5C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 38AE60 0048AE60 00108244 */  mtc1       $2, $f2
    /* 38AE64 0048AE64 00000000 */  nop
    /* 38AE68 0048AE68 41100346 */  sub.s      $f1, $f2, $f3
    /* 38AE6C 0048AE6C 00080244 */  mfc1       $2, $f1
    /* 38AE70 0048AE70 00000000 */  nop
    /* 38AE74 0048AE74 0010A248 */  qmtc2.ni   $2, $vf2
    /* 38AE78 0048AE78 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 38AE7C 0048AE7C 00180244 */  mfc1       $2, $f3
    /* 38AE80 0048AE80 00000000 */  nop
    /* 38AE84 0048AE84 0010A248 */  qmtc2.ni   $2, $vf2
    /* 38AE88 0048AE88 D85AE24B */  vmulx.xyzw $vf11, $vf11, $vf2x
    /* 38AE8C 0048AE8C A852EB4B */  vadd.xyzw  $vf10, $vf10, $vf11
    /* 38AE90 0048AE90 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 38AE94 0048AE94 0010A248 */  qmtc2.ni   $2, $vf2
    /* 38AE98 0048AE98 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 38AE9C 0048AE9C 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 38AEA0 0048AEA0 00502248 */  qmfc2.ni   $2, $vf10
    /* 38AEA4 0048AEA4 C8150270 */  ppach      $2, $0, $2
    /* 38AEA8 0048AEA8 C8160270 */  ppacb      $2, $0, $2
    /* 38AEAC 0048AEAC 0400A2AF */  sw         $2, 0x4($29)
    /* 38AEB0 0048AEB0 0400A48F */  lw         $4, 0x4($29)
    /* 38AEB4 0048AEB4 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 38AEB8 0048AEB8 42080046 */  mul.s      $f1, $f1, $f0
    /* 38AEBC 0048AEBC 64080046 */  .word      0x46000864                    # cvt.w.s    $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 38AEC0 0048AEC0 00080244 */  mfc1       $2, $f1
    /* 38AEC4 0048AEC4 0C00A1C4 */  lwc1       $f1, 0xC($5)
    /* 38AEC8 0048AEC8 02080046 */  mul.s      $f0, $f1, $f0
    /* 38AECC 0048AECC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 38AED0 0048AED0 00000344 */  mfc1       $3, $f0
    /* 38AED4 0048AED4 2A08C200 */  slt        $1, $6, $2
    /* 38AED8 0048AED8 0D002010 */  beqz       $1, .L0048AF10
    /* 38AEDC 0048AEDC 00000000 */   nop
    /* 38AEE0 0048AEE0 00008644 */  mtc1       $6, $f0
    /* 38AEE4 0048AEE4 00000000 */  nop
    /* 38AEE8 0048AEE8 60008046 */  cvt.s.w    $f1, $f0
    /* 38AEEC 0048AEEC 00008244 */  mtc1       $2, $f0
    /* 38AEF0 0048AEF0 00000000 */  nop
    /* 38AEF4 0048AEF4 20008046 */  cvt.s.w    $f0, $f0
    /* 38AEF8 0048AEF8 83080046 */  div.s      $f2, $f1, $f0
    /* 38AEFC 0048AEFC 00000000 */  nop
    /* 38AF00 0048AF00 00000000 */  nop
    /* 38AF04 0048AF04 00000000 */  nop
    /* 38AF08 0048AF08 10000010 */  b          .L0048AF4C
    /* 38AF0C 0048AF0C 00000000 */   nop
  .L0048AF10:
    /* 38AF10 0048AF10 2A086600 */  slt        $1, $3, $6
    /* 38AF14 0048AF14 0D002010 */  beqz       $1, .L0048AF4C
    /* 38AF18 0048AF18 00000000 */   nop
    /* 38AF1C 0048AF1C 2310E600 */  subu       $2, $7, $6
    /* 38AF20 0048AF20 00008244 */  mtc1       $2, $f0
    /* 38AF24 0048AF24 00000000 */  nop
    /* 38AF28 0048AF28 60008046 */  cvt.s.w    $f1, $f0
    /* 38AF2C 0048AF2C 2310E300 */  subu       $2, $7, $3
    /* 38AF30 0048AF30 00008244 */  mtc1       $2, $f0
    /* 38AF34 0048AF34 00000000 */  nop
    /* 38AF38 0048AF38 20008046 */  cvt.s.w    $f0, $f0
    /* 38AF3C 0048AF3C 83080046 */  div.s      $f2, $f1, $f0
    /* 38AF40 0048AF40 00000000 */  nop
    /* 38AF44 0048AF44 00000000 */  nop
    /* 38AF48 0048AF48 00000000 */  nop
  .L0048AF4C:
    /* 38AF4C 0048AF4C 0000A28C */  lw         $2, 0x0($5)
    /* 38AF50 0048AF50 06004004 */  bltz       $2, .L0048AF6C
    /* 38AF54 0048AF54 00000000 */   nop
    /* 38AF58 0048AF58 00008244 */  mtc1       $2, $f0
    /* 38AF5C 0048AF5C 00000000 */  nop
    /* 38AF60 0048AF60 20008046 */  cvt.s.w    $f0, $f0
    /* 38AF64 0048AF64 08000010 */  b          .L0048AF88
    /* 38AF68 0048AF68 00000000 */   nop
  .L0048AF6C:
    /* 38AF6C 0048AF6C 42180200 */  srl        $3, $2, 1
    /* 38AF70 0048AF70 01004230 */  andi       $2, $2, 0x1
    /* 38AF74 0048AF74 25186200 */  or         $3, $3, $2
    /* 38AF78 0048AF78 00008344 */  mtc1       $3, $f0
    /* 38AF7C 0048AF7C 00000000 */  nop
    /* 38AF80 0048AF80 20008046 */  cvt.s.w    $f0, $f0
    /* 38AF84 0048AF84 00000046 */  add.s      $f0, $f0, $f0
  .L0048AF88:
    /* 38AF88 0048AF88 42000246 */  mul.s      $f1, $f0, $f2
    /* 38AF8C 0048AF8C 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 38AF90 0048AF90 00008244 */  mtc1       $2, $f0
    /* 38AF94 0048AF94 00000000 */  nop
    /* 38AF98 0048AF98 36000146 */  c.le.s     $f0, $f1
    /* 38AF9C 0048AF9C 05000145 */  bc1t       .L0048AFB4
    /* 38AFA0 0048AFA0 00000000 */   nop
    /* 38AFA4 0048AFA4 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 38AFA8 0048AFA8 00000344 */  mfc1       $3, $f0
    /* 38AFAC 0048AFAC 06000010 */  b          .L0048AFC8
    /* 38AFB0 0048AFB0 00000000 */   nop
  .L0048AFB4:
    /* 38AFB4 0048AFB4 01080046 */  sub.s      $f0, $f1, $f0
    /* 38AFB8 0048AFB8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 38AFBC 0048AFBC 00000344 */  mfc1       $3, $f0
    /* 38AFC0 0048AFC0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 38AFC4 0048AFC4 25186200 */  or         $3, $3, $2
  .L0048AFC8:
    /* 38AFC8 0048AFC8 001E0300 */  sll        $3, $3, 24
    /* 38AFCC 0048AFCC 3C120400 */  dsll32     $2, $4, 8
    /* 38AFD0 0048AFD0 3E120200 */  dsrl32     $2, $2, 8
    /* 38AFD4 0048AFD4 25104300 */  or         $2, $2, $3
  .L0048AFD8:
    /* 38AFD8 0048AFD8 1000BD27 */  addiu      $29, $29, 0x10
    /* 38AFDC 0048AFDC 0800E003 */  jr         $31
    /* 38AFE0 0048AFE0 00000000 */   nop
    /* 38AFE4 0048AFE4 00000000 */  nop
    /* 38AFE8 0048AFE8 00000000 */  nop
    /* 38AFEC 0048AFEC 00000000 */  nop
.size func_0048abd0, 0x420
