.section .text
.set noat
.set noreorder
glabel func_0022ead0
    /* 12EAD0 0022EAD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 12EAD4 0022EAD4 1000BFFF */  sd         $31, 0x10($29)
    /* 12EAD8 0022EAD8 0000B07F */  sq         $16, 0x0($29)
    /* 12EADC 0022EADC ACB3828F */  lw         $2, -0x4C54($28)
    /* 12EAE0 0022EAE0 0C00438C */  lw         $3, 0xC($2)
    /* 12EAE4 0022EAE4 2000023C */  lui        $2, (0x200000 >> 16)
    /* 12EAE8 0022EAE8 24106200 */  and        $2, $3, $2
    /* 12EAEC 0022EAEC 04004014 */  bnez       $2, .L0022EB00
    /* 12EAF0 0022EAF0 00000000 */   nop
    /* 12EAF4 0022EAF4 2D100000 */  daddu      $2, $0, $0
    /* 12EAF8 0022EAF8 22000010 */  b          .L0022EB84
    /* 12EAFC 0022EAFC 00000000 */   nop
  .L0022EB00:
    /* 12EB00 0022EB00 68BE070C */  jal        func_001ef9a0
    /* 12EB04 0022EB04 00000000 */   nop
    /* 12EB08 0022EB08 02020324 */  addiu      $3, $0, 0x202
    /* 12EB0C 0022EB0C 03004310 */  beq        $2, $3, .L0022EB1C
    /* 12EB10 0022EB10 00000000 */   nop
    /* 12EB14 0022EB14 1A000010 */  b          .L0022EB80
    /* 12EB18 0022EB18 00000000 */   nop
  .L0022EB1C:
    /* 12EB1C 0022EB1C ACB3828F */  lw         $2, -0x4C54($28)
    /* 12EB20 0022EB20 8001508C */  lw         $16, 0x180($2)
    /* 12EB24 0022EB24 14000010 */  b          .L0022EB78
    /* 12EB28 0022EB28 00000000 */   nop
  .L0022EB2C:
    /* 12EB2C 0022EB2C A4000396 */  lhu        $3, 0xA4($16)
    /* 12EB30 0022EB30 0D010224 */  addiu      $2, $0, 0x10D
    /* 12EB34 0022EB34 0F006214 */  bne        $3, $2, .L0022EB74
    /* 12EB38 0022EB38 00000000 */   nop
    /* 12EB3C 0022EB3C 9B43023C */  lui        $2, (0x439B0000 >> 16)
    /* 12EB40 0022EB40 2000A2AF */  sw         $2, 0x20($29)
    /* 12EB44 0022EB44 2400A0AF */  sw         $0, 0x24($29)
    /* 12EB48 0022EB48 4C8380C7 */  lwc1       $f0, -0x7CB4($28)
    /* 12EB4C 0022EB4C 2800A0E7 */  swc1       $f0, 0x28($29)
    /* 12EB50 0022EB50 94000426 */  addiu      $4, $16, 0x94
    /* 12EB54 0022EB54 96000526 */  addiu      $5, $16, 0x96
    /* 12EB58 0022EB58 2000A627 */  addiu      $6, $29, 0x20
    /* 12EB5C 0022EB5C B4B1070C */  jal        func_001ec6d0
    /* 12EB60 0022EB60 00000000 */   nop
    /* 12EB64 0022EB64 2D200002 */  daddu      $4, $16, $0
    /* 12EB68 0022EB68 2000A527 */  addiu      $5, $29, 0x20
    /* 12EB6C 0022EB6C B853060C */  jal        func_00194ee0
    /* 12EB70 0022EB70 00000000 */   nop
  .L0022EB74:
    /* 12EB74 0022EB74 6C0A108E */  lw         $16, 0xA6C($16)
  .L0022EB78:
    /* 12EB78 0022EB78 ECFF0016 */  bnez       $16, .L0022EB2C
    /* 12EB7C 0022EB7C 00000000 */   nop
  .L0022EB80:
    /* 12EB80 0022EB80 01000224 */  addiu      $2, $0, 0x1
  .L0022EB84:
    /* 12EB84 0022EB84 1000BFDF */  ld         $31, 0x10($29)
    /* 12EB88 0022EB88 0000B07B */  lq         $16, 0x0($29)
    /* 12EB8C 0022EB8C 3000BD27 */  addiu      $29, $29, 0x30
    /* 12EB90 0022EB90 0800E003 */  jr         $31
    /* 12EB94 0022EB94 00000000 */   nop
    /* 12EB98 0022EB98 00000000 */  nop
    /* 12EB9C 0022EB9C 00000000 */  nop
.size func_0022ead0, 0xd0
