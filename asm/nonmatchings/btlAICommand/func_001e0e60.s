.section .text
.set noat
.set noreorder
glabel func_001e0e60
    /* E0E60 001E0E60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E0E64 001E0E64 1000BFFF */  sd         $31, 0x10($29)
    /* E0E68 001E0E68 0000B07F */  sq         $16, 0x0($29)
    /* E0E6C 001E0E6C 2D200000 */  daddu      $4, $0, $0
    /* E0E70 001E0E70 00730A0C */  jal        func_0029cc00
    /* E0E74 001E0E74 00000000 */   nop
    /* E0E78 001E0E78 3C1A0200 */  dsll32     $3, $2, 8
    /* E0E7C 001E0E7C 3E1A0300 */  dsrl32     $3, $3, 8
    /* E0E80 001E0E80 002C023C */  lui        $2, (0x2C000000 >> 16)
    /* E0E84 001E0E84 25806200 */  or         $16, $3, $2
    /* E0E88 001E0E88 14740A0C */  jal        func_0029d050
    /* E0E8C 001E0E8C 00000000 */   nop
    /* E0E90 001E0E90 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* E0E94 001E0E94 24180302 */  and        $3, $16, $3
    /* E0E98 001E0E98 021E0300 */  srl        $3, $3, 24
    /* E0E9C 001E0E9C 3C2A1000 */  dsll32     $5, $16, 8
    /* E0EA0 001E0EA0 3E2A0500 */  dsrl32     $5, $5, 8
    /* E0EA4 001E0EA4 04006014 */  bnez       $3, .L001E0EB8
    /* E0EA8 001E0EA8 00000000 */   nop
    /* E0EAC 001E0EAC 2D100000 */  daddu      $2, $0, $0
    /* E0EB0 001E0EB0 0B000010 */  b          .L001E0EE0
    /* E0EB4 001E0EB4 00000000 */   nop
  .L001E0EB8:
    /* E0EB8 001E0EB8 2D204000 */  daddu      $4, $2, $0
    /* E0EBC 001E0EBC 40100300 */  sll        $2, $3, 1
    /* E0EC0 001E0EC0 21104300 */  addu       $2, $2, $3
    /* E0EC4 001E0EC4 80180200 */  sll        $3, $2, 2
    /* E0EC8 001E0EC8 6100023C */  lui        $2, %hi(D_00609850)
    /* E0ECC 001E0ECC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E0ED0 001E0ED0 21104300 */  addu       $2, $2, $3
    /* E0ED4 001E0ED4 0000428C */  lw         $2, 0x0($2)
    /* E0ED8 001E0ED8 09F84000 */  jalr       $2
    /* E0EDC 001E0EDC 00000000 */   nop
  .L001E0EE0:
    /* E0EE0 001E0EE0 2B200200 */  sltu       $4, $0, $2
    /* E0EE4 001E0EE4 D4730A0C */  jal        func_0029cf50
    /* E0EE8 001E0EE8 00000000 */   nop
    /* E0EEC 001E0EEC 01000224 */  addiu      $2, $0, 0x1
    /* E0EF0 001E0EF0 1000BFDF */  ld         $31, 0x10($29)
    /* E0EF4 001E0EF4 0000B07B */  lq         $16, 0x0($29)
    /* E0EF8 001E0EF8 2000BD27 */  addiu      $29, $29, 0x20
    /* E0EFC 001E0EFC 0800E003 */  jr         $31
    /* E0F00 001E0F00 00000000 */   nop
    /* E0F04 001E0F04 00000000 */  nop
    /* E0F08 001E0F08 00000000 */  nop
    /* E0F0C 001E0F0C 00000000 */  nop
.size func_001e0e60, 0xb0
