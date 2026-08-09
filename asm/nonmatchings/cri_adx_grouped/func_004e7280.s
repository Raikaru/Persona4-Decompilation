.section .text
.set noat
.set noreorder
glabel func_004e7280
    /* 3E7280 004E7280 7300023C */  lui        $2, %hi(D_00733DC0)
    /* 3E7284 004E7284 7300033C */  lui        $3, %hi(D_00733DC4)
    /* 3E7288 004E7288 C03D4224 */  addiu      $2, $2, %lo(D_00733DC0)
    /* 3E728C 004E728C C43D67AC */  sw         $7, %lo(D_00733DC4)($3)
    /* 3E7290 004E7290 020046A0 */  sb         $6, 0x2($2)
    /* 3E7294 004E7294 000044A0 */  sb         $4, 0x0($2)
    /* 3E7298 004E7298 0800E003 */  jr         $31
    /* 3E729C 004E729C 010045A0 */   sb        $5, 0x1($2)
.size func_004e7280, 0x20
