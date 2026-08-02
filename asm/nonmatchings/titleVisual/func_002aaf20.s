.section .text
.set noat
.set noreorder
glabel func_002aaf20
    /* 1AAF20 002AAF20 80FFBD27 */  addiu      $29, $29, -0x80
    /* 1AAF24 002AAF24 6000BFFF */  sd         $31, 0x60($29)
    /* 1AAF28 002AAF28 5000B37F */  sq         $19, 0x50($29)
    /* 1AAF2C 002AAF2C 4000B27F */  sq         $18, 0x40($29)
    /* 1AAF30 002AAF30 3000B17F */  sq         $17, 0x30($29)
    /* 1AAF34 002AAF34 2000B07F */  sq         $16, 0x20($29)
    /* 1AAF38 002AAF38 1000B8E7 */  swc1       $f24, 0x10($29)
    /* 1AAF3C 002AAF3C 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 1AAF40 002AAF40 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 1AAF44 002AAF44 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1AAF48 002AAF48 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1AAF4C 002AAF4C 06660046 */  mov.s      $f24, $f12
    /* 1AAF50 002AAF50 C66D0046 */  mov.s      $f23, $f13
    /* 1AAF54 002AAF54 06750046 */  mov.s      $f20, $f14
    /* 1AAF58 002AAF58 2D988000 */  daddu      $19, $4, $0
    /* 1AAF5C 002AAF5C 867D0046 */  mov.s      $f22, $f15
    /* 1AAF60 002AAF60 46850046 */  mov.s      $f21, $f16
    /* 1AAF64 002AAF64 2D90A000 */  daddu      $18, $5, $0
    /* 1AAF68 002AAF68 2D88C000 */  daddu      $17, $6, $0
    /* 1AAF6C 002AAF6C 6400043C */  lui        $4, %hi(D_0063EE50)
    /* 1AAF70 002AAF70 50EE8424 */  addiu      $4, $4, %lo(D_0063EE50)
    /* 1AAF74 002AAF74 91000524 */  addiu      $5, $0, 0x91
    /* 1AAF78 002AAF78 A43A110C */  jal        func_0044ea90
    /* 1AAF7C 002AAF7C 00000000 */   nop
    /* 1AAF80 002AAF80 01000424 */  addiu      $4, $0, 0x1
    /* 1AAF84 002AAF84 1C000524 */  addiu      $5, $0, 0x1C
    /* 1AAF88 002AAF88 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1AAF8C 002AAF8C 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1AAF90 002AAF90 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1AAF94 002AAF94 09F84000 */  jalr       $2
    /* 1AAF98 002AAF98 00000000 */   nop
    /* 1AAF9C 002AAF9C 2D804000 */  daddu      $16, $2, $0
    /* 1AAFA0 002AAFA0 7000A327 */  addiu      $3, $29, 0x70
    /* 1AAFA4 002AAFA4 10000224 */  addiu      $2, $0, 0x10
    /* 1AAFA8 002AAFA8 08006010 */  beqz       $3, .L002AAFCC
    /* 1AAFAC 002AAFAC 00000000 */   nop
  .L002AAFB0:
    /* 1AAFB0 002AAFB0 000060A0 */  sb         $0, 0x0($3)
    /* 1AAFB4 002AAFB4 01006324 */  addiu      $3, $3, 0x1
    /* 1AAFB8 002AAFB8 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1AAFBC 002AAFBC 00000000 */  nop
    /* 1AAFC0 002AAFC0 00000000 */  nop
    /* 1AAFC4 002AAFC4 FAFF4014 */  bnez       $2, .L002AAFB0
    /* 1AAFC8 002AAFC8 00000000 */   nop
  .L002AAFCC:
    /* 1AAFCC 002AAFCC 24C00046 */  .word      0x4600C024                    # cvt.w.s    $f0, $f24 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AAFD0 002AAFD0 00000244 */  mfc1       $2, $f0
    /* 1AAFD4 002AAFD4 00000000 */  nop
    /* 1AAFD8 002AAFD8 7000A2AF */  sw         $2, 0x70($29)
    /* 1AAFDC 002AAFDC 24B80046 */  .word      0x4600B824                    # cvt.w.s    $f0, $f23 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AAFE0 002AAFE0 00000244 */  mfc1       $2, $f0
    /* 1AAFE4 002AAFE4 00000000 */  nop
    /* 1AAFE8 002AAFE8 7400A2AF */  sw         $2, 0x74($29)
    /* 1AAFEC 002AAFEC 00C01646 */  add.s      $f0, $f24, $f22
    /* 1AAFF0 002AAFF0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AAFF4 002AAFF4 00000244 */  mfc1       $2, $f0
    /* 1AAFF8 002AAFF8 00000000 */  nop
    /* 1AAFFC 002AAFFC 7800A2AF */  sw         $2, 0x78($29)
    /* 1AB000 002AB000 00B81546 */  add.s      $f0, $f23, $f21
    /* 1AB004 002AB004 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AB008 002AB008 00000244 */  mfc1       $2, $f0
    /* 1AB00C 002AB00C 00000000 */  nop
    /* 1AB010 002AB010 7C00A2AF */  sw         $2, 0x7C($29)
    /* 1AB014 002AB014 7000A3C7 */  lwc1       $f3, 0x70($29)
    /* 1AB018 002AB018 7400A2C7 */  lwc1       $f2, 0x74($29)
    /* 1AB01C 002AB01C 7800A1C7 */  lwc1       $f1, 0x78($29)
    /* 1AB020 002AB020 7C00A0C7 */  lwc1       $f0, 0x7C($29)
    /* 1AB024 002AB024 000003E6 */  swc1       $f3, 0x0($16)
    /* 1AB028 002AB028 040002E6 */  swc1       $f2, 0x4($16)
    /* 1AB02C 002AB02C 080001E6 */  swc1       $f1, 0x8($16)
    /* 1AB030 002AB030 0C0000E6 */  swc1       $f0, 0xC($16)
    /* 1AB034 002AB034 100014E6 */  swc1       $f20, 0x10($16)
    /* 1AB038 002AB038 00006592 */  lbu        $5, 0x0($19)
    /* 1AB03C 002AB03C 01006492 */  lbu        $4, 0x1($19)
    /* 1AB040 002AB040 02006392 */  lbu        $3, 0x2($19)
    /* 1AB044 002AB044 03006292 */  lbu        $2, 0x3($19)
    /* 1AB048 002AB048 140005A2 */  sb         $5, 0x14($16)
    /* 1AB04C 002AB04C 150004A2 */  sb         $4, 0x15($16)
    /* 1AB050 002AB050 160003A2 */  sb         $3, 0x16($16)
    /* 1AB054 002AB054 170002A2 */  sb         $2, 0x17($16)
    /* 1AB058 002AB058 180012AE */  sw         $18, 0x18($16)
    /* 1AB05C 002AB05C 0D002012 */  beqz       $17, .L002AB094
    /* 1AB060 002AB060 00000000 */   nop
    /* 1AB064 002AB064 6482110C */  jal        func_00460990
    /* 1AB068 002AB068 00000000 */   nop
    /* 1AB06C 002AB06C 2D284000 */  daddu      $5, $2, $0
    /* 1AB070 002AB070 2B00033C */  lui        $3, %hi(func_002aabf0)
    /* 1AB074 002AB074 F0AB6324 */  addiu      $3, $3, %lo(func_002aabf0)
    /* 1AB078 002AB078 080043AC */  sw         $3, 0x8($2)
    /* 1AB07C 002AB07C 100050AC */  sw         $16, 0x10($2)
    /* 1AB080 002AB080 2D202002 */  daddu      $4, $17, $0
    /* 1AB084 002AB084 B082110C */  jal        func_00460ac0
    /* 1AB088 002AB088 00000000 */   nop
    /* 1AB08C 002AB08C 05000010 */  b          .L002AB0A4
    /* 1AB090 002AB090 00000000 */   nop
  .L002AB094:
    /* 1AB094 002AB094 2D200000 */  daddu      $4, $0, $0
    /* 1AB098 002AB098 2D280002 */  daddu      $5, $16, $0
    /* 1AB09C 002AB09C FCAA0A0C */  jal        func_002aabf0
    /* 1AB0A0 002AB0A0 00000000 */   nop
  .L002AB0A4:
    /* 1AB0A4 002AB0A4 6000BFDF */  ld         $31, 0x60($29)
    /* 1AB0A8 002AB0A8 5000B37B */  lq         $19, 0x50($29)
    /* 1AB0AC 002AB0AC 4000B27B */  lq         $18, 0x40($29)
    /* 1AB0B0 002AB0B0 3000B17B */  lq         $17, 0x30($29)
    /* 1AB0B4 002AB0B4 2000B07B */  lq         $16, 0x20($29)
    /* 1AB0B8 002AB0B8 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* 1AB0BC 002AB0BC 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 1AB0C0 002AB0C0 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 1AB0C4 002AB0C4 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1AB0C8 002AB0C8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1AB0CC 002AB0CC 8000BD27 */  addiu      $29, $29, 0x80
    /* 1AB0D0 002AB0D0 0800E003 */  jr         $31
    /* 1AB0D4 002AB0D4 00000000 */   nop
    /* 1AB0D8 002AB0D8 00000000 */  nop
    /* 1AB0DC 002AB0DC 00000000 */  nop
.size func_002aaf20, 0x1c0
