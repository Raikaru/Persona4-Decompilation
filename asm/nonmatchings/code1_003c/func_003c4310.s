.section .text
.set noat
.set noreorder
glabel func_003c4310
    /* 2C4310 003C4310 2D10A000 */  daddu      $2, $5, $0
    /* 2C4314 003C4314 2D18C000 */  daddu      $3, $6, $0
    /* 2C4318 003C4318 2D288000 */  daddu      $5, $4, $0
    /* 2C431C 003C431C 2D304000 */  daddu      $6, $2, $0
    /* 2C4320 003C4320 2D10E000 */  daddu      $2, $7, $0
    /* 2C4324 003C4324 2D480001 */  daddu      $9, $8, $0
    /* 2C4328 003C4328 7100043C */  lui        $4, %hi(D_0070AFF0)
    /* 2C432C 003C432C 2D386000 */  daddu      $7, $3, $0
    /* 2C4330 003C4330 2D404000 */  daddu      $8, $2, $0
    /* 2C4334 003C4334 1C8E0F08 */  j          func_003e3870
    /* 2C4338 003C4338 F0AF8424 */   addiu     $4, $4, %lo(D_0070AFF0)
    /* 2C433C 003C433C 00000000 */  nop
.size func_003c4310, 0x30
