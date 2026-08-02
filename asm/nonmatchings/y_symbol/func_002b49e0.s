.section .text
.set noat
.set noreorder
glabel func_002b49e0
    /* 1B49E0 002B49E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B49E4 002B49E4 0000BFFF */  sd         $31, 0x0($29)
    /* 1B49E8 002B49E8 3800848C */  lw         $4, 0x38($4)
    /* 1B49EC 002B49EC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1B49F0 002B49F0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1B49F4 002B49F4 09F84000 */  jalr       $2
    /* 1B49F8 002B49F8 00000000 */   nop
    /* 1B49FC 002B49FC 0000BFDF */  ld         $31, 0x0($29)
    /* 1B4A00 002B4A00 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B4A04 002B4A04 0800E003 */  jr         $31
    /* 1B4A08 002B4A08 00000000 */   nop
    /* 1B4A0C 002B4A0C 00000000 */  nop
.size func_002b49e0, 0x30
