.section .text
.set noat
.set noreorder
glabel func_001fa190
    /* FA190 001FA190 A0FFBD27 */  addiu      $29, $29, -0x60
    /* FA194 001FA194 5000BFFF */  sd         $31, 0x50($29)
    /* FA198 001FA198 4000B47F */  sq         $20, 0x40($29)
    /* FA19C 001FA19C 3000B37F */  sq         $19, 0x30($29)
    /* FA1A0 001FA1A0 2000B27F */  sq         $18, 0x20($29)
    /* FA1A4 001FA1A4 1000B17F */  sq         $17, 0x10($29)
    /* FA1A8 001FA1A8 0000B07F */  sq         $16, 0x0($29)
    /* FA1AC 001FA1AC 2D908000 */  daddu      $18, $4, $0
    /* FA1B0 001FA1B0 01001424 */  addiu      $20, $0, 0x1
    /* FA1B4 001FA1B4 1405120C */  jal        func_00481450
    /* FA1B8 001FA1B8 00000000 */   nop
    /* FA1BC 001FA1BC 2D884000 */  daddu      $17, $2, $0
    /* FA1C0 001FA1C0 5E00043C */  lui        $4, %hi(D_005DC8CC)
    /* FA1C4 001FA1C4 CCC88424 */  addiu      $4, $4, %lo(D_005DC8CC)
    /* FA1C8 001FA1C8 1005120C */  jal        func_00481440
    /* FA1CC 001FA1CC 00000000 */   nop
    /* FA1D0 001FA1D0 2D800000 */  daddu      $16, $0, $0
    /* FA1D4 001FA1D4 23000010 */  b          .L001FA264
    /* FA1D8 001FA1D8 00000000 */   nop
  .L001FA1DC:
    /* FA1DC 001FA1DC ACB3838F */  lw         $3, -0x4C54($28)
    /* FA1E0 001FA1E0 80101000 */  sll        $2, $16, 2
    /* FA1E4 001FA1E4 21106200 */  addu       $2, $3, $2
    /* FA1E8 001FA1E8 5C0B448C */  lw         $4, 0xB5C($2)
    /* FA1EC 001FA1EC 1C008010 */  beqz       $4, .L001FA260
    /* FA1F0 001FA1F0 00000000 */   nop
    /* FA1F4 001FA1F4 48C5120C */  jal        func_004b1520
    /* FA1F8 001FA1F8 00000000 */   nop
    /* FA1FC 001FA1FC 0F004014 */  bnez       $2, .L001FA23C
    /* FA200 001FA200 00000000 */   nop
    /* FA204 001FA204 80981000 */  sll        $19, $16, 2
    /* FA208 001FA208 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA20C 001FA20C 21105300 */  addu       $2, $2, $19
    /* FA210 001FA210 5C0B448C */  lw         $4, 0xB5C($2)
    /* FA214 001FA214 8C15120C */  jal        func_00485630
    /* FA218 001FA218 00000000 */   nop
    /* FA21C 001FA21C ACB3828F */  lw         $2, -0x4C54($28)
    /* FA220 001FA220 21105300 */  addu       $2, $2, $19
    /* FA224 001FA224 5C0B448C */  lw         $4, 0xB5C($2)
    /* FA228 001FA228 1C16120C */  jal        func_00485870
    /* FA22C 001FA22C 00000000 */   nop
    /* FA230 001FA230 2DA00000 */  daddu      $20, $0, $0
    /* FA234 001FA234 0A000010 */  b          .L001FA260
    /* FA238 001FA238 00000000 */   nop
  .L001FA23C:
    /* FA23C 001FA23C 80981000 */  sll        $19, $16, 2
    /* FA240 001FA240 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA244 001FA244 21105300 */  addu       $2, $2, $19
    /* FA248 001FA248 5C0B448C */  lw         $4, 0xB5C($2)
    /* FA24C 001FA24C C816120C */  jal        func_00485b20
    /* FA250 001FA250 00000000 */   nop
    /* FA254 001FA254 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA258 001FA258 21105300 */  addu       $2, $2, $19
    /* FA25C 001FA25C 5C0B40AC */  sw         $0, 0xB5C($2)
  .L001FA260:
    /* FA260 001FA260 01001026 */  addiu      $16, $16, 0x1
  .L001FA264:
    /* FA264 001FA264 0400022A */  slti       $2, $16, 0x4
    /* FA268 001FA268 DCFF4014 */  bnez       $2, .L001FA1DC
    /* FA26C 001FA26C 00000000 */   nop
    /* FA270 001FA270 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA274 001FA274 540B448C */  lw         $4, 0xB54($2)
    /* FA278 001FA278 16008010 */  beqz       $4, .L001FA2D4
    /* FA27C 001FA27C 00000000 */   nop
    /* FA280 001FA280 48C5120C */  jal        func_004b1520
    /* FA284 001FA284 00000000 */   nop
    /* FA288 001FA288 0C004014 */  bnez       $2, .L001FA2BC
    /* FA28C 001FA28C 00000000 */   nop
    /* FA290 001FA290 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA294 001FA294 540B448C */  lw         $4, 0xB54($2)
    /* FA298 001FA298 8C15120C */  jal        func_00485630
    /* FA29C 001FA29C 00000000 */   nop
    /* FA2A0 001FA2A0 ACB3828F */  lw         $2, -0x4C54($28)
    /* FA2A4 001FA2A4 540B448C */  lw         $4, 0xB54($2)
    /* FA2A8 001FA2A8 1C16120C */  jal        func_00485870
    /* FA2AC 001FA2AC 00000000 */   nop
    /* FA2B0 001FA2B0 2DA00000 */  daddu      $20, $0, $0
    /* FA2B4 001FA2B4 07000010 */  b          .L001FA2D4
    /* FA2B8 001FA2B8 00000000 */   nop
  .L001FA2BC:
    /* FA2BC 001FA2BC ACB3828F */  lw         $2, -0x4C54($28)
    /* FA2C0 001FA2C0 540B448C */  lw         $4, 0xB54($2)
    /* FA2C4 001FA2C4 C816120C */  jal        func_00485b20
    /* FA2C8 001FA2C8 00000000 */   nop
    /* FA2CC 001FA2CC ACB3828F */  lw         $2, -0x4C54($28)
    /* FA2D0 001FA2D0 540B40AC */  sw         $0, 0xB54($2)
  .L001FA2D4:
    /* FA2D4 001FA2D4 2D202002 */  daddu      $4, $17, $0
    /* FA2D8 001FA2D8 1005120C */  jal        func_00481440
    /* FA2DC 001FA2DC 00000000 */   nop
    /* FA2E0 001FA2E0 0000428E */  lw         $2, 0x0($18)
    /* FA2E4 001FA2E4 01004224 */  addiu      $2, $2, 0x1
    /* FA2E8 001FA2E8 000042AE */  sw         $2, 0x0($18)
    /* FA2EC 001FA2EC 2D108002 */  daddu      $2, $20, $0
    /* FA2F0 001FA2F0 5000BFDF */  ld         $31, 0x50($29)
    /* FA2F4 001FA2F4 4000B47B */  lq         $20, 0x40($29)
    /* FA2F8 001FA2F8 3000B37B */  lq         $19, 0x30($29)
    /* FA2FC 001FA2FC 2000B27B */  lq         $18, 0x20($29)
    /* FA300 001FA300 1000B17B */  lq         $17, 0x10($29)
    /* FA304 001FA304 0000B07B */  lq         $16, 0x0($29)
    /* FA308 001FA308 6000BD27 */  addiu      $29, $29, 0x60
    /* FA30C 001FA30C 0800E003 */  jr         $31
    /* FA310 001FA310 00000000 */   nop
    /* FA314 001FA314 00000000 */  nop
    /* FA318 001FA318 00000000 */  nop
    /* FA31C 001FA31C 00000000 */  nop
.size func_001fa190, 0x190
