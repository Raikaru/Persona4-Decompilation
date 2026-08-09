.section .text
.set noat
.set noreorder
glabel func_003c8d60
    /* 2C8D60 003C8D60 2D108000 */  daddu      $2, $4, $0
    /* 2C8D64 003C8D64 2D30A000 */  daddu      $6, $5, $0
    /* 2C8D68 003C8D68 7100043C */  lui        $4, %hi(D_0070B040)
    /* 2C8D6C 003C8D6C 2D284000 */  daddu      $5, $2, $0
    /* 2C8D70 003C8D70 1C8C0F08 */  j          func_003e3070
    /* 2C8D74 003C8D74 40B08424 */   addiu     $4, $4, %lo(D_0070B040)
    /* 2C8D78 003C8D78 00000000 */  nop
    /* 2C8D7C 003C8D7C 00000000 */  nop
.size func_003c8d60, 0x20
