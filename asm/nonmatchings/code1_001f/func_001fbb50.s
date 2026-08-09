.section .text
.set noat
.set noreorder
glabel func_001fbb50
    /* FBB50 001FBB50 80FFBD27 */  addiu      $29, $29, -0x80
    /* FBB54 001FBB54 4000BFFF */  sd         $31, 0x40($29)
    /* FBB58 001FBB58 3000B27F */  sq         $18, 0x30($29)
    /* FBB5C 001FBB5C 2000B17F */  sq         $17, 0x20($29)
    /* FBB60 001FBB60 1000B07F */  sq         $16, 0x10($29)
    /* FBB64 001FBB64 0400B5E7 */  swc1       $f21, 0x4($29)
    /* FBB68 001FBB68 0000B4E7 */  swc1       $f20, 0x0($29)
    /* FBB6C 001FBB6C 2D888000 */  daddu      $17, $4, $0
    /* FBB70 001FBB70 485C110C */  jal        func_00457120
    /* FBB74 001FBB74 00000000 */   nop
    /* FBB78 001FBB78 2D204000 */  daddu      $4, $2, $0
    /* FBB7C 001FBB7C 48A00F0C */  jal        func_003e8120
    /* FBB80 001FBB80 00000000 */   nop
    /* FBB84 001FBB84 04004014 */  bnez       $2, .L001FBB98
    /* FBB88 001FBB88 00000000 */   nop
    /* FBB8C 001FBB8C 2D100000 */  daddu      $2, $0, $0
    /* FBB90 001FBB90 7B010010 */  b          .L001FC180
    /* FBB94 001FBB94 00000000 */   nop
  .L001FBB98:
    /* FBB98 001FBB98 2D900000 */  daddu      $18, $0, $0
    /* FBB9C 001FBB9C 2D800000 */  daddu      $16, $0, $0
    /* FBBA0 001FBBA0 0D000010 */  b          .L001FBBD8
    /* FBBA4 001FBBA4 00000000 */   nop
  .L001FBBA8:
    /* FBBA8 001FBBA8 80201000 */  sll        $4, $16, 2
    /* FBBAC 001FBBAC 6200023C */  lui        $2, %hi(D_00625210)
    /* FBBB0 001FBBB0 10524224 */  addiu      $2, $2, %lo(D_00625210)
    /* FBBB4 001FBBB4 21184400 */  addu       $3, $2, $4
    /* FBBB8 001FBBB8 21109D00 */  addu       $2, $4, $29
    /* FBBBC 001FBBBC 0000648C */  lw         $4, 0x0($3)
    /* FBBC0 001FBBC0 50004524 */  addiu      $5, $2, 0x50
    /* FBBC4 001FBBC4 8800023C */  lui        $2, %hi(D_00887304)
    /* FBBC8 001FBBC8 0473428C */  lw         $2, %lo(D_00887304)($2)
    /* FBBCC 001FBBCC 09F84000 */  jalr       $2
    /* FBBD0 001FBBD0 00000000 */   nop
    /* FBBD4 001FBBD4 01001026 */  addiu      $16, $16, 0x1
  .L001FBBD8:
    /* FBBD8 001FBBD8 0700022E */  sltiu      $2, $16, 0x7
    /* FBBDC 001FBBDC F2FF4014 */  bnez       $2, .L001FBBA8
    /* FBBE0 001FBBE0 00000000 */   nop
    /* FBBE4 001FBBE4 3800318E */  lw         $17, 0x38($17)
    /* FBBE8 001FBBE8 00002392 */  lbu        $3, 0x0($17)
    /* FBBEC 001FBBEC 03000224 */  addiu      $2, $0, 0x3
    /* FBBF0 001FBBF0 32016210 */  beq        $3, $2, .L001FC0BC
    /* FBBF4 001FBBF4 00000000 */   nop
    /* FBBF8 001FBBF8 02000224 */  addiu      $2, $0, 0x2
    /* FBBFC 001FBBFC FA006210 */  beq        $3, $2, .L001FBFE8
    /* FBC00 001FBC00 00000000 */   nop
    /* FBC04 001FBC04 01000224 */  addiu      $2, $0, 0x1
    /* FBC08 001FBC08 05006210 */  beq        $3, $2, .L001FBC20
    /* FBC0C 001FBC0C 00000000 */   nop
    /* FBC10 001FBC10 34016010 */  beqz       $3, .L001FC0E4
    /* FBC14 001FBC14 00000000 */   nop
    /* FBC18 001FBC18 32010010 */  b          .L001FC0E4
    /* FBC1C 001FBC1C 00000000 */   nop
  .L001FBC20:
    /* FBC20 001FBC20 6CB48297 */  lhu        $2, -0x4B94($28)
    /* FBC24 001FBC24 EE004014 */  bnez       $2, .L001FBFE0
    /* FBC28 001FBC28 00000000 */   nop
    /* FBC2C 001FBC2C 6AB48297 */  lhu        $2, -0x4B96($28)
    /* FBC30 001FBC30 01004224 */  addiu      $2, $2, 0x1
    /* FBC34 001FBC34 6AB482A7 */  sh         $2, -0x4B96($28)
    /* FBC38 001FBC38 6AB48297 */  lhu        $2, -0x4B96($28)
    /* FBC3C 001FBC3C 06004004 */  bltz       $2, .L001FBC58
    /* FBC40 001FBC40 00000000 */   nop
    /* FBC44 001FBC44 00008244 */  mtc1       $2, $f0
    /* FBC48 001FBC48 00000000 */  nop
    /* FBC4C 001FBC4C 60008046 */  cvt.s.w    $f1, $f0
    /* FBC50 001FBC50 08000010 */  b          .L001FBC74
    /* FBC54 001FBC54 00000000 */   nop
  .L001FBC58:
    /* FBC58 001FBC58 42180200 */  srl        $3, $2, 1
    /* FBC5C 001FBC5C 01004230 */  andi       $2, $2, 0x1
    /* FBC60 001FBC60 25186200 */  or         $3, $3, $2
    /* FBC64 001FBC64 00008344 */  mtc1       $3, $f0
    /* FBC68 001FBC68 00000000 */  nop
    /* FBC6C 001FBC6C 60008046 */  cvt.s.w    $f1, $f0
    /* FBC70 001FBC70 40080146 */  add.s      $f1, $f1, $f1
  .L001FBC74:
    /* FBC74 001FBC74 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* FBC78 001FBC78 00008244 */  mtc1       $2, $f0
    /* FBC7C 001FBC7C 00000000 */  nop
    /* FBC80 001FBC80 430D0046 */  div.s      $f21, $f1, $f0
    /* FBC84 001FBC84 8800103C */  lui        $16, %hi(D_00887300)
    /* FBC88 001FBC88 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* FBC8C 001FBC8C 07000424 */  addiu      $4, $0, 0x7
    /* FBC90 001FBC90 02000524 */  addiu      $5, $0, 0x2
    /* FBC94 001FBC94 0000028E */  lw         $2, 0x0($16)
    /* FBC98 001FBC98 09F84000 */  jalr       $2
    /* FBC9C 001FBC9C 00000000 */   nop
    /* FBCA0 001FBCA0 14000424 */  addiu      $4, $0, 0x14
    /* FBCA4 001FBCA4 01000524 */  addiu      $5, $0, 0x1
    /* FBCA8 001FBCA8 0000028E */  lw         $2, 0x0($16)
    /* FBCAC 001FBCAC 09F84000 */  jalr       $2
    /* FBCB0 001FBCB0 00000000 */   nop
    /* FBCB4 001FBCB4 0E000424 */  addiu      $4, $0, 0xE
    /* FBCB8 001FBCB8 2D280000 */  daddu      $5, $0, $0
    /* FBCBC 001FBCBC 0000028E */  lw         $2, 0x0($16)
    /* FBCC0 001FBCC0 09F84000 */  jalr       $2
    /* FBCC4 001FBCC4 00000000 */   nop
    /* FBCC8 001FBCC8 06000424 */  addiu      $4, $0, 0x6
    /* FBCCC 001FBCCC 2D280000 */  daddu      $5, $0, $0
    /* FBCD0 001FBCD0 0000028E */  lw         $2, 0x0($16)
    /* FBCD4 001FBCD4 09F84000 */  jalr       $2
    /* FBCD8 001FBCD8 00000000 */   nop
    /* FBCDC 001FBCDC 08000424 */  addiu      $4, $0, 0x8
    /* FBCE0 001FBCE0 2D280000 */  daddu      $5, $0, $0
    /* FBCE4 001FBCE4 0000028E */  lw         $2, 0x0($16)
    /* FBCE8 001FBCE8 09F84000 */  jalr       $2
    /* FBCEC 001FBCEC 00000000 */   nop
    /* FBCF0 001FBCF0 0C000424 */  addiu      $4, $0, 0xC
    /* FBCF4 001FBCF4 01000524 */  addiu      $5, $0, 0x1
    /* FBCF8 001FBCF8 0000028E */  lw         $2, 0x0($16)
    /* FBCFC 001FBCFC 09F84000 */  jalr       $2
    /* FBD00 001FBD00 00000000 */   nop
    /* FBD04 001FBD04 01000424 */  addiu      $4, $0, 0x1
    /* FBD08 001FBD08 2D280000 */  daddu      $5, $0, $0
    /* FBD0C 001FBD0C 0000028E */  lw         $2, 0x0($16)
    /* FBD10 001FBD10 09F84000 */  jalr       $2
    /* FBD14 001FBD14 00000000 */   nop
    /* FBD18 001FBD18 02000424 */  addiu      $4, $0, 0x2
    /* FBD1C 001FBD1C 44000524 */  addiu      $5, $0, 0x44
    /* FBD20 001FBD20 10D90F0C */  jal        func_003f6440
    /* FBD24 001FBD24 00000000 */   nop
    /* FBD28 001FBD28 03000424 */  addiu      $4, $0, 0x3
    /* FBD2C 001FBD2C 0300023C */  lui        $2, (0x31801 >> 16)
    /* FBD30 001FBD30 01184534 */  ori        $5, $2, (0x31801 & 0xFFFF)
    /* FBD34 001FBD34 10D90F0C */  jal        func_003f6440
    /* FBD38 001FBD38 00000000 */   nop
    /* FBD3C 001FBD3C E027120C */  jal        func_00489f80
    /* FBD40 001FBD40 00000000 */   nop
    /* FBD44 001FBD44 FF000224 */  addiu      $2, $0, 0xFF
    /* FBD48 001FBD48 7C00A2A3 */  sb         $2, 0x7C($29)
    /* FBD4C 001FBD4C 7D00A2A3 */  sb         $2, 0x7D($29)
    /* FBD50 001FBD50 7E00A2A3 */  sb         $2, 0x7E($29)
    /* FBD54 001FBD54 02AD1546 */  mul.s      $f20, $f21, $f21
    /* FBD58 001FBD58 02A81446 */  mul.s      $f0, $f21, $f20
    /* FBD5C 001FBD5C 02A80046 */  mul.s      $f0, $f21, $f0
    /* FBD60 001FBD60 82A80046 */  mul.s      $f2, $f21, $f0
    /* FBD64 001FBD64 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FBD68 001FBD68 00088244 */  mtc1       $2, $f1
    /* FBD6C 001FBD6C 00008044 */  mtc1       $0, $f0
    /* FBD70 001FBD70 00000000 */  nop
    /* FBD74 001FBD74 18000146 */  adda.s     $f0, $f1
    /* FBD78 001FBD78 5DA80246 */  msub.s     $f1, $f21, $f2
    /* FBD7C 001FBD7C 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* FBD80 001FBD80 00008244 */  mtc1       $2, $f0
    /* FBD84 001FBD84 00000000 */  nop
    /* FBD88 001FBD88 42000146 */  mul.s      $f1, $f0, $f1
    /* FBD8C 001FBD8C 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* FBD90 001FBD90 00008244 */  mtc1       $2, $f0
    /* FBD94 001FBD94 00000000 */  nop
    /* FBD98 001FBD98 36000146 */  c.le.s     $f0, $f1
    /* FBD9C 001FBD9C 07000145 */  bc1t       .L001FBDBC
    /* FBDA0 001FBDA0 00000000 */   nop
    /* FBDA4 001FBDA4 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FBDA8 001FBDA8 00000344 */  mfc1       $3, $f0
    /* FBDAC 001FBDAC 00000000 */  nop
    /* FBDB0 001FBDB0 FF006330 */  andi       $3, $3, 0xFF
    /* FBDB4 001FBDB4 07000010 */  b          .L001FBDD4
    /* FBDB8 001FBDB8 00000000 */   nop
  .L001FBDBC:
    /* FBDBC 001FBDBC 01080046 */  sub.s      $f0, $f1, $f0
    /* FBDC0 001FBDC0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FBDC4 001FBDC4 00000344 */  mfc1       $3, $f0
    /* FBDC8 001FBDC8 0080023C */  lui        $2, (0x80000000 >> 16)
    /* FBDCC 001FBDCC 25186200 */  or         $3, $3, $2
    /* FBDD0 001FBDD0 FF006330 */  andi       $3, $3, 0xFF
  .L001FBDD4:
    /* FBDD4 001FBDD4 7F00A3A3 */  sb         $3, 0x7F($29)
    /* FBDD8 001FBDD8 7C00A427 */  addiu      $4, $29, 0x7C
    /* FBDDC 001FBDDC 2D280000 */  daddu      $5, $0, $0
    /* FBDE0 001FBDE0 1C72110C */  jal        func_0045c870
    /* FBDE4 001FBDE4 00000000 */   nop
    /* FBDE8 001FBDE8 FF000224 */  addiu      $2, $0, 0xFF
    /* FBDEC 001FBDEC 7800A2A3 */  sb         $2, 0x78($29)
    /* FBDF0 001FBDF0 7900A2A3 */  sb         $2, 0x79($29)
    /* FBDF4 001FBDF4 7A00A2A3 */  sb         $2, 0x7A($29)
    /* FBDF8 001FBDF8 2043023C */  lui        $2, (0x43200000 >> 16)
    /* FBDFC 001FBDFC 00088244 */  mtc1       $2, $f1
    /* FBE00 001FBE00 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FBE04 001FBE04 00008244 */  mtc1       $2, $f0
    /* FBE08 001FBE08 00000000 */  nop
    /* FBE0C 001FBE0C 01001446 */  sub.s      $f0, $f0, $f20
    /* FBE10 001FBE10 42080046 */  mul.s      $f1, $f1, $f0
    /* FBE14 001FBE14 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* FBE18 001FBE18 00008244 */  mtc1       $2, $f0
    /* FBE1C 001FBE1C 00000000 */  nop
    /* FBE20 001FBE20 36000146 */  c.le.s     $f0, $f1
    /* FBE24 001FBE24 07000145 */  bc1t       .L001FBE44
    /* FBE28 001FBE28 00000000 */   nop
    /* FBE2C 001FBE2C 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FBE30 001FBE30 00000344 */  mfc1       $3, $f0
    /* FBE34 001FBE34 00000000 */  nop
    /* FBE38 001FBE38 FF006330 */  andi       $3, $3, 0xFF
    /* FBE3C 001FBE3C 07000010 */  b          .L001FBE5C
    /* FBE40 001FBE40 00000000 */   nop
  .L001FBE44:
    /* FBE44 001FBE44 01080046 */  sub.s      $f0, $f1, $f0
    /* FBE48 001FBE48 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* FBE4C 001FBE4C 00000344 */  mfc1       $3, $f0
    /* FBE50 001FBE50 0080023C */  lui        $2, (0x80000000 >> 16)
    /* FBE54 001FBE54 25186200 */  or         $3, $3, $2
    /* FBE58 001FBE58 FF006330 */  andi       $3, $3, 0xFF
  .L001FBE5C:
    /* FBE5C 001FBE5C 7B00A3A3 */  sb         $3, 0x7B($29)
    /* FBE60 001FBE60 6AB48297 */  lhu        $2, -0x4B96($28)
    /* FBE64 001FBE64 06004004 */  bltz       $2, .L001FBE80
    /* FBE68 001FBE68 00000000 */   nop
    /* FBE6C 001FBE6C 00008244 */  mtc1       $2, $f0
    /* FBE70 001FBE70 00000000 */  nop
    /* FBE74 001FBE74 60008046 */  cvt.s.w    $f1, $f0
    /* FBE78 001FBE78 08000010 */  b          .L001FBE9C
    /* FBE7C 001FBE7C 00000000 */   nop
  .L001FBE80:
    /* FBE80 001FBE80 42180200 */  srl        $3, $2, 1
    /* FBE84 001FBE84 01004230 */  andi       $2, $2, 0x1
    /* FBE88 001FBE88 25186200 */  or         $3, $3, $2
    /* FBE8C 001FBE8C 00008344 */  mtc1       $3, $f0
    /* FBE90 001FBE90 00000000 */  nop
    /* FBE94 001FBE94 60008046 */  cvt.s.w    $f1, $f0
    /* FBE98 001FBE98 40080146 */  add.s      $f1, $f1, $f1
  .L001FBE9C:
    /* FBE9C 001FBE9C A041023C */  lui        $2, (0x41A00000 >> 16)
    /* FBEA0 001FBEA0 00008244 */  mtc1       $2, $f0
    /* FBEA4 001FBEA4 00000000 */  nop
    /* FBEA8 001FBEA8 43080046 */  div.s      $f1, $f1, $f0
    /* FBEAC 001FBEAC C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* FBEB0 001FBEB0 00008244 */  mtc1       $2, $f0
    /* FBEB4 001FBEB4 00000000 */  nop
    /* FBEB8 001FBEB8 02050146 */  mul.s      $f20, $f0, $f1
    /* FBEBC 001FBEBC 485C110C */  jal        func_00457120
    /* FBEC0 001FBEC0 00000000 */   nop
    /* FBEC4 001FBEC4 07000424 */  addiu      $4, $0, 0x7
    /* FBEC8 001FBEC8 02000524 */  addiu      $5, $0, 0x2
    /* FBECC 001FBECC 0000028E */  lw         $2, 0x0($16)
    /* FBED0 001FBED0 09F84000 */  jalr       $2
    /* FBED4 001FBED4 00000000 */   nop
    /* FBED8 001FBED8 14000424 */  addiu      $4, $0, 0x14
    /* FBEDC 001FBEDC 01000524 */  addiu      $5, $0, 0x1
    /* FBEE0 001FBEE0 0000028E */  lw         $2, 0x0($16)
    /* FBEE4 001FBEE4 09F84000 */  jalr       $2
    /* FBEE8 001FBEE8 00000000 */   nop
    /* FBEEC 001FBEEC 0E000424 */  addiu      $4, $0, 0xE
    /* FBEF0 001FBEF0 2D280000 */  daddu      $5, $0, $0
    /* FBEF4 001FBEF4 0000028E */  lw         $2, 0x0($16)
    /* FBEF8 001FBEF8 09F84000 */  jalr       $2
    /* FBEFC 001FBEFC 00000000 */   nop
    /* FBF00 001FBF00 06000424 */  addiu      $4, $0, 0x6
    /* FBF04 001FBF04 2D280000 */  daddu      $5, $0, $0
    /* FBF08 001FBF08 0000028E */  lw         $2, 0x0($16)
    /* FBF0C 001FBF0C 09F84000 */  jalr       $2
    /* FBF10 001FBF10 00000000 */   nop
    /* FBF14 001FBF14 08000424 */  addiu      $4, $0, 0x8
    /* FBF18 001FBF18 2D280000 */  daddu      $5, $0, $0
    /* FBF1C 001FBF1C 0000028E */  lw         $2, 0x0($16)
    /* FBF20 001FBF20 09F84000 */  jalr       $2
    /* FBF24 001FBF24 00000000 */   nop
    /* FBF28 001FBF28 0C000424 */  addiu      $4, $0, 0xC
    /* FBF2C 001FBF2C 01000524 */  addiu      $5, $0, 0x1
    /* FBF30 001FBF30 0000028E */  lw         $2, 0x0($16)
    /* FBF34 001FBF34 09F84000 */  jalr       $2
    /* FBF38 001FBF38 00000000 */   nop
    /* FBF3C 001FBF3C 01000424 */  addiu      $4, $0, 0x1
    /* FBF40 001FBF40 2D280000 */  daddu      $5, $0, $0
    /* FBF44 001FBF44 0000028E */  lw         $2, 0x0($16)
    /* FBF48 001FBF48 09F84000 */  jalr       $2
    /* FBF4C 001FBF4C 00000000 */   nop
    /* FBF50 001FBF50 02000424 */  addiu      $4, $0, 0x2
    /* FBF54 001FBF54 44000524 */  addiu      $5, $0, 0x44
    /* FBF58 001FBF58 10D90F0C */  jal        func_003f6440
    /* FBF5C 001FBF5C 00000000 */   nop
    /* FBF60 001FBF60 03000424 */  addiu      $4, $0, 0x3
    /* FBF64 001FBF64 0300023C */  lui        $2, (0x31801 >> 16)
    /* FBF68 001FBF68 01184534 */  ori        $5, $2, (0x31801 & 0xFFFF)
    /* FBF6C 001FBF6C 10D90F0C */  jal        func_003f6440
    /* FBF70 001FBF70 00000000 */   nop
    /* FBF74 001FBF74 2D200000 */  daddu      $4, $0, $0
    /* FBF78 001FBF78 06A30046 */  mov.s      $f12, $f20
    /* FBF7C 001FBF7C 46A30046 */  mov.s      $f13, $f20
    /* FBF80 001FBF80 8800023C */  lui        $2, %hi(D_008872FC)
    /* FBF84 001FBF84 FC724EC4 */  lwc1       $f14, %lo(D_008872FC)($2)
    /* FBF88 001FBF88 7800A58F */  lw         $5, 0x78($29)
    /* FBF8C 001FBF8C A411080C */  jal        func_00204690
    /* FBF90 001FBF90 00000000 */   nop
    /* FBF94 001FBF94 0028120C */  jal        func_0048a000
    /* FBF98 001FBF98 00000000 */   nop
    /* FBF9C 001FBF9C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FBFA0 001FBFA0 00608244 */  mtc1       $2, $f12
    /* FBFA4 001FBFA4 D8A48427 */  addiu      $4, $28, -0x5B28
    /* FBFA8 001FBFA8 54000524 */  addiu      $5, $0, 0x54
    /* FBFAC 001FBFAC 0300023C */  lui        $2, (0x31801 >> 16)
    /* FBFB0 001FBFB0 01184634 */  ori        $6, $2, (0x31801 & 0xFFFF)
    /* FBFB4 001FBFB4 01000724 */  addiu      $7, $0, 0x1
    /* FBFB8 001FBFB8 20ED070C */  jal        func_001fb480
    /* FBFBC 001FBFBC 00000000 */   nop
    /* FBFC0 001FBFC0 6AB48297 */  lhu        $2, -0x4B96($28)
    /* FBFC4 001FBFC4 14004228 */  slti       $2, $2, 0x14
    /* FBFC8 001FBFC8 46004014 */  bnez       $2, .L001FC0E4
    /* FBFCC 001FBFCC 00000000 */   nop
    /* FBFD0 001FBFD0 03000224 */  addiu      $2, $0, 0x3
    /* FBFD4 001FBFD4 000022A2 */  sb         $2, 0x0($17)
    /* FBFD8 001FBFD8 42000010 */  b          .L001FC0E4
    /* FBFDC 001FBFDC 00000000 */   nop
  .L001FBFE0:
    /* FBFE0 001FBFE0 FFFF4224 */  addiu      $2, $2, -0x1
    /* FBFE4 001FBFE4 6CB482A7 */  sh         $2, -0x4B94($28)
  .L001FBFE8:
    /* FBFE8 001FBFE8 69B48293 */  lbu        $2, -0x4B97($28)
    /* FBFEC 001FBFEC 3D004014 */  bnez       $2, .L001FC0E4
    /* FBFF0 001FBFF0 00000000 */   nop
    /* FBFF4 001FBFF4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* FBFF8 001FBFF8 00608244 */  mtc1       $2, $f12
    /* FBFFC 001FBFFC D8A48427 */  addiu      $4, $28, -0x5B28
    /* FC000 001FC000 44000524 */  addiu      $5, $0, 0x44
    /* FC004 001FC004 0300023C */  lui        $2, (0x31801 >> 16)
    /* FC008 001FC008 01184634 */  ori        $6, $2, (0x31801 & 0xFFFF)
    /* FC00C 001FC00C 01000724 */  addiu      $7, $0, 0x1
    /* FC010 001FC010 20ED070C */  jal        func_001fb480
    /* FC014 001FC014 00000000 */   nop
    /* FC018 001FC018 06002396 */  lhu        $3, 0x6($17)
    /* FC01C 001FC01C 01000224 */  addiu      $2, $0, 0x1
    /* FC020 001FC020 04006214 */  bne        $3, $2, .L001FC034
    /* FC024 001FC024 00000000 */   nop
    /* FC028 001FC028 F08294C7 */  lwc1       $f20, -0x7D10($28)
    /* FC02C 001FC02C 02000010 */  b          .L001FC038
    /* FC030 001FC030 00000000 */   nop
  .L001FC034:
    /* FC034 001FC034 F48294C7 */  lwc1       $f20, -0x7D0C($28)
  .L001FC038:
    /* FC038 001FC038 FF000224 */  addiu      $2, $0, 0xFF
    /* FC03C 001FC03C 7C00A2A3 */  sb         $2, 0x7C($29)
    /* FC040 001FC040 7D00A2A3 */  sb         $2, 0x7D($29)
    /* FC044 001FC044 7E00A2A3 */  sb         $2, 0x7E($29)
    /* FC048 001FC048 06002396 */  lhu        $3, 0x6($17)
    /* FC04C 001FC04C 01000224 */  addiu      $2, $0, 0x1
    /* FC050 001FC050 04006214 */  bne        $3, $2, .L001FC064
    /* FC054 001FC054 00000000 */   nop
    /* FC058 001FC058 06000224 */  addiu      $2, $0, 0x6
    /* FC05C 001FC05C 02000010 */  b          .L001FC068
    /* FC060 001FC060 00000000 */   nop
  .L001FC064:
    /* FC064 001FC064 0A000224 */  addiu      $2, $0, 0xA
  .L001FC068:
    /* FC068 001FC068 7F00A2A3 */  sb         $2, 0x7F($29)
    /* FC06C 001FC06C 06A30046 */  mov.s      $f12, $f20
    /* FC070 001FC070 7C00A427 */  addiu      $4, $29, 0x7C
    /* FC074 001FC074 44000524 */  addiu      $5, $0, 0x44
    /* FC078 001FC078 0300023C */  lui        $2, (0x31801 >> 16)
    /* FC07C 001FC07C 01184634 */  ori        $6, $2, (0x31801 & 0xFFFF)
    /* FC080 001FC080 02000724 */  addiu      $7, $0, 0x2
    /* FC084 001FC084 20ED070C */  jal        func_001fb480
    /* FC088 001FC088 00000000 */   nop
    /* FC08C 001FC08C 05000224 */  addiu      $2, $0, 0x5
    /* FC090 001FC090 7F00A2A3 */  sb         $2, 0x7F($29)
    /* FC094 001FC094 06A30046 */  mov.s      $f12, $f20
    /* FC098 001FC098 7C00A427 */  addiu      $4, $29, 0x7C
    /* FC09C 001FC09C 48000524 */  addiu      $5, $0, 0x48
    /* FC0A0 001FC0A0 0300023C */  lui        $2, (0x31801 >> 16)
    /* FC0A4 001FC0A4 01184634 */  ori        $6, $2, (0x31801 & 0xFFFF)
    /* FC0A8 001FC0A8 02000724 */  addiu      $7, $0, 0x2
    /* FC0AC 001FC0AC 20ED070C */  jal        func_001fb480
    /* FC0B0 001FC0B0 00000000 */   nop
    /* FC0B4 001FC0B4 0B000010 */  b          .L001FC0E4
    /* FC0B8 001FC0B8 00000000 */   nop
  .L001FC0BC:
    /* FC0BC 001FC0BC C889040C */  jal        func_00122720
    /* FC0C0 001FC0C0 00000000 */   nop
    /* FC0C4 001FC0C4 07004010 */  beqz       $2, .L001FC0E4
    /* FC0C8 001FC0C8 00000000 */   nop
    /* FC0CC 001FC0CC 01000424 */  addiu      $4, $0, 0x1
    /* FC0D0 001FC0D0 1E000524 */  addiu      $5, $0, 0x1E
    /* FC0D4 001FC0D4 9089040C */  jal        func_00122640
    /* FC0D8 001FC0D8 00000000 */   nop
    /* FC0DC 001FC0DC 68B480A3 */  sb         $0, -0x4B98($28)
    /* FC0E0 001FC0E0 FFFF1224 */  addiu      $18, $0, -0x1
  .L001FC0E4:
    /* FC0E4 001FC0E4 2D800000 */  daddu      $16, $0, $0
    /* FC0E8 001FC0E8 0D000010 */  b          .L001FC120
    /* FC0EC 001FC0EC 00000000 */   nop
  .L001FC0F0:
    /* FC0F0 001FC0F0 80201000 */  sll        $4, $16, 2
    /* FC0F4 001FC0F4 6200023C */  lui        $2, %hi(D_00625210)
    /* FC0F8 001FC0F8 10524224 */  addiu      $2, $2, %lo(D_00625210)
    /* FC0FC 001FC0FC 21184400 */  addu       $3, $2, $4
    /* FC100 001FC100 21109D00 */  addu       $2, $4, $29
    /* FC104 001FC104 0000648C */  lw         $4, 0x0($3)
    /* FC108 001FC108 5000458C */  lw         $5, 0x50($2)
    /* FC10C 001FC10C 8800023C */  lui        $2, %hi(D_00887300)
    /* FC110 001FC110 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* FC114 001FC114 09F84000 */  jalr       $2
    /* FC118 001FC118 00000000 */   nop
    /* FC11C 001FC11C 01001026 */  addiu      $16, $16, 0x1
  .L001FC120:
    /* FC120 001FC120 0700022E */  sltiu      $2, $16, 0x7
    /* FC124 001FC124 F2FF4014 */  bnez       $2, .L001FC0F0
    /* FC128 001FC128 00000000 */   nop
    /* FC12C 001FC12C 01000424 */  addiu      $4, $0, 0x1
    /* FC130 001FC130 2D280000 */  daddu      $5, $0, $0
    /* FC134 001FC134 8800023C */  lui        $2, %hi(D_00887300)
    /* FC138 001FC138 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* FC13C 001FC13C 09F84000 */  jalr       $2
    /* FC140 001FC140 00000000 */   nop
    /* FC144 001FC144 02000424 */  addiu      $4, $0, 0x2
    /* FC148 001FC148 44000524 */  addiu      $5, $0, 0x44
    /* FC14C 001FC14C 10D90F0C */  jal        func_003f6440
    /* FC150 001FC150 00000000 */   nop
    /* FC154 001FC154 03000424 */  addiu      $4, $0, 0x3
    /* FC158 001FC158 0700023C */  lui        $2, (0x717FB >> 16)
    /* FC15C 001FC15C FB174534 */  ori        $5, $2, (0x717FB & 0xFFFF)
    /* FC160 001FC160 10D90F0C */  jal        func_003f6440
    /* FC164 001FC164 00000000 */   nop
    /* FC168 001FC168 485C110C */  jal        func_00457120
    /* FC16C 001FC16C 00000000 */   nop
    /* FC170 001FC170 2D204000 */  daddu      $4, $2, $0
    /* FC174 001FC174 44A00F0C */  jal        func_003e8110
    /* FC178 001FC178 00000000 */   nop
    /* FC17C 001FC17C 2D104002 */  daddu      $2, $18, $0
  .L001FC180:
    /* FC180 001FC180 4000BFDF */  ld         $31, 0x40($29)
    /* FC184 001FC184 3000B27B */  lq         $18, 0x30($29)
    /* FC188 001FC188 2000B17B */  lq         $17, 0x20($29)
    /* FC18C 001FC18C 1000B07B */  lq         $16, 0x10($29)
    /* FC190 001FC190 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* FC194 001FC194 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* FC198 001FC198 8000BD27 */  addiu      $29, $29, 0x80
    /* FC19C 001FC19C 0800E003 */  jr         $31
    /* FC1A0 001FC1A0 00000000 */   nop
    /* FC1A4 001FC1A4 00000000 */  nop
    /* FC1A8 001FC1A8 00000000 */  nop
    /* FC1AC 001FC1AC 00000000 */  nop
.size func_001fbb50, 0x660
