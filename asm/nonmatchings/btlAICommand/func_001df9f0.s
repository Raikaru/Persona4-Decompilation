.section .text
.set noat
.set noreorder
glabel func_001df9f0
    /* DF9F0 001DF9F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF9F4 001DF9F4 1000BFFF */  sd         $31, 0x10($29)
    /* DF9F8 001DF9F8 0000B07F */  sq         $16, 0x0($29)
    /* DF9FC 001DF9FC 2D200000 */  daddu      $4, $0, $0
    /* DFA00 001DFA00 00730A0C */  jal        func_0029cc00
    /* DFA04 001DFA04 00000000 */   nop
    /* DFA08 001DFA08 3C1A0200 */  dsll32     $3, $2, 8
    /* DFA0C 001DFA0C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFA10 001DFA10 000B023C */  lui        $2, (0xB000000 >> 16)
    /* DFA14 001DFA14 25806200 */  or         $16, $3, $2
    /* DFA18 001DFA18 14740A0C */  jal        func_0029d050
    /* DFA1C 001DFA1C 00000000 */   nop
    /* DFA20 001DFA20 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFA24 001DFA24 24180302 */  and        $3, $16, $3
    /* DFA28 001DFA28 021E0300 */  srl        $3, $3, 24
    /* DFA2C 001DFA2C 3C2A1000 */  dsll32     $5, $16, 8
    /* DFA30 001DFA30 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFA34 001DFA34 04006014 */  bnez       $3, .L001DFA48
    /* DFA38 001DFA38 00000000 */   nop
    /* DFA3C 001DFA3C 2D100000 */  daddu      $2, $0, $0
    /* DFA40 001DFA40 0B000010 */  b          .L001DFA70
    /* DFA44 001DFA44 00000000 */   nop
  .L001DFA48:
    /* DFA48 001DFA48 2D204000 */  daddu      $4, $2, $0
    /* DFA4C 001DFA4C 40100300 */  sll        $2, $3, 1
    /* DFA50 001DFA50 21104300 */  addu       $2, $2, $3
    /* DFA54 001DFA54 80180200 */  sll        $3, $2, 2
    /* DFA58 001DFA58 6100023C */  lui        $2, %hi(D_00609850)
    /* DFA5C 001DFA5C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFA60 001DFA60 21104300 */  addu       $2, $2, $3
    /* DFA64 001DFA64 0000428C */  lw         $2, 0x0($2)
    /* DFA68 001DFA68 09F84000 */  jalr       $2
    /* DFA6C 001DFA6C 00000000 */   nop
  .L001DFA70:
    /* DFA70 001DFA70 2B200200 */  sltu       $4, $0, $2
    /* DFA74 001DFA74 D4730A0C */  jal        func_0029cf50
    /* DFA78 001DFA78 00000000 */   nop
    /* DFA7C 001DFA7C 01000224 */  addiu      $2, $0, 0x1
    /* DFA80 001DFA80 1000BFDF */  ld         $31, 0x10($29)
    /* DFA84 001DFA84 0000B07B */  lq         $16, 0x0($29)
    /* DFA88 001DFA88 2000BD27 */  addiu      $29, $29, 0x20
    /* DFA8C 001DFA8C 0800E003 */  jr         $31
    /* DFA90 001DFA90 00000000 */   nop
    /* DFA94 001DFA94 00000000 */  nop
    /* DFA98 001DFA98 00000000 */  nop
    /* DFA9C 001DFA9C 00000000 */  nop
.size func_001df9f0, 0xb0
