.section .text
.set noat
.set noreorder
glabel func_0037ab50
    /* 27AB50 0037AB50 80FFBD27 */  addiu      $29, $29, -0x80
    /* 27AB54 0037AB54 4000BFFF */  sd         $31, 0x40($29)
    /* 27AB58 0037AB58 3000B27F */  sq         $18, 0x30($29)
    /* 27AB5C 0037AB5C 2000B17F */  sq         $17, 0x20($29)
    /* 27AB60 0037AB60 1000B07F */  sq         $16, 0x10($29)
    /* 27AB64 0037AB64 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 27AB68 0037AB68 2D908000 */  daddu      $18, $4, $0
    /* 27AB6C 0037AB6C 2D88A000 */  daddu      $17, $5, $0
    /* 27AB70 0037AB70 2D80C000 */  daddu      $16, $6, $0
    /* 27AB74 0037AB74 7000A427 */  addiu      $4, $29, 0x70
    /* 27AB78 0037AB78 98C40D0C */  jal        func_00371260
    /* 27AB7C 0037AB7C 00000000 */   nop
    /* 27AB80 0037AB80 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* 27AB84 0037AB84 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* 27AB88 0037AB88 00008244 */  mtc1       $2, $f0
    /* 27AB8C 0037AB8C 00000000 */  nop
    /* 27AB90 0037AB90 41080046 */  sub.s      $f1, $f1, $f0
    /* 27AB94 0037AB94 7400A1E7 */  swc1       $f1, 0x74($29)
    /* 27AB98 0037AB98 7000A0C7 */  lwc1       $f0, 0x70($29)
    /* 27AB9C 0037AB9C 6000A0E7 */  swc1       $f0, 0x60($29)
    /* 27ABA0 0037ABA0 6400A1E7 */  swc1       $f1, 0x64($29)
    /* 27ABA4 0037ABA4 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* 27ABA8 0037ABA8 4843023C */  lui        $2, (0x43480000 >> 16)
    /* 27ABAC 0037ABAC 00008244 */  mtc1       $2, $f0
    /* 27ABB0 0037ABB0 00000000 */  nop
    /* 27ABB4 0037ABB4 00080046 */  add.s      $f0, $f1, $f0
    /* 27ABB8 0037ABB8 6800A0E7 */  swc1       $f0, 0x68($29)
    /* 27ABBC 0037ABBC 01002232 */  andi       $2, $17, 0x1
    /* 27ABC0 0037ABC0 04002106 */  bgez       $17, .L0037ABD4
    /* 27ABC4 0037ABC4 00000000 */   nop
    /* 27ABC8 0037ABC8 02004010 */  beqz       $2, .L0037ABD4
    /* 27ABCC 0037ABCC 00000000 */   nop
    /* 27ABD0 0037ABD0 FEFF4224 */  addiu      $2, $2, -0x2
  .L0037ABD4:
    /* 27ABD4 0037ABD4 1A004014 */  bnez       $2, .L0037AC40
    /* 27ABD8 0037ABD8 00000000 */   nop
    /* 27ABDC 0037ABDC E4838CC7 */  lwc1       $f12, -0x7C1C($28)
    /* 27ABE0 0037ABE0 842D110C */  jal        func_0044b610
    /* 27ABE4 0037ABE4 00000000 */   nop
    /* 27ABE8 0037ABE8 07050046 */  neg.s      $f20, $f0
    /* 27ABEC 0037ABEC 7C838CC7 */  lwc1       $f12, -0x7C84($28)
    /* 27ABF0 0037ABF0 EC2D110C */  jal        func_0044b7b0
    /* 27ABF4 0037ABF4 00000000 */   nop
    /* 27ABF8 0037ABF8 02A00046 */  mul.s      $f0, $f20, $f0
    /* 27ABFC 0037ABFC 5000A0E7 */  swc1       $f0, 0x50($29)
    /* 27AC00 0037AC00 E4838CC7 */  lwc1       $f12, -0x7C1C($28)
    /* 27AC04 0037AC04 842D110C */  jal        func_0044b610
    /* 27AC08 0037AC08 00000000 */   nop
    /* 27AC0C 0037AC0C 07050046 */  neg.s      $f20, $f0
    /* 27AC10 0037AC10 7C838CC7 */  lwc1       $f12, -0x7C84($28)
    /* 27AC14 0037AC14 842D110C */  jal        func_0044b610
    /* 27AC18 0037AC18 00000000 */   nop
    /* 27AC1C 0037AC1C 02A00046 */  mul.s      $f0, $f20, $f0
    /* 27AC20 0037AC20 5400A0E7 */  swc1       $f0, 0x54($29)
    /* 27AC24 0037AC24 E4838CC7 */  lwc1       $f12, -0x7C1C($28)
    /* 27AC28 0037AC28 EC2D110C */  jal        func_0044b7b0
    /* 27AC2C 0037AC2C 00000000 */   nop
    /* 27AC30 0037AC30 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 27AC34 0037AC34 00608044 */  mtc1       $0, $f12
    /* 27AC38 0037AC38 19000010 */  b          .L0037ACA0
    /* 27AC3C 0037AC3C 00000000 */   nop
  .L0037AC40:
    /* 27AC40 0037AC40 E4838CC7 */  lwc1       $f12, -0x7C1C($28)
    /* 27AC44 0037AC44 842D110C */  jal        func_0044b610
    /* 27AC48 0037AC48 00000000 */   nop
    /* 27AC4C 0037AC4C 07050046 */  neg.s      $f20, $f0
    /* 27AC50 0037AC50 7C838CC7 */  lwc1       $f12, -0x7C84($28)
    /* 27AC54 0037AC54 EC2D110C */  jal        func_0044b7b0
    /* 27AC58 0037AC58 00000000 */   nop
    /* 27AC5C 0037AC5C 02A00046 */  mul.s      $f0, $f20, $f0
    /* 27AC60 0037AC60 5000A0E7 */  swc1       $f0, 0x50($29)
    /* 27AC64 0037AC64 E4838CC7 */  lwc1       $f12, -0x7C1C($28)
    /* 27AC68 0037AC68 842D110C */  jal        func_0044b610
    /* 27AC6C 0037AC6C 00000000 */   nop
    /* 27AC70 0037AC70 06050046 */  mov.s      $f20, $f0
    /* 27AC74 0037AC74 7C838CC7 */  lwc1       $f12, -0x7C84($28)
    /* 27AC78 0037AC78 842D110C */  jal        func_0044b610
    /* 27AC7C 0037AC7C 00000000 */   nop
    /* 27AC80 0037AC80 02A00046 */  mul.s      $f0, $f20, $f0
    /* 27AC84 0037AC84 5400A0E7 */  swc1       $f0, 0x54($29)
    /* 27AC88 0037AC88 E4838CC7 */  lwc1       $f12, -0x7C1C($28)
    /* 27AC8C 0037AC8C EC2D110C */  jal        func_0044b7b0
    /* 27AC90 0037AC90 00000000 */   nop
    /* 27AC94 0037AC94 07000046 */  neg.s      $f0, $f0
    /* 27AC98 0037AC98 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 27AC9C 0037AC9C 00608044 */  mtc1       $0, $f12
  .L0037ACA0:
    /* 27ACA0 0037ACA0 09000012 */  beqz       $16, .L0037ACC8
    /* 27ACA4 0037ACA4 00000000 */   nop
    /* 27ACA8 0037ACA8 6000A427 */  addiu      $4, $29, 0x60
    /* 27ACAC 0037ACAC 5000A527 */  addiu      $5, $29, 0x50
    /* 27ACB0 0037ACB0 7000A627 */  addiu      $6, $29, 0x70
    /* 27ACB4 0037ACB4 2D380002 */  daddu      $7, $16, $0
    /* 27ACB8 0037ACB8 58C40D0C */  jal        func_00371160
    /* 27ACBC 0037ACBC 00000000 */   nop
    /* 27ACC0 0037ACC0 0A000010 */  b          .L0037ACEC
    /* 27ACC4 0037ACC4 00000000 */   nop
  .L0037ACC8:
    /* 27ACC8 0037ACC8 2D204002 */  daddu      $4, $18, $0
    /* 27ACCC 0037ACCC 2D282002 */  daddu      $5, $17, $0
    /* 27ACD0 0037ACD0 2D300000 */  daddu      $6, $0, $0
    /* 27ACD4 0037ACD4 5000A727 */  addiu      $7, $29, 0x50
    /* 27ACD8 0037ACD8 6000A827 */  addiu      $8, $29, 0x60
    /* 27ACDC 0037ACDC 7000A927 */  addiu      $9, $29, 0x70
    /* 27ACE0 0037ACE0 46630046 */  mov.s      $f13, $f12
    /* 27ACE4 0037ACE4 E8D70D0C */  jal        func_00375fa0
    /* 27ACE8 0037ACE8 00000000 */   nop
  .L0037ACEC:
    /* 27ACEC 0037ACEC 4000BFDF */  ld         $31, 0x40($29)
    /* 27ACF0 0037ACF0 3000B27B */  lq         $18, 0x30($29)
    /* 27ACF4 0037ACF4 2000B17B */  lq         $17, 0x20($29)
    /* 27ACF8 0037ACF8 1000B07B */  lq         $16, 0x10($29)
    /* 27ACFC 0037ACFC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 27AD00 0037AD00 8000BD27 */  addiu      $29, $29, 0x80
    /* 27AD04 0037AD04 0800E003 */  jr         $31
    /* 27AD08 0037AD08 00000000 */   nop
    /* 27AD0C 0037AD0C 00000000 */  nop
.size func_0037ab50, 0x1c0
