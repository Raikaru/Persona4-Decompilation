.section .text
.set noat
.set noreorder
glabel func_0038ecc0
    /* 28ECC0 0038ECC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 28ECC4 0038ECC4 1000BFFF */  sd         $31, 0x10($29)
    /* 28ECC8 0038ECC8 0000B07F */  sq         $16, 0x0($29)
    /* 28ECCC 0038ECCC B0B5828F */  lw         $2, -0x4A50($28)
    /* 28ECD0 0038ECD0 06004014 */  bnez       $2, .L0038ECEC
    /* 28ECD4 0038ECD4 00000000 */   nop
    /* 28ECD8 0038ECD8 6500043C */  lui        $4, %hi(D_0064F220)
    /* 28ECDC 0038ECDC 20F28424 */  addiu      $4, $4, %lo(D_0064F220)
    /* 28ECE0 0038ECE0 6B000524 */  addiu      $5, $0, 0x6B
    /* 28ECE4 0038ECE4 CCB5110C */  jal        func_0046d730
    /* 28ECE8 0038ECE8 00000000 */   nop
  .L0038ECEC:
    /* 28ECEC 0038ECEC B0B5908F */  lw         $16, -0x4A50($28)
    /* 28ECF0 0038ECF0 543E0E0C */  jal        func_0038f950
    /* 28ECF4 0038ECF4 00000000 */   nop
    /* 28ECF8 0038ECF8 2D204000 */  daddu      $4, $2, $0
    /* 28ECFC 0038ECFC 783D0E0C */  jal        func_0038f5e0
    /* 28ED00 0038ED00 00000000 */   nop
    /* 28ED04 0038ED04 0C12038E */  lw         $3, 0x120C($16)
    /* 28ED08 0038ED08 21106200 */  addu       $2, $3, $2
    /* 28ED0C 0038ED0C 01004290 */  lbu        $2, 0x1($2)
    /* 28ED10 0038ED10 1000BFDF */  ld         $31, 0x10($29)
    /* 28ED14 0038ED14 0000B07B */  lq         $16, 0x0($29)
    /* 28ED18 0038ED18 2000BD27 */  addiu      $29, $29, 0x20
    /* 28ED1C 0038ED1C 0800E003 */  jr         $31
    /* 28ED20 0038ED20 00000000 */   nop
    /* 28ED24 0038ED24 00000000 */  nop
    /* 28ED28 0038ED28 00000000 */  nop
    /* 28ED2C 0038ED2C 00000000 */  nop
.size func_0038ecc0, 0x70
