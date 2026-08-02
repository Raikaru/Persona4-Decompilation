.section .text
.set noat
.set noreorder
glabel func_00275bd0
    /* 175BD0 00275BD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 175BD4 00275BD4 0000BFFF */  sd         $31, 0x0($29)
    /* 175BD8 00275BD8 C8B4848F */  lw         $4, -0x4B38($28)
    /* 175BDC 00275BDC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 175BE0 00275BE0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 175BE4 00275BE4 09F84000 */  jalr       $2
    /* 175BE8 00275BE8 00000000 */   nop
    /* 175BEC 00275BEC C8B480AF */  sw         $0, -0x4B38($28)
    /* 175BF0 00275BF0 0000BFDF */  ld         $31, 0x0($29)
    /* 175BF4 00275BF4 1000BD27 */  addiu      $29, $29, 0x10
    /* 175BF8 00275BF8 0800E003 */  jr         $31
    /* 175BFC 00275BFC 00000000 */   nop
.size func_00275bd0, 0x30
