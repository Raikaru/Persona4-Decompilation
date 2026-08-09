.section .text
.set noat
.set noreorder
glabel func_004ec300
    /* 3EC300 004EC300 80180400 */  sll        $3, $4, 2
    /* 3EC304 004EC304 0200842C */  sltiu      $4, $4, 0x2
    /* 3EC308 004EC308 04008010 */  beqz       $4, .L004EC31C
    /* 3EC30C 004EC30C 2D100000 */   daddu     $2, $0, $0
    /* 3EC310 004EC310 7400023C */  lui        $2, %hi(D_0073A780)
    /* 3EC314 004EC314 21104300 */  addu       $2, $2, $3
    /* 3EC318 004EC318 80A7428C */  lw         $2, %lo(D_0073A780)($2)
  .L004EC31C:
    /* 3EC31C 004EC31C 0800E003 */  jr         $31
    /* 3EC320 004EC320 00000000 */   nop
    /* 3EC324 004EC324 00000000 */  nop
.size func_004ec300, 0x28
