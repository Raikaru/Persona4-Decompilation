.section .text
.set noat
.set noreorder
glabel func_0052bbd8
    /* 42BBD8 0052BBD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BBDC 0052BBDC 0000BFFF */  sd         $31, 0x0($29)
    /* 42BBE0 0052BBE0 2400848C */  lw         $4, 0x24($4)
    /* 42BBE4 0052BBE4 0000BFDF */  ld         $31, 0x0($29)
    /* 42BBE8 0052BBE8 E4B11408 */  j          func_0052c790
    /* 42BBEC 0052BBEC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052bbd8, 0x18
