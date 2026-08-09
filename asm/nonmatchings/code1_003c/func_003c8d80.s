.section .text
.set noat
.set noreorder
glabel func_003c8d80
    /* 2C8D80 003C8D80 2D108000 */  daddu      $2, $4, $0
    /* 2C8D84 003C8D84 2D30A000 */  daddu      $6, $5, $0
    /* 2C8D88 003C8D88 7100043C */  lui        $4, %hi(D_0070B040)
    /* 2C8D8C 003C8D8C 2D284000 */  daddu      $5, $2, $0
    /* 2C8D90 003C8D90 308C0F08 */  j          func_003e30c0
    /* 2C8D94 003C8D94 40B08424 */   addiu     $4, $4, %lo(D_0070B040)
    /* 2C8D98 003C8D98 00000000 */  nop
    /* 2C8D9C 003C8D9C 00000000 */  nop
.size func_003c8d80, 0x20
