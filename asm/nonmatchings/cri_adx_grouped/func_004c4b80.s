.section .text
.set noat
.set noreorder
glabel func_004c4b80
    /* 3C4B80 004C4B80 7500053C */  lui        $5, %hi(D_00757E30)
    /* 3C4B84 004C4B84 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C4B88 004C4B88 04000624 */  addiu      $6, $0, 0x4
    /* 3C4B8C 004C4B8C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C4B90 004C4B90 DEFD100C */  jal        func_0043f778
    /* 3C4B94 004C4B94 307EA524 */   addiu     $5, $5, %lo(D_00757E30)
    /* 3C4B98 004C4B98 0000BFDF */  ld         $31, 0x0($29)
    /* 3C4B9C 004C4B9C 0100422C */  sltiu      $2, $2, 0x1
    /* 3C4BA0 004C4BA0 0800E003 */  jr         $31
    /* 3C4BA4 004C4BA4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c4b80, 0x28
