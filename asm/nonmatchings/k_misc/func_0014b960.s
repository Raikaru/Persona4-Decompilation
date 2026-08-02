.section .text
.set noat
.set noreorder
glabel func_0014b960
    /* 4B960 0014B960 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4B964 0014B964 0000BFFF */  sd         $31, 0x0($29)
    /* 4B968 0014B968 3800848C */  lw         $4, 0x38($4)
    /* 4B96C 0014B96C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 4B970 0014B970 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 4B974 0014B974 09F84000 */  jalr       $2
    /* 4B978 0014B978 00000000 */   nop
    /* 4B97C 0014B97C 0000BFDF */  ld         $31, 0x0($29)
    /* 4B980 0014B980 1000BD27 */  addiu      $29, $29, 0x10
    /* 4B984 0014B984 0800E003 */  jr         $31
    /* 4B988 0014B988 00000000 */   nop
    /* 4B98C 0014B98C 00000000 */  nop
.size func_0014b960, 0x30
