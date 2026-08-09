.section .text
.set noat
.set noreorder
glabel func_001faa00
    /* FAA00 001FAA00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAA04 001FAA04 0000BFFF */  sd         $31, 0x0($29)
    /* FAA08 001FAA08 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAA0C 001FAA0C 800B448C */  lw         $4, 0xB80($2)
    /* FAA10 001FAA10 03008010 */  beqz       $4, .L001FAA20
    /* FAA14 001FAA14 00000000 */   nop
    /* FAA18 001FAA18 6018120C */  jal        func_00486180
    /* FAA1C 001FAA1C 00000000 */   nop
  .L001FAA20:
    /* FAA20 001FAA20 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAA24 001FAA24 880B448C */  lw         $4, 0xB88($2)
    /* FAA28 001FAA28 05008010 */  beqz       $4, .L001FAA40
    /* FAA2C 001FAA2C 00000000 */   nop
    /* FAA30 001FAA30 C883040C */  jal        func_00120f20
    /* FAA34 001FAA34 00000000 */   nop
    /* FAA38 001FAA38 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAA3C 001FAA3C 880B40AC */  sw         $0, 0xB88($2)
  .L001FAA40:
    /* FAA40 001FAA40 01000224 */  addiu      $2, $0, 0x1
    /* FAA44 001FAA44 0000BFDF */  ld         $31, 0x0($29)
    /* FAA48 001FAA48 1000BD27 */  addiu      $29, $29, 0x10
    /* FAA4C 001FAA4C 0800E003 */  jr         $31
    /* FAA50 001FAA50 00000000 */   nop
    /* FAA54 001FAA54 00000000 */  nop
    /* FAA58 001FAA58 00000000 */  nop
    /* FAA5C 001FAA5C 00000000 */  nop
.size func_001faa00, 0x60
