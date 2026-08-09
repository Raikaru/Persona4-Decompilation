.section .text
.set noat
.set noreorder
glabel func_003c2b70
    /* 2C2B70 003C2B70 2D10A000 */  daddu      $2, $5, $0
    /* 2C2B74 003C2B74 2D18C000 */  daddu      $3, $6, $0
    /* 2C2B78 003C2B78 2D288000 */  daddu      $5, $4, $0
    /* 2C2B7C 003C2B7C 2D304000 */  daddu      $6, $2, $0
    /* 2C2B80 003C2B80 2D10E000 */  daddu      $2, $7, $0
    /* 2C2B84 003C2B84 2D480001 */  daddu      $9, $8, $0
    /* 2C2B88 003C2B88 7100043C */  lui        $4, %hi(D_0070AFB0)
    /* 2C2B8C 003C2B8C 2D386000 */  daddu      $7, $3, $0
    /* 2C2B90 003C2B90 2D404000 */  daddu      $8, $2, $0
    /* 2C2B94 003C2B94 1C8E0F08 */  j          func_003e3870
    /* 2C2B98 003C2B98 B0AF8424 */   addiu     $4, $4, %lo(D_0070AFB0)
    /* 2C2B9C 003C2B9C 00000000 */  nop
.size func_003c2b70, 0x30
