.section .text
.set noat
.set noreorder
glabel func_001e3b90
    /* E3B90 001E3B90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E3B94 001E3B94 1000BFFF */  sd         $31, 0x10($29)
    /* E3B98 001E3B98 0000B07F */  sq         $16, 0x0($29)
    /* E3B9C 001E3B9C 2D200000 */  daddu      $4, $0, $0
    /* E3BA0 001E3BA0 00730A0C */  jal        func_0029cc00
    /* E3BA4 001E3BA4 00000000 */   nop
    /* E3BA8 001E3BA8 3C1A0200 */  dsll32     $3, $2, 8
    /* E3BAC 001E3BAC 3E1A0300 */  dsrl32     $3, $3, 8
    /* E3BB0 001E3BB0 0042023C */  lui        $2, (0x42000000 >> 16)
    /* E3BB4 001E3BB4 25806200 */  or         $16, $3, $2
    /* E3BB8 001E3BB8 14740A0C */  jal        func_0029d050
    /* E3BBC 001E3BBC 00000000 */   nop
    /* E3BC0 001E3BC0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* E3BC4 001E3BC4 24180302 */  and        $3, $16, $3
    /* E3BC8 001E3BC8 021E0300 */  srl        $3, $3, 24
    /* E3BCC 001E3BCC 3C2A1000 */  dsll32     $5, $16, 8
    /* E3BD0 001E3BD0 3E2A0500 */  dsrl32     $5, $5, 8
    /* E3BD4 001E3BD4 04006014 */  bnez       $3, .L001E3BE8
    /* E3BD8 001E3BD8 00000000 */   nop
    /* E3BDC 001E3BDC 2D100000 */  daddu      $2, $0, $0
    /* E3BE0 001E3BE0 0B000010 */  b          .L001E3C10
    /* E3BE4 001E3BE4 00000000 */   nop
  .L001E3BE8:
    /* E3BE8 001E3BE8 2D204000 */  daddu      $4, $2, $0
    /* E3BEC 001E3BEC 40100300 */  sll        $2, $3, 1
    /* E3BF0 001E3BF0 21104300 */  addu       $2, $2, $3
    /* E3BF4 001E3BF4 80180200 */  sll        $3, $2, 2
    /* E3BF8 001E3BF8 6100023C */  lui        $2, %hi(D_00609850)
    /* E3BFC 001E3BFC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E3C00 001E3C00 21104300 */  addu       $2, $2, $3
    /* E3C04 001E3C04 0000428C */  lw         $2, 0x0($2)
    /* E3C08 001E3C08 09F84000 */  jalr       $2
    /* E3C0C 001E3C0C 00000000 */   nop
  .L001E3C10:
    /* E3C10 001E3C10 2B200200 */  sltu       $4, $0, $2
    /* E3C14 001E3C14 D4730A0C */  jal        func_0029cf50
    /* E3C18 001E3C18 00000000 */   nop
    /* E3C1C 001E3C1C 01000224 */  addiu      $2, $0, 0x1
    /* E3C20 001E3C20 1000BFDF */  ld         $31, 0x10($29)
    /* E3C24 001E3C24 0000B07B */  lq         $16, 0x0($29)
    /* E3C28 001E3C28 2000BD27 */  addiu      $29, $29, 0x20
    /* E3C2C 001E3C2C 0800E003 */  jr         $31
    /* E3C30 001E3C30 00000000 */   nop
    /* E3C34 001E3C34 00000000 */  nop
    /* E3C38 001E3C38 00000000 */  nop
    /* E3C3C 001E3C3C 00000000 */  nop
.size func_001e3b90, 0xb0
