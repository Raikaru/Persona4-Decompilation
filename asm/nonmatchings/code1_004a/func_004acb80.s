.section .text
.set noat
.set noreorder
glabel func_004acb80
    /* 3ACB80 004ACB80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ACB84 004ACB84 1000BFFF */  sd         $31, 0x10($29)
    /* 3ACB88 004ACB88 0000B07F */  sq         $16, 0x0($29)
    /* 3ACB8C 004ACB8C 2D808000 */  daddu      $16, $4, $0
    /* 3ACB90 004ACB90 B400848C */  lw         $4, 0xB4($4)
    /* 3ACB94 004ACB94 2D280000 */  daddu      $5, $0, $0
    /* 3ACB98 004ACB98 20E8110C */  jal        func_0047a080
    /* 3ACB9C 004ACB9C 00000000 */   nop
    /* 3ACBA0 004ACBA0 004F033C */  lui        $3, (0x4F000000 >> 16)
    /* 3ACBA4 004ACBA4 00088344 */  mtc1       $3, $f1
    /* 3ACBA8 004ACBA8 00000000 */  nop
    /* 3ACBAC 004ACBAC 36080046 */  c.le.s     $f1, $f0
    /* 3ACBB0 004ACBB0 05000145 */  bc1t       .L004ACBC8
    /* 3ACBB4 004ACBB4 00000000 */   nop
    /* 3ACBB8 004ACBB8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3ACBBC 004ACBBC 00000444 */  mfc1       $4, $f0
    /* 3ACBC0 004ACBC0 06000010 */  b          .L004ACBDC
    /* 3ACBC4 004ACBC4 00000000 */   nop
  .L004ACBC8:
    /* 3ACBC8 004ACBC8 01000146 */  sub.s      $f0, $f0, $f1
    /* 3ACBCC 004ACBCC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3ACBD0 004ACBD0 00000444 */  mfc1       $4, $f0
    /* 3ACBD4 004ACBD4 0080033C */  lui        $3, %hi(D_80000001)
    /* 3ACBD8 004ACBD8 25208300 */  or         $4, $4, $3
  .L004ACBDC:
    /* 3ACBDC 004ACBDC 01008524 */  addiu      $5, $4, %lo(D_80000001)
    /* 3ACBE0 004ACBE0 9C00038E */  lw         $3, 0x9C($16)
    /* 3ACBE4 004ACBE4 2B086500 */  sltu       $1, $3, $5
    /* 3ACBE8 004ACBE8 03002010 */  beqz       $1, .L004ACBF8
    /* 3ACBEC 004ACBEC 00000000 */   nop
    /* 3ACBF0 004ACBF0 2D006014 */  bnez       $3, .L004ACCA8
    /* 3ACBF4 004ACBF4 00000000 */   nop
  .L004ACBF8:
    /* 3ACBF8 004ACBF8 B8000492 */  lbu        $4, 0xB8($16)
    /* 3ACBFC 004ACBFC 01000324 */  addiu      $3, $0, 0x1
    /* 3ACC00 004ACC00 11008314 */  bne        $4, $3, .L004ACC48
    /* 3ACC04 004ACC04 00000000 */   nop
    /* 3ACC08 004ACC08 7400038E */  lw         $3, 0x74($16)
    /* 3ACC0C 004ACC0C 2B08A300 */  sltu       $1, $5, $3
    /* 3ACC10 004ACC10 23002014 */  bnez       $1, .L004ACCA0
    /* 3ACC14 004ACC14 00000000 */   nop
    /* 3ACC18 004ACC18 700000C6 */  lwc1       $f0, 0x70($16)
    /* 3ACC1C 004ACC1C 60008046 */  cvt.s.w    $f1, $f0
    /* 3ACC20 004ACC20 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3ACC24 004ACC24 00008244 */  mtc1       $2, $f0
    /* 3ACC28 004ACC28 00000000 */  nop
    /* 3ACC2C 004ACC2C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 3ACC30 004ACC30 B400048E */  lw         $4, 0xB4($16)
    /* 3ACC34 004ACC34 2D280000 */  daddu      $5, $0, $0
    /* 3ACC38 004ACC38 98E7110C */  jal        func_00479e60
    /* 3ACC3C 004ACC3C 00000000 */   nop
    /* 3ACC40 004ACC40 17000010 */  b          .L004ACCA0
    /* 3ACC44 004ACC44 00000000 */   nop
  .L004ACC48:
    /* 3ACC48 004ACC48 80000392 */  lbu        $3, 0x80($16)
    /* 3ACC4C 004ACC4C 14006010 */  beqz       $3, .L004ACCA0
    /* 3ACC50 004ACC50 00000000 */   nop
    /* 3ACC54 004ACC54 7000038E */  lw         $3, 0x70($16)
    /* 3ACC58 004ACC58 2B08A300 */  sltu       $1, $5, $3
    /* 3ACC5C 004ACC5C 10002014 */  bnez       $1, .L004ACCA0
    /* 3ACC60 004ACC60 00000000 */   nop
    /* 3ACC64 004ACC64 7400038E */  lw         $3, 0x74($16)
    /* 3ACC68 004ACC68 2B08A300 */  sltu       $1, $5, $3
    /* 3ACC6C 004ACC6C 0C002010 */  beqz       $1, .L004ACCA0
    /* 3ACC70 004ACC70 00000000 */   nop
    /* 3ACC74 004ACC74 00008344 */  mtc1       $3, $f0
    /* 3ACC78 004ACC78 00000000 */  nop
    /* 3ACC7C 004ACC7C 60008046 */  cvt.s.w    $f1, $f0
    /* 3ACC80 004ACC80 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3ACC84 004ACC84 00008244 */  mtc1       $2, $f0
    /* 3ACC88 004ACC88 00000000 */  nop
    /* 3ACC8C 004ACC8C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 3ACC90 004ACC90 B400048E */  lw         $4, 0xB4($16)
    /* 3ACC94 004ACC94 2D280000 */  daddu      $5, $0, $0
    /* 3ACC98 004ACC98 98E7110C */  jal        func_00479e60
    /* 3ACC9C 004ACC9C 00000000 */   nop
  .L004ACCA0:
    /* 3ACCA0 004ACCA0 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 3ACCA4 004ACCA4 080003AE */  sw         $3, 0x8($16)
  .L004ACCA8:
    /* 3ACCA8 004ACCA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3ACCAC 004ACCAC 0000B07B */  lq         $16, 0x0($29)
    /* 3ACCB0 004ACCB0 2000BD27 */  addiu      $29, $29, 0x20
    /* 3ACCB4 004ACCB4 0800E003 */  jr         $31
    /* 3ACCB8 004ACCB8 00000000 */   nop
    /* 3ACCBC 004ACCBC 00000000 */  nop
.size func_004acb80, 0x140
