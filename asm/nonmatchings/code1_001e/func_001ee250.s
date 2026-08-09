.section .text
.set noat
.set noreorder
glabel func_001ee250
    /* EE250 001EE250 B0FFBD27 */  addiu      $29, $29, -0x50
    /* EE254 001EE254 3000BFFF */  sd         $31, 0x30($29)
    /* EE258 001EE258 2000B17F */  sq         $17, 0x20($29)
    /* EE25C 001EE25C 1000B07F */  sq         $16, 0x10($29)
    /* EE260 001EE260 0000B4E7 */  swc1       $f20, 0x0($29)
    /* EE264 001EE264 2D888000 */  daddu      $17, $4, $0
    /* EE268 001EE268 2D80A000 */  daddu      $16, $5, $0
    /* EE26C 001EE26C 4000A527 */  addiu      $5, $29, 0x40
    /* EE270 001EE270 1456060C */  jal        func_00195850
    /* EE274 001EE274 00000000 */   nop
    /* EE278 001EE278 900021C6 */  lwc1       $f1, 0x90($17)
    /* EE27C 001EE27C 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* EE280 001EE280 020D0046 */  mul.s      $f20, $f1, $f0
    /* EE284 001EE284 D6060224 */  addiu      $2, $0, 0x6D6
    /* EE288 001EE288 00008244 */  mtc1       $2, $f0
    /* EE28C 001EE28C 00000000 */  nop
    /* EE290 001EE290 60008046 */  cvt.s.w    $f1, $f0
    /* EE294 001EE294 4000A0C7 */  lwc1       $f0, 0x40($29)
    /* EE298 001EE298 00080046 */  add.s      $f0, $f1, $f0
    /* EE29C 001EE29C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* EE2A0 001EE2A0 00000544 */  mfc1       $5, $f0
    /* EE2A4 001EE2A4 4800A0C7 */  lwc1       $f0, 0x48($29)
    /* EE2A8 001EE2A8 00080046 */  add.s      $f0, $f1, $f0
    /* EE2AC 001EE2AC 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* EE2B0 001EE2B0 00000444 */  mfc1       $4, $f0
    /* EE2B4 001EE2B4 19000324 */  addiu      $3, $0, 0x19
    /* EE2B8 001EE2B8 1A00A300 */  div        $0, $5, $3
    /* EE2BC 001EE2BC 12100000 */  mflo       $2
    /* EE2C0 001EE2C0 3C3C0200 */  dsll32     $7, $2, 16
    /* EE2C4 001EE2C4 3F3C0700 */  dsra32     $7, $7, 16
    /* EE2C8 001EE2C8 1A008370 */  div1       $0, $4, $3
    /* EE2CC 001EE2CC 12100070 */  mflo1      $2
    /* EE2D0 001EE2D0 3C340200 */  dsll32     $6, $2, 16
    /* EE2D4 001EE2D4 3F340600 */  dsra32     $6, $6, 16
    /* EE2D8 001EE2D8 1A00A300 */  div        $0, $5, $3
    /* EE2DC 001EE2DC 10100000 */  mfhi       $2
    /* EE2E0 001EE2E0 0D004128 */  slti       $1, $2, 0xD
    /* EE2E4 001EE2E4 04002014 */  bnez       $1, .L001EE2F8
    /* EE2E8 001EE2E8 00000000 */   nop
    /* EE2EC 001EE2EC 0100E224 */  addiu      $2, $7, 0x1
    /* EE2F0 001EE2F0 3C3C0200 */  dsll32     $7, $2, 16
    /* EE2F4 001EE2F4 3F3C0700 */  dsra32     $7, $7, 16
  .L001EE2F8:
    /* EE2F8 001EE2F8 19000224 */  addiu      $2, $0, 0x19
    /* EE2FC 001EE2FC 1A008200 */  div        $0, $4, $2
    /* EE300 001EE300 10100000 */  mfhi       $2
    /* EE304 001EE304 0D004128 */  slti       $1, $2, 0xD
    /* EE308 001EE308 04002014 */  bnez       $1, .L001EE31C
    /* EE30C 001EE30C 00000000 */   nop
    /* EE310 001EE310 0100C224 */  addiu      $2, $6, 0x1
    /* EE314 001EE314 3C340200 */  dsll32     $6, $2, 16
    /* EE318 001EE318 3F340600 */  dsra32     $6, $6, 16
  .L001EE31C:
    /* EE31C 001EE31C 4E00A227 */  addiu      $2, $29, 0x4E
    /* EE320 001EE320 02004010 */  beqz       $2, .L001EE32C
    /* EE324 001EE324 00000000 */   nop
    /* EE328 001EE328 4E00A7A7 */  sh         $7, 0x4E($29)
  .L001EE32C:
    /* EE32C 001EE32C 4C00A227 */  addiu      $2, $29, 0x4C
    /* EE330 001EE330 02004010 */  beqz       $2, .L001EE33C
    /* EE334 001EE334 00000000 */   nop
    /* EE338 001EE338 4C00A6A7 */  sh         $6, 0x4C($29)
  .L001EE33C:
    /* EE33C 001EE33C 2D202002 */  daddu      $4, $17, $0
    /* EE340 001EE340 4E00A587 */  lh         $5, 0x4E($29)
    /* EE344 001EE344 4C00A687 */  lh         $6, 0x4C($29)
    /* EE348 001EE348 06A30046 */  mov.s      $f12, $f20
    /* EE34C 001EE34C E4B1070C */  jal        func_001ec790
    /* EE350 001EE350 00000000 */   nop
    /* EE354 001EE354 16000012 */  beqz       $16, .L001EE3B0
    /* EE358 001EE358 00000000 */   nop
    /* EE35C 001EE35C 4E00A487 */  lh         $4, 0x4E($29)
    /* EE360 001EE360 80180400 */  sll        $3, $4, 2
    /* EE364 001EE364 21206400 */  addu       $4, $3, $4
    /* EE368 001EE368 80180400 */  sll        $3, $4, 2
    /* EE36C 001EE36C 21188300 */  addu       $3, $4, $3
    /* EE370 001EE370 2AF96324 */  addiu      $3, $3, -0x6D6
    /* EE374 001EE374 00008344 */  mtc1       $3, $f0
    /* EE378 001EE378 00000000 */  nop
    /* EE37C 001EE37C 20008046 */  cvt.s.w    $f0, $f0
    /* EE380 001EE380 000000E6 */  swc1       $f0, 0x0($16)
    /* EE384 001EE384 040000AE */  sw         $0, 0x4($16)
    /* EE388 001EE388 4C00A487 */  lh         $4, 0x4C($29)
    /* EE38C 001EE38C 80180400 */  sll        $3, $4, 2
    /* EE390 001EE390 21206400 */  addu       $4, $3, $4
    /* EE394 001EE394 80180400 */  sll        $3, $4, 2
    /* EE398 001EE398 21188300 */  addu       $3, $4, $3
    /* EE39C 001EE39C 2AF96324 */  addiu      $3, $3, -0x6D6
    /* EE3A0 001EE3A0 00008344 */  mtc1       $3, $f0
    /* EE3A4 001EE3A4 00000000 */  nop
    /* EE3A8 001EE3A8 20008046 */  cvt.s.w    $f0, $f0
    /* EE3AC 001EE3AC 080000E6 */  swc1       $f0, 0x8($16)
  .L001EE3B0:
    /* EE3B0 001EE3B0 4E00A387 */  lh         $3, 0x4E($29)
    /* EE3B4 001EE3B4 080523A6 */  sh         $3, 0x508($17)
    /* EE3B8 001EE3B8 4C00A387 */  lh         $3, 0x4C($29)
    /* EE3BC 001EE3BC 0A0523A6 */  sh         $3, 0x50A($17)
    /* EE3C0 001EE3C0 0C0534E6 */  swc1       $f20, 0x50C($17)
    /* EE3C4 001EE3C4 9C00238E */  lw         $3, 0x9C($17)
    /* EE3C8 001EE3C8 04006334 */  ori        $3, $3, 0x4
    /* EE3CC 001EE3CC 9C0023AE */  sw         $3, 0x9C($17)
    /* EE3D0 001EE3D0 D00920AE */  sw         $0, 0x9D0($17)
    /* EE3D4 001EE3D4 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE3D8 001EE3D8 1803648C */  lw         $4, 0x318($3)
    /* EE3DC 001EE3DC 08008010 */  beqz       $4, .L001EE400
    /* EE3E0 001EE3E0 00000000 */   nop
    /* EE3E4 001EE3E4 08052326 */  addiu      $3, $17, 0x508
    /* EE3E8 001EE3E8 C80483AC */  sw         $3, 0x4C8($4)
    /* EE3EC 001EE3EC ACB3838F */  lw         $3, -0x4C54($28)
    /* EE3F0 001EE3F0 1803638C */  lw         $3, 0x318($3)
    /* EE3F4 001EE3F4 D40923AE */  sw         $3, 0x9D4($17)
    /* EE3F8 001EE3F8 02000010 */  b          .L001EE404
    /* EE3FC 001EE3FC 00000000 */   nop
  .L001EE400:
    /* EE400 001EE400 D40920AE */  sw         $0, 0x9D4($17)
  .L001EE404:
    /* EE404 001EE404 08052426 */  addiu      $4, $17, 0x508
    /* EE408 001EE408 ACB3838F */  lw         $3, -0x4C54($28)
    /* EE40C 001EE40C 180364AC */  sw         $4, 0x318($3)
    /* EE410 001EE410 3000BFDF */  ld         $31, 0x30($29)
    /* EE414 001EE414 2000B17B */  lq         $17, 0x20($29)
    /* EE418 001EE418 1000B07B */  lq         $16, 0x10($29)
    /* EE41C 001EE41C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* EE420 001EE420 5000BD27 */  addiu      $29, $29, 0x50
    /* EE424 001EE424 0800E003 */  jr         $31
    /* EE428 001EE428 00000000 */   nop
    /* EE42C 001EE42C 00000000 */  nop
.size func_001ee250, 0x1e0
