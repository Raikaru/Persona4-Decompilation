.section .text
.set noat
.set noreorder
glabel func_004ef1c0
    /* 3EF1C0 004EF1C0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3EF1C4 004EF1C4 2800B1FF */  sd         $17, 0x28($29)
    /* 3EF1C8 004EF1C8 2D88E000 */  daddu      $17, $7, $0
    /* 3EF1CC 004EF1CC 2000B0FF */  sd         $16, 0x20($29)
    /* 3EF1D0 004EF1D0 3000B2FF */  sd         $18, 0x30($29)
    /* 3EF1D4 004EF1D4 08008014 */  bnez       $4, .L004EF1F8
    /* 3EF1D8 004EF1D8 3800BFFF */   sd        $31, 0x38($29)
    /* 3EF1DC 004EF1DC 7600043C */  lui        $4, %hi(D_0075CFC8)
    /* 3EF1E0 004EF1E0 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EF1E4 004EF1E4 C8CF8424 */  addiu      $4, $4, %lo(D_0075CFC8)
    /* 3EF1E8 004EF1E8 B6BA130C */  jal        func_004eead8
    /* 3EF1EC 004EF1EC F8CEA524 */   addiu     $5, $5, %lo(D_0075CEF8)
    /* 3EF1F0 004EF1F0 42000010 */  b          .L004EF2FC
    /* 3EF1F4 004EF1F4 2000B0DF */   ld        $16, 0x20($29)
  .L004EF1F8:
    /* 3EF1F8 004EF1F8 04008280 */  lb         $2, 0x4($4)
    /* 3EF1FC 004EF1FC 08004014 */  bnez       $2, .L004EF220
    /* 3EF200 004EF200 0400A22C */   sltiu     $2, $5, 0x4
    /* 3EF204 004EF204 7600043C */  lui        $4, %hi(D_0075CFD8)
    /* 3EF208 004EF208 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EF20C 004EF20C D8CF8424 */  addiu      $4, $4, %lo(D_0075CFD8)
    /* 3EF210 004EF210 B6BA130C */  jal        func_004eead8
    /* 3EF214 004EF214 28CFA524 */   addiu     $5, $5, %lo(D_0075CF28)
    /* 3EF218 004EF218 38000010 */  b          .L004EF2FC
    /* 3EF21C 004EF21C 2000B0DF */   ld        $16, 0x20($29)
  .L004EF220:
    /* 3EF220 004EF220 09004014 */  bnez       $2, .L004EF248
    /* 3EF224 004EF224 80100500 */   sll       $2, $5, 2
    /* 3EF228 004EF228 2800828C */  lw         $2, 0x28($4)
    /* 3EF22C 004EF22C 31004050 */  beql       $2, $0, .L004EF2F4
    /* 3EF230 004EF230 040020AE */   sw        $0, 0x4($17)
    /* 3EF234 004EF234 2C00848C */  lw         $4, 0x2C($4)
    /* 3EF238 004EF238 09F84000 */  jalr       $2
    /* 3EF23C 004EF23C FDFF0524 */   addiu     $5, $0, -0x3
    /* 3EF240 004EF240 2C000010 */  b          .L004EF2F4
    /* 3EF244 004EF244 040020AE */   sw        $0, 0x4($17)
  .L004EF248:
    /* 3EF248 004EF248 21104400 */  addu       $2, $2, $4
    /* 3EF24C 004EF24C 18004524 */  addiu      $5, $2, 0x18
    /* 3EF250 004EF250 0000A78C */  lw         $7, 0x0($5)
    /* 3EF254 004EF254 2600E010 */  beqz       $7, .L004EF2F0
    /* 3EF258 004EF258 0800F224 */   addiu     $18, $7, 0x8
    /* 3EF25C 004EF25C 0700426A */  ldl        $2, 0x7($18)
    /* 3EF260 004EF260 0000426E */  ldr        $2, 0x0($18)
    /* 3EF264 004EF264 0700A2B3 */  sdl        $2, 0x7($29)
    /* 3EF268 004EF268 0000A2B7 */  sdr        $2, 0x0($29)
    /* 3EF26C 004EF26C 0400A28F */  lw         $2, 0x4($29)
    /* 3EF270 004EF270 2A10C200 */  slt        $2, $6, $2
    /* 3EF274 004EF274 0C004054 */  bnel       $2, $0, .L004EF2A8
    /* 3EF278 004EF278 05008380 */   lb        $3, 0x5($4)
    /* 3EF27C 004EF27C 0000E38C */  lw         $3, 0x0($7)
    /* 3EF280 004EF280 0700A26B */  ldl        $2, 0x7($29)
    /* 3EF284 004EF284 0000A26F */  ldr        $2, 0x0($29)
    /* 3EF288 004EF288 070022B2 */  sdl        $2, 0x7($17)
    /* 3EF28C 004EF28C 000022B6 */  sdr        $2, 0x0($17)
    /* 3EF290 004EF290 0000A3AC */  sw         $3, 0x0($5)
    /* 3EF294 004EF294 1400828C */  lw         $2, 0x14($4)
    /* 3EF298 004EF298 0000E2AC */  sw         $2, 0x0($7)
    /* 3EF29C 004EF29C 16000010 */  b          .L004EF2F8
    /* 3EF2A0 004EF2A0 140087AC */   sw        $7, 0x14($4)
    /* 3EF2A4 004EF2A4 00000000 */  nop
  .L004EF2A8:
    /* 3EF2A8 004EF2A8 01000224 */  addiu      $2, $0, 0x1
    /* 3EF2AC 004EF2AC 11006254 */  bnel       $3, $2, .L004EF2F4
    /* 3EF2B0 004EF2B0 040020AE */   sw        $0, 0x4($17)
    /* 3EF2B4 004EF2B4 1000B027 */  addiu      $16, $29, 0x10
    /* 3EF2B8 004EF2B8 2D28C000 */  daddu      $5, $6, $0
    /* 3EF2BC 004EF2BC 2D20A003 */  daddu      $4, $29, $0
    /* 3EF2C0 004EF2C0 2D380002 */  daddu      $7, $16, $0
    /* 3EF2C4 004EF2C4 2EBE130C */  jal        func_004ef8b8
    /* 3EF2C8 004EF2C8 2D30A003 */   daddu     $6, $29, $0
    /* 3EF2CC 004EF2CC 0700A26B */  ldl        $2, 0x7($29)
    /* 3EF2D0 004EF2D0 0000A26F */  ldr        $2, 0x0($29)
    /* 3EF2D4 004EF2D4 070022B2 */  sdl        $2, 0x7($17)
    /* 3EF2D8 004EF2D8 000022B6 */  sdr        $2, 0x0($17)
    /* 3EF2DC 004EF2DC 0700066A */  ldl        $6, 0x7($16)
    /* 3EF2E0 004EF2E0 0000066E */  ldr        $6, 0x0($16)
    /* 3EF2E4 004EF2E4 070046B2 */  sdl        $6, 0x7($18)
    /* 3EF2E8 004EF2E8 03000010 */  b          .L004EF2F8
    /* 3EF2EC 004EF2EC 000046B6 */   sdr       $6, 0x0($18)
  .L004EF2F0:
    /* 3EF2F0 004EF2F0 040020AE */  sw         $0, 0x4($17)
  .L004EF2F4:
    /* 3EF2F4 004EF2F4 000020AE */  sw         $0, 0x0($17)
  .L004EF2F8:
    /* 3EF2F8 004EF2F8 2000B0DF */  ld         $16, 0x20($29)
  .L004EF2FC:
    /* 3EF2FC 004EF2FC 2800B1DF */  ld         $17, 0x28($29)
    /* 3EF300 004EF300 3000B2DF */  ld         $18, 0x30($29)
    /* 3EF304 004EF304 3800BFDF */  ld         $31, 0x38($29)
    /* 3EF308 004EF308 0800E003 */  jr         $31
    /* 3EF30C 004EF30C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004ef1c0, 0x150
