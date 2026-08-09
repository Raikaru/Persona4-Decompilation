.section .text
.set noat
.set noreorder
glabel func_004ec9b0
    /* 3EC9B0 004EC9B0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC9B4 004EC9B4 01000624 */  addiu      $6, $0, 0x1
    /* 3EC9B8 004EC9B8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC9BC 004EC9BC 05006654 */  bnel       $3, $6, .L004EC9D4
    /* 3EC9C0 004EC9C0 500085A0 */   sb        $5, 0x50($4)
    /* 3EC9C4 004EC9C4 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC9C8 004EC9C8 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC9CC 004EC9CC 0100605C */  bgtzl      $3, .L004EC9D4
    /* 3EC9D0 004EC9D0 500085A0 */   sb        $5, 0x50($4)
  .L004EC9D4:
    /* 3EC9D4 004EC9D4 0800E003 */  jr         $31
    /* 3EC9D8 004EC9D8 00000000 */   nop
    /* 3EC9DC 004EC9DC 00000000 */  nop
.size func_004ec9b0, 0x30
