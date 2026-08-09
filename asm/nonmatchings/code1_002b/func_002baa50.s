.section .text
.set noat
.set noreorder
glabel func_002baa50
    /* 1BAA50 002BAA50 2D280000 */  daddu      $5, $0, $0
    /* 1BAA54 002BAA54 8800043C */  lui        $4, %hi(D_00882F40)
    /* 1BAA58 002BAA58 402F8424 */  addiu      $4, $4, %lo(D_00882F40)
    /* 1BAA5C 002BAA5C 05000010 */  b          .L002BAA74
    /* 1BAA60 002BAA60 00000000 */   nop
  .L002BAA64:
    /* 1BAA64 002BAA64 80180500 */  sll        $3, $5, 2
    /* 1BAA68 002BAA68 21188300 */  addu       $3, $4, $3
    /* 1BAA6C 002BAA6C 000060AC */  sw         $0, 0x0($3)
    /* 1BAA70 002BAA70 0100A524 */  addiu      $5, $5, 0x1
  .L002BAA74:
    /* 1BAA74 002BAA74 0500A328 */  slti       $3, $5, 0x5
    /* 1BAA78 002BAA78 FAFF6014 */  bnez       $3, .L002BAA64
    /* 1BAA7C 002BAA7C 00000000 */   nop
    /* 1BAA80 002BAA80 0800E003 */  jr         $31
    /* 1BAA84 002BAA84 00000000 */   nop
    /* 1BAA88 002BAA88 00000000 */  nop
    /* 1BAA8C 002BAA8C 00000000 */  nop
.size func_002baa50, 0x40
