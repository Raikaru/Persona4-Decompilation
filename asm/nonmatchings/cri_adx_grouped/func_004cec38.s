.section .text
.set noat
.set noreorder
glabel func_004cec38
    /* 3CEC38 004CEC38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEC3C 004CEC3C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEC40 004CEC40 0400848C */  lw         $4, 0x4($4)
    /* 3CEC44 004CEC44 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEC48 004CEC48 5C0F1308 */  j          func_004c3d70
    /* 3CEC4C 004CEC4C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cec38, 0x18
