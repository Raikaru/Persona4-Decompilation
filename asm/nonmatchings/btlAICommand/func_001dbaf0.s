.section .text
.set noat
.set noreorder
glabel func_001dbaf0
    /* DBAF0 001DBAF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DBAF4 001DBAF4 0000BFFF */  sd         $31, 0x0($29)
    /* DBAF8 001DBAF8 2D180000 */  daddu      $3, $0, $0
    /* DBAFC 001DBAFC 0100A230 */  andi       $2, $5, 0x1
    /* DBB00 001DBB00 03004010 */  beqz       $2, .L001DBB10
    /* DBB04 001DBB04 00000000 */   nop
    /* DBB08 001DBB08 0008023C */  lui        $2, (0x8000000 >> 16)
    /* DBB0C 001DBB0C 25186200 */  or         $3, $3, $2
  .L001DBB10:
    /* DBB10 001DBB10 0200A230 */  andi       $2, $5, 0x2
    /* DBB14 001DBB14 03004010 */  beqz       $2, .L001DBB24
    /* DBB18 001DBB18 00000000 */   nop
    /* DBB1C 001DBB1C 0010023C */  lui        $2, (0x10000000 >> 16)
    /* DBB20 001DBB20 25186200 */  or         $3, $3, $2
  .L001DBB24:
    /* DBB24 001DBB24 0400A230 */  andi       $2, $5, 0x4
    /* DBB28 001DBB28 03004010 */  beqz       $2, .L001DBB38
    /* DBB2C 001DBB2C 00000000 */   nop
    /* DBB30 001DBB30 0020023C */  lui        $2, (0x20000000 >> 16)
    /* DBB34 001DBB34 25186200 */  or         $3, $3, $2
  .L001DBB38:
    /* DBB38 001DBB38 0800A230 */  andi       $2, $5, 0x8
    /* DBB3C 001DBB3C 03004010 */  beqz       $2, .L001DBB4C
    /* DBB40 001DBB40 00000000 */   nop
    /* DBB44 001DBB44 0040023C */  lui        $2, (0x40000000 >> 16)
    /* DBB48 001DBB48 25186200 */  or         $3, $3, $2
  .L001DBB4C:
    /* DBB4C 001DBB4C 04006014 */  bnez       $3, .L001DBB60
    /* DBB50 001DBB50 00000000 */   nop
    /* DBB54 001DBB54 2D100000 */  daddu      $2, $0, $0
    /* DBB58 001DBB58 07000010 */  b          .L001DBB78
    /* DBB5C 001DBB5C 00000000 */   nop
  .L001DBB60:
    /* DBB60 001DBB60 3000828C */  lw         $2, 0x30($4)
    /* DBB64 001DBB64 640A448C */  lw         $4, 0xA64($2)
    /* DBB68 001DBB68 2D286000 */  daddu      $5, $3, $0
    /* DBB6C 001DBB6C 30D0080C */  jal        func_002340c0
    /* DBB70 001DBB70 00000000 */   nop
    /* DBB74 001DBB74 2B100200 */  sltu       $2, $0, $2
  .L001DBB78:
    /* DBB78 001DBB78 0000BFDF */  ld         $31, 0x0($29)
    /* DBB7C 001DBB7C 1000BD27 */  addiu      $29, $29, 0x10
    /* DBB80 001DBB80 0800E003 */  jr         $31
    /* DBB84 001DBB84 00000000 */   nop
    /* DBB88 001DBB88 00000000 */  nop
    /* DBB8C 001DBB8C 00000000 */  nop
.size func_001dbaf0, 0xa0
