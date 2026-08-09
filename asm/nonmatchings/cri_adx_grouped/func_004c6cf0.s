.section .text
.set noat
.set noreorder
glabel func_004c6cf0
    /* 3C6CF0 004C6CF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6CF4 004C6CF4 21288500 */  addu       $5, $4, $5
    /* 3C6CF8 004C6CF8 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6CFC 004C6CFC FFFFA524 */  addiu      $5, $5, -0x1
    /* 3C6D00 004C6D00 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6D04 004C6D04 86881008 */  j          func_00422218
    /* 3C6D08 004C6D08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C6D0C 004C6D0C 00000000 */  nop
.size func_004c6cf0, 0x20
