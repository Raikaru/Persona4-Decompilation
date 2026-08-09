.section .text
.set noat
.set noreorder
glabel func_001ec1c0
    /* EC1C0 001EC1C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* EC1C4 001EC1C4 1000BFFF */  sd         $31, 0x10($29)
    /* EC1C8 001EC1C8 0000B07F */  sq         $16, 0x0($29)
    /* EC1CC 001EC1CC 2D808000 */  daddu      $16, $4, $0
    /* EC1D0 001EC1D0 0000C1C4 */  lwc1       $f1, 0x0($6)
    /* EC1D4 001EC1D4 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* EC1D8 001EC1D8 010B0046 */  sub.s      $f12, $f1, $f0
    /* EC1DC 001EC1DC 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* EC1E0 001EC1E0 0800A0C4 */  lwc1       $f0, 0x8($5)
    /* EC1E4 001EC1E4 410B0046 */  sub.s      $f13, $f1, $f0
    /* EC1E8 001EC1E8 00008044 */  mtc1       $0, $f0
    /* EC1EC 001EC1EC 00000000 */  nop
    /* EC1F0 001EC1F0 32000C46 */  c.eq.s     $f0, $f12
    /* EC1F4 001EC1F4 04000045 */  bc1f       .L001EC208
    /* EC1F8 001EC1F8 00000000 */   nop
    /* EC1FC 001EC1FC 32000D46 */  c.eq.s     $f0, $f13
    /* EC200 001EC200 05000145 */  bc1t       .L001EC218
    /* EC204 001EC204 00000000 */   nop
  .L001EC208:
    /* EC208 001EC208 542E110C */  jal        func_0044b950
    /* EC20C 001EC20C 00000000 */   nop
    /* EC210 001EC210 488081C7 */  lwc1       $f1, -0x7FB8($28)
    /* EC214 001EC214 02080046 */  mul.s      $f0, $f1, $f0
  .L001EC218:
    /* EC218 001EC218 2D200002 */  daddu      $4, $16, $0
    /* EC21C 001EC21C 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* EC220 001EC220 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* EC224 001EC224 06030046 */  mov.s      $f12, $f0
    /* EC228 001EC228 2D300000 */  daddu      $6, $0, $0
    /* EC22C 001EC22C D0710F0C */  jal        func_003dc740
    /* EC230 001EC230 00000000 */   nop
    /* EC234 001EC234 1000BFDF */  ld         $31, 0x10($29)
    /* EC238 001EC238 0000B07B */  lq         $16, 0x0($29)
    /* EC23C 001EC23C 2000BD27 */  addiu      $29, $29, 0x20
    /* EC240 001EC240 0800E003 */  jr         $31
    /* EC244 001EC244 00000000 */   nop
    /* EC248 001EC248 00000000 */  nop
    /* EC24C 001EC24C 00000000 */  nop
.size func_001ec1c0, 0x90
