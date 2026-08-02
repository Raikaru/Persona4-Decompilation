.section .text
.set noat
.set noreorder
glabel func_002b9f60
    /* 1B9F60 002B9F60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B9F64 002B9F64 0000BFFF */  sd         $31, 0x0($29)
    /* 1B9F68 002B9F68 3800848C */  lw         $4, 0x38($4)
    /* 1B9F6C 002B9F6C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1B9F70 002B9F70 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1B9F74 002B9F74 09F84000 */  jalr       $2
    /* 1B9F78 002B9F78 00000000 */   nop
    /* 1B9F7C 002B9F7C 0000BFDF */  ld         $31, 0x0($29)
    /* 1B9F80 002B9F80 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B9F84 002B9F84 0800E003 */  jr         $31
    /* 1B9F88 002B9F88 00000000 */   nop
    /* 1B9F8C 002B9F8C 00000000 */  nop
.size func_002b9f60, 0x30
