.section .text
.set noat
.set noreorder
glabel func_004e9e68
    /* 3E9E68 004E9E68 7400023C */  lui        $2, %hi(D_00738CF4)
    /* 3E9E6C 004E9E6C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E9E70 004E9E70 F48C438C */  lw         $3, %lo(D_00738CF4)($2)
    /* 3E9E74 004E9E74 2D308000 */  daddu      $6, $4, $0
    /* 3E9E78 004E9E78 04006010 */  beqz       $3, .L004E9E8C
    /* 3E9E7C 004E9E7C 0000BFFF */   sd        $31, 0x0($29)
    /* 3E9E80 004E9E80 7400023C */  lui        $2, %hi(D_00738CF8)
    /* 3E9E84 004E9E84 09F86000 */  jalr       $3
    /* 3E9E88 004E9E88 F88C448C */   lw        $4, %lo(D_00738CF8)($2)
  .L004E9E8C:
    /* 3E9E8C 004E9E8C 0000BFDF */  ld         $31, 0x0($29)
    /* 3E9E90 004E9E90 0800E003 */  jr         $31
    /* 3E9E94 004E9E94 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e9e68, 0x30
