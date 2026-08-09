.section .text
.set noat
.set noreorder
glabel func_004ed0b8
    /* 3ED0B8 004ED0B8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED0BC 004ED0BC 01000524 */  addiu      $5, $0, 0x1
    /* 3ED0C0 004ED0C0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED0C4 004ED0C4 05006514 */  bne        $3, $5, .L004ED0DC
    /* 3ED0C8 004ED0C8 2D308000 */   daddu     $6, $4, $0
    /* 3ED0CC 004ED0CC 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED0D0 004ED0D0 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED0D4 004ED0D4 02006018 */  blez       $3, .L004ED0E0
    /* 3ED0D8 004ED0D8 2D100000 */   daddu     $2, $0, $0
  .L004ED0DC:
    /* 3ED0DC 004ED0DC 3000C28C */  lw         $2, 0x30($6)
  .L004ED0E0:
    /* 3ED0E0 004ED0E0 0800E003 */  jr         $31
    /* 3ED0E4 004ED0E4 00000000 */   nop
.size func_004ed0b8, 0x30
