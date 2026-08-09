.section .text
.set noat
.set noreorder
glabel func_003c1ae0
    /* 2C1AE0 003C1AE0 2D10A000 */  daddu      $2, $5, $0
    /* 2C1AE4 003C1AE4 2D18C000 */  daddu      $3, $6, $0
    /* 2C1AE8 003C1AE8 2D288000 */  daddu      $5, $4, $0
    /* 2C1AEC 003C1AEC 2D304000 */  daddu      $6, $2, $0
    /* 2C1AF0 003C1AF0 2D10E000 */  daddu      $2, $7, $0
    /* 2C1AF4 003C1AF4 2D480001 */  daddu      $9, $8, $0
    /* 2C1AF8 003C1AF8 7100043C */  lui        $4, %hi(D_0070AF90)
    /* 2C1AFC 003C1AFC 2D386000 */  daddu      $7, $3, $0
    /* 2C1B00 003C1B00 2D404000 */  daddu      $8, $2, $0
    /* 2C1B04 003C1B04 1C8E0F08 */  j          func_003e3870
    /* 2C1B08 003C1B08 90AF8424 */   addiu     $4, $4, %lo(D_0070AF90)
    /* 2C1B0C 003C1B0C 00000000 */  nop
.size func_003c1ae0, 0x30
