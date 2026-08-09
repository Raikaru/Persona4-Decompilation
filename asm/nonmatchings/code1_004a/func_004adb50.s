.section .text
.set noat
.set noreorder
glabel func_004adb50
    /* 3ADB50 004ADB50 C0FEBD27 */  addiu      $29, $29, -0x140
    /* 3ADB54 004ADB54 7000BFFF */  sd         $31, 0x70($29)
    /* 3ADB58 004ADB58 6000B57F */  sq         $21, 0x60($29)
    /* 3ADB5C 004ADB5C 5000B47F */  sq         $20, 0x50($29)
    /* 3ADB60 004ADB60 4000B37F */  sq         $19, 0x40($29)
    /* 3ADB64 004ADB64 3000B27F */  sq         $18, 0x30($29)
    /* 3ADB68 004ADB68 2000B17F */  sq         $17, 0x20($29)
    /* 3ADB6C 004ADB6C 1000B07F */  sq         $16, 0x10($29)
    /* 3ADB70 004ADB70 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 3ADB74 004ADB74 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3ADB78 004ADB78 2D988000 */  daddu      $19, $4, $0
    /* 3ADB7C 004ADB7C 2C00918C */  lw         $17, 0x2C($4)
    /* 3ADB80 004ADB80 9000908C */  lw         $16, 0x90($4)
    /* 3ADB84 004ADB84 2800948C */  lw         $20, 0x28($4)
    /* 3ADB88 004ADB88 9800928C */  lw         $18, 0x98($4)
    /* 3ADB8C 004ADB8C 2A183002 */  slt        $3, $17, $16
    /* 3ADB90 004ADB90 03006014 */  bnez       $3, .L004ADBA0
    /* 3ADB94 004ADB94 00000000 */   nop
    /* 3ADB98 004ADB98 A8000016 */  bnez       $16, .L004ADE3C
    /* 3ADB9C 004ADB9C 00000000 */   nop
  .L004ADBA0:
    /* 3ADBA0 004ADBA0 C000A427 */  addiu      $4, $29, 0xC0
    /* 3ADBA4 004ADBA4 10006526 */  addiu      $5, $19, 0x10
    /* 3ADBA8 004ADBA8 5428120C */  jal        func_0048a150
    /* 3ADBAC 004ADBAC 00000000 */   nop
    /* 3ADBB0 004ADBB0 A000648E */  lw         $4, 0xA0($19)
    /* 3ADBB4 004ADBB4 C000A527 */  addiu      $5, $29, 0xC0
    /* 3ADBB8 004ADBB8 2D300000 */  daddu      $6, $0, $0
    /* 3ADBBC 004ADBBC 70E8110C */  jal        func_0047a1c0
    /* 3ADBC0 004ADBC0 00000000 */   nop
    /* 3ADBC4 004ADBC4 200060C6 */  lwc1       $f0, 0x20($19)
    /* 3ADBC8 004ADBC8 3001A0E7 */  swc1       $f0, 0x130($29)
    /* 3ADBCC 004ADBCC 2C01A0E7 */  swc1       $f0, 0x12C($29)
    /* 3ADBD0 004ADBD0 2801A0E7 */  swc1       $f0, 0x128($29)
    /* 3ADBD4 004ADBD4 A000648E */  lw         $4, 0xA0($19)
    /* 3ADBD8 004ADBD8 2801A527 */  addiu      $5, $29, 0x128
    /* 3ADBDC 004ADBDC 02000624 */  addiu      $6, $0, 0x2
    /* 3ADBE0 004ADBE0 78E8110C */  jal        func_0047a1e0
    /* 3ADBE4 004ADBE4 00000000 */   nop
    /* 3ADBE8 004ADBE8 000060C6 */  lwc1       $f0, 0x0($19)
    /* 3ADBEC 004ADBEC 2801A0E7 */  swc1       $f0, 0x128($29)
    /* 3ADBF0 004ADBF0 040060C6 */  lwc1       $f0, 0x4($19)
    /* 3ADBF4 004ADBF4 2C01A0E7 */  swc1       $f0, 0x12C($29)
    /* 3ADBF8 004ADBF8 080060C6 */  lwc1       $f0, 0x8($19)
    /* 3ADBFC 004ADBFC 3001A0E7 */  swc1       $f0, 0x130($29)
    /* 3ADC00 004ADC00 A000648E */  lw         $4, 0xA0($19)
    /* 3ADC04 004ADC04 2801A527 */  addiu      $5, $29, 0x128
    /* 3ADC08 004ADC08 02000624 */  addiu      $6, $0, 0x2
    /* 3ADC0C 004ADC0C 60E8110C */  jal        func_0047a180
    /* 3ADC10 004ADC10 00000000 */   nop
    /* 3ADC14 004ADC14 A000648E */  lw         $4, 0xA0($19)
    /* 3ADC18 004ADC18 2D280000 */  daddu      $5, $0, $0
    /* 3ADC1C 004ADC1C 94006CC6 */  lwc1       $f12, 0x94($19)
    /* 3ADC20 004ADC20 38E8110C */  jal        func_0047a0e0
    /* 3ADC24 004ADC24 00000000 */   nop
    /* 3ADC28 004ADC28 A000648E */  lw         $4, 0xA0($19)
    /* 3ADC2C 004ADC2C 9CE3110C */  jal        func_00478e70
    /* 3ADC30 004ADC30 00000000 */   nop
    /* 3ADC34 004ADC34 9C00638E */  lw         $3, 0x9C($19)
    /* 3ADC38 004ADC38 80006010 */  beqz       $3, .L004ADE3C
    /* 3ADC3C 004ADC3C 00000000 */   nop
    /* 3ADC40 004ADC40 30006426 */  addiu      $4, $19, 0x30
    /* 3ADC44 004ADC44 54006526 */  addiu      $5, $19, 0x54
    /* 3ADC48 004ADC48 2D302002 */  daddu      $6, $17, $0
    /* 3ADC4C 004ADC4C 2D380002 */  daddu      $7, $16, $0
    /* 3ADC50 004ADC50 F42A120C */  jal        func_0048abd0
    /* 3ADC54 004ADC54 00000000 */   nop
    /* 3ADC58 004ADC58 2D184000 */  daddu      $3, $2, $0
    /* 3ADC5C 004ADC5C 2400628E */  lw         $2, 0x24($19)
    /* 3ADC60 004ADC60 3C01A2AF */  sw         $2, 0x13C($29)
    /* 3ADC64 004ADC64 3C01A227 */  addiu      $2, $29, 0x13C
    /* 3ADC68 004ADC68 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3ADC6C 004ADC6C 0000428C */  lw         $2, 0x0($2)
    /* 3ADC70 004ADC70 88160270 */  pextlb     $2, $0, $2
    /* 3ADC74 004ADC74 88150270 */  pextlh     $2, $0, $2
    /* 3ADC78 004ADC78 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3ADC7C 004ADC7C 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3ADC80 004ADC80 00000244 */  mfc1       $2, $f0
    /* 3ADC84 004ADC84 00000000 */  nop
    /* 3ADC88 004ADC88 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3ADC8C 004ADC8C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3ADC90 004ADC90 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3ADC94 004ADC94 3801A3AF */  sw         $3, 0x138($29)
    /* 3ADC98 004ADC98 3801A227 */  addiu      $2, $29, 0x138
    /* 3ADC9C 004ADC9C 0000428C */  lw         $2, 0x0($2)
    /* 3ADCA0 004ADCA0 88160270 */  pextlb     $2, $0, $2
    /* 3ADCA4 004ADCA4 88150270 */  pextlh     $2, $0, $2
    /* 3ADCA8 004ADCA8 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3ADCAC 004ADCAC 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3ADCB0 004ADCB0 00000244 */  mfc1       $2, $f0
    /* 3ADCB4 004ADCB4 00000000 */  nop
    /* 3ADCB8 004ADCB8 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3ADCBC 004ADCBC 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3ADCC0 004ADCC0 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3ADCC4 004ADCC4 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3ADCC8 004ADCC8 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3ADCCC 004ADCCC 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3ADCD0 004ADCD0 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3ADCD4 004ADCD4 00502248 */  qmfc2.ni   $2, $vf10
    /* 3ADCD8 004ADCD8 C8150270 */  ppach      $2, $0, $2
    /* 3ADCDC 004ADCDC C8160270 */  ppacb      $2, $0, $2
    /* 3ADCE0 004ADCE0 3401A2AF */  sw         $2, 0x134($29)
    /* 3ADCE4 004ADCE4 3401B58F */  lw         $21, 0x134($29)
    /* 3ADCE8 004ADCE8 64006426 */  addiu      $4, $19, 0x64
    /* 3ADCEC 004ADCEC 2D282002 */  daddu      $5, $17, $0
    /* 3ADCF0 004ADCF0 2D300002 */  daddu      $6, $16, $0
    /* 3ADCF4 004ADCF4 FC2B120C */  jal        func_0048aff0
    /* 3ADCF8 004ADCF8 00000000 */   nop
    /* 3ADCFC 004ADCFC 2041033C */  lui        $3, (0x41200000 >> 16)
    /* 3ADD00 004ADD00 00088344 */  mtc1       $3, $f1
    /* 3ADD04 004ADD04 00000000 */  nop
    /* 3ADD08 004ADD08 43000146 */  div.s      $f1, $f0, $f1
    /* 3ADD0C 004ADD0C 200060C6 */  lwc1       $f0, 0x20($19)
    /* 3ADD10 004ADD10 420D0046 */  mul.s      $f21, $f1, $f0
    /* 3ADD14 004ADD14 2D800000 */  daddu      $16, $0, $0
    /* 3ADD18 004ADD18 00A08044 */  mtc1       $0, $f20
    /* 3ADD1C 004ADD1C 44000010 */  b          .L004ADE30
    /* 3ADD20 004ADD20 00000000 */   nop
  .L004ADD24:
    /* 3ADD24 004ADD24 A000648E */  lw         $4, 0xA0($19)
    /* 3ADD28 004ADD28 2D280002 */  daddu      $5, $16, $0
    /* 3ADD2C 004ADD2C C000A627 */  addiu      $6, $29, 0xC0
    /* 3ADD30 004ADD30 44E9110C */  jal        func_0047a510
    /* 3ADD34 004ADD34 00000000 */   nop
    /* 3ADD38 004ADD38 3B004010 */  beqz       $2, .L004ADE28
    /* 3ADD3C 004ADD3C 00000000 */   nop
    /* 3ADD40 004ADD40 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* 3ADD44 004ADD44 1001A0E7 */  swc1       $f0, 0x110($29)
    /* 3ADD48 004ADD48 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* 3ADD4C 004ADD4C 1401A0E7 */  swc1       $f0, 0x114($29)
    /* 3ADD50 004ADD50 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* 3ADD54 004ADD54 1801A0E7 */  swc1       $f0, 0x118($29)
    /* 3ADD58 004ADD58 1C01B4E7 */  swc1       $f20, 0x11C($29)
    /* 3ADD5C 004ADD5C 0000448E */  lw         $4, 0x0($18)
    /* 3ADD60 004ADD60 1001A527 */  addiu      $5, $29, 0x110
    /* 3ADD64 004ADD64 7C18120C */  jal        func_004861f0
    /* 3ADD68 004ADD68 00000000 */   nop
    /* 3ADD6C 004ADD6C C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* 3ADD70 004ADD70 8000A0E7 */  swc1       $f0, 0x80($29)
    /* 3ADD74 004ADD74 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* 3ADD78 004ADD78 8400A0E7 */  swc1       $f0, 0x84($29)
    /* 3ADD7C 004ADD7C C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* 3ADD80 004ADD80 8800A0E7 */  swc1       $f0, 0x88($29)
    /* 3ADD84 004ADD84 8C00B4E7 */  swc1       $f20, 0x8C($29)
    /* 3ADD88 004ADD88 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* 3ADD8C 004ADD8C 9000A0E7 */  swc1       $f0, 0x90($29)
    /* 3ADD90 004ADD90 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* 3ADD94 004ADD94 9400A0E7 */  swc1       $f0, 0x94($29)
    /* 3ADD98 004ADD98 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* 3ADD9C 004ADD9C 9800A0E7 */  swc1       $f0, 0x98($29)
    /* 3ADDA0 004ADDA0 9C00B4E7 */  swc1       $f20, 0x9C($29)
    /* 3ADDA4 004ADDA4 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* 3ADDA8 004ADDA8 A000A0E7 */  swc1       $f0, 0xA0($29)
    /* 3ADDAC 004ADDAC E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* 3ADDB0 004ADDB0 A400A0E7 */  swc1       $f0, 0xA4($29)
    /* 3ADDB4 004ADDB4 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* 3ADDB8 004ADDB8 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 3ADDBC 004ADDBC AC00B4E7 */  swc1       $f20, 0xAC($29)
    /* 3ADDC0 004ADDC0 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* 3ADDC4 004ADDC4 B000A0E7 */  swc1       $f0, 0xB0($29)
    /* 3ADDC8 004ADDC8 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* 3ADDCC 004ADDCC B400A0E7 */  swc1       $f0, 0xB4($29)
    /* 3ADDD0 004ADDD0 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* 3ADDD4 004ADDD4 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* 3ADDD8 004ADDD8 BC00B4E7 */  swc1       $f20, 0xBC($29)
    /* 3ADDDC 004ADDDC 8000A427 */  addiu      $4, $29, 0x80
    /* 3ADDE0 004ADDE0 602A120C */  jal        func_0048a980
    /* 3ADDE4 004ADDE4 00000000 */   nop
    /* 3ADDE8 004ADDE8 0001A527 */  addiu      $5, $29, 0x100
    /* 3ADDEC 004ADDEC 0000AAF8 */  sqc2       $vf10, 0x0($5)
    /* 3ADDF0 004ADDF0 0000448E */  lw         $4, 0x0($18)
    /* 3ADDF4 004ADDF4 CC18120C */  jal        func_00486330
    /* 3ADDF8 004ADDF8 00000000 */   nop
    /* 3ADDFC 004ADDFC 0000448E */  lw         $4, 0x0($18)
    /* 3ADE00 004ADE00 06AB0046 */  mov.s      $f12, $f21
    /* 3ADE04 004ADE04 0019120C */  jal        func_00486400
    /* 3ADE08 004ADE08 00000000 */   nop
    /* 3ADE0C 004ADE0C 0000448E */  lw         $4, 0x0($18)
    /* 3ADE10 004ADE10 2D28A002 */  daddu      $5, $21, $0
    /* 3ADE14 004ADE14 7019120C */  jal        func_004865c0
    /* 3ADE18 004ADE18 00000000 */   nop
    /* 3ADE1C 004ADE1C 0000448E */  lw         $4, 0x0($18)
    /* 3ADE20 004ADE20 8C15120C */  jal        func_00485630
    /* 3ADE24 004ADE24 00000000 */   nop
  .L004ADE28:
    /* 3ADE28 004ADE28 01001026 */  addiu      $16, $16, 0x1
    /* 3ADE2C 004ADE2C 04005226 */  addiu      $18, $18, 0x4
  .L004ADE30:
    /* 3ADE30 004ADE30 2B181402 */  sltu       $3, $16, $20
    /* 3ADE34 004ADE34 BBFF6014 */  bnez       $3, .L004ADD24
    /* 3ADE38 004ADE38 00000000 */   nop
  .L004ADE3C:
    /* 3ADE3C 004ADE3C 2C00638E */  lw         $3, 0x2C($19)
    /* 3ADE40 004ADE40 01006324 */  addiu      $3, $3, 0x1
    /* 3ADE44 004ADE44 2C0063AE */  sw         $3, 0x2C($19)
    /* 3ADE48 004ADE48 7000BFDF */  ld         $31, 0x70($29)
    /* 3ADE4C 004ADE4C 6000B57B */  lq         $21, 0x60($29)
    /* 3ADE50 004ADE50 5000B47B */  lq         $20, 0x50($29)
    /* 3ADE54 004ADE54 4000B37B */  lq         $19, 0x40($29)
    /* 3ADE58 004ADE58 3000B27B */  lq         $18, 0x30($29)
    /* 3ADE5C 004ADE5C 2000B17B */  lq         $17, 0x20($29)
    /* 3ADE60 004ADE60 1000B07B */  lq         $16, 0x10($29)
    /* 3ADE64 004ADE64 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 3ADE68 004ADE68 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3ADE6C 004ADE6C 4001BD27 */  addiu      $29, $29, 0x140
    /* 3ADE70 004ADE70 0800E003 */  jr         $31
    /* 3ADE74 004ADE74 00000000 */   nop
    /* 3ADE78 004ADE78 00000000 */  nop
    /* 3ADE7C 004ADE7C 00000000 */  nop
.size func_004adb50, 0x330
