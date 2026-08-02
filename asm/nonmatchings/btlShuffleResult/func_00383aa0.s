.section .text
.set noat
.set noreorder
glabel func_00383aa0
    /* 283AA0 00383AA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 283AA4 00383AA4 1000BFFF */  sd         $31, 0x10($29)
    /* 283AA8 00383AA8 0000B07F */  sq         $16, 0x0($29)
    /* 283AAC 00383AAC 3800908C */  lw         $16, 0x38($4)
    /* 283AB0 00383AB0 38ED0A0C */  jal        func_002bb4e0
    /* 283AB4 00383AB4 00000000 */   nop
    /* 283AB8 00383AB8 2D200002 */  daddu      $4, $16, $0
    /* 283ABC 00383ABC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 283AC0 00383AC0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 283AC4 00383AC4 09F84000 */  jalr       $2
    /* 283AC8 00383AC8 00000000 */   nop
    /* 283ACC 00383ACC 1000BFDF */  ld         $31, 0x10($29)
    /* 283AD0 00383AD0 0000B07B */  lq         $16, 0x0($29)
    /* 283AD4 00383AD4 2000BD27 */  addiu      $29, $29, 0x20
    /* 283AD8 00383AD8 0800E003 */  jr         $31
    /* 283ADC 00383ADC 00000000 */   nop
.size func_00383aa0, 0x40
