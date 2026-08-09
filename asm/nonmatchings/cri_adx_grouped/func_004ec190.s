.section .text
.set noat
.set noreorder
glabel func_004ec190
    /* 3EC190 004EC190 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC194 004EC194 01000624 */  addiu      $6, $0, 0x1
    /* 3EC198 004EC198 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC19C 004EC19C 05006614 */  bne        $3, $6, .L004EC1B4
    /* 3EC1A0 004EC1A0 2D388000 */   daddu     $7, $4, $0
    /* 3EC1A4 004EC1A4 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC1A8 004EC1A8 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC1AC 004EC1AC 09006018 */  blez       $3, .L004EC1D4
    /* 3EC1B0 004EC1B0 00000000 */   nop
  .L004EC1B4:
    /* 3EC1B4 004EC1B4 7400023C */  lui        $2, %hi(D_0073A788)
    /* 3EC1B8 004EC1B8 02000424 */  addiu      $4, $0, 0x2
    /* 3EC1BC 004EC1BC 88A7438C */  lw         $3, %lo(D_0073A788)($2)
    /* 3EC1C0 004EC1C0 04006414 */  bne        $3, $4, .L004EC1D4
    /* 3EC1C4 004EC1C4 00000000 */   nop
    /* 3EC1C8 004EC1C8 5600E280 */  lb         $2, 0x56($7)
    /* 3EC1CC 004EC1CC 01004554 */  bnel       $2, $5, .L004EC1D4
    /* 3EC1D0 004EC1D0 5600E5A0 */   sb        $5, 0x56($7)
  .L004EC1D4:
    /* 3EC1D4 004EC1D4 0800E003 */  jr         $31
    /* 3EC1D8 004EC1D8 00000000 */   nop
    /* 3EC1DC 004EC1DC 00000000 */  nop
.size func_004ec190, 0x50
