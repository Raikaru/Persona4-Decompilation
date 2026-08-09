.section .text
.set noat
.set noreorder
glabel func_003e9eb0
    /* 2E9EB0 003E9EB0 2D10A000 */  daddu      $2, $5, $0
    /* 2E9EB4 003E9EB4 2D18C000 */  daddu      $3, $6, $0
    /* 2E9EB8 003E9EB8 2D288000 */  daddu      $5, $4, $0
    /* 2E9EBC 003E9EBC 2D304000 */  daddu      $6, $2, $0
    /* 2E9EC0 003E9EC0 2D10E000 */  daddu      $2, $7, $0
    /* 2E9EC4 003E9EC4 2D480001 */  daddu      $9, $8, $0
    /* 2E9EC8 003E9EC8 7100043C */  lui        $4, %hi(D_0070B7A0)
    /* 2E9ECC 003E9ECC 2D386000 */  daddu      $7, $3, $0
    /* 2E9ED0 003E9ED0 2D404000 */  daddu      $8, $2, $0
    /* 2E9ED4 003E9ED4 1C8E0F08 */  j          func_003e3870
    /* 2E9ED8 003E9ED8 A0B78424 */   addiu     $4, $4, %lo(D_0070B7A0)
    /* 2E9EDC 003E9EDC 00000000 */  nop
.size func_003e9eb0, 0x30
