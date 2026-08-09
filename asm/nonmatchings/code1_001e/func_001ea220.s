.section .text
.set noat
.set noreorder
glabel func_001ea220
    /* EA220 001EA220 E0FFBD27 */  addiu      $29, $29, -0x20
    /* EA224 001EA224 1000BFFF */  sd         $31, 0x10($29)
    /* EA228 001EA228 0000B07F */  sq         $16, 0x0($29)
    /* EA22C 001EA22C 14740A0C */  jal        func_0029d050
    /* EA230 001EA230 00000000 */   nop
    /* EA234 001EA234 2D804000 */  daddu      $16, $2, $0
    /* EA238 001EA238 2D200000 */  daddu      $4, $0, $0
    /* EA23C 001EA23C 00730A0C */  jal        func_0029cc00
    /* EA240 001EA240 00000000 */   nop
    /* EA244 001EA244 6E0002A6 */  sh         $2, 0x6E($16)
    /* EA248 001EA248 09000224 */  addiu      $2, $0, 0x9
    /* EA24C 001EA24C 6C0002A6 */  sh         $2, 0x6C($16)
    /* EA250 001EA250 01000424 */  addiu      $4, $0, 0x1
    /* EA254 001EA254 00730A0C */  jal        func_0029cc00
    /* EA258 001EA258 00000000 */   nop
    /* EA25C 001EA25C 760002A6 */  sh         $2, 0x76($16)
    /* EA260 001EA260 02000424 */  addiu      $4, $0, 0x2
    /* EA264 001EA264 00730A0C */  jal        func_0029cc00
    /* EA268 001EA268 00000000 */   nop
    /* EA26C 001EA26C 780002A6 */  sh         $2, 0x78($16)
    /* EA270 001EA270 03000424 */  addiu      $4, $0, 0x3
    /* EA274 001EA274 00730A0C */  jal        func_0029cc00
    /* EA278 001EA278 00000000 */   nop
    /* EA27C 001EA27C 7A0002A6 */  sh         $2, 0x7A($16)
    /* EA280 001EA280 2D200002 */  daddu      $4, $16, $0
    /* EA284 001EA284 2D280000 */  daddu      $5, $0, $0
    /* EA288 001EA288 6100023C */  lui        $2, %hi(D_00609D20)
    /* EA28C 001EA28C 209D428C */  lw         $2, %lo(D_00609D20)($2)
    /* EA290 001EA290 09F84000 */  jalr       $2
    /* EA294 001EA294 00000000 */   nop
    /* EA298 001EA298 07004014 */  bnez       $2, .L001EA2B8
    /* EA29C 001EA29C 00000000 */   nop
    /* EA2A0 001EA2A0 2D200002 */  daddu      $4, $16, $0
    /* EA2A4 001EA2A4 2D280000 */  daddu      $5, $0, $0
    /* EA2A8 001EA2A8 6100023C */  lui        $2, %hi(D_00609CE0)
    /* EA2AC 001EA2AC E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* EA2B0 001EA2B0 09F84000 */  jalr       $2
    /* EA2B4 001EA2B4 00000000 */   nop
  .L001EA2B8:
    /* EA2B8 001EA2B8 01000224 */  addiu      $2, $0, 0x1
    /* EA2BC 001EA2BC 1000BFDF */  ld         $31, 0x10($29)
    /* EA2C0 001EA2C0 0000B07B */  lq         $16, 0x0($29)
    /* EA2C4 001EA2C4 2000BD27 */  addiu      $29, $29, 0x20
    /* EA2C8 001EA2C8 0800E003 */  jr         $31
    /* EA2CC 001EA2CC 00000000 */   nop
.size func_001ea220, 0xb0
