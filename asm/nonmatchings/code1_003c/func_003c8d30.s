.section .text
.set noat
.set noreorder
glabel func_003c8d30
    /* 2C8D30 003C8D30 2D18A000 */  daddu      $3, $5, $0
    /* 2C8D34 003C8D34 2D10C000 */  daddu      $2, $6, $0
    /* 2C8D38 003C8D38 2D288000 */  daddu      $5, $4, $0
    /* 2C8D3C 003C8D3C 2D40E000 */  daddu      $8, $7, $0
    /* 2C8D40 003C8D40 7100043C */  lui        $4, %hi(D_0070B040)
    /* 2C8D44 003C8D44 2D306000 */  daddu      $6, $3, $0
    /* 2C8D48 003C8D48 40B08424 */  addiu      $4, $4, %lo(D_0070B040)
    /* 2C8D4C 003C8D4C 088C0F08 */  j          func_003e3020
    /* 2C8D50 003C8D50 2D384000 */   daddu     $7, $2, $0
    /* 2C8D54 003C8D54 00000000 */  nop
    /* 2C8D58 003C8D58 00000000 */  nop
    /* 2C8D5C 003C8D5C 00000000 */  nop
.size func_003c8d30, 0x30
