.section .text
.set noat
.set noreorder
glabel func_0033e3a0
    /* 23E3A0 0033E3A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 23E3A4 0033E3A4 1000BFFF */  sd         $31, 0x10($29)
    /* 23E3A8 0033E3A8 0000B07F */  sq         $16, 0x0($29)
    /* 23E3AC 0033E3AC 2D808000 */  daddu      $16, $4, $0
    /* 23E3B0 0033E3B0 3800828C */  lw         $2, 0x38($4)
    /* 23E3B4 0033E3B4 0400448C */  lw         $4, 0x4($2)
    /* 23E3B8 0033E3B8 34AC110C */  jal        func_0046b0d0
    /* 23E3BC 0033E3BC 00000000 */   nop
    /* 23E3C0 0033E3C0 3800048E */  lw         $4, 0x38($16)
    /* 23E3C4 0033E3C4 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 23E3C8 0033E3C8 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 23E3CC 0033E3CC 09F84000 */  jalr       $2
    /* 23E3D0 0033E3D0 00000000 */   nop
    /* 23E3D4 0033E3D4 1000BFDF */  ld         $31, 0x10($29)
    /* 23E3D8 0033E3D8 0000B07B */  lq         $16, 0x0($29)
    /* 23E3DC 0033E3DC 2000BD27 */  addiu      $29, $29, 0x20
    /* 23E3E0 0033E3E0 0800E003 */  jr         $31
    /* 23E3E4 0033E3E4 00000000 */   nop
    /* 23E3E8 0033E3E8 00000000 */  nop
    /* 23E3EC 0033E3EC 00000000 */  nop
.size func_0033e3a0, 0x50
