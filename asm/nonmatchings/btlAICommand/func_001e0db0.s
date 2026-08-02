.section .text
.set noat
.set noreorder
glabel func_001e0db0
    /* E0DB0 001E0DB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E0DB4 001E0DB4 1000BFFF */  sd         $31, 0x10($29)
    /* E0DB8 001E0DB8 0000B07F */  sq         $16, 0x0($29)
    /* E0DBC 001E0DBC 2D200000 */  daddu      $4, $0, $0
    /* E0DC0 001E0DC0 00730A0C */  jal        func_0029cc00
    /* E0DC4 001E0DC4 00000000 */   nop
    /* E0DC8 001E0DC8 3C1A0200 */  dsll32     $3, $2, 8
    /* E0DCC 001E0DCC 3E1A0300 */  dsrl32     $3, $3, 8
    /* E0DD0 001E0DD0 002B023C */  lui        $2, (0x2B000000 >> 16)
    /* E0DD4 001E0DD4 25806200 */  or         $16, $3, $2
    /* E0DD8 001E0DD8 14740A0C */  jal        func_0029d050
    /* E0DDC 001E0DDC 00000000 */   nop
    /* E0DE0 001E0DE0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* E0DE4 001E0DE4 24180302 */  and        $3, $16, $3
    /* E0DE8 001E0DE8 021E0300 */  srl        $3, $3, 24
    /* E0DEC 001E0DEC 3C2A1000 */  dsll32     $5, $16, 8
    /* E0DF0 001E0DF0 3E2A0500 */  dsrl32     $5, $5, 8
    /* E0DF4 001E0DF4 04006014 */  bnez       $3, .L001E0E08
    /* E0DF8 001E0DF8 00000000 */   nop
    /* E0DFC 001E0DFC 2D100000 */  daddu      $2, $0, $0
    /* E0E00 001E0E00 0B000010 */  b          .L001E0E30
    /* E0E04 001E0E04 00000000 */   nop
  .L001E0E08:
    /* E0E08 001E0E08 2D204000 */  daddu      $4, $2, $0
    /* E0E0C 001E0E0C 40100300 */  sll        $2, $3, 1
    /* E0E10 001E0E10 21104300 */  addu       $2, $2, $3
    /* E0E14 001E0E14 80180200 */  sll        $3, $2, 2
    /* E0E18 001E0E18 6100023C */  lui        $2, %hi(D_00609850)
    /* E0E1C 001E0E1C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E0E20 001E0E20 21104300 */  addu       $2, $2, $3
    /* E0E24 001E0E24 0000428C */  lw         $2, 0x0($2)
    /* E0E28 001E0E28 09F84000 */  jalr       $2
    /* E0E2C 001E0E2C 00000000 */   nop
  .L001E0E30:
    /* E0E30 001E0E30 2B200200 */  sltu       $4, $0, $2
    /* E0E34 001E0E34 D4730A0C */  jal        func_0029cf50
    /* E0E38 001E0E38 00000000 */   nop
    /* E0E3C 001E0E3C 01000224 */  addiu      $2, $0, 0x1
    /* E0E40 001E0E40 1000BFDF */  ld         $31, 0x10($29)
    /* E0E44 001E0E44 0000B07B */  lq         $16, 0x0($29)
    /* E0E48 001E0E48 2000BD27 */  addiu      $29, $29, 0x20
    /* E0E4C 001E0E4C 0800E003 */  jr         $31
    /* E0E50 001E0E50 00000000 */   nop
    /* E0E54 001E0E54 00000000 */  nop
    /* E0E58 001E0E58 00000000 */  nop
    /* E0E5C 001E0E5C 00000000 */  nop
.size func_001e0db0, 0xb0
