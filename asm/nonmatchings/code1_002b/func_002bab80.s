.section .text
.set noat
.set noreorder
glabel func_002bab80
    /* 1BAB80 002BAB80 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1BAB84 002BAB84 3000BFFF */  sd         $31, 0x30($29)
    /* 1BAB88 002BAB88 2000B27F */  sq         $18, 0x20($29)
    /* 1BAB8C 002BAB8C 1000B17F */  sq         $17, 0x10($29)
    /* 1BAB90 002BAB90 0000B07F */  sq         $16, 0x0($29)
    /* 1BAB94 002BAB94 2D888000 */  daddu      $17, $4, $0
    /* 1BAB98 002BAB98 2CEB0A0C */  jal        func_002bacb0
    /* 1BAB9C 002BAB9C 00000000 */   nop
    /* 1BABA0 002BABA0 3C860200 */  dsll32     $16, $2, 24
    /* 1BABA4 002BABA4 3F861000 */  dsra32     $16, $16, 24
    /* 1BABA8 002BABA8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BABAC 002BABAC 03000216 */  bne        $16, $2, .L002BABBC
    /* 1BABB0 002BABB0 00000000 */   nop
    /* 1BABB4 002BABB4 36000010 */  b          .L002BAC90
    /* 1BABB8 002BABB8 00000000 */   nop
  .L002BABBC:
    /* 1BABBC 002BABBC 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BABC0 002BABC0 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BABC4 002BABC4 90000524 */  addiu      $5, $0, 0x90
    /* 1BABC8 002BABC8 A43A110C */  jal        func_0044ea90
    /* 1BABCC 002BABCC 00000000 */   nop
    /* 1BABD0 002BABD0 01000424 */  addiu      $4, $0, 0x1
    /* 1BABD4 002BABD4 10000524 */  addiu      $5, $0, 0x10
    /* 1BABD8 002BABD8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1BABDC 002BABDC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1BABE0 002BABE0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1BABE4 002BABE4 09F84000 */  jalr       $2
    /* 1BABE8 002BABE8 00000000 */   nop
    /* 1BABEC 002BABEC 3C1E1000 */  dsll32     $3, $16, 24
    /* 1BABF0 002BABF0 3F1E0300 */  dsra32     $3, $3, 24
    /* 1BABF4 002BABF4 80200300 */  sll        $4, $3, 2
    /* 1BABF8 002BABF8 8800033C */  lui        $3, %hi(D_00882F40)
    /* 1BABFC 002BABFC 402F6324 */  addiu      $3, $3, %lo(D_00882F40)
    /* 1BAC00 002BAC00 21286400 */  addu       $5, $3, $4
    /* 1BAC04 002BAC04 0000A2AC */  sw         $2, 0x0($5)
    /* 1BAC08 002BAC08 09004010 */  beqz       $2, .L002BAC30
    /* 1BAC0C 002BAC0C 00000000 */   nop
    /* 1BAC10 002BAC10 FFFF0324 */  addiu      $3, $0, -0x1
    /* 1BAC14 002BAC14 000043AC */  sw         $3, 0x0($2)
    /* 1BAC18 002BAC18 040040A0 */  sb         $0, 0x4($2)
    /* 1BAC1C 002BAC1C 050040A0 */  sb         $0, 0x5($2)
    /* 1BAC20 002BAC20 080043AC */  sw         $3, 0x8($2)
    /* 1BAC24 002BAC24 01000324 */  addiu      $3, $0, 0x1
    /* 1BAC28 002BAC28 0C0043A0 */  sb         $3, 0xC($2)
    /* 1BAC2C 002BAC2C 0D0043A0 */  sb         $3, 0xD($2)
  .L002BAC30:
    /* 1BAC30 002BAC30 3C261000 */  dsll32     $4, $16, 24
    /* 1BAC34 002BAC34 3F260400 */  dsra32     $4, $4, 24
    /* 1BAC38 002BAC38 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BAC3C 002BAC3C 80B58327 */  addiu      $3, $28, -0x4A80
    /* 1BAC40 002BAC40 21186400 */  addu       $3, $3, $4
    /* 1BAC44 002BAC44 000062A0 */  sb         $2, 0x0($3)
    /* 1BAC48 002BAC48 0000A38C */  lw         $3, 0x0($5)
    /* 1BAC4C 002BAC4C 0000638C */  lw         $3, 0x0($3)
    /* 1BAC50 002BAC50 0F006104 */  bgez       $3, .L002BAC90
    /* 1BAC54 002BAC54 00000000 */   nop
    /* 1BAC58 002BAC58 80180400 */  sll        $3, $4, 2
    /* 1BAC5C 002BAC5C 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BAC60 002BAC60 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BAC64 002BAC64 21904300 */  addu       $18, $2, $3
    /* 1BAC68 002BAC68 2D202002 */  daddu      $4, $17, $0
    /* 1BAC6C 002BAC6C 34DD090C */  jal        func_002774d0
    /* 1BAC70 002BAC70 00000000 */   nop
    /* 1BAC74 002BAC74 0000438E */  lw         $3, 0x0($18)
    /* 1BAC78 002BAC78 000062AC */  sw         $2, 0x0($3)
    /* 1BAC7C 002BAC7C 0000448E */  lw         $4, 0x0($18)
    /* 1BAC80 002BAC80 2D280000 */  daddu      $5, $0, $0
    /* 1BAC84 002BAC84 E0EF0A0C */  jal        func_002bbf80
    /* 1BAC88 002BAC88 00000000 */   nop
    /* 1BAC8C 002BAC8C 2D100002 */  daddu      $2, $16, $0
  .L002BAC90:
    /* 1BAC90 002BAC90 3000BFDF */  ld         $31, 0x30($29)
    /* 1BAC94 002BAC94 2000B27B */  lq         $18, 0x20($29)
    /* 1BAC98 002BAC98 1000B17B */  lq         $17, 0x10($29)
    /* 1BAC9C 002BAC9C 0000B07B */  lq         $16, 0x0($29)
    /* 1BACA0 002BACA0 4000BD27 */  addiu      $29, $29, 0x40
    /* 1BACA4 002BACA4 0800E003 */  jr         $31
    /* 1BACA8 002BACA8 00000000 */   nop
    /* 1BACAC 002BACAC 00000000 */  nop
.size func_002bab80, 0x130
