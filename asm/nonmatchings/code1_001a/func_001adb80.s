.section .text
.set noat
.set noreorder
glabel func_001adb80
    /* ADB80 001ADB80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* ADB84 001ADB84 2000BFFF */  sd         $31, 0x20($29)
    /* ADB88 001ADB88 1000B17F */  sq         $17, 0x10($29)
    /* ADB8C 001ADB8C 0000B07F */  sq         $16, 0x0($29)
    /* ADB90 001ADB90 2D808000 */  daddu      $16, $4, $0
    /* ADB94 001ADB94 1A008494 */  lhu        $4, 0x1A($4)
    /* ADB98 001ADB98 01008230 */  andi       $2, $4, 0x1
    /* ADB9C 001ADB9C 04004014 */  bnez       $2, .L001ADBB0
    /* ADBA0 001ADBA0 00000000 */   nop
    /* ADBA4 001ADBA4 2D100000 */  daddu      $2, $0, $0
    /* ADBA8 001ADBA8 11000010 */  b          .L001ADBF0
    /* ADBAC 001ADBAC 00000000 */   nop
  .L001ADBB0:
    /* ADBB0 001ADBB0 3000028E */  lw         $2, 0x30($16)
    /* ADBB4 001ADBB4 0C0A438C */  lw         $3, 0xA0C($2)
    /* ADBB8 001ADBB8 10008230 */  andi       $2, $4, 0x10
    /* ADBBC 001ADBBC 04004014 */  bnez       $2, .L001ADBD0
    /* ADBC0 001ADBC0 00000000 */   nop
    /* ADBC4 001ADBC4 2D100000 */  daddu      $2, $0, $0
    /* ADBC8 001ADBC8 09000010 */  b          .L001ADBF0
    /* ADBCC 001ADBCC 00000000 */   nop
  .L001ADBD0:
    /* ADBD0 001ADBD0 9800628C */  lw         $2, 0x98($3)
    /* ADBD4 001ADBD4 02004230 */  andi       $2, $2, 0x2
    /* ADBD8 001ADBD8 04004010 */  beqz       $2, .L001ADBEC
    /* ADBDC 001ADBDC 00000000 */   nop
    /* ADBE0 001ADBE0 01000224 */  addiu      $2, $0, 0x1
    /* ADBE4 001ADBE4 02000010 */  b          .L001ADBF0
    /* ADBE8 001ADBE8 00000000 */   nop
  .L001ADBEC:
    /* ADBEC 001ADBEC 2D100000 */  daddu      $2, $0, $0
  .L001ADBF0:
    /* ADBF0 001ADBF0 0B004010 */  beqz       $2, .L001ADC20
    /* ADBF4 001ADBF4 00000000 */   nop
    /* ADBF8 001ADBF8 3000028E */  lw         $2, 0x30($16)
    /* ADBFC 001ADBFC 0C0A448C */  lw         $4, 0xA0C($2)
    /* ADC00 001ADC00 A86D060C */  jal        func_0019b6a0
    /* ADC04 001ADC04 00000000 */   nop
    /* ADC08 001ADC08 2D204000 */  daddu      $4, $2, $0
    /* ADC0C 001ADC0C 000003DE */  ld         $3, 0x0($16)
    /* ADC10 001ADC10 600043FC */  sd         $3, 0x60($2)
    /* ADC14 001ADC14 01000524 */  addiu      $5, $0, 0x1
    /* ADC18 001ADC18 6451060C */  jal        func_00194590
    /* ADC1C 001ADC1C 00000000 */   nop
  .L001ADC20:
    /* ADC20 001ADC20 2D200002 */  daddu      $4, $16, $0
    /* ADC24 001ADC24 EC80060C */  jal        func_001a03b0
    /* ADC28 001ADC28 00000000 */   nop
    /* ADC2C 001ADC2C 3000048E */  lw         $4, 0x30($16)
    /* ADC30 001ADC30 6C000596 */  lhu        $5, 0x6C($16)
    /* ADC34 001ADC34 B808080C */  jal        func_002022e0
    /* ADC38 001ADC38 00000000 */   nop
    /* ADC3C 001ADC3C 2D204000 */  daddu      $4, $2, $0
    /* ADC40 001ADC40 000003DE */  ld         $3, 0x0($16)
    /* ADC44 001ADC44 600043FC */  sd         $3, 0x60($2)
    /* ADC48 001ADC48 03000524 */  addiu      $5, $0, 0x3
    /* ADC4C 001ADC4C 6451060C */  jal        func_00194590
    /* ADC50 001ADC50 00000000 */   nop
    /* ADC54 001ADC54 2D200002 */  daddu      $4, $16, $0
    /* ADC58 001ADC58 1F000524 */  addiu      $5, $0, 0x1F
    /* ADC5C 001ADC5C 48F2060C */  jal        func_001bc920
    /* ADC60 001ADC60 00000000 */   nop
    /* ADC64 001ADC64 2D204000 */  daddu      $4, $2, $0
    /* ADC68 001ADC68 000003DE */  ld         $3, 0x0($16)
    /* ADC6C 001ADC6C 600043FC */  sd         $3, 0x60($2)
    /* ADC70 001ADC70 2D280000 */  daddu      $5, $0, $0
    /* ADC74 001ADC74 6451060C */  jal        func_00194590
    /* ADC78 001ADC78 00000000 */   nop
    /* ADC7C 001ADC7C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* ADC80 001ADC80 00608244 */  mtc1       $2, $f12
    /* ADC84 001ADC84 3000048E */  lw         $4, 0x30($16)
    /* ADC88 001ADC88 19000524 */  addiu      $5, $0, 0x19
    /* ADC8C 001ADC8C 2D300000 */  daddu      $6, $0, $0
    /* ADC90 001ADC90 2D380000 */  daddu      $7, $0, $0
    /* ADC94 001ADC94 B867060C */  jal        func_00199ee0
    /* ADC98 001ADC98 00000000 */   nop
    /* ADC9C 001ADC9C 2D204000 */  daddu      $4, $2, $0
    /* ADCA0 001ADCA0 000003DE */  ld         $3, 0x0($16)
    /* ADCA4 001ADCA4 600043FC */  sd         $3, 0x60($2)
    /* ADCA8 001ADCA8 2D280000 */  daddu      $5, $0, $0
    /* ADCAC 001ADCAC 6451060C */  jal        func_00194590
    /* ADCB0 001ADCB0 00000000 */   nop
    /* ADCB4 001ADCB4 2D200002 */  daddu      $4, $16, $0
    /* ADCB8 001ADCB8 15000524 */  addiu      $5, $0, 0x15
    /* ADCBC 001ADCBC 2D300000 */  daddu      $6, $0, $0
    /* ADCC0 001ADCC0 2D380000 */  daddu      $7, $0, $0
    /* ADCC4 001ADCC4 2D400000 */  daddu      $8, $0, $0
    /* ADCC8 001ADCC8 70E6070C */  jal        func_001f99c0
    /* ADCCC 001ADCCC 00000000 */   nop
    /* ADCD0 001ADCD0 2D204000 */  daddu      $4, $2, $0
    /* ADCD4 001ADCD4 000003DE */  ld         $3, 0x0($16)
    /* ADCD8 001ADCD8 600043FC */  sd         $3, 0x60($2)
    /* ADCDC 001ADCDC 01000524 */  addiu      $5, $0, 0x1
    /* ADCE0 001ADCE0 6451060C */  jal        func_00194590
    /* ADCE4 001ADCE4 00000000 */   nop
    /* ADCE8 001ADCE8 3000028E */  lw         $2, 0x30($16)
    /* ADCEC 001ADCEC A2004290 */  lbu        $2, 0xA2($2)
    /* ADCF0 001ADCF0 15004014 */  bnez       $2, .L001ADD48
    /* ADCF4 001ADCF4 00000000 */   nop
    /* ADCF8 001ADCF8 74000496 */  lhu        $4, 0x74($16)
    /* ADCFC 001ADCFC C02C040C */  jal        func_0010b300
    /* ADD00 001ADD00 00000000 */   nop
    /* ADD04 001ADD04 74000596 */  lhu        $5, 0x74($16)
    /* ADD08 001ADD08 3000048E */  lw         $4, 0x30($16)
    /* ADD0C 001ADD0C CC7B060C */  jal        func_0019ef30
    /* ADD10 001ADD10 00000000 */   nop
    /* ADD14 001ADD14 FC2D040C */  jal        func_0010b7f0
    /* ADD18 001ADD18 00000000 */   nop
    /* ADD1C 001ADD1C 3C000424 */  addiu      $4, $0, 0x3C
    /* ADD20 001ADD20 CC18040C */  jal        func_00106330
    /* ADD24 001ADD24 00000000 */   nop
    /* ADD28 001ADD28 07004010 */  beqz       $2, .L001ADD48
    /* ADD2C 001ADD2C 00000000 */   nop
    /* ADD30 001ADD30 F003028E */  lw         $2, 0x3F0($16)
    /* ADD34 001ADD34 04004010 */  beqz       $2, .L001ADD48
    /* ADD38 001ADD38 00000000 */   nop
    /* ADD3C 001ADD3C 060040A4 */  sh         $0, 0x6($2)
    /* ADD40 001ADD40 F003028E */  lw         $2, 0x3F0($16)
    /* ADD44 001ADD44 040040A4 */  sh         $0, 0x4($2)
  .L001ADD48:
    /* ADD48 001ADD48 3000058E */  lw         $5, 0x30($16)
    /* ADD4C 001ADD4C ACB3828F */  lw         $2, -0x4C54($28)
    /* ADD50 001ADD50 3C0D448C */  lw         $4, 0xD3C($2)
    /* ADD54 001ADD54 2D30A000 */  daddu      $6, $5, $0
    /* ADD58 001ADD58 2D380000 */  daddu      $7, $0, $0
    /* ADD5C 001ADD5C 2D400000 */  daddu      $8, $0, $0
    /* ADD60 001ADD60 9058070C */  jal        func_001d6240
    /* ADD64 001ADD64 00000000 */   nop
    /* ADD68 001ADD68 2D884000 */  daddu      $17, $2, $0
    /* ADD6C 001ADD6C 0F000324 */  addiu      $3, $0, 0xF
    /* ADD70 001ADD70 480043A4 */  sh         $3, 0x48($2)
    /* ADD74 001ADD74 000003DE */  ld         $3, 0x0($16)
    /* ADD78 001ADD78 600043FC */  sd         $3, 0x60($2)
    /* ADD7C 001ADD7C 2D202002 */  daddu      $4, $17, $0
    /* ADD80 001ADD80 02000524 */  addiu      $5, $0, 0x2
    /* ADD84 001ADD84 6451060C */  jal        func_00194590
    /* ADD88 001ADD88 00000000 */   nop
    /* ADD8C 001ADD8C 0A000424 */  addiu      $4, $0, 0xA
    /* ADD90 001ADD90 02000524 */  addiu      $5, $0, 0x2
    /* ADD94 001ADD94 06000624 */  addiu      $6, $0, 0x6
    /* ADD98 001ADD98 08DF070C */  jal        func_001f7c20
    /* ADD9C 001ADD9C 00000000 */   nop
    /* ADDA0 001ADDA0 2D204000 */  daddu      $4, $2, $0
    /* ADDA4 001ADDA4 05000324 */  addiu      $3, $0, 0x5
    /* ADDA8 001ADDA8 000043A0 */  sb         $3, 0x0($2)
    /* ADDAC 001ADDAC 580023DE */  ld         $3, 0x58($17)
    /* ADDB0 001ADDB0 080043FC */  sd         $3, 0x8($2)
    /* ADDB4 001ADDB4 000003DE */  ld         $3, 0x0($16)
    /* ADDB8 001ADDB8 600043FC */  sd         $3, 0x60($2)
    /* ADDBC 001ADDBC 01000524 */  addiu      $5, $0, 0x1
    /* ADDC0 001ADDC0 6451060C */  jal        func_00194590
    /* ADDC4 001ADDC4 00000000 */   nop
    /* ADDC8 001ADDC8 ACB3858F */  lw         $5, -0x4C54($28)
    /* ADDCC 001ADDCC 0C00A48C */  lw         $4, 0xC($5)
    /* ADDD0 001ADDD0 4000033C */  lui        $3, (0x400000 >> 16)
    /* ADDD4 001ADDD4 25188300 */  or         $3, $4, $3
    /* ADDD8 001ADDD8 0C00A3AC */  sw         $3, 0xC($5)
    /* ADDDC 001ADDDC ACB3848F */  lw         $4, -0x4C54($28)
    /* ADDE0 001ADDE0 18008394 */  lhu        $3, 0x18($4)
    /* ADDE4 001ADDE4 05006334 */  ori        $3, $3, 0x5
    /* ADDE8 001ADDE8 180083A4 */  sh         $3, 0x18($4)
    /* ADDEC 001ADDEC 2000BFDF */  ld         $31, 0x20($29)
    /* ADDF0 001ADDF0 1000B17B */  lq         $17, 0x10($29)
    /* ADDF4 001ADDF4 0000B07B */  lq         $16, 0x0($29)
    /* ADDF8 001ADDF8 3000BD27 */  addiu      $29, $29, 0x30
    /* ADDFC 001ADDFC 0800E003 */  jr         $31
    /* ADE00 001ADE00 00000000 */   nop
    /* ADE04 001ADE04 00000000 */  nop
    /* ADE08 001ADE08 00000000 */  nop
    /* ADE0C 001ADE0C 00000000 */  nop
.size func_001adb80, 0x290
