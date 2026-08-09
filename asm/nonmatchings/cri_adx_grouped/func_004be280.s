.section .text
.set noat
.set noreorder
glabel func_004be280
    /* 3BE280 004BE280 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE284 004BE284 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE288 004BE288 0400848C */  lw         $4, 0x4($4)
    /* 3BE28C 004BE28C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE290 004BE290 2E7B1308 */  j          func_004decb8
    /* 3BE294 004BE294 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be280, 0x18
