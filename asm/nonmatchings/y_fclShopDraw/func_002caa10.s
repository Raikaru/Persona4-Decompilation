.section .text
.set noat
.set noreorder
glabel func_002caa10
    /* 1CAA10 002CAA10 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 1CAA14 002CAA14 A000BFFF */  sd         $31, 0xA0($29)
    /* 1CAA18 002CAA18 9000BE7F */  sq         $30, 0x90($29)
    /* 1CAA1C 002CAA1C 8000B77F */  sq         $23, 0x80($29)
    /* 1CAA20 002CAA20 7000B67F */  sq         $22, 0x70($29)
    /* 1CAA24 002CAA24 6000B57F */  sq         $21, 0x60($29)
    /* 1CAA28 002CAA28 5000B47F */  sq         $20, 0x50($29)
    /* 1CAA2C 002CAA2C 4000B37F */  sq         $19, 0x40($29)
    /* 1CAA30 002CAA30 3000B27F */  sq         $18, 0x30($29)
    /* 1CAA34 002CAA34 2000B17F */  sq         $17, 0x20($29)
    /* 1CAA38 002CAA38 1000B07F */  sq         $16, 0x10($29)
    /* 1CAA3C 002CAA3C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 1CAA40 002CAA40 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1CAA44 002CAA44 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1CAA48 002CAA48 D000A4FF */  sd         $4, 0xD0($29)
    /* 1CAA4C 002CAA4C 46650046 */  mov.s      $f21, $f12
    /* 1CAA50 002CAA50 DC00A5AF */  sw         $5, 0xDC($29)
    /* 1CAA54 002CAA54 2DB8E000 */  daddu      $23, $7, $0
    /* 1CAA58 002CAA58 2D900001 */  daddu      $18, $8, $0
    /* 1CAA5C 002CAA5C 2DB02001 */  daddu      $22, $9, $0
    /* 1CAA60 002CAA60 2D88C000 */  daddu      $17, $6, $0
    /* 1CAA64 002CAA64 2D800000 */  daddu      $16, $0, $0
    /* 1CAA68 002CAA68 D000B4C7 */  lwc1       $f20, 0xD0($29)
    /* 1CAA6C 002CAA6C 3CAC1700 */  dsll32     $21, $23, 16
    /* 1CAA70 002CAA70 3FAC1500 */  dsra32     $21, $21, 16
    /* 1CAA74 002CAA74 2D204002 */  daddu      $4, $18, $0
    /* 1CAA78 002CAA78 2D28A002 */  daddu      $5, $21, $0
    /* 1CAA7C 002CAA7C 80B4110C */  jal        func_0046d200
    /* 1CAA80 002CAA80 00000000 */   nop
    /* 1CAA84 002CAA84 2DA04000 */  daddu      $20, $2, $0
    /* 1CAA88 002CAA88 2D208002 */  daddu      $4, $20, $0
    /* 1CAA8C 002CAA8C 98AC110C */  jal        func_0046b260
    /* 1CAA90 002CAA90 00000000 */   nop
    /* 1CAA94 002CAA94 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1CAA98 002CAA98 00088244 */  mtc1       $2, $f1
    /* 1CAA9C 002CAA9C 00000000 */  nop
    /* 1CAAA0 002CAAA0 01000146 */  sub.s      $f0, $f0, $f1
    /* 1CAAA4 002CAAA4 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CAAA8 002CAAA8 00000244 */  mfc1       $2, $f0
    /* 1CAAAC 002CAAAC 00000000 */  nop
    /* 1CAAB0 002CAAB0 3C9C0200 */  dsll32     $19, $2, 16
    /* 1CAAB4 002CAAB4 3F9C1300 */  dsra32     $19, $19, 16
    /* 1CAAB8 002CAAB8 2D208002 */  daddu      $4, $20, $0
    /* 1CAABC 002CAABC A0B4110C */  jal        func_0046d280
    /* 1CAAC0 002CAAC0 00000000 */   nop
    /* 1CAAC4 002CAAC4 0A00BE26 */  addiu      $30, $21, 0xA
    /* 1CAAC8 002CAAC8 2D204002 */  daddu      $4, $18, $0
    /* 1CAACC 002CAACC 2D28C003 */  daddu      $5, $30, $0
    /* 1CAAD0 002CAAD0 80B4110C */  jal        func_0046d200
    /* 1CAAD4 002CAAD4 00000000 */   nop
    /* 1CAAD8 002CAAD8 2DA04000 */  daddu      $20, $2, $0
    /* 1CAADC 002CAADC 2D208002 */  daddu      $4, $20, $0
    /* 1CAAE0 002CAAE0 98AC110C */  jal        func_0046b260
    /* 1CAAE4 002CAAE4 00000000 */   nop
    /* 1CAAE8 002CAAE8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1CAAEC 002CAAEC 00088244 */  mtc1       $2, $f1
    /* 1CAAF0 002CAAF0 00000000 */  nop
    /* 1CAAF4 002CAAF4 01000146 */  sub.s      $f0, $f0, $f1
    /* 1CAAF8 002CAAF8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1CAAFC 002CAAFC 00000244 */  mfc1       $2, $f0
    /* 1CAB00 002CAB00 00000000 */  nop
    /* 1CAB04 002CAB04 3C140200 */  dsll32     $2, $2, 16
    /* 1CAB08 002CAB08 3F140200 */  dsra32     $2, $2, 16
    /* 1CAB0C 002CAB0C C000A27F */  sq         $2, 0xC0($29)
    /* 1CAB10 002CAB10 2D208002 */  daddu      $4, $20, $0
    /* 1CAB14 002CAB14 A0B4110C */  jal        func_0046d280
    /* 1CAB18 002CAB18 00000000 */   nop
    /* 1CAB1C 002CAB1C E000A427 */  addiu      $4, $29, 0xE0
    /* 1CAB20 002CAB20 84A88527 */  addiu      $5, $28, -0x577C
    /* 1CAB24 002CAB24 0C0A110C */  jal        func_00442830
    /* 1CAB28 002CAB28 00000000 */   nop
    /* 1CAB2C 002CAB2C 40101600 */  sll        $2, $22, 1
    /* 1CAB30 002CAB30 21105600 */  addu       $2, $2, $22
    /* 1CAB34 002CAB34 00190200 */  sll        $3, $2, 4
    /* 1CAB38 002CAB38 7900023C */  lui        $2, %hi(D_00793E80)
    /* 1CAB3C 002CAB3C 803E4224 */  addiu      $2, $2, %lo(D_00793E80)
    /* 1CAB40 002CAB40 21A84300 */  addu       $21, $2, $3
    /* 1CAB44 002CAB44 3C141700 */  dsll32     $2, $23, 16
    /* 1CAB48 002CAB48 3F140200 */  dsra32     $2, $2, 16
    /* 1CAB4C 002CAB4C B000A27F */  sq         $2, 0xB0($29)
    /* 1CAB50 002CAB50 DF00B493 */  lbu        $20, 0xDF($29)
    /* 1CAB54 002CAB54 DE00B693 */  lbu        $22, 0xDE($29)
    /* 1CAB58 002CAB58 DD00B793 */  lbu        $23, 0xDD($29)
    /* 1CAB5C 002CAB5C D400B6C7 */  lwc1       $f22, 0xD4($29)
  .L002CAB60:
    /* 1CAB60 002CAB60 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CAB64 002CAB64 DC00A593 */  lbu        $5, 0xDC($29)
    /* 1CAB68 002CAB68 2D30E002 */  daddu      $6, $23, $0
    /* 1CAB6C 002CAB6C 2D38C002 */  daddu      $7, $22, $0
    /* 1CAB70 002CAB70 8CCA0A0C */  jal        func_002b2a30
    /* 1CAB74 002CAB74 00000000 */   nop
    /* 1CAB78 002CAB78 0A000324 */  addiu      $3, $0, 0xA
    /* 1CAB7C 002CAB7C 1B002302 */  divu       $0, $17, $3
    /* 1CAB80 002CAB80 10200000 */  mfhi       $4
    /* 1CAB84 002CAB84 B000A37B */  lq         $3, 0xB0($29)
    /* 1CAB88 002CAB88 21306400 */  addu       $6, $3, $4
    /* 1CAB8C 002CAB8C 06A30046 */  mov.s      $f12, $f20
    /* 1CAB90 002CAB90 46B30046 */  mov.s      $f13, $f22
    /* 1CAB94 002CAB94 86AB0046 */  mov.s      $f14, $f21
    /* 1CAB98 002CAB98 2D204000 */  daddu      $4, $2, $0
    /* 1CAB9C 002CAB9C 2D288002 */  daddu      $5, $20, $0
    /* 1CABA0 002CABA0 2D384002 */  daddu      $7, $18, $0
    /* 1CABA4 002CABA4 01000824 */  addiu      $8, $0, 0x1
    /* 1CABA8 002CABA8 2D48A002 */  daddu      $9, $21, $0
    /* 1CABAC 002CABAC 247B090C */  jal        func_0025ec90
    /* 1CABB0 002CABB0 00000000 */   nop
    /* 1CABB4 002CABB4 0A000324 */  addiu      $3, $0, 0xA
    /* 1CABB8 002CABB8 1B002302 */  divu       $0, $17, $3
    /* 1CABBC 002CABBC 12880000 */  mflo       $17
    /* 1CABC0 002CABC0 01000326 */  addiu      $3, $16, 0x1
    /* 1CABC4 002CABC4 3C860300 */  dsll32     $16, $3, 24
    /* 1CABC8 002CABC8 3F861000 */  dsra32     $16, $16, 24
    /* 1CABCC 002CABCC 03000324 */  addiu      $3, $0, 0x3
    /* 1CABD0 002CABD0 1A000302 */  div        $0, $16, $3
    /* 1CABD4 002CABD4 10180000 */  mfhi       $3
    /* 1CABD8 002CABD8 25006014 */  bnez       $3, .L002CAC70
    /* 1CABDC 002CABDC 00000000 */   nop
    /* 1CABE0 002CABE0 1D002012 */  beqz       $17, .L002CAC58
    /* 1CABE4 002CABE4 00000000 */   nop
    /* 1CABE8 002CABE8 C000A27B */  lq         $2, 0xC0($29)
    /* 1CABEC 002CABEC 00008244 */  mtc1       $2, $f0
    /* 1CABF0 002CABF0 00000000 */  nop
    /* 1CABF4 002CABF4 20008046 */  cvt.s.w    $f0, $f0
    /* 1CABF8 002CABF8 01A50046 */  sub.s      $f20, $f20, $f0
    /* 1CABFC 002CABFC FF000424 */  addiu      $4, $0, 0xFF
    /* 1CAC00 002CAC00 DC00A593 */  lbu        $5, 0xDC($29)
    /* 1CAC04 002CAC04 2D30E002 */  daddu      $6, $23, $0
    /* 1CAC08 002CAC08 2D38C002 */  daddu      $7, $22, $0
    /* 1CAC0C 002CAC0C 8CCA0A0C */  jal        func_002b2a30
    /* 1CAC10 002CAC10 00000000 */   nop
    /* 1CAC14 002CAC14 06A30046 */  mov.s      $f12, $f20
    /* 1CAC18 002CAC18 46B30046 */  mov.s      $f13, $f22
    /* 1CAC1C 002CAC1C 86AB0046 */  mov.s      $f14, $f21
    /* 1CAC20 002CAC20 2D204000 */  daddu      $4, $2, $0
    /* 1CAC24 002CAC24 2D288002 */  daddu      $5, $20, $0
    /* 1CAC28 002CAC28 2D30C003 */  daddu      $6, $30, $0
    /* 1CAC2C 002CAC2C 2D384002 */  daddu      $7, $18, $0
    /* 1CAC30 002CAC30 01000824 */  addiu      $8, $0, 0x1
    /* 1CAC34 002CAC34 2D48A002 */  daddu      $9, $21, $0
    /* 1CAC38 002CAC38 247B090C */  jal        func_0025ec90
    /* 1CAC3C 002CAC3C 00000000 */   nop
    /* 1CAC40 002CAC40 00009344 */  mtc1       $19, $f0
    /* 1CAC44 002CAC44 00000000 */  nop
    /* 1CAC48 002CAC48 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAC4C 002CAC4C 01A50046 */  sub.s      $f20, $f20, $f0
    /* 1CAC50 002CAC50 0B000010 */  b          .L002CAC80
    /* 1CAC54 002CAC54 00000000 */   nop
  .L002CAC58:
    /* 1CAC58 002CAC58 00009344 */  mtc1       $19, $f0
    /* 1CAC5C 002CAC5C 00000000 */  nop
    /* 1CAC60 002CAC60 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAC64 002CAC64 01A50046 */  sub.s      $f20, $f20, $f0
    /* 1CAC68 002CAC68 05000010 */  b          .L002CAC80
    /* 1CAC6C 002CAC6C 00000000 */   nop
  .L002CAC70:
    /* 1CAC70 002CAC70 00009344 */  mtc1       $19, $f0
    /* 1CAC74 002CAC74 00000000 */  nop
    /* 1CAC78 002CAC78 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAC7C 002CAC7C 01A50046 */  sub.s      $f20, $f20, $f0
  .L002CAC80:
    /* 1CAC80 002CAC80 B7FF2016 */  bnez       $17, .L002CAB60
    /* 1CAC84 002CAC84 00000000 */   nop
    /* 1CAC88 002CAC88 A000BFDF */  ld         $31, 0xA0($29)
    /* 1CAC8C 002CAC8C 9000BE7B */  lq         $30, 0x90($29)
    /* 1CAC90 002CAC90 8000B77B */  lq         $23, 0x80($29)
    /* 1CAC94 002CAC94 7000B67B */  lq         $22, 0x70($29)
    /* 1CAC98 002CAC98 6000B57B */  lq         $21, 0x60($29)
    /* 1CAC9C 002CAC9C 5000B47B */  lq         $20, 0x50($29)
    /* 1CACA0 002CACA0 4000B37B */  lq         $19, 0x40($29)
    /* 1CACA4 002CACA4 3000B27B */  lq         $18, 0x30($29)
    /* 1CACA8 002CACA8 2000B17B */  lq         $17, 0x20($29)
    /* 1CACAC 002CACAC 1000B07B */  lq         $16, 0x10($29)
    /* 1CACB0 002CACB0 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 1CACB4 002CACB4 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1CACB8 002CACB8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1CACBC 002CACBC F000BD27 */  addiu      $29, $29, 0xF0
    /* 1CACC0 002CACC0 0800E003 */  jr         $31
    /* 1CACC4 002CACC4 00000000 */   nop
    /* 1CACC8 002CACC8 00000000 */  nop
    /* 1CACCC 002CACCC 00000000 */  nop
.size func_002caa10, 0x2c0
