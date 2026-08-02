.section .text
.set noat
.set noreorder
glabel func_001e0b60
    /* E0B60 001E0B60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E0B64 001E0B64 1000BFFF */  sd         $31, 0x10($29)
    /* E0B68 001E0B68 0000B07F */  sq         $16, 0x0($29)
    /* E0B6C 001E0B6C 2D200000 */  daddu      $4, $0, $0
    /* E0B70 001E0B70 00730A0C */  jal        func_0029cc00
    /* E0B74 001E0B74 00000000 */   nop
    /* E0B78 001E0B78 3C1A0200 */  dsll32     $3, $2, 8
    /* E0B7C 001E0B7C 3E1A0300 */  dsrl32     $3, $3, 8
    /* E0B80 001E0B80 0026023C */  lui        $2, (0x26000000 >> 16)
    /* E0B84 001E0B84 25806200 */  or         $16, $3, $2
    /* E0B88 001E0B88 14740A0C */  jal        func_0029d050
    /* E0B8C 001E0B8C 00000000 */   nop
    /* E0B90 001E0B90 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* E0B94 001E0B94 24180302 */  and        $3, $16, $3
    /* E0B98 001E0B98 021E0300 */  srl        $3, $3, 24
    /* E0B9C 001E0B9C 3C2A1000 */  dsll32     $5, $16, 8
    /* E0BA0 001E0BA0 3E2A0500 */  dsrl32     $5, $5, 8
    /* E0BA4 001E0BA4 04006014 */  bnez       $3, .L001E0BB8
    /* E0BA8 001E0BA8 00000000 */   nop
    /* E0BAC 001E0BAC 2D100000 */  daddu      $2, $0, $0
    /* E0BB0 001E0BB0 0B000010 */  b          .L001E0BE0
    /* E0BB4 001E0BB4 00000000 */   nop
  .L001E0BB8:
    /* E0BB8 001E0BB8 2D204000 */  daddu      $4, $2, $0
    /* E0BBC 001E0BBC 40100300 */  sll        $2, $3, 1
    /* E0BC0 001E0BC0 21104300 */  addu       $2, $2, $3
    /* E0BC4 001E0BC4 80180200 */  sll        $3, $2, 2
    /* E0BC8 001E0BC8 6100023C */  lui        $2, %hi(D_00609850)
    /* E0BCC 001E0BCC 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E0BD0 001E0BD0 21104300 */  addu       $2, $2, $3
    /* E0BD4 001E0BD4 0000428C */  lw         $2, 0x0($2)
    /* E0BD8 001E0BD8 09F84000 */  jalr       $2
    /* E0BDC 001E0BDC 00000000 */   nop
  .L001E0BE0:
    /* E0BE0 001E0BE0 2B200200 */  sltu       $4, $0, $2
    /* E0BE4 001E0BE4 D4730A0C */  jal        func_0029cf50
    /* E0BE8 001E0BE8 00000000 */   nop
    /* E0BEC 001E0BEC 01000224 */  addiu      $2, $0, 0x1
    /* E0BF0 001E0BF0 1000BFDF */  ld         $31, 0x10($29)
    /* E0BF4 001E0BF4 0000B07B */  lq         $16, 0x0($29)
    /* E0BF8 001E0BF8 2000BD27 */  addiu      $29, $29, 0x20
    /* E0BFC 001E0BFC 0800E003 */  jr         $31
    /* E0C00 001E0C00 00000000 */   nop
    /* E0C04 001E0C04 00000000 */  nop
    /* E0C08 001E0C08 00000000 */  nop
    /* E0C0C 001E0C0C 00000000 */  nop
.size func_001e0b60, 0xb0
