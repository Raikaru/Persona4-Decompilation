.section .text
.set noat
.set noreorder
glabel func_002dd230
    /* 1DD230 002DD230 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1DD234 002DD234 2000BFFF */  sd         $31, 0x20($29)
    /* 1DD238 002DD238 1000B17F */  sq         $17, 0x10($29)
    /* 1DD23C 002DD23C 0000B07F */  sq         $16, 0x0($29)
    /* 1DD240 002DD240 3800908C */  lw         $16, 0x38($4)
    /* 1DD244 002DD244 900D048E */  lw         $4, 0xD90($16)
    /* 1DD248 002DD248 38810B0C */  jal        func_002e04e0
    /* 1DD24C 002DD24C 00000000 */   nop
    /* 1DD250 002DD250 2D884000 */  daddu      $17, $2, $0
    /* 1DD254 002DD254 37010224 */  addiu      $2, $0, 0x137
    /* 1DD258 002DD258 00008244 */  mtc1       $2, $f0
    /* 1DD25C 002DD25C 00000000 */  nop
    /* 1DD260 002DD260 20038046 */  cvt.s.w    $f12, $f0
    /* 1DD264 002DD264 88C1023C */  lui        $2, (0xC1880000 >> 16)
    /* 1DD268 002DD268 00688244 */  mtc1       $2, $f13
    /* 1DD26C 002DD26C 4800A427 */  addiu      $4, $29, 0x48
    /* 1DD270 002DD270 5CCA0A0C */  jal        func_002b2970
    /* 1DD274 002DD274 00000000 */   nop
    /* 1DD278 002DD278 900D048E */  lw         $4, 0xD90($16)
    /* 1DD27C 002DD27C 2C00256E */  ldr        $5, 0x2C($17)
    /* 1DD280 002DD280 3300256A */  ldl        $5, 0x33($17)
    /* 1DD284 002DD284 4800A6DF */  ld         $6, 0x48($29)
    /* 1DD288 002DD288 2D380000 */  daddu      $7, $0, $0
    /* 1DD28C 002DD28C 0A000824 */  addiu      $8, $0, 0xA
    /* 1DD290 002DD290 2D480000 */  daddu      $9, $0, $0
    /* 1DD294 002DD294 88810B0C */  jal        func_002e0620
    /* 1DD298 002DD298 00000000 */   nop
    /* 1DD29C 002DD29C 940D048E */  lw         $4, 0xD94($16)
    /* 1DD2A0 002DD2A0 38810B0C */  jal        func_002e04e0
    /* 1DD2A4 002DD2A4 00000000 */   nop
    /* 1DD2A8 002DD2A8 2D884000 */  daddu      $17, $2, $0
    /* 1DD2AC 002DD2AC 0D44023C */  lui        $2, (0x440D0000 >> 16)
    /* 1DD2B0 002DD2B0 00608244 */  mtc1       $2, $f12
    /* 1DD2B4 002DD2B4 88C1023C */  lui        $2, (0xC1880000 >> 16)
    /* 1DD2B8 002DD2B8 00688244 */  mtc1       $2, $f13
    /* 1DD2BC 002DD2BC 4000A427 */  addiu      $4, $29, 0x40
    /* 1DD2C0 002DD2C0 5CCA0A0C */  jal        func_002b2970
    /* 1DD2C4 002DD2C4 00000000 */   nop
    /* 1DD2C8 002DD2C8 940D048E */  lw         $4, 0xD94($16)
    /* 1DD2CC 002DD2CC 2C00256E */  ldr        $5, 0x2C($17)
    /* 1DD2D0 002DD2D0 3300256A */  ldl        $5, 0x33($17)
    /* 1DD2D4 002DD2D4 4000A6DF */  ld         $6, 0x40($29)
    /* 1DD2D8 002DD2D8 2D380000 */  daddu      $7, $0, $0
    /* 1DD2DC 002DD2DC 0A000824 */  addiu      $8, $0, 0xA
    /* 1DD2E0 002DD2E0 2D480000 */  daddu      $9, $0, $0
    /* 1DD2E4 002DD2E4 88810B0C */  jal        func_002e0620
    /* 1DD2E8 002DD2E8 00000000 */   nop
    /* 1DD2EC 002DD2EC 8C0D048E */  lw         $4, 0xD8C($16)
    /* 1DD2F0 002DD2F0 38810B0C */  jal        func_002e04e0
    /* 1DD2F4 002DD2F4 00000000 */   nop
    /* 1DD2F8 002DD2F8 2D884000 */  daddu      $17, $2, $0
    /* 1DD2FC 002DD2FC 9EFD0224 */  addiu      $2, $0, -0x262
    /* 1DD300 002DD300 00008244 */  mtc1       $2, $f0
    /* 1DD304 002DD304 00000000 */  nop
    /* 1DD308 002DD308 20038046 */  cvt.s.w    $f12, $f0
    /* 1DD30C 002DD30C 1BC4023C */  lui        $2, (0xC41B0000 >> 16)
    /* 1DD310 002DD310 00688244 */  mtc1       $2, $f13
    /* 1DD314 002DD314 3800A427 */  addiu      $4, $29, 0x38
    /* 1DD318 002DD318 5CCA0A0C */  jal        func_002b2970
    /* 1DD31C 002DD31C 00000000 */   nop
    /* 1DD320 002DD320 8C0D048E */  lw         $4, 0xD8C($16)
    /* 1DD324 002DD324 2C00256E */  ldr        $5, 0x2C($17)
    /* 1DD328 002DD328 3300256A */  ldl        $5, 0x33($17)
    /* 1DD32C 002DD32C 3800A6DF */  ld         $6, 0x38($29)
    /* 1DD330 002DD330 2D380000 */  daddu      $7, $0, $0
    /* 1DD334 002DD334 0A000824 */  addiu      $8, $0, 0xA
    /* 1DD338 002DD338 2D480000 */  daddu      $9, $0, $0
    /* 1DD33C 002DD33C 88810B0C */  jal        func_002e0620
    /* 1DD340 002DD340 00000000 */   nop
    /* 1DD344 002DD344 8C0D048E */  lw         $4, 0xD8C($16)
    /* 1DD348 002DD348 03000524 */  addiu      $5, $0, 0x3
    /* 1DD34C 002DD34C 01000624 */  addiu      $6, $0, 0x1
    /* 1DD350 002DD350 3C810B0C */  jal        func_002e04f0
    /* 1DD354 002DD354 00000000 */   nop
    /* 1DD358 002DD358 00608044 */  mtc1       $0, $f12
    /* 1DD35C 002DD35C B443023C */  lui        $2, (0x43B40000 >> 16)
    /* 1DD360 002DD360 00688244 */  mtc1       $2, $f13
    /* 1DD364 002DD364 8C0D048E */  lw         $4, 0xD8C($16)
    /* 1DD368 002DD368 2D280000 */  daddu      $5, $0, $0
    /* 1DD36C 002DD36C 08070624 */  addiu      $6, $0, 0x708
    /* 1DD370 002DD370 2D380000 */  daddu      $7, $0, $0
    /* 1DD374 002DD374 50820B0C */  jal        func_002e0940
    /* 1DD378 002DD378 00000000 */   nop
    /* 1DD37C 002DD37C 8C0D048E */  lw         $4, 0xD8C($16)
    /* 1DD380 002DD380 06000524 */  addiu      $5, $0, 0x6
    /* 1DD384 002DD384 2D300000 */  daddu      $6, $0, $0
    /* 1DD388 002DD388 3C810B0C */  jal        func_002e04f0
    /* 1DD38C 002DD38C 00000000 */   nop
    /* 1DD390 002DD390 2000BFDF */  ld         $31, 0x20($29)
    /* 1DD394 002DD394 1000B17B */  lq         $17, 0x10($29)
    /* 1DD398 002DD398 0000B07B */  lq         $16, 0x0($29)
    /* 1DD39C 002DD39C 5000BD27 */  addiu      $29, $29, 0x50
    /* 1DD3A0 002DD3A0 0800E003 */  jr         $31
    /* 1DD3A4 002DD3A4 00000000 */   nop
    /* 1DD3A8 002DD3A8 00000000 */  nop
    /* 1DD3AC 002DD3AC 00000000 */  nop
.size func_002dd230, 0x180
