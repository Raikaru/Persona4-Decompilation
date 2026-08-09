.section .text
.set noat
.set noreorder
glabel func_004bdc20
    /* 3BDC20 004BDC20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BDC24 004BDC24 3100023C */  lui        $2, (0x316938 >> 16)
    /* 3BDC28 004BDC28 0000B0FF */  sd         $16, 0x0($29)
    /* 3BDC2C 004BDC2C 2D80A000 */  daddu      $16, $5, $0
    /* 3BDC30 004BDC30 0800BFFF */  sd         $31, 0x8($29)
    /* 3BDC34 004BDC34 38694234 */  ori        $2, $2, (0x316938 & 0xFFFF)
    /* 3BDC38 004BDC38 3D000012 */  beqz       $16, .L004BDD30
    /* 3BDC3C 004BDC3C 1000B4E7 */   swc1      $f20, 0x10($29)
    /* 3BDC40 004BDC40 40FC0324 */  addiu      $3, $0, -0x3C0
    /* 3BDC44 004BDC44 3A000312 */  beq        $16, $3, .L004BDD30
    /* 3BDC48 004BDC48 2D100000 */   daddu     $2, $0, $0
    /* 3BDC4C 004BDC4C 18008480 */  lb         $4, 0x18($4)
    /* 3BDC50 004BDC50 03008010 */  beqz       $4, .L004BDC60
    /* 3BDC54 004BDC54 01000224 */   addiu     $2, $0, 0x1
    /* 3BDC58 004BDC58 15008210 */  beq        $4, $2, .L004BDCB0
    /* 3BDC5C 004BDC5C 00000000 */   nop
  .L004BDC60:
    /* 3BDC60 004BDC60 00009044 */  mtc1       $16, $f0
    /* 3BDC64 004BDC64 20008046 */  cvt.s.w    $f0, $f0
    /* 3BDC68 004BDC68 4843013C */  lui        $1, (0x43480000 >> 16)
    /* 3BDC6C 004BDC6C 00608144 */  mtc1       $1, $f12
    /* 3BDC70 004BDC70 00000000 */  nop
    /* 3BDC74 004BDC74 00000000 */  nop
    /* 3BDC78 004BDC78 03030C46 */  div.s      $f12, $f0, $f12
    /* 3BDC7C 004BDC7C 3637110C */  jal        func_0044dcd8
    /* 3BDC80 004BDC80 00000000 */   nop
    /* 3BDC84 004BDC84 48800434 */  ori        $4, $0, 0x8048
    /* 3BDC88 004BDC88 FC230400 */  dsll32     $4, $4, 15
    /* 3BDC8C 004BDC8C 422E110C */  jal        func_0044b908
    /* 3BDC90 004BDC90 2D284000 */   daddu     $5, $2, $0
    /* 3BDC94 004BDC94 F639110C */  jal        func_0044e7d8
    /* 3BDC98 004BDC98 2D204000 */   daddu     $4, $2, $0
    /* 3BDC9C 004BDC9C 454A013C */  lui        $1, (0x4A45A4E0 >> 16)
    /* 3BDCA0 004BDCA0 E0A42134 */  ori        $1, $1, (0x4A45A4E0 & 0xFFFF)
    /* 3BDCA4 004BDCA4 00088144 */  mtc1       $1, $f1
    /* 3BDCA8 004BDCA8 15000010 */  b          .L004BDD00
    /* 3BDCAC 004BDCAC 02000146 */   mul.s     $f0, $f0, $f1
  .L004BDCB0:
    /* 3BDCB0 004BDCB0 1C810434 */  ori        $4, $0, 0x811C
    /* 3BDCB4 004BDCB4 3C2E110C */  jal        func_0044b8f0
    /* 3BDCB8 004BDCB8 FC230400 */   dsll32    $4, $4, 15
    /* 3BDCBC 004BDCBC F639110C */  jal        func_0044e7d8
    /* 3BDCC0 004BDCC0 2D204000 */   daddu     $4, $2, $0
    /* 3BDCC4 004BDCC4 23201000 */  negu       $4, $16
    /* 3BDCC8 004BDCC8 9639110C */  jal        func_0044e658
    /* 3BDCCC 004BDCCC 06050046 */   mov.s     $f20, $f0
    /* 3BDCD0 004BDCD0 2D204000 */  daddu      $4, $2, $0
    /* 3BDCD4 004BDCD4 3C2E110C */  jal        func_0044b8f0
    /* 3BDCD8 004BDCD8 00000000 */   nop
    /* 3BDCDC 004BDCDC F639110C */  jal        func_0044e7d8
    /* 3BDCE0 004BDCE0 2D204000 */   daddu     $4, $2, $0
    /* 3BDCE4 004BDCE4 7500023C */  lui        $2, %hi(D_007568C0)
    /* 3BDCE8 004BDCE8 C06841C4 */  lwc1       $f1, %lo(D_007568C0)($2)
    /* 3BDCEC 004BDCEC 60088046 */  cvt.s.w    $f1, $f1
    /* 3BDCF0 004BDCF0 42080046 */  mul.s      $f1, $f1, $f0
    /* 3BDCF4 004BDCF4 00000000 */  nop
    /* 3BDCF8 004BDCF8 00000000 */  nop
    /* 3BDCFC 004BDCFC 03081446 */  div.s      $f0, $f1, $f20
  .L004BDD00:
    /* 3BDD00 004BDD00 00088044 */  mtc1       $0, $f1
    /* 3BDD04 004BDD04 34080046 */  c.lt.s     $f1, $f0
    /* 3BDD08 004BDD08 01000245 */  bc1fl      .L004BDD10
    /* 3BDD0C 004BDD0C 06080046 */   mov.s     $f0, $f1
  .L004BDD10:
    /* 3BDD10 004BDD10 454A013C */  lui        $1, (0x4A45A4E0 >> 16)
    /* 3BDD14 004BDD14 E0A42134 */  ori        $1, $1, (0x4A45A4E0 & 0xFFFF)
    /* 3BDD18 004BDD18 00088144 */  mtc1       $1, $f1
    /* 3BDD1C 004BDD1C 34000146 */  c.lt.s     $f0, $f1
    /* 3BDD20 004BDD20 01000245 */  bc1fl      .L004BDD28
    /* 3BDD24 004BDD24 06080046 */   mov.s     $f0, $f1
  .L004BDD28:
    /* 3BDD28 004BDD28 64000046 */  .word      0x46000064                    # cvt.w.s    $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3BDD2C 004BDD2C 00080244 */  mfc1       $2, $f1
  .L004BDD30:
    /* 3BDD30 004BDD30 0000B0DF */  ld         $16, 0x0($29)
    /* 3BDD34 004BDD34 0800BFDF */  ld         $31, 0x8($29)
    /* 3BDD38 004BDD38 1000B4C7 */  lwc1       $f20, 0x10($29)
    /* 3BDD3C 004BDD3C 0800E003 */  jr         $31
    /* 3BDD40 004BDD40 2000BD27 */   addiu     $29, $29, 0x20
    /* 3BDD44 004BDD44 00000000 */  nop
.size func_004bdc20, 0x128
