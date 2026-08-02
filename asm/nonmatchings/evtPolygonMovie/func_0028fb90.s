.section .text
.set noat
.set noreorder
glabel func_0028fb90
    /* 18FB90 0028FB90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 18FB94 0028FB94 1000BFFF */  sd         $31, 0x10($29)
    /* 18FB98 0028FB98 0000B07F */  sq         $16, 0x0($29)
    /* 18FB9C 0028FB9C 7500043C */  lui        $4, %hi(D_00748340)
    /* 18FBA0 0028FBA0 40838424 */  addiu      $4, $4, %lo(D_00748340)
    /* 18FBA4 0028FBA4 52000524 */  addiu      $5, $0, 0x52
    /* 18FBA8 0028FBA8 A43A110C */  jal        func_0044ea90
    /* 18FBAC 0028FBAC 00000000 */   nop
    /* 18FBB0 0028FBB0 01000424 */  addiu      $4, $0, 0x1
    /* 18FBB4 0028FBB4 14010524 */  addiu      $5, $0, 0x114
    /* 18FBB8 0028FBB8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 18FBBC 0028FBBC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 18FBC0 0028FBC0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 18FBC4 0028FBC4 09F84000 */  jalr       $2
    /* 18FBC8 0028FBC8 00000000 */   nop
    /* 18FBCC 0028FBCC 2D804000 */  daddu      $16, $2, $0
    /* 18FBD0 0028FBD0 01000424 */  addiu      $4, $0, 0x1
    /* 18FBD4 0028FBD4 14010524 */  addiu      $5, $0, 0x114
    /* 18FBD8 0028FBD8 A8140A0C */  jal        func_002852a0
    /* 18FBDC 0028FBDC 00000000 */   nop
    /* 18FBE0 0028FBE0 09000016 */  bnez       $16, .L0028FC08
    /* 18FBE4 0028FBE4 00000000 */   nop
    /* 18FBE8 0028FBE8 6400043C */  lui        $4, %hi(D_0063C6A0)
    /* 18FBEC 0028FBEC A0C68424 */  addiu      $4, $4, %lo(D_0063C6A0)
    /* 18FBF0 0028FBF0 2D010524 */  addiu      $5, $0, 0x12D
    /* 18FBF4 0028FBF4 CCB5110C */  jal        func_0046d730
    /* 18FBF8 0028FBF8 00000000 */   nop
    /* 18FBFC 0028FBFC 2D100000 */  daddu      $2, $0, $0
    /* 18FC00 0028FC00 07000010 */  b          .L0028FC20
    /* 18FC04 0028FC04 00000000 */   nop
  .L0028FC08:
    /* 18FC08 0028FC08 2D200002 */  daddu      $4, $16, $0
    /* 18FC0C 0028FC0C 2D280000 */  daddu      $5, $0, $0
    /* 18FC10 0028FC10 14010624 */  addiu      $6, $0, 0x114
    /* 18FC14 0028FC14 72FE100C */  jal        func_0043f9c8
    /* 18FC18 0028FC18 00000000 */   nop
    /* 18FC1C 0028FC1C 2D100002 */  daddu      $2, $16, $0
  .L0028FC20:
    /* 18FC20 0028FC20 1000BFDF */  ld         $31, 0x10($29)
    /* 18FC24 0028FC24 0000B07B */  lq         $16, 0x0($29)
    /* 18FC28 0028FC28 2000BD27 */  addiu      $29, $29, 0x20
    /* 18FC2C 0028FC2C 0800E003 */  jr         $31
    /* 18FC30 0028FC30 00000000 */   nop
    /* 18FC34 0028FC34 00000000 */  nop
    /* 18FC38 0028FC38 00000000 */  nop
    /* 18FC3C 0028FC3C 00000000 */  nop
.size func_0028fb90, 0xb0
