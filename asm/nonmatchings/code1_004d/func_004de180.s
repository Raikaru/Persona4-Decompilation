.section .text
.set noat
.set noreorder
glabel func_004de180
    /* 3DE180 004DE180 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE184 004DE184 0000BFFF */  sd         $31, 0x0($29)
    /* 3DE188 004DE188 0000848C */  lw         $4, 0x0($4)
    /* 3DE18C 004DE18C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DE190 004DE190 12691308 */  j          func_004da448
    /* 3DE194 004DE194 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de180, 0x18
