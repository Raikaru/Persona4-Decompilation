.section .text
.set noat
.set noreorder
glabel func_001e5b40
    /* E5B40 001E5B40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E5B44 001E5B44 2000BFFF */  sd         $31, 0x20($29)
    /* E5B48 001E5B48 1000B17F */  sq         $17, 0x10($29)
    /* E5B4C 001E5B4C 0000B07F */  sq         $16, 0x0($29)
    /* E5B50 001E5B50 2D200000 */  daddu      $4, $0, $0
    /* E5B54 001E5B54 00730A0C */  jal        func_0029cc00
    /* E5B58 001E5B58 00000000 */   nop
    /* E5B5C 001E5B5C 3C1A0200 */  dsll32     $3, $2, 8
    /* E5B60 001E5B60 3E1A0300 */  dsrl32     $3, $3, 8
    /* E5B64 001E5B64 0023023C */  lui        $2, (0x23000000 >> 16)
    /* E5B68 001E5B68 25886200 */  or         $17, $3, $2
    /* E5B6C 001E5B6C 14740A0C */  jal        func_0029d050
    /* E5B70 001E5B70 00000000 */   nop
    /* E5B74 001E5B74 2D804000 */  daddu      $16, $2, $0
    /* E5B78 001E5B78 3C2A1100 */  dsll32     $5, $17, 8
    /* E5B7C 001E5B7C 3E2A0500 */  dsrl32     $5, $5, 8
    /* E5B80 001E5B80 2D200002 */  daddu      $4, $16, $0
    /* E5B84 001E5B84 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E5B88 001E5B88 24102202 */  and        $2, $17, $2
    /* E5B8C 001E5B8C 02160200 */  srl        $2, $2, 24
    /* E5B90 001E5B90 C0180200 */  sll        $3, $2, 3
    /* E5B94 001E5B94 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E5B98 001E5B98 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* E5B9C 001E5B9C 21104300 */  addu       $2, $2, $3
    /* E5BA0 001E5BA0 0000428C */  lw         $2, 0x0($2)
    /* E5BA4 001E5BA4 09F84000 */  jalr       $2
    /* E5BA8 001E5BA8 00000000 */   nop
    /* E5BAC 001E5BAC 07004014 */  bnez       $2, .L001E5BCC
    /* E5BB0 001E5BB0 00000000 */   nop
    /* E5BB4 001E5BB4 2D200002 */  daddu      $4, $16, $0
    /* E5BB8 001E5BB8 2D280000 */  daddu      $5, $0, $0
    /* E5BBC 001E5BBC 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E5BC0 001E5BC0 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E5BC4 001E5BC4 09F84000 */  jalr       $2
    /* E5BC8 001E5BC8 00000000 */   nop
  .L001E5BCC:
    /* E5BCC 001E5BCC 01000224 */  addiu      $2, $0, 0x1
    /* E5BD0 001E5BD0 2000BFDF */  ld         $31, 0x20($29)
    /* E5BD4 001E5BD4 1000B17B */  lq         $17, 0x10($29)
    /* E5BD8 001E5BD8 0000B07B */  lq         $16, 0x0($29)
    /* E5BDC 001E5BDC 3000BD27 */  addiu      $29, $29, 0x30
    /* E5BE0 001E5BE0 0800E003 */  jr         $31
    /* E5BE4 001E5BE4 00000000 */   nop
    /* E5BE8 001E5BE8 00000000 */  nop
    /* E5BEC 001E5BEC 00000000 */  nop
.size func_001e5b40, 0xb0
