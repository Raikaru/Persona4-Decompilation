.section .text
.set noat
.set noreorder
glabel func_004c0fe8
    /* 3C0FE8 004C0FE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C0FEC 004C0FEC 0000BFFF */  sd         $31, 0x0($29)
    /* 3C0FF0 004C0FF0 0400848C */  lw         $4, 0x4($4)
    /* 3C0FF4 004C0FF4 0000BFDF */  ld         $31, 0x0($29)
    /* 3C0FF8 004C0FF8 D6F51208 */  j          func_004bd758
    /* 3C0FFC 004C0FFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c0fe8, 0x18
