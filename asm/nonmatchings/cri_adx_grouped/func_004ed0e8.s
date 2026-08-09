.section .text
.set noat
.set noreorder
glabel func_004ed0e8
    /* 3ED0E8 004ED0E8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED0EC 004ED0EC 01000524 */  addiu      $5, $0, 0x1
    /* 3ED0F0 004ED0F0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED0F4 004ED0F4 05006514 */  bne        $3, $5, .L004ED10C
    /* 3ED0F8 004ED0F8 2D308000 */   daddu     $6, $4, $0
    /* 3ED0FC 004ED0FC 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED100 004ED100 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED104 004ED104 02006018 */  blez       $3, .L004ED110
    /* 3ED108 004ED108 2D100000 */   daddu     $2, $0, $0
  .L004ED10C:
    /* 3ED10C 004ED10C 3800C28C */  lw         $2, 0x38($6)
  .L004ED110:
    /* 3ED110 004ED110 0800E003 */  jr         $31
    /* 3ED114 004ED114 00000000 */   nop
.size func_004ed0e8, 0x30
