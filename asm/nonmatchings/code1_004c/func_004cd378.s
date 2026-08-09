.section .text
.set noat
.set noreorder
glabel func_004cd378
    /* 3CD378 004CD378 7200023C */  lui        $2, %hi(D_007212D0)
    /* 3CD37C 004CD37C 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 3CD380 004CD380 D012438C */  lw         $3, %lo(D_007212D0)($2)
    /* 3CD384 004CD384 B800A5FF */  sd         $5, 0xB8($29)
    /* 3CD388 004CD388 2D288000 */  daddu      $5, $4, $0
    /* 3CD38C 004CD38C C000A6FF */  sd         $6, 0xC0($29)
    /* 3CD390 004CD390 B800A627 */  addiu      $6, $29, 0xB8
    /* 3CD394 004CD394 8000BFFF */  sd         $31, 0x80($29)
    /* 3CD398 004CD398 2D20A003 */  daddu      $4, $29, $0
    /* 3CD39C 004CD39C C800A7FF */  sd         $7, 0xC8($29)
    /* 3CD3A0 004CD3A0 D000A8FF */  sd         $8, 0xD0($29)
    /* 3CD3A4 004CD3A4 D800A9FF */  sd         $9, 0xD8($29)
    /* 3CD3A8 004CD3A8 E000AAFF */  sd         $10, 0xE0($29)
    /* 3CD3AC 004CD3AC E800ABFF */  sd         $11, 0xE8($29)
    /* 3CD3B0 004CD3B0 9800ACE7 */  swc1       $f12, 0x98($29)
    /* 3CD3B4 004CD3B4 9C00ADE7 */  swc1       $f13, 0x9C($29)
    /* 3CD3B8 004CD3B8 A000AEE7 */  swc1       $f14, 0xA0($29)
    /* 3CD3BC 004CD3BC A400AFE7 */  swc1       $f15, 0xA4($29)
    /* 3CD3C0 004CD3C0 A800B0E7 */  swc1       $f16, 0xA8($29)
    /* 3CD3C4 004CD3C4 AC00B1E7 */  swc1       $f17, 0xAC($29)
    /* 3CD3C8 004CD3C8 B000B2E7 */  swc1       $f18, 0xB0($29)
    /* 3CD3CC 004CD3CC 05006014 */  bnez       $3, .L004CD3E4
    /* 3CD3D0 004CD3D0 B400B3E7 */   swc1      $f19, 0xB4($29)
    /* 3CD3D4 004CD3D4 B61B110C */  jal        func_00446ed8
    /* 3CD3D8 004CD3D8 00000000 */   nop
    /* 3CD3DC 004CD3DC 3291100C */  jal        func_004244c8
    /* 3CD3E0 004CD3E0 2D20A003 */   daddu     $4, $29, $0
  .L004CD3E4:
    /* 3CD3E4 004CD3E4 8000BFDF */  ld         $31, 0x80($29)
    /* 3CD3E8 004CD3E8 0800E003 */  jr         $31
    /* 3CD3EC 004CD3EC F000BD27 */   addiu     $29, $29, 0xF0
.size func_004cd378, 0x78
