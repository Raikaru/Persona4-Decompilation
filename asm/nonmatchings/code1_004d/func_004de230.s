.section .text
.set noat
.set noreorder
glabel func_004de230
    /* 3DE230 004DE230 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE234 004DE234 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE238 004DE238 0000848C */  lw         $4, 0x0($4)
    /* 3DE23C 004DE23C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE240 004DE240 54691308 */  j          func_004da550
    /* 3DE244 004DE244 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de230, 0x18
