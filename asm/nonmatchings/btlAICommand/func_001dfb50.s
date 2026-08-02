.section .text
.set noat
.set noreorder
glabel func_001dfb50
    /* DFB50 001DFB50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DFB54 001DFB54 1000BFFF */  sd         $31, 0x10($29)
    /* DFB58 001DFB58 0000B07F */  sq         $16, 0x0($29)
    /* DFB5C 001DFB5C 2D200000 */  daddu      $4, $0, $0
    /* DFB60 001DFB60 00730A0C */  jal        func_0029cc00
    /* DFB64 001DFB64 00000000 */   nop
    /* DFB68 001DFB68 3C1A0200 */  dsll32     $3, $2, 8
    /* DFB6C 001DFB6C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DFB70 001DFB70 000D023C */  lui        $2, (0xD000000 >> 16)
    /* DFB74 001DFB74 25806200 */  or         $16, $3, $2
    /* DFB78 001DFB78 14740A0C */  jal        func_0029d050
    /* DFB7C 001DFB7C 00000000 */   nop
    /* DFB80 001DFB80 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DFB84 001DFB84 24180302 */  and        $3, $16, $3
    /* DFB88 001DFB88 021E0300 */  srl        $3, $3, 24
    /* DFB8C 001DFB8C 3C2A1000 */  dsll32     $5, $16, 8
    /* DFB90 001DFB90 3E2A0500 */  dsrl32     $5, $5, 8
    /* DFB94 001DFB94 04006014 */  bnez       $3, .L001DFBA8
    /* DFB98 001DFB98 00000000 */   nop
    /* DFB9C 001DFB9C 2D100000 */  daddu      $2, $0, $0
    /* DFBA0 001DFBA0 0B000010 */  b          .L001DFBD0
    /* DFBA4 001DFBA4 00000000 */   nop
  .L001DFBA8:
    /* DFBA8 001DFBA8 2D204000 */  daddu      $4, $2, $0
    /* DFBAC 001DFBAC 40100300 */  sll        $2, $3, 1
    /* DFBB0 001DFBB0 21104300 */  addu       $2, $2, $3
    /* DFBB4 001DFBB4 80180200 */  sll        $3, $2, 2
    /* DFBB8 001DFBB8 6100023C */  lui        $2, %hi(D_00609850)
    /* DFBBC 001DFBBC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DFBC0 001DFBC0 21104300 */  addu       $2, $2, $3
    /* DFBC4 001DFBC4 0000428C */  lw         $2, 0x0($2)
    /* DFBC8 001DFBC8 09F84000 */  jalr       $2
    /* DFBCC 001DFBCC 00000000 */   nop
  .L001DFBD0:
    /* DFBD0 001DFBD0 2B200200 */  sltu       $4, $0, $2
    /* DFBD4 001DFBD4 D4730A0C */  jal        func_0029cf50
    /* DFBD8 001DFBD8 00000000 */   nop
    /* DFBDC 001DFBDC 01000224 */  addiu      $2, $0, 0x1
    /* DFBE0 001DFBE0 1000BFDF */  ld         $31, 0x10($29)
    /* DFBE4 001DFBE4 0000B07B */  lq         $16, 0x0($29)
    /* DFBE8 001DFBE8 2000BD27 */  addiu      $29, $29, 0x20
    /* DFBEC 001DFBEC 0800E003 */  jr         $31
    /* DFBF0 001DFBF0 00000000 */   nop
    /* DFBF4 001DFBF4 00000000 */  nop
    /* DFBF8 001DFBF8 00000000 */  nop
    /* DFBFC 001DFBFC 00000000 */  nop
.size func_001dfb50, 0xb0
