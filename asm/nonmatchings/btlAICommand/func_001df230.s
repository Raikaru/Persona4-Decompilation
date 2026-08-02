.section .text
.set noat
.set noreorder
glabel func_001df230
    /* DF230 001DF230 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF234 001DF234 1000BFFF */  sd         $31, 0x10($29)
    /* DF238 001DF238 0000B07F */  sq         $16, 0x0($29)
    /* DF23C 001DF23C 14740A0C */  jal        func_0029d050
    /* DF240 001DF240 00000000 */   nop
    /* DF244 001DF244 2D804000 */  daddu      $16, $2, $0
    /* DF248 001DF248 09000324 */  addiu      $3, $0, 0x9
    /* DF24C 001DF24C 6C0043A4 */  sh         $3, 0x6C($2)
    /* DF250 001DF250 11010324 */  addiu      $3, $0, 0x111
    /* DF254 001DF254 6E0043A4 */  sh         $3, 0x6E($2)
    /* DF258 001DF258 2D200000 */  daddu      $4, $0, $0
    /* DF25C 001DF25C 00730A0C */  jal        func_0029cc00
    /* DF260 001DF260 00000000 */   nop
    /* DF264 001DF264 760002A6 */  sh         $2, 0x76($16)
    /* DF268 001DF268 01000424 */  addiu      $4, $0, 0x1
    /* DF26C 001DF26C 00730A0C */  jal        func_0029cc00
    /* DF270 001DF270 00000000 */   nop
    /* DF274 001DF274 780002A6 */  sh         $2, 0x78($16)
    /* DF278 001DF278 2D200002 */  daddu      $4, $16, $0
    /* DF27C 001DF27C 2D280000 */  daddu      $5, $0, $0
    /* DF280 001DF280 6100023C */  lui        $2, %hi(D_00609D20)
    /* DF284 001DF284 209D428C */  lw         $2, %lo(D_00609D20)($2)
    /* DF288 001DF288 09F84000 */  jalr       $2
    /* DF28C 001DF28C 00000000 */   nop
    /* DF290 001DF290 07004014 */  bnez       $2, .L001DF2B0
    /* DF294 001DF294 00000000 */   nop
    /* DF298 001DF298 2D200002 */  daddu      $4, $16, $0
    /* DF29C 001DF29C 2D280000 */  daddu      $5, $0, $0
    /* DF2A0 001DF2A0 6100023C */  lui        $2, %hi(D_00609CE0)
    /* DF2A4 001DF2A4 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* DF2A8 001DF2A8 09F84000 */  jalr       $2
    /* DF2AC 001DF2AC 00000000 */   nop
  .L001DF2B0:
    /* DF2B0 001DF2B0 01000224 */  addiu      $2, $0, 0x1
    /* DF2B4 001DF2B4 1000BFDF */  ld         $31, 0x10($29)
    /* DF2B8 001DF2B8 0000B07B */  lq         $16, 0x0($29)
    /* DF2BC 001DF2BC 2000BD27 */  addiu      $29, $29, 0x20
    /* DF2C0 001DF2C0 0800E003 */  jr         $31
    /* DF2C4 001DF2C4 00000000 */   nop
    /* DF2C8 001DF2C8 00000000 */  nop
    /* DF2CC 001DF2CC 00000000 */  nop
.size func_001df230, 0xa0
