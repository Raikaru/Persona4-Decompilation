.section .text
.set noat
.set noreorder
glabel func_003c1b40
    /* 2C1B40 003C1B40 2D108000 */  daddu      $2, $4, $0
    /* 2C1B44 003C1B44 2D30A000 */  daddu      $6, $5, $0
    /* 2C1B48 003C1B48 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2C1B4C 003C1B4C 2D284000 */  daddu      $5, $2, $0
    /* 2C1B50 003C1B50 1C8C0F08 */  j          func_003e3070
    /* 2C1B54 003C1B54 70AF8424 */   addiu     $4, $4, %lo(D_0070AF70)
    /* 2C1B58 003C1B58 00000000 */  nop
    /* 2C1B5C 003C1B5C 00000000 */  nop
.size func_003c1b40, 0x20
