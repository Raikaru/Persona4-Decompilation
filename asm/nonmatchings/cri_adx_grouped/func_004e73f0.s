.section .text
.set noat
.set noreorder
glabel func_004e73f0
    /* 3E73F0 004E73F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E73F4 004E73F4 7300023C */  lui        $2, %hi(D_00733F58)
    /* 3E73F8 004E73F8 0000BFFF */  sd         $31, 0x0($29)
    /* 3E73FC 004E73FC 583F4224 */  addiu      $2, $2, %lo(D_00733F58)
    /* 3E7400 004E7400 2D200000 */  daddu      $4, $0, $0
    /* 3E7404 004E7404 66A3130C */  jal        func_004e8d98
    /* 3E7408 004E7408 0000438C */   lw        $3, 0x0($2)
    /* 3E740C 004E740C 8AA3130C */  jal        func_004e8e28
    /* 3E7410 004E7410 2D200000 */   daddu     $4, $0, $0
    /* 3E7414 004E7414 7300023C */  lui        $2, %hi(D_00733F68)
    /* 3E7418 004E7418 0000BFDF */  ld         $31, 0x0($29)
    /* 3E741C 004E741C 683F4224 */  addiu      $2, $2, %lo(D_00733F68)
    /* 3E7420 004E7420 0800E003 */  jr         $31
    /* 3E7424 004E7424 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e73f0, 0x38
