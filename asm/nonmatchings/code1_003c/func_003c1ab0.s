.section .text
.set noat
.set noreorder
glabel func_003c1ab0
    /* 2C1AB0 003C1AB0 2D10A000 */  daddu      $2, $5, $0
    /* 2C1AB4 003C1AB4 2D18C000 */  daddu      $3, $6, $0
    /* 2C1AB8 003C1AB8 2D288000 */  daddu      $5, $4, $0
    /* 2C1ABC 003C1ABC 2D304000 */  daddu      $6, $2, $0
    /* 2C1AC0 003C1AC0 2D10E000 */  daddu      $2, $7, $0
    /* 2C1AC4 003C1AC4 2D480001 */  daddu      $9, $8, $0
    /* 2C1AC8 003C1AC8 7100043C */  lui        $4, %hi(D_0070AF70)
    /* 2C1ACC 003C1ACC 2D386000 */  daddu      $7, $3, $0
    /* 2C1AD0 003C1AD0 2D404000 */  daddu      $8, $2, $0
    /* 2C1AD4 003C1AD4 1C8E0F08 */  j          func_003e3870
    /* 2C1AD8 003C1AD8 70AF8424 */   addiu     $4, $4, %lo(D_0070AF70)
    /* 2C1ADC 003C1ADC 00000000 */  nop
.size func_003c1ab0, 0x30
