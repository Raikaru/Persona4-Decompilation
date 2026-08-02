.section .text
.set noat
.set noreorder
glabel func_002e1db0
    /* 1E1DB0 002E1DB0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 1E1DB4 002E1DB4 6000BFFF */  sd         $31, 0x60($29)
    /* 1E1DB8 002E1DB8 5000B57F */  sq         $21, 0x50($29)
    /* 1E1DBC 002E1DBC 4000B47F */  sq         $20, 0x40($29)
    /* 1E1DC0 002E1DC0 3000B37F */  sq         $19, 0x30($29)
    /* 1E1DC4 002E1DC4 2000B27F */  sq         $18, 0x20($29)
    /* 1E1DC8 002E1DC8 1000B17F */  sq         $17, 0x10($29)
    /* 1E1DCC 002E1DCC 0000B07F */  sq         $16, 0x0($29)
    /* 1E1DD0 002E1DD0 2DA88000 */  daddu      $21, $4, $0
    /* 1E1DD4 002E1DD4 2DA0A000 */  daddu      $20, $5, $0
    /* 1E1DD8 002E1DD8 2D98C000 */  daddu      $19, $6, $0
    /* 1E1DDC 002E1DDC 2D90E000 */  daddu      $18, $7, $0
    /* 1E1DE0 002E1DE0 2800B126 */  addiu      $17, $21, 0x28
    /* 1E1DE4 002E1DE4 6400043C */  lui        $4, %hi(D_0063FC38)
    /* 1E1DE8 002E1DE8 38FC8424 */  addiu      $4, $4, %lo(D_0063FC38)
    /* 1E1DEC 002E1DEC 33000524 */  addiu      $5, $0, 0x33
    /* 1E1DF0 002E1DF0 A43A110C */  jal        func_0044ea90
    /* 1E1DF4 002E1DF4 00000000 */   nop
    /* 1E1DF8 002E1DF8 2D202002 */  daddu      $4, $17, $0
    /* 1E1DFC 002E1DFC 0400053C */  lui        $5, (0x40000 >> 16)
    /* 1E1E00 002E1E00 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 1E1E04 002E1E04 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 1E1E08 002E1E08 09F84000 */  jalr       $2
    /* 1E1E0C 002E1E0C 00000000 */   nop
    /* 1E1E10 002E1E10 2D804000 */  daddu      $16, $2, $0
    /* 1E1E14 002E1E14 06000016 */  bnez       $16, .L002E1E30
    /* 1E1E18 002E1E18 00000000 */   nop
    /* 1E1E1C 002E1E1C 6400043C */  lui        $4, %hi(D_0063FC38)
    /* 1E1E20 002E1E20 38FC8424 */  addiu      $4, $4, %lo(D_0063FC38)
    /* 1E1E24 002E1E24 35000524 */  addiu      $5, $0, 0x35
    /* 1E1E28 002E1E28 CCB5110C */  jal        func_0046d730
    /* 1E1E2C 002E1E2C 00000000 */   nop
  .L002E1E30:
    /* 1E1E30 002E1E30 2D200002 */  daddu      $4, $16, $0
    /* 1E1E34 002E1E34 2D280000 */  daddu      $5, $0, $0
    /* 1E1E38 002E1E38 2D302002 */  daddu      $6, $17, $0
    /* 1E1E3C 002E1E3C 72FE100C */  jal        func_0043f9c8
    /* 1E1E40 002E1E40 00000000 */   nop
    /* 1E1E44 002E1E44 0300A012 */  beqz       $21, .L002E1E54
    /* 1E1E48 002E1E48 00000000 */   nop
    /* 1E1E4C 002E1E4C 28000226 */  addiu      $2, $16, 0x28
    /* 1E1E50 002E1E50 240002AE */  sw         $2, 0x24($16)
  .L002E1E54:
    /* 1E1E54 002E1E54 200011AE */  sw         $17, 0x20($16)
    /* 1E1E58 002E1E58 04008012 */  beqz       $20, .L002E1E6C
    /* 1E1E5C 002E1E5C 00000000 */   nop
    /* 1E1E60 002E1E60 140014AE */  sw         $20, 0x14($16)
    /* 1E1E64 002E1E64 04000010 */  b          .L002E1E78
    /* 1E1E68 002E1E68 00000000 */   nop
  .L002E1E6C:
    /* 1E1E6C 002E1E6C 2E00023C */  lui        $2, %hi(func_002e1cd0)
    /* 1E1E70 002E1E70 D01C4224 */  addiu      $2, $2, %lo(func_002e1cd0)
    /* 1E1E74 002E1E74 140002AE */  sw         $2, 0x14($16)
  .L002E1E78:
    /* 1E1E78 002E1E78 04006012 */  beqz       $19, .L002E1E8C
    /* 1E1E7C 002E1E7C 00000000 */   nop
    /* 1E1E80 002E1E80 180013AE */  sw         $19, 0x18($16)
    /* 1E1E84 002E1E84 04000010 */  b          .L002E1E98
    /* 1E1E88 002E1E88 00000000 */   nop
  .L002E1E8C:
    /* 1E1E8C 002E1E8C 2E00023C */  lui        $2, %hi(func_002e1ce0)
    /* 1E1E90 002E1E90 E01C4224 */  addiu      $2, $2, %lo(func_002e1ce0)
    /* 1E1E94 002E1E94 180002AE */  sw         $2, 0x18($16)
  .L002E1E98:
    /* 1E1E98 002E1E98 04004012 */  beqz       $18, .L002E1EAC
    /* 1E1E9C 002E1E9C 00000000 */   nop
    /* 1E1EA0 002E1EA0 1C0012AE */  sw         $18, 0x1C($16)
    /* 1E1EA4 002E1EA4 04000010 */  b          .L002E1EB8
    /* 1E1EA8 002E1EA8 00000000 */   nop
  .L002E1EAC:
    /* 1E1EAC 002E1EAC 2E00023C */  lui        $2, %hi(func_002e1cf0)
    /* 1E1EB0 002E1EB0 F01C4224 */  addiu      $2, $2, %lo(func_002e1cf0)
    /* 1E1EB4 002E1EB4 1C0002AE */  sw         $2, 0x1C($16)
  .L002E1EB8:
    /* 1E1EB8 002E1EB8 2D100002 */  daddu      $2, $16, $0
    /* 1E1EBC 002E1EBC 6000BFDF */  ld         $31, 0x60($29)
    /* 1E1EC0 002E1EC0 5000B57B */  lq         $21, 0x50($29)
    /* 1E1EC4 002E1EC4 4000B47B */  lq         $20, 0x40($29)
    /* 1E1EC8 002E1EC8 3000B37B */  lq         $19, 0x30($29)
    /* 1E1ECC 002E1ECC 2000B27B */  lq         $18, 0x20($29)
    /* 1E1ED0 002E1ED0 1000B17B */  lq         $17, 0x10($29)
    /* 1E1ED4 002E1ED4 0000B07B */  lq         $16, 0x0($29)
    /* 1E1ED8 002E1ED8 7000BD27 */  addiu      $29, $29, 0x70
    /* 1E1EDC 002E1EDC 0800E003 */  jr         $31
    /* 1E1EE0 002E1EE0 00000000 */   nop
    /* 1E1EE4 002E1EE4 00000000 */  nop
    /* 1E1EE8 002E1EE8 00000000 */  nop
    /* 1E1EEC 002E1EEC 00000000 */  nop
.size func_002e1db0, 0x140
