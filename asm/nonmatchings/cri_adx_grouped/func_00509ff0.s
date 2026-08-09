.section .text
.set noat
.set noreorder
glabel func_00509ff0
    /* 409FF0 00509FF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 409FF4 00509FF4 0000BFFF */  sd         $31, 0x0($29)
    /* 409FF8 00509FF8 A402848C */  lw         $4, 0x2A4($4)
    /* 409FFC 00509FFC 0000BFDF */  ld         $31, 0x0($29)
    /* 40A000 0050A000 A81F1408 */  j          func_00507ea0
    /* 40A004 0050A004 1000BD27 */   addiu     $29, $29, 0x10
.size func_00509ff0, 0x18
