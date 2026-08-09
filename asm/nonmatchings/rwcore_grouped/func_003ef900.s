.section .text
.set noat
.set noreorder
glabel func_003ef900
    /* 2EF900 003EF900 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2EF904 003EF904 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF908 003EF908 2000BFFF */  sd         $31, 0x20($29)
    /* 2EF90C 003EF90C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF910 003EF910 1000B17F */  sq         $17, 0x10($29)
    /* 2EF914 003EF914 0000B07F */  sq         $16, 0x0($29)
    /* 2EF918 003EF918 2D888000 */  daddu      $17, $4, $0
    /* 2EF91C 003EF91C E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF920 003EF920 21104300 */  addu       $2, $2, $3
    /* 2EF924 003EF924 2400448C */  lw         $4, 0x24($2)
    /* 2EF928 003EF928 0B008010 */  beqz       $4, .L003EF958
    /* 2EF92C 003EF92C 00000000 */   nop
    /* 2EF930 003EF930 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EF934 003EF934 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EF938 003EF938 09F84000 */  jalr       $2
    /* 2EF93C 003EF93C 00000000 */   nop
    /* 2EF940 003EF940 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF944 003EF944 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF948 003EF948 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF94C 003EF94C 21104300 */  addu       $2, $2, $3
    /* 2EF950 003EF950 240040AC */  sw         $0, 0x24($2)
    /* 2EF954 003EF954 280040A4 */  sh         $0, 0x28($2)
  .L003EF958:
    /* 2EF958 003EF958 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EF95C 003EF95C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EF960 003EF960 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EF964 003EF964 21284300 */  addu       $5, $2, $3
    /* 2EF968 003EF968 0800A28C */  lw         $2, 0x8($5)
    /* 2EF96C 003EF96C 30004010 */  beqz       $2, .L003EFA30
    /* 2EF970 003EF970 00000000 */   nop
    /* 2EF974 003EF974 0C00A28C */  lw         $2, 0xC($5)
    /* 2EF978 003EF978 2D004010 */  beqz       $2, .L003EFA30
    /* 2EF97C 003EF97C 00000000 */   nop
    /* 2EF980 003EF980 0000A28C */  lw         $2, 0x0($5)
    /* 2EF984 003EF984 2A004510 */  beq        $2, $5, .L003EFA30
    /* 2EF988 003EF988 00000000 */   nop
    /* 2EF98C 003EF98C D8B7848F */  lw         $4, -0x4828($28)
  .L003EF990:
    /* 2EF990 003EF990 0000438C */  lw         $3, 0x0($2)
    /* 2EF994 003EF994 F0FF4224 */  addiu      $2, $2, -0x10
    /* 2EF998 003EF998 23004414 */  bne        $2, $4, .L003EFA28
    /* 2EF99C 003EF99C 00000000 */   nop
    /* 2EF9A0 003EF9A0 D8B7908F */  lw         $16, -0x4828($28)
    /* 2EF9A4 003EF9A4 1000A28C */  lw         $2, 0x10($5)
    /* 2EF9A8 003EF9A8 3E005010 */  beq        $2, $16, .L003EFAA4
    /* 2EF9AC 003EF9AC 1000A324 */   addiu     $3, $5, 0x10
  .L003EF9B0:
    /* 2EF9B0 003EF9B0 3F00053C */  lui        $5, %hi(func_003ef3a0)
    /* 2EF9B4 003EF9B4 2D200002 */  daddu      $4, $16, $0
    /* 2EF9B8 003EF9B8 A0F3A524 */  addiu      $5, $5, %lo(func_003ef3a0)
    /* 2EF9BC 003EF9BC 98BC0F0C */  jal        func_003ef260
    /* 2EF9C0 003EF9C0 2D300000 */   daddu     $6, $0, $0
    /* 2EF9C4 003EF9C4 7100043C */  lui        $4, %hi(D_0070B820)
    /* 2EF9C8 003EF9C8 2D280002 */  daddu      $5, $16, $0
    /* 2EF9CC 003EF9CC 088F0F0C */  jal        func_003e3c20
    /* 2EF9D0 003EF9D0 20B88424 */   addiu     $4, $4, %lo(D_0070B820)
    /* 2EF9D4 003EF9D4 1000068E */  lw         $6, 0x10($16)
    /* 2EF9D8 003EF9D8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EF9DC 003EF9DC 1400048E */  lw         $4, 0x14($16)
    /* 2EF9E0 003EF9E0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EF9E4 003EF9E4 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EF9E8 003EF9E8 000086AC */  sw         $6, 0x0($4)
    /* 2EF9EC 003EF9EC 1400068E */  lw         $6, 0x14($16)
    /* 2EF9F0 003EF9F0 1000048E */  lw         $4, 0x10($16)
    /* 2EF9F4 003EF9F4 040086AC */  sw         $6, 0x4($4)
    /* 2EF9F8 003EF9F8 E0B7848F */  lw         $4, -0x4820($28)
    /* 2EF9FC 003EF9FC FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EFA00 003EFA00 21186400 */  addu       $3, $3, $4
    /* 2EFA04 003EFA04 0C00648C */  lw         $4, 0xC($3)
    /* 2EFA08 003EFA08 09F84000 */  jalr       $2
    /* 2EFA0C 003EFA0C 2D280002 */   daddu     $5, $16, $0
    /* 2EFA10 003EFA10 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFA14 003EFA14 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EFA18 003EFA18 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EFA1C 003EFA1C D8B780AF */  sw         $0, -0x4828($28)
    /* 2EFA20 003EFA20 03000010 */  b          .L003EFA30
    /* 2EFA24 003EFA24 21284300 */   addu      $5, $2, $3
  .L003EFA28:
    /* 2EFA28 003EFA28 D9FF6514 */  bne        $3, $5, .L003EF990
    /* 2EFA2C 003EFA2C 2D106000 */   daddu     $2, $3, $0
  .L003EFA30:
    /* 2EFA30 003EFA30 0800A48C */  lw         $4, 0x8($5)
    /* 2EFA34 003EFA34 08008010 */  beqz       $4, .L003EFA58
    /* 2EFA38 003EFA38 00000000 */   nop
    /* 2EFA3C 003EFA3C BC840F0C */  jal        func_003e12f0
    /* 2EFA40 003EFA40 00000000 */   nop
    /* 2EFA44 003EFA44 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFA48 003EFA48 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EFA4C 003EFA4C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EFA50 003EFA50 21104300 */  addu       $2, $2, $3
    /* 2EFA54 003EFA54 080040AC */  sw         $0, 0x8($2)
  .L003EFA58:
    /* 2EFA58 003EFA58 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFA5C 003EFA5C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EFA60 003EFA60 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EFA64 003EFA64 21104300 */  addu       $2, $2, $3
    /* 2EFA68 003EFA68 0C00448C */  lw         $4, 0xC($2)
    /* 2EFA6C 003EFA6C 08008010 */  beqz       $4, .L003EFA90
    /* 2EFA70 003EFA70 00000000 */   nop
    /* 2EFA74 003EFA74 BC840F0C */  jal        func_003e12f0
    /* 2EFA78 003EFA78 00000000 */   nop
    /* 2EFA7C 003EFA7C E0B7838F */  lw         $3, -0x4820($28)
    /* 2EFA80 003EFA80 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EFA84 003EFA84 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EFA88 003EFA88 21104300 */  addu       $2, $2, $3
    /* 2EFA8C 003EFA8C 0C0040AC */  sw         $0, 0xC($2)
  .L003EFA90:
    /* 2EFA90 003EFA90 E4B7838F */  lw         $3, -0x481C($28)
    /* 2EFA94 003EFA94 2D102002 */  daddu      $2, $17, $0
    /* 2EFA98 003EFA98 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2EFA9C 003EFA9C 03000010 */  b          .L003EFAAC
    /* 2EFAA0 003EFAA0 E4B783AF */   sw        $3, -0x481C($28)
  .L003EFAA4:
    /* 2EFAA4 003EFAA4 C2FF0010 */  b          .L003EF9B0
    /* 2EFAA8 003EFAA8 000060AC */   sw        $0, 0x0($3)
  .L003EFAAC:
    /* 2EFAAC 003EFAAC 2000BFDF */  ld         $31, 0x20($29)
    /* 2EFAB0 003EFAB0 1000B17B */  lq         $17, 0x10($29)
    /* 2EFAB4 003EFAB4 0000B07B */  lq         $16, 0x0($29)
    /* 2EFAB8 003EFAB8 0800E003 */  jr         $31
    /* 2EFABC 003EFABC 3000BD27 */   addiu     $29, $29, 0x30
.size func_003ef900, 0x1c0
