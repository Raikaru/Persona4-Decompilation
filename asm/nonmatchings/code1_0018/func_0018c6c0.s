.section .text
.set noat
.set noreorder
glabel func_0018c6c0
    /* 8C6C0 0018C6C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8C6C4 0018C6C4 0000BFFF */  sd         $31, 0x0($29)
    /* 8C6C8 0018C6C8 1800A0AF */  sw         $0, 0x18($29)
    /* 8C6CC 0018C6CC 1C00A5AF */  sw         $5, 0x1C($29)
    /* 8C6D0 0018C6D0 1900053C */  lui        $5, %hi(func_0018c680)
    /* 8C6D4 0018C6D4 80C6A524 */  addiu      $5, $5, %lo(func_0018c680)
    /* 8C6D8 0018C6D8 1800A627 */  addiu      $6, $29, 0x18
    /* 8C6DC 0018C6DC CCFF0E0C */  jal        func_003bff30
    /* 8C6E0 0018C6E0 00000000 */   nop
    /* 8C6E4 0018C6E4 1800A28F */  lw         $2, 0x18($29)
    /* 8C6E8 0018C6E8 0000BFDF */  ld         $31, 0x0($29)
    /* 8C6EC 0018C6EC 2000BD27 */  addiu      $29, $29, 0x20
    /* 8C6F0 0018C6F0 0800E003 */  jr         $31
    /* 8C6F4 0018C6F4 00000000 */   nop
    /* 8C6F8 0018C6F8 00000000 */  nop
    /* 8C6FC 0018C6FC 00000000 */  nop
.size func_0018c6c0, 0x40
