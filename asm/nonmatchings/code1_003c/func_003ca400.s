.section .text
.set noat
.set noreorder
glabel func_003ca400
    /* 2CA400 003CA400 2D18A000 */  daddu      $3, $5, $0
    /* 2CA404 003CA404 2D10C000 */  daddu      $2, $6, $0
    /* 2CA408 003CA408 2D288000 */  daddu      $5, $4, $0
    /* 2CA40C 003CA40C 2D40E000 */  daddu      $8, $7, $0
    /* 2CA410 003CA410 7100043C */  lui        $4, %hi(D_0070B060)
    /* 2CA414 003CA414 2D306000 */  daddu      $6, $3, $0
    /* 2CA418 003CA418 60B08424 */  addiu      $4, $4, %lo(D_0070B060)
    /* 2CA41C 003CA41C 088C0F08 */  j          func_003e3020
    /* 2CA420 003CA420 2D384000 */   daddu     $7, $2, $0
    /* 2CA424 003CA424 00000000 */  nop
    /* 2CA428 003CA428 00000000 */  nop
    /* 2CA42C 003CA42C 00000000 */  nop
.size func_003ca400, 0x30
