.section .text
.set noat
.set noreorder
glabel func_0014b080
    /* 4B080 0014B080 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4B084 0014B084 0000BFFF */  sd         $31, 0x0($29)
    /* 4B088 0014B088 05000424 */  addiu      $4, $0, 0x5
    /* 4B08C 0014B08C AC14050C */  jal        func_001452b0
    /* 4B090 0014B090 00000000 */   nop
    /* 4B094 0014B094 04004010 */  beqz       $2, .L0014B0A8
    /* 4B098 0014B098 00000000 */   nop
    /* 4B09C 0014B09C 60014224 */  addiu      $2, $2, 0x160
    /* 4B0A0 0014B0A0 02000010 */  b          .L0014B0AC
    /* 4B0A4 0014B0A4 00000000 */   nop
  .L0014B0A8:
    /* 4B0A8 0014B0A8 2D100000 */  daddu      $2, $0, $0
  .L0014B0AC:
    /* 4B0AC 0014B0AC 0000BFDF */  ld         $31, 0x0($29)
    /* 4B0B0 0014B0B0 1000BD27 */  addiu      $29, $29, 0x10
    /* 4B0B4 0014B0B4 0800E003 */  jr         $31
    /* 4B0B8 0014B0B8 00000000 */   nop
    /* 4B0BC 0014B0BC 00000000 */  nop
.size func_0014b080, 0x40
