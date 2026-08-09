.section .text
.set noat
.set noreorder
glabel func_004ed180
    /* 3ED180 004ED180 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ED184 004ED184 01000424 */  addiu      $4, $0, 0x1
    /* 3ED188 004ED188 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ED18C 004ED18C 03006414 */  bne        $3, $4, .L004ED19C
    /* 3ED190 004ED190 10000224 */   addiu     $2, $0, 0x10
    /* 3ED194 004ED194 7400043C */  lui        $4, %hi(D_0073A740)
    /* 3ED198 004ED198 40A7838C */  lw         $3, %lo(D_0073A740)($4)
  .L004ED19C:
    /* 3ED19C 004ED19C 0800E003 */  jr         $31
    /* 3ED1A0 004ED1A0 00000000 */   nop
    /* 3ED1A4 004ED1A4 00000000 */  nop
.size func_004ed180, 0x28
