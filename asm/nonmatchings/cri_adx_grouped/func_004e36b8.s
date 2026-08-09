.section .text
.set noat
.set noreorder
glabel func_004e36b8
    /* 3E36B8 004E36B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E36BC 004E36BC 7300023C */  lui        $2, %hi(D_00731C38)
    /* 3E36C0 004E36C0 0000BFFF */  sd         $31, 0x0($29)
    /* 3E36C4 004E36C4 381C4224 */  addiu      $2, $2, %lo(D_00731C38)
    /* 3E36C8 004E36C8 7300043C */  lui        $4, %hi(D_00731C00)
    /* 3E36CC 004E36CC 2D280000 */  daddu      $5, $0, $0
    /* 3E36D0 004E36D0 0000438C */  lw         $3, 0x0($2)
    /* 3E36D4 004E36D4 001C8424 */  addiu      $4, $4, %lo(D_00731C00)
    /* 3E36D8 004E36D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E36DC 004E36DC 38000624 */  addiu      $6, $0, 0x38
    /* 3E36E0 004E36E0 72FE1008 */  j          func_0043f9c8
    /* 3E36E4 004E36E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e36b8, 0x30
