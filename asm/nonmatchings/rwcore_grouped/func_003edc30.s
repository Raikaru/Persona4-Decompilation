.section .text
.set noat
.set noreorder
glabel func_003edc30
    /* 2EDC30 003EDC30 60BFBD27 */  addiu      $29, $29, -0x40A0
    /* 2EDC34 003EDC34 8000BFFF */  sd         $31, 0x80($29)
    /* 2EDC38 003EDC38 7000B77F */  sq         $23, 0x70($29)
    /* 2EDC3C 003EDC3C 6000B67F */  sq         $22, 0x60($29)
    /* 2EDC40 003EDC40 2DB8A000 */  daddu      $23, $5, $0
    /* 2EDC44 003EDC44 5000B57F */  sq         $21, 0x50($29)
    /* 2EDC48 003EDC48 2DB00001 */  daddu      $22, $8, $0
    /* 2EDC4C 003EDC4C 4000B47F */  sq         $20, 0x40($29)
    /* 2EDC50 003EDC50 2DA88000 */  daddu      $21, $4, $0
    /* 2EDC54 003EDC54 3000B37F */  sq         $19, 0x30($29)
    /* 2EDC58 003EDC58 2000B27F */  sq         $18, 0x20($29)
    /* 2EDC5C 003EDC5C 2D98E000 */  daddu      $19, $7, $0
    /* 2EDC60 003EDC60 1000B17F */  sq         $17, 0x10($29)
    /* 2EDC64 003EDC64 0000B07F */  sq         $16, 0x0($29)
    /* 2EDC68 003EDC68 0000C78C */  lw         $7, 0x0($6)
    /* 2EDC6C 003EDC6C 1800E58C */  lw         $5, 0x18($7)
    /* 2EDC70 003EDC70 3000A010 */  beqz       $5, .L003EDD34
    /* 2EDC74 003EDC74 2DA0C000 */   daddu     $20, $6, $0
    /* 2EDC78 003EDC78 0200612A */  slti       $1, $19, 0x2
    /* 2EDC7C 003EDC7C 21002014 */  bnez       $1, .L003EDD04
    /* 2EDC80 003EDC80 01000B24 */   addiu     $11, $0, 0x1
    /* 2EDC84 003EDC84 0430CB02 */  sllv       $6, $11, $22
    /* 2EDC88 003EDC88 40000324 */  addiu      $3, $0, 0x40
  .L003EDC8C:
    /* 2EDC8C 003EDC8C 80100B00 */  sll        $2, $11, 2
    /* 2EDC90 003EDC90 21108202 */  addu       $2, $20, $2
    /* 2EDC94 003EDC94 0000428C */  lw         $2, 0x0($2)
    /* 2EDC98 003EDC98 1900A010 */  beqz       $5, .L003EDD00
    /* 2EDC9C 003EDC9C 1800498C */   lw        $9, 0x18($2)
    /* 2EDCA0 003EDCA0 17002011 */  beqz       $9, .L003EDD00
    /* 2EDCA4 003EDCA4 00000000 */   nop
    /* 2EDCA8 003EDCA8 2A080600 */  slt        $1, $0, $6
    /* 2EDCAC 003EDCAC 0E002010 */  beqz       $1, .L003EDCE8
    /* 2EDCB0 003EDCB0 2D500000 */   daddu     $10, $0, $0
    /* 2EDCB4 003EDCB4 2D40A000 */  daddu      $8, $5, $0
  .L003EDCB8:
    /* 2EDCB8 003EDCB8 0000048D */  lw         $4, 0x0($8)
    /* 2EDCBC 003EDCBC 0000228D */  lw         $2, 0x0($9)
    /* 2EDCC0 003EDCC0 03008210 */  beq        $4, $2, .L003EDCD0
    /* 2EDCC4 003EDCC4 00000000 */   nop
    /* 2EDCC8 003EDCC8 07000010 */  b          .L003EDCE8
    /* 2EDCCC 003EDCCC 2D586000 */   daddu     $11, $3, $0
  .L003EDCD0:
    /* 2EDCD0 003EDCD0 01004A25 */  addiu      $10, $10, 0x1
    /* 2EDCD4 003EDCD4 2A104601 */  slt        $2, $10, $6
    /* 2EDCD8 003EDCD8 04002925 */  addiu      $9, $9, 0x4
    /* 2EDCDC 003EDCDC F6FF4014 */  bnez       $2, .L003EDCB8
    /* 2EDCE0 003EDCE0 04000825 */   addiu     $8, $8, 0x4
    /* 2EDCE4 003EDCE4 00000000 */  nop
  .L003EDCE8:
    /* 2EDCE8 003EDCE8 01006B25 */  addiu      $11, $11, 0x1
    /* 2EDCEC 003EDCEC 2A107301 */  slt        $2, $11, $19
    /* 2EDCF0 003EDCF0 E6FF4014 */  bnez       $2, .L003EDC8C
    /* 2EDCF4 003EDCF4 00000000 */   nop
    /* 2EDCF8 003EDCF8 02000010 */  b          .L003EDD04
    /* 2EDCFC 003EDCFC 00000000 */   nop
  .L003EDD00:
    /* 2EDD00 003EDD00 40000B24 */  addiu      $11, $0, 0x40
  .L003EDD04:
    /* 2EDD04 003EDD04 0B007315 */  bne        $11, $19, .L003EDD34
    /* 2EDD08 003EDD08 00000000 */   nop
    /* 2EDD0C 003EDD0C 0C00E28C */  lw         $2, 0xC($7)
    /* 2EDD10 003EDD10 01000324 */  addiu      $3, $0, 0x1
    /* 2EDD14 003EDD14 2D20A002 */  daddu      $4, $21, $0
    /* 2EDD18 003EDD18 14104300 */  dsllv      $2, $3, $2
    /* 2EDD1C 003EDD1C B8100200 */  dsll       $2, $2, 2
    /* 2EDD20 003EDD20 3C300200 */  dsll32     $6, $2, 0
    /* 2EDD24 003EDD24 04FE100C */  jal        func_0043f810
    /* 2EDD28 003EDD28 3F300600 */   dsra32    $6, $6, 0
    /* 2EDD2C 003EDD2C 3D000010 */  b          .L003EDE24
    /* 2EDD30 003EDD30 01000224 */   addiu     $2, $0, 0x1
  .L003EDD34:
    /* 2EDD34 003EDD34 28C90F0C */  jal        func_003f24a0
    /* 2EDD38 003EDD38 9000A427 */   addiu     $4, $29, 0x90
    /* 2EDD3C 003EDD3C 10004010 */  beqz       $2, .L003EDD80
    /* 2EDD40 003EDD40 00000000 */   nop
    /* 2EDD44 003EDD44 2A081300 */  slt        $1, $0, $19
    /* 2EDD48 003EDD48 0F002010 */  beqz       $1, .L003EDD88
    /* 2EDD4C 003EDD4C 2D800000 */   daddu     $16, $0, $0
    /* 2EDD50 003EDD50 2D888002 */  daddu      $17, $20, $0
  .L003EDD54:
    /* 2EDD54 003EDD54 0000258E */  lw         $5, 0x0($17)
    /* 2EDD58 003EDD58 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 2EDD5C 003EDD5C 00608244 */  mtc1       $2, $f12
    /* 2EDD60 003EDD60 F4C10F0C */  jal        func_003f07d0
    /* 2EDD64 003EDD64 9000A427 */   addiu     $4, $29, 0x90
    /* 2EDD68 003EDD68 01001026 */  addiu      $16, $16, 0x1
    /* 2EDD6C 003EDD6C 2A101302 */  slt        $2, $16, $19
    /* 2EDD70 003EDD70 F8FF4014 */  bnez       $2, .L003EDD54
    /* 2EDD74 003EDD74 04003126 */   addiu     $17, $17, 0x4
    /* 2EDD78 003EDD78 04000010 */  b          .L003EDD8C
    /* 2EDD7C 003EDD7C 01000224 */   addiu     $2, $0, 0x1
  .L003EDD80:
    /* 2EDD80 003EDD80 28000010 */  b          .L003EDE24
    /* 2EDD84 003EDD84 2D100000 */   daddu     $2, $0, $0
  .L003EDD88:
    /* 2EDD88 003EDD88 01000224 */  addiu      $2, $0, 0x1
  .L003EDD8C:
    /* 2EDD8C 003EDD8C 2D20A002 */  daddu      $4, $21, $0
    /* 2EDD90 003EDD90 0428C202 */  sllv       $5, $2, $22
    /* 2EDD94 003EDD94 F8C50F0C */  jal        func_003f17e0
    /* 2EDD98 003EDD98 9000A627 */   addiu     $6, $29, 0x90
    /* 2EDD9C 003EDD9C 2A081300 */  slt        $1, $0, $19
    /* 2EDDA0 003EDDA0 1B002010 */  beqz       $1, .L003EDE10
    /* 2EDDA4 003EDDA4 2D880000 */   daddu     $17, $0, $0
  .L003EDDA8:
    /* 2EDDA8 003EDDA8 0000908E */  lw         $16, 0x0($20)
    /* 2EDDAC 003EDDAC 0400048E */  lw         $4, 0x4($16)
    /* 2EDDB0 003EDDB0 0800058E */  lw         $5, 0x8($16)
    /* 2EDDB4 003EDDB4 B0A80F0C */  jal        func_003ea2c0
    /* 2EDDB8 003EDDB8 2D30C002 */   daddu     $6, $22, $0
    /* 2EDDBC 003EDDBC 2D904000 */  daddu      $18, $2, $0
    /* 2EDDC0 003EDDC0 17004012 */  beqz       $18, .L003EDE20
    /* 2EDDC4 003EDDC4 00000000 */   nop
    /* 2EDDC8 003EDDC8 F8A80F0C */  jal        func_003ea3e0
    /* 2EDDCC 003EDDCC 2D204002 */   daddu     $4, $18, $0
    /* 2EDDD0 003EDDD0 1400448E */  lw         $4, 0x14($18)
    /* 2EDDD4 003EDDD4 2D380000 */  daddu      $7, $0, $0
    /* 2EDDD8 003EDDD8 1000458E */  lw         $5, 0x10($18)
    /* 2EDDDC 003EDDDC 9000A827 */  addiu      $8, $29, 0x90
    /* 2EDDE0 003EDDE0 0C00468E */  lw         $6, 0xC($18)
    /* 2EDDE4 003EDDE4 38C70F0C */  jal        func_003f1ce0
    /* 2EDDE8 003EDDE8 2D480002 */   daddu     $9, $16, $0
    /* 2EDDEC 003EDDEC 180055AE */  sw         $21, 0x18($18)
    /* 2EDDF0 003EDDF0 03001712 */  beq        $16, $23, .L003EDE00
    /* 2EDDF4 003EDDF4 000092AE */   sw        $18, 0x0($20)
    /* 2EDDF8 003EDDF8 DCA80F0C */  jal        func_003ea370
    /* 2EDDFC 003EDDFC 2D200002 */   daddu     $4, $16, $0
  .L003EDE00:
    /* 2EDE00 003EDE00 01003126 */  addiu      $17, $17, 0x1
    /* 2EDE04 003EDE04 2A103302 */  slt        $2, $17, $19
    /* 2EDE08 003EDE08 E7FF4014 */  bnez       $2, .L003EDDA8
    /* 2EDE0C 003EDE0C 04009426 */   addiu     $20, $20, 0x4
  .L003EDE10:
    /* 2EDE10 003EDE10 B0C90F0C */  jal        func_003f26c0
    /* 2EDE14 003EDE14 9000A427 */   addiu     $4, $29, 0x90
    /* 2EDE18 003EDE18 02000010 */  b          .L003EDE24
    /* 2EDE1C 003EDE1C 01000224 */   addiu     $2, $0, 0x1
  .L003EDE20:
    /* 2EDE20 003EDE20 2D100000 */  daddu      $2, $0, $0
  .L003EDE24:
    /* 2EDE24 003EDE24 8000BFDF */  ld         $31, 0x80($29)
    /* 2EDE28 003EDE28 7000B77B */  lq         $23, 0x70($29)
    /* 2EDE2C 003EDE2C 6000B67B */  lq         $22, 0x60($29)
    /* 2EDE30 003EDE30 5000B57B */  lq         $21, 0x50($29)
    /* 2EDE34 003EDE34 4000B47B */  lq         $20, 0x40($29)
    /* 2EDE38 003EDE38 3000B37B */  lq         $19, 0x30($29)
    /* 2EDE3C 003EDE3C 2000B27B */  lq         $18, 0x20($29)
    /* 2EDE40 003EDE40 1000B17B */  lq         $17, 0x10($29)
    /* 2EDE44 003EDE44 0000B07B */  lq         $16, 0x0($29)
    /* 2EDE48 003EDE48 0800E003 */  jr         $31
    /* 2EDE4C 003EDE4C A040BD27 */   addiu     $29, $29, 0x40A0
.size func_003edc30, 0x220
