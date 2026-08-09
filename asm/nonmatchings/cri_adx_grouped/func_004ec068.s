.section .text
.set noat
.set noreorder
glabel func_004ec068
    /* 3EC068 004EC068 7400033C */  lui        $3, %hi(D_0073A748)
    /* 3EC06C 004EC06C E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EC070 004EC070 48A7628C */  lw         $2, %lo(D_0073A748)($3)
    /* 3EC074 004EC074 0000B0FF */  sd         $16, 0x0($29)
    /* 3EC078 004EC078 01001024 */  addiu      $16, $0, 0x1
    /* 3EC07C 004EC07C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EC080 004EC080 05005014 */  bne        $2, $16, .L004EC098
    /* 3EC084 004EC084 1000BFFF */   sd        $31, 0x10($29)
    /* 3EC088 004EC088 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC08C 004EC08C 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC090 004EC090 0D006058 */  blezl      $3, .L004EC0C8
    /* 3EC094 004EC094 0000B0DF */   ld        $16, 0x0($29)
  .L004EC098:
    /* 3EC098 004EC098 7400023C */  lui        $2, %hi(D_0073A770)
    /* 3EC09C 004EC09C 70A75124 */  addiu      $17, $2, %lo(D_0073A770)
    /* 3EC0A0 004EC0A0 0000238E */  lw         $3, 0x0($17)
    /* 3EC0A4 004EC0A4 07007010 */  beq        $3, $16, .L004EC0C4
    /* 3EC0A8 004EC0A8 0E000424 */   addiu     $4, $0, 0xE
    /* 3EC0AC 004EC0AC 2D280000 */  daddu      $5, $0, $0
    /* 3EC0B0 004EC0B0 2D300000 */  daddu      $6, $0, $0
    /* 3EC0B4 004EC0B4 2D380000 */  daddu      $7, $0, $0
    /* 3EC0B8 004EC0B8 2896130C */  jal        func_004e58a0
    /* 3EC0BC 004EC0BC 2D400000 */   daddu     $8, $0, $0
    /* 3EC0C0 004EC0C0 000030AE */  sw         $16, 0x0($17)
  .L004EC0C4:
    /* 3EC0C4 004EC0C4 0000B0DF */  ld         $16, 0x0($29)
  .L004EC0C8:
    /* 3EC0C8 004EC0C8 0800B1DF */  ld         $17, 0x8($29)
    /* 3EC0CC 004EC0CC 1000BFDF */  ld         $31, 0x10($29)
    /* 3EC0D0 004EC0D0 0800E003 */  jr         $31
    /* 3EC0D4 004EC0D4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ec068, 0x70
