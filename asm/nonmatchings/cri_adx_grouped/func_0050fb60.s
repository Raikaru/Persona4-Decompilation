.section .text
.set noat
.set noreorder
glabel func_0050fb60
    /* 40FB60 0050FB60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FB64 0050FB64 2D10A000 */  daddu      $2, $5, $0
    /* 40FB68 0050FB68 0000BFFF */  sd         $31, 0x0($29)
    /* 40FB6C 0050FB6C 2D400000 */  daddu      $8, $0, $0
    /* 40FB70 0050FB70 2D480000 */  daddu      $9, $0, $0
    /* 40FB74 0050FB74 10004B8C */  lw         $11, 0x10($2)
    /* 40FB78 0050FB78 0C004A8C */  lw         $10, 0xC($2)
    /* 40FB7C 0050FB7C 0000BFDF */  ld         $31, 0x0($29)
    /* 40FB80 0050FB80 E23E1408 */  j          func_0050fb88
    /* 40FB84 0050FB84 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050fb60, 0x28
