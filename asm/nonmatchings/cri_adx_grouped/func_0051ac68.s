.section .text
.set noat
.set noreorder
glabel func_0051ac68
    /* 41AC68 0051AC68 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 41AC6C 0051AC6C 1000B0FF */  sd         $16, 0x10($29)
    /* 41AC70 0051AC70 2000BFFF */  sd         $31, 0x20($29)
    /* 41AC74 0051AC74 1800B1FF */  sd         $17, 0x18($29)
    /* 41AC78 0051AC78 2D888000 */  daddu      $17, $4, $0
    /* 41AC7C 0051AC7C 2D202002 */  daddu      $4, $17, $0
  .L0051AC80:
    /* 41AC80 0051AC80 2D28A003 */  daddu      $5, $29, $0
    /* 41AC84 0051AC84 0400A627 */  addiu      $6, $29, 0x4
    /* 41AC88 0051AC88 3A6B140C */  jal        func_0051ace8
    /* 41AC8C 0051AC8C 0800A727 */   addiu     $7, $29, 0x8
    /* 41AC90 0051AC90 2D202002 */  daddu      $4, $17, $0
    /* 41AC94 0051AC94 2D804000 */  daddu      $16, $2, $0
    /* 41AC98 0051AC98 0A000016 */  bnez       $16, .L0051ACC4
    /* 41AC9C 0051AC9C 0C00A827 */   addiu     $8, $29, 0xC
    /* 41ACA0 0051ACA0 0000A58F */  lw         $5, 0x0($29)
    /* 41ACA4 0051ACA4 0400A68F */  lw         $6, 0x4($29)
    /* 41ACA8 0051ACA8 266D140C */  jal        func_0051b498
    /* 41ACAC 0051ACAC 0800A78F */   lw        $7, 0x8($29)
    /* 41ACB0 0051ACB0 2D804000 */  daddu      $16, $2, $0
    /* 41ACB4 0051ACB4 03000016 */  bnez       $16, .L0051ACC4
    /* 41ACB8 0051ACB8 0C00A28F */   lw        $2, 0xC($29)
    /* 41ACBC 0051ACBC F0FF4054 */  bnel       $2, $0, .L0051AC80
    /* 41ACC0 0051ACC0 2D202002 */   daddu     $4, $17, $0
  .L0051ACC4:
    /* 41ACC4 0051ACC4 7A79140C */  jal        func_0051e5e8
    /* 41ACC8 0051ACC8 2D202002 */   daddu     $4, $17, $0
    /* 41ACCC 0051ACCC 2D100002 */  daddu      $2, $16, $0
    /* 41ACD0 0051ACD0 1800B1DF */  ld         $17, 0x18($29)
    /* 41ACD4 0051ACD4 1000B0DF */  ld         $16, 0x10($29)
    /* 41ACD8 0051ACD8 2000BFDF */  ld         $31, 0x20($29)
    /* 41ACDC 0051ACDC 0800E003 */  jr         $31
    /* 41ACE0 0051ACE0 3000BD27 */   addiu     $29, $29, 0x30
    /* 41ACE4 0051ACE4 00000000 */  nop
.size func_0051ac68, 0x80
