.section .text
.set noat
.set noreorder
glabel func_004eca48
    /* 3ECA48 004ECA48 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3ECA4C 004ECA4C 01000624 */  addiu      $6, $0, 0x1
    /* 3ECA50 004ECA50 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3ECA54 004ECA54 05006654 */  bnel       $3, $6, .L004ECA6C
    /* 3ECA58 004ECA58 5B0085A0 */   sb        $5, 0x5B($4)
    /* 3ECA5C 004ECA5C 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3ECA60 004ECA60 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3ECA64 004ECA64 0100605C */  bgtzl      $3, .L004ECA6C
    /* 3ECA68 004ECA68 5B0085A0 */   sb        $5, 0x5B($4)
  .L004ECA6C:
    /* 3ECA6C 004ECA6C 0800E003 */  jr         $31
    /* 3ECA70 004ECA70 00000000 */   nop
    /* 3ECA74 004ECA74 00000000 */  nop
.size func_004eca48, 0x30
