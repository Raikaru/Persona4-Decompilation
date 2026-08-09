.section .text
.set noat
.set noreorder
glabel func_003ec3a0
    /* 2EC3A0 003EC3A0 2D10A000 */  daddu      $2, $5, $0
    /* 2EC3A4 003EC3A4 2D18C000 */  daddu      $3, $6, $0
    /* 2EC3A8 003EC3A8 2D288000 */  daddu      $5, $4, $0
    /* 2EC3AC 003EC3AC 2D304000 */  daddu      $6, $2, $0
    /* 2EC3B0 003EC3B0 2D10E000 */  daddu      $2, $7, $0
    /* 2EC3B4 003EC3B4 2D480001 */  daddu      $9, $8, $0
    /* 2EC3B8 003EC3B8 7100043C */  lui        $4, %hi(D_0070B7E0)
    /* 2EC3BC 003EC3BC 2D386000 */  daddu      $7, $3, $0
    /* 2EC3C0 003EC3C0 2D404000 */  daddu      $8, $2, $0
    /* 2EC3C4 003EC3C4 1C8E0F08 */  j          func_003e3870
    /* 2EC3C8 003EC3C8 E0B78424 */   addiu     $4, $4, %lo(D_0070B7E0)
    /* 2EC3CC 003EC3CC 00000000 */  nop
.size func_003ec3a0, 0x30
