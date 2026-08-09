.section .text
.set noat
.set noreorder
glabel func_003b84a0
    /* 2B84A0 003B84A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2B84A4 003B84A4 1000BFFF */  sd         $31, 0x10($29)
    /* 2B84A8 003B84A8 0000B07F */  sq         $16, 0x0($29)
    /* 2B84AC 003B84AC 2D808000 */  daddu      $16, $4, $0
    /* 2B84B0 003B84B0 4400848C */  lw         $4, 0x44($4)
    /* 2B84B4 003B84B4 05008010 */  beqz       $4, .L003B84CC
    /* 2B84B8 003B84B8 00000000 */   nop
    /* 2B84BC 003B84BC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2B84C0 003B84C0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2B84C4 003B84C4 09F84000 */  jalr       $2
    /* 2B84C8 003B84C8 00000000 */   nop
  .L003B84CC:
    /* 2B84CC 003B84CC 54DC0E0C */  jal        func_003b7150
    /* 2B84D0 003B84D0 2D200002 */   daddu     $4, $16, $0
    /* 2B84D4 003B84D4 8800023C */  lui        $2, %hi(D_008864A8)
    /* 2B84D8 003B84D8 A864448C */  lw         $4, %lo(D_008864A8)($2)
    /* 2B84DC 003B84DC 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2B84E0 003B84E0 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2B84E4 003B84E4 09F84000 */  jalr       $2
    /* 2B84E8 003B84E8 2D280002 */   daddu     $5, $16, $0
    /* 2B84EC 003B84EC 1000BFDF */  ld         $31, 0x10($29)
    /* 2B84F0 003B84F0 2D100000 */  daddu      $2, $0, $0
    /* 2B84F4 003B84F4 0000B07B */  lq         $16, 0x0($29)
    /* 2B84F8 003B84F8 0800E003 */  jr         $31
    /* 2B84FC 003B84FC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003b84a0, 0x60
