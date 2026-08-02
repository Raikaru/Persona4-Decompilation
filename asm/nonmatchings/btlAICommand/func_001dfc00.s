.section .text
.set noat
.set noreorder
glabel func_001dfc00
    /* DFC00 001DFC00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DFC04 001DFC04 1000BFFF */  sd         $31, 0x10($29)
    /* DFC08 001DFC08 0000B07F */  sq         $16, 0x0($29)
    /* DFC0C 001DFC0C 2D200000 */  daddu      $4, $0, $0
    /* DFC10 001DFC10 00730A0C */  jal        func_0029cc00
    /* DFC14 001DFC14 00000000 */   nop
    /* DFC18 001DFC18 3C1A0200 */  dsll32     $3, $2, 8
    /* DFC1C 001DFC1C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFC20 001DFC20 000E023C */  lui        $2, (0xE000000 >> 16)
    /* DFC24 001DFC24 25806200 */  or         $16, $3, $2
    /* DFC28 001DFC28 14740A0C */  jal        func_0029d050
    /* DFC2C 001DFC2C 00000000 */   nop
    /* DFC30 001DFC30 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFC34 001DFC34 24180302 */  and        $3, $16, $3
    /* DFC38 001DFC38 021E0300 */  srl        $3, $3, 24
    /* DFC3C 001DFC3C 3C2A1000 */  dsll32     $5, $16, 8
    /* DFC40 001DFC40 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFC44 001DFC44 04006014 */  bnez       $3, .L001DFC58
    /* DFC48 001DFC48 00000000 */   nop
    /* DFC4C 001DFC4C 2D100000 */  daddu      $2, $0, $0
    /* DFC50 001DFC50 0B000010 */  b          .L001DFC80
    /* DFC54 001DFC54 00000000 */   nop
  .L001DFC58:
    /* DFC58 001DFC58 2D204000 */  daddu      $4, $2, $0
    /* DFC5C 001DFC5C 40100300 */  sll        $2, $3, 1
    /* DFC60 001DFC60 21104300 */  addu       $2, $2, $3
    /* DFC64 001DFC64 80180200 */  sll        $3, $2, 2
    /* DFC68 001DFC68 6100023C */  lui        $2, %hi(D_00609850)
    /* DFC6C 001DFC6C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFC70 001DFC70 21104300 */  addu       $2, $2, $3
    /* DFC74 001DFC74 0000428C */  lw         $2, 0x0($2)
    /* DFC78 001DFC78 09F84000 */  jalr       $2
    /* DFC7C 001DFC7C 00000000 */   nop
  .L001DFC80:
    /* DFC80 001DFC80 2B200200 */  sltu       $4, $0, $2
    /* DFC84 001DFC84 D4730A0C */  jal        func_0029cf50
    /* DFC88 001DFC88 00000000 */   nop
    /* DFC8C 001DFC8C 01000224 */  addiu      $2, $0, 0x1
    /* DFC90 001DFC90 1000BFDF */  ld         $31, 0x10($29)
    /* DFC94 001DFC94 0000B07B */  lq         $16, 0x0($29)
    /* DFC98 001DFC98 2000BD27 */  addiu      $29, $29, 0x20
    /* DFC9C 001DFC9C 0800E003 */  jr         $31
    /* DFCA0 001DFCA0 00000000 */   nop
    /* DFCA4 001DFCA4 00000000 */  nop
    /* DFCA8 001DFCA8 00000000 */  nop
    /* DFCAC 001DFCAC 00000000 */  nop
.size func_001dfc00, 0xb0
