.section .text
.set noat
.set noreorder
glabel func_001e4b30
    /* E4B30 001E4B30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E4B34 001E4B34 2000BFFF */  sd         $31, 0x20($29)
    /* E4B38 001E4B38 1000B17F */  sq         $17, 0x10($29)
    /* E4B3C 001E4B3C 0000B07F */  sq         $16, 0x0($29)
    /* E4B40 001E4B40 2D200000 */  daddu      $4, $0, $0
    /* E4B44 001E4B44 00730A0C */  jal        func_0029cc00
    /* E4B48 001E4B48 00000000 */   nop
    /* E4B4C 001E4B4C 2D884000 */  daddu      $17, $2, $0
    /* E4B50 001E4B50 01000424 */  addiu      $4, $0, 0x1
    /* E4B54 001E4B54 00730A0C */  jal        func_0029cc00
    /* E4B58 001E4B58 00000000 */   nop
    /* E4B5C 001E4B5C 2D804000 */  daddu      $16, $2, $0
    /* E4B60 001E4B60 14740A0C */  jal        func_0029d050
    /* E4B64 001E4B64 00000000 */   nop
    /* E4B68 001E4B68 2D204000 */  daddu      $4, $2, $0
    /* E4B6C 001E4B6C 2D282002 */  daddu      $5, $17, $0
    /* E4B70 001E4B70 2D300002 */  daddu      $6, $16, $0
    /* E4B74 001E4B74 2D380000 */  daddu      $7, $0, $0
    /* E4B78 001E4B78 2D400000 */  daddu      $8, $0, $0
    /* E4B7C 001E4B7C 1E00093C */  lui        $9, %hi(func_001dacc0)
    /* E4B80 001E4B80 C0AC2925 */  addiu      $9, $9, %lo(func_001dacc0)
    /* E4B84 001E4B84 E86E070C */  jal        func_001dbba0
    /* E4B88 001E4B88 00000000 */   nop
    /* E4B8C 001E4B8C 01000224 */  addiu      $2, $0, 0x1
    /* E4B90 001E4B90 2000BFDF */  ld         $31, 0x20($29)
    /* E4B94 001E4B94 1000B17B */  lq         $17, 0x10($29)
    /* E4B98 001E4B98 0000B07B */  lq         $16, 0x0($29)
    /* E4B9C 001E4B9C 3000BD27 */  addiu      $29, $29, 0x30
    /* E4BA0 001E4BA0 0800E003 */  jr         $31
    /* E4BA4 001E4BA4 00000000 */   nop
    /* E4BA8 001E4BA8 00000000 */  nop
    /* E4BAC 001E4BAC 00000000 */  nop
.size func_001e4b30, 0x80
