.section .text
.set noat
.set noreorder
glabel func_004e5a38
    /* 3E5A38 004E5A38 7300023C */  lui        $2, %hi(D_007330C4)
    /* 3E5A3C 004E5A3C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E5A40 004E5A40 C430438C */  lw         $3, %lo(D_007330C4)($2)
    /* 3E5A44 004E5A44 2D308000 */  daddu      $6, $4, $0
    /* 3E5A48 004E5A48 04006010 */  beqz       $3, .L004E5A5C
    /* 3E5A4C 004E5A4C 0000BFFF */   sd        $31, 0x0($29)
    /* 3E5A50 004E5A50 7300023C */  lui        $2, %hi(D_007330C8)
    /* 3E5A54 004E5A54 09F86000 */  jalr       $3
    /* 3E5A58 004E5A58 C830448C */   lw        $4, %lo(D_007330C8)($2)
  .L004E5A5C:
    /* 3E5A5C 004E5A5C 0000BFDF */  ld         $31, 0x0($29)
    /* 3E5A60 004E5A60 0800E003 */  jr         $31
    /* 3E5A64 004E5A64 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e5a38, 0x30
