.section .text
.set noat
.set noreorder
glabel func_002be100
    /* 1BE100 002BE100 2D100000 */  daddu      $2, $0, $0
    /* 1BE104 002BE104 FF008630 */  andi       $6, $4, 0xFF
    /* 1BE108 002BE108 7500053C */  lui        $5, %hi(D_007488F8)
    /* 1BE10C 002BE10C F888A524 */  addiu      $5, $5, %lo(D_007488F8)
    /* 1BE110 002BE110 09000010 */  b          .L002BE138
    /* 1BE114 002BE114 00000000 */   nop
  .L002BE118:
    /* 1BE118 002BE118 2118A400 */  addu       $3, $5, $4
    /* 1BE11C 002BE11C 00006380 */  lb         $3, 0x0($3)
    /* 1BE120 002BE120 0300C314 */  bne        $6, $3, .L002BE130
    /* 1BE124 002BE124 00000000 */   nop
    /* 1BE128 002BE128 08000010 */  b          .L002BE14C
    /* 1BE12C 002BE12C 00000000 */   nop
  .L002BE130:
    /* 1BE130 002BE130 01004224 */  addiu      $2, $2, 0x1
    /* 1BE134 002BE134 FF004230 */  andi       $2, $2, 0xFF
  .L002BE138:
    /* 1BE138 002BE138 FF004430 */  andi       $4, $2, 0xFF
    /* 1BE13C 002BE13C 0C008328 */  slti       $3, $4, 0xC
    /* 1BE140 002BE140 F5FF6014 */  bnez       $3, .L002BE118
    /* 1BE144 002BE144 00000000 */   nop
    /* 1BE148 002BE148 2D100000 */  daddu      $2, $0, $0
  .L002BE14C:
    /* 1BE14C 002BE14C 0800E003 */  jr         $31
    /* 1BE150 002BE150 00000000 */   nop
    /* 1BE154 002BE154 00000000 */  nop
    /* 1BE158 002BE158 00000000 */  nop
    /* 1BE15C 002BE15C 00000000 */  nop
.size func_002be100, 0x60
