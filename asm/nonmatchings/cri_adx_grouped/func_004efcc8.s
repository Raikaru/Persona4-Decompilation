.section .text
.set noat
.set noreorder
glabel func_004efcc8
    /* 3EFCC8 004EFCC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFCCC 004EFCCC 9200053C */  lui        $5, %hi(D_009259C0)
    /* 3EFCD0 004EFCD0 0000BFFF */  sd         $31, 0x0($29)
    /* 3EFCD4 004EFCD4 C059A524 */  addiu      $5, $5, %lo(D_009259C0)
    /* 3EFCD8 004EFCD8 0000A4AC */  sw         $4, 0x0($5)
    /* 3EFCDC 004EFCDC 23000424 */  addiu      $4, $0, 0x23
    /* 3EFCE0 004EFCE0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EFCE4 004EFCE4 01000624 */  addiu      $6, $0, 0x1
    /* 3EFCE8 004EFCE8 2D380000 */  daddu      $7, $0, $0
    /* 3EFCEC 004EFCEC 2D400000 */  daddu      $8, $0, $0
    /* 3EFCF0 004EFCF0 28961308 */  j          func_004e58a0
    /* 3EFCF4 004EFCF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004efcc8, 0x30
