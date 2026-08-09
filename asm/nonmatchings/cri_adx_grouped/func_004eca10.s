.section .text
.set noat
.set noreorder
glabel func_004eca10
    /* 3ECA10 004ECA10 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECA14 004ECA14 01000424 */  addiu      $4, $0, 0x1
    /* 3ECA18 004ECA18 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECA1C 004ECA1C 06006414 */  bne        $3, $4, .L004ECA38
    /* 3ECA20 004ECA20 7400033C */   lui       $3, %hi(D_0073A774)
    /* 3ECA24 004ECA24 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ECA28 004ECA28 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ECA2C 004ECA2C 03006018 */  blez       $3, .L004ECA3C
    /* 3ECA30 004ECA30 2D100000 */   daddu     $2, $0, $0
    /* 3ECA34 004ECA34 7400033C */  lui        $3, %hi(D_0073A774)
  .L004ECA38:
    /* 3ECA38 004ECA38 74A7628C */  lw         $2, %lo(D_0073A774)($3)
  .L004ECA3C:
    /* 3ECA3C 004ECA3C 0800E003 */  jr         $31
    /* 3ECA40 004ECA40 00000000 */   nop
    /* 3ECA44 004ECA44 00000000 */  nop
.size func_004eca10, 0x38
