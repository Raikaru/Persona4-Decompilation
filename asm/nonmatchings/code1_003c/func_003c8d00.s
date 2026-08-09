.section .text
.set noat
.set noreorder
glabel func_003c8d00
    /* 2C8D00 003C8D00 2D10A000 */  daddu      $2, $5, $0
    /* 2C8D04 003C8D04 2D18C000 */  daddu      $3, $6, $0
    /* 2C8D08 003C8D08 2D288000 */  daddu      $5, $4, $0
    /* 2C8D0C 003C8D0C 2D304000 */  daddu      $6, $2, $0
    /* 2C8D10 003C8D10 2D10E000 */  daddu      $2, $7, $0
    /* 2C8D14 003C8D14 2D480001 */  daddu      $9, $8, $0
    /* 2C8D18 003C8D18 7100043C */  lui        $4, %hi(D_0070B040)
    /* 2C8D1C 003C8D1C 2D386000 */  daddu      $7, $3, $0
    /* 2C8D20 003C8D20 2D404000 */  daddu      $8, $2, $0
    /* 2C8D24 003C8D24 1C8E0F08 */  j          func_003e3870
    /* 2C8D28 003C8D28 40B08424 */   addiu     $4, $4, %lo(D_0070B040)
    /* 2C8D2C 003C8D2C 00000000 */  nop
.size func_003c8d00, 0x30
