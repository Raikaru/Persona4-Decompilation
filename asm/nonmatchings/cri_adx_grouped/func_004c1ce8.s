.section .text
.set noat
.set noreorder
glabel func_004c1ce8
    /* 3C1CE8 004C1CE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C1CEC 004C1CEC 7100023C */  lui        $2, %hi(D_00714A14)
    /* 3C1CF0 004C1CF0 0000BFFF */  sd         $31, 0x0($29)
    /* 3C1CF4 004C1CF4 144A438C */  lw         $3, %lo(D_00714A14)($2)
    /* 3C1CF8 004C1CF8 09F86000 */  jalr       $3
    /* 3C1CFC 004C1CFC 00000000 */   nop
    /* 3C1D00 004C1D00 0000BFDF */  ld         $31, 0x0($29)
    /* 3C1D04 004C1D04 0800E003 */  jr         $31
    /* 3C1D08 004C1D08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C1D0C 004C1D0C 00000000 */  nop
.size func_004c1ce8, 0x28
