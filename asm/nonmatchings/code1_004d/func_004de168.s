.section .text
.set noat
.set noreorder
glabel func_004de168
    /* 3DE168 004DE168 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE16C 004DE16C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE170 004DE170 0000848C */  lw         $4, 0x0($4)
    /* 3DE174 004DE174 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE178 004DE178 0C691308 */  j          func_004da430
    /* 3DE17C 004DE17C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de168, 0x18
