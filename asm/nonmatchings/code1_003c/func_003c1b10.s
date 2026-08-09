.section .text
.set noat
.set noreorder
glabel func_003c1b10
    /* 2C1B10 003C1B10 2D18A000 */  daddu      $3, $5, $0
    /* 2C1B14 003C1B14 2D10C000 */  daddu      $2, $6, $0
    /* 2C1B18 003C1B18 2D288000 */  daddu      $5, $4, $0
    /* 2C1B1C 003C1B1C 2D40E000 */  daddu      $8, $7, $0
    /* 2C1B20 003C1B20 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2C1B24 003C1B24 2D306000 */  daddu      $6, $3, $0
    /* 2C1B28 003C1B28 70AF8424 */  addiu      $4, $4, %lo(D_0070AF70)
    /* 2C1B2C 003C1B2C 088C0F08 */  j          func_003e3020
    /* 2C1B30 003C1B30 2D384000 */   daddu     $7, $2, $0
    /* 2C1B34 003C1B34 00000000 */  nop
    /* 2C1B38 003C1B38 00000000 */  nop
    /* 2C1B3C 003C1B3C 00000000 */  nop
.size func_003c1b10, 0x30
