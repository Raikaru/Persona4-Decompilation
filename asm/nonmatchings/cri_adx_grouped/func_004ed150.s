.section .text
.set noat
.set noreorder
glabel func_004ed150
    /* 3ED150 004ED150 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED154 004ED154 01000524 */  addiu      $5, $0, 0x1
    /* 3ED158 004ED158 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED15C 004ED15C 05006514 */  bne        $3, $5, .L004ED174
    /* 3ED160 004ED160 2D308000 */   daddu     $6, $4, $0
    /* 3ED164 004ED164 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED168 004ED168 40A7838C */  lw         $3, %lo(D_0073A740)($4)
    /* 3ED16C 004ED16C 02006018 */  blez       $3, .L004ED178
    /* 3ED170 004ED170 2D100000 */   daddu     $2, $0, $0
  .L004ED174:
    /* 3ED174 004ED174 5C00C28C */  lw         $2, 0x5C($6)
  .L004ED178:
    /* 3ED178 004ED178 0800E003 */  jr         $31
    /* 3ED17C 004ED17C 00000000 */   nop
.size func_004ed150, 0x30
