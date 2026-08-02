.section .text
.set noat
.set noreorder
glabel func_0045aac0
    /* 35AAC0 0045AAC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 35AAC4 0045AAC4 4000BFFF */  sd         $31, 0x40($29)
    /* 35AAC8 0045AAC8 3000B37F */  sq         $19, 0x30($29)
    /* 35AACC 0045AACC 2000B27F */  sq         $18, 0x20($29)
    /* 35AAD0 0045AAD0 1000B17F */  sq         $17, 0x10($29)
    /* 35AAD4 0045AAD4 0000B07F */  sq         $16, 0x0($29)
    /* 35AAD8 0045AAD8 2D988000 */  daddu      $19, $4, $0
    /* 35AADC 0045AADC 2D80C000 */  daddu      $16, $6, $0
    /* 35AAE0 0045AAE0 3C8C1300 */  dsll32     $17, $19, 16
    /* 35AAE4 0045AAE4 3F8C1100 */  dsra32     $17, $17, 16
    /* 35AAE8 0045AAE8 3C340500 */  dsll32     $6, $5, 16
    /* 35AAEC 0045AAEC 3F340600 */  dsra32     $6, $6, 16
    /* 35AAF0 0045AAF0 7100043C */  lui        $4, %hi(D_007122F0)
    /* 35AAF4 0045AAF4 F0228424 */  addiu      $4, $4, %lo(D_007122F0)
    /* 35AAF8 0045AAF8 2D282002 */  daddu      $5, $17, $0
    /* 35AAFC 0045AAFC 2D380002 */  daddu      $7, $16, $0
    /* 35AB00 0045AB00 DA02110C */  jal        func_00440b68
    /* 35AB04 0045AB04 00000000 */   nop
    /* 35AB08 0045AB08 0500212A */  slti       $1, $17, 0x5
    /* 35AB0C 0045AB0C 24002010 */  beqz       $1, .L0045ABA0
    /* 35AB10 0045AB10 00000000 */   nop
    /* 35AB14 0045AB14 34010424 */  addiu      $4, $0, 0x134
    /* 35AB18 0045AB18 18182402 */  mult       $3, $17, $4
    /* 35AB1C 0045AB1C 8D00023C */  lui        $2, %hi(D_008D2B90)
    /* 35AB20 0045AB20 902B4224 */  addiu      $2, $2, %lo(D_008D2B90)
    /* 35AB24 0045AB24 21904300 */  addu       $18, $2, $3
    /* 35AB28 0045AB28 0000428E */  lw         $2, 0x0($18)
    /* 35AB2C 0045AB2C 1C004010 */  beqz       $2, .L0045ABA0
    /* 35AB30 0045AB30 00000000 */   nop
    /* 35AB34 0045AB34 8D00023C */  lui        $2, %hi(D_008D2BA0)
    /* 35AB38 0045AB38 A02B4224 */  addiu      $2, $2, %lo(D_008D2BA0)
    /* 35AB3C 0045AB3C 21884300 */  addu       $17, $2, $3
    /* 35AB40 0045AB40 0000248E */  lw         $4, 0x0($17)
    /* 35AB44 0045AB44 2D280002 */  daddu      $5, $16, $0
    /* 35AB48 0045AB48 AC63130C */  jal        func_004d8eb0
    /* 35AB4C 0045AB4C 00000000 */   nop
    /* 35AB50 0045AB50 0000428E */  lw         $2, 0x0($18)
    /* 35AB54 0045AB54 12004010 */  beqz       $2, .L0045ABA0
    /* 35AB58 0045AB58 00000000 */   nop
    /* 35AB5C 0045AB5C 3C1C1300 */  dsll32     $3, $19, 16
    /* 35AB60 0045AB60 3F1C0300 */  dsra32     $3, $3, 16
    /* 35AB64 0045AB64 34010224 */  addiu      $2, $0, 0x134
    /* 35AB68 0045AB68 18806200 */  mult       $16, $3, $2
    /* 35AB6C 0045AB6C 0000248E */  lw         $4, 0x0($17)
    /* 35AB70 0045AB70 6463130C */  jal        func_004d8d90
    /* 35AB74 0045AB74 00000000 */   nop
    /* 35AB78 0045AB78 8D00023C */  lui        $2, %hi(D_008D2B9C)
    /* 35AB7C 0045AB7C 9C2B4224 */  addiu      $2, $2, %lo(D_008D2B9C)
    /* 35AB80 0045AB80 21105000 */  addu       $2, $2, $16
    /* 35AB84 0045AB84 000040A4 */  sh         $0, 0x0($2)
    /* 35AB88 0045AB88 000040AE */  sw         $0, 0x0($18)
    /* 35AB8C 0045AB8C FFFF0324 */  addiu      $3, $0, -0x1
    /* 35AB90 0045AB90 8D00023C */  lui        $2, %hi(D_008D2B98)
    /* 35AB94 0045AB94 982B4224 */  addiu      $2, $2, %lo(D_008D2B98)
    /* 35AB98 0045AB98 21105000 */  addu       $2, $2, $16
    /* 35AB9C 0045AB9C 000043A4 */  sh         $3, 0x0($2)
  .L0045ABA0:
    /* 35ABA0 0045ABA0 01000224 */  addiu      $2, $0, 0x1
    /* 35ABA4 0045ABA4 4000BFDF */  ld         $31, 0x40($29)
    /* 35ABA8 0045ABA8 3000B37B */  lq         $19, 0x30($29)
    /* 35ABAC 0045ABAC 2000B27B */  lq         $18, 0x20($29)
    /* 35ABB0 0045ABB0 1000B17B */  lq         $17, 0x10($29)
    /* 35ABB4 0045ABB4 0000B07B */  lq         $16, 0x0($29)
    /* 35ABB8 0045ABB8 5000BD27 */  addiu      $29, $29, 0x50
    /* 35ABBC 0045ABBC 0800E003 */  jr         $31
    /* 35ABC0 0045ABC0 00000000 */   nop
    /* 35ABC4 0045ABC4 00000000 */  nop
    /* 35ABC8 0045ABC8 00000000 */  nop
    /* 35ABCC 0045ABCC 00000000 */  nop
.size func_0045aac0, 0x110
