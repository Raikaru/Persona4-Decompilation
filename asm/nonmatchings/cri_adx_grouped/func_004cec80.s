.section .text
.set noat
.set noreorder
glabel func_004cec80
    /* 3CEC80 004CEC80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEC84 004CEC84 002C0500 */  sll        $5, $5, 16
    /* 3CEC88 004CEC88 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEC8C 004CEC8C 00340600 */  sll        $6, $6, 16
    /* 3CEC90 004CEC90 003C0700 */  sll        $7, $7, 16
    /* 3CEC94 004CEC94 032C0500 */  sra        $5, $5, 16
    /* 3CEC98 004CEC98 0400848C */  lw         $4, 0x4($4)
    /* 3CEC9C 004CEC9C 03340600 */  sra        $6, $6, 16
    /* 3CECA0 004CECA0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CECA4 004CECA4 033C0700 */  sra        $7, $7, 16
    /* 3CECA8 004CECA8 900F1308 */  j          func_004c3e40
    /* 3CECAC 004CECAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cec80, 0x30
