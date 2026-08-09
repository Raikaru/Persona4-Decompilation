.section .text
.set noat
.set noreorder
glabel func_004be9c0
    /* 3BE9C0 004BE9C0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BE9C4 004BE9C4 01000324 */  addiu      $3, $0, 0x1
    /* 3BE9C8 004BE9C8 0800B1FF */  sd         $17, 0x8($29)
    /* 3BE9CC 004BE9CC 2D888000 */  daddu      $17, $4, $0
    /* 3BE9D0 004BE9D0 0000B0FF */  sd         $16, 0x0($29)
    /* 3BE9D4 004BE9D4 1000B2FF */  sd         $18, 0x10($29)
    /* 3BE9D8 004BE9D8 1800B3FF */  sd         $19, 0x18($29)
    /* 3BE9DC 004BE9DC 2000BFFF */  sd         $31, 0x20($29)
    /* 3BE9E0 004BE9E0 5000228E */  lw         $2, 0x50($17)
    /* 3BE9E4 004BE9E4 05004350 */  beql       $2, $3, .L004BE9FC
    /* 3BE9E8 004BE9E8 A000228E */   lw        $2, 0xA0($17)
    /* 3BE9EC 004BE9EC 5400228E */  lw         $2, 0x54($17)
    /* 3BE9F0 004BE9F0 23004314 */  bne        $2, $3, .L004BEA80
    /* 3BE9F4 004BE9F4 0000B0DF */   ld        $16, 0x0($29)
    /* 3BE9F8 004BE9F8 A000228E */  lw         $2, 0xA0($17)
  .L004BE9FC:
    /* 3BE9FC 004BE9FC 2D980000 */  daddu      $19, $0, $0
    /* 3BEA00 004BEA00 500020AE */  sw         $0, 0x50($17)
    /* 3BEA04 004BEA04 1D004018 */  blez       $2, .L004BEA7C
    /* 3BEA08 004BEA08 540020AE */   sw        $0, 0x54($17)
    /* 3BEA0C 004BEA0C 2D802002 */  daddu      $16, $17, $0
    /* 3BEA10 004BEA10 20003226 */  addiu      $18, $17, 0x20
    /* 3BEA14 004BEA14 00000000 */  nop
  .L004BEA18:
    /* 3BEA18 004BEA18 0000448E */  lw         $4, 0x0($18)
    /* 3BEA1C 004BEA1C C8F5120C */  jal        func_004bd720
    /* 3BEA20 004BEA20 0C005226 */   addiu     $18, $18, 0xC
    /* 3BEA24 004BEA24 0000028E */  lw         $2, 0x0($16)
    /* 3BEA28 004BEA28 0F004010 */  beqz       $2, .L004BEA68
    /* 3BEA2C 004BEA2C 2D204000 */   daddu     $4, $2, $0
    /* 3BEA30 004BEA30 0000428C */  lw         $2, 0x0($2)
    /* 3BEA34 004BEA34 0400438C */  lw         $3, 0x4($2)
    /* 3BEA38 004BEA38 09F86000 */  jalr       $3
    /* 3BEA3C 004BEA3C 00000000 */   nop
    /* 3BEA40 004BEA40 9400228E */  lw         $2, 0x94($17)
    /* 3BEA44 004BEA44 06004010 */  beqz       $2, .L004BEA60
    /* 3BEA48 004BEA48 00000000 */   nop
    /* 3BEA4C 004BEA4C 54F8120C */  jal        func_004be150
    /* 3BEA50 004BEA50 0000048E */   lw        $4, 0x0($16)
    /* 3BEA54 004BEA54 05000010 */  b          .L004BEA6C
    /* 3BEA58 004BEA58 A000228E */   lw        $2, 0xA0($17)
    /* 3BEA5C 004BEA5C 00000000 */  nop
  .L004BEA60:
    /* 3BEA60 004BEA60 84F7120C */  jal        func_004bde10
    /* 3BEA64 004BEA64 0000048E */   lw        $4, 0x0($16)
  .L004BEA68:
    /* 3BEA68 004BEA68 A000228E */  lw         $2, 0xA0($17)
  .L004BEA6C:
    /* 3BEA6C 004BEA6C 01007326 */  addiu      $19, $19, 0x1
    /* 3BEA70 004BEA70 2A106202 */  slt        $2, $19, $2
    /* 3BEA74 004BEA74 E8FF4014 */  bnez       $2, .L004BEA18
    /* 3BEA78 004BEA78 04001026 */   addiu     $16, $16, 0x4
  .L004BEA7C:
    /* 3BEA7C 004BEA7C 0000B0DF */  ld         $16, 0x0($29)
  .L004BEA80:
    /* 3BEA80 004BEA80 0800B1DF */  ld         $17, 0x8($29)
    /* 3BEA84 004BEA84 1000B2DF */  ld         $18, 0x10($29)
    /* 3BEA88 004BEA88 1800B3DF */  ld         $19, 0x18($29)
    /* 3BEA8C 004BEA8C 2000BFDF */  ld         $31, 0x20($29)
    /* 3BEA90 004BEA90 0800E003 */  jr         $31
    /* 3BEA94 004BEA94 3000BD27 */   addiu     $29, $29, 0x30
.size func_004be9c0, 0xd8
