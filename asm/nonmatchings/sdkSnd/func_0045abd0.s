.section .text
.set noat
.set noreorder
glabel func_0045abd0
    /* 35ABD0 0045ABD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 35ABD4 0045ABD4 0000BFFF */  sd         $31, 0x0($29)
    /* 35ABD8 0045ABD8 3C240400 */  dsll32     $4, $4, 16
    /* 35ABDC 0045ABDC 3F240400 */  dsra32     $4, $4, 16
    /* 35ABE0 0045ABE0 05008128 */  slti       $1, $4, 0x5
    /* 35ABE4 0045ABE4 22002010 */  beqz       $1, .L0045AC70
    /* 35ABE8 0045ABE8 00000000 */   nop
    /* 35ABEC 0045ABEC 34010224 */  addiu      $2, $0, 0x134
    /* 35ABF0 0045ABF0 18388200 */  mult       $7, $4, $2
    /* 35ABF4 0045ABF4 01000324 */  addiu      $3, $0, 0x1
    /* 35ABF8 0045ABF8 8D00023C */  lui        $2, %hi(D_008D2B90)
    /* 35ABFC 0045ABFC 902B4224 */  addiu      $2, $2, %lo(D_008D2B90)
    /* 35AC00 0045AC00 21104700 */  addu       $2, $2, $7
    /* 35AC04 0045AC04 000043AC */  sw         $3, 0x0($2)
    /* 35AC08 0045AC08 3C1C0600 */  dsll32     $3, $6, 16
    /* 35AC0C 0045AC0C 3F1C0300 */  dsra32     $3, $3, 16
    /* 35AC10 0045AC10 8D00023C */  lui        $2, %hi(D_008D2CAC)
    /* 35AC14 0045AC14 AC2C4224 */  addiu      $2, $2, %lo(D_008D2CAC)
    /* 35AC18 0045AC18 21104700 */  addu       $2, $2, $7
    /* 35AC1C 0045AC1C 000043AC */  sw         $3, 0x0($2)
    /* 35AC20 0045AC20 8D00023C */  lui        $2, %hi(D_008D2B9C)
    /* 35AC24 0045AC24 9C2B4224 */  addiu      $2, $2, %lo(D_008D2B9C)
    /* 35AC28 0045AC28 21104700 */  addu       $2, $2, $7
    /* 35AC2C 0045AC2C 000040A4 */  sh         $0, 0x0($2)
    /* 35AC30 0045AC30 8D00023C */  lui        $2, %hi(D_008D2BA4)
    /* 35AC34 0045AC34 A42B4224 */  addiu      $2, $2, %lo(D_008D2BA4)
    /* 35AC38 0045AC38 21304700 */  addu       $6, $2, $7
    /* 35AC3C 0045AC3C 0000C384 */  lh         $3, 0x0($6)
    /* 35AC40 0045AC40 8D00023C */  lui        $2, %hi(D_008D2BA6)
    /* 35AC44 0045AC44 A62B4224 */  addiu      $2, $2, %lo(D_008D2BA6)
    /* 35AC48 0045AC48 21104700 */  addu       $2, $2, $7
    /* 35AC4C 0045AC4C 000043A4 */  sh         $3, 0x0($2)
    /* 35AC50 0045AC50 03000224 */  addiu      $2, $0, 0x3
    /* 35AC54 0045AC54 0000C2A4 */  sh         $2, 0x0($6)
    /* 35AC58 0045AC58 8D00023C */  lui        $2, %hi(D_008D2CA8)
    /* 35AC5C 0045AC5C A82C4224 */  addiu      $2, $2, %lo(D_008D2CA8)
    /* 35AC60 0045AC60 21104700 */  addu       $2, $2, $7
    /* 35AC64 0045AC64 000045AC */  sw         $5, 0x0($2)
    /* 35AC68 0045AC68 B466110C */  jal        func_00459ad0
    /* 35AC6C 0045AC6C 00000000 */   nop
  .L0045AC70:
    /* 35AC70 0045AC70 01000224 */  addiu      $2, $0, 0x1
    /* 35AC74 0045AC74 0000BFDF */  ld         $31, 0x0($29)
    /* 35AC78 0045AC78 1000BD27 */  addiu      $29, $29, 0x10
    /* 35AC7C 0045AC7C 0800E003 */  jr         $31
    /* 35AC80 0045AC80 00000000 */   nop
    /* 35AC84 0045AC84 00000000 */  nop
    /* 35AC88 0045AC88 00000000 */  nop
    /* 35AC8C 0045AC8C 00000000 */  nop
.size func_0045abd0, 0xc0
