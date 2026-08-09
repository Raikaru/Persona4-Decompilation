.section .text
.set noat
.set noreorder
glabel func_004ec9e0
    /* 3EC9E0 004EC9E0 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EC9E4 004EC9E4 01000524 */  addiu      $5, $0, 0x1
    /* 3EC9E8 004EC9E8 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EC9EC 004EC9EC 05006514 */  bne        $3, $5, .L004ECA04
    /* 3EC9F0 004EC9F0 7400023C */   lui       $2, %hi(D_0073A774)
    /* 3EC9F4 004EC9F4 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EC9F8 004EC9F8 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EC9FC 004EC9FC 02006018 */  blez       $3, .L004ECA08
    /* 3ECA00 004ECA00 7400023C */   lui       $2, %hi(D_0073A774)
  .L004ECA04:
    /* 3ECA04 004ECA04 74A744AC */  sw         $4, %lo(D_0073A774)($2)
  .L004ECA08:
    /* 3ECA08 004ECA08 0800E003 */  jr         $31
    /* 3ECA0C 004ECA0C 00000000 */   nop
.size func_004ec9e0, 0x30
