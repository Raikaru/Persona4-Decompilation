.section .text
.set noat
.set noreorder
glabel func_001dd920
    /* DD920 001DD920 40FFBD27 */  addiu      $29, $29, -0xC0
    /* DD924 001DD924 9000BFFF */  sd         $31, 0x90($29)
    /* DD928 001DD928 8000BE7F */  sq         $30, 0x80($29)
    /* DD92C 001DD92C 7000B77F */  sq         $23, 0x70($29)
    /* DD930 001DD930 6000B67F */  sq         $22, 0x60($29)
    /* DD934 001DD934 5000B57F */  sq         $21, 0x50($29)
    /* DD938 001DD938 4000B47F */  sq         $20, 0x40($29)
    /* DD93C 001DD93C 3000B37F */  sq         $19, 0x30($29)
    /* DD940 001DD940 2000B27F */  sq         $18, 0x20($29)
    /* DD944 001DD944 1000B17F */  sq         $17, 0x10($29)
    /* DD948 001DD948 0000B07F */  sq         $16, 0x0($29)
    /* DD94C 001DD94C 2DA08000 */  daddu      $20, $4, $0
    /* DD950 001DD950 2D98A000 */  daddu      $19, $5, $0
    /* DD954 001DD954 2DF0E000 */  daddu      $30, $7, $0
    /* DD958 001DD958 FFFF1024 */  addiu      $16, $0, -0x1
    /* DD95C 001DD95C 2D900000 */  daddu      $18, $0, $0
    /* DD960 001DD960 3000958C */  lw         $21, 0x30($4)
    /* DD964 001DD964 640AA48E */  lw         $4, 0xA64($21)
    /* DD968 001DD968 4CF8080C */  jal        func_0023e130
    /* DD96C 001DD96C 00000000 */   nop
    /* DD970 001DD970 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* DD974 001DD974 640AA48E */  lw         $4, 0xA64($21)
    /* DD978 001DD978 50F8080C */  jal        func_0023e140
    /* DD97C 001DD97C 00000000 */   nop
    /* DD980 001DD980 2DB84000 */  daddu      $23, $2, $0
    /* DD984 001DD984 3000628E */  lw         $2, 0x30($19)
    /* DD988 001DD988 640A448C */  lw         $4, 0xA64($2)
    /* DD98C 001DD98C 2D280000 */  daddu      $5, $0, $0
    /* DD990 001DD990 3C0A090C */  jal        func_002428f0
    /* DD994 001DD994 00000000 */   nop
    /* DD998 001DD998 04004010 */  beqz       $2, .L001DD9AC
    /* DD99C 001DD99C 00000000 */   nop
    /* DD9A0 001DD9A0 2D800000 */  daddu      $16, $0, $0
    /* DD9A4 001DD9A4 2D000010 */  b          .L001DDA5C
    /* DD9A8 001DD9A8 00000000 */   nop
  .L001DD9AC:
    /* DD9AC 001DD9AC 3000628E */  lw         $2, 0x30($19)
    /* DD9B0 001DD9B0 640A448C */  lw         $4, 0xA64($2)
    /* DD9B4 001DD9B4 08009594 */  lhu        $21, 0x8($4)
    /* DD9B8 001DD9B8 E0C7080C */  jal        func_00231f80
    /* DD9BC 001DD9BC 00000000 */   nop
    /* DD9C0 001DD9C0 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* DD9C4 001DD9C4 80101500 */  sll        $2, $21, 2
    /* DD9C8 001DD9C8 21185500 */  addu       $3, $2, $21
    /* DD9CC 001DD9CC 80100300 */  sll        $2, $3, 2
    /* DD9D0 001DD9D0 21106200 */  addu       $2, $3, $2
    /* DD9D4 001DD9D4 80180200 */  sll        $3, $2, 2
    /* DD9D8 001DD9D8 00110400 */  sll        $2, $4, 4
    /* DD9DC 001DD9DC 23104400 */  subu       $2, $2, $4
    /* DD9E0 001DD9E0 80100200 */  sll        $2, $2, 2
    /* DD9E4 001DD9E4 2B084300 */  sltu       $1, $2, $3
    /* DD9E8 001DD9E8 04002014 */  bnez       $1, .L001DD9FC
    /* DD9EC 001DD9EC 00000000 */   nop
    /* DD9F0 001DD9F0 01001024 */  addiu      $16, $0, 0x1
    /* DD9F4 001DD9F4 19000010 */  b          .L001DDA5C
    /* DD9F8 001DD9F8 00000000 */   nop
  .L001DD9FC:
    /* DD9FC 001DD9FC 3000628E */  lw         $2, 0x30($19)
    /* DDA00 001DDA00 640A448C */  lw         $4, 0xA64($2)
    /* DDA04 001DDA04 0C000524 */  addiu      $5, $0, 0xC
    /* DDA08 001DDA08 C4C9080C */  jal        func_00232710
    /* DDA0C 001DDA0C 00000000 */   nop
    /* DDA10 001DDA10 04004010 */  beqz       $2, .L001DDA24
    /* DDA14 001DDA14 00000000 */   nop
    /* DDA18 001DDA18 02001024 */  addiu      $16, $0, 0x2
    /* DDA1C 001DDA1C 0F000010 */  b          .L001DDA5C
    /* DDA20 001DDA20 00000000 */   nop
  .L001DDA24:
    /* DDA24 001DDA24 3000628E */  lw         $2, 0x30($19)
    /* DDA28 001DDA28 640A448C */  lw         $4, 0xA64($2)
    /* DDA2C 001DDA2C B4C7080C */  jal        func_00231ed0
    /* DDA30 001DDA30 00000000 */   nop
    /* DDA34 001DDA34 FFFF5530 */  andi       $21, $2, 0xFFFF
    /* DDA38 001DDA38 3000628E */  lw         $2, 0x30($19)
    /* DDA3C 001DDA3C 640A448C */  lw         $4, 0xA64($2)
    /* DDA40 001DDA40 E0C7080C */  jal        func_00231f80
    /* DDA44 001DDA44 00000000 */   nop
    /* DDA48 001DDA48 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DDA4C 001DDA4C 2A08A202 */  slt        $1, $21, $2
    /* DDA50 001DDA50 02002010 */  beqz       $1, .L001DDA5C
    /* DDA54 001DDA54 00000000 */   nop
    /* DDA58 001DDA58 01001024 */  addiu      $16, $0, 0x1
  .L001DDA5C:
    /* DDA5C 001DDA5C 3C1C1000 */  dsll32     $3, $16, 16
    /* DDA60 001DDA60 3F1C0300 */  dsra32     $3, $3, 16
    /* DDA64 001DDA64 02000224 */  addiu      $2, $0, 0x2
    /* DDA68 001DDA68 F3006210 */  beq        $3, $2, .L001DDE38
    /* DDA6C 001DDA6C 00000000 */   nop
    /* DDA70 001DDA70 01000224 */  addiu      $2, $0, 0x1
    /* DDA74 001DDA74 5E006210 */  beq        $3, $2, .L001DDBF0
    /* DDA78 001DDA78 00000000 */   nop
    /* DDA7C 001DDA7C 03006010 */  beqz       $3, .L001DDA8C
    /* DDA80 001DDA80 00000000 */   nop
    /* DDA84 001DDA84 43010010 */  b          .L001DDF94
    /* DDA88 001DDA88 00000000 */   nop
  .L001DDA8C:
    /* DDA8C 001DDA8C 2D800000 */  daddu      $16, $0, $0
    /* DDA90 001DDA90 FFFF3632 */  andi       $22, $17, 0xFFFF
    /* DDA94 001DDA94 50000010 */  b          .L001DDBD8
    /* DDA98 001DDA98 00000000 */   nop
  .L001DDA9C:
    /* DDA9C 001DDA9C FFFF0232 */  andi       $2, $16, 0xFFFF
    /* DDAA0 001DDAA0 40100200 */  sll        $2, $2, 1
    /* DDAA4 001DDAA4 2198E202 */  addu       $19, $23, $2
    /* DDAA8 001DDAA8 00006396 */  lhu        $3, 0x0($19)
    /* DDAAC 001DDAAC 48006010 */  beqz       $3, .L001DDBD0
    /* DDAB0 001DDAB0 00000000 */   nop
    /* DDAB4 001DDAB4 B8016128 */  slti       $1, $3, 0x1B8
    /* DDAB8 001DDAB8 45002010 */  beqz       $1, .L001DDBD0
    /* DDABC 001DDABC 00000000 */   nop
    /* DDAC0 001DDAC0 D2000224 */  addiu      $2, $0, 0xD2
    /* DDAC4 001DDAC4 06006210 */  beq        $3, $2, .L001DDAE0
    /* DDAC8 001DDAC8 00000000 */   nop
    /* DDACC 001DDACC D1000224 */  addiu      $2, $0, 0xD1
    /* DDAD0 001DDAD0 03006210 */  beq        $3, $2, .L001DDAE0
    /* DDAD4 001DDAD4 00000000 */   nop
    /* DDAD8 001DDAD8 3D000010 */  b          .L001DDBD0
    /* DDADC 001DDADC 00000000 */   nop
  .L001DDAE0:
    /* DDAE0 001DDAE0 FFFF7530 */  andi       $21, $3, 0xFFFF
    /* DDAE4 001DDAE4 4002A22A */  slti       $2, $21, 0x240
    /* DDAE8 001DDAE8 06004014 */  bnez       $2, .L001DDB04
    /* DDAEC 001DDAEC 00000000 */   nop
    /* DDAF0 001DDAF0 6100043C */  lui        $4, %hi(D_006095E0)
    /* DDAF4 001DDAF4 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* DDAF8 001DDAF8 5F040524 */  addiu      $5, $0, 0x45F
    /* DDAFC 001DDAFC CCB5110C */  jal        func_0046d730
    /* DDB00 001DDB00 00000000 */   nop
  .L001DDB04:
    /* DDB04 001DDB04 3000918E */  lw         $17, 0x30($20)
    /* DDB08 001DDB08 B801A12A */  slti       $1, $21, 0x1B8
    /* DDB0C 001DDB0C 1D002010 */  beqz       $1, .L001DDB84
    /* DDB10 001DDB10 00000000 */   nop
    /* DDB14 001DDB14 640A248E */  lw         $4, 0xA64($17)
    /* DDB18 001DDB18 0800023C */  lui        $2, (0x80008 >> 16)
    /* DDB1C 001DDB1C 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* DDB20 001DDB20 C4C9080C */  jal        func_00232710
    /* DDB24 001DDB24 00000000 */   nop
    /* DDB28 001DDB28 04004010 */  beqz       $2, .L001DDB3C
    /* DDB2C 001DDB2C 00000000 */   nop
    /* DDB30 001DDB30 2D100000 */  daddu      $2, $0, $0
    /* DDB34 001DDB34 1D000010 */  b          .L001DDBAC
    /* DDB38 001DDB38 00000000 */   nop
  .L001DDB3C:
    /* DDB3C 001DDB3C 640A248E */  lw         $4, 0xA64($17)
    /* DDB40 001DDB40 2D28A002 */  daddu      $5, $21, $0
    /* DDB44 001DDB44 CCC9080C */  jal        func_00232730
    /* DDB48 001DDB48 00000000 */   nop
    /* DDB4C 001DDB4C 04004014 */  bnez       $2, .L001DDB60
    /* DDB50 001DDB50 00000000 */   nop
    /* DDB54 001DDB54 2D100000 */  daddu      $2, $0, $0
    /* DDB58 001DDB58 14000010 */  b          .L001DDBAC
    /* DDB5C 001DDB5C 00000000 */   nop
  .L001DDB60:
    /* DDB60 001DDB60 640A248E */  lw         $4, 0xA64($17)
    /* DDB64 001DDB64 2D28A002 */  daddu      $5, $21, $0
    /* DDB68 001DDB68 70F7080C */  jal        func_0023ddc0
    /* DDB6C 001DDB6C 00000000 */   nop
    /* DDB70 001DDB70 0D004010 */  beqz       $2, .L001DDBA8
    /* DDB74 001DDB74 00000000 */   nop
    /* DDB78 001DDB78 2D100000 */  daddu      $2, $0, $0
    /* DDB7C 001DDB7C 0B000010 */  b          .L001DDBAC
    /* DDB80 001DDB80 00000000 */   nop
  .L001DDB84:
    /* DDB84 001DDB84 640A248E */  lw         $4, 0xA64($17)
    /* DDB88 001DDB88 2D28A002 */  daddu      $5, $21, $0
    /* DDB8C 001DDB8C CCC9080C */  jal        func_00232730
    /* DDB90 001DDB90 00000000 */   nop
    /* DDB94 001DDB94 04004014 */  bnez       $2, .L001DDBA8
    /* DDB98 001DDB98 00000000 */   nop
    /* DDB9C 001DDB9C 2D100000 */  daddu      $2, $0, $0
    /* DDBA0 001DDBA0 02000010 */  b          .L001DDBAC
    /* DDBA4 001DDBA4 00000000 */   nop
  .L001DDBA8:
    /* DDBA8 001DDBA8 01000224 */  addiu      $2, $0, 0x1
  .L001DDBAC:
    /* DDBAC 001DDBAC 08004010 */  beqz       $2, .L001DDBD0
    /* DDBB0 001DDBB0 00000000 */   nop
    /* DDBB4 001DDBB4 00006396 */  lhu        $3, 0x0($19)
    /* DDBB8 001DDBB8 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DDBBC 001DDBBC 40100200 */  sll        $2, $2, 1
    /* DDBC0 001DDBC0 21105D00 */  addu       $2, $2, $29
    /* DDBC4 001DDBC4 B00043A4 */  sh         $3, 0xB0($2)
    /* DDBC8 001DDBC8 01004226 */  addiu      $2, $18, 0x1
    /* DDBCC 001DDBCC FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DDBD0:
    /* DDBD0 001DDBD0 01000226 */  addiu      $2, $16, 0x1
    /* DDBD4 001DDBD4 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001DDBD8:
    /* DDBD8 001DDBD8 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* DDBDC 001DDBDC 2A105600 */  slt        $2, $2, $22
    /* DDBE0 001DDBE0 AEFF4014 */  bnez       $2, .L001DDA9C
    /* DDBE4 001DDBE4 00000000 */   nop
    /* DDBE8 001DDBE8 EA000010 */  b          .L001DDF94
    /* DDBEC 001DDBEC 00000000 */   nop
  .L001DDBF0:
    /* DDBF0 001DDBF0 2D800000 */  daddu      $16, $0, $0
    /* DDBF4 001DDBF4 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* DDBF8 001DDBF8 A000A27F */  sq         $2, 0xA0($29)
    /* DDBFC 001DDBFC 53000010 */  b          .L001DDD4C
    /* DDC00 001DDC00 00000000 */   nop
  .L001DDC04:
    /* DDC04 001DDC04 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* DDC08 001DDC08 40100200 */  sll        $2, $2, 1
    /* DDC0C 001DDC0C 21B0E202 */  addu       $22, $23, $2
    /* DDC10 001DDC10 0000C496 */  lhu        $4, 0x0($22)
    /* DDC14 001DDC14 4B008010 */  beqz       $4, .L001DDD44
    /* DDC18 001DDC18 00000000 */   nop
    /* DDC1C 001DDC1C B8018128 */  slti       $1, $4, 0x1B8
    /* DDC20 001DDC20 48002010 */  beqz       $1, .L001DDD44
    /* DDC24 001DDC24 00000000 */   nop
    /* DDC28 001DDC28 40FF8224 */  addiu      $2, $4, -0xC0
    /* DDC2C 001DDC2C 0700412C */  sltiu      $1, $2, 0x7
    /* DDC30 001DDC30 44002010 */  beqz       $1, .L001DDD44
    /* DDC34 001DDC34 00000000 */   nop
    /* DDC38 001DDC38 7400033C */  lui        $3, %hi(jtbl_00747130)
    /* DDC3C 001DDC3C 30716324 */  addiu      $3, $3, %lo(jtbl_00747130)
    /* DDC40 001DDC40 80100200 */  sll        $2, $2, 2
    /* DDC44 001DDC44 21104300 */  addu       $2, $2, $3
    /* DDC48 001DDC48 0000428C */  lw         $2, 0x0($2)
    /* DDC4C 001DDC4C 08004000 */  jr         $2
    /* DDC50 001DDC50 00000000 */   nop
    /* DDC54 001DDC54 FFFF9130 */  andi       $17, $4, 0xFFFF
    /* DDC58 001DDC58 4002222A */  slti       $2, $17, 0x240
    /* DDC5C 001DDC5C 06004014 */  bnez       $2, .L001DDC78
    /* DDC60 001DDC60 00000000 */   nop
    /* DDC64 001DDC64 6100043C */  lui        $4, %hi(D_006095E0)
    /* DDC68 001DDC68 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* DDC6C 001DDC6C 5F040524 */  addiu      $5, $0, 0x45F
    /* DDC70 001DDC70 CCB5110C */  jal        func_0046d730
    /* DDC74 001DDC74 00000000 */   nop
  .L001DDC78:
    /* DDC78 001DDC78 3000958E */  lw         $21, 0x30($20)
    /* DDC7C 001DDC7C B801212A */  slti       $1, $17, 0x1B8
    /* DDC80 001DDC80 1D002010 */  beqz       $1, .L001DDCF8
    /* DDC84 001DDC84 00000000 */   nop
    /* DDC88 001DDC88 640AA48E */  lw         $4, 0xA64($21)
    /* DDC8C 001DDC8C 0800023C */  lui        $2, (0x80008 >> 16)
    /* DDC90 001DDC90 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* DDC94 001DDC94 C4C9080C */  jal        func_00232710
    /* DDC98 001DDC98 00000000 */   nop
    /* DDC9C 001DDC9C 04004010 */  beqz       $2, .L001DDCB0
    /* DDCA0 001DDCA0 00000000 */   nop
    /* DDCA4 001DDCA4 2D100000 */  daddu      $2, $0, $0
    /* DDCA8 001DDCA8 1D000010 */  b          .L001DDD20
    /* DDCAC 001DDCAC 00000000 */   nop
  .L001DDCB0:
    /* DDCB0 001DDCB0 640AA48E */  lw         $4, 0xA64($21)
    /* DDCB4 001DDCB4 2D282002 */  daddu      $5, $17, $0
    /* DDCB8 001DDCB8 CCC9080C */  jal        func_00232730
    /* DDCBC 001DDCBC 00000000 */   nop
    /* DDCC0 001DDCC0 04004014 */  bnez       $2, .L001DDCD4
    /* DDCC4 001DDCC4 00000000 */   nop
    /* DDCC8 001DDCC8 2D100000 */  daddu      $2, $0, $0
    /* DDCCC 001DDCCC 14000010 */  b          .L001DDD20
    /* DDCD0 001DDCD0 00000000 */   nop
  .L001DDCD4:
    /* DDCD4 001DDCD4 640AA48E */  lw         $4, 0xA64($21)
    /* DDCD8 001DDCD8 2D282002 */  daddu      $5, $17, $0
    /* DDCDC 001DDCDC 70F7080C */  jal        func_0023ddc0
    /* DDCE0 001DDCE0 00000000 */   nop
    /* DDCE4 001DDCE4 0D004010 */  beqz       $2, .L001DDD1C
    /* DDCE8 001DDCE8 00000000 */   nop
    /* DDCEC 001DDCEC 2D100000 */  daddu      $2, $0, $0
    /* DDCF0 001DDCF0 0B000010 */  b          .L001DDD20
    /* DDCF4 001DDCF4 00000000 */   nop
  .L001DDCF8:
    /* DDCF8 001DDCF8 640AA48E */  lw         $4, 0xA64($21)
    /* DDCFC 001DDCFC 2D282002 */  daddu      $5, $17, $0
    /* DDD00 001DDD00 CCC9080C */  jal        func_00232730
    /* DDD04 001DDD04 00000000 */   nop
    /* DDD08 001DDD08 04004014 */  bnez       $2, .L001DDD1C
    /* DDD0C 001DDD0C 00000000 */   nop
    /* DDD10 001DDD10 2D100000 */  daddu      $2, $0, $0
    /* DDD14 001DDD14 02000010 */  b          .L001DDD20
    /* DDD18 001DDD18 00000000 */   nop
  .L001DDD1C:
    /* DDD1C 001DDD1C 01000224 */  addiu      $2, $0, 0x1
  .L001DDD20:
    /* DDD20 001DDD20 08004010 */  beqz       $2, .L001DDD44
    /* DDD24 001DDD24 00000000 */   nop
    /* DDD28 001DDD28 0000C396 */  lhu        $3, 0x0($22)
    /* DDD2C 001DDD2C FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DDD30 001DDD30 40100200 */  sll        $2, $2, 1
    /* DDD34 001DDD34 21105D00 */  addu       $2, $2, $29
    /* DDD38 001DDD38 B00043A4 */  sh         $3, 0xB0($2)
    /* DDD3C 001DDD3C 01004226 */  addiu      $2, $18, 0x1
    /* DDD40 001DDD40 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DDD44:
    /* DDD44 001DDD44 01000226 */  addiu      $2, $16, 0x1
    /* DDD48 001DDD48 FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001DDD4C:
    /* DDD4C 001DDD4C FFFF0332 */  andi       $3, $16, 0xFFFF
    /* DDD50 001DDD50 A000A27B */  lq         $2, 0xA0($29)
    /* DDD54 001DDD54 2A106200 */  slt        $2, $3, $2
    /* DDD58 001DDD58 AAFF4014 */  bnez       $2, .L001DDC04
    /* DDD5C 001DDD5C 00000000 */   nop
    /* DDD60 001DDD60 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DDD64 001DDD64 8B004018 */  blez       $2, .L001DDF94
    /* DDD68 001DDD68 00000000 */   nop
    /* DDD6C 001DDD6C 01000824 */  addiu      $8, $0, 0x1
    /* DDD70 001DDD70 1700C813 */  beq        $30, $8, .L001DDDD0
    /* DDD74 001DDD74 00000000 */   nop
    /* DDD78 001DDD78 0300C013 */  beqz       $30, .L001DDD88
    /* DDD7C 001DDD7C 00000000 */   nop
    /* DDD80 001DDD80 24000010 */  b          .L001DDE14
    /* DDD84 001DDD84 00000000 */   nop
  .L001DDD88:
    /* DDD88 001DDD88 2D208002 */  daddu      $4, $20, $0
    /* DDD8C 001DDD8C 2D286002 */  daddu      $5, $19, $0
    /* DDD90 001DDD90 B000A627 */  addiu      $6, $29, 0xB0
    /* DDD94 001DDD94 2D384002 */  daddu      $7, $18, $0
    /* DDD98 001DDD98 2D400000 */  daddu      $8, $0, $0
    /* DDD9C 001DDD9C E874070C */  jal        func_001dd3a0
    /* DDDA0 001DDDA0 00000000 */   nop
    /* DDDA4 001DDDA4 22004104 */  bgez       $2, .L001DDE30
    /* DDDA8 001DDDA8 00000000 */   nop
    /* DDDAC 001DDDAC 2D208002 */  daddu      $4, $20, $0
    /* DDDB0 001DDDB0 2D286002 */  daddu      $5, $19, $0
    /* DDDB4 001DDDB4 B000A627 */  addiu      $6, $29, 0xB0
    /* DDDB8 001DDDB8 2D384002 */  daddu      $7, $18, $0
    /* DDDBC 001DDDBC 01000824 */  addiu      $8, $0, 0x1
    /* DDDC0 001DDDC0 E874070C */  jal        func_001dd3a0
    /* DDDC4 001DDDC4 00000000 */   nop
    /* DDDC8 001DDDC8 19000010 */  b          .L001DDE30
    /* DDDCC 001DDDCC 00000000 */   nop
  .L001DDDD0:
    /* DDDD0 001DDDD0 2D208002 */  daddu      $4, $20, $0
    /* DDDD4 001DDDD4 2D286002 */  daddu      $5, $19, $0
    /* DDDD8 001DDDD8 B000A627 */  addiu      $6, $29, 0xB0
    /* DDDDC 001DDDDC 2D384002 */  daddu      $7, $18, $0
    /* DDDE0 001DDDE0 E874070C */  jal        func_001dd3a0
    /* DDDE4 001DDDE4 00000000 */   nop
    /* DDDE8 001DDDE8 11004104 */  bgez       $2, .L001DDE30
    /* DDDEC 001DDDEC 00000000 */   nop
    /* DDDF0 001DDDF0 2D208002 */  daddu      $4, $20, $0
    /* DDDF4 001DDDF4 2D286002 */  daddu      $5, $19, $0
    /* DDDF8 001DDDF8 B000A627 */  addiu      $6, $29, 0xB0
    /* DDDFC 001DDDFC 2D384002 */  daddu      $7, $18, $0
    /* DDE00 001DDE00 2D400000 */  daddu      $8, $0, $0
    /* DDE04 001DDE04 E874070C */  jal        func_001dd3a0
    /* DDE08 001DDE08 00000000 */   nop
    /* DDE0C 001DDE0C 08000010 */  b          .L001DDE30
    /* DDE10 001DDE10 00000000 */   nop
  .L001DDE14:
    /* DDE14 001DDE14 2D208002 */  daddu      $4, $20, $0
    /* DDE18 001DDE18 2D286002 */  daddu      $5, $19, $0
    /* DDE1C 001DDE1C B000A627 */  addiu      $6, $29, 0xB0
    /* DDE20 001DDE20 2D384002 */  daddu      $7, $18, $0
    /* DDE24 001DDE24 FFFF0834 */  ori        $8, $0, 0xFFFF
    /* DDE28 001DDE28 E874070C */  jal        func_001dd3a0
    /* DDE2C 001DDE2C 00000000 */   nop
  .L001DDE30:
    /* DDE30 001DDE30 63000010 */  b          .L001DDFC0
    /* DDE34 001DDE34 00000000 */   nop
  .L001DDE38:
    /* DDE38 001DDE38 2D980000 */  daddu      $19, $0, $0
    /* DDE3C 001DDE3C FFFF3632 */  andi       $22, $17, 0xFFFF
    /* DDE40 001DDE40 50000010 */  b          .L001DDF84
    /* DDE44 001DDE44 00000000 */   nop
  .L001DDE48:
    /* DDE48 001DDE48 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* DDE4C 001DDE4C 40100200 */  sll        $2, $2, 1
    /* DDE50 001DDE50 2188E202 */  addu       $17, $23, $2
    /* DDE54 001DDE54 00002396 */  lhu        $3, 0x0($17)
    /* DDE58 001DDE58 48006010 */  beqz       $3, .L001DDF7C
    /* DDE5C 001DDE5C 00000000 */   nop
    /* DDE60 001DDE60 B8016128 */  slti       $1, $3, 0x1B8
    /* DDE64 001DDE64 45002010 */  beqz       $1, .L001DDF7C
    /* DDE68 001DDE68 00000000 */   nop
    /* DDE6C 001DDE6C C8000224 */  addiu      $2, $0, 0xC8
    /* DDE70 001DDE70 06006210 */  beq        $3, $2, .L001DDE8C
    /* DDE74 001DDE74 00000000 */   nop
    /* DDE78 001DDE78 C7000224 */  addiu      $2, $0, 0xC7
    /* DDE7C 001DDE7C 03006210 */  beq        $3, $2, .L001DDE8C
    /* DDE80 001DDE80 00000000 */   nop
    /* DDE84 001DDE84 3D000010 */  b          .L001DDF7C
    /* DDE88 001DDE88 00000000 */   nop
  .L001DDE8C:
    /* DDE8C 001DDE8C FFFF7530 */  andi       $21, $3, 0xFFFF
    /* DDE90 001DDE90 4002A22A */  slti       $2, $21, 0x240
    /* DDE94 001DDE94 06004014 */  bnez       $2, .L001DDEB0
    /* DDE98 001DDE98 00000000 */   nop
    /* DDE9C 001DDE9C 6100043C */  lui        $4, %hi(D_006095E0)
    /* DDEA0 001DDEA0 E0958424 */  addiu      $4, $4, %lo(D_006095E0)
    /* DDEA4 001DDEA4 5F040524 */  addiu      $5, $0, 0x45F
    /* DDEA8 001DDEA8 CCB5110C */  jal        func_0046d730
    /* DDEAC 001DDEAC 00000000 */   nop
  .L001DDEB0:
    /* DDEB0 001DDEB0 3000908E */  lw         $16, 0x30($20)
    /* DDEB4 001DDEB4 B801A12A */  slti       $1, $21, 0x1B8
    /* DDEB8 001DDEB8 1D002010 */  beqz       $1, .L001DDF30
    /* DDEBC 001DDEBC 00000000 */   nop
    /* DDEC0 001DDEC0 640A048E */  lw         $4, 0xA64($16)
    /* DDEC4 001DDEC4 0800023C */  lui        $2, (0x80008 >> 16)
    /* DDEC8 001DDEC8 08004534 */  ori        $5, $2, (0x80008 & 0xFFFF)
    /* DDECC 001DDECC C4C9080C */  jal        func_00232710
    /* DDED0 001DDED0 00000000 */   nop
    /* DDED4 001DDED4 04004010 */  beqz       $2, .L001DDEE8
    /* DDED8 001DDED8 00000000 */   nop
    /* DDEDC 001DDEDC 2D100000 */  daddu      $2, $0, $0
    /* DDEE0 001DDEE0 1D000010 */  b          .L001DDF58
    /* DDEE4 001DDEE4 00000000 */   nop
  .L001DDEE8:
    /* DDEE8 001DDEE8 640A048E */  lw         $4, 0xA64($16)
    /* DDEEC 001DDEEC 2D28A002 */  daddu      $5, $21, $0
    /* DDEF0 001DDEF0 CCC9080C */  jal        func_00232730
    /* DDEF4 001DDEF4 00000000 */   nop
    /* DDEF8 001DDEF8 04004014 */  bnez       $2, .L001DDF0C
    /* DDEFC 001DDEFC 00000000 */   nop
    /* DDF00 001DDF00 2D100000 */  daddu      $2, $0, $0
    /* DDF04 001DDF04 14000010 */  b          .L001DDF58
    /* DDF08 001DDF08 00000000 */   nop
  .L001DDF0C:
    /* DDF0C 001DDF0C 640A048E */  lw         $4, 0xA64($16)
    /* DDF10 001DDF10 2D28A002 */  daddu      $5, $21, $0
    /* DDF14 001DDF14 70F7080C */  jal        func_0023ddc0
    /* DDF18 001DDF18 00000000 */   nop
    /* DDF1C 001DDF1C 0D004010 */  beqz       $2, .L001DDF54
    /* DDF20 001DDF20 00000000 */   nop
    /* DDF24 001DDF24 2D100000 */  daddu      $2, $0, $0
    /* DDF28 001DDF28 0B000010 */  b          .L001DDF58
    /* DDF2C 001DDF2C 00000000 */   nop
  .L001DDF30:
    /* DDF30 001DDF30 640A048E */  lw         $4, 0xA64($16)
    /* DDF34 001DDF34 2D28A002 */  daddu      $5, $21, $0
    /* DDF38 001DDF38 CCC9080C */  jal        func_00232730
    /* DDF3C 001DDF3C 00000000 */   nop
    /* DDF40 001DDF40 04004014 */  bnez       $2, .L001DDF54
    /* DDF44 001DDF44 00000000 */   nop
    /* DDF48 001DDF48 2D100000 */  daddu      $2, $0, $0
    /* DDF4C 001DDF4C 02000010 */  b          .L001DDF58
    /* DDF50 001DDF50 00000000 */   nop
  .L001DDF54:
    /* DDF54 001DDF54 01000224 */  addiu      $2, $0, 0x1
  .L001DDF58:
    /* DDF58 001DDF58 08004010 */  beqz       $2, .L001DDF7C
    /* DDF5C 001DDF5C 00000000 */   nop
    /* DDF60 001DDF60 00002396 */  lhu        $3, 0x0($17)
    /* DDF64 001DDF64 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* DDF68 001DDF68 40100200 */  sll        $2, $2, 1
    /* DDF6C 001DDF6C 21105D00 */  addu       $2, $2, $29
    /* DDF70 001DDF70 B00043A4 */  sh         $3, 0xB0($2)
    /* DDF74 001DDF74 01004226 */  addiu      $2, $18, 0x1
    /* DDF78 001DDF78 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001DDF7C:
    /* DDF7C 001DDF7C 01006226 */  addiu      $2, $19, 0x1
    /* DDF80 001DDF80 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001DDF84:
    /* DDF84 001DDF84 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* DDF88 001DDF88 2A105600 */  slt        $2, $2, $22
    /* DDF8C 001DDF8C AEFF4014 */  bnez       $2, .L001DDE48
    /* DDF90 001DDF90 00000000 */   nop
  .L001DDF94:
    /* DDF94 001DDF94 FFFF4432 */  andi       $4, $18, 0xFFFF
    /* DDF98 001DDF98 08008018 */  blez       $4, .L001DDFBC
    /* DDF9C 001DDF9C 00000000 */   nop
    /* DDFA0 001DDFA0 5CC7080C */  jal        func_00231d70
    /* DDFA4 001DDFA4 00000000 */   nop
    /* DDFA8 001DDFA8 40100200 */  sll        $2, $2, 1
    /* DDFAC 001DDFAC 21105D00 */  addu       $2, $2, $29
    /* DDFB0 001DDFB0 B0004294 */  lhu        $2, 0xB0($2)
    /* DDFB4 001DDFB4 02000010 */  b          .L001DDFC0
    /* DDFB8 001DDFB8 00000000 */   nop
  .L001DDFBC:
    /* DDFBC 001DDFBC FFFF0224 */  addiu      $2, $0, -0x1
  .L001DDFC0:
    /* DDFC0 001DDFC0 9000BFDF */  ld         $31, 0x90($29)
    /* DDFC4 001DDFC4 8000BE7B */  lq         $30, 0x80($29)
    /* DDFC8 001DDFC8 7000B77B */  lq         $23, 0x70($29)
    /* DDFCC 001DDFCC 6000B67B */  lq         $22, 0x60($29)
    /* DDFD0 001DDFD0 5000B57B */  lq         $21, 0x50($29)
    /* DDFD4 001DDFD4 4000B47B */  lq         $20, 0x40($29)
    /* DDFD8 001DDFD8 3000B37B */  lq         $19, 0x30($29)
    /* DDFDC 001DDFDC 2000B27B */  lq         $18, 0x20($29)
    /* DDFE0 001DDFE0 1000B17B */  lq         $17, 0x10($29)
    /* DDFE4 001DDFE4 0000B07B */  lq         $16, 0x0($29)
    /* DDFE8 001DDFE8 C000BD27 */  addiu      $29, $29, 0xC0
    /* DDFEC 001DDFEC 0800E003 */  jr         $31
    /* DDFF0 001DDFF0 00000000 */   nop
    /* DDFF4 001DDFF4 00000000 */  nop
    /* DDFF8 001DDFF8 00000000 */  nop
    /* DDFFC 001DDFFC 00000000 */  nop
.size func_001dd920, 0x6e0
