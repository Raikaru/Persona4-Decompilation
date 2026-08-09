.section .text
.set noat
.set noreorder
glabel func_004de278
    /* 3DE278 004DE278 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE27C 004DE27C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE280 004DE280 0000848C */  lw         $4, 0x0($4)
    /* 3DE284 004DE284 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE288 004DE288 32691308 */  j          func_004da4c8
    /* 3DE28C 004DE28C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de278, 0x18
