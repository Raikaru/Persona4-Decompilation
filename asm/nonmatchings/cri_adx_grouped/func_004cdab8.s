.section .text
.set noat
.set noreorder
glabel func_004cdab8
    /* 3CDAB8 004CDAB8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3CDABC 004CDABC 7200073C */  lui        $7, %hi(D_007212E8)
    /* 3CDAC0 004CDAC0 1800B3FF */  sd         $19, 0x18($29)
    /* 3CDAC4 004CDAC4 2D98A000 */  daddu      $19, $5, $0
    /* 3CDAC8 004CDAC8 2000B4FF */  sd         $20, 0x20($29)
    /* 3CDACC 004CDACC 2DA0C000 */  daddu      $20, $6, $0
    /* 3CDAD0 004CDAD0 2800B5FF */  sd         $21, 0x28($29)
    /* 3CDAD4 004CDAD4 2DA88000 */  daddu      $21, $4, $0
    /* 3CDAD8 004CDAD8 0000B0FF */  sd         $16, 0x0($29)
    /* 3CDADC 004CDADC E812E324 */  addiu      $3, $7, %lo(D_007212E8)
    /* 3CDAE0 004CDAE0 0800B1FF */  sd         $17, 0x8($29)
    /* 3CDAE4 004CDAE4 2D280000 */  daddu      $5, $0, $0
    /* 3CDAE8 004CDAE8 1000B2FF */  sd         $18, 0x10($29)
    /* 3CDAEC 004CDAEC 3000BFFF */  sd         $31, 0x30($29)
    /* 3CDAF0 004CDAF0 00006280 */  lb         $2, 0x0($3)
    /* 3CDAF4 004CDAF4 0B004010 */  beqz       $2, .L004CDB24
    /* 3CDAF8 004CDAF8 0000908E */   lw        $16, 0x0($20)
    /* 3CDAFC 004CDAFC 0100A524 */  addiu      $5, $5, 0x1
  .L004CDB00:
    /* 3CDB00 004CDB00 1000A228 */  slti       $2, $5, 0x10
    /* 3CDB04 004CDB04 07004010 */  beqz       $2, .L004CDB24
    /* 3CDB08 004CDB08 A8006324 */   addiu     $3, $3, 0xA8
    /* 3CDB0C 004CDB0C 00006280 */  lb         $2, 0x0($3)
    /* 3CDB10 004CDB10 00000000 */  nop
    /* 3CDB14 004CDB14 00000000 */  nop
    /* 3CDB18 004CDB18 00000000 */  nop
    /* 3CDB1C 004CDB1C F8FF4054 */  bnel       $2, $0, .L004CDB00
    /* 3CDB20 004CDB20 0100A524 */   addiu     $5, $5, 0x1
  .L004CDB24:
    /* 3CDB24 004CDB24 10000324 */  addiu      $3, $0, 0x10
    /* 3CDB28 004CDB28 3900A310 */  beq        $5, $3, .L004CDC10
    /* 3CDB2C 004CDB2C 2D100000 */   daddu     $2, $0, $0
    /* 3CDB30 004CDB30 80100500 */  sll        $2, $5, 2
    /* 3CDB34 004CDB34 E812E324 */  addiu      $3, $7, %lo(D_007212E8)
    /* 3CDB38 004CDB38 21104500 */  addu       $2, $2, $5
    /* 3CDB3C 004CDB3C 2D200002 */  daddu      $4, $16, $0
    /* 3CDB40 004CDB40 80100200 */  sll        $2, $2, 2
    /* 3CDB44 004CDB44 21104500 */  addu       $2, $2, $5
    /* 3CDB48 004CDB48 C0100200 */  sll        $2, $2, 3
    /* 3CDB4C 004CDB4C 9CBA130C */  jal        func_004eea70
    /* 3CDB50 004CDB50 21904300 */   addu      $18, $2, $3
    /* 3CDB54 004CDB54 2D200002 */  daddu      $4, $16, $0
    /* 3CDB58 004CDB58 9EBA130C */  jal        func_004eea78
    /* 3CDB5C 004CDB5C 2D884000 */   daddu     $17, $2, $0
    /* 3CDB60 004CDB60 2D200002 */  daddu      $4, $16, $0
    /* 3CDB64 004CDB64 C2870200 */  srl        $16, $2, 31
    /* 3CDB68 004CDB68 A0BA130C */  jal        func_004eea80
    /* 3CDB6C 004CDB6C 21800202 */   addu      $16, $16, $2
    /* 3CDB70 004CDB70 C23F0200 */  srl        $7, $2, 31
    /* 3CDB74 004CDB74 43801000 */  sra        $16, $16, 1
    /* 3CDB78 004CDB78 2138E200 */  addu       $7, $7, $2
    /* 3CDB7C 004CDB7C 2D300002 */  daddu      $6, $16, $0
    /* 3CDB80 004CDB80 43380700 */  sra        $7, $7, 1
    /* 3CDB84 004CDB84 2D206002 */  daddu      $4, $19, $0
    /* 3CDB88 004CDB88 2D282002 */  daddu      $5, $17, $0
    /* 3CDB8C 004CDB8C 480D130C */  jal        func_004c3520
    /* 3CDB90 004CDB90 2138C700 */   addu      $7, $6, $7
    /* 3CDB94 004CDB94 2D204000 */  daddu      $4, $2, $0
    /* 3CDB98 004CDB98 1D008010 */  beqz       $4, .L004CDC10
    /* 3CDB9C 004CDB9C 040044AE */   sw        $4, 0x4($18)
    /* 3CDBA0 004CDBA0 4D00053C */  lui        $5, %hi(func_004ce0c8)
    /* 3CDBA4 004CDBA4 2D304002 */  daddu      $6, $18, $0
    /* 3CDBA8 004CDBA8 E60E130C */  jal        func_004c3b98
    /* 3CDBAC 004CDBAC C8E0A524 */   addiu     $5, $5, %lo(func_004ce0c8)
    /* 3CDBB0 004CDBB0 080055AE */  sw         $21, 0x8($18)
    /* 3CDBB4 004CDBB4 020053A2 */  sb         $19, 0x2($18)
    /* 3CDBB8 004CDBB8 0B00601A */  blez       $19, .L004CDBE8
    /* 3CDBBC 004CDBBC 2D300000 */   daddu     $6, $0, $0
    /* 3CDBC0 004CDBC0 0C004726 */  addiu      $7, $18, 0xC
    /* 3CDBC4 004CDBC4 00000000 */  nop
  .L004CDBC8:
    /* 3CDBC8 004CDBC8 80100600 */  sll        $2, $6, 2
    /* 3CDBCC 004CDBCC 0100C624 */  addiu      $6, $6, 0x1
    /* 3CDBD0 004CDBD0 21185400 */  addu       $3, $2, $20
    /* 3CDBD4 004CDBD4 2110E200 */  addu       $2, $7, $2
    /* 3CDBD8 004CDBD8 0000648C */  lw         $4, 0x0($3)
    /* 3CDBDC 004CDBDC 2A28D300 */  slt        $5, $6, $19
    /* 3CDBE0 004CDBE0 F9FFA014 */  bnez       $5, .L004CDBC8
    /* 3CDBE4 004CDBE4 000044AC */   sw        $4, 0x0($2)
  .L004CDBE8:
    /* 3CDBE8 004CDBE8 010040A2 */  sb         $0, 0x1($18)
    /* 3CDBEC 004CDBEC 9E36130C */  jal        func_004cda78
    /* 3CDBF0 004CDBF0 2D204002 */   daddu     $4, $18, $0
    /* 3CDBF4 004CDBF4 480040AE */  sw         $0, 0x48($18)
    /* 3CDBF8 004CDBF8 01000224 */  addiu      $2, $0, 0x1
    /* 3CDBFC 004CDBFC 4C0040AE */  sw         $0, 0x4C($18)
    /* 3CDC00 004CDC00 500040AE */  sw         $0, 0x50($18)
    /* 3CDC04 004CDC04 540040AE */  sw         $0, 0x54($18)
    /* 3CDC08 004CDC08 000042A2 */  sb         $2, 0x0($18)
    /* 3CDC0C 004CDC0C 2D104002 */  daddu      $2, $18, $0
  .L004CDC10:
    /* 3CDC10 004CDC10 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDC14 004CDC14 0800B1DF */  ld         $17, 0x8($29)
    /* 3CDC18 004CDC18 1000B2DF */  ld         $18, 0x10($29)
    /* 3CDC1C 004CDC1C 1800B3DF */  ld         $19, 0x18($29)
    /* 3CDC20 004CDC20 2000B4DF */  ld         $20, 0x20($29)
    /* 3CDC24 004CDC24 2800B5DF */  ld         $21, 0x28($29)
    /* 3CDC28 004CDC28 3000BFDF */  ld         $31, 0x30($29)
    /* 3CDC2C 004CDC2C 0800E003 */  jr         $31
    /* 3CDC30 004CDC30 4000BD27 */   addiu     $29, $29, 0x40
    /* 3CDC34 004CDC34 00000000 */  nop
.size func_004cdab8, 0x180
