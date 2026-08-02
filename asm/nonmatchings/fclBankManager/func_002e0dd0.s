.section .text
.set noat
.set noreorder
glabel func_002e0dd0
    /* 1E0DD0 002E0DD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1E0DD4 002E0DD4 1000BFFF */  sd         $31, 0x10($29)
    /* 1E0DD8 002E0DD8 0000B07F */  sq         $16, 0x0($29)
    /* 1E0DDC 002E0DDC 88B5828F */  lw         $2, -0x4A78($28)
    /* 1E0DE0 002E0DE0 2400428C */  lw         $2, 0x24($2)
    /* 1E0DE4 002E0DE4 04004424 */  addiu      $4, $2, 0x4
    /* 1E0DE8 002E0DE8 2D280000 */  daddu      $5, $0, $0
    /* 1E0DEC 002E0DEC 0C000010 */  b          .L002E0E20
    /* 1E0DF0 002E0DF0 00000000 */   nop
  .L002E0DF4:
    /* 1E0DF4 002E0DF4 00008384 */  lh         $3, 0x0($4)
    /* 1E0DF8 002E0DF8 01006230 */  andi       $2, $3, 0x1
    /* 1E0DFC 002E0DFC 06004010 */  beqz       $2, .L002E0E18
    /* 1E0E00 002E0E00 00000000 */   nop
    /* 1E0E04 002E0E04 00106230 */  andi       $2, $3, 0x1000
    /* 1E0E08 002E0E08 03004014 */  bnez       $2, .L002E0E18
    /* 1E0E0C 002E0E0C 00000000 */   nop
    /* 1E0E10 002E0E10 00046234 */  ori        $2, $3, 0x400
    /* 1E0E14 002E0E14 000082A4 */  sh         $2, 0x0($4)
  .L002E0E18:
    /* 1E0E18 002E0E18 14008424 */  addiu      $4, $4, 0x14
    /* 1E0E1C 002E0E1C 0100A524 */  addiu      $5, $5, 0x1
  .L002E0E20:
    /* 1E0E20 002E0E20 0200A228 */  slti       $2, $5, 0x2
    /* 1E0E24 002E0E24 F3FF4014 */  bnez       $2, .L002E0DF4
    /* 1E0E28 002E0E28 00000000 */   nop
    /* 1E0E2C 002E0E2C 88B5828F */  lw         $2, -0x4A78($28)
    /* 1E0E30 002E0E30 0400468C */  lw         $6, 0x4($2)
    /* 1E0E34 002E0E34 07000010 */  b          .L002E0E54
    /* 1E0E38 002E0E38 00000000 */   nop
  .L002E0E3C:
    /* 1E0E3C 002E0E3C 1000D08C */  lw         $16, 0x10($6)
    /* 1E0E40 002E0E40 88B5848F */  lw         $4, -0x4A78($28)
    /* 1E0E44 002E0E44 04008524 */  addiu      $5, $4, 0x4
    /* 1E0E48 002E0E48 90880B0C */  jal        func_002e2240
    /* 1E0E4C 002E0E4C 00000000 */   nop
    /* 1E0E50 002E0E50 2D300002 */  daddu      $6, $16, $0
  .L002E0E54:
    /* 1E0E54 002E0E54 F9FFC014 */  bnez       $6, .L002E0E3C
    /* 1E0E58 002E0E58 00000000 */   nop
    /* 1E0E5C 002E0E5C 90A88427 */  addiu      $4, $28, -0x5770
    /* 1E0E60 002E0E60 6400053C */  lui        $5, %hi(D_0063FBB0)
    /* 1E0E64 002E0E64 B0FBA524 */  addiu      $5, $5, %lo(D_0063FBB0)
    /* 1E0E68 002E0E68 CA000624 */  addiu      $6, $0, 0xCA
    /* 1E0E6C 002E0E6C DA02110C */  jal        func_00440b68
    /* 1E0E70 002E0E70 00000000 */   nop
    /* 1E0E74 002E0E74 98A88427 */  addiu      $4, $28, -0x5768
    /* 1E0E78 002E0E78 A8830B0C */  jal        func_002e0ea0
    /* 1E0E7C 002E0E7C 00000000 */   nop
    /* 1E0E80 002E0E80 1000BFDF */  ld         $31, 0x10($29)
    /* 1E0E84 002E0E84 0000B07B */  lq         $16, 0x0($29)
    /* 1E0E88 002E0E88 2000BD27 */  addiu      $29, $29, 0x20
    /* 1E0E8C 002E0E8C 0800E003 */  jr         $31
    /* 1E0E90 002E0E90 00000000 */   nop
    /* 1E0E94 002E0E94 00000000 */  nop
    /* 1E0E98 002E0E98 00000000 */  nop
    /* 1E0E9C 002E0E9C 00000000 */  nop
.size func_002e0dd0, 0xd0
