.section .text
.set noat
.set noreorder
glabel func_001e6b90
    /* E6B90 001E6B90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E6B94 001E6B94 2000BFFF */  sd         $31, 0x20($29)
    /* E6B98 001E6B98 1000B17F */  sq         $17, 0x10($29)
    /* E6B9C 001E6B9C 0000B07F */  sq         $16, 0x0($29)
    /* E6BA0 001E6BA0 2D200000 */  daddu      $4, $0, $0
    /* E6BA4 001E6BA4 00730A0C */  jal        func_0029cc00
    /* E6BA8 001E6BA8 00000000 */   nop
    /* E6BAC 001E6BAC 2D884000 */  daddu      $17, $2, $0
    /* E6BB0 001E6BB0 01000424 */  addiu      $4, $0, 0x1
    /* E6BB4 001E6BB4 00730A0C */  jal        func_0029cc00
    /* E6BB8 001E6BB8 00000000 */   nop
    /* E6BBC 001E6BBC 2D804000 */  daddu      $16, $2, $0
    /* E6BC0 001E6BC0 3C211100 */  dsll32     $4, $17, 4
    /* E6BC4 001E6BC4 3E210400 */  dsrl32     $4, $4, 4
    /* E6BC8 001E6BC8 30C3060C */  jal        func_001b0cc0
    /* E6BCC 001E6BCC 00000000 */   nop
    /* E6BD0 001E6BD0 3C1A1000 */  dsll32     $3, $16, 8
    /* E6BD4 001E6BD4 3E1A0300 */  dsrl32     $3, $3, 8
    /* E6BD8 001E6BD8 0048053C */  lui        $5, (0x48000000 >> 16)
    /* E6BDC 001E6BDC 25206500 */  or         $4, $3, $5
    /* E6BE0 001E6BE0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* E6BE4 001E6BE4 24188300 */  and        $3, $4, $3
    /* E6BE8 001E6BE8 02360300 */  srl        $6, $3, 24
    /* E6BEC 001E6BEC 25180502 */  or         $3, $16, $5
    /* E6BF0 001E6BF0 3C2A0300 */  dsll32     $5, $3, 8
    /* E6BF4 001E6BF4 3E2A0500 */  dsrl32     $5, $5, 8
    /* E6BF8 001E6BF8 0400C014 */  bnez       $6, .L001E6C0C
    /* E6BFC 001E6BFC 00000000 */   nop
    /* E6C00 001E6C00 2D100000 */  daddu      $2, $0, $0
    /* E6C04 001E6C04 0B000010 */  b          .L001E6C34
    /* E6C08 001E6C08 00000000 */   nop
  .L001E6C0C:
    /* E6C0C 001E6C0C 2D204000 */  daddu      $4, $2, $0
    /* E6C10 001E6C10 40100600 */  sll        $2, $6, 1
    /* E6C14 001E6C14 21104600 */  addu       $2, $2, $6
    /* E6C18 001E6C18 80180200 */  sll        $3, $2, 2
    /* E6C1C 001E6C1C 6100023C */  lui        $2, %hi(D_00609850)
    /* E6C20 001E6C20 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* E6C24 001E6C24 21104300 */  addu       $2, $2, $3
    /* E6C28 001E6C28 0000428C */  lw         $2, 0x0($2)
    /* E6C2C 001E6C2C 09F84000 */  jalr       $2
    /* E6C30 001E6C30 00000000 */   nop
  .L001E6C34:
    /* E6C34 001E6C34 2B200200 */  sltu       $4, $0, $2
    /* E6C38 001E6C38 D4730A0C */  jal        func_0029cf50
    /* E6C3C 001E6C3C 00000000 */   nop
    /* E6C40 001E6C40 01000224 */  addiu      $2, $0, 0x1
    /* E6C44 001E6C44 2000BFDF */  ld         $31, 0x20($29)
    /* E6C48 001E6C48 1000B17B */  lq         $17, 0x10($29)
    /* E6C4C 001E6C4C 0000B07B */  lq         $16, 0x0($29)
    /* E6C50 001E6C50 3000BD27 */  addiu      $29, $29, 0x30
    /* E6C54 001E6C54 0800E003 */  jr         $31
    /* E6C58 001E6C58 00000000 */   nop
    /* E6C5C 001E6C5C 00000000 */  nop
.size func_001e6b90, 0xd0
