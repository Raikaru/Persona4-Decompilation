.section .text
.set noat
.set noreorder
glabel func_001ef9c0
    /* EF9C0 001EF9C0 20FFBD27 */  addiu      $29, $29, -0xE0
    /* EF9C4 001EF9C4 9000BFFF */  sd         $31, 0x90($29)
    /* EF9C8 001EF9C8 8000BE7F */  sq         $30, 0x80($29)
    /* EF9CC 001EF9CC 7000B77F */  sq         $23, 0x70($29)
    /* EF9D0 001EF9D0 6000B67F */  sq         $22, 0x60($29)
    /* EF9D4 001EF9D4 5000B57F */  sq         $21, 0x50($29)
    /* EF9D8 001EF9D8 4000B47F */  sq         $20, 0x40($29)
    /* EF9DC 001EF9DC 3000B37F */  sq         $19, 0x30($29)
    /* EF9E0 001EF9E0 2000B27F */  sq         $18, 0x20($29)
    /* EF9E4 001EF9E4 1000B17F */  sq         $17, 0x10($29)
    /* EF9E8 001EF9E8 0000B07F */  sq         $16, 0x0($29)
    /* EF9EC 001EF9EC 2DA08000 */  daddu      $20, $4, $0
    /* EF9F0 001EF9F0 FFFF0224 */  addiu      $2, $0, -0x1
    /* EF9F4 001EF9F4 480482A4 */  sh         $2, 0x448($4)
    /* EF9F8 001EF9F8 440480AC */  sw         $0, 0x444($4)
    /* EF9FC 001EF9FC 3000848C */  lw         $4, 0x30($4)
    /* EFA00 001EFA00 A2008290 */  lbu        $2, 0xA2($4)
    /* EFA04 001EFA04 04004010 */  beqz       $2, .L001EFA18
    /* EFA08 001EFA08 00000000 */   nop
    /* EFA0C 001EFA0C 2D100000 */  daddu      $2, $0, $0
    /* EFA10 001EFA10 C0000010 */  b          .L001EFD14
    /* EFA14 001EFA14 00000000 */   nop
  .L001EFA18:
    /* EFA18 001EFA18 A4008394 */  lhu        $3, 0xA4($4)
    /* EFA1C 001EFA1C 01000224 */  addiu      $2, $0, 0x1
    /* EFA20 001EFA20 04006214 */  bne        $3, $2, .L001EFA34
    /* EFA24 001EFA24 00000000 */   nop
    /* EFA28 001EFA28 2D100000 */  daddu      $2, $0, $0
    /* EFA2C 001EFA2C B9000010 */  b          .L001EFD14
    /* EFA30 001EFA30 00000000 */   nop
  .L001EFA34:
    /* EFA34 001EFA34 640A848C */  lw         $4, 0xA64($4)
    /* EFA38 001EFA38 1000023C */  lui        $2, (0x1001FF >> 16)
    /* EFA3C 001EFA3C FF014534 */  ori        $5, $2, (0x1001FF & 0xFFFF)
    /* EFA40 001EFA40 C4C9080C */  jal        func_00232710
    /* EFA44 001EFA44 00000000 */   nop
    /* EFA48 001EFA48 04004010 */  beqz       $2, .L001EFA5C
    /* EFA4C 001EFA4C 00000000 */   nop
    /* EFA50 001EFA50 2D100000 */  daddu      $2, $0, $0
    /* EFA54 001EFA54 AF000010 */  b          .L001EFD14
    /* EFA58 001EFA58 00000000 */   nop
  .L001EFA5C:
    /* EFA5C 001EFA5C ACB3828F */  lw         $2, -0x4C54($28)
    /* EFA60 001EFA60 0C00428C */  lw         $2, 0xC($2)
    /* EFA64 001EFA64 00104230 */  andi       $2, $2, 0x1000
    /* EFA68 001EFA68 05004014 */  bnez       $2, .L001EFA80
    /* EFA6C 001EFA6C 00000000 */   nop
    /* EFA70 001EFA70 14008396 */  lhu        $3, 0x14($20)
    /* EFA74 001EFA74 09000224 */  addiu      $2, $0, 0x9
    /* EFA78 001EFA78 04006214 */  bne        $3, $2, .L001EFA8C
    /* EFA7C 001EFA7C 00000000 */   nop
  .L001EFA80:
    /* EFA80 001EFA80 2D100000 */  daddu      $2, $0, $0
    /* EFA84 001EFA84 A3000010 */  b          .L001EFD14
    /* EFA88 001EFA88 00000000 */   nop
  .L001EFA8C:
    /* EFA8C 001EFA8C 3000828E */  lw         $2, 0x30($20)
    /* EFA90 001EFA90 640A448C */  lw         $4, 0xA64($2)
    /* EFA94 001EFA94 8C0F090C */  jal        func_00243e30
    /* EFA98 001EFA98 00000000 */   nop
    /* EFA9C 001EFA9C 04004010 */  beqz       $2, .L001EFAB0
    /* EFAA0 001EFAA0 00000000 */   nop
    /* EFAA4 001EFAA4 2D100000 */  daddu      $2, $0, $0
    /* EFAA8 001EFAA8 9A000010 */  b          .L001EFD14
    /* EFAAC 001EFAAC 00000000 */   nop
  .L001EFAB0:
    /* EFAB0 001EFAB0 3000828E */  lw         $2, 0x30($20)
    /* EFAB4 001EFAB4 A4004484 */  lh         $4, 0xA4($2)
    /* EFAB8 001EFAB8 2C1F090C */  jal        func_00247cb0
    /* EFABC 001EFABC 00000000 */   nop
    /* EFAC0 001EFAC0 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* EFAC4 001EFAC4 B01E040C */  jal        func_00107ac0
    /* EFAC8 001EFAC8 00000000 */   nop
    /* EFACC 001EFACC FFFF4230 */  andi       $2, $2, 0xFFFF
    /* EFAD0 001EFAD0 A000A27F */  sq         $2, 0xA0($29)
    /* EFAD4 001EFAD4 2D900000 */  daddu      $18, $0, $0
    /* EFAD8 001EFAD8 2D880000 */  daddu      $17, $0, $0
    /* EFADC 001EFADC 2D800000 */  daddu      $16, $0, $0
    /* EFAE0 001EFAE0 2DA80000 */  daddu      $21, $0, $0
    /* EFAE4 001EFAE4 2DB00000 */  daddu      $22, $0, $0
    /* EFAE8 001EFAE8 2DB80000 */  daddu      $23, $0, $0
    /* EFAEC 001EFAEC ACB3828F */  lw         $2, -0x4C54($28)
    /* EFAF0 001EFAF0 7401538C */  lw         $19, 0x174($2)
    /* EFAF4 001EFAF4 46000010 */  b          .L001EFC10
    /* EFAF8 001EFAF8 00000000 */   nop
  .L001EFAFC:
    /* EFAFC 001EFAFC 1A006396 */  lhu        $3, 0x1A($19)
    /* EFB00 001EFB00 01006230 */  andi       $2, $3, 0x1
    /* EFB04 001EFB04 41004010 */  beqz       $2, .L001EFC0C
    /* EFB08 001EFB08 00000000 */   nop
    /* EFB0C 001EFB0C 08006230 */  andi       $2, $3, 0x8
    /* EFB10 001EFB10 3E004010 */  beqz       $2, .L001EFC0C
    /* EFB14 001EFB14 00000000 */   nop
    /* EFB18 001EFB18 3C007412 */  beq        $19, $20, .L001EFC0C
    /* EFB1C 001EFB1C 00000000 */   nop
    /* EFB20 001EFB20 30007E8E */  lw         $30, 0x30($19)
    /* EFB24 001EFB24 A200C293 */  lbu        $2, 0xA2($30)
    /* EFB28 001EFB28 38004014 */  bnez       $2, .L001EFC0C
    /* EFB2C 001EFB2C 00000000 */   nop
    /* EFB30 001EFB30 A000A27B */  lq         $2, 0xA0($29)
    /* EFB34 001EFB34 05004228 */  slti       $2, $2, 0x5
    /* EFB38 001EFB38 21004014 */  bnez       $2, .L001EFBC0
    /* EFB3C 001EFB3C 00000000 */   nop
    /* EFB40 001EFB40 640AC48F */  lw         $4, 0xA64($30)
    /* EFB44 001EFB44 01000524 */  addiu      $5, $0, 0x1
    /* EFB48 001EFB48 C4C9080C */  jal        func_00232710
    /* EFB4C 001EFB4C 00000000 */   nop
    /* EFB50 001EFB50 0C004010 */  beqz       $2, .L001EFB84
    /* EFB54 001EFB54 00000000 */   nop
    /* EFB58 001EFB58 ACB3828F */  lw         $2, -0x4C54($28)
    /* EFB5C 001EFB5C 7001428C */  lw         $2, 0x170($2)
    /* EFB60 001EFB60 02005314 */  bne        $2, $19, .L001EFB6C
    /* EFB64 001EFB64 00000000 */   nop
    /* EFB68 001EFB68 2DA86002 */  daddu      $21, $19, $0
  .L001EFB6C:
    /* EFB6C 001EFB6C 80101200 */  sll        $2, $18, 2
    /* EFB70 001EFB70 21105D00 */  addu       $2, $2, $29
    /* EFB74 001EFB74 D00053AC */  sw         $19, 0xD0($2)
    /* EFB78 001EFB78 01005226 */  addiu      $18, $18, 0x1
    /* EFB7C 001EFB7C 10000010 */  b          .L001EFBC0
    /* EFB80 001EFB80 00000000 */   nop
  .L001EFB84:
    /* EFB84 001EFB84 640AC48F */  lw         $4, 0xA64($30)
    /* EFB88 001EFB88 1000053C */  lui        $5, (0x100000 >> 16)
    /* EFB8C 001EFB8C C4C9080C */  jal        func_00232710
    /* EFB90 001EFB90 00000000 */   nop
    /* EFB94 001EFB94 0A004010 */  beqz       $2, .L001EFBC0
    /* EFB98 001EFB98 00000000 */   nop
    /* EFB9C 001EFB9C ACB3828F */  lw         $2, -0x4C54($28)
    /* EFBA0 001EFBA0 7001428C */  lw         $2, 0x170($2)
    /* EFBA4 001EFBA4 02005314 */  bne        $2, $19, .L001EFBB0
    /* EFBA8 001EFBA8 00000000 */   nop
    /* EFBAC 001EFBAC 2DB06002 */  daddu      $22, $19, $0
  .L001EFBB0:
    /* EFBB0 001EFBB0 80101100 */  sll        $2, $17, 2
    /* EFBB4 001EFBB4 21105D00 */  addu       $2, $2, $29
    /* EFBB8 001EFBB8 C00053AC */  sw         $19, 0xC0($2)
    /* EFBBC 001EFBBC 01003126 */  addiu      $17, $17, 0x1
  .L001EFBC0:
    /* EFBC0 001EFBC0 A000A27B */  lq         $2, 0xA0($29)
    /* EFBC4 001EFBC4 07004228 */  slti       $2, $2, 0x7
    /* EFBC8 001EFBC8 10004014 */  bnez       $2, .L001EFC0C
    /* EFBCC 001EFBCC 00000000 */   nop
    /* EFBD0 001EFBD0 640AC48F */  lw         $4, 0xA64($30)
    /* EFBD4 001EFBD4 1E000524 */  addiu      $5, $0, 0x1E
    /* EFBD8 001EFBD8 C4C9080C */  jal        func_00232710
    /* EFBDC 001EFBDC 00000000 */   nop
    /* EFBE0 001EFBE0 0A004010 */  beqz       $2, .L001EFC0C
    /* EFBE4 001EFBE4 00000000 */   nop
    /* EFBE8 001EFBE8 ACB3828F */  lw         $2, -0x4C54($28)
    /* EFBEC 001EFBEC 7001428C */  lw         $2, 0x170($2)
    /* EFBF0 001EFBF0 02005314 */  bne        $2, $19, .L001EFBFC
    /* EFBF4 001EFBF4 00000000 */   nop
    /* EFBF8 001EFBF8 2DB86002 */  daddu      $23, $19, $0
  .L001EFBFC:
    /* EFBFC 001EFBFC 80101000 */  sll        $2, $16, 2
    /* EFC00 001EFC00 21105D00 */  addu       $2, $2, $29
    /* EFC04 001EFC04 B00053AC */  sw         $19, 0xB0($2)
    /* EFC08 001EFC08 01001026 */  addiu      $16, $16, 0x1
  .L001EFC0C:
    /* EFC0C 001EFC0C 5004738E */  lw         $19, 0x450($19)
  .L001EFC10:
    /* EFC10 001EFC10 BAFF6016 */  bnez       $19, .L001EFAFC
    /* EFC14 001EFC14 00000000 */   nop
    /* EFC18 001EFC18 08002016 */  bnez       $17, .L001EFC3C
    /* EFC1C 001EFC1C 00000000 */   nop
    /* EFC20 001EFC20 06000016 */  bnez       $16, .L001EFC3C
    /* EFC24 001EFC24 00000000 */   nop
    /* EFC28 001EFC28 04004016 */  bnez       $18, .L001EFC3C
    /* EFC2C 001EFC2C 00000000 */   nop
    /* EFC30 001EFC30 2D100000 */  daddu      $2, $0, $0
    /* EFC34 001EFC34 37000010 */  b          .L001EFD14
    /* EFC38 001EFC38 00000000 */   nop
  .L001EFC3C:
    /* EFC3C 001EFC3C 11004012 */  beqz       $18, .L001EFC84
    /* EFC40 001EFC40 00000000 */   nop
    /* EFC44 001EFC44 01000224 */  addiu      $2, $0, 0x1
    /* EFC48 001EFC48 480482A6 */  sh         $2, 0x448($20)
    /* EFC4C 001EFC4C 0300A012 */  beqz       $21, .L001EFC5C
    /* EFC50 001EFC50 00000000 */   nop
    /* EFC54 001EFC54 07000010 */  b          .L001EFC74
    /* EFC58 001EFC58 00000000 */   nop
  .L001EFC5C:
    /* EFC5C 001EFC5C 2D204002 */  daddu      $4, $18, $0
    /* EFC60 001EFC60 5CC7080C */  jal        func_00231d70
    /* EFC64 001EFC64 00000000 */   nop
    /* EFC68 001EFC68 80100200 */  sll        $2, $2, 2
    /* EFC6C 001EFC6C 21105D00 */  addu       $2, $2, $29
    /* EFC70 001EFC70 D000558C */  lw         $21, 0xD0($2)
  .L001EFC74:
    /* EFC74 001EFC74 440495AE */  sw         $21, 0x444($20)
    /* EFC78 001EFC78 01000224 */  addiu      $2, $0, 0x1
    /* EFC7C 001EFC7C 25000010 */  b          .L001EFD14
    /* EFC80 001EFC80 00000000 */   nop
  .L001EFC84:
    /* EFC84 001EFC84 11002012 */  beqz       $17, .L001EFCCC
    /* EFC88 001EFC88 00000000 */   nop
    /* EFC8C 001EFC8C 01000224 */  addiu      $2, $0, 0x1
    /* EFC90 001EFC90 480482A6 */  sh         $2, 0x448($20)
    /* EFC94 001EFC94 0300C012 */  beqz       $22, .L001EFCA4
    /* EFC98 001EFC98 00000000 */   nop
    /* EFC9C 001EFC9C 07000010 */  b          .L001EFCBC
    /* EFCA0 001EFCA0 00000000 */   nop
  .L001EFCA4:
    /* EFCA4 001EFCA4 2D202002 */  daddu      $4, $17, $0
    /* EFCA8 001EFCA8 5CC7080C */  jal        func_00231d70
    /* EFCAC 001EFCAC 00000000 */   nop
    /* EFCB0 001EFCB0 80100200 */  sll        $2, $2, 2
    /* EFCB4 001EFCB4 21105D00 */  addu       $2, $2, $29
    /* EFCB8 001EFCB8 C000568C */  lw         $22, 0xC0($2)
  .L001EFCBC:
    /* EFCBC 001EFCBC 440496AE */  sw         $22, 0x444($20)
    /* EFCC0 001EFCC0 01000224 */  addiu      $2, $0, 0x1
    /* EFCC4 001EFCC4 13000010 */  b          .L001EFD14
    /* EFCC8 001EFCC8 00000000 */   nop
  .L001EFCCC:
    /* EFCCC 001EFCCC 10000012 */  beqz       $16, .L001EFD10
    /* EFCD0 001EFCD0 00000000 */   nop
    /* EFCD4 001EFCD4 480480A6 */  sh         $0, 0x448($20)
    /* EFCD8 001EFCD8 0300E012 */  beqz       $23, .L001EFCE8
    /* EFCDC 001EFCDC 00000000 */   nop
    /* EFCE0 001EFCE0 07000010 */  b          .L001EFD00
    /* EFCE4 001EFCE4 00000000 */   nop
  .L001EFCE8:
    /* EFCE8 001EFCE8 2D200002 */  daddu      $4, $16, $0
    /* EFCEC 001EFCEC 5CC7080C */  jal        func_00231d70
    /* EFCF0 001EFCF0 00000000 */   nop
    /* EFCF4 001EFCF4 80100200 */  sll        $2, $2, 2
    /* EFCF8 001EFCF8 21105D00 */  addu       $2, $2, $29
    /* EFCFC 001EFCFC B000578C */  lw         $23, 0xB0($2)
  .L001EFD00:
    /* EFD00 001EFD00 440497AE */  sw         $23, 0x444($20)
    /* EFD04 001EFD04 01000224 */  addiu      $2, $0, 0x1
    /* EFD08 001EFD08 02000010 */  b          .L001EFD14
    /* EFD0C 001EFD0C 00000000 */   nop
  .L001EFD10:
    /* EFD10 001EFD10 2D100000 */  daddu      $2, $0, $0
  .L001EFD14:
    /* EFD14 001EFD14 9000BFDF */  ld         $31, 0x90($29)
    /* EFD18 001EFD18 8000BE7B */  lq         $30, 0x80($29)
    /* EFD1C 001EFD1C 7000B77B */  lq         $23, 0x70($29)
    /* EFD20 001EFD20 6000B67B */  lq         $22, 0x60($29)
    /* EFD24 001EFD24 5000B57B */  lq         $21, 0x50($29)
    /* EFD28 001EFD28 4000B47B */  lq         $20, 0x40($29)
    /* EFD2C 001EFD2C 3000B37B */  lq         $19, 0x30($29)
    /* EFD30 001EFD30 2000B27B */  lq         $18, 0x20($29)
    /* EFD34 001EFD34 1000B17B */  lq         $17, 0x10($29)
    /* EFD38 001EFD38 0000B07B */  lq         $16, 0x0($29)
    /* EFD3C 001EFD3C E000BD27 */  addiu      $29, $29, 0xE0
    /* EFD40 001EFD40 0800E003 */  jr         $31
    /* EFD44 001EFD44 00000000 */   nop
    /* EFD48 001EFD48 00000000 */  nop
    /* EFD4C 001EFD4C 00000000 */  nop
.size func_001ef9c0, 0x390
