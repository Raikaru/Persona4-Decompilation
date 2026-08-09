.section .text
.set noat
.set noreorder
glabel func_004cedf0
    /* 3CEDF0 004CEDF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEDF4 004CEDF4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEDF8 004CEDF8 0400848C */  lw         $4, 0x4($4)
    /* 3CEDFC 004CEDFC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEE00 004CEE00 1C0F1308 */  j          func_004c3c70
    /* 3CEE04 004CEE04 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cedf0, 0x18
