.section .text
.set noat
.set noreorder
glabel func_003ef890
    /* 2EF890 003EF890 2D10A000 */  daddu      $2, $5, $0
    /* 2EF894 003EF894 2D18C000 */  daddu      $3, $6, $0
    /* 2EF898 003EF898 2D288000 */  daddu      $5, $4, $0
    /* 2EF89C 003EF89C 2D304000 */  daddu      $6, $2, $0
    /* 2EF8A0 003EF8A0 2D10E000 */  daddu      $2, $7, $0
    /* 2EF8A4 003EF8A4 2D480001 */  daddu      $9, $8, $0
    /* 2EF8A8 003EF8A8 7100043C */  lui        $4, %hi(D_0070B800)
    /* 2EF8AC 003EF8AC 2D386000 */  daddu      $7, $3, $0
    /* 2EF8B0 003EF8B0 2D404000 */  daddu      $8, $2, $0
    /* 2EF8B4 003EF8B4 1C8E0F08 */  j          func_003e3870
    /* 2EF8B8 003EF8B8 00B88424 */   addiu     $4, $4, %lo(D_0070B800)
    /* 2EF8BC 003EF8BC 00000000 */  nop
.size func_003ef890, 0x30
