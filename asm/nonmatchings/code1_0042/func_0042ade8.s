.section .text
.set noat
.set noreorder
glabel func_0042ade8
    /* 32ADE8 0042ADE8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 32ADEC 0042ADEC 3000B2FF */  sd         $18, 0x30($29)
    /* 32ADF0 0042ADF0 2000B1FF */  sd         $17, 0x20($29)
    /* 32ADF4 0042ADF4 2D908000 */  daddu      $18, $4, $0
    /* 32ADF8 0042ADF8 1000B0FF */  sd         $16, 0x10($29)
    /* 32ADFC 0042ADFC 2D88A000 */  daddu      $17, $5, $0
    /* 32AE00 0042AE00 4000BFFF */  sd         $31, 0x40($29)
    /* 32AE04 0042AE04 5AA8100C */  jal        func_0042a168
    /* 32AE08 0042AE08 2D80C000 */   daddu     $16, $6, $0
    /* 32AE0C 0042AE0C 03004104 */  bgez       $2, .L0042AE1C
    /* 32AE10 0042AE10 8900073C */   lui       $7, %hi(D_00891140)
    /* 32AE14 0042AE14 25000010 */  b          .L0042AEAC
    /* 32AE18 0042AE18 FFFF023C */   lui       $2, (0xFFFF0000 >> 16)
  .L0042AE1C:
    /* 32AE1C 0042AE1C 4011E324 */  addiu      $3, $7, %lo(D_00891140)
    /* 32AE20 0042AE20 4011F2AC */  sw         $18, %lo(D_00891140)($7)
    /* 32AE24 0042AE24 04000016 */  bnez       $16, .L0042AE38
    /* 32AE28 0042AE28 040070AC */   sw        $16, 0x4($3)
    /* 32AE2C 0042AE2C 00002292 */  lbu        $2, 0x0($17)
    /* 32AE30 0042AE30 0D000010 */  b          .L0042AE68
    /* 32AE34 0042AE34 080062A0 */   sb        $2, 0x8($3)
  .L0042AE38:
    /* 32AE38 0042AE38 01000224 */  addiu      $2, $0, 0x1
    /* 32AE3C 0042AE3C 04000216 */  bne        $16, $2, .L0042AE50
    /* 32AE40 0042AE40 02000224 */   addiu     $2, $0, 0x2
    /* 32AE44 0042AE44 00002296 */  lhu        $2, 0x0($17)
    /* 32AE48 0042AE48 07000010 */  b          .L0042AE68
    /* 32AE4C 0042AE4C 080062A4 */   sh        $2, 0x8($3)
  .L0042AE50:
    /* 32AE50 0042AE50 04000252 */  beql       $16, $2, .L0042AE64
    /* 32AE54 0042AE54 0000228E */   lw        $2, 0x0($17)
    /* 32AE58 0042AE58 FEFF023C */  lui        $2, (0xFFFEFFFE >> 16)
    /* 32AE5C 0042AE5C 13000010 */  b          .L0042AEAC
    /* 32AE60 0042AE60 FEFF4234 */   ori       $2, $2, (0xFFFEFFFE & 0xFFFF)
  .L0042AE64:
    /* 32AE64 0042AE64 080062AC */  sw         $2, 0x8($3)
  .L0042AE68:
    /* 32AE68 0042AE68 4011E724 */  addiu      $7, $7, %lo(D_00891140)
    /* 32AE6C 0042AE6C 8900043C */  lui        $4, %hi(D_00891340)
    /* 32AE70 0042AE70 40138424 */  addiu      $4, $4, %lo(D_00891340)
    /* 32AE74 0042AE74 0000A0AF */  sw         $0, 0x0($29)
    /* 32AE78 0042AE78 02000524 */  addiu      $5, $0, 0x2
    /* 32AE7C 0042AE7C 2D300000 */  daddu      $6, $0, $0
    /* 32AE80 0042AE80 20000824 */  addiu      $8, $0, 0x20
    /* 32AE84 0042AE84 2D48E000 */  daddu      $9, $7, $0
    /* 32AE88 0042AE88 10000A24 */  addiu      $10, $0, 0x10
    /* 32AE8C 0042AE8C 2C96100C */  jal        func_004258b0
    /* 32AE90 0042AE90 2D580000 */   daddu     $11, $0, $0
    /* 32AE94 0042AE94 FEFF043C */  lui        $4, (0xFFFEFFFF >> 16)
    /* 32AE98 0042AE98 FFFF0324 */  addiu      $3, $0, -0x1
    /* 32AE9C 0042AE9C 2A186200 */  slt        $3, $3, $2
    /* 32AEA0 0042AEA0 FFFF8434 */  ori        $4, $4, (0xFFFEFFFF & 0xFFFF)
    /* 32AEA4 0042AEA4 2D108000 */  daddu      $2, $4, $0
    /* 32AEA8 0042AEA8 0B100300 */  movn       $2, $0, $3
  .L0042AEAC:
    /* 32AEAC 0042AEAC 4000BFDF */  ld         $31, 0x40($29)
    /* 32AEB0 0042AEB0 3000B2DF */  ld         $18, 0x30($29)
    /* 32AEB4 0042AEB4 2000B1DF */  ld         $17, 0x20($29)
    /* 32AEB8 0042AEB8 1000B0DF */  ld         $16, 0x10($29)
    /* 32AEBC 0042AEBC 0800E003 */  jr         $31
    /* 32AEC0 0042AEC0 5000BD27 */   addiu     $29, $29, 0x50
    /* 32AEC4 0042AEC4 00000000 */  nop
.size func_0042ade8, 0xe0
