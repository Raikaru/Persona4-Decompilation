.section .text
.set noat
.set noreorder
glabel func_0014ba40
    /* 4BA40 0014BA40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 4BA44 0014BA44 1000BFFF */  sd         $31, 0x10($29)
    /* 4BA48 0014BA48 0000B07F */  sq         $16, 0x0($29)
    /* 4BA4C 0014BA4C 3800908C */  lw         $16, 0x38($4)
    /* 4BA50 0014BA50 0400048E */  lw         $4, 0x4($16)
    /* 4BA54 0014BA54 94E8110C */  jal        func_0047a250
    /* 4BA58 0014BA58 00000000 */   nop
    /* 4BA5C 0014BA5C 00004590 */  lbu        $5, 0x0($2)
    /* 4BA60 0014BA60 01004490 */  lbu        $4, 0x1($2)
    /* 4BA64 0014BA64 02004390 */  lbu        $3, 0x2($2)
    /* 4BA68 0014BA68 03004290 */  lbu        $2, 0x3($2)
    /* 4BA6C 0014BA6C 2C00A5A3 */  sb         $5, 0x2C($29)
    /* 4BA70 0014BA70 2D00A4A3 */  sb         $4, 0x2D($29)
    /* 4BA74 0014BA74 2E00A3A3 */  sb         $3, 0x2E($29)
    /* 4BA78 0014BA78 2F00A2A3 */  sb         $2, 0x2F($29)
    /* 4BA7C 0014BA7C 0000038E */  lw         $3, 0x0($16)
    /* 4BA80 0014BA80 01000224 */  addiu      $2, $0, 0x1
    /* 4BA84 0014BA84 43006210 */  beq        $3, $2, .L0014BB94
    /* 4BA88 0014BA88 00000000 */   nop
    /* 4BA8C 0014BA8C 03006010 */  beqz       $3, .L0014BA9C
    /* 4BA90 0014BA90 00000000 */   nop
    /* 4BA94 0014BA94 3F000010 */  b          .L0014BB94
    /* 4BA98 0014BA98 00000000 */   nop
  .L0014BA9C:
    /* 4BA9C 0014BA9C 080000C6 */  lwc1       $f0, 0x8($16)
    /* 4BAA0 0014BAA0 0C0002C6 */  lwc1       $f2, 0xC($16)
    /* 4BAA4 0014BAA4 41000246 */  sub.s      $f1, $f0, $f2
    /* 4BAA8 0014BAA8 100000C6 */  lwc1       $f0, 0x10($16)
    /* 4BAAC 0014BAAC 20008046 */  cvt.s.w    $f0, $f0
    /* 4BAB0 0014BAB0 03080046 */  div.s      $f0, $f1, $f0
    /* 4BAB4 0014BAB4 40100046 */  add.s      $f1, $f2, $f0
    /* 4BAB8 0014BAB8 0C0001E6 */  swc1       $f1, 0xC($16)
    /* 4BABC 0014BABC 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 4BAC0 0014BAC0 00008244 */  mtc1       $2, $f0
    /* 4BAC4 0014BAC4 00000000 */  nop
    /* 4BAC8 0014BAC8 36000146 */  c.le.s     $f0, $f1
    /* 4BACC 0014BACC 07000145 */  bc1t       .L0014BAEC
    /* 4BAD0 0014BAD0 00000000 */   nop
    /* 4BAD4 0014BAD4 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 4BAD8 0014BAD8 00000344 */  mfc1       $3, $f0
    /* 4BADC 0014BADC 00000000 */  nop
    /* 4BAE0 0014BAE0 FF006330 */  andi       $3, $3, 0xFF
    /* 4BAE4 0014BAE4 07000010 */  b          .L0014BB04
    /* 4BAE8 0014BAE8 00000000 */   nop
  .L0014BAEC:
    /* 4BAEC 0014BAEC 01080046 */  sub.s      $f0, $f1, $f0
    /* 4BAF0 0014BAF0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 4BAF4 0014BAF4 00000344 */  mfc1       $3, $f0
    /* 4BAF8 0014BAF8 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 4BAFC 0014BAFC 25186200 */  or         $3, $3, $2
    /* 4BB00 0014BB00 FF006330 */  andi       $3, $3, 0xFF
  .L0014BB04:
    /* 4BB04 0014BB04 2F00A3A3 */  sb         $3, 0x2F($29)
    /* 4BB08 0014BB08 0400048E */  lw         $4, 0x4($16)
    /* 4BB0C 0014BB0C 2C00A527 */  addiu      $5, $29, 0x2C
    /* 4BB10 0014BB10 88E8110C */  jal        func_0047a220
    /* 4BB14 0014BB14 00000000 */   nop
    /* 4BB18 0014BB18 1000028E */  lw         $2, 0x10($16)
    /* 4BB1C 0014BB1C FFFF4224 */  addiu      $2, $2, -0x1
    /* 4BB20 0014BB20 100002AE */  sw         $2, 0x10($16)
    /* 4BB24 0014BB24 1B00401C */  bgtz       $2, .L0014BB94
    /* 4BB28 0014BB28 00000000 */   nop
    /* 4BB2C 0014BB2C 080001C6 */  lwc1       $f1, 0x8($16)
    /* 4BB30 0014BB30 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 4BB34 0014BB34 00008244 */  mtc1       $2, $f0
    /* 4BB38 0014BB38 00000000 */  nop
    /* 4BB3C 0014BB3C 36000146 */  c.le.s     $f0, $f1
    /* 4BB40 0014BB40 07000145 */  bc1t       .L0014BB60
    /* 4BB44 0014BB44 00000000 */   nop
    /* 4BB48 0014BB48 24080046 */  .word      0x46000824                    # cvt.w.s    $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 4BB4C 0014BB4C 00000344 */  mfc1       $3, $f0
    /* 4BB50 0014BB50 00000000 */  nop
    /* 4BB54 0014BB54 FF006330 */  andi       $3, $3, 0xFF
    /* 4BB58 0014BB58 07000010 */  b          .L0014BB78
    /* 4BB5C 0014BB5C 00000000 */   nop
  .L0014BB60:
    /* 4BB60 0014BB60 01080046 */  sub.s      $f0, $f1, $f0
    /* 4BB64 0014BB64 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 4BB68 0014BB68 00000344 */  mfc1       $3, $f0
    /* 4BB6C 0014BB6C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* 4BB70 0014BB70 25186200 */  or         $3, $3, $2
    /* 4BB74 0014BB74 FF006330 */  andi       $3, $3, 0xFF
  .L0014BB78:
    /* 4BB78 0014BB78 2F00A3A3 */  sb         $3, 0x2F($29)
    /* 4BB7C 0014BB7C 0400048E */  lw         $4, 0x4($16)
    /* 4BB80 0014BB80 2C00A527 */  addiu      $5, $29, 0x2C
    /* 4BB84 0014BB84 88E8110C */  jal        func_0047a220
    /* 4BB88 0014BB88 00000000 */   nop
    /* 4BB8C 0014BB8C 01000224 */  addiu      $2, $0, 0x1
    /* 4BB90 0014BB90 000002AE */  sw         $2, 0x0($16)
  .L0014BB94:
    /* 4BB94 0014BB94 2D100000 */  daddu      $2, $0, $0
    /* 4BB98 0014BB98 1000BFDF */  ld         $31, 0x10($29)
    /* 4BB9C 0014BB9C 0000B07B */  lq         $16, 0x0($29)
    /* 4BBA0 0014BBA0 3000BD27 */  addiu      $29, $29, 0x30
    /* 4BBA4 0014BBA4 0800E003 */  jr         $31
    /* 4BBA8 0014BBA8 00000000 */   nop
    /* 4BBAC 0014BBAC 00000000 */  nop
.size func_0014ba40, 0x170
