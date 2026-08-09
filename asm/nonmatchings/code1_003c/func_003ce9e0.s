.section .text
.set noat
.set noreorder
glabel func_003ce9e0
    /* 2CE9E0 003CE9E0 80FFBD27 */  addiu      $29, $29, -0x80
    /* 2CE9E4 003CE9E4 6000BFFF */  sd         $31, 0x60($29)
    /* 2CE9E8 003CE9E8 5000B57F */  sq         $21, 0x50($29)
    /* 2CE9EC 003CE9EC 4000B47F */  sq         $20, 0x40($29)
    /* 2CE9F0 003CE9F0 3000B37F */  sq         $19, 0x30($29)
    /* 2CE9F4 003CE9F4 2DA08000 */  daddu      $20, $4, $0
    /* 2CE9F8 003CE9F8 2000B27F */  sq         $18, 0x20($29)
    /* 2CE9FC 003CE9FC 2D98A000 */  daddu      $19, $5, $0
    /* 2CEA00 003CEA00 1000B17F */  sq         $17, 0x10($29)
    /* 2CEA04 003CEA04 2D206002 */  daddu      $4, $19, $0
    /* 2CEA08 003CEA08 08270F0C */  jal        func_003c9c20
    /* 2CEA0C 003CEA0C 0000B07F */   sq        $16, 0x0($29)
    /* 2CEA10 003CEA10 0800438C */  lw         $3, 0x8($2)
    /* 2CEA14 003CEA14 0001023C */  lui        $2, (0x1000000 >> 16)
    /* 2CEA18 003CEA18 24106200 */  and        $2, $3, $2
    /* 2CEA1C 003CEA1C 52004010 */  beqz       $2, .L003CEB68
    /* 2CEA20 003CEA20 00000000 */   nop
    /* 2CEA24 003CEA24 28B7828F */  lw         $2, -0x48D8($28)
    /* 2CEA28 003CEA28 21106202 */  addu       $2, $19, $2
    /* 2CEA2C 003CEA2C 0000528C */  lw         $18, 0x0($2)
    /* 2CEA30 003CEA30 0000558E */  lw         $21, 0x0($18)
    /* 2CEA34 003CEA34 2B081500 */  sltu       $1, $0, $21
    /* 2CEA38 003CEA38 09002010 */  beqz       $1, .L003CEA60
    /* 2CEA3C 003CEA3C 2D880000 */   daddu     $17, $0, $0
    /* 2CEA40 003CEA40 2D804002 */  daddu      $16, $18, $0
  .L003CEA44:
    /* 2CEA44 003CEA44 B8310F0C */  jal        func_003cc6e0
    /* 2CEA48 003CEA48 0400048E */   lw        $4, 0x4($16)
    /* 2CEA4C 003CEA4C 01003126 */  addiu      $17, $17, 0x1
    /* 2CEA50 003CEA50 04001026 */  addiu      $16, $16, 0x4
    /* 2CEA54 003CEA54 2B103502 */  sltu       $2, $17, $21
    /* 2CEA58 003CEA58 FAFF4014 */  bnez       $2, .L003CEA44
    /* 2CEA5C 003CEA5C 00000000 */   nop
  .L003CEA60:
    /* 2CEA60 003CEA60 AC3B0F0C */  jal        func_003ceeb0
    /* 2CEA64 003CEA64 2D206002 */   daddu     $4, $19, $0
    /* 2CEA68 003CEA68 F4FF4624 */  addiu      $6, $2, -0xC
    /* 2CEA6C 003CEA6C 2D208002 */  daddu      $4, $20, $0
    /* 2CEA70 003CEA70 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2CEA74 003CEA74 01000524 */  addiu      $5, $0, 0x1
    /* 2CEA78 003CEA78 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2CEA7C 003CEA7C FC7B0F0C */  jal        func_003deff0
    /* 2CEA80 003CEA80 37000824 */   addiu     $8, $0, 0x37
    /* 2CEA84 003CEA84 03004014 */  bnez       $2, .L003CEA94
    /* 2CEA88 003CEA88 00000000 */   nop
    /* 2CEA8C 003CEA8C 3D000010 */  b          .L003CEB84
    /* 2CEA90 003CEA90 2D100000 */   daddu     $2, $0, $0
  .L003CEA94:
    /* 2CEA94 003CEA94 2D208002 */  daddu      $4, $20, $0
    /* 2CEA98 003CEA98 BCAA8527 */  addiu      $5, $28, -0x5544
    /* 2CEA9C 003CEA9C AC8A0F0C */  jal        func_003e2ab0
    /* 2CEAA0 003CEAA0 04000624 */   addiu     $6, $0, 0x4
    /* 2CEAA4 003CEAA4 32004010 */  beqz       $2, .L003CEB70
    /* 2CEAA8 003CEAA8 00000000 */   nop
    /* 2CEAAC 003CEAAC 0000428E */  lw         $2, 0x0($18)
    /* 2CEAB0 003CEAB0 2B080200 */  sltu       $1, $0, $2
    /* 2CEAB4 003CEAB4 2C002010 */  beqz       $1, .L003CEB68
    /* 2CEAB8 003CEAB8 2D880000 */   daddu     $17, $0, $0
    /* 2CEABC 003CEABC 2D984002 */  daddu      $19, $18, $0
  .L003CEAC0:
    /* 2CEAC0 003CEAC0 0400708E */  lw         $16, 0x4($19)
    /* 2CEAC4 003CEAC4 2D208002 */  daddu      $4, $20, $0
    /* 2CEAC8 003CEAC8 7C00A527 */  addiu      $5, $29, 0x7C
    /* 2CEACC 003CEACC 04000624 */  addiu      $6, $0, 0x4
    /* 2CEAD0 003CEAD0 2000038E */  lw         $3, 0x20($16)
    /* 2CEAD4 003CEAD4 18001526 */  addiu      $21, $16, 0x18
    /* 2CEAD8 003CEAD8 0800028E */  lw         $2, 0x8($16)
    /* 2CEADC 003CEADC 23187000 */  subu       $3, $3, $16
    /* 2CEAE0 003CEAE0 23104300 */  subu       $2, $2, $3
    /* 2CEAE4 003CEAE4 AC8A0F0C */  jal        func_003e2ab0
    /* 2CEAE8 003CEAE8 7C00A2AF */   sw        $2, 0x7C($29)
    /* 2CEAEC 003CEAEC 03004014 */  bnez       $2, .L003CEAFC
    /* 2CEAF0 003CEAF0 00000000 */   nop
    /* 2CEAF4 003CEAF4 23000010 */  b          .L003CEB84
    /* 2CEAF8 003CEAF8 2D100000 */   daddu     $2, $0, $0
  .L003CEAFC:
    /* 2CEAFC 003CEAFC 5C380F0C */  jal        func_003ce170
    /* 2CEB00 003CEB00 2D20A002 */   daddu     $4, $21, $0
    /* 2CEB04 003CEB04 7800A2AF */  sw         $2, 0x78($29)
    /* 2CEB08 003CEB08 2D208002 */  daddu      $4, $20, $0
    /* 2CEB0C 003CEB0C 7800A527 */  addiu      $5, $29, 0x78
    /* 2CEB10 003CEB10 AC8A0F0C */  jal        func_003e2ab0
    /* 2CEB14 003CEB14 04000624 */   addiu     $6, $0, 0x4
    /* 2CEB18 003CEB18 17004010 */  beqz       $2, .L003CEB78
    /* 2CEB1C 003CEB1C 00000000 */   nop
    /* 2CEB20 003CEB20 0800A58E */  lw         $5, 0x8($21)
    /* 2CEB24 003CEB24 7C00A68F */  lw         $6, 0x7C($29)
    /* 2CEB28 003CEB28 AC8A0F0C */  jal        func_003e2ab0
    /* 2CEB2C 003CEB2C 2D208002 */   daddu     $4, $20, $0
    /* 2CEB30 003CEB30 13004010 */  beqz       $2, .L003CEB80
    /* 2CEB34 003CEB34 00000000 */   nop
    /* 2CEB38 003CEB38 8C380F0C */  jal        func_003ce230
    /* 2CEB3C 003CEB3C 2D20A002 */   daddu     $4, $21, $0
    /* 2CEB40 003CEB40 0800028E */  lw         $2, 0x8($16)
    /* 2CEB44 003CEB44 2D200002 */  daddu      $4, $16, $0
    /* 2CEB48 003CEB48 21100202 */  addu       $2, $16, $2
    /* 2CEB4C 003CEB4C 3688100C */  jal        func_004220d8
    /* 2CEB50 003CEB50 18004524 */   addiu     $5, $2, 0x18
    /* 2CEB54 003CEB54 0000428E */  lw         $2, 0x0($18)
    /* 2CEB58 003CEB58 01003126 */  addiu      $17, $17, 0x1
    /* 2CEB5C 003CEB5C 2B102202 */  sltu       $2, $17, $2
    /* 2CEB60 003CEB60 D7FF4014 */  bnez       $2, .L003CEAC0
    /* 2CEB64 003CEB64 04007326 */   addiu     $19, $19, 0x4
  .L003CEB68:
    /* 2CEB68 003CEB68 06000010 */  b          .L003CEB84
    /* 2CEB6C 003CEB6C 2D108002 */   daddu     $2, $20, $0
  .L003CEB70:
    /* 2CEB70 003CEB70 04000010 */  b          .L003CEB84
    /* 2CEB74 003CEB74 2D100000 */   daddu     $2, $0, $0
  .L003CEB78:
    /* 2CEB78 003CEB78 02000010 */  b          .L003CEB84
    /* 2CEB7C 003CEB7C 2D100000 */   daddu     $2, $0, $0
  .L003CEB80:
    /* 2CEB80 003CEB80 2D100000 */  daddu      $2, $0, $0
  .L003CEB84:
    /* 2CEB84 003CEB84 6000BFDF */  ld         $31, 0x60($29)
    /* 2CEB88 003CEB88 5000B57B */  lq         $21, 0x50($29)
    /* 2CEB8C 003CEB8C 4000B47B */  lq         $20, 0x40($29)
    /* 2CEB90 003CEB90 3000B37B */  lq         $19, 0x30($29)
    /* 2CEB94 003CEB94 2000B27B */  lq         $18, 0x20($29)
    /* 2CEB98 003CEB98 1000B17B */  lq         $17, 0x10($29)
    /* 2CEB9C 003CEB9C 0000B07B */  lq         $16, 0x0($29)
    /* 2CEBA0 003CEBA0 0800E003 */  jr         $31
    /* 2CEBA4 003CEBA4 8000BD27 */   addiu     $29, $29, 0x80
    /* 2CEBA8 003CEBA8 00000000 */  nop
    /* 2CEBAC 003CEBAC 00000000 */  nop
.size func_003ce9e0, 0x1d0
