.section .text
.set noat
.set noreorder
glabel func_0011bb90
    /* 1BB90 0011BB90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BB94 0011BB94 1000BFFF */  sd         $31, 0x10($29)
    /* 1BB98 0011BB98 0000B07F */  sq         $16, 0x0($29)
    /* 1BB9C 0011BB9C 3800908C */  lw         $16, 0x38($4)
    /* 1BBA0 0011BBA0 3405038E */  lw         $3, 0x534($16)
    /* 1BBA4 0011BBA4 02006330 */  andi       $3, $3, 0x2
    /* 1BBA8 0011BBA8 2C006014 */  bnez       $3, .L0011BC5C
    /* 1BBAC 0011BBAC 00000000 */   nop
    /* 1BBB0 0011BBB0 05050492 */  lbu        $4, 0x505($16)
    /* 1BBB4 0011BBB4 FF000324 */  addiu      $3, $0, 0xFF
    /* 1BBB8 0011BBB8 28008310 */  beq        $4, $3, .L0011BC5C
    /* 1BBBC 0011BBBC 00000000 */   nop
    /* 1BBC0 0011BBC0 2D200002 */  daddu      $4, $16, $0
    /* 1BBC4 0011BBC4 906E040C */  jal        func_0011ba40
    /* 1BBC8 0011BBC8 00000000 */   nop
    /* 1BBCC 0011BBCC 080500A6 */  sh         $0, 0x508($16)
    /* 1BBD0 0011BBD0 05050292 */  lbu        $2, 0x505($16)
    /* 1BBD4 0011BBD4 040502A2 */  sb         $2, 0x504($16)
    /* 1BBD8 0011BBD8 FF000224 */  addiu      $2, $0, 0xFF
    /* 1BBDC 0011BBDC 060502A2 */  sb         $2, 0x506($16)
    /* 1BBE0 0011BBE0 FC0401C6 */  lwc1       $f1, 0x4FC($16)
    /* 1BBE4 0011BBE4 0343023C */  lui        $2, (0x43030000 >> 16)
    /* 1BBE8 0011BBE8 00008244 */  mtc1       $2, $f0
    /* 1BBEC 0011BBEC 00000000 */  nop
    /* 1BBF0 0011BBF0 80000146 */  add.s      $f2, $f0, $f1
    /* 1BBF4 0011BBF4 2800A2E7 */  swc1       $f2, 0x28($29)
    /* 1BBF8 0011BBF8 000501C6 */  lwc1       $f1, 0x500($16)
    /* 1BBFC 0011BBFC 6CC2023C */  lui        $2, (0xC26C0000 >> 16)
    /* 1BC00 0011BC00 00008244 */  mtc1       $2, $f0
    /* 1BC04 0011BC04 00000000 */  nop
    /* 1BC08 0011BC08 40000146 */  add.s      $f1, $f0, $f1
    /* 1BC0C 0011BC0C 2C00A1E7 */  swc1       $f1, 0x2C($29)
    /* 1BC10 0011BC10 2044023C */  lui        $2, (0x44200000 >> 16)
    /* 1BC14 0011BC14 00008244 */  mtc1       $2, $f0
    /* 1BC18 0011BC18 00000000 */  nop
    /* 1BC1C 0011BC1C 00000246 */  add.s      $f0, $f0, $f2
    /* 1BC20 0011BC20 2000A0E7 */  swc1       $f0, 0x20($29)
    /* 1BC24 0011BC24 2400A1E7 */  swc1       $f1, 0x24($29)
    /* 1BC28 0011BC28 F804048E */  lw         $4, 0x4F8($16)
    /* 1BC2C 0011BC2C 2000A527 */  addiu      $5, $29, 0x20
    /* 1BC30 0011BC30 2800A627 */  addiu      $6, $29, 0x28
    /* 1BC34 0011BC34 AC78040C */  jal        func_0011e2b0
    /* 1BC38 0011BC38 00000000 */   nop
    /* 1BC3C 0011BC3C F804048E */  lw         $4, 0x4F8($16)
    /* 1BC40 0011BC40 2D280000 */  daddu      $5, $0, $0
    /* 1BC44 0011BC44 9078040C */  jal        func_0011e240
    /* 1BC48 0011BC48 00000000 */   nop
    /* 1BC4C 0011BC4C 2D200002 */  daddu      $4, $16, $0
    /* 1BC50 0011BC50 2D280000 */  daddu      $5, $0, $0
    /* 1BC54 0011BC54 A86A040C */  jal        func_0011aaa0
    /* 1BC58 0011BC58 00000000 */   nop
  .L0011BC5C:
    /* 1BC5C 0011BC5C 1000BFDF */  ld         $31, 0x10($29)
    /* 1BC60 0011BC60 0000B07B */  lq         $16, 0x0($29)
    /* 1BC64 0011BC64 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BC68 0011BC68 0800E003 */  jr         $31
    /* 1BC6C 0011BC6C 00000000 */   nop
.size func_0011bb90, 0xe0
