.section .text
.set noat
.set noreorder
glabel func_004bde38
    /* 3BDE38 004BDE38 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BDE3C 004BDE3C 0000B0FF */  sd         $16, 0x0($29)
    /* 3BDE40 004BDE40 2D808000 */  daddu      $16, $4, $0
    /* 3BDE44 004BDE44 0800B1FF */  sd         $17, 0x8($29)
    /* 3BDE48 004BDE48 2D88A000 */  daddu      $17, $5, $0
    /* 3BDE4C 004BDE4C 1000BFFF */  sd         $31, 0x10($29)
    /* 3BDE50 004BDE50 2D28C000 */  daddu      $5, $6, $0
    /* 3BDE54 004BDE54 0800228E */  lw         $2, 0x8($17)
    /* 3BDE58 004BDE58 05004010 */  beqz       $2, .L004BDE70
    /* 3BDE5C 004BDE5C 2D20A000 */   daddu     $4, $5, $0
    /* 3BDE60 004BDE60 F04E130C */  jal        func_004d3bc0
    /* 3BDE64 004BDE64 F4FFE524 */   addiu     $5, $7, -0xC
    /* 3BDE68 004BDE68 05000010 */  b          .L004BDE80
    /* 3BDE6C 004BDE6C 040002AE */   sw        $2, 0x4($16)
  .L004BDE70:
    /* 3BDE70 004BDE70 0000248E */  lw         $4, 0x0($17)
    /* 3BDE74 004BDE74 144E130C */  jal        func_004d3850
    /* 3BDE78 004BDE78 F4FFE624 */   addiu     $6, $7, -0xC
    /* 3BDE7C 004BDE7C 040002AE */  sw         $2, 0x4($16)
  .L004BDE80:
    /* 3BDE80 004BDE80 0400028E */  lw         $2, 0x4($16)
    /* 3BDE84 004BDE84 06004054 */  bnel       $2, $0, .L004BDEA0
    /* 3BDE88 004BDE88 0000238E */   lw        $3, 0x0($17)
    /* 3BDE8C 004BDE8C 7500043C */  lui        $4, %hi(D_007569F0)
    /* 3BDE90 004BDE90 A8F5120C */  jal        func_004bd6a0
    /* 3BDE94 004BDE94 F0698424 */   addiu     $4, $4, %lo(D_007569F0)
    /* 3BDE98 004BDE98 03000010 */  b          .L004BDEA8
    /* 3BDE9C 004BDE9C 2D100000 */   daddu     $2, $0, $0
  .L004BDEA0:
    /* 3BDEA0 004BDEA0 01000224 */  addiu      $2, $0, 0x1
    /* 3BDEA4 004BDEA4 080003AE */  sw         $3, 0x8($16)
  .L004BDEA8:
    /* 3BDEA8 004BDEA8 0000B0DF */  ld         $16, 0x0($29)
    /* 3BDEAC 004BDEAC 0800B1DF */  ld         $17, 0x8($29)
    /* 3BDEB0 004BDEB0 1000BFDF */  ld         $31, 0x10($29)
    /* 3BDEB4 004BDEB4 0800E003 */  jr         $31
    /* 3BDEB8 004BDEB8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3BDEBC 004BDEBC 00000000 */  nop
.size func_004bde38, 0x88
