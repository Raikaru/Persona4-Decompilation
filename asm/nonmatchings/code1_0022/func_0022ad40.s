.section .text
.set noat
.set noreorder
glabel func_0022ad40
    /* 12AD40 0022AD40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12AD44 0022AD44 0000BFFF */  sd         $31, 0x0($29)
    /* 12AD48 0022AD48 000084DC */  ld         $4, 0x0($4)
    /* 12AD4C 0022AD4C FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* 12AD50 0022AD50 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* 12AD54 0022AD54 3C180200 */  dsll32     $3, $2, 0
    /* 12AD58 0022AD58 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* 12AD5C 0022AD5C 38140200 */  dsll       $2, $2, 16
    /* 12AD60 0022AD60 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* 12AD64 0022AD64 25284300 */  or         $5, $2, $3
    /* 12AD68 0022AD68 FC4E060C */  jal        func_00193bf0
    /* 12AD6C 0022AD6C 00000000 */   nop
    /* 12AD70 0022AD70 1E004014 */  bnez       $2, .L0022ADEC
    /* 12AD74 0022AD74 00000000 */   nop
    /* 12AD78 0022AD78 35140424 */  addiu      $4, $0, 0x1435
    /* 12AD7C 0022AD7C 2D280000 */  daddu      $5, $0, $0
    /* 12AD80 0022AD80 E418040C */  jal        func_00106390
    /* 12AD84 0022AD84 00000000 */   nop
    /* 12AD88 0022AD88 C5150424 */  addiu      $4, $0, 0x15C5
    /* 12AD8C 0022AD8C 2D280000 */  daddu      $5, $0, $0
    /* 12AD90 0022AD90 E418040C */  jal        func_00106390
    /* 12AD94 0022AD94 00000000 */   nop
    /* 12AD98 0022AD98 C6150424 */  addiu      $4, $0, 0x15C6
    /* 12AD9C 0022AD9C 2D280000 */  daddu      $5, $0, $0
    /* 12ADA0 0022ADA0 E418040C */  jal        func_00106390
    /* 12ADA4 0022ADA4 00000000 */   nop
    /* 12ADA8 0022ADA8 C7150424 */  addiu      $4, $0, 0x15C7
    /* 12ADAC 0022ADAC 2D280000 */  daddu      $5, $0, $0
    /* 12ADB0 0022ADB0 E418040C */  jal        func_00106390
    /* 12ADB4 0022ADB4 00000000 */   nop
    /* 12ADB8 0022ADB8 C8150424 */  addiu      $4, $0, 0x15C8
    /* 12ADBC 0022ADBC 2D280000 */  daddu      $5, $0, $0
    /* 12ADC0 0022ADC0 E418040C */  jal        func_00106390
    /* 12ADC4 0022ADC4 00000000 */   nop
    /* 12ADC8 0022ADC8 ACB3848F */  lw         $4, -0x4C54($28)
    /* 12ADCC 0022ADCC 0C00838C */  lw         $3, 0xC($4)
    /* 12ADD0 0022ADD0 F7FF023C */  lui        $2, (0xFFF7FFFF >> 16)
    /* 12ADD4 0022ADD4 FFFF4234 */  ori        $2, $2, (0xFFF7FFFF & 0xFFFF)
    /* 12ADD8 0022ADD8 24106200 */  and        $2, $3, $2
    /* 12ADDC 0022ADDC 0C0082AC */  sw         $2, 0xC($4)
    /* 12ADE0 0022ADE0 2D100000 */  daddu      $2, $0, $0
    /* 12ADE4 0022ADE4 02000010 */  b          .L0022ADF0
    /* 12ADE8 0022ADE8 00000000 */   nop
  .L0022ADEC:
    /* 12ADEC 0022ADEC 01000224 */  addiu      $2, $0, 0x1
  .L0022ADF0:
    /* 12ADF0 0022ADF0 0000BFDF */  ld         $31, 0x0($29)
    /* 12ADF4 0022ADF4 1000BD27 */  addiu      $29, $29, 0x10
    /* 12ADF8 0022ADF8 0800E003 */  jr         $31
    /* 12ADFC 0022ADFC 00000000 */   nop
.size func_0022ad40, 0xc0
