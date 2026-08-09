.section .text
.set noat
.set noreorder
glabel func_004cec00
    /* 3CEC00 004CEC00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEC04 004CEC04 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEC08 004CEC08 0400848C */  lw         $4, 0x4($4)
    /* 3CEC0C 004CEC0C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEC10 004CEC10 22101308 */  j          func_004c4088
    /* 3CEC14 004CEC14 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cec00, 0x18
