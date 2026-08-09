.section .text
.set noat
.set noreorder
glabel func_004ed118
    /* 3ED118 004ED118 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED11C 004ED11C 01000624 */  addiu      $6, $0, 0x1
    /* 3ED120 004ED120 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED124 004ED124 2D388000 */  daddu      $7, $4, $0
    /* 3ED128 004ED128 05006614 */  bne        $3, $6, .L004ED140
    /* 3ED12C 004ED12C 80280500 */   sll       $5, $5, 2
    /* 3ED130 004ED130 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED134 004ED134 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED138 004ED138 03006018 */  blez       $3, .L004ED148
    /* 3ED13C 004ED13C 2D100000 */   daddu     $2, $0, $0
  .L004ED140:
    /* 3ED140 004ED140 2118A700 */  addu       $3, $5, $7
    /* 3ED144 004ED144 4000628C */  lw         $2, 0x40($3)
  .L004ED148:
    /* 3ED148 004ED148 0800E003 */  jr         $31
    /* 3ED14C 004ED14C 00000000 */   nop
.size func_004ed118, 0x38
