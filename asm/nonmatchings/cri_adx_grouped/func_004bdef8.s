.section .text
.set noat
.set noreorder
glabel func_004bdef8
    /* 3BDEF8 004BDEF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDEFC 004BDEFC 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDF00 004BDF00 0400848C */  lw         $4, 0x4($4)
    /* 3BDF04 004BDF04 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDF08 004BDF08 DE5B1308 */  j          func_004d6f78
    /* 3BDF0C 004BDF0C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdef8, 0x18
