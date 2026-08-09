.section .text
.set noat
.set noreorder
glabel func_001cb200
    /* CB200 001CB200 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CB204 001CB204 0000BFFF */  sd         $31, 0x0($29)
    /* CB208 001CB208 2D388000 */  daddu      $7, $4, $0
    /* CB20C 001CB20C E000848C */  lw         $4, 0xE0($4)
    /* CB210 001CB210 2F008010 */  beqz       $4, .L001CB2D0
    /* CB214 001CB214 00000000 */   nop
    /* CB218 001CB218 6A008394 */  lhu        $3, 0x6A($4)
    /* CB21C 001CB21C 01000624 */  addiu      $6, $0, 0x1
    /* CB220 001CB220 2B006614 */  bne        $3, $6, .L001CB2D0
    /* CB224 001CB224 00000000 */   nop
    /* CB228 001CB228 2801E58C */  lw         $5, 0x128($7)
    /* CB22C 001CB22C 3800838C */  lw         $3, 0x38($4)
    /* CB230 001CB230 2700A314 */  bne        $5, $3, .L001CB2D0
    /* CB234 001CB234 00000000 */   nop
    /* CB238 001CB238 1A008394 */  lhu        $3, 0x1A($4)
    /* CB23C 001CB23C 01006530 */  andi       $5, $3, 0x1
    /* CB240 001CB240 2300A010 */  beqz       $5, .L001CB2D0
    /* CB244 001CB244 00000000 */   nop
    /* CB248 001CB248 3000838C */  lw         $3, 0x30($4)
    /* CB24C 001CB24C A2006390 */  lbu        $3, 0xA2($3)
    /* CB250 001CB250 1F006014 */  bnez       $3, .L001CB2D0
    /* CB254 001CB254 00000000 */   nop
    /* CB258 001CB258 ACB3838F */  lw         $3, -0x4C54($28)
    /* CB25C 001CB25C 0E016394 */  lhu        $3, 0x10E($3)
    /* CB260 001CB260 11006610 */  beq        $3, $6, .L001CB2A8
    /* CB264 001CB264 00000000 */   nop
    /* CB268 001CB268 03006010 */  beqz       $3, .L001CB278
    /* CB26C 001CB26C 00000000 */   nop
    /* CB270 001CB270 0D000010 */  b          .L001CB2A8
    /* CB274 001CB274 00000000 */   nop
  .L001CB278:
    /* CB278 001CB278 15008010 */  beqz       $4, .L001CB2D0
    /* CB27C 001CB27C 00000000 */   nop
    /* CB280 001CB280 1300A010 */  beqz       $5, .L001CB2D0
    /* CB284 001CB284 00000000 */   nop
    /* CB288 001CB288 9C00E524 */  addiu      $5, $7, 0x9C
    /* CB28C 001CB28C 0001E624 */  addiu      $6, $7, 0x100
    /* CB290 001CB290 0C01ECC4 */  lwc1       $f12, 0x10C($7)
    /* CB294 001CB294 C3000724 */  addiu      $7, $0, 0xC3
    /* CB298 001CB298 50F3060C */  jal        func_001bcd40
    /* CB29C 001CB29C 00000000 */   nop
    /* CB2A0 001CB2A0 0B000010 */  b          .L001CB2D0
    /* CB2A4 001CB2A4 00000000 */   nop
  .L001CB2A8:
    /* CB2A8 001CB2A8 09008010 */  beqz       $4, .L001CB2D0
    /* CB2AC 001CB2AC 00000000 */   nop
    /* CB2B0 001CB2B0 0700A010 */  beqz       $5, .L001CB2D0
    /* CB2B4 001CB2B4 00000000 */   nop
    /* CB2B8 001CB2B8 9C00E524 */  addiu      $5, $7, 0x9C
    /* CB2BC 001CB2BC 0001E624 */  addiu      $6, $7, 0x100
    /* CB2C0 001CB2C0 0C01ECC4 */  lwc1       $f12, 0x10C($7)
    /* CB2C4 001CB2C4 C3000724 */  addiu      $7, $0, 0xC3
    /* CB2C8 001CB2C8 50F3060C */  jal        func_001bcd40
    /* CB2CC 001CB2CC 00000000 */   nop
  .L001CB2D0:
    /* CB2D0 001CB2D0 0000BFDF */  ld         $31, 0x0($29)
    /* CB2D4 001CB2D4 1000BD27 */  addiu      $29, $29, 0x10
    /* CB2D8 001CB2D8 0800E003 */  jr         $31
    /* CB2DC 001CB2DC 00000000 */   nop
.size func_001cb200, 0xe0
