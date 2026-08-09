.section .text
.set noat
.set noreorder
glabel func_0029e9e0
    /* 19E9E0 0029E9E0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 19E9E4 0029E9E4 5000BFFF */  sd         $31, 0x50($29)
    /* 19E9E8 0029E9E8 4000B27F */  sq         $18, 0x40($29)
    /* 19E9EC 0029E9EC 3000B17F */  sq         $17, 0x30($29)
    /* 19E9F0 0029E9F0 2000B07F */  sq         $16, 0x20($29)
    /* 19E9F4 0029E9F4 1400B9E7 */  swc1       $f25, 0x14($29)
    /* 19E9F8 0029E9F8 1000B8E7 */  swc1       $f24, 0x10($29)
    /* 19E9FC 0029E9FC 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 19EA00 0029EA00 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 19EA04 0029EA04 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 19EA08 0029EA08 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 19EA0C 0029EA0C 2D108000 */  daddu      $2, $4, $0
    /* 19EA10 0029EA10 C6650046 */  mov.s      $f23, $f12
    /* 19EA14 0029EA14 866D0046 */  mov.s      $f22, $f13
    /* 19EA18 0029EA18 46760046 */  mov.s      $f25, $f14
    /* 19EA1C 0029EA1C 067E0046 */  mov.s      $f24, $f15
    /* 19EA20 0029EA20 2D90A000 */  daddu      $18, $5, $0
    /* 19EA24 0029EA24 2D88C000 */  daddu      $17, $6, $0
    /* 19EA28 0029EA28 40B5848F */  lw         $4, -0x4AC0($28)
    /* 19EA2C 0029EA2C 2D284000 */  daddu      $5, $2, $0
    /* 19EA30 0029EA30 80B4110C */  jal        func_0046d200
    /* 19EA34 0029EA34 00000000 */   nop
    /* 19EA38 0029EA38 2D804000 */  daddu      $16, $2, $0
    /* 19EA3C 0029EA3C 240040AC */  sw         $0, 0x24($2)
    /* 19EA40 0029EA40 080057E4 */  swc1       $f23, 0x8($2)
    /* 19EA44 0029EA44 0C0056E4 */  swc1       $f22, 0xC($2)
    /* 19EA48 0029EA48 2D200002 */  daddu      $4, $16, $0
    /* 19EA4C 0029EA4C 98AC110C */  jal        func_0046b260
    /* 19EA50 0029EA50 00000000 */   nop
    /* 19EA54 0029EA54 46050046 */  mov.s      $f21, $f0
    /* 19EA58 0029EA58 2D200002 */  daddu      $4, $16, $0
    /* 19EA5C 0029EA5C BCAC110C */  jal        func_0046b2f0
    /* 19EA60 0029EA60 00000000 */   nop
    /* 19EA64 0029EA64 06050046 */  mov.s      $f20, $f0
    /* 19EA68 0029EA68 FF000324 */  addiu      $3, $0, 0xFF
    /* 19EA6C 0029EA6C FF004232 */  andi       $2, $18, 0xFF
    /* 19EA70 0029EA70 23106200 */  subu       $2, $3, $2
    /* 19EA74 0029EA74 100002A2 */  sb         $2, 0x10($16)
    /* 19EA78 0029EA78 8045023C */  lui        $2, (0x45800000 >> 16)
    /* 19EA7C 0029EA7C 00008244 */  mtc1       $2, $f0
    /* 19EA80 0029EA80 00000000 */  nop
    /* 19EA84 0029EA84 42001946 */  mul.s      $f1, $f0, $f25
    /* 19EA88 0029EA88 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 19EA8C 0029EA8C 00008244 */  mtc1       $2, $f0
    /* 19EA90 0029EA90 00000000 */  nop
    /* 19EA94 0029EA94 36000146 */  c.le.s     $f0, $f1
    /* 19EA98 0029EA98 07000145 */  bc1t       .L0029EAB8
    /* 19EA9C 0029EA9C 00000000 */   nop
    /* 19EAA0 0029EAA0 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 19EAA4 0029EAA4 00000344 */  mfc1       $3, $f0
    /* 19EAA8 0029EAA8 00000000 */  nop
    /* 19EAAC 0029EAAC FFFF6330 */  andi       $3, $3, 0xFFFF
    /* 19EAB0 0029EAB0 07000010 */  b          .L0029EAD0
    /* 19EAB4 0029EAB4 00000000 */   nop
  .L0029EAB8:
    /* 19EAB8 0029EAB8 01080046 */  sub.s      $f0, $f1, $f0
    /* 19EABC 0029EABC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 19EAC0 0029EAC0 00000344 */  mfc1       $3, $f0
    /* 19EAC4 0029EAC4 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 19EAC8 0029EAC8 25186200 */  or         $3, $3, $2
    /* 19EACC 0029EACC FFFF6330 */  andi       $3, $3, 0xFFFF
  .L0029EAD0:
    /* 19EAD0 0029EAD0 200003A6 */  sh         $3, 0x20($16)
    /* 19EAD4 0029EAD4 8045023C */  lui        $2, (0x45800000 >> 16)
    /* 19EAD8 0029EAD8 00008244 */  mtc1       $2, $f0
    /* 19EADC 0029EADC 00000000 */  nop
    /* 19EAE0 0029EAE0 42001846 */  mul.s      $f1, $f0, $f24
    /* 19EAE4 0029EAE4 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 19EAE8 0029EAE8 00008244 */  mtc1       $2, $f0
    /* 19EAEC 0029EAEC 00000000 */  nop
    /* 19EAF0 0029EAF0 36000146 */  c.le.s     $f0, $f1
    /* 19EAF4 0029EAF4 07000145 */  bc1t       .L0029EB14
    /* 19EAF8 0029EAF8 00000000 */   nop
    /* 19EAFC 0029EAFC 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 19EB00 0029EB00 00000344 */  mfc1       $3, $f0
    /* 19EB04 0029EB04 00000000 */  nop
    /* 19EB08 0029EB08 FFFF6330 */  andi       $3, $3, 0xFFFF
    /* 19EB0C 0029EB0C 07000010 */  b          .L0029EB2C
    /* 19EB10 0029EB10 00000000 */   nop
  .L0029EB14:
    /* 19EB14 0029EB14 01080046 */  sub.s      $f0, $f1, $f0
    /* 19EB18 0029EB18 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 19EB1C 0029EB1C 00000344 */  mfc1       $3, $f0
    /* 19EB20 0029EB20 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 19EB24 0029EB24 25186200 */  or         $3, $3, $2
    /* 19EB28 0029EB28 FFFF6330 */  andi       $3, $3, 0xFFFF
  .L0029EB2C:
    /* 19EB2C 0029EB2C 220003A6 */  sh         $3, 0x22($16)
    /* 19EB30 0029EB30 01000224 */  addiu      $2, $0, 0x1
    /* 19EB34 0029EB34 18002216 */  bne        $17, $2, .L0029EB98
    /* 19EB38 0029EB38 00000000 */   nop
    /* 19EB3C 0029EB3C 2D200002 */  daddu      $4, $16, $0
    /* 19EB40 0029EB40 98AC110C */  jal        func_0046b260
    /* 19EB44 0029EB44 00000000 */   nop
    /* 19EB48 0029EB48 06060046 */  mov.s      $f24, $f0
    /* 19EB4C 0029EB4C 2D200002 */  daddu      $4, $16, $0
    /* 19EB50 0029EB50 BCAC110C */  jal        func_0046b2f0
    /* 19EB54 0029EB54 00000000 */   nop
    /* 19EB58 0029EB58 41C01546 */  sub.s      $f1, $f24, $f21
    /* 19EB5C 0029EB5C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* 19EB60 0029EB60 00188244 */  mtc1       $2, $f3
    /* 19EB64 0029EB64 00000000 */  nop
    /* 19EB68 0029EB68 40180146 */  add.s      $f1, $f3, $f1
    /* 19EB6C 0029EB6C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 19EB70 0029EB70 00108244 */  mtc1       $2, $f2
    /* 19EB74 0029EB74 00000000 */  nop
    /* 19EB78 0029EB78 43080246 */  div.s      $f1, $f1, $f2
    /* 19EB7C 0029EB7C 41B80146 */  sub.s      $f1, $f23, $f1
    /* 19EB80 0029EB80 080001E6 */  swc1       $f1, 0x8($16)
    /* 19EB84 0029EB84 01001446 */  sub.s      $f0, $f0, $f20
    /* 19EB88 0029EB88 00180046 */  add.s      $f0, $f3, $f0
    /* 19EB8C 0029EB8C 03000246 */  div.s      $f0, $f0, $f2
    /* 19EB90 0029EB90 01B00046 */  sub.s      $f0, $f22, $f0
    /* 19EB94 0029EB94 0C0000E6 */  swc1       $f0, 0xC($16)
  .L0029EB98:
    /* 19EB98 0029EB98 2D200002 */  daddu      $4, $16, $0
    /* 19EB9C 0029EB9C 01000524 */  addiu      $5, $0, 0x1
    /* 19EBA0 0029EBA0 E0AC110C */  jal        func_0046b380
    /* 19EBA4 0029EBA4 00000000 */   nop
    /* 19EBA8 0029EBA8 2D200002 */  daddu      $4, $16, $0
    /* 19EBAC 0029EBAC A0B4110C */  jal        func_0046d280
    /* 19EBB0 0029EBB0 00000000 */   nop
    /* 19EBB4 0029EBB4 5000BFDF */  ld         $31, 0x50($29)
    /* 19EBB8 0029EBB8 4000B27B */  lq         $18, 0x40($29)
    /* 19EBBC 0029EBBC 3000B17B */  lq         $17, 0x30($29)
    /* 19EBC0 0029EBC0 2000B07B */  lq         $16, 0x20($29)
    /* 19EBC4 0029EBC4 1400B9C7 */  lwc1       $f25, 0x14($29)
    /* 19EBC8 0029EBC8 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* 19EBCC 0029EBCC 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 19EBD0 0029EBD0 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 19EBD4 0029EBD4 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 19EBD8 0029EBD8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 19EBDC 0029EBDC 6000BD27 */  addiu      $29, $29, 0x60
    /* 19EBE0 0029EBE0 0800E003 */  jr         $31
    /* 19EBE4 0029EBE4 00000000 */   nop
    /* 19EBE8 0029EBE8 00000000 */  nop
    /* 19EBEC 0029EBEC 00000000 */  nop
.size func_0029e9e0, 0x210
