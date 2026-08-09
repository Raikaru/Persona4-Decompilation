.section .text
.set noat
.set noreorder
glabel func_001ad280
    /* AD280 001AD280 D0FFBD27 */  addiu      $29, $29, -0x30
    /* AD284 001AD284 1000BFFF */  sd         $31, 0x10($29)
    /* AD288 001AD288 0000B07F */  sq         $16, 0x0($29)
    /* AD28C 001AD28C 2D808000 */  daddu      $16, $4, $0
    /* AD290 001AD290 EC80060C */  jal        func_001a03b0
    /* AD294 001AD294 00000000 */   nop
    /* AD298 001AD298 ACB3828F */  lw         $2, -0x4C54($28)
    /* AD29C 001AD29C 7001428C */  lw         $2, 0x170($2)
    /* AD2A0 001AD2A0 3000448C */  lw         $4, 0x30($2)
    /* AD2A4 001AD2A4 3000058E */  lw         $5, 0x30($16)
    /* AD2A8 001AD2A8 2D300000 */  daddu      $6, $0, $0
    /* AD2AC 001AD2AC 5479060C */  jal        func_0019e550
    /* AD2B0 001AD2B0 00000000 */   nop
    /* AD2B4 001AD2B4 2D204000 */  daddu      $4, $2, $0
    /* AD2B8 001AD2B8 000003DE */  ld         $3, 0x0($16)
    /* AD2BC 001AD2BC 600043FC */  sd         $3, 0x60($2)
    /* AD2C0 001AD2C0 01000524 */  addiu      $5, $0, 0x1
    /* AD2C4 001AD2C4 6451060C */  jal        func_00194590
    /* AD2C8 001AD2C8 00000000 */   nop
    /* AD2CC 001AD2CC ACB3828F */  lw         $2, -0x4C54($28)
    /* AD2D0 001AD2D0 7001428C */  lw         $2, 0x170($2)
    /* AD2D4 001AD2D4 3000048E */  lw         $4, 0x30($16)
    /* AD2D8 001AD2D8 3000458C */  lw         $5, 0x30($2)
    /* AD2DC 001AD2DC 2D300000 */  daddu      $6, $0, $0
    /* AD2E0 001AD2E0 5479060C */  jal        func_0019e550
    /* AD2E4 001AD2E4 00000000 */   nop
    /* AD2E8 001AD2E8 2D204000 */  daddu      $4, $2, $0
    /* AD2EC 001AD2EC 000003DE */  ld         $3, 0x0($16)
    /* AD2F0 001AD2F0 600043FC */  sd         $3, 0x60($2)
    /* AD2F4 001AD2F4 01000524 */  addiu      $5, $0, 0x1
    /* AD2F8 001AD2F8 6451060C */  jal        func_00194590
    /* AD2FC 001AD2FC 00000000 */   nop
    /* AD300 001AD300 18000296 */  lhu        $2, 0x18($16)
    /* AD304 001AD304 00024234 */  ori        $2, $2, 0x200
    /* AD308 001AD308 180002A6 */  sh         $2, 0x18($16)
    /* AD30C 001AD30C 03000424 */  addiu      $4, $0, 0x3
    /* AD310 001AD310 FF0F0524 */  addiu      $5, $0, 0xFFF
    /* AD314 001AD314 C04D070C */  jal        func_001d3700
    /* AD318 001AD318 00000000 */   nop
    /* AD31C 001AD31C 2D204000 */  daddu      $4, $2, $0
    /* AD320 001AD320 000003DE */  ld         $3, 0x0($16)
    /* AD324 001AD324 600043FC */  sd         $3, 0x60($2)
    /* AD328 001AD328 2D280000 */  daddu      $5, $0, $0
    /* AD32C 001AD32C 6451060C */  jal        func_00194590
    /* AD330 001AD330 00000000 */   nop
    /* AD334 001AD334 2D200002 */  daddu      $4, $16, $0
    /* AD338 001AD338 09000524 */  addiu      $5, $0, 0x9
    /* AD33C 001AD33C 48F2060C */  jal        func_001bc920
    /* AD340 001AD340 00000000 */   nop
    /* AD344 001AD344 2D204000 */  daddu      $4, $2, $0
    /* AD348 001AD348 000003DE */  ld         $3, 0x0($16)
    /* AD34C 001AD34C 600043FC */  sd         $3, 0x60($2)
    /* AD350 001AD350 2D280000 */  daddu      $5, $0, $0
    /* AD354 001AD354 6451060C */  jal        func_00194590
    /* AD358 001AD358 00000000 */   nop
    /* AD35C 001AD35C 05000224 */  addiu      $2, $0, 0x5
    /* AD360 001AD360 2000A2A7 */  sh         $2, 0x20($29)
    /* AD364 001AD364 2000A427 */  addiu      $4, $29, 0x20
    /* AD368 001AD368 C8E9070C */  jal        func_001fa720
    /* AD36C 001AD36C 00000000 */   nop
    /* AD370 001AD370 2D204000 */  daddu      $4, $2, $0
    /* AD374 001AD374 000003DE */  ld         $3, 0x0($16)
    /* AD378 001AD378 600043FC */  sd         $3, 0x60($2)
    /* AD37C 001AD37C 01000524 */  addiu      $5, $0, 0x1
    /* AD380 001AD380 6451060C */  jal        func_00194590
    /* AD384 001AD384 00000000 */   nop
    /* AD388 001AD388 18AE070C */  jal        func_001eb860
    /* AD38C 001AD38C 00000000 */   nop
    /* AD390 001AD390 01000324 */  addiu      $3, $0, 0x1
    /* AD394 001AD394 0B004314 */  bne        $2, $3, .L001AD3C4
    /* AD398 001AD398 00000000 */   nop
    /* AD39C 001AD39C ACB3848F */  lw         $4, -0x4C54($28)
    /* AD3A0 001AD3A0 0C00838C */  lw         $3, 0xC($4)
    /* AD3A4 001AD3A4 FFDF0224 */  addiu      $2, $0, -0x2001
    /* AD3A8 001AD3A8 24106200 */  and        $2, $3, $2
    /* AD3AC 001AD3AC 0C0082AC */  sw         $2, 0xC($4)
    /* AD3B0 001AD3B0 ACB3828F */  lw         $2, -0x4C54($28)
    /* AD3B4 001AD3B4 D40D448C */  lw         $4, 0xDD4($2)
    /* AD3B8 001AD3B8 2D280000 */  daddu      $5, $0, $0
    /* AD3BC 001AD3BC 9048080C */  jal        func_00212240
    /* AD3C0 001AD3C0 00000000 */   nop
  .L001AD3C4:
    /* AD3C4 001AD3C4 1C0400AE */  sw         $0, 0x41C($16)
    /* AD3C8 001AD3C8 1000BFDF */  ld         $31, 0x10($29)
    /* AD3CC 001AD3CC 0000B07B */  lq         $16, 0x0($29)
    /* AD3D0 001AD3D0 3000BD27 */  addiu      $29, $29, 0x30
    /* AD3D4 001AD3D4 0800E003 */  jr         $31
    /* AD3D8 001AD3D8 00000000 */   nop
    /* AD3DC 001AD3DC 00000000 */  nop
.size func_001ad280, 0x160
