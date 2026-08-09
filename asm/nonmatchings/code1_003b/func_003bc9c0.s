.section .text
.set noat
.set noreorder
glabel func_003bc9c0
    /* 2BC9C0 003BC9C0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2BC9C4 003BC9C4 6000BFFF */  sd         $31, 0x60($29)
    /* 2BC9C8 003BC9C8 5000B57F */  sq         $21, 0x50($29)
    /* 2BC9CC 003BC9CC 4000B47F */  sq         $20, 0x40($29)
    /* 2BC9D0 003BC9D0 FFFF1524 */  addiu      $21, $0, -0x1
    /* 2BC9D4 003BC9D4 3000B37F */  sq         $19, 0x30($29)
    /* 2BC9D8 003BC9D8 2DA08000 */  daddu      $20, $4, $0
    /* 2BC9DC 003BC9DC 2000B27F */  sq         $18, 0x20($29)
    /* 2BC9E0 003BC9E0 1000B17F */  sq         $17, 0x10($29)
    /* 2BC9E4 003BC9E4 2D90A000 */  daddu      $18, $5, $0
    /* 2BC9E8 003BC9E8 0000B07F */  sq         $16, 0x0($29)
    /* 2BC9EC 003BC9EC 2D88C000 */  daddu      $17, $6, $0
    /* 2BC9F0 003BC9F0 0000838C */  lw         $3, 0x0($4)
    /* 2BC9F4 003BC9F4 2D80E000 */  daddu      $16, $7, $0
    /* 2BC9F8 003BC9F8 2A080300 */  slt        $1, $0, $3
    /* 2BC9FC 003BC9FC 0C002010 */  beqz       $1, .L003BCA30
    /* 2BCA00 003BCA00 2D280000 */   daddu     $5, $0, $0
    /* 2BCA04 003BCA04 0400848E */  lw         $4, 0x4($20)
  .L003BCA08:
    /* 2BCA08 003BCA08 0C00828C */  lw         $2, 0xC($4)
    /* 2BCA0C 003BCA0C 03004014 */  bnez       $2, .L003BCA1C
    /* 2BCA10 003BCA10 00000000 */   nop
    /* 2BCA14 003BCA14 06000010 */  b          .L003BCA30
    /* 2BCA18 003BCA18 2DA8A000 */   daddu     $21, $5, $0
  .L003BCA1C:
    /* 2BCA1C 003BCA1C 0100A524 */  addiu      $5, $5, 0x1
    /* 2BCA20 003BCA20 2A10A300 */  slt        $2, $5, $3
    /* 2BCA24 003BCA24 F8FF4014 */  bnez       $2, .L003BCA08
    /* 2BCA28 003BCA28 10008424 */   addiu     $4, $4, 0x10
    /* 2BCA2C 003BCA2C 00000000 */  nop
  .L003BCA30:
    /* 2BCA30 003BCA30 FFFF0224 */  addiu      $2, $0, -0x1
    /* 2BCA34 003BCA34 1B00A216 */  bne        $21, $2, .L003BCAA4
    /* 2BCA38 003BCA38 00000000 */   nop
    /* 2BCA3C 003BCA3C 0400828E */  lw         $2, 0x4($20)
    /* 2BCA40 003BCA40 48004010 */  beqz       $2, .L003BCB64
    /* 2BCA44 003BCA44 00000000 */   nop
    /* 2BCA48 003BCA48 0300023C */  lui        $2, (0x3011F >> 16)
    /* 2BCA4C 003BCA4C 01006324 */  addiu      $3, $3, 0x1
    /* 2BCA50 003BCA50 1F014534 */  ori        $5, $2, (0x3011F & 0xFFFF)
    /* 2BCA54 003BCA54 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2BCA58 003BCA58 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2BCA5C 003BCA5C 09F84000 */  jalr       $2
    /* 2BCA60 003BCA60 00210300 */   sll       $4, $3, 4
    /* 2BCA64 003BCA64 2D984000 */  daddu      $19, $2, $0
    /* 2BCA68 003BCA68 3C006012 */  beqz       $19, .L003BCB5C
    /* 2BCA6C 003BCA6C 00000000 */   nop
    /* 2BCA70 003BCA70 0000828E */  lw         $2, 0x0($20)
    /* 2BCA74 003BCA74 2D206002 */  daddu      $4, $19, $0
    /* 2BCA78 003BCA78 0400858E */  lw         $5, 0x4($20)
    /* 2BCA7C 003BCA7C 04FE100C */  jal        func_0043f810
    /* 2BCA80 003BCA80 00310200 */   sll       $6, $2, 4
    /* 2BCA84 003BCA84 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2BCA88 003BCA88 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2BCA8C 003BCA8C 09F84000 */  jalr       $2
    /* 2BCA90 003BCA90 0400848E */   lw        $4, 0x4($20)
    /* 2BCA94 003BCA94 040093AE */  sw         $19, 0x4($20)
  .L003BCA98:
    /* 2BCA98 003BCA98 0000958E */  lw         $21, 0x0($20)
    /* 2BCA9C 003BCA9C 0100A226 */  addiu      $2, $21, 0x1
    /* 2BCAA0 003BCAA0 000082AE */  sw         $2, 0x0($20)
  .L003BCAA4:
    /* 2BCAA4 003BCAA4 0400828E */  lw         $2, 0x4($20)
    /* 2BCAA8 003BCAA8 00191500 */  sll        $3, $21, 4
    /* 2BCAAC 003BCAAC 8800133C */  lui        $19, %hi(jtbl_008873E8)
    /* 2BCAB0 003BCAB0 2D202002 */  daddu      $4, $17, $0
    /* 2BCAB4 003BCAB4 E8737326 */  addiu      $19, $19, %lo(jtbl_008873E8)
    /* 2BCAB8 003BCAB8 44F40E0C */  jal        func_003bd110
    /* 2BCABC 003BCABC 21A04300 */   addu      $20, $2, $3
    /* 2BCAC0 003BCAC0 18200202 */  mult       $4, $16, $2
    /* 2BCAC4 003BCAC4 0300023C */  lui        $2, (0x3011F >> 16)
    /* 2BCAC8 003BCAC8 1F014534 */  ori        $5, $2, (0x3011F & 0xFFFF)
    /* 2BCACC 003BCACC 0000628E */  lw         $2, 0x0($19)
    /* 2BCAD0 003BCAD0 09F84000 */  jalr       $2
    /* 2BCAD4 003BCAD4 00000000 */   nop
    /* 2BCAD8 003BCAD8 0C0082AE */  sw         $2, 0xC($20)
    /* 2BCADC 003BCADC 0C00828E */  lw         $2, 0xC($20)
    /* 2BCAE0 003BCAE0 2D004010 */  beqz       $2, .L003BCB98
    /* 2BCAE4 003BCAE4 00000000 */   nop
    /* 2BCAE8 003BCAE8 44F40E0C */  jal        func_003bd110
    /* 2BCAEC 003BCAEC 2D202002 */   daddu     $4, $17, $0
    /* 2BCAF0 003BCAF0 18300202 */  mult       $6, $16, $2
    /* 2BCAF4 003BCAF4 0C00848E */  lw         $4, 0xC($20)
    /* 2BCAF8 003BCAF8 72FE100C */  jal        func_0043f9c8
    /* 2BCAFC 003BCAFC 2D280000 */   daddu     $5, $0, $0
    /* 2BCB00 003BCB00 12004012 */  beqz       $18, .L003BCB4C
    /* 2BCB04 003BCB04 000080AE */   sw        $0, 0x0($20)
    /* 2BCB08 003BCB08 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2BCB0C 003BCB0C D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2BCB10 003BCB10 09F84000 */  jalr       $2
    /* 2BCB14 003BCB14 2D204002 */   daddu     $4, $18, $0
    /* 2BCB18 003BCB18 0000638E */  lw         $3, 0x0($19)
    /* 2BCB1C 003BCB1C 01004424 */  addiu      $4, $2, 0x1
    /* 2BCB20 003BCB20 0300023C */  lui        $2, (0x30002 >> 16)
    /* 2BCB24 003BCB24 09F86000 */  jalr       $3
    /* 2BCB28 003BCB28 02004534 */   ori       $5, $2, (0x30002 & 0xFFFF)
    /* 2BCB2C 003BCB2C 000082AE */  sw         $2, 0x0($20)
    /* 2BCB30 003BCB30 0000848E */  lw         $4, 0x0($20)
    /* 2BCB34 003BCB34 05008010 */  beqz       $4, .L003BCB4C
    /* 2BCB38 003BCB38 00000000 */   nop
    /* 2BCB3C 003BCB3C 8800023C */  lui        $2, %hi(D_008873AC)
    /* 2BCB40 003BCB40 AC73428C */  lw         $2, %lo(D_008873AC)($2)
    /* 2BCB44 003BCB44 09F84000 */  jalr       $2
    /* 2BCB48 003BCB48 2D284002 */   daddu     $5, $18, $0
  .L003BCB4C:
    /* 2BCB4C 003BCB4C 040091AE */  sw         $17, 0x4($20)
    /* 2BCB50 003BCB50 2D10A002 */  daddu      $2, $21, $0
    /* 2BCB54 003BCB54 11000010 */  b          .L003BCB9C
    /* 2BCB58 003BCB58 080090AE */   sw        $16, 0x8($20)
  .L003BCB5C:
    /* 2BCB5C 003BCB5C 0F000010 */  b          .L003BCB9C
    /* 2BCB60 003BCB60 FFFF0224 */   addiu     $2, $0, -0x1
  .L003BCB64:
    /* 2BCB64 003BCB64 0300023C */  lui        $2, (0x3011F >> 16)
    /* 2BCB68 003BCB68 01006324 */  addiu      $3, $3, 0x1
    /* 2BCB6C 003BCB6C 1F014534 */  ori        $5, $2, (0x3011F & 0xFFFF)
    /* 2BCB70 003BCB70 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2BCB74 003BCB74 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2BCB78 003BCB78 09F84000 */  jalr       $2
    /* 2BCB7C 003BCB7C 00210300 */   sll       $4, $3, 4
    /* 2BCB80 003BCB80 040082AE */  sw         $2, 0x4($20)
    /* 2BCB84 003BCB84 0400828E */  lw         $2, 0x4($20)
    /* 2BCB88 003BCB88 C3FF4014 */  bnez       $2, .L003BCA98
    /* 2BCB8C 003BCB8C 00000000 */   nop
    /* 2BCB90 003BCB90 02000010 */  b          .L003BCB9C
    /* 2BCB94 003BCB94 FFFF0224 */   addiu     $2, $0, -0x1
  .L003BCB98:
    /* 2BCB98 003BCB98 FFFF0224 */  addiu      $2, $0, -0x1
  .L003BCB9C:
    /* 2BCB9C 003BCB9C 6000BFDF */  ld         $31, 0x60($29)
    /* 2BCBA0 003BCBA0 5000B57B */  lq         $21, 0x50($29)
    /* 2BCBA4 003BCBA4 4000B47B */  lq         $20, 0x40($29)
    /* 2BCBA8 003BCBA8 3000B37B */  lq         $19, 0x30($29)
    /* 2BCBAC 003BCBAC 2000B27B */  lq         $18, 0x20($29)
    /* 2BCBB0 003BCBB0 1000B17B */  lq         $17, 0x10($29)
    /* 2BCBB4 003BCBB4 0000B07B */  lq         $16, 0x0($29)
    /* 2BCBB8 003BCBB8 0800E003 */  jr         $31
    /* 2BCBBC 003BCBBC 7000BD27 */   addiu     $29, $29, 0x70
.size func_003bc9c0, 0x200
