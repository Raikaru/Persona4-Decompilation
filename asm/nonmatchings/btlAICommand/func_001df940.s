.section .text
.set noat
.set noreorder
glabel func_001df940
    /* DF940 001DF940 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF944 001DF944 1000BFFF */  sd         $31, 0x10($29)
    /* DF948 001DF948 0000B07F */  sq         $16, 0x0($29)
    /* DF94C 001DF94C 2D200000 */  daddu      $4, $0, $0
    /* DF950 001DF950 00730A0C */  jal        func_0029cc00
    /* DF954 001DF954 00000000 */   nop
    /* DF958 001DF958 3C1A0200 */  dsll32     $3, $2, 8
    /* DF95C 001DF95C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF960 001DF960 000A023C */  lui        $2, (0xA000000 >> 16)
    /* DF964 001DF964 25806200 */  or         $16, $3, $2
    /* DF968 001DF968 14740A0C */  jal        func_0029d050
    /* DF96C 001DF96C 00000000 */   nop
    /* DF970 001DF970 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF974 001DF974 24180302 */  and        $3, $16, $3
    /* DF978 001DF978 021E0300 */  srl        $3, $3, 24
    /* DF97C 001DF97C 3C2A1000 */  dsll32     $5, $16, 8
    /* DF980 001DF980 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF984 001DF984 04006014 */  bnez       $3, .L001DF998
    /* DF988 001DF988 00000000 */   nop
    /* DF98C 001DF98C 2D100000 */  daddu      $2, $0, $0
    /* DF990 001DF990 0B000010 */  b          .L001DF9C0
    /* DF994 001DF994 00000000 */   nop
  .L001DF998:
    /* DF998 001DF998 2D204000 */  daddu      $4, $2, $0
    /* DF99C 001DF99C 40100300 */  sll        $2, $3, 1
    /* DF9A0 001DF9A0 21104300 */  addu       $2, $2, $3
    /* DF9A4 001DF9A4 80180200 */  sll        $3, $2, 2
    /* DF9A8 001DF9A8 6100023C */  lui        $2, %hi(D_00609850)
    /* DF9AC 001DF9AC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF9B0 001DF9B0 21104300 */  addu       $2, $2, $3
    /* DF9B4 001DF9B4 0000428C */  lw         $2, 0x0($2)
    /* DF9B8 001DF9B8 09F84000 */  jalr       $2
    /* DF9BC 001DF9BC 00000000 */   nop
  .L001DF9C0:
    /* DF9C0 001DF9C0 2B200200 */  sltu       $4, $0, $2
    /* DF9C4 001DF9C4 D4730A0C */  jal        func_0029cf50
    /* DF9C8 001DF9C8 00000000 */   nop
    /* DF9CC 001DF9CC 01000224 */  addiu      $2, $0, 0x1
    /* DF9D0 001DF9D0 1000BFDF */  ld         $31, 0x10($29)
    /* DF9D4 001DF9D4 0000B07B */  lq         $16, 0x0($29)
    /* DF9D8 001DF9D8 2000BD27 */  addiu      $29, $29, 0x20
    /* DF9DC 001DF9DC 0800E003 */  jr         $31
    /* DF9E0 001DF9E0 00000000 */   nop
    /* DF9E4 001DF9E4 00000000 */  nop
    /* DF9E8 001DF9E8 00000000 */  nop
    /* DF9EC 001DF9EC 00000000 */  nop
.size func_001df940, 0xb0
