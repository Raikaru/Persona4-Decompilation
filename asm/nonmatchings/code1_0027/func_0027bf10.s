.section .text
.set noat
.set noreorder
glabel func_0027bf10
    /* 17BF10 0027BF10 80180400 */  sll        $3, $4, 2
    /* 17BF14 0027BF14 6400023C */  lui        $2, %hi(D_0063BF80)
    /* 17BF18 0027BF18 80BF4224 */  addiu      $2, $2, %lo(D_0063BF80)
    /* 17BF1C 0027BF1C 21104300 */  addu       $2, $2, $3
    /* 17BF20 0027BF20 0000428C */  lw         $2, 0x0($2)
    /* 17BF24 0027BF24 0800E003 */  jr         $31
    /* 17BF28 0027BF28 00000000 */   nop
    /* 17BF2C 0027BF2C 00000000 */  nop
.size func_0027bf10, 0x20
