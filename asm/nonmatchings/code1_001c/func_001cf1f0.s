.section .text
.set noat
.set noreorder
glabel func_001cf1f0
    /* CF1F0 001CF1F0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* CF1F4 001CF1F4 1000BFFF */  sd         $31, 0x10($29)
    /* CF1F8 001CF1F8 0000B07F */  sq         $16, 0x0($29)
    /* CF1FC 001CF1FC 2D808000 */  daddu      $16, $4, $0
    /* CF200 001CF200 ACB3828F */  lw         $2, -0x4C54($28)
    /* CF204 001CF204 7001428C */  lw         $2, 0x170($2)
    /* CF208 001CF208 3000448C */  lw         $4, 0x30($2)
    /* CF20C 001CF20C 9000A527 */  addiu      $5, $29, 0x90
    /* CF210 001CF210 1456060C */  jal        func_00195850
    /* CF214 001CF214 00000000 */   nop
    /* CF218 001CF218 9400A0AF */  sw         $0, 0x94($29)
    /* CF21C 001CF21C F0C1023C */  lui        $2, (0xC1F00000 >> 16)
    /* CF220 001CF220 00608244 */  mtc1       $2, $f12
    /* CF224 001CF224 2000A427 */  addiu      $4, $29, 0x20
    /* CF228 001CF228 6100053C */  lui        $5, %hi(D_0060A0D0)
    /* CF22C 001CF22C D0A0A524 */  addiu      $5, $5, %lo(D_0060A0D0)
    /* CF230 001CF230 2D300000 */  daddu      $6, $0, $0
    /* CF234 001CF234 1C820F0C */  jal        func_003e0870
    /* CF238 001CF238 00000000 */   nop
    /* CF23C 001CF23C 2000A427 */  addiu      $4, $29, 0x20
    /* CF240 001CF240 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CF244 001CF244 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CF248 001CF248 00010CC6 */  lwc1       $f12, 0x100($16)
    /* CF24C 001CF24C 02000624 */  addiu      $6, $0, 0x2
    /* CF250 001CF250 1C820F0C */  jal        func_003e0870
    /* CF254 001CF254 00000000 */   nop
    /* CF258 001CF258 8000A427 */  addiu      $4, $29, 0x80
    /* CF25C 001CF25C 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* CF260 001CF260 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* CF264 001CF264 2000A627 */  addiu      $6, $29, 0x20
    /* CF268 001CF268 C8900F0C */  jal        func_003e4320
    /* CF26C 001CF26C 00000000 */   nop
    /* CF270 001CF270 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* CF274 001CF274 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* CF278 001CF278 00188244 */  mtc1       $2, $f3
    /* CF27C 001CF27C 9000A0C7 */  lwc1       $f0, 0x90($29)
    /* CF280 001CF280 00108044 */  mtc1       $0, $f2
    /* CF284 001CF284 00000000 */  nop
    /* CF288 001CF288 18100046 */  adda.s     $f2, $f0
    /* CF28C 001CF28C 1C080346 */  madd.s     $f0, $f1, $f3
    /* CF290 001CF290 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CF294 001CF294 8400A1C7 */  lwc1       $f1, 0x84($29)
    /* CF298 001CF298 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* CF29C 001CF29C 18100046 */  adda.s     $f2, $f0
    /* CF2A0 001CF2A0 1C080346 */  madd.s     $f0, $f1, $f3
    /* CF2A4 001CF2A4 6400A0E7 */  swc1       $f0, 0x64($29)
    /* CF2A8 001CF2A8 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* CF2AC 001CF2AC 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CF2B0 001CF2B0 18100046 */  adda.s     $f2, $f0
    /* CF2B4 001CF2B4 1C080346 */  madd.s     $f0, $f1, $f3
    /* CF2B8 001CF2B8 6800A0E7 */  swc1       $f0, 0x68($29)
    /* CF2BC 001CF2BC 6C00A427 */  addiu      $4, $29, 0x6C
    /* CF2C0 001CF2C0 6000A527 */  addiu      $5, $29, 0x60
    /* CF2C4 001CF2C4 9000A627 */  addiu      $6, $29, 0x90
    /* CF2C8 001CF2C8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CF2CC 001CF2CC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CF2D0 001CF2D0 E0F5060C */  jal        func_001bd780
    /* CF2D4 001CF2D4 00000000 */   nop
    /* CF2D8 001CF2D8 6400A1C7 */  lwc1       $f1, 0x64($29)
    /* CF2DC 001CF2DC C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CF2E0 001CF2E0 00008244 */  mtc1       $2, $f0
    /* CF2E4 001CF2E4 00000000 */  nop
    /* CF2E8 001CF2E8 34080046 */  c.lt.s     $f1, $f0
    /* CF2EC 001CF2EC 02000045 */  bc1f       .L001CF2F8
    /* CF2F0 001CF2F0 00000000 */   nop
    /* CF2F4 001CF2F4 6400A0E7 */  swc1       $f0, 0x64($29)
  .L001CF2F8:
    /* CF2F8 001CF2F8 000101C6 */  lwc1       $f1, 0x100($16)
    /* CF2FC 001CF2FC 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CF300 001CF300 00008244 */  mtc1       $2, $f0
    /* CF304 001CF304 00000000 */  nop
    /* CF308 001CF308 00080046 */  add.s      $f0, $f1, $f0
    /* CF30C 001CF30C 000100E6 */  swc1       $f0, 0x100($16)
    /* CF310 001CF310 00608044 */  mtc1       $0, $f12
    /* CF314 001CF314 2D200000 */  daddu      $4, $0, $0
    /* CF318 001CF318 2D280000 */  daddu      $5, $0, $0
    /* CF31C 001CF31C 2D300000 */  daddu      $6, $0, $0
    /* CF320 001CF320 04000724 */  addiu      $7, $0, 0x4
    /* CF324 001CF324 50F3060C */  jal        func_001bcd40
    /* CF328 001CF328 00000000 */   nop
    /* CF32C 001CF32C 2D200002 */  daddu      $4, $16, $0
    /* CF330 001CF330 6000A527 */  addiu      $5, $29, 0x60
    /* CF334 001CF334 C0EA060C */  jal        func_001bab00
    /* CF338 001CF338 00000000 */   nop
    /* CF33C 001CF33C 1000BFDF */  ld         $31, 0x10($29)
    /* CF340 001CF340 0000B07B */  lq         $16, 0x0($29)
    /* CF344 001CF344 A000BD27 */  addiu      $29, $29, 0xA0
    /* CF348 001CF348 0800E003 */  jr         $31
    /* CF34C 001CF34C 00000000 */   nop
.size func_001cf1f0, 0x160
