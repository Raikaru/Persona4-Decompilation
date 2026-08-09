.section .text
.set noat
.set noreorder
glabel func_004ad280
    /* 3AD280 004AD280 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AD284 004AD284 1000BFFF */  sd         $31, 0x10($29)
    /* 3AD288 004AD288 0000B07F */  sq         $16, 0x0($29)
    /* 3AD28C 004AD28C 2D808000 */  daddu      $16, $4, $0
    /* 3AD290 004AD290 B400848C */  lw         $4, 0xB4($4)
    /* 3AD294 004AD294 2D280000 */  daddu      $5, $0, $0
    /* 3AD298 004AD298 20E8110C */  jal        func_0047a080
    /* 3AD29C 004AD29C 00000000 */   nop
    /* 3AD2A0 004AD2A0 004F023C */  lui        $2, (0x4F000000 >> 16)
    /* 3AD2A4 004AD2A4 00088244 */  mtc1       $2, $f1
    /* 3AD2A8 004AD2A8 00000000 */  nop
    /* 3AD2AC 004AD2AC 36080046 */  c.le.s     $f1, $f0
    /* 3AD2B0 004AD2B0 05000145 */  bc1t       .L004AD2C8
    /* 3AD2B4 004AD2B4 00000000 */   nop
    /* 3AD2B8 004AD2B8 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3AD2BC 004AD2BC 00000344 */  mfc1       $3, $f0
    /* 3AD2C0 004AD2C0 06000010 */  b          .L004AD2DC
    /* 3AD2C4 004AD2C4 00000000 */   nop
  .L004AD2C8:
    /* 3AD2C8 004AD2C8 01000146 */  sub.s      $f0, $f0, $f1
    /* 3AD2CC 004AD2CC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3AD2D0 004AD2D0 00000344 */  mfc1       $3, $f0
    /* 3AD2D4 004AD2D4 0080023C */  lui        $2, %hi(D_80000001)
    /* 3AD2D8 004AD2D8 25186200 */  or         $3, $3, $2
  .L004AD2DC:
    /* 3AD2DC 004AD2DC 01006424 */  addiu      $4, $3, %lo(D_80000001)
    /* 3AD2E0 004AD2E0 9C00028E */  lw         $2, 0x9C($16)
    /* 3AD2E4 004AD2E4 2B084400 */  sltu       $1, $2, $4
    /* 3AD2E8 004AD2E8 03002010 */  beqz       $1, .L004AD2F8
    /* 3AD2EC 004AD2EC 00000000 */   nop
    /* 3AD2F0 004AD2F0 2D004014 */  bnez       $2, .L004AD3A8
    /* 3AD2F4 004AD2F4 00000000 */   nop
  .L004AD2F8:
    /* 3AD2F8 004AD2F8 B8000392 */  lbu        $3, 0xB8($16)
    /* 3AD2FC 004AD2FC 01000224 */  addiu      $2, $0, 0x1
    /* 3AD300 004AD300 11006214 */  bne        $3, $2, .L004AD348
    /* 3AD304 004AD304 00000000 */   nop
    /* 3AD308 004AD308 7400028E */  lw         $2, 0x74($16)
    /* 3AD30C 004AD30C 2B088200 */  sltu       $1, $4, $2
    /* 3AD310 004AD310 23002014 */  bnez       $1, .L004AD3A0
    /* 3AD314 004AD314 00000000 */   nop
    /* 3AD318 004AD318 700000C6 */  lwc1       $f0, 0x70($16)
    /* 3AD31C 004AD31C 60008046 */  cvt.s.w    $f1, $f0
    /* 3AD320 004AD320 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AD324 004AD324 00008244 */  mtc1       $2, $f0
    /* 3AD328 004AD328 00000000 */  nop
    /* 3AD32C 004AD32C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 3AD330 004AD330 B400048E */  lw         $4, 0xB4($16)
    /* 3AD334 004AD334 2D280000 */  daddu      $5, $0, $0
    /* 3AD338 004AD338 98E7110C */  jal        func_00479e60
    /* 3AD33C 004AD33C 00000000 */   nop
    /* 3AD340 004AD340 17000010 */  b          .L004AD3A0
    /* 3AD344 004AD344 00000000 */   nop
  .L004AD348:
    /* 3AD348 004AD348 80000292 */  lbu        $2, 0x80($16)
    /* 3AD34C 004AD34C 14004010 */  beqz       $2, .L004AD3A0
    /* 3AD350 004AD350 00000000 */   nop
    /* 3AD354 004AD354 7000028E */  lw         $2, 0x70($16)
    /* 3AD358 004AD358 2B088200 */  sltu       $1, $4, $2
    /* 3AD35C 004AD35C 10002014 */  bnez       $1, .L004AD3A0
    /* 3AD360 004AD360 00000000 */   nop
    /* 3AD364 004AD364 7400028E */  lw         $2, 0x74($16)
    /* 3AD368 004AD368 2B088200 */  sltu       $1, $4, $2
    /* 3AD36C 004AD36C 0C002010 */  beqz       $1, .L004AD3A0
    /* 3AD370 004AD370 00000000 */   nop
    /* 3AD374 004AD374 00008244 */  mtc1       $2, $f0
    /* 3AD378 004AD378 00000000 */  nop
    /* 3AD37C 004AD37C 60008046 */  cvt.s.w    $f1, $f0
    /* 3AD380 004AD380 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AD384 004AD384 00008244 */  mtc1       $2, $f0
    /* 3AD388 004AD388 00000000 */  nop
    /* 3AD38C 004AD38C 010B0046 */  sub.s      $f12, $f1, $f0
    /* 3AD390 004AD390 B400048E */  lw         $4, 0xB4($16)
    /* 3AD394 004AD394 2D280000 */  daddu      $5, $0, $0
    /* 3AD398 004AD398 98E7110C */  jal        func_00479e60
    /* 3AD39C 004AD39C 00000000 */   nop
  .L004AD3A0:
    /* 3AD3A0 004AD3A0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AD3A4 004AD3A4 080002AE */  sw         $2, 0x8($16)
  .L004AD3A8:
    /* 3AD3A8 004AD3A8 38000496 */  lhu        $4, 0x38($16)
    /* 3AD3AC 004AD3AC 3405120C */  jal        func_004814d0
    /* 3AD3B0 004AD3B0 00000000 */   nop
    /* 3AD3B4 004AD3B4 2D204000 */  daddu      $4, $2, $0
    /* 3AD3B8 004AD3B8 2D280002 */  daddu      $5, $16, $0
    /* 3AD3BC 004AD3BC 0CB4120C */  jal        func_004ad030
    /* 3AD3C0 004AD3C0 00000000 */   nop
    /* 3AD3C4 004AD3C4 1000BFDF */  ld         $31, 0x10($29)
    /* 3AD3C8 004AD3C8 0000B07B */  lq         $16, 0x0($29)
    /* 3AD3CC 004AD3CC 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AD3D0 004AD3D0 0800E003 */  jr         $31
    /* 3AD3D4 004AD3D4 00000000 */   nop
    /* 3AD3D8 004AD3D8 00000000 */  nop
    /* 3AD3DC 004AD3DC 00000000 */  nop
.size func_004ad280, 0x160
