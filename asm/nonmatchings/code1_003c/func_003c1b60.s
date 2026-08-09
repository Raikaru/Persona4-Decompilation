.section .text
.set noat
.set noreorder
glabel func_003c1b60
    /* 2C1B60 003C1B60 2D108000 */  daddu      $2, $4, $0
    /* 2C1B64 003C1B64 2D30A000 */  daddu      $6, $5, $0
    /* 2C1B68 003C1B68 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2C1B6C 003C1B6C 2D284000 */  daddu      $5, $2, $0
    /* 2C1B70 003C1B70 308C0F08 */  j          func_003e30c0
    /* 2C1B74 003C1B74 70AF8424 */   addiu     $4, $4, %lo(D_0070AF70)
    /* 2C1B78 003C1B78 00000000 */  nop
    /* 2C1B7C 003C1B7C 00000000 */  nop
.size func_003c1b60, 0x20
