.section .text
.set noat
.set noreorder
glabel func_004ae930
    /* 3AE930 004AE930 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3AE934 004AE934 4000BFFF */  sd         $31, 0x40($29)
    /* 3AE938 004AE938 3000B37F */  sq         $19, 0x30($29)
    /* 3AE93C 004AE93C 2000B27F */  sq         $18, 0x20($29)
    /* 3AE940 004AE940 1000B17F */  sq         $17, 0x10($29)
    /* 3AE944 004AE944 0000B07F */  sq         $16, 0x0($29)
    /* 3AE948 004AE948 2D888000 */  daddu      $17, $4, $0
    /* 3AE94C 004AE94C 2D90A000 */  daddu      $18, $5, $0
    /* 3AE950 004AE950 2D80C000 */  daddu      $16, $6, $0
    /* 3AE954 004AE954 5800848C */  lw         $4, 0x58($4)
    /* 3AE958 004AE958 03008010 */  beqz       $4, .L004AE968
    /* 3AE95C 004AE95C 00000000 */   nop
    /* 3AE960 004AE960 344B120C */  jal        func_00492cd0
    /* 3AE964 004AE964 00000000 */   nop
  .L004AE968:
    /* 3AE968 004AE968 C000028E */  lw         $2, 0xC0($16)
    /* 3AE96C 004AE96C 06004010 */  beqz       $2, .L004AE988
    /* 3AE970 004AE970 00000000 */   nop
    /* 3AE974 004AE974 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AE978 004AE978 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AE97C 004AE97C 8B010524 */  addiu      $5, $0, 0x18B
    /* 3AE980 004AE980 CCB5110C */  jal        func_0046d730
    /* 3AE984 004AE984 00000000 */   nop
  .L004AE988:
    /* 3AE988 004AE988 FFFF4432 */  andi       $4, $18, 0xFFFF
    /* 3AE98C 004AE98C 0000258E */  lw         $5, 0x0($17)
    /* 3AE990 004AE990 2D300002 */  daddu      $6, $16, $0
    /* 3AE994 004AE994 C84A120C */  jal        func_00492b20
    /* 3AE998 004AE998 00000000 */   nop
    /* 3AE99C 004AE99C 580022AE */  sw         $2, 0x58($17)
    /* 3AE9A0 004AE9A0 6000248E */  lw         $4, 0x60($17)
    /* 3AE9A4 004AE9A4 05008010 */  beqz       $4, .L004AE9BC
    /* 3AE9A8 004AE9A8 00000000 */   nop
    /* 3AE9AC 004AE9AC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3AE9B0 004AE9B0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3AE9B4 004AE9B4 09F84000 */  jalr       $2
    /* 3AE9B8 004AE9B8 00000000 */   nop
  .L004AE9BC:
    /* 3AE9BC 004AE9BC 5800228E */  lw         $2, 0x58($17)
    /* 3AE9C0 004AE9C0 0800508C */  lw         $16, 0x8($2)
    /* 3AE9C4 004AE9C4 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AE9C8 004AE9C8 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AE9CC 004AE9CC 95010524 */  addiu      $5, $0, 0x195
    /* 3AE9D0 004AE9D0 A43A110C */  jal        func_0044ea90
    /* 3AE9D4 004AE9D4 00000000 */   nop
    /* 3AE9D8 004AE9D8 40101000 */  sll        $2, $16, 1
    /* 3AE9DC 004AE9DC 21105000 */  addu       $2, $2, $16
    /* 3AE9E0 004AE9E0 C0200200 */  sll        $4, $2, 3
    /* 3AE9E4 004AE9E4 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3AE9E8 004AE9E8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3AE9EC 004AE9EC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3AE9F0 004AE9F0 09F84000 */  jalr       $2
    /* 3AE9F4 004AE9F4 00000000 */   nop
    /* 3AE9F8 004AE9F8 600022AE */  sw         $2, 0x60($17)
    /* 3AE9FC 004AE9FC 06004014 */  bnez       $2, .L004AEA18
    /* 3AEA00 004AEA00 00000000 */   nop
    /* 3AEA04 004AEA04 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AEA08 004AEA08 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AEA0C 004AEA0C 96010524 */  addiu      $5, $0, 0x196
    /* 3AEA10 004AEA10 CCB5110C */  jal        func_0046d730
    /* 3AEA14 004AEA14 00000000 */   nop
  .L004AEA18:
    /* 3AEA18 004AEA18 6000338E */  lw         $19, 0x60($17)
    /* 3AEA1C 004AEA1C 5C0033AE */  sw         $19, 0x5C($17)
    /* 3AEA20 004AEA20 2D900000 */  daddu      $18, $0, $0
    /* 3AEA24 004AEA24 07000010 */  b          .L004AEA44
    /* 3AEA28 004AEA28 00000000 */   nop
  .L004AEA2C:
    /* 3AEA2C 004AEA2C 2D202002 */  daddu      $4, $17, $0
    /* 3AEA30 004AEA30 2D286002 */  daddu      $5, $19, $0
    /* 3AEA34 004AEA34 28B8120C */  jal        func_004ae0a0
    /* 3AEA38 004AEA38 00000000 */   nop
    /* 3AEA3C 004AEA3C 01005226 */  addiu      $18, $18, 0x1
    /* 3AEA40 004AEA40 18007326 */  addiu      $19, $19, 0x18
  .L004AEA44:
    /* 3AEA44 004AEA44 2B185002 */  sltu       $3, $18, $16
    /* 3AEA48 004AEA48 F8FF6014 */  bnez       $3, .L004AEA2C
    /* 3AEA4C 004AEA4C 00000000 */   nop
    /* 3AEA50 004AEA50 4000BFDF */  ld         $31, 0x40($29)
    /* 3AEA54 004AEA54 3000B37B */  lq         $19, 0x30($29)
    /* 3AEA58 004AEA58 2000B27B */  lq         $18, 0x20($29)
    /* 3AEA5C 004AEA5C 1000B17B */  lq         $17, 0x10($29)
    /* 3AEA60 004AEA60 0000B07B */  lq         $16, 0x0($29)
    /* 3AEA64 004AEA64 5000BD27 */  addiu      $29, $29, 0x50
    /* 3AEA68 004AEA68 0800E003 */  jr         $31
    /* 3AEA6C 004AEA6C 00000000 */   nop
.size func_004ae930, 0x140
