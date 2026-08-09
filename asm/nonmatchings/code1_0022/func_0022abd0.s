.section .text
.set noat
.set noreorder
glabel func_0022abd0
    /* 12ABD0 0022ABD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12ABD4 0022ABD4 0000BFFF */  sd         $31, 0x0($29)
    /* 12ABD8 0022ABD8 000084DC */  ld         $4, 0x0($4)
    /* 12ABDC 0022ABDC FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* 12ABE0 0022ABE0 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* 12ABE4 0022ABE4 3C180200 */  dsll32     $3, $2, 0
    /* 12ABE8 0022ABE8 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* 12ABEC 0022ABEC 38140200 */  dsll       $2, $2, 16
    /* 12ABF0 0022ABF0 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* 12ABF4 0022ABF4 25284300 */  or         $5, $2, $3
    /* 12ABF8 0022ABF8 FC4E060C */  jal        func_00193bf0
    /* 12ABFC 0022ABFC 00000000 */   nop
    /* 12AC00 0022AC00 26004014 */  bnez       $2, .L0022AC9C
    /* 12AC04 0022AC04 00000000 */   nop
    /* 12AC08 0022AC08 FF150424 */  addiu      $4, $0, 0x15FF
    /* 12AC0C 0022AC0C 2D280000 */  daddu      $5, $0, $0
    /* 12AC10 0022AC10 E418040C */  jal        func_00106390
    /* 12AC14 0022AC14 00000000 */   nop
    /* 12AC18 0022AC18 CF150424 */  addiu      $4, $0, 0x15CF
    /* 12AC1C 0022AC1C 2D280000 */  daddu      $5, $0, $0
    /* 12AC20 0022AC20 E418040C */  jal        func_00106390
    /* 12AC24 0022AC24 00000000 */   nop
    /* 12AC28 0022AC28 D0150424 */  addiu      $4, $0, 0x15D0
    /* 12AC2C 0022AC2C 2D280000 */  daddu      $5, $0, $0
    /* 12AC30 0022AC30 E418040C */  jal        func_00106390
    /* 12AC34 0022AC34 00000000 */   nop
    /* 12AC38 0022AC38 D1150424 */  addiu      $4, $0, 0x15D1
    /* 12AC3C 0022AC3C 2D280000 */  daddu      $5, $0, $0
    /* 12AC40 0022AC40 E418040C */  jal        func_00106390
    /* 12AC44 0022AC44 00000000 */   nop
    /* 12AC48 0022AC48 D2150424 */  addiu      $4, $0, 0x15D2
    /* 12AC4C 0022AC4C 2D280000 */  daddu      $5, $0, $0
    /* 12AC50 0022AC50 E418040C */  jal        func_00106390
    /* 12AC54 0022AC54 00000000 */   nop
    /* 12AC58 0022AC58 D3150424 */  addiu      $4, $0, 0x15D3
    /* 12AC5C 0022AC5C 2D280000 */  daddu      $5, $0, $0
    /* 12AC60 0022AC60 E418040C */  jal        func_00106390
    /* 12AC64 0022AC64 00000000 */   nop
    /* 12AC68 0022AC68 D4150424 */  addiu      $4, $0, 0x15D4
    /* 12AC6C 0022AC6C 2D280000 */  daddu      $5, $0, $0
    /* 12AC70 0022AC70 E418040C */  jal        func_00106390
    /* 12AC74 0022AC74 00000000 */   nop
    /* 12AC78 0022AC78 ACB3848F */  lw         $4, -0x4C54($28)
    /* 12AC7C 0022AC7C 0C00838C */  lw         $3, 0xC($4)
    /* 12AC80 0022AC80 F7FF023C */  lui        $2, (0xFFF7FFFF >> 16)
    /* 12AC84 0022AC84 FFFF4234 */  ori        $2, $2, (0xFFF7FFFF & 0xFFFF)
    /* 12AC88 0022AC88 24106200 */  and        $2, $3, $2
    /* 12AC8C 0022AC8C 0C0082AC */  sw         $2, 0xC($4)
    /* 12AC90 0022AC90 2D100000 */  daddu      $2, $0, $0
    /* 12AC94 0022AC94 02000010 */  b          .L0022ACA0
    /* 12AC98 0022AC98 00000000 */   nop
  .L0022AC9C:
    /* 12AC9C 0022AC9C 01000224 */  addiu      $2, $0, 0x1
  .L0022ACA0:
    /* 12ACA0 0022ACA0 0000BFDF */  ld         $31, 0x0($29)
    /* 12ACA4 0022ACA4 1000BD27 */  addiu      $29, $29, 0x10
    /* 12ACA8 0022ACA8 0800E003 */  jr         $31
    /* 12ACAC 0022ACAC 00000000 */   nop
.size func_0022abd0, 0xe0
