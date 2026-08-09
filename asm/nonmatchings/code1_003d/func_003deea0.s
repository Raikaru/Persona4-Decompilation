.section .text
.set noat
.set noreorder
glabel func_003deea0
    /* 2DEEA0 003DEEA0 80FFBD27 */  addiu      $29, $29, -0x80
    /* 2DEEA4 003DEEA4 4000BFFF */  sd         $31, 0x40($29)
    /* 2DEEA8 003DEEA8 3000B37F */  sq         $19, 0x30($29)
    /* 2DEEAC 003DEEAC 2000B27F */  sq         $18, 0x20($29)
    /* 2DEEB0 003DEEB0 2D98A000 */  daddu      $19, $5, $0
    /* 2DEEB4 003DEEB4 1000B17F */  sq         $17, 0x10($29)
    /* 2DEEB8 003DEEB8 2D90C000 */  daddu      $18, $6, $0
    /* 2DEEBC 003DEEBC 0000B07F */  sq         $16, 0x0($29)
    /* 2DEEC0 003DEEC0 2D88E000 */  daddu      $17, $7, $0
    /* 2DEEC4 003DEEC4 2D800001 */  daddu      $16, $8, $0
    /* 2DEEC8 003DEEC8 7000A527 */  addiu      $5, $29, 0x70
    /* 2DEECC 003DEECC 448A0F0C */  jal        func_003e2910
    /* 2DEED0 003DEED0 0C000624 */   addiu     $6, $0, 0xC
    /* 2DEED4 003DEED4 0C004238 */  xori       $2, $2, 0xC
    /* 2DEED8 003DEED8 0100422C */  sltiu      $2, $2, 0x1
    /* 2DEEDC 003DEEDC 32004010 */  beqz       $2, .L003DEFA8
    /* 2DEEE0 003DEEE0 00000000 */   nop
    /* 2DEEE4 003DEEE4 7800A227 */  addiu      $2, $29, 0x78
    /* 2DEEE8 003DEEE8 7000A68F */  lw         $6, 0x70($29)
    /* 2DEEEC 003DEEEC 0000448C */  lw         $4, 0x0($2)
    /* 2DEEF0 003DEEF0 5400A527 */  addiu      $5, $29, 0x54
    /* 2DEEF4 003DEEF4 7400A38F */  lw         $3, 0x74($29)
    /* 2DEEF8 003DEEF8 5000A6AF */  sw         $6, 0x50($29)
    /* 2DEEFC 003DEEFC FFFF023C */  lui        $2, (0xFFFF0000 >> 16)
    /* 2DEF00 003DEF00 24108200 */  and        $2, $4, $2
    /* 2DEF04 003DEF04 07004014 */  bnez       $2, .L003DEF24
    /* 2DEF08 003DEF08 0000A3AC */   sw        $3, 0x0($5)
    /* 2DEF0C 003DEF0C 5C00A927 */  addiu      $9, $29, 0x5C
    /* 2DEF10 003DEF10 00120400 */  sll        $2, $4, 8
    /* 2DEF14 003DEF14 5800A627 */  addiu      $6, $29, 0x58
    /* 2DEF18 003DEF18 000020AD */  sw         $0, 0x0($9)
    /* 2DEF1C 003DEF1C 0E000010 */  b          .L003DEF58
    /* 2DEF20 003DEF20 0000C2AC */   sw        $2, 0x0($6)
  .L003DEF24:
    /* 2DEF24 003DEF24 02140400 */  srl        $2, $4, 16
    /* 2DEF28 003DEF28 82430400 */  srl        $8, $4, 14
    /* 2DEF2C 003DEF2C 3F004330 */  andi       $3, $2, 0x3F
    /* 2DEF30 003DEF30 0300073C */  lui        $7, (0x3FF00 >> 16)
    /* 2DEF34 003DEF34 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* 2DEF38 003DEF38 5C00A927 */  addiu      $9, $29, 0x5C
    /* 2DEF3C 003DEF3C 00FFE434 */  ori        $4, $7, (0x3FF00 & 0xFFFF)
    /* 2DEF40 003DEF40 000022AD */  sw         $2, 0x0($9)
    /* 2DEF44 003DEF44 24200401 */  and        $4, $8, $4
    /* 2DEF48 003DEF48 5800A627 */  addiu      $6, $29, 0x58
    /* 2DEF4C 003DEF4C 21108700 */  addu       $2, $4, $7
    /* 2DEF50 003DEF50 25104300 */  or         $2, $2, $3
    /* 2DEF54 003DEF54 0000C2AC */  sw         $2, 0x0($6)
  .L003DEF58:
    /* 2DEF58 003DEF58 487B0F0C */  jal        func_003ded20
    /* 2DEF5C 003DEF5C 5000A427 */   addiu     $4, $29, 0x50
    /* 2DEF60 003DEF60 03006012 */  beqz       $19, .L003DEF70
    /* 2DEF64 003DEF64 6000A2AF */   sw        $2, 0x60($29)
    /* 2DEF68 003DEF68 5000A28F */  lw         $2, 0x50($29)
    /* 2DEF6C 003DEF6C 000062AE */  sw         $2, 0x0($19)
  .L003DEF70:
    /* 2DEF70 003DEF70 03004012 */  beqz       $18, .L003DEF80
    /* 2DEF74 003DEF74 00000000 */   nop
    /* 2DEF78 003DEF78 0000A28C */  lw         $2, 0x0($5)
    /* 2DEF7C 003DEF7C 000042AE */  sw         $2, 0x0($18)
  .L003DEF80:
    /* 2DEF80 003DEF80 03000012 */  beqz       $16, .L003DEF90
    /* 2DEF84 003DEF84 00000000 */   nop
    /* 2DEF88 003DEF88 0000228D */  lw         $2, 0x0($9)
    /* 2DEF8C 003DEF8C 000002AE */  sw         $2, 0x0($16)
  .L003DEF90:
    /* 2DEF90 003DEF90 03002012 */  beqz       $17, .L003DEFA0
    /* 2DEF94 003DEF94 00000000 */   nop
    /* 2DEF98 003DEF98 0000C28C */  lw         $2, 0x0($6)
    /* 2DEF9C 003DEF9C 000022AE */  sw         $2, 0x0($17)
  .L003DEFA0:
    /* 2DEFA0 003DEFA0 0A000010 */  b          .L003DEFCC
    /* 2DEFA4 003DEFA4 01000224 */   addiu     $2, $0, 0x1
  .L003DEFA8:
    /* 2DEFA8 003DEFA8 01000324 */  addiu      $3, $0, 0x1
    /* 2DEFAC 003DEFAC 0080023C */  lui        $2, (0x8000001A >> 16)
    /* 2DEFB0 003DEFB0 6800A3AF */  sw         $3, 0x68($29)
    /* 2DEFB4 003DEFB4 647D0F0C */  jal        func_003df590
    /* 2DEFB8 003DEFB8 1A004434 */   ori       $4, $2, (0x8000001A & 0xFFFF)
    /* 2DEFBC 003DEFBC 6C00A2AF */  sw         $2, 0x6C($29)
    /* 2DEFC0 003DEFC0 347D0F0C */  jal        func_003df4d0
    /* 2DEFC4 003DEFC4 6800A427 */   addiu     $4, $29, 0x68
    /* 2DEFC8 003DEFC8 2D100000 */  daddu      $2, $0, $0
  .L003DEFCC:
    /* 2DEFCC 003DEFCC 4000BFDF */  ld         $31, 0x40($29)
    /* 2DEFD0 003DEFD0 3000B37B */  lq         $19, 0x30($29)
    /* 2DEFD4 003DEFD4 2000B27B */  lq         $18, 0x20($29)
    /* 2DEFD8 003DEFD8 1000B17B */  lq         $17, 0x10($29)
    /* 2DEFDC 003DEFDC 0000B07B */  lq         $16, 0x0($29)
    /* 2DEFE0 003DEFE0 0800E003 */  jr         $31
    /* 2DEFE4 003DEFE4 8000BD27 */   addiu     $29, $29, 0x80
    /* 2DEFE8 003DEFE8 00000000 */  nop
    /* 2DEFEC 003DEFEC 00000000 */  nop
.size func_003deea0, 0x150
