.section .text
.set noat
.set noreorder
glabel func_004ab960
    /* 3AB960 004AB960 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3AB964 004AB964 3000BFFF */  sd         $31, 0x30($29)
    /* 3AB968 004AB968 2000B27F */  sq         $18, 0x20($29)
    /* 3AB96C 004AB96C 1000B17F */  sq         $17, 0x10($29)
    /* 3AB970 004AB970 0000B07F */  sq         $16, 0x0($29)
    /* 3AB974 004AB974 2D808000 */  daddu      $16, $4, $0
    /* 3AB978 004AB978 2D90A000 */  daddu      $18, $5, $0
    /* 3AB97C 004AB97C 7100043C */  lui        $4, %hi(D_00714450)
    /* 3AB980 004AB980 50448424 */  addiu      $4, $4, %lo(D_00714450)
    /* 3AB984 004AB984 71010524 */  addiu      $5, $0, 0x171
    /* 3AB988 004AB988 A43A110C */  jal        func_0044ea90
    /* 3AB98C 004AB98C 00000000 */   nop
    /* 3AB990 004AB990 0C000424 */  addiu      $4, $0, 0xC
    /* 3AB994 004AB994 0400053C */  lui        $5, (0x40000 >> 16)
    /* 3AB998 004AB998 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 3AB99C 004AB99C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 3AB9A0 004AB9A0 09F84000 */  jalr       $2
    /* 3AB9A4 004AB9A4 00000000 */   nop
    /* 3AB9A8 004AB9A8 2D884000 */  daddu      $17, $2, $0
    /* 3AB9AC 004AB9AC 2D202002 */  daddu      $4, $17, $0
    /* 3AB9B0 004AB9B0 2D280000 */  daddu      $5, $0, $0
    /* 3AB9B4 004AB9B4 0C000624 */  addiu      $6, $0, 0xC
    /* 3AB9B8 004AB9B8 72FE100C */  jal        func_0043f9c8
    /* 3AB9BC 004AB9BC 00000000 */   nop
    /* 3AB9C0 004AB9C0 06002016 */  bnez       $17, .L004AB9DC
    /* 3AB9C4 004AB9C4 00000000 */   nop
    /* 3AB9C8 004AB9C8 7100043C */  lui        $4, %hi(D_00714380)
    /* 3AB9CC 004AB9CC 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3AB9D0 004AB9D0 B0070524 */  addiu      $5, $0, 0x7B0
    /* 3AB9D4 004AB9D4 CCB5110C */  jal        func_0046d730
    /* 3AB9D8 004AB9D8 00000000 */   nop
  .L004AB9DC:
    /* 3AB9DC 004AB9DC FFFF4432 */  andi       $4, $18, 0xFFFF
    /* 3AB9E0 004AB9E0 000024AE */  sw         $4, 0x0($17)
    /* 3AB9E4 004AB9E4 01000324 */  addiu      $3, $0, 0x1
    /* 3AB9E8 004AB9E8 040023AE */  sw         $3, 0x4($17)
    /* 3AB9EC 004AB9EC 04000224 */  addiu      $2, $0, 0x4
    /* 3AB9F0 004AB9F0 0B008210 */  beq        $4, $2, .L004ABA20
    /* 3AB9F4 004AB9F4 00000000 */   nop
    /* 3AB9F8 004AB9F8 03008310 */  beq        $4, $3, .L004ABA08
    /* 3AB9FC 004AB9FC 00000000 */   nop
    /* 3ABA00 004ABA00 0D000010 */  b          .L004ABA38
    /* 3ABA04 004ABA04 00000000 */   nop
  .L004ABA08:
    /* 3ABA08 004ABA08 2D200002 */  daddu      $4, $16, $0
    /* 3ABA0C 004ABA0C E404120C */  jal        func_00481390
    /* 3ABA10 004ABA10 00000000 */   nop
    /* 3ABA14 004ABA14 080022AE */  sw         $2, 0x8($17)
    /* 3ABA18 004ABA18 0C000010 */  b          .L004ABA4C
    /* 3ABA1C 004ABA1C 00000000 */   nop
  .L004ABA20:
    /* 3ABA20 004ABA20 00000496 */  lhu        $4, 0x0($16)
    /* 3ABA24 004ABA24 C004120C */  jal        func_00481300
    /* 3ABA28 004ABA28 00000000 */   nop
    /* 3ABA2C 004ABA2C 080022AE */  sw         $2, 0x8($17)
    /* 3ABA30 004ABA30 06000010 */  b          .L004ABA4C
    /* 3ABA34 004ABA34 00000000 */   nop
  .L004ABA38:
    /* 3ABA38 004ABA38 7100043C */  lui        $4, %hi(D_00714380)
    /* 3ABA3C 004ABA3C 80438424 */  addiu      $4, $4, %lo(D_00714380)
    /* 3ABA40 004ABA40 BC070524 */  addiu      $5, $0, 0x7BC
    /* 3ABA44 004ABA44 CCB5110C */  jal        func_0046d730
    /* 3ABA48 004ABA48 00000000 */   nop
  .L004ABA4C:
    /* 3ABA4C 004ABA4C 2D102002 */  daddu      $2, $17, $0
    /* 3ABA50 004ABA50 3000BFDF */  ld         $31, 0x30($29)
    /* 3ABA54 004ABA54 2000B27B */  lq         $18, 0x20($29)
    /* 3ABA58 004ABA58 1000B17B */  lq         $17, 0x10($29)
    /* 3ABA5C 004ABA5C 0000B07B */  lq         $16, 0x0($29)
    /* 3ABA60 004ABA60 4000BD27 */  addiu      $29, $29, 0x40
    /* 3ABA64 004ABA64 0800E003 */  jr         $31
    /* 3ABA68 004ABA68 00000000 */   nop
    /* 3ABA6C 004ABA6C 00000000 */  nop
.size func_004ab960, 0x110
