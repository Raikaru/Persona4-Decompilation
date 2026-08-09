.section .text
.set noat
.set noreorder
glabel func_004e5a08
    /* 3E5A08 004E5A08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E5A0C 004E5A0C 7300023C */  lui        $2, %hi(D_007330C0)
    /* 3E5A10 004E5A10 0000BFFF */  sd         $31, 0x0($29)
    /* 3E5A14 004E5A14 C0304224 */  addiu      $2, $2, %lo(D_007330C0)
    /* 3E5A18 004E5A18 2D200000 */  daddu      $4, $0, $0
    /* 3E5A1C 004E5A1C A89C130C */  jal        func_004e72a0
    /* 3E5A20 004E5A20 0000438C */   lw        $3, 0x0($2)
    /* 3E5A24 004E5A24 0000BFDF */  ld         $31, 0x0($29)
    /* 3E5A28 004E5A28 7300023C */  lui        $2, %hi(D_007330D8)
    /* 3E5A2C 004E5A2C D8304224 */  addiu      $2, $2, %lo(D_007330D8)
    /* 3E5A30 004E5A30 0800E003 */  jr         $31
    /* 3E5A34 004E5A34 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e5a08, 0x30
